/**
	* \file WdbeMtpModbscbuDpbram_v8_4.cpp
	* Wdbe operation processor - adapt port widths (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpModbscbuDpbram_v8_4.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpModbscbu;

/******************************************************************************
 namespace WdbeMtpModbscbuDpbram_v8_4
 ******************************************************************************/

DpchRetWdbe* WdbeMtpModbscbuDpbram_v8_4::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpModbscbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	string size;
	unsigned short w;

	bool a32Not8, b32Not8;

	string dir, rwa, rwb;
	string Defval;

	string s;

	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "size", size)) {
		// adapt address and data port widths
		w = Wdbe::valToWidth(atoi(size.c_str())*1024-1);

		Wdbe::getMpa(dbswdbe, refWdbeMModule, "a32Not8", s); a32Not8 = (s == "true");
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "addrA", (a32Not8) ? (w-2) : w);
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "doutA", (a32Not8) ? 32 : 8);
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "dinA", (a32Not8) ? 32 : 8);

		Wdbe::getMpa(dbswdbe, refWdbeMModule, "b32Not8", s); b32Not8 = (s == "true");
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "addrB", (b32Not8) ? (w-2) : w);
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "doutB", (b32Not8) ? 32 : 8);
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "dinB", (b32Not8) ? 32 : 8);

		// set port default values according to dir/rwa/rwb parameters ; exact copy from WdbeMtpModbsctdDpbram_v1_0
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "dir", dir)) {
			Wdbe::getMpa(dbswdbe, refWdbeMModule, "rwa", rwa);
			if (rwa != "true") rwa = "false";

			Wdbe::getMpa(dbswdbe, refWdbeMModule, "rwb", rwb);
			if (rwb != "true") rwb = "false";

			// weA
			if (dir == "atob") Defval = "1"; else Defval = "0";
			if (rwa == "false") Wdbe::setPrtDfv(dbswdbe, refWdbeMModule, "weA", Defval);
		
			// dwrA
			if ((dir == "btoa") && (rwa == "false")) Wdbe::setPrtDfv(dbswdbe, refWdbeMModule, "dinA", "0");

			// weB
			if (dir == "atob") Defval = "0"; else Defval = "1";
			if (rwb == "false") Wdbe::setPrtDfv(dbswdbe, refWdbeMModule, "weB", Defval);

			// dwrB
			if ((dir == "atob") && (rwb == "false")) Wdbe::setPrtDfv(dbswdbe, refWdbeMModule, "dinB", "0");
		};
	};

	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT



