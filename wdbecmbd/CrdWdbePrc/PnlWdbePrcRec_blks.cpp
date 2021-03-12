/**
	* \file PnlWdbePrcRec_blks.cpp
	* job handler for job PnlWdbePrcRec (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

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

void PnlWdbePrcRec::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbePrcRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtRef"] = TxtRef;
};

void PnlWdbePrcRec::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbePrcRec";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWdbePrcRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtRef", TxtRef);
	xmlTextWriterEndElement(wr);
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

void PnlWdbePrcRec::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const bool initdoneDetail
			, const bool initdoneKHdltype
			, const bool initdonePrc1NVariable
			, const bool initdoneMge1NSignal
			, const bool initdoneFsmFsm1NFsmstate
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbePrcRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["initdoneDetail"] = initdoneDetail;
	me["initdoneKHdltype"] = initdoneKHdltype;
	me["initdonePrc1NVariable"] = initdonePrc1NVariable;
	me["initdoneMge1NSignal"] = initdoneMge1NSignal;
	me["initdoneFsmFsm1NFsmstate"] = initdoneFsmFsm1NFsmstate;
};

void PnlWdbePrcRec::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdoneDetail
			, const bool initdoneKHdltype
			, const bool initdonePrc1NVariable
			, const bool initdoneMge1NSignal
			, const bool initdoneFsmFsm1NFsmstate
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbePrcRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWdbePrcRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdoneDetail", initdoneDetail);
		writeBoolAttr(wr, itemtag, "sref", "initdoneKHdltype", initdoneKHdltype);
		writeBoolAttr(wr, itemtag, "sref", "initdonePrc1NVariable", initdonePrc1NVariable);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMge1NSignal", initdoneMge1NSignal);
		writeBoolAttr(wr, itemtag, "sref", "initdoneFsmFsm1NFsmstate", initdoneFsmFsm1NFsmstate);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbePrcRec::StatShr
 ******************************************************************************/

PnlWdbePrcRec::StatShr::StatShr(
			const uint ixWdbeVExpstate
			, const ubigint jrefDetail
			, const ubigint jrefKHdltype
			, const ubigint jrefPrc1NVariable
			, const ubigint jrefMge1NSignal
			, const ubigint jrefFsmFsm1NFsmstate
			, const bool pnlfsmfsm1nfsmstateAvail
			, const bool ButRegularizeActive
		) :
			Block()
		{
	this->ixWdbeVExpstate = ixWdbeVExpstate;
	this->jrefDetail = jrefDetail;
	this->jrefKHdltype = jrefKHdltype;
	this->jrefPrc1NVariable = jrefPrc1NVariable;
	this->jrefMge1NSignal = jrefMge1NSignal;
	this->jrefFsmFsm1NFsmstate = jrefFsmFsm1NFsmstate;
	this->pnlfsmfsm1nfsmstateAvail = pnlfsmfsm1nfsmstateAvail;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXWDBEVEXPSTATE, JREFDETAIL, JREFKHDLTYPE, JREFPRC1NVARIABLE, JREFMGE1NSIGNAL, JREFFSMFSM1NFSMSTATE, PNLFSMFSM1NFSMSTATEAVAIL, BUTREGULARIZEACTIVE};
};

void PnlWdbePrcRec::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbePrcRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWdbeVExpstate"] = VecWdbeVExpstate::getSref(ixWdbeVExpstate);
	me["scrJrefDetail"] = Scr::scramble(jrefDetail);
	me["scrJrefKHdltype"] = Scr::scramble(jrefKHdltype);
	me["scrJrefPrc1NVariable"] = Scr::scramble(jrefPrc1NVariable);
	me["scrJrefMge1NSignal"] = Scr::scramble(jrefMge1NSignal);
	me["scrJrefFsmFsm1NFsmstate"] = Scr::scramble(jrefFsmFsm1NFsmstate);
	me["pnlfsmfsm1nfsmstateAvail"] = pnlfsmfsm1nfsmstateAvail;
	me["ButRegularizeActive"] = ButRegularizeActive;
};

void PnlWdbePrcRec::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbePrcRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWdbePrcRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWdbeVExpstate", VecWdbeVExpstate::getSref(ixWdbeVExpstate));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDetail", Scr::scramble(jrefDetail));
		writeStringAttr(wr, itemtag, "sref", "scrJrefKHdltype", Scr::scramble(jrefKHdltype));
		writeStringAttr(wr, itemtag, "sref", "scrJrefPrc1NVariable", Scr::scramble(jrefPrc1NVariable));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMge1NSignal", Scr::scramble(jrefMge1NSignal));
		writeStringAttr(wr, itemtag, "sref", "scrJrefFsmFsm1NFsmstate", Scr::scramble(jrefFsmFsm1NFsmstate));
		writeBoolAttr(wr, itemtag, "sref", "pnlfsmfsm1nfsmstateAvail", pnlfsmfsm1nfsmstateAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButRegularizeActive", ButRegularizeActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbePrcRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWdbeVExpstate == comp->ixWdbeVExpstate) insert(items, IXWDBEVEXPSTATE);
	if (jrefDetail == comp->jrefDetail) insert(items, JREFDETAIL);
	if (jrefKHdltype == comp->jrefKHdltype) insert(items, JREFKHDLTYPE);
	if (jrefPrc1NVariable == comp->jrefPrc1NVariable) insert(items, JREFPRC1NVARIABLE);
	if (jrefMge1NSignal == comp->jrefMge1NSignal) insert(items, JREFMGE1NSIGNAL);
	if (jrefFsmFsm1NFsmstate == comp->jrefFsmFsm1NFsmstate) insert(items, JREFFSMFSM1NFSMSTATE);
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

	diffitems = {IXWDBEVEXPSTATE, JREFDETAIL, JREFKHDLTYPE, JREFPRC1NVARIABLE, JREFMGE1NSIGNAL, JREFFSMFSM1NFSMSTATE, PNLFSMFSM1NFSMSTATEAVAIL, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbePrcRec::Tag
 ******************************************************************************/

void PnlWdbePrcRec::Tag::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWdbePrcRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		me["Cpt"] = "Process";
	};
};

void PnlWdbePrcRec::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWdbePrcRec";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWdbePrcRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Process");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbePrcRec::DpchAppDo
 ******************************************************************************/

PnlWdbePrcRec::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEPRCRECDO)
		{
	ixVDo = 0;
};

string PnlWdbePrcRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbePrcRec::DpchAppDo::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["DpchAppWdbePrcRecDo"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWdbePrcRec::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbePrcRecDo");
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
 class PnlWdbePrcRec::DpchEngData
 ******************************************************************************/

PnlWdbePrcRec::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBEPRCRECDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWdbePrcRec::DpchEngData::getSrefsMask() {
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

void PnlWdbePrcRec::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWdbePrcRec::DpchEngData::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWdbePrcRecData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWdbeVLocale, me);
};

void PnlWdbePrcRec::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWdbePrcRecData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};
