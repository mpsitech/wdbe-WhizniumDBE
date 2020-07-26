#!/bin/bash
# file checkout.sh
# checkout script for Wdbe combined daemon, release wdbecmbd_jack
# author Alexander Wirthmueller
# date created: 11 Jul 2020
# modified: 11 Jul 2020

export set SRCROOT=/home/mpsitech/src
export set LIBROOT=/home/mpsitech/lib
export set BINROOT=/home/mpsitech/bin

mkdir $SRCROOT/wdbecmbd
mkdir $SRCROOT/wdbecmbd/IexWdbe
mkdir $SRCROOT/wdbecmbd/VecWdbe
mkdir $SRCROOT/wdbecmbd/CrdWdbeUsg
mkdir $SRCROOT/wdbecmbd/CrdWdbeUsr
mkdir $SRCROOT/wdbecmbd/CrdWdbePrs
mkdir $SRCROOT/wdbecmbd/CrdWdbeFil
mkdir $SRCROOT/wdbecmbd/CrdWdbeNav
mkdir $SRCROOT/wdbecmbd/CrdWdbeMch
mkdir $SRCROOT/wdbecmbd/CrdWdbeLib
mkdir $SRCROOT/wdbecmbd/CrdWdbeFam
mkdir $SRCROOT/wdbecmbd/CrdWdbeSil
mkdir $SRCROOT/wdbecmbd/CrdWdbeMtp
mkdir $SRCROOT/wdbecmbd/CrdWdbePrj
mkdir $SRCROOT/wdbecmbd/CrdWdbeVer
mkdir $SRCROOT/wdbecmbd/CrdWdbeSys
mkdir $SRCROOT/wdbecmbd/CrdWdbeTrg
mkdir $SRCROOT/wdbecmbd/CrdWdbeUnt
mkdir $SRCROOT/wdbecmbd/CrdWdbeRls
mkdir $SRCROOT/wdbecmbd/CrdWdbeCpr
mkdir $SRCROOT/wdbecmbd/CrdWdbeCvr
mkdir $SRCROOT/wdbecmbd/CrdWdbeMod
mkdir $SRCROOT/wdbecmbd/CrdWdbeVec
mkdir $SRCROOT/wdbecmbd/CrdWdbeVit
mkdir $SRCROOT/wdbecmbd/CrdWdbeCmd
mkdir $SRCROOT/wdbecmbd/CrdWdbeErr
mkdir $SRCROOT/wdbecmbd/CrdWdbePph
mkdir $SRCROOT/wdbecmbd/CrdWdbeBnk
mkdir $SRCROOT/wdbecmbd/CrdWdbePin
mkdir $SRCROOT/wdbecmbd/CrdWdbeGen
mkdir $SRCROOT/wdbecmbd/CrdWdbePrt
mkdir $SRCROOT/wdbecmbd/CrdWdbeSig
mkdir $SRCROOT/wdbecmbd/CrdWdbePrc
mkdir $SRCROOT/wdbecmbd/CrdWdbeFst
mkdir $SRCROOT/wdbecmbd/CrdWdbeVar
mkdir $SRCROOT/wdbecmbd/CrdWdbeUtl
mkdir $SRCROOT/wdbecmbd/WdbeWrmcu
mkdir $SRCROOT/wdbecmbd/WdbeWrfpga
mkdir $SRCROOT/wdbecmbd/WdbeWrdev
mkdir $SRCROOT/wdbecmbd/WdbePrctree
mkdir $SRCROOT/wdbecmbd/WdbePrcfile
mkdir $SRCROOT/wdbecmbd/WdbePlhmcu
mkdir $SRCROOT/wdbecmbd/WdbePlhfpga
mkdir $SRCROOT/wdbecmbd/WdbeMtpWrmcu
mkdir $SRCROOT/wdbecmbd/WdbeMtpWrfpga
mkdir $SRCROOT/wdbecmbd/WdbeMtpModdet
mkdir $SRCROOT/wdbecmbd/WdbeMtpModbsctd
mkdir $SRCROOT/wdbecmbd/WdbeMtpModbscbu
mkdir $SRCROOT/wdbecmbd/WdbeMtpPlhmcu
mkdir $SRCROOT/wdbecmbd/WdbeMtpPlhfpga
mkdir $SRCROOT/wdbecmbd/WdbeModdet
mkdir $SRCROOT/wdbecmbd/WdbeModbsc

mkdir $LIBROOT/wdbecmbd

mkdir $BINROOT/wdbecmbd

cp make.sh $SRCROOT/wdbecmbd/
cp remake.sh $SRCROOT/wdbecmbd/

cp Makefile.inc $SRCROOT/wdbecmbd/
cp Makefile $SRCROOT/wdbecmbd/

cp ../../wdbecmbd/Wdbecmbd.h $SRCROOT/wdbecmbd/
cp ../../wdbecmbd/Wdbecmbd.cpp $SRCROOT/wdbecmbd/

cp ../../wdbecmbd/WdbecmbdAppsrv.h $SRCROOT/wdbecmbd/
cp ../../wdbecmbd/WdbecmbdAppsrv.cpp $SRCROOT/wdbecmbd/

cp ../../wdbecmbd/WdbecmbdJobprc.h $SRCROOT/wdbecmbd/
cp ../../wdbecmbd/WdbecmbdJobprc.cpp $SRCROOT/wdbecmbd/

cp ../../wdbecmbd/WdbecmbdOpprc.h $SRCROOT/wdbecmbd/
cp ../../wdbecmbd/WdbecmbdOpprc.cpp $SRCROOT/wdbecmbd/

cp ../../wdbecmbd/Wdbecmbd_exe.h $SRCROOT/wdbecmbd/
cp ../../wdbecmbd/Wdbecmbd_exe.cpp $SRCROOT/wdbecmbd/

cp ../../wdbecmbd/Wdbe.h $SRCROOT/wdbecmbd/
cp ../../wdbecmbd/Wdbe.cpp $SRCROOT/wdbecmbd/

cp ../../wdbecmbd/Root*.h $SRCROOT/wdbecmbd/
cp ../../wdbecmbd/Root*.cpp $SRCROOT/wdbecmbd/

cp ../../wdbecmbd/Sess*.h $SRCROOT/wdbecmbd/
cp ../../wdbecmbd/Sess*.cpp $SRCROOT/wdbecmbd/

cp ../../wdbecmbd/gbl/*.h $SRCROOT/wdbecmbd/
cp ../../wdbecmbd/gbl/*.cpp $SRCROOT/wdbecmbd/

cp Makefile_IexWdbe $SRCROOT/wdbecmbd/IexWdbe/Makefile

cp ../../wdbecmbd/IexWdbe/IexWdbe*.h $SRCROOT/wdbecmbd/IexWdbe/
cp ../../wdbecmbd/IexWdbe/IexWdbe*.cpp $SRCROOT/wdbecmbd/IexWdbe/

cp ../../wdbecmbd/IexWdbe/JobWdbeIex*.h $SRCROOT/wdbecmbd/IexWdbe/
cp ../../wdbecmbd/IexWdbe/JobWdbeIex*.cpp $SRCROOT/wdbecmbd/IexWdbe/

cp Makefile_VecWdbe $SRCROOT/wdbecmbd/VecWdbe/Makefile

cp ../../wdbecmbd/VecWdbe/Vec*.h $SRCROOT/wdbecmbd/VecWdbe/
cp ../../wdbecmbd/VecWdbe/Vec*.cpp $SRCROOT/wdbecmbd/VecWdbe/

cp Makefile_CrdWdbeUsg $SRCROOT/wdbecmbd/CrdWdbeUsg/Makefile

cp ../../wdbecmbd/CrdWdbeUsg/*.h $SRCROOT/wdbecmbd/CrdWdbeUsg/
cp ../../wdbecmbd/CrdWdbeUsg/*.cpp $SRCROOT/wdbecmbd/CrdWdbeUsg/

cp Makefile_CrdWdbeUsr $SRCROOT/wdbecmbd/CrdWdbeUsr/Makefile

cp ../../wdbecmbd/CrdWdbeUsr/*.h $SRCROOT/wdbecmbd/CrdWdbeUsr/
cp ../../wdbecmbd/CrdWdbeUsr/*.cpp $SRCROOT/wdbecmbd/CrdWdbeUsr/

cp Makefile_CrdWdbePrs $SRCROOT/wdbecmbd/CrdWdbePrs/Makefile

cp ../../wdbecmbd/CrdWdbePrs/*.h $SRCROOT/wdbecmbd/CrdWdbePrs/
cp ../../wdbecmbd/CrdWdbePrs/*.cpp $SRCROOT/wdbecmbd/CrdWdbePrs/

cp Makefile_CrdWdbeFil $SRCROOT/wdbecmbd/CrdWdbeFil/Makefile

cp ../../wdbecmbd/CrdWdbeFil/*.h $SRCROOT/wdbecmbd/CrdWdbeFil/
cp ../../wdbecmbd/CrdWdbeFil/*.cpp $SRCROOT/wdbecmbd/CrdWdbeFil/

cp Makefile_CrdWdbeNav $SRCROOT/wdbecmbd/CrdWdbeNav/Makefile

cp ../../wdbecmbd/CrdWdbeNav/*.h $SRCROOT/wdbecmbd/CrdWdbeNav/
cp ../../wdbecmbd/CrdWdbeNav/*.cpp $SRCROOT/wdbecmbd/CrdWdbeNav/

cp Makefile_CrdWdbeMch $SRCROOT/wdbecmbd/CrdWdbeMch/Makefile

cp ../../wdbecmbd/CrdWdbeMch/*.h $SRCROOT/wdbecmbd/CrdWdbeMch/
cp ../../wdbecmbd/CrdWdbeMch/*.cpp $SRCROOT/wdbecmbd/CrdWdbeMch/

cp Makefile_CrdWdbeLib $SRCROOT/wdbecmbd/CrdWdbeLib/Makefile

cp ../../wdbecmbd/CrdWdbeLib/*.h $SRCROOT/wdbecmbd/CrdWdbeLib/
cp ../../wdbecmbd/CrdWdbeLib/*.cpp $SRCROOT/wdbecmbd/CrdWdbeLib/

cp Makefile_CrdWdbeFam $SRCROOT/wdbecmbd/CrdWdbeFam/Makefile

cp ../../wdbecmbd/CrdWdbeFam/*.h $SRCROOT/wdbecmbd/CrdWdbeFam/
cp ../../wdbecmbd/CrdWdbeFam/*.cpp $SRCROOT/wdbecmbd/CrdWdbeFam/

cp Makefile_CrdWdbeSil $SRCROOT/wdbecmbd/CrdWdbeSil/Makefile

cp ../../wdbecmbd/CrdWdbeSil/*.h $SRCROOT/wdbecmbd/CrdWdbeSil/
cp ../../wdbecmbd/CrdWdbeSil/*.cpp $SRCROOT/wdbecmbd/CrdWdbeSil/

cp Makefile_CrdWdbeMtp $SRCROOT/wdbecmbd/CrdWdbeMtp/Makefile

cp ../../wdbecmbd/CrdWdbeMtp/*.h $SRCROOT/wdbecmbd/CrdWdbeMtp/
cp ../../wdbecmbd/CrdWdbeMtp/*.cpp $SRCROOT/wdbecmbd/CrdWdbeMtp/

cp Makefile_CrdWdbePrj $SRCROOT/wdbecmbd/CrdWdbePrj/Makefile

cp ../../wdbecmbd/CrdWdbePrj/*.h $SRCROOT/wdbecmbd/CrdWdbePrj/
cp ../../wdbecmbd/CrdWdbePrj/*.cpp $SRCROOT/wdbecmbd/CrdWdbePrj/

cp Makefile_CrdWdbeVer $SRCROOT/wdbecmbd/CrdWdbeVer/Makefile

cp ../../wdbecmbd/CrdWdbeVer/*.h $SRCROOT/wdbecmbd/CrdWdbeVer/
cp ../../wdbecmbd/CrdWdbeVer/*.cpp $SRCROOT/wdbecmbd/CrdWdbeVer/

cp Makefile_CrdWdbeSys $SRCROOT/wdbecmbd/CrdWdbeSys/Makefile

cp ../../wdbecmbd/CrdWdbeSys/*.h $SRCROOT/wdbecmbd/CrdWdbeSys/
cp ../../wdbecmbd/CrdWdbeSys/*.cpp $SRCROOT/wdbecmbd/CrdWdbeSys/

cp Makefile_CrdWdbeTrg $SRCROOT/wdbecmbd/CrdWdbeTrg/Makefile

cp ../../wdbecmbd/CrdWdbeTrg/*.h $SRCROOT/wdbecmbd/CrdWdbeTrg/
cp ../../wdbecmbd/CrdWdbeTrg/*.cpp $SRCROOT/wdbecmbd/CrdWdbeTrg/

cp Makefile_CrdWdbeUnt $SRCROOT/wdbecmbd/CrdWdbeUnt/Makefile

cp ../../wdbecmbd/CrdWdbeUnt/*.h $SRCROOT/wdbecmbd/CrdWdbeUnt/
cp ../../wdbecmbd/CrdWdbeUnt/*.cpp $SRCROOT/wdbecmbd/CrdWdbeUnt/

cp Makefile_CrdWdbeRls $SRCROOT/wdbecmbd/CrdWdbeRls/Makefile

cp ../../wdbecmbd/CrdWdbeRls/*.h $SRCROOT/wdbecmbd/CrdWdbeRls/
cp ../../wdbecmbd/CrdWdbeRls/*.cpp $SRCROOT/wdbecmbd/CrdWdbeRls/

cp Makefile_CrdWdbeCpr $SRCROOT/wdbecmbd/CrdWdbeCpr/Makefile

cp ../../wdbecmbd/CrdWdbeCpr/*.h $SRCROOT/wdbecmbd/CrdWdbeCpr/
cp ../../wdbecmbd/CrdWdbeCpr/*.cpp $SRCROOT/wdbecmbd/CrdWdbeCpr/

cp Makefile_CrdWdbeCvr $SRCROOT/wdbecmbd/CrdWdbeCvr/Makefile

cp ../../wdbecmbd/CrdWdbeCvr/*.h $SRCROOT/wdbecmbd/CrdWdbeCvr/
cp ../../wdbecmbd/CrdWdbeCvr/*.cpp $SRCROOT/wdbecmbd/CrdWdbeCvr/

cp Makefile_CrdWdbeMod $SRCROOT/wdbecmbd/CrdWdbeMod/Makefile

cp ../../wdbecmbd/CrdWdbeMod/*.h $SRCROOT/wdbecmbd/CrdWdbeMod/
cp ../../wdbecmbd/CrdWdbeMod/*.cpp $SRCROOT/wdbecmbd/CrdWdbeMod/

cp Makefile_CrdWdbeVec $SRCROOT/wdbecmbd/CrdWdbeVec/Makefile

cp ../../wdbecmbd/CrdWdbeVec/*.h $SRCROOT/wdbecmbd/CrdWdbeVec/
cp ../../wdbecmbd/CrdWdbeVec/*.cpp $SRCROOT/wdbecmbd/CrdWdbeVec/

cp Makefile_CrdWdbeVit $SRCROOT/wdbecmbd/CrdWdbeVit/Makefile

cp ../../wdbecmbd/CrdWdbeVit/*.h $SRCROOT/wdbecmbd/CrdWdbeVit/
cp ../../wdbecmbd/CrdWdbeVit/*.cpp $SRCROOT/wdbecmbd/CrdWdbeVit/

cp Makefile_CrdWdbeCmd $SRCROOT/wdbecmbd/CrdWdbeCmd/Makefile

cp ../../wdbecmbd/CrdWdbeCmd/*.h $SRCROOT/wdbecmbd/CrdWdbeCmd/
cp ../../wdbecmbd/CrdWdbeCmd/*.cpp $SRCROOT/wdbecmbd/CrdWdbeCmd/

cp Makefile_CrdWdbeErr $SRCROOT/wdbecmbd/CrdWdbeErr/Makefile

cp ../../wdbecmbd/CrdWdbeErr/*.h $SRCROOT/wdbecmbd/CrdWdbeErr/
cp ../../wdbecmbd/CrdWdbeErr/*.cpp $SRCROOT/wdbecmbd/CrdWdbeErr/

cp Makefile_CrdWdbePph $SRCROOT/wdbecmbd/CrdWdbePph/Makefile

cp ../../wdbecmbd/CrdWdbePph/*.h $SRCROOT/wdbecmbd/CrdWdbePph/
cp ../../wdbecmbd/CrdWdbePph/*.cpp $SRCROOT/wdbecmbd/CrdWdbePph/

cp Makefile_CrdWdbeBnk $SRCROOT/wdbecmbd/CrdWdbeBnk/Makefile

cp ../../wdbecmbd/CrdWdbeBnk/*.h $SRCROOT/wdbecmbd/CrdWdbeBnk/
cp ../../wdbecmbd/CrdWdbeBnk/*.cpp $SRCROOT/wdbecmbd/CrdWdbeBnk/

cp Makefile_CrdWdbePin $SRCROOT/wdbecmbd/CrdWdbePin/Makefile

cp ../../wdbecmbd/CrdWdbePin/*.h $SRCROOT/wdbecmbd/CrdWdbePin/
cp ../../wdbecmbd/CrdWdbePin/*.cpp $SRCROOT/wdbecmbd/CrdWdbePin/

cp Makefile_CrdWdbeGen $SRCROOT/wdbecmbd/CrdWdbeGen/Makefile

cp ../../wdbecmbd/CrdWdbeGen/*.h $SRCROOT/wdbecmbd/CrdWdbeGen/
cp ../../wdbecmbd/CrdWdbeGen/*.cpp $SRCROOT/wdbecmbd/CrdWdbeGen/

cp Makefile_CrdWdbePrt $SRCROOT/wdbecmbd/CrdWdbePrt/Makefile

cp ../../wdbecmbd/CrdWdbePrt/*.h $SRCROOT/wdbecmbd/CrdWdbePrt/
cp ../../wdbecmbd/CrdWdbePrt/*.cpp $SRCROOT/wdbecmbd/CrdWdbePrt/

cp Makefile_CrdWdbeSig $SRCROOT/wdbecmbd/CrdWdbeSig/Makefile

cp ../../wdbecmbd/CrdWdbeSig/*.h $SRCROOT/wdbecmbd/CrdWdbeSig/
cp ../../wdbecmbd/CrdWdbeSig/*.cpp $SRCROOT/wdbecmbd/CrdWdbeSig/

cp Makefile_CrdWdbePrc $SRCROOT/wdbecmbd/CrdWdbePrc/Makefile

cp ../../wdbecmbd/CrdWdbePrc/*.h $SRCROOT/wdbecmbd/CrdWdbePrc/
cp ../../wdbecmbd/CrdWdbePrc/*.cpp $SRCROOT/wdbecmbd/CrdWdbePrc/

cp Makefile_CrdWdbeFst $SRCROOT/wdbecmbd/CrdWdbeFst/Makefile

cp ../../wdbecmbd/CrdWdbeFst/*.h $SRCROOT/wdbecmbd/CrdWdbeFst/
cp ../../wdbecmbd/CrdWdbeFst/*.cpp $SRCROOT/wdbecmbd/CrdWdbeFst/

cp Makefile_CrdWdbeVar $SRCROOT/wdbecmbd/CrdWdbeVar/Makefile

cp ../../wdbecmbd/CrdWdbeVar/*.h $SRCROOT/wdbecmbd/CrdWdbeVar/
cp ../../wdbecmbd/CrdWdbeVar/*.cpp $SRCROOT/wdbecmbd/CrdWdbeVar/

cp Makefile_CrdWdbeUtl $SRCROOT/wdbecmbd/CrdWdbeUtl/Makefile

cp ../../wdbecmbd/CrdWdbeUtl/*.h $SRCROOT/wdbecmbd/CrdWdbeUtl/
cp ../../wdbecmbd/CrdWdbeUtl/*.cpp $SRCROOT/wdbecmbd/CrdWdbeUtl/

cp Makefile_WdbeWrmcu $SRCROOT/wdbecmbd/WdbeWrmcu/Makefile

cp ../../wdbecmbd/WdbeWrmcu/*.h $SRCROOT/wdbecmbd/WdbeWrmcu/
cp ../../wdbecmbd/WdbeWrmcu/*.cpp $SRCROOT/wdbecmbd/WdbeWrmcu/

cp Makefile_WdbeWrfpga $SRCROOT/wdbecmbd/WdbeWrfpga/Makefile

cp ../../wdbecmbd/WdbeWrfpga/*.h $SRCROOT/wdbecmbd/WdbeWrfpga/
cp ../../wdbecmbd/WdbeWrfpga/*.cpp $SRCROOT/wdbecmbd/WdbeWrfpga/

cp Makefile_WdbeWrdev $SRCROOT/wdbecmbd/WdbeWrdev/Makefile

cp ../../wdbecmbd/WdbeWrdev/*.h $SRCROOT/wdbecmbd/WdbeWrdev/
cp ../../wdbecmbd/WdbeWrdev/*.cpp $SRCROOT/wdbecmbd/WdbeWrdev/

cp Makefile_WdbePrctree $SRCROOT/wdbecmbd/WdbePrctree/Makefile

cp ../../wdbecmbd/WdbePrctree/*.h $SRCROOT/wdbecmbd/WdbePrctree/
cp ../../wdbecmbd/WdbePrctree/*.cpp $SRCROOT/wdbecmbd/WdbePrctree/

cp Makefile_WdbePrcfile $SRCROOT/wdbecmbd/WdbePrcfile/Makefile

cp ../../wdbecmbd/WdbePrcfile/*.h $SRCROOT/wdbecmbd/WdbePrcfile/
cp ../../wdbecmbd/WdbePrcfile/*.cpp $SRCROOT/wdbecmbd/WdbePrcfile/

cp Makefile_WdbePlhmcu $SRCROOT/wdbecmbd/WdbePlhmcu/Makefile

cp ../../wdbecmbd/WdbePlhmcu/*.h $SRCROOT/wdbecmbd/WdbePlhmcu/
cp ../../wdbecmbd/WdbePlhmcu/*.cpp $SRCROOT/wdbecmbd/WdbePlhmcu/

cp Makefile_WdbePlhfpga $SRCROOT/wdbecmbd/WdbePlhfpga/Makefile

cp ../../wdbecmbd/WdbePlhfpga/*.h $SRCROOT/wdbecmbd/WdbePlhfpga/
cp ../../wdbecmbd/WdbePlhfpga/*.cpp $SRCROOT/wdbecmbd/WdbePlhfpga/

cp Makefile_WdbeMtpWrmcu $SRCROOT/wdbecmbd/WdbeMtpWrmcu/Makefile

cp ../../wdbecmbd/WdbeMtpWrmcu/*.h $SRCROOT/wdbecmbd/WdbeMtpWrmcu/
cp ../../wdbecmbd/WdbeMtpWrmcu/*.cpp $SRCROOT/wdbecmbd/WdbeMtpWrmcu/

cp Makefile_WdbeMtpWrfpga $SRCROOT/wdbecmbd/WdbeMtpWrfpga/Makefile

cp ../../wdbecmbd/WdbeMtpWrfpga/*.h $SRCROOT/wdbecmbd/WdbeMtpWrfpga/
cp ../../wdbecmbd/WdbeMtpWrfpga/*.cpp $SRCROOT/wdbecmbd/WdbeMtpWrfpga/

cp Makefile_WdbeMtpModdet $SRCROOT/wdbecmbd/WdbeMtpModdet/Makefile

cp ../../wdbecmbd/WdbeMtpModdet/*.h $SRCROOT/wdbecmbd/WdbeMtpModdet/
cp ../../wdbecmbd/WdbeMtpModdet/*.cpp $SRCROOT/wdbecmbd/WdbeMtpModdet/

cp Makefile_WdbeMtpModbsctd $SRCROOT/wdbecmbd/WdbeMtpModbsctd/Makefile

cp ../../wdbecmbd/WdbeMtpModbsctd/*.h $SRCROOT/wdbecmbd/WdbeMtpModbsctd/
cp ../../wdbecmbd/WdbeMtpModbsctd/*.cpp $SRCROOT/wdbecmbd/WdbeMtpModbsctd/

cp Makefile_WdbeMtpModbscbu $SRCROOT/wdbecmbd/WdbeMtpModbscbu/Makefile

cp ../../wdbecmbd/WdbeMtpModbscbu/*.h $SRCROOT/wdbecmbd/WdbeMtpModbscbu/
cp ../../wdbecmbd/WdbeMtpModbscbu/*.cpp $SRCROOT/wdbecmbd/WdbeMtpModbscbu/

cp Makefile_WdbeMtpPlhmcu $SRCROOT/wdbecmbd/WdbeMtpPlhmcu/Makefile

cp ../../wdbecmbd/WdbeMtpPlhmcu/*.h $SRCROOT/wdbecmbd/WdbeMtpPlhmcu/
cp ../../wdbecmbd/WdbeMtpPlhmcu/*.cpp $SRCROOT/wdbecmbd/WdbeMtpPlhmcu/

cp Makefile_WdbeMtpPlhfpga $SRCROOT/wdbecmbd/WdbeMtpPlhfpga/Makefile

cp ../../wdbecmbd/WdbeMtpPlhfpga/*.h $SRCROOT/wdbecmbd/WdbeMtpPlhfpga/
cp ../../wdbecmbd/WdbeMtpPlhfpga/*.cpp $SRCROOT/wdbecmbd/WdbeMtpPlhfpga/

cp Makefile_WdbeModdet $SRCROOT/wdbecmbd/WdbeModdet/Makefile

cp ../../wdbecmbd/WdbeModdet/*.h $SRCROOT/wdbecmbd/WdbeModdet/
cp ../../wdbecmbd/WdbeModdet/*.cpp $SRCROOT/wdbecmbd/WdbeModdet/

cp Makefile_WdbeModbsc $SRCROOT/wdbecmbd/WdbeModbsc/Makefile

cp ../../wdbecmbd/WdbeModbsc/*.h $SRCROOT/wdbecmbd/WdbeModbsc/
cp ../../wdbecmbd/WdbeModbsc/*.cpp $SRCROOT/wdbecmbd/WdbeModbsc/

