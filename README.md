# Doxygen Skeleton Generator

This tool reconstructs `.c` and `.h` source skeletons from a Doxygen-generated HTML archive.  
It restores function signatures, macros, variables, and Doxygen comments extracted from the HTML.

The process uses two components:

- `doxygen_to_skeleton.py` — scans a Doxygen ZIP and generates source files
- `html_to_c.py` — converts individual HTML pages into .c/.h code

---

## Requirements

- Python 3.8+
- Install dependency:
  ```
  pip install beautifulsoup4
  ```

---

## Expected Input

A ZIP produced by Doxygen containing HTML output.

Valid file patterns inside the archive:
```
*_8c.html
*_8h.html
```

Examples:
```
src/lcd_8c.html     → lcd.c
drivers/foo_8h.html → foo.h
```

Filename reconstruction is handled automatically.

---

## Basic Usage

Generate skeleton `.c` and `.h` files:

```
python doxygen_to_skeleton.py input/DoxygenV6_LED.zip -o output/skeletonV6_LED
```

Result:
```
output_dir/
 ├─ lcd.c
 └─ foo/bar.h
```

If no `--output` is specified, nothing is written.

---

## How It Works

### 1) Detect HTML sources
`find_doxygen_files()` scans the ZIP for matching HTML entries.

### 2) Convert each file
For each HTML page:
- extracted to a temporary file
- output type inferred from extension
- processed via `generate_code()` in `html_to_c.py`
- written into the output directory

### 3) Generated content includes
- file-level Doxygen header
- includes
- macros
- variables
- function declarations (`.h`)
- function skeletons with empty bodies (`.c`)

Example output pattern:
```c
/*!
 * Description text...
 * @param value explanation
 */
int foo(int value) {

}
```

---

## Comparing Versions for a Versuch

When generating multiple skeleton versions (e.g., before and after code changes for a *Versuch*), the differences can be reviewed efficiently using Visual Studio Code:

### Recommended Extension

Install:
```
Compare Folders
```

### Usage

1. Generate two skeleton directories, for example:
   ```
   output_v1/
   output_v2/
   ```
2. In VS Code:
   - Open the command palette (`Ctrl+Shift+P`)
   - Run: `Compare Folders: Select Folder`
   - Select the first version
   - Repeat for the second version

### Benefits

- Highlights added/removed functions
- Makes required implementation changes obvious
- Avoids manual file-by-file inspection

This workflow is particularly useful when only specific functions must be updated between lab iterations.

---

## Command-Line Reference

```
usage: doxygen_to_skeleton.py zip [-o OUTPUT]

positional arguments:
  zip           Path to doxygen.zip

optional arguments:
  -o, --output  Directory where .c/.h files are created
```

---

## Direct HTML Conversion (Advanced)

Call the HTML converter directly:

```
python3 html_to_c.py file_8c.html --kind c
python3 html_to_c.py file_8h.html --kind h
```

Outputs source code to stdout.

---

## Overwriting Behavior

Existing files are overwritten by default.  
Modify `OVERWRITE_EXISTING` in `doxygen_to_skeleton.py` if needed.