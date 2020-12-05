/**
	* \file PnlWdbePrcRec.cpp
	* API code for job PnlWdbePrcRec (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWdbePrcRec.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbePrcRec::VecVDo
 ******************************************************************************/

uint PnlWdbePrcRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlWdbePrcRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlWdbePrcRec::ContInf
 ******************************************************************************/

PnlWdbePrcRec::ContInf::ContInf(
			const string& TxtRef
		) :
			Block()
		{
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

bool PnlWdbePrcRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWdbePrcRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWdbePrcRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
};

set<uint> PnlWdbePrcRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlWdbePrcRec::ContInf::diff(
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
 class PnlWdbePrcRec::StatApp
 ******************************************************************************/

PnlWdbePrcRec::StatApp::StatApp(
			const bool initdoneDetail
			, const bool initdoneKHdltype
			, const bool initdonePrc1NVariable
			, const bool initdoneMge1NSignal
			, const bool initdoneFsmFsm1NFsmstate
		) :
			Block()
		{
	this->initdoneDetail = initdoneDetail;
	this->initdoneKHdltype = initdoneKHdltype;
	this->initdonePrc1NVariable = initdonePrc1NVariable;
	this->initdoneMge1NSignal = initdoneMge1NSignal;
	this->initdoneFsmFsm1NFsmstate = initdoneFsmFsm1NFsmstate;

	mask = {INITDONEDETAIL, INITDONEKHDLTYPE, INITDONEPRC1NVARIABLE, INITDONEMGE1NSIGNAL, INITDONEFSMFSM1NFSMSTATE};
};

bool PnlWdbePrcRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWdbePrcRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWdbePrcRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneKHdltype", initdoneKHdltype)) add(INITDONEKHDLTYPE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdonePrc1NVariable", initdonePrc1NVariable)) add(INITDONEPRC1NVARIABLE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMge1NSignal", initdoneMge1NSignal)) add(INITDONEMGE1NSIGNAL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneFsmFsm1NFsmstate", initdoneFsmFsm1NFsmstate)) add(INITDONEFSMFSM1NFSMSTATE);
	};

	return basefound;
};

set<uint> PnlWdbePrcRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdoneKHdltype == comp->initdoneKHdltype) insert(items, INITDONEKHDLTYPE);
	if (initdonePrc1NVariable == comp->initdonePrc1NVariable) insert(items, INITDONEPRC1NVARIABLE);
	if (initdoneMge1NSignal == comp->initdoneMge1NSignal) insert(items, INITDONEMGE1NSIGNAL);
	if (initdoneFsmFsm1NFsmstate == comp->initdoneFsmFsm1NFsmstate) insert(items, INITDONEFSMFSM1NFSMSTATE);

	return(items);
};

set<uint> PnlWdbePrcRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEDETAIL, INITDONEKHDLTYPE, INITDONEPRC1NVARIABLE, INITDONEMGE1NSIGNAL, INITDONEFSMFSM1NFSMSTATE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbePrcRec::StatShr
 ******************************************************************************/

PnlWdbePrcRec::StatShr::StatShr(
			const uint ixWdbeVExpstate
			, const string& scrJrefDetail
			, const string& scrJrefKHdltype
			, const string& scrJrefPrc1NVariable
			, const string& scrJrefMge1NSignal
			, const string& scrJrefFsmFsm1NFsmstate
			, const bool pnlfsmfsm1nfsmstateAvail
			, const bool ButRegularizeActive
		) :
			Block()
		{
	this->ixWdbeVExpstate = ixWdbeVExpstate;
	this->scrJrefDetail = scrJrefDetail;
	this->scrJrefKHdltype = scrJrefKHdltype;
	this->scrJrefPrc1NVariable = scrJrefPrc1NVariable;
	this->scrJrefMge1NSignal = scrJrefMge1NSignal;
	this->scrJrefFsmFsm1NFsmstate = scrJrefFsmFsm1NFsmstate;
	this->pnlfsmfsm1nfsmstateAvail = pnlfsmfsm1nfsmstateAvail;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXWDBEVEXPSTATE, SCRJREFDETAIL, SCRJREFKHDLTYPE, SCRJREFPRC1NVARIABLE, SCRJREFMGE1NSIGNAL, SCRJREFFSMFSM1NFSMSTATE, PNLFSMFSM1NFSMSTATEAVAIL, BUTREGULARIZEACTIVE};
};

bool PnlWdbePrcRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWdbeVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWdbePrcRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWdbePrcRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", srefIxWdbeVExpstate)) {
			ixWdbeVExpstate = VecWdbeVExpstate::getIx(srefIxWdbeVExpstate);
			add(IXWDBEVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefKHdltype", scrJrefKHdltype)) add(SCRJREFKHDLTYPE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefPrc1NVariable", scrJrefPrc1NVariable)) add(SCRJREFPRC1NVARIABLE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMge1NSignal", scrJrefMge1NSignal)) add(SCRJREFMGE1NSIGNAL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefFsmFsm1NFsmstate", scrJrefFsmFsm1NFsmstate)) add(SCRJREFFSMFSM1NFSMSTATE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlfsmfsm1nfsmstateAvail", pnlfsmfsm1nfsmstateAvail)) add(PNLFSMFSM1NFSMSTATEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlWdbePrcRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWdbeVExpstate == comp->ixWdbeVExpstate) insert(items, IXWDBEVEXPSTATE);
	if (scrJrefDetail == comp->scrJrefDetail) insert(items, SCRJREFDETAIL);
	if (scrJrefKHdltype == comp->scrJrefKHdltype) insert(items, SCRJREFKHDLTYPE);
	if (scrJrefPrc1NVariable == comp->scrJrefPrc1NVariable) insert(items, SCRJREFPRC1NVARIABLE);
	if (scrJrefMge1NSignal == comp->scrJrefMge1NSignal) insert(items, SCRJREFMGE1NSIGNAL);
	if (scrJrefFsmFsm1NFsmstate == comp->scrJrefFsmFsm1NFsmstate) insert(items, SCRJREFFSMFSM1NFSMSTATE);
	if (pnlfsmfsm1nfsmstateAvail == comp->pnlfsmfsm1nfsmstateAvail) insert(items, PNLFSMFSM1NFSMSTATEAVAIL);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlWdbePrcRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWDBEVEXPSTATE, SCRJREFDETAIL, SCRJREFKHDLTYPE, SCRJREFPRC1NVARIABLE, SCRJREFMGE1NSIGNAL, SCRJREFFSMFSM1NFSMSTATE, PNLFSMFSM1NFSMSTATEAVAIL, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbePrcRec::Tag
 ******************************************************************************/

PnlWdbePrcRec::Tag::Tag(
			const string& Cpt
		) :
			Block()
		{
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlWdbePrcRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWdbePrcRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWdbePrcRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWdbePrcRec::DpchAppDo
 ******************************************************************************/

PnlWdbePrcRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEPRCRECDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWdbePrcRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbePrcRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbePrcRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbePrcRec::DpchEngData
 ******************************************************************************/

PnlWdbePrcRec::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBEPRCRECDATA)
		{
};

string PnlWdbePrcRec::DpchEngData::getSrefsMask() {
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

void PnlWdbePrcRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWdbePrcRecData");
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

