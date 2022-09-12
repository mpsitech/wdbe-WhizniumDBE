/**
	* \file WdbeMtpCplmsttdI2c_Easy_v1_0.cpp
	* Wdbe operation processor - infer tri-state buffer primitive (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 7 Jun 2022
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpCplmsttdI2c_Easy_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmsttd;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmsttdI2c_Easy_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmsttdI2c_Easy_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmsttd* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	ubigint ref;

	WdbeMModule* mdl = NULL;
	uint mdlNum;

	ubigint refMtp = 0;

	ubigint refPrcOp;

	string srefWdbeKVendor;


	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		mdlNum = 1;

		refPrcOp = dbswdbe->tblwdbemprocess->insertNewRec(NULL, mdl->ref, 0, "op", "mclk", "reset", true, "", false, "main operation");

		dbswdbe->loadStringBySQL("SELECT TblWdbeMFamily.srefWdbeKVendor FROM TblWdbeMFamily, TblWdbeMUnit AS unt1, TblWdbeMUnit AS unt2 WHERE TblWdbeMFamily.ref = unt2.refUref AND unt2.ref = unt1.silRefWdbeMUnit AND unt1.ref = "
					+ to_string(mdl->hkUref), srefWdbeKVendor);

		if (srefWdbeKVendor == "lttc") Wdbe::getRefMtp(dbswdbe, "BB");
		else if (srefWdbeKVendor == "mchp") Wdbe::getRefMtp(dbswdbe, "BIBUF");
		else if (srefWdbeKVendor == "xlnx") Wdbe::getRefMtp(dbswdbe, "IOBUF");

		if (refMtp != 0) {
			dbswdbe->executeQuery("UPDATE TblWdbeMModule SET hkNum = hkNum + 1 WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND hkNum > " + to_string(mdl->hkNum));
			ref = dbswdbe->tblwdbemmodule->insertNewRec(NULL, VecWdbeVMModuleBasetype::MNFCORE, mdl->hkIxVTbl, mdl->hkUref, mdl->hkNum+1, mdl->ref, refMtp, 0, 0, "iobufSda", "", "", "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "sda_sig", false, "sl", 1, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "sda_in", false, "sl", 1, "", "", "", "0", false, 0, "");

			if (srefWdbeKVendor == "lttc") {
				Wdbe::setPrtCsi(dbswdbe, ref, "O", "sda_in");
				Wdbe::setPrtCpr(dbswdbe, ref, "B", "sda");
				Wdbe::setPrtDfv(dbswdbe, ref, "I", "0");
				Wdbe::setPrtCsi(dbswdbe, ref, "T", "sda_sig");

			} else if (srefWdbeKVendor == "mchp") {
				Wdbe::setPrtCsi(dbswdbe, ref, "Y", "sda_in");
				Wdbe::setPrtCpr(dbswdbe, ref, "PAD", "sda");
				Wdbe::setPrtDfv(dbswdbe, ref, "D", "0");
				Wdbe::setPrtCsi(dbswdbe, ref, "E", "sda_sig");

			} else if (srefWdbeKVendor == "xlnx") {
				Wdbe::setPrtCsi(dbswdbe, ref, "O", "sda_in");
				Wdbe::setPrtCpr(dbswdbe, ref, "IO", "sda");
				Wdbe::setPrtDfv(dbswdbe, ref, "I", "0");
				Wdbe::setPrtCsi(dbswdbe, ref, "T", "sda_sig");
			};
		};

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
