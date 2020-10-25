#!/bin/bash
# file remake.sh
# re-make script for Wdbe operation daemon, release wdbeopd2_jack
# author Alexander Wirthmueller
# date created: 23 Aug 2020
# modified: 23 Aug 2020

export set SRCROOT=/home/mpsitech/src
export set REPROOT=/home/mpsitech/srcrep

cd $REPROOT/wdbe/_rls/wdbeopd2_jack
./checkout.sh

cd $SRCROOT/wdbeopd2

./make.sh "$@"

