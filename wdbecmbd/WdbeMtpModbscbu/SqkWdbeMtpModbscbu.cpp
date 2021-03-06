/**
	* \file SqkWdbeMtpModbscbu.cpp
	* squawk generation for operation pack WdbeMtpModbscbu (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "SqkWdbeMtpModbscbu.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace SqkWdbeMtpModbscbu
 ******************************************************************************/

string SqkWdbeMtpModbscbu::getSquawk(
			DbsWdbe* dbswdbe
			, DpchInvWdbeMtpModbscbu* dpchinv
		) {
	// example: "modify module template-specific basic device description bottom-up for module 'icm2-cmdinv (cmdinv_v1_0 command invocation buffer)' / connect buffer"
	// IP getSquawk --- RBEGIN
	string stub;

	stub = dbswdbe->getKlstTitleBySref(VecWdbeVKeylist::KLSTKWDBEMTPMODBSCBUCUSTOP, dpchinv->srefKCustop);
	if (stub != "") stub = " / " + stub;

	stub = "modify module template-specific basic device description bottom-up for module '" + StubWdbe::getStubMdlStd(dbswdbe, dpchinv->refWdbeMModule) + "'" + stub;
	
	return stub;
	// IP getSquawk --- REND
};
