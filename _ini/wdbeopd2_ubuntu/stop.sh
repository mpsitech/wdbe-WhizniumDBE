#!/bin/bash
# file stopall.sh
# stop script for Wdbe operation daemon(s), release wdbeopd2_ubuntu
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 13 Jan 2021
# IP header --- ABOVE

IFS=$'\n'
pids=$(pgrep Wdbeopd2)

for var in "${pids[@]}"
do
	kill -15 $var
done
