#!/bin/bash
# file checkin.sh
# checkin script for Wdbe web-based UI, release webappwdbe_awsubt
# author Alexander Wirthmueller
# date created: 11 Jul 2020
# modified: 11 Jul 2020

export set REPROOT=/home/ubuntu/srcrep

cp -r * $REPROOT/wdbe/webappwdbe/

rm $REPROOT/wdbe/webappwdbe/checkin.sh

