/**
	* \file WdbePlhmcuEhostif.cpp
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

#include "WdbePlhmcuEhostif.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbePlhmcu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbePlhmcuEhostif
 ******************************************************************************/

DpchRetWdbePlhmcuEhostif* WdbePlhmcuEhostif::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbePlhmcuEhostif* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	std::vector<std::string> keys;
	std::vector<std::string> vals;

	// IP run --- IBEGIN

	// sizeRetbuf

	WdbeMModule* mdl = NULL;

	unsigned int sizeInvbuf, sizeRetbuf;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		Wdbe::getHostifSizeInvretbuf(dbswdbe, mdl->hkUref, sizeInvbuf, sizeRetbuf);

		keys.push_back("sizeRetbuf");
		vals.push_back(to_string(sizeRetbuf));

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbePlhmcuEhostif("", "", ixOpVOpres, 100, keys, vals));
};

// IP cust --- INSERT
