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
# $2 : File for the workgroups.
# $3 : File for the masterbrowsers.
#
if [ -z "$1" ]; then
    echo "Usage: list_workgroups [MASTERBROWSER]"
else 
    more $HOME/.jags/plugins/offline.plugin/sample_smb_output | cut -b 2-22 | fixsmbcop Workgroup --------- _NEWLINE
fi
