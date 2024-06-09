/**
	* \file WdbeMtpCplmstbuFifo_lttc_v1_3.cpp
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

#include "WdbeMtpCplmstbuFifo_lttc_v1_3.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuFifo_lttc_v1_3
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuFifo_lttc_v1_3::run(
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

	string wWr, wRd;
	unsigned short wWord;

	string s;

	if (dbswdbe->tblwdbemimbuf->loadRecBySQL("SELECT * FROM TblWdbeMImbuf WHERE refWdbeMModule = " + to_string(refWdbeMModule), &imb)) {
		// inter-module buffer width trumps wWr/wRd parameter
		s = to_string((int) (imb->Width));

		mgmtToNotFrom = Wdbe::getImbsrefs(dbswdbe, refWdbeMModule, sref, srefrootMgmt, srefrootCor);

		if (!mgmtToNotFrom) Wdbe::setMpa(dbswdbe, refWdbeMModule, "wRd", s);
		else Wdbe::setMpa(dbswdbe, refWdbeMModule, "wWr", s);

		delete imb;
	};

	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wWr", wWr))
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wRd", wRd)) {
			// adapt data port widths
			Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "wr_data_i", atoi(wWr.c_str()));
			Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "rd_data_o", atoi(wRd.c_str()));
		};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
