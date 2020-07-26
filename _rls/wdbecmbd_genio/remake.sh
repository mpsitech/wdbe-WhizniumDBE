#!/bin/bash
# file remake.sh
# re-make script for Wdbe combined daemon, release wdbecmbd_genio
# author Alexander Wirthmueller
# date created: 11 Jul 2020
# modified: 11 Jul 2020

export set SRCROOT=/home/mpsitech/src
export set REPROOT=/home/mpsitech/srcrep

cd $REPROOT/wdbe/_rls/wdbecmbd_genio
./checkout.sh

cd $SRCROOT/wdbecmbd

./make.sh "$@"

