#!/bin/sh
#
# (C) Daniel Sundberg 2000
# This is free software and you may do whatever 
# you want to with this according to the GPL.
#
# This program requires nmblookup, findsmb, 
# grep, cut & sh.
#
# Gets your masterbrowser in workgroup $1.
#
if [ -z "$1" ]; then
    echo "Usage: list_shares_remote SERVER [REMOTELOCALMASTERBROWSER]"
else
    if [ -z "$2" ]; then
	smbclient -L "$1" -N | cut -b 2-80 | fixsmbcop "Sharename      Type      Comment" "---------      ----      -------" _NEWLINE > ~/.jags/outfile1.dat
	cat ~/.jags/outfile1.dat | cut -b 1-15
	cat ~/.jags/outfile1.dat | cut -b 16-25 > ~/.jags/outfile2.dat
	cat ~/.jags/outfile1.dat | cut -b 26-80 > ~/.jags/outfile3.dat
    else
    	nmb_result=$(nmblookup -U $2 -R $1)
        ip_addr_row=$(echo "$nmb_result" | grep "<00>")
        if [ -n "$ip_addr_row" ]; then
		ip_addr=$(echo "$ip_addr_row" | cut -d ' ' -f 1)
		if [ -n "$ip_addr" ]; then
			smbclient -L "$1" -N -I "$ip_addr" | cut -b 2-80 | fixsmbcop "Sharename      Type      Comment" "---------      ----      -------" _NEWLINE > ~/.jags/outfile1.dat
			cat ~/.jags/outfile1.dat | cut -b 1-15
			cat ~/.jags/outfile1.dat | cut -b 16-25 > ~/.jags/outfile2.dat
        		cat ~/.jags/outfile1.dat | cut -b 26-80 > ~/.jags/outfile3.dat
		else
	 		echo "Error: Could not parse destination server IP"
			echo "Error" > ~/.jags/outfile2.dat
			echo "NA" > ~/.jags/outfile3.dat
		fi
   	else 
	    echo "Error: Destination server IP not found"
	    echo "Error" > ~/.jags/outfile2.dat
	    echo "NA" > ~/.jags/outfile3.dat
    	fi
    fi
fi
