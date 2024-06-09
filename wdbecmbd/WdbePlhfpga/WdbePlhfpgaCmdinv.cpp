/**
	* \file WdbePlhfpgaCmdinv.cpp
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

#include "WdbePlhfpgaCmdinv.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbePlhfpga;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbePlhfpgaCmdinv
 ******************************************************************************/

DpchRetWdbePlhfpgaCmdinv* WdbePlhfpgaCmdinv::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbePlhfpgaCmdinv* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	std::vector<std::string> keys;
	std::vector<std::string> vals;

	// IP run --- IBEGIN
	// Hostif, Cmdbus
	// sizeBuf, wLenBuf, msbLenBuf, wABuf, msbABuf
	// sizeTocBuf
	// maxlenInv

	ubigint ref;

	WdbeMModule* mdl = NULL;

	string sref;

	string sizeTocBuf;

	string sizeBuf;
	usmallint w;

	string maxlen;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		keys.push_back("Hostif");
		vals.push_back(StrMod::cap(Wdbe::getHostifSref(dbswdbe, mdl->hkUref)));

		if (dbswdbe->loadStringBySQL("SELECT sref FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::CMDBUS), sref)) {
			keys.push_back("Cmdbus");
			vals.push_back(StrMod::cap(sref));
		};

		if (Wdbe::getMpa(dbswdbe, mdl->ref, "sizeTocBuf", sizeTocBuf)) {
			keys.push_back("sizeTocBuf"); vals.push_back(sizeTocBuf);
		};

		if (Wdbe::getMpa(dbswdbe, mdl->ref, "sizeBuf", sizeBuf)) {
			keys.push_back("sizeBuf"); vals.push_back(to_string(1024*atoi(sizeBuf.c_str())));

			w = Wdbe::valToWidth(1024*atoi(sizeBuf.c_str())-1);

			keys.push_back("wABuf"); vals.push_back(to_string(w));
			keys.push_back("msbABuf"); vals.push_back(to_string(w-1));
		};

		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "maxlenRecv", maxlen)) {
			keys.push_back("maxlenRecv"); vals.push_back(maxlen);

			w = Wdbe::valToWidth(atoi(maxlen.c_str()));

			keys.push_back("wLenBuf"); vals.push_back(to_string(w));
			keys.push_back("msbLenBuf"); vals.push_back(to_string(w-1));
		};

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbePlhfpgaCmdinv("", "", ixOpVOpres, 100, keys, vals));
};

// IP cust --- INSERT
