fileNames=$(find $1 -type f -name "*.log")
user_name=saad-hussain  #change it according to your system
if [ -n "$fileNames" ]; then
    mkdir -p /home/$user_name/logs_backup
    mv $1/*.log /home/$user_name/logs_backup
    echo "$fileNames $(date +'%Y-%m-%d %H:%M:%S')" >> /home/$user_name/logs_backup/log_actions.txt
    echo "All log files moved to the /home/$user_name/logs_backup directory, and the record is appended to /home/$user_name/logs_backup directory/log_actions.txt"

else
    echo "no log files in the specified directory!!!"
fi
