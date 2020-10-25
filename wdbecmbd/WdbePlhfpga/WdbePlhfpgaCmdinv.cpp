/**
	* \file WdbePlhfpgaCmdinv.cpp
	* Wdbe operation processor - fill type-specific placeholders (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

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
	// Hostifsref, Cmdbussref
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
		if (dbswdbe->loadStringBySQL("SELECT sref FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::HOSTIF), sref)) {
			keys.push_back("Hostifsref");
			vals.push_back(StrMod::cap(sref));
		};

		if (dbswdbe->loadStringBySQL("SELECT sref FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::CMDBUS), sref)) {
			keys.push_back("Cmdbussref");
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

		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::IMBUF), ref)) {
			if (Wdbe::getMpa(dbswdbe, ref, "maxlen", maxlen)) {
				keys.push_back("maxlenInv"); vals.push_back(maxlen);

				w = Wdbe::valToWidth(atoi(maxlen.c_str()));

				keys.push_back("wLenBuf"); vals.push_back(to_string(w));
				keys.push_back("msbLenBuf"); vals.push_back(to_string(w-1));
			};
		};

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbePlhfpgaCmdinv("", "", ixOpVOpres, 100, keys, vals));
};

// IP cust --- INSERT


