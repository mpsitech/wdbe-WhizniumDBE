/**
	* \file WdbeMtpWrfpgaCrcspec_v3_0.h
	* Wdbe operation processor -  (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 3 Apr 2023
  */
// IP header --- ABOVE

#ifndef WDBEMTPWRFPGACRCSPEC_V3_0_H
#define WDBEMTPWRFPGACRCSPEC_V3_0_H

#include "WdbeMtpWrfpga.h"

// IP include.cust --- INSERT

namespace WdbeMtpWrfpgaCrcspec_v3_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpWrfpga* dpchinv);
	// IP cust --- IBEGIN

	void writeMdlVhd(DbsWdbe* dbswdbe, std::fstream& outfile, WdbeMModule* mdl);

	unsigned int getLittleEndian(const unsigned int wDinc, const unsigned int ix);
	// IP cust --- IEND
};

#endif
