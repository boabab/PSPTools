#!/usr/bin/env python3

from __future__ import annotations
import argparse
import os
import re
from pathlib import Path
from zipfile import ZipFile
from tempfile import TemporaryDirectory

import html_to_c


# ---------------------------------------------------------------------------
# Configuration
# ---------------------------------------------------------------------------

HTML_FILE_SUFFIXES = ("_8h.html", "_8c.html")

DEFAULT_HTML_ENCODING = "utf-8"
DEFAULT_OUTPUT_ENCODING = "utf-8"

OVERWRITE_EXISTING = True


def _html_to_source_name(html_filename: str) -> str | None:
    base = os.path.basename(html_filename)
    m = re.match(r"(.+)_8([ch])\.html$", base)
    if not m:
        return None
    mangled_stem, ext = m.groups()
    stem = mangled_stem.replace("__", "_")
    return f"{stem}.{ext}"


def find_doxygen_files(zip_path: str | os.PathLike) -> list[tuple[str, str]]:
    """
    Return a list of (html_path_inside_zip, reconstructed_source_path).
    Example: ('lcd_8c.html', 'lcd.c')
    """
    zip_path = Path(zip_path)
    results: list[tuple[str, str]] = []

    with ZipFile(zip_path, "r") as zf:
        for info in zf.infolist():
            if info.is_dir():
                continue
            name = info.filename
            if not name.endswith(HTML_FILE_SUFFIXES):
                continue

            src_name = _html_to_source_name(name)
            if src_name is None:
                continue

            html_path = Path(name)
            src_path = (html_path.parent / src_name).as_posix()
            results.append((name, src_path))

    return results


def create_skeleton_sources(zip_path: str | os.PathLike,
                            output_root: str | os.PathLike) -> None:
    """
    For each *_8c.html / *_8h.html in the zip, uses html_to_c.generate_from_html
    to build a C/H skeleton and writes it to output_root.
    """
    output_root = Path(output_root)
    files = find_doxygen_files(zip_path)

    with ZipFile(zip_path, "r") as zf, TemporaryDirectory() as tmpdir_str:
        tmpdir = Path(tmpdir_str)

        for html_inside, src_rel in files:
            # write HTML from zip to a temporary file so html_to_c can read it
            html_bytes = zf.read(html_inside)
            temp_html = tmpdir / Path(html_inside).name
            temp_html.write_bytes(html_bytes)

            # decide kind based on target extension
            ext = Path(src_rel).suffix.lower()
            kind = "h" if ext == ".h" else "c"

            # delegate to html_to_c
            content = html_to_c.generate_code(temp_html, output_kind=kind)

            out_path = output_root / src_rel
            out_path.parent.mkdir(parents=True, exist_ok=True)

            if out_path.exists() and not OVERWRITE_EXISTING:
                continue

            out_path.write_text(content, encoding=DEFAULT_OUTPUT_ENCODING)


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def main() -> None:
    parser = argparse.ArgumentParser(
        description=(
            "Recover C/H skeletons (with Doxygen comments and signatures) "
            "from a Doxygen HTML zip, using html_to_c."
        )
    )
    parser.add_argument("zip", help="Path to doxygen.zip")
    parser.add_argument(
        "-o", "--output",
        help="Directory where .c/.h files are created."
    )
    args = parser.parse_args()

    if args.output:
        create_skeleton_sources(args.zip, args.output)
        print(f"Skeleton .c/.h files created under: {args.output}")


if __name__ == "__main__":
    main()
