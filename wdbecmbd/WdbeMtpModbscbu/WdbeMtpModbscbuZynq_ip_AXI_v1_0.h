/**
	* \file WdbeMtpModbscbuZynq_ip_AXI_v1_0.h
	* Wdbe operation processor - add pin substitute signals (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEMTPMODBSCBUZYNQ_IP_AXI_V1_0_H
#define WDBEMTPMODBSCBUZYNQ_IP_AXI_V1_0_H

#include "WdbeMtpModbscbu.h"

// IP include.cust --- INSERT

namespace WdbeMtpModbscbuZynq_ip_AXI_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpModbscbu* dpchinv);
	// IP cust --- INSERT
};

#endif

