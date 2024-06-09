/**
	* \file WdbePlhfpgaCtr.cpp
	* Wdbe operation processor - fill type-specific placeholders (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 13 May 2023
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbePlhfpgaCtr.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbePlhfpga;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbePlhfpgaCtr
 ******************************************************************************/

DpchRetWdbePlhfpgaCtr* WdbePlhfpgaCtr::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbePlhfpgaCtr* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	std::vector<std::string> keys;
	std::vector<std::string> vals;

	// IP run --- INSERT

	return(new DpchRetWdbePlhfpgaCtr("", "", ixOpVOpres, 100, keys, vals));
};

// IP cust --- INSERT
