/**
	* \file WdbeMtpCplmsttdGpio_Easy_v1_0.cpp
	* Wdbe operation processor - infer tri-state buffer primitives (implementation)
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

#include "WdbeMtpCplmsttdGpio_Easy_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmsttd;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmsttdGpio_Easy_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmsttdGpio_Easy_v1_0::run(
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

	string s;
	unsigned int w = 32;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		mdlNum = 1;

		if (Wdbe::getGenDfv(dbswdbe, refWdbeMModule, "w", s)) w = atoi(s.c_str());

		refPrcOp = dbswdbe->tblwdbemprocess->insertNewRec(NULL, mdl->ref, 0, "op", "mclk", "reset", true, "", false, "main operation");

		dbswdbe->loadStringBySQL("SELECT TblWdbeMFamily.srefWdbeKVendor FROM TblWdbeMFamily, TblWdbeMUnit AS unt1, TblWdbeMUnit AS unt2 WHERE TblWdbeMFamily.ref = unt2.refUref AND unt2.ref = unt1.silRefWdbeMUnit AND unt1.ref = "
					+ to_string(mdl->hkUref), srefWdbeKVendor);

		if (srefWdbeKVendor == "lttc") Wdbe::getRefMtp(dbswdbe, "BB");
		else if (srefWdbeKVendor == "mchp") Wdbe::getRefMtp(dbswdbe, "BIBUF");
		else if (srefWdbeKVendor == "xlnx") Wdbe::getRefMtp(dbswdbe, "IOBUF");

		if (refMtp != 0) {
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "trimask", false, "slvdn", 32, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "inbits", false, "slvdn", 32, "", "", "", "0", false, 0, "");
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, "outbits", false, "slvdn", 32, "", "", "", "0", false, 0, "");

			dbswdbe->executeQuery("UPDATE TblWdbeMModule SET hkNum = hkNum + 32 WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND hkNum > " + to_string(mdl->hkNum));
			for (unsigned int i = 0; i < w; i++) {
				ref = dbswdbe->tblwdbemmodule->insertNewRec(NULL, VecWdbeVMModuleBasetype::MNFCORE, mdl->hkIxVTbl, mdl->hkUref, mdl->hkNum+1+i, mdl->ref, refMtp, 0, 0, "iobuf" + to_string(i), "", "", "");

				if (srefWdbeKVendor == "lttc") {
					Wdbe::setPrtCsi(dbswdbe, ref, "O", "iobits[" + to_string(i) + "]");
					Wdbe::setPrtCsi(dbswdbe, ref, "I", "outbits[" + to_string(i) + "]");
					Wdbe::setPrtCsi(dbswdbe, ref, "T", "trimask[" + to_string(i) + "]");

				} else if (srefWdbeKVendor == "mchp") {
					Wdbe::setPrtCsi(dbswdbe, ref, "Y", "iobits[" + to_string(i) + "]");
					Wdbe::setPrtCsi(dbswdbe, ref, "D", "outbits[" + to_string(i) + "]");
					Wdbe::setPrtCsi(dbswdbe, ref, "E", "trimask[" + to_string(i) + "]");

				} else if (srefWdbeKVendor == "xlnx") {
					Wdbe::setPrtCsi(dbswdbe, ref, "O", "iobits[" + to_string(i) + "]");
					Wdbe::setPrtCsi(dbswdbe, ref, "I", "outbits[" + to_string(i) + "]");
					Wdbe::setPrtCsi(dbswdbe, ref, "T", "trimask[" + to_string(i) + "]");
				};

				if (i < w) {
					if (srefWdbeKVendor == "lttc") Wdbe::setPrtCpr(dbswdbe, ref, "B", "io[" + to_string(i) + "]");
					else if (srefWdbeKVendor == "mchp") Wdbe::setPrtCpr(dbswdbe, ref, "PAD", "io[" + to_string(i) + "]");
					else if (srefWdbeKVendor == "xlnx") Wdbe::setPrtCpr(dbswdbe, ref, "IO", "io[" + to_string(i) + "]");
				} else {
					if (srefWdbeKVendor == "lttc") Wdbe::setPrtDfv(dbswdbe, ref, "B", "0");
					else if (srefWdbeKVendor == "mchp") Wdbe::setPrtDfv(dbswdbe, ref, "PAD", "0");
					else if (srefWdbeKVendor == "xlnx") Wdbe::setPrtDfv(dbswdbe, ref, "IO", "0");
				};
			};
		};

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
