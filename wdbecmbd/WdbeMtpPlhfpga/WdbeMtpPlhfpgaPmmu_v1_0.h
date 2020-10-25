/**
	* \file WdbeMtpPlhfpgaPmmu_v1_0.h
	* Wdbe operation processor -  (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEMTPPLHFPGAPMMU_V1_0_H
#define WDBEMTPPLHFPGAPMMU_V1_0_H

#include "WdbeMtpPlhfpga.h"

// IP include.cust --- INSERT

namespace WdbeMtpPlhfpgaPmmu_v1_0 {

	DpchRetWdbeMtpPlhfpga* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpPlhfpga* dpchinv);
	// IP cust --- INSERT
};

#endif

