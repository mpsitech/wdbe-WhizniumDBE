/**
	* \file WdbeMtpCplmstbuSpbram_efnx_v6_1.cpp
	* Wdbe operation processor - adapt port widths (implementation)
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

#include "WdbeMtpCplmstbuSpbram_efnx_v6_1.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuSpbram_efnx_v6_1
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuSpbram_efnx_v6_1::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	string size, w;
	unsigned short wAddr0, wWord;

	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "size", size))
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "w", w)) {
			// adapt address and data port widths
			wAddr0 = Wdbe::valToWidth(atoi(size.c_str()) * 1024 - 1);

			wWord = atoi(w.c_str()) / 8;
			Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "addr", wAddr0 - log2(wWord));
			Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "rdata_a", 8 * wWord);
			Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "wdata_a", 8 * wWord);
		};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
