#!/bin/bash
# file remake.sh
# re-make script for Wdbe daemon, release wdbed_ubuntu
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 7 Feb 2024
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set BUILDROOT=${WHIZSDKROOT}/build
export set REPROOT=${WHIZDEVROOT}/rep

cd $REPROOT/wdbe/_rls/wdbed_ubuntu
./checkout.sh

cd $BUILDROOT/wdbed

./make.sh "$@"
