/**
	* \file WdbeMtpCplmstbuTpsram_mchp_v1_1_108.cpp
	* Wdbe operation processor - adapt port identifiers and widths (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 19 Oct 2025
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpCplmstbuTpsram_mchp_v1_1_108.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuTpsram_mchp_v1_1_108
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuTpsram_mchp_v1_1_108::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	string size, wRd, wWr;
	unsigned short wAddr0, wWord;

	string s;

	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "size", size))
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wRd", wRd))
			if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wWr", wWr)) {
				// adapt address and data port widths
				wAddr0 = Wdbe::valToWidth(atoi(size.c_str()) * 1024 - 1);

				wWord = atoi(wRd.c_str()) / 8;
				Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "R_ADDR", wAddr0 - log2(wWord));
				Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "R_DATA", 8 * wWord);

				wWord = atoi(wWr.c_str()) / 8;
				Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "W_ADDR", wAddr0 - log2(wWord));
				Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "W_DATA", 8 * wWord);
			};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
