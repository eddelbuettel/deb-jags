#!/bin/sh
#
# (C) Daniel Sundberg 2000
# This is free software and you may do whatever
# you want to with this according to the GPL.
#
# This is pretty simple but if you're on 
# FreeBSD you probably can't do 
# mount -t smbfs because FreeBSD wraps 
# smb-shares into nfs or something...:-)
#
# Args:
#
if [ -z "$1" ]; then
    mount -t smbfs
else
    echo "Usage: ls_mnts.sh"    
fi

