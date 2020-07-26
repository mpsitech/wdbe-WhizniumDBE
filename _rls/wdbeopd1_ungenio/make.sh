#!/bin/bash
# file make.sh
# make script for Wdbe operation daemon, release wdbeopd1_ungenio
# author Alexander Wirthmueller
# date created: 11 Jul 2020
# modified: 11 Jul 2020

make Wdbeopd.h.gch
if [ $? -ne 0 ]; then
	exit
fi

if [ "$1" = "all" ]; then
	subs=("IexWdbe" "VecWdbe" "WdbeWrmcu" "WdbeWrfpga" "WdbeWrdev" "WdbePrctree" "WdbePrcfile" "WdbePlhmcu" "WdbePlhfpga" "WdbeModdet" "WdbeModbsc")
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

