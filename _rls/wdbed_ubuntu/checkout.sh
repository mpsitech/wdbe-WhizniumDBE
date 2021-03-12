#!/bin/bash
# file checkout.sh
# checkout script for Wdbe daemon, release wdbed_ubuntu
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 12 Mar 2021
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set BUILDROOT=${WHIZSDKROOT}/build
export set LIBROOT=${WHIZSDKROOT}/lib
export set BINROOT=${WHIZROOT}/bin
export set REPROOT=${WHIZDEVROOT}/rep
export set CMBDBUILDROOT=$REPROOT/wdbe/wdbecmbd

mkdir $BUILDROOT/wdbed
mkdir $BUILDROOT/wdbed/IexWdbe
mkdir $BUILDROOT/wdbed/VecWdbe
mkdir $BUILDROOT/wdbed/CrdWdbeUsg
mkdir $BUILDROOT/wdbed/CrdWdbeUsr
mkdir $BUILDROOT/wdbed/CrdWdbePrs
mkdir $BUILDROOT/wdbed/CrdWdbeFil
mkdir $BUILDROOT/wdbed/CrdWdbeNav
mkdir $BUILDROOT/wdbed/CrdWdbeMch
mkdir $BUILDROOT/wdbed/CrdWdbeLib
mkdir $BUILDROOT/wdbed/CrdWdbeFam
mkdir $BUILDROOT/wdbed/CrdWdbeSil
mkdir $BUILDROOT/wdbed/CrdWdbeMtp
mkdir $BUILDROOT/wdbed/CrdWdbePrj
mkdir $BUILDROOT/wdbed/CrdWdbeVer
mkdir $BUILDROOT/wdbed/CrdWdbeSys
mkdir $BUILDROOT/wdbed/CrdWdbeTrg
mkdir $BUILDROOT/wdbed/CrdWdbeUnt
mkdir $BUILDROOT/wdbed/CrdWdbeRls
mkdir $BUILDROOT/wdbed/CrdWdbeCpr
mkdir $BUILDROOT/wdbed/CrdWdbeCvr
mkdir $BUILDROOT/wdbed/CrdWdbeMod
mkdir $BUILDROOT/wdbed/CrdWdbeVec
mkdir $BUILDROOT/wdbed/CrdWdbeVit
mkdir $BUILDROOT/wdbed/CrdWdbeCmd
mkdir $BUILDROOT/wdbed/CrdWdbeErr
mkdir $BUILDROOT/wdbed/CrdWdbePph
mkdir $BUILDROOT/wdbed/CrdWdbeBnk
mkdir $BUILDROOT/wdbed/CrdWdbePin
mkdir $BUILDROOT/wdbed/CrdWdbeGen
mkdir $BUILDROOT/wdbed/CrdWdbePrt
mkdir $BUILDROOT/wdbed/CrdWdbeSig
mkdir $BUILDROOT/wdbed/CrdWdbePrc
mkdir $BUILDROOT/wdbed/CrdWdbeFst
mkdir $BUILDROOT/wdbed/CrdWdbeVar
mkdir $BUILDROOT/wdbed/CrdWdbeUtl

mkdir $LIBROOT/wdbed

mkdir $BINROOT/wdbed

cp make.sh $BUILDROOT/wdbed/
cp remake.sh $BUILDROOT/wdbed/

cp Makefile.inc $BUILDROOT/wdbed/
cp Makefile $BUILDROOT/wdbed/

cp ../../wdbed/Wdbed.h $BUILDROOT/wdbed/
cp ../../wdbed/Wdbed.cpp $BUILDROOT/wdbed/

cp ../../wdbed/WdbedAppsrv.h $BUILDROOT/wdbed/
cp ../../wdbed/WdbedAppsrv.cpp $BUILDROOT/wdbed/

cp ../../wdbed/WdbedJobprc.h $BUILDROOT/wdbed/
cp ../../wdbed/WdbedJobprc.cpp $BUILDROOT/wdbed/

cp ../../wdbed/WdbedOpprc.h $BUILDROOT/wdbed/
cp ../../wdbed/WdbedOpprc.cpp $BUILDROOT/wdbed/

cp ../../wdbed/WdbedOpengsrv.h $BUILDROOT/wdbed/
cp ../../wdbed/WdbedOpengsrv.cpp $BUILDROOT/wdbed/

cp ../../wdbed/WdbedOpengcli.h $BUILDROOT/wdbed/
cp ../../wdbed/WdbedOpengcli.cpp $BUILDROOT/wdbed/

cp ../../wdbed/Wdbed_exe.h $BUILDROOT/wdbed/
cp ../../wdbed/Wdbed_exe.cpp $BUILDROOT/wdbed/

cp $CMBDBUILDROOT/Wdbe.h $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/Wdbe.cpp $BUILDROOT/wdbed/

cp $CMBDBUILDROOT/Root*.h $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/Root*.cpp $BUILDROOT/wdbed/

cp $CMBDBUILDROOT/Sess*.h $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/Sess*.cpp $BUILDROOT/wdbed/

cp $CMBDBUILDROOT/gbl/*.h $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/gbl/*.cpp $BUILDROOT/wdbed/

cp Makefile_IexWdbe $BUILDROOT/wdbed/IexWdbe/Makefile

cp $CMBDBUILDROOT/IexWdbe/IexWdbe*.h $BUILDROOT/wdbed/IexWdbe/
cp $CMBDBUILDROOT/IexWdbe/IexWdbe*.cpp $BUILDROOT/wdbed/IexWdbe/

cp $CMBDBUILDROOT/IexWdbe/JobWdbeIex*.h $BUILDROOT/wdbed/IexWdbe/
cp $CMBDBUILDROOT/IexWdbe/JobWdbeIex*.cpp $BUILDROOT/wdbed/IexWdbe/

cp Makefile_VecWdbe $BUILDROOT/wdbed/VecWdbe/Makefile

cp $CMBDBUILDROOT/VecWdbe/Vec*.h $BUILDROOT/wdbed/VecWdbe/
cp $CMBDBUILDROOT/VecWdbe/Vec*.cpp $BUILDROOT/wdbed/VecWdbe/

cp Makefile_CrdWdbeUsg $BUILDROOT/wdbed/CrdWdbeUsg/Makefile

cp $CMBDBUILDROOT/CrdWdbeUsg/*.h $BUILDROOT/wdbed/CrdWdbeUsg/
cp $CMBDBUILDROOT/CrdWdbeUsg/*.cpp $BUILDROOT/wdbed/CrdWdbeUsg/

cp Makefile_CrdWdbeUsr $BUILDROOT/wdbed/CrdWdbeUsr/Makefile

cp $CMBDBUILDROOT/CrdWdbeUsr/*.h $BUILDROOT/wdbed/CrdWdbeUsr/
cp $CMBDBUILDROOT/CrdWdbeUsr/*.cpp $BUILDROOT/wdbed/CrdWdbeUsr/

cp Makefile_CrdWdbePrs $BUILDROOT/wdbed/CrdWdbePrs/Makefile

cp $CMBDBUILDROOT/CrdWdbePrs/*.h $BUILDROOT/wdbed/CrdWdbePrs/
cp $CMBDBUILDROOT/CrdWdbePrs/*.cpp $BUILDROOT/wdbed/CrdWdbePrs/

cp Makefile_CrdWdbeFil $BUILDROOT/wdbed/CrdWdbeFil/Makefile

cp $CMBDBUILDROOT/CrdWdbeFil/*.h $BUILDROOT/wdbed/CrdWdbeFil/
cp $CMBDBUILDROOT/CrdWdbeFil/*.cpp $BUILDROOT/wdbed/CrdWdbeFil/

cp Makefile_CrdWdbeNav $BUILDROOT/wdbed/CrdWdbeNav/Makefile

cp $CMBDBUILDROOT/CrdWdbeNav/*.h $BUILDROOT/wdbed/CrdWdbeNav/
cp $CMBDBUILDROOT/CrdWdbeNav/*.cpp $BUILDROOT/wdbed/CrdWdbeNav/

cp Makefile_CrdWdbeMch $BUILDROOT/wdbed/CrdWdbeMch/Makefile

cp $CMBDBUILDROOT/CrdWdbeMch/*.h $BUILDROOT/wdbed/CrdWdbeMch/
cp $CMBDBUILDROOT/CrdWdbeMch/*.cpp $BUILDROOT/wdbed/CrdWdbeMch/

cp Makefile_CrdWdbeLib $BUILDROOT/wdbed/CrdWdbeLib/Makefile

cp $CMBDBUILDROOT/CrdWdbeLib/*.h $BUILDROOT/wdbed/CrdWdbeLib/
cp $CMBDBUILDROOT/CrdWdbeLib/*.cpp $BUILDROOT/wdbed/CrdWdbeLib/

cp Makefile_CrdWdbeFam $BUILDROOT/wdbed/CrdWdbeFam/Makefile

cp $CMBDBUILDROOT/CrdWdbeFam/*.h $BUILDROOT/wdbed/CrdWdbeFam/
cp $CMBDBUILDROOT/CrdWdbeFam/*.cpp $BUILDROOT/wdbed/CrdWdbeFam/

cp Makefile_CrdWdbeSil $BUILDROOT/wdbed/CrdWdbeSil/Makefile

cp $CMBDBUILDROOT/CrdWdbeSil/*.h $BUILDROOT/wdbed/CrdWdbeSil/
cp $CMBDBUILDROOT/CrdWdbeSil/*.cpp $BUILDROOT/wdbed/CrdWdbeSil/

cp Makefile_CrdWdbeMtp $BUILDROOT/wdbed/CrdWdbeMtp/Makefile

cp $CMBDBUILDROOT/CrdWdbeMtp/*.h $BUILDROOT/wdbed/CrdWdbeMtp/
cp $CMBDBUILDROOT/CrdWdbeMtp/*.cpp $BUILDROOT/wdbed/CrdWdbeMtp/

cp Makefile_CrdWdbePrj $BUILDROOT/wdbed/CrdWdbePrj/Makefile

cp $CMBDBUILDROOT/CrdWdbePrj/*.h $BUILDROOT/wdbed/CrdWdbePrj/
cp $CMBDBUILDROOT/CrdWdbePrj/*.cpp $BUILDROOT/wdbed/CrdWdbePrj/

cp Makefile_CrdWdbeVer $BUILDROOT/wdbed/CrdWdbeVer/Makefile

cp $CMBDBUILDROOT/CrdWdbeVer/*.h $BUILDROOT/wdbed/CrdWdbeVer/
cp $CMBDBUILDROOT/CrdWdbeVer/*.cpp $BUILDROOT/wdbed/CrdWdbeVer/

cp Makefile_CrdWdbeSys $BUILDROOT/wdbed/CrdWdbeSys/Makefile

cp $CMBDBUILDROOT/CrdWdbeSys/*.h $BUILDROOT/wdbed/CrdWdbeSys/
cp $CMBDBUILDROOT/CrdWdbeSys/*.cpp $BUILDROOT/wdbed/CrdWdbeSys/

cp Makefile_CrdWdbeTrg $BUILDROOT/wdbed/CrdWdbeTrg/Makefile

cp $CMBDBUILDROOT/CrdWdbeTrg/*.h $BUILDROOT/wdbed/CrdWdbeTrg/
cp $CMBDBUILDROOT/CrdWdbeTrg/*.cpp $BUILDROOT/wdbed/CrdWdbeTrg/

cp Makefile_CrdWdbeUnt $BUILDROOT/wdbed/CrdWdbeUnt/Makefile

cp $CMBDBUILDROOT/CrdWdbeUnt/*.h $BUILDROOT/wdbed/CrdWdbeUnt/
cp $CMBDBUILDROOT/CrdWdbeUnt/*.cpp $BUILDROOT/wdbed/CrdWdbeUnt/

cp Makefile_CrdWdbeRls $BUILDROOT/wdbed/CrdWdbeRls/Makefile

cp $CMBDBUILDROOT/CrdWdbeRls/*.h $BUILDROOT/wdbed/CrdWdbeRls/
cp $CMBDBUILDROOT/CrdWdbeRls/*.cpp $BUILDROOT/wdbed/CrdWdbeRls/

cp Makefile_CrdWdbeCpr $BUILDROOT/wdbed/CrdWdbeCpr/Makefile

cp $CMBDBUILDROOT/CrdWdbeCpr/*.h $BUILDROOT/wdbed/CrdWdbeCpr/
cp $CMBDBUILDROOT/CrdWdbeCpr/*.cpp $BUILDROOT/wdbed/CrdWdbeCpr/

cp Makefile_CrdWdbeCvr $BUILDROOT/wdbed/CrdWdbeCvr/Makefile

cp $CMBDBUILDROOT/CrdWdbeCvr/*.h $BUILDROOT/wdbed/CrdWdbeCvr/
cp $CMBDBUILDROOT/CrdWdbeCvr/*.cpp $BUILDROOT/wdbed/CrdWdbeCvr/

cp Makefile_CrdWdbeMod $BUILDROOT/wdbed/CrdWdbeMod/Makefile

cp $CMBDBUILDROOT/CrdWdbeMod/*.h $BUILDROOT/wdbed/CrdWdbeMod/
cp $CMBDBUILDROOT/CrdWdbeMod/*.cpp $BUILDROOT/wdbed/CrdWdbeMod/

cp Makefile_CrdWdbeVec $BUILDROOT/wdbed/CrdWdbeVec/Makefile

cp $CMBDBUILDROOT/CrdWdbeVec/*.h $BUILDROOT/wdbed/CrdWdbeVec/
cp $CMBDBUILDROOT/CrdWdbeVec/*.cpp $BUILDROOT/wdbed/CrdWdbeVec/

cp Makefile_CrdWdbeVit $BUILDROOT/wdbed/CrdWdbeVit/Makefile

cp $CMBDBUILDROOT/CrdWdbeVit/*.h $BUILDROOT/wdbed/CrdWdbeVit/
cp $CMBDBUILDROOT/CrdWdbeVit/*.cpp $BUILDROOT/wdbed/CrdWdbeVit/

cp Makefile_CrdWdbeCmd $BUILDROOT/wdbed/CrdWdbeCmd/Makefile

cp $CMBDBUILDROOT/CrdWdbeCmd/*.h $BUILDROOT/wdbed/CrdWdbeCmd/
cp $CMBDBUILDROOT/CrdWdbeCmd/*.cpp $BUILDROOT/wdbed/CrdWdbeCmd/

cp Makefile_CrdWdbeErr $BUILDROOT/wdbed/CrdWdbeErr/Makefile

cp $CMBDBUILDROOT/CrdWdbeErr/*.h $BUILDROOT/wdbed/CrdWdbeErr/
cp $CMBDBUILDROOT/CrdWdbeErr/*.cpp $BUILDROOT/wdbed/CrdWdbeErr/

cp Makefile_CrdWdbePph $BUILDROOT/wdbed/CrdWdbePph/Makefile

cp $CMBDBUILDROOT/CrdWdbePph/*.h $BUILDROOT/wdbed/CrdWdbePph/
cp $CMBDBUILDROOT/CrdWdbePph/*.cpp $BUILDROOT/wdbed/CrdWdbePph/

cp Makefile_CrdWdbeBnk $BUILDROOT/wdbed/CrdWdbeBnk/Makefile

cp $CMBDBUILDROOT/CrdWdbeBnk/*.h $BUILDROOT/wdbed/CrdWdbeBnk/
cp $CMBDBUILDROOT/CrdWdbeBnk/*.cpp $BUILDROOT/wdbed/CrdWdbeBnk/

cp Makefile_CrdWdbePin $BUILDROOT/wdbed/CrdWdbePin/Makefile

cp $CMBDBUILDROOT/CrdWdbePin/*.h $BUILDROOT/wdbed/CrdWdbePin/
cp $CMBDBUILDROOT/CrdWdbePin/*.cpp $BUILDROOT/wdbed/CrdWdbePin/

cp Makefile_CrdWdbeGen $BUILDROOT/wdbed/CrdWdbeGen/Makefile

cp $CMBDBUILDROOT/CrdWdbeGen/*.h $BUILDROOT/wdbed/CrdWdbeGen/
cp $CMBDBUILDROOT/CrdWdbeGen/*.cpp $BUILDROOT/wdbed/CrdWdbeGen/

cp Makefile_CrdWdbePrt $BUILDROOT/wdbed/CrdWdbePrt/Makefile

cp $CMBDBUILDROOT/CrdWdbePrt/*.h $BUILDROOT/wdbed/CrdWdbePrt/
cp $CMBDBUILDROOT/CrdWdbePrt/*.cpp $BUILDROOT/wdbed/CrdWdbePrt/

cp Makefile_CrdWdbeSig $BUILDROOT/wdbed/CrdWdbeSig/Makefile

cp $CMBDBUILDROOT/CrdWdbeSig/*.h $BUILDROOT/wdbed/CrdWdbeSig/
cp $CMBDBUILDROOT/CrdWdbeSig/*.cpp $BUILDROOT/wdbed/CrdWdbeSig/

cp Makefile_CrdWdbePrc $BUILDROOT/wdbed/CrdWdbePrc/Makefile

cp $CMBDBUILDROOT/CrdWdbePrc/*.h $BUILDROOT/wdbed/CrdWdbePrc/
cp $CMBDBUILDROOT/CrdWdbePrc/*.cpp $BUILDROOT/wdbed/CrdWdbePrc/

cp Makefile_CrdWdbeFst $BUILDROOT/wdbed/CrdWdbeFst/Makefile

cp $CMBDBUILDROOT/CrdWdbeFst/*.h $BUILDROOT/wdbed/CrdWdbeFst/
cp $CMBDBUILDROOT/CrdWdbeFst/*.cpp $BUILDROOT/wdbed/CrdWdbeFst/

cp Makefile_CrdWdbeVar $BUILDROOT/wdbed/CrdWdbeVar/Makefile

cp $CMBDBUILDROOT/CrdWdbeVar/*.h $BUILDROOT/wdbed/CrdWdbeVar/
cp $CMBDBUILDROOT/CrdWdbeVar/*.cpp $BUILDROOT/wdbed/CrdWdbeVar/

cp Makefile_CrdWdbeUtl $BUILDROOT/wdbed/CrdWdbeUtl/Makefile

cp $CMBDBUILDROOT/CrdWdbeUtl/*.h $BUILDROOT/wdbed/CrdWdbeUtl/
cp $CMBDBUILDROOT/CrdWdbeUtl/*.cpp $BUILDROOT/wdbed/CrdWdbeUtl/

cp $CMBDBUILDROOT/WdbeWrmcu/WdbeWrmcu_blks.h $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbeWrmcu/WdbeWrmcu_blks.cpp $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbeWrmcu/SqkWdbeWrmcu.h $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbeWrmcu/SqkWdbeWrmcu.cpp $BUILDROOT/wdbed/

cp $CMBDBUILDROOT/WdbePlhmcu/WdbePlhmcu_blks.h $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbePlhmcu/WdbePlhmcu_blks.cpp $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbePlhmcu/SqkWdbePlhmcu.h $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbePlhmcu/SqkWdbePlhmcu.cpp $BUILDROOT/wdbed/

cp $CMBDBUILDROOT/WdbeWrfpga/WdbeWrfpga_blks.h $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbeWrfpga/WdbeWrfpga_blks.cpp $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbeWrfpga/SqkWdbeWrfpga.h $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbeWrfpga/SqkWdbeWrfpga.cpp $BUILDROOT/wdbed/

cp $CMBDBUILDROOT/WdbeWrdev/WdbeWrdev_blks.h $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbeWrdev/WdbeWrdev_blks.cpp $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbeWrdev/SqkWdbeWrdev.h $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbeWrdev/SqkWdbeWrdev.cpp $BUILDROOT/wdbed/

cp $CMBDBUILDROOT/WdbePrctree/WdbePrctree_blks.h $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbePrctree/WdbePrctree_blks.cpp $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbePrctree/SqkWdbePrctree.h $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbePrctree/SqkWdbePrctree.cpp $BUILDROOT/wdbed/

cp $CMBDBUILDROOT/WdbePrcfile/WdbePrcfile_blks.h $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbePrcfile/WdbePrcfile_blks.cpp $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbePrcfile/SqkWdbePrcfile.h $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbePrcfile/SqkWdbePrcfile.cpp $BUILDROOT/wdbed/

cp $CMBDBUILDROOT/WdbePlhfpga/WdbePlhfpga_blks.h $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbePlhfpga/WdbePlhfpga_blks.cpp $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbePlhfpga/SqkWdbePlhfpga.h $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbePlhfpga/SqkWdbePlhfpga.cpp $BUILDROOT/wdbed/

cp $CMBDBUILDROOT/WdbeMtpWrmcu/WdbeMtpWrmcu_blks.h $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbeMtpWrmcu/WdbeMtpWrmcu_blks.cpp $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbeMtpWrmcu/SqkWdbeMtpWrmcu.h $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbeMtpWrmcu/SqkWdbeMtpWrmcu.cpp $BUILDROOT/wdbed/

cp $CMBDBUILDROOT/WdbeMtpModdet/WdbeMtpModdet_blks.h $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbeMtpModdet/WdbeMtpModdet_blks.cpp $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbeMtpModdet/SqkWdbeMtpModdet.h $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbeMtpModdet/SqkWdbeMtpModdet.cpp $BUILDROOT/wdbed/

cp $CMBDBUILDROOT/WdbeMtpWrfpga/WdbeMtpWrfpga_blks.h $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbeMtpWrfpga/WdbeMtpWrfpga_blks.cpp $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbeMtpWrfpga/SqkWdbeMtpWrfpga.h $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbeMtpWrfpga/SqkWdbeMtpWrfpga.cpp $BUILDROOT/wdbed/

cp $CMBDBUILDROOT/WdbeMtpModbsctd/WdbeMtpModbsctd_blks.h $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbeMtpModbsctd/WdbeMtpModbsctd_blks.cpp $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbeMtpModbsctd/SqkWdbeMtpModbsctd.h $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbeMtpModbsctd/SqkWdbeMtpModbsctd.cpp $BUILDROOT/wdbed/

cp $CMBDBUILDROOT/WdbeMtpModbscbu/WdbeMtpModbscbu_blks.h $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbeMtpModbscbu/WdbeMtpModbscbu_blks.cpp $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbeMtpModbscbu/SqkWdbeMtpModbscbu.h $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbeMtpModbscbu/SqkWdbeMtpModbscbu.cpp $BUILDROOT/wdbed/

cp $CMBDBUILDROOT/WdbeMtpPlhfpga/WdbeMtpPlhfpga_blks.h $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbeMtpPlhfpga/WdbeMtpPlhfpga_blks.cpp $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbeMtpPlhfpga/SqkWdbeMtpPlhfpga.h $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbeMtpPlhfpga/SqkWdbeMtpPlhfpga.cpp $BUILDROOT/wdbed/

cp $CMBDBUILDROOT/WdbeMtpPlhmcu/WdbeMtpPlhmcu_blks.h $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbeMtpPlhmcu/WdbeMtpPlhmcu_blks.cpp $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbeMtpPlhmcu/SqkWdbeMtpPlhmcu.h $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbeMtpPlhmcu/SqkWdbeMtpPlhmcu.cpp $BUILDROOT/wdbed/

cp $CMBDBUILDROOT/WdbeModdet/WdbeModdet_blks.h $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbeModdet/WdbeModdet_blks.cpp $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbeModdet/SqkWdbeModdet.h $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbeModdet/SqkWdbeModdet.cpp $BUILDROOT/wdbed/

cp $CMBDBUILDROOT/WdbeModbsc/WdbeModbsc_blks.h $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbeModbsc/WdbeModbsc_blks.cpp $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbeModbsc/SqkWdbeModbsc.h $BUILDROOT/wdbed/
cp $CMBDBUILDROOT/WdbeModbsc/SqkWdbeModbsc.cpp $BUILDROOT/wdbed/
