#!/usr/bin/env python3
from __future__ import annotations

import argparse
import os
import re
import textwrap
from dataclasses import dataclass, field
from pathlib import Path
from typing import Optional

from bs4 import BeautifulSoup, Tag

# ---------------------------------------------------------------------------
# Configuration
# ---------------------------------------------------------------------------

MAX_LINE_WIDTH = 100

NOISE_SELECTORS = [
    "div.dynheader",
    "div.dyncontent",
    "iframe",
]

# ---------------------------------------------------------------------------
# Data Structures
# ---------------------------------------------------------------------------

MULTILINE_COMMENT_PREFIX = " * "

@dataclass
class SymbolDoc:
    member_id: str
    kind: str
    signature: str
    brief: Optional[str] = None
    detailed_text: Optional[str] = None  # Text content only, no params
    params: list[str] = field(default_factory=list) # List of @param strings

@dataclass
class FileDoc:
    brief: Optional[str] = None
    detailed: Optional[str] = None
    sections: list[tuple[str, str]] = field(default_factory=list)
    includes: list[str] = field(default_factory=list)
    macros: list[SymbolDoc] = field(default_factory=list)
    variables: list[SymbolDoc] = field(default_factory=list)
    typedefs: list[SymbolDoc] = field(default_factory=list)
    functions: list[SymbolDoc] = field(default_factory=list)

# ---------------------------------------------------------------------------
# Text Processing Helpers
# ---------------------------------------------------------------------------

def _clean_whitespace(text: str) -> str:
    """Collapses multiple spaces/newlines into a single space."""
    return re.sub(r"\s+", " ", text).strip()

def _clean_signature(raw: str) -> str:
    """
    Cleans signature whitespace specifically for C-style parentheses.
    """
    text = _clean_whitespace(raw)
    text = re.sub(r"\s*\(\s*", "(", text)
    text = re.sub(r"\s+\)", ")", text)
    text = re.sub(r",\s*", ", ", text)
    return text.strip()

def _clean_include_line(raw: str) -> str:
    clean = _clean_whitespace(raw)
    if m := re.match(r"#include\s+\"(.+)\"", clean):
        return f'#include "{m.group(1).strip()}"'
    if m := re.match(r"#include\s+<(.+)>", clean):
        return f'#include <{m.group(1).strip()}>'
    return clean

def _needs_semicolon(signature: str) -> bool:
    sig = signature.strip()
    if sig.startswith("#define") or sig.endswith((";", "}", "*/")):
        return False
    return True

def _clean_dynamic_content(element: Tag) -> None:
    for selector in NOISE_SELECTORS:
        for tag in element.select(selector):
            tag.decompose()

# ---------------------------------------------------------------------------
# Doxygen Comment Formatting
# ---------------------------------------------------------------------------

def _format_doxygen_block(text_part: str, params_list: list[str]) -> str:
    """
    Combines text and params into a formatted Doxygen block.
    """
    if not text_part and not params_list:
        return ""

    out = ["/*!"]
    wrapper = textwrap.TextWrapper(
        width=MAX_LINE_WIDTH,
        initial_indent=MULTILINE_COMMENT_PREFIX,
        subsequent_indent=MULTILINE_COMMENT_PREFIX
    )

    # 1. Format Description Text
    if text_part:
        lines = [ln.strip() for ln in text_part.splitlines()]
        # Simple preservation of paragraph structure
        para = []
        for line in lines:
            if not line:
                if para:
                    out.extend(wrapper.wrap(" ".join(para)))
                    out.append(" *")
                    para = []
            else:
                para.append(line)
        if para:
            out.extend(wrapper.wrap(" ".join(para)))

    # 2. Format Parameters
    if params_list:
        if text_part:
            out.append(" *")
        
        for p_line in params_list:
            # p_line expects format "@param name description"
            parts = p_line.split(" ", 2) # @param, name, desc
            if len(parts) < 2:
                continue
                
            p_tag = parts[0] # @param
            p_name = parts[1]
            p_desc = parts[2] if len(parts) > 2 else ""
            
            prefix = f"{MULTILINE_COMMENT_PREFIX}{p_tag} {p_name.ljust(8)} "
            remaining_width = MAX_LINE_WIDTH - len(prefix)
            
            if remaining_width < 20: 
                out.append(prefix.strip())
                desc_lines = textwrap.wrap(
                    p_desc, 
                    width=MAX_LINE_WIDTH, 
                    initial_indent=MULTILINE_COMMENT_PREFIX + " " * 13, 
                    subsequent_indent=MULTILINE_COMMENT_PREFIX + " " * 13
                )
                out.extend(desc_lines)
            else:
                desc_lines = textwrap.wrap(
                    p_desc, 
                    width=MAX_LINE_WIDTH, 
                    initial_indent=prefix, 
                    subsequent_indent=MULTILINE_COMMENT_PREFIX + " " * (len(p_tag) + 9)
                )
                out.extend(desc_lines)

    out.append(" */")
    return "\n".join(out)

# ---------------------------------------------------------------------------
# HTML Extraction Logic
# ---------------------------------------------------------------------------

def _extract_file_brief(soup: BeautifulSoup) -> Optional[str]:
    contents = soup.find("div", class_="contents")
    if not contents:
        return None

    _clean_dynamic_content(contents)

    for p in contents.find_all("p"):
        text = p.get_text(" ", strip=True)
        if not text or "SVG" in text:
            continue
        return re.sub(r"\s*More\.\.\.$", "", text).strip()
    return None

def _extract_file_detailed(soup: BeautifulSoup) -> tuple[Optional[str], list[tuple[str, str]]]:
    h2 = soup.find("h2", string=lambda s: s and "Detailed Description" in s)
    if not h2:
        return None, []

    block = h2.find_next_sibling("div", class_="textblock")
    if not block:
        return None, []

    _clean_dynamic_content(block)

    sections = []
    for dl in block.find_all("dl", class_="section"):
        dt = dl.find("dt")
        dd = dl.find("dd")
        if dt and dd:
            key = dt.get_text(strip=True).lower()
            val = dd.get_text(" ", strip=True)
            sections.append((key, val))
        dl.decompose()

    text = block.get_text("\n", strip=True)
    return (text or None, sections)

def _extract_includes(soup: BeautifulSoup) -> list[str]:
    contents = soup.find("div", class_="contents")
    if not contents:
        return []

    block = contents.find("div", class_="textblock")
    if not block:
        return []

    includes = []
    for code in block.find_all("code"):
        text = code.get_text(" ", strip=True)
        if text.strip().startswith("#include"):
            includes.append(_clean_include_line(text))
    return includes

def _parse_members(soup: BeautifulSoup) -> tuple[list[SymbolDoc], list[SymbolDoc], list[SymbolDoc]]:
    # Map member_id -> (signature, detailed_text_only, params_list)
    details_map: dict[str, tuple[str, str, list[str]]] = {}
    
    for h2 in soup.find_all("h2", class_="memtitle"):
        if not (anchor := h2.find("a", href=True)):
            continue
        member_id = anchor["href"].split("#")[-1]

        memitem = h2.find_next_sibling("div", class_="memitem")
        if not memitem:
            continue

        signature = ""
        if proto := memitem.find("div", class_="memproto"):
            signature = _clean_signature(proto.get_text(" ", strip=True))

        detailed_text = ""
        params_list = []

        if doc := memitem.find("div", class_="memdoc"):
            _clean_dynamic_content(doc)
            
            # 1. Extract Parameters into list
            for param_table in doc.find_all("table", class_="params"):
                for tr in param_table.find_all("tr"):
                    tds = tr.find_all("td")
                    if len(tds) >= 2:
                        p_name = tds[0].get_text(" ", strip=True)
                        p_desc = tds[-1].get_text(" ", strip=True)
                        params_list.append(f"@param {p_name} {p_desc}")
                
                # 2. Clean up the HTML so the word "Parameters" doesn't end up in the text.
                parent_dl = param_table.find_parent("dl", class_="params")
                if parent_dl:
                    parent_dl.decompose()
                else:
                    param_table.decompose()
            
            # 3. Remaining text is the description
            detailed_text = doc.get_text("\n", strip=True)

        details_map[member_id] = (signature, detailed_text, params_list)

    macros, typedefs, vars, funcs = [], [], [], []
    section_map = {
        "Macros": ("macro", macros),
        "Typedefs": ("typedef", typedefs),
        "Variables": ("variable", vars),
        "Functions": ("function", funcs),
    }

    summary_data = {}
    ordering = [] 

    for table in soup.find_all("table", class_="memberdecls"):
        header = table.find("h2", class_="groupheader")
        if not header:
            continue
        
        kind_tuple = section_map.get(header.get_text(" ", strip=True))
        if not kind_tuple:
            continue
        kind, target_list = kind_tuple

        for tr in table.find_all("tr"):
            classes = tr.get("class") or []
            
            mem_id = next((c.split(":", 1)[1] for c in classes 
                           if ":" in c and (c.startswith("memitem:") or c.startswith("memdesc:"))), None)
            
            if not mem_id:
                continue

            if mem_id not in summary_data:
                ordering.append((mem_id, target_list))
                summary_data[mem_id] = {"kind": kind}

            entry = summary_data[mem_id]
            text_content = tr.get_text(" ", strip=True)

            if any(c.startswith("memitem:") for c in classes):
                entry["sig_fallback"] = _clean_signature(text_content)
            elif any(c.startswith("memdesc:") for c in classes):
                clean_text = _clean_whitespace(text_content)
                brief = re.sub(r"\s*More\.\.\.$", "", clean_text).strip()
                if brief:
                    entry["brief"] = brief

    for mem_id, target_list in ordering:
        data = summary_data.get(mem_id, {})
        full_sig, detailed_body, params_list = details_map.get(mem_id, (None, "", []))
        
        sig = full_sig or data.get("sig_fallback", "")
        brief = data.get("brief", "").strip()
        detailed_body = detailed_body.strip()

        target_list.append(SymbolDoc(
            member_id=mem_id,
            kind=data.get("kind", "unknown"),
            signature=sig,
            brief=brief,
            detailed_text=detailed_body,
            params=params_list
        ))

    return macros, typedefs, vars, funcs

# ---------------------------------------------------------------------------
# Output Generation
# ---------------------------------------------------------------------------

def _render_file_header(doc: FileDoc) -> str:
    if not doc.brief and not doc.detailed and not doc.sections:
        return ""

    out = ["/*! \\file"]
    wrapper = textwrap.TextWrapper(width=MAX_LINE_WIDTH, initial_indent=" * ", subsequent_indent=" * ")



    if doc.detailed and doc.brief and "".join(doc.brief.split()).replace("\n", " ") in "".join(doc.detailed.split()).replace("\n", " "):
        pass
    elif doc.brief and doc.brief != doc.detailed:
        out.append(f" * \\brief {doc.brief}")
    
    if doc.detailed:
        out.append(" *")
        out.extend(wrapper.wrap(doc.detailed))

    if doc.sections:
        out.append(" *")
        for key, val in doc.sections:
            if key != 'author':
                continue
            line = f" * \\{key} {val}"
            out.extend(wrapper.wrap(line.replace(MULTILINE_COMMENT_PREFIX, "")))

    out.append(" *")
    out.append(" */")
    return "\n".join(out)

def _render_symbol(sym: SymbolDoc, output_kind: str) -> str:
    code_lines = []
    
    # Logic: 
    # if kind == c: Use detailed_text. If detailed_text missing, use brief. Include params.
    # if kind == h: Use brief. No params.

    if output_kind == "h":
        if sym.brief:
            code_lines.append(f"//! {sym.brief}")
        # If no brief, typically header remains silent or uses one-liner from detailed, 
        # but strict separation suggests using only brief unless completely empty.
    else:
        # Outputting .c (implementation)
        description_to_use = sym.detailed_text
        
        # Fallback: If detailed text is empty, grab the brief.
        # This handles the case where HTML had brief="X" and detailed="<param table>".
        if not description_to_use:
            description_to_use = sym.brief
            
        # Render the full block with params
        comment_block = _format_doxygen_block(description_to_use, sym.params)
        if comment_block:
            code_lines.append(comment_block)

    sig = sym.signature.strip()
    
    if sym.kind == "function":
        # format ugly signatures
        # e.g. func(Heap * heap , size_t size) -> func(Heap *heap, size_t size)
        sig = sig.replace(' ,', ',').replace('* ', '*')
    
    if sym.kind == "function" and output_kind == "c":
            sig = sig.rstrip(";").strip()
            code_lines.append(f"{sig} {{")
            code_lines.append("    // TODO implement.")
            code_lines.append("}")
    else:
        if _needs_semicolon(sig):
            sig += ";"
        code_lines.append(sig)

    code_lines.append("")
    return "\n".join(code_lines)

def generate_code(html_path: str | Path, output_kind: str = "c") -> str:
    html = Path(html_path).read_text(encoding="utf-8", errors="ignore")
    soup = BeautifulSoup(html, "html.parser")

    macros, typedefs, vars, funcs = _parse_members(soup)
    detailed_text, sections = _extract_file_detailed(soup)
    
    doc = FileDoc(
        brief=_extract_file_brief(soup),
        detailed=detailed_text,
        sections=sections,
        includes=_extract_includes(soup),
        macros=macros,
        typedefs=typedefs,
        variables=vars,
        functions=funcs
    )

    sections_out = []
    
    if header := _render_file_header(doc):
        sections_out.append(header)
        sections_out.append("")

    if output_kind == "h":
        file_name = os.path.basename(html_path)
        from doxygen_to_skeleton import html_to_source_name
        def_name = "_" + html_to_source_name(file_name).replace(".", "_").upper()
        sections_out.append(f"#ifndef {def_name}")
        sections_out.append(f"#define {def_name}")
        sections_out.append("")

    if doc.includes:
        sections_out.extend(doc.includes)

    groups = [
        ("Macros", doc.macros),
        ("Typedefs", doc.typedefs),
        ("Variables", doc.variables),
        ("Functions", doc.functions)
    ]

    for title, group_list in groups:
        if group_list:
            sections_out.append("")
            sections_out.append("//----------------------------------------------------------------------------")
            sections_out.append(f"// {title}")
            sections_out.append("//----------------------------------------------------------------------------")
            sections_out.append("")

            for sym in group_list:
                sections_out.append(_render_symbol(sym, output_kind))

    if output_kind == "h":
        sections_out.append("#endif")

    return "\n".join(sections_out).strip() + "\n"

# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Generate C skeleton from Doxygen HTML.")
    parser.add_argument("html", help="Path to Doxygen HTML file (*.html)")
    parser.add_argument("--kind", choices=["c", "h"], default="c", help="Output type")
    
    args = parser.parse_args()
    print(generate_code(args.html, args.kind), end="")