/**
	* \file SqkWdbeMtpModbsctd.cpp
	* squawk generation for operation pack WdbeMtpModbsctd (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "SqkWdbeMtpModbsctd.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace SqkWdbeMtpModbsctd
 ******************************************************************************/

string SqkWdbeMtpModbsctd::getSquawk(
			DbsWdbe* dbswdbe
			, DpchInvWdbeMtpModbsctd* dpchinv
		) {
	// example: "modify module template-specific basic device description top-down for module 'icm2-cmdinv (cmdinv_v1_0 command invocation buffer)' / adapt buffer size"
	// IP getSquawk --- RBEGIN
	string stub;

	stub = dbswdbe->getKlstTitleBySref(VecWdbeVKeylist::KLSTKWDBEMTPMODBSCTDCUSTOP, dpchinv->srefKCustop);
	if (stub != "") stub = " / " + stub;

	stub = "modify module template-specific basic device description top-down for module '" + StubWdbe::getStubMdlStd(dbswdbe, dpchinv->refWdbeMModule) + "'" + stub;
	
	return stub;
	// IP getSquawk --- REND
};
