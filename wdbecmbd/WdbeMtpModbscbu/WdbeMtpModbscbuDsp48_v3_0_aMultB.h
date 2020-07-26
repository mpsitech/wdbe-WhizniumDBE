/**
	* \file WdbeMtpModbscbuDsp48_v3_0_aMultB.h
	* Wdbe operation processor - adapt port widths (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEMTPMODBSCBUDSP48_V3_0_AMULTB_H
#define WDBEMTPMODBSCBUDSP48_V3_0_AMULTB_H

#include "WdbeMtpModbscbu.h"

// IP include.cust --- INSERT

namespace WdbeMtpModbscbuDsp48_v3_0_aMultB {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpModbscbu* dpchinv);
	// IP cust --- INSERT
};

#endif

