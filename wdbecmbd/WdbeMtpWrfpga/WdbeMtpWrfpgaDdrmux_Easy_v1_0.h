/**
	* \file WdbeMtpWrfpgaDdrmux_Easy_v1_0.h
	* Wdbe operation processor -  (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Oct 2023
  */
// IP header --- ABOVE

#ifndef WDBEMTPWRFPGADDRMUX_EASY_V1_0_H
#define WDBEMTPWRFPGADDRMUX_EASY_V1_0_H

#include "WdbeMtpWrfpga.h"

// IP include.cust --- INSERT

namespace WdbeMtpWrfpgaDdrmux_Easy_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpWrfpga* dpchinv);
	// IP cust --- IBEGIN

	void writeMdlVhd(DbsWdbe* dbswdbe, std::fstream& outfile, WdbeMModule* mdl);

	std::string getChsref(const bool wrNotRd, const unsigned int i, const bool capNotUncap);
	// IP cust --- IEND
};

#endif
