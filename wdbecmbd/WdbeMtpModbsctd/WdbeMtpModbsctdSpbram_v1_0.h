/**
	* \file WdbeMtpModbsctdSpbram_v1_0.h
	* Wdbe operation processor - infer BRAM primitives and adapt port widths (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEMTPMODBSCTDSPBRAM_V1_0_H
#define WDBEMTPMODBSCTDSPBRAM_V1_0_H

#include "WdbeMtpModbsctd.h"

// IP include.cust --- INSERT

namespace WdbeMtpModbsctdSpbram_v1_0 {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpModbsctd* dpchinv);
	// IP cust --- INSERT
};

#endif
