#!/bin/bash
# file remake.sh
# re-make script for Wdbe combined daemon, release wdbecmbd_jack
# author Alexander Wirthmueller
# date created: 23 Aug 2020
# modified: 23 Aug 2020

export set SRCROOT=/home/mpsitech/src
export set REPROOT=/home/mpsitech/srcrep

cd $REPROOT/wdbe/_rls/wdbecmbd_jack
./checkout.sh

cd $SRCROOT/wdbecmbd

./make.sh "$@"

