/**
	* \file WdbeMtpModbsctdCmdret_v1_0.h
	* Wdbe operation processor - adapt buffer size (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEMTPMODBSCTDCMDRET_V1_0_H
#define WDBEMTPMODBSCTDCMDRET_V1_0_H

#include "WdbeMtpModbsctd.h"

// IP include.cust --- INSERT

namespace WdbeMtpModbsctdCmdret_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpModbsctd* dpchinv);
	// IP cust --- INSERT
};

#endif

