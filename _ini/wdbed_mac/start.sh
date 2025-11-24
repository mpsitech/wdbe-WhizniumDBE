#!/bin/bash
# file start.sh
# start script for Wdbe daemon, release wdbed_mac
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 23 Nov 2025
# IP header --- ABOVE

nohup ./Wdbed -nocp &
disown
