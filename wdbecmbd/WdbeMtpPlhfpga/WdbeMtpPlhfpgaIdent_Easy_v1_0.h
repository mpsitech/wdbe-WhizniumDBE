/**
	* \file WdbeMtpPlhfpgaIdent_Easy_v1_0.h
	* Wdbe operation processor -  (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 31 Dec 2022
  */
// IP header --- ABOVE

#ifndef WDBEMTPPLHFPGAIDENT_EASY_V1_0_H
#define WDBEMTPPLHFPGAIDENT_EASY_V1_0_H

#include "WdbeMtpPlhfpga.h"

// IP include.cust --- INSERT

namespace WdbeMtpPlhfpgaIdent_Easy_v1_0 {

	DpchRetWdbeMtpPlhfpga* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpPlhfpga* dpchinv);
	// IP cust --- IBEGIN

	std::string trimVal(const std::string& val, const size_t len = 8);
	// IP cust --- IEND
};

#endif
