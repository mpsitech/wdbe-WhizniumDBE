/**
	* \file WdbeGenTest.cpp
	* Wdbe operation processor - generate test infrastructure (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 23 Oct 2021
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeGenTest.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeGen;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeGenTest
 ******************************************************************************/

DpchRetWdbeGenTest* WdbeGenTest::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeGenTest* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	std::string logfile;

	// IP run --- IBEGIN
	ListWdbeMProcess prcs;
	WdbeMProcess* prc = NULL;

	ubigint refC;

	uint mdlNum;

	// --- FSM debug ports
	mdlNum = Wdbe::getNextPrtMdlNum(dbswdbe, refWdbeMModule);

	dbswdbe->tblwdbemprocess->loadRstByMdl(refWdbeMModule, false, prcs);

	refC = 0;
	if (prcs.nodes.size() > 1) refC = dbswdbe->tblwdbecport->getNewRef();

	for (unsigned int i = 0; i < prcs.nodes.size(); i++) {
		prc = prcs.nodes[i];

		if (prc->refWdbeMFsm != 0) dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::DBG, "state" + StrMod::cap(prc->sref) + "_dbg", VecWdbeVMPortDir::OUT, "slvdn", 8, "", "", "", "", "", "");
	};
	// IP run --- IEND

	return(new DpchRetWdbeGenTest("", "", ixOpVOpres, 100, logfile));
};

// IP cust --- INSERT
