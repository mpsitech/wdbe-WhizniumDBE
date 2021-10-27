/**
	* \file WdbeMtpCplmstbuDpbram_xlnx_v8_4.cpp
	* Wdbe operation processor - adapt port widths (implementation)
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

#include "WdbeMtpCplmstbuDpbram_xlnx_v8_4.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuDpbram_xlnx_v8_4
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuDpbram_xlnx_v8_4::run(
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

	bool a32Not8, b32Not8;

	string s;

	if (dbswdbe->tblwdbemimbuf->loadRecBySQL("SELECT * FROM TblWdbeMImbuf WHERE refWdbeMModule = " + to_string(refWdbeMModule), &imb)) {
		// inter-module buffer width trumps b32Not8 parameter
		if (imb->Width == 32) s = "true";
		else s = "false";

		Wdbe::setMpa(dbswdbe, refWdbeMModule, "b32Not8", s);

		// write enable default according to inter-module buffer direction
		mgmtToNotFrom = Wdbe::getImbsrefs(dbswdbe, refWdbeMModule, sref, srefrootMgmt, srefrootCor);
		if (!mgmtToNotFrom) Wdbe::setPrtDfv(dbswdbe, refWdbeMModule, "weA", "1");
		else Wdbe::setPrtDfv(dbswdbe, refWdbeMModule, "weB", "1");

		delete imb;
	};

	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "size", size)) {
		// adapt address and data port widths
		w = Wdbe::valToWidth(atoi(size.c_str()) * 1024 - 1);

		Wdbe::getMpa(dbswdbe, refWdbeMModule, "a32Not8", s); a32Not8 = (s == "true");
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "addrA", (a32Not8) ? (w-2) : w);
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "doutA", (a32Not8) ? 32 : 8);
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "dinA", (a32Not8) ? 32 : 8);

		Wdbe::getMpa(dbswdbe, refWdbeMModule, "b32Not8", s); b32Not8 = (s == "true");
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "addrB", (b32Not8) ? (w-2) : w);
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "doutB", (b32Not8) ? 32 : 8);
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "dinB", (b32Not8) ? 32 : 8);
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
