/**
	* \file WdbeMtpCplmstbuDpbram_v1_0.cpp
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

#include "WdbeMtpCplmstbuDpbram_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuDpbram_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuDpbram_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WdbeMModule* mdl = NULL;
	ubigint ref;

	bool mgmtToNotFrom;
	string sref, srefrootMgmt, srefrootCor;

	string size, wA, wB;
	unsigned short wAddr0, wWord;

	uint mdlNum;

	string srefKVendor;

	map<string, string> srefsPrts;
	string srefPrt;

	if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMImbuf WHERE refWdbeMModule = " + to_string(refWdbeMModule), ref)) {
		// write enable default according to inter-module buffer direction
		mgmtToNotFrom = Wdbe::getImbsrefs(dbswdbe, refWdbeMModule, sref, srefrootMgmt, srefrootCor);
		if (!mgmtToNotFrom) Wdbe::setPrtDfv(dbswdbe, refWdbeMModule, "weA", "1");
		else Wdbe::setPrtDfv(dbswdbe, refWdbeMModule, "weB", "1");
	};

	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "size", size))
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wA", wA))
			if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "wB", wB)) {
				// adapt address and data port widths
				wAddr0 = Wdbe::valToWidth(atoi(size.c_str()) * 1024 - 1);

				wWord = atoi(wA.c_str()) / 8;
				Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "aA", wAddr0 - log2(wWord));
				Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "drdA", 8 * wWord);
				Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "dwrA", 8 * wWord);

				wWord = atoi(wB.c_str()) / 8;
				Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "aB", wAddr0 - log2(wWord));
				Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "drdB", 8 * wWord);
				Wdbe::setPrtWdt(dbswdbe, refWdbeMModule, "dwrB", 8 * wWord);
			};

	mdlNum = 1;

	if (dbswdbe->tblwdbemmodule->loadRecBySQL("SELECT * FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'mnfcore'", &mdl)) {
		srefKVendor = Wdbe::getUntVendor(dbswdbe, mdl->hkUref);

		if (srefKVendor == "efnx") {
			srefsPrts["clkA"] = "clk_a";
			srefsPrts["enA"] = "addren_a";
			srefsPrts["weA"] = "we_a.sig"; // slvdn
			srefsPrts["aA"] = "addr_a";
			srefsPrts["dwrA"] = "wdata_a";
			srefsPrts["drdA"] = "rdata_a";

			srefsPrts["clkB"] = "clk_b";
			srefsPrts["enB"] = "addren_b";
			srefsPrts["weB"] = "we_b.sig"; // slvdn
			srefsPrts["aB"] = "addr_b";
			srefsPrts["dwrB"] = "wdata_b";
			srefsPrts["drdB"] = "rdata_b";

		} else if (srefKVendor == "lttc") {
			srefsPrts["rstA"] = "rst_a_i";
			srefsPrts["clkA"] = "clk_a_i";
			srefsPrts["enA"] = "clk_en_a_i";
			srefsPrts["weA"] = "wr_en_a_i";
			srefsPrts["aA"] = "addr_a_i";
			srefsPrts["dwrA"] = "wr_data_a_i";
			srefsPrts["drdA"] = "rd_data_a_o";

			srefsPrts["rstB"] = "rst_b_i";
			srefsPrts["clkB"] = "clk_b_i";
			srefsPrts["enB"] = "clk_en_b_i";
			srefsPrts["weB"] = "wr_en_b_i";
			srefsPrts["aB"] = "addr_b_i";
			srefsPrts["dwrB"] = "wr_data_b_i";
			srefsPrts["drdB"] = "rd_data_b_o";

		} else if (srefKVendor == "mchp") {
			srefsPrts["clkA"] = "A_CLK";
			srefsPrts["enA"] = "A_BLK_EN";
			srefsPrts["weA"] = "A_WEN";
			srefsPrts["aA"] = "A_ADDR";
			srefsPrts["dwrA"] = "A_DIN";
			srefsPrts["drdA"] = "A_DOUT";

			srefsPrts["clkB"] = "B_CLK";
			srefsPrts["enB"] = "B_BLK_EN";
			srefsPrts["weB"] = "B_WEN";
			srefsPrts["aB"] = "B_ADDR";
			srefsPrts["dwrB"] = "B_DIN";
			srefsPrts["drdB"] = "B_DOUT";

		} else if (srefKVendor == "xlnx") {
			srefsPrts["clkA"] = "clkA";
			srefsPrts["enA"] = "enA";
			srefsPrts["weA"] = "weA.sig"; // slvdn
			srefsPrts["aA"] = "addrA";
			srefsPrts["dwrA"] = "dinA";
			srefsPrts["drdA"] = "doutA";

			srefsPrts["clkB"] = "clkB";
			srefsPrts["enB"] = "enB";
			srefsPrts["weB"] = "weB.sig"; // slvdn
			srefsPrts["aB"] = "addrB";
			srefsPrts["dwrB"] = "dinB";
			srefsPrts["drdB"] = "doutB";
		};

		for (auto it = srefsPrts.begin(); it != srefsPrts.end(); it++) {
			srefPrt = it->second;

			if ((srefPrt.length() > 4) && ((srefPrt.rfind(".sig") + 4) == srefPrt.length())) {
				srefPrt = srefPrt.substr(0, srefPrt.length() - 4);

				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, 0, srefPrt + "_sig", false, "slvdn", 1, "", "", "", "", 0, it->first);

				Wdbe::setPrtCsi(dbswdbe, mdl->ref, srefPrt, srefPrt + "_sig");

			} else Wdbe::setPrtCpr(dbswdbe, mdl->ref, it->second, it->first);
		};

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
