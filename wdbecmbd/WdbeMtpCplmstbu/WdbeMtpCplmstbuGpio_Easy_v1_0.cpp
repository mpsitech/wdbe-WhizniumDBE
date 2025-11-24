/**
	* \file WdbeMtpCplmstbuGpio_Easy_v1_0.cpp
	* Wdbe operation processor - adapt port widths and commands (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 7 Jun 2022
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpCplmstbuGpio_Easy_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuGpio_Easy_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuGpio_Easy_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	unsigned int w = 32;
	bool threeNotInout = false;
	bool bidirNotUnidir = false;
	bool inNotOut = false;

	vector<ubigint> refsSubmdls;
	string srefIobuf;

	ubigint ref, refC;

	string s;

	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "w", s)) w = atoi(s.c_str());
	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "threeNotInout", s)) threeNotInout = (s == "true");
	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "bidirNotUnidir", s)) bidirNotUnidir = (s == "true");
	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "inNotOut", s)) inNotOut = (s == "true");

	dbswdbe->loadRefsBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " ORDER BY ref ASC", false, refsSubmdls); // to ensure correct numerical order
	if (refsSubmdls.size() > 0) {
		dbswdbe->loadStringBySQL("SELECT sref FROM TblWdbeMModule WHERE ref = " + to_string(refsSubmdls[0]), srefIobuf);
		srefIobuf = srefIobuf.substr(0, srefIobuf.length() - 1);
	};

	// - ports
	if (!threeNotInout && bidirNotUnidir) {
		refC = 0; dbswdbe->loadRefBySQL("SELECT refWdbeCPort FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'bits_in'", refC);
		if (refC != 0) dbswdbe->executeQuery("DELETE FROM TblWdbeMPort WHERE refWdbeCPort = " + to_string(refC));

		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "bits", w);

	} else {
		dbswdbe->executeQuery("DELETE FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'bits'");

		if (!bidirNotUnidir && !inNotOut) dbswdbe->executeQuery("DELETE FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'bits_in'");
		else Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "bits_in", w);

		if (!bidirNotUnidir && inNotOut) dbswdbe->executeQuery("DELETE FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'bits_out'");
		else Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "bits_out", w);

		if (!bidirNotUnidir) dbswdbe->executeQuery("DELETE FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'bits_tri'");
		else Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "bits_tri", w);
	};

	// - sub-module wiring
	if (srefIobuf == "bb")
		for (unsigned int i = 0; i < refsSubmdls.size(); i++) {
			Wdbe::setPrtCsi(dbswdbe, refsSubmdls[i], "O", "bitsIn_sig[" + to_string(i) + "]");
			Wdbe::setPrtCpr(dbswdbe, refsSubmdls[i], "B", "bits[" + to_string(i) + "]");
			Wdbe::setPrtCsi(dbswdbe, refsSubmdls[i], "I", "bitsOut_sig[" + to_string(i) + "]");
			Wdbe::setPrtCsi(dbswdbe, refsSubmdls[i], "T", "bitsDirn_sig[" + to_string(i) + "]");
		}
	else if (srefIobuf == "bibuf")
		for (unsigned int i = 0; i < refsSubmdls.size(); i++) {
			Wdbe::setPrtCsi(dbswdbe, refsSubmdls[i], "Y", "bitsIn_sig[" + to_string(i) + "]");
			Wdbe::setPrtCpr(dbswdbe, refsSubmdls[i], "PAD", "bits[" + to_string(i) + "]");
			Wdbe::setPrtCsi(dbswdbe, refsSubmdls[i], "D", "bitsOut_sig[" + to_string(i) + "]");
			Wdbe::setPrtCsi(dbswdbe, refsSubmdls[i], "E", "bitsDir_sig[" + to_string(i) + "]");
		}
	else if (srefIobuf == "iobuf")
		for (unsigned int i = 0; i < refsSubmdls.size(); i++) {
			Wdbe::setPrtCsi(dbswdbe, refsSubmdls[i], "O", "bitsIn_sig[" + to_string(i) + "]");
			Wdbe::setPrtCpr(dbswdbe, refsSubmdls[i], "IO", "bits[" + to_string(i) + "]");
			Wdbe::setPrtCsi(dbswdbe, refsSubmdls[i], "I", "bitsOut_sig[" + to_string(i) + "]");
			Wdbe::setPrtCsi(dbswdbe, refsSubmdls[i], "T", "bitsDirn_sig[" + to_string(i) + "]");
		};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
