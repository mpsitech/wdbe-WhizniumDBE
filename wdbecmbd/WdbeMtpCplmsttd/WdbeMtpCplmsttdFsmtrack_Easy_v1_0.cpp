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
	ubigint ref;

	WdbeMModule* mdl = NULL;

	WdbeMModule* submdl = NULL;

	ubigint refHostif;
	string srefHostif;
	unsigned int wHostif;

	const unsigned int sizeCntbuf = 1;
	const unsigned int sizeFstoccbuf = 1;
	unsigned int sizeSeqbuf = 4;

	string s;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		refHostif = Wdbe::getHostifRef(dbswdbe, mdl->hkUref);
		srefHostif = Wdbe::getHostifSref(dbswdbe, mdl->hkUref);
		wHostif = Wdbe::getHostifWidth(dbswdbe, mdl->hkUref);

		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "sizeSeqbuf", s)) sizeSeqbuf = atoi(s.c_str());

		if (dbswdbe->tblwdbemmodule->loadRecBySQL("SELECT * FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'cntbuf'", &submdl)) {
			dbswdbe->tblwdbermmodulemmodule->insertNewRec(NULL, submdl->ref, refHostif, "snk");

			submdl->refWdbeMImbuf = dbswdbe->tblwdbemimbuf->insertNewRec(NULL, VecWdbeVMImbufRotype::MULTATMT, submdl->ref, "cntbuf" + StrMod::cap(mdl->sref) + "To" + StrMod::cap(srefHostif), wHostif, "0..1024", 2);
			dbswdbe->tblwdbemmodule->updateRec(submdl);

			delete submdl;
		};

		if (dbswdbe->tblwdbemmodule->loadRecBySQL("SELECT * FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'fstoccbuf'", &submdl)) {
			Wdbe::setMpa(dbswdbe, submdl->ref, "wB", to_string(wHostif));

			dbswdbe->tblwdbermmodulemmodule->insertNewRec(NULL, submdl->ref, refHostif, "snk");

			submdl->refWdbeMImbuf = dbswdbe->tblwdbemimbuf->insertNewRec(NULL, VecWdbeVMImbufRotype::MULTATMT, submdl->ref, "fstoccbuf" + StrMod::cap(mdl->sref) + "To" + StrMod::cap(srefHostif), wHostif, "0..1024", 2);
			dbswdbe->tblwdbemmodule->updateRec(submdl);

			delete submdl;
		};

		if (dbswdbe->tblwdbemmodule->loadRecBySQL("SELECT * FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'seqbuf'", &submdl)) {
			Wdbe::setMpa(dbswdbe, submdl->ref, "size", to_string(sizeSeqbuf));
			Wdbe::setMpa(dbswdbe, submdl->ref, "wB", to_string(wHostif));

			dbswdbe->tblwdbermmodulemmodule->insertNewRec(NULL, submdl->ref, refHostif, "snk");

			submdl->refWdbeMImbuf = dbswdbe->tblwdbemimbuf->insertNewRec(NULL, VecWdbeVMImbufRotype::MULTATMT, submdl->ref, "seqbuf" + StrMod::cap(mdl->sref) + "To" + StrMod::cap(srefHostif), wHostif, "0.." + to_string(sizeSeqbuf*1024), 2);
			dbswdbe->tblwdbemmodule->updateRec(submdl);

			delete submdl;
		};

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
