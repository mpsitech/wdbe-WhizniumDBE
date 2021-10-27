/**
	* \file WdbePlhmcuEctr.cpp
	* Wdbe operation processor - fill type-specific placeholders (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Oct 2021
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbePlhmcuEctr.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbePlhmcu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbePlhmcuEctr
 ******************************************************************************/

DpchRetWdbePlhmcuEctr* WdbePlhmcuEctr::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbePlhmcuEctr* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	std::vector<std::string> keys;
	std::vector<std::string> vals;

	// IP run --- IBEGIN

	// Hostif

	string Hostif;

	if (dbswdbe->loadStringBySQL("SELECT mdl2.sref FROM TblWdbeMModule AS mdl1, TblWdbeMModule AS mdl2 WHERE mdl2.hkUref = mdl1.hkUref AND mdl1.ref = " + to_string(refWdbeMModule) + " AND mdl2.ixVBasetype = "
				+ to_string(VecWdbeVMModuleBasetype::EHOSTIF), Hostif)) {

		keys.push_back("Hostif");
		vals.push_back(StrMod::cap(Hostif));
	};
	// IP run --- IEND

	return(new DpchRetWdbePlhmcuEctr("", "", ixOpVOpres, 100, keys, vals));
};

// IP cust --- INSERT
