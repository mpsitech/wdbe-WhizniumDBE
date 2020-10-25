#!/bin/bash
# file remake.sh
# re-make script for Wdbe operation daemon, release wdbeopd2_awsubt
# author Alexander Wirthmueller
# date created: 23 Aug 2020
# modified: 23 Aug 2020

export set SRCROOT=/home/ubuntu/src
export set REPROOT=/home/ubuntu/srcrep

cd $REPROOT/wdbe/_rls/wdbeopd2_awsubt
./checkout.sh

cd $SRCROOT/wdbeopd2

./make.sh "$@"

