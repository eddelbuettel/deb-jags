#!/bin/sh
#
# (C) Daniel Sundberg 2000
# This is free software and you may do whatever
# you want to with this according to the GPL.
#
# This program requires smbclient, grep, cut & sh
# Lists the workgroups and their masterbrowsers.
#
# Args:
#
if [ -z "$1" ]; then
    echo "Usage: mount_share.sh [SERVER] [SHARE] [MOUNT_DIR] [USERNAME] [PASSWORD]"
else
    mkdir -p "$3/$2"
    smbmount "//$1/$2" "$3/$2" -o username="$4",password="$5"    
fi

