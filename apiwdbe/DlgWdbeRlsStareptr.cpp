/**
	* \file DlgWdbeRlsStareptr.cpp
	* API code for job DlgWdbeRlsStareptr (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "DlgWdbeRlsStareptr.h"

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

/******************************************************************************
 class DlgWdbeRlsStareptr::ContIac
 ******************************************************************************/

DlgWdbeRlsStareptr::ContIac::ContIac(
			const uint numFDse
		) :
			Block()
			, numFDse(numFDse)
		{
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
			, numFRbuBrt(numFRbuBrt)
			, TxfGrl(TxfGrl)
		{
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
			, numFSge(numFSge)
		{
	mask = {NUMFSGE};
};

bool DlgWdbeRlsStareptr::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWdbeRlsStareptr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWdbeRlsStareptr";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
	};

	return basefound;
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
			, TxtPrg(TxtPrg)
		{
	mask = {TXTPRG};
};

bool DlgWdbeRlsStareptr::ContInfExt::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWdbeRlsStareptrExt");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWdbeRlsStareptrExt";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPrg", TxtPrg)) add(TXTPRG);
	};

	return basefound;
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
			, TxtPrg(TxtPrg)
		{
	mask = {TXTPRG};
};

bool DlgWdbeRlsStareptr::ContInfIni::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWdbeRlsStareptrIni");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWdbeRlsStareptrIni";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPrg", TxtPrg)) add(TXTPRG);
	};

	return basefound;
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
			, Dld(Dld)
		{
	mask = {DLD};
};

bool DlgWdbeRlsStareptr::ContInfLfi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWdbeRlsStareptrLfi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWdbeRlsStareptrLfi";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Dld", Dld)) add(DLD);
	};

	return basefound;
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

DlgWdbeRlsStareptr::StatApp::StatApp(
			const bool initdone
			, const string& shortMenu
		) :
			Block()
			, initdone(initdone)
			, shortMenu(shortMenu)
		{
	mask = {INITDONE, SHORTMENU};
};

bool DlgWdbeRlsStareptr::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppDlgWdbeRlsStareptr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppDlgWdbeRlsStareptr";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone", initdone)) add(INITDONE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
	};

	return basefound;
};

set<uint> DlgWdbeRlsStareptr::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdone == comp->initdone) insert(items, INITDONE);
	if (shortMenu == comp->shortMenu) insert(items, SHORTMENU);

	return(items);
};

set<uint> DlgWdbeRlsStareptr::StatApp::diff(
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
 class DlgWdbeRlsStareptr::StatShr
 ******************************************************************************/

DlgWdbeRlsStareptr::StatShr::StatShr(
			const bool ButDneActive
		) :
			Block()
			, ButDneActive(ButDneActive)
		{
	mask = {BUTDNEACTIVE};
};

bool DlgWdbeRlsStareptr::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWdbeRlsStareptr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWdbeRlsStareptr";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDneActive", ButDneActive)) add(BUTDNEACTIVE);
	};

	return basefound;
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
			, TxfGrlAvail(TxfGrlAvail)
			, ButStaActive(ButStaActive)
		{
	mask = {TXFGRLAVAIL, BUTSTAACTIVE};
};

bool DlgWdbeRlsStareptr::StatShrDet::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWdbeRlsStareptrDet");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWdbeRlsStareptrDet";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfGrlAvail", TxfGrlAvail)) add(TXFGRLAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStaActive", ButStaActive)) add(BUTSTAACTIVE);
	};

	return basefound;
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
			, ButRunActive(ButRunActive)
			, ButStoActive(ButStoActive)
		{
	mask = {BUTRUNACTIVE, BUTSTOACTIVE};
};

bool DlgWdbeRlsStareptr::StatShrExt::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWdbeRlsStareptrExt");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWdbeRlsStareptrExt";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRunActive", ButRunActive)) add(BUTRUNACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStoActive", ButStoActive)) add(BUTSTOACTIVE);
	};

	return basefound;
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
			, UldAvail(UldAvail)
			, UldActive(UldActive)
			, TxtPrgAvail(TxtPrgAvail)
			, Sep1Avail(Sep1Avail)
			, ButClgAvail(ButClgAvail)
			, ButClgActive(ButClgActive)
		{
	mask = {ULDAVAIL, ULDACTIVE, TXTPRGAVAIL, SEP1AVAIL, BUTCLGAVAIL, BUTCLGACTIVE};
};

bool DlgWdbeRlsStareptr::StatShrIni::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWdbeRlsStareptrIni");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWdbeRlsStareptrIni";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "UldAvail", UldAvail)) add(ULDAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "UldActive", UldActive)) add(ULDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtPrgAvail", TxtPrgAvail)) add(TXTPRGAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Sep1Avail", Sep1Avail)) add(SEP1AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButClgAvail", ButClgAvail)) add(BUTCLGAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButClgActive", ButClgActive)) add(BUTCLGACTIVE);
	};

	return basefound;
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
			, DldActive(DldActive)
		{
	mask = {DLDACTIVE};
};

bool DlgWdbeRlsStareptr::StatShrLfi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWdbeRlsStareptrLfi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWdbeRlsStareptrLfi";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "DldActive", DldActive)) add(DLDACTIVE);
	};

	return basefound;
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

DlgWdbeRlsStareptr::Tag::Tag(
			const string& Cpt
			, const string& ButDne
		) :
			Block()
			, Cpt(Cpt)
			, ButDne(ButDne)
		{
	mask = {CPT, BUTDNE};
};

bool DlgWdbeRlsStareptr::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWdbeRlsStareptr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWdbeRlsStareptr";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButDne", ButDne)) add(BUTDNE);
	};

	return basefound;
};

/******************************************************************************
 class DlgWdbeRlsStareptr::TagDet
 ******************************************************************************/

DlgWdbeRlsStareptr::TagDet::TagDet(
			const string& CptBrt
			, const string& CptGrl
			, const string& ButSta
		) :
			Block()
			, CptBrt(CptBrt)
			, CptGrl(CptGrl)
			, ButSta(ButSta)
		{
	mask = {CPTBRT, CPTGRL, BUTSTA};
};

bool DlgWdbeRlsStareptr::TagDet::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWdbeRlsStareptrDet");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWdbeRlsStareptrDet";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptBrt", CptBrt)) add(CPTBRT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptGrl", CptGrl)) add(CPTGRL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButSta", ButSta)) add(BUTSTA);
	};

	return basefound;
};

/******************************************************************************
 class DlgWdbeRlsStareptr::TagExt
 ******************************************************************************/

DlgWdbeRlsStareptr::TagExt::TagExt(
			const string& CptPrg
			, const string& ButRun
			, const string& ButSto
		) :
			Block()
			, CptPrg(CptPrg)
			, ButRun(ButRun)
			, ButSto(ButSto)
		{
	mask = {CPTPRG, BUTRUN, BUTSTO};
};

bool DlgWdbeRlsStareptr::TagExt::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWdbeRlsStareptrExt");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWdbeRlsStareptrExt";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrg", CptPrg)) add(CPTPRG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButRun", ButRun)) add(BUTRUN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButSto", ButSto)) add(BUTSTO);
	};

	return basefound;
};

/******************************************************************************
 class DlgWdbeRlsStareptr::TagIni
 ******************************************************************************/

DlgWdbeRlsStareptr::TagIni::TagIni(
			const string& Uld
			, const string& Cpt
			, const string& CptPrg
			, const string& ButClg
		) :
			Block()
			, Uld(Uld)
			, Cpt(Cpt)
			, CptPrg(CptPrg)
			, ButClg(ButClg)
		{
	mask = {ULD, CPT, CPTPRG, BUTCLG};
};

bool DlgWdbeRlsStareptr::TagIni::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWdbeRlsStareptrIni");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWdbeRlsStareptrIni";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Uld", Uld)) add(ULD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrg", CptPrg)) add(CPTPRG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButClg", ButClg)) add(BUTCLG);
	};

	return basefound;
};

/******************************************************************************
 class DlgWdbeRlsStareptr::TagLfi
 ******************************************************************************/

DlgWdbeRlsStareptr::TagLfi::TagLfi(
			const string& Dld
		) :
			Block()
			, Dld(Dld)
		{
	mask = {DLD};
};

bool DlgWdbeRlsStareptr::TagLfi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWdbeRlsStareptrLfi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWdbeRlsStareptrLfi";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Dld", Dld)) add(DLD);
	};

	return basefound;
};

/******************************************************************************
 class DlgWdbeRlsStareptr::DpchAppData
 ******************************************************************************/

DlgWdbeRlsStareptr::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, ContIacDet* contiacdet
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPDLGWDBERLSSTAREPTRDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC, CONTIACDET};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
		if (find(this->mask, CONTIACDET) && contiacdet) this->contiacdet = *contiacdet;
};

string DlgWdbeRlsStareptr::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTIACDET)) ss.push_back("contiacdet");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbeRlsStareptr::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgWdbeRlsStareptrData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTIACDET)) contiacdet.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeRlsStareptr::DpchAppDo
 ******************************************************************************/

DlgWdbeRlsStareptr::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const uint ixVDoDet
			, const uint ixVDoExt
			, const uint ixVDoIni
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPDLGWDBERLSSTAREPTRDO, scrJref)
			, ixVDo(ixVDo)
			, ixVDoDet(ixVDoDet)
			, ixVDoExt(ixVDoExt)
			, ixVDoIni(ixVDoIni)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO, IXVDODET, IXVDOEXT, IXVDOINI};
	else this->mask = mask;

};

string DlgWdbeRlsStareptr::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");
	if (has(IXVDODET)) ss.push_back("ixVDoDet");
	if (has(IXVDOEXT)) ss.push_back("ixVDoExt");
	if (has(IXVDOINI)) ss.push_back("ixVDoIni");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbeRlsStareptr::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgWdbeRlsStareptrDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
		if (has(IXVDODET)) writeString(wr, "srefIxVDoDet", VecVDoDet::getSref(ixVDoDet));
		if (has(IXVDOEXT)) writeString(wr, "srefIxVDoExt", VecVDoExt::getSref(ixVDoExt));
		if (has(IXVDOINI)) writeString(wr, "srefIxVDoIni", VecVDoIni::getSref(ixVDoIni));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeRlsStareptr::DpchEngData
 ******************************************************************************/

DlgWdbeRlsStareptr::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGDLGWDBERLSSTAREPTRDATA)
		{
	feedFDetRbuBrt.tag = "FeedFDetRbuBrt";
	feedFDse.tag = "FeedFDse";
	feedFSge.tag = "FeedFSge";
};

string DlgWdbeRlsStareptr::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
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

void DlgWdbeRlsStareptr::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngDlgWdbeRlsStareptrData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (contiacdet.readXML(docctx, basexpath, true)) add(CONTIACDET);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (continfext.readXML(docctx, basexpath, true)) add(CONTINFEXT);
		if (continfini.readXML(docctx, basexpath, true)) add(CONTINFINI);
		if (continflfi.readXML(docctx, basexpath, true)) add(CONTINFLFI);
		if (feedFDetRbuBrt.readXML(docctx, basexpath, true)) add(FEEDFDETRBUBRT);
		if (feedFDse.readXML(docctx, basexpath, true)) add(FEEDFDSE);
		if (feedFSge.readXML(docctx, basexpath, true)) add(FEEDFSGE);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (statshrdet.readXML(docctx, basexpath, true)) add(STATSHRDET);
		if (statshrext.readXML(docctx, basexpath, true)) add(STATSHREXT);
		if (statshrini.readXML(docctx, basexpath, true)) add(STATSHRINI);
		if (statshrlfi.readXML(docctx, basexpath, true)) add(STATSHRLFI);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
		if (tagdet.readXML(docctx, basexpath, true)) add(TAGDET);
		if (tagext.readXML(docctx, basexpath, true)) add(TAGEXT);
		if (tagini.readXML(docctx, basexpath, true)) add(TAGINI);
		if (taglfi.readXML(docctx, basexpath, true)) add(TAGLFI);
	} else {
		contiac = ContIac();
		contiacdet = ContIacDet();
		continf = ContInf();
		continfext = ContInfExt();
		continfini = ContInfIni();
		continflfi = ContInfLfi();
		feedFDetRbuBrt.clear();
		feedFDse.clear();
		feedFSge.clear();
		statapp = StatApp();
		statshr = StatShr();
		statshrdet = StatShrDet();
		statshrext = StatShrExt();
		statshrini = StatShrIni();
		statshrlfi = StatShrLfi();
		tag = Tag();
		tagdet = TagDet();
		tagext = TagExt();
		tagini = TagIni();
		taglfi = TagLfi();
	};
};
