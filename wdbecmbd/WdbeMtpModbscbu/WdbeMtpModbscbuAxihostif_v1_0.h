/**
	* \file WdbeMtpModbscbuAxihostif_v1_0.h
	* Wdbe operation processor - connect AXI controllers, CRC and timeout (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEMTPMODBSCBUAXIHOSTIF_V1_0_H
#define WDBEMTPMODBSCBUAXIHOSTIF_V1_0_H

#include "WdbeMtpModbscbu.h"

// IP include.cust --- INSERT

namespace WdbeMtpModbscbuAxihostif_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpModbscbu* dpchinv);
	// IP cust --- INSERT
};

#endif

