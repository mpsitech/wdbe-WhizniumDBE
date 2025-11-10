/**
	* \file WdbeMtpCplmstbuTop_v1_0.cpp
	* Wdbe operation processor - connect clock primitives (implementation)
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

#include "WdbeMtpCplmstbuTop_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpCplmstbu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmstbuTop_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpCplmstbuTop_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpCplmstbu* dpchinv
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

	ubigint ref;

	uint mdlNum = 1;

	ubigint refGBUFCE;
	ubigint refOscAclk, refIB, refPll;
	ubigint refCLKBUF, refINBUF_DIFF, refCcc;
	ubigint refBUFG, refIBUFGDS, refMmcm;

	string srefKVendor;

	bool haseq, hasneq;

	string Clk;
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

		srefKVendor = Wdbe::getMdlVendor(dbswdbe, refWdbeMModule);

		// use same decision tree as in Cplmsttd

		// - add root clock wiring
		haseq = false;
		hasneq = false;
		for (unsigned int i = 0; i < NClk; i++)
			if (fAclk == fClks[i]) haseq = true;
			else hasneq = true;

		if (srefKVendor == "efnx") {
			if (haseq) {
				refGBUFCE = 0; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'gbufceAclk'", refGBUFCE);

				if (refGBUFCE != 0) {
					dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, refGBUFCE, 0, "aclk_sig", false, "sl", 1, "", "", "", "0", 0, "");

					Wdbe::setPrtDfv(dbswdbe, refGBUFCE, "CE", "1");
					Wdbe::setPrtCpi(dbswdbe, refGBUFCE, "I", "aclk");
					Wdbe::setPrtCsi(dbswdbe, refGBUFCE, "O", "aclk_sig");
				};
			};

		} else if (srefKVendor == "lttc") {
			if (aclkIntNotExt) {
				refOscAclk = 0; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'oscAclk'", refOscAclk);

				if (refOscAclk != 0) {
					dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, ref, 0, "aclk", false, "sl", 1, "", "", "", "0", 0, "");

					Wdbe::setPrtDfv(dbswdbe, refOscAclk, "hf_out_en_i", "1");
					Wdbe::setPrtCsi(dbswdbe, refOscAclk, "hf_clk_out_o", "aclk");
				};

			} else if (haseq) {
				refIB = 0; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'ibAclk'", refIB);

				if (refIB != 0) {
					dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, refIB, 0, "aclk_sig", false, "sl", 1, "", "", "", "0", 0, "");

					Wdbe::setPrtCpi(dbswdbe, refIB, "I", "aclk");
					Wdbe::setPrtCsi(dbswdbe, refIB, "O", "aclk_sig");
				};
			};

		} else if (srefKVendor == "mchp") {
			if (haseq || (hasneq && aclkDiffNotSng)) {
				if (!aclkDiffNotSng) {
					refCLKBUF = 0; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'clkbufAclk'", refCLKBUF);

					if (refCLKBUF != 0) {
						dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, refCLKBUF, 0, "aclk_sig", false, "sl", 1, "", "", "", "0", 0, "");

						Wdbe::setPrtCpi(dbswdbe, refCLKBUF, "PAD", "aclk");
						Wdbe::setPrtCsi(dbswdbe, refCLKBUF, "Y", "aclk_sig");
					};

				} else {
					refINBUF_DIFF = 0; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'inbuf_diffAclk'", refINBUF_DIFF);

					if (refINBUF_DIFF != 0) {
						dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, refINBUF_DIFF, 0, "aclk", false, "sl", 1, "", "", "", "0", 0, "");

						Wdbe::setPrtCpi(dbswdbe, refINBUF_DIFF, "PADP", "aclkp");
						Wdbe::setPrtCpi(dbswdbe, refINBUF_DIFF, "PADN", "aclkn");
						Wdbe::setPrtCsi(dbswdbe, refINBUF_DIFF, "Y", "aclk");
					};
				};
			};

		} else if (srefKVendor == "xlnx") {
			if (haseq || (hasneq && aclkDiffNotSng)) {
				if (!aclkDiffNotSng) {
					refBUFG = 0; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'bufgAclk'", refBUFG);

					if (refBUFG != 0) {
						dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, refBUFG, 0, "aclk_sig", false, "sl", 1, "", "", "", "0", 0, "");

						Wdbe::setPrtCpi(dbswdbe, refBUFG, "I", "aclk");
						Wdbe::setPrtCsi(dbswdbe, refBUFG, "O", "aclk_sig");
					};

				} else {
					refIBUFGDS = 0; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'ibufgdsAclk'", refIBUFGDS);

					if (refIBUFGDS != 0) {
						dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, refIBUFGDS, 0, "aclk", false, "sl", 1, "", "", "", "0", 0, "");

						Wdbe::setPrtCpi(dbswdbe, refIBUFGDS, "I", "aclkp");
						Wdbe::setPrtCpi(dbswdbe, refIBUFGDS, "IB", "aclkn");
						Wdbe::setPrtCsi(dbswdbe, refIBUFGDS, "O", "aclk");
					};
				};
			};
		};

		// - add design clock wiring
		for (unsigned int i = 0; i < NClk; i++) {
			Clk = StrMod::cap(clks[i]);

			if (srefKVendor == "efnx") {
				if (fAclk != fClks[i]) {
					// skip for now: port and signal would have the same sref
				};

			} else if (srefKVendor == "lttc") {
				if (fAclk != fClks[i]) {
					if (!clkIntNotExts[i]) {
						if (!clkDiffNotSngs[i]) {
							// skip for now: port and signal would have the same sref
						} else {
							// TBD
						};

					} else {
						refPll = 0; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'pll" + Clk + "'", refPll);

						if (refPll != 0) {
							dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, refPll, 0, clks[i], false, "sl", 1, "", "", "", "0", 0, "");

							Wdbe::setPrtDfv(dbswdbe, refPll, "rstn_i", "1");
							if (!aclkIntNotExt) Wdbe::setPrtCpi(dbswdbe, refPll, "clki_i", "aclk");
							else Wdbe::setPrtCsi(dbswdbe, refPll, "clki_i", "aclk");
							Wdbe::setPrtCsi(dbswdbe, refPll, "clkop_o", clks[i]);
						};
					};
				};

			} else if (srefKVendor == "mchp") {
				if (fAclk != fClks[i]) {
					if (!clkIntNotExts[i]) {
						if (!clkDiffNotSngs[i]) {
							// TBD

						} else {
							refINBUF_DIFF = 0; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'inbuf_diff" + Clk +  "'", refINBUF_DIFF);

							if (refINBUF_DIFF != 0) {
								dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, refINBUF_DIFF, 0, clks[i], false, "sl", 1, "", "", "", "0", 0, "");

								Wdbe::setPrtCpi(dbswdbe, refINBUF_DIFF, "PADP", clks[i] + "p");
								Wdbe::setPrtCpi(dbswdbe, refINBUF_DIFF, "PADN", clks[i] + "n");
								Wdbe::setPrtCsi(dbswdbe, refINBUF_DIFF, "Y", clks[i]);
							};
						};

					} else {
						refCcc = 0; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'ccc" + Clk + "'", refCcc);

						if (refCcc != 0) {
							dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, refCcc, 0, clks[i], false, "sl", 1, "", "", "", "0", 0, "");

							Wdbe::setPrtDfv(dbswdbe, refCcc, "PLL_POWERDOWN_N_0", "0");
							if (!aclkIntNotExt) Wdbe::setPrtCpi(dbswdbe, refCcc, "REF_CLK_0", "aclk");
							else Wdbe::setPrtCsi(dbswdbe, refCcc, "REF_CLK_0", "aclk");
							Wdbe::setPrtCsi(dbswdbe, refCcc, "OUT0_FABCLK_0", clks[i]);
						};
					};
				};

			} else if (srefKVendor == "xlnx") {
				if (fAclk != fClks[i]) {
					if (!clkIntNotExts[i]) {
						if (!clkDiffNotSngs[i]) {
							// TBD

						} else {
							refIBUFGDS = 0; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'ibufgds" + Clk + "'", refIBUFGDS);

							if (refIBUFGDS != 0) {
								dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, refIBUFGDS, 0, clks[i], false, "sl", 1, "", "", "", "0", 0, "");

								Wdbe::setPrtCpi(dbswdbe, refIBUFGDS, "I", clks[i] + "p");
								Wdbe::setPrtCpi(dbswdbe, refIBUFGDS, "IB", clks[i] + "n");
								Wdbe::setPrtCsi(dbswdbe, refIBUFGDS, "O", clks[i]);
							};
						};

					} else {
						refMmcm = 0; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'mmcm" + Clk + "'", refMmcm);

						if (refMmcm != 0) {
							dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::MDL, refMmcm, 0, clks[i], false, "sl", 1, "", "", "", "0", 0, "");

							Wdbe::setPrtDfv(dbswdbe, refMmcm, "reset", "0");
							if (!aclkIntNotExt) Wdbe::setPrtCpi(dbswdbe, refMmcm, "clk_in1", "aclk");
							else Wdbe::setPrtCsi(dbswdbe, refMmcm, "clk_in1", "aclk");
							Wdbe::setPrtCsi(dbswdbe, refMmcm, "clk_out1", clks[i]);
						};
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
