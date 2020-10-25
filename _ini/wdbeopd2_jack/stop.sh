#!/bin/bash
# file stopall.sh
# stop script for Wdbe operation daemon(s), release wdbeopd2_jack
# author Alexander Wirthmueller
# date created: 23 Aug 2020
# modified: 23 Aug 2020

IFS=$'\n'
pids=$(pgrep Wdbeopd2)

for var in "${pids[@]}"
do
	kill -15 $var
done

