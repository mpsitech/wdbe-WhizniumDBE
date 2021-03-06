/**
	* \file PnlWdbeUntRec_blks.cpp
	* job handler for job PnlWdbeUntRec (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

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

void PnlWdbeUntRec::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbeUntRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtRef"] = TxtRef;
};

void PnlWdbeUntRec::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbeUntRec";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWdbeUntRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtRef", TxtRef);
	xmlTextWriterEndElement(wr);
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

void PnlWdbeUntRec::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const bool initdoneDetail
			, const bool initdone1NPeripheral
			, const bool initdoneSil1NUnit
			, const bool initdone1NBank
			, const bool initdoneFwd1NController
			, const bool initdone1NTarget
			, const bool initdoneRef1NCommand
			, const bool initdoneRef1NError
			, const bool initdoneHk1NVector
			, const bool initdoneHk1NModule
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeUntRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["initdoneDetail"] = initdoneDetail;
	me["initdone1NPeripheral"] = initdone1NPeripheral;
	me["initdoneSil1NUnit"] = initdoneSil1NUnit;
	me["initdone1NBank"] = initdone1NBank;
	me["initdoneFwd1NController"] = initdoneFwd1NController;
	me["initdone1NTarget"] = initdone1NTarget;
	me["initdoneRef1NCommand"] = initdoneRef1NCommand;
	me["initdoneRef1NError"] = initdoneRef1NError;
	me["initdoneHk1NVector"] = initdoneHk1NVector;
	me["initdoneHk1NModule"] = initdoneHk1NModule;
};

void PnlWdbeUntRec::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdoneDetail
			, const bool initdone1NPeripheral
			, const bool initdoneSil1NUnit
			, const bool initdone1NBank
			, const bool initdoneFwd1NController
			, const bool initdone1NTarget
			, const bool initdoneRef1NCommand
			, const bool initdoneRef1NError
			, const bool initdoneHk1NVector
			, const bool initdoneHk1NModule
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeUntRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWdbeUntRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdoneDetail", initdoneDetail);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NPeripheral", initdone1NPeripheral);
		writeBoolAttr(wr, itemtag, "sref", "initdoneSil1NUnit", initdoneSil1NUnit);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NBank", initdone1NBank);
		writeBoolAttr(wr, itemtag, "sref", "initdoneFwd1NController", initdoneFwd1NController);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NTarget", initdone1NTarget);
		writeBoolAttr(wr, itemtag, "sref", "initdoneRef1NCommand", initdoneRef1NCommand);
		writeBoolAttr(wr, itemtag, "sref", "initdoneRef1NError", initdoneRef1NError);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHk1NVector", initdoneHk1NVector);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHk1NModule", initdoneHk1NModule);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeUntRec::StatShr
 ******************************************************************************/

PnlWdbeUntRec::StatShr::StatShr(
			const uint ixWdbeVExpstate
			, const ubigint jrefDetail
			, const ubigint jref1NPeripheral
			, const ubigint jrefSil1NUnit
			, const bool pnlsil1nunitAvail
			, const ubigint jref1NBank
			, const ubigint jrefFwd1NController
			, const ubigint jref1NTarget
			, const ubigint jrefRef1NCommand
			, const ubigint jrefRef1NError
			, const ubigint jrefHk1NVector
			, const ubigint jrefHk1NModule
			, const bool ButRegularizeActive
		) :
			Block()
		{
	this->ixWdbeVExpstate = ixWdbeVExpstate;
	this->jrefDetail = jrefDetail;
	this->jref1NPeripheral = jref1NPeripheral;
	this->jrefSil1NUnit = jrefSil1NUnit;
	this->pnlsil1nunitAvail = pnlsil1nunitAvail;
	this->jref1NBank = jref1NBank;
	this->jrefFwd1NController = jrefFwd1NController;
	this->jref1NTarget = jref1NTarget;
	this->jrefRef1NCommand = jrefRef1NCommand;
	this->jrefRef1NError = jrefRef1NError;
	this->jrefHk1NVector = jrefHk1NVector;
	this->jrefHk1NModule = jrefHk1NModule;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXWDBEVEXPSTATE, JREFDETAIL, JREF1NPERIPHERAL, JREFSIL1NUNIT, PNLSIL1NUNITAVAIL, JREF1NBANK, JREFFWD1NCONTROLLER, JREF1NTARGET, JREFREF1NCOMMAND, JREFREF1NERROR, JREFHK1NVECTOR, JREFHK1NMODULE, BUTREGULARIZEACTIVE};
};

void PnlWdbeUntRec::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeUntRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWdbeVExpstate"] = VecWdbeVExpstate::getSref(ixWdbeVExpstate);
	me["scrJrefDetail"] = Scr::scramble(jrefDetail);
	me["scrJref1NPeripheral"] = Scr::scramble(jref1NPeripheral);
	me["scrJrefSil1NUnit"] = Scr::scramble(jrefSil1NUnit);
	me["pnlsil1nunitAvail"] = pnlsil1nunitAvail;
	me["scrJref1NBank"] = Scr::scramble(jref1NBank);
	me["scrJrefFwd1NController"] = Scr::scramble(jrefFwd1NController);
	me["scrJref1NTarget"] = Scr::scramble(jref1NTarget);
	me["scrJrefRef1NCommand"] = Scr::scramble(jrefRef1NCommand);
	me["scrJrefRef1NError"] = Scr::scramble(jrefRef1NError);
	me["scrJrefHk1NVector"] = Scr::scramble(jrefHk1NVector);
	me["scrJrefHk1NModule"] = Scr::scramble(jrefHk1NModule);
	me["ButRegularizeActive"] = ButRegularizeActive;
};

void PnlWdbeUntRec::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeUntRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWdbeUntRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWdbeVExpstate", VecWdbeVExpstate::getSref(ixWdbeVExpstate));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDetail", Scr::scramble(jrefDetail));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NPeripheral", Scr::scramble(jref1NPeripheral));
		writeStringAttr(wr, itemtag, "sref", "scrJrefSil1NUnit", Scr::scramble(jrefSil1NUnit));
		writeBoolAttr(wr, itemtag, "sref", "pnlsil1nunitAvail", pnlsil1nunitAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJref1NBank", Scr::scramble(jref1NBank));
		writeStringAttr(wr, itemtag, "sref", "scrJrefFwd1NController", Scr::scramble(jrefFwd1NController));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NTarget", Scr::scramble(jref1NTarget));
		writeStringAttr(wr, itemtag, "sref", "scrJrefRef1NCommand", Scr::scramble(jrefRef1NCommand));
		writeStringAttr(wr, itemtag, "sref", "scrJrefRef1NError", Scr::scramble(jrefRef1NError));
		writeStringAttr(wr, itemtag, "sref", "scrJrefHk1NVector", Scr::scramble(jrefHk1NVector));
		writeStringAttr(wr, itemtag, "sref", "scrJrefHk1NModule", Scr::scramble(jrefHk1NModule));
		writeBoolAttr(wr, itemtag, "sref", "ButRegularizeActive", ButRegularizeActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeUntRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWdbeVExpstate == comp->ixWdbeVExpstate) insert(items, IXWDBEVEXPSTATE);
	if (jrefDetail == comp->jrefDetail) insert(items, JREFDETAIL);
	if (jref1NPeripheral == comp->jref1NPeripheral) insert(items, JREF1NPERIPHERAL);
	if (jrefSil1NUnit == comp->jrefSil1NUnit) insert(items, JREFSIL1NUNIT);
	if (pnlsil1nunitAvail == comp->pnlsil1nunitAvail) insert(items, PNLSIL1NUNITAVAIL);
	if (jref1NBank == comp->jref1NBank) insert(items, JREF1NBANK);
	if (jrefFwd1NController == comp->jrefFwd1NController) insert(items, JREFFWD1NCONTROLLER);
	if (jref1NTarget == comp->jref1NTarget) insert(items, JREF1NTARGET);
	if (jrefRef1NCommand == comp->jrefRef1NCommand) insert(items, JREFREF1NCOMMAND);
	if (jrefRef1NError == comp->jrefRef1NError) insert(items, JREFREF1NERROR);
	if (jrefHk1NVector == comp->jrefHk1NVector) insert(items, JREFHK1NVECTOR);
	if (jrefHk1NModule == comp->jrefHk1NModule) insert(items, JREFHK1NMODULE);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlWdbeUntRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWDBEVEXPSTATE, JREFDETAIL, JREF1NPERIPHERAL, JREFSIL1NUNIT, PNLSIL1NUNITAVAIL, JREF1NBANK, JREFFWD1NCONTROLLER, JREF1NTARGET, JREFREF1NCOMMAND, JREFREF1NERROR, JREFHK1NVECTOR, JREFHK1NMODULE, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeUntRec::Tag
 ******************************************************************************/

void PnlWdbeUntRec::Tag::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWdbeUntRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		me["Cpt"] = "Unit";
	};
};

void PnlWdbeUntRec::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWdbeUntRec";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWdbeUntRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Unit");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeUntRec::DpchAppDo
 ******************************************************************************/

PnlWdbeUntRec::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEUNTRECDO)
		{
	ixVDo = 0;
};

string PnlWdbeUntRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeUntRec::DpchAppDo::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["DpchAppWdbeUntRecDo"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWdbeUntRec::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeUntRecDo");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (extractStringUclc(docctx, basexpath, "srefIxVDo", "", srefIxVDo)) {
			ixVDo = VecVDo::getIx(srefIxVDo);
			add(IXVDO);
		};
	} else {
	};
};

/******************************************************************************
 class PnlWdbeUntRec::DpchEngData
 ******************************************************************************/

PnlWdbeUntRec::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBEUNTRECDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWdbeUntRec::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeUntRec::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWdbeUntRec::DpchEngData::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWdbeUntRecData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWdbeVLocale, me);
};

void PnlWdbeUntRec::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWdbeUntRecData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};
