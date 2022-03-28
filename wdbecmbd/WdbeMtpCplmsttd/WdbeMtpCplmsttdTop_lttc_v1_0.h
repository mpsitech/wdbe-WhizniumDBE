/**
	* \file WdbeMtpCplmsttdTop_lttc_v1_0.h
	* Wdbe operation processor - infer clock primitives and adapt ports (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 21 Dec 2021
  */
// IP header --- ABOVE

#ifndef WDBEMTPCPLMSTTDTOP_LTTC_V1_0_H
#define WDBEMTPCPLMSTTDTOP_LTTC_V1_0_H

#include "WdbeMtpCplmsttd.h"

// IP include.cust --- INSERT

namespace WdbeMtpCplmsttdTop_lttc_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpCplmsttd* dpchinv);
	// IP cust --- INSERT
};

#endif
