#!/bin/bash
# file start.sh
# start script for Wdbe daemon, release wdbed_genio
# author Alexander Wirthmueller
# date created: 11 Jul 2020
# modified: 11 Jul 2020

nohup ./Wdbed -nocp &
disown

