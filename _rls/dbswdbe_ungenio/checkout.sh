#!/bin/bash
# file checkout.sh
# checkout script for Wdbe database access library, release dbswdbe_ungenio
# author Alexander Wirthmueller
# date created: 11 Jul 2020
# modified: 11 Jul 2020

export set SRCROOT=/Users/mpsitech/src

mkdir $SRCROOT/dbswdbe

cp makeall.sh $SRCROOT/dbswdbe/

cp Makefile $SRCROOT/dbswdbe/

cp ../../dbswdbe/DbsWdbe.h $SRCROOT/dbswdbe/
cp ../../dbswdbe/DbsWdbe_vecs.cpp $SRCROOT/dbswdbe/
cp ../../dbswdbe/DbsWdbe.cpp $SRCROOT/dbswdbe/

cp ../../dbswdbe/Wdbe*.h $SRCROOT/dbswdbe/
cp ../../dbswdbe/Wdbe*.cpp $SRCROOT/dbswdbe/

