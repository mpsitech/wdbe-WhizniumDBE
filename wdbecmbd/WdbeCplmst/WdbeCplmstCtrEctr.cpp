/**
	* \file WdbeCplmstCtrEctr.cpp
	* Wdbe operation processor - add controller (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Oct 2021
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeCplmstCtrEctr.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeCplmst;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeCplmstCtrEctr
 ******************************************************************************/

DpchRetWdbe* WdbeCplmstCtrEctr::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeCplmstCtrEctr* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WdbeMModule* mdl = NULL;
	WdbeMUnit* unt = NULL;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		if (mdl->hkIxVTbl == VecWdbeVMModuleHkTbl::UNT) if (dbswdbe->tblwdbemunit->loadRecByRef(mdl->hkUref, &unt)) {
			if (mdl->refWdbeMController == 0) {
				mdl->refWdbeMController = dbswdbe->tblwdbemcontroller->insertNewRec(NULL, mdl->ref, 0, "Ctr" + unt->Fullsref.substr(3) + StrMod::cap(mdl->sref), 0);
				dbswdbe->tblwdbemmodule->updateRec(mdl);
			};

			// command vector: fill in GenStdvec
			dbswdbe->tblwdbemvector->insertNewRec(NULL, VecWdbeVMVectorBasetype::TIXLIN, VecWdbeVMVectorHkTbl::CTR, mdl->refWdbeMController, "VecV" + unt->Fullsref.substr(3) + StrMod::cap(mdl->sref) + "Command", "notit;filfed");

			delete unt;
		};
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
