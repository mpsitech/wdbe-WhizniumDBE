/**
	* \file WdbeMtpModbscbuXadc_v3_3.cpp
	* Wdbe operation processor - adapt port names (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpModbscbuXadc_v3_3.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpModbscbu;

/******************************************************************************
 namespace WdbeMtpModbscbuXadc_v3_3
 ******************************************************************************/

DpchRetWdbe* WdbeMtpModbscbuXadc_v3_3::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpModbscbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	string chA, chB;

	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "chA", chA)) {
		dbswdbe->executeQuery("UPDATE TblWdbeMPort SET sref = 'vauxp" + chA + "' WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'vauxpA'");
		dbswdbe->executeQuery("UPDATE TblWdbeMPort SET sref = 'vauxn" + chA + "' WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'vauxnA'");
	};
	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "chB", chB)) {
		dbswdbe->executeQuery("UPDATE TblWdbeMPort SET sref = 'vauxp" + chB + "' WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'vauxpB'");
		dbswdbe->executeQuery("UPDATE TblWdbeMPort SET sref = 'vauxn" + chB + "' WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'vauxnB'");
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT


