#!/bin/bash
# file start.sh
# start script for Wdbe daemon, release wdbed_jack
# author Alexander Wirthmueller
# date created: 23 Aug 2020
# modified: 23 Aug 2020

nohup ./Wdbed -nocp &
disown

