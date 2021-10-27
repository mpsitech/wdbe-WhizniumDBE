/**
	* \file WdbeCplmstSys.cpp
	* Wdbe operation processor - add standard vectors (implementation)
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

#include "WdbeCplmstSys.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeCplmst;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeCplmstSys
 ******************************************************************************/

DpchRetWdbe* WdbeCplmstSys::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeCplmstSys* dpchinv
		) {
	ubigint refWdbeMVersion = dpchinv->refWdbeMVersion;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	ubigint ref;

	ListWdbeMSystem syss;
	WdbeMSystem* sys = NULL;

	ListWdbeMTarget trgs;
	WdbeMTarget* trg = NULL;

	// target vector per system
	dbswdbe->tblwdbemsystem->loadRstBySQL("SELECT * FROM TblWdbeMSystem WHERE refWdbeMVersion = " + to_string(refWdbeMVersion), false, syss);

	for (unsigned int i = 0; i < syss.nodes.size(); i++) {
		sys = syss.nodes[i];

		ref = dbswdbe->tblwdbemvector->insertNewRec(NULL, VecWdbeVMVectorBasetype::IXLIN, VecWdbeVMVectorHkTbl::SYS, sys->ref, "VecV" + sys->sref + "Target", "notit;filfed");

		dbswdbe->tblwdbemtarget->loadRstBySQL("SELECT * FROM TblWdbeMTarget WHERE sysRefWdbeMSystem = " + to_string(sys->ref) + " ORDER BY sysNum ASC", false, trgs);

		for (unsigned int j = 0; j < trgs.nodes.size(); j++) {
			trg = trgs.nodes[j];

			dbswdbe->tblwdbemvectoritem->insertNewRec(NULL, ref, trg->sysNum, trg->sref, "", "");
		};
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
