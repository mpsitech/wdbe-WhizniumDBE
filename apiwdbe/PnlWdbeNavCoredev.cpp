/**
	* \file PnlWdbeNavCoredev.cpp
	* API code for job PnlWdbeNavCoredev (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "PnlWdbeNavCoredev.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbeNavCoredev::VecVDo
 ******************************************************************************/

uint PnlWdbeNavCoredev::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butcprviewclick") return BUTCPRVIEWCLICK;
	if (s == "butcprnewcrdclick") return BUTCPRNEWCRDCLICK;
	if (s == "butcvrviewclick") return BUTCVRVIEWCLICK;
	if (s == "butcvrnewcrdclick") return BUTCVRNEWCRDCLICK;

	return(0);
};

string PnlWdbeNavCoredev::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTCPRVIEWCLICK) return("ButCprViewClick");
	if (ix == BUTCPRNEWCRDCLICK) return("ButCprNewcrdClick");
	if (ix == BUTCVRVIEWCLICK) return("ButCvrViewClick");
	if (ix == BUTCVRNEWCRDCLICK) return("ButCvrNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlWdbeNavCoredev::ContIac
 ******************************************************************************/

PnlWdbeNavCoredev::ContIac::ContIac(
			const uint numFLstCpr
			, const uint numFLstCvr
		) :
			Block()
		{
	this->numFLstCpr = numFLstCpr;
	this->numFLstCvr = numFLstCvr;

	mask = {NUMFLSTCPR, NUMFLSTCVR};
};

bool PnlWdbeNavCoredev::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWdbeNavCoredev");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWdbeNavCoredev";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstCpr", numFLstCpr)) add(NUMFLSTCPR);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstCvr", numFLstCvr)) add(NUMFLSTCVR);
	};

	return basefound;
};

void PnlWdbeNavCoredev::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeNavCoredev";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWdbeNavCoredev";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstCpr", numFLstCpr);
		writeUintAttr(wr, itemtag, "sref", "numFLstCvr", numFLstCvr);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeNavCoredev::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstCpr == comp->numFLstCpr) insert(items, NUMFLSTCPR);
	if (numFLstCvr == comp->numFLstCvr) insert(items, NUMFLSTCVR);

	return(items);
};

set<uint> PnlWdbeNavCoredev::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTCPR, NUMFLSTCVR};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeNavCoredev::StatApp
 ******************************************************************************/

PnlWdbeNavCoredev::StatApp::StatApp(
			const uint ixWdbeVExpstate
			, const bool LstCprAlt
			, const bool LstCvrAlt
			, const uint LstCprNumFirstdisp
			, const uint LstCvrNumFirstdisp
		) :
			Block()
		{
	this->ixWdbeVExpstate = ixWdbeVExpstate;
	this->LstCprAlt = LstCprAlt;
	this->LstCvrAlt = LstCvrAlt;
	this->LstCprNumFirstdisp = LstCprNumFirstdisp;
	this->LstCvrNumFirstdisp = LstCvrNumFirstdisp;

	mask = {IXWDBEVEXPSTATE, LSTCPRALT, LSTCVRALT, LSTCPRNUMFIRSTDISP, LSTCVRNUMFIRSTDISP};
};

bool PnlWdbeNavCoredev::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWdbeVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWdbeNavCoredev");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWdbeNavCoredev";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", srefIxWdbeVExpstate)) {
			ixWdbeVExpstate = VecWdbeVExpstate::getIx(srefIxWdbeVExpstate);
			add(IXWDBEVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCprAlt", LstCprAlt)) add(LSTCPRALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCvrAlt", LstCvrAlt)) add(LSTCVRALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCprNumFirstdisp", LstCprNumFirstdisp)) add(LSTCPRNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCvrNumFirstdisp", LstCvrNumFirstdisp)) add(LSTCVRNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlWdbeNavCoredev::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWdbeVExpstate == comp->ixWdbeVExpstate) insert(items, IXWDBEVEXPSTATE);
	if (LstCprAlt == comp->LstCprAlt) insert(items, LSTCPRALT);
	if (LstCvrAlt == comp->LstCvrAlt) insert(items, LSTCVRALT);
	if (LstCprNumFirstdisp == comp->LstCprNumFirstdisp) insert(items, LSTCPRNUMFIRSTDISP);
	if (LstCvrNumFirstdisp == comp->LstCvrNumFirstdisp) insert(items, LSTCVRNUMFIRSTDISP);

	return(items);
};

set<uint> PnlWdbeNavCoredev::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWDBEVEXPSTATE, LSTCPRALT, LSTCVRALT, LSTCPRNUMFIRSTDISP, LSTCVRNUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeNavCoredev::StatShr
 ******************************************************************************/

PnlWdbeNavCoredev::StatShr::StatShr(
			const bool LstCprAvail
			, const bool ButCprViewActive
			, const bool LstCvrAvail
			, const bool ButCvrViewActive
		) :
			Block()
		{
	this->LstCprAvail = LstCprAvail;
	this->ButCprViewActive = ButCprViewActive;
	this->LstCvrAvail = LstCvrAvail;
	this->ButCvrViewActive = ButCvrViewActive;

	mask = {LSTCPRAVAIL, BUTCPRVIEWACTIVE, LSTCVRAVAIL, BUTCVRVIEWACTIVE};
};

bool PnlWdbeNavCoredev::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWdbeNavCoredev");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWdbeNavCoredev";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCprAvail", LstCprAvail)) add(LSTCPRAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCprViewActive", ButCprViewActive)) add(BUTCPRVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCvrAvail", LstCvrAvail)) add(LSTCVRAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCvrViewActive", ButCvrViewActive)) add(BUTCVRVIEWACTIVE);
	};

	return basefound;
};

set<uint> PnlWdbeNavCoredev::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstCprAvail == comp->LstCprAvail) insert(items, LSTCPRAVAIL);
	if (ButCprViewActive == comp->ButCprViewActive) insert(items, BUTCPRVIEWACTIVE);
	if (LstCvrAvail == comp->LstCvrAvail) insert(items, LSTCVRAVAIL);
	if (ButCvrViewActive == comp->ButCvrViewActive) insert(items, BUTCVRVIEWACTIVE);

	return(items);
};

set<uint> PnlWdbeNavCoredev::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTCPRAVAIL, BUTCPRVIEWACTIVE, LSTCVRAVAIL, BUTCVRVIEWACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeNavCoredev::Tag
 ******************************************************************************/

PnlWdbeNavCoredev::Tag::Tag(
			const string& Cpt
			, const string& CptCpr
			, const string& CptCvr
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptCpr = CptCpr;
	this->CptCvr = CptCvr;

	mask = {CPT, CPTCPR, CPTCVR};
};

bool PnlWdbeNavCoredev::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWdbeNavCoredev");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWdbeNavCoredev";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCpr", CptCpr)) add(CPTCPR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCvr", CptCvr)) add(CPTCVR);
	};

	return basefound;
};

/******************************************************************************
 class PnlWdbeNavCoredev::DpchAppData
 ******************************************************************************/

PnlWdbeNavCoredev::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBENAVCOREDEVDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWdbeNavCoredev::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavCoredev::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeNavCoredevData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeNavCoredev::DpchAppDo
 ******************************************************************************/

PnlWdbeNavCoredev::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBENAVCOREDEVDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWdbeNavCoredev::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavCoredev::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeNavCoredevDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeNavCoredev::DpchEngData
 ******************************************************************************/

PnlWdbeNavCoredev::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBENAVCOREDEVDATA)
		{
	feedFLstCpr.tag = "FeedFLstCpr";
	feedFLstCvr.tag = "FeedFLstCvr";
};

string PnlWdbeNavCoredev::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTCPR)) ss.push_back("feedFLstCpr");
	if (has(FEEDFLSTCVR)) ss.push_back("feedFLstCvr");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavCoredev::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWdbeNavCoredevData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (feedFLstCpr.readXML(docctx, basexpath, true)) add(FEEDFLSTCPR);
		if (feedFLstCvr.readXML(docctx, basexpath, true)) add(FEEDFLSTCVR);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		feedFLstCpr.clear();
		feedFLstCvr.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

