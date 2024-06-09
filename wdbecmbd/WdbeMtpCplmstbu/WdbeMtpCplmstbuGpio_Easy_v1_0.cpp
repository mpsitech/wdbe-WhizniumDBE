/**
	* \file WdbeMtpCplmstbuGpio_Easy_v1_0.cpp
	* Wdbe operation processor - adapt port widths, connect tri-state primitives (implementation)
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

	vector<ubigint> refsSubmdls;
	string srefIobuf;

	string s;

	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "w", s)) w = atoi(s.c_str());

	dbswdbe->loadRefsBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " ORDER BY ref ASC", false, refsSubmdls); // to ensure correct numerical order
	if (refsSubmdls.size() > 0) {
		dbswdbe->loadStringBySQL("SELECT sref FROM TblWdbeMModule WHERE ref = " + to_string(refsSubmdls[0]), srefIobuf);
		srefIobuf = srefIobuf.substr(0, srefIobuf.length() - 1);
	};

	// - port widths
	if (refsSubmdls.size() > 0) {
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "bitsIo", w);

	} else {
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "bitsIn", w);
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "bitsOut", w);
		Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "bitsDir", w);
	};

	// - sub-module wiring
	if (srefIobuf == "bb")
		for (unsigned int i = 0; i < refsSubmdls.size(); i++) {
			Wdbe::setPrtCsi(dbswdbe, refsSubmdls[i], "O", "bitsIn_sig[" + to_string(i) + "]");
			Wdbe::setPrtCpr(dbswdbe, refsSubmdls[i], "B", "bitsIo[" + to_string(i) + "]");
			Wdbe::setPrtCsi(dbswdbe, refsSubmdls[i], "I", "bitsOut_sig[" + to_string(i) + "]");
			Wdbe::setPrtCsi(dbswdbe, refsSubmdls[i], "T", "bitsDirn_sig[" + to_string(i) + "]");
		}
	else if (srefIobuf == "bibuf")
		for (unsigned int i = 0; i < refsSubmdls.size(); i++) {
			Wdbe::setPrtCsi(dbswdbe, refsSubmdls[i], "Y", "bitsIn_sig[" + to_string(i) + "]");
			Wdbe::setPrtCpr(dbswdbe, refsSubmdls[i], "PAD", "bitsIo[" + to_string(i) + "]");
			Wdbe::setPrtCsi(dbswdbe, refsSubmdls[i], "D", "bitsOut_sig[" + to_string(i) + "]");
			Wdbe::setPrtCsi(dbswdbe, refsSubmdls[i], "E", "bitsDir_sig[" + to_string(i) + "]");
		}
	else if (srefIobuf == "iobuf")
		for (unsigned int i = 0; i < refsSubmdls.size(); i++) {
			Wdbe::setPrtCsi(dbswdbe, refsSubmdls[i], "O", "bitsIn_sig[" + to_string(i) + "]");
			Wdbe::setPrtCpr(dbswdbe, refsSubmdls[i], "IO", "bitsIo[" + to_string(i) + "]");
			Wdbe::setPrtCsi(dbswdbe, refsSubmdls[i], "I", "bitsOut_sig[" + to_string(i) + "]");
			Wdbe::setPrtCsi(dbswdbe, refsSubmdls[i], "T", "bitsDirn_sig[" + to_string(i) + "]");
		};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
