#!/bin/bash
# file make.sh
# make script for Wdbe combined daemon, release wdbecmbd_jack
# author Alexander Wirthmueller
# date created: 23 Aug 2020
# modified: 23 Aug 2020

make Wdbecmbd.h.gch
if [ $? -ne 0 ]; then
	exit
fi

if [ "$1" = "all" ]; then
	subs=("IexWdbe" "VecWdbe" "CrdWdbeNav" "CrdWdbeUsg" "CrdWdbeUsr" "CrdWdbePrs" "CrdWdbeFil" "CrdWdbeMch" "CrdWdbeLib" "CrdWdbeFam" "CrdWdbeSil" "CrdWdbeMtp" "CrdWdbePrj" "CrdWdbeVer" "CrdWdbeSys" "CrdWdbeTrg" "CrdWdbeUnt" "CrdWdbeRls" "CrdWdbeCpr" "CrdWdbeCvr" "CrdWdbeMod" "CrdWdbeVec" "CrdWdbeVit" "CrdWdbeCmd" "CrdWdbeErr" "CrdWdbePph" "CrdWdbeBnk" "CrdWdbePin" "CrdWdbeGen" "CrdWdbePrt" "CrdWdbeSig" "CrdWdbePrc" "CrdWdbeFst" "CrdWdbeVar" "CrdWdbeUtl" "WdbeModbsc" "WdbeModdet" "WdbeMtpPlhfpga" "WdbeMtpPlhmcu" "WdbeMtpModbscbu" "WdbeMtpModbsctd" "WdbeMtpModdet" "WdbeMtpWrfpga" "WdbeMtpWrmcu" "WdbePlhfpga" "WdbePlhmcu" "WdbePrcfile" "WdbePrctree" "WdbeWrdev" "WdbeWrfpga" "WdbeWrmcu")
else
	subs=("$@")
fi

for var in "${subs[@]}"
do
	cd "$var"
	make -j16
	if [ $? -ne 0 ]; then
		exit
	fi
	make install
	cd ..
done

make -j16
if [ $? -ne 0 ]; then
	exit
fi

make install

rm Wdbecmbd.h.gch

