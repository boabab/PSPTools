# Create a project skeleton from a given Doxygen.zip and save it to -o <output>.
python doxygen_to_skeleton.py input/DoxygenV3.zip -o output/skeletonV3

# Generate a .c / .h file from a given doxygen-html file.
python html_to_c.py path/to/doxygen_file.html > output_filename.c