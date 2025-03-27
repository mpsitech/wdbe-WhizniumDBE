/**
	* \file WdbeMtpGenfstHostif_Easy_v1_0.cpp
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

#include "WdbeMtpGenfstHostif_Easy_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpGenfst;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpGenfstHostif_Easy_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpGenfstHostif_Easy_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpGenfst* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	ubigint refC;
	uint fsmNum = 1;

	WdbeMProcess* prc = NULL;

	dbswdbe->tblwdbemprocess->insertNewRec(&prc, refWdbeMModule, 0, "op", "mclk", "reset", false, "state(init) or wordto or xferto", false, "main operation");

	prc->refWdbeMFsm = dbswdbe->tblwdbemfsm->insertNewRec(NULL, prc->ref, VecWdbeVMFsmDbgtaptype::CLUST);
	dbswdbe->tblwdbemprocess->updateRec(prc);

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
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "txpollE", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "txpollF", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "txpollG", false, "");

	refC = dbswdbe->tblwdbecfsmstate->getNewRef();
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "txA", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "txB", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "txC", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "txD", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "txE", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "txF", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "txG", false, "");

	refC = dbswdbe->tblwdbecfsmstate->getNewRef();
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "txbufA", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "txbufB", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "txbufC", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "txbufD", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "txbufE", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "txbufF", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "txbufG", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "txbufH", false, "");

	refC = dbswdbe->tblwdbecfsmstate->getNewRef();
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "rxA", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "rxB", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "rxC", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "rxD", false, "");

	refC = dbswdbe->tblwdbecfsmstate->getNewRef();
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "rxbufA", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "rxbufB", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "rxbufC", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "rxbufD", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "rxbufE", false, "");
	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "rxbufF", false, "");

	dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, prc->refWdbeMFsm, fsmNum++, "inv", false, "");

	delete prc;
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
