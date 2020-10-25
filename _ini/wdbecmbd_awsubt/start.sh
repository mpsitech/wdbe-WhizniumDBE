#!/bin/bash
# file start.sh
# start script for Wdbe combined daemon, release wdbecmbd_awsubt
# author Alexander Wirthmueller
# date created: 23 Aug 2020
# modified: 23 Aug 2020

nohup ./Wdbecmbd -nocp &
disown

