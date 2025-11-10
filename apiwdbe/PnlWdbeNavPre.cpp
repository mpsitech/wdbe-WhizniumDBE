/**
	* \file PnlWdbeNavPre.cpp
	* API code for job PnlWdbeNavPre (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWdbeNavPre.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbeNavPre::VecVDo
 ******************************************************************************/

uint PnlWdbeNavPre::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butcvrremoveclick") return BUTCVRREMOVECLICK;
	if (s == "butuntremoveclick") return BUTUNTREMOVECLICK;
	if (s == "butverremoveclick") return BUTVERREMOVECLICK;

	return(0);
};

string PnlWdbeNavPre::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTCVRREMOVECLICK) return("ButCvrRemoveClick");
	if (ix == BUTUNTREMOVECLICK) return("ButUntRemoveClick");
	if (ix == BUTVERREMOVECLICK) return("ButVerRemoveClick");

	return("");
};

/******************************************************************************
 class PnlWdbeNavPre::ContInf
 ******************************************************************************/

PnlWdbeNavPre::ContInf::ContInf(
			const string& TxtCvr
			, const string& TxtUnt
			, const string& TxtVer
		) :
			Block()
			, TxtCvr(TxtCvr)
			, TxtUnt(TxtUnt)
			, TxtVer(TxtVer)
		{
	mask = {TXTCVR, TXTUNT, TXTVER};
};

bool PnlWdbeNavPre::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWdbeNavPre");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWdbeNavPre";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtCvr", TxtCvr)) add(TXTCVR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtUnt", TxtUnt)) add(TXTUNT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtVer", TxtVer)) add(TXTVER);
	};

	return basefound;
};

set<uint> PnlWdbeNavPre::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtCvr == comp->TxtCvr) insert(items, TXTCVR);
	if (TxtUnt == comp->TxtUnt) insert(items, TXTUNT);
	if (TxtVer == comp->TxtVer) insert(items, TXTVER);

	return(items);
};

set<uint> PnlWdbeNavPre::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTCVR, TXTUNT, TXTVER};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeNavPre::StatShr
 ******************************************************************************/

PnlWdbeNavPre::StatShr::StatShr(
			const bool TxtCvrAvail
			, const bool TxtUntAvail
			, const bool TxtVerAvail
		) :
			Block()
			, TxtCvrAvail(TxtCvrAvail)
			, TxtUntAvail(TxtUntAvail)
			, TxtVerAvail(TxtVerAvail)
		{
	mask = {TXTCVRAVAIL, TXTUNTAVAIL, TXTVERAVAIL};
};

bool PnlWdbeNavPre::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWdbeNavPre");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWdbeNavPre";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtCvrAvail", TxtCvrAvail)) add(TXTCVRAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtUntAvail", TxtUntAvail)) add(TXTUNTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtVerAvail", TxtVerAvail)) add(TXTVERAVAIL);
	};

	return basefound;
};

set<uint> PnlWdbeNavPre::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxtCvrAvail == comp->TxtCvrAvail) insert(items, TXTCVRAVAIL);
	if (TxtUntAvail == comp->TxtUntAvail) insert(items, TXTUNTAVAIL);
	if (TxtVerAvail == comp->TxtVerAvail) insert(items, TXTVERAVAIL);

	return(items);
};

set<uint> PnlWdbeNavPre::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTCVRAVAIL, TXTUNTAVAIL, TXTVERAVAIL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeNavPre::Tag
 ******************************************************************************/

PnlWdbeNavPre::Tag::Tag(
			const string& CptCvr
			, const string& CptUnt
			, const string& CptVer
		) :
			Block()
			, CptCvr(CptCvr)
			, CptUnt(CptUnt)
			, CptVer(CptVer)
		{
	mask = {CPTCVR, CPTUNT, CPTVER};
};

bool PnlWdbeNavPre::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWdbeNavPre");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWdbeNavPre";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCvr", CptCvr)) add(CPTCVR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptUnt", CptUnt)) add(CPTUNT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVer", CptVer)) add(CPTVER);
	};

	return basefound;
};

/******************************************************************************
 class PnlWdbeNavPre::DpchAppDo
 ******************************************************************************/

PnlWdbeNavPre::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBENAVPREDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string PnlWdbeNavPre::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavPre::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeNavPreDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeNavPre::DpchEngData
 ******************************************************************************/

PnlWdbeNavPre::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBENAVPREDATA)
		{
};

string PnlWdbeNavPre::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavPre::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWdbeNavPreData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		continf = ContInf();
		statshr = StatShr();
		tag = Tag();
	};
};
