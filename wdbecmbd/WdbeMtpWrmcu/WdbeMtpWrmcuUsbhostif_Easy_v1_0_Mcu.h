/**
	* \file WdbeMtpWrmcuUsbhostif_Easy_v1_0_Mcu.h
	* Wdbe operation processor -  (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 4 Oct 2021
  */
// IP header --- ABOVE

#ifndef WDBEMTPWRMCUUSBHOSTIF_EASY_V1_0_MCU_H
#define WDBEMTPWRMCUUSBHOSTIF_EASY_V1_0_MCU_H

#include "WdbeMtpWrmcu.h"

// IP include.cust --- INSERT

namespace WdbeMtpWrmcuUsbhostif_Easy_v1_0_Mcu {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeMtpWrmcu* dpchinv);
	// IP cust --- IBEGIN

	void writeMdlC(DbsWdbe* dbswdbe, std::fstream& outfile, const std::string& Prjshort, const std::string& Untsref, WdbeMModule* mdl);
	// IP cust --- IEND
};

#endif
