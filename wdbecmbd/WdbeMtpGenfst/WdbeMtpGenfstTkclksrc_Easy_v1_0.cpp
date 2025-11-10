/**
	* \file WdbeMtpGenfstTkclksrc_Easy_v1_0.cpp
	* Wdbe operation processor - add process (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2024
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpGenfstTkclksrc_Easy_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpGenfst;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpGenfstTkclksrc_Easy_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpGenfstTkclksrc_Easy_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpGenfst* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	uint fsmNum = 1;

	WdbeMProcess* prc = NULL;

	dbswdbe->tblwdbemprocess->insertNewRec(&prc, refWdbeMModule, 0, "op", "mclk", "reset", false, "state(init) or (!state(inv) and reqInvSetTkst)", false, "main operation");

	prc->refWdbeMFsm = dbswdbe->tblwdbemfsm->insertNewRec(NULL, prc->ref, VecWdbeVMFsmDbgtaptype::CLUST);
	dbswdbe->tblwdbemprocess->updateRec(prc);

	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, fsmNum++, "init", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, fsmNum++, "inv", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, fsmNum++, "run", false, "");

	delete prc;
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
