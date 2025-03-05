#!/bin/bash

#if command line arguments are not given correctly 
if [ $# -ne 1 ]; then
    echo "Usage: $0 <file_or_directory>"
    exit 1
fi

item="$1"

#if it is a file, display size, permission, last modified date
if [ -f "$item" ]; then
    echo "'$item' is a regular file."
    echo "File size: $(stat -c%s "$item") bytes"
    echo "Permissions: $(ls -l "$item" | awk '{print $1}')"
    echo "Last modified: $(stat -c%y "$item")"
#if it is a directory, display no of files, permission of each, and last modified
elif [ -d "$item" ]; then
    echo "'$item' is a directory."
    echo "Number of files: $(ls -1 "$item" | wc -l)"
    echo "Permissions: $(ls -ld "$item" | awk '{print $1}')"
    echo "Last modified: $(stat -c%y "$item")"
else
    echo "'$item' is neither a regular file nor a directory."
fi
