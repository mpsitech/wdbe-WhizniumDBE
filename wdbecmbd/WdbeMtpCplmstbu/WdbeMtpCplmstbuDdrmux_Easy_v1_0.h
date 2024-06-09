/**
	* \file WdbeMtpCplmstbuDdrmux_Easy_v1_0.h
	* Wdbe operation processor - adapt port widths, connect PHY (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Oct 2023
  */
// IP header --- ABOVE

#ifndef WDBEMTPCPLMSTBUDDRMUX_EASY_V1_0_H
#define WDBEMTPCPLMSTBUDDRMUX_EASY_V1_0_H

#include "WdbeMtpCplmstbu.h"

// IP include.cust --- INSERT

namespace WdbeMtpCplmstbuDdrmux_Easy_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpCplmstbu* dpchinv);
	// IP cust --- IBEGIN

	std::string getChsref(const bool wrNotRd, const unsigned int i, const bool capNotUncap);
	// IP cust --- IEND
};

#endif
