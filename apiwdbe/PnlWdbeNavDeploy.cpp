/**
	* \file PnlWdbeNavDeploy.cpp
	* API code for job PnlWdbeNavDeploy (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Sep 2023
	*/
// IP header --- ABOVE

#include "PnlWdbeNavDeploy.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbeNavDeploy::VecVDo
 ******************************************************************************/

uint PnlWdbeNavDeploy::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butcmpviewclick") return BUTCMPVIEWCLICK;
	if (s == "butcmpnewcrdclick") return BUTCMPNEWCRDCLICK;
	if (s == "butrlsviewclick") return BUTRLSVIEWCLICK;
	if (s == "butrlsnewcrdclick") return BUTRLSNEWCRDCLICK;

	return(0);
};

string PnlWdbeNavDeploy::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTCMPVIEWCLICK) return("ButCmpViewClick");
	if (ix == BUTCMPNEWCRDCLICK) return("ButCmpNewcrdClick");
	if (ix == BUTRLSVIEWCLICK) return("ButRlsViewClick");
	if (ix == BUTRLSNEWCRDCLICK) return("ButRlsNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlWdbeNavDeploy::ContIac
 ******************************************************************************/

PnlWdbeNavDeploy::ContIac::ContIac(
			const uint numFLstCmp
			, const uint numFLstRls
		) :
			Block()
			, numFLstCmp(numFLstCmp)
			, numFLstRls(numFLstRls)
		{
	mask = {NUMFLSTCMP, NUMFLSTRLS};
};

bool PnlWdbeNavDeploy::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWdbeNavDeploy");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWdbeNavDeploy";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstCmp", numFLstCmp)) add(NUMFLSTCMP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstRls", numFLstRls)) add(NUMFLSTRLS);
	};

	return basefound;
};

void PnlWdbeNavDeploy::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeNavDeploy";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWdbeNavDeploy";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstCmp", numFLstCmp);
		writeUintAttr(wr, itemtag, "sref", "numFLstRls", numFLstRls);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeNavDeploy::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstCmp == comp->numFLstCmp) insert(items, NUMFLSTCMP);
	if (numFLstRls == comp->numFLstRls) insert(items, NUMFLSTRLS);

	return(items);
};

set<uint> PnlWdbeNavDeploy::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTCMP, NUMFLSTRLS};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeNavDeploy::StatApp
 ******************************************************************************/

PnlWdbeNavDeploy::StatApp::StatApp(
			const uint ixWdbeVExpstate
			, const bool LstCmpAlt
			, const bool LstRlsAlt
			, const uint LstCmpNumFirstdisp
			, const uint LstRlsNumFirstdisp
		) :
			Block()
			, ixWdbeVExpstate(ixWdbeVExpstate)
			, LstCmpAlt(LstCmpAlt)
			, LstRlsAlt(LstRlsAlt)
			, LstCmpNumFirstdisp(LstCmpNumFirstdisp)
			, LstRlsNumFirstdisp(LstRlsNumFirstdisp)
		{
	mask = {IXWDBEVEXPSTATE, LSTCMPALT, LSTRLSALT, LSTCMPNUMFIRSTDISP, LSTRLSNUMFIRSTDISP};
};

bool PnlWdbeNavDeploy::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWdbeVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWdbeNavDeploy");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWdbeNavDeploy";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", srefIxWdbeVExpstate)) {
			ixWdbeVExpstate = VecWdbeVExpstate::getIx(srefIxWdbeVExpstate);
			add(IXWDBEVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCmpAlt", LstCmpAlt)) add(LSTCMPALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstRlsAlt", LstRlsAlt)) add(LSTRLSALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCmpNumFirstdisp", LstCmpNumFirstdisp)) add(LSTCMPNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstRlsNumFirstdisp", LstRlsNumFirstdisp)) add(LSTRLSNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlWdbeNavDeploy::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWdbeVExpstate == comp->ixWdbeVExpstate) insert(items, IXWDBEVEXPSTATE);
	if (LstCmpAlt == comp->LstCmpAlt) insert(items, LSTCMPALT);
	if (LstRlsAlt == comp->LstRlsAlt) insert(items, LSTRLSALT);
	if (LstCmpNumFirstdisp == comp->LstCmpNumFirstdisp) insert(items, LSTCMPNUMFIRSTDISP);
	if (LstRlsNumFirstdisp == comp->LstRlsNumFirstdisp) insert(items, LSTRLSNUMFIRSTDISP);

	return(items);
};

set<uint> PnlWdbeNavDeploy::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWDBEVEXPSTATE, LSTCMPALT, LSTRLSALT, LSTCMPNUMFIRSTDISP, LSTRLSNUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeNavDeploy::StatShr
 ******************************************************************************/

PnlWdbeNavDeploy::StatShr::StatShr(
			const bool LstCmpAvail
			, const bool ButCmpViewActive
			, const bool LstRlsAvail
			, const bool ButRlsViewActive
			, const bool ButRlsNewcrdActive
		) :
			Block()
			, LstCmpAvail(LstCmpAvail)
			, ButCmpViewActive(ButCmpViewActive)
			, LstRlsAvail(LstRlsAvail)
			, ButRlsViewActive(ButRlsViewActive)
			, ButRlsNewcrdActive(ButRlsNewcrdActive)
		{
	mask = {LSTCMPAVAIL, BUTCMPVIEWACTIVE, LSTRLSAVAIL, BUTRLSVIEWACTIVE, BUTRLSNEWCRDACTIVE};
};

bool PnlWdbeNavDeploy::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWdbeNavDeploy");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWdbeNavDeploy";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCmpAvail", LstCmpAvail)) add(LSTCMPAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCmpViewActive", ButCmpViewActive)) add(BUTCMPVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstRlsAvail", LstRlsAvail)) add(LSTRLSAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRlsViewActive", ButRlsViewActive)) add(BUTRLSVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRlsNewcrdActive", ButRlsNewcrdActive)) add(BUTRLSNEWCRDACTIVE);
	};

	return basefound;
};

set<uint> PnlWdbeNavDeploy::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstCmpAvail == comp->LstCmpAvail) insert(items, LSTCMPAVAIL);
	if (ButCmpViewActive == comp->ButCmpViewActive) insert(items, BUTCMPVIEWACTIVE);
	if (LstRlsAvail == comp->LstRlsAvail) insert(items, LSTRLSAVAIL);
	if (ButRlsViewActive == comp->ButRlsViewActive) insert(items, BUTRLSVIEWACTIVE);
	if (ButRlsNewcrdActive == comp->ButRlsNewcrdActive) insert(items, BUTRLSNEWCRDACTIVE);

	return(items);
};

set<uint> PnlWdbeNavDeploy::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTCMPAVAIL, BUTCMPVIEWACTIVE, LSTRLSAVAIL, BUTRLSVIEWACTIVE, BUTRLSNEWCRDACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeNavDeploy::Tag
 ******************************************************************************/

PnlWdbeNavDeploy::Tag::Tag(
			const string& Cpt
			, const string& CptCmp
			, const string& CptRls
		) :
			Block()
			, Cpt(Cpt)
			, CptCmp(CptCmp)
			, CptRls(CptRls)
		{
	mask = {CPT, CPTCMP, CPTRLS};
};

bool PnlWdbeNavDeploy::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWdbeNavDeploy");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWdbeNavDeploy";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCmp", CptCmp)) add(CPTCMP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptRls", CptRls)) add(CPTRLS);
	};

	return basefound;
};

/******************************************************************************
 class PnlWdbeNavDeploy::DpchAppData
 ******************************************************************************/

PnlWdbeNavDeploy::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBENAVDEPLOYDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWdbeNavDeploy::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavDeploy::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeNavDeployData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeNavDeploy::DpchAppDo
 ******************************************************************************/

PnlWdbeNavDeploy::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBENAVDEPLOYDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string PnlWdbeNavDeploy::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavDeploy::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeNavDeployDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeNavDeploy::DpchEngData
 ******************************************************************************/

PnlWdbeNavDeploy::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBENAVDEPLOYDATA)
		{
	feedFLstCmp.tag = "FeedFLstCmp";
	feedFLstRls.tag = "FeedFLstRls";
};

string PnlWdbeNavDeploy::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTCMP)) ss.push_back("feedFLstCmp");
	if (has(FEEDFLSTRLS)) ss.push_back("feedFLstRls");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavDeploy::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWdbeNavDeployData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (feedFLstCmp.readXML(docctx, basexpath, true)) add(FEEDFLSTCMP);
		if (feedFLstRls.readXML(docctx, basexpath, true)) add(FEEDFLSTRLS);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		feedFLstCmp.clear();
		feedFLstRls.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
