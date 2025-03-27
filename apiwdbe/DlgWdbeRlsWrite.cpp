/**
	* \file DlgWdbeRlsWrite.cpp
	* API code for job DlgWdbeRlsWrite (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "DlgWdbeRlsWrite.h"

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

/******************************************************************************
 class DlgWdbeRlsWrite::ContIac
 ******************************************************************************/

DlgWdbeRlsWrite::ContIac::ContIac(
			const uint numFDse
		) :
			Block()
			, numFDse(numFDse)
		{
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
			, ChkBso(ChkBso)
		{
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
			, numFSge(numFSge)
		{
	mask = {NUMFSGE};
};

bool DlgWdbeRlsWrite::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWdbeRlsWrite");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWdbeRlsWrite";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
	};

	return basefound;
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
			, Dld(Dld)
		{
	mask = {DLD};
};

bool DlgWdbeRlsWrite::ContInfFia::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWdbeRlsWriteFia");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWdbeRlsWriteFia";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Dld", Dld)) add(DLD);
	};

	return basefound;
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
			, Dld(Dld)
		{
	mask = {DLD};
};

bool DlgWdbeRlsWrite::ContInfLfi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWdbeRlsWriteLfi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWdbeRlsWriteLfi";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Dld", Dld)) add(DLD);
	};

	return basefound;
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
			, TxtPrg(TxtPrg)
		{
	mask = {TXTPRG};
};

bool DlgWdbeRlsWrite::ContInfWrc::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWdbeRlsWriteWrc");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWdbeRlsWriteWrc";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPrg", TxtPrg)) add(TXTPRG);
	};

	return basefound;
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

DlgWdbeRlsWrite::StatApp::StatApp(
			const bool initdone
			, const string& shortMenu
		) :
			Block()
			, initdone(initdone)
			, shortMenu(shortMenu)
		{
	mask = {INITDONE, SHORTMENU};
};

bool DlgWdbeRlsWrite::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppDlgWdbeRlsWrite");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppDlgWdbeRlsWrite";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone", initdone)) add(INITDONE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
	};

	return basefound;
};

set<uint> DlgWdbeRlsWrite::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdone == comp->initdone) insert(items, INITDONE);
	if (shortMenu == comp->shortMenu) insert(items, SHORTMENU);

	return(items);
};

set<uint> DlgWdbeRlsWrite::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONE, SHORTMENU};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeRlsWrite::StatShr
 ******************************************************************************/

DlgWdbeRlsWrite::StatShr::StatShr(
			const bool ButDneActive
		) :
			Block()
			, ButDneActive(ButDneActive)
		{
	mask = {BUTDNEACTIVE};
};

bool DlgWdbeRlsWrite::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWdbeRlsWrite");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWdbeRlsWrite";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDneActive", ButDneActive)) add(BUTDNEACTIVE);
	};

	return basefound;
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
			, UldAvail(UldAvail)
			, UldActive(UldActive)
		{
	mask = {ULDAVAIL, ULDACTIVE};
};

bool DlgWdbeRlsWrite::StatShrCuc::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWdbeRlsWriteCuc");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWdbeRlsWriteCuc";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "UldAvail", UldAvail)) add(ULDAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "UldActive", UldActive)) add(ULDACTIVE);
	};

	return basefound;
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
			, DldAvail(DldAvail)
			, DldActive(DldActive)
		{
	mask = {DLDAVAIL, DLDACTIVE};
};

bool DlgWdbeRlsWrite::StatShrFia::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWdbeRlsWriteFia");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWdbeRlsWriteFia";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "DldAvail", DldAvail)) add(DLDAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "DldActive", DldActive)) add(DLDACTIVE);
	};

	return basefound;
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
			, DldActive(DldActive)
		{
	mask = {DLDACTIVE};
};

bool DlgWdbeRlsWrite::StatShrLfi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWdbeRlsWriteLfi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWdbeRlsWriteLfi";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "DldActive", DldActive)) add(DLDACTIVE);
	};

	return basefound;
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
			, ButAutActive(ButAutActive)
			, ButRunActive(ButRunActive)
			, ButStoActive(ButStoActive)
		{
	mask = {BUTAUTACTIVE, BUTRUNACTIVE, BUTSTOACTIVE};
};

bool DlgWdbeRlsWrite::StatShrWrc::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWdbeRlsWriteWrc");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWdbeRlsWriteWrc";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButAutActive", ButAutActive)) add(BUTAUTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRunActive", ButRunActive)) add(BUTRUNACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStoActive", ButStoActive)) add(BUTSTOACTIVE);
	};

	return basefound;
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

DlgWdbeRlsWrite::Tag::Tag(
			const string& Cpt
			, const string& ButDne
		) :
			Block()
			, Cpt(Cpt)
			, ButDne(ButDne)
		{
	mask = {CPT, BUTDNE};
};

bool DlgWdbeRlsWrite::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWdbeRlsWrite");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWdbeRlsWrite";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButDne", ButDne)) add(BUTDNE);
	};

	return basefound;
};

/******************************************************************************
 class DlgWdbeRlsWrite::TagCuc
 ******************************************************************************/

DlgWdbeRlsWrite::TagCuc::TagCuc(
			const string& Uld
			, const string& Cpt
		) :
			Block()
			, Uld(Uld)
			, Cpt(Cpt)
		{
	mask = {ULD, CPT};
};

bool DlgWdbeRlsWrite::TagCuc::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWdbeRlsWriteCuc");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWdbeRlsWriteCuc";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Uld", Uld)) add(ULD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class DlgWdbeRlsWrite::TagDet
 ******************************************************************************/

DlgWdbeRlsWrite::TagDet::TagDet(
			const string& CptBso
		) :
			Block()
			, CptBso(CptBso)
		{
	mask = {CPTBSO};
};

bool DlgWdbeRlsWrite::TagDet::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWdbeRlsWriteDet");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWdbeRlsWriteDet";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptBso", CptBso)) add(CPTBSO);
	};

	return basefound;
};

/******************************************************************************
 class DlgWdbeRlsWrite::TagFia
 ******************************************************************************/

DlgWdbeRlsWrite::TagFia::TagFia(
			const string& Dld
		) :
			Block()
			, Dld(Dld)
		{
	mask = {DLD};
};

bool DlgWdbeRlsWrite::TagFia::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWdbeRlsWriteFia");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWdbeRlsWriteFia";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Dld", Dld)) add(DLD);
	};

	return basefound;
};

/******************************************************************************
 class DlgWdbeRlsWrite::TagLfi
 ******************************************************************************/

DlgWdbeRlsWrite::TagLfi::TagLfi(
			const string& Dld
		) :
			Block()
			, Dld(Dld)
		{
	mask = {DLD};
};

bool DlgWdbeRlsWrite::TagLfi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWdbeRlsWriteLfi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWdbeRlsWriteLfi";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Dld", Dld)) add(DLD);
	};

	return basefound;
};

/******************************************************************************
 class DlgWdbeRlsWrite::TagWrc
 ******************************************************************************/

DlgWdbeRlsWrite::TagWrc::TagWrc(
			const string& CptPrg
			, const string& ButAut
			, const string& ButRun
			, const string& ButSto
		) :
			Block()
			, CptPrg(CptPrg)
			, ButAut(ButAut)
			, ButRun(ButRun)
			, ButSto(ButSto)
		{
	mask = {CPTPRG, BUTAUT, BUTRUN, BUTSTO};
};

bool DlgWdbeRlsWrite::TagWrc::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWdbeRlsWriteWrc");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWdbeRlsWriteWrc";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrg", CptPrg)) add(CPTPRG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButAut", ButAut)) add(BUTAUT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButRun", ButRun)) add(BUTRUN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButSto", ButSto)) add(BUTSTO);
	};

	return basefound;
};

/******************************************************************************
 class DlgWdbeRlsWrite::DpchAppData
 ******************************************************************************/

DlgWdbeRlsWrite::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, ContIacDet* contiacdet
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPDLGWDBERLSWRITEDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC, CONTIACDET};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
		if (find(this->mask, CONTIACDET) && contiacdet) this->contiacdet = *contiacdet;
};

string DlgWdbeRlsWrite::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTIACDET)) ss.push_back("contiacdet");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbeRlsWrite::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgWdbeRlsWriteData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTIACDET)) contiacdet.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeRlsWrite::DpchAppDo
 ******************************************************************************/

DlgWdbeRlsWrite::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const uint ixVDoWrc
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPDLGWDBERLSWRITEDO, scrJref)
			, ixVDo(ixVDo)
			, ixVDoWrc(ixVDoWrc)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO, IXVDOWRC};
	else this->mask = mask;

};

string DlgWdbeRlsWrite::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");
	if (has(IXVDOWRC)) ss.push_back("ixVDoWrc");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbeRlsWrite::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgWdbeRlsWriteDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
		if (has(IXVDOWRC)) writeString(wr, "srefIxVDoWrc", VecVDoWrc::getSref(ixVDoWrc));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeRlsWrite::DpchEngData
 ******************************************************************************/

DlgWdbeRlsWrite::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGDLGWDBERLSWRITEDATA)
		{
	feedFDse.tag = "FeedFDse";
	feedFSge.tag = "FeedFSge";
};

string DlgWdbeRlsWrite::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
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

void DlgWdbeRlsWrite::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngDlgWdbeRlsWriteData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (contiacdet.readXML(docctx, basexpath, true)) add(CONTIACDET);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (continffia.readXML(docctx, basexpath, true)) add(CONTINFFIA);
		if (continflfi.readXML(docctx, basexpath, true)) add(CONTINFLFI);
		if (continfwrc.readXML(docctx, basexpath, true)) add(CONTINFWRC);
		if (feedFDse.readXML(docctx, basexpath, true)) add(FEEDFDSE);
		if (feedFSge.readXML(docctx, basexpath, true)) add(FEEDFSGE);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (statshrcuc.readXML(docctx, basexpath, true)) add(STATSHRCUC);
		if (statshrfia.readXML(docctx, basexpath, true)) add(STATSHRFIA);
		if (statshrlfi.readXML(docctx, basexpath, true)) add(STATSHRLFI);
		if (statshrwrc.readXML(docctx, basexpath, true)) add(STATSHRWRC);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
		if (tagcuc.readXML(docctx, basexpath, true)) add(TAGCUC);
		if (tagdet.readXML(docctx, basexpath, true)) add(TAGDET);
		if (tagfia.readXML(docctx, basexpath, true)) add(TAGFIA);
		if (taglfi.readXML(docctx, basexpath, true)) add(TAGLFI);
		if (tagwrc.readXML(docctx, basexpath, true)) add(TAGWRC);
	} else {
		contiac = ContIac();
		contiacdet = ContIacDet();
		continf = ContInf();
		continffia = ContInfFia();
		continflfi = ContInfLfi();
		continfwrc = ContInfWrc();
		feedFDse.clear();
		feedFSge.clear();
		statapp = StatApp();
		statshr = StatShr();
		statshrcuc = StatShrCuc();
		statshrfia = StatShrFia();
		statshrlfi = StatShrLfi();
		statshrwrc = StatShrWrc();
		tag = Tag();
		tagcuc = TagCuc();
		tagdet = TagDet();
		tagfia = TagFia();
		taglfi = TagLfi();
		tagwrc = TagWrc();
	};
};
