/**
	* \file PnlWdbeSilRec.cpp
	* API code for job PnlWdbeSilRec (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWdbeSilRec.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbeSilRec::VecVDo
 ******************************************************************************/

uint PnlWdbeSilRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlWdbeSilRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlWdbeSilRec::ContInf
 ******************************************************************************/

PnlWdbeSilRec::ContInf::ContInf(
			const string& TxtRef
		) :
			Block()
		{
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

bool PnlWdbeSilRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWdbeSilRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWdbeSilRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
};

set<uint> PnlWdbeSilRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlWdbeSilRec::ContInf::diff(
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
 class PnlWdbeSilRec::StatApp
 ******************************************************************************/

PnlWdbeSilRec::StatApp::StatApp(
			const bool initdoneDetail
			, const bool initdone1NInterrupt
			, const bool initdone1NPeripheral
			, const bool initdoneSil1NUnit
			, const bool initdone1NBank
			, const bool initdoneHk1NModule
			, const bool initdoneRef1NError
			, const bool initdoneRef1NSignal
			, const bool initdoneHk1NVector
			, const bool initdoneRef1NCommand
		) :
			Block()
		{
	this->initdoneDetail = initdoneDetail;
	this->initdone1NInterrupt = initdone1NInterrupt;
	this->initdone1NPeripheral = initdone1NPeripheral;
	this->initdoneSil1NUnit = initdoneSil1NUnit;
	this->initdone1NBank = initdone1NBank;
	this->initdoneHk1NModule = initdoneHk1NModule;
	this->initdoneRef1NError = initdoneRef1NError;
	this->initdoneRef1NSignal = initdoneRef1NSignal;
	this->initdoneHk1NVector = initdoneHk1NVector;
	this->initdoneRef1NCommand = initdoneRef1NCommand;

	mask = {INITDONEDETAIL, INITDONE1NINTERRUPT, INITDONE1NPERIPHERAL, INITDONESIL1NUNIT, INITDONE1NBANK, INITDONEHK1NMODULE, INITDONEREF1NERROR, INITDONEREF1NSIGNAL, INITDONEHK1NVECTOR, INITDONEREF1NCOMMAND};
};

bool PnlWdbeSilRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWdbeSilRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWdbeSilRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NInterrupt", initdone1NInterrupt)) add(INITDONE1NINTERRUPT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NPeripheral", initdone1NPeripheral)) add(INITDONE1NPERIPHERAL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneSil1NUnit", initdoneSil1NUnit)) add(INITDONESIL1NUNIT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NBank", initdone1NBank)) add(INITDONE1NBANK);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHk1NModule", initdoneHk1NModule)) add(INITDONEHK1NMODULE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRef1NError", initdoneRef1NError)) add(INITDONEREF1NERROR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRef1NSignal", initdoneRef1NSignal)) add(INITDONEREF1NSIGNAL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHk1NVector", initdoneHk1NVector)) add(INITDONEHK1NVECTOR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRef1NCommand", initdoneRef1NCommand)) add(INITDONEREF1NCOMMAND);
	};

	return basefound;
};

set<uint> PnlWdbeSilRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdone1NInterrupt == comp->initdone1NInterrupt) insert(items, INITDONE1NINTERRUPT);
	if (initdone1NPeripheral == comp->initdone1NPeripheral) insert(items, INITDONE1NPERIPHERAL);
	if (initdoneSil1NUnit == comp->initdoneSil1NUnit) insert(items, INITDONESIL1NUNIT);
	if (initdone1NBank == comp->initdone1NBank) insert(items, INITDONE1NBANK);
	if (initdoneHk1NModule == comp->initdoneHk1NModule) insert(items, INITDONEHK1NMODULE);
	if (initdoneRef1NError == comp->initdoneRef1NError) insert(items, INITDONEREF1NERROR);
	if (initdoneRef1NSignal == comp->initdoneRef1NSignal) insert(items, INITDONEREF1NSIGNAL);
	if (initdoneHk1NVector == comp->initdoneHk1NVector) insert(items, INITDONEHK1NVECTOR);
	if (initdoneRef1NCommand == comp->initdoneRef1NCommand) insert(items, INITDONEREF1NCOMMAND);

	return(items);
};

set<uint> PnlWdbeSilRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEDETAIL, INITDONE1NINTERRUPT, INITDONE1NPERIPHERAL, INITDONESIL1NUNIT, INITDONE1NBANK, INITDONEHK1NMODULE, INITDONEREF1NERROR, INITDONEREF1NSIGNAL, INITDONEHK1NVECTOR, INITDONEREF1NCOMMAND};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeSilRec::StatShr
 ******************************************************************************/

PnlWdbeSilRec::StatShr::StatShr(
			const uint ixWdbeVExpstate
			, const string& scrJrefDetail
			, const string& scrJref1NInterrupt
			, const string& scrJref1NPeripheral
			, const string& scrJrefSil1NUnit
			, const string& scrJref1NBank
			, const string& scrJrefHk1NModule
			, const string& scrJrefRef1NError
			, const string& scrJrefRef1NSignal
			, const string& scrJrefHk1NVector
			, const string& scrJrefRef1NCommand
			, const bool ButRegularizeActive
		) :
			Block()
		{
	this->ixWdbeVExpstate = ixWdbeVExpstate;
	this->scrJrefDetail = scrJrefDetail;
	this->scrJref1NInterrupt = scrJref1NInterrupt;
	this->scrJref1NPeripheral = scrJref1NPeripheral;
	this->scrJrefSil1NUnit = scrJrefSil1NUnit;
	this->scrJref1NBank = scrJref1NBank;
	this->scrJrefHk1NModule = scrJrefHk1NModule;
	this->scrJrefRef1NError = scrJrefRef1NError;
	this->scrJrefRef1NSignal = scrJrefRef1NSignal;
	this->scrJrefHk1NVector = scrJrefHk1NVector;
	this->scrJrefRef1NCommand = scrJrefRef1NCommand;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXWDBEVEXPSTATE, SCRJREFDETAIL, SCRJREF1NINTERRUPT, SCRJREF1NPERIPHERAL, SCRJREFSIL1NUNIT, SCRJREF1NBANK, SCRJREFHK1NMODULE, SCRJREFREF1NERROR, SCRJREFREF1NSIGNAL, SCRJREFHK1NVECTOR, SCRJREFREF1NCOMMAND, BUTREGULARIZEACTIVE};
};

bool PnlWdbeSilRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWdbeVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWdbeSilRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWdbeSilRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", srefIxWdbeVExpstate)) {
			ixWdbeVExpstate = VecWdbeVExpstate::getIx(srefIxWdbeVExpstate);
			add(IXWDBEVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NInterrupt", scrJref1NInterrupt)) add(SCRJREF1NINTERRUPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NPeripheral", scrJref1NPeripheral)) add(SCRJREF1NPERIPHERAL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefSil1NUnit", scrJrefSil1NUnit)) add(SCRJREFSIL1NUNIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NBank", scrJref1NBank)) add(SCRJREF1NBANK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHk1NModule", scrJrefHk1NModule)) add(SCRJREFHK1NMODULE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRef1NError", scrJrefRef1NError)) add(SCRJREFREF1NERROR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRef1NSignal", scrJrefRef1NSignal)) add(SCRJREFREF1NSIGNAL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHk1NVector", scrJrefHk1NVector)) add(SCRJREFHK1NVECTOR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRef1NCommand", scrJrefRef1NCommand)) add(SCRJREFREF1NCOMMAND);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlWdbeSilRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWdbeVExpstate == comp->ixWdbeVExpstate) insert(items, IXWDBEVEXPSTATE);
	if (scrJrefDetail == comp->scrJrefDetail) insert(items, SCRJREFDETAIL);
	if (scrJref1NInterrupt == comp->scrJref1NInterrupt) insert(items, SCRJREF1NINTERRUPT);
	if (scrJref1NPeripheral == comp->scrJref1NPeripheral) insert(items, SCRJREF1NPERIPHERAL);
	if (scrJrefSil1NUnit == comp->scrJrefSil1NUnit) insert(items, SCRJREFSIL1NUNIT);
	if (scrJref1NBank == comp->scrJref1NBank) insert(items, SCRJREF1NBANK);
	if (scrJrefHk1NModule == comp->scrJrefHk1NModule) insert(items, SCRJREFHK1NMODULE);
	if (scrJrefRef1NError == comp->scrJrefRef1NError) insert(items, SCRJREFREF1NERROR);
	if (scrJrefRef1NSignal == comp->scrJrefRef1NSignal) insert(items, SCRJREFREF1NSIGNAL);
	if (scrJrefHk1NVector == comp->scrJrefHk1NVector) insert(items, SCRJREFHK1NVECTOR);
	if (scrJrefRef1NCommand == comp->scrJrefRef1NCommand) insert(items, SCRJREFREF1NCOMMAND);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlWdbeSilRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWDBEVEXPSTATE, SCRJREFDETAIL, SCRJREF1NINTERRUPT, SCRJREF1NPERIPHERAL, SCRJREFSIL1NUNIT, SCRJREF1NBANK, SCRJREFHK1NMODULE, SCRJREFREF1NERROR, SCRJREFREF1NSIGNAL, SCRJREFHK1NVECTOR, SCRJREFREF1NCOMMAND, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeSilRec::Tag
 ******************************************************************************/

PnlWdbeSilRec::Tag::Tag(
			const string& Cpt
		) :
			Block()
		{
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlWdbeSilRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWdbeSilRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWdbeSilRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWdbeSilRec::DpchAppDo
 ******************************************************************************/

PnlWdbeSilRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBESILRECDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWdbeSilRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeSilRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeSilRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeSilRec::DpchEngData
 ******************************************************************************/

PnlWdbeSilRec::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBESILRECDATA)
		{
};

string PnlWdbeSilRec::DpchEngData::getSrefsMask() {
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

void PnlWdbeSilRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWdbeSilRecData");
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
