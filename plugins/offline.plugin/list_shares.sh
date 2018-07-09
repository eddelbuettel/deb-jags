#!/bin/sh
#
# (C) Daniel Sundberg 2000
# This is free software and you may do whatever 
# you want to with this according to the GPL.
#
# This program requires smbclient, fixsmbcop, cut & sh.
# Lists the share on a computer.
# Args:
# $1 : Computer
#
if [ -z "$1" ]; then
    echo "Usage: list_sharess [COMPUTER]"
else 
    more $HOME/.jags/plugins/offline.plugin/sample_smb_output | cut -b 2-16 | fixsmbcop Sharename --------- _NEWLINE
fi
