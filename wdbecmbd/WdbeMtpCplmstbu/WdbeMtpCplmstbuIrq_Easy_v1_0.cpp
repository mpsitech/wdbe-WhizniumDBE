/**
	* \file WdbeMtpCplmstbuIrq_Easy_v1_0.cpp
	* Wdbe operation processor - add capture port (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 3 Apr 2023
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpCplmstbuIrq_Easy_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuIrq_Easy_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuIrq_Easy_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	string capt; // ex. xyz.32

	vector<string> ss;

	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "capt", capt)) {
		StrMod::stringToVector(capt, ss, '.');

		if (ss.size() == 2) dbswdbe->tblwdbemport->insertNewRec(NULL, 0, refWdbeMModule, 4, VecWdbeVMPortMdlCat::RTESUP, ss[0], VecWdbeVMPortDir::IN, (ss[1] == "1") ? "sl" : "slvdn", atoi(ss[1].c_str()), "", "", "", "", ss[0], "");
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
