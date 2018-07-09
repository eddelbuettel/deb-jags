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
# $2 : File for the masterbrowsers.
#
if [ -z "$1" ]; then
    echo "Usage: list_workgroups [MASTERBROWSER]"
else 
    smbclient -L "$1" -N | cut -b 2-22 | fixsmbcop Server --------- _NEWLINE
fi
