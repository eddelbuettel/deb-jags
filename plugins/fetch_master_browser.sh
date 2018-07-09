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
    # Store the ip-adress
    ipadr=$(nmblookup -M "-" $1 | grep $1 | grep "<1d>" | cut -d ' ' -f 1)
    # Parse out the netbios name from findsmb output
    findsmb $ipadr | grep "+" | cut -b 17-30
fi
