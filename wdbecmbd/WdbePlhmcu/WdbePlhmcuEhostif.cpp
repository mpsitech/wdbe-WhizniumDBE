/**
	* \file WdbePlhmcuEhostif.cpp
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

#include "WdbePlhmcuEhostif.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbePlhmcu;

/******************************************************************************
 namespace WdbePlhmcuEhostif
 ******************************************************************************/

DpchRetWdbePlhmcuEhostif* WdbePlhmcuEhostif::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbePlhmcuEhostif* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	std::vector<std::string> keys;
	std::vector<std::string> vals;

	// IP run --- IBEGIN

	// exact copy from WdbePlhfpgaEhostif

	// Hostifsref
	// sizeRxbuf, sizeTxbuf

	vector<ubigint> refs, refs2;

	WdbeMModule* mdl = NULL;

	unsigned int sizeRxbuf, sizeTxbuf;

	unsigned int len;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		keys.push_back("Hostifsref");
		vals.push_back(StrMod::cap(mdl->sref));

		sizeRxbuf = 2;
		sizeTxbuf = 2;

		dbswdbe->loadRefsBySQL("SELECT refWdbeMController FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::ECTR), false, refs);

		for (unsigned int i = 0; i < refs.size();i++) {
			dbswdbe->loadRefsBySQL("SELECT ref FROM TblWdbeMCommand WHERE refIxVTbl = " + to_string(VecWdbeVMCommandRefTbl::CTR) + " AND refUref = " + to_string(refs[i]), false, refs2);

			for (unsigned int j = 0; j < refs2.size();j++) {
				len = Wdbe::getLenInv(dbswdbe, refs2[j]) + 2;
				if (len > sizeRxbuf) sizeRxbuf = len;

				len = Wdbe::getLenRet(dbswdbe, refs2[j]) + 2;
				if (len > sizeTxbuf) sizeTxbuf = len;
			};
		};

		keys.push_back("sizeRxbuf");
		vals.push_back(to_string(sizeRxbuf));
		keys.push_back("sizeTxbuf");
		vals.push_back(to_string(sizeTxbuf));

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbePlhmcuEhostif("", "", ixOpVOpres, 100, keys, vals));
};

// IP cust --- INSERT



