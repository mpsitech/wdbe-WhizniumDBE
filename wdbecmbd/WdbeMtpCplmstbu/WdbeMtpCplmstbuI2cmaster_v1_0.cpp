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

	uint mdlNum = 1;

	refBb = 0; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'bbSda'", refBb);
	refBibuf = 0; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'bibufSda'", refBibuf);
	refIobuf = 0; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'iobufSda'", refIobuf);

	dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "sda_sig", false, "sl", 1, "", "", "", "0", false, 0, "");
	if (refBibuf) dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, refBibuf + refIobuf + refBb, 0, "sdan_sig", false, "sl", 1, "", "", "", "0", false, 0, "");
	if (refBb + refBibuf + refIobuf) dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, refBibuf + refIobuf + refBb, 0, "sda_in", false, "sl", 1, "", "", "", "0", false, 0, "");

	if (refBb != 0) {
		Wdbe::setPrtCsi(dbswdbe, refBb, "O", "sda_in");
		Wdbe::setPrtCpr(dbswdbe, refBb, "B", "sda");
		Wdbe::setPrtDfv(dbswdbe, refBb, "I", "0");
		Wdbe::setPrtCsi(dbswdbe, refBb, "T", "sda_sig");

	} else if (refBibuf != 0) {
		Wdbe::setPrtCsi(dbswdbe, refBibuf, "Y", "sda_in");
		Wdbe::setPrtCpr(dbswdbe, refBibuf, "PAD", "sda");
		Wdbe::setPrtDfv(dbswdbe, refBibuf, "D", "0");
		Wdbe::setPrtCsi(dbswdbe, refBibuf, "E", "sdan_sig");

	} else if (refIobuf != 0) {
		Wdbe::setPrtCsi(dbswdbe, refIobuf, "O", "sda_in");
		Wdbe::setPrtCpr(dbswdbe, refIobuf, "IO", "sda");
		Wdbe::setPrtDfv(dbswdbe, refIobuf, "I", "0");
		Wdbe::setPrtCsi(dbswdbe, refIobuf, "T", "sda_sig");
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
