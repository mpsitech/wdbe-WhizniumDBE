/**
	* \file WdbeMtpGenfstDdrmux_Easy_v1_0.h
	* Wdbe operation processor - add A/B buffers, processes and clock domain crossing (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Oct 2023
  */
// IP header --- ABOVE

#ifndef WDBEMTPGENFSTDDRMUX_EASY_V1_0_H
#define WDBEMTPGENFSTDDRMUX_EASY_V1_0_H

#include "WdbeMtpGenfst.h"

// IP include.cust --- INSERT

namespace WdbeMtpGenfstDdrmux_Easy_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpGenfst* dpchinv);
	// IP cust --- IBEGIN

	std::string getChsref(const bool wrNotRd, const unsigned int i, const bool capNotUncap);
	// IP cust --- IEND
};

#endif
