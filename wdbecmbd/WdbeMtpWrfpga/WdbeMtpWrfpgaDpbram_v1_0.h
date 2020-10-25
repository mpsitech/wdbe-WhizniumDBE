/**
	* \file WdbeMtpWrfpgaDpbram_v1_0.h
	* Wdbe operation processor -  (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEMTPWRFPGADPBRAM_V1_0_H
#define WDBEMTPWRFPGADPBRAM_V1_0_H

#include "WdbeMtpWrfpga.h"

// IP include.cust --- INSERT

namespace WdbeMtpWrfpgaDpbram_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpWrfpga* dpchinv);
	// IP cust --- IBEGIN

	void writeMdlVhd(DbsWdbe* dbswdbe, std::fstream& outfile, WdbeMModule* mdl);
	// IP cust --- IEND
};

#endif


