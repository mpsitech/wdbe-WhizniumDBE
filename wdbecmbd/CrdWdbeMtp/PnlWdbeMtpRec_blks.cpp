/**
	* \file PnlWdbeMtpRec_blks.cpp
	* job handler for job PnlWdbeMtpRec (implementation of blocks)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

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

void PnlWdbeMtpRec::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbeMtpRec";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWdbeMtpRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtRef", TxtRef);
	xmlTextWriterEndElement(wr);
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

void PnlWdbeMtpRec::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdoneDetail
			, const bool initdoneKParKey
			, const bool initdoneKHdltype
			, const bool initdoneAPar
			, const bool initdoneMdl1NGeneric
			, const bool initdoneTpl1NModule
			, const bool initdoneMdl1NPort
			, const bool initdoneSup1NModule
			, const bool initdoneRef1NFile
			, const bool initdoneMge1NSignal
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeMtpRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWdbeMtpRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdoneDetail", initdoneDetail);
		writeBoolAttr(wr, itemtag, "sref", "initdoneKParKey", initdoneKParKey);
		writeBoolAttr(wr, itemtag, "sref", "initdoneKHdltype", initdoneKHdltype);
		writeBoolAttr(wr, itemtag, "sref", "initdoneAPar", initdoneAPar);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMdl1NGeneric", initdoneMdl1NGeneric);
		writeBoolAttr(wr, itemtag, "sref", "initdoneTpl1NModule", initdoneTpl1NModule);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMdl1NPort", initdoneMdl1NPort);
		writeBoolAttr(wr, itemtag, "sref", "initdoneSup1NModule", initdoneSup1NModule);
		writeBoolAttr(wr, itemtag, "sref", "initdoneRef1NFile", initdoneRef1NFile);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMge1NSignal", initdoneMge1NSignal);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeMtpRec::StatShr
 ******************************************************************************/

PnlWdbeMtpRec::StatShr::StatShr(
			const uint ixWdbeVExpstate
			, const ubigint jrefDetail
			, const ubigint jrefKParKey
			, const ubigint jrefKHdltype
			, const ubigint jrefAPar
			, const ubigint jrefMdl1NGeneric
			, const ubigint jrefTpl1NModule
			, const ubigint jrefMdl1NPort
			, const ubigint jrefSup1NModule
			, const ubigint jrefRef1NFile
			, const ubigint jrefMge1NSignal
			, const bool ButRegularizeActive
		) :
			Block()
		{
	this->ixWdbeVExpstate = ixWdbeVExpstate;
	this->jrefDetail = jrefDetail;
	this->jrefKParKey = jrefKParKey;
	this->jrefKHdltype = jrefKHdltype;
	this->jrefAPar = jrefAPar;
	this->jrefMdl1NGeneric = jrefMdl1NGeneric;
	this->jrefTpl1NModule = jrefTpl1NModule;
	this->jrefMdl1NPort = jrefMdl1NPort;
	this->jrefSup1NModule = jrefSup1NModule;
	this->jrefRef1NFile = jrefRef1NFile;
	this->jrefMge1NSignal = jrefMge1NSignal;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXWDBEVEXPSTATE, JREFDETAIL, JREFKPARKEY, JREFKHDLTYPE, JREFAPAR, JREFMDL1NGENERIC, JREFTPL1NMODULE, JREFMDL1NPORT, JREFSUP1NMODULE, JREFREF1NFILE, JREFMGE1NSIGNAL, BUTREGULARIZEACTIVE};
};

void PnlWdbeMtpRec::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeMtpRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWdbeMtpRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWdbeVExpstate", VecWdbeVExpstate::getSref(ixWdbeVExpstate));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDetail", Scr::scramble(jrefDetail));
		writeStringAttr(wr, itemtag, "sref", "scrJrefKParKey", Scr::scramble(jrefKParKey));
		writeStringAttr(wr, itemtag, "sref", "scrJrefKHdltype", Scr::scramble(jrefKHdltype));
		writeStringAttr(wr, itemtag, "sref", "scrJrefAPar", Scr::scramble(jrefAPar));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMdl1NGeneric", Scr::scramble(jrefMdl1NGeneric));
		writeStringAttr(wr, itemtag, "sref", "scrJrefTpl1NModule", Scr::scramble(jrefTpl1NModule));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMdl1NPort", Scr::scramble(jrefMdl1NPort));
		writeStringAttr(wr, itemtag, "sref", "scrJrefSup1NModule", Scr::scramble(jrefSup1NModule));
		writeStringAttr(wr, itemtag, "sref", "scrJrefRef1NFile", Scr::scramble(jrefRef1NFile));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMge1NSignal", Scr::scramble(jrefMge1NSignal));
		writeBoolAttr(wr, itemtag, "sref", "ButRegularizeActive", ButRegularizeActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeMtpRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWdbeVExpstate == comp->ixWdbeVExpstate) insert(items, IXWDBEVEXPSTATE);
	if (jrefDetail == comp->jrefDetail) insert(items, JREFDETAIL);
	if (jrefKParKey == comp->jrefKParKey) insert(items, JREFKPARKEY);
	if (jrefKHdltype == comp->jrefKHdltype) insert(items, JREFKHDLTYPE);
	if (jrefAPar == comp->jrefAPar) insert(items, JREFAPAR);
	if (jrefMdl1NGeneric == comp->jrefMdl1NGeneric) insert(items, JREFMDL1NGENERIC);
	if (jrefTpl1NModule == comp->jrefTpl1NModule) insert(items, JREFTPL1NMODULE);
	if (jrefMdl1NPort == comp->jrefMdl1NPort) insert(items, JREFMDL1NPORT);
	if (jrefSup1NModule == comp->jrefSup1NModule) insert(items, JREFSUP1NMODULE);
	if (jrefRef1NFile == comp->jrefRef1NFile) insert(items, JREFREF1NFILE);
	if (jrefMge1NSignal == comp->jrefMge1NSignal) insert(items, JREFMGE1NSIGNAL);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlWdbeMtpRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWDBEVEXPSTATE, JREFDETAIL, JREFKPARKEY, JREFKHDLTYPE, JREFAPAR, JREFMDL1NGENERIC, JREFTPL1NMODULE, JREFMDL1NPORT, JREFSUP1NMODULE, JREFREF1NFILE, JREFMGE1NSIGNAL, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeMtpRec::Tag
 ******************************************************************************/

void PnlWdbeMtpRec::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWdbeMtpRec";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWdbeMtpRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Module template");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeMtpRec::DpchAppDo
 ******************************************************************************/

PnlWdbeMtpRec::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEMTPRECDO)
		{
	ixVDo = 0;
};

string PnlWdbeMtpRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeMtpRec::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeMtpRecDo");
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
 class PnlWdbeMtpRec::DpchEngData
 ******************************************************************************/

PnlWdbeMtpRec::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBEMTPRECDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWdbeMtpRec::DpchEngData::getSrefsMask() {
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

void PnlWdbeMtpRec::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWdbeMtpRec::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWdbeMtpRecData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};

