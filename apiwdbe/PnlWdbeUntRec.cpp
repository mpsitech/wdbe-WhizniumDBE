/**
	* \file PnlWdbeUntRec.cpp
	* API code for job PnlWdbeUntRec (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWdbeUntRec.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbeUntRec::VecVDo
 ******************************************************************************/

uint PnlWdbeUntRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlWdbeUntRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlWdbeUntRec::ContInf
 ******************************************************************************/

PnlWdbeUntRec::ContInf::ContInf(
			const string& TxtRef
		) :
			Block()
		{
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

bool PnlWdbeUntRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWdbeUntRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWdbeUntRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
};

set<uint> PnlWdbeUntRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlWdbeUntRec::ContInf::diff(
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
 class PnlWdbeUntRec::StatApp
 ******************************************************************************/

PnlWdbeUntRec::StatApp::StatApp(
			const bool initdoneDetail
			, const bool initdone1NBank
			, const bool initdoneFwd1NController
			, const bool initdone1NTarget
			, const bool initdoneSil1NUnit
			, const bool initdone1NPeripheral
			, const bool initdoneRef1NCommand
			, const bool initdoneHk1NModule
			, const bool initdoneHk1NVector
			, const bool initdoneRef1NError
		) :
			Block()
		{
	this->initdoneDetail = initdoneDetail;
	this->initdone1NBank = initdone1NBank;
	this->initdoneFwd1NController = initdoneFwd1NController;
	this->initdone1NTarget = initdone1NTarget;
	this->initdoneSil1NUnit = initdoneSil1NUnit;
	this->initdone1NPeripheral = initdone1NPeripheral;
	this->initdoneRef1NCommand = initdoneRef1NCommand;
	this->initdoneHk1NModule = initdoneHk1NModule;
	this->initdoneHk1NVector = initdoneHk1NVector;
	this->initdoneRef1NError = initdoneRef1NError;

	mask = {INITDONEDETAIL, INITDONE1NBANK, INITDONEFWD1NCONTROLLER, INITDONE1NTARGET, INITDONESIL1NUNIT, INITDONE1NPERIPHERAL, INITDONEREF1NCOMMAND, INITDONEHK1NMODULE, INITDONEHK1NVECTOR, INITDONEREF1NERROR};
};

bool PnlWdbeUntRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWdbeUntRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWdbeUntRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NBank", initdone1NBank)) add(INITDONE1NBANK);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneFwd1NController", initdoneFwd1NController)) add(INITDONEFWD1NCONTROLLER);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NTarget", initdone1NTarget)) add(INITDONE1NTARGET);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneSil1NUnit", initdoneSil1NUnit)) add(INITDONESIL1NUNIT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NPeripheral", initdone1NPeripheral)) add(INITDONE1NPERIPHERAL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRef1NCommand", initdoneRef1NCommand)) add(INITDONEREF1NCOMMAND);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHk1NModule", initdoneHk1NModule)) add(INITDONEHK1NMODULE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHk1NVector", initdoneHk1NVector)) add(INITDONEHK1NVECTOR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRef1NError", initdoneRef1NError)) add(INITDONEREF1NERROR);
	};

	return basefound;
};

set<uint> PnlWdbeUntRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdone1NBank == comp->initdone1NBank) insert(items, INITDONE1NBANK);
	if (initdoneFwd1NController == comp->initdoneFwd1NController) insert(items, INITDONEFWD1NCONTROLLER);
	if (initdone1NTarget == comp->initdone1NTarget) insert(items, INITDONE1NTARGET);
	if (initdoneSil1NUnit == comp->initdoneSil1NUnit) insert(items, INITDONESIL1NUNIT);
	if (initdone1NPeripheral == comp->initdone1NPeripheral) insert(items, INITDONE1NPERIPHERAL);
	if (initdoneRef1NCommand == comp->initdoneRef1NCommand) insert(items, INITDONEREF1NCOMMAND);
	if (initdoneHk1NModule == comp->initdoneHk1NModule) insert(items, INITDONEHK1NMODULE);
	if (initdoneHk1NVector == comp->initdoneHk1NVector) insert(items, INITDONEHK1NVECTOR);
	if (initdoneRef1NError == comp->initdoneRef1NError) insert(items, INITDONEREF1NERROR);

	return(items);
};

set<uint> PnlWdbeUntRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEDETAIL, INITDONE1NBANK, INITDONEFWD1NCONTROLLER, INITDONE1NTARGET, INITDONESIL1NUNIT, INITDONE1NPERIPHERAL, INITDONEREF1NCOMMAND, INITDONEHK1NMODULE, INITDONEHK1NVECTOR, INITDONEREF1NERROR};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeUntRec::StatShr
 ******************************************************************************/

PnlWdbeUntRec::StatShr::StatShr(
			const uint ixWdbeVExpstate
			, const string& scrJrefDetail
			, const string& scrJref1NBank
			, const string& scrJrefFwd1NController
			, const string& scrJref1NTarget
			, const string& scrJrefSil1NUnit
			, const bool pnlsil1nunitAvail
			, const string& scrJref1NPeripheral
			, const string& scrJrefRef1NCommand
			, const string& scrJrefHk1NModule
			, const string& scrJrefHk1NVector
			, const string& scrJrefRef1NError
			, const bool ButRegularizeActive
		) :
			Block()
		{
	this->ixWdbeVExpstate = ixWdbeVExpstate;
	this->scrJrefDetail = scrJrefDetail;
	this->scrJref1NBank = scrJref1NBank;
	this->scrJrefFwd1NController = scrJrefFwd1NController;
	this->scrJref1NTarget = scrJref1NTarget;
	this->scrJrefSil1NUnit = scrJrefSil1NUnit;
	this->pnlsil1nunitAvail = pnlsil1nunitAvail;
	this->scrJref1NPeripheral = scrJref1NPeripheral;
	this->scrJrefRef1NCommand = scrJrefRef1NCommand;
	this->scrJrefHk1NModule = scrJrefHk1NModule;
	this->scrJrefHk1NVector = scrJrefHk1NVector;
	this->scrJrefRef1NError = scrJrefRef1NError;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXWDBEVEXPSTATE, SCRJREFDETAIL, SCRJREF1NBANK, SCRJREFFWD1NCONTROLLER, SCRJREF1NTARGET, SCRJREFSIL1NUNIT, PNLSIL1NUNITAVAIL, SCRJREF1NPERIPHERAL, SCRJREFREF1NCOMMAND, SCRJREFHK1NMODULE, SCRJREFHK1NVECTOR, SCRJREFREF1NERROR, BUTREGULARIZEACTIVE};
};

bool PnlWdbeUntRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWdbeVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWdbeUntRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWdbeUntRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", srefIxWdbeVExpstate)) {
			ixWdbeVExpstate = VecWdbeVExpstate::getIx(srefIxWdbeVExpstate);
			add(IXWDBEVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NBank", scrJref1NBank)) add(SCRJREF1NBANK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefFwd1NController", scrJrefFwd1NController)) add(SCRJREFFWD1NCONTROLLER);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NTarget", scrJref1NTarget)) add(SCRJREF1NTARGET);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefSil1NUnit", scrJrefSil1NUnit)) add(SCRJREFSIL1NUNIT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlsil1nunitAvail", pnlsil1nunitAvail)) add(PNLSIL1NUNITAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NPeripheral", scrJref1NPeripheral)) add(SCRJREF1NPERIPHERAL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRef1NCommand", scrJrefRef1NCommand)) add(SCRJREFREF1NCOMMAND);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHk1NModule", scrJrefHk1NModule)) add(SCRJREFHK1NMODULE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHk1NVector", scrJrefHk1NVector)) add(SCRJREFHK1NVECTOR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRef1NError", scrJrefRef1NError)) add(SCRJREFREF1NERROR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlWdbeUntRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWdbeVExpstate == comp->ixWdbeVExpstate) insert(items, IXWDBEVEXPSTATE);
	if (scrJrefDetail == comp->scrJrefDetail) insert(items, SCRJREFDETAIL);
	if (scrJref1NBank == comp->scrJref1NBank) insert(items, SCRJREF1NBANK);
	if (scrJrefFwd1NController == comp->scrJrefFwd1NController) insert(items, SCRJREFFWD1NCONTROLLER);
	if (scrJref1NTarget == comp->scrJref1NTarget) insert(items, SCRJREF1NTARGET);
	if (scrJrefSil1NUnit == comp->scrJrefSil1NUnit) insert(items, SCRJREFSIL1NUNIT);
	if (pnlsil1nunitAvail == comp->pnlsil1nunitAvail) insert(items, PNLSIL1NUNITAVAIL);
	if (scrJref1NPeripheral == comp->scrJref1NPeripheral) insert(items, SCRJREF1NPERIPHERAL);
	if (scrJrefRef1NCommand == comp->scrJrefRef1NCommand) insert(items, SCRJREFREF1NCOMMAND);
	if (scrJrefHk1NModule == comp->scrJrefHk1NModule) insert(items, SCRJREFHK1NMODULE);
	if (scrJrefHk1NVector == comp->scrJrefHk1NVector) insert(items, SCRJREFHK1NVECTOR);
	if (scrJrefRef1NError == comp->scrJrefRef1NError) insert(items, SCRJREFREF1NERROR);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlWdbeUntRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWDBEVEXPSTATE, SCRJREFDETAIL, SCRJREF1NBANK, SCRJREFFWD1NCONTROLLER, SCRJREF1NTARGET, SCRJREFSIL1NUNIT, PNLSIL1NUNITAVAIL, SCRJREF1NPERIPHERAL, SCRJREFREF1NCOMMAND, SCRJREFHK1NMODULE, SCRJREFHK1NVECTOR, SCRJREFREF1NERROR, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeUntRec::Tag
 ******************************************************************************/

PnlWdbeUntRec::Tag::Tag(
			const string& Cpt
		) :
			Block()
		{
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlWdbeUntRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWdbeUntRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWdbeUntRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWdbeUntRec::DpchAppDo
 ******************************************************************************/

PnlWdbeUntRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEUNTRECDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWdbeUntRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeUntRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeUntRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeUntRec::DpchEngData
 ******************************************************************************/

PnlWdbeUntRec::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBEUNTRECDATA)
		{
};

string PnlWdbeUntRec::DpchEngData::getSrefsMask() {
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

void PnlWdbeUntRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWdbeUntRecData");
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
