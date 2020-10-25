#!/bin/bash
# file checkout.sh
# checkout script for Wdbe web-based UI, release webappwdbe_jack
# author Alexander Wirthmueller
# date created: 23 Aug 2020
# modified: 23 Aug 2020

export set WEBROOT=/home/mpsitech/web

mkdir $WEBROOT/appwdbe

cp checkin.sh $WEBROOT/appwdbe/

cp -r ../../webappwdbe/* $WEBROOT/appwdbe/

