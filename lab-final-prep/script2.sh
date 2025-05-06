#!/bin/bash

process_data() {
    input_file=$1
    output_content=$(grep "a" $input_file | sort -n)
    echo $output_content
}

for file in $(pwd)/* ; do
    chmod 777 $file
done

echo "done processing all files"