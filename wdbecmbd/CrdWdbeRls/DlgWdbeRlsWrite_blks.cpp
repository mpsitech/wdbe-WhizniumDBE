/**
	* \file DlgWdbeRlsWrite_blks.cpp
	* job handler for job DlgWdbeRlsWrite (implementation of blocks)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DlgWdbeRlsWrite::VecVDit
 ******************************************************************************/

uint DlgWdbeRlsWrite::VecVDit::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "det") return DET;
	if (s == "cuc") return CUC;
	if (s == "wrc") return WRC;
	if (s == "lfi") return LFI;
	if (s == "fia") return FIA;

	return(0);
};

string DlgWdbeRlsWrite::VecVDit::getSref(
			const uint ix
		) {
	if (ix == DET) return("Det");
	if (ix == CUC) return("Cuc");
	if (ix == WRC) return("Wrc");
	if (ix == LFI) return("Lfi");
	if (ix == FIA) return("Fia");

	return("");
};

string DlgWdbeRlsWrite::VecVDit::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == DET) return("Details");
		if (ix == CUC) return("Custom code");
		if (ix == WRC) return("Writing");
		if (ix == LFI) return("Log file");
		if (ix == FIA) return("File archive");
		return(getSref(ix));
	};

	return("");
};

void DlgWdbeRlsWrite::VecVDit::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 5; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};

/******************************************************************************
 class DlgWdbeRlsWrite::VecVDo
 ******************************************************************************/

uint DlgWdbeRlsWrite::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butdneclick") return BUTDNECLICK;

	return(0);
};

string DlgWdbeRlsWrite::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgWdbeRlsWrite::VecVDoWrc
 ******************************************************************************/

uint DlgWdbeRlsWrite::VecVDoWrc::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butautclick") return BUTAUTCLICK;
	if (s == "butrunclick") return BUTRUNCLICK;
	if (s == "butstoclick") return BUTSTOCLICK;

	return(0);
};

string DlgWdbeRlsWrite::VecVDoWrc::getSref(
			const uint ix
		) {
	if (ix == BUTAUTCLICK) return("ButAutClick");
	if (ix == BUTRUNCLICK) return("ButRunClick");
	if (ix == BUTSTOCLICK) return("ButStoClick");

	return("");
};

/******************************************************************************
 class DlgWdbeRlsWrite::VecVSge
 ******************************************************************************/

uint DlgWdbeRlsWrite::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "alraer") return ALRAER;
	if (s == "alrmer") return ALRMER;
	if (s == "upkidle") return UPKIDLE;
	if (s == "unpack") return UNPACK;
	if (s == "upkdone") return UPKDONE;
	if (s == "auth") return AUTH;
	if (s == "autdone") return AUTDONE;
	if (s == "fillplh") return FILLPLH;
	if (s == "create") return CREATE;
	if (s == "write") return WRITE;
	if (s == "mrg") return MRG;
	if (s == "mrgfine") return MRGFINE;
	if (s == "mrgtypspec") return MRGTYPSPEC;
	if (s == "mrgtplspec") return MRGTPLSPEC;
	if (s == "clrspec") return CLRSPEC;
	if (s == "mrgcust") return MRGCUST;
	if (s == "pack") return PACK;
	if (s == "fail") return FAIL;
	if (s == "done") return DONE;

	return(0);
};

string DlgWdbeRlsWrite::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRAER) return("alraer");
	if (ix == ALRMER) return("alrmer");
	if (ix == UPKIDLE) return("upkidle");
	if (ix == UNPACK) return("unpack");
	if (ix == UPKDONE) return("upkdone");
	if (ix == AUTH) return("auth");
	if (ix == AUTDONE) return("autdone");
	if (ix == FILLPLH) return("fillplh");
	if (ix == CREATE) return("create");
	if (ix == WRITE) return("write");
	if (ix == MRG) return("mrg");
	if (ix == MRGFINE) return("mrgfine");
	if (ix == MRGTYPSPEC) return("mrgtypspec");
	if (ix == MRGTPLSPEC) return("mrgtplspec");
	if (ix == CLRSPEC) return("clrspec");
	if (ix == MRGCUST) return("mrgcust");
	if (ix == PACK) return("pack");
	if (ix == FAIL) return("fail");
	if (ix == DONE) return("done");

	return("");
};

void DlgWdbeRlsWrite::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 20; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class DlgWdbeRlsWrite::ContIac
 ******************************************************************************/

DlgWdbeRlsWrite::ContIac::ContIac(
			const uint numFDse
		) :
			Block()
		{
	this->numFDse = numFDse;

	mask = {NUMFDSE};
};

bool DlgWdbeRlsWrite::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgWdbeRlsWrite");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgWdbeRlsWrite";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDse", numFDse)) add(NUMFDSE);
	};

	return basefound;
};

void DlgWdbeRlsWrite::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWdbeRlsWrite";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgWdbeRlsWrite";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFDse", numFDse);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeRlsWrite::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFDse == comp->numFDse) insert(items, NUMFDSE);

	return(items);
};

set<uint> DlgWdbeRlsWrite::ContIac::diff(
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
 class DlgWdbeRlsWrite::ContIacDet
 ******************************************************************************/

DlgWdbeRlsWrite::ContIacDet::ContIacDet(
			const bool ChkBso
		) :
			Block()
		{
	this->ChkBso = ChkBso;

	mask = {CHKBSO};
};

bool DlgWdbeRlsWrite::ContIacDet::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgWdbeRlsWriteDet");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgWdbeRlsWriteDet";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkBso", ChkBso)) add(CHKBSO);
	};

	return basefound;
};

void DlgWdbeRlsWrite::ContIacDet::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWdbeRlsWriteDet";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgWdbeRlsWriteDet";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ChkBso", ChkBso);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeRlsWrite::ContIacDet::comm(
			const ContIacDet* comp
		) {
	set<uint> items;

	if (ChkBso == comp->ChkBso) insert(items, CHKBSO);

	return(items);
};

set<uint> DlgWdbeRlsWrite::ContIacDet::diff(
			const ContIacDet* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {CHKBSO};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeRlsWrite::ContInf
 ******************************************************************************/

DlgWdbeRlsWrite::ContInf::ContInf(
			const uint numFSge
		) :
			Block()
		{
	this->numFSge = numFSge;

	mask = {NUMFSGE};
};

void DlgWdbeRlsWrite::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWdbeRlsWrite";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWdbeRlsWrite";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeRlsWrite::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);

	return(items);
};

set<uint> DlgWdbeRlsWrite::ContInf::diff(
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
 class DlgWdbeRlsWrite::ContInfFia
 ******************************************************************************/

DlgWdbeRlsWrite::ContInfFia::ContInfFia(
			const string& Dld
		) :
			Block()
		{
	this->Dld = Dld;

	mask = {DLD};
};

void DlgWdbeRlsWrite::ContInfFia::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWdbeRlsWriteFia";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWdbeRlsWriteFia";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "Dld", Dld);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeRlsWrite::ContInfFia::comm(
			const ContInfFia* comp
		) {
	set<uint> items;

	if (Dld == comp->Dld) insert(items, DLD);

	return(items);
};

set<uint> DlgWdbeRlsWrite::ContInfFia::diff(
			const ContInfFia* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {DLD};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeRlsWrite::ContInfLfi
 ******************************************************************************/

DlgWdbeRlsWrite::ContInfLfi::ContInfLfi(
			const string& Dld
		) :
			Block()
		{
	this->Dld = Dld;

	mask = {DLD};
};

void DlgWdbeRlsWrite::ContInfLfi::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWdbeRlsWriteLfi";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWdbeRlsWriteLfi";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "Dld", Dld);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeRlsWrite::ContInfLfi::comm(
			const ContInfLfi* comp
		) {
	set<uint> items;

	if (Dld == comp->Dld) insert(items, DLD);

	return(items);
};

set<uint> DlgWdbeRlsWrite::ContInfLfi::diff(
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
 class DlgWdbeRlsWrite::ContInfWrc
 ******************************************************************************/

DlgWdbeRlsWrite::ContInfWrc::ContInfWrc(
			const string& TxtPrg
		) :
			Block()
		{
	this->TxtPrg = TxtPrg;

	mask = {TXTPRG};
};

void DlgWdbeRlsWrite::ContInfWrc::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWdbeRlsWriteWrc";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWdbeRlsWriteWrc";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtPrg", TxtPrg);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeRlsWrite::ContInfWrc::comm(
			const ContInfWrc* comp
		) {
	set<uint> items;

	if (TxtPrg == comp->TxtPrg) insert(items, TXTPRG);

	return(items);
};

set<uint> DlgWdbeRlsWrite::ContInfWrc::diff(
			const ContInfWrc* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTPRG};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeRlsWrite::StatApp
 ******************************************************************************/

void DlgWdbeRlsWrite::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdone
			, const string& shortMenu
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgWdbeRlsWrite";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppDlgWdbeRlsWrite";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdone", initdone);
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeRlsWrite::StatShr
 ******************************************************************************/

DlgWdbeRlsWrite::StatShr::StatShr(
			const bool ButDneActive
		) :
			Block()
		{
	this->ButDneActive = ButDneActive;

	mask = {BUTDNEACTIVE};
};

void DlgWdbeRlsWrite::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWdbeRlsWrite";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWdbeRlsWrite";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButDneActive", ButDneActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeRlsWrite::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButDneActive == comp->ButDneActive) insert(items, BUTDNEACTIVE);

	return(items);
};

set<uint> DlgWdbeRlsWrite::StatShr::diff(
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
 class DlgWdbeRlsWrite::StatShrCuc
 ******************************************************************************/

DlgWdbeRlsWrite::StatShrCuc::StatShrCuc(
			const bool UldAvail
			, const bool UldActive
		) :
			Block()
		{
	this->UldAvail = UldAvail;
	this->UldActive = UldActive;

	mask = {ULDAVAIL, ULDACTIVE};
};

void DlgWdbeRlsWrite::StatShrCuc::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWdbeRlsWriteCuc";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWdbeRlsWriteCuc";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "UldAvail", UldAvail);
		writeBoolAttr(wr, itemtag, "sref", "UldActive", UldActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeRlsWrite::StatShrCuc::comm(
			const StatShrCuc* comp
		) {
	set<uint> items;

	if (UldAvail == comp->UldAvail) insert(items, ULDAVAIL);
	if (UldActive == comp->UldActive) insert(items, ULDACTIVE);

	return(items);
};

set<uint> DlgWdbeRlsWrite::StatShrCuc::diff(
			const StatShrCuc* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {ULDAVAIL, ULDACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeRlsWrite::StatShrFia
 ******************************************************************************/

DlgWdbeRlsWrite::StatShrFia::StatShrFia(
			const bool DldAvail
			, const bool DldActive
		) :
			Block()
		{
	this->DldAvail = DldAvail;
	this->DldActive = DldActive;

	mask = {DLDAVAIL, DLDACTIVE};
};

void DlgWdbeRlsWrite::StatShrFia::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWdbeRlsWriteFia";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWdbeRlsWriteFia";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "DldAvail", DldAvail);
		writeBoolAttr(wr, itemtag, "sref", "DldActive", DldActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeRlsWrite::StatShrFia::comm(
			const StatShrFia* comp
		) {
	set<uint> items;

	if (DldAvail == comp->DldAvail) insert(items, DLDAVAIL);
	if (DldActive == comp->DldActive) insert(items, DLDACTIVE);

	return(items);
};

set<uint> DlgWdbeRlsWrite::StatShrFia::diff(
			const StatShrFia* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {DLDAVAIL, DLDACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeRlsWrite::StatShrLfi
 ******************************************************************************/

DlgWdbeRlsWrite::StatShrLfi::StatShrLfi(
			const bool DldActive
		) :
			Block()
		{
	this->DldActive = DldActive;

	mask = {DLDACTIVE};
};

void DlgWdbeRlsWrite::StatShrLfi::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWdbeRlsWriteLfi";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWdbeRlsWriteLfi";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "DldActive", DldActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeRlsWrite::StatShrLfi::comm(
			const StatShrLfi* comp
		) {
	set<uint> items;

	if (DldActive == comp->DldActive) insert(items, DLDACTIVE);

	return(items);
};

set<uint> DlgWdbeRlsWrite::StatShrLfi::diff(
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
 class DlgWdbeRlsWrite::StatShrWrc
 ******************************************************************************/

DlgWdbeRlsWrite::StatShrWrc::StatShrWrc(
			const bool ButAutActive
			, const bool ButRunActive
			, const bool ButStoActive
		) :
			Block()
		{
	this->ButAutActive = ButAutActive;
	this->ButRunActive = ButRunActive;
	this->ButStoActive = ButStoActive;

	mask = {BUTAUTACTIVE, BUTRUNACTIVE, BUTSTOACTIVE};
};

void DlgWdbeRlsWrite::StatShrWrc::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWdbeRlsWriteWrc";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWdbeRlsWriteWrc";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButAutActive", ButAutActive);
		writeBoolAttr(wr, itemtag, "sref", "ButRunActive", ButRunActive);
		writeBoolAttr(wr, itemtag, "sref", "ButStoActive", ButStoActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeRlsWrite::StatShrWrc::comm(
			const StatShrWrc* comp
		) {
	set<uint> items;

	if (ButAutActive == comp->ButAutActive) insert(items, BUTAUTACTIVE);
	if (ButRunActive == comp->ButRunActive) insert(items, BUTRUNACTIVE);
	if (ButStoActive == comp->ButStoActive) insert(items, BUTSTOACTIVE);

	return(items);
};

set<uint> DlgWdbeRlsWrite::StatShrWrc::diff(
			const StatShrWrc* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTAUTACTIVE, BUTRUNACTIVE, BUTSTOACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeRlsWrite::Tag
 ******************************************************************************/

void DlgWdbeRlsWrite::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWdbeRlsWrite";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWdbeRlsWrite";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Write code");
		};
		writeStringAttr(wr, itemtag, "sref", "ButDne", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DONE, ixWdbeVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeRlsWrite::TagCuc
 ******************************************************************************/

void DlgWdbeRlsWrite::TagCuc::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWdbeRlsWriteCuc";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWdbeRlsWriteCuc";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		};
		writeStringAttr(wr, itemtag, "sref", "Uld", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::UPLOAD, ixWdbeVLocale)));
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::FILENAME, ixWdbeVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeRlsWrite::TagDet
 ******************************************************************************/

void DlgWdbeRlsWrite::TagDet::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWdbeRlsWriteDet";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWdbeRlsWriteDet";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptBso", "Build scripts only");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeRlsWrite::TagFia
 ******************************************************************************/

void DlgWdbeRlsWrite::TagFia::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWdbeRlsWriteFia";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWdbeRlsWriteFia";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		};
		writeStringAttr(wr, itemtag, "sref", "Dld", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DOWNLOAD, ixWdbeVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeRlsWrite::TagLfi
 ******************************************************************************/

void DlgWdbeRlsWrite::TagLfi::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWdbeRlsWriteLfi";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWdbeRlsWriteLfi";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		};
		writeStringAttr(wr, itemtag, "sref", "Dld", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DOWNLOAD, ixWdbeVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeRlsWrite::TagWrc
 ******************************************************************************/

void DlgWdbeRlsWrite::TagWrc::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWdbeRlsWriteWrc";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWdbeRlsWriteWrc";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "ButAut", "Authenticate");
		};
		writeStringAttr(wr, itemtag, "sref", "CptPrg", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::PROGRESS, ixWdbeVLocale)));
		writeStringAttr(wr, itemtag, "sref", "ButRun", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::RUN, ixWdbeVLocale)));
		writeStringAttr(wr, itemtag, "sref", "ButSto", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::STOP, ixWdbeVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeRlsWrite::DpchAppData
 ******************************************************************************/

DlgWdbeRlsWrite::DpchAppData::DpchAppData() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPDLGWDBERLSWRITEDATA)
		{
};

string DlgWdbeRlsWrite::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTIACDET)) ss.push_back("contiacdet");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbeRlsWrite::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgWdbeRlsWriteData");
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
 class DlgWdbeRlsWrite::DpchAppDo
 ******************************************************************************/

DlgWdbeRlsWrite::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPDLGWDBERLSWRITEDO)
		{
	ixVDo = 0;
	ixVDoWrc = 0;
};

string DlgWdbeRlsWrite::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");
	if (has(IXVDOWRC)) ss.push_back("ixVDoWrc");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbeRlsWrite::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;
	string srefIxVDoWrc;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgWdbeRlsWriteDo");
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
		if (extractStringUclc(docctx, basexpath, "srefIxVDoWrc", "", srefIxVDoWrc)) {
			ixVDoWrc = VecVDoWrc::getIx(srefIxVDoWrc);
			add(IXVDOWRC);
		};
	} else {
	};
};

/******************************************************************************
 class DlgWdbeRlsWrite::DpchEngData
 ******************************************************************************/

DlgWdbeRlsWrite::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContIacDet* contiacdet
			, ContInf* continf
			, ContInfFia* continffia
			, ContInfLfi* continflfi
			, ContInfWrc* continfwrc
			, Feed* feedFDse
			, Feed* feedFSge
			, StatShr* statshr
			, StatShrCuc* statshrcuc
			, StatShrFia* statshrfia
			, StatShrLfi* statshrlfi
			, StatShrWrc* statshrwrc
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGDLGWDBERLSWRITEDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTIACDET, CONTINF, CONTINFFIA, CONTINFLFI, CONTINFWRC, FEEDFDSE, FEEDFSGE, STATAPP, STATSHR, STATSHRCUC, STATSHRFIA, STATSHRLFI, STATSHRWRC, TAG, TAGCUC, TAGDET, TAGFIA, TAGLFI, TAGWRC};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTIACDET) && contiacdet) this->contiacdet = *contiacdet;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, CONTINFFIA) && continffia) this->continffia = *continffia;
	if (find(this->mask, CONTINFLFI) && continflfi) this->continflfi = *continflfi;
	if (find(this->mask, CONTINFWRC) && continfwrc) this->continfwrc = *continfwrc;
	if (find(this->mask, FEEDFDSE) && feedFDse) this->feedFDse = *feedFDse;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
	if (find(this->mask, STATSHRCUC) && statshrcuc) this->statshrcuc = *statshrcuc;
	if (find(this->mask, STATSHRFIA) && statshrfia) this->statshrfia = *statshrfia;
	if (find(this->mask, STATSHRLFI) && statshrlfi) this->statshrlfi = *statshrlfi;
	if (find(this->mask, STATSHRWRC) && statshrwrc) this->statshrwrc = *statshrwrc;
};

string DlgWdbeRlsWrite::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTIACDET)) ss.push_back("contiacdet");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(CONTINFFIA)) ss.push_back("continffia");
	if (has(CONTINFLFI)) ss.push_back("continflfi");
	if (has(CONTINFWRC)) ss.push_back("continfwrc");
	if (has(FEEDFDSE)) ss.push_back("feedFDse");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(STATSHRCUC)) ss.push_back("statshrcuc");
	if (has(STATSHRFIA)) ss.push_back("statshrfia");
	if (has(STATSHRLFI)) ss.push_back("statshrlfi");
	if (has(STATSHRWRC)) ss.push_back("statshrwrc");
	if (has(TAG)) ss.push_back("tag");
	if (has(TAGCUC)) ss.push_back("tagcuc");
	if (has(TAGDET)) ss.push_back("tagdet");
	if (has(TAGFIA)) ss.push_back("tagfia");
	if (has(TAGLFI)) ss.push_back("taglfi");
	if (has(TAGWRC)) ss.push_back("tagwrc");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbeRlsWrite::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTIACDET)) {contiacdet = src->contiacdet; add(CONTIACDET);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(CONTINFFIA)) {continffia = src->continffia; add(CONTINFFIA);};
	if (src->has(CONTINFLFI)) {continflfi = src->continflfi; add(CONTINFLFI);};
	if (src->has(CONTINFWRC)) {continfwrc = src->continfwrc; add(CONTINFWRC);};
	if (src->has(FEEDFDSE)) {feedFDse = src->feedFDse; add(FEEDFDSE);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(STATSHRCUC)) {statshrcuc = src->statshrcuc; add(STATSHRCUC);};
	if (src->has(STATSHRFIA)) {statshrfia = src->statshrfia; add(STATSHRFIA);};
	if (src->has(STATSHRLFI)) {statshrlfi = src->statshrlfi; add(STATSHRLFI);};
	if (src->has(STATSHRWRC)) {statshrwrc = src->statshrwrc; add(STATSHRWRC);};
	if (src->has(TAG)) add(TAG);
	if (src->has(TAGCUC)) add(TAGCUC);
	if (src->has(TAGDET)) add(TAGDET);
	if (src->has(TAGFIA)) add(TAGFIA);
	if (src->has(TAGLFI)) add(TAGLFI);
	if (src->has(TAGWRC)) add(TAGWRC);
};

void DlgWdbeRlsWrite::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngDlgWdbeRlsWriteData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTIACDET)) contiacdet.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(CONTINFFIA)) continffia.writeXML(wr);
		if (has(CONTINFLFI)) continflfi.writeXML(wr);
		if (has(CONTINFWRC)) continfwrc.writeXML(wr);
		if (has(FEEDFDSE)) feedFDse.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STATSHRCUC)) statshrcuc.writeXML(wr);
		if (has(STATSHRFIA)) statshrfia.writeXML(wr);
		if (has(STATSHRLFI)) statshrlfi.writeXML(wr);
		if (has(STATSHRWRC)) statshrwrc.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
		if (has(TAGCUC)) TagCuc::writeXML(ixWdbeVLocale, wr);
		if (has(TAGDET)) TagDet::writeXML(ixWdbeVLocale, wr);
		if (has(TAGFIA)) TagFia::writeXML(ixWdbeVLocale, wr);
		if (has(TAGLFI)) TagLfi::writeXML(ixWdbeVLocale, wr);
		if (has(TAGWRC)) TagWrc::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};

