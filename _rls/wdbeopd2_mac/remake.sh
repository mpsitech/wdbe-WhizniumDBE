#!/bin/bash
# file remake.sh
# re-make script for Wdbe operation daemon, release wdbeopd2_mac
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 23 Oct 2021
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set BUILDROOT=${WHIZSDKROOT}/build
export set REPROOT=${WHIZDEVROOT}/rep

cd $REPROOT/wdbe/_rls/wdbeopd2_mac
./checkout.sh

cd $BUILDROOT/wdbeopd2

./make.sh "$@"
