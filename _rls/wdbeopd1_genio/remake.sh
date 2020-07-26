#!/bin/bash
# file remake.sh
# re-make script for Wdbe operation daemon, release wdbeopd1_genio
# author Alexander Wirthmueller
# date created: 11 Jul 2020
# modified: 11 Jul 2020

export set SRCROOT=/home/mpsitech/src
export set REPROOT=/home/mpsitech/srcrep

cd $REPROOT/wdbe/_rls/wdbeopd1_genio
./checkout.sh

cd $SRCROOT/wdbeopd1

./make.sh "$@"

