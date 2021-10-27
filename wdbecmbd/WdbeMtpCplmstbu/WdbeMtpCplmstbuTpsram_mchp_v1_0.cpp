/**
	* \file WdbeMtpCplmstbuTpsram_mchp_v1_0.cpp
	* Wdbe operation processor - adapt port identifiers and widths (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpCplmstbuTpsram_mchp_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuTpsram_mchp_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuTpsram_mchp_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WdbeMImbuf* imb = NULL;

	string sref, srefrootMgmt, srefrootCor;

	string size;
	unsigned short w;

	bool clkNotP, d32Not8;

	string s;

	if (dbswdbe->tblwdbemimbuf->loadRecBySQL("SELECT * FROM TblWdbeMImbuf WHERE refWdbeMModule = " + to_string(refWdbeMModule), &imb)) {
		// inter-module buffer width trumps b32Not8 parameter
		if (imb->Width == 32) s = "32";
		else s = "8";

		if (!Wdbe::getImbsrefs(dbswdbe, refWdbeMModule, sref, srefrootMgmt, srefrootCor)) Wdbe::setMpa(dbswdbe, refWdbeMModule, "r8Vs32", s);
		else Wdbe::setMpa(dbswdbe, refWdbeMModule, "w8Vs32", s);

		delete imb;
	};

	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "size", size)) {
		// update clock identifier
		Wdbe::getMpa(dbswdbe, refWdbeMModule, "rPVsN", s); clkNotP = (s == "n");
		if (clkNotP) dbswdbe->executeQuery("UPDATE TblWdbeMPort SET sref = 'R_CLK_N' WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'R_CLK'");

		Wdbe::getMpa(dbswdbe, refWdbeMModule, "wPVsN", s); clkNotP = (s == "n");
		if (clkNotP) dbswdbe->executeQuery("UPDATE TblWdbeMPort SET sref = 'W_CLK_N' WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'W_CLK'");

		// adapt address and data port widths
		w = Wdbe::valToWidth(atoi(size.c_str()) * 1024 - 1);

		Wdbe::getMpa(dbswdbe, refWdbeMModule, "r8Vs32", s); d32Not8 = (s == "32");
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "R_ADDR", (d32Not8) ? (w - 2) : w);
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "R_DATA", (d32Not8) ? 32 : 8);

		Wdbe::getMpa(dbswdbe, refWdbeMModule, "w8Vs32", s); d32Not8 = (s == "32");
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "W_ADDR", (d32Not8) ? (w - 2) : w);
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "W_DATA", (d32Not8) ? 32 : 8);
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
