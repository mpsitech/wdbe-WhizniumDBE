#!/bin/bash
# file checkout.sh
# checkout script for Wdbe daemon, release wdbed_awsubt
# author Alexander Wirthmueller
# date created: 11 Jul 2020
# modified: 11 Jul 2020

export set SRCROOT=/home/ubuntu/src
export set LIBROOT=/home/ubuntu/lib
export set BINROOT=/home/ubuntu/bin
export set REPROOT=/home/ubuntu/srcrep
export set CMBDSRCROOT=$REPROOT/wdbe/wdbecmbd

mkdir $SRCROOT/wdbed
mkdir $SRCROOT/wdbed/IexWdbe
mkdir $SRCROOT/wdbed/VecWdbe
mkdir $SRCROOT/wdbed/CrdWdbeUsg
mkdir $SRCROOT/wdbed/CrdWdbeUsr
mkdir $SRCROOT/wdbed/CrdWdbePrs
mkdir $SRCROOT/wdbed/CrdWdbeFil
mkdir $SRCROOT/wdbed/CrdWdbeNav
mkdir $SRCROOT/wdbed/CrdWdbeMch
mkdir $SRCROOT/wdbed/CrdWdbeLib
mkdir $SRCROOT/wdbed/CrdWdbeFam
mkdir $SRCROOT/wdbed/CrdWdbeSil
mkdir $SRCROOT/wdbed/CrdWdbeMtp
mkdir $SRCROOT/wdbed/CrdWdbePrj
mkdir $SRCROOT/wdbed/CrdWdbeVer
mkdir $SRCROOT/wdbed/CrdWdbeSys
mkdir $SRCROOT/wdbed/CrdWdbeTrg
mkdir $SRCROOT/wdbed/CrdWdbeUnt
mkdir $SRCROOT/wdbed/CrdWdbeRls
mkdir $SRCROOT/wdbed/CrdWdbeCpr
mkdir $SRCROOT/wdbed/CrdWdbeCvr
mkdir $SRCROOT/wdbed/CrdWdbeMod
mkdir $SRCROOT/wdbed/CrdWdbeVec
mkdir $SRCROOT/wdbed/CrdWdbeVit
mkdir $SRCROOT/wdbed/CrdWdbeCmd
mkdir $SRCROOT/wdbed/CrdWdbeErr
mkdir $SRCROOT/wdbed/CrdWdbePph
mkdir $SRCROOT/wdbed/CrdWdbeBnk
mkdir $SRCROOT/wdbed/CrdWdbePin
mkdir $SRCROOT/wdbed/CrdWdbeGen
mkdir $SRCROOT/wdbed/CrdWdbePrt
mkdir $SRCROOT/wdbed/CrdWdbeSig
mkdir $SRCROOT/wdbed/CrdWdbePrc
mkdir $SRCROOT/wdbed/CrdWdbeFst
mkdir $SRCROOT/wdbed/CrdWdbeVar
mkdir $SRCROOT/wdbed/CrdWdbeUtl

mkdir $LIBROOT/wdbed

mkdir $BINROOT/wdbed

cp make.sh $SRCROOT/wdbed/
cp remake.sh $SRCROOT/wdbed/

cp Makefile.inc $SRCROOT/wdbed/
cp Makefile $SRCROOT/wdbed/

cp ../../wdbed/Wdbed.h $SRCROOT/wdbed/
cp ../../wdbed/Wdbed.cpp $SRCROOT/wdbed/

cp ../../wdbed/WdbedAppsrv.h $SRCROOT/wdbed/
cp ../../wdbed/WdbedAppsrv.cpp $SRCROOT/wdbed/

cp ../../wdbed/WdbedJobprc.h $SRCROOT/wdbed/
cp ../../wdbed/WdbedJobprc.cpp $SRCROOT/wdbed/

cp ../../wdbed/WdbedOpprc.h $SRCROOT/wdbed/
cp ../../wdbed/WdbedOpprc.cpp $SRCROOT/wdbed/

cp ../../wdbed/WdbedOpengsrv.h $SRCROOT/wdbed/
cp ../../wdbed/WdbedOpengsrv.cpp $SRCROOT/wdbed/

cp ../../wdbed/WdbedOpengcli.h $SRCROOT/wdbed/
cp ../../wdbed/WdbedOpengcli.cpp $SRCROOT/wdbed/

cp ../../wdbed/Wdbed_exe.h $SRCROOT/wdbed/
cp ../../wdbed/Wdbed_exe.cpp $SRCROOT/wdbed/

cp $CMBDSRCROOT/Wdbe.h $SRCROOT/wdbed/
cp $CMBDSRCROOT/Wdbe.cpp $SRCROOT/wdbed/

cp $CMBDSRCROOT/Root*.h $SRCROOT/wdbed/
cp $CMBDSRCROOT/Root*.cpp $SRCROOT/wdbed/

cp $CMBDSRCROOT/Sess*.h $SRCROOT/wdbed/
cp $CMBDSRCROOT/Sess*.cpp $SRCROOT/wdbed/

cp $CMBDSRCROOT/gbl/*.h $SRCROOT/wdbed/
cp $CMBDSRCROOT/gbl/*.cpp $SRCROOT/wdbed/

cp Makefile_IexWdbe $SRCROOT/wdbed/IexWdbe/Makefile

cp $CMBDSRCROOT/IexWdbe/IexWdbe*.h $SRCROOT/wdbed/IexWdbe/
cp $CMBDSRCROOT/IexWdbe/IexWdbe*.cpp $SRCROOT/wdbed/IexWdbe/

cp $CMBDSRCROOT/IexWdbe/JobWdbeIex*.h $SRCROOT/wdbed/IexWdbe/
cp $CMBDSRCROOT/IexWdbe/JobWdbeIex*.cpp $SRCROOT/wdbed/IexWdbe/

cp Makefile_VecWdbe $SRCROOT/wdbed/VecWdbe/Makefile

cp $CMBDSRCROOT/VecWdbe/Vec*.h $SRCROOT/wdbed/VecWdbe/
cp $CMBDSRCROOT/VecWdbe/Vec*.cpp $SRCROOT/wdbed/VecWdbe/

cp Makefile_CrdWdbeUsg $SRCROOT/wdbed/CrdWdbeUsg/Makefile

cp $CMBDSRCROOT/CrdWdbeUsg/*.h $SRCROOT/wdbed/CrdWdbeUsg/
cp $CMBDSRCROOT/CrdWdbeUsg/*.cpp $SRCROOT/wdbed/CrdWdbeUsg/

cp Makefile_CrdWdbeUsr $SRCROOT/wdbed/CrdWdbeUsr/Makefile

cp $CMBDSRCROOT/CrdWdbeUsr/*.h $SRCROOT/wdbed/CrdWdbeUsr/
cp $CMBDSRCROOT/CrdWdbeUsr/*.cpp $SRCROOT/wdbed/CrdWdbeUsr/

cp Makefile_CrdWdbePrs $SRCROOT/wdbed/CrdWdbePrs/Makefile

cp $CMBDSRCROOT/CrdWdbePrs/*.h $SRCROOT/wdbed/CrdWdbePrs/
cp $CMBDSRCROOT/CrdWdbePrs/*.cpp $SRCROOT/wdbed/CrdWdbePrs/

cp Makefile_CrdWdbeFil $SRCROOT/wdbed/CrdWdbeFil/Makefile

cp $CMBDSRCROOT/CrdWdbeFil/*.h $SRCROOT/wdbed/CrdWdbeFil/
cp $CMBDSRCROOT/CrdWdbeFil/*.cpp $SRCROOT/wdbed/CrdWdbeFil/

cp Makefile_CrdWdbeNav $SRCROOT/wdbed/CrdWdbeNav/Makefile

cp $CMBDSRCROOT/CrdWdbeNav/*.h $SRCROOT/wdbed/CrdWdbeNav/
cp $CMBDSRCROOT/CrdWdbeNav/*.cpp $SRCROOT/wdbed/CrdWdbeNav/

cp Makefile_CrdWdbeMch $SRCROOT/wdbed/CrdWdbeMch/Makefile

cp $CMBDSRCROOT/CrdWdbeMch/*.h $SRCROOT/wdbed/CrdWdbeMch/
cp $CMBDSRCROOT/CrdWdbeMch/*.cpp $SRCROOT/wdbed/CrdWdbeMch/

cp Makefile_CrdWdbeLib $SRCROOT/wdbed/CrdWdbeLib/Makefile

cp $CMBDSRCROOT/CrdWdbeLib/*.h $SRCROOT/wdbed/CrdWdbeLib/
cp $CMBDSRCROOT/CrdWdbeLib/*.cpp $SRCROOT/wdbed/CrdWdbeLib/

cp Makefile_CrdWdbeFam $SRCROOT/wdbed/CrdWdbeFam/Makefile

cp $CMBDSRCROOT/CrdWdbeFam/*.h $SRCROOT/wdbed/CrdWdbeFam/
cp $CMBDSRCROOT/CrdWdbeFam/*.cpp $SRCROOT/wdbed/CrdWdbeFam/

cp Makefile_CrdWdbeSil $SRCROOT/wdbed/CrdWdbeSil/Makefile

cp $CMBDSRCROOT/CrdWdbeSil/*.h $SRCROOT/wdbed/CrdWdbeSil/
cp $CMBDSRCROOT/CrdWdbeSil/*.cpp $SRCROOT/wdbed/CrdWdbeSil/

cp Makefile_CrdWdbeMtp $SRCROOT/wdbed/CrdWdbeMtp/Makefile

cp $CMBDSRCROOT/CrdWdbeMtp/*.h $SRCROOT/wdbed/CrdWdbeMtp/
cp $CMBDSRCROOT/CrdWdbeMtp/*.cpp $SRCROOT/wdbed/CrdWdbeMtp/

cp Makefile_CrdWdbePrj $SRCROOT/wdbed/CrdWdbePrj/Makefile

cp $CMBDSRCROOT/CrdWdbePrj/*.h $SRCROOT/wdbed/CrdWdbePrj/
cp $CMBDSRCROOT/CrdWdbePrj/*.cpp $SRCROOT/wdbed/CrdWdbePrj/

cp Makefile_CrdWdbeVer $SRCROOT/wdbed/CrdWdbeVer/Makefile

cp $CMBDSRCROOT/CrdWdbeVer/*.h $SRCROOT/wdbed/CrdWdbeVer/
cp $CMBDSRCROOT/CrdWdbeVer/*.cpp $SRCROOT/wdbed/CrdWdbeVer/

cp Makefile_CrdWdbeSys $SRCROOT/wdbed/CrdWdbeSys/Makefile

cp $CMBDSRCROOT/CrdWdbeSys/*.h $SRCROOT/wdbed/CrdWdbeSys/
cp $CMBDSRCROOT/CrdWdbeSys/*.cpp $SRCROOT/wdbed/CrdWdbeSys/

cp Makefile_CrdWdbeTrg $SRCROOT/wdbed/CrdWdbeTrg/Makefile

cp $CMBDSRCROOT/CrdWdbeTrg/*.h $SRCROOT/wdbed/CrdWdbeTrg/
cp $CMBDSRCROOT/CrdWdbeTrg/*.cpp $SRCROOT/wdbed/CrdWdbeTrg/

cp Makefile_CrdWdbeUnt $SRCROOT/wdbed/CrdWdbeUnt/Makefile

cp $CMBDSRCROOT/CrdWdbeUnt/*.h $SRCROOT/wdbed/CrdWdbeUnt/
cp $CMBDSRCROOT/CrdWdbeUnt/*.cpp $SRCROOT/wdbed/CrdWdbeUnt/

cp Makefile_CrdWdbeRls $SRCROOT/wdbed/CrdWdbeRls/Makefile

cp $CMBDSRCROOT/CrdWdbeRls/*.h $SRCROOT/wdbed/CrdWdbeRls/
cp $CMBDSRCROOT/CrdWdbeRls/*.cpp $SRCROOT/wdbed/CrdWdbeRls/

cp Makefile_CrdWdbeCpr $SRCROOT/wdbed/CrdWdbeCpr/Makefile

cp $CMBDSRCROOT/CrdWdbeCpr/*.h $SRCROOT/wdbed/CrdWdbeCpr/
cp $CMBDSRCROOT/CrdWdbeCpr/*.cpp $SRCROOT/wdbed/CrdWdbeCpr/

cp Makefile_CrdWdbeCvr $SRCROOT/wdbed/CrdWdbeCvr/Makefile

cp $CMBDSRCROOT/CrdWdbeCvr/*.h $SRCROOT/wdbed/CrdWdbeCvr/
cp $CMBDSRCROOT/CrdWdbeCvr/*.cpp $SRCROOT/wdbed/CrdWdbeCvr/

cp Makefile_CrdWdbeMod $SRCROOT/wdbed/CrdWdbeMod/Makefile

cp $CMBDSRCROOT/CrdWdbeMod/*.h $SRCROOT/wdbed/CrdWdbeMod/
cp $CMBDSRCROOT/CrdWdbeMod/*.cpp $SRCROOT/wdbed/CrdWdbeMod/

cp Makefile_CrdWdbeVec $SRCROOT/wdbed/CrdWdbeVec/Makefile

cp $CMBDSRCROOT/CrdWdbeVec/*.h $SRCROOT/wdbed/CrdWdbeVec/
cp $CMBDSRCROOT/CrdWdbeVec/*.cpp $SRCROOT/wdbed/CrdWdbeVec/

cp Makefile_CrdWdbeVit $SRCROOT/wdbed/CrdWdbeVit/Makefile

cp $CMBDSRCROOT/CrdWdbeVit/*.h $SRCROOT/wdbed/CrdWdbeVit/
cp $CMBDSRCROOT/CrdWdbeVit/*.cpp $SRCROOT/wdbed/CrdWdbeVit/

cp Makefile_CrdWdbeCmd $SRCROOT/wdbed/CrdWdbeCmd/Makefile

cp $CMBDSRCROOT/CrdWdbeCmd/*.h $SRCROOT/wdbed/CrdWdbeCmd/
cp $CMBDSRCROOT/CrdWdbeCmd/*.cpp $SRCROOT/wdbed/CrdWdbeCmd/

cp Makefile_CrdWdbeErr $SRCROOT/wdbed/CrdWdbeErr/Makefile

cp $CMBDSRCROOT/CrdWdbeErr/*.h $SRCROOT/wdbed/CrdWdbeErr/
cp $CMBDSRCROOT/CrdWdbeErr/*.cpp $SRCROOT/wdbed/CrdWdbeErr/

cp Makefile_CrdWdbePph $SRCROOT/wdbed/CrdWdbePph/Makefile

cp $CMBDSRCROOT/CrdWdbePph/*.h $SRCROOT/wdbed/CrdWdbePph/
cp $CMBDSRCROOT/CrdWdbePph/*.cpp $SRCROOT/wdbed/CrdWdbePph/

cp Makefile_CrdWdbeBnk $SRCROOT/wdbed/CrdWdbeBnk/Makefile

cp $CMBDSRCROOT/CrdWdbeBnk/*.h $SRCROOT/wdbed/CrdWdbeBnk/
cp $CMBDSRCROOT/CrdWdbeBnk/*.cpp $SRCROOT/wdbed/CrdWdbeBnk/

cp Makefile_CrdWdbePin $SRCROOT/wdbed/CrdWdbePin/Makefile

cp $CMBDSRCROOT/CrdWdbePin/*.h $SRCROOT/wdbed/CrdWdbePin/
cp $CMBDSRCROOT/CrdWdbePin/*.cpp $SRCROOT/wdbed/CrdWdbePin/

cp Makefile_CrdWdbeGen $SRCROOT/wdbed/CrdWdbeGen/Makefile

cp $CMBDSRCROOT/CrdWdbeGen/*.h $SRCROOT/wdbed/CrdWdbeGen/
cp $CMBDSRCROOT/CrdWdbeGen/*.cpp $SRCROOT/wdbed/CrdWdbeGen/

cp Makefile_CrdWdbePrt $SRCROOT/wdbed/CrdWdbePrt/Makefile

cp $CMBDSRCROOT/CrdWdbePrt/*.h $SRCROOT/wdbed/CrdWdbePrt/
cp $CMBDSRCROOT/CrdWdbePrt/*.cpp $SRCROOT/wdbed/CrdWdbePrt/

cp Makefile_CrdWdbeSig $SRCROOT/wdbed/CrdWdbeSig/Makefile

cp $CMBDSRCROOT/CrdWdbeSig/*.h $SRCROOT/wdbed/CrdWdbeSig/
cp $CMBDSRCROOT/CrdWdbeSig/*.cpp $SRCROOT/wdbed/CrdWdbeSig/

cp Makefile_CrdWdbePrc $SRCROOT/wdbed/CrdWdbePrc/Makefile

cp $CMBDSRCROOT/CrdWdbePrc/*.h $SRCROOT/wdbed/CrdWdbePrc/
cp $CMBDSRCROOT/CrdWdbePrc/*.cpp $SRCROOT/wdbed/CrdWdbePrc/

cp Makefile_CrdWdbeFst $SRCROOT/wdbed/CrdWdbeFst/Makefile

cp $CMBDSRCROOT/CrdWdbeFst/*.h $SRCROOT/wdbed/CrdWdbeFst/
cp $CMBDSRCROOT/CrdWdbeFst/*.cpp $SRCROOT/wdbed/CrdWdbeFst/

cp Makefile_CrdWdbeVar $SRCROOT/wdbed/CrdWdbeVar/Makefile

cp $CMBDSRCROOT/CrdWdbeVar/*.h $SRCROOT/wdbed/CrdWdbeVar/
cp $CMBDSRCROOT/CrdWdbeVar/*.cpp $SRCROOT/wdbed/CrdWdbeVar/

cp Makefile_CrdWdbeUtl $SRCROOT/wdbed/CrdWdbeUtl/Makefile

cp $CMBDSRCROOT/CrdWdbeUtl/*.h $SRCROOT/wdbed/CrdWdbeUtl/
cp $CMBDSRCROOT/CrdWdbeUtl/*.cpp $SRCROOT/wdbed/CrdWdbeUtl/

cp $CMBDSRCROOT/WdbeWrmcu/WdbeWrmcu_blks.h $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbeWrmcu/WdbeWrmcu_blks.cpp $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbeWrmcu/SqkWdbeWrmcu.h $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbeWrmcu/SqkWdbeWrmcu.cpp $SRCROOT/wdbed/

cp $CMBDSRCROOT/WdbeWrfpga/WdbeWrfpga_blks.h $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbeWrfpga/WdbeWrfpga_blks.cpp $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbeWrfpga/SqkWdbeWrfpga.h $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbeWrfpga/SqkWdbeWrfpga.cpp $SRCROOT/wdbed/

cp $CMBDSRCROOT/WdbeWrdev/WdbeWrdev_blks.h $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbeWrdev/WdbeWrdev_blks.cpp $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbeWrdev/SqkWdbeWrdev.h $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbeWrdev/SqkWdbeWrdev.cpp $SRCROOT/wdbed/

cp $CMBDSRCROOT/WdbePrctree/WdbePrctree_blks.h $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbePrctree/WdbePrctree_blks.cpp $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbePrctree/SqkWdbePrctree.h $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbePrctree/SqkWdbePrctree.cpp $SRCROOT/wdbed/

cp $CMBDSRCROOT/WdbePrcfile/WdbePrcfile_blks.h $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbePrcfile/WdbePrcfile_blks.cpp $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbePrcfile/SqkWdbePrcfile.h $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbePrcfile/SqkWdbePrcfile.cpp $SRCROOT/wdbed/

cp $CMBDSRCROOT/WdbePlhmcu/WdbePlhmcu_blks.h $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbePlhmcu/WdbePlhmcu_blks.cpp $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbePlhmcu/SqkWdbePlhmcu.h $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbePlhmcu/SqkWdbePlhmcu.cpp $SRCROOT/wdbed/

cp $CMBDSRCROOT/WdbePlhfpga/WdbePlhfpga_blks.h $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbePlhfpga/WdbePlhfpga_blks.cpp $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbePlhfpga/SqkWdbePlhfpga.h $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbePlhfpga/SqkWdbePlhfpga.cpp $SRCROOT/wdbed/

cp $CMBDSRCROOT/WdbeMtpWrmcu/WdbeMtpWrmcu_blks.h $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbeMtpWrmcu/WdbeMtpWrmcu_blks.cpp $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbeMtpWrmcu/SqkWdbeMtpWrmcu.h $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbeMtpWrmcu/SqkWdbeMtpWrmcu.cpp $SRCROOT/wdbed/

cp $CMBDSRCROOT/WdbeMtpWrfpga/WdbeMtpWrfpga_blks.h $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbeMtpWrfpga/WdbeMtpWrfpga_blks.cpp $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbeMtpWrfpga/SqkWdbeMtpWrfpga.h $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbeMtpWrfpga/SqkWdbeMtpWrfpga.cpp $SRCROOT/wdbed/

cp $CMBDSRCROOT/WdbeMtpModdet/WdbeMtpModdet_blks.h $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbeMtpModdet/WdbeMtpModdet_blks.cpp $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbeMtpModdet/SqkWdbeMtpModdet.h $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbeMtpModdet/SqkWdbeMtpModdet.cpp $SRCROOT/wdbed/

cp $CMBDSRCROOT/WdbeMtpModbsctd/WdbeMtpModbsctd_blks.h $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbeMtpModbsctd/WdbeMtpModbsctd_blks.cpp $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbeMtpModbsctd/SqkWdbeMtpModbsctd.h $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbeMtpModbsctd/SqkWdbeMtpModbsctd.cpp $SRCROOT/wdbed/

cp $CMBDSRCROOT/WdbeMtpModbscbu/WdbeMtpModbscbu_blks.h $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbeMtpModbscbu/WdbeMtpModbscbu_blks.cpp $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbeMtpModbscbu/SqkWdbeMtpModbscbu.h $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbeMtpModbscbu/SqkWdbeMtpModbscbu.cpp $SRCROOT/wdbed/

cp $CMBDSRCROOT/WdbeMtpPlhmcu/WdbeMtpPlhmcu_blks.h $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbeMtpPlhmcu/WdbeMtpPlhmcu_blks.cpp $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbeMtpPlhmcu/SqkWdbeMtpPlhmcu.h $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbeMtpPlhmcu/SqkWdbeMtpPlhmcu.cpp $SRCROOT/wdbed/

cp $CMBDSRCROOT/WdbeMtpPlhfpga/WdbeMtpPlhfpga_blks.h $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbeMtpPlhfpga/WdbeMtpPlhfpga_blks.cpp $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbeMtpPlhfpga/SqkWdbeMtpPlhfpga.h $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbeMtpPlhfpga/SqkWdbeMtpPlhfpga.cpp $SRCROOT/wdbed/

cp $CMBDSRCROOT/WdbeModdet/WdbeModdet_blks.h $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbeModdet/WdbeModdet_blks.cpp $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbeModdet/SqkWdbeModdet.h $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbeModdet/SqkWdbeModdet.cpp $SRCROOT/wdbed/

cp $CMBDSRCROOT/WdbeModbsc/WdbeModbsc_blks.h $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbeModbsc/WdbeModbsc_blks.cpp $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbeModbsc/SqkWdbeModbsc.h $SRCROOT/wdbed/
cp $CMBDSRCROOT/WdbeModbsc/SqkWdbeModbsc.cpp $SRCROOT/wdbed/

