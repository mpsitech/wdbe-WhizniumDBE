/**
	* \file WdbeMtpWrfpga.h
	* Wdbe operation pack global code (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEMTPWRFPGA_H
#define WDBEMTPWRFPGA_H

#include "WdbeMtpWrfpga_blks.h"

// IP include.cust --- INSERT

namespace WdbeMtpWrfpga {

	// IP cust --- IBEGIN
	std::string valToSlv(const std::string& val, unsigned short w, const bool upNotDn = false, const bool othNotFull = false);
	// IP cust --- IEND
};

#endif
