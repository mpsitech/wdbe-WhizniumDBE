#!/bin/bash
# file stopall.sh
# stop script for Wdbe operation daemon(s), release wdbeopd2_genio
# author Alexander Wirthmueller
# date created: 11 Jul 2020
# modified: 11 Jul 2020

IFS=$'\n'
pids=$(pgrep Wdbeopd2)

for var in "${pids[@]}"
do
	kill -15 $var
done

