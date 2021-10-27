/**
	* \file WdbeMtpCplmstbuDpsram_mchp_v1_0.cpp
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

#include "WdbeMtpCplmstbuDpsram_mchp_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuDpsram_mchp_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuDpsram_mchp_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WdbeMImbuf* imb = NULL;

	bool mgmtToNotFrom;
	string sref, srefrootMgmt, srefrootCor;

	string size;
	unsigned short w;

	bool clkNotP, a32Not8, b32Not8;

	string s;

	b32Not8 = false;
	if (dbswdbe->tblwdbemimbuf->loadRecBySQL("SELECT * FROM TblWdbeMImbuf WHERE refWdbeMModule = " + to_string(refWdbeMModule), &imb)) {
		// inter-module buffer width trumps 8Vs32 parameter
		b32Not8 = (imb->Width == 32);

		// write enable default according to inter-module buffer direction
		mgmtToNotFrom = Wdbe::getImbsrefs(dbswdbe, refWdbeMModule, sref, srefrootMgmt, srefrootCor);
		if (!mgmtToNotFrom) Wdbe::setPrtDfv(dbswdbe, refWdbeMModule, "A_WEN", "1");
		else Wdbe::setPrtDfv(dbswdbe, refWdbeMModule, "B_WEN", "1");

		delete imb;
	};

	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "size", size)) {
		// update clock identifier
		Wdbe::getMpa(dbswdbe, refWdbeMModule, "pVsN", s); clkNotP = (s == "n");
		if (clkNotP) dbswdbe->executeQuery("UPDATE TblWdbeMPort SET sref = 'CLK_N' WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'CLK'");

		// adapt address and data port widths
		w = Wdbe::valToWidth(atoi(size.c_str()) * 1024 - 1);

		Wdbe::getMpa(dbswdbe, refWdbeMModule, "8Vs32", s); a32Not8 = (s == "32");
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "A_ADDR", (a32Not8) ? (w - 2) : w);
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "A_DOUT", (a32Not8) ? 32 : 8);
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "A_DIN", (a32Not8) ? 32 : 8);

		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "B_ADDR", (b32Not8) ? (w - 2) : w);
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "B_DOUT", (b32Not8) ? 32 : 8);
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "B_DIN", (b32Not8) ? 32 : 8);
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
