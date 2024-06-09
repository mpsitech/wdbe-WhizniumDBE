/**
	* \file DlgWdbeCvrDetcd_blks.cpp
	* job handler for job DlgWdbeCvrDetcd (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DlgWdbeCvrDetcd::VecVDit
 ******************************************************************************/

uint DlgWdbeCvrDetcd::VecVDit::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "ifi") return IFI;
	if (s == "imp") return IMP;
	if (s == "ppr") return PPR;
	if (s == "lfi") return LFI;

	return(0);
};

string DlgWdbeCvrDetcd::VecVDit::getSref(
			const uint ix
		) {
	if (ix == IFI) return("Ifi");
	if (ix == IMP) return("Imp");
	if (ix == PPR) return("Ppr");
	if (ix == LFI) return("Lfi");

	return("");
};

string DlgWdbeCvrDetcd::VecVDit::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == IFI) return("Input file");
		if (ix == IMP) return("Import");
		if (ix == PPR) return("Postprocessing");
		if (ix == LFI) return("Log file");
		return(getSref(ix));
	};

	return("");
};

void DlgWdbeCvrDetcd::VecVDit::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 4; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};

/******************************************************************************
 class DlgWdbeCvrDetcd::VecVDo
 ******************************************************************************/

uint DlgWdbeCvrDetcd::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butdneclick") return BUTDNECLICK;

	return(0);
};

string DlgWdbeCvrDetcd::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgWdbeCvrDetcd::VecVDoImp
 ******************************************************************************/

uint DlgWdbeCvrDetcd::VecVDoImp::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butrunclick") return BUTRUNCLICK;
	if (s == "butstoclick") return BUTSTOCLICK;

	return(0);
};

string DlgWdbeCvrDetcd::VecVDoImp::getSref(
			const uint ix
		) {
	if (ix == BUTRUNCLICK) return("ButRunClick");
	if (ix == BUTSTOCLICK) return("ButStoClick");

	return("");
};

/******************************************************************************
 class DlgWdbeCvrDetcd::VecVDoPpr
 ******************************************************************************/

uint DlgWdbeCvrDetcd::VecVDoPpr::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butrunclick") return BUTRUNCLICK;
	if (s == "butstoclick") return BUTSTOCLICK;

	return(0);
};

string DlgWdbeCvrDetcd::VecVDoPpr::getSref(
			const uint ix
		) {
	if (ix == BUTRUNCLICK) return("ButRunClick");
	if (ix == BUTSTOCLICK) return("ButStoClick");

	return("");
};

/******************************************************************************
 class DlgWdbeCvrDetcd::VecVSge
 ******************************************************************************/

uint DlgWdbeCvrDetcd::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "prsidle") return PRSIDLE;
	if (s == "parse") return PARSE;
	if (s == "alrwdbeper") return ALRWDBEPER;
	if (s == "prsdone") return PRSDONE;
	if (s == "impidle") return IMPIDLE;
	if (s == "import") return IMPORT;
	if (s == "alrwdbeier") return ALRWDBEIER;
	if (s == "impdone") return IMPDONE;
	if (s == "postprc") return POSTPRC;
	if (s == "done") return DONE;

	return(0);
};

string DlgWdbeCvrDetcd::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == PRSIDLE) return("prsidle");
	if (ix == PARSE) return("parse");
	if (ix == ALRWDBEPER) return("alrwdbeper");
	if (ix == PRSDONE) return("prsdone");
	if (ix == IMPIDLE) return("impidle");
	if (ix == IMPORT) return("import");
	if (ix == ALRWDBEIER) return("alrwdbeier");
	if (ix == IMPDONE) return("impdone");
	if (ix == POSTPRC) return("postprc");
	if (ix == DONE) return("done");

	return("");
};

void DlgWdbeCvrDetcd::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 11; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class DlgWdbeCvrDetcd::ContIac
 ******************************************************************************/

DlgWdbeCvrDetcd::ContIac::ContIac(
			const uint numFDse
		) :
			Block()
		{
	this->numFDse = numFDse;

	mask = {NUMFDSE};
};

bool DlgWdbeCvrDetcd::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacDlgWdbeCvrDetcd"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFDse")) {numFDse = me["numFDse"].asUInt(); add(NUMFDSE);};
	};

	return basefound;
};

bool DlgWdbeCvrDetcd::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgWdbeCvrDetcd");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgWdbeCvrDetcd";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDse", numFDse)) add(NUMFDSE);
	};

	return basefound;
};

void DlgWdbeCvrDetcd::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWdbeCvrDetcd";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFDse"] = (Json::Value::UInt) numFDse;
};

void DlgWdbeCvrDetcd::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWdbeCvrDetcd";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgWdbeCvrDetcd";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFDse", numFDse);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeCvrDetcd::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFDse == comp->numFDse) insert(items, NUMFDSE);

	return(items);
};

set<uint> DlgWdbeCvrDetcd::ContIac::diff(
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
 class DlgWdbeCvrDetcd::ContInf
 ******************************************************************************/

DlgWdbeCvrDetcd::ContInf::ContInf(
			const uint numFSge
		) :
			Block()
		{
	this->numFSge = numFSge;

	mask = {NUMFSGE};
};

void DlgWdbeCvrDetcd::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWdbeCvrDetcd";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFSge"] = (Json::Value::UInt) numFSge;
};

void DlgWdbeCvrDetcd::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWdbeCvrDetcd";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWdbeCvrDetcd";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeCvrDetcd::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);

	return(items);
};

set<uint> DlgWdbeCvrDetcd::ContInf::diff(
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
 class DlgWdbeCvrDetcd::ContInfImp
 ******************************************************************************/

DlgWdbeCvrDetcd::ContInfImp::ContInfImp(
			const string& TxtPrg
		) :
			Block()
		{
	this->TxtPrg = TxtPrg;

	mask = {TXTPRG};
};

void DlgWdbeCvrDetcd::ContInfImp::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWdbeCvrDetcdImp";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtPrg"] = TxtPrg;
};

void DlgWdbeCvrDetcd::ContInfImp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWdbeCvrDetcdImp";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWdbeCvrDetcdImp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtPrg", TxtPrg);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeCvrDetcd::ContInfImp::comm(
			const ContInfImp* comp
		) {
	set<uint> items;

	if (TxtPrg == comp->TxtPrg) insert(items, TXTPRG);

	return(items);
};

set<uint> DlgWdbeCvrDetcd::ContInfImp::diff(
			const ContInfImp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTPRG};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeCvrDetcd::ContInfLfi
 ******************************************************************************/

DlgWdbeCvrDetcd::ContInfLfi::ContInfLfi(
			const string& Dld
		) :
			Block()
		{
	this->Dld = Dld;

	mask = {DLD};
};

void DlgWdbeCvrDetcd::ContInfLfi::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWdbeCvrDetcdLfi";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["Dld"] = Dld;
};

void DlgWdbeCvrDetcd::ContInfLfi::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWdbeCvrDetcdLfi";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWdbeCvrDetcdLfi";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "Dld", Dld);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeCvrDetcd::ContInfLfi::comm(
			const ContInfLfi* comp
		) {
	set<uint> items;

	if (Dld == comp->Dld) insert(items, DLD);

	return(items);
};

set<uint> DlgWdbeCvrDetcd::ContInfLfi::diff(
			const ContInfLfi* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {DLD};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeCvrDetcd::ContInfPpr
 ******************************************************************************/

DlgWdbeCvrDetcd::ContInfPpr::ContInfPpr(
			const string& TxtPrg
		) :
			Block()
		{
	this->TxtPrg = TxtPrg;

	mask = {TXTPRG};
};

void DlgWdbeCvrDetcd::ContInfPpr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWdbeCvrDetcdPpr";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtPrg"] = TxtPrg;
};

void DlgWdbeCvrDetcd::ContInfPpr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWdbeCvrDetcdPpr";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWdbeCvrDetcdPpr";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtPrg", TxtPrg);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeCvrDetcd::ContInfPpr::comm(
			const ContInfPpr* comp
		) {
	set<uint> items;

	if (TxtPrg == comp->TxtPrg) insert(items, TXTPRG);

	return(items);
};

set<uint> DlgWdbeCvrDetcd::ContInfPpr::diff(
			const ContInfPpr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTPRG};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeCvrDetcd::StatApp
 ******************************************************************************/

void DlgWdbeCvrDetcd::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const bool initdone
			, const string& shortMenu
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgWdbeCvrDetcd";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["initdone"] = initdone;
	me["shortMenu"] = shortMenu;
};

void DlgWdbeCvrDetcd::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdone
			, const string& shortMenu
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgWdbeCvrDetcd";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppDlgWdbeCvrDetcd";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdone", initdone);
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeCvrDetcd::StatShr
 ******************************************************************************/

DlgWdbeCvrDetcd::StatShr::StatShr(
			const bool ButDneActive
		) :
			Block()
		{
	this->ButDneActive = ButDneActive;

	mask = {BUTDNEACTIVE};
};

void DlgWdbeCvrDetcd::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWdbeCvrDetcd";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButDneActive"] = ButDneActive;
};

void DlgWdbeCvrDetcd::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWdbeCvrDetcd";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWdbeCvrDetcd";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButDneActive", ButDneActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeCvrDetcd::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButDneActive == comp->ButDneActive) insert(items, BUTDNEACTIVE);

	return(items);
};

set<uint> DlgWdbeCvrDetcd::StatShr::diff(
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
 class DlgWdbeCvrDetcd::StatShrIfi
 ******************************************************************************/

DlgWdbeCvrDetcd::StatShrIfi::StatShrIfi(
			const bool UldActive
		) :
			Block()
		{
	this->UldActive = UldActive;

	mask = {ULDACTIVE};
};

void DlgWdbeCvrDetcd::StatShrIfi::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWdbeCvrDetcdIfi";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["UldActive"] = UldActive;
};

void DlgWdbeCvrDetcd::StatShrIfi::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWdbeCvrDetcdIfi";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWdbeCvrDetcdIfi";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "UldActive", UldActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeCvrDetcd::StatShrIfi::comm(
			const StatShrIfi* comp
		) {
	set<uint> items;

	if (UldActive == comp->UldActive) insert(items, ULDACTIVE);

	return(items);
};

set<uint> DlgWdbeCvrDetcd::StatShrIfi::diff(
			const StatShrIfi* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {ULDACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeCvrDetcd::StatShrImp
 ******************************************************************************/

DlgWdbeCvrDetcd::StatShrImp::StatShrImp(
			const bool ButRunActive
			, const bool ButStoActive
		) :
			Block()
		{
	this->ButRunActive = ButRunActive;
	this->ButStoActive = ButStoActive;

	mask = {BUTRUNACTIVE, BUTSTOACTIVE};
};

void DlgWdbeCvrDetcd::StatShrImp::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWdbeCvrDetcdImp";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButRunActive"] = ButRunActive;
	me["ButStoActive"] = ButStoActive;
};

void DlgWdbeCvrDetcd::StatShrImp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWdbeCvrDetcdImp";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWdbeCvrDetcdImp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButRunActive", ButRunActive);
		writeBoolAttr(wr, itemtag, "sref", "ButStoActive", ButStoActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeCvrDetcd::StatShrImp::comm(
			const StatShrImp* comp
		) {
	set<uint> items;

	if (ButRunActive == comp->ButRunActive) insert(items, BUTRUNACTIVE);
	if (ButStoActive == comp->ButStoActive) insert(items, BUTSTOACTIVE);

	return(items);
};

set<uint> DlgWdbeCvrDetcd::StatShrImp::diff(
			const StatShrImp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTRUNACTIVE, BUTSTOACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeCvrDetcd::StatShrLfi
 ******************************************************************************/

DlgWdbeCvrDetcd::StatShrLfi::StatShrLfi(
			const bool DldActive
		) :
			Block()
		{
	this->DldActive = DldActive;

	mask = {DLDACTIVE};
};

void DlgWdbeCvrDetcd::StatShrLfi::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWdbeCvrDetcdLfi";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["DldActive"] = DldActive;
};

void DlgWdbeCvrDetcd::StatShrLfi::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWdbeCvrDetcdLfi";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWdbeCvrDetcdLfi";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "DldActive", DldActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeCvrDetcd::StatShrLfi::comm(
			const StatShrLfi* comp
		) {
	set<uint> items;

	if (DldActive == comp->DldActive) insert(items, DLDACTIVE);

	return(items);
};

set<uint> DlgWdbeCvrDetcd::StatShrLfi::diff(
			const StatShrLfi* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {DLDACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeCvrDetcd::StatShrPpr
 ******************************************************************************/

DlgWdbeCvrDetcd::StatShrPpr::StatShrPpr(
			const bool ButRunActive
			, const bool ButStoActive
		) :
			Block()
		{
	this->ButRunActive = ButRunActive;
	this->ButStoActive = ButStoActive;

	mask = {BUTRUNACTIVE, BUTSTOACTIVE};
};

void DlgWdbeCvrDetcd::StatShrPpr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWdbeCvrDetcdPpr";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButRunActive"] = ButRunActive;
	me["ButStoActive"] = ButStoActive;
};

void DlgWdbeCvrDetcd::StatShrPpr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWdbeCvrDetcdPpr";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWdbeCvrDetcdPpr";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButRunActive", ButRunActive);
		writeBoolAttr(wr, itemtag, "sref", "ButStoActive", ButStoActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeCvrDetcd::StatShrPpr::comm(
			const StatShrPpr* comp
		) {
	set<uint> items;

	if (ButRunActive == comp->ButRunActive) insert(items, BUTRUNACTIVE);
	if (ButStoActive == comp->ButStoActive) insert(items, BUTSTOACTIVE);

	return(items);
};

set<uint> DlgWdbeCvrDetcd::StatShrPpr::diff(
			const StatShrPpr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTRUNACTIVE, BUTSTOACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeCvrDetcd::Tag
 ******************************************************************************/

void DlgWdbeCvrDetcd::Tag::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagDlgWdbeCvrDetcd";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		me["Cpt"] = "Import detailed core description";
	};
	me["ButDne"] = StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DONE, ixWdbeVLocale));
};

void DlgWdbeCvrDetcd::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWdbeCvrDetcd";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWdbeCvrDetcd";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Import detailed core description");
		};
		writeStringAttr(wr, itemtag, "sref", "ButDne", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DONE, ixWdbeVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeCvrDetcd::TagIfi
 ******************************************************************************/

void DlgWdbeCvrDetcd::TagIfi::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagDlgWdbeCvrDetcdIfi";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
	};
	me["Uld"] = StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::UPLOAD, ixWdbeVLocale));
	me["Cpt"] = StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::FILENAME, ixWdbeVLocale));
};

void DlgWdbeCvrDetcd::TagIfi::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWdbeCvrDetcdIfi";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWdbeCvrDetcdIfi";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		};
		writeStringAttr(wr, itemtag, "sref", "Uld", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::UPLOAD, ixWdbeVLocale)));
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::FILENAME, ixWdbeVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeCvrDetcd::TagImp
 ******************************************************************************/

void DlgWdbeCvrDetcd::TagImp::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagDlgWdbeCvrDetcdImp";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
	};
	me["CptPrg"] = StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::PROGRESS, ixWdbeVLocale));
	me["ButRun"] = StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::RUN, ixWdbeVLocale));
	me["ButSto"] = StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::STOP, ixWdbeVLocale));
};

void DlgWdbeCvrDetcd::TagImp::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWdbeCvrDetcdImp";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWdbeCvrDetcdImp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		};
		writeStringAttr(wr, itemtag, "sref", "CptPrg", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::PROGRESS, ixWdbeVLocale)));
		writeStringAttr(wr, itemtag, "sref", "ButRun", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::RUN, ixWdbeVLocale)));
		writeStringAttr(wr, itemtag, "sref", "ButSto", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::STOP, ixWdbeVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeCvrDetcd::TagLfi
 ******************************************************************************/

void DlgWdbeCvrDetcd::TagLfi::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagDlgWdbeCvrDetcdLfi";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
	};
	me["Dld"] = StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DOWNLOAD, ixWdbeVLocale));
};

void DlgWdbeCvrDetcd::TagLfi::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWdbeCvrDetcdLfi";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWdbeCvrDetcdLfi";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		};
		writeStringAttr(wr, itemtag, "sref", "Dld", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DOWNLOAD, ixWdbeVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeCvrDetcd::TagPpr
 ******************************************************************************/

void DlgWdbeCvrDetcd::TagPpr::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagDlgWdbeCvrDetcdPpr";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
	};
	me["CptPrg"] = StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::PROGRESS, ixWdbeVLocale));
	me["ButRun"] = StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::RUN, ixWdbeVLocale));
	me["ButSto"] = StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::STOP, ixWdbeVLocale));
};

void DlgWdbeCvrDetcd::TagPpr::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWdbeCvrDetcdPpr";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWdbeCvrDetcdPpr";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		};
		writeStringAttr(wr, itemtag, "sref", "CptPrg", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::PROGRESS, ixWdbeVLocale)));
		writeStringAttr(wr, itemtag, "sref", "ButRun", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::RUN, ixWdbeVLocale)));
		writeStringAttr(wr, itemtag, "sref", "ButSto", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::STOP, ixWdbeVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeCvrDetcd::DpchAppData
 ******************************************************************************/

DlgWdbeCvrDetcd::DpchAppData::DpchAppData() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPDLGWDBECVRDETCDDATA)
		{
};

string DlgWdbeCvrDetcd::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbeCvrDetcd::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppDlgWdbeCvrDetcdData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void DlgWdbeCvrDetcd::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgWdbeCvrDetcdData");
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
 class DlgWdbeCvrDetcd::DpchAppDo
 ******************************************************************************/

DlgWdbeCvrDetcd::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPDLGWDBECVRDETCDDO)
		{
	ixVDo = 0;
	ixVDoImp = 0;
	ixVDoPpr = 0;
};

string DlgWdbeCvrDetcd::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");
	if (has(IXVDOIMP)) ss.push_back("ixVDoImp");
	if (has(IXVDOPPR)) ss.push_back("ixVDoPpr");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbeCvrDetcd::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppDlgWdbeCvrDetcdDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
		if (me.isMember("srefIxVDoImp")) {ixVDoImp = VecVDoImp::getIx(me["srefIxVDoImp"].asString()); add(IXVDOIMP);};
		if (me.isMember("srefIxVDoPpr")) {ixVDoPpr = VecVDoPpr::getIx(me["srefIxVDoPpr"].asString()); add(IXVDOPPR);};
	} else {
	};
};

void DlgWdbeCvrDetcd::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;
	string srefIxVDoImp;
	string srefIxVDoPpr;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgWdbeCvrDetcdDo");
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
		if (extractStringUclc(docctx, basexpath, "srefIxVDoImp", "", srefIxVDoImp)) {
			ixVDoImp = VecVDoImp::getIx(srefIxVDoImp);
			add(IXVDOIMP);
		};
		if (extractStringUclc(docctx, basexpath, "srefIxVDoPpr", "", srefIxVDoPpr)) {
			ixVDoPpr = VecVDoPpr::getIx(srefIxVDoPpr);
			add(IXVDOPPR);
		};
	} else {
	};
};

/******************************************************************************
 class DlgWdbeCvrDetcd::DpchEngData
 ******************************************************************************/

DlgWdbeCvrDetcd::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, ContInfImp* continfimp
			, ContInfLfi* continflfi
			, ContInfPpr* continfppr
			, Feed* feedFDse
			, Feed* feedFSge
			, StatShr* statshr
			, StatShrIfi* statshrifi
			, StatShrImp* statshrimp
			, StatShrLfi* statshrlfi
			, StatShrPpr* statshrppr
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGDLGWDBECVRDETCDDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, CONTINFIMP, CONTINFLFI, CONTINFPPR, FEEDFDSE, FEEDFSGE, STATAPP, STATSHR, STATSHRIFI, STATSHRIMP, STATSHRLFI, STATSHRPPR, TAG, TAGIFI, TAGIMP, TAGLFI, TAGPPR};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, CONTINFIMP) && continfimp) this->continfimp = *continfimp;
	if (find(this->mask, CONTINFLFI) && continflfi) this->continflfi = *continflfi;
	if (find(this->mask, CONTINFPPR) && continfppr) this->continfppr = *continfppr;
	if (find(this->mask, FEEDFDSE) && feedFDse) this->feedFDse = *feedFDse;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
	if (find(this->mask, STATSHRIFI) && statshrifi) this->statshrifi = *statshrifi;
	if (find(this->mask, STATSHRIMP) && statshrimp) this->statshrimp = *statshrimp;
	if (find(this->mask, STATSHRLFI) && statshrlfi) this->statshrlfi = *statshrlfi;
	if (find(this->mask, STATSHRPPR) && statshrppr) this->statshrppr = *statshrppr;
};

string DlgWdbeCvrDetcd::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(CONTINFIMP)) ss.push_back("continfimp");
	if (has(CONTINFLFI)) ss.push_back("continflfi");
	if (has(CONTINFPPR)) ss.push_back("continfppr");
	if (has(FEEDFDSE)) ss.push_back("feedFDse");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(STATSHRIFI)) ss.push_back("statshrifi");
	if (has(STATSHRIMP)) ss.push_back("statshrimp");
	if (has(STATSHRLFI)) ss.push_back("statshrlfi");
	if (has(STATSHRPPR)) ss.push_back("statshrppr");
	if (has(TAG)) ss.push_back("tag");
	if (has(TAGIFI)) ss.push_back("tagifi");
	if (has(TAGIMP)) ss.push_back("tagimp");
	if (has(TAGLFI)) ss.push_back("taglfi");
	if (has(TAGPPR)) ss.push_back("tagppr");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbeCvrDetcd::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(CONTINFIMP)) {continfimp = src->continfimp; add(CONTINFIMP);};
	if (src->has(CONTINFLFI)) {continflfi = src->continflfi; add(CONTINFLFI);};
	if (src->has(CONTINFPPR)) {continfppr = src->continfppr; add(CONTINFPPR);};
	if (src->has(FEEDFDSE)) {feedFDse = src->feedFDse; add(FEEDFDSE);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(STATSHRIFI)) {statshrifi = src->statshrifi; add(STATSHRIFI);};
	if (src->has(STATSHRIMP)) {statshrimp = src->statshrimp; add(STATSHRIMP);};
	if (src->has(STATSHRLFI)) {statshrlfi = src->statshrlfi; add(STATSHRLFI);};
	if (src->has(STATSHRPPR)) {statshrppr = src->statshrppr; add(STATSHRPPR);};
	if (src->has(TAG)) add(TAG);
	if (src->has(TAGIFI)) add(TAGIFI);
	if (src->has(TAGIMP)) add(TAGIMP);
	if (src->has(TAGLFI)) add(TAGLFI);
	if (src->has(TAGPPR)) add(TAGPPR);
};

void DlgWdbeCvrDetcd::DpchEngData::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngDlgWdbeCvrDetcdData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(CONTINFIMP)) continfimp.writeJSON(me);
	if (has(CONTINFLFI)) continflfi.writeJSON(me);
	if (has(CONTINFPPR)) continfppr.writeJSON(me);
	if (has(FEEDFDSE)) feedFDse.writeJSON(me);
	if (has(FEEDFSGE)) feedFSge.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(STATSHRIFI)) statshrifi.writeJSON(me);
	if (has(STATSHRIMP)) statshrimp.writeJSON(me);
	if (has(STATSHRLFI)) statshrlfi.writeJSON(me);
	if (has(STATSHRPPR)) statshrppr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWdbeVLocale, me);
	if (has(TAGIFI)) TagIfi::writeJSON(ixWdbeVLocale, me);
	if (has(TAGIMP)) TagImp::writeJSON(ixWdbeVLocale, me);
	if (has(TAGLFI)) TagLfi::writeJSON(ixWdbeVLocale, me);
	if (has(TAGPPR)) TagPpr::writeJSON(ixWdbeVLocale, me);
};

void DlgWdbeCvrDetcd::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngDlgWdbeCvrDetcdData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(CONTINFIMP)) continfimp.writeXML(wr);
		if (has(CONTINFLFI)) continflfi.writeXML(wr);
		if (has(CONTINFPPR)) continfppr.writeXML(wr);
		if (has(FEEDFDSE)) feedFDse.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STATSHRIFI)) statshrifi.writeXML(wr);
		if (has(STATSHRIMP)) statshrimp.writeXML(wr);
		if (has(STATSHRLFI)) statshrlfi.writeXML(wr);
		if (has(STATSHRPPR)) statshrppr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
		if (has(TAGIFI)) TagIfi::writeXML(ixWdbeVLocale, wr);
		if (has(TAGIMP)) TagImp::writeXML(ixWdbeVLocale, wr);
		if (has(TAGLFI)) TagLfi::writeXML(ixWdbeVLocale, wr);
		if (has(TAGPPR)) TagPpr::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};
