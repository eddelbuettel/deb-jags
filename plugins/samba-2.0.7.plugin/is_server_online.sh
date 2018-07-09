#!/bin/sh
#
# (C) Daniel Sundberg 2000
# This is free software and you may do whatever 
# you want to with this according to the GPL.
#
# This program requires nmblookup, findsmb, 
# grep, cut & sh.
#
# Checks wether server $1 is online.
#
if [ -z "$1" ]; then
     echo "Usage: is_server_online.sh [SERVER]"
else 
    nmb_result=$(nmblookup "$1")
    ip_addr_row=$(echo "$nmb_result" | grep "<00>")
    if [ -n "$ip_addr_row" ]; then
	ip_addr=$(echo "$ip_addr_row" | cut -d ' ' -f 1)
	if [ -n "$ip_addr" ]; then
	    echo "$ip_addr"
	else
	    echo "Error: Server is unreachable or is offline"
	fi
    else 
	echo "Error: Server is unreachable or is offline"
    fi
fi
