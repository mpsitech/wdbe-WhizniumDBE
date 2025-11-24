#!/bin/bash
# file checkout.sh
# checkout script for Wdbe operation daemon, release wdbeopd2_mac
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
export set REPROOT=${WHIZDEVROOT}/rep
export set CMBDBUILDROOT=$REPROOT/wdbe/wdbecmbd

mkdir $BUILDROOT/wdbeopd2
mkdir $BUILDROOT/wdbeopd2/IexWdbe
mkdir $BUILDROOT/wdbeopd2/VecWdbe
mkdir $BUILDROOT/wdbeopd2/WdbeMtpPlhfpga
mkdir $BUILDROOT/wdbeopd2/WdbeMtpPlhmcu
mkdir $BUILDROOT/wdbeopd2/WdbeMtpCplmstbu
mkdir $BUILDROOT/wdbeopd2/WdbeMtpCplmsttd
mkdir $BUILDROOT/wdbeopd2/WdbeMtpGenfst
mkdir $BUILDROOT/wdbeopd2/WdbeMtpWrfpga
mkdir $BUILDROOT/wdbeopd2/WdbeMtpWrmcu

mkdir $LIBROOT/wdbeopd2

mkdir $BINROOT/wdbeopd2

cp make.sh $BUILDROOT/wdbeopd2/
cp remake.sh $BUILDROOT/wdbeopd2/

cp Makefile.inc $BUILDROOT/wdbeopd2/
cp Makefile $BUILDROOT/wdbeopd2/

cp ../../wdbeopd2/Wdbeopd.h $BUILDROOT/wdbeopd2/
cp ../../wdbeopd2/Wdbeopd.cpp $BUILDROOT/wdbeopd2/

cp ../../wdbeopd2/WdbeopdEngsrv.h $BUILDROOT/wdbeopd2/
cp ../../wdbeopd2/WdbeopdEngsrv.cpp $BUILDROOT/wdbeopd2/

cp ../../wdbeopd2/WdbeopdOpprc.h $BUILDROOT/wdbeopd2/
cp ../../wdbeopd2/WdbeopdOpprc.cpp $BUILDROOT/wdbeopd2/

cp ../../wdbeopd2/Wdbeopd_exe.h $BUILDROOT/wdbeopd2/
cp ../../wdbeopd2/Wdbeopd_exe.cpp $BUILDROOT/wdbeopd2/

cp $CMBDBUILDROOT/Wdbe.h $BUILDROOT/wdbeopd2/
cp $CMBDBUILDROOT/Wdbe.cpp $BUILDROOT/wdbeopd2/

cp Makefile_IexWdbe $BUILDROOT/wdbeopd2/IexWdbe/Makefile

cp $CMBDBUILDROOT/IexWdbe/IexWdbe*.h $BUILDROOT/wdbeopd2/IexWdbe/
cp $CMBDBUILDROOT/IexWdbe/IexWdbe*.cpp $BUILDROOT/wdbeopd2/IexWdbe/

cp Makefile_VecWdbe $BUILDROOT/wdbeopd2/VecWdbe/Makefile

cp $CMBDBUILDROOT/VecWdbe/Vec*.h $BUILDROOT/wdbeopd2/VecWdbe/
cp $CMBDBUILDROOT/VecWdbe/Vec*.cpp $BUILDROOT/wdbeopd2/VecWdbe/

cp Makefile_WdbeMtpPlhfpga $BUILDROOT/wdbeopd2/WdbeMtpPlhfpga/Makefile

cp $CMBDBUILDROOT/WdbeMtpPlhfpga/WdbeMtpPlhfpga*.h $BUILDROOT/wdbeopd2/WdbeMtpPlhfpga/
cp $CMBDBUILDROOT/WdbeMtpPlhfpga/WdbeMtpPlhfpga*.cpp $BUILDROOT/wdbeopd2/WdbeMtpPlhfpga/

cp Makefile_WdbeMtpPlhmcu $BUILDROOT/wdbeopd2/WdbeMtpPlhmcu/Makefile

cp $CMBDBUILDROOT/WdbeMtpPlhmcu/WdbeMtpPlhmcu*.h $BUILDROOT/wdbeopd2/WdbeMtpPlhmcu/
cp $CMBDBUILDROOT/WdbeMtpPlhmcu/WdbeMtpPlhmcu*.cpp $BUILDROOT/wdbeopd2/WdbeMtpPlhmcu/

cp Makefile_WdbeMtpCplmstbu $BUILDROOT/wdbeopd2/WdbeMtpCplmstbu/Makefile

cp $CMBDBUILDROOT/WdbeMtpCplmstbu/WdbeMtpCplmstbu*.h $BUILDROOT/wdbeopd2/WdbeMtpCplmstbu/
cp $CMBDBUILDROOT/WdbeMtpCplmstbu/WdbeMtpCplmstbu*.cpp $BUILDROOT/wdbeopd2/WdbeMtpCplmstbu/

cp Makefile_WdbeMtpCplmsttd $BUILDROOT/wdbeopd2/WdbeMtpCplmsttd/Makefile

cp $CMBDBUILDROOT/WdbeMtpCplmsttd/WdbeMtpCplmsttd*.h $BUILDROOT/wdbeopd2/WdbeMtpCplmsttd/
cp $CMBDBUILDROOT/WdbeMtpCplmsttd/WdbeMtpCplmsttd*.cpp $BUILDROOT/wdbeopd2/WdbeMtpCplmsttd/

cp Makefile_WdbeMtpGenfst $BUILDROOT/wdbeopd2/WdbeMtpGenfst/Makefile

cp $CMBDBUILDROOT/WdbeMtpGenfst/WdbeMtpGenfst*.h $BUILDROOT/wdbeopd2/WdbeMtpGenfst/
cp $CMBDBUILDROOT/WdbeMtpGenfst/WdbeMtpGenfst*.cpp $BUILDROOT/wdbeopd2/WdbeMtpGenfst/

cp Makefile_WdbeMtpWrfpga $BUILDROOT/wdbeopd2/WdbeMtpWrfpga/Makefile

cp $CMBDBUILDROOT/WdbeMtpWrfpga/WdbeMtpWrfpga*.h $BUILDROOT/wdbeopd2/WdbeMtpWrfpga/
cp $CMBDBUILDROOT/WdbeMtpWrfpga/WdbeMtpWrfpga*.cpp $BUILDROOT/wdbeopd2/WdbeMtpWrfpga/

cp Makefile_WdbeMtpWrmcu $BUILDROOT/wdbeopd2/WdbeMtpWrmcu/Makefile

cp $CMBDBUILDROOT/WdbeMtpWrmcu/WdbeMtpWrmcu*.h $BUILDROOT/wdbeopd2/WdbeMtpWrmcu/
cp $CMBDBUILDROOT/WdbeMtpWrmcu/WdbeMtpWrmcu*.cpp $BUILDROOT/wdbeopd2/WdbeMtpWrmcu/
