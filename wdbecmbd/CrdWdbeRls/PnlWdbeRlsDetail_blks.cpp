/**
	* \file PnlWdbeRlsDetail_blks.cpp
	* job handler for job PnlWdbeRlsDetail (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbeRlsDetail::VecVDo
 ******************************************************************************/

uint PnlWdbeRlsDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butcmpviewclick") return BUTCMPVIEWCLICK;
	if (s == "butmchviewclick") return BUTMCHVIEWCLICK;
	if (s == "butopteditclick") return BUTOPTEDITCLICK;

	return(0);
};

string PnlWdbeRlsDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTCMPVIEWCLICK) return("ButCmpViewClick");
	if (ix == BUTMCHVIEWCLICK) return("ButMchViewClick");
	if (ix == BUTOPTEDITCLICK) return("ButOptEditClick");

	return("");
};

/******************************************************************************
 class PnlWdbeRlsDetail::ContIac
 ******************************************************************************/

PnlWdbeRlsDetail::ContIac::ContIac(
			const vector<uint>& numsFLstOpt
			, const string& TxfOpt
			, const string& TxfCmt
		) :
			Block()
		{
	this->numsFLstOpt = numsFLstOpt;
	this->TxfOpt = TxfOpt;
	this->TxfCmt = TxfCmt;

	mask = {NUMSFLSTOPT, TXFOPT, TXFCMT};
};

bool PnlWdbeRlsDetail::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacWdbeRlsDetail"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (Jsonio::extractUintvec(me, "numsFLstOpt", numsFLstOpt)) add(NUMSFLSTOPT);
		if (me.isMember("TxfOpt")) {TxfOpt = me["TxfOpt"].asString(); add(TXFOPT);};
		if (me.isMember("TxfCmt")) {TxfCmt = me["TxfCmt"].asString(); add(TXFCMT);};
	};

	return basefound;
};

bool PnlWdbeRlsDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWdbeRlsDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWdbeRlsDetail";

	if (basefound) {
		if (extractUintvecAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numsFLstOpt", numsFLstOpt)) add(NUMSFLSTOPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfOpt", TxfOpt)) add(TXFOPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlWdbeRlsDetail::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeRlsDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	Jsonio::writeUintvec(me, "numsFLstOpt", numsFLstOpt);
	me["TxfOpt"] = TxfOpt;
	me["TxfCmt"] = TxfCmt;
};

void PnlWdbeRlsDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeRlsDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWdbeRlsDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintvecAttr(wr, itemtag, "sref", "numsFLstOpt", numsFLstOpt);
		writeStringAttr(wr, itemtag, "sref", "TxfOpt", TxfOpt);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeRlsDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (compareUintvec(numsFLstOpt, comp->numsFLstOpt)) insert(items, NUMSFLSTOPT);
	if (TxfOpt == comp->TxfOpt) insert(items, TXFOPT);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlWdbeRlsDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMSFLSTOPT, TXFOPT, TXFCMT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeRlsDetail::ContInf
 ******************************************************************************/

PnlWdbeRlsDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtCmp
			, const string& TxtMch
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtCmp = TxtCmp;
	this->TxtMch = TxtMch;

	mask = {TXTSRF, TXTCMP, TXTMCH};
};

void PnlWdbeRlsDetail::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbeRlsDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtSrf"] = TxtSrf;
	me["TxtCmp"] = TxtCmp;
	me["TxtMch"] = TxtMch;
};

void PnlWdbeRlsDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbeRlsDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWdbeRlsDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtCmp", TxtCmp);
		writeStringAttr(wr, itemtag, "sref", "TxtMch", TxtMch);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeRlsDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtCmp == comp->TxtCmp) insert(items, TXTCMP);
	if (TxtMch == comp->TxtMch) insert(items, TXTMCH);

	return(items);
};

set<uint> PnlWdbeRlsDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTCMP, TXTMCH};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeRlsDetail::StatApp
 ******************************************************************************/

void PnlWdbeRlsDetail::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWdbeVExpstate
			, const bool LstOptAlt
			, const uint LstOptNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeRlsDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWdbeVExpstate"] = VecWdbeVExpstate::getSref(ixWdbeVExpstate);
	me["LstOptAlt"] = LstOptAlt;
	me["LstOptNumFirstdisp"] = (Json::Value::UInt) LstOptNumFirstdisp;
};

void PnlWdbeRlsDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWdbeVExpstate
			, const bool LstOptAlt
			, const uint LstOptNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeRlsDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWdbeRlsDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWdbeVExpstate", VecWdbeVExpstate::getSref(ixWdbeVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstOptAlt", LstOptAlt);
		writeUintAttr(wr, itemtag, "sref", "LstOptNumFirstdisp", LstOptNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeRlsDetail::StatShr
 ******************************************************************************/

PnlWdbeRlsDetail::StatShr::StatShr(
			const bool TxfOptValid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool TxtCmpActive
			, const bool ButCmpViewAvail
			, const bool ButCmpViewActive
			, const bool TxtMchActive
			, const bool ButMchViewAvail
			, const bool ButMchViewActive
			, const bool LstOptActive
			, const bool ButOptEditAvail
			, const bool TxfCmtActive
		) :
			Block()
		{
	this->TxfOptValid = TxfOptValid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->TxtCmpActive = TxtCmpActive;
	this->ButCmpViewAvail = ButCmpViewAvail;
	this->ButCmpViewActive = ButCmpViewActive;
	this->TxtMchActive = TxtMchActive;
	this->ButMchViewAvail = ButMchViewAvail;
	this->ButMchViewActive = ButMchViewActive;
	this->LstOptActive = LstOptActive;
	this->ButOptEditAvail = ButOptEditAvail;
	this->TxfCmtActive = TxfCmtActive;

	mask = {TXFOPTVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTCMPACTIVE, BUTCMPVIEWAVAIL, BUTCMPVIEWACTIVE, TXTMCHACTIVE, BUTMCHVIEWAVAIL, BUTMCHVIEWACTIVE, LSTOPTACTIVE, BUTOPTEDITAVAIL, TXFCMTACTIVE};
};

void PnlWdbeRlsDetail::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeRlsDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxfOptValid"] = TxfOptValid;
	me["ButSaveAvail"] = ButSaveAvail;
	me["ButSaveActive"] = ButSaveActive;
	me["TxtSrfActive"] = TxtSrfActive;
	me["TxtCmpActive"] = TxtCmpActive;
	me["ButCmpViewAvail"] = ButCmpViewAvail;
	me["ButCmpViewActive"] = ButCmpViewActive;
	me["TxtMchActive"] = TxtMchActive;
	me["ButMchViewAvail"] = ButMchViewAvail;
	me["ButMchViewActive"] = ButMchViewActive;
	me["LstOptActive"] = LstOptActive;
	me["ButOptEditAvail"] = ButOptEditAvail;
	me["TxfCmtActive"] = TxfCmtActive;
};

void PnlWdbeRlsDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeRlsDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWdbeRlsDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "TxfOptValid", TxfOptValid);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSrfActive", TxtSrfActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtCmpActive", TxtCmpActive);
		writeBoolAttr(wr, itemtag, "sref", "ButCmpViewAvail", ButCmpViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButCmpViewActive", ButCmpViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtMchActive", TxtMchActive);
		writeBoolAttr(wr, itemtag, "sref", "ButMchViewAvail", ButMchViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButMchViewActive", ButMchViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstOptActive", LstOptActive);
		writeBoolAttr(wr, itemtag, "sref", "ButOptEditAvail", ButOptEditAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfCmtActive", TxfCmtActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeRlsDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfOptValid == comp->TxfOptValid) insert(items, TXFOPTVALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (TxtCmpActive == comp->TxtCmpActive) insert(items, TXTCMPACTIVE);
	if (ButCmpViewAvail == comp->ButCmpViewAvail) insert(items, BUTCMPVIEWAVAIL);
	if (ButCmpViewActive == comp->ButCmpViewActive) insert(items, BUTCMPVIEWACTIVE);
	if (TxtMchActive == comp->TxtMchActive) insert(items, TXTMCHACTIVE);
	if (ButMchViewAvail == comp->ButMchViewAvail) insert(items, BUTMCHVIEWAVAIL);
	if (ButMchViewActive == comp->ButMchViewActive) insert(items, BUTMCHVIEWACTIVE);
	if (LstOptActive == comp->LstOptActive) insert(items, LSTOPTACTIVE);
	if (ButOptEditAvail == comp->ButOptEditAvail) insert(items, BUTOPTEDITAVAIL);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);

	return(items);
};

set<uint> PnlWdbeRlsDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFOPTVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTCMPACTIVE, BUTCMPVIEWAVAIL, BUTCMPVIEWACTIVE, TXTMCHACTIVE, BUTMCHVIEWAVAIL, BUTMCHVIEWACTIVE, LSTOPTACTIVE, BUTOPTEDITAVAIL, TXFCMTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeRlsDetail::Tag
 ******************************************************************************/

void PnlWdbeRlsDetail::Tag::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWdbeRlsDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		me["CptSrf"] = "identifier";
		me["CptCmp"] = "component";
		me["CptMch"] = "machine";
		me["CptOpt"] = "options";
		me["CptCmt"] = "comment";
	};
	me["Cpt"] = StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DETAIL, ixWdbeVLocale));
};

void PnlWdbeRlsDetail::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWdbeRlsDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWdbeRlsDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptCmp", "component");
			writeStringAttr(wr, itemtag, "sref", "CptMch", "machine");
			writeStringAttr(wr, itemtag, "sref", "CptOpt", "options");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "comment");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DETAIL, ixWdbeVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeRlsDetail::DpchAppData
 ******************************************************************************/

PnlWdbeRlsDetail::DpchAppData::DpchAppData() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBERLSDETAILDATA)
		{
};

string PnlWdbeRlsDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeRlsDetail::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWdbeRlsDetailData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWdbeRlsDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeRlsDetailData");
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
 class PnlWdbeRlsDetail::DpchAppDo
 ******************************************************************************/

PnlWdbeRlsDetail::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBERLSDETAILDO)
		{
	ixVDo = 0;
};

string PnlWdbeRlsDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeRlsDetail::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWdbeRlsDetailDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWdbeRlsDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeRlsDetailDo");
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
 class PnlWdbeRlsDetail::DpchEngData
 ******************************************************************************/

PnlWdbeRlsDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFLstOpt
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBERLSDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFLSTOPT, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFLSTOPT) && feedFLstOpt) this->feedFLstOpt = *feedFLstOpt;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWdbeRlsDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTOPT)) ss.push_back("feedFLstOpt");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeRlsDetail::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFLSTOPT)) {feedFLstOpt = src->feedFLstOpt; add(FEEDFLSTOPT);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWdbeRlsDetail::DpchEngData::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWdbeRlsDetailData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFLSTOPT)) feedFLstOpt.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWdbeVLocale, me);
};

void PnlWdbeRlsDetail::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWdbeRlsDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFLSTOPT)) feedFLstOpt.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};
