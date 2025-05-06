#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Usage: $0 <directory_path>"
    exit 1
fi

source_dir="$1"
backup_root="/home/saad-hussain/backup"
timestamp=$(date +"%Y-%m-%d_%H-%M-%S")
backup_dir="${backup_root}/backup_${timestamp}"

if [ ! -d "$source_dir" ]; then
    echo "Error: Directory '$source_dir' does not exist."
    exit 1
fi

mkdir -p "$backup_dir"
cp -r "$source_dir"/* "$backup_dir"

file_count=$(find "$backup_dir" -type f | wc -l)
dir_count=$(find "$backup_dir" -type d | wc -l)

echo "Backup completed successfully!"
echo "Backup location: $backup_dir"
echo "Files backed up: $file_count"
echo "Directories backed up: $dir_count"

