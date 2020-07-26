#!/bin/bash
# file remake.sh
# re-make script for Wdbe operation daemon, release wdbeopd1_awsubt
# author Alexander Wirthmueller
# date created: 11 Jul 2020
# modified: 11 Jul 2020

export set SRCROOT=/home/ubuntu/src
export set REPROOT=/home/ubuntu/srcrep

cd $REPROOT/wdbe/_rls/wdbeopd1_awsubt
./checkout.sh

cd $SRCROOT/wdbeopd1

./make.sh "$@"

