#!/bin/bash
# file checkout.sh
# checkout script for Wdbe API library, release apiwdbe_jack
# author Alexander Wirthmueller
# date created: 11 Jul 2020
# modified: 11 Jul 2020

export set SRCROOT=/home/mpsitech/src

mkdir $SRCROOT/apiwdbe

cp makeall.sh $SRCROOT/apiwdbe/

cp Makefile $SRCROOT/apiwdbe/

cp ../../apiwdbe/*.h $SRCROOT/apiwdbe/
cp ../../apiwdbe/*.cpp $SRCROOT/apiwdbe/

