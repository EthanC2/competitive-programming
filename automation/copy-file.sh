#! /bin/bash

# Summary: copies a file to the system clipboard
# Dependencies: xclip

# Copy file to clipboard
cat "$PWD"/"$1" | xclip -i -selection clipboard
