/**
	* \file WdbeMtpCplmsttdCohostif_Easy_v1_0.cpp
	* Wdbe operation processor - infer PHY (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 3 Apr 2023
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpCplmsttdCohostif_Easy_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmsttd;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmsttdCohostif_Easy_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmsttdCohostif_Easy_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmsttd* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	// exact copy from WdbeMtpCplmsttdHostif_Easy_v1_0.cpp

	WdbeMModule* mdl = NULL;

	ubigint refMtp, refSubmdl;

	ubigint refCAxi, refCSpi, refCUart;

	string phytype, wD;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "phytype", phytype)) {
			refCAxi = 0; dbswdbe->loadRefBySQL("SELECT refWdbeCPort FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'AXIL_araddr'", refCAxi);
			refCSpi = 0; dbswdbe->loadRefBySQL("SELECT refWdbeCPort FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'nss'", refCSpi);
			refCUart = 0; dbswdbe->loadRefBySQL("SELECT refWdbeCPort FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'rxd'", refCUart);

			wD = "8";

			if (phytype == "axi") {
				dbswdbe->executeQuery("UPDATE TblWdbeMModule SET hkNum = hkNum + 1 WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND hkNum > " + to_string(mdl->hkNum));

				refMtp = Wdbe::getRefMtp(dbswdbe, "axislave_v1_0");
				refSubmdl = dbswdbe->tblwdbemmodule->insertNewRec(NULL, VecWdbeVMModuleBasetype::OTH, mdl->hkIxVTbl, mdl->hkUref, mdl->hkNum + 1, mdl->ref, refMtp, 0, 0, "axi", "", "", "");

				Wdbe::getMpa(dbswdbe, refWdbeMModule, "wD", wD);

				dbswdbe->executeQuery("DELETE FROM TblWdbeMGeneric WHERE mdlRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'fSclk'");
				if (refCSpi != 0) dbswdbe->executeQuery("DELETE FROM TblWdbeMPort WHERE refWdbeCPort = " + to_string(refCSpi));
				if (refCUart != 0) dbswdbe->executeQuery("DELETE FROM TblWdbeMPort WHERE refWdbeCPort = " + to_string(refCUart));

			} else if (phytype == "spi") {
				dbswdbe->executeQuery("UPDATE TblWdbeMModule SET hkNum = hkNum + 1 WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND hkNum > " + to_string(mdl->hkNum));

				refMtp = Wdbe::getRefMtp(dbswdbe, "spislave_v2_0");
				refSubmdl = dbswdbe->tblwdbemmodule->insertNewRec(NULL, VecWdbeVMModuleBasetype::OTH, mdl->hkIxVTbl, mdl->hkUref, mdl->hkNum + 1, mdl->ref, refMtp, 0, 0, "spi", "", "", "");

				Wdbe::setMpa(dbswdbe, refWdbeMModule, "wD", "8");

				if (refCAxi != 0) dbswdbe->executeQuery("DELETE FROM TblWdbeMPort WHERE refWdbeCPort = " + to_string(refCAxi));
				if (refCUart != 0) dbswdbe->executeQuery("DELETE FROM TblWdbeMPort WHERE refWdbeCPort = " + to_string(refCUart));

			} else if (phytype == "uart") {
				dbswdbe->executeQuery("UPDATE TblWdbeMModule SET hkNum = hkNum + 2 WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND hkNum > " + to_string(mdl->hkNum));

				refMtp = Wdbe::getRefMtp(dbswdbe, "uartrx_v2_0");
				refSubmdl = dbswdbe->tblwdbemmodule->insertNewRec(NULL, VecWdbeVMModuleBasetype::OTH, mdl->hkIxVTbl, mdl->hkUref, mdl->hkNum + 1, mdl->ref, refMtp, 0, 0, "rx", "", "", "");

				refMtp = Wdbe::getRefMtp(dbswdbe, "uarttx_v2_0");
				refSubmdl = dbswdbe->tblwdbemmodule->insertNewRec(NULL, VecWdbeVMModuleBasetype::OTH, mdl->hkIxVTbl, mdl->hkUref, mdl->hkNum + 2, mdl->ref, refMtp, 0, 0, "tx", "", "", "");

				Wdbe::setMpa(dbswdbe, refWdbeMModule, "wD", "8");

				if (refCAxi != 0) dbswdbe->executeQuery("DELETE FROM TblWdbeMPort WHERE refWdbeCPort = " + to_string(refCAxi));
				if (refCSpi != 0) dbswdbe->executeQuery("DELETE FROM TblWdbeMPort WHERE refWdbeCPort = " + to_string(refCSpi));
			};

			if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'crc'", refSubmdl)) Wdbe::setMpa(dbswdbe, refSubmdl, "wD", wD);
		};

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
