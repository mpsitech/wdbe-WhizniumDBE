/**
	* \file WdbeMtpCplmsttdTop_xlnx_v1_0.cpp
	* Wdbe operation processor - infer clock primitives (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 15 Oct 2021
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpCplmsttdTop_xlnx_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmsttd;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmsttdTop_xlnx_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmsttdTop_xlnx_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmsttd* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	ubigint ref;

	WdbeMModule* mdl = NULL;

	ListWdbeMPort prts;
	WdbeMPort* prt = NULL;

	bool extresetNNotP, extclkDiffNotSng;

	double fExtclk, fMclk;
	string divstr;

	string s;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		Wdbe::getMpa(dbswdbe, refWdbeMModule, "extresetNNotP", s);
		extresetNNotP = (s == "true");
		Wdbe::getMpa(dbswdbe, refWdbeMModule, "extclkDiffNotSng", s);
		extclkDiffNotSng = (s == "true");

		Wdbe::getMpa(dbswdbe, refWdbeMModule, "fExtclk", s);
		fExtclk = atof(s.c_str());
		Wdbe::getGenDfv(dbswdbe, mdl->ref, "fMclk", s);
		fMclk = atof(s.c_str());

		// - adapt ports
		dbswdbe->tblwdbemport->loadRstByMdl(refWdbeMModule, false, prts);

		for (unsigned int i = 0; i < prts.nodes.size(); i++) {
			prt = prts.nodes[i];

			if (prt->sref == "extreset") {
				if (extresetNNotP) prt->sref = "extresetn";
				if (mdl->supRefWdbeMModule == 0) prt->cpiSrefWdbeMPin = prt->sref;
				else {
					prt->mdlIxVCat = VecWdbeVMPortMdlCat::RTESUP;
					prt->cprSrefWdbeMPort = prt->sref;
				};
				dbswdbe->tblwdbemport->updateRec(prt);

			} else if (prt->sref == "extclkp") {
				if (!extclkDiffNotSng) {
					prt->refWdbeCPort = 0;
					prt->sref = "extclk";
				};
				if (mdl->supRefWdbeMModule == 0) prt->cpiSrefWdbeMPin = prt->sref;
				else {
					prt->mdlIxVCat = VecWdbeVMPortMdlCat::RTESUP;
					prt->cprSrefWdbeMPort = prt->sref;
				};
				dbswdbe->tblwdbemport->updateRec(prt);

			} else if (prt->sref == "extclkn") {
				if (!extclkDiffNotSng) dbswdbe->tblwdbemport->removeRecByRef(prt->ref);
				else {
					if (mdl->supRefWdbeMModule == 0) prt->cpiSrefWdbeMPin = prt->sref;
					else {
						prt->mdlIxVCat = VecWdbeVMPortMdlCat::RTESUP;
						prt->cprSrefWdbeMPort = prt->sref;
					};
					dbswdbe->tblwdbemport->updateRec(prt);
				};
			};
		};

		// - clock conditioning
		if ((fExtclk == 0.0) || (fMclk == 0.0) || (fExtclk == fMclk)) {
			// clock ratio 1:1, simple input buffer

			if (!extclkDiffNotSng) {
				dbswdbe->executeQuery("UPDATE TblWdbeMModule SET hkNum = hkNum + 1 WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND hkNum > " + to_string(mdl->hkNum));

				dbswdbe->tblwdbemmodule->insertNewRec(NULL, VecWdbeVMModuleBasetype::MNFPRIM, mdl->hkIxVTbl, mdl->hkUref, mdl->hkNum + 1, mdl->ref, Wdbe::getRefMtp(dbswdbe, "BUFG"), 0, 0, "bufgExtclk", "", "", "");

			} else {
				dbswdbe->executeQuery("UPDATE TblWdbeMModule SET hkNum = hkNum + 1 WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND hkNum > " + to_string(mdl->hkNum));

				dbswdbe->tblwdbemmodule->insertNewRec(NULL, VecWdbeVMModuleBasetype::MNFPRIM, mdl->hkIxVTbl, mdl->hkUref, mdl->hkNum + 1, mdl->ref, Wdbe::getRefMtp(dbswdbe, "IBUFGDS"), 0, 0, "ibufgdsExtclk", "", "", "");
			};

		} else {
			// clock ratio x:1, use clock conditioning primitive
			divstr = getDivstr(fExtclk / fMclk);

			if (!extclkDiffNotSng) {
				dbswdbe->executeQuery("UPDATE TblWdbeMModule SET hkNum = hkNum + 1 WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND hkNum > " + to_string(mdl->hkNum));

				ref = dbswdbe->tblwdbemmodule->insertNewRec(NULL, VecWdbeVMModuleBasetype::MNFCORE, mdl->hkIxVTbl, mdl->hkUref, mdl->hkNum+2, mdl->ref, Wdbe::getRefMtp(dbswdbe, "mmcm_xlnx_v5_4"), 0, 0, "mmcmMclk", "", "", "");
				Wdbe::setMpa(dbswdbe, ref, "div", divstr);

			} else {
				dbswdbe->executeQuery("UPDATE TblWdbeMModule SET hkNum = hkNum + 2 WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND hkNum > " + to_string(mdl->hkNum));

				dbswdbe->tblwdbemmodule->insertNewRec(NULL, VecWdbeVMModuleBasetype::MNFPRIM, mdl->hkIxVTbl, mdl->hkUref, mdl->hkNum + 1, mdl->ref, Wdbe::getRefMtp(dbswdbe, "IBUFDS"), 0, 0, "ibufdsExtclk", "", "", "");

				ref = dbswdbe->tblwdbemmodule->insertNewRec(NULL, VecWdbeVMModuleBasetype::MNFCORE, mdl->hkIxVTbl, mdl->hkUref, mdl->hkNum+2, mdl->ref, Wdbe::getRefMtp(dbswdbe, "mmcm_xlnx_v5_4"), 0, 0, "mmcmMclk", "", "", "");
				Wdbe::setMpa(dbswdbe, ref, "div", divstr);
			};
		};

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
