#!/bin/bash
# file make.sh
# make script for Wdbe operation daemon, release wdbeopd1_awsubt
# author Alexander Wirthmueller
# date created: 23 Aug 2020
# modified: 23 Aug 2020

make Wdbeopd.h.gch
if [ $? -ne 0 ]; then
	exit
fi

if [ "$1" = "all" ]; then
	subs=("IexWdbe" "VecWdbe" "WdbeModbsc" "WdbeModdet" "WdbePlhfpga" "WdbePlhmcu" "WdbePrcfile" "WdbePrctree" "WdbeWrdev" "WdbeWrfpga" "WdbeWrmcu")
else
	subs=("$@")
fi

for var in "${subs[@]}"
do
	cd "$var"
	make -j2
	if [ $? -ne 0 ]; then
		exit
	fi
	make install
	cd ..
done

make -j2
if [ $? -ne 0 ]; then
	exit
fi

make install

rm Wdbeopd.h.gch

