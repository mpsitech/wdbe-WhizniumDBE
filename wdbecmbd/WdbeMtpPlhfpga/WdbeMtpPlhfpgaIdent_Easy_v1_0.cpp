/**
	* \file WdbeMtpPlhfpgaIdent_Easy_v1_0.cpp
	* Wdbe operation processor -  (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 31 Dec 2022
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpPlhfpgaIdent_Easy_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpPlhfpga;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpPlhfpgaIdent_Easy_v1_0
 ******************************************************************************/

DpchRetWdbeMtpPlhfpga* WdbeMtpPlhfpgaIdent_Easy_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpPlhfpga* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	std::vector<std::string> keys;
	std::vector<std::string> vals;

	// IP run --- IBEGIN
	// keys / ex.:
	// hash = "abcd123 "
	// who = "aw.myn  "

	ubigint refWdbeMVersion;

	string ver, hash, who;

	dbswdbe->loadRefBySQL("SELECT TblWdbeMUnit.refUref FROM TblWdbeMUnit, TblWdbeMModule WHERE TblWdbeMUnit.ref = TblWdbeMModule.hkUref AND TblWdbeMModule.hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT)
				+ " AND TblWdbeMModule.ref = " + to_string(refWdbeMModule), refWdbeMVersion);

	ver = StubWdbe::getStubVerNo(dbswdbe, refWdbeMVersion);

	keys.push_back("ver");
	vals.push_back(trimVal(ver, 8));

	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "hash", hash)) {
		keys.push_back("hash");
		vals.push_back(trimVal(hash, 8));
	};

	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "who", who)) {
		keys.push_back("who");
		vals.push_back(trimVal(who, 8));
	};
	// IP run --- IEND

	return(new DpchRetWdbeMtpPlhfpga("", "", ixOpVOpres, 100, keys, vals));
};

// IP cust --- IBEGIN
string WdbeMtpPlhfpgaIdent_Easy_v1_0::trimVal(
			const string& val
			, const size_t len
		) {
	string retval;

	if (val.length() < len) retval = val + string(len - val.length(), ' ');
	else retval = val.substr(0, len);

	return retval;
};
// IP cust --- IEND
