/**
	* \file WdbeMtpCplmsttdCohostif_Easy_v1_0.h
	* Wdbe operation processor - infer PHY (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 3 Apr 2023
  */
// IP header --- ABOVE

#ifndef WDBEMTPCPLMSTTDCOHOSTIF_EASY_V1_0_H
#define WDBEMTPCPLMSTTDCOHOSTIF_EASY_V1_0_H

#include "WdbeMtpCplmsttd.h"

// IP include.cust --- INSERT

namespace WdbeMtpCplmsttdCohostif_Easy_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpCplmsttd* dpchinv);
	// IP cust --- INSERT
};

#endif
