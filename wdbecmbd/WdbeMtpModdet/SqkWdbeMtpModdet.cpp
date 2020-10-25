/**
	* \file SqkWdbeMtpModdet.cpp
	* squawk generation for operation pack WdbeMtpModdet (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "SqkWdbeMtpModdet.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace SqkWdbeMtpModdet
 ******************************************************************************/

string SqkWdbeMtpModdet::getSquawk(
			DbsWdbe* dbswdbe
			, DpchInvWdbeMtpModdet* dpchinv
		) {
	// example: "modify module template-specific detailed device description for module 'icm2-tkclksrc (tkclksrc_v1_0 controller)' / add command process handshake"
	// IP getSquawk --- RBEGIN
	string stub;

	stub = dbswdbe->getKlstTitleBySref(VecWdbeVKeylist::KLSTKWDBEMTPMODDETCUSTOP, dpchinv->srefKCustop);
	if (stub != "") stub = " / " + stub;

	stub = "modify module template-specific detailed device description for module '" + StubWdbe::getStubMdlStd(dbswdbe, dpchinv->refWdbeMModule) + "'" + stub;
	
	return stub;
	// IP getSquawk --- REND
};


