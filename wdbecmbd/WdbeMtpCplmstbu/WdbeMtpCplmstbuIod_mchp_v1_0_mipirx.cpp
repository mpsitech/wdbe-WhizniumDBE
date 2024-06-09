/**
	* \file WdbeMtpCplmstbuIod_mchp_v1_0_mipirx.cpp
	* Wdbe operation processor - adapt port widths (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 21 Dec 2021
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpCplmstbuIod_mchp_v1_0_mipirx.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuIod_mchp_v1_0_mipirx
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuIod_mchp_v1_0_mipirx::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	string nLane_s;

	int nLane;

	ubigint refC;
	uint mdlNum;

	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "nLane", nLane_s)) {
		nLane = atoi(nLane_s.c_str());

		dbswdbe->loadRefBySQL("SELECT refWdbeCPort FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'l0_rxd_data'", refC);
		mdlNum = Wdbe::getNextPrtMdlNum(dbswdbe, refWdbeMModule);

		for (int i = 2; i < nLane; i++) dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::RTESUP, "l" + to_string(i) + "_rxd_data", VecWdbeVMPortDir::IN, "slvdn", 8, "", "", "", "", "", "");
	
		for (int i = 2; i < nLane; i++) {
			refC = dbswdbe->tblwdbecport->getNewRef();

			dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::RTESUP, "l" + to_string(i) + "_lp_data", VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", "", "");
			dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::RTESUP, "l" + to_string(i) + "_lp_data_n", VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", "", "");
		};

		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "rxd", nLane);
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "rxd_n", nLane);
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
