#!/bin/bash
#
# (C) Daniel Sundberg 2000
# This is free software and you may do whatever 
# you want to with this according to the GPL.
#
# This program requires nmblookup, findsmb, 
# grep, cut & sh.
#
smbumount "$1"
rmdir "$1"
echo "rmdir $1"

flag=$(ls "$2")
if [ -z "$flag" ]; then
    rmdir "$2"
    echo "rmdir $2"
else
    echo "Not currently removing $2"
fi
