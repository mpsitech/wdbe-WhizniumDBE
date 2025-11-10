/**
	* \file WdbeMtpCplmstbuSpbram_v1_0.cpp
	* Wdbe operation processor - adapt port widths, connect buffer (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 19 Oct 2025
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpCplmstbuSpbram_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuSpbram_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuSpbram_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WdbeMModule* mdl = NULL;

	string size, w;
	unsigned short wAddr0, wWord;

	uint mdlNum;

	string srefKVendor;

	map<string, string> srefsPrts;
	string srefPrt;

	vector<string> ss;

	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "size", size))
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "w", w)) {
			// adapt address and data port widths
			wAddr0 = Wdbe::valToWidth(atoi(size.c_str()) * 1024 - 1);

			wWord = atoi(w.c_str()) / 8;
			Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "aA", wAddr0 - log2(wWord));
			Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "drdA", 8 * wWord);
			Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "dwrA", 8 * wWord);
		};

	mdlNum = 1;

	if (dbswdbe->tblwdbemmodule->loadRecBySQL("SELECT * FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'mnfcore'", &mdl)) {
		srefKVendor = Wdbe::getUntVendor(dbswdbe, mdl->hkUref);

		if (srefKVendor == "efnx") {
			srefsPrts["clk"] = "clk";
			srefsPrts["en"] = "addren";
			srefsPrts["we"] = "we_a.sig"; // slvdn
			srefsPrts["a"] = "addr";
			srefsPrts["dwr"] = "wdata_a";
			srefsPrts["drd"] = "rdata_a";

		} else if (srefKVendor == "lttc") {
			srefsPrts["rst"] = "rst_i";
			srefsPrts["clk"] = "clk_i";
			srefsPrts["en"] = "clk_en_i";
			srefsPrts["we"] = "wr_en_i";
			srefsPrts["a"] = "addr_i";
			srefsPrts["dwr"] = "wr_data_i";
			srefsPrts["drd"] = "rd_data_o";

		} else if (srefKVendor == "mchp") {
			srefsPrts["clk"] = "CLK";
			srefsPrts["en"] = "R_EN.sig;W_EN.sig"; // R_EN_sig <= en and not we, W_EN <= en and we
			srefsPrts["a"] = "R_ADDR;W_ADDR";
			srefsPrts["dwr"] = "W_DATA";
			srefsPrts["drd"] = "R_DATA";

		} else if (srefKVendor == "xlnx") {
			srefsPrts["clk"] = "clk";
			srefsPrts["en"] = "en";
			srefsPrts["we"] = "we.sig"; // slvdn
			srefsPrts["a"] = "addr";
			srefsPrts["dwr"] = "din";
			srefsPrts["drd"] = "dout";
		};

		for (auto it = srefsPrts.begin(); it != srefsPrts.end(); it++) {
			StrMod::stringToVector(it->second, ss, ';');

			for (unsigned int i = 0; i < ss.size(); i++) {
				srefPrt = ss[i];

				if ((srefPrt.length() > 4) && ((srefPrt.rfind(".sig") + 4) == srefPrt.length())) {
					srefPrt = srefPrt.substr(0, srefPrt.length() - 4);

					if (srefPrt == "R_EN") dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, srefPrt + "_sig", false, "sl", 1, "", "", "", "", 0, "en and not we");
					else if (srefPrt == "W_EN") dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, srefPrt + "_sig", false, "sl", 1, "", "", "", "", 0, "en and we");
					else dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, srefPrt + "_sig", false, "slvdn", 1, "", "", "", "", 0, it->first);

					Wdbe::setPrtCsi(dbswdbe, mdl->ref, srefPrt, srefPrt + "_sig");

				} else Wdbe::setPrtCpr(dbswdbe, mdl->ref, it->second, it->first);
			};
		};

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
