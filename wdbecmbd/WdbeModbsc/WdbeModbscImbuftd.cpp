/**
	* \file WdbeModbscImbuftd.cpp
	* Wdbe operation processor - add parameters (implementation)
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

#include "WdbeModbscImbuftd.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeModbsc;

/******************************************************************************
 namespace WdbeModbscImbuftd
 ******************************************************************************/

DpchRetWdbe* WdbeModbscImbuftd::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeModbscImbuftd* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WdbeMModule* mdl = NULL;

	string dir;

	string sref;
	uint ixVDir;

	string s;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		if (mdl->refWdbeMImbuf == 0) {
			if (!Wdbe::getMpa(dbswdbe, mdl->ref, "dir", dir)) dir = "atob";

			sref = StubWdbe::getStubMdlSref(dbswdbe, mdl->supRefWdbeMModule);

			if (dir == "atob") {
				sref = sref + "ToCormdl";
				ixVDir = VecWdbeVMImbufDir::OUT;
			} else {
				sref = "cormdlTo" + StrMod::cap(sref);
				ixVDir = VecWdbeVMImbufDir::IN;
			};

			mdl->refWdbeMImbuf = dbswdbe->tblwdbemimbuf->insertNewRec(NULL, mdl->ref, 0, sref, ixVDir, 0);
			dbswdbe->tblwdbemmodule->updateRec(mdl);
		};

		if (!Wdbe::getMpa(dbswdbe, mdl->ref, "maxlen", s)) Wdbe::setMpa(dbswdbe, mdl->ref, "maxlen", "1024");

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
