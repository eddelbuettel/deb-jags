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
    echo "Usage: mount_share.sh [COMPUTER] [SHARE] [MOUNT_DIR] [WORKGROUP] [REMOTELOCALMASTERBROWSER]"
else
    mkdir -p "$3"
    mkdir -p "$3/$2"
    if [ -z "$5" ]; then
        smbmount "//$1/$2" "$3/$2" -o guest,iocharset=koi8-r,codepage=866
    else
   	nmb_result=$(nmblookup -U $5 -R $1)
        ip_addr_row=$(echo "$nmb_result" | grep "<00>")
        if [ -n "$ip_addr_row" ]; then
		ip_addr=$(echo "$ip_addr_row" | cut -d ' ' -f 1)
		if [ -n "$ip_addr" ]; then
		    smbmount "//$1/$2" "$3/$2" -o guest,ip="$ip_addr",workgroup="$4",iocharset=koi8-r,codepage=866
		else
	 	    echo "Error: Could not parse destination server IP"
		fi
   	else 
	    echo "Error: Destination server IP not found"
    	fi
	
    fi
fi

