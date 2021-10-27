/**
	* \file WdbeMtpCplmstbuDft_xlnx_v4_0.cpp
	* Wdbe operation processor - adapt port widths (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpCplmstbuDft_xlnx_v4_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuDft_xlnx_v4_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuDft_xlnx_v4_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	string wD;

	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wD", wD)) {
		dbswdbe->executeQuery("UPDATE TblWdbeMPort SET Width = " + wD + " WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'XN_RE'");
		dbswdbe->executeQuery("UPDATE TblWdbeMPort SET Width = " + wD + " WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'XN_IM'");
		dbswdbe->executeQuery("UPDATE TblWdbeMPort SET Width = " + wD + " WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'XK_RE'");
		dbswdbe->executeQuery("UPDATE TblWdbeMPort SET Width = " + wD + " WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'XK_IM'");
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
