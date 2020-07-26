/**
	* \file WdbeMtpModbsctdDpbram_v1_0.h
	* Wdbe operation processor - infer BRAM primitives and adapt port widths (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEMTPMODBSCTDDPBRAM_V1_0_H
#define WDBEMTPMODBSCTDDPBRAM_V1_0_H

#include "WdbeMtpModbsctd.h"

// IP include.cust --- INSERT

namespace WdbeMtpModbsctdDpbram_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpModbsctd* dpchinv);
	// IP cust --- INSERT
};

#endif

