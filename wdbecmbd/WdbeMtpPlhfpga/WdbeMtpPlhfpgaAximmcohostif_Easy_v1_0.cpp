/**
	* \file WdbeMtpPlhfpgaAximmcohostif_Easy_v1_0.cpp
	* Wdbe operation processor -  (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 3 Mar 2025
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpPlhfpgaAximmcohostif_Easy_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpPlhfpga;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpPlhfpgaAximmcohostif_Easy_v1_0
 ******************************************************************************/

DpchRetWdbeMtpPlhfpga* WdbeMtpPlhfpgaAximmcohostif_Easy_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpPlhfpga* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	std::vector<std::string> keys;
	std::vector<std::string> vals;

	// IP run --- IBEGIN

	// wD, logWD
	// sizeInvbuf
	// tru, fls

	WdbeMModule* mdl = NULL;

	unsigned int wD;

	unsigned int sizeInvbuf, sizeRetbuf;
	unsigned int resid;

	string s;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		s = "8";
		Wdbe::getMpa(dbswdbe, refWdbeMModule, "wD", s);

		keys.push_back("wD");
		vals.push_back(s);

		wD = atoi(s.c_str());

		keys.push_back("logWD");
		vals.push_back(to_string(lround(log2(wD/8))));

		Wdbe::getHostifSizeInvretbuf(dbswdbe, mdl->hkUref, sizeInvbuf, sizeRetbuf);

		sizeInvbuf = extendToWD(sizeInvbuf, wD, resid);

		keys.push_back("sizeInvbuf");
		vals.push_back(to_string(sizeInvbuf));

		keys.push_back("tru");
		vals.push_back("tru" + to_string(wD));

		keys.push_back("fls");
		vals.push_back("fls" + to_string(wD));

		delete mdl;
	};

	// wD(64) logWD(3) sizeInvbuf tru(tru64) fls(fls64)

	// IP run --- IEND

	return(new DpchRetWdbeMtpPlhfpga("", "", ixOpVOpres, 100, keys, vals));
};

// IP cust --- INSERT
