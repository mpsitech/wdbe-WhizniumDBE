#!/bin/bash
# file remake.sh
# re-make script for Wdbe daemon, release wdbed_awsubt
# author Alexander Wirthmueller
# date created: 23 Aug 2020
# modified: 23 Aug 2020

export set SRCROOT=/home/ubuntu/src
export set REPROOT=/home/ubuntu/srcrep

cd $REPROOT/wdbe/_rls/wdbed_awsubt
./checkout.sh

cd $SRCROOT/wdbed

./make.sh "$@"

