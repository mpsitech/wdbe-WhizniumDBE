#!/bin/bash
# file stopall.sh
# stop script for Wdbe operation daemon(s), release wdbeopd1_mac
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 16 Dec 2020
# IP header --- ABOVE

IFS=$'\n'
pids=$(pgrep Wdbeopd1)

for var in "${pids[@]}"
do
	kill -15 $var
done
