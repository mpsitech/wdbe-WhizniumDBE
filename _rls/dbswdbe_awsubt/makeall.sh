#!/bin/bash
# file makeall.sh
# make script for Wdbe database access library, release dbswdbe_awsubt
# author Alexander Wirthmueller
# date created: 23 Aug 2020
# modified: 23 Aug 2020

make DbsWdbe.h.gch
if [ $? -ne 0 ]; then
	exit
fi

make -j2
if [ $? -ne 0 ]; then
	exit
fi

make install

