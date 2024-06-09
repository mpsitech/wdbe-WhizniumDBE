/**
	* \file WdbeMtpCplmstbuDpebram_lttc_v1_2.cpp
	* Wdbe operation processor - adapt port widths (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jan 2023
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpCplmstbuDpebram_lttc_v1_2.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuDpebram_lttc_v1_2
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuDpebram_lttc_v1_2::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	ubigint ref;

	bool mgmtToNotFrom;
	string sref, srefrootMgmt, srefrootCor;

	string size, wA, wB;
	unsigned short wAddr0, wWord;

	if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMImbuf WHERE refWdbeMModule = " + to_string(refWdbeMModule), ref)) {
		// write enable default according to inter-module buffer direction
		mgmtToNotFrom = Wdbe::getImbsrefs(dbswdbe, refWdbeMModule, sref, srefrootMgmt, srefrootCor);
		if (!mgmtToNotFrom) Wdbe::setPrtDfv(dbswdbe, refWdbeMModule, "weA", "1");
		else Wdbe::setPrtDfv(dbswdbe, refWdbeMModule, "weB", "1");
	};

	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "size", size))
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wA", wA))
			if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wB", wB)) {
				// adapt address and data port widths
				wAddr0 = Wdbe::valToWidth(atoi(size.c_str()) * 1024 - 1);

				wWord = atoi(wA.c_str()) / 8;
				Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "addr_a_i", wAddr0 - log2(wWord));
				Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "rd_data_a_o", 8 * wWord);
				Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "wr_data_a_i", 8 * wWord);

				wWord = atoi(wB.c_str()) / 8;
				Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "addr_b_i", wAddr0 - log2(wWord));
				Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "rd_data_b_o", 8 * wWord);
				Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "wr_data_b_i", 8 * wWord);
			};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
