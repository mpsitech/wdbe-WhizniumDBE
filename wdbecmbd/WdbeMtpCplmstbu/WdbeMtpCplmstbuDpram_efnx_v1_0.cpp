/**
	* \file WdbeMtpCplmstbuDpram_efnx_v1_0.cpp
	* Wdbe operation processor - connect buffer primitives (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Apr 2023
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpCplmstbuDpram_efnx_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuDpram_efnx_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuDpram_efnx_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	ubigint ref;

	ListWdbeMModule mdls;
	WdbeMModule* mdl = NULL;

	string suffix;
	unsigned int i, j, k, l;

	string range;

	string s;
	size_t ptr;

	bool aA_sig, aB_sig;

	dbswdbe->tblwdbemmodule->loadRstBySQL("SELECT * FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref LIKE 'ram_%'", false, mdls);
	aA_sig = dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMSignal WHERE refIxVTbl = " + to_string(VecWdbeVMSignalRefTbl::MDL) + " AND refUref = " + to_string(refWdbeMModule) + " AND sref = 'aA_sig'", ref);
	aB_sig = dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMSignal WHERE refIxVTbl = " + to_string(VecWdbeVMSignalRefTbl::MDL) + " AND refUref = " + to_string(refWdbeMModule) + " AND sref = 'aB_sig'", ref);

	for (unsigned int m = 0; m < mdls.nodes.size(); m++) {
		mdl = mdls.nodes[m];

		suffix = mdl->sref.substr(3);

		i = 0;
		j = 0;
		k = 0;
		l = 0;

		ptr = suffix.find("i");
		if (ptr != string::npos) i = atoi(suffix.substr(ptr + 1).c_str());

		ptr = suffix.find("j");
		if (ptr != string::npos) j = atoi(suffix.substr(ptr + 1).c_str());

		ptr = suffix.find("k");
		if (ptr != string::npos) k = atoi(suffix.substr(ptr + 1).c_str());

		ptr = suffix.find("l");
		if (ptr != string::npos) l = atoi(suffix.substr(ptr + 1).c_str());

		// A port
		Wdbe::setPrtDfv(dbswdbe, mdl->ref, "RSTA", "resetA");
		Wdbe::setPrtCpr(dbswdbe, mdl->ref, "CLKA", "clkA");

		Wdbe::setPrtDfv(dbswdbe, mdl->ref, "CLKEA", "1");
		Wdbe::setPrtCsi(dbswdbe, mdl->ref, "WEA", "enA_i" + to_string(i));

		if (aA_sig) Wdbe::setPrtCsi(dbswdbe, mdl->ref, "ADDRA", "aA_sig[0..9]");
		else Wdbe::setPrtCpr(dbswdbe, mdl->ref, "ADDRA", "aA[0..9]");

		Wdbe::setPrtDfv(dbswdbe, mdl->ref, "ADDRENA", "1");

		range = "[" + to_string(8*j) + ".." + to_string(8*(j+1)-1) + "]";
		Wdbe::setPrtCpr(dbswdbe, mdl->ref, "WDATAA", "dwrA" + range);

		Wdbe::setPrtCsi(dbswdbe, mdl->ref, "RDATAA", "drdA_i" + to_string(i) + "j" + to_string(j));

		// B port
		Wdbe::setPrtDfv(dbswdbe, mdl->ref, "RSTB", "resetB");
		Wdbe::setPrtCpr(dbswdbe, mdl->ref, "CLKB", "clkB");

		Wdbe::setPrtDfv(dbswdbe, mdl->ref, "CLKEB", "1");
		Wdbe::setPrtCsi(dbswdbe, mdl->ref, "WEB", "enB_k" + to_string(k));

		if (aB_sig) Wdbe::setPrtCsi(dbswdbe, mdl->ref, "ADDRB", "aB_sig[0..9]");
		else Wdbe::setPrtCpr(dbswdbe, mdl->ref, "ADDRB", "aB[0..9]");

		Wdbe::setPrtDfv(dbswdbe, mdl->ref, "ADDRENB", "1");

		range = "[" + to_string(8*l) + ".." + to_string(8*(l+1)-1) + "]";
		Wdbe::setPrtCpr(dbswdbe, mdl->ref, "WDATAB", "dwrB" + range);

		Wdbe::setPrtCsi(dbswdbe, mdl->ref, "RDATAB", "drdB_k" + to_string(k) + "l" + to_string(l));
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
