#!/bin/bash
# file checkout.sh
# checkout script for Wdbe API library, release apiwdbe_awsubt
# author Alexander Wirthmueller
# date created: 23 Aug 2020
# modified: 23 Aug 2020

export set SRCROOT=/home/ubuntu/src

mkdir $SRCROOT/apiwdbe

cp makeall.sh $SRCROOT/apiwdbe/

cp Makefile $SRCROOT/apiwdbe/

cp ../../apiwdbe/*.h $SRCROOT/apiwdbe/
cp ../../apiwdbe/*.cpp $SRCROOT/apiwdbe/

