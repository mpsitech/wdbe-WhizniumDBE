#!/bin/bash
# file checkout.sh
# checkout script for Wdbe Java API library, release &rlssref;
# author &author;
# date created: 23 Aug 2020
# modified: 23 Aug 2020

export set JAVAROOT=/home/mpsitech/srcjava

mkdir $JAVAROOT/apiwdbe
mkdir $JAVAROOT/apiwdbe/src
mkdir $JAVAROOT/apiwdbe/src/apiwdbe
mkdir $JAVAROOT/apiwdbe/bin
mkdir $JAVAROOT/apiwdbe/bin/apiwdbe

cp ../../japiwdbe/*.java $JAVAROOT/apiwdbe/src/apiwdbe/

