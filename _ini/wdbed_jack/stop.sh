#!/bin/bash
# file stop.sh
# stop script for Wdbe daemon, release wdbed_jack
# author Alexander Wirthmueller
# date created: 23 Aug 2020
# modified: 23 Aug 2020

pid=$(pgrep Wdbed)
kill -15 $pid

