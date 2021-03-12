/**
	* \file WdbeMtpModdetTop_v1_0.cpp
	* Wdbe operation processor - add reset and master clock (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpModdetTop_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpModdet;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpModdetTop_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpModdetTop_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpModdet* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	ubigint ref, refC;

	WdbeMProcess* prc = NULL;

	WdbeMPort* prt = NULL;

	WdbeMModule* mdl = NULL;
	uint mdlNum = 1;

	ubigint refPrcRst;

	double fExtclk, fMclk;

	string s;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		// - reset circuitry
		refPrcRst = dbswdbe->tblwdbemprocess->insertNewRec(&prc, mdl->ref, 0, "rst", "", "", false, "", false, "reset");

		ref = dbswdbe->tblwdbemfsm->insertNewRec(NULL, prc->ref);

		prc->refWdbeMFsm = ref;
		dbswdbe->tblwdbemprocess->updateRec(prc);

		delete prc;

		dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, ref, 1, "reset", false, "");
		dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, 0, ref, 2, "run", false, "");

		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcRst, 0, "reset", false, "sl", 1, "", "state(reset)", "1", "0", false, 0, "");

		if (dbswdbe->tblwdbemport->loadRecBySQL("SELECT TblWdbeMPort.* FROM TblWdbeMModule, TblWdbeMPort WHERE TblWdbeMModule.supRefWdbeMModule = " + to_string(mdl->ref) + " AND TblWdbeMPort.ixVDir = " + to_string(VecWdbeVMPortDir::OUT)
					+ " AND TblWdbeMPort.mdlRefWdbeMModule = TblWdbeMModule.ref AND TblWdbeMPort.sref = 'reqReset'", &prt)) {

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "reqReset", false, "sl", 1, "", "", "", "0", false, 0, "");

			prt->csiSrefWdbeMSignal = "reqReset";
			dbswdbe->tblwdbemport->updateRec(prt);

			delete prt;
		};

		// - master clock circuitry
		Wdbe::getGenDfv(dbswdbe, mdl->ref, "fExtclk", s);
		fExtclk = atof(s.c_str());
		Wdbe::getGenDfv(dbswdbe, mdl->ref, "fMclk", s);
		fMclk = atof(s.c_str());

		if ((fExtclk == 0.0) || (fMclk == 0.0) || (fExtclk == fMclk)) {
			// clock ratio 1:1, simple input buffer

			if (dbswdbe->loadRefBySQL("SELECT TblWdbeMPin.ref FROM TblWdbeMBank, TblWdbeMPin WHERE TblWdbeMBank.refWdbeMUnit = " + to_string(mdl->hkUref) + " AND TblWdbeMPin.refWdbeMBank = TblWdbeMBank.ref AND TblWdbeMPin.sref = 'extclkp'", ref)) {
				// LVDS external clock input
				dbswdbe->executeQuery("UPDATE TblWdbeMModule SET hkNum = hkNum + 1 WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND hkNum > " + to_string(mdl->hkNum));

				ref = dbswdbe->tblwdbemmodule->insertNewRec(NULL, VecWdbeVMModuleBasetype::MNFPRIM, mdl->hkIxVTbl, mdl->hkUref, mdl->hkNum+1, mdl->ref, Wdbe::getRefMtp(dbswdbe, "IBUFGDS"), 0, 0, "ibufgdsExtclk", "");

				refC = dbswdbe->tblwdbecport->getNewRef();
				dbswdbe->tblwdbemport->insertNewRec(NULL, refC, ref, 1, VecWdbeVMPortMdlCat::RTEPIN, "I", VecWdbeVMPortDir::IN, "sl", 1, "", "", "extclkp", "", "", "");
				dbswdbe->tblwdbemport->insertNewRec(NULL, refC, ref, 2, VecWdbeVMPortMdlCat::RTEPIN, "IB", VecWdbeVMPortDir::IN, "sl", 1, "", "", "extclkn", "", "", "");
				dbswdbe->tblwdbemport->insertNewRec(NULL, refC, ref, 3, VecWdbeVMPortMdlCat::RTESUP, "O", VecWdbeVMPortDir::OUT, "sl", 1, "", "", "", "", "mclk", "");

			} else {
				// non-LVDS external clock input
				dbswdbe->executeQuery("UPDATE TblWdbeMModule SET hkNum = hkNum + 1 WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND hkNum > " + to_string(mdl->hkNum));

				ref = dbswdbe->tblwdbemmodule->insertNewRec(NULL, VecWdbeVMModuleBasetype::MNFPRIM, mdl->hkIxVTbl, mdl->hkUref, mdl->hkNum+1, mdl->ref, Wdbe::getRefMtp(dbswdbe, "BUFG"), 0, 0, "bufgExtclk", "");

				refC = dbswdbe->tblwdbecport->getNewRef();
				dbswdbe->tblwdbemport->insertNewRec(NULL, refC, ref, 1, VecWdbeVMPortMdlCat::RTEPIN, "I", VecWdbeVMPortDir::IN, "sl", 1, "", "", "extclk", "", "", "");
				dbswdbe->tblwdbemport->insertNewRec(NULL, refC, ref, 2, VecWdbeVMPortMdlCat::RTESUP, "O", VecWdbeVMPortDir::OUT, "sl", 1, "", "", "", "", "mclk", "");
			};

		} else {
			// clock ratio x:1, mmclk

			if (dbswdbe->loadRefBySQL("SELECT TblWdbeMPin.ref FROM TblWdbeMBank, TblWdbeMPin WHERE TblWdbeMBank.refWdbeMUnit = " + to_string(mdl->hkUref) + " AND TblWdbeMPin.refWdbeMBank = TblWdbeMBank.ref AND TblWdbeMPin.sref = 'extclkp'", ref)) {
				// LVDS external clock input
				dbswdbe->executeQuery("UPDATE TblWdbeMModule SET hkNum = hkNum + 2 WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND hkNum > " + to_string(mdl->hkNum));

				ref = dbswdbe->tblwdbemmodule->insertNewRec(NULL, VecWdbeVMModuleBasetype::MNFPRIM, mdl->hkIxVTbl, mdl->hkUref, mdl->hkNum+1, mdl->ref, Wdbe::getRefMtp(dbswdbe, "IBUFDS"), 0, 0, "ibufdsExtclk", "");

				refC = dbswdbe->tblwdbecport->getNewRef();
				dbswdbe->tblwdbemport->insertNewRec(NULL, refC, ref, 1, VecWdbeVMPortMdlCat::RTEPIN, "I", VecWdbeVMPortDir::IN, "sl", 1, "", "", "extclkp", "", "", "");
				dbswdbe->tblwdbemport->insertNewRec(NULL, refC, ref, 2, VecWdbeVMPortMdlCat::RTEPIN, "IB", VecWdbeVMPortDir::IN, "sl", 1, "", "", "extclkn", "", "", "");
				dbswdbe->tblwdbemport->insertNewRec(NULL, refC, ref, 3, VecWdbeVMPortMdlCat::RTESUP, "O", VecWdbeVMPortDir::OUT, "sl", 1, "", "", "", "", "extclk", "");

				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::CLK, 0, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "extclk", false, "sl", 1, "", "", "", "0", false, 0, "");

				ref = dbswdbe->tblwdbemmodule->insertNewRec(NULL, VecWdbeVMModuleBasetype::MNFCORE, mdl->hkIxVTbl, mdl->hkUref, mdl->hkNum+2, mdl->ref, Wdbe::getRefMtp(dbswdbe, "mmcm_v5_4"), 0, 0, "mmcmMclk", "");
				Wdbe::setMpa(dbswdbe, ref, "div", to_string(lround(fExtclk/fMclk)));

				refC = dbswdbe->tblwdbecport->getNewRef();
				dbswdbe->tblwdbemport->insertNewRec(NULL, refC, ref, 1, VecWdbeVMPortMdlCat::RTESUP, "reset", VecWdbeVMPortDir::IN, "sl", 1, "", "0", "", "", "", "");
				dbswdbe->tblwdbemport->insertNewRec(NULL, refC, ref, 2, VecWdbeVMPortMdlCat::RTESUP, "clk_in1", VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", "extclk", "");
				dbswdbe->tblwdbemport->insertNewRec(NULL, refC, ref, 3, VecWdbeVMPortMdlCat::RTESUP, "clk_out1", VecWdbeVMPortDir::OUT, "sl", 1, "", "", "", "", "mclk", "");

			} else {
				// non-LVDS external clock input
				dbswdbe->executeQuery("UPDATE TblWdbeMModule SET hkNum = hkNum + 1 WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND hkNum > " + to_string(mdl->hkNum));

				ref = dbswdbe->tblwdbemmodule->insertNewRec(NULL, VecWdbeVMModuleBasetype::MNFCORE, mdl->hkIxVTbl, mdl->hkUref, mdl->hkNum+2, mdl->ref, Wdbe::getRefMtp(dbswdbe, "mmcm_v5_4"), 0, 0, "mmcmMclk", "");
				Wdbe::setMpa(dbswdbe, ref, "div", to_string(lround(fExtclk/fMclk)));

				refC = dbswdbe->tblwdbecport->getNewRef();
				dbswdbe->tblwdbemport->insertNewRec(NULL, refC, ref, 1, VecWdbeVMPortMdlCat::RTESUP, "reset", VecWdbeVMPortDir::IN, "sl", 1, "", "0", "", "", "", "");
				dbswdbe->tblwdbemport->insertNewRec(NULL, refC, ref, 2, VecWdbeVMPortMdlCat::RTEPIN, "clk_in1", VecWdbeVMPortDir::IN, "sl", 1, "", "", "extclk", "", "", "");
				dbswdbe->tblwdbemport->insertNewRec(NULL, refC, ref, 3, VecWdbeVMPortMdlCat::RTESUP, "clk_out1", VecWdbeVMPortDir::OUT, "sl", 1, "", "", "", "", "mclk", "");
			};
		};

		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "mclk", false, "sl", 1, "", "", "", "0", false, 0, "");

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
