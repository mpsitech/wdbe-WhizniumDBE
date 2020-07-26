/**
	* \file WdbeModbscCtrtd.cpp
	* Wdbe operation processor - add controller (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeModbscCtrtd.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeModbsc;

/******************************************************************************
 namespace WdbeModbscCtrtd
 ******************************************************************************/

DpchRetWdbe* WdbeModbscCtrtd::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeModbscCtrtd* dpchinv
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

			// command vector: fill in ModdetUnt
			dbswdbe->tblwdbemvector->insertNewRec(NULL, VecWdbeVMVectorBasetype::TIXLIN, VecWdbeVMVectorHkTbl::CTR, mdl->refWdbeMController, "VecV" + unt->Fullsref.substr(3) + StrMod::cap(mdl->sref) + "Command", "notit;filfed");

			delete unt;
		};
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT


