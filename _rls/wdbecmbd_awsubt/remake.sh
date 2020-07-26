#!/bin/bash
# file remake.sh
# re-make script for Wdbe combined daemon, release wdbecmbd_awsubt
# author Alexander Wirthmueller
# date created: 11 Jul 2020
# modified: 11 Jul 2020

export set SRCROOT=/home/ubuntu/src
export set REPROOT=/home/ubuntu/srcrep

cd $REPROOT/wdbe/_rls/wdbecmbd_awsubt
./checkout.sh

cd $SRCROOT/wdbecmbd

./make.sh "$@"

