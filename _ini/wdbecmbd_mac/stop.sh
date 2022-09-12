#!/bin/bash
# file stop.sh
# stop script for Wdbe combined daemon, release wdbecmbd_mac
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 11 Sep 2022
# IP header --- ABOVE

pid=$(pgrep Wdbecmbd)
kill -15 $pid
