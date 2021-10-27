/**
	* \file WdbeMtpCplmsttdPmmu_v1_0.h
	* Wdbe operation processor - adapt buffer sizes (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEMTPCPLMSTTDPMMU_V1_0_H
#define WDBEMTPCPLMSTTDPMMU_V1_0_H

#include "WdbeMtpCplmsttd.h"

// IP include.cust --- INSERT

namespace WdbeMtpCplmsttdPmmu_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpCplmsttd* dpchinv);
	// IP cust --- INSERT
};

#endif
