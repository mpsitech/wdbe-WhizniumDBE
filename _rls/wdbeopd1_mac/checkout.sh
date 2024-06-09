#!/bin/bash
# file checkout.sh
# checkout script for Wdbe operation daemon, release wdbeopd1_mac
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 7 Feb 2024
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

mkdir $BUILDROOT/wdbeopd1
mkdir $BUILDROOT/wdbeopd1/IexWdbe
mkdir $BUILDROOT/wdbeopd1/VecWdbe
mkdir $BUILDROOT/wdbeopd1/WdbeWrterm
mkdir $BUILDROOT/wdbeopd1/WdbeWrmcu
mkdir $BUILDROOT/wdbeopd1/WdbeWrfpga
mkdir $BUILDROOT/wdbeopd1/WdbeWrdev
mkdir $BUILDROOT/wdbeopd1/WdbePrctree
mkdir $BUILDROOT/wdbeopd1/WdbePrcfile
mkdir $BUILDROOT/wdbeopd1/WdbePlhmcu
mkdir $BUILDROOT/wdbeopd1/WdbePlhfpga
mkdir $BUILDROOT/wdbeopd1/WdbeGenfst
mkdir $BUILDROOT/wdbeopd1/WdbeGen
mkdir $BUILDROOT/wdbeopd1/WdbeCplmst

mkdir $LIBROOT/wdbeopd1

mkdir $BINROOT/wdbeopd1

cp make.sh $BUILDROOT/wdbeopd1/
cp remake.sh $BUILDROOT/wdbeopd1/

cp Makefile.inc $BUILDROOT/wdbeopd1/
cp Makefile $BUILDROOT/wdbeopd1/

cp ../../wdbeopd1/Wdbeopd.h $BUILDROOT/wdbeopd1/
cp ../../wdbeopd1/Wdbeopd.cpp $BUILDROOT/wdbeopd1/

cp ../../wdbeopd1/WdbeopdEngsrv.h $BUILDROOT/wdbeopd1/
cp ../../wdbeopd1/WdbeopdEngsrv.cpp $BUILDROOT/wdbeopd1/

cp ../../wdbeopd1/WdbeopdOpprc.h $BUILDROOT/wdbeopd1/
cp ../../wdbeopd1/WdbeopdOpprc.cpp $BUILDROOT/wdbeopd1/

cp ../../wdbeopd1/Wdbeopd_exe.h $BUILDROOT/wdbeopd1/
cp ../../wdbeopd1/Wdbeopd_exe.cpp $BUILDROOT/wdbeopd1/

cp $CMBDBUILDROOT/Wdbe.h $BUILDROOT/wdbeopd1/
cp $CMBDBUILDROOT/Wdbe.cpp $BUILDROOT/wdbeopd1/

cp Makefile_IexWdbe $BUILDROOT/wdbeopd1/IexWdbe/Makefile

cp $CMBDBUILDROOT/IexWdbe/IexWdbe*.h $BUILDROOT/wdbeopd1/IexWdbe/
cp $CMBDBUILDROOT/IexWdbe/IexWdbe*.cpp $BUILDROOT/wdbeopd1/IexWdbe/

cp Makefile_VecWdbe $BUILDROOT/wdbeopd1/VecWdbe/Makefile

cp $CMBDBUILDROOT/VecWdbe/Vec*.h $BUILDROOT/wdbeopd1/VecWdbe/
cp $CMBDBUILDROOT/VecWdbe/Vec*.cpp $BUILDROOT/wdbeopd1/VecWdbe/

cp Makefile_WdbeWrterm $BUILDROOT/wdbeopd1/WdbeWrterm/Makefile

cp $CMBDBUILDROOT/WdbeWrterm/WdbeWrterm*.h $BUILDROOT/wdbeopd1/WdbeWrterm/
cp $CMBDBUILDROOT/WdbeWrterm/WdbeWrterm*.cpp $BUILDROOT/wdbeopd1/WdbeWrterm/

cp Makefile_WdbeWrmcu $BUILDROOT/wdbeopd1/WdbeWrmcu/Makefile

cp $CMBDBUILDROOT/WdbeWrmcu/WdbeWrmcu*.h $BUILDROOT/wdbeopd1/WdbeWrmcu/
cp $CMBDBUILDROOT/WdbeWrmcu/WdbeWrmcu*.cpp $BUILDROOT/wdbeopd1/WdbeWrmcu/

cp Makefile_WdbeWrfpga $BUILDROOT/wdbeopd1/WdbeWrfpga/Makefile

cp $CMBDBUILDROOT/WdbeWrfpga/WdbeWrfpga*.h $BUILDROOT/wdbeopd1/WdbeWrfpga/
cp $CMBDBUILDROOT/WdbeWrfpga/WdbeWrfpga*.cpp $BUILDROOT/wdbeopd1/WdbeWrfpga/

cp Makefile_WdbeWrdev $BUILDROOT/wdbeopd1/WdbeWrdev/Makefile

cp $CMBDBUILDROOT/WdbeWrdev/WdbeWrdev*.h $BUILDROOT/wdbeopd1/WdbeWrdev/
cp $CMBDBUILDROOT/WdbeWrdev/WdbeWrdev*.cpp $BUILDROOT/wdbeopd1/WdbeWrdev/

cp Makefile_WdbePrctree $BUILDROOT/wdbeopd1/WdbePrctree/Makefile

cp $CMBDBUILDROOT/WdbePrctree/WdbePrctree*.h $BUILDROOT/wdbeopd1/WdbePrctree/
cp $CMBDBUILDROOT/WdbePrctree/WdbePrctree*.cpp $BUILDROOT/wdbeopd1/WdbePrctree/

cp Makefile_WdbePrcfile $BUILDROOT/wdbeopd1/WdbePrcfile/Makefile

cp $CMBDBUILDROOT/WdbePrcfile/WdbePrcfile*.h $BUILDROOT/wdbeopd1/WdbePrcfile/
cp $CMBDBUILDROOT/WdbePrcfile/WdbePrcfile*.cpp $BUILDROOT/wdbeopd1/WdbePrcfile/

cp Makefile_WdbePlhmcu $BUILDROOT/wdbeopd1/WdbePlhmcu/Makefile

cp $CMBDBUILDROOT/WdbePlhmcu/WdbePlhmcu*.h $BUILDROOT/wdbeopd1/WdbePlhmcu/
cp $CMBDBUILDROOT/WdbePlhmcu/WdbePlhmcu*.cpp $BUILDROOT/wdbeopd1/WdbePlhmcu/

cp Makefile_WdbePlhfpga $BUILDROOT/wdbeopd1/WdbePlhfpga/Makefile

cp $CMBDBUILDROOT/WdbePlhfpga/WdbePlhfpga*.h $BUILDROOT/wdbeopd1/WdbePlhfpga/
cp $CMBDBUILDROOT/WdbePlhfpga/WdbePlhfpga*.cpp $BUILDROOT/wdbeopd1/WdbePlhfpga/

cp Makefile_WdbeGenfst $BUILDROOT/wdbeopd1/WdbeGenfst/Makefile

cp $CMBDBUILDROOT/WdbeGenfst/WdbeGenfst*.h $BUILDROOT/wdbeopd1/WdbeGenfst/
cp $CMBDBUILDROOT/WdbeGenfst/WdbeGenfst*.cpp $BUILDROOT/wdbeopd1/WdbeGenfst/

cp Makefile_WdbeGen $BUILDROOT/wdbeopd1/WdbeGen/Makefile

cp $CMBDBUILDROOT/WdbeGen/WdbeGen*.h $BUILDROOT/wdbeopd1/WdbeGen/
cp $CMBDBUILDROOT/WdbeGen/WdbeGen*.cpp $BUILDROOT/wdbeopd1/WdbeGen/

cp Makefile_WdbeCplmst $BUILDROOT/wdbeopd1/WdbeCplmst/Makefile

cp $CMBDBUILDROOT/WdbeCplmst/WdbeCplmst*.h $BUILDROOT/wdbeopd1/WdbeCplmst/
cp $CMBDBUILDROOT/WdbeCplmst/WdbeCplmst*.cpp $BUILDROOT/wdbeopd1/WdbeCplmst/
