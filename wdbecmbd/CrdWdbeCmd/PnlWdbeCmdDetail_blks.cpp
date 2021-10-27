/**
	* \file PnlWdbeCmdDetail_blks.cpp
	* job handler for job PnlWdbeCmdDetail (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbeCmdDetail::VecVDo
 ******************************************************************************/

uint PnlWdbeCmdDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butreuviewclick") return BUTREUVIEWCLICK;
	if (s == "butivrviewclick") return BUTIVRVIEWCLICK;
	if (s == "butrvrviewclick") return BUTRVRVIEWCLICK;
	if (s == "butrerviewclick") return BUTRERVIEWCLICK;

	return(0);
};

string PnlWdbeCmdDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTREUVIEWCLICK) return("ButReuViewClick");
	if (ix == BUTIVRVIEWCLICK) return("ButIvrViewClick");
	if (ix == BUTRVRVIEWCLICK) return("ButRvrViewClick");
	if (ix == BUTRERVIEWCLICK) return("ButRerViewClick");

	return("");
};

/******************************************************************************
 class PnlWdbeCmdDetail::ContIac
 ******************************************************************************/

PnlWdbeCmdDetail::ContIac::ContIac(
			const string& TxfFsr
			, const uint numFPupRet
			, const uint numFPupRty
			, const string& TxfCmt
		) :
			Block()
		{
	this->TxfFsr = TxfFsr;
	this->numFPupRet = numFPupRet;
	this->numFPupRty = numFPupRty;
	this->TxfCmt = TxfCmt;

	mask = {TXFFSR, NUMFPUPRET, NUMFPUPRTY, TXFCMT};
};

bool PnlWdbeCmdDetail::ContIac::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["ContIacWdbeCmdDetail"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("TxfFsr")) {TxfFsr = me["TxfFsr"].asString(); add(TXFFSR);};
		if (me.isMember("numFPupRet")) {numFPupRet = me["numFPupRet"].asUInt(); add(NUMFPUPRET);};
		if (me.isMember("numFPupRty")) {numFPupRty = me["numFPupRty"].asUInt(); add(NUMFPUPRTY);};
		if (me.isMember("TxfCmt")) {TxfCmt = me["TxfCmt"].asString(); add(TXFCMT);};
	};

	return basefound;
};

bool PnlWdbeCmdDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWdbeCmdDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWdbeCmdDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFsr", TxfFsr)) add(TXFFSR);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupRet", numFPupRet)) add(NUMFPUPRET);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupRty", numFPupRty)) add(NUMFPUPRTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlWdbeCmdDetail::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeCmdDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxfFsr"] = TxfFsr;
	me["numFPupRet"] = numFPupRet;
	me["numFPupRty"] = numFPupRty;
	me["TxfCmt"] = TxfCmt;
};

void PnlWdbeCmdDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeCmdDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWdbeCmdDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfFsr", TxfFsr);
		writeUintAttr(wr, itemtag, "sref", "numFPupRet", numFPupRet);
		writeUintAttr(wr, itemtag, "sref", "numFPupRty", numFPupRty);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeCmdDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfFsr == comp->TxfFsr) insert(items, TXFFSR);
	if (numFPupRet == comp->numFPupRet) insert(items, NUMFPUPRET);
	if (numFPupRty == comp->numFPupRty) insert(items, NUMFPUPRTY);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlWdbeCmdDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFFSR, NUMFPUPRET, NUMFPUPRTY, TXFCMT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeCmdDetail::ContInf
 ******************************************************************************/

PnlWdbeCmdDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtReu
			, const string& TxtIvr
			, const string& TxtRvr
			, const string& TxtRer
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtReu = TxtReu;
	this->TxtIvr = TxtIvr;
	this->TxtRvr = TxtRvr;
	this->TxtRer = TxtRer;

	mask = {TXTSRF, TXTREU, TXTIVR, TXTRVR, TXTRER};
};

void PnlWdbeCmdDetail::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbeCmdDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtSrf"] = TxtSrf;
	me["TxtReu"] = TxtReu;
	me["TxtIvr"] = TxtIvr;
	me["TxtRvr"] = TxtRvr;
	me["TxtRer"] = TxtRer;
};

void PnlWdbeCmdDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbeCmdDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWdbeCmdDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtReu", TxtReu);
		writeStringAttr(wr, itemtag, "sref", "TxtIvr", TxtIvr);
		writeStringAttr(wr, itemtag, "sref", "TxtRvr", TxtRvr);
		writeStringAttr(wr, itemtag, "sref", "TxtRer", TxtRer);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeCmdDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtReu == comp->TxtReu) insert(items, TXTREU);
	if (TxtIvr == comp->TxtIvr) insert(items, TXTIVR);
	if (TxtRvr == comp->TxtRvr) insert(items, TXTRVR);
	if (TxtRer == comp->TxtRer) insert(items, TXTRER);

	return(items);
};

set<uint> PnlWdbeCmdDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTREU, TXTIVR, TXTRVR, TXTRER};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeCmdDetail::StatApp
 ******************************************************************************/

void PnlWdbeCmdDetail::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWdbeVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeCmdDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWdbeVExpstate"] = VecWdbeVExpstate::getSref(ixWdbeVExpstate);
};

void PnlWdbeCmdDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWdbeVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeCmdDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWdbeCmdDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWdbeVExpstate", VecWdbeVExpstate::getSref(ixWdbeVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeCmdDetail::StatShr
 ******************************************************************************/

PnlWdbeCmdDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool TxfFsrActive
			, const bool TxtReuActive
			, const bool ButReuViewAvail
			, const bool ButReuViewActive
			, const bool PupRtyActive
			, const bool TxtIvrActive
			, const bool ButIvrViewAvail
			, const bool ButIvrViewActive
			, const bool TxtRvrActive
			, const bool ButRvrViewAvail
			, const bool ButRvrViewActive
			, const bool TxtRerActive
			, const bool ButRerViewAvail
			, const bool ButRerViewActive
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
	this->PupRtyActive = PupRtyActive;
	this->TxtIvrActive = TxtIvrActive;
	this->ButIvrViewAvail = ButIvrViewAvail;
	this->ButIvrViewActive = ButIvrViewActive;
	this->TxtRvrActive = TxtRvrActive;
	this->ButRvrViewAvail = ButRvrViewAvail;
	this->ButRvrViewActive = ButRvrViewActive;
	this->TxtRerActive = TxtRerActive;
	this->ButRerViewAvail = ButRerViewAvail;
	this->ButRerViewActive = ButRerViewActive;
	this->TxfCmtActive = TxfCmtActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFFSRACTIVE, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, PUPRTYACTIVE, TXTIVRACTIVE, BUTIVRVIEWAVAIL, BUTIVRVIEWACTIVE, TXTRVRACTIVE, BUTRVRVIEWAVAIL, BUTRVRVIEWACTIVE, TXTRERACTIVE, BUTRERVIEWAVAIL, BUTRERVIEWACTIVE, TXFCMTACTIVE};
};

void PnlWdbeCmdDetail::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeCmdDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButSaveAvail"] = ButSaveAvail;
	me["ButSaveActive"] = ButSaveActive;
	me["TxtSrfActive"] = TxtSrfActive;
	me["TxfFsrActive"] = TxfFsrActive;
	me["TxtReuActive"] = TxtReuActive;
	me["ButReuViewAvail"] = ButReuViewAvail;
	me["ButReuViewActive"] = ButReuViewActive;
	me["PupRtyActive"] = PupRtyActive;
	me["TxtIvrActive"] = TxtIvrActive;
	me["ButIvrViewAvail"] = ButIvrViewAvail;
	me["ButIvrViewActive"] = ButIvrViewActive;
	me["TxtRvrActive"] = TxtRvrActive;
	me["ButRvrViewAvail"] = ButRvrViewAvail;
	me["ButRvrViewActive"] = ButRvrViewActive;
	me["TxtRerActive"] = TxtRerActive;
	me["ButRerViewAvail"] = ButRerViewAvail;
	me["ButRerViewActive"] = ButRerViewActive;
	me["TxfCmtActive"] = TxfCmtActive;
};

void PnlWdbeCmdDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeCmdDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWdbeCmdDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSrfActive", TxtSrfActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfFsrActive", TxfFsrActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtReuActive", TxtReuActive);
		writeBoolAttr(wr, itemtag, "sref", "ButReuViewAvail", ButReuViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButReuViewActive", ButReuViewActive);
		writeBoolAttr(wr, itemtag, "sref", "PupRtyActive", PupRtyActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtIvrActive", TxtIvrActive);
		writeBoolAttr(wr, itemtag, "sref", "ButIvrViewAvail", ButIvrViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButIvrViewActive", ButIvrViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtRvrActive", TxtRvrActive);
		writeBoolAttr(wr, itemtag, "sref", "ButRvrViewAvail", ButRvrViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButRvrViewActive", ButRvrViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtRerActive", TxtRerActive);
		writeBoolAttr(wr, itemtag, "sref", "ButRerViewAvail", ButRerViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButRerViewActive", ButRerViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfCmtActive", TxfCmtActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeCmdDetail::StatShr::comm(
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
	if (PupRtyActive == comp->PupRtyActive) insert(items, PUPRTYACTIVE);
	if (TxtIvrActive == comp->TxtIvrActive) insert(items, TXTIVRACTIVE);
	if (ButIvrViewAvail == comp->ButIvrViewAvail) insert(items, BUTIVRVIEWAVAIL);
	if (ButIvrViewActive == comp->ButIvrViewActive) insert(items, BUTIVRVIEWACTIVE);
	if (TxtRvrActive == comp->TxtRvrActive) insert(items, TXTRVRACTIVE);
	if (ButRvrViewAvail == comp->ButRvrViewAvail) insert(items, BUTRVRVIEWAVAIL);
	if (ButRvrViewActive == comp->ButRvrViewActive) insert(items, BUTRVRVIEWACTIVE);
	if (TxtRerActive == comp->TxtRerActive) insert(items, TXTRERACTIVE);
	if (ButRerViewAvail == comp->ButRerViewAvail) insert(items, BUTRERVIEWAVAIL);
	if (ButRerViewActive == comp->ButRerViewActive) insert(items, BUTRERVIEWACTIVE);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);

	return(items);
};

set<uint> PnlWdbeCmdDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFFSRACTIVE, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, PUPRTYACTIVE, TXTIVRACTIVE, BUTIVRVIEWAVAIL, BUTIVRVIEWACTIVE, TXTRVRACTIVE, BUTRVRVIEWAVAIL, BUTRVRVIEWACTIVE, TXTRERACTIVE, BUTRERVIEWAVAIL, BUTRERVIEWACTIVE, TXFCMTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeCmdDetail::Tag
 ******************************************************************************/

void PnlWdbeCmdDetail::Tag::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWdbeCmdDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		me["CptSrf"] = "identifier";
		me["CptFsr"] = "full identifier";
		me["CptReu"] = "reference";
		me["CptRty"] = "return type";
		me["CptIvr"] = "invocation request signal";
		me["CptRvr"] = "revocation request signal";
		me["CptRer"] = "(new) return request signal";
		me["CptCmt"] = "comment";
	};
	me["Cpt"] = StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DETAIL, ixWdbeVLocale));
};

void PnlWdbeCmdDetail::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWdbeCmdDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWdbeCmdDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptFsr", "full identifier");
			writeStringAttr(wr, itemtag, "sref", "CptReu", "reference");
			writeStringAttr(wr, itemtag, "sref", "CptRty", "return type");
			writeStringAttr(wr, itemtag, "sref", "CptIvr", "invocation request signal");
			writeStringAttr(wr, itemtag, "sref", "CptRvr", "revocation request signal");
			writeStringAttr(wr, itemtag, "sref", "CptRer", "(new) return request signal");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "comment");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DETAIL, ixWdbeVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeCmdDetail::DpchAppData
 ******************************************************************************/

PnlWdbeCmdDetail::DpchAppData::DpchAppData() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBECMDDETAILDATA)
		{
};

string PnlWdbeCmdDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeCmdDetail::DpchAppData::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["DpchAppWdbeCmdDetailData"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWdbeCmdDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeCmdDetailData");
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
 class PnlWdbeCmdDetail::DpchAppDo
 ******************************************************************************/

PnlWdbeCmdDetail::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBECMDDETAILDO)
		{
	ixVDo = 0;
};

string PnlWdbeCmdDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeCmdDetail::DpchAppDo::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["DpchAppWdbeCmdDetailDo"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWdbeCmdDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeCmdDetailDo");
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
 class PnlWdbeCmdDetail::DpchEngData
 ******************************************************************************/

PnlWdbeCmdDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupRet
			, Feed* feedFPupRty
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBECMDDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPRET, FEEDFPUPRTY, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPRET) && feedFPupRet) this->feedFPupRet = *feedFPupRet;
	if (find(this->mask, FEEDFPUPRTY) && feedFPupRty) this->feedFPupRty = *feedFPupRty;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWdbeCmdDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPRET)) ss.push_back("feedFPupRet");
	if (has(FEEDFPUPRTY)) ss.push_back("feedFPupRty");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeCmdDetail::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFPUPRET)) {feedFPupRet = src->feedFPupRet; add(FEEDFPUPRET);};
	if (src->has(FEEDFPUPRTY)) {feedFPupRty = src->feedFPupRty; add(FEEDFPUPRTY);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWdbeCmdDetail::DpchEngData::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWdbeCmdDetailData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFPUPRET)) feedFPupRet.writeJSON(me);
	if (has(FEEDFPUPRTY)) feedFPupRty.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWdbeVLocale, me);
};

void PnlWdbeCmdDetail::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWdbeCmdDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFPUPRET)) feedFPupRet.writeXML(wr);
		if (has(FEEDFPUPRTY)) feedFPupRty.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};
