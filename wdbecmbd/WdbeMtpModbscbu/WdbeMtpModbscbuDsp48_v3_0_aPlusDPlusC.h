/**
	* \file WdbeMtpModbscbuDsp48_v3_0_aPlusDPlusC.h
	* Wdbe operation processor - adapt port widths (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEMTPMODBSCBUDSP48_V3_0_APLUSDPLUSC_H
#define WDBEMTPMODBSCBUDSP48_V3_0_APLUSDPLUSC_H

#include "WdbeMtpModbscbu.h"

// IP include.cust --- INSERT

namespace WdbeMtpModbscbuDsp48_v3_0_aPlusDPlusC {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpModbscbu* dpchinv);
	// IP cust --- INSERT
};

#endif

