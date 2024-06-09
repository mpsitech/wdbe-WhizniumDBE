/**
	* \file WdbeMtpCplmstbuCrcspec_v2_0.cpp
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

#include "WdbeMtpCplmstbuCrcspec_v2_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuCrcspec_v2_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuCrcspec_v2_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	string poly, wD;
	unsigned short wWord;

	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "poly", poly)) {
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wD", wD)) {
			wWord = atoi(wD.c_str()) / 8;

			// adapt data port width
			Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "d", 8 * wWord);

			// lsbD port required only for data port wider than one byte
			if (wWord < 2) dbswdbe->executeQuery("DELETE FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'lsbD'");
			else Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "lsbD", log2(wWord));

			// adapt output CRC port width
			Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "crc", (poly.length() > 4) ? 32 : 16);
		};
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
