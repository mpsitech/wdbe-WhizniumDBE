/**
	* \file WdbeModdetEctr.cpp
	* Wdbe operation processor - add vector constants and FSM debug ports (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeModdetEctr.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeModdet;

/******************************************************************************
 namespace WdbeModdetEctr
 ******************************************************************************/

DpchRetWdbe* WdbeModdetEctr::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeModdetEctr* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;
	string Prjshort = dpchinv->Prjshort;
	string Untsref = dpchinv->Untsref;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WdbeMController* ctr = NULL;

	ListWdbeMCommand cmds;

	ListWdbeMProcess prcs;
	WdbeMProcess* prc = NULL;

	uint mdlNum = 1;

	// vector constants
	if (dbswdbe->tblwdbemcontroller->loadRecBySQL("SELECT * FROM TblWdbeMController WHERE refWdbeMModule = " + to_string(refWdbeMModule), &ctr)) {
		dbswdbe->tblwdbemcommand->loadRstByRetReu(VecWdbeVMCommandRefTbl::CTR, ctr->ref, false, cmds);

		if (dbswdbe->loadUintBySQL("SELECT mdlNum FROM TblWdbeMSignal WHERE mdlRefWdbeMModule = " + to_string(ctr->refWdbeMModule) + " ORDER BY mdlNum DESC LIMIT 1", mdlNum)) mdlNum++;

		addCtrVits(dbswdbe, ctr, cmds, mdlNum, Prjshort, Untsref);

		delete ctr;
	};

	// FSM debug ports
	dbswdbe->tblwdbemprocess->loadRstByMdl(refWdbeMModule, false, prcs);

	mdlNum = 1;
	if (dbswdbe->loadUintBySQL("SELECT mdlNum FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " ORDER BY mdlNum DESC LIMIT 1", mdlNum)) mdlNum++;

	for (unsigned int i = 0; i < prcs.nodes.size(); i++) {
		prc = prcs.nodes[i];

		if (prc->refWdbeMFsm != 0) dbswdbe->tblwdbemport->insertNewRec(NULL, 0, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::DBG, "state" + StrMod::cap(prc->sref) + "_dbg", VecWdbeVMPortDir::OUT, "slvdn", 8, "", "", "", "", "", "");
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT


