#!/bin/bash
# file checkin.sh
# checkin script for Wdbe web-based UI, release webappwdbe_any
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 7 Feb 2024
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set REPROOT=${WHIZDEVROOT}/rep

cp -r * $REPROOT/wdbe/webappwdbe/
mv $REPROOT/wdbe/webappwdbe/favicon.ico $REPROOT/wdbe/webappwdbe/iconwdbe/
touch $REPROOT/wdbe/webappwdbe/iconwdbe/"IP folder --- KEEP"

rm $REPROOT/wdbe/webappwdbe/checkin.sh
