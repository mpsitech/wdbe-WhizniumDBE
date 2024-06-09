/**
	* \file WdbeMtpCplmstbuSpbram_xlnx_v8_4.cpp
	* Wdbe operation processor - adapt port widths (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 31 Dec 2022
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpCplmstbuSpbram_xlnx_v8_4.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuSpbram_xlnx_v8_4
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuSpbram_xlnx_v8_4::run(
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
			Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "addrA", wAddr0 - log2(wWord));
			Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "doutA", 8 * wWord);
			Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "dinA", 8 * wWord);
		};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
