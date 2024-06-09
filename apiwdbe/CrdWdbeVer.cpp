/**
	* \file CrdWdbeVer.cpp
	* API code for job CrdWdbeVer (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "CrdWdbeVer.h"

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

/******************************************************************************
 class CrdWdbeVer::ContInf
 ******************************************************************************/

CrdWdbeVer::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
			, const string& MtxCrdVer
		) :
			Block()
		{
	this->numFSge = numFSge;
	this->MrlAppHlp = MrlAppHlp;
	this->MtxCrdVer = MtxCrdVer;

	mask = {NUMFSGE, MRLAPPHLP, MTXCRDVER};
};

bool CrdWdbeVer::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWdbeVer");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWdbeVer";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MtxCrdVer", MtxCrdVer)) add(MTXCRDVER);
	};

	return basefound;
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

CrdWdbeVer::StatApp::StatApp(
			const uint ixWdbeVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdoneList
			, const bool initdoneRec
		) :
			Block()
		{
	this->ixWdbeVReqitmode = ixWdbeVReqitmode;
	this->latency = latency;
	this->shortMenu = shortMenu;
	this->widthMenu = widthMenu;
	this->initdoneHeadbar = initdoneHeadbar;
	this->initdoneList = initdoneList;
	this->initdoneRec = initdoneRec;

	mask = {IXWDBEVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONELIST, INITDONEREC};
};

bool CrdWdbeVer::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWdbeVReqitmode;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWdbeVer");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWdbeVer";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWdbeVReqitmode", srefIxWdbeVReqitmode)) {
			ixWdbeVReqitmode = VecWdbeVReqitmode::getIx(srefIxWdbeVReqitmode);
			add(IXWDBEVREQITMODE);
		};
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "latency", latency)) add(LATENCY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "widthMenu", widthMenu)) add(WIDTHMENU);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHeadbar", initdoneHeadbar)) add(INITDONEHEADBAR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneList", initdoneList)) add(INITDONELIST);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRec", initdoneRec)) add(INITDONEREC);
	};

	return basefound;
};

set<uint> CrdWdbeVer::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWdbeVReqitmode == comp->ixWdbeVReqitmode) insert(items, IXWDBEVREQITMODE);
	if (latency == comp->latency) insert(items, LATENCY);
	if (shortMenu == comp->shortMenu) insert(items, SHORTMENU);
	if (widthMenu == comp->widthMenu) insert(items, WIDTHMENU);
	if (initdoneHeadbar == comp->initdoneHeadbar) insert(items, INITDONEHEADBAR);
	if (initdoneList == comp->initdoneList) insert(items, INITDONELIST);
	if (initdoneRec == comp->initdoneRec) insert(items, INITDONEREC);

	return(items);
};

set<uint> CrdWdbeVer::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWDBEVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONELIST, INITDONEREC};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWdbeVer::StatShr
 ******************************************************************************/

CrdWdbeVer::StatShr::StatShr(
			const string& scrJrefDlgcmdset
			, const string& scrJrefDlgcustfst
			, const string& scrJrefDlgdeploy
			, const string& scrJrefDlgdflalg
			, const string& scrJrefDlgfinmod
			, const string& scrJrefDlggenfst
			, const string& scrJrefDlgmdlstr
			, const string& scrJrefDlgnew
			, const string& scrJrefHeadbar
			, const string& scrJrefList
			, const string& scrJrefRec
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
		{
	this->scrJrefDlgcmdset = scrJrefDlgcmdset;
	this->scrJrefDlgcustfst = scrJrefDlgcustfst;
	this->scrJrefDlgdeploy = scrJrefDlgdeploy;
	this->scrJrefDlgdflalg = scrJrefDlgdflalg;
	this->scrJrefDlgfinmod = scrJrefDlgfinmod;
	this->scrJrefDlggenfst = scrJrefDlggenfst;
	this->scrJrefDlgmdlstr = scrJrefDlgmdlstr;
	this->scrJrefDlgnew = scrJrefDlgnew;
	this->scrJrefHeadbar = scrJrefHeadbar;
	this->scrJrefList = scrJrefList;
	this->scrJrefRec = scrJrefRec;
	this->MspCrd1Avail = MspCrd1Avail;
	this->MitCrdNewAvail = MitCrdNewAvail;
	this->MitCrdPcvAvail = MitCrdPcvAvail;
	this->MitCrdPcvActive = MitCrdPcvActive;
	this->MspCrd3Avail = MspCrd3Avail;
	this->MspCrd3Active = MspCrd3Active;
	this->MitCrdIdpAvail = MitCrdIdpAvail;
	this->MitCrdIdpActive = MitCrdIdpActive;
	this->MspCrd4Avail = MspCrd4Avail;
	this->MspCrd4Active = MspCrd4Active;
	this->MitCrdImdAvail = MitCrdImdAvail;
	this->MitCrdImdActive = MitCrdImdActive;
	this->MitCrdIcsAvail = MitCrdIcsAvail;
	this->MitCrdIcsActive = MitCrdIcsActive;
	this->MitCrdIdaAvail = MitCrdIdaAvail;
	this->MitCrdIdaActive = MitCrdIdaActive;
	this->MspCrd5Avail = MspCrd5Avail;
	this->MspCrd5Active = MspCrd5Active;
	this->MitCrdGfsAvail = MitCrdGfsAvail;
	this->MitCrdGfsActive = MitCrdGfsActive;
	this->MitCrdIfsAvail = MitCrdIfsAvail;
	this->MitCrdIfsActive = MitCrdIfsActive;
	this->MspCrd6Avail = MspCrd6Avail;
	this->MspCrd6Active = MspCrd6Active;
	this->MitCrdFnmAvail = MitCrdFnmAvail;
	this->MitCrdFnmActive = MitCrdFnmActive;

	mask = {SCRJREFDLGCMDSET, SCRJREFDLGCUSTFST, SCRJREFDLGDEPLOY, SCRJREFDLGDFLALG, SCRJREFDLGFINMOD, SCRJREFDLGGENFST, SCRJREFDLGMDLSTR, SCRJREFDLGNEW, SCRJREFHEADBAR, SCRJREFLIST, SCRJREFREC, MSPCRD1AVAIL, MITCRDNEWAVAIL, MITCRDPCVAVAIL, MITCRDPCVACTIVE, MSPCRD3AVAIL, MSPCRD3ACTIVE, MITCRDIDPAVAIL, MITCRDIDPACTIVE, MSPCRD4AVAIL, MSPCRD4ACTIVE, MITCRDIMDAVAIL, MITCRDIMDACTIVE, MITCRDICSAVAIL, MITCRDICSACTIVE, MITCRDIDAAVAIL, MITCRDIDAACTIVE, MSPCRD5AVAIL, MSPCRD5ACTIVE, MITCRDGFSAVAIL, MITCRDGFSACTIVE, MITCRDIFSAVAIL, MITCRDIFSACTIVE, MSPCRD6AVAIL, MSPCRD6ACTIVE, MITCRDFNMAVAIL, MITCRDFNMACTIVE};
};

bool CrdWdbeVer::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWdbeVer");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWdbeVer";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgcmdset", scrJrefDlgcmdset)) add(SCRJREFDLGCMDSET);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgcustfst", scrJrefDlgcustfst)) add(SCRJREFDLGCUSTFST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgdeploy", scrJrefDlgdeploy)) add(SCRJREFDLGDEPLOY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgdflalg", scrJrefDlgdflalg)) add(SCRJREFDLGDFLALG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgfinmod", scrJrefDlgfinmod)) add(SCRJREFDLGFINMOD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlggenfst", scrJrefDlggenfst)) add(SCRJREFDLGGENFST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgmdlstr", scrJrefDlgmdlstr)) add(SCRJREFDLGMDLSTR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgnew", scrJrefDlgnew)) add(SCRJREFDLGNEW);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", scrJrefHeadbar)) add(SCRJREFHEADBAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefList", scrJrefList)) add(SCRJREFLIST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRec", scrJrefRec)) add(SCRJREFREC);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd1Avail", MspCrd1Avail)) add(MSPCRD1AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdNewAvail", MitCrdNewAvail)) add(MITCRDNEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdPcvAvail", MitCrdPcvAvail)) add(MITCRDPCVAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdPcvActive", MitCrdPcvActive)) add(MITCRDPCVACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd3Avail", MspCrd3Avail)) add(MSPCRD3AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd3Active", MspCrd3Active)) add(MSPCRD3ACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdIdpAvail", MitCrdIdpAvail)) add(MITCRDIDPAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdIdpActive", MitCrdIdpActive)) add(MITCRDIDPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd4Avail", MspCrd4Avail)) add(MSPCRD4AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd4Active", MspCrd4Active)) add(MSPCRD4ACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdImdAvail", MitCrdImdAvail)) add(MITCRDIMDAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdImdActive", MitCrdImdActive)) add(MITCRDIMDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdIcsAvail", MitCrdIcsAvail)) add(MITCRDICSAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdIcsActive", MitCrdIcsActive)) add(MITCRDICSACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdIdaAvail", MitCrdIdaAvail)) add(MITCRDIDAAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdIdaActive", MitCrdIdaActive)) add(MITCRDIDAACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd5Avail", MspCrd5Avail)) add(MSPCRD5AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd5Active", MspCrd5Active)) add(MSPCRD5ACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdGfsAvail", MitCrdGfsAvail)) add(MITCRDGFSAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdGfsActive", MitCrdGfsActive)) add(MITCRDGFSACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdIfsAvail", MitCrdIfsAvail)) add(MITCRDIFSAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdIfsActive", MitCrdIfsActive)) add(MITCRDIFSACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd6Avail", MspCrd6Avail)) add(MSPCRD6AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd6Active", MspCrd6Active)) add(MSPCRD6ACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdFnmAvail", MitCrdFnmAvail)) add(MITCRDFNMAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdFnmActive", MitCrdFnmActive)) add(MITCRDFNMACTIVE);
	};

	return basefound;
};

set<uint> CrdWdbeVer::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (scrJrefDlgcmdset == comp->scrJrefDlgcmdset) insert(items, SCRJREFDLGCMDSET);
	if (scrJrefDlgcustfst == comp->scrJrefDlgcustfst) insert(items, SCRJREFDLGCUSTFST);
	if (scrJrefDlgdeploy == comp->scrJrefDlgdeploy) insert(items, SCRJREFDLGDEPLOY);
	if (scrJrefDlgdflalg == comp->scrJrefDlgdflalg) insert(items, SCRJREFDLGDFLALG);
	if (scrJrefDlgfinmod == comp->scrJrefDlgfinmod) insert(items, SCRJREFDLGFINMOD);
	if (scrJrefDlggenfst == comp->scrJrefDlggenfst) insert(items, SCRJREFDLGGENFST);
	if (scrJrefDlgmdlstr == comp->scrJrefDlgmdlstr) insert(items, SCRJREFDLGMDLSTR);
	if (scrJrefDlgnew == comp->scrJrefDlgnew) insert(items, SCRJREFDLGNEW);
	if (scrJrefHeadbar == comp->scrJrefHeadbar) insert(items, SCRJREFHEADBAR);
	if (scrJrefList == comp->scrJrefList) insert(items, SCRJREFLIST);
	if (scrJrefRec == comp->scrJrefRec) insert(items, SCRJREFREC);
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

	diffitems = {SCRJREFDLGCMDSET, SCRJREFDLGCUSTFST, SCRJREFDLGDEPLOY, SCRJREFDLGDFLALG, SCRJREFDLGFINMOD, SCRJREFDLGGENFST, SCRJREFDLGMDLSTR, SCRJREFDLGNEW, SCRJREFHEADBAR, SCRJREFLIST, SCRJREFREC, MSPCRD1AVAIL, MITCRDNEWAVAIL, MITCRDPCVAVAIL, MITCRDPCVACTIVE, MSPCRD3AVAIL, MSPCRD3ACTIVE, MITCRDIDPAVAIL, MITCRDIDPACTIVE, MSPCRD4AVAIL, MSPCRD4ACTIVE, MITCRDIMDAVAIL, MITCRDIMDACTIVE, MITCRDICSAVAIL, MITCRDICSACTIVE, MITCRDIDAAVAIL, MITCRDIDAACTIVE, MSPCRD5AVAIL, MSPCRD5ACTIVE, MITCRDGFSAVAIL, MITCRDGFSACTIVE, MITCRDIFSAVAIL, MITCRDIFSACTIVE, MSPCRD6AVAIL, MSPCRD6ACTIVE, MITCRDFNMAVAIL, MITCRDFNMACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWdbeVer::Tag
 ******************************************************************************/

CrdWdbeVer::Tag::Tag(
			const string& MitAppAbt
			, const string& MrlAppHlp
			, const string& MitCrdNew
			, const string& MitCrdPcv
			, const string& MitCrdIdp
			, const string& MitCrdImd
			, const string& MitCrdIcs
			, const string& MitCrdIda
			, const string& MitCrdGfs
			, const string& MitCrdIfs
			, const string& MitCrdFnm
		) :
			Block()
		{
	this->MitAppAbt = MitAppAbt;
	this->MrlAppHlp = MrlAppHlp;
	this->MitCrdNew = MitCrdNew;
	this->MitCrdPcv = MitCrdPcv;
	this->MitCrdIdp = MitCrdIdp;
	this->MitCrdImd = MitCrdImd;
	this->MitCrdIcs = MitCrdIcs;
	this->MitCrdIda = MitCrdIda;
	this->MitCrdGfs = MitCrdGfs;
	this->MitCrdIfs = MitCrdIfs;
	this->MitCrdFnm = MitCrdFnm;

	mask = {MITAPPABT, MRLAPPHLP, MITCRDNEW, MITCRDPCV, MITCRDIDP, MITCRDIMD, MITCRDICS, MITCRDIDA, MITCRDGFS, MITCRDIFS, MITCRDFNM};
};

bool CrdWdbeVer::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWdbeVer");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWdbeVer";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitAppAbt", MitAppAbt)) add(MITAPPABT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdNew", MitCrdNew)) add(MITCRDNEW);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdPcv", MitCrdPcv)) add(MITCRDPCV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdIdp", MitCrdIdp)) add(MITCRDIDP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdImd", MitCrdImd)) add(MITCRDIMD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdIcs", MitCrdIcs)) add(MITCRDICS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdIda", MitCrdIda)) add(MITCRDIDA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdGfs", MitCrdGfs)) add(MITCRDGFS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdIfs", MitCrdIfs)) add(MITCRDIFS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdFnm", MitCrdFnm)) add(MITCRDFNM);
	};

	return basefound;
};

/******************************************************************************
 class CrdWdbeVer::DpchAppDo
 ******************************************************************************/

CrdWdbeVer::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEVERDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string CrdWdbeVer::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWdbeVer::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeVerDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWdbeVer::DpchEngData
 ******************************************************************************/

CrdWdbeVer::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBEVERDATA)
		{
	feedFSge.tag = "FeedFSge";
};

string CrdWdbeVer::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWdbeVer::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWdbeVerData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFSge.readXML(docctx, basexpath, true)) add(FEEDFSGE);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		continf = ContInf();
		feedFSge.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
