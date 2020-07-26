#!/bin/bash
# file stop.sh
# stop script for Wdbe daemon, release wdbed_awsubt
# author Alexander Wirthmueller
# date created: 11 Jul 2020
# modified: 11 Jul 2020

pid=$(pgrep Wdbed)
kill -15 $pid

