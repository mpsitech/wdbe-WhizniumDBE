/**
	* \file WdbeMtpWrfpgaCmdinv_v1_0.h
	* Wdbe operation processor -  (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEMTPWRFPGACMDINV_V1_0_H
#define WDBEMTPWRFPGACMDINV_V1_0_H

#include "WdbeMtpWrfpga.h"

// IP include.cust --- INSERT

namespace WdbeMtpWrfpgaCmdinv_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpWrfpga* dpchinv);
	// IP cust --- IBEGIN

	void writeMdlVhd(DbsWdbe* dbswdbe, std::fstream& outfile, const std::string& Prjshort, const std::string& Untsref, WdbeMModule* mdl);
	// IP cust --- IEND
};

#endif


