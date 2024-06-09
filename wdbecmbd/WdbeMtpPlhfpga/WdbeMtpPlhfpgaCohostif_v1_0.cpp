/**
	* \file WdbeMtpPlhfpgaCohostif_v1_0.cpp
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

#include "WdbeMtpPlhfpgaCohostif_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpPlhfpga;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpPlhfpgaCohostif_v1_0
 ******************************************************************************/

DpchRetWdbeMtpPlhfpga* WdbeMtpPlhfpgaCohostif_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpPlhfpga* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	std::vector<std::string> keys;
	std::vector<std::string> vals;

	// IP run --- INSERT

	return(new DpchRetWdbeMtpPlhfpga("", "", ixOpVOpres, 100, keys, vals));
};

// IP cust --- INSERT
