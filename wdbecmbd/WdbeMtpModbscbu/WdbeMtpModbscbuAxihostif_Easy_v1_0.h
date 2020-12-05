/**
	* \file WdbeMtpModbscbuAxihostif_Easy_v1_0.h
	* Wdbe operation processor - connect AXI controllers, CRC and timeout (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEMTPMODBSCBUAXIHOSTIF_EASY_V1_0_H
#define WDBEMTPMODBSCBUAXIHOSTIF_EASY_V1_0_H

#include "WdbeMtpModbscbu.h"

// IP include.cust --- INSERT

namespace WdbeMtpModbscbuAxihostif_Easy_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpModbscbu* dpchinv);
	// IP cust --- INSERT
};

#endif



