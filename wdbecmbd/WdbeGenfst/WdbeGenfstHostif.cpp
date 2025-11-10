/**
	* \file WdbeGenfstHostif.cpp
	* Wdbe operation processor - connect reset request (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 16 Oct 2021
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeGenfstHostif.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeGenfst;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeGenfstHostif
 ******************************************************************************/

DpchRetWdbe* WdbeGenfstHostif::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeGenfstHostif* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN

	// adapted version from WdbeGenfstEhostif

	WdbeMModule* mdl = NULL;

	WdbeMPort* prt = NULL;

	uint refNum;

	string s;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		if (mdl->supRefWdbeMModule != 0) {
			if (dbswdbe->tblwdbemport->loadRecBySQL("SELECT * FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'reqReset'", &prt)) {
				refNum = Wdbe::getNextSigRefNum(dbswdbe, VecWdbeVMSignalRefTbl::MDL, mdl->supRefWdbeMModule);

				s = "reqResetFrom" + StrMod::cap(mdl->sref);

				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, 0, VecWdbeVMSignalRefTbl::MDL, mdl->supRefWdbeMModule, refNum++, VecWdbeVMSignalMgeTbl::MDL, refWdbeMModule, 0, s, false, "sl", 1, "", "", "", "", 0, "");

				prt->csiSrefWdbeMSignal = s;
				dbswdbe->tblwdbemport->updateRec(prt);

				delete prt;
			};
		};

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
