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
#
if [ -z "$1" ]; then
    echo "Usage: mount_share.sh [COMPUTER] [SHARE] [MOUNT_DIR]"
else
    mkdir $3/$1
    mkdir $3/$1/$2
    cat $HOME/.jags/plugins/offline.plugin/sample_smb_output > $3/samplefile    
fi

