/**
	* \file PnlWdbeMtpRec.cpp
	* API code for job PnlWdbeMtpRec (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWdbeMtpRec.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbeMtpRec::VecVDo
 ******************************************************************************/

uint PnlWdbeMtpRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlWdbeMtpRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlWdbeMtpRec::ContInf
 ******************************************************************************/

PnlWdbeMtpRec::ContInf::ContInf(
			const string& TxtRef
		) :
			Block()
		{
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

bool PnlWdbeMtpRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWdbeMtpRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWdbeMtpRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
};

set<uint> PnlWdbeMtpRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlWdbeMtpRec::ContInf::diff(
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
 class PnlWdbeMtpRec::StatApp
 ******************************************************************************/

PnlWdbeMtpRec::StatApp::StatApp(
			const bool initdoneDetail
			, const bool initdoneKParKey
			, const bool initdoneKHdltype
			, const bool initdoneAPar
			, const bool initdoneMdl1NGeneric
			, const bool initdoneHsm1NPipeline
			, const bool initdoneMdl1NPort
			, const bool initdoneTpl1NModule
			, const bool initdoneSup1NModule
			, const bool initdoneRef1NSensitivity
			, const bool initdoneRef1NVariable
			, const bool initdoneMge1NSignal
			, const bool initdoneRef1NFile
		) :
			Block()
		{
	this->initdoneDetail = initdoneDetail;
	this->initdoneKParKey = initdoneKParKey;
	this->initdoneKHdltype = initdoneKHdltype;
	this->initdoneAPar = initdoneAPar;
	this->initdoneMdl1NGeneric = initdoneMdl1NGeneric;
	this->initdoneHsm1NPipeline = initdoneHsm1NPipeline;
	this->initdoneMdl1NPort = initdoneMdl1NPort;
	this->initdoneTpl1NModule = initdoneTpl1NModule;
	this->initdoneSup1NModule = initdoneSup1NModule;
	this->initdoneRef1NSensitivity = initdoneRef1NSensitivity;
	this->initdoneRef1NVariable = initdoneRef1NVariable;
	this->initdoneMge1NSignal = initdoneMge1NSignal;
	this->initdoneRef1NFile = initdoneRef1NFile;

	mask = {INITDONEDETAIL, INITDONEKPARKEY, INITDONEKHDLTYPE, INITDONEAPAR, INITDONEMDL1NGENERIC, INITDONEHSM1NPIPELINE, INITDONEMDL1NPORT, INITDONETPL1NMODULE, INITDONESUP1NMODULE, INITDONEREF1NSENSITIVITY, INITDONEREF1NVARIABLE, INITDONEMGE1NSIGNAL, INITDONEREF1NFILE};
};

bool PnlWdbeMtpRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWdbeMtpRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWdbeMtpRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneKParKey", initdoneKParKey)) add(INITDONEKPARKEY);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneKHdltype", initdoneKHdltype)) add(INITDONEKHDLTYPE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneAPar", initdoneAPar)) add(INITDONEAPAR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMdl1NGeneric", initdoneMdl1NGeneric)) add(INITDONEMDL1NGENERIC);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHsm1NPipeline", initdoneHsm1NPipeline)) add(INITDONEHSM1NPIPELINE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMdl1NPort", initdoneMdl1NPort)) add(INITDONEMDL1NPORT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneTpl1NModule", initdoneTpl1NModule)) add(INITDONETPL1NMODULE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneSup1NModule", initdoneSup1NModule)) add(INITDONESUP1NMODULE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRef1NSensitivity", initdoneRef1NSensitivity)) add(INITDONEREF1NSENSITIVITY);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRef1NVariable", initdoneRef1NVariable)) add(INITDONEREF1NVARIABLE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMge1NSignal", initdoneMge1NSignal)) add(INITDONEMGE1NSIGNAL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRef1NFile", initdoneRef1NFile)) add(INITDONEREF1NFILE);
	};

	return basefound;
};

set<uint> PnlWdbeMtpRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdoneKParKey == comp->initdoneKParKey) insert(items, INITDONEKPARKEY);
	if (initdoneKHdltype == comp->initdoneKHdltype) insert(items, INITDONEKHDLTYPE);
	if (initdoneAPar == comp->initdoneAPar) insert(items, INITDONEAPAR);
	if (initdoneMdl1NGeneric == comp->initdoneMdl1NGeneric) insert(items, INITDONEMDL1NGENERIC);
	if (initdoneHsm1NPipeline == comp->initdoneHsm1NPipeline) insert(items, INITDONEHSM1NPIPELINE);
	if (initdoneMdl1NPort == comp->initdoneMdl1NPort) insert(items, INITDONEMDL1NPORT);
	if (initdoneTpl1NModule == comp->initdoneTpl1NModule) insert(items, INITDONETPL1NMODULE);
	if (initdoneSup1NModule == comp->initdoneSup1NModule) insert(items, INITDONESUP1NMODULE);
	if (initdoneRef1NSensitivity == comp->initdoneRef1NSensitivity) insert(items, INITDONEREF1NSENSITIVITY);
	if (initdoneRef1NVariable == comp->initdoneRef1NVariable) insert(items, INITDONEREF1NVARIABLE);
	if (initdoneMge1NSignal == comp->initdoneMge1NSignal) insert(items, INITDONEMGE1NSIGNAL);
	if (initdoneRef1NFile == comp->initdoneRef1NFile) insert(items, INITDONEREF1NFILE);

	return(items);
};

set<uint> PnlWdbeMtpRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEDETAIL, INITDONEKPARKEY, INITDONEKHDLTYPE, INITDONEAPAR, INITDONEMDL1NGENERIC, INITDONEHSM1NPIPELINE, INITDONEMDL1NPORT, INITDONETPL1NMODULE, INITDONESUP1NMODULE, INITDONEREF1NSENSITIVITY, INITDONEREF1NVARIABLE, INITDONEMGE1NSIGNAL, INITDONEREF1NFILE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeMtpRec::StatShr
 ******************************************************************************/

PnlWdbeMtpRec::StatShr::StatShr(
			const uint ixWdbeVExpstate
			, const string& scrJrefDetail
			, const string& scrJrefKParKey
			, const string& scrJrefKHdltype
			, const string& scrJrefAPar
			, const string& scrJrefMdl1NGeneric
			, const string& scrJrefHsm1NPipeline
			, const string& scrJrefMdl1NPort
			, const string& scrJrefTpl1NModule
			, const string& scrJrefSup1NModule
			, const string& scrJrefRef1NSensitivity
			, const string& scrJrefRef1NVariable
			, const string& scrJrefMge1NSignal
			, const string& scrJrefRef1NFile
			, const bool ButRegularizeActive
		) :
			Block()
		{
	this->ixWdbeVExpstate = ixWdbeVExpstate;
	this->scrJrefDetail = scrJrefDetail;
	this->scrJrefKParKey = scrJrefKParKey;
	this->scrJrefKHdltype = scrJrefKHdltype;
	this->scrJrefAPar = scrJrefAPar;
	this->scrJrefMdl1NGeneric = scrJrefMdl1NGeneric;
	this->scrJrefHsm1NPipeline = scrJrefHsm1NPipeline;
	this->scrJrefMdl1NPort = scrJrefMdl1NPort;
	this->scrJrefTpl1NModule = scrJrefTpl1NModule;
	this->scrJrefSup1NModule = scrJrefSup1NModule;
	this->scrJrefRef1NSensitivity = scrJrefRef1NSensitivity;
	this->scrJrefRef1NVariable = scrJrefRef1NVariable;
	this->scrJrefMge1NSignal = scrJrefMge1NSignal;
	this->scrJrefRef1NFile = scrJrefRef1NFile;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXWDBEVEXPSTATE, SCRJREFDETAIL, SCRJREFKPARKEY, SCRJREFKHDLTYPE, SCRJREFAPAR, SCRJREFMDL1NGENERIC, SCRJREFHSM1NPIPELINE, SCRJREFMDL1NPORT, SCRJREFTPL1NMODULE, SCRJREFSUP1NMODULE, SCRJREFREF1NSENSITIVITY, SCRJREFREF1NVARIABLE, SCRJREFMGE1NSIGNAL, SCRJREFREF1NFILE, BUTREGULARIZEACTIVE};
};

bool PnlWdbeMtpRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWdbeVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWdbeMtpRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWdbeMtpRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", srefIxWdbeVExpstate)) {
			ixWdbeVExpstate = VecWdbeVExpstate::getIx(srefIxWdbeVExpstate);
			add(IXWDBEVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefKParKey", scrJrefKParKey)) add(SCRJREFKPARKEY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefKHdltype", scrJrefKHdltype)) add(SCRJREFKHDLTYPE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAPar", scrJrefAPar)) add(SCRJREFAPAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMdl1NGeneric", scrJrefMdl1NGeneric)) add(SCRJREFMDL1NGENERIC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHsm1NPipeline", scrJrefHsm1NPipeline)) add(SCRJREFHSM1NPIPELINE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMdl1NPort", scrJrefMdl1NPort)) add(SCRJREFMDL1NPORT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefTpl1NModule", scrJrefTpl1NModule)) add(SCRJREFTPL1NMODULE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefSup1NModule", scrJrefSup1NModule)) add(SCRJREFSUP1NMODULE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRef1NSensitivity", scrJrefRef1NSensitivity)) add(SCRJREFREF1NSENSITIVITY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRef1NVariable", scrJrefRef1NVariable)) add(SCRJREFREF1NVARIABLE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMge1NSignal", scrJrefMge1NSignal)) add(SCRJREFMGE1NSIGNAL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRef1NFile", scrJrefRef1NFile)) add(SCRJREFREF1NFILE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlWdbeMtpRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWdbeVExpstate == comp->ixWdbeVExpstate) insert(items, IXWDBEVEXPSTATE);
	if (scrJrefDetail == comp->scrJrefDetail) insert(items, SCRJREFDETAIL);
	if (scrJrefKParKey == comp->scrJrefKParKey) insert(items, SCRJREFKPARKEY);
	if (scrJrefKHdltype == comp->scrJrefKHdltype) insert(items, SCRJREFKHDLTYPE);
	if (scrJrefAPar == comp->scrJrefAPar) insert(items, SCRJREFAPAR);
	if (scrJrefMdl1NGeneric == comp->scrJrefMdl1NGeneric) insert(items, SCRJREFMDL1NGENERIC);
	if (scrJrefHsm1NPipeline == comp->scrJrefHsm1NPipeline) insert(items, SCRJREFHSM1NPIPELINE);
	if (scrJrefMdl1NPort == comp->scrJrefMdl1NPort) insert(items, SCRJREFMDL1NPORT);
	if (scrJrefTpl1NModule == comp->scrJrefTpl1NModule) insert(items, SCRJREFTPL1NMODULE);
	if (scrJrefSup1NModule == comp->scrJrefSup1NModule) insert(items, SCRJREFSUP1NMODULE);
	if (scrJrefRef1NSensitivity == comp->scrJrefRef1NSensitivity) insert(items, SCRJREFREF1NSENSITIVITY);
	if (scrJrefRef1NVariable == comp->scrJrefRef1NVariable) insert(items, SCRJREFREF1NVARIABLE);
	if (scrJrefMge1NSignal == comp->scrJrefMge1NSignal) insert(items, SCRJREFMGE1NSIGNAL);
	if (scrJrefRef1NFile == comp->scrJrefRef1NFile) insert(items, SCRJREFREF1NFILE);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlWdbeMtpRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWDBEVEXPSTATE, SCRJREFDETAIL, SCRJREFKPARKEY, SCRJREFKHDLTYPE, SCRJREFAPAR, SCRJREFMDL1NGENERIC, SCRJREFHSM1NPIPELINE, SCRJREFMDL1NPORT, SCRJREFTPL1NMODULE, SCRJREFSUP1NMODULE, SCRJREFREF1NSENSITIVITY, SCRJREFREF1NVARIABLE, SCRJREFMGE1NSIGNAL, SCRJREFREF1NFILE, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeMtpRec::Tag
 ******************************************************************************/

PnlWdbeMtpRec::Tag::Tag(
			const string& Cpt
		) :
			Block()
		{
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlWdbeMtpRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWdbeMtpRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWdbeMtpRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWdbeMtpRec::DpchAppDo
 ******************************************************************************/

PnlWdbeMtpRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEMTPRECDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWdbeMtpRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeMtpRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeMtpRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeMtpRec::DpchEngData
 ******************************************************************************/

PnlWdbeMtpRec::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBEMTPRECDATA)
		{
};

string PnlWdbeMtpRec::DpchEngData::getSrefsMask() {
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

void PnlWdbeMtpRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWdbeMtpRecData");
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
