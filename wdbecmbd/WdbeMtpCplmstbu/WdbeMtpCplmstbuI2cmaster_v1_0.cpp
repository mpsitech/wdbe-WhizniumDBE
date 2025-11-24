/**
	* \file WdbeMtpCplmstbuI2cmaster_v1_0.cpp
	* Wdbe operation processor - connect tri-state buffer primitive (implementation)
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

#include "WdbeMtpCplmstbuI2cmaster_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuI2cmaster_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuI2cmaster_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	ubigint refBb, refBibuf, refIobuf;

	ubigint refC;

	uint mdlNum = 1;

	bool threeNotInout;

	string s;

	Wdbe::getMpa(dbswdbe, refWdbeMModule, "threeNotInout", s);
	threeNotInout = (s == "true");

	if (threeNotInout) {
		dbswdbe->executeQuery("DELETE FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'scl'");
		dbswdbe->executeQuery("DELETE FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'sda'");

	} else {
		// - ports
		refC = 0; dbswdbe->loadRefBySQL("SELECT refWdbeCPort FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'scl_in'", refC);
		if (refC != 0) dbswdbe->executeQuery("DELETE FROM TblWdbeMPort WHERE refWdbeCPort = " + to_string(refC));

		refC = 0; dbswdbe->loadRefBySQL("SELECT refWdbeCPort FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'sda_in'", refC);
		if (refC != 0) dbswdbe->executeQuery("DELETE FROM TblWdbeMPort WHERE refWdbeCPort = " + to_string(refC));

		// - sub-module wiring
		for (unsigned int i = 0; i < 2; i++) {
			if (i == 0) s = "scl";
			else s = "sda";

			refBb = 0; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'bb" + StrMod::cap(s) + "'", refBb);
			refBibuf = 0; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'bibuf" + StrMod::cap(s) + "'", refBibuf);
			refIobuf = 0; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'iobuf" + StrMod::cap(s) + "'", refIobuf);

			if (refBb + refBibuf + refIobuf) dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, s + "_sig", false, "sl", 1, "", "", "", "0", 0, "");
			if (refBibuf) dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, refBibuf + refIobuf + refBb, 0, s + "n_sig", false, "sl", 1, "", "", "", "0", 0, "");
			if (refBb + refBibuf + refIobuf) dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, refBibuf + refIobuf + refBb, 0, s + "_in", false, "sl", 1, "", "", "", "0", 0, "");

			if (refBb != 0) {
				Wdbe::setPrtCsi(dbswdbe, refBb, "O", s + "_in");
				Wdbe::setPrtCpr(dbswdbe, refBb, "B", s);
				Wdbe::setPrtDfv(dbswdbe, refBb, "I", "0");
				Wdbe::setPrtCsi(dbswdbe, refBb, "T", s + "_sig");

			} else if (refBibuf != 0) {
				Wdbe::setPrtCsi(dbswdbe, refBibuf, "Y", s + "_in");
				Wdbe::setPrtCpr(dbswdbe, refBibuf, "PAD", s);
				Wdbe::setPrtDfv(dbswdbe, refBibuf, "D", "0");
				Wdbe::setPrtCsi(dbswdbe, refBibuf, "E", s + "n_sig");

			} else if (refIobuf != 0) {
				Wdbe::setPrtCsi(dbswdbe, refIobuf, "O", s + "_in");
				Wdbe::setPrtCpr(dbswdbe, refIobuf, "IO", s);
				Wdbe::setPrtDfv(dbswdbe, refIobuf, "I", "0");
				Wdbe::setPrtCsi(dbswdbe, refIobuf, "T", s + "_sig");
			};
		};
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
