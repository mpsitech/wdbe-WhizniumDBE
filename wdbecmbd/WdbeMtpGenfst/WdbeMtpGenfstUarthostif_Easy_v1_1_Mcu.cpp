/**
	* \file WdbeMtpGenfstUarthostif_Easy_v1_1_Mcu.cpp
	* Wdbe operation processor - add process and sensitivities (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 4 Oct 2021
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpGenfstUarthostif_Easy_v1_1_Mcu.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpGenfst;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpGenfstUarthostif_Easy_v1_1_Mcu
 ******************************************************************************/

DpchRetWdbe* WdbeMtpGenfstUarthostif_Easy_v1_1_Mcu::run(
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
	dbswdbe->tblwdbemprocess->insertNewRec(&prc, refWdbeMModule, 0, "op", "", "", false, "", false, "main operation");

	prc->refWdbeMFsm = dbswdbe->tblwdbemfsm->insertNewRec(NULL, prc->ref);
	dbswdbe->tblwdbemprocess->updateRec(prc);

	fsmNum = 1;

	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, fsmNum++, "init", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, fsmNum++, "idle", false, "");

	refC = dbswdbe->tblwdbecfsmstate->getNewRef();
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "rxopA", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "rxopB", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "rxopC", false, "");

	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, fsmNum++, "voidinv", false, "");

	refC = dbswdbe->tblwdbecfsmstate->getNewRef();
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "txA", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "txB", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "txC", false, "");

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

	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, fsmNum++, "inv", false, "");

	if (hasrxbuf) {
		refC = dbswdbe->tblwdbecfsmstate->getNewRef();
		dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "rxbufA", false, "");
		dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "rxbufB", false, "");
		dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "rxbufC", false, "");
	};

	refC = dbswdbe->tblwdbecfsmstate->getNewRef();
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "txackA", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "txackB", false, "");

	delete prc;

	// sensitivity to hhstsrc.getHhst statsng update (can't use command invocation as hostif is not a controller)
	if (dbswdbe->tblwdbemmodule->loadRecBySQL("SELECT TblWdbeMModule.* FROM TblWdbeMModule, TblWdbeRMModuleMModule WHERE TblWdbeMModule.ref = TblWdbeRMModuleMModule.corRefWdbeMModule AND TblWdbeRMModuleMModule.ctdRefWdbeMModule = "
				+ to_string(refWdbeMModule) + " AND srefKFunction = 'hhstsrc'", &mdl)) {
		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMSignal WHERE refIxVTbl = " + to_string(VecWdbeVMSignalRefTbl::UNT) + " AND refUref = " + to_string(mdl->hkUref) + " AND sref = '" + mdl->sref + "GetHhst'", ref))
					dbswdbe->tblwdbemsensitivity->insertNewRec(NULL, VecWdbeVMSensitivityRefTbl::MDL, refWdbeMModule, VecWdbeVMSensitivitySrcTbl::SIG, ref);

		delete mdl;
	};

	// sensitivities to UART RX / TX strobes
	if (dbswdbe->tblwdbemmodule->loadRecBySQL("SELECT TblWdbeMModule.* FROM TblWdbeMModule, TblWdbeRMModuleMModule WHERE TblWdbeMModule.ref = TblWdbeRMModuleMModule.corRefWdbeMModule AND TblWdbeRMModuleMModule.ctdRefWdbeMModule = "
				+ to_string(refWdbeMModule) + " AND srefKFunction = 'rx'", &mdl)) {
		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMSignal WHERE refIxVTbl = " + to_string(VecWdbeVMSignalRefTbl::UNT) + " AND refUref = " + to_string(mdl->hkUref) + " AND sref = 'strb" + StrMod::cap(mdl->sref) + "D'", ref))
					dbswdbe->tblwdbemsensitivity->insertNewRec(NULL, VecWdbeVMSensitivityRefTbl::MDL, refWdbeMModule, VecWdbeVMSensitivitySrcTbl::SIG, ref);

		delete mdl;
	};

	if (dbswdbe->tblwdbemmodule->loadRecBySQL("SELECT TblWdbeMModule.* FROM TblWdbeMModule, TblWdbeRMModuleMModule WHERE TblWdbeMModule.ref = TblWdbeRMModuleMModule.corRefWdbeMModule AND TblWdbeRMModuleMModule.ctdRefWdbeMModule = "
				+ to_string(refWdbeMModule) + " AND srefKFunction = 'tx'", &mdl)) {
		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMSignal WHERE refIxVTbl = " + to_string(VecWdbeVMSignalRefTbl::UNT) + " AND refUref = " + to_string(mdl->hkUref) + " AND sref = 'strb" + StrMod::cap(mdl->sref) + "D'", ref))
					dbswdbe->tblwdbemsensitivity->insertNewRec(NULL, VecWdbeVMSensitivityRefTbl::MDL, refWdbeMModule, VecWdbeVMSensitivitySrcTbl::SIG, ref);

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
