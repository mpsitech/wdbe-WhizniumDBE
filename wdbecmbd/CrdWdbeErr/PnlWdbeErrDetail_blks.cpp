/**
	* \file PnlWdbeErrDetail_blks.cpp
	* job handler for job PnlWdbeErrDetail (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbeErrDetail::VecVDo
 ******************************************************************************/

uint PnlWdbeErrDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butreuviewclick") return BUTREUVIEWCLICK;
	if (s == "buttraviewclick") return BUTTRAVIEWCLICK;

	return(0);
};

string PnlWdbeErrDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTREUVIEWCLICK) return("ButReuViewClick");
	if (ix == BUTTRAVIEWCLICK) return("ButTraViewClick");

	return("");
};

/******************************************************************************
 class PnlWdbeErrDetail::ContIac
 ******************************************************************************/

PnlWdbeErrDetail::ContIac::ContIac(
			const string& TxfFsr
			, const uint numFPupRet
			, const string& TxfCmt
		) :
			Block()
		{
	this->TxfFsr = TxfFsr;
	this->numFPupRet = numFPupRet;
	this->TxfCmt = TxfCmt;

	mask = {TXFFSR, NUMFPUPRET, TXFCMT};
};

bool PnlWdbeErrDetail::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacWdbeErrDetail"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("TxfFsr")) {TxfFsr = me["TxfFsr"].asString(); add(TXFFSR);};
		if (me.isMember("numFPupRet")) {numFPupRet = me["numFPupRet"].asUInt(); add(NUMFPUPRET);};
		if (me.isMember("TxfCmt")) {TxfCmt = me["TxfCmt"].asString(); add(TXFCMT);};
	};

	return basefound;
};

bool PnlWdbeErrDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWdbeErrDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWdbeErrDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFsr", TxfFsr)) add(TXFFSR);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupRet", numFPupRet)) add(NUMFPUPRET);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlWdbeErrDetail::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeErrDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxfFsr"] = TxfFsr;
	me["numFPupRet"] = (Json::Value::UInt) numFPupRet;
	me["TxfCmt"] = TxfCmt;
};

void PnlWdbeErrDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeErrDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWdbeErrDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfFsr", TxfFsr);
		writeUintAttr(wr, itemtag, "sref", "numFPupRet", numFPupRet);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeErrDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfFsr == comp->TxfFsr) insert(items, TXFFSR);
	if (numFPupRet == comp->numFPupRet) insert(items, NUMFPUPRET);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlWdbeErrDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFFSR, NUMFPUPRET, TXFCMT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeErrDetail::ContInf
 ******************************************************************************/

PnlWdbeErrDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtReu
			, const string& TxtTra
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtReu = TxtReu;
	this->TxtTra = TxtTra;

	mask = {TXTSRF, TXTREU, TXTTRA};
};

void PnlWdbeErrDetail::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbeErrDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtSrf"] = TxtSrf;
	me["TxtReu"] = TxtReu;
	me["TxtTra"] = TxtTra;
};

void PnlWdbeErrDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbeErrDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWdbeErrDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtReu", TxtReu);
		writeStringAttr(wr, itemtag, "sref", "TxtTra", TxtTra);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeErrDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtReu == comp->TxtReu) insert(items, TXTREU);
	if (TxtTra == comp->TxtTra) insert(items, TXTTRA);

	return(items);
};

set<uint> PnlWdbeErrDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTREU, TXTTRA};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeErrDetail::StatApp
 ******************************************************************************/

void PnlWdbeErrDetail::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWdbeVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeErrDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWdbeVExpstate"] = VecWdbeVExpstate::getSref(ixWdbeVExpstate);
};

void PnlWdbeErrDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWdbeVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeErrDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWdbeErrDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWdbeVExpstate", VecWdbeVExpstate::getSref(ixWdbeVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeErrDetail::StatShr
 ******************************************************************************/

PnlWdbeErrDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool TxfFsrActive
			, const bool TxtReuActive
			, const bool ButReuViewAvail
			, const bool ButReuViewActive
			, const bool TxtTraActive
			, const bool ButTraViewAvail
			, const bool ButTraViewActive
			, const bool TxfCmtActive
		) :
			Block()
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->TxfFsrActive = TxfFsrActive;
	this->TxtReuActive = TxtReuActive;
	this->ButReuViewAvail = ButReuViewAvail;
	this->ButReuViewActive = ButReuViewActive;
	this->TxtTraActive = TxtTraActive;
	this->ButTraViewAvail = ButTraViewAvail;
	this->ButTraViewActive = ButTraViewActive;
	this->TxfCmtActive = TxfCmtActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFFSRACTIVE, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, TXTTRAACTIVE, BUTTRAVIEWAVAIL, BUTTRAVIEWACTIVE, TXFCMTACTIVE};
};

void PnlWdbeErrDetail::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeErrDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButSaveAvail"] = ButSaveAvail;
	me["ButSaveActive"] = ButSaveActive;
	me["TxtSrfActive"] = TxtSrfActive;
	me["TxfFsrActive"] = TxfFsrActive;
	me["TxtReuActive"] = TxtReuActive;
	me["ButReuViewAvail"] = ButReuViewAvail;
	me["ButReuViewActive"] = ButReuViewActive;
	me["TxtTraActive"] = TxtTraActive;
	me["ButTraViewAvail"] = ButTraViewAvail;
	me["ButTraViewActive"] = ButTraViewActive;
	me["TxfCmtActive"] = TxfCmtActive;
};

void PnlWdbeErrDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeErrDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWdbeErrDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSrfActive", TxtSrfActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfFsrActive", TxfFsrActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtReuActive", TxtReuActive);
		writeBoolAttr(wr, itemtag, "sref", "ButReuViewAvail", ButReuViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButReuViewActive", ButReuViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtTraActive", TxtTraActive);
		writeBoolAttr(wr, itemtag, "sref", "ButTraViewAvail", ButTraViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButTraViewActive", ButTraViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfCmtActive", TxfCmtActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeErrDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (TxfFsrActive == comp->TxfFsrActive) insert(items, TXFFSRACTIVE);
	if (TxtReuActive == comp->TxtReuActive) insert(items, TXTREUACTIVE);
	if (ButReuViewAvail == comp->ButReuViewAvail) insert(items, BUTREUVIEWAVAIL);
	if (ButReuViewActive == comp->ButReuViewActive) insert(items, BUTREUVIEWACTIVE);
	if (TxtTraActive == comp->TxtTraActive) insert(items, TXTTRAACTIVE);
	if (ButTraViewAvail == comp->ButTraViewAvail) insert(items, BUTTRAVIEWAVAIL);
	if (ButTraViewActive == comp->ButTraViewActive) insert(items, BUTTRAVIEWACTIVE);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);

	return(items);
};

set<uint> PnlWdbeErrDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFFSRACTIVE, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, TXTTRAACTIVE, BUTTRAVIEWAVAIL, BUTTRAVIEWACTIVE, TXFCMTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeErrDetail::Tag
 ******************************************************************************/

void PnlWdbeErrDetail::Tag::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWdbeErrDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		me["CptSrf"] = "identifier";
		me["CptFsr"] = "full identifier";
		me["CptReu"] = "reference";
		me["CptTra"] = "trigger acknowledgement signal";
		me["CptCmt"] = "comment";
	};
	me["Cpt"] = StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DETAIL, ixWdbeVLocale));
};

void PnlWdbeErrDetail::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWdbeErrDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWdbeErrDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptFsr", "full identifier");
			writeStringAttr(wr, itemtag, "sref", "CptReu", "reference");
			writeStringAttr(wr, itemtag, "sref", "CptTra", "trigger acknowledgement signal");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "comment");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DETAIL, ixWdbeVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeErrDetail::DpchAppData
 ******************************************************************************/

PnlWdbeErrDetail::DpchAppData::DpchAppData() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEERRDETAILDATA)
		{
};

string PnlWdbeErrDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeErrDetail::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWdbeErrDetailData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWdbeErrDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeErrDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

/******************************************************************************
 class PnlWdbeErrDetail::DpchAppDo
 ******************************************************************************/

PnlWdbeErrDetail::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEERRDETAILDO)
		{
	ixVDo = 0;
};

string PnlWdbeErrDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeErrDetail::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWdbeErrDetailDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWdbeErrDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeErrDetailDo");
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
 class PnlWdbeErrDetail::DpchEngData
 ******************************************************************************/

PnlWdbeErrDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupRet
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBEERRDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPRET, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPRET) && feedFPupRet) this->feedFPupRet = *feedFPupRet;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWdbeErrDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPRET)) ss.push_back("feedFPupRet");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeErrDetail::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFPUPRET)) {feedFPupRet = src->feedFPupRet; add(FEEDFPUPRET);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWdbeErrDetail::DpchEngData::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWdbeErrDetailData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFPUPRET)) feedFPupRet.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWdbeVLocale, me);
};

void PnlWdbeErrDetail::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWdbeErrDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFPUPRET)) feedFPupRet.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};
