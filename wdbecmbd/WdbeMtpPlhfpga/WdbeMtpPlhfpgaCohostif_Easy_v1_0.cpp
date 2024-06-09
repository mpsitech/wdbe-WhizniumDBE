/**
	* \file WdbeMtpPlhfpgaCohostif_Easy_v1_0.cpp
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

#include "WdbeMtpPlhfpgaCohostif_Easy_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpPlhfpga;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpPlhfpgaCohostif_Easy_v1_0
 ******************************************************************************/

DpchRetWdbeMtpPlhfpga* WdbeMtpPlhfpgaCohostif_Easy_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpPlhfpga* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	std::vector<std::string> keys;
	std::vector<std::string> vals;

	// IP run --- IBEGIN
	// slightly adapted from WdbeMtpPlhfpgaHostif_Easy_v1_0.cpp

	// Hostif
	// wA, wD
	// sizeOpbuf, opbufLastAXIS_tkeep
	// sizePollbuf, pollbufLastAXIS_tkeep
	// sizeInvbuf, sizeRetbuf

	WdbeMModule* mdl = NULL;

	string srefHostif;

	string phytype;

	unsigned int wD;

	const unsigned int sizeOpbuf = 9;
	const unsigned int sizePollbuf = 6;

	unsigned int sizeInvbuf, sizeRetbuf;

	unsigned int resid;

	string s;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		srefHostif = Wdbe::getHostifSref(dbswdbe, mdl->hkUref);

		keys.push_back("Hostif");
		vals.push_back(StrMod::cap(srefHostif));

		s = "32";
		Wdbe::getMpa(dbswdbe, refWdbeMModule, "wA", s);

		keys.push_back("wA");
		vals.push_back(s);

		s = "8";

		Wdbe::getMpa(dbswdbe, refWdbeMModule, "phytype", phytype);
		if (phytype == "axi") Wdbe::getMpa(dbswdbe, refWdbeMModule, "wD", s);

		keys.push_back("wD");
		vals.push_back(s);

		wD = atoi(s.c_str());

		keys.push_back("sizeOpbuf");
		vals.push_back(to_string(extendToWD(sizeOpbuf, wD, resid))); // include CRC

		s = "";
		for (unsigned int i = 0; i < wD/8; i++)
			if (i < resid) s += "1";
			else s = "0" + s;

		keys.push_back("opbufLastAXIS_tkeep");
		vals.push_back(s);

		keys.push_back("sizePollbuf");
		vals.push_back(to_string(extendToWD(sizePollbuf, wD, resid))); // include CRC

		extendToWD(sizePollbuf-2, wD, resid); // run again to exclude CRC (only residual needed)

		s = "";
		for (unsigned int i = 0; i < wD/8; i++)
			if (i < resid) s += "1";
			else s = "0" + s;

		keys.push_back("pollbufLastAXIS_tkeep");
		vals.push_back(s);

		Wdbe::getHostifSizeInvretbuf(dbswdbe, mdl->hkUref, sizeInvbuf, sizeRetbuf);

		sizeInvbuf = extendToWD(sizeInvbuf, wD, resid);
		sizeRetbuf = extendToWD(sizeRetbuf, wD, resid);

		keys.push_back("sizeInvbuf");
		vals.push_back(to_string(sizeInvbuf));

		keys.push_back("sizeRetbuf");
		vals.push_back(to_string(sizeRetbuf));

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbeMtpPlhfpga("", "", ixOpVOpres, 100, keys, vals));
};

// IP cust --- IBEGIN
unsigned int WdbeMtpPlhfpgaCohostif_Easy_v1_0::extendToWD(
			const unsigned int size
			, const unsigned int wD
			, unsigned int& resid
		) {
	resid = size % (wD/8);

	if (resid == 0) return size;
	else return(size-resid + wD/8);
};
// IP cust --- IEND
