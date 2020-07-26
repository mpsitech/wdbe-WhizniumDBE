/**
	* \file WdbeMtpWrfpgaTop_v1_0.h
	* Wdbe operation processor -  (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEMTPWRFPGATOP_V1_0_H
#define WDBEMTPWRFPGATOP_V1_0_H

#include "WdbeMtpWrfpga.h"

// IP include.cust --- INSERT

namespace WdbeMtpWrfpgaTop_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpWrfpga* dpchinv);
	// IP cust --- IBEGIN

	void writeMdlVhd(DbsWdbe* dbswdbe, std::fstream& outfile, WdbeMModule* mdl);
	// IP cust --- IEND
};

#endif


