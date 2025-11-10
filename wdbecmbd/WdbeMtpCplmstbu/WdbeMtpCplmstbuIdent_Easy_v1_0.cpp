/**
	* \file WdbeMtpCplmstbuIdent_Easy_v1_0.cpp
	* Wdbe operation processor - add configuration ports and signals (implementation)
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

#include "WdbeMtpCplmstbuIdent_Easy_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuIdent_Easy_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuIdent_Easy_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	ubigint ref;

	WdbeMModule* mdl = NULL;
	WdbeMController* ctr = NULL;

	uint refNum = 1; // ident.get() always present with opcode 0x00

	uint mdlNum = 1;
	string srefWdbeKHdltype;
	usmallint Width;

	uint cmdNum = 1;
	uint ixWdbeVPartype;

	string cfg; // ex. fMclk.nat.uint32;R.nat.uint8;xyz.32.uint32

	vector<string> ss, ss2;
	unsigned short wWord;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		if (dbswdbe->tblwdbemcontroller->loadRecByRef(mdl->refWdbeMController, &ctr)) {
			if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "cfg", cfg)) {
				StrMod::stringToVector(cfg, ss, ';');

				if (ss.size() > 0) {
					ref = dbswdbe->tblwdbemcommand->insertNewRec(NULL, VecWdbeVMCommandRefTbl::CTR, mdl->refWdbeMController, refNum++, "getCfg", "Cmd" + ctr->Fullsref.substr(3) + "GetCfg", VecWdbeVMCommandRettype::STATSNG, 0, 0, 0, "");

					// add generic and command return parameter per cfg generic
					for (unsigned int i = 0; i < ss.size(); i++) {
						StrMod::stringToVector(ss[i], ss2, '.');

						if (ss2.size() != 3) continue;

						ixWdbeVPartype = VecWdbeVPartype::getIx(ss2[2]);
						if ((ixWdbeVPartype != VecWdbeVPartype::UINT8) && (ixWdbeVPartype != VecWdbeVPartype::UINT16) && (ixWdbeVPartype != VecWdbeVPartype::UINT32)) continue;

						srefWdbeKHdltype = ss2[1];
						if (srefWdbeKHdltype == "nat") Width = 0;
						else {
							srefWdbeKHdltype = "slvdn";
							Width = atoi(ss2[1].c_str());
						};

						dbswdbe->tblwdbemgeneric->insertNewRec(NULL, 0, mdl->ref, mdlNum++, ss2[0], srefWdbeKHdltype, Width, "", "0", ss2[0], "");
						dbswdbe->tblwdbeamcommandretpar->insertNewRec(NULL, ref, cmdNum++, ss2[0], ixWdbeVPartype, 0, 0, "");
					};
				};
			};

			delete ctr;
		};

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
