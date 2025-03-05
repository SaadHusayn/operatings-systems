#!/bin/bash

#if command line argument not given, we will tell user to about usage of it
if [ $# -ne 1 ]; then
    echo "Usage: $0 <filename>"
    exit 1
fi

filename="$1"

#we check if file exist through -f flag, if exists we append date by >> sign
if [ -f "$filename" ]; then
    echo "$(date)" >> "$filename"
    echo "Date and time appended to $filename."
else
    echo "Error: File '$filename' does not exist."
fi
