/**
	* \file PnlWdbeVerRec.cpp
	* API code for job PnlWdbeVerRec (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWdbeVerRec.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbeVerRec::VecVDo
 ******************************************************************************/

uint PnlWdbeVerRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlWdbeVerRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlWdbeVerRec::ContInf
 ******************************************************************************/

PnlWdbeVerRec::ContInf::ContInf(
			const string& TxtRef
		) :
			Block()
		{
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

bool PnlWdbeVerRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWdbeVerRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWdbeVerRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
};

set<uint> PnlWdbeVerRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlWdbeVerRec::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTREF};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeVerRec::StatApp
 ******************************************************************************/

PnlWdbeVerRec::StatApp::StatApp(
			const bool initdoneDetail
			, const bool initdone1NRelease
			, const bool initdoneBvr1NVersion
			, const bool initdone1NSystem
			, const bool initdone1NUnit
			, const bool initdoneRef1NFile
			, const bool initdoneMNLibrary
		) :
			Block()
		{
	this->initdoneDetail = initdoneDetail;
	this->initdone1NRelease = initdone1NRelease;
	this->initdoneBvr1NVersion = initdoneBvr1NVersion;
	this->initdone1NSystem = initdone1NSystem;
	this->initdone1NUnit = initdone1NUnit;
	this->initdoneRef1NFile = initdoneRef1NFile;
	this->initdoneMNLibrary = initdoneMNLibrary;

	mask = {INITDONEDETAIL, INITDONE1NRELEASE, INITDONEBVR1NVERSION, INITDONE1NSYSTEM, INITDONE1NUNIT, INITDONEREF1NFILE, INITDONEMNLIBRARY};
};

bool PnlWdbeVerRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWdbeVerRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWdbeVerRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NRelease", initdone1NRelease)) add(INITDONE1NRELEASE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneBvr1NVersion", initdoneBvr1NVersion)) add(INITDONEBVR1NVERSION);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NSystem", initdone1NSystem)) add(INITDONE1NSYSTEM);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NUnit", initdone1NUnit)) add(INITDONE1NUNIT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRef1NFile", initdoneRef1NFile)) add(INITDONEREF1NFILE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNLibrary", initdoneMNLibrary)) add(INITDONEMNLIBRARY);
	};

	return basefound;
};

set<uint> PnlWdbeVerRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdone1NRelease == comp->initdone1NRelease) insert(items, INITDONE1NRELEASE);
	if (initdoneBvr1NVersion == comp->initdoneBvr1NVersion) insert(items, INITDONEBVR1NVERSION);
	if (initdone1NSystem == comp->initdone1NSystem) insert(items, INITDONE1NSYSTEM);
	if (initdone1NUnit == comp->initdone1NUnit) insert(items, INITDONE1NUNIT);
	if (initdoneRef1NFile == comp->initdoneRef1NFile) insert(items, INITDONEREF1NFILE);
	if (initdoneMNLibrary == comp->initdoneMNLibrary) insert(items, INITDONEMNLIBRARY);

	return(items);
};

set<uint> PnlWdbeVerRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEDETAIL, INITDONE1NRELEASE, INITDONEBVR1NVERSION, INITDONE1NSYSTEM, INITDONE1NUNIT, INITDONEREF1NFILE, INITDONEMNLIBRARY};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeVerRec::StatShr
 ******************************************************************************/

PnlWdbeVerRec::StatShr::StatShr(
			const uint ixWdbeVExpstate
			, const string& scrJrefDetail
			, const string& scrJref1NRelease
			, const string& scrJrefBvr1NVersion
			, const string& scrJref1NSystem
			, const string& scrJref1NUnit
			, const string& scrJrefRef1NFile
			, const string& scrJrefMNLibrary
			, const bool ButRegularizeActive
		) :
			Block()
		{
	this->ixWdbeVExpstate = ixWdbeVExpstate;
	this->scrJrefDetail = scrJrefDetail;
	this->scrJref1NRelease = scrJref1NRelease;
	this->scrJrefBvr1NVersion = scrJrefBvr1NVersion;
	this->scrJref1NSystem = scrJref1NSystem;
	this->scrJref1NUnit = scrJref1NUnit;
	this->scrJrefRef1NFile = scrJrefRef1NFile;
	this->scrJrefMNLibrary = scrJrefMNLibrary;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXWDBEVEXPSTATE, SCRJREFDETAIL, SCRJREF1NRELEASE, SCRJREFBVR1NVERSION, SCRJREF1NSYSTEM, SCRJREF1NUNIT, SCRJREFREF1NFILE, SCRJREFMNLIBRARY, BUTREGULARIZEACTIVE};
};

bool PnlWdbeVerRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWdbeVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWdbeVerRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWdbeVerRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", srefIxWdbeVExpstate)) {
			ixWdbeVExpstate = VecWdbeVExpstate::getIx(srefIxWdbeVExpstate);
			add(IXWDBEVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NRelease", scrJref1NRelease)) add(SCRJREF1NRELEASE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefBvr1NVersion", scrJrefBvr1NVersion)) add(SCRJREFBVR1NVERSION);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NSystem", scrJref1NSystem)) add(SCRJREF1NSYSTEM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NUnit", scrJref1NUnit)) add(SCRJREF1NUNIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRef1NFile", scrJrefRef1NFile)) add(SCRJREFREF1NFILE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNLibrary", scrJrefMNLibrary)) add(SCRJREFMNLIBRARY);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlWdbeVerRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWdbeVExpstate == comp->ixWdbeVExpstate) insert(items, IXWDBEVEXPSTATE);
	if (scrJrefDetail == comp->scrJrefDetail) insert(items, SCRJREFDETAIL);
	if (scrJref1NRelease == comp->scrJref1NRelease) insert(items, SCRJREF1NRELEASE);
	if (scrJrefBvr1NVersion == comp->scrJrefBvr1NVersion) insert(items, SCRJREFBVR1NVERSION);
	if (scrJref1NSystem == comp->scrJref1NSystem) insert(items, SCRJREF1NSYSTEM);
	if (scrJref1NUnit == comp->scrJref1NUnit) insert(items, SCRJREF1NUNIT);
	if (scrJrefRef1NFile == comp->scrJrefRef1NFile) insert(items, SCRJREFREF1NFILE);
	if (scrJrefMNLibrary == comp->scrJrefMNLibrary) insert(items, SCRJREFMNLIBRARY);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlWdbeVerRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWDBEVEXPSTATE, SCRJREFDETAIL, SCRJREF1NRELEASE, SCRJREFBVR1NVERSION, SCRJREF1NSYSTEM, SCRJREF1NUNIT, SCRJREFREF1NFILE, SCRJREFMNLIBRARY, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeVerRec::Tag
 ******************************************************************************/

PnlWdbeVerRec::Tag::Tag(
			const string& Cpt
		) :
			Block()
		{
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlWdbeVerRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWdbeVerRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWdbeVerRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWdbeVerRec::DpchAppDo
 ******************************************************************************/

PnlWdbeVerRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEVERRECDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWdbeVerRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeVerRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeVerRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeVerRec::DpchEngData
 ******************************************************************************/

PnlWdbeVerRec::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBEVERRECDATA)
		{
};

string PnlWdbeVerRec::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeVerRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWdbeVerRecData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		continf = ContInf();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
