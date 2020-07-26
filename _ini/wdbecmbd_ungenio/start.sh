#!/bin/bash
# file start.sh
# start script for Wdbe combined daemon, release wdbecmbd_ungenio
# author Alexander Wirthmueller
# date created: 11 Jul 2020
# modified: 11 Jul 2020

nohup ./Wdbecmbd -nocp &
disown

