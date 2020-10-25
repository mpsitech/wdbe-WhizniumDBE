/**
	* \file PnlWdbePrsHeadbar.cpp
	* API code for job PnlWdbePrsHeadbar (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "PnlWdbePrsHeadbar.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbePrsHeadbar::StgInf
 ******************************************************************************/

PnlWdbePrsHeadbar::StgInf::StgInf(
			const uint MenAppCptwidth
			, const uint MenAppWidth
			, const uint MenCrdCptwidth
			, const uint MenCrdWidth
		) :
			Block()
		{
	this->MenAppCptwidth = MenAppCptwidth;
	this->MenAppWidth = MenAppWidth;
	this->MenCrdCptwidth = MenCrdCptwidth;
	this->MenCrdWidth = MenCrdWidth;

	mask = {MENAPPCPTWIDTH, MENAPPWIDTH, MENCRDCPTWIDTH, MENCRDWIDTH};
};

bool PnlWdbePrsHeadbar::StgInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgInfWdbePrsHeadbar");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemInfWdbePrsHeadbar";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MenAppCptwidth", MenAppCptwidth)) add(MENAPPCPTWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MenAppWidth", MenAppWidth)) add(MENAPPWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MenCrdCptwidth", MenCrdCptwidth)) add(MENCRDCPTWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MenCrdWidth", MenCrdWidth)) add(MENCRDWIDTH);
	};

	return basefound;
};

set<uint> PnlWdbePrsHeadbar::StgInf::comm(
			const StgInf* comp
		) {
	set<uint> items;

	if (MenAppCptwidth == comp->MenAppCptwidth) insert(items, MENAPPCPTWIDTH);
	if (MenAppWidth == comp->MenAppWidth) insert(items, MENAPPWIDTH);
	if (MenCrdCptwidth == comp->MenCrdCptwidth) insert(items, MENCRDCPTWIDTH);
	if (MenCrdWidth == comp->MenCrdWidth) insert(items, MENCRDWIDTH);

	return(items);
};

set<uint> PnlWdbePrsHeadbar::StgInf::diff(
			const StgInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {MENAPPCPTWIDTH, MENAPPWIDTH, MENCRDCPTWIDTH, MENCRDWIDTH};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbePrsHeadbar::Tag
 ******************************************************************************/

PnlWdbePrsHeadbar::Tag::Tag(
			const string& MenApp
			, const string& MenCrd
		) :
			Block()
		{
	this->MenApp = MenApp;
	this->MenCrd = MenCrd;

	mask = {MENAPP, MENCRD};
};

bool PnlWdbePrsHeadbar::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWdbePrsHeadbar");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWdbePrsHeadbar";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MenApp", MenApp)) add(MENAPP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MenCrd", MenCrd)) add(MENCRD);
	};

	return basefound;
};

/******************************************************************************
 class PnlWdbePrsHeadbar::DpchEngData
 ******************************************************************************/

PnlWdbePrsHeadbar::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBEPRSHEADBARDATA)
		{
};

string PnlWdbePrsHeadbar::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(STGINF)) ss.push_back("stginf");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbePrsHeadbar::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWdbePrsHeadbarData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (stginf.readXML(docctx, basexpath, true)) add(STGINF);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		stginf = StgInf();
		tag = Tag();
	};
};

