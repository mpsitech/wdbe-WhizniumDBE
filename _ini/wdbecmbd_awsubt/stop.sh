#!/bin/bash
# file stop.sh
# stop script for Wdbe combined daemon, release wdbecmbd_awsubt
# author Alexander Wirthmueller
# date created: 23 Aug 2020
# modified: 23 Aug 2020

pid=$(pgrep Wdbecmbd)
kill -15 $pid

