#!/bin/bash
# file make.sh
# make script for Wdbe combined daemon, release wdbecmbd_jack
# author Alexander Wirthmueller
# date created: 11 Jul 2020
# modified: 11 Jul 2020

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

