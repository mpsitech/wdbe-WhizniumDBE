/**
	* \file WdbePlhfpgaFwdctr.cpp
	* Wdbe operation processor - fill type-specific placeholders (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbePlhfpgaFwdctr.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbePlhfpga;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbePlhfpgaFwdctr
 ******************************************************************************/

DpchRetWdbePlhfpgaFwdctr* WdbePlhfpgaFwdctr::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbePlhfpgaFwdctr* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	std::vector<std::string> keys;
	std::vector<std::string> vals;

	// IP run --- IBEGIN
	// keys / ex.:
	// Trguntsref
	// sizeRdbuf=1024, msbARdbuf=10
	// sizeWrbuf=1024, msbAWrbuf=10
	// reqInvReset

	ubigint ref;

	string sref;

	bool hasrdbuf, haswrbuf;

	string size;
	usmallint w;

	if (dbswdbe->loadStringBySQL("SELECT TblWdbeMUnit.sref FROM TblWdbeMController, TblWdbeMUnit WHERE TblWdbeMController.refWdbeMModule = " + to_string(refWdbeMModule) + " AND TblWdbeMUnit.ref = TblWdbeMController.fwdRefWdbeMUnit", sref)) {
		keys.push_back("Trguntsref");
		vals.push_back(StrMod::cap(sref));
	};

	hasrdbuf = dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::IMBUF) + " AND sref = 'rdbuf'", ref);
	if (hasrdbuf) {
		if (Wdbe::getMpa(dbswdbe, ref, "size", size)) {
			keys.push_back("sizeRdbuf"); vals.push_back(to_string(512*atoi(size.c_str()))); // half the imbuf size

			w = Wdbe::valToWidth(1024*atoi(size.c_str())-1);
			keys.push_back("msbARdbuf"); vals.push_back(to_string(w-1));
		};
	};

	haswrbuf = dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::IMBUF) + " AND sref = 'wrbuf'", ref);
	if (haswrbuf) {
		if (Wdbe::getMpa(dbswdbe, ref, "size", size)) {
			keys.push_back("sizeWrbuf"); vals.push_back(to_string(512*atoi(size.c_str()))); // half the imbuf size

			w = Wdbe::valToWidth(1024*atoi(size.c_str())-1);
			keys.push_back("msbAWrbuf"); vals.push_back(to_string(w-1));
		};
	};

	keys.push_back("reqInvReset");
	if (hasrdbuf || haswrbuf) vals.push_back("reqCmdInvReset");
	else vals.push_back("reqCmdToOpInvReset");
	// IP run --- IEND

	return(new DpchRetWdbePlhfpgaFwdctr("", "", ixOpVOpres, 100, keys, vals));
};

// IP cust --- INSERT
