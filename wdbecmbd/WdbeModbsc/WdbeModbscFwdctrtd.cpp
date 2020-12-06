/**
	* \file WdbeModbscFwdctrtd.cpp
	* Wdbe operation processor - add read and write buffers and commands (implementation)
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

#include "WdbeModbscFwdctrtd.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeModbsc;

/******************************************************************************
 namespace WdbeModbscFwdctrtd
 ******************************************************************************/

DpchRetWdbe* WdbeModbscFwdctrtd::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeModbscFwdctrtd* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	ubigint ref;

	WdbeMModule* mdl = NULL;
	WdbeMController* ctr = NULL;
	WdbeMModule* hostif = NULL;
	WdbeMModule* submdl = NULL;

	WdbeMUnit* unt = NULL;

	ubigint refUntbufvec;
	ubigint refUnthostif, refUntcmdinv, refUntcmdret;

	uint cnt;
	bool hasrdbuf, haswrbuf;

	uint refNum = 1;

	string size;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		if (dbswdbe->tblwdbemcontroller->loadRecByRef(mdl->refWdbeMController, &ctr)) {
			// command vector: fill in ModdetUnt
			dbswdbe->tblwdbemvector->insertNewRec(NULL, VecWdbeVMVectorBasetype::TIXLIN, VecWdbeVMVectorHkTbl::CTR, ctr->ref, "VecV" + ctr->Fullsref.substr(3) + "Command", "notit;filfed");

			// add reset command
			dbswdbe->tblwdbemcommand->insertNewRec(NULL, VecWdbeVMCommandRefTbl::CTR, mdl->refWdbeMController, refNum++, "reset", "Cmd" + ctr->Fullsref.substr(3) + "Reset", VecWdbeVMCommandRettype::VOID, 0, 0, 0, "");

			if (dbswdbe->tblwdbemmodule->loadRecBySQL("SELECT * FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::HOSTIF), &hostif)) {

				if (dbswdbe->tblwdbemunit->loadRecByRef(ctr->fwdRefWdbeMUnit, &unt)) {

					if (unt->ixVBasetype == VecWdbeVMUnitBasetype::FPGA) {
						dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMVector WHERE hkIxVTbl = " + to_string(VecWdbeVMVectorHkTbl::UNT) + " AND hkUref = " + to_string(unt->ref) + " AND sref = 'VecW" + unt->Fullsref.substr(3) + "Buffer'", refUntbufvec);

						dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND hkUref = " + to_string(unt->ref) + " AND ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::HOSTIF), refUnthostif);
						dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND hkUref = " + to_string(unt->ref) + " AND ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::CMDINV), refUntcmdinv);
						dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND hkUref = " + to_string(unt->ref) + " AND ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::CMDRET), refUntcmdret);

						dbswdbe->loadUintBySQL("SELECT COUNT(ref) FROM TblWdbeMImbuf WHERE corRefWdbeMModule = " + to_string(refUnthostif) + " AND ixVDir = " + to_string(VecWdbeVMImbufDir::OUT) + " AND refWdbeMModule <> " + to_string(refUntcmdret), cnt);
						hasrdbuf = (cnt > 0);

						dbswdbe->loadUintBySQL("SELECT COUNT(ref) FROM TblWdbeMImbuf WHERE corRefWdbeMModule = " + to_string(refUnthostif) + " AND ixVDir = " + to_string(VecWdbeVMImbufDir::IN) + " AND refWdbeMModule <> " + to_string(refUntcmdinv), cnt);
						haswrbuf = (cnt > 0);

						if (hasrdbuf) {
							dbswdbe->executeQuery("UPDATE TblWdbeMModule SET hkNum = hkNum + 1 WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND hkNum > " + to_string(mdl->hkNum));

							dbswdbe->tblwdbemmodule->insertNewRec(&submdl, VecWdbeVMModuleBasetype::IMBUF, mdl->hkIxVTbl, mdl->hkUref, mdl->hkNum+1, mdl->ref, Wdbe::getRefMtp(dbswdbe, "dpbram_v1_0"), 0, 0, "rdbuf", "");
				
							submdl->refWdbeMImbuf = dbswdbe->tblwdbemimbuf->insertNewRec(NULL, submdl->ref, hostif->ref, mdl->sref + "To" + StrMod::cap(hostif->sref), VecWdbeVMImbufDir::OUT, 1);
							dbswdbe->tblwdbemmodule->updateRec(submdl);

							if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "sizeRdbuf", size)) Wdbe::setMpa(dbswdbe, submdl->ref, "size", size);
							Wdbe::setMpa(dbswdbe, submdl->ref, "dir", "atob");
				
							delete submdl;

							// add read command
							ref = dbswdbe->tblwdbemcommand->insertNewRec(NULL, VecWdbeVMCommandRefTbl::CTR, mdl->refWdbeMController, refNum++, "read", "Cmd" + ctr->Fullsref.substr(3) + "Read", VecWdbeVMCommandRettype::DFRSNG, 0, 0, 0, "");
							
							dbswdbe->tblwdbeamcommandinvpar->insertNewRec(NULL, ref, 1, "tixW" + StrMod::cap(unt->sref) + "Buffer", VecWdbeVPartype::TIX, refUntbufvec, 0, "");
							dbswdbe->tblwdbeamcommandinvpar->insertNewRec(NULL, ref, 2, "reqLen", VecWdbeVPartype::UINT, 0, 0, "");
						};

						if (haswrbuf) {
							dbswdbe->executeQuery("UPDATE TblWdbeMModule SET hkNum = hkNum + 1 WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND hkNum > " + to_string(mdl->hkNum));

							dbswdbe->tblwdbemmodule->insertNewRec(&submdl, VecWdbeVMModuleBasetype::IMBUF, mdl->hkIxVTbl, mdl->hkUref, mdl->hkNum+1, mdl->ref, Wdbe::getRefMtp(dbswdbe, "dpbram_v1_0"), 0, 0, "wrbuf", "");
				
							submdl->refWdbeMImbuf = dbswdbe->tblwdbemimbuf->insertNewRec(NULL, submdl->ref, hostif->ref, hostif->sref + "To" + StrMod::cap(mdl->sref), VecWdbeVMImbufDir::IN, 1);
							dbswdbe->tblwdbemmodule->updateRec(submdl);

							if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "sizeWrbuf", size)) Wdbe::setMpa(dbswdbe, submdl->ref, "size", size);
							Wdbe::setMpa(dbswdbe, submdl->ref, "dir", "btoa");
				
							delete submdl;

							// add write command
							ref = dbswdbe->tblwdbemcommand->insertNewRec(NULL, VecWdbeVMCommandRefTbl::CTR, mdl->refWdbeMController, refNum++, "write", "Cmd" + ctr->Fullsref.substr(3) + "Write", VecWdbeVMCommandRettype::DFRSNG, 0, 0, 0, "");
							
							dbswdbe->tblwdbeamcommandinvpar->insertNewRec(NULL, ref, 1, "tixW" + StrMod::cap(unt->sref) + "Buffer", VecWdbeVPartype::TIX, refUntbufvec, 0, "");
							dbswdbe->tblwdbeamcommandinvpar->insertNewRec(NULL, ref, 2, "reqLen", VecWdbeVPartype::UINT, 0, 0, "");
						};

						if (hasrdbuf || haswrbuf) {
							// add buffer transfer error
							dbswdbe->tblwdbemerror->insertNewRec(NULL, VecWdbeVMErrorRefTbl::CTR, ctr->ref, 0, "bufxfer", "Err" + ctr->Fullsref.substr(3) + "Bufxfer", 0, "buffer transfer error");
						};
					};

					delete unt;
				};

				delete hostif;
			};
			
			delete ctr;
		};

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
