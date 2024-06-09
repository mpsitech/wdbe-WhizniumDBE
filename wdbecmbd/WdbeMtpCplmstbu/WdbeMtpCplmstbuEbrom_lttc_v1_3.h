/**
	* \file WdbeMtpCplmstbuEbrom_lttc_v1_3.h
	* Wdbe operation processor - adapt port widths (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jan 2023
  */
// IP header --- ABOVE

#ifndef WDBEMTPCPLMSTBUEBROM_LTTC_V1_3_H
#define WDBEMTPCPLMSTBUEBROM_LTTC_V1_3_H

#include "WdbeMtpCplmstbu.h"

// IP include.cust --- INSERT

namespace WdbeMtpCplmstbuEbrom_lttc_v1_3 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpCplmstbu* dpchinv);
	// IP cust --- INSERT
};

#endif
