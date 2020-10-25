#!/bin/bash
# file checkout.sh
# checkout script for Wdbe operation daemon, release wdbeopd2_jack
# author Alexander Wirthmueller
# date created: 23 Aug 2020
# modified: 23 Aug 2020

export set SRCROOT=/home/mpsitech/src
export set LIBROOT=/home/mpsitech/lib
export set BINROOT=/home/mpsitech/bin
export set REPROOT=/home/mpsitech/srcrep
export set CMBDSRCROOT=$REPROOT/wdbe/wdbecmbd

mkdir $SRCROOT/wdbeopd2
mkdir $SRCROOT/wdbeopd2/IexWdbe
mkdir $SRCROOT/wdbeopd2/VecWdbe
mkdir $SRCROOT/wdbeopd2/WdbeMtpPlhfpga
mkdir $SRCROOT/wdbeopd2/WdbeMtpPlhmcu
mkdir $SRCROOT/wdbeopd2/WdbeMtpModbscbu
mkdir $SRCROOT/wdbeopd2/WdbeMtpModbsctd
mkdir $SRCROOT/wdbeopd2/WdbeMtpModdet
mkdir $SRCROOT/wdbeopd2/WdbeMtpWrfpga
mkdir $SRCROOT/wdbeopd2/WdbeMtpWrmcu

mkdir $LIBROOT/wdbeopd2

mkdir $BINROOT/wdbeopd2

cp make.sh $SRCROOT/wdbeopd2/
cp remake.sh $SRCROOT/wdbeopd2/

cp Makefile.inc $SRCROOT/wdbeopd2/
cp Makefile $SRCROOT/wdbeopd2/

cp ../../wdbeopd2/Wdbeopd.h $SRCROOT/wdbeopd2/
cp ../../wdbeopd2/Wdbeopd.cpp $SRCROOT/wdbeopd2/

cp ../../wdbeopd2/WdbeopdEngsrv.h $SRCROOT/wdbeopd2/
cp ../../wdbeopd2/WdbeopdEngsrv.cpp $SRCROOT/wdbeopd2/

cp ../../wdbeopd2/WdbeopdOpprc.h $SRCROOT/wdbeopd2/
cp ../../wdbeopd2/WdbeopdOpprc.cpp $SRCROOT/wdbeopd2/

cp ../../wdbeopd2/Wdbeopd_exe.h $SRCROOT/wdbeopd2/
cp ../../wdbeopd2/Wdbeopd_exe.cpp $SRCROOT/wdbeopd2/

cp $CMBDSRCROOT/Wdbe.h $SRCROOT/wdbeopd2/
cp $CMBDSRCROOT/Wdbe.cpp $SRCROOT/wdbeopd2/

cp Makefile_IexWdbe $SRCROOT/wdbeopd2/IexWdbe/Makefile

cp $CMBDSRCROOT/IexWdbe/IexWdbe*.h $SRCROOT/wdbeopd2/IexWdbe/
cp $CMBDSRCROOT/IexWdbe/IexWdbe*.cpp $SRCROOT/wdbeopd2/IexWdbe/

cp Makefile_VecWdbe $SRCROOT/wdbeopd2/VecWdbe/Makefile

cp $CMBDSRCROOT/VecWdbe/Vec*.h $SRCROOT/wdbeopd2/VecWdbe/
cp $CMBDSRCROOT/VecWdbe/Vec*.cpp $SRCROOT/wdbeopd2/VecWdbe/

cp Makefile_WdbeMtpPlhfpga $SRCROOT/wdbeopd2/WdbeMtpPlhfpga/Makefile

cp $CMBDSRCROOT/WdbeMtpPlhfpga/WdbeMtpPlhfpga*.h $SRCROOT/wdbeopd2/WdbeMtpPlhfpga/
cp $CMBDSRCROOT/WdbeMtpPlhfpga/WdbeMtpPlhfpga*.cpp $SRCROOT/wdbeopd2/WdbeMtpPlhfpga/

cp Makefile_WdbeMtpPlhmcu $SRCROOT/wdbeopd2/WdbeMtpPlhmcu/Makefile

cp $CMBDSRCROOT/WdbeMtpPlhmcu/WdbeMtpPlhmcu*.h $SRCROOT/wdbeopd2/WdbeMtpPlhmcu/
cp $CMBDSRCROOT/WdbeMtpPlhmcu/WdbeMtpPlhmcu*.cpp $SRCROOT/wdbeopd2/WdbeMtpPlhmcu/

cp Makefile_WdbeMtpModbscbu $SRCROOT/wdbeopd2/WdbeMtpModbscbu/Makefile

cp $CMBDSRCROOT/WdbeMtpModbscbu/WdbeMtpModbscbu*.h $SRCROOT/wdbeopd2/WdbeMtpModbscbu/
cp $CMBDSRCROOT/WdbeMtpModbscbu/WdbeMtpModbscbu*.cpp $SRCROOT/wdbeopd2/WdbeMtpModbscbu/

cp Makefile_WdbeMtpModbsctd $SRCROOT/wdbeopd2/WdbeMtpModbsctd/Makefile

cp $CMBDSRCROOT/WdbeMtpModbsctd/WdbeMtpModbsctd*.h $SRCROOT/wdbeopd2/WdbeMtpModbsctd/
cp $CMBDSRCROOT/WdbeMtpModbsctd/WdbeMtpModbsctd*.cpp $SRCROOT/wdbeopd2/WdbeMtpModbsctd/

cp Makefile_WdbeMtpModdet $SRCROOT/wdbeopd2/WdbeMtpModdet/Makefile

cp $CMBDSRCROOT/WdbeMtpModdet/WdbeMtpModdet*.h $SRCROOT/wdbeopd2/WdbeMtpModdet/
cp $CMBDSRCROOT/WdbeMtpModdet/WdbeMtpModdet*.cpp $SRCROOT/wdbeopd2/WdbeMtpModdet/

cp Makefile_WdbeMtpWrfpga $SRCROOT/wdbeopd2/WdbeMtpWrfpga/Makefile

cp $CMBDSRCROOT/WdbeMtpWrfpga/WdbeMtpWrfpga*.h $SRCROOT/wdbeopd2/WdbeMtpWrfpga/
cp $CMBDSRCROOT/WdbeMtpWrfpga/WdbeMtpWrfpga*.cpp $SRCROOT/wdbeopd2/WdbeMtpWrfpga/

cp Makefile_WdbeMtpWrmcu $SRCROOT/wdbeopd2/WdbeMtpWrmcu/Makefile

cp $CMBDSRCROOT/WdbeMtpWrmcu/WdbeMtpWrmcu*.h $SRCROOT/wdbeopd2/WdbeMtpWrmcu/
cp $CMBDSRCROOT/WdbeMtpWrmcu/WdbeMtpWrmcu*.cpp $SRCROOT/wdbeopd2/WdbeMtpWrmcu/

