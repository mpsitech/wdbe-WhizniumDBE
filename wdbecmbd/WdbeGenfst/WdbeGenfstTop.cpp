/**
	* \file WdbeGenfstTop.cpp
	* Wdbe operation processor - add reset process (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 16 Oct 2021
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeGenfstTop.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeGenfst;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeGenfstTop
 ******************************************************************************/

DpchRetWdbe* WdbeGenfstTop::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeGenfstTop* dpchinv
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

	ubigint refC;
	ubigint refPrc;

	uint refNum;

	double ratio;
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

		for (unsigned int i = 0; i < NClk; i++) {
			refPrc = dbswdbe->tblwdbemprocess->insertNewRec(NULL, mdl->ref, 0, clks[i], clks[i], (aresetNNotP) ? "aresetn" : "areset", false, "", false, clks[i] + " wiring and reset");

			refC = dbswdbe->tblwdbecvariable->getNewRef();
			dbswdbe->tblwdbemvariable->insertNewRec(NULL, refC, VecWdbeVMVariableRefTbl::PRC, refPrc, 1, "imax", true, false, "nat", 0, "", "", (i == 0) ? "16" : ("(16*f" + StrMod::cap(clks[i]) + ")/f" + StrMod::cap(clks[0]) + "+1"), false, "");
			dbswdbe->tblwdbemvariable->insertNewRec(NULL, refC, VecWdbeVMVariableRefTbl::PRC, refPrc, 2, "i", false, false, "nat", 0, "0..imax", "", "0", false, "");

			if (i == 0) {
				ratio = 1.0;

				for (unsigned int j = 1; j < NClk; j++) if (fClks[j] < fClks[0]) ratio = fClks[0]/fClks[j];

				refC = dbswdbe->tblwdbecvariable->getNewRef();
				dbswdbe->tblwdbemvariable->insertNewRec(NULL, refC, VecWdbeVMVariableRefTbl::PRC, refPrc, 3, "jmax", true, false, "nat", 0, "", "", to_string(lround(ceil(ratio))), false, "");
				dbswdbe->tblwdbemvariable->insertNewRec(NULL, refC, VecWdbeVMVariableRefTbl::PRC, refPrc, 4, "j", false, false, "nat", 0, "0..jmax", "", "0", false, "");
			};

			refNum = Wdbe::getNextSigRefNum(dbswdbe, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule);

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, refNum++, VecWdbeVMSignalMgeTbl::PRC, refPrc, 0, (i == 0) ? "reset" : ("reset" + StrMod::cap(clks[i])), false, "sl", 1, "", "", "", "1", false, 0, "");
			if (fAclk == fClks[i]) dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, refNum++, VecWdbeVMSignalMgeTbl::PRC, refPrc, 0, clks[i], false, "sl", 1, "", "*", "", (aclkIntNotExt || aclkDiffNotSng) ? "aclk" : "aclk_sig", false, 0, "");
		};


		delete mdl;
	};
///
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
