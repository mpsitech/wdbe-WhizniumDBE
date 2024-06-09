/**
	* \file WdbeMtpCplmstbuMipidec_mchp_v1_0.cpp
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

#include "WdbeMtpCplmstbuMipidec_mchp_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuMipidec_mchp_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuMipidec_mchp_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	string g_LANE_WIDTH_s;
	string g_NUM_OF_PIXELS_s;

	int g_LANE_WIDTH;
	int g_NUM_OF_PIXELS;

	const int wData = 12; // currently fixed for g_DATATYPE = RAW-12

	ubigint refC;
	uint mdlNum;

	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "g_LANE_WIDTH", g_LANE_WIDTH_s) && Wdbe::getMpa(dbswdbe, refWdbeMModule, "g_NUM_OF_PIXELS", g_NUM_OF_PIXELS_s)) {
		g_LANE_WIDTH = atoi(g_LANE_WIDTH_s.c_str());
		g_NUM_OF_PIXELS = atoi(g_NUM_OF_PIXELS_s.c_str());

		dbswdbe->loadRefBySQL("SELECT refWdbeCPort FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'l0_hs_data_i'", refC);
		mdlNum = Wdbe::getNextPrtMdlNum(dbswdbe, refWdbeMModule);

		for (int i = 2; i < g_LANE_WIDTH; i++) dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::RTESUP, "l" + to_string(i) + "_hs_data_i", VecWdbeVMPortDir::IN, "slvdn", 8, "", "", "", "", "", "");
	
		for (int i = 2; i < g_LANE_WIDTH; i++) {
			refC = dbswdbe->tblwdbecport->getNewRef();

			dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::RTESUP, "l" + to_string(i) + "_lp_data_i", VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", "", "");
			dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::RTESUP, "l" + to_string(i) + "_lp_data_n_i", VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", "", "");
		};

		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "data_out_o", wData * g_NUM_OF_PIXELS);
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
