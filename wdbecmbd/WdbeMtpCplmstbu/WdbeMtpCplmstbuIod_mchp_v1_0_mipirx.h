/**
	* \file WdbeMtpCplmstbuIod_mchp_v1_0_mipirx.h
	* Wdbe operation processor - adapt port widths (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 21 Dec 2021
  */
// IP header --- ABOVE

#ifndef WDBEMTPCPLMSTBUIOD_MCHP_V1_0_MIPIRX_H
#define WDBEMTPCPLMSTBUIOD_MCHP_V1_0_MIPIRX_H

#include "WdbeMtpCplmstbu.h"

// IP include.cust --- INSERT

namespace WdbeMtpCplmstbuIod_mchp_v1_0_mipirx {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpCplmstbu* dpchinv);
	// IP cust --- INSERT
};

#endif
