/**
	* \file WdbeModdetUnt.cpp
	* Wdbe operation processor - fill standard vectors (implementation)
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

#include "WdbeModdetUnt.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeModdet;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeModdetUnt
 ******************************************************************************/

DpchRetWdbe* WdbeModdetUnt::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeModdetUnt* dpchinv
		) {
	ubigint refWdbeMUnit = dpchinv->refWdbeMUnit;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	vector<ubigint> refs;
	ubigint ref;

	WdbeMUnit* unt = NULL;

	ListWdbeMCommand cmds;
	WdbeMCommand* cmd = NULL;

	ListWdbeMError errs;
	WdbeMError* err = NULL;

	WdbeMModule* hostif = NULL;

	ListWdbeMImbuf imbs;
	WdbeMImbuf* imb = NULL;

	ListWdbeMController ctrs;
	WdbeMController* ctr = NULL;

	uint vecNum;

	if (dbswdbe->tblwdbemunit->loadRecByRef(refWdbeMUnit, &unt)) {
		// -- unit vectors

		// - fill command vector
		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMVector WHERE hkIxVTbl = " + to_string(VecWdbeVMVectorHkTbl::UNT) + " AND hkUref = " + to_string(refWdbeMUnit) + " AND sref = 'VecV" + unt->Fullsref.substr(3) + "Command'", ref)) {
			vecNum = 0;

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
		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMVector WHERE hkIxVTbl = " + to_string(VecWdbeVMVectorHkTbl::UNT) + " AND hkUref = " + to_string(refWdbeMUnit) + " AND sref = 'VecW" + unt->Fullsref.substr(3) + "Buffer'", ref)) {
			hostif = NULL;

			if (dbswdbe->tblwdbemmodule->loadRecBySQL("SELECT * FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND hkUref = " + to_string(refWdbeMUnit) + " AND ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::HOSTIF), &hostif)) {
				vecNum = 1;

			} else if (dbswdbe->tblwdbemmodule->loadRecBySQL("SELECT * FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND hkUref = " + to_string(refWdbeMUnit) + " AND ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::EHOSTIF), &hostif)) {
				dbswdbe->tblwdbemvectoritem->insertNewRec(NULL, ref, 1, "cmdretTo" + StrMod::cap(hostif->sref), "", "");
				dbswdbe->tblwdbemvectoritem->insertNewRec(NULL, ref, 2, hostif->sref + "ToCmdinv", "", "");

				vecNum = 4;
			};

			if (hostif) {
				dbswdbe->tblwdbemimbuf->loadRstBySQL("SELECT * FROM TblWdbeMImbuf WHERE corRefWdbeMModule = " + to_string(hostif->ref) + " ORDER BY Prio ASC, sref ASC", false, imbs);

				for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
					imb = imbs.nodes[i];

					dbswdbe->tblwdbemvectoritem->insertNewRec(NULL, ref, vecNum, imb->sref, "", "");
					vecNum *= 2;
				};

				delete hostif;
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
