/**
	* \file WdbeMtpWrfpgaPmmu_v1_0.h
	* Wdbe operation processor -  (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEMTPWRFPGAPMMU_V1_0_H
#define WDBEMTPWRFPGAPMMU_V1_0_H

#include "WdbeMtpWrfpga.h"

// IP include.cust --- INSERT

namespace WdbeMtpWrfpgaPmmu_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpWrfpga* dpchinv);
	// IP cust --- IBEGIN

	void writeMdlVhd(DbsWdbe* dbswdbe, std::fstream& outfile, WdbeMModule* mdl);
	// IP cust --- IEND
};

#endif
