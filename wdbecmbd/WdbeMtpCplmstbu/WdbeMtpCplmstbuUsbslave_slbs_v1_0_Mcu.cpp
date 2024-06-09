/**
	* \file WdbeMtpCplmstbuUsbslave_slbs_v1_0_Mcu.cpp
	* Wdbe operation processor - add handshake with managing module (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 31 Dec 2022
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpCplmstbuUsbslave_slbs_v1_0_Mcu.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuUsbslave_slbs_v1_0_Mcu
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuUsbslave_slbs_v1_0_Mcu::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WdbeMModule* mdl = NULL;
	WdbeMModule* mgmt = NULL;

	uint mdlNum;

	ubigint refC;

	string s;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		if (dbswdbe->tblwdbemmodule->loadRecBySQL("SELECT TblWdbeMModule.* FROM TblWdbeMModule, TblWdbeRMModuleMModule WHERE TblWdbeMModule.ref = TblWdbeRMModuleMModule.corRefWdbeMModule AND TblWdbeRMModuleMModule.ctdRefWdbeMModule = "
					+ to_string(refWdbeMModule) + " AND TblWdbeRMModuleMModule.srefKFunction = 'mgmt'", &mgmt)) {

			s = StrMod::cap(mgmt->sref) + "To" + StrMod::cap(mdl->sref);

			mdlNum = Wdbe::getNextSigRefNum(dbswdbe, VecWdbeVMSignalRefTbl::UNT, mdl->hkUref);

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::UNT, mdl->hkUref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, mgmt->ref, 0, "req" + s + "Send", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::UNT, mdl->hkUref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, refWdbeMModule, 0, "ack" + s + "Send", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::UNT, mdl->hkUref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, refWdbeMModule, 0, "dne" + s + "Send", false, "sl", 1, "", "", "", "0", false, 0, "");

			refC = dbswdbe->tblwdbecsignal->getNewRef();
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::UNT, mdl->hkUref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, mgmt->ref, 0, "req" + s + "Recv", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::UNT, mdl->hkUref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, refWdbeMModule, 0, "ack" + s + "Recv", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::UNT, mdl->hkUref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, refWdbeMModule, 0, "dne" + s + "Recv", false, "sl", 1, "", "", "", "0", false, 0, "");

			delete mgmt;
		};

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
