#!/bin/bash
# file make.sh
# make script for Wdbe combined daemon, release wdbecmbd_ubuntu
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 21 Dec 2021
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

make Wdbecmbd.h.gch
if [ $? -ne 0 ]; then
	exit
fi

if [ "$1" = "all" ]; then
	subs=("IexWdbe" "VecWdbe" "CrdWdbeUsg" "CrdWdbeUsr" "CrdWdbePrs" "CrdWdbeFil" "CrdWdbeNav" "CrdWdbeMch" "CrdWdbeLib" "CrdWdbeFam" "CrdWdbeSil" "CrdWdbeMtp" "CrdWdbePrj" "CrdWdbeVer" "CrdWdbeSys" "CrdWdbeTrg" "CrdWdbeUnt" "CrdWdbeRls" "CrdWdbeCpr" "CrdWdbeCvr" "CrdWdbePph" "CrdWdbeMod" "CrdWdbeVec" "CrdWdbeVit" "CrdWdbeCmd" "CrdWdbeErr" "CrdWdbePpl" "CrdWdbeSeg" "CrdWdbeBnk" "CrdWdbePin" "CrdWdbeInt" "CrdWdbeSns" "CrdWdbeVar" "CrdWdbeGen" "CrdWdbePrt" "CrdWdbeSig" "CrdWdbePrc" "CrdWdbeFst" "CrdWdbeUtl" "WdbeWrfpga" "WdbeWrmcu" "WdbeWrdev" "WdbePrcfile" "WdbePrctree" "WdbePlhfpga" "WdbePlhmcu" "WdbeMtpWrmcu" "WdbeMtpGenfst" "WdbeMtpWrfpga" "WdbeMtpCplmsttd" "WdbeMtpCplmstbu" "WdbeMtpPlhmcu" "WdbeMtpPlhfpga" "WdbeCplmst" "WdbeGen" "WdbeGenfst")
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

rm Wdbecmbd.h.gch
