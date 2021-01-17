#!/bin/bash
# file checkout.sh
# checkout script for Wdbe API library, release apiwdbe_ubuntu
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 13 Jan 2021
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set BUILDROOT=${WHIZSDKROOT}/build

mkdir $BUILDROOT/apiwdbe

cp makeall.sh $BUILDROOT/apiwdbe/

cp Makefile $BUILDROOT/apiwdbe/

cp ../../apiwdbe/*.h $BUILDROOT/apiwdbe/
cp ../../apiwdbe/*.cpp $BUILDROOT/apiwdbe/
