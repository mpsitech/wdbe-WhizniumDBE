/**
	* \file WdbeMtpGenfstUsbhostif_Easy_v2_0_Mcu.cpp
	* Wdbe operation processor - add process and sensitivity (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 19 Jun 2023
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpGenfstUsbhostif_Easy_v2_0_Mcu.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpGenfst;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpGenfstUsbhostif_Easy_v2_0_Mcu
 ******************************************************************************/

DpchRetWdbe* WdbeMtpGenfstUsbhostif_Easy_v2_0_Mcu::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpGenfst* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WdbeMModule* mdl = NULL;

	WdbeMProcess* prc = NULL;

	uint cnt;
	bool hastxbuf, hasrxbuf;

	ubigint ref, refC;

	uint fsmNum;

	dbswdbe->loadUintBySQL("SELECT COUNT(ref) FROM TblWdbeRMModuleMModule WHERE corRefWdbeMModule = " + to_string(refWdbeMModule) + " AND srefKFunction = 'snk'", cnt);
	hastxbuf = (cnt > 0);

	dbswdbe->loadUintBySQL("SELECT COUNT(ref) FROM TblWdbeRMModuleMModule WHERE corRefWdbeMModule = " + to_string(refWdbeMModule) + " AND srefKFunction = 'src'", cnt);
	hasrxbuf = (cnt > 0);

	// main operation process (leave out state(init) to get external syncrst)
	dbswdbe->tblwdbemprocess->insertNewRec(&prc, refWdbeMModule, 0, "op", "", "", false, "state(init)", false, "main operation");

	prc->refWdbeMFsm = dbswdbe->tblwdbemfsm->insertNewRec(NULL, prc->ref, VecWdbeVMFsmDbgtaptype::VOID);
	dbswdbe->tblwdbemprocess->updateRec(prc);

	fsmNum = 1;

	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, fsmNum++, "init", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, fsmNum++, "idle", false, "");

	refC = dbswdbe->tblwdbecfsmstate->getNewRef();
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "rxopA", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "rxopB", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "rxopC", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "rxopD", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "rxopE", false, "");

	refC = dbswdbe->tblwdbecfsmstate->getNewRef();
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "txpollA", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "txpollB", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "txpollC", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "txpollD", false, "");

	refC = dbswdbe->tblwdbecfsmstate->getNewRef();
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "txA", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "txB", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "txC", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "txD", false, "");

	if (hastxbuf) {
		refC = dbswdbe->tblwdbecfsmstate->getNewRef();
		dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "txbufA", false, "");
		dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "txbufB", false, "");
		dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "txbufC", false, "");
		dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "txbufD", false, "");
		dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "txbufE", false, "");
	};

	refC = dbswdbe->tblwdbecfsmstate->getNewRef();
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "rxA", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "rxB", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "rxC", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "rxD", false, "");

	if (hasrxbuf) {
		refC = dbswdbe->tblwdbecfsmstate->getNewRef();
		dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "rxbufA", false, "");
		dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "rxbufB", false, "");
		dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "rxbufC", false, "");
		dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "rxbufD", false, "");
		dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "rxbufE", false, "");
		dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "rxbufF", false, "");
	};

	refC = dbswdbe->tblwdbecfsmstate->getNewRef();
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "invA", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "invB", false, "");

	delete prc;

	// sensitivity to hhstsrc.getHhst statsng update (can't use command invocation as hostif is not a controller)
	if (dbswdbe->tblwdbemmodule->loadRecBySQL("SELECT TblWdbeMModule.* FROM TblWdbeMModule, TblWdbeRMModuleMModule WHERE TblWdbeMModule.ref = TblWdbeRMModuleMModule.corRefWdbeMModule AND TblWdbeRMModuleMModule.ctdRefWdbeMModule = "
				+ to_string(refWdbeMModule) + " AND srefKFunction = 'hhstsrc'", &mdl)) {
		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMSignal WHERE refIxVTbl = " + to_string(VecWdbeVMSignalRefTbl::UNT) + " AND refUref = " + to_string(mdl->hkUref) + " AND sref = '" + mdl->sref + "GetHhst'", ref))
					dbswdbe->tblwdbemsensitivity->insertNewRec(NULL, VecWdbeVMSensitivityRefTbl::MDL, refWdbeMModule, VecWdbeVMSensitivitySrcTbl::SIG, ref);

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
