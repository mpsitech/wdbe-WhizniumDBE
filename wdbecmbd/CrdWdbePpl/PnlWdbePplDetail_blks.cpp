/**
	* \file PnlWdbePplDetail_blks.cpp
	* job handler for job PnlWdbePplDetail (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbePplDetail::VecVDo
 ******************************************************************************/

uint PnlWdbePplDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "buthsmviewclick") return BUTHSMVIEWCLICK;
	if (s == "butclkviewclick") return BUTCLKVIEWCLICK;
	if (s == "butclgviewclick") return BUTCLGVIEWCLICK;
	if (s == "butasrviewclick") return BUTASRVIEWCLICK;

	return(0);
};

string PnlWdbePplDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTHSMVIEWCLICK) return("ButHsmViewClick");
	if (ix == BUTCLKVIEWCLICK) return("ButClkViewClick");
	if (ix == BUTCLGVIEWCLICK) return("ButClgViewClick");
	if (ix == BUTASRVIEWCLICK) return("ButAsrViewClick");

	return("");
};

/******************************************************************************
 class PnlWdbePplDetail::ContIac
 ******************************************************************************/

PnlWdbePplDetail::ContIac::ContIac(
			const string& TxfClk
			, const string& TxfClg
			, const string& TxfAsr
			, const string& TxfDpt
			, const string& TxfCmt
		) :
			Block()
			, TxfClk(TxfClk)
			, TxfClg(TxfClg)
			, TxfAsr(TxfAsr)
			, TxfDpt(TxfDpt)
			, TxfCmt(TxfCmt)
		{
	mask = {TXFCLK, TXFCLG, TXFASR, TXFDPT, TXFCMT};
};

bool PnlWdbePplDetail::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacWdbePplDetail"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("TxfClk")) {TxfClk = me["TxfClk"].asString(); add(TXFCLK);};
		if (me.isMember("TxfClg")) {TxfClg = me["TxfClg"].asString(); add(TXFCLG);};
		if (me.isMember("TxfAsr")) {TxfAsr = me["TxfAsr"].asString(); add(TXFASR);};
		if (me.isMember("TxfDpt")) {TxfDpt = me["TxfDpt"].asString(); add(TXFDPT);};
		if (me.isMember("TxfCmt")) {TxfCmt = me["TxfCmt"].asString(); add(TXFCMT);};
	};

	return basefound;
};

bool PnlWdbePplDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWdbePplDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWdbePplDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfClk", TxfClk)) add(TXFCLK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfClg", TxfClg)) add(TXFCLG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAsr", TxfAsr)) add(TXFASR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfDpt", TxfDpt)) add(TXFDPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlWdbePplDetail::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbePplDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxfClk"] = TxfClk;
	me["TxfClg"] = TxfClg;
	me["TxfAsr"] = TxfAsr;
	me["TxfDpt"] = TxfDpt;
	me["TxfCmt"] = TxfCmt;
};

void PnlWdbePplDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbePplDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWdbePplDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfClk", TxfClk);
		writeStringAttr(wr, itemtag, "sref", "TxfClg", TxfClg);
		writeStringAttr(wr, itemtag, "sref", "TxfAsr", TxfAsr);
		writeStringAttr(wr, itemtag, "sref", "TxfDpt", TxfDpt);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbePplDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfClk == comp->TxfClk) insert(items, TXFCLK);
	if (TxfClg == comp->TxfClg) insert(items, TXFCLG);
	if (TxfAsr == comp->TxfAsr) insert(items, TXFASR);
	if (TxfDpt == comp->TxfDpt) insert(items, TXFDPT);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlWdbePplDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFCLK, TXFCLG, TXFASR, TXFDPT, TXFCMT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbePplDetail::ContInf
 ******************************************************************************/

PnlWdbePplDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtHsm
			, const string& TxtClk
			, const string& TxtClg
			, const string& TxtAsr
		) :
			Block()
			, TxtSrf(TxtSrf)
			, TxtHsm(TxtHsm)
			, TxtClk(TxtClk)
			, TxtClg(TxtClg)
			, TxtAsr(TxtAsr)
		{
	mask = {TXTSRF, TXTHSM, TXTCLK, TXTCLG, TXTASR};
};

void PnlWdbePplDetail::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbePplDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtSrf"] = TxtSrf;
	me["TxtHsm"] = TxtHsm;
	me["TxtClk"] = TxtClk;
	me["TxtClg"] = TxtClg;
	me["TxtAsr"] = TxtAsr;
};

void PnlWdbePplDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbePplDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWdbePplDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtHsm", TxtHsm);
		writeStringAttr(wr, itemtag, "sref", "TxtClk", TxtClk);
		writeStringAttr(wr, itemtag, "sref", "TxtClg", TxtClg);
		writeStringAttr(wr, itemtag, "sref", "TxtAsr", TxtAsr);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbePplDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtHsm == comp->TxtHsm) insert(items, TXTHSM);
	if (TxtClk == comp->TxtClk) insert(items, TXTCLK);
	if (TxtClg == comp->TxtClg) insert(items, TXTCLG);
	if (TxtAsr == comp->TxtAsr) insert(items, TXTASR);

	return(items);
};

set<uint> PnlWdbePplDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTHSM, TXTCLK, TXTCLG, TXTASR};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbePplDetail::StatApp
 ******************************************************************************/

void PnlWdbePplDetail::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWdbeVExpstate
			, const bool TxtClkAlt
			, const bool TxtClgAlt
			, const bool TxtAsrAlt
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbePplDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWdbeVExpstate"] = VecWdbeVExpstate::getSref(ixWdbeVExpstate);
	me["TxtClkAlt"] = TxtClkAlt;
	me["TxtClgAlt"] = TxtClgAlt;
	me["TxtAsrAlt"] = TxtAsrAlt;
};

void PnlWdbePplDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWdbeVExpstate
			, const bool TxtClkAlt
			, const bool TxtClgAlt
			, const bool TxtAsrAlt
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbePplDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWdbePplDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWdbeVExpstate", VecWdbeVExpstate::getSref(ixWdbeVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "TxtClkAlt", TxtClkAlt);
		writeBoolAttr(wr, itemtag, "sref", "TxtClgAlt", TxtClgAlt);
		writeBoolAttr(wr, itemtag, "sref", "TxtAsrAlt", TxtAsrAlt);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbePplDetail::StatShr
 ******************************************************************************/

PnlWdbePplDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool TxtHsmActive
			, const bool ButHsmViewAvail
			, const bool ButHsmViewActive
			, const bool TxtClkActive
			, const bool TxfClkValid
			, const bool ButClkViewAvail
			, const bool TxtClgActive
			, const bool TxfClgValid
			, const bool ButClgViewAvail
			, const bool TxtAsrActive
			, const bool TxfAsrValid
			, const bool ButAsrViewAvail
			, const bool TxfDptActive
			, const bool TxfCmtActive
		) :
			Block()
			, ButSaveAvail(ButSaveAvail)
			, ButSaveActive(ButSaveActive)
			, TxtSrfActive(TxtSrfActive)
			, TxtHsmActive(TxtHsmActive)
			, ButHsmViewAvail(ButHsmViewAvail)
			, ButHsmViewActive(ButHsmViewActive)
			, TxtClkActive(TxtClkActive)
			, TxfClkValid(TxfClkValid)
			, ButClkViewAvail(ButClkViewAvail)
			, TxtClgActive(TxtClgActive)
			, TxfClgValid(TxfClgValid)
			, ButClgViewAvail(ButClgViewAvail)
			, TxtAsrActive(TxtAsrActive)
			, TxfAsrValid(TxfAsrValid)
			, ButAsrViewAvail(ButAsrViewAvail)
			, TxfDptActive(TxfDptActive)
			, TxfCmtActive(TxfCmtActive)
		{
	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTHSMACTIVE, BUTHSMVIEWAVAIL, BUTHSMVIEWACTIVE, TXTCLKACTIVE, TXFCLKVALID, BUTCLKVIEWAVAIL, TXTCLGACTIVE, TXFCLGVALID, BUTCLGVIEWAVAIL, TXTASRACTIVE, TXFASRVALID, BUTASRVIEWAVAIL, TXFDPTACTIVE, TXFCMTACTIVE};
};

void PnlWdbePplDetail::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbePplDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButSaveAvail"] = ButSaveAvail;
	me["ButSaveActive"] = ButSaveActive;
	me["TxtSrfActive"] = TxtSrfActive;
	me["TxtHsmActive"] = TxtHsmActive;
	me["ButHsmViewAvail"] = ButHsmViewAvail;
	me["ButHsmViewActive"] = ButHsmViewActive;
	me["TxtClkActive"] = TxtClkActive;
	me["TxfClkValid"] = TxfClkValid;
	me["ButClkViewAvail"] = ButClkViewAvail;
	me["TxtClgActive"] = TxtClgActive;
	me["TxfClgValid"] = TxfClgValid;
	me["ButClgViewAvail"] = ButClgViewAvail;
	me["TxtAsrActive"] = TxtAsrActive;
	me["TxfAsrValid"] = TxfAsrValid;
	me["ButAsrViewAvail"] = ButAsrViewAvail;
	me["TxfDptActive"] = TxfDptActive;
	me["TxfCmtActive"] = TxfCmtActive;
};

void PnlWdbePplDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbePplDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWdbePplDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSrfActive", TxtSrfActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtHsmActive", TxtHsmActive);
		writeBoolAttr(wr, itemtag, "sref", "ButHsmViewAvail", ButHsmViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButHsmViewActive", ButHsmViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtClkActive", TxtClkActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfClkValid", TxfClkValid);
		writeBoolAttr(wr, itemtag, "sref", "ButClkViewAvail", ButClkViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtClgActive", TxtClgActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfClgValid", TxfClgValid);
		writeBoolAttr(wr, itemtag, "sref", "ButClgViewAvail", ButClgViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtAsrActive", TxtAsrActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfAsrValid", TxfAsrValid);
		writeBoolAttr(wr, itemtag, "sref", "ButAsrViewAvail", ButAsrViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfDptActive", TxfDptActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfCmtActive", TxfCmtActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbePplDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (TxtHsmActive == comp->TxtHsmActive) insert(items, TXTHSMACTIVE);
	if (ButHsmViewAvail == comp->ButHsmViewAvail) insert(items, BUTHSMVIEWAVAIL);
	if (ButHsmViewActive == comp->ButHsmViewActive) insert(items, BUTHSMVIEWACTIVE);
	if (TxtClkActive == comp->TxtClkActive) insert(items, TXTCLKACTIVE);
	if (TxfClkValid == comp->TxfClkValid) insert(items, TXFCLKVALID);
	if (ButClkViewAvail == comp->ButClkViewAvail) insert(items, BUTCLKVIEWAVAIL);
	if (TxtClgActive == comp->TxtClgActive) insert(items, TXTCLGACTIVE);
	if (TxfClgValid == comp->TxfClgValid) insert(items, TXFCLGVALID);
	if (ButClgViewAvail == comp->ButClgViewAvail) insert(items, BUTCLGVIEWAVAIL);
	if (TxtAsrActive == comp->TxtAsrActive) insert(items, TXTASRACTIVE);
	if (TxfAsrValid == comp->TxfAsrValid) insert(items, TXFASRVALID);
	if (ButAsrViewAvail == comp->ButAsrViewAvail) insert(items, BUTASRVIEWAVAIL);
	if (TxfDptActive == comp->TxfDptActive) insert(items, TXFDPTACTIVE);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);

	return(items);
};

set<uint> PnlWdbePplDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTHSMACTIVE, BUTHSMVIEWAVAIL, BUTHSMVIEWACTIVE, TXTCLKACTIVE, TXFCLKVALID, BUTCLKVIEWAVAIL, TXTCLGACTIVE, TXFCLGVALID, BUTCLGVIEWAVAIL, TXTASRACTIVE, TXFASRVALID, BUTASRVIEWAVAIL, TXFDPTACTIVE, TXFCMTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbePplDetail::Tag
 ******************************************************************************/

void PnlWdbePplDetail::Tag::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWdbePplDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		me["CptSrf"] = "identifier";
		me["CptHsm"] = "host module";
		me["CptClk"] = "clock signal";
		me["CptClg"] = "clock gating signal";
		me["CptAsr"] = "asynchronous reset signal";
		me["CptDpt"] = "depth";
		me["CptCmt"] = "comment";
	};
	me["Cpt"] = StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DETAIL, ixWdbeVLocale));
};

void PnlWdbePplDetail::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWdbePplDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWdbePplDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptHsm", "host module");
			writeStringAttr(wr, itemtag, "sref", "CptClk", "clock signal");
			writeStringAttr(wr, itemtag, "sref", "CptClg", "clock gating signal");
			writeStringAttr(wr, itemtag, "sref", "CptAsr", "asynchronous reset signal");
			writeStringAttr(wr, itemtag, "sref", "CptDpt", "depth");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "comment");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DETAIL, ixWdbeVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbePplDetail::DpchAppData
 ******************************************************************************/

PnlWdbePplDetail::DpchAppData::DpchAppData() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEPPLDETAILDATA)
		{
};

string PnlWdbePplDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbePplDetail::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWdbePplDetailData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWdbePplDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbePplDetailData");
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
 class PnlWdbePplDetail::DpchAppDo
 ******************************************************************************/

PnlWdbePplDetail::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEPPLDETAILDO)
		{
	ixVDo = 0;
};

string PnlWdbePplDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbePplDetail::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWdbePplDetailDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWdbePplDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbePplDetailDo");
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
 class PnlWdbePplDetail::DpchEngData
 ******************************************************************************/

PnlWdbePplDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBEPPLDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWdbePplDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbePplDetail::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWdbePplDetail::DpchEngData::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWdbePplDetailData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWdbeVLocale, me);
};

void PnlWdbePplDetail::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWdbePplDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};
