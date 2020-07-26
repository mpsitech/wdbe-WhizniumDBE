/**
	* \file WdbeMtpModbscbuDpbram_v1_0.cpp
	* Wdbe operation processor - adapt internal wiring (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpModbscbuDpbram_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpModbscbu;

/******************************************************************************
 namespace WdbeMtpModbscbuDpbram_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpModbscbuDpbram_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpModbscbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	unsigned int wD;
	string range;

	ubigint refPrtCEnA, refPrtCEnB;
	ubigint refPrtCDrdA, refPrtCDrdB;

	ListWdbeMModule mdls;
	WdbeMModule* mdl = NULL;

	string suffix;

	string s;

	Wdbe::getMpa(dbswdbe, refWdbeMModule, "d9NotD8", s);
	if (s == "true") wD = 9; else wD = 8;
	if (wD == 9) range = "[0..7]";

	dbswdbe->tblwdbemmodule->loadRstBySQL("SELECT * FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref LIKE 'bram%' ORDER BY hkNum ASC", false, mdls);

	if (mdls.nodes.size() > 1) {
		refPrtCEnA = dbswdbe->tblwdbecsignal->getNewRef();
		refPrtCEnB = dbswdbe->tblwdbecsignal->getNewRef();

		refPrtCDrdA = dbswdbe->tblwdbecsignal->getNewRef();
		refPrtCDrdB = dbswdbe->tblwdbecsignal->getNewRef();
	};

	for (unsigned int i = 0; i < mdls.nodes.size(); i++) {
		mdl = mdls.nodes[i];

		suffix = mdl->sref.substr(4);

		if (mdls.nodes.size() > 1) {
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refPrtCDrdA, refWdbeMModule, mdls.nodes.size() + (i+1), VecWdbeVMSignalMgeTbl::VOID, 0, 0, "drdA" + suffix, false, "slvdn", wD, "", "", "", "0", false, 0, "");
			Wdbe::setPrtCsi(dbswdbe, mdl->ref, "DOA", "drdA" + suffix + range);

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refPrtCDrdB, refWdbeMModule, 3*mdls.nodes.size() + (i+1), VecWdbeVMSignalMgeTbl::VOID, 0, 0, "drdB" + suffix, false, "slvdn", wD, "", "", "", "0", false, 0, "");
			Wdbe::setPrtCsi(dbswdbe, mdl->ref, "DOB", "drdB" + suffix + range);

			if (wD == 9) {
				Wdbe::setPrtCsi(dbswdbe, mdl->ref, "DOPA", "drdA" + suffix + "[8..8]");
				Wdbe::setPrtCsi(dbswdbe, mdl->ref, "DOPB", "drdB" + suffix + "[8..8]");
			};

		} else {
			Wdbe::setPrtCpr(dbswdbe, mdl->ref, "DOA", "drdA" + range);
			Wdbe::setPrtCpr(dbswdbe, mdl->ref, "DOB", "drdB" + range);

			if (wD == 9) {
				Wdbe::setPrtCpr(dbswdbe, mdl->ref, "DOPA", "drdA[8..8]");
				Wdbe::setPrtCpr(dbswdbe, mdl->ref, "DOPB", "drdB[8..8]");
			};
		};

		if (mdls.nodes.size() > 1) {
			Wdbe::setPrtCpr(dbswdbe, mdl->ref, "ADDRA", "aA[0..10]");
			Wdbe::setPrtCpr(dbswdbe, mdl->ref, "ADDRB", "aB[0..10]");
		} else {
			Wdbe::setPrtCpr(dbswdbe, mdl->ref, "ADDRA", "aA");
			Wdbe::setPrtCpr(dbswdbe, mdl->ref, "ADDRB", "aB");
		};

		Wdbe::setPrtCpr(dbswdbe, mdl->ref, "CLKA", "clkA");
		Wdbe::setPrtCpr(dbswdbe, mdl->ref, "CLKB", "clkB");

		Wdbe::setPrtCpr(dbswdbe, mdl->ref, "DIA", "dwrA" + range);
		Wdbe::setPrtCpr(dbswdbe, mdl->ref, "DIB", "dwrB" + range);

		if (wD == 8) {
			Wdbe::setPrtDfv(dbswdbe, mdl->ref, "DIPA", "0");
			Wdbe::setPrtDfv(dbswdbe, mdl->ref, "DIPB", "0");
		} else {
			Wdbe::setPrtCpr(dbswdbe, mdl->ref, "DIPA", "dwrA[8..8]");
			Wdbe::setPrtCpr(dbswdbe, mdl->ref, "DIPB", "dwrB[8..8]");
		};

		if (mdls.nodes.size() > 1) {
			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refPrtCEnA, refWdbeMModule, i+1, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "enA" + suffix, false, "sl", 1, "", "", "", "0", false, 0, "");
			Wdbe::setPrtCsi(dbswdbe, mdl->ref, "ENA", "enA" + suffix);

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refPrtCEnB, refWdbeMModule, 2*mdls.nodes.size() + (i+1), VecWdbeVMSignalMgeTbl::VOID, 0, 0, "enB" + suffix, false, "sl", 1, "", "", "", "0", false, 0, "");
			Wdbe::setPrtCsi(dbswdbe, mdl->ref, "ENB", "enB" + suffix);

		} else {
			Wdbe::setPrtCpr(dbswdbe, mdl->ref, "ENA", "enA");
			Wdbe::setPrtCpr(dbswdbe, mdl->ref, "ENB", "enB");
		};

		Wdbe::setPrtDfv(dbswdbe, mdl->ref, "SSRA", "0");
		Wdbe::setPrtDfv(dbswdbe, mdl->ref, "SSRB", "0");
		Wdbe::setPrtCpr(dbswdbe, mdl->ref, "WEA", "weA");
		Wdbe::setPrtCpr(dbswdbe, mdl->ref, "WEB", "weB");
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT


