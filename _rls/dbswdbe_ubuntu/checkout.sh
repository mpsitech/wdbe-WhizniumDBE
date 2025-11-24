#!/bin/bash
# file checkout.sh
# checkout script for Wdbe database access library, release dbswdbe_ubuntu
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 23 Nov 2025
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set BUILDROOT=${WHIZSDKROOT}/build

mkdir $BUILDROOT/dbswdbe

cp makeall.sh $BUILDROOT/dbswdbe/

cp Makefile $BUILDROOT/dbswdbe/

cp ../../dbswdbe/DbsWdbe.h $BUILDROOT/dbswdbe/
cp ../../dbswdbe/DbsWdbe_vecs.cpp $BUILDROOT/dbswdbe/
cp ../../dbswdbe/DbsWdbe.cpp $BUILDROOT/dbswdbe/

cp ../../dbswdbe/Wdbe*.h $BUILDROOT/dbswdbe/
cp ../../dbswdbe/Wdbe*.cpp $BUILDROOT/dbswdbe/
