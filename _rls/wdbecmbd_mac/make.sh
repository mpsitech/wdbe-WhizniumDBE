#!/bin/bash
# file make.sh
# make script for Wdbe combined daemon, release wdbecmbd_mac
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 7 Feb 2024
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

if [ "$1" = "all" ] || [ "$1" = "clean" ]; then
	subs=("IexWdbe" "VecWdbe" "CrdWdbeUsg" "CrdWdbeUsr" "CrdWdbePrs" "CrdWdbeFil" "CrdWdbeNav" "CrdWdbeMch" "CrdWdbeLib" "CrdWdbeFam" "CrdWdbeSil" "CrdWdbeMtp" "CrdWdbePrj" "CrdWdbeVer" "CrdWdbeUnt" "CrdWdbeCpr" "CrdWdbeCvr" "CrdWdbePph" "CrdWdbeMod" "CrdWdbeVec" "CrdWdbeVit" "CrdWdbeCmd" "CrdWdbeErr" "CrdWdbePpl" "CrdWdbeSeg" "CrdWdbeBnk" "CrdWdbePin" "CrdWdbeInt" "CrdWdbeSns" "CrdWdbeVar" "CrdWdbeGen" "CrdWdbePrt" "CrdWdbeSig" "CrdWdbeCdc" "CrdWdbePrc" "CrdWdbeFst" "CrdWdbeCmp" "CrdWdbeRls" "CrdWdbeUtl" "WdbeWrdev" "WdbeWrfpga" "WdbeWrmcu" "WdbeWrterm" "WdbePrcfile" "WdbePrctree" "WdbePlhmcu" "WdbePlhfpga" "WdbeMtpWrmcu" "WdbeMtpWrfpga" "WdbeMtpGenfst" "WdbeMtpCplmsttd" "WdbeMtpPlhmcu" "WdbeMtpCplmstbu" "WdbeGenfst" "WdbeMtpPlhfpga" "WdbeCplmst" "WdbeGen")
else
	subs=("$@")
fi

if [ "$1" = "clean" ]; then
	for var in "${subs[@]}"
	do
		cd "$var"
		make clean
		cd ..
	done

	make clean
else
	make Wdbecmbd.h.gch
	if [ $? -ne 0 ]; then
		exit
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

	rm Wdbecmbd.h.gch
fi
