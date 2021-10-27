/**
	* \file WdbeMtpGenfstUsbhostif_Easy_v1_0_Mcu.h
	* Wdbe operation processor - add process (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Oct 2021
  */
// IP header --- ABOVE

#ifndef WDBEMTPGENFSTUSBHOSTIF_EASY_V1_0_MCU_H
#define WDBEMTPGENFSTUSBHOSTIF_EASY_V1_0_MCU_H

#include "WdbeMtpGenfst.h"

// IP include.cust --- INSERT

namespace WdbeMtpGenfstUsbhostif_Easy_v1_0_Mcu {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpGenfst* dpchinv);
	// IP cust --- INSERT
};

#endif
