#!/bin/bash
# file make.sh
# make script for Wdbe operation daemon, release wdbeopd1_ubuntu
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 23 Oct 2021
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

make Wdbeopd.h.gch
if [ $? -ne 0 ]; then
	exit
fi

if [ "$1" = "all" ]; then
	subs=("IexWdbe" "VecWdbe" "WdbeCplmst" "WdbeGen" "WdbeGenfst" "WdbePlhfpga" "WdbePlhmcu" "WdbePrcfile" "WdbePrctree" "WdbeWrdev" "WdbeWrfpga" "WdbeWrmcu")
else
	subs=("$@")
fi

for var in "${subs[@]}"
do
	cd "$var"
	make -j4
	if [ $? -ne 0 ]; then
		exit
	fi
	make install
	cd ..
done

make -j4
if [ $? -ne 0 ]; then
	exit
fi

make install

rm Wdbeopd.h.gch
