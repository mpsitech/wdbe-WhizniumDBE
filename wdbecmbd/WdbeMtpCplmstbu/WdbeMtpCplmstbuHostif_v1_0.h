/**
	* \file WdbeMtpCplmstbuHostif_v1_0.h
	* Wdbe operation processor - connect PHY, CRC and timeout (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 3 Apr 2023
  */
// IP header --- ABOVE

#ifndef WDBEMTPCPLMSTBUHOSTIF_V1_0_H
#define WDBEMTPCPLMSTBUHOSTIF_V1_0_H

#include "WdbeMtpCplmstbu.h"

// IP include.cust --- INSERT

namespace WdbeMtpCplmstbuHostif_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpCplmstbu* dpchinv);
	// IP cust --- INSERT
};

#endif
