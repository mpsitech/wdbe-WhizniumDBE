#!/bin/bash
# file make.sh
# make script for Wdbe daemon, release wdbed_awsubt
# author Alexander Wirthmueller
# date created: 23 Aug 2020
# modified: 23 Aug 2020

make Wdbed.h.gch
if [ $? -ne 0 ]; then
	exit
fi

if [ "$1" = "all" ]; then
	subs=("IexWdbe" "VecWdbe" "CrdWdbeNav" "CrdWdbeUsg" "CrdWdbeUsr" "CrdWdbePrs" "CrdWdbeFil" "CrdWdbeMch" "CrdWdbeLib" "CrdWdbeFam" "CrdWdbeSil" "CrdWdbeMtp" "CrdWdbePrj" "CrdWdbeVer" "CrdWdbeSys" "CrdWdbeTrg" "CrdWdbeUnt" "CrdWdbeRls" "CrdWdbeCpr" "CrdWdbeCvr" "CrdWdbeMod" "CrdWdbeVec" "CrdWdbeVit" "CrdWdbeCmd" "CrdWdbeErr" "CrdWdbePph" "CrdWdbeBnk" "CrdWdbePin" "CrdWdbeGen" "CrdWdbePrt" "CrdWdbeSig" "CrdWdbePrc" "CrdWdbeFst" "CrdWdbeVar" "CrdWdbeUtl")
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

rm Wdbed.h.gch

