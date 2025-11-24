#!/bin/bash
# file checkout.sh
# checkout script for Wdbe Vue.js UI, release vueappwdbe_any
# copyright: (C) 2022 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 23 Nov 2025
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set WEBROOT=${WHIZROOT}/web

mkdir $WEBROOT/vueappwdbe/src

cp checkin.sh $WEBROOT/vueappwdbe/src

cp ../../vueappwdbe/AppWdbe.vue $WEBROOT/vueappwdbe/src/
cp ../../vueappwdbe/main.js $WEBROOT/vueappwdbe/src/

mkdir $WEBROOT/vueappwdbe/src/assets

cp ../../vueappwdbe/assets/* $WEBROOT/vueappwdbe/src/assets/
cp ../../vueappwdbe/assets/favicon.ico $WEBROOT/vueappwdbe/public/

mkdir $WEBROOT/vueappwdbe/src/components

cp ../../vueappwdbe/SessWdbe.vue $WEBROOT/vueappwdbe/src/components/

mkdir $WEBROOT/vueappwdbe/src/components/CrdWdbeStart

cp ../../vueappwdbe/CrdWdbeStart/CrdWdbeStart.vue $WEBROOT/vueappwdbe/src/components/CrdWdbeStart/

mkdir $WEBROOT/vueappwdbe/src/components/CrdWdbeNav

cp ../../vueappwdbe/CrdWdbeNav/*.vue $WEBROOT/vueappwdbe/src/components/CrdWdbeNav/

mkdir $WEBROOT/vueappwdbe/src/components/CrdWdbeUsg

cp ../../vueappwdbe/CrdWdbeUsg/*.vue $WEBROOT/vueappwdbe/src/components/CrdWdbeUsg/

mkdir $WEBROOT/vueappwdbe/src/components/CrdWdbeUsr

cp ../../vueappwdbe/CrdWdbeUsr/*.vue $WEBROOT/vueappwdbe/src/components/CrdWdbeUsr/

mkdir $WEBROOT/vueappwdbe/src/components/CrdWdbePrs

cp ../../vueappwdbe/CrdWdbePrs/*.vue $WEBROOT/vueappwdbe/src/components/CrdWdbePrs/

mkdir $WEBROOT/vueappwdbe/src/components/CrdWdbeFil

cp ../../vueappwdbe/CrdWdbeFil/*.vue $WEBROOT/vueappwdbe/src/components/CrdWdbeFil/

mkdir $WEBROOT/vueappwdbe/src/components/CrdWdbePrf

cp ../../vueappwdbe/CrdWdbePrf/*.vue $WEBROOT/vueappwdbe/src/components/CrdWdbePrf/

mkdir $WEBROOT/vueappwdbe/src/components/CrdWdbeMch

cp ../../vueappwdbe/CrdWdbeMch/*.vue $WEBROOT/vueappwdbe/src/components/CrdWdbeMch/

mkdir $WEBROOT/vueappwdbe/src/components/CrdWdbeLib

cp ../../vueappwdbe/CrdWdbeLib/*.vue $WEBROOT/vueappwdbe/src/components/CrdWdbeLib/

mkdir $WEBROOT/vueappwdbe/src/components/CrdWdbeFam

cp ../../vueappwdbe/CrdWdbeFam/*.vue $WEBROOT/vueappwdbe/src/components/CrdWdbeFam/

mkdir $WEBROOT/vueappwdbe/src/components/CrdWdbeSil

cp ../../vueappwdbe/CrdWdbeSil/*.vue $WEBROOT/vueappwdbe/src/components/CrdWdbeSil/

mkdir $WEBROOT/vueappwdbe/src/components/CrdWdbeMtp

cp ../../vueappwdbe/CrdWdbeMtp/*.vue $WEBROOT/vueappwdbe/src/components/CrdWdbeMtp/

mkdir $WEBROOT/vueappwdbe/src/components/CrdWdbePrj

cp ../../vueappwdbe/CrdWdbePrj/*.vue $WEBROOT/vueappwdbe/src/components/CrdWdbePrj/

mkdir $WEBROOT/vueappwdbe/src/components/CrdWdbeVer

cp ../../vueappwdbe/CrdWdbeVer/*.vue $WEBROOT/vueappwdbe/src/components/CrdWdbeVer/

mkdir $WEBROOT/vueappwdbe/src/components/CrdWdbeUnt

cp ../../vueappwdbe/CrdWdbeUnt/*.vue $WEBROOT/vueappwdbe/src/components/CrdWdbeUnt/

mkdir $WEBROOT/vueappwdbe/src/components/CrdWdbeCpr

cp ../../vueappwdbe/CrdWdbeCpr/*.vue $WEBROOT/vueappwdbe/src/components/CrdWdbeCpr/

mkdir $WEBROOT/vueappwdbe/src/components/CrdWdbeCvr

cp ../../vueappwdbe/CrdWdbeCvr/*.vue $WEBROOT/vueappwdbe/src/components/CrdWdbeCvr/

mkdir $WEBROOT/vueappwdbe/src/components/CrdWdbePph

cp ../../vueappwdbe/CrdWdbePph/*.vue $WEBROOT/vueappwdbe/src/components/CrdWdbePph/

mkdir $WEBROOT/vueappwdbe/src/components/CrdWdbeMod

cp ../../vueappwdbe/CrdWdbeMod/*.vue $WEBROOT/vueappwdbe/src/components/CrdWdbeMod/

mkdir $WEBROOT/vueappwdbe/src/components/CrdWdbeVec

cp ../../vueappwdbe/CrdWdbeVec/*.vue $WEBROOT/vueappwdbe/src/components/CrdWdbeVec/

mkdir $WEBROOT/vueappwdbe/src/components/CrdWdbeVit

cp ../../vueappwdbe/CrdWdbeVit/*.vue $WEBROOT/vueappwdbe/src/components/CrdWdbeVit/

mkdir $WEBROOT/vueappwdbe/src/components/CrdWdbeCmd

cp ../../vueappwdbe/CrdWdbeCmd/*.vue $WEBROOT/vueappwdbe/src/components/CrdWdbeCmd/

mkdir $WEBROOT/vueappwdbe/src/components/CrdWdbeErr

cp ../../vueappwdbe/CrdWdbeErr/*.vue $WEBROOT/vueappwdbe/src/components/CrdWdbeErr/

mkdir $WEBROOT/vueappwdbe/src/components/CrdWdbePpl

cp ../../vueappwdbe/CrdWdbePpl/*.vue $WEBROOT/vueappwdbe/src/components/CrdWdbePpl/

mkdir $WEBROOT/vueappwdbe/src/components/CrdWdbeSeg

cp ../../vueappwdbe/CrdWdbeSeg/*.vue $WEBROOT/vueappwdbe/src/components/CrdWdbeSeg/

mkdir $WEBROOT/vueappwdbe/src/components/CrdWdbeBnk

cp ../../vueappwdbe/CrdWdbeBnk/*.vue $WEBROOT/vueappwdbe/src/components/CrdWdbeBnk/

mkdir $WEBROOT/vueappwdbe/src/components/CrdWdbePin

cp ../../vueappwdbe/CrdWdbePin/*.vue $WEBROOT/vueappwdbe/src/components/CrdWdbePin/

mkdir $WEBROOT/vueappwdbe/src/components/CrdWdbeInt

cp ../../vueappwdbe/CrdWdbeInt/*.vue $WEBROOT/vueappwdbe/src/components/CrdWdbeInt/

mkdir $WEBROOT/vueappwdbe/src/components/CrdWdbeSns

cp ../../vueappwdbe/CrdWdbeSns/*.vue $WEBROOT/vueappwdbe/src/components/CrdWdbeSns/

mkdir $WEBROOT/vueappwdbe/src/components/CrdWdbeVar

cp ../../vueappwdbe/CrdWdbeVar/*.vue $WEBROOT/vueappwdbe/src/components/CrdWdbeVar/

mkdir $WEBROOT/vueappwdbe/src/components/CrdWdbeGen

cp ../../vueappwdbe/CrdWdbeGen/*.vue $WEBROOT/vueappwdbe/src/components/CrdWdbeGen/

mkdir $WEBROOT/vueappwdbe/src/components/CrdWdbePrt

cp ../../vueappwdbe/CrdWdbePrt/*.vue $WEBROOT/vueappwdbe/src/components/CrdWdbePrt/

mkdir $WEBROOT/vueappwdbe/src/components/CrdWdbeSig

cp ../../vueappwdbe/CrdWdbeSig/*.vue $WEBROOT/vueappwdbe/src/components/CrdWdbeSig/

mkdir $WEBROOT/vueappwdbe/src/components/CrdWdbeCdc

cp ../../vueappwdbe/CrdWdbeCdc/*.vue $WEBROOT/vueappwdbe/src/components/CrdWdbeCdc/

mkdir $WEBROOT/vueappwdbe/src/components/CrdWdbePrc

cp ../../vueappwdbe/CrdWdbePrc/*.vue $WEBROOT/vueappwdbe/src/components/CrdWdbePrc/

mkdir $WEBROOT/vueappwdbe/src/components/CrdWdbeFst

cp ../../vueappwdbe/CrdWdbeFst/*.vue $WEBROOT/vueappwdbe/src/components/CrdWdbeFst/

mkdir $WEBROOT/vueappwdbe/src/components/CrdWdbeCmp

cp ../../vueappwdbe/CrdWdbeCmp/*.vue $WEBROOT/vueappwdbe/src/components/CrdWdbeCmp/

mkdir $WEBROOT/vueappwdbe/src/components/CrdWdbeRls

cp ../../vueappwdbe/CrdWdbeRls/*.vue $WEBROOT/vueappwdbe/src/components/CrdWdbeRls/

mkdir $WEBROOT/vueappwdbe/src/components/CrdWdbeIdf

cp ../../vueappwdbe/CrdWdbeIdf/*.vue $WEBROOT/vueappwdbe/src/components/CrdWdbeIdf/

mkdir $WEBROOT/vueappwdbe/src/components/CrdWdbeUtl

cp ../../vueappwdbe/CrdWdbeUtl/*.vue $WEBROOT/vueappwdbe/src/components/CrdWdbeUtl/

mkdir $WEBROOT/vueappwdbe/src/scripts

cp ../../vueappwdbe/scripts/*.js $WEBROOT/vueappwdbe/src/scripts/
