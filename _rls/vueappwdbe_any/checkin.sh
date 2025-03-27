#!/bin/bash
# file checkin.sh
# checkin script for Wdbe Vue.js UI, release vueappwdbe_any
# copyright: (C) 2022 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 3 Mar 2025
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set REPROOT=${WHIZDEVROOT}/rep

cp AppWdbe.vue $REPROOT/wdbe/vueappwdbe/
cp main.js $REPROOT/wdbe/vueappwdbe/

cp assets/* $REPROOT/wdbe/vueappwdbe/assets/
cp ../public/favicon.ico $REPROOT/wdbe/vueappwdbe/assets/
touch $REPROOT/wdbe/vueappwdbe/assets/"IP folder --- KEEP"

cp -r components/* $REPROOT/wdbe/vueappwdbe/

cp -r scripts $REPROOT/wdbe/vueappwdbe/
