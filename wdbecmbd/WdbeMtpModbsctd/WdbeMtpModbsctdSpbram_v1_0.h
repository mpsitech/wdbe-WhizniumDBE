/**
	* \file WdbeMtpModbsctdSpbram_v1_0.h
	* Wdbe operation processor - infer BRAM primitives and adapt port widths (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEMTPMODBSCTDSPBRAM_V1_0_H
#define WDBEMTPMODBSCTDSPBRAM_V1_0_H

#include "WdbeMtpModbsctd.h"

// IP include.cust --- INSERT

namespace WdbeMtpModbsctdSpbram_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpModbsctd* dpchinv);
	// IP cust --- INSERT
};

#endif

