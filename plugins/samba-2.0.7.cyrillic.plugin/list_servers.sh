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
    echo "Usage: list_servers [MASTERBROWSER]"
else 
	smbclient -L "$1" -N | cut -b 2-80 | fixsmbcop "Server               Comment" "---------            -------" _NEWLINE > ~/.jags/outfile1.dat
	cat ~/.jags/outfile1.dat | cut -b 1-21
	cat ~/.jags/outfile1.dat | cut -b 22-80 > ~/.jags/outfile2.dat
fi
