#!/bin/bash
# file make.sh
# make script for Wdbe combined daemon, release wdbecmbd_mac
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 5 Dec 2020
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
	subs=("IexWdbe" "VecWdbe" "CrdWdbeUsg" "CrdWdbeUsr" "CrdWdbePrs" "CrdWdbeFil" "CrdWdbeNav" "CrdWdbeMch" "CrdWdbeLib" "CrdWdbeFam" "CrdWdbeSil" "CrdWdbeMtp" "CrdWdbePrj" "CrdWdbeVer" "CrdWdbeSys" "CrdWdbeTrg" "CrdWdbeUnt" "CrdWdbeRls" "CrdWdbeCpr" "CrdWdbeCvr" "CrdWdbeMod" "CrdWdbeVec" "CrdWdbeVit" "CrdWdbeCmd" "CrdWdbeErr" "CrdWdbePph" "CrdWdbeBnk" "CrdWdbePin" "CrdWdbeGen" "CrdWdbePrt" "CrdWdbeSig" "CrdWdbePrc" "CrdWdbeFst" "CrdWdbeVar" "CrdWdbeUtl" "WdbeWrmcu" "WdbeWrfpga" "WdbeWrdev" "WdbePrctree" "WdbePrcfile" "WdbePlhmcu" "WdbePlhfpga" "WdbeMtpWrmcu" "WdbeMtpWrfpga" "WdbeMtpModdet" "WdbeMtpModbsctd" "WdbeMtpModbscbu" "WdbeMtpPlhmcu" "WdbeMtpPlhfpga" "WdbeModdet" "WdbeModbsc")
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
