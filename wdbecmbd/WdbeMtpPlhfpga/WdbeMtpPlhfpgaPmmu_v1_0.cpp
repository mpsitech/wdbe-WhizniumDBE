/**
	* \file WdbeMtpPlhfpgaPmmu_v1_0.cpp
	* Wdbe operation processor -  (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpPlhfpgaPmmu_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpPlhfpga;

/******************************************************************************
 namespace WdbeMtpPlhfpgaPmmu_v1_0
 ******************************************************************************/

DpchRetWdbeMtpPlhfpga* WdbeMtpPlhfpgaPmmu_v1_0::run(
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
	// CorsrefInbuf0, CorsrefOutbuf0
	// pgsizeMem=40, sizePg=4096
	// sizeMem=163840
	// msbAp1Mem=17, wAp1Mem=18
	// msbAInoutbuf=12
	// wAPg=6

	// sizeTocbuf=2048
	// wATocbuf=11

	// slot=140

	string sref;

	string pgsizeMem, sizePg, sizeTocbuf, slot;
	unsigned int size;
	usmallint wA, wAp1, wPg;

	if (dbswdbe->loadStringBySQL("SELECT TblWdbeMModule2.sref FROM TblWdbeMModule AS TblWdbeMModule1, TblWdbeMImbuf, TblWdbeMModule AS TblWdbeMModule2  WHERE TblWdbeMModule1.supRefWdbeMModule = " + to_string(refWdbeMModule)
				+ " AND TblWdbeMImbuf.refWdbeMModule = TblWdbeMModule1.ref AND TblWdbeMModule1.sref = 'inbuf0' AND TblWdbeMModule2.ref = TblWdbeMImbuf.corRefWdbeMModule", sref)) {
		keys.push_back("CorsrefInbuf0");
		vals.push_back(StrMod::cap(sref));
	};
	if (dbswdbe->loadStringBySQL("SELECT TblWdbeMModule2.sref FROM TblWdbeMModule AS TblWdbeMModule1, TblWdbeMImbuf, TblWdbeMModule AS TblWdbeMModule2  WHERE TblWdbeMModule1.supRefWdbeMModule = " + to_string(refWdbeMModule)
				+ " AND TblWdbeMImbuf.refWdbeMModule = TblWdbeMModule1.ref AND TblWdbeMModule1.sref = 'outbuf0' AND TblWdbeMModule2.ref = TblWdbeMImbuf.corRefWdbeMModule", sref)) {
		keys.push_back("CorsrefOutbuf0");
		vals.push_back(StrMod::cap(sref));
	};

	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "pgsizeMem", pgsizeMem)) {
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "sizePg", sizePg)) {
			size = atoi(pgsizeMem.c_str()) * 1024*atoi(sizePg.c_str());
			wA = Wdbe::valToWidth(size-1);
			wAp1 = Wdbe::valToWidth(size);
			wPg = Wdbe::valToWidth(1024*atoi(sizePg.c_str())-1);

			keys.push_back("pgsizeMem");
			vals.push_back(pgsizeMem);

			keys.push_back("sizePg");
			vals.push_back(to_string(1024*atoi(sizePg.c_str())));

			keys.push_back("sizeMem");
			vals.push_back(to_string(size));

			keys.push_back("msbAp1Mem");
			vals.push_back(to_string(wAp1-1));

			keys.push_back("wAp1Mem");
			vals.push_back(to_string(wAp1));

			keys.push_back("msbAInoutbuf");
			vals.push_back(to_string(wPg)); // inbuf0/outbuf0 is 2x page size

			keys.push_back("wAPg");
			vals.push_back(to_string(wA-wPg));
		};
	};

	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "sizeTocbuf", sizeTocbuf)) {
		wA = Wdbe::valToWidth(1024*atoi(sizeTocbuf.c_str())-1);

		keys.push_back("sizeTocbuf");
		vals.push_back(to_string(1024*atoi(sizeTocbuf.c_str())));

		keys.push_back("wATocbuf");
		vals.push_back(to_string(wA));
	};

	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "slot", slot)) {
		keys.push_back("slot");
		vals.push_back(slot);
	};
	// IP run --- IEND

	return(new DpchRetWdbeMtpPlhfpga("", "", ixOpVOpres, 100, keys, vals));
};

// IP cust --- INSERT


