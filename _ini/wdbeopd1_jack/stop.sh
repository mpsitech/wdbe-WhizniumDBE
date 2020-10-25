#!/bin/bash
# file stopall.sh
# stop script for Wdbe operation daemon(s), release wdbeopd1_jack
# author Alexander Wirthmueller
# date created: 23 Aug 2020
# modified: 23 Aug 2020

IFS=$'\n'
pids=$(pgrep Wdbeopd1)

for var in "${pids[@]}"
do
	kill -15 $var
done

