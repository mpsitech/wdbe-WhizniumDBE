/**
	* \file WdbeMtpCplmstbuFsmprobe_Easy_v1_0.cpp
	* Wdbe operation processor - add capture ports and fill vector (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 9 May 2023
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpCplmstbuFsmprobe_Easy_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuFsmprobe_Easy_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuFsmprobe_Easy_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WdbeMModule* mdl = NULL;

	string capts; // ex. tkclksrc.op;camif.stream

	ubigint refVecSrc;
	uint vecNum = 1;

	uint mdlNum = 4;

	vector<string> ss, ss2;

	string sref;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMVector WHERE hkIxVTbl = " + to_string(VecWdbeVMVectorHkTbl::CTR) + " AND hkUref = " + to_string(mdl->refWdbeMController) + " AND sref LIKE 'VecV%Source'", refVecSrc)) {
			if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "capts", capts)) {
				StrMod::stringToVector(capts, ss, ';');

				for (unsigned int i = 0; i < ss.size(); i++) {
					StrMod::stringToVector(ss[i], ss2, '.');

					if (ss2.size() == 2) {
						dbswdbe->tblwdbemvectoritem->insertNewRec(NULL, refVecSrc, vecNum++, ss2[0] + StrMod::cap(ss2[1]), "", "");

						sref = ss2[0] + "State" + StrMod::cap(ss2[1]);
						dbswdbe->tblwdbemport->insertNewRec(NULL, 0, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::DBG, sref, VecWdbeVMPortDir::IN, "slvdn", 8, "", "", "", "", sref + "_dbg", "");
					};
				};

			};
		};

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
