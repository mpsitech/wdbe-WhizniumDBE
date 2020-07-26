#!/bin/bash
# file checkin.sh
# checkin script for Wdbe web-based UI, release webappwdbe_ungenio
# author Alexander Wirthmueller
# date created: 11 Jul 2020
# modified: 11 Jul 2020

export set REPROOT=/Users/mpsitech/srcrep

cp -r * $REPROOT/wdbe/webappwdbe/

rm $REPROOT/wdbe/webappwdbe/checkin.sh

