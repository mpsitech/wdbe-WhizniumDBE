/**
	* \file WdbeMtpModbscbuDpbram_v1_0.h
	* Wdbe operation processor - adapt internal wiring (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEMTPMODBSCBUDPBRAM_V1_0_H
#define WDBEMTPMODBSCBUDPBRAM_V1_0_H

#include "WdbeMtpModbscbu.h"

// IP include.cust --- INSERT

namespace WdbeMtpModbscbuDpbram_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpModbscbu* dpchinv);
	// IP cust --- INSERT
};

#endif
