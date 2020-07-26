#!/bin/bash
# file checkout.sh
# checkout script for Wdbe operation daemon, release wdbeopd1_ungenio
# author Alexander Wirthmueller
# date created: 11 Jul 2020
# modified: 11 Jul 2020

export set SRCROOT=/Users/mpsitech/src
export set LIBROOT=/Users/mpsitech/lib
export set BINROOT=/Users/mpsitech/bin
export set REPROOT=/Users/mpsitech/srcrep
export set CMBDSRCROOT=$REPROOT/wdbe/wdbecmbd

mkdir $SRCROOT/wdbeopd1
mkdir $SRCROOT/wdbeopd1/IexWdbe
mkdir $SRCROOT/wdbeopd1/VecWdbe
mkdir $SRCROOT/wdbeopd1/WdbeWrmcu
mkdir $SRCROOT/wdbeopd1/WdbeWrfpga
mkdir $SRCROOT/wdbeopd1/WdbeWrdev
mkdir $SRCROOT/wdbeopd1/WdbePrctree
mkdir $SRCROOT/wdbeopd1/WdbePrcfile
mkdir $SRCROOT/wdbeopd1/WdbePlhmcu
mkdir $SRCROOT/wdbeopd1/WdbePlhfpga
mkdir $SRCROOT/wdbeopd1/WdbeModdet
mkdir $SRCROOT/wdbeopd1/WdbeModbsc

mkdir $LIBROOT/wdbeopd1

mkdir $BINROOT/wdbeopd1

cp make.sh $SRCROOT/wdbeopd1/
cp remake.sh $SRCROOT/wdbeopd1/

cp Makefile.inc $SRCROOT/wdbeopd1/
cp Makefile $SRCROOT/wdbeopd1/

cp ../../wdbeopd1/Wdbeopd.h $SRCROOT/wdbeopd1/
cp ../../wdbeopd1/Wdbeopd.cpp $SRCROOT/wdbeopd1/

cp ../../wdbeopd1/WdbeopdEngsrv.h $SRCROOT/wdbeopd1/
cp ../../wdbeopd1/WdbeopdEngsrv.cpp $SRCROOT/wdbeopd1/

cp ../../wdbeopd1/WdbeopdOpprc.h $SRCROOT/wdbeopd1/
cp ../../wdbeopd1/WdbeopdOpprc.cpp $SRCROOT/wdbeopd1/

cp ../../wdbeopd1/Wdbeopd_exe.h $SRCROOT/wdbeopd1/
cp ../../wdbeopd1/Wdbeopd_exe.cpp $SRCROOT/wdbeopd1/

cp $CMBDSRCROOT/Wdbe.h $SRCROOT/wdbeopd1/
cp $CMBDSRCROOT/Wdbe.cpp $SRCROOT/wdbeopd1/

cp Makefile_IexWdbe $SRCROOT/wdbeopd1/IexWdbe/Makefile

cp $CMBDSRCROOT/IexWdbe/IexWdbe*.h $SRCROOT/wdbeopd1/IexWdbe/
cp $CMBDSRCROOT/IexWdbe/IexWdbe*.cpp $SRCROOT/wdbeopd1/IexWdbe/

cp Makefile_VecWdbe $SRCROOT/wdbeopd1/VecWdbe/Makefile

cp $CMBDSRCROOT/VecWdbe/Vec*.h $SRCROOT/wdbeopd1/VecWdbe/
cp $CMBDSRCROOT/VecWdbe/Vec*.cpp $SRCROOT/wdbeopd1/VecWdbe/

cp Makefile_WdbeWrmcu $SRCROOT/wdbeopd1/WdbeWrmcu/Makefile

cp $CMBDSRCROOT/WdbeWrmcu/WdbeWrmcu*.h $SRCROOT/wdbeopd1/WdbeWrmcu/
cp $CMBDSRCROOT/WdbeWrmcu/WdbeWrmcu*.cpp $SRCROOT/wdbeopd1/WdbeWrmcu/

cp Makefile_WdbeWrfpga $SRCROOT/wdbeopd1/WdbeWrfpga/Makefile

cp $CMBDSRCROOT/WdbeWrfpga/WdbeWrfpga*.h $SRCROOT/wdbeopd1/WdbeWrfpga/
cp $CMBDSRCROOT/WdbeWrfpga/WdbeWrfpga*.cpp $SRCROOT/wdbeopd1/WdbeWrfpga/

cp Makefile_WdbeWrdev $SRCROOT/wdbeopd1/WdbeWrdev/Makefile

cp $CMBDSRCROOT/WdbeWrdev/WdbeWrdev*.h $SRCROOT/wdbeopd1/WdbeWrdev/
cp $CMBDSRCROOT/WdbeWrdev/WdbeWrdev*.cpp $SRCROOT/wdbeopd1/WdbeWrdev/

cp Makefile_WdbePrctree $SRCROOT/wdbeopd1/WdbePrctree/Makefile

cp $CMBDSRCROOT/WdbePrctree/WdbePrctree*.h $SRCROOT/wdbeopd1/WdbePrctree/
cp $CMBDSRCROOT/WdbePrctree/WdbePrctree*.cpp $SRCROOT/wdbeopd1/WdbePrctree/

cp Makefile_WdbePrcfile $SRCROOT/wdbeopd1/WdbePrcfile/Makefile

cp $CMBDSRCROOT/WdbePrcfile/WdbePrcfile*.h $SRCROOT/wdbeopd1/WdbePrcfile/
cp $CMBDSRCROOT/WdbePrcfile/WdbePrcfile*.cpp $SRCROOT/wdbeopd1/WdbePrcfile/

cp Makefile_WdbePlhmcu $SRCROOT/wdbeopd1/WdbePlhmcu/Makefile

cp $CMBDSRCROOT/WdbePlhmcu/WdbePlhmcu*.h $SRCROOT/wdbeopd1/WdbePlhmcu/
cp $CMBDSRCROOT/WdbePlhmcu/WdbePlhmcu*.cpp $SRCROOT/wdbeopd1/WdbePlhmcu/

cp Makefile_WdbePlhfpga $SRCROOT/wdbeopd1/WdbePlhfpga/Makefile

cp $CMBDSRCROOT/WdbePlhfpga/WdbePlhfpga*.h $SRCROOT/wdbeopd1/WdbePlhfpga/
cp $CMBDSRCROOT/WdbePlhfpga/WdbePlhfpga*.cpp $SRCROOT/wdbeopd1/WdbePlhfpga/

cp Makefile_WdbeModdet $SRCROOT/wdbeopd1/WdbeModdet/Makefile

cp $CMBDSRCROOT/WdbeModdet/WdbeModdet*.h $SRCROOT/wdbeopd1/WdbeModdet/
cp $CMBDSRCROOT/WdbeModdet/WdbeModdet*.cpp $SRCROOT/wdbeopd1/WdbeModdet/

cp Makefile_WdbeModbsc $SRCROOT/wdbeopd1/WdbeModbsc/Makefile

cp $CMBDSRCROOT/WdbeModbsc/WdbeModbsc*.h $SRCROOT/wdbeopd1/WdbeModbsc/
cp $CMBDSRCROOT/WdbeModbsc/WdbeModbsc*.cpp $SRCROOT/wdbeopd1/WdbeModbsc/

