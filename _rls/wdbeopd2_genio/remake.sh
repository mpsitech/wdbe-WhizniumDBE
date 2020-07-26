#!/bin/bash
# file remake.sh
# re-make script for Wdbe operation daemon, release wdbeopd2_genio
# author Alexander Wirthmueller
# date created: 11 Jul 2020
# modified: 11 Jul 2020

export set SRCROOT=/home/mpsitech/src
export set REPROOT=/home/mpsitech/srcrep

cd $REPROOT/wdbe/_rls/wdbeopd2_genio
./checkout.sh

cd $SRCROOT/wdbeopd2

./make.sh "$@"

