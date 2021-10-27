/**
	* \file WdbeGenfstTop.cpp
	* Wdbe operation processor - add reset process (implementation)
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

#include "WdbeGenfstTop.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeGenfst;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeGenfstTop
 ******************************************************************************/

DpchRetWdbe* WdbeGenfstTop::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeGenfstTop* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	ubigint ref;

	WdbeMModule* mdl = NULL;

	WdbeMProcess* prc = NULL;

	string srefPrtReset;

	ubigint refFstReset, refFstRun;

	uint refNum;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		srefPrtReset = "extreset";
		dbswdbe->loadStringBySQL("SELECT sref FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'extresetn'", srefPrtReset);

		dbswdbe->tblwdbemprocess->insertNewRec(&prc, mdl->ref, 0, "rst", "mclk", srefPrtReset, false, "", false, "reset");

		dbswdbe->tblwdbemvariable->insertNewRec(NULL, 0, VecWdbeVMVariableRefTbl::PRC, prc->ref, 1, "imax", true, false, "nat", 0, "", "", "16", false, "");
		dbswdbe->tblwdbemvariable->insertNewRec(NULL, 0, VecWdbeVMVariableRefTbl::PRC, prc->ref, 2, "i", false, false, "nat", 0, "0..imax", "", "0", false, "");

		ref = dbswdbe->tblwdbemfsm->insertNewRec(NULL, prc->ref);
		prc->refWdbeMFsm = ref;
		dbswdbe->tblwdbemprocess->updateRec(prc);

		refFstReset = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, ref, 1, "reset", true, "");
		refFstRun = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, ref, 2, "run", false, "");

		dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstReset, 1, refFstRun, "i=imax", "", "", "", "", "", "", "");

		refNum = Wdbe::getNextSigRefNum(dbswdbe, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule);

		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, refNum++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "reset", false, "sl", 1, "", "state(reset)", "1", "0", false, 0, "");

		delete prc;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
