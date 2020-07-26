/**
	* \file WdbeMtpWrfpga.h
	* Wdbe operation pack global code (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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


