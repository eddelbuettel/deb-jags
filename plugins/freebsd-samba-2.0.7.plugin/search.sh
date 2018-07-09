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
    echo "Usage: search [COMPUTER]"
else 
    nmb_result=$(nmblookup "$1" | grep "<00>")
    if [ -n "$nmb_result" ]; then
	echo "$1"
    else 
	echo "Sorry, can't find $1"
    fi
fi
