#!/bin/bash
# file start.sh
# start script for Wdbe combined daemon, release wdbecmbd_ubuntu
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 13 Jan 2021
# IP header --- ABOVE

nohup ./Wdbecmbd -nocp &
disown
