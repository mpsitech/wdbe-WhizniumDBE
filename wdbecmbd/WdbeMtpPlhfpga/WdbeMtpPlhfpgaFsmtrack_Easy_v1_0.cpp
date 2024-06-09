/**
	* \file WdbeMtpPlhfpgaFsmtrack_Easy_v1_0.cpp
	* Wdbe operation processor -  (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 30 May 2023
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpPlhfpgaFsmtrack_Easy_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpPlhfpga;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpPlhfpgaFsmtrack_Easy_v1_0
 ******************************************************************************/

DpchRetWdbeMtpPlhfpga* WdbeMtpPlhfpgaFsmtrack_Easy_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpPlhfpga* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	std::vector<std::string> keys;
	std::vector<std::string> vals;

	// IP run --- IBEGIN

	// hostif, Hostif
	// resetTrkclk, trkclk, Trkclk
	// cross, ssorc, waitcdc, cdclat

	WdbeMModule* mdl = NULL;

	string srefHostif;

	string trkclk;
	double cdclat;

	string s;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		srefHostif = Wdbe::getHostifSref(dbswdbe, mdl->hkUref);

		keys.push_back("hostif");
		vals.push_back(srefHostif);

		keys.push_back("Hostif");
		vals.push_back(StrMod::cap(srefHostif));

		Wdbe::getMpa(dbswdbe, refWdbeMModule, "trkclk", trkclk);

		keys.push_back("resetTrkclk");
		vals.push_back((trkclk == "mclk") ? "reset" : ("reset" + StrMod::cap(trkclk)));

		keys.push_back("trkclk");
		vals.push_back(trkclk);

		keys.push_back("Trkclk");
		vals.push_back(StrMod::cap(trkclk));

		keys.push_back("cross");
		vals.push_back((trkclk == "mclk") ? "" : ("_" + trkclk));

		keys.push_back("ssorc");
		vals.push_back((trkclk == "mclk") ? "" : "_mclk");

		keys.push_back("waitcdc");
		vals.push_back((trkclk == "mclk") ? "false" : "true");

		keys.push_back("cdclat");
		cdclat = 1.0;
		if (trkclk != "mclk")
			if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "ratioTrkclk", s)) {
				cdclat = atof(s.c_str());

				if ((cdclat == 0.0) || (cdclat > 1.0)) cdclat = 1.0;
				else cdclat = 1.0 / cdclat;
			};
		vals.push_back(to_string(lround(cdclat)));

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbeMtpPlhfpga("", "", ixOpVOpres, 100, keys, vals));
};

// IP cust --- INSERT
