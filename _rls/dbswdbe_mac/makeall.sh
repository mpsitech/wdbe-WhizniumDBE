#!/bin/bash
# file makeall.sh
# make script for Wdbe database access library, release dbswdbe_mac
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 7 Feb 2024
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

make DbsWdbe.h.gch
if [ $? -ne 0 ]; then
	exit
fi

make -j4
if [ $? -ne 0 ]; then
	exit
fi

make install
