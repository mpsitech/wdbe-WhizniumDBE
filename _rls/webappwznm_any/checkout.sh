#!/bin/bash
# file checkout.sh
# checkout script for Wdbe web-based UI, release webappwznm_any
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 5 Dec 2020
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set WEBROOT=${WHIZROOT}/web

mkdir $WEBROOT/appwdbe

cp checkin.sh $WEBROOT/appwdbe/

cp -r ../../webappwdbe/* $WEBROOT/appwdbe/

