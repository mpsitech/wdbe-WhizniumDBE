/**
	* \file WdbeMtpCplmsttdFsmtrack_Easy_v1_0.cpp
	* Wdbe operation processor - infer buffers (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 9 May 2023
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpCplmsttdFsmtrack_Easy_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmsttd;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmsttdFsmtrack_Easy_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmsttdFsmtrack_Easy_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmsttd* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WdbeMModule* mdl = NULL;
	uint mdlNum;

	WdbeMModule* submdl = NULL;

	string srefKVendor;

	ubigint refMtp;

	ubigint refHostif;
	string srefHostif;
	unsigned int wHostif;

	unsigned int sizeSeqbuf;

	string s;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		dbswdbe->executeQuery("UPDATE TblWdbeMModule SET hkNum = hkNum + 3 WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND hkNum > " + to_string(mdl->hkNum));

		srefKVendor = Wdbe::getUntVendor(dbswdbe, mdl->hkUref);

		refHostif = Wdbe::getHostifRef(dbswdbe, mdl->hkUref);
		srefHostif = Wdbe::getHostifSref(dbswdbe, mdl->hkUref);
		wHostif = Wdbe::getHostifWidth(dbswdbe, mdl->hkUref);

		sizeSeqbuf = 2;
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "sizeSeqbuf", s)) sizeSeqbuf = atoi(s.c_str());

		refMtp = 0;
		if (srefKVendor == "efnx") refMtp = Wdbe::getRefMtp(dbswdbe, "dpram_efnx_v1_0");
		else if (srefKVendor == "lttc") refMtp = Wdbe::getRefMtp(dbswdbe, "dpebram_lttc_v1_2");
		else if (srefKVendor == "xlnx") refMtp = Wdbe::getRefMtp(dbswdbe, "dpbram_xlnx_v8_4");

		if (refMtp != 0) {
			dbswdbe->tblwdbemmodule->insertNewRec(&submdl, VecWdbeVMModuleBasetype::IMBUF, mdl->hkIxVTbl, mdl->hkUref, mdl->hkNum + 1, mdl->ref, refMtp, 0, 0, "cntbuf", "", "", "");
			Wdbe::setMpa(dbswdbe, submdl->ref, "size", "2");
			Wdbe::setMpa(dbswdbe, submdl->ref, "wA", "32");
			Wdbe::setMpa(dbswdbe, submdl->ref, "wB", "32");

			dbswdbe->tblwdbermmodulemmodule->insertNewRec(NULL, submdl->ref, refHostif, "snk");

			submdl->refWdbeMImbuf = dbswdbe->tblwdbemimbuf->insertNewRec(NULL, VecWdbeVMImbufRotype::MULTATMT, submdl->ref, "cntbuf" + StrMod::cap(mdl->sref) + "To" + StrMod::cap(srefHostif), wHostif, "0..1024", 2);
			dbswdbe->tblwdbemmodule->updateRec(submdl);

			delete submdl;

			dbswdbe->tblwdbemmodule->insertNewRec(&submdl, VecWdbeVMModuleBasetype::IMBUF, mdl->hkIxVTbl, mdl->hkUref, mdl->hkNum + 2, mdl->ref, refMtp, 0, 0, "fstoccbuf", "", "", "");
			Wdbe::setMpa(dbswdbe, submdl->ref, "size", "2");
			Wdbe::setMpa(dbswdbe, submdl->ref, "wA", "32");
			Wdbe::setMpa(dbswdbe, submdl->ref, "wB", to_string(wHostif));

			dbswdbe->tblwdbermmodulemmodule->insertNewRec(NULL, submdl->ref, refHostif, "snk");

			submdl->refWdbeMImbuf = dbswdbe->tblwdbemimbuf->insertNewRec(NULL, VecWdbeVMImbufRotype::MULTATMT, submdl->ref, "fstoccbuf" + StrMod::cap(mdl->sref) + "To" + StrMod::cap(srefHostif), wHostif, "0..1024", 2);
			dbswdbe->tblwdbemmodule->updateRec(submdl);

			delete submdl;

			dbswdbe->tblwdbemmodule->insertNewRec(&submdl, VecWdbeVMModuleBasetype::IMBUF, mdl->hkIxVTbl, mdl->hkUref, mdl->hkNum + 3, mdl->ref, refMtp, 0, 0, "seqbuf", "", "", "");
			Wdbe::setMpa(dbswdbe, submdl->ref, "size", to_string(sizeSeqbuf));
			Wdbe::setMpa(dbswdbe, submdl->ref, "wA", "32");
			Wdbe::setMpa(dbswdbe, submdl->ref, "wB", to_string(wHostif));

			dbswdbe->tblwdbermmodulemmodule->insertNewRec(NULL, submdl->ref, refHostif, "snk");

			submdl->refWdbeMImbuf = dbswdbe->tblwdbemimbuf->insertNewRec(NULL, VecWdbeVMImbufRotype::MULTATMT, submdl->ref, "seqbuf" + StrMod::cap(mdl->sref) + "To" + StrMod::cap(srefHostif), wHostif, "0.." + to_string(1024 * sizeSeqbuf), 2);
			dbswdbe->tblwdbemmodule->updateRec(submdl);

			delete submdl;
		};

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
