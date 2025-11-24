#!/bin/bash
# file checkout.sh
# checkout script for Wdbe combined daemon, release wdbecmbd_ubuntu
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 23 Nov 2025
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set BUILDROOT=${WHIZSDKROOT}/build
export set LIBROOT=${WHIZSDKROOT}/lib
export set BINROOT=${WHIZROOT}/bin

mkdir $BUILDROOT/wdbecmbd
mkdir $BUILDROOT/wdbecmbd/IexWdbe
mkdir $BUILDROOT/wdbecmbd/VecWdbe
mkdir $BUILDROOT/wdbecmbd/CrdWdbeNav
mkdir $BUILDROOT/wdbecmbd/CrdWdbeUsg
mkdir $BUILDROOT/wdbecmbd/CrdWdbeUsr
mkdir $BUILDROOT/wdbecmbd/CrdWdbePrs
mkdir $BUILDROOT/wdbecmbd/CrdWdbeFil
mkdir $BUILDROOT/wdbecmbd/CrdWdbePrf
mkdir $BUILDROOT/wdbecmbd/CrdWdbeMch
mkdir $BUILDROOT/wdbecmbd/CrdWdbeLib
mkdir $BUILDROOT/wdbecmbd/CrdWdbeFam
mkdir $BUILDROOT/wdbecmbd/CrdWdbeSil
mkdir $BUILDROOT/wdbecmbd/CrdWdbeMtp
mkdir $BUILDROOT/wdbecmbd/CrdWdbePrj
mkdir $BUILDROOT/wdbecmbd/CrdWdbeVer
mkdir $BUILDROOT/wdbecmbd/CrdWdbeUnt
mkdir $BUILDROOT/wdbecmbd/CrdWdbeCpr
mkdir $BUILDROOT/wdbecmbd/CrdWdbeCvr
mkdir $BUILDROOT/wdbecmbd/CrdWdbePph
mkdir $BUILDROOT/wdbecmbd/CrdWdbeMod
mkdir $BUILDROOT/wdbecmbd/CrdWdbeVec
mkdir $BUILDROOT/wdbecmbd/CrdWdbeVit
mkdir $BUILDROOT/wdbecmbd/CrdWdbeCmd
mkdir $BUILDROOT/wdbecmbd/CrdWdbeErr
mkdir $BUILDROOT/wdbecmbd/CrdWdbePpl
mkdir $BUILDROOT/wdbecmbd/CrdWdbeSeg
mkdir $BUILDROOT/wdbecmbd/CrdWdbeBnk
mkdir $BUILDROOT/wdbecmbd/CrdWdbePin
mkdir $BUILDROOT/wdbecmbd/CrdWdbeInt
mkdir $BUILDROOT/wdbecmbd/CrdWdbeSns
mkdir $BUILDROOT/wdbecmbd/CrdWdbeVar
mkdir $BUILDROOT/wdbecmbd/CrdWdbeGen
mkdir $BUILDROOT/wdbecmbd/CrdWdbePrt
mkdir $BUILDROOT/wdbecmbd/CrdWdbeSig
mkdir $BUILDROOT/wdbecmbd/CrdWdbeCdc
mkdir $BUILDROOT/wdbecmbd/CrdWdbePrc
mkdir $BUILDROOT/wdbecmbd/CrdWdbeFst
mkdir $BUILDROOT/wdbecmbd/CrdWdbeCmp
mkdir $BUILDROOT/wdbecmbd/CrdWdbeRls
mkdir $BUILDROOT/wdbecmbd/CrdWdbeIdf
mkdir $BUILDROOT/wdbecmbd/CrdWdbeUtl
mkdir $BUILDROOT/wdbecmbd/WdbeCplmst
mkdir $BUILDROOT/wdbecmbd/WdbeGen
mkdir $BUILDROOT/wdbecmbd/WdbeGenfst
mkdir $BUILDROOT/wdbecmbd/WdbeMtpPlhfpga
mkdir $BUILDROOT/wdbecmbd/WdbeMtpPlhmcu
mkdir $BUILDROOT/wdbecmbd/WdbeMtpCplmstbu
mkdir $BUILDROOT/wdbecmbd/WdbeMtpCplmsttd
mkdir $BUILDROOT/wdbecmbd/WdbeMtpGenfst
mkdir $BUILDROOT/wdbecmbd/WdbeMtpWrfpga
mkdir $BUILDROOT/wdbecmbd/WdbeMtpWrmcu
mkdir $BUILDROOT/wdbecmbd/WdbePlhfpga
mkdir $BUILDROOT/wdbecmbd/WdbePlhmcu
mkdir $BUILDROOT/wdbecmbd/WdbePrcfile
mkdir $BUILDROOT/wdbecmbd/WdbePrctree
mkdir $BUILDROOT/wdbecmbd/WdbeWrdev
mkdir $BUILDROOT/wdbecmbd/WdbeWrfpga
mkdir $BUILDROOT/wdbecmbd/WdbeWrmcu
mkdir $BUILDROOT/wdbecmbd/WdbeWrterm

mkdir $LIBROOT/wdbecmbd

mkdir $BINROOT/wdbecmbd

cp make.sh $BUILDROOT/wdbecmbd/
cp remake.sh $BUILDROOT/wdbecmbd/

cp Makefile.inc $BUILDROOT/wdbecmbd/
cp Makefile $BUILDROOT/wdbecmbd/

cp ../../wdbecmbd/Wdbecmbd.h $BUILDROOT/wdbecmbd/
cp ../../wdbecmbd/Wdbecmbd.cpp $BUILDROOT/wdbecmbd/

cp ../../wdbecmbd/WdbecmbdAppsrv.h $BUILDROOT/wdbecmbd/
cp ../../wdbecmbd/WdbecmbdAppsrv.cpp $BUILDROOT/wdbecmbd/

cp ../../wdbecmbd/WdbecmbdJobprc.h $BUILDROOT/wdbecmbd/
cp ../../wdbecmbd/WdbecmbdJobprc.cpp $BUILDROOT/wdbecmbd/

cp ../../wdbecmbd/WdbecmbdOpprc.h $BUILDROOT/wdbecmbd/
cp ../../wdbecmbd/WdbecmbdOpprc.cpp $BUILDROOT/wdbecmbd/

cp ../../wdbecmbd/Wdbecmbd_exe.h $BUILDROOT/wdbecmbd/
cp ../../wdbecmbd/Wdbecmbd_exe.cpp $BUILDROOT/wdbecmbd/

cp ../../wdbecmbd/Wdbe.h $BUILDROOT/wdbecmbd/
cp ../../wdbecmbd/Wdbe.cpp $BUILDROOT/wdbecmbd/

cp ../../wdbecmbd/Root*.h $BUILDROOT/wdbecmbd/
cp ../../wdbecmbd/Root*.cpp $BUILDROOT/wdbecmbd/

cp ../../wdbecmbd/Sess*.h $BUILDROOT/wdbecmbd/
cp ../../wdbecmbd/Sess*.cpp $BUILDROOT/wdbecmbd/

cp ../../wdbecmbd/gbl/*.h $BUILDROOT/wdbecmbd/
cp ../../wdbecmbd/gbl/*.cpp $BUILDROOT/wdbecmbd/

cp Makefile_IexWdbe $BUILDROOT/wdbecmbd/IexWdbe/Makefile

cp ../../wdbecmbd/IexWdbe/IexWdbe*.h $BUILDROOT/wdbecmbd/IexWdbe/
cp ../../wdbecmbd/IexWdbe/IexWdbe*.cpp $BUILDROOT/wdbecmbd/IexWdbe/

cp ../../wdbecmbd/IexWdbe/JobWdbeIex*.h $BUILDROOT/wdbecmbd/IexWdbe/
cp ../../wdbecmbd/IexWdbe/JobWdbeIex*.cpp $BUILDROOT/wdbecmbd/IexWdbe/

cp Makefile_VecWdbe $BUILDROOT/wdbecmbd/VecWdbe/Makefile

cp ../../wdbecmbd/VecWdbe/Vec*.h $BUILDROOT/wdbecmbd/VecWdbe/
cp ../../wdbecmbd/VecWdbe/Vec*.cpp $BUILDROOT/wdbecmbd/VecWdbe/

cp Makefile_CrdWdbeNav $BUILDROOT/wdbecmbd/CrdWdbeNav/Makefile

cp ../../wdbecmbd/CrdWdbeNav/*.h $BUILDROOT/wdbecmbd/CrdWdbeNav/
cp ../../wdbecmbd/CrdWdbeNav/*.cpp $BUILDROOT/wdbecmbd/CrdWdbeNav/

cp Makefile_CrdWdbeUsg $BUILDROOT/wdbecmbd/CrdWdbeUsg/Makefile

cp ../../wdbecmbd/CrdWdbeUsg/*.h $BUILDROOT/wdbecmbd/CrdWdbeUsg/
cp ../../wdbecmbd/CrdWdbeUsg/*.cpp $BUILDROOT/wdbecmbd/CrdWdbeUsg/

cp Makefile_CrdWdbeUsr $BUILDROOT/wdbecmbd/CrdWdbeUsr/Makefile

cp ../../wdbecmbd/CrdWdbeUsr/*.h $BUILDROOT/wdbecmbd/CrdWdbeUsr/
cp ../../wdbecmbd/CrdWdbeUsr/*.cpp $BUILDROOT/wdbecmbd/CrdWdbeUsr/

cp Makefile_CrdWdbePrs $BUILDROOT/wdbecmbd/CrdWdbePrs/Makefile

cp ../../wdbecmbd/CrdWdbePrs/*.h $BUILDROOT/wdbecmbd/CrdWdbePrs/
cp ../../wdbecmbd/CrdWdbePrs/*.cpp $BUILDROOT/wdbecmbd/CrdWdbePrs/

cp Makefile_CrdWdbeFil $BUILDROOT/wdbecmbd/CrdWdbeFil/Makefile

cp ../../wdbecmbd/CrdWdbeFil/*.h $BUILDROOT/wdbecmbd/CrdWdbeFil/
cp ../../wdbecmbd/CrdWdbeFil/*.cpp $BUILDROOT/wdbecmbd/CrdWdbeFil/

cp Makefile_CrdWdbePrf $BUILDROOT/wdbecmbd/CrdWdbePrf/Makefile

cp ../../wdbecmbd/CrdWdbePrf/*.h $BUILDROOT/wdbecmbd/CrdWdbePrf/
cp ../../wdbecmbd/CrdWdbePrf/*.cpp $BUILDROOT/wdbecmbd/CrdWdbePrf/

cp Makefile_CrdWdbeMch $BUILDROOT/wdbecmbd/CrdWdbeMch/Makefile

cp ../../wdbecmbd/CrdWdbeMch/*.h $BUILDROOT/wdbecmbd/CrdWdbeMch/
cp ../../wdbecmbd/CrdWdbeMch/*.cpp $BUILDROOT/wdbecmbd/CrdWdbeMch/

cp Makefile_CrdWdbeLib $BUILDROOT/wdbecmbd/CrdWdbeLib/Makefile

cp ../../wdbecmbd/CrdWdbeLib/*.h $BUILDROOT/wdbecmbd/CrdWdbeLib/
cp ../../wdbecmbd/CrdWdbeLib/*.cpp $BUILDROOT/wdbecmbd/CrdWdbeLib/

cp Makefile_CrdWdbeFam $BUILDROOT/wdbecmbd/CrdWdbeFam/Makefile

cp ../../wdbecmbd/CrdWdbeFam/*.h $BUILDROOT/wdbecmbd/CrdWdbeFam/
cp ../../wdbecmbd/CrdWdbeFam/*.cpp $BUILDROOT/wdbecmbd/CrdWdbeFam/

cp Makefile_CrdWdbeSil $BUILDROOT/wdbecmbd/CrdWdbeSil/Makefile

cp ../../wdbecmbd/CrdWdbeSil/*.h $BUILDROOT/wdbecmbd/CrdWdbeSil/
cp ../../wdbecmbd/CrdWdbeSil/*.cpp $BUILDROOT/wdbecmbd/CrdWdbeSil/

cp Makefile_CrdWdbeMtp $BUILDROOT/wdbecmbd/CrdWdbeMtp/Makefile

cp ../../wdbecmbd/CrdWdbeMtp/*.h $BUILDROOT/wdbecmbd/CrdWdbeMtp/
cp ../../wdbecmbd/CrdWdbeMtp/*.cpp $BUILDROOT/wdbecmbd/CrdWdbeMtp/

cp Makefile_CrdWdbePrj $BUILDROOT/wdbecmbd/CrdWdbePrj/Makefile

cp ../../wdbecmbd/CrdWdbePrj/*.h $BUILDROOT/wdbecmbd/CrdWdbePrj/
cp ../../wdbecmbd/CrdWdbePrj/*.cpp $BUILDROOT/wdbecmbd/CrdWdbePrj/

cp Makefile_CrdWdbeVer $BUILDROOT/wdbecmbd/CrdWdbeVer/Makefile

cp ../../wdbecmbd/CrdWdbeVer/*.h $BUILDROOT/wdbecmbd/CrdWdbeVer/
cp ../../wdbecmbd/CrdWdbeVer/*.cpp $BUILDROOT/wdbecmbd/CrdWdbeVer/

cp Makefile_CrdWdbeUnt $BUILDROOT/wdbecmbd/CrdWdbeUnt/Makefile

cp ../../wdbecmbd/CrdWdbeUnt/*.h $BUILDROOT/wdbecmbd/CrdWdbeUnt/
cp ../../wdbecmbd/CrdWdbeUnt/*.cpp $BUILDROOT/wdbecmbd/CrdWdbeUnt/

cp Makefile_CrdWdbeCpr $BUILDROOT/wdbecmbd/CrdWdbeCpr/Makefile

cp ../../wdbecmbd/CrdWdbeCpr/*.h $BUILDROOT/wdbecmbd/CrdWdbeCpr/
cp ../../wdbecmbd/CrdWdbeCpr/*.cpp $BUILDROOT/wdbecmbd/CrdWdbeCpr/

cp Makefile_CrdWdbeCvr $BUILDROOT/wdbecmbd/CrdWdbeCvr/Makefile

cp ../../wdbecmbd/CrdWdbeCvr/*.h $BUILDROOT/wdbecmbd/CrdWdbeCvr/
cp ../../wdbecmbd/CrdWdbeCvr/*.cpp $BUILDROOT/wdbecmbd/CrdWdbeCvr/

cp Makefile_CrdWdbePph $BUILDROOT/wdbecmbd/CrdWdbePph/Makefile

cp ../../wdbecmbd/CrdWdbePph/*.h $BUILDROOT/wdbecmbd/CrdWdbePph/
cp ../../wdbecmbd/CrdWdbePph/*.cpp $BUILDROOT/wdbecmbd/CrdWdbePph/

cp Makefile_CrdWdbeMod $BUILDROOT/wdbecmbd/CrdWdbeMod/Makefile

cp ../../wdbecmbd/CrdWdbeMod/*.h $BUILDROOT/wdbecmbd/CrdWdbeMod/
cp ../../wdbecmbd/CrdWdbeMod/*.cpp $BUILDROOT/wdbecmbd/CrdWdbeMod/

cp Makefile_CrdWdbeVec $BUILDROOT/wdbecmbd/CrdWdbeVec/Makefile

cp ../../wdbecmbd/CrdWdbeVec/*.h $BUILDROOT/wdbecmbd/CrdWdbeVec/
cp ../../wdbecmbd/CrdWdbeVec/*.cpp $BUILDROOT/wdbecmbd/CrdWdbeVec/

cp Makefile_CrdWdbeVit $BUILDROOT/wdbecmbd/CrdWdbeVit/Makefile

cp ../../wdbecmbd/CrdWdbeVit/*.h $BUILDROOT/wdbecmbd/CrdWdbeVit/
cp ../../wdbecmbd/CrdWdbeVit/*.cpp $BUILDROOT/wdbecmbd/CrdWdbeVit/

cp Makefile_CrdWdbeCmd $BUILDROOT/wdbecmbd/CrdWdbeCmd/Makefile

cp ../../wdbecmbd/CrdWdbeCmd/*.h $BUILDROOT/wdbecmbd/CrdWdbeCmd/
cp ../../wdbecmbd/CrdWdbeCmd/*.cpp $BUILDROOT/wdbecmbd/CrdWdbeCmd/

cp Makefile_CrdWdbeErr $BUILDROOT/wdbecmbd/CrdWdbeErr/Makefile

cp ../../wdbecmbd/CrdWdbeErr/*.h $BUILDROOT/wdbecmbd/CrdWdbeErr/
cp ../../wdbecmbd/CrdWdbeErr/*.cpp $BUILDROOT/wdbecmbd/CrdWdbeErr/

cp Makefile_CrdWdbePpl $BUILDROOT/wdbecmbd/CrdWdbePpl/Makefile

cp ../../wdbecmbd/CrdWdbePpl/*.h $BUILDROOT/wdbecmbd/CrdWdbePpl/
cp ../../wdbecmbd/CrdWdbePpl/*.cpp $BUILDROOT/wdbecmbd/CrdWdbePpl/

cp Makefile_CrdWdbeSeg $BUILDROOT/wdbecmbd/CrdWdbeSeg/Makefile

cp ../../wdbecmbd/CrdWdbeSeg/*.h $BUILDROOT/wdbecmbd/CrdWdbeSeg/
cp ../../wdbecmbd/CrdWdbeSeg/*.cpp $BUILDROOT/wdbecmbd/CrdWdbeSeg/

cp Makefile_CrdWdbeBnk $BUILDROOT/wdbecmbd/CrdWdbeBnk/Makefile

cp ../../wdbecmbd/CrdWdbeBnk/*.h $BUILDROOT/wdbecmbd/CrdWdbeBnk/
cp ../../wdbecmbd/CrdWdbeBnk/*.cpp $BUILDROOT/wdbecmbd/CrdWdbeBnk/

cp Makefile_CrdWdbePin $BUILDROOT/wdbecmbd/CrdWdbePin/Makefile

cp ../../wdbecmbd/CrdWdbePin/*.h $BUILDROOT/wdbecmbd/CrdWdbePin/
cp ../../wdbecmbd/CrdWdbePin/*.cpp $BUILDROOT/wdbecmbd/CrdWdbePin/

cp Makefile_CrdWdbeInt $BUILDROOT/wdbecmbd/CrdWdbeInt/Makefile

cp ../../wdbecmbd/CrdWdbeInt/*.h $BUILDROOT/wdbecmbd/CrdWdbeInt/
cp ../../wdbecmbd/CrdWdbeInt/*.cpp $BUILDROOT/wdbecmbd/CrdWdbeInt/

cp Makefile_CrdWdbeSns $BUILDROOT/wdbecmbd/CrdWdbeSns/Makefile

cp ../../wdbecmbd/CrdWdbeSns/*.h $BUILDROOT/wdbecmbd/CrdWdbeSns/
cp ../../wdbecmbd/CrdWdbeSns/*.cpp $BUILDROOT/wdbecmbd/CrdWdbeSns/

cp Makefile_CrdWdbeVar $BUILDROOT/wdbecmbd/CrdWdbeVar/Makefile

cp ../../wdbecmbd/CrdWdbeVar/*.h $BUILDROOT/wdbecmbd/CrdWdbeVar/
cp ../../wdbecmbd/CrdWdbeVar/*.cpp $BUILDROOT/wdbecmbd/CrdWdbeVar/

cp Makefile_CrdWdbeGen $BUILDROOT/wdbecmbd/CrdWdbeGen/Makefile

cp ../../wdbecmbd/CrdWdbeGen/*.h $BUILDROOT/wdbecmbd/CrdWdbeGen/
cp ../../wdbecmbd/CrdWdbeGen/*.cpp $BUILDROOT/wdbecmbd/CrdWdbeGen/

cp Makefile_CrdWdbePrt $BUILDROOT/wdbecmbd/CrdWdbePrt/Makefile

cp ../../wdbecmbd/CrdWdbePrt/*.h $BUILDROOT/wdbecmbd/CrdWdbePrt/
cp ../../wdbecmbd/CrdWdbePrt/*.cpp $BUILDROOT/wdbecmbd/CrdWdbePrt/

cp Makefile_CrdWdbeSig $BUILDROOT/wdbecmbd/CrdWdbeSig/Makefile

cp ../../wdbecmbd/CrdWdbeSig/*.h $BUILDROOT/wdbecmbd/CrdWdbeSig/
cp ../../wdbecmbd/CrdWdbeSig/*.cpp $BUILDROOT/wdbecmbd/CrdWdbeSig/

cp Makefile_CrdWdbeCdc $BUILDROOT/wdbecmbd/CrdWdbeCdc/Makefile

cp ../../wdbecmbd/CrdWdbeCdc/*.h $BUILDROOT/wdbecmbd/CrdWdbeCdc/
cp ../../wdbecmbd/CrdWdbeCdc/*.cpp $BUILDROOT/wdbecmbd/CrdWdbeCdc/

cp Makefile_CrdWdbePrc $BUILDROOT/wdbecmbd/CrdWdbePrc/Makefile

cp ../../wdbecmbd/CrdWdbePrc/*.h $BUILDROOT/wdbecmbd/CrdWdbePrc/
cp ../../wdbecmbd/CrdWdbePrc/*.cpp $BUILDROOT/wdbecmbd/CrdWdbePrc/

cp Makefile_CrdWdbeFst $BUILDROOT/wdbecmbd/CrdWdbeFst/Makefile

cp ../../wdbecmbd/CrdWdbeFst/*.h $BUILDROOT/wdbecmbd/CrdWdbeFst/
cp ../../wdbecmbd/CrdWdbeFst/*.cpp $BUILDROOT/wdbecmbd/CrdWdbeFst/

cp Makefile_CrdWdbeCmp $BUILDROOT/wdbecmbd/CrdWdbeCmp/Makefile

cp ../../wdbecmbd/CrdWdbeCmp/*.h $BUILDROOT/wdbecmbd/CrdWdbeCmp/
cp ../../wdbecmbd/CrdWdbeCmp/*.cpp $BUILDROOT/wdbecmbd/CrdWdbeCmp/

cp Makefile_CrdWdbeRls $BUILDROOT/wdbecmbd/CrdWdbeRls/Makefile

cp ../../wdbecmbd/CrdWdbeRls/*.h $BUILDROOT/wdbecmbd/CrdWdbeRls/
cp ../../wdbecmbd/CrdWdbeRls/*.cpp $BUILDROOT/wdbecmbd/CrdWdbeRls/

cp Makefile_CrdWdbeIdf $BUILDROOT/wdbecmbd/CrdWdbeIdf/Makefile

cp ../../wdbecmbd/CrdWdbeIdf/*.h $BUILDROOT/wdbecmbd/CrdWdbeIdf/
cp ../../wdbecmbd/CrdWdbeIdf/*.cpp $BUILDROOT/wdbecmbd/CrdWdbeIdf/

cp Makefile_CrdWdbeUtl $BUILDROOT/wdbecmbd/CrdWdbeUtl/Makefile

cp ../../wdbecmbd/CrdWdbeUtl/*.h $BUILDROOT/wdbecmbd/CrdWdbeUtl/
cp ../../wdbecmbd/CrdWdbeUtl/*.cpp $BUILDROOT/wdbecmbd/CrdWdbeUtl/

cp Makefile_WdbeCplmst $BUILDROOT/wdbecmbd/WdbeCplmst/Makefile

cp ../../wdbecmbd/WdbeCplmst/*.h $BUILDROOT/wdbecmbd/WdbeCplmst/
cp ../../wdbecmbd/WdbeCplmst/*.cpp $BUILDROOT/wdbecmbd/WdbeCplmst/

cp Makefile_WdbeGen $BUILDROOT/wdbecmbd/WdbeGen/Makefile

cp ../../wdbecmbd/WdbeGen/*.h $BUILDROOT/wdbecmbd/WdbeGen/
cp ../../wdbecmbd/WdbeGen/*.cpp $BUILDROOT/wdbecmbd/WdbeGen/

cp Makefile_WdbeGenfst $BUILDROOT/wdbecmbd/WdbeGenfst/Makefile

cp ../../wdbecmbd/WdbeGenfst/*.h $BUILDROOT/wdbecmbd/WdbeGenfst/
cp ../../wdbecmbd/WdbeGenfst/*.cpp $BUILDROOT/wdbecmbd/WdbeGenfst/

cp Makefile_WdbeMtpPlhfpga $BUILDROOT/wdbecmbd/WdbeMtpPlhfpga/Makefile

cp ../../wdbecmbd/WdbeMtpPlhfpga/*.h $BUILDROOT/wdbecmbd/WdbeMtpPlhfpga/
cp ../../wdbecmbd/WdbeMtpPlhfpga/*.cpp $BUILDROOT/wdbecmbd/WdbeMtpPlhfpga/

cp Makefile_WdbeMtpPlhmcu $BUILDROOT/wdbecmbd/WdbeMtpPlhmcu/Makefile

cp ../../wdbecmbd/WdbeMtpPlhmcu/*.h $BUILDROOT/wdbecmbd/WdbeMtpPlhmcu/
cp ../../wdbecmbd/WdbeMtpPlhmcu/*.cpp $BUILDROOT/wdbecmbd/WdbeMtpPlhmcu/

cp Makefile_WdbeMtpCplmstbu $BUILDROOT/wdbecmbd/WdbeMtpCplmstbu/Makefile

cp ../../wdbecmbd/WdbeMtpCplmstbu/*.h $BUILDROOT/wdbecmbd/WdbeMtpCplmstbu/
cp ../../wdbecmbd/WdbeMtpCplmstbu/*.cpp $BUILDROOT/wdbecmbd/WdbeMtpCplmstbu/

cp Makefile_WdbeMtpCplmsttd $BUILDROOT/wdbecmbd/WdbeMtpCplmsttd/Makefile

cp ../../wdbecmbd/WdbeMtpCplmsttd/*.h $BUILDROOT/wdbecmbd/WdbeMtpCplmsttd/
cp ../../wdbecmbd/WdbeMtpCplmsttd/*.cpp $BUILDROOT/wdbecmbd/WdbeMtpCplmsttd/

cp Makefile_WdbeMtpGenfst $BUILDROOT/wdbecmbd/WdbeMtpGenfst/Makefile

cp ../../wdbecmbd/WdbeMtpGenfst/*.h $BUILDROOT/wdbecmbd/WdbeMtpGenfst/
cp ../../wdbecmbd/WdbeMtpGenfst/*.cpp $BUILDROOT/wdbecmbd/WdbeMtpGenfst/

cp Makefile_WdbeMtpWrfpga $BUILDROOT/wdbecmbd/WdbeMtpWrfpga/Makefile

cp ../../wdbecmbd/WdbeMtpWrfpga/*.h $BUILDROOT/wdbecmbd/WdbeMtpWrfpga/
cp ../../wdbecmbd/WdbeMtpWrfpga/*.cpp $BUILDROOT/wdbecmbd/WdbeMtpWrfpga/

cp Makefile_WdbeMtpWrmcu $BUILDROOT/wdbecmbd/WdbeMtpWrmcu/Makefile

cp ../../wdbecmbd/WdbeMtpWrmcu/*.h $BUILDROOT/wdbecmbd/WdbeMtpWrmcu/
cp ../../wdbecmbd/WdbeMtpWrmcu/*.cpp $BUILDROOT/wdbecmbd/WdbeMtpWrmcu/

cp Makefile_WdbePlhfpga $BUILDROOT/wdbecmbd/WdbePlhfpga/Makefile

cp ../../wdbecmbd/WdbePlhfpga/*.h $BUILDROOT/wdbecmbd/WdbePlhfpga/
cp ../../wdbecmbd/WdbePlhfpga/*.cpp $BUILDROOT/wdbecmbd/WdbePlhfpga/

cp Makefile_WdbePlhmcu $BUILDROOT/wdbecmbd/WdbePlhmcu/Makefile

cp ../../wdbecmbd/WdbePlhmcu/*.h $BUILDROOT/wdbecmbd/WdbePlhmcu/
cp ../../wdbecmbd/WdbePlhmcu/*.cpp $BUILDROOT/wdbecmbd/WdbePlhmcu/

cp Makefile_WdbePrcfile $BUILDROOT/wdbecmbd/WdbePrcfile/Makefile

cp ../../wdbecmbd/WdbePrcfile/*.h $BUILDROOT/wdbecmbd/WdbePrcfile/
cp ../../wdbecmbd/WdbePrcfile/*.cpp $BUILDROOT/wdbecmbd/WdbePrcfile/

cp Makefile_WdbePrctree $BUILDROOT/wdbecmbd/WdbePrctree/Makefile

cp ../../wdbecmbd/WdbePrctree/*.h $BUILDROOT/wdbecmbd/WdbePrctree/
cp ../../wdbecmbd/WdbePrctree/*.cpp $BUILDROOT/wdbecmbd/WdbePrctree/

cp Makefile_WdbeWrdev $BUILDROOT/wdbecmbd/WdbeWrdev/Makefile

cp ../../wdbecmbd/WdbeWrdev/*.h $BUILDROOT/wdbecmbd/WdbeWrdev/
cp ../../wdbecmbd/WdbeWrdev/*.cpp $BUILDROOT/wdbecmbd/WdbeWrdev/

cp Makefile_WdbeWrfpga $BUILDROOT/wdbecmbd/WdbeWrfpga/Makefile

cp ../../wdbecmbd/WdbeWrfpga/*.h $BUILDROOT/wdbecmbd/WdbeWrfpga/
cp ../../wdbecmbd/WdbeWrfpga/*.cpp $BUILDROOT/wdbecmbd/WdbeWrfpga/

cp Makefile_WdbeWrmcu $BUILDROOT/wdbecmbd/WdbeWrmcu/Makefile

cp ../../wdbecmbd/WdbeWrmcu/*.h $BUILDROOT/wdbecmbd/WdbeWrmcu/
cp ../../wdbecmbd/WdbeWrmcu/*.cpp $BUILDROOT/wdbecmbd/WdbeWrmcu/

cp Makefile_WdbeWrterm $BUILDROOT/wdbecmbd/WdbeWrterm/Makefile

cp ../../wdbecmbd/WdbeWrterm/*.h $BUILDROOT/wdbecmbd/WdbeWrterm/
cp ../../wdbecmbd/WdbeWrterm/*.cpp $BUILDROOT/wdbecmbd/WdbeWrterm/
