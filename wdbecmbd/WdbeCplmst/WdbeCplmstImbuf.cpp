/**
	* \file WdbeCplmstImbuf.cpp
	* Wdbe operation processor - add parameters (implementation)
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

#include "WdbeCplmstImbuf.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeCplmst;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeCplmstImbuf
 ******************************************************************************/

DpchRetWdbeCplmstImbuf* WdbeCplmstImbuf::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeCplmstImbuf* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	std::string logfile;

	// IP run --- IBEGIN
	fstream logfi;

	WdbeMModule* mdl = NULL;
	WdbeMImbuf* imb = NULL;

	string s;

	string sref, srefrootMgmt, srefrootCor;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		if (dbswdbe->tblwdbemimbuf->loadRecByRef(mdl->refWdbeMImbuf, &imb)) {
			// inter-module buffer width becomes wB parameter if not speficied
			if (!Wdbe::getMpa(dbswdbe, refWdbeMModule, "wB", s)) {
				s = to_string((int) (imb->Width));
				Wdbe::setMpa(dbswdbe, refWdbeMModule, "wB", s);
			};

			delete imb;

		} else Wdbe::appendToTmpfile(xchg->tmppath, logfile, logfi, "modular structure error: no inter-module buffer information specified!");

		delete mdl;
	};

	if (logfi.is_open()) {
		logfi.close();

		ixOpVOpres = VecOpVOpres::FAILURE;
	};
	// IP run --- IEND

	return(new DpchRetWdbeCplmstImbuf("", "", ixOpVOpres, 100, logfile));
};

// IP cust --- INSERT
