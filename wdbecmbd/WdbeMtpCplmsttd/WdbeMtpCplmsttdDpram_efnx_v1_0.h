/**
	* \file WdbeMtpCplmsttdDpram_efnx_v1_0.h
	* Wdbe operation processor - infer EFX_DPRAM10 primitives and add mux logic (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Apr 2023
  */
// IP header --- ABOVE

#ifndef WDBEMTPCPLMSTTDDPRAM_EFNX_V1_0_H
#define WDBEMTPCPLMSTTDDPRAM_EFNX_V1_0_H

#include "WdbeMtpCplmsttd.h"

// IP include.cust --- INSERT

namespace WdbeMtpCplmsttdDpram_efnx_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpCplmsttd* dpchinv);
	// IP cust --- IBEGIN

	std::string getComb(const unsigned int NRam, const unsigned int w, const unsigned int ik, const std::string& AB, const std::string& Postfix, const std::string& Sig);
	// IP cust --- IEND
};

#endif
