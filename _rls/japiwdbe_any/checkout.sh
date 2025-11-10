#!/bin/bash
# file checkout.sh
# checkout script for Wdbe Java API library, release japiwdbe_any
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 5 Nov 2025
# IP header --- ABOVE

if [ -z ${JAVAROOT+x} ]; then
	echo "JAVAROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

mkdir $JAVAROOT/apiwdbe
mkdir $JAVAROOT/apiwdbe/src
mkdir $JAVAROOT/apiwdbe/src/apiwdbe
mkdir $JAVAROOT/apiwdbe/bin
mkdir $JAVAROOT/apiwdbe/bin/apiwdbe

cp ../../japiwdbe/*.java $JAVAROOT/apiwdbe/src/apiwdbe/
