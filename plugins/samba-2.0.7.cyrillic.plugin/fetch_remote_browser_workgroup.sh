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
# $1 : Masterbrowser
# $2 : Remote Workgroup
#
if [ -z "$1" ]; then
    echo "Usage: fetch_remote_browser_workgroup.sh [LOCALMASTERBROWSER] [REMOTEMASTERBROWSER]"
else 
    smbclient -L $1 -N | grep -A 100 "Workgroup            Master"| grep $2 | cut -b 2-22
fi
