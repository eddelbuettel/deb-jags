#!/bin/sh
#
# (C) Daniel Sundberg 2000
# This is free software and you may do whatever 
# you want to with this according to the GPL.
#
# This program requires nmblookup, findsmb, 
# grep, cut & sh.
#
# Gets your masterbrowser in workgroup $1.
#
if [ -z "$1" ]; then
    echo "Usage: fetch_master_browser [WORKGROUP]"
else 
    nmb_result=$(nmblookup -M "$1")
    ip_addr_row=$(echo "$nmb_result" | grep "<1d>" | grep -v "10.0.0.1" | grep -v '192.168\.[0-9][0-9]\?[0-9]\?\.[0-9][0-9]\?[0-9]\?$')
    if [ -n "$ip_addr_row" ]; then
	ip_addr=$(echo "$ip_addr_row" | cut -d ' ' -f 1)
	if [ -n "$ip_addr" ]; then
	  nb_name_stuff=$(nmblookup -A "$ip_addr")
	  #echo "$nb_name_stuff"
	  found_name=$(echo "$nb_name_stuff" | grep "(this is not unusual)")
	  if [ -z "$found_name" ]; then
	    nb_name=$(echo "$nb_name_stuff" | grep "<00>" | grep -v "<GROUP>" | cut -b 2-17)
	    echo "$nb_name"
	  else
	    echo "Error: Could not lookup IP"
 	  fi
	else
	    echo "Error: Could not parse master browser IP"
	fi
    else 
	echo "Error: Masterbrowser IP not found"
    fi
fi
