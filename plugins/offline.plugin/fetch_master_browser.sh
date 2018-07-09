#!/bin/sh
#
# (C) Daniel Sundberg 2000
# This is free software and you may do whatever 
# you want to with this according to the GPL.
#
# This program requires nmblookup, grep, cut & sh
# Gets your masterbrowser in workgroup $1.
#
if [ -z "$1" ]; then
    echo "Usage: fetch_master_browser [WORKGROUP]"
else 
    more $HOME/.jags/plugins/offline.plugin/nmblookup_sample | grep "<1d>" | cut -d ' ' -f 1 
fi
