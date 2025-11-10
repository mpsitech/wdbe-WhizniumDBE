/**
	* \file WdbeGenStdvec.cpp
	* Wdbe operation processor - fill standard vectors (implementation)
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

#include "WdbeGenStdvec.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeGen;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeGenStdvec
 ******************************************************************************/

DpchRetWdbe* WdbeGenStdvec::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeGenStdvec* dpchinv
		) {
	ubigint refWdbeMUnit = dpchinv->refWdbeMUnit;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	vector<ubigint> refs;
	ubigint ref, ref2;

	WdbeMUnit* unt = NULL;

	ListWdbeMCommand cmds;
	WdbeMCommand* cmd = NULL;

	ListWdbeAMCommandInvpar ipas;
	WdbeAMCommandInvpar* ipa = NULL;

	ListWdbeAMCommandRetpar rpas;
	WdbeAMCommandRetpar* rpa = NULL;

	ListWdbeMError errs;
	WdbeMError* err = NULL;

	WdbeMModule* hostif = NULL;

	string sref, srefrootMgmt, srefrootCor;

	ListWdbeMController ctrs;
	WdbeMController* ctr = NULL;

	uint vecNum, vecNum2;

	if (dbswdbe->tblwdbemunit->loadRecByRef(refWdbeMUnit, &unt)) {
		// -- unit vectors

		// - fill command vector
		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMVector WHERE hkIxVTbl = " + to_string(VecWdbeVMVectorHkTbl::UNT) + " AND hkUref = " + to_string(refWdbeMUnit) + " AND sref = 'VecV" + unt->Fullsref.substr(3) + "Command'", ref)) {
			dbswdbe->tblwdbemcommand->loadRstByRetReu(VecWdbeVMCommandRefTbl::UNT, refWdbeMUnit, false, cmds);
			for (unsigned int j = 0; j < cmds.nodes.size(); j++) {
				cmd = cmds.nodes[j];
				dbswdbe->tblwdbemvectoritem->insertNewRec(NULL, ref, cmd->refNum, cmd->sref, "", "");
			};
		};

		dbswdbe->tblwdbemerror->loadRstByRetReu(VecWdbeVMErrorRefTbl::UNT, unt->ref, false, errs);
		if (errs.nodes.size() > 0) {
			// - create and fill error vector
			ref = dbswdbe->tblwdbemvector->insertNewRec(NULL, VecWdbeVMVectorBasetype::TIXLIN, VecWdbeVMVectorHkTbl::UNT, unt->ref, "VecV" + unt->Fullsref.substr(3) + "Error", "");

			vecNum = 0;

			for (unsigned int i = 0; i < errs.nodes.size(); i++) {
				err = errs.nodes[i];
				dbswdbe->tblwdbemvectoritem->insertNewRec(NULL, ref, err->refNum, err->sref, err->Comment, "");
			};
		};

		// - fill buffer vector
		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMVector WHERE hkIxVTbl = " + to_string(VecWdbeVMVectorHkTbl::UNT) + " AND hkUref = " + to_string(refWdbeMUnit) + " AND sref = 'VecV" + unt->Fullsref.substr(3) + "Buffer'", ref)) {
			hostif = NULL;

			if (dbswdbe->tblwdbemmodule->loadRecBySQL("SELECT * FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND hkUref = " + to_string(refWdbeMUnit) + " AND ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::HOSTIF), &hostif)) {
				vecNum = 0;

			} else if (dbswdbe->tblwdbemmodule->loadRecBySQL("SELECT * FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND hkUref = " + to_string(refWdbeMUnit) + " AND ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::EHOSTIF), &hostif)) {
				dbswdbe->tblwdbemvectoritem->insertNewRec(NULL, ref, 0, "cmdretTo" + StrMod::cap(hostif->sref), "", "");
				dbswdbe->tblwdbemvectoritem->insertNewRec(NULL, ref, 1, hostif->sref + "ToCmdinv", "", "");

				vecNum = 2;
			};

			if (hostif) {
				dbswdbe->loadRefsBySQL("SELECT TblWdbeMImbuf.refWdbeMModule FROM TblWdbeMImbuf, TblWdbeMModule, TblWdbeRMModuleMModule WHERE TblWdbeMImbuf.refWdbeMModule = TblWdbeMModule.ref AND TblWdbeMModule.ref = TblWdbeRMModuleMModule.ctdRefWdbeMModule AND TblWdbeRMModuleMModule.corRefWdbeMModule = "
							+ to_string(hostif->ref) + " ORDER BY TblWdbeMImbuf.Prio ASC, TblWdbeMModule.sref ASC", false, refs);

				for (unsigned int i = 0; i < refs.size(); i++) {
					Wdbe::getImbsrefs(dbswdbe, refs[i], sref, srefrootMgmt, srefrootCor);
					dbswdbe->tblwdbemvectoritem->insertNewRec(NULL, ref, vecNum++, sref, "", "");
				};
			};
		};

		// -- controller vectors
		dbswdbe->loadRefsBySQL("SELECT refWdbeMController FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND hkUref = " + to_string(refWdbeMUnit) + " AND refWdbeMController <> 0", false, refs);
		dbswdbe->tblwdbemcontroller->loadRstByRefs(refs, false, ctrs);

		for (unsigned int i = 0; i < ctrs.nodes.size(); i++) {
			ctr = ctrs.nodes[i];

			// - fill command vector
			if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMVector WHERE hkIxVTbl = " + to_string(VecWdbeVMVectorHkTbl::CTR) + " AND hkUref = " + to_string(ctr->ref) + " AND sref = 'VecV" + ctr->Fullsref.substr(3) + "Command'", ref)) {
				vecNum = 0;

				dbswdbe->tblwdbemcommand->loadRstByRetReu(VecWdbeVMCommandRefTbl::CTR, ctr->ref, false, cmds);
				for (unsigned int j = 0; j < cmds.nodes.size(); j++) {
					cmd = cmds.nodes[j];
					dbswdbe->tblwdbemvectoritem->insertNewRec(NULL, ref, cmd->refNum, cmd->sref, "", "");

					// create and fill invocation parameter vector
					dbswdbe->tblwdbeamcommandinvpar->loadRstByCmd(cmd->ref, false, ipas);
					if (ipas.nodes.size() > 0) {
						ref2 = dbswdbe->tblwdbemvector->insertNewRec(NULL, VecWdbeVMVectorBasetype::IXLIN, VecWdbeVMVectorHkTbl::CMD, cmd->ref, "VecV" + cmd->Fullsref.substr(3) + "Invpar", "noloc;notit;filfed");

						vecNum2 = 0;
						for (unsigned int k = 0; k < ipas.nodes.size(); k++) {
							ipa = ipas.nodes[k];

							dbswdbe->tblwdbemvectoritem->insertNewRec(NULL, ref2, vecNum2, ipa->sref, "", "");
							vecNum2 += Wdbe::getParlen(ipa->ixWdbeVPartype, ipa->Length);
						};
					};

					// create and fill return parameter vector
					dbswdbe->tblwdbeamcommandretpar->loadRstByCmd(cmd->ref, false, rpas);
					if (rpas.nodes.size() > 0) {
						ref2 = dbswdbe->tblwdbemvector->insertNewRec(NULL, VecWdbeVMVectorBasetype::IXLIN, VecWdbeVMVectorHkTbl::CMD, cmd->ref, "VecV" + cmd->Fullsref.substr(3) + "Retpar", "noloc;notit;filfed");

						vecNum2 = 0;
						for (unsigned int k = 0; k < rpas.nodes.size(); k++) {
							rpa = rpas.nodes[k];

							dbswdbe->tblwdbemvectoritem->insertNewRec(NULL, ref2, vecNum2, rpa->sref, "", "");
							vecNum2 += Wdbe::getParlen(rpa->ixWdbeVPartype, rpa->Length);
						};
					};
				};
			};

			dbswdbe->tblwdbemerror->loadRstByRetReu(VecWdbeVMErrorRefTbl::CTR, ctr->ref, false, errs);
			if (errs.nodes.size() > 0) {
				// - create and fill error vector
				ref = dbswdbe->tblwdbemvector->insertNewRec(NULL, VecWdbeVMVectorBasetype::TIXLIN, VecWdbeVMVectorHkTbl::CTR, ctr->ref, "VecV" + ctr->Fullsref.substr(3) + "Error", "");

				vecNum = 0;

				for (unsigned int i = 0; i < errs.nodes.size(); i++) {
					err = errs.nodes[i];
					dbswdbe->tblwdbemvectoritem->insertNewRec(NULL, ref, err->refNum, err->sref, err->Comment, "");
				};
			};
		};

		delete unt;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
