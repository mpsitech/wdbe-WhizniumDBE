/**
	* \file WdbeMtpCplmsttdDdrmux_Easy_v1_0.h
	* Wdbe operation processor - infer PHY (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Oct 2023
  */
// IP header --- ABOVE

#ifndef WDBEMTPCPLMSTTDDDRMUX_EASY_V1_0_H
#define WDBEMTPCPLMSTTDDDRMUX_EASY_V1_0_H

#include "WdbeMtpCplmsttd.h"

// IP include.cust --- INSERT

namespace WdbeMtpCplmsttdDdrmux_Easy_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpCplmsttd* dpchinv);
	// IP cust --- IBEGIN

	std::string getChsref(const bool wrNotRd, const unsigned int i, const bool capNotUncap);
	// IP cust --- IEND
};

#endif
