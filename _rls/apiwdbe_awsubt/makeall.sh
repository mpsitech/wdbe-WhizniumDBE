#!/bin/bash
# file makeall.sh
# make script for Wdbe API library, release apiwdbe_awsubt
# author Alexander Wirthmueller
# date created: 23 Aug 2020
# modified: 23 Aug 2020

make ApiWdbe.h.gch
if [ $? -ne 0 ]; then
	exit
fi

make -j2
if [ $? -ne 0 ]; then
	exit
fi

make install

