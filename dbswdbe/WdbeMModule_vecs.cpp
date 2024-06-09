/**
	* \file WdbeMModule_vecs.cpp
	* database access for table TblWdbeMModule (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWdbeMModule::VecVBasetype
 ******************************************************************************/

uint TblWdbeMModule::VecVBasetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "top") return TOP;
	if (s == "hostif") return HOSTIF;
	if (s == "ehostif") return EHOSTIF;
	if (s == "cmdbus") return CMDBUS;
	if (s == "cmdinv") return CMDINV;
	if (s == "cmdret") return CMDRET;
	if (s == "imbuf") return IMBUF;
	if (s == "mnfcore") return MNFCORE;
	if (s == "mnfprim") return MNFPRIM;
	if (s == "ctr") return CTR;
	if (s == "ectr") return ECTR;
	if (s == "dbg") return DBG;
	if (s == "dbgctr") return DBGCTR;
	if (s == "edbgctr") return EDBGCTR;
	if (s == "oth") return OTH;

	return(0);
};

string TblWdbeMModule::VecVBasetype::getSref(
			const uint ix
		) {
	if (ix == TOP) return("top");
	if (ix == HOSTIF) return("hostif");
	if (ix == EHOSTIF) return("ehostif");
	if (ix == CMDBUS) return("cmdbus");
	if (ix == CMDINV) return("cmdinv");
	if (ix == CMDRET) return("cmdret");
	if (ix == IMBUF) return("imbuf");
	if (ix == MNFCORE) return("mnfcore");
	if (ix == MNFPRIM) return("mnfprim");
	if (ix == CTR) return("ctr");
	if (ix == ECTR) return("ectr");
	if (ix == DBG) return("dbg");
	if (ix == DBGCTR) return("dbgctr");
	if (ix == EDBGCTR) return("edbgctr");
	if (ix == OTH) return("oth");

	return("");
};

string TblWdbeMModule::VecVBasetype::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == TOP) return("top");
		if (ix == HOSTIF) return("host interface");
		if (ix == EHOSTIF) return("easy model host interface");
		if (ix == CMDBUS) return("command bus controller");
		if (ix == CMDINV) return("command invocation buffer");
		if (ix == CMDRET) return("command return buffer");
		if (ix == IMBUF) return("inter-module buffer");
		if (ix == MNFCORE) return("manufacturer core");
		if (ix == MNFPRIM) return("manufacturer primitive");
		if (ix == CTR) return("controller");
		if (ix == ECTR) return("easy model controller");
		if (ix == DBG) return("debug");
		if (ix == DBGCTR) return("debug controller");
		if (ix == EDBGCTR) return("easy model debug controller");
		if (ix == OTH) return("other");
		return(getSref(ix));
	};

	return("");
};

void TblWdbeMModule::VecVBasetype::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 15; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};

/******************************************************************************
 class TblWdbeMModule::VecVHkTbl
 ******************************************************************************/

uint TblWdbeMModule::VecVHkTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "cvr") return CVR;
	if (s == "unt") return UNT;

	return(0);
};

string TblWdbeMModule::VecVHkTbl::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == CVR) return("cvr");
	if (ix == UNT) return("unt");

	return("");
};

string TblWdbeMModule::VecVHkTbl::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == CVR) return("core version");
		if (ix == UNT) return("unit");
		return(getSref(ix));
	};

	return("");
};

void TblWdbeMModule::VecVHkTbl::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};

/******************************************************************************
 class TblWdbeMModule::VecWSubset
 ******************************************************************************/

uint TblWdbeMModule::VecWSubset::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sbswdbebmmodulemct") ix |= SBSWDBEBMMODULEMCT;
		else if (ss[i] == "sbswdbebmmodulemib") ix |= SBSWDBEBMMODULEMIB;
		else if (ss[i] == "sbswdbebmmodulemod") ix |= SBSWDBEBMMODULEMOD;
		else if (ss[i] == "sbswdbebmmodulemtp") ix |= SBSWDBEBMMODULEMTP;
	};

	return(ix);
};

void TblWdbeMModule::VecWSubset::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SBSWDBEBMMODULEMTP); i *= 2) if (ix & i) ics.insert(i);
};

string TblWdbeMModule::VecWSubset::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SBSWDBEBMMODULEMCT) ss.push_back("SbsWdbeBMModuleMct");
	if (ix & SBSWDBEBMMODULEMIB) ss.push_back("SbsWdbeBMModuleMib");
	if (ix & SBSWDBEBMMODULEMOD) ss.push_back("SbsWdbeBMModuleMod");
	if (ix & SBSWDBEBMMODULEMTP) ss.push_back("SbsWdbeBMModuleMtp");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string TblWdbeMModule::VecWSubset::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == SBSWDBEBMMODULEMCT) return("controller module");
		if (ix == SBSWDBEBMMODULEMIB) return("inter-module buffer module");
		if (ix == SBSWDBEBMMODULEMOD) return("module");
		if (ix == SBSWDBEBMMODULEMTP) return("module template");
		return(getSrefs(ix));
	};

	return("");
};
