/**
	* \file WdbeMtpCplmsttdTop_v1_0.cpp
	* Wdbe operation processor - infer clock primitives and adapt ports (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Apr 2023
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpCplmsttdTop_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmsttd;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmsttdTop_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmsttdTop_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmsttd* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WdbeMModule* mdl = NULL;

	bool aresetNNotP;
	double fAclk;
	bool aclkIntNotExt;
	bool aclkDiffNotSng;

	unsigned int NClk;

	vector<string> clks;
	vector<double> fClks;
	vector<bool> clkIntNotExts;
	vector<bool> clkDiffNotSngs;

	vector<string> ss;
	string s;
	///

	ubigint ref, refC;

	ListWdbeMPort prts;
	WdbeMPort* prt = NULL;

	uint mdlNum;

	string srefKVendor;

	bool haseq, hasneq;

	string Clk;
	string divstr;
	///

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		aresetNNotP = false;
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "aresetNNotP", s)) aresetNNotP = (s == "true");

		fAclk = 100000.0;
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "fAclk", s)) fAclk = atof(s.c_str());

		aclkIntNotExt = false;
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "aclkIntNotExt", s)) aclkIntNotExt = (s == "true");

		aclkDiffNotSng = true;
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "aclkDiffNotSng", s)) aclkDiffNotSng = (s == "true");

		NClk = 1;
		clks.resize(NClk, "mclk");

		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "clks", s)) {
			StrMod::stringToVector(s, ss);

			if (ss.size() > 1) {
				NClk = ss.size();
				clks.resize(NClk, "mclk");
			};

			for (unsigned int i = 0; i < NClk; i++) clks[i] = ss[i];
		};

		fClks.resize(NClk, fAclk);
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "fClks", s)) {
			StrMod::stringToVector(s, ss);
			if (ss.size() == NClk) for (unsigned int i = 0; i < NClk; i++) fClks[i] = atof(ss[i].c_str());
		};

		clkIntNotExts.resize(NClk, false);
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "clkIntNotExts", s)) {
			StrMod::stringToVector(s, ss);
			if (ss.size() == NClk) for (unsigned int i = 0; i < NClk; i++) clkIntNotExts[i] = (ss[i] == "true");
		};

		clkDiffNotSngs.resize(NClk, true);
		if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "clkDiffNotSngs", s)) {
			StrMod::stringToVector(s, ss);
			if (ss.size() == NClk) for (unsigned int i = 0; i < NClk; i++) clkDiffNotSngs[i] = (ss[i] == "true");
		};
		///

		srefKVendor = Wdbe::getUntVendor(dbswdbe, mdl->hkUref);

		// - add generics
		mdlNum = 1;

		dbswdbe->tblwdbemgeneric->insertNewRec(NULL, 0, mdl->ref, mdlNum++, "fAclk", "nat", 0, "", to_string(lround(fAclk)), "", "");
		for (unsigned int i = 0; i < NClk; i++) dbswdbe->tblwdbemgeneric->insertNewRec(NULL, 0, mdl->ref, mdlNum++, "f" + StrMod::cap(clks[i]), "nat", 0, "", to_string(lround(fClks[i])), "", "");

		// - configure root clock ports
		dbswdbe->tblwdbemport->loadRstByMdl(refWdbeMModule, false, prts);

		mdlNum = 4;

		for (unsigned int i = 0; i < prts.nodes.size(); i++) {
			prt = prts.nodes[i];

			if (prt->sref == "areset") {
				if (aresetNNotP) prt->sref = "aresetn";
				//prt->cpiSrefWdbeMPin = prt->sref;

				dbswdbe->tblwdbemport->updateRec(prt);

			} else if (prt->sref == "aclkp") {
				if (aclkIntNotExt) {
					dbswdbe->tblwdbemport->removeRecByRef(prt->ref);
					mdlNum--;

				} else if (!aclkDiffNotSng) {
					prt->refWdbeCPort = 0;
					prt->sref = "aclk";
				};
				//prt->cpiSrefWdbeMPin = prt->sref;

				dbswdbe->tblwdbemport->updateRec(prt);

			} else if (prt->sref == "aclkn") {
				if (aclkIntNotExt || !aclkDiffNotSng) {
					dbswdbe->tblwdbemport->removeRecByRef(prt->ref);
					mdlNum--;

				} else {
					//prt->cpiSrefWdbeMPin = prt->sref;

					dbswdbe->tblwdbemport->updateRec(prt);
				};
			};
		};

		// - add design clock ports
		for (unsigned int i = 0; i < NClk; i++)
			if (!clkIntNotExts[i]) {
				if (!clkDiffNotSngs[i]) refC = 0;
				else refC = dbswdbe->tblwdbecport->getNewRef();

				dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::CLK, (clkDiffNotSngs[i]) ? (clks[i] + "p") : clks[i], VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", "", "");
				if (clkDiffNotSngs[i]) dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::CLK, clks[i] + "n", VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", "", "");
			};

		// - add root clock conditioning
		haseq = false;
		hasneq = false;
		for (unsigned int i = 0; i < NClk; i++)
			if (fAclk == fClks[i]) haseq = true;
			else hasneq = true;

		if (srefKVendor == "efnx") {
			// aclkIntNotExt always false, differential buffer handled outside
			if (haseq) {
				dbswdbe->executeQuery("UPDATE TblWdbeMModule SET hkNum = hkNum + 1 WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND hkNum > " + to_string(mdl->hkNum));
				dbswdbe->tblwdbemmodule->insertNewRec(NULL, VecWdbeVMModuleBasetype::MNFPRIM, mdl->hkIxVTbl, mdl->hkUref, ++(mdl->hkNum), mdl->ref, Wdbe::getRefMtp(dbswdbe, "EFX_GBUFCE"), 0, 0, "gbufceAclk", "", "", "");
			};
			
		} else if (srefKVendor == "lttc") {
			if (aclkIntNotExt) {
				// internal oscillator generates aclk
				dbswdbe->executeQuery("UPDATE TblWdbeMModule SET hkNum = hkNum + 1 WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND hkNum > " + to_string(mdl->hkNum));

				divstr = getDivstr(450000.0 / fAclk);

				ref = dbswdbe->tblwdbemmodule->insertNewRec(NULL, VecWdbeVMModuleBasetype::MNFPRIM, mdl->hkIxVTbl, mdl->hkUref, ++(mdl->hkNum), mdl->ref, Wdbe::getRefMtp(dbswdbe, "osc_lttc_v1_3"), 0, 0, "oscAclk", "", "", "");
				Wdbe::setMpa(dbswdbe, ref, "div", divstr);

			} else if (haseq) {
				dbswdbe->executeQuery("UPDATE TblWdbeMModule SET hkNum = hkNum + 1 WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND hkNum > " + to_string(mdl->hkNum));
				dbswdbe->tblwdbemmodule->insertNewRec(NULL, VecWdbeVMModuleBasetype::MNFPRIM, mdl->hkIxVTbl, mdl->hkUref, ++(mdl->hkNum), mdl->ref, Wdbe::getRefMtp(dbswdbe, "IB"), 0, 0, "ibAclk", "", "", "");
			};

		} else if (srefKVendor == "mchp") {
			// aclkIntNotExt always false
			if (haseq || (hasneq && aclkDiffNotSng)) {
				dbswdbe->executeQuery("UPDATE TblWdbeMModule SET hkNum = hkNum + 1 WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND hkNum > " + to_string(mdl->hkNum));

				if (!aclkDiffNotSng) {
					dbswdbe->tblwdbemmodule->insertNewRec(NULL, VecWdbeVMModuleBasetype::MNFPRIM, mdl->hkIxVTbl, mdl->hkUref, ++(mdl->hkNum), mdl->ref, Wdbe::getRefMtp(dbswdbe, "CLKBUF"), 0, 0, "clkbufAclk", "", "", "");
				} else {
					dbswdbe->tblwdbemmodule->insertNewRec(NULL, VecWdbeVMModuleBasetype::MNFPRIM, mdl->hkIxVTbl, mdl->hkUref, ++(mdl->hkNum), mdl->ref, Wdbe::getRefMtp(dbswdbe, "INBUF_DIFF"), 0, 0, "inbuf_diffAclk", "", "", "");
				};
			};

		} else if (srefKVendor == "xlnx") {
			// aclkIntNotExt always false
			if (haseq || (hasneq && aclkDiffNotSng)) {
				dbswdbe->executeQuery("UPDATE TblWdbeMModule SET hkNum = hkNum + 1 WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND hkNum > " + to_string(mdl->hkNum));

				if (!aclkDiffNotSng) {
					dbswdbe->tblwdbemmodule->insertNewRec(NULL, VecWdbeVMModuleBasetype::MNFPRIM, mdl->hkIxVTbl, mdl->hkUref, ++(mdl->hkNum), mdl->ref, Wdbe::getRefMtp(dbswdbe, "BUFG"), 0, 0, "bufgAclk", "", "", "");
				} else {
					dbswdbe->tblwdbemmodule->insertNewRec(NULL, VecWdbeVMModuleBasetype::MNFPRIM, mdl->hkIxVTbl, mdl->hkUref, ++(mdl->hkNum), mdl->ref, Wdbe::getRefMtp(dbswdbe, "IBUFGDS"), 0, 0, "ibufgdsAclk", "", "", "");
				};
			};
		};

		// - add design clock conditioning
		for (unsigned int i = 0; i < NClk; i++) {
			Clk = StrMod::cap(clks[i]);

			if (srefKVendor == "efnx") {
				// clkIntNotExt always false, differential buffer and PLL handled outside
				if (fAclk != fClks[i]) {
					// skip for now: port and signal would have the same sref
					//dbswdbe->executeQuery("UPDATE TblWdbeMModule SET hkNum = hkNum + 1 WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND hkNum > " + to_string(mdl->hkNum));
					//dbswdbe->tblwdbemmodule->insertNewRec(NULL, VecWdbeVMModuleBasetype::MNFPRIM, mdl->hkIxVTbl, mdl->hkUref, ++(mdl->hkNum), mdl->ref, Wdbe::getRefMtp(dbswdbe, "EFX_GBUFCE"), 0, 0, "gbufce" + Clk, "", "", "");
				};

			} else if (srefKVendor == "lttc") {
				if (fAclk != fClks[i]) {
					dbswdbe->executeQuery("UPDATE TblWdbeMModule SET hkNum = hkNum + 1 WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND hkNum > " + to_string(mdl->hkNum));

					if (!clkIntNotExts[i]) {
						if (!clkDiffNotSngs[i]) {
							// skip for now: port and signal would have the same sref
							//dbswdbe->tblwdbemmodule->insertNewRec(NULL, VecWdbeVMModuleBasetype::MNFPRIM, mdl->hkIxVTbl, mdl->hkUref, ++(mdl->hkNum), mdl->ref, Wdbe::getRefMtp(dbswdbe, "IB"), 0, 0, "ib" + Clk, "", "", "");
						} else {
							// TBD
						};

					} else {
						// PLL generates clk
						divstr = getDivstr(fAclk / fClks[i]);

						ref = dbswdbe->tblwdbemmodule->insertNewRec(NULL, VecWdbeVMModuleBasetype::MNFCORE, mdl->hkIxVTbl, mdl->hkUref, ++(mdl->hkNum), mdl->ref, Wdbe::getRefMtp(dbswdbe, "pll_lttc_v1_6"), 0, 0, "pll" + Clk, "", "", "");
						Wdbe::setMpa(dbswdbe, ref, "div", divstr);
					};
				};

			} else if (srefKVendor == "mchp") {
				if (fAclk != fClks[i]) {
					dbswdbe->executeQuery("UPDATE TblWdbeMModule SET hkNum = hkNum + 1 WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND hkNum > " + to_string(mdl->hkNum));

					if (!clkIntNotExts[i]) {
						if (!clkDiffNotSngs[i]) {
							// TBD
						} else {
							dbswdbe->tblwdbemmodule->insertNewRec(NULL, VecWdbeVMModuleBasetype::MNFPRIM, mdl->hkIxVTbl, mdl->hkUref, ++(mdl->hkNum), mdl->ref, Wdbe::getRefMtp(dbswdbe, "INBUF_DIFF"), 0, 0, "inbuf_diff" + Clk, "", "", "");
						};

					} else {
						// CCC generates clk
						divstr = getDivstr(fAclk / fClks[i]);

						ref = dbswdbe->tblwdbemmodule->insertNewRec(NULL, VecWdbeVMModuleBasetype::MNFCORE, mdl->hkIxVTbl, mdl->hkUref, ++(mdl->hkNum), mdl->ref, Wdbe::getRefMtp(dbswdbe, "ccc_mchp_v1_0"), 0, 0, "ccc" + Clk, "", "", "");
						Wdbe::setMpa(dbswdbe, ref, "div", divstr);
					};
				};

			} else if (srefKVendor == "xlnx") {
				if (fAclk != fClks[i]) {

					if (!clkIntNotExts[i]) {
						if (!clkDiffNotSngs[i]) {
							// TBD
						} else {
							dbswdbe->tblwdbemmodule->insertNewRec(NULL, VecWdbeVMModuleBasetype::MNFPRIM, mdl->hkIxVTbl, mdl->hkUref, mdl->hkNum + 1, mdl->ref, Wdbe::getRefMtp(dbswdbe, "IBUFGDS"), 0, 0, "ibufgds" + Clk, "", "", "");
						};

					} else {
						// MMCM generates clk
						divstr = getDivstr(fAclk / fClks[i]);

						ref = dbswdbe->tblwdbemmodule->insertNewRec(NULL, VecWdbeVMModuleBasetype::MNFCORE, mdl->hkIxVTbl, mdl->hkUref, mdl->hkNum+2, mdl->ref, Wdbe::getRefMtp(dbswdbe, "mmcm_xlnx_v5_4"), 0, 0, "mmcm" + Clk, "", "", "");
						Wdbe::setMpa(dbswdbe, ref, "div", divstr);
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
