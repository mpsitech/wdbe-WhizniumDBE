/**
	* \file WdbeModbscUnt.cpp
	* Wdbe operation processor - add standard vectors (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeModbscUnt.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeModbsc;

/******************************************************************************
 namespace WdbeModbscUnt
 ******************************************************************************/

DpchRetWdbe* WdbeModbscUnt::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeModbscUnt* dpchinv
		) {
	ubigint refWdbeMUnit = dpchinv->refWdbeMUnit;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	ubigint ref;

	WdbeMUnit* unt = NULL;

	ListWdbeMPeripheral pphs;
	WdbeMPeripheral* pph = NULL;

	ListWdbeMPeripheral pph2s;
	WdbeMPeripheral* pph2 = NULL;

	map<ubigint,ubigint> refsPphs; // (unit peripheral ref) by silicon device peripheral ref

	ListWdbeMBank bnks;
	WdbeMBank* bnk = NULL;

	ListWdbeMPin pins;
	WdbeMPin* pin = NULL;

	ListWdbeJMPinSref pinJsrfs;
	WdbeJMPinSref* pinJsrf = NULL;

	ListWdbeMModule mdls;
	WdbeMModule* mdl = NULL;

	bool hashostif, hasehostif, hascmdinv, hasctr;

	uint vecNum;

	if (dbswdbe->tblwdbemunit->loadRecByRef(refWdbeMUnit, &unt)) {
		if (unt->silRefWdbeMUnit != 0) {
			// --- copy banks and pins with optional peripheral sref override
			dbswdbe->tblwdbemperipheral->loadRstByUnt(unt->ref, false, pphs);
			dbswdbe->tblwdbemperipheral->loadRstByUnt(unt->silRefWdbeMUnit, false, pph2s);

			for (unsigned int i = 0; i < pphs.nodes.size(); i++) {
				pph = pphs.nodes[i];

				for (unsigned int j = 0; j < pph2s.nodes.size(); j++) {
					pph2 = pph2s.nodes[j];

					if (pph->sref == pph2->sref) {
						refsPphs[pph2->ref] = pph->ref;
						break;
					};
				};
			};

			dbswdbe->tblwdbembank->loadRstByUnt(unt->silRefWdbeMUnit, false, bnks);
			for (unsigned int i = 0; i < bnks.nodes.size(); i++) {
				bnk = bnks.nodes[i];

				dbswdbe->tblwdbempin->loadRstByBnk(bnk->ref, false, pins);

				bnk->ref = 0;
				bnk->refWdbeMUnit = unt->ref;

				dbswdbe->tblwdbembank->insertRec(bnk);

				for (unsigned int j = 0; j < pins.nodes.size(); j++) {
					pin = pins.nodes[j];

					dbswdbe->tblwdbejmpinsref->loadRstByPin(pin->ref, false, pinJsrfs);

					pin->ref = 0;
					pin->refWdbeMBank = bnk->ref;

					dbswdbe->tblwdbempin->insertRec(pin);

					ref = pin->refJSref;
					pin->refJSref = 0;

					for (unsigned int k = 0; k < pinJsrfs.nodes.size(); k++) {
						pinJsrf = pinJsrfs.nodes[k];

						auto it = refsPphs.find(pinJsrf->x1RefWdbeMPeripheral);

						if (it != refsPphs.end()) {
							pinJsrf->ref = 0;
							pinJsrf->refWdbeMPin = pin->ref;
							pinJsrf->x1RefWdbeMPeripheral = it->second;

							dbswdbe->tblwdbejmpinsref->insertRec(pinJsrf);

							pin->refJSref = pinJsrf->ref;
							pin->sref = pinJsrf->sref;

						} else if ((pinJsrf->ref == ref) || (pinJsrf->x1RefWdbeMPeripheral == 0)) {
							pinJsrf->ref = 0;
							pinJsrf->refWdbeMPin = pin->ref;
							pinJsrf->x1RefWdbeMPeripheral = 0;

							dbswdbe->tblwdbejmpinsref->insertRec(pinJsrf);

							if ((pinJsrf->ref == ref) && (pin->refJSref == 0)) {
								pin->refJSref = pinJsrf->ref;
								pin->sref = pinJsrf->sref;
							};
						};
					};

					dbswdbe->tblwdbempin->updateRec(pin);
				};
			};
		};

		// --- add standard vectors
		dbswdbe->tblwdbemmodule->loadRstBySQL("SELECT * FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND hkUref = " + to_string(refWdbeMUnit) + " ORDER BY hkNum ASC", false, mdls);

		hashostif = false;
		hasehostif = false;
		hascmdinv = false;
		hasctr = false;

		for (unsigned int i = 0; i < mdls.nodes.size(); i++) {
			mdl = mdls.nodes[i];

			if (mdl->ixVBasetype == VecWdbeVMModuleBasetype::HOSTIF) hashostif = true;
			else if (mdl->ixVBasetype == VecWdbeVMModuleBasetype::EHOSTIF) hasehostif = true;
			else if (mdl->ixVBasetype == VecWdbeVMModuleBasetype::CMDINV) hascmdinv = true;
			else if ((mdl->ixVBasetype == VecWdbeVMModuleBasetype::CTR) || (mdl->ixVBasetype == VecWdbeVMModuleBasetype::FWDCTR) || (mdl->ixVBasetype == VecWdbeVMModuleBasetype::ECTR)) hasctr = true;

			if (((hashostif && hascmdinv) || hasehostif) && hasctr) break;
		};

		// - buffer vector if hostif is present: fill in ModdetUnt
		if (hashostif || hasehostif) dbswdbe->tblwdbemvector->insertNewRec(NULL, VecWdbeVMVectorBasetype::TIXOR, VecWdbeVMVectorHkTbl::UNT, unt->ref, "VecW" + unt->Fullsref.substr(3) + "Buffer", "notit;filfed");

		if (hashostif && hascmdinv && hasctr) {
			// - full model: controller vector if cmdinv and controllers are present
			ref = dbswdbe->tblwdbemvector->insertNewRec(NULL, VecWdbeVMVectorBasetype::TIXLIN, VecWdbeVMVectorHkTbl::UNT, unt->ref, "VecV" + unt->Fullsref.substr(3) + "Controller", "notit;filfed");

			vecNum = 3;

			for (unsigned int i = 0; i < mdls.nodes.size(); i++) {
				mdl = mdls.nodes[i];

				if (mdl->ixVBasetype == VecWdbeVMModuleBasetype::CMDINV) {
					dbswdbe->tblwdbemvectoritem->insertNewRec(NULL, ref, 1, mdl->sref, "", "");
				} else if (mdl->ixVBasetype == VecWdbeVMModuleBasetype::CMDRET) {
					dbswdbe->tblwdbemvectoritem->insertNewRec(NULL, ref, 2, mdl->sref, "", "");
				} else if ((mdl->ixVBasetype == VecWdbeVMModuleBasetype::CTR) || (mdl->ixVBasetype == VecWdbeVMModuleBasetype::FWDCTR)) {
					dbswdbe->tblwdbemvectoritem->insertNewRec(NULL, ref, vecNum++, mdl->sref, "", "");
				};
			};

		} else if (hasehostif && hasctr) {
			// - easy model: controller vector if controllers are present
			ref = dbswdbe->tblwdbemvector->insertNewRec(NULL, VecWdbeVMVectorBasetype::TIXLIN, VecWdbeVMVectorHkTbl::UNT, unt->ref, "VecV" + unt->Fullsref.substr(3) + "Controller", "notit;filfed");

			vecNum = 1;

			for (unsigned int i = 0; i < mdls.nodes.size(); i++) {
				mdl = mdls.nodes[i];

				if (mdl->ixVBasetype == VecWdbeVMModuleBasetype::ECTR) {
					dbswdbe->tblwdbemvectoritem->insertNewRec(NULL, ref, vecNum++, mdl->sref, "", "");
				};
			};

		} else {
			// - unit-based command vector if no controllers are present: fill in ModdetUnt
			dbswdbe->tblwdbemvector->insertNewRec(NULL, VecWdbeVMVectorBasetype::TIXLIN, VecWdbeVMVectorHkTbl::UNT, unt->ref, "VecV" + unt->Fullsref.substr(3) + "Command", "notit;filfed");
		};

		delete unt;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT


