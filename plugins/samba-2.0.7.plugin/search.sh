#!/bin/sh
#
# (C) Daniel Sundberg 2000
# This is free software and you may do whatever 
# you want to with this according to the GPL.
#
# This program requires nmblookup, findsmb, 
# grep, cut & sh.
#
# Searches for $1 server on $2 RemoteLocalMasterBrowser
#
if [ -z "$1" ]; then
    echo "Usage: search [COMPUTER] [REMOTELOCALMASTERBROWSER]"
else 
    if [ -z "$2" ]; then
        nmb_result=$(nmblookup "$1" | grep "<00>")
	if [ -n "$nmb_result" ]; then
	    echo "$1"
        else 
    	    echo "Sorry, can't locate $1 on native workgroup"
	fi
    else
        nmb_result=$(nmblookup -U $2 -R "$1" | grep "<00>")
	if [ -n "$nmb_result" ]; then
	    echo "$1"
        else 
    	    echo "Sorry, can't locate $1 on $2"
	fi
    fi
fi
