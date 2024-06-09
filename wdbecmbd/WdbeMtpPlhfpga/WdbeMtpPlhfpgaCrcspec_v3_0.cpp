/**
	* \file WdbeMtpPlhfpgaCrcspec_v3_0.cpp
	* Wdbe operation processor -  (implementation)
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

#include "WdbeMtpPlhfpgaCrcspec_v3_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpPlhfpga;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpPlhfpgaCrcspec_v3_0
 ******************************************************************************/

DpchRetWdbeMtpPlhfpga* WdbeMtpPlhfpgaCrcspec_v3_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpPlhfpga* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	std::vector<std::string> keys;
	std::vector<std::string> vals;

	// IP run --- IBEGIN
	// keys / ex.:
	// wPolym1 = 7
	// wDm1 = 31

	string poly, wD;

	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "poly", poly)) {
		keys.push_back("wPolym1");
		vals.push_back((poly.length() > 4) ? "31" : "15");
	};

	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wD", wD)) {
		keys.push_back("wDm1");
		vals.push_back(to_string(atoi(wD.c_str()) - 1));
	};
	// IP run --- IEND

	return(new DpchRetWdbeMtpPlhfpga("", "", ixOpVOpres, 100, keys, vals));
};

// IP cust --- INSERT
