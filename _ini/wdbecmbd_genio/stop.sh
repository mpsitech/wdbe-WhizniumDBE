#!/bin/bash
# file stop.sh
# stop script for Wdbe combined daemon, release wdbecmbd_genio
# author Alexander Wirthmueller
# date created: 11 Jul 2020
# modified: 11 Jul 2020

pid=$(pgrep Wdbecmbd)
kill -15 $pid

