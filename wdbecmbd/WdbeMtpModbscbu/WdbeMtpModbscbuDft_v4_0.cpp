/**
	* \file WdbeMtpModbscbuDft_v4_0.cpp
	* Wdbe operation processor - adapt port widths (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpModbscbuDft_v4_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpModbscbu;

/******************************************************************************
 namespace WdbeMtpModbscbuDft_v4_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpModbscbuDft_v4_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpModbscbu* dpchinv
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


