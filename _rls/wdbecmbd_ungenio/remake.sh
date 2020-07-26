#!/bin/bash
# file remake.sh
# re-make script for Wdbe combined daemon, release wdbecmbd_ungenio
# author Alexander Wirthmueller
# date created: 11 Jul 2020
# modified: 11 Jul 2020

export set SRCROOT=/Users/mpsitech/src
export set REPROOT=/Users/mpsitech/srcrep

cd $REPROOT/wdbe/_rls/wdbecmbd_ungenio
./checkout.sh

cd $SRCROOT/wdbecmbd

./make.sh "$@"

