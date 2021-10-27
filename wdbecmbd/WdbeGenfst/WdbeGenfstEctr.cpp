/**
	* \file WdbeGenfstEctr.cpp
	* Wdbe operation processor - add vector constants and FSM debug ports (implementation)
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

#include "WdbeGenfstEctr.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeGenfst;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeGenfstEctr
 ******************************************************************************/

DpchRetWdbe* WdbeGenfstEctr::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeGenfstEctr* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;
	string Prjshort = dpchinv->Prjshort;
	string Untsref = dpchinv->Untsref;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WdbeMModule* mdl = NULL;
	WdbeMController* ctr = NULL;

	ListWdbeMCommand cmds;

	uint mdlNum;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		if (dbswdbe->tblwdbemcontroller->loadRecBySQL("SELECT * FROM TblWdbeMController WHERE refWdbeMModule = " + to_string(refWdbeMModule), &ctr)) {
			// vector constants
			dbswdbe->tblwdbemcommand->loadRstByRetReu(VecWdbeVMCommandRefTbl::CTR, ctr->ref, false, cmds);

			mdlNum = Wdbe::getNextSigRefNum(dbswdbe, VecWdbeVMSignalRefTbl::MDL, ctr->refWdbeMModule);

			addCtrVits(dbswdbe, ctr, cmds, mdlNum, Prjshort, Untsref);

			delete ctr;
		};

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
