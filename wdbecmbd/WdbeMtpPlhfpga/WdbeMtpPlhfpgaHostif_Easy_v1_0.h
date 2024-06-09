/**
	* \file WdbeMtpPlhfpgaHostif_Easy_v1_0.h
	* Wdbe operation processor -  (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 3 Apr 2023
  */
// IP header --- ABOVE

#ifndef WDBEMTPPLHFPGAHOSTIF_EASY_V1_0_H
#define WDBEMTPPLHFPGAHOSTIF_EASY_V1_0_H

#include "WdbeMtpPlhfpga.h"

// IP include.cust --- INSERT

namespace WdbeMtpPlhfpgaHostif_Easy_v1_0 {

	DpchRetWdbeMtpPlhfpga* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpPlhfpga* dpchinv);
	// IP cust --- IBEGIN
	unsigned int extendToWD(const unsigned int size, const unsigned int wD, unsigned int& resid);
	// IP cust --- IEND
};

#endif
