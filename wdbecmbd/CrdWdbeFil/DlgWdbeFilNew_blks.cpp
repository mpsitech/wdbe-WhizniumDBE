/**
	* \file DlgWdbeFilNew_blks.cpp
	* job handler for job DlgWdbeFilNew (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DlgWdbeFilNew::VecVDit
 ******************************************************************************/

uint DlgWdbeFilNew::VecVDit::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "det") return DET;
	if (s == "fil") return FIL;

	return(0);
};

string DlgWdbeFilNew::VecVDit::getSref(
			const uint ix
		) {
	if (ix == DET) return("Det");
	if (ix == FIL) return("Fil");

	return("");
};

string DlgWdbeFilNew::VecVDit::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == DET) return("Details");
		if (ix == FIL) return("File");
		return(getSref(ix));
	};

	return("");
};

void DlgWdbeFilNew::VecVDit::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};

/******************************************************************************
 class DlgWdbeFilNew::VecVDo
 ******************************************************************************/

uint DlgWdbeFilNew::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butdneclick") return BUTDNECLICK;

	return(0);
};

string DlgWdbeFilNew::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgWdbeFilNew::VecVDoDet
 ******************************************************************************/

uint DlgWdbeFilNew::VecVDoDet::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butcreclick") return BUTCRECLICK;

	return(0);
};

string DlgWdbeFilNew::VecVDoDet::getSref(
			const uint ix
		) {
	if (ix == BUTCRECLICK) return("ButCreClick");

	return("");
};

/******************************************************************************
 class DlgWdbeFilNew::VecVSge
 ******************************************************************************/

uint DlgWdbeFilNew::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "create") return CREATE;
	if (s == "credone") return CREDONE;
	if (s == "done") return DONE;

	return(0);
};

string DlgWdbeFilNew::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == CREATE) return("create");
	if (ix == CREDONE) return("credone");
	if (ix == DONE) return("done");

	return("");
};

void DlgWdbeFilNew::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 4; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class DlgWdbeFilNew::ContIac
 ******************************************************************************/

DlgWdbeFilNew::ContIac::ContIac(
			const uint numFDse
		) :
			Block()
		{
	this->numFDse = numFDse;

	mask = {NUMFDSE};
};

bool DlgWdbeFilNew::ContIac::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["ContIacDlgWdbeFilNew"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFDse")) {numFDse = me["numFDse"].asUInt(); add(NUMFDSE);};
	};

	return basefound;
};

bool DlgWdbeFilNew::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgWdbeFilNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgWdbeFilNew";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDse", numFDse)) add(NUMFDSE);
	};

	return basefound;
};

void DlgWdbeFilNew::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWdbeFilNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFDse"] = numFDse;
};

void DlgWdbeFilNew::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWdbeFilNew";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgWdbeFilNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFDse", numFDse);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeFilNew::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFDse == comp->numFDse) insert(items, NUMFDSE);

	return(items);
};

set<uint> DlgWdbeFilNew::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFDSE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeFilNew::ContIacDet
 ******************************************************************************/

DlgWdbeFilNew::ContIacDet::ContIacDet(
			const string& TxfFnm
			, const uint numFPupRet
			, const string& TxfReu
			, const uint numFPupCnt
			, const uint numFPupMim
			, const string& TxfCmt
		) :
			Block()
		{
	this->TxfFnm = TxfFnm;
	this->numFPupRet = numFPupRet;
	this->TxfReu = TxfReu;
	this->numFPupCnt = numFPupCnt;
	this->numFPupMim = numFPupMim;
	this->TxfCmt = TxfCmt;

	mask = {TXFFNM, NUMFPUPRET, TXFREU, NUMFPUPCNT, NUMFPUPMIM, TXFCMT};
};

bool DlgWdbeFilNew::ContIacDet::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["ContIacDlgWdbeFilNewDet"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("TxfFnm")) {TxfFnm = me["TxfFnm"].asString(); add(TXFFNM);};
		if (me.isMember("numFPupRet")) {numFPupRet = me["numFPupRet"].asUInt(); add(NUMFPUPRET);};
		if (me.isMember("TxfReu")) {TxfReu = me["TxfReu"].asString(); add(TXFREU);};
		if (me.isMember("numFPupCnt")) {numFPupCnt = me["numFPupCnt"].asUInt(); add(NUMFPUPCNT);};
		if (me.isMember("numFPupMim")) {numFPupMim = me["numFPupMim"].asUInt(); add(NUMFPUPMIM);};
		if (me.isMember("TxfCmt")) {TxfCmt = me["TxfCmt"].asString(); add(TXFCMT);};
	};

	return basefound;
};

bool DlgWdbeFilNew::ContIacDet::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgWdbeFilNewDet");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgWdbeFilNewDet";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFnm", TxfFnm)) add(TXFFNM);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupRet", numFPupRet)) add(NUMFPUPRET);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfReu", TxfReu)) add(TXFREU);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupCnt", numFPupCnt)) add(NUMFPUPCNT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupMim", numFPupMim)) add(NUMFPUPMIM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void DlgWdbeFilNew::ContIacDet::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWdbeFilNewDet";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxfFnm"] = TxfFnm;
	me["numFPupRet"] = numFPupRet;
	me["TxfReu"] = TxfReu;
	me["numFPupCnt"] = numFPupCnt;
	me["numFPupMim"] = numFPupMim;
	me["TxfCmt"] = TxfCmt;
};

void DlgWdbeFilNew::ContIacDet::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWdbeFilNewDet";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgWdbeFilNewDet";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfFnm", TxfFnm);
		writeUintAttr(wr, itemtag, "sref", "numFPupRet", numFPupRet);
		writeStringAttr(wr, itemtag, "sref", "TxfReu", TxfReu);
		writeUintAttr(wr, itemtag, "sref", "numFPupCnt", numFPupCnt);
		writeUintAttr(wr, itemtag, "sref", "numFPupMim", numFPupMim);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeFilNew::ContIacDet::comm(
			const ContIacDet* comp
		) {
	set<uint> items;

	if (TxfFnm == comp->TxfFnm) insert(items, TXFFNM);
	if (numFPupRet == comp->numFPupRet) insert(items, NUMFPUPRET);
	if (TxfReu == comp->TxfReu) insert(items, TXFREU);
	if (numFPupCnt == comp->numFPupCnt) insert(items, NUMFPUPCNT);
	if (numFPupMim == comp->numFPupMim) insert(items, NUMFPUPMIM);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> DlgWdbeFilNew::ContIacDet::diff(
			const ContIacDet* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFFNM, NUMFPUPRET, TXFREU, NUMFPUPCNT, NUMFPUPMIM, TXFCMT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeFilNew::ContInf
 ******************************************************************************/

DlgWdbeFilNew::ContInf::ContInf(
			const uint numFSge
		) :
			Block()
		{
	this->numFSge = numFSge;

	mask = {NUMFSGE};
};

void DlgWdbeFilNew::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWdbeFilNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFSge"] = numFSge;
};

void DlgWdbeFilNew::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWdbeFilNew";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWdbeFilNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeFilNew::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);

	return(items);
};

set<uint> DlgWdbeFilNew::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeFilNew::StatApp
 ******************************************************************************/

void DlgWdbeFilNew::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const bool initdone
			, const string& shortMenu
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgWdbeFilNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["initdone"] = initdone;
	me["shortMenu"] = shortMenu;
};

void DlgWdbeFilNew::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdone
			, const string& shortMenu
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgWdbeFilNew";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppDlgWdbeFilNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdone", initdone);
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeFilNew::StatShr
 ******************************************************************************/

DlgWdbeFilNew::StatShr::StatShr(
			const bool ButDneActive
		) :
			Block()
		{
	this->ButDneActive = ButDneActive;

	mask = {BUTDNEACTIVE};
};

void DlgWdbeFilNew::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWdbeFilNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButDneActive"] = ButDneActive;
};

void DlgWdbeFilNew::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWdbeFilNew";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWdbeFilNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButDneActive", ButDneActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeFilNew::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButDneActive == comp->ButDneActive) insert(items, BUTDNEACTIVE);

	return(items);
};

set<uint> DlgWdbeFilNew::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTDNEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeFilNew::StatShrDet
 ******************************************************************************/

DlgWdbeFilNew::StatShrDet::StatShrDet(
			const bool ButCreActive
		) :
			Block()
		{
	this->ButCreActive = ButCreActive;

	mask = {BUTCREACTIVE};
};

void DlgWdbeFilNew::StatShrDet::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWdbeFilNewDet";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButCreActive"] = ButCreActive;
};

void DlgWdbeFilNew::StatShrDet::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWdbeFilNewDet";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWdbeFilNewDet";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButCreActive", ButCreActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeFilNew::StatShrDet::comm(
			const StatShrDet* comp
		) {
	set<uint> items;

	if (ButCreActive == comp->ButCreActive) insert(items, BUTCREACTIVE);

	return(items);
};

set<uint> DlgWdbeFilNew::StatShrDet::diff(
			const StatShrDet* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTCREACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeFilNew::StatShrFil
 ******************************************************************************/

DlgWdbeFilNew::StatShrFil::StatShrFil(
			const bool UldActive
		) :
			Block()
		{
	this->UldActive = UldActive;

	mask = {ULDACTIVE};
};

void DlgWdbeFilNew::StatShrFil::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWdbeFilNewFil";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["UldActive"] = UldActive;
};

void DlgWdbeFilNew::StatShrFil::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWdbeFilNewFil";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWdbeFilNewFil";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "UldActive", UldActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeFilNew::StatShrFil::comm(
			const StatShrFil* comp
		) {
	set<uint> items;

	if (UldActive == comp->UldActive) insert(items, ULDACTIVE);

	return(items);
};

set<uint> DlgWdbeFilNew::StatShrFil::diff(
			const StatShrFil* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {ULDACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeFilNew::Tag
 ******************************************************************************/

void DlgWdbeFilNew::Tag::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagDlgWdbeFilNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		me["Cpt"] = "Upload new file";
	};
	me["ButDne"] = StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DONE, ixWdbeVLocale));
};

void DlgWdbeFilNew::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWdbeFilNew";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWdbeFilNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Upload new file");
		};
		writeStringAttr(wr, itemtag, "sref", "ButDne", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DONE, ixWdbeVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeFilNew::TagDet
 ******************************************************************************/

void DlgWdbeFilNew::TagDet::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagDlgWdbeFilNewDet";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		me["CptFnm"] = "File name";
		me["CptRet"] = "Table of reference";
		me["CptReu"] = "Reference";
		me["CptCnt"] = "Content";
		me["CptMim"] = "MIME type";
		me["CptCmt"] = "Comment";
	};
	me["ButCre"] = StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::CREATE, ixWdbeVLocale));
};

void DlgWdbeFilNew::TagDet::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWdbeFilNewDet";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWdbeFilNewDet";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptFnm", "File name");
			writeStringAttr(wr, itemtag, "sref", "CptRet", "Table of reference");
			writeStringAttr(wr, itemtag, "sref", "CptReu", "Reference");
			writeStringAttr(wr, itemtag, "sref", "CptCnt", "Content");
			writeStringAttr(wr, itemtag, "sref", "CptMim", "MIME type");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "Comment");
		};
		writeStringAttr(wr, itemtag, "sref", "ButCre", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::CREATE, ixWdbeVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeFilNew::TagFil
 ******************************************************************************/

void DlgWdbeFilNew::TagFil::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagDlgWdbeFilNewFil";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
	};
	me["Uld"] = StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::UPLOAD, ixWdbeVLocale));
	me["Cpt"] = StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::FILENAME, ixWdbeVLocale));
};

void DlgWdbeFilNew::TagFil::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWdbeFilNewFil";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWdbeFilNewFil";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		};
		writeStringAttr(wr, itemtag, "sref", "Uld", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::UPLOAD, ixWdbeVLocale)));
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::FILENAME, ixWdbeVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeFilNew::DpchAppData
 ******************************************************************************/

DlgWdbeFilNew::DpchAppData::DpchAppData() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPDLGWDBEFILNEWDATA)
		{
};

string DlgWdbeFilNew::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTIACDET)) ss.push_back("contiacdet");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbeFilNew::DpchAppData::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["DpchAppDlgWdbeFilNewData"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
		if (contiacdet.readJSON(me, true)) add(CONTIACDET);
	} else {
		contiac = ContIac();
		contiacdet = ContIacDet();
	};
};

void DlgWdbeFilNew::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgWdbeFilNewData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (contiacdet.readXML(docctx, basexpath, true)) add(CONTIACDET);
	} else {
		contiac = ContIac();
		contiacdet = ContIacDet();
	};
};

/******************************************************************************
 class DlgWdbeFilNew::DpchAppDo
 ******************************************************************************/

DlgWdbeFilNew::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPDLGWDBEFILNEWDO)
		{
	ixVDo = 0;
	ixVDoDet = 0;
};

string DlgWdbeFilNew::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");
	if (has(IXVDODET)) ss.push_back("ixVDoDet");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbeFilNew::DpchAppDo::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["DpchAppDlgWdbeFilNewDo"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
		if (me.isMember("srefIxVDoDet")) {ixVDoDet = VecVDoDet::getIx(me["srefIxVDoDet"].asString()); add(IXVDODET);};
	} else {
	};
};

void DlgWdbeFilNew::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;
	string srefIxVDoDet;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgWdbeFilNewDo");
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
		if (extractStringUclc(docctx, basexpath, "srefIxVDoDet", "", srefIxVDoDet)) {
			ixVDoDet = VecVDoDet::getIx(srefIxVDoDet);
			add(IXVDODET);
		};
	} else {
	};
};

/******************************************************************************
 class DlgWdbeFilNew::DpchEngData
 ******************************************************************************/

DlgWdbeFilNew::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContIacDet* contiacdet
			, ContInf* continf
			, Feed* feedFDetPupCnt
			, Feed* feedFDetPupMim
			, Feed* feedFDetPupRet
			, Feed* feedFDse
			, Feed* feedFSge
			, StatShr* statshr
			, StatShrDet* statshrdet
			, StatShrFil* statshrfil
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGDLGWDBEFILNEWDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTIACDET, CONTINF, FEEDFDETPUPCNT, FEEDFDETPUPMIM, FEEDFDETPUPRET, FEEDFDSE, FEEDFSGE, STATAPP, STATSHR, STATSHRDET, STATSHRFIL, TAG, TAGDET, TAGFIL};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTIACDET) && contiacdet) this->contiacdet = *contiacdet;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFDETPUPCNT) && feedFDetPupCnt) this->feedFDetPupCnt = *feedFDetPupCnt;
	if (find(this->mask, FEEDFDETPUPMIM) && feedFDetPupMim) this->feedFDetPupMim = *feedFDetPupMim;
	if (find(this->mask, FEEDFDETPUPRET) && feedFDetPupRet) this->feedFDetPupRet = *feedFDetPupRet;
	if (find(this->mask, FEEDFDSE) && feedFDse) this->feedFDse = *feedFDse;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
	if (find(this->mask, STATSHRDET) && statshrdet) this->statshrdet = *statshrdet;
	if (find(this->mask, STATSHRFIL) && statshrfil) this->statshrfil = *statshrfil;
};

string DlgWdbeFilNew::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTIACDET)) ss.push_back("contiacdet");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFDETPUPCNT)) ss.push_back("feedFDetPupCnt");
	if (has(FEEDFDETPUPMIM)) ss.push_back("feedFDetPupMim");
	if (has(FEEDFDETPUPRET)) ss.push_back("feedFDetPupRet");
	if (has(FEEDFDSE)) ss.push_back("feedFDse");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(STATSHRDET)) ss.push_back("statshrdet");
	if (has(STATSHRFIL)) ss.push_back("statshrfil");
	if (has(TAG)) ss.push_back("tag");
	if (has(TAGDET)) ss.push_back("tagdet");
	if (has(TAGFIL)) ss.push_back("tagfil");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbeFilNew::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTIACDET)) {contiacdet = src->contiacdet; add(CONTIACDET);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFDETPUPCNT)) {feedFDetPupCnt = src->feedFDetPupCnt; add(FEEDFDETPUPCNT);};
	if (src->has(FEEDFDETPUPMIM)) {feedFDetPupMim = src->feedFDetPupMim; add(FEEDFDETPUPMIM);};
	if (src->has(FEEDFDETPUPRET)) {feedFDetPupRet = src->feedFDetPupRet; add(FEEDFDETPUPRET);};
	if (src->has(FEEDFDSE)) {feedFDse = src->feedFDse; add(FEEDFDSE);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(STATSHRDET)) {statshrdet = src->statshrdet; add(STATSHRDET);};
	if (src->has(STATSHRFIL)) {statshrfil = src->statshrfil; add(STATSHRFIL);};
	if (src->has(TAG)) add(TAG);
	if (src->has(TAGDET)) add(TAGDET);
	if (src->has(TAGFIL)) add(TAGFIL);
};

void DlgWdbeFilNew::DpchEngData::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngDlgWdbeFilNewData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTIACDET)) contiacdet.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFDETPUPCNT)) feedFDetPupCnt.writeJSON(me);
	if (has(FEEDFDETPUPMIM)) feedFDetPupMim.writeJSON(me);
	if (has(FEEDFDETPUPRET)) feedFDetPupRet.writeJSON(me);
	if (has(FEEDFDSE)) feedFDse.writeJSON(me);
	if (has(FEEDFSGE)) feedFSge.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(STATSHRDET)) statshrdet.writeJSON(me);
	if (has(STATSHRFIL)) statshrfil.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWdbeVLocale, me);
	if (has(TAGDET)) TagDet::writeJSON(ixWdbeVLocale, me);
	if (has(TAGFIL)) TagFil::writeJSON(ixWdbeVLocale, me);
};

void DlgWdbeFilNew::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngDlgWdbeFilNewData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTIACDET)) contiacdet.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFDETPUPCNT)) feedFDetPupCnt.writeXML(wr);
		if (has(FEEDFDETPUPMIM)) feedFDetPupMim.writeXML(wr);
		if (has(FEEDFDETPUPRET)) feedFDetPupRet.writeXML(wr);
		if (has(FEEDFDSE)) feedFDse.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STATSHRDET)) statshrdet.writeXML(wr);
		if (has(STATSHRFIL)) statshrfil.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
		if (has(TAGDET)) TagDet::writeXML(ixWdbeVLocale, wr);
		if (has(TAGFIL)) TagFil::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};
