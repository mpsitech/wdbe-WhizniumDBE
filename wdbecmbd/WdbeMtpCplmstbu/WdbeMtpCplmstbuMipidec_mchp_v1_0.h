/**
	* \file WdbeMtpCplmstbuMipidec_mchp_v1_0.h
	* Wdbe operation processor - adapt port widths (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 21 Dec 2021
  */
// IP header --- ABOVE

#ifndef WDBEMTPCPLMSTBUMIPIDEC_MCHP_V1_0_H
#define WDBEMTPCPLMSTBUMIPIDEC_MCHP_V1_0_H

#include "WdbeMtpCplmstbu.h"

// IP include.cust --- INSERT

namespace WdbeMtpCplmstbuMipidec_mchp_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpCplmstbu* dpchinv);
	// IP cust --- INSERT
};

#endif
