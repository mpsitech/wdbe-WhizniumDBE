#!/bin/bash
# file checkout.sh
# checkout script for Wdbe web-based UI, release webappwdbe_ungenio
# author Alexander Wirthmueller
# date created: 11 Jul 2020
# modified: 11 Jul 2020

export set WEBROOT=/Users/mpsitech/web

mkdir $WEBROOT/appwdbe

cp checkin.sh $WEBROOT/appwdbe/

cp -r ../../webappwdbe/* $WEBROOT/appwdbe/

