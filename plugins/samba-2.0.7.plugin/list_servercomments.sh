#!/bin/sh
#
# (C) Daniel Sundberg 2000
# This is free software and you may do whatever 
# you want to with this according to the GPL.
#
# This program requires smbclient, fixsmbcop, cut & sh
# Lists the server comment strings.
# 
# Args:
# $1 : Masterbrowser
#
if [ -z "$1" ]; then
    echo "Usage: list_servercomments [MASTERBROWSER]"
else 
    smbclient -L $1 -N | cut -b 23-80 | fixsmbcop Comment ------ _NEWLINE
fi
