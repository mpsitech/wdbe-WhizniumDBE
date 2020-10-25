/**
	* \file WdbeMtpModbsctdPmmu_v1_0.h
	* Wdbe operation processor - adapt buffer sizes (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEMTPMODBSCTDPMMU_V1_0_H
#define WDBEMTPMODBSCTDPMMU_V1_0_H

#include "WdbeMtpModbsctd.h"

// IP include.cust --- INSERT

namespace WdbeMtpModbsctdPmmu_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpModbsctd* dpchinv);
	// IP cust --- INSERT
};

#endif

