/**
	* \file WdbePlhfpgaEhostif.cpp
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

#include "WdbePlhfpgaEhostif.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbePlhfpga;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbePlhfpgaEhostif
 ******************************************************************************/

DpchRetWdbePlhfpgaEhostif* WdbePlhfpgaEhostif::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbePlhfpgaEhostif* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	std::vector<std::string> keys;
	std::vector<std::string> vals;

	// IP run --- IBEGIN

	// sizeRxbuf, sizeRxbuf32, sizeTxbuf, sizeTxbuf32

	WdbeMModule* mdl = NULL;

	unsigned int sizeRxbuf, sizeTxbuf, len;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		Wdbe::getHostifSizeRxtxbuf(dbswdbe, mdl->hkUref, sizeRxbuf, sizeTxbuf);

		keys.push_back("sizeRxbuf");
		vals.push_back(to_string(sizeRxbuf));

		len = sizeRxbuf/4;
		if ((sizeRxbuf%4) != 0) len++;
		keys.push_back("sizeRxbuf32");
		vals.push_back(to_string(4*len));

		keys.push_back("sizeTxbuf");
		vals.push_back(to_string(sizeTxbuf));

		len = sizeTxbuf/4;
		if ((sizeTxbuf%4) != 0) len++;
		keys.push_back("sizeTxbuf32");
		vals.push_back(to_string(4*len));

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbePlhfpgaEhostif("", "", ixOpVOpres, 100, keys, vals));
};

// IP cust --- INSERT
