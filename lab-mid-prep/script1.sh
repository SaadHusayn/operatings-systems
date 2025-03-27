#!/bin/bash

if [ "$#" -lt 1 ]; then
    echo "Usage: $0 <directory_path>"
    exit 1
fi

backup_root="/home/saad-hussain/backup/"
directory_path="$1"
directory_name="$(date +"%y-%m-%d_%H-%M-%S")"
backup_path="${backup_root}${directory_name}"

if [ -d "$directory_path" ]; then
    mkdir -p "$backup_path"
    cp -r "$directory_path"/* "$backup_path/"
    echo "Backup completed: $backup_path"
else 
    echo "Error: Not a directory"
fi
