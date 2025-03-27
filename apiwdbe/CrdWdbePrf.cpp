/**
	* \file CrdWdbePrf.cpp
	* API code for job CrdWdbePrf (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 8 Jan 2025
	*/
// IP header --- ABOVE

#include "CrdWdbePrf.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class CrdWdbePrf::VecVDo
 ******************************************************************************/

uint CrdWdbePrf::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "close") return CLOSE;
	if (s == "mitappabtclick") return MITAPPABTCLICK;
	if (s == "mitcrdrvrclick") return MITCRDRVRCLICK;
	if (s == "mitcrdstoclick") return MITCRDSTOCLICK;

	return(0);
};

string CrdWdbePrf::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
	if (ix == MITCRDRVRCLICK) return("MitCrdRvrClick");
	if (ix == MITCRDSTOCLICK) return("MitCrdStoClick");

	return("");
};

/******************************************************************************
 class CrdWdbePrf::VecVSge
 ******************************************************************************/

uint CrdWdbePrf::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "alrwdbeabt") return ALRWDBEABT;

	return(0);
};

string CrdWdbePrf::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRWDBEABT) return("alrwdbeabt");

	return("");
};

/******************************************************************************
 class CrdWdbePrf::ContInf
 ******************************************************************************/

CrdWdbePrf::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
		) :
			Block()
			, numFSge(numFSge)
			, MrlAppHlp(MrlAppHlp)
		{
	mask = {NUMFSGE, MRLAPPHLP};
};

bool CrdWdbePrf::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWdbePrf");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWdbePrf";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
	};

	return basefound;
};

set<uint> CrdWdbePrf::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp == comp->MrlAppHlp) insert(items, MRLAPPHLP);

	return(items);
};

set<uint> CrdWdbePrf::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, MRLAPPHLP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWdbePrf::StatApp
 ******************************************************************************/

CrdWdbePrf::StatApp::StatApp(
			const uint ixWdbeVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneDaemon
			, const bool initdoneHeadbar
			, const bool initdoneLicense
		) :
			Block()
			, ixWdbeVReqitmode(ixWdbeVReqitmode)
			, latency(latency)
			, shortMenu(shortMenu)
			, widthMenu(widthMenu)
			, initdoneDaemon(initdoneDaemon)
			, initdoneHeadbar(initdoneHeadbar)
			, initdoneLicense(initdoneLicense)
		{
	mask = {IXWDBEVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEDAEMON, INITDONEHEADBAR, INITDONELICENSE};
};

bool CrdWdbePrf::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWdbeVReqitmode;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWdbePrf");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWdbePrf";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWdbeVReqitmode", srefIxWdbeVReqitmode)) {
			ixWdbeVReqitmode = VecWdbeVReqitmode::getIx(srefIxWdbeVReqitmode);
			add(IXWDBEVREQITMODE);
		};
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "latency", latency)) add(LATENCY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "widthMenu", widthMenu)) add(WIDTHMENU);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDaemon", initdoneDaemon)) add(INITDONEDAEMON);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHeadbar", initdoneHeadbar)) add(INITDONEHEADBAR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneLicense", initdoneLicense)) add(INITDONELICENSE);
	};

	return basefound;
};

set<uint> CrdWdbePrf::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWdbeVReqitmode == comp->ixWdbeVReqitmode) insert(items, IXWDBEVREQITMODE);
	if (latency == comp->latency) insert(items, LATENCY);
	if (shortMenu == comp->shortMenu) insert(items, SHORTMENU);
	if (widthMenu == comp->widthMenu) insert(items, WIDTHMENU);
	if (initdoneDaemon == comp->initdoneDaemon) insert(items, INITDONEDAEMON);
	if (initdoneHeadbar == comp->initdoneHeadbar) insert(items, INITDONEHEADBAR);
	if (initdoneLicense == comp->initdoneLicense) insert(items, INITDONELICENSE);

	return(items);
};

set<uint> CrdWdbePrf::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWDBEVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEDAEMON, INITDONEHEADBAR, INITDONELICENSE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWdbePrf::StatShr
 ******************************************************************************/

CrdWdbePrf::StatShr::StatShr(
			const string& scrJrefDaemon
			, const string& scrJrefHeadbar
			, const string& scrJrefLicense
		) :
			Block()
			, scrJrefDaemon(scrJrefDaemon)
			, scrJrefHeadbar(scrJrefHeadbar)
			, scrJrefLicense(scrJrefLicense)
		{
	mask = {SCRJREFDAEMON, SCRJREFHEADBAR, SCRJREFLICENSE};
};

bool CrdWdbePrf::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWdbePrf");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWdbePrf";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDaemon", scrJrefDaemon)) add(SCRJREFDAEMON);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", scrJrefHeadbar)) add(SCRJREFHEADBAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefLicense", scrJrefLicense)) add(SCRJREFLICENSE);
	};

	return basefound;
};

set<uint> CrdWdbePrf::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (scrJrefDaemon == comp->scrJrefDaemon) insert(items, SCRJREFDAEMON);
	if (scrJrefHeadbar == comp->scrJrefHeadbar) insert(items, SCRJREFHEADBAR);
	if (scrJrefLicense == comp->scrJrefLicense) insert(items, SCRJREFLICENSE);

	return(items);
};

set<uint> CrdWdbePrf::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SCRJREFDAEMON, SCRJREFHEADBAR, SCRJREFLICENSE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWdbePrf::Tag
 ******************************************************************************/

CrdWdbePrf::Tag::Tag(
			const string& MitAppAbt
			, const string& MrlAppHlp
			, const string& MitCrdRvr
			, const string& MitCrdSto
		) :
			Block()
			, MitAppAbt(MitAppAbt)
			, MrlAppHlp(MrlAppHlp)
			, MitCrdRvr(MitCrdRvr)
			, MitCrdSto(MitCrdSto)
		{
	mask = {MITAPPABT, MRLAPPHLP, MITCRDRVR, MITCRDSTO};
};

bool CrdWdbePrf::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWdbePrf");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWdbePrf";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitAppAbt", MitAppAbt)) add(MITAPPABT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdRvr", MitCrdRvr)) add(MITCRDRVR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdSto", MitCrdSto)) add(MITCRDSTO);
	};

	return basefound;
};

/******************************************************************************
 class CrdWdbePrf::DpchAppDo
 ******************************************************************************/

CrdWdbePrf::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEPRFDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string CrdWdbePrf::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWdbePrf::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbePrfDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWdbePrf::DpchEngData
 ******************************************************************************/

CrdWdbePrf::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBEPRFDATA)
		{
	feedFSge.tag = "FeedFSge";
};

string CrdWdbePrf::DpchEngData::getSrefsMask() {
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

void CrdWdbePrf::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWdbePrfData");
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
