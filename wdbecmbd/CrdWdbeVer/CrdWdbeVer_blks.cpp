/**
	* \file CrdWdbeVer_blks.cpp
	* job handler for job CrdWdbeVer (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class CrdWdbeVer::VecVDo
 ******************************************************************************/

uint CrdWdbeVer::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "close") return CLOSE;
	if (s == "mitappabtclick") return MITAPPABTCLICK;
	if (s == "mitcrdnewclick") return MITCRDNEWCLICK;
	if (s == "mitcrdpcvclick") return MITCRDPCVCLICK;
	if (s == "mitcrdidpclick") return MITCRDIDPCLICK;
	if (s == "mitcrdimdclick") return MITCRDIMDCLICK;
	if (s == "mitcrdicsclick") return MITCRDICSCLICK;
	if (s == "mitcrdidaclick") return MITCRDIDACLICK;
	if (s == "mitcrdgfsclick") return MITCRDGFSCLICK;
	if (s == "mitcrdifsclick") return MITCRDIFSCLICK;
	if (s == "mitcrdfnmclick") return MITCRDFNMCLICK;

	return(0);
};

string CrdWdbeVer::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
	if (ix == MITCRDNEWCLICK) return("MitCrdNewClick");
	if (ix == MITCRDPCVCLICK) return("MitCrdPcvClick");
	if (ix == MITCRDIDPCLICK) return("MitCrdIdpClick");
	if (ix == MITCRDIMDCLICK) return("MitCrdImdClick");
	if (ix == MITCRDICSCLICK) return("MitCrdIcsClick");
	if (ix == MITCRDIDACLICK) return("MitCrdIdaClick");
	if (ix == MITCRDGFSCLICK) return("MitCrdGfsClick");
	if (ix == MITCRDIFSCLICK) return("MitCrdIfsClick");
	if (ix == MITCRDFNMCLICK) return("MitCrdFnmClick");

	return("");
};

/******************************************************************************
 class CrdWdbeVer::VecVSge
 ******************************************************************************/

uint CrdWdbeVer::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "alrwdbeabt") return ALRWDBEABT;
	if (s == "alrcvw") return ALRCVW;
	if (s == "setprjcvr") return SETPRJCVR;

	return(0);
};

string CrdWdbeVer::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRWDBEABT) return("alrwdbeabt");
	if (ix == ALRCVW) return("alrcvw");
	if (ix == SETPRJCVR) return("setprjcvr");

	return("");
};

void CrdWdbeVer::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 4; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class CrdWdbeVer::ContInf
 ******************************************************************************/

CrdWdbeVer::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
			, const string& MtxCrdVer
		) :
			Block()
			, numFSge(numFSge)
			, MrlAppHlp(MrlAppHlp)
			, MtxCrdVer(MtxCrdVer)
		{
	mask = {NUMFSGE, MRLAPPHLP, MTXCRDVER};
};

void CrdWdbeVer::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbeVer";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFSge"] = (Json::Value::UInt) numFSge;
	me["MrlAppHlp"] = MrlAppHlp;
	me["MtxCrdVer"] = MtxCrdVer;
};

void CrdWdbeVer::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbeVer";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWdbeVer";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", MrlAppHlp);
		writeStringAttr(wr, itemtag, "sref", "MtxCrdVer", MtxCrdVer);
	xmlTextWriterEndElement(wr);
};

set<uint> CrdWdbeVer::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp == comp->MrlAppHlp) insert(items, MRLAPPHLP);
	if (MtxCrdVer == comp->MtxCrdVer) insert(items, MTXCRDVER);

	return(items);
};

set<uint> CrdWdbeVer::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, MRLAPPHLP, MTXCRDVER};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWdbeVer::StatApp
 ******************************************************************************/

void CrdWdbeVer::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWdbeVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdoneList
			, const bool initdoneRec
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeVer";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWdbeVReqitmode"] = VecWdbeVReqitmode::getSref(ixWdbeVReqitmode);
	me["latency"] = latency;
	me["shortMenu"] = shortMenu;
	me["widthMenu"] = (Json::Value::UInt) widthMenu;
	me["initdoneHeadbar"] = initdoneHeadbar;
	me["initdoneList"] = initdoneList;
	me["initdoneRec"] = initdoneRec;
};

void CrdWdbeVer::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWdbeVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdoneList
			, const bool initdoneRec
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeVer";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWdbeVer";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWdbeVReqitmode", VecWdbeVReqitmode::getSref(ixWdbeVReqitmode));
		writeUsmallintAttr(wr, itemtag, "sref", "latency", latency);
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
		writeUintAttr(wr, itemtag, "sref", "widthMenu", widthMenu);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHeadbar", initdoneHeadbar);
		writeBoolAttr(wr, itemtag, "sref", "initdoneList", initdoneList);
		writeBoolAttr(wr, itemtag, "sref", "initdoneRec", initdoneRec);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWdbeVer::StatShr
 ******************************************************************************/

CrdWdbeVer::StatShr::StatShr(
			const ubigint jrefDlgcmdset
			, const ubigint jrefDlgcustfst
			, const ubigint jrefDlgdeploy
			, const ubigint jrefDlgdflalg
			, const ubigint jrefDlgfinmod
			, const ubigint jrefDlggenfst
			, const ubigint jrefDlgmdlstr
			, const ubigint jrefDlgnew
			, const ubigint jrefHeadbar
			, const ubigint jrefList
			, const ubigint jrefRec
			, const bool MspCrd1Avail
			, const bool MitCrdNewAvail
			, const bool MitCrdPcvAvail
			, const bool MitCrdPcvActive
			, const bool MspCrd3Avail
			, const bool MspCrd3Active
			, const bool MitCrdIdpAvail
			, const bool MitCrdIdpActive
			, const bool MspCrd4Avail
			, const bool MspCrd4Active
			, const bool MitCrdImdAvail
			, const bool MitCrdImdActive
			, const bool MitCrdIcsAvail
			, const bool MitCrdIcsActive
			, const bool MitCrdIdaAvail
			, const bool MitCrdIdaActive
			, const bool MspCrd5Avail
			, const bool MspCrd5Active
			, const bool MitCrdGfsAvail
			, const bool MitCrdGfsActive
			, const bool MitCrdIfsAvail
			, const bool MitCrdIfsActive
			, const bool MspCrd6Avail
			, const bool MspCrd6Active
			, const bool MitCrdFnmAvail
			, const bool MitCrdFnmActive
		) :
			Block()
			, jrefDlgcmdset(jrefDlgcmdset)
			, jrefDlgcustfst(jrefDlgcustfst)
			, jrefDlgdeploy(jrefDlgdeploy)
			, jrefDlgdflalg(jrefDlgdflalg)
			, jrefDlgfinmod(jrefDlgfinmod)
			, jrefDlggenfst(jrefDlggenfst)
			, jrefDlgmdlstr(jrefDlgmdlstr)
			, jrefDlgnew(jrefDlgnew)
			, jrefHeadbar(jrefHeadbar)
			, jrefList(jrefList)
			, jrefRec(jrefRec)
			, MspCrd1Avail(MspCrd1Avail)
			, MitCrdNewAvail(MitCrdNewAvail)
			, MitCrdPcvAvail(MitCrdPcvAvail)
			, MitCrdPcvActive(MitCrdPcvActive)
			, MspCrd3Avail(MspCrd3Avail)
			, MspCrd3Active(MspCrd3Active)
			, MitCrdIdpAvail(MitCrdIdpAvail)
			, MitCrdIdpActive(MitCrdIdpActive)
			, MspCrd4Avail(MspCrd4Avail)
			, MspCrd4Active(MspCrd4Active)
			, MitCrdImdAvail(MitCrdImdAvail)
			, MitCrdImdActive(MitCrdImdActive)
			, MitCrdIcsAvail(MitCrdIcsAvail)
			, MitCrdIcsActive(MitCrdIcsActive)
			, MitCrdIdaAvail(MitCrdIdaAvail)
			, MitCrdIdaActive(MitCrdIdaActive)
			, MspCrd5Avail(MspCrd5Avail)
			, MspCrd5Active(MspCrd5Active)
			, MitCrdGfsAvail(MitCrdGfsAvail)
			, MitCrdGfsActive(MitCrdGfsActive)
			, MitCrdIfsAvail(MitCrdIfsAvail)
			, MitCrdIfsActive(MitCrdIfsActive)
			, MspCrd6Avail(MspCrd6Avail)
			, MspCrd6Active(MspCrd6Active)
			, MitCrdFnmAvail(MitCrdFnmAvail)
			, MitCrdFnmActive(MitCrdFnmActive)
		{
	mask = {JREFDLGCMDSET, JREFDLGCUSTFST, JREFDLGDEPLOY, JREFDLGDFLALG, JREFDLGFINMOD, JREFDLGGENFST, JREFDLGMDLSTR, JREFDLGNEW, JREFHEADBAR, JREFLIST, JREFREC, MSPCRD1AVAIL, MITCRDNEWAVAIL, MITCRDPCVAVAIL, MITCRDPCVACTIVE, MSPCRD3AVAIL, MSPCRD3ACTIVE, MITCRDIDPAVAIL, MITCRDIDPACTIVE, MSPCRD4AVAIL, MSPCRD4ACTIVE, MITCRDIMDAVAIL, MITCRDIMDACTIVE, MITCRDICSAVAIL, MITCRDICSACTIVE, MITCRDIDAAVAIL, MITCRDIDAACTIVE, MSPCRD5AVAIL, MSPCRD5ACTIVE, MITCRDGFSAVAIL, MITCRDGFSACTIVE, MITCRDIFSAVAIL, MITCRDIFSACTIVE, MSPCRD6AVAIL, MSPCRD6ACTIVE, MITCRDFNMAVAIL, MITCRDFNMACTIVE};
};

void CrdWdbeVer::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeVer";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["scrJrefDlgcmdset"] = Scr::scramble(jrefDlgcmdset);
	me["scrJrefDlgcustfst"] = Scr::scramble(jrefDlgcustfst);
	me["scrJrefDlgdeploy"] = Scr::scramble(jrefDlgdeploy);
	me["scrJrefDlgdflalg"] = Scr::scramble(jrefDlgdflalg);
	me["scrJrefDlgfinmod"] = Scr::scramble(jrefDlgfinmod);
	me["scrJrefDlggenfst"] = Scr::scramble(jrefDlggenfst);
	me["scrJrefDlgmdlstr"] = Scr::scramble(jrefDlgmdlstr);
	me["scrJrefDlgnew"] = Scr::scramble(jrefDlgnew);
	me["scrJrefHeadbar"] = Scr::scramble(jrefHeadbar);
	me["scrJrefList"] = Scr::scramble(jrefList);
	me["scrJrefRec"] = Scr::scramble(jrefRec);
	me["MspCrd1Avail"] = MspCrd1Avail;
	me["MitCrdNewAvail"] = MitCrdNewAvail;
	me["MitCrdPcvAvail"] = MitCrdPcvAvail;
	me["MitCrdPcvActive"] = MitCrdPcvActive;
	me["MspCrd3Avail"] = MspCrd3Avail;
	me["MspCrd3Active"] = MspCrd3Active;
	me["MitCrdIdpAvail"] = MitCrdIdpAvail;
	me["MitCrdIdpActive"] = MitCrdIdpActive;
	me["MspCrd4Avail"] = MspCrd4Avail;
	me["MspCrd4Active"] = MspCrd4Active;
	me["MitCrdImdAvail"] = MitCrdImdAvail;
	me["MitCrdImdActive"] = MitCrdImdActive;
	me["MitCrdIcsAvail"] = MitCrdIcsAvail;
	me["MitCrdIcsActive"] = MitCrdIcsActive;
	me["MitCrdIdaAvail"] = MitCrdIdaAvail;
	me["MitCrdIdaActive"] = MitCrdIdaActive;
	me["MspCrd5Avail"] = MspCrd5Avail;
	me["MspCrd5Active"] = MspCrd5Active;
	me["MitCrdGfsAvail"] = MitCrdGfsAvail;
	me["MitCrdGfsActive"] = MitCrdGfsActive;
	me["MitCrdIfsAvail"] = MitCrdIfsAvail;
	me["MitCrdIfsActive"] = MitCrdIfsActive;
	me["MspCrd6Avail"] = MspCrd6Avail;
	me["MspCrd6Active"] = MspCrd6Active;
	me["MitCrdFnmAvail"] = MitCrdFnmAvail;
	me["MitCrdFnmActive"] = MitCrdFnmActive;
};

void CrdWdbeVer::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeVer";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWdbeVer";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgcmdset", Scr::scramble(jrefDlgcmdset));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgcustfst", Scr::scramble(jrefDlgcustfst));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgdeploy", Scr::scramble(jrefDlgdeploy));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgdflalg", Scr::scramble(jrefDlgdflalg));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgfinmod", Scr::scramble(jrefDlgfinmod));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlggenfst", Scr::scramble(jrefDlggenfst));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgmdlstr", Scr::scramble(jrefDlgmdlstr));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgnew", Scr::scramble(jrefDlgnew));
		writeStringAttr(wr, itemtag, "sref", "scrJrefHeadbar", Scr::scramble(jrefHeadbar));
		writeStringAttr(wr, itemtag, "sref", "scrJrefList", Scr::scramble(jrefList));
		writeStringAttr(wr, itemtag, "sref", "scrJrefRec", Scr::scramble(jrefRec));
		writeBoolAttr(wr, itemtag, "sref", "MspCrd1Avail", MspCrd1Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdNewAvail", MitCrdNewAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdPcvAvail", MitCrdPcvAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdPcvActive", MitCrdPcvActive);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd3Avail", MspCrd3Avail);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd3Active", MspCrd3Active);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdIdpAvail", MitCrdIdpAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdIdpActive", MitCrdIdpActive);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd4Avail", MspCrd4Avail);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd4Active", MspCrd4Active);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdImdAvail", MitCrdImdAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdImdActive", MitCrdImdActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdIcsAvail", MitCrdIcsAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdIcsActive", MitCrdIcsActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdIdaAvail", MitCrdIdaAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdIdaActive", MitCrdIdaActive);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd5Avail", MspCrd5Avail);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd5Active", MspCrd5Active);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdGfsAvail", MitCrdGfsAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdGfsActive", MitCrdGfsActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdIfsAvail", MitCrdIfsAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdIfsActive", MitCrdIfsActive);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd6Avail", MspCrd6Avail);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd6Active", MspCrd6Active);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdFnmAvail", MitCrdFnmAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdFnmActive", MitCrdFnmActive);
	xmlTextWriterEndElement(wr);
};

set<uint> CrdWdbeVer::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (jrefDlgcmdset == comp->jrefDlgcmdset) insert(items, JREFDLGCMDSET);
	if (jrefDlgcustfst == comp->jrefDlgcustfst) insert(items, JREFDLGCUSTFST);
	if (jrefDlgdeploy == comp->jrefDlgdeploy) insert(items, JREFDLGDEPLOY);
	if (jrefDlgdflalg == comp->jrefDlgdflalg) insert(items, JREFDLGDFLALG);
	if (jrefDlgfinmod == comp->jrefDlgfinmod) insert(items, JREFDLGFINMOD);
	if (jrefDlggenfst == comp->jrefDlggenfst) insert(items, JREFDLGGENFST);
	if (jrefDlgmdlstr == comp->jrefDlgmdlstr) insert(items, JREFDLGMDLSTR);
	if (jrefDlgnew == comp->jrefDlgnew) insert(items, JREFDLGNEW);
	if (jrefHeadbar == comp->jrefHeadbar) insert(items, JREFHEADBAR);
	if (jrefList == comp->jrefList) insert(items, JREFLIST);
	if (jrefRec == comp->jrefRec) insert(items, JREFREC);
	if (MspCrd1Avail == comp->MspCrd1Avail) insert(items, MSPCRD1AVAIL);
	if (MitCrdNewAvail == comp->MitCrdNewAvail) insert(items, MITCRDNEWAVAIL);
	if (MitCrdPcvAvail == comp->MitCrdPcvAvail) insert(items, MITCRDPCVAVAIL);
	if (MitCrdPcvActive == comp->MitCrdPcvActive) insert(items, MITCRDPCVACTIVE);
	if (MspCrd3Avail == comp->MspCrd3Avail) insert(items, MSPCRD3AVAIL);
	if (MspCrd3Active == comp->MspCrd3Active) insert(items, MSPCRD3ACTIVE);
	if (MitCrdIdpAvail == comp->MitCrdIdpAvail) insert(items, MITCRDIDPAVAIL);
	if (MitCrdIdpActive == comp->MitCrdIdpActive) insert(items, MITCRDIDPACTIVE);
	if (MspCrd4Avail == comp->MspCrd4Avail) insert(items, MSPCRD4AVAIL);
	if (MspCrd4Active == comp->MspCrd4Active) insert(items, MSPCRD4ACTIVE);
	if (MitCrdImdAvail == comp->MitCrdImdAvail) insert(items, MITCRDIMDAVAIL);
	if (MitCrdImdActive == comp->MitCrdImdActive) insert(items, MITCRDIMDACTIVE);
	if (MitCrdIcsAvail == comp->MitCrdIcsAvail) insert(items, MITCRDICSAVAIL);
	if (MitCrdIcsActive == comp->MitCrdIcsActive) insert(items, MITCRDICSACTIVE);
	if (MitCrdIdaAvail == comp->MitCrdIdaAvail) insert(items, MITCRDIDAAVAIL);
	if (MitCrdIdaActive == comp->MitCrdIdaActive) insert(items, MITCRDIDAACTIVE);
	if (MspCrd5Avail == comp->MspCrd5Avail) insert(items, MSPCRD5AVAIL);
	if (MspCrd5Active == comp->MspCrd5Active) insert(items, MSPCRD5ACTIVE);
	if (MitCrdGfsAvail == comp->MitCrdGfsAvail) insert(items, MITCRDGFSAVAIL);
	if (MitCrdGfsActive == comp->MitCrdGfsActive) insert(items, MITCRDGFSACTIVE);
	if (MitCrdIfsAvail == comp->MitCrdIfsAvail) insert(items, MITCRDIFSAVAIL);
	if (MitCrdIfsActive == comp->MitCrdIfsActive) insert(items, MITCRDIFSACTIVE);
	if (MspCrd6Avail == comp->MspCrd6Avail) insert(items, MSPCRD6AVAIL);
	if (MspCrd6Active == comp->MspCrd6Active) insert(items, MSPCRD6ACTIVE);
	if (MitCrdFnmAvail == comp->MitCrdFnmAvail) insert(items, MITCRDFNMAVAIL);
	if (MitCrdFnmActive == comp->MitCrdFnmActive) insert(items, MITCRDFNMACTIVE);

	return(items);
};

set<uint> CrdWdbeVer::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JREFDLGCMDSET, JREFDLGCUSTFST, JREFDLGDEPLOY, JREFDLGDFLALG, JREFDLGFINMOD, JREFDLGGENFST, JREFDLGMDLSTR, JREFDLGNEW, JREFHEADBAR, JREFLIST, JREFREC, MSPCRD1AVAIL, MITCRDNEWAVAIL, MITCRDPCVAVAIL, MITCRDPCVACTIVE, MSPCRD3AVAIL, MSPCRD3ACTIVE, MITCRDIDPAVAIL, MITCRDIDPACTIVE, MSPCRD4AVAIL, MSPCRD4ACTIVE, MITCRDIMDAVAIL, MITCRDIMDACTIVE, MITCRDICSAVAIL, MITCRDICSACTIVE, MITCRDIDAAVAIL, MITCRDIDAACTIVE, MSPCRD5AVAIL, MSPCRD5ACTIVE, MITCRDGFSAVAIL, MITCRDGFSACTIVE, MITCRDIFSAVAIL, MITCRDIFSACTIVE, MSPCRD6AVAIL, MSPCRD6ACTIVE, MITCRDFNMAVAIL, MITCRDFNMACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWdbeVer::Tag
 ******************************************************************************/

void CrdWdbeVer::Tag::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWdbeVer";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		me["MitCrdPcv"] = "Make project's current version";
		me["MitCrdIdp"] = "Import deployment information ...";
		me["MitCrdImd"] = "Import modular structure ...";
		me["MitCrdIcs"] = "Import command set ...";
		me["MitCrdIda"] = "Import data flows and algorithms ...";
		me["MitCrdGfs"] = "Generate fine structure ...";
		me["MitCrdIfs"] = "Apply custom fine structure ...";
		me["MitCrdFnm"] = "Finalize model ...";
	};
	me["MitAppAbt"] = StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::ABOUT, ixWdbeVLocale)) + " ...";
	me["MrlAppHlp"] = StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::HELP, ixWdbeVLocale)) + " ...";
	me["MitCrdNew"] = StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::NEW, ixWdbeVLocale)) + " ...";
};

void CrdWdbeVer::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWdbeVer";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWdbeVer";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MitCrdPcv", "Make project's current version");
			writeStringAttr(wr, itemtag, "sref", "MitCrdIdp", "Import deployment information ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdImd", "Import modular structure ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdIcs", "Import command set ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdIda", "Import data flows and algorithms ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdGfs", "Generate fine structure ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdIfs", "Apply custom fine structure ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdFnm", "Finalize model ...");
		};
		writeStringAttr(wr, itemtag, "sref", "MitAppAbt", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::ABOUT, ixWdbeVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::HELP, ixWdbeVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "MitCrdNew", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::NEW, ixWdbeVLocale)) + " ...");
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWdbeVer::DpchAppDo
 ******************************************************************************/

CrdWdbeVer::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEVERDO)
		{
	ixVDo = 0;
};

string CrdWdbeVer::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWdbeVer::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWdbeVerDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void CrdWdbeVer::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeVerDo");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (extractStringUclc(docctx, basexpath, "srefIxVDo", "", srefIxVDo)) {
			ixVDo = VecVDo::getIx(srefIxVDo);
			add(IXVDO);
		};
	} else {
	};
};

/******************************************************************************
 class CrdWdbeVer::DpchEngData
 ******************************************************************************/

CrdWdbeVer::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFSge
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBEVERDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFSGE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string CrdWdbeVer::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWdbeVer::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void CrdWdbeVer::DpchEngData::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWdbeVerData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFSGE)) feedFSge.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWdbeVLocale, me);
};

void CrdWdbeVer::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWdbeVerData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};
