#!/bin/bash
# file remake.sh
# re-make script for Wdbe daemon, release wdbed_jack
# author Alexander Wirthmueller
# date created: 11 Jul 2020
# modified: 11 Jul 2020

export set SRCROOT=/home/mpsitech/src
export set REPROOT=/home/mpsitech/srcrep

cd $REPROOT/wdbe/_rls/wdbed_jack
./checkout.sh

cd $SRCROOT/wdbed

./make.sh "$@"

