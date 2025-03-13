#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <filename (without .c)>"
    exit 1
fi

filename="$1"

# Compile the C file
gcc -o "$filename.out" "$filename.c"

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Running $filename..."
    ./"$filename"
else
    echo "Compilation failed."
fi
