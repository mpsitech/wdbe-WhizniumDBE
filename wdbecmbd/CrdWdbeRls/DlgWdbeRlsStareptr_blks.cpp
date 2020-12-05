/**
	* \file DlgWdbeRlsStareptr_blks.cpp
	* job handler for job DlgWdbeRlsStareptr (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DlgWdbeRlsStareptr::VecVDit
 ******************************************************************************/

uint DlgWdbeRlsStareptr::VecVDit::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "det") return DET;
	if (s == "ini") return INI;
	if (s == "ext") return EXT;
	if (s == "lfi") return LFI;

	return(0);
};

string DlgWdbeRlsStareptr::VecVDit::getSref(
			const uint ix
		) {
	if (ix == DET) return("Det");
	if (ix == INI) return("Ini");
	if (ix == EXT) return("Ext");
	if (ix == LFI) return("Lfi");

	return("");
};

string DlgWdbeRlsStareptr::VecVDit::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == DET) return("Details");
		if (ix == INI) return("Initialization");
		if (ix == EXT) return("Code extraction");
		if (ix == LFI) return("Log file");
		return(getSref(ix));
	};

	return("");
};

void DlgWdbeRlsStareptr::VecVDit::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 4; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};

/******************************************************************************
 class DlgWdbeRlsStareptr::VecVDo
 ******************************************************************************/

uint DlgWdbeRlsStareptr::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butdneclick") return BUTDNECLICK;

	return(0);
};

string DlgWdbeRlsStareptr::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgWdbeRlsStareptr::VecVDoDet
 ******************************************************************************/

uint DlgWdbeRlsStareptr::VecVDoDet::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butstaclick") return BUTSTACLICK;

	return(0);
};

string DlgWdbeRlsStareptr::VecVDoDet::getSref(
			const uint ix
		) {
	if (ix == BUTSTACLICK) return("ButStaClick");

	return("");
};

/******************************************************************************
 class DlgWdbeRlsStareptr::VecVDoExt
 ******************************************************************************/

uint DlgWdbeRlsStareptr::VecVDoExt::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butrunclick") return BUTRUNCLICK;
	if (s == "butstoclick") return BUTSTOCLICK;

	return(0);
};

string DlgWdbeRlsStareptr::VecVDoExt::getSref(
			const uint ix
		) {
	if (ix == BUTRUNCLICK) return("ButRunClick");
	if (ix == BUTSTOCLICK) return("ButStoClick");

	return("");
};

/******************************************************************************
 class DlgWdbeRlsStareptr::VecVDoIni
 ******************************************************************************/

uint DlgWdbeRlsStareptr::VecVDoIni::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butclgclick") return BUTCLGCLICK;

	return(0);
};

string DlgWdbeRlsStareptr::VecVDoIni::getSref(
			const uint ix
		) {
	if (ix == BUTCLGCLICK) return("ButClgClick");

	return("");
};

/******************************************************************************
 class DlgWdbeRlsStareptr::VecVSge
 ******************************************************************************/

uint DlgWdbeRlsStareptr::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "alrgnf") return ALRGNF;
	if (s == "alrgad") return ALRGAD;
	if (s == "alrgve") return ALRGVE;
	if (s == "alrxer") return ALRXER;
	if (s == "stadone") return STADONE;
	if (s == "upkidle") return UPKIDLE;
	if (s == "unpack") return UNPACK;
	if (s == "upkdone") return UPKDONE;
	if (s == "clgidle") return CLGIDLE;
	if (s == "clonegit") return CLONEGIT;
	if (s == "clgdone") return CLGDONE;
	if (s == "extract") return EXTRACT;
	if (s == "pack") return PACK;
	if (s == "fail") return FAIL;
	if (s == "done") return DONE;

	return(0);
};

string DlgWdbeRlsStareptr::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRGNF) return("alrgnf");
	if (ix == ALRGAD) return("alrgad");
	if (ix == ALRGVE) return("alrgve");
	if (ix == ALRXER) return("alrxer");
	if (ix == STADONE) return("stadone");
	if (ix == UPKIDLE) return("upkidle");
	if (ix == UNPACK) return("unpack");
	if (ix == UPKDONE) return("upkdone");
	if (ix == CLGIDLE) return("clgidle");
	if (ix == CLONEGIT) return("clonegit");
	if (ix == CLGDONE) return("clgdone");
	if (ix == EXTRACT) return("extract");
	if (ix == PACK) return("pack");
	if (ix == FAIL) return("fail");
	if (ix == DONE) return("done");

	return("");
};

void DlgWdbeRlsStareptr::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 16; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class DlgWdbeRlsStareptr::ContIac
 ******************************************************************************/

DlgWdbeRlsStareptr::ContIac::ContIac(
			const uint numFDse
		) :
			Block()
		{
	this->numFDse = numFDse;

	mask = {NUMFDSE};
};

bool DlgWdbeRlsStareptr::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgWdbeRlsStareptr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgWdbeRlsStareptr";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDse", numFDse)) add(NUMFDSE);
	};

	return basefound;
};

void DlgWdbeRlsStareptr::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWdbeRlsStareptr";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgWdbeRlsStareptr";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFDse", numFDse);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeRlsStareptr::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFDse == comp->numFDse) insert(items, NUMFDSE);

	return(items);
};

set<uint> DlgWdbeRlsStareptr::ContIac::diff(
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
 class DlgWdbeRlsStareptr::ContIacDet
 ******************************************************************************/

DlgWdbeRlsStareptr::ContIacDet::ContIacDet(
			const uint numFRbuBrt
			, const string& TxfGrl
		) :
			Block()
		{
	this->numFRbuBrt = numFRbuBrt;
	this->TxfGrl = TxfGrl;

	mask = {NUMFRBUBRT, TXFGRL};
};

bool DlgWdbeRlsStareptr::ContIacDet::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgWdbeRlsStareptrDet");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgWdbeRlsStareptrDet";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFRbuBrt", numFRbuBrt)) add(NUMFRBUBRT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfGrl", TxfGrl)) add(TXFGRL);
	};

	return basefound;
};

void DlgWdbeRlsStareptr::ContIacDet::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWdbeRlsStareptrDet";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgWdbeRlsStareptrDet";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFRbuBrt", numFRbuBrt);
		writeStringAttr(wr, itemtag, "sref", "TxfGrl", TxfGrl);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeRlsStareptr::ContIacDet::comm(
			const ContIacDet* comp
		) {
	set<uint> items;

	if (numFRbuBrt == comp->numFRbuBrt) insert(items, NUMFRBUBRT);
	if (TxfGrl == comp->TxfGrl) insert(items, TXFGRL);

	return(items);
};

set<uint> DlgWdbeRlsStareptr::ContIacDet::diff(
			const ContIacDet* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFRBUBRT, TXFGRL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeRlsStareptr::ContInf
 ******************************************************************************/

DlgWdbeRlsStareptr::ContInf::ContInf(
			const uint numFSge
		) :
			Block()
		{
	this->numFSge = numFSge;

	mask = {NUMFSGE};
};

void DlgWdbeRlsStareptr::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWdbeRlsStareptr";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWdbeRlsStareptr";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeRlsStareptr::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);

	return(items);
};

set<uint> DlgWdbeRlsStareptr::ContInf::diff(
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
 class DlgWdbeRlsStareptr::ContInfExt
 ******************************************************************************/

DlgWdbeRlsStareptr::ContInfExt::ContInfExt(
			const string& TxtPrg
		) :
			Block()
		{
	this->TxtPrg = TxtPrg;

	mask = {TXTPRG};
};

void DlgWdbeRlsStareptr::ContInfExt::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWdbeRlsStareptrExt";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWdbeRlsStareptrExt";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtPrg", TxtPrg);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeRlsStareptr::ContInfExt::comm(
			const ContInfExt* comp
		) {
	set<uint> items;

	if (TxtPrg == comp->TxtPrg) insert(items, TXTPRG);

	return(items);
};

set<uint> DlgWdbeRlsStareptr::ContInfExt::diff(
			const ContInfExt* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTPRG};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeRlsStareptr::ContInfIni
 ******************************************************************************/

DlgWdbeRlsStareptr::ContInfIni::ContInfIni(
			const string& TxtPrg
		) :
			Block()
		{
	this->TxtPrg = TxtPrg;

	mask = {TXTPRG};
};

void DlgWdbeRlsStareptr::ContInfIni::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWdbeRlsStareptrIni";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWdbeRlsStareptrIni";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtPrg", TxtPrg);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeRlsStareptr::ContInfIni::comm(
			const ContInfIni* comp
		) {
	set<uint> items;

	if (TxtPrg == comp->TxtPrg) insert(items, TXTPRG);

	return(items);
};

set<uint> DlgWdbeRlsStareptr::ContInfIni::diff(
			const ContInfIni* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTPRG};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeRlsStareptr::ContInfLfi
 ******************************************************************************/

DlgWdbeRlsStareptr::ContInfLfi::ContInfLfi(
			const string& Dld
		) :
			Block()
		{
	this->Dld = Dld;

	mask = {DLD};
};

void DlgWdbeRlsStareptr::ContInfLfi::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWdbeRlsStareptrLfi";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWdbeRlsStareptrLfi";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "Dld", Dld);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeRlsStareptr::ContInfLfi::comm(
			const ContInfLfi* comp
		) {
	set<uint> items;

	if (Dld == comp->Dld) insert(items, DLD);

	return(items);
};

set<uint> DlgWdbeRlsStareptr::ContInfLfi::diff(
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
 class DlgWdbeRlsStareptr::StatApp
 ******************************************************************************/

void DlgWdbeRlsStareptr::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdone
			, const string& shortMenu
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgWdbeRlsStareptr";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppDlgWdbeRlsStareptr";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdone", initdone);
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeRlsStareptr::StatShr
 ******************************************************************************/

DlgWdbeRlsStareptr::StatShr::StatShr(
			const bool ButDneActive
		) :
			Block()
		{
	this->ButDneActive = ButDneActive;

	mask = {BUTDNEACTIVE};
};

void DlgWdbeRlsStareptr::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWdbeRlsStareptr";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWdbeRlsStareptr";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButDneActive", ButDneActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeRlsStareptr::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButDneActive == comp->ButDneActive) insert(items, BUTDNEACTIVE);

	return(items);
};

set<uint> DlgWdbeRlsStareptr::StatShr::diff(
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
 class DlgWdbeRlsStareptr::StatShrDet
 ******************************************************************************/

DlgWdbeRlsStareptr::StatShrDet::StatShrDet(
			const bool TxfGrlAvail
			, const bool ButStaActive
		) :
			Block()
		{
	this->TxfGrlAvail = TxfGrlAvail;
	this->ButStaActive = ButStaActive;

	mask = {TXFGRLAVAIL, BUTSTAACTIVE};
};

void DlgWdbeRlsStareptr::StatShrDet::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWdbeRlsStareptrDet";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWdbeRlsStareptrDet";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "TxfGrlAvail", TxfGrlAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButStaActive", ButStaActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeRlsStareptr::StatShrDet::comm(
			const StatShrDet* comp
		) {
	set<uint> items;

	if (TxfGrlAvail == comp->TxfGrlAvail) insert(items, TXFGRLAVAIL);
	if (ButStaActive == comp->ButStaActive) insert(items, BUTSTAACTIVE);

	return(items);
};

set<uint> DlgWdbeRlsStareptr::StatShrDet::diff(
			const StatShrDet* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFGRLAVAIL, BUTSTAACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeRlsStareptr::StatShrExt
 ******************************************************************************/

DlgWdbeRlsStareptr::StatShrExt::StatShrExt(
			const bool ButRunActive
			, const bool ButStoActive
		) :
			Block()
		{
	this->ButRunActive = ButRunActive;
	this->ButStoActive = ButStoActive;

	mask = {BUTRUNACTIVE, BUTSTOACTIVE};
};

void DlgWdbeRlsStareptr::StatShrExt::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWdbeRlsStareptrExt";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWdbeRlsStareptrExt";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButRunActive", ButRunActive);
		writeBoolAttr(wr, itemtag, "sref", "ButStoActive", ButStoActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeRlsStareptr::StatShrExt::comm(
			const StatShrExt* comp
		) {
	set<uint> items;

	if (ButRunActive == comp->ButRunActive) insert(items, BUTRUNACTIVE);
	if (ButStoActive == comp->ButStoActive) insert(items, BUTSTOACTIVE);

	return(items);
};

set<uint> DlgWdbeRlsStareptr::StatShrExt::diff(
			const StatShrExt* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTRUNACTIVE, BUTSTOACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeRlsStareptr::StatShrIni
 ******************************************************************************/

DlgWdbeRlsStareptr::StatShrIni::StatShrIni(
			const bool UldAvail
			, const bool UldActive
			, const bool TxtPrgAvail
			, const bool Sep1Avail
			, const bool ButClgAvail
			, const bool ButClgActive
		) :
			Block()
		{
	this->UldAvail = UldAvail;
	this->UldActive = UldActive;
	this->TxtPrgAvail = TxtPrgAvail;
	this->Sep1Avail = Sep1Avail;
	this->ButClgAvail = ButClgAvail;
	this->ButClgActive = ButClgActive;

	mask = {ULDAVAIL, ULDACTIVE, TXTPRGAVAIL, SEP1AVAIL, BUTCLGAVAIL, BUTCLGACTIVE};
};

void DlgWdbeRlsStareptr::StatShrIni::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWdbeRlsStareptrIni";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWdbeRlsStareptrIni";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "UldAvail", UldAvail);
		writeBoolAttr(wr, itemtag, "sref", "UldActive", UldActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtPrgAvail", TxtPrgAvail);
		writeBoolAttr(wr, itemtag, "sref", "Sep1Avail", Sep1Avail);
		writeBoolAttr(wr, itemtag, "sref", "ButClgAvail", ButClgAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButClgActive", ButClgActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeRlsStareptr::StatShrIni::comm(
			const StatShrIni* comp
		) {
	set<uint> items;

	if (UldAvail == comp->UldAvail) insert(items, ULDAVAIL);
	if (UldActive == comp->UldActive) insert(items, ULDACTIVE);
	if (TxtPrgAvail == comp->TxtPrgAvail) insert(items, TXTPRGAVAIL);
	if (Sep1Avail == comp->Sep1Avail) insert(items, SEP1AVAIL);
	if (ButClgAvail == comp->ButClgAvail) insert(items, BUTCLGAVAIL);
	if (ButClgActive == comp->ButClgActive) insert(items, BUTCLGACTIVE);

	return(items);
};

set<uint> DlgWdbeRlsStareptr::StatShrIni::diff(
			const StatShrIni* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {ULDAVAIL, ULDACTIVE, TXTPRGAVAIL, SEP1AVAIL, BUTCLGAVAIL, BUTCLGACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeRlsStareptr::StatShrLfi
 ******************************************************************************/

DlgWdbeRlsStareptr::StatShrLfi::StatShrLfi(
			const bool DldActive
		) :
			Block()
		{
	this->DldActive = DldActive;

	mask = {DLDACTIVE};
};

void DlgWdbeRlsStareptr::StatShrLfi::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWdbeRlsStareptrLfi";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWdbeRlsStareptrLfi";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "DldActive", DldActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeRlsStareptr::StatShrLfi::comm(
			const StatShrLfi* comp
		) {
	set<uint> items;

	if (DldActive == comp->DldActive) insert(items, DLDACTIVE);

	return(items);
};

set<uint> DlgWdbeRlsStareptr::StatShrLfi::diff(
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
 class DlgWdbeRlsStareptr::Tag
 ******************************************************************************/

void DlgWdbeRlsStareptr::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWdbeRlsStareptr";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWdbeRlsStareptr";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Start repository transaction");
		};
		writeStringAttr(wr, itemtag, "sref", "ButDne", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DONE, ixWdbeVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeRlsStareptr::TagDet
 ******************************************************************************/

void DlgWdbeRlsStareptr::TagDet::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWdbeRlsStareptrDet";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWdbeRlsStareptrDet";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptBrt", "Base repository type");
			writeStringAttr(wr, itemtag, "sref", "CptGrl", "Git URL");
			writeStringAttr(wr, itemtag, "sref", "ButSta", "Start");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeRlsStareptr::TagExt
 ******************************************************************************/

void DlgWdbeRlsStareptr::TagExt::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWdbeRlsStareptrExt";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWdbeRlsStareptrExt";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		};
		writeStringAttr(wr, itemtag, "sref", "CptPrg", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::PROGRESS, ixWdbeVLocale)));
		writeStringAttr(wr, itemtag, "sref", "ButRun", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::RUN, ixWdbeVLocale)));
		writeStringAttr(wr, itemtag, "sref", "ButSto", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::STOP, ixWdbeVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeRlsStareptr::TagIni
 ******************************************************************************/

void DlgWdbeRlsStareptr::TagIni::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWdbeRlsStareptrIni";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWdbeRlsStareptrIni";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "ButClg", "Clone Git");
		};
		writeStringAttr(wr, itemtag, "sref", "Uld", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::UPLOAD, ixWdbeVLocale)));
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::FILENAME, ixWdbeVLocale)));
		writeStringAttr(wr, itemtag, "sref", "CptPrg", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::PROGRESS, ixWdbeVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeRlsStareptr::TagLfi
 ******************************************************************************/

void DlgWdbeRlsStareptr::TagLfi::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWdbeRlsStareptrLfi";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWdbeRlsStareptrLfi";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		};
		writeStringAttr(wr, itemtag, "sref", "Dld", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DOWNLOAD, ixWdbeVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeRlsStareptr::DpchAppData
 ******************************************************************************/

DlgWdbeRlsStareptr::DpchAppData::DpchAppData() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPDLGWDBERLSSTAREPTRDATA)
		{
};

string DlgWdbeRlsStareptr::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTIACDET)) ss.push_back("contiacdet");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbeRlsStareptr::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgWdbeRlsStareptrData");
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
 class DlgWdbeRlsStareptr::DpchAppDo
 ******************************************************************************/

DlgWdbeRlsStareptr::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPDLGWDBERLSSTAREPTRDO)
		{
	ixVDo = 0;
	ixVDoDet = 0;
	ixVDoExt = 0;
	ixVDoIni = 0;
};

string DlgWdbeRlsStareptr::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");
	if (has(IXVDODET)) ss.push_back("ixVDoDet");
	if (has(IXVDOEXT)) ss.push_back("ixVDoExt");
	if (has(IXVDOINI)) ss.push_back("ixVDoIni");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbeRlsStareptr::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;
	string srefIxVDoDet;
	string srefIxVDoExt;
	string srefIxVDoIni;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgWdbeRlsStareptrDo");
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
		if (extractStringUclc(docctx, basexpath, "srefIxVDoExt", "", srefIxVDoExt)) {
			ixVDoExt = VecVDoExt::getIx(srefIxVDoExt);
			add(IXVDOEXT);
		};
		if (extractStringUclc(docctx, basexpath, "srefIxVDoIni", "", srefIxVDoIni)) {
			ixVDoIni = VecVDoIni::getIx(srefIxVDoIni);
			add(IXVDOINI);
		};
	} else {
	};
};

/******************************************************************************
 class DlgWdbeRlsStareptr::DpchEngData
 ******************************************************************************/

DlgWdbeRlsStareptr::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContIacDet* contiacdet
			, ContInf* continf
			, ContInfExt* continfext
			, ContInfIni* continfini
			, ContInfLfi* continflfi
			, Feed* feedFDetRbuBrt
			, Feed* feedFDse
			, Feed* feedFSge
			, StatShr* statshr
			, StatShrDet* statshrdet
			, StatShrExt* statshrext
			, StatShrIni* statshrini
			, StatShrLfi* statshrlfi
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGDLGWDBERLSSTAREPTRDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTIACDET, CONTINF, CONTINFEXT, CONTINFINI, CONTINFLFI, FEEDFDETRBUBRT, FEEDFDSE, FEEDFSGE, STATAPP, STATSHR, STATSHRDET, STATSHREXT, STATSHRINI, STATSHRLFI, TAG, TAGDET, TAGEXT, TAGINI, TAGLFI};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTIACDET) && contiacdet) this->contiacdet = *contiacdet;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, CONTINFEXT) && continfext) this->continfext = *continfext;
	if (find(this->mask, CONTINFINI) && continfini) this->continfini = *continfini;
	if (find(this->mask, CONTINFLFI) && continflfi) this->continflfi = *continflfi;
	if (find(this->mask, FEEDFDETRBUBRT) && feedFDetRbuBrt) this->feedFDetRbuBrt = *feedFDetRbuBrt;
	if (find(this->mask, FEEDFDSE) && feedFDse) this->feedFDse = *feedFDse;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
	if (find(this->mask, STATSHRDET) && statshrdet) this->statshrdet = *statshrdet;
	if (find(this->mask, STATSHREXT) && statshrext) this->statshrext = *statshrext;
	if (find(this->mask, STATSHRINI) && statshrini) this->statshrini = *statshrini;
	if (find(this->mask, STATSHRLFI) && statshrlfi) this->statshrlfi = *statshrlfi;
};

string DlgWdbeRlsStareptr::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTIACDET)) ss.push_back("contiacdet");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(CONTINFEXT)) ss.push_back("continfext");
	if (has(CONTINFINI)) ss.push_back("continfini");
	if (has(CONTINFLFI)) ss.push_back("continflfi");
	if (has(FEEDFDETRBUBRT)) ss.push_back("feedFDetRbuBrt");
	if (has(FEEDFDSE)) ss.push_back("feedFDse");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(STATSHRDET)) ss.push_back("statshrdet");
	if (has(STATSHREXT)) ss.push_back("statshrext");
	if (has(STATSHRINI)) ss.push_back("statshrini");
	if (has(STATSHRLFI)) ss.push_back("statshrlfi");
	if (has(TAG)) ss.push_back("tag");
	if (has(TAGDET)) ss.push_back("tagdet");
	if (has(TAGEXT)) ss.push_back("tagext");
	if (has(TAGINI)) ss.push_back("tagini");
	if (has(TAGLFI)) ss.push_back("taglfi");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbeRlsStareptr::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTIACDET)) {contiacdet = src->contiacdet; add(CONTIACDET);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(CONTINFEXT)) {continfext = src->continfext; add(CONTINFEXT);};
	if (src->has(CONTINFINI)) {continfini = src->continfini; add(CONTINFINI);};
	if (src->has(CONTINFLFI)) {continflfi = src->continflfi; add(CONTINFLFI);};
	if (src->has(FEEDFDETRBUBRT)) {feedFDetRbuBrt = src->feedFDetRbuBrt; add(FEEDFDETRBUBRT);};
	if (src->has(FEEDFDSE)) {feedFDse = src->feedFDse; add(FEEDFDSE);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(STATSHRDET)) {statshrdet = src->statshrdet; add(STATSHRDET);};
	if (src->has(STATSHREXT)) {statshrext = src->statshrext; add(STATSHREXT);};
	if (src->has(STATSHRINI)) {statshrini = src->statshrini; add(STATSHRINI);};
	if (src->has(STATSHRLFI)) {statshrlfi = src->statshrlfi; add(STATSHRLFI);};
	if (src->has(TAG)) add(TAG);
	if (src->has(TAGDET)) add(TAGDET);
	if (src->has(TAGEXT)) add(TAGEXT);
	if (src->has(TAGINI)) add(TAGINI);
	if (src->has(TAGLFI)) add(TAGLFI);
};

void DlgWdbeRlsStareptr::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngDlgWdbeRlsStareptrData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTIACDET)) contiacdet.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(CONTINFEXT)) continfext.writeXML(wr);
		if (has(CONTINFINI)) continfini.writeXML(wr);
		if (has(CONTINFLFI)) continflfi.writeXML(wr);
		if (has(FEEDFDETRBUBRT)) feedFDetRbuBrt.writeXML(wr);
		if (has(FEEDFDSE)) feedFDse.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STATSHRDET)) statshrdet.writeXML(wr);
		if (has(STATSHREXT)) statshrext.writeXML(wr);
		if (has(STATSHRINI)) statshrini.writeXML(wr);
		if (has(STATSHRLFI)) statshrlfi.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
		if (has(TAGDET)) TagDet::writeXML(ixWdbeVLocale, wr);
		if (has(TAGEXT)) TagExt::writeXML(ixWdbeVLocale, wr);
		if (has(TAGINI)) TagIni::writeXML(ixWdbeVLocale, wr);
		if (has(TAGLFI)) TagLfi::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};



