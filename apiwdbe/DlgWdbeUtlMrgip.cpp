/**
	* \file DlgWdbeUtlMrgip.cpp
	* API code for job DlgWdbeUtlMrgip (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "DlgWdbeUtlMrgip.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DlgWdbeUtlMrgip::VecVDit
 ******************************************************************************/

uint DlgWdbeUtlMrgip::VecVDit::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "src") return SRC;
	if (s == "trg") return TRG;
	if (s == "mrg") return MRG;
	if (s == "lfi") return LFI;
	if (s == "res") return RES;

	return(0);
};

string DlgWdbeUtlMrgip::VecVDit::getSref(
			const uint ix
		) {
	if (ix == SRC) return("Src");
	if (ix == TRG) return("Trg");
	if (ix == MRG) return("Mrg");
	if (ix == LFI) return("Lfi");
	if (ix == RES) return("Res");

	return("");
};

/******************************************************************************
 class DlgWdbeUtlMrgip::VecVDo
 ******************************************************************************/

uint DlgWdbeUtlMrgip::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butdneclick") return BUTDNECLICK;

	return(0);
};

string DlgWdbeUtlMrgip::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgWdbeUtlMrgip::VecVDoMrg
 ******************************************************************************/

uint DlgWdbeUtlMrgip::VecVDoMrg::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butrunclick") return BUTRUNCLICK;
	if (s == "butstoclick") return BUTSTOCLICK;

	return(0);
};

string DlgWdbeUtlMrgip::VecVDoMrg::getSref(
			const uint ix
		) {
	if (ix == BUTRUNCLICK) return("ButRunClick");
	if (ix == BUTSTOCLICK) return("ButStoClick");

	return("");
};

/******************************************************************************
 class DlgWdbeUtlMrgip::VecVSge
 ******************************************************************************/

uint DlgWdbeUtlMrgip::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "alrmer") return ALRMER;
	if (s == "supidle") return SUPIDLE;
	if (s == "srcunpack") return SRCUNPACK;
	if (s == "supdone") return SUPDONE;
	if (s == "suldone") return SULDONE;
	if (s == "tupidle") return TUPIDLE;
	if (s == "trgunpack") return TRGUNPACK;
	if (s == "tupdone") return TUPDONE;
	if (s == "tuldone") return TULDONE;
	if (s == "merge") return MERGE;
	if (s == "pack") return PACK;
	if (s == "fail") return FAIL;
	if (s == "done") return DONE;

	return(0);
};

string DlgWdbeUtlMrgip::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRMER) return("alrmer");
	if (ix == SUPIDLE) return("supidle");
	if (ix == SRCUNPACK) return("srcunpack");
	if (ix == SUPDONE) return("supdone");
	if (ix == SULDONE) return("suldone");
	if (ix == TUPIDLE) return("tupidle");
	if (ix == TRGUNPACK) return("trgunpack");
	if (ix == TUPDONE) return("tupdone");
	if (ix == TULDONE) return("tuldone");
	if (ix == MERGE) return("merge");
	if (ix == PACK) return("pack");
	if (ix == FAIL) return("fail");
	if (ix == DONE) return("done");

	return("");
};

/******************************************************************************
 class DlgWdbeUtlMrgip::ContIac
 ******************************************************************************/

DlgWdbeUtlMrgip::ContIac::ContIac(
			const uint numFDse
		) :
			Block()
		{
	this->numFDse = numFDse;

	mask = {NUMFDSE};
};

bool DlgWdbeUtlMrgip::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgWdbeUtlMrgip");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgWdbeUtlMrgip";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDse", numFDse)) add(NUMFDSE);
	};

	return basefound;
};

void DlgWdbeUtlMrgip::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWdbeUtlMrgip";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgWdbeUtlMrgip";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFDse", numFDse);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeUtlMrgip::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFDse == comp->numFDse) insert(items, NUMFDSE);

	return(items);
};

set<uint> DlgWdbeUtlMrgip::ContIac::diff(
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
 class DlgWdbeUtlMrgip::ContInf
 ******************************************************************************/

DlgWdbeUtlMrgip::ContInf::ContInf(
			const uint numFSge
		) :
			Block()
		{
	this->numFSge = numFSge;

	mask = {NUMFSGE};
};

bool DlgWdbeUtlMrgip::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWdbeUtlMrgip");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWdbeUtlMrgip";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
	};

	return basefound;
};

set<uint> DlgWdbeUtlMrgip::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);

	return(items);
};

set<uint> DlgWdbeUtlMrgip::ContInf::diff(
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
 class DlgWdbeUtlMrgip::ContInfLfi
 ******************************************************************************/

DlgWdbeUtlMrgip::ContInfLfi::ContInfLfi(
			const string& Dld
		) :
			Block()
		{
	this->Dld = Dld;

	mask = {DLD};
};

bool DlgWdbeUtlMrgip::ContInfLfi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWdbeUtlMrgipLfi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWdbeUtlMrgipLfi";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Dld", Dld)) add(DLD);
	};

	return basefound;
};

set<uint> DlgWdbeUtlMrgip::ContInfLfi::comm(
			const ContInfLfi* comp
		) {
	set<uint> items;

	if (Dld == comp->Dld) insert(items, DLD);

	return(items);
};

set<uint> DlgWdbeUtlMrgip::ContInfLfi::diff(
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
 class DlgWdbeUtlMrgip::ContInfMrg
 ******************************************************************************/

DlgWdbeUtlMrgip::ContInfMrg::ContInfMrg(
			const string& TxtPrg
		) :
			Block()
		{
	this->TxtPrg = TxtPrg;

	mask = {TXTPRG};
};

bool DlgWdbeUtlMrgip::ContInfMrg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWdbeUtlMrgipMrg");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWdbeUtlMrgipMrg";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPrg", TxtPrg)) add(TXTPRG);
	};

	return basefound;
};

set<uint> DlgWdbeUtlMrgip::ContInfMrg::comm(
			const ContInfMrg* comp
		) {
	set<uint> items;

	if (TxtPrg == comp->TxtPrg) insert(items, TXTPRG);

	return(items);
};

set<uint> DlgWdbeUtlMrgip::ContInfMrg::diff(
			const ContInfMrg* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTPRG};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeUtlMrgip::ContInfRes
 ******************************************************************************/

DlgWdbeUtlMrgip::ContInfRes::ContInfRes(
			const string& Dld
		) :
			Block()
		{
	this->Dld = Dld;

	mask = {DLD};
};

bool DlgWdbeUtlMrgip::ContInfRes::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWdbeUtlMrgipRes");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWdbeUtlMrgipRes";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Dld", Dld)) add(DLD);
	};

	return basefound;
};

set<uint> DlgWdbeUtlMrgip::ContInfRes::comm(
			const ContInfRes* comp
		) {
	set<uint> items;

	if (Dld == comp->Dld) insert(items, DLD);

	return(items);
};

set<uint> DlgWdbeUtlMrgip::ContInfRes::diff(
			const ContInfRes* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {DLD};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeUtlMrgip::StatApp
 ******************************************************************************/

DlgWdbeUtlMrgip::StatApp::StatApp(
			const bool initdone
			, const string& shortMenu
		) :
			Block()
		{
	this->initdone = initdone;
	this->shortMenu = shortMenu;

	mask = {INITDONE, SHORTMENU};
};

bool DlgWdbeUtlMrgip::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppDlgWdbeUtlMrgip");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppDlgWdbeUtlMrgip";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone", initdone)) add(INITDONE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
	};

	return basefound;
};

set<uint> DlgWdbeUtlMrgip::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdone == comp->initdone) insert(items, INITDONE);
	if (shortMenu == comp->shortMenu) insert(items, SHORTMENU);

	return(items);
};

set<uint> DlgWdbeUtlMrgip::StatApp::diff(
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
 class DlgWdbeUtlMrgip::StatShr
 ******************************************************************************/

DlgWdbeUtlMrgip::StatShr::StatShr(
			const bool ButDneActive
		) :
			Block()
		{
	this->ButDneActive = ButDneActive;

	mask = {BUTDNEACTIVE};
};

bool DlgWdbeUtlMrgip::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWdbeUtlMrgip");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWdbeUtlMrgip";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDneActive", ButDneActive)) add(BUTDNEACTIVE);
	};

	return basefound;
};

set<uint> DlgWdbeUtlMrgip::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButDneActive == comp->ButDneActive) insert(items, BUTDNEACTIVE);

	return(items);
};

set<uint> DlgWdbeUtlMrgip::StatShr::diff(
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
 class DlgWdbeUtlMrgip::StatShrLfi
 ******************************************************************************/

DlgWdbeUtlMrgip::StatShrLfi::StatShrLfi(
			const bool DldActive
		) :
			Block()
		{
	this->DldActive = DldActive;

	mask = {DLDACTIVE};
};

bool DlgWdbeUtlMrgip::StatShrLfi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWdbeUtlMrgipLfi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWdbeUtlMrgipLfi";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "DldActive", DldActive)) add(DLDACTIVE);
	};

	return basefound;
};

set<uint> DlgWdbeUtlMrgip::StatShrLfi::comm(
			const StatShrLfi* comp
		) {
	set<uint> items;

	if (DldActive == comp->DldActive) insert(items, DLDACTIVE);

	return(items);
};

set<uint> DlgWdbeUtlMrgip::StatShrLfi::diff(
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
 class DlgWdbeUtlMrgip::StatShrMrg
 ******************************************************************************/

DlgWdbeUtlMrgip::StatShrMrg::StatShrMrg(
			const bool ButRunActive
			, const bool ButStoActive
		) :
			Block()
		{
	this->ButRunActive = ButRunActive;
	this->ButStoActive = ButStoActive;

	mask = {BUTRUNACTIVE, BUTSTOACTIVE};
};

bool DlgWdbeUtlMrgip::StatShrMrg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWdbeUtlMrgipMrg");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWdbeUtlMrgipMrg";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRunActive", ButRunActive)) add(BUTRUNACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStoActive", ButStoActive)) add(BUTSTOACTIVE);
	};

	return basefound;
};

set<uint> DlgWdbeUtlMrgip::StatShrMrg::comm(
			const StatShrMrg* comp
		) {
	set<uint> items;

	if (ButRunActive == comp->ButRunActive) insert(items, BUTRUNACTIVE);
	if (ButStoActive == comp->ButStoActive) insert(items, BUTSTOACTIVE);

	return(items);
};

set<uint> DlgWdbeUtlMrgip::StatShrMrg::diff(
			const StatShrMrg* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTRUNACTIVE, BUTSTOACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeUtlMrgip::StatShrRes
 ******************************************************************************/

DlgWdbeUtlMrgip::StatShrRes::StatShrRes(
			const bool DldActive
		) :
			Block()
		{
	this->DldActive = DldActive;

	mask = {DLDACTIVE};
};

bool DlgWdbeUtlMrgip::StatShrRes::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWdbeUtlMrgipRes");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWdbeUtlMrgipRes";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "DldActive", DldActive)) add(DLDACTIVE);
	};

	return basefound;
};

set<uint> DlgWdbeUtlMrgip::StatShrRes::comm(
			const StatShrRes* comp
		) {
	set<uint> items;

	if (DldActive == comp->DldActive) insert(items, DLDACTIVE);

	return(items);
};

set<uint> DlgWdbeUtlMrgip::StatShrRes::diff(
			const StatShrRes* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {DLDACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeUtlMrgip::StatShrSrc
 ******************************************************************************/

DlgWdbeUtlMrgip::StatShrSrc::StatShrSrc(
			const bool UldActive
		) :
			Block()
		{
	this->UldActive = UldActive;

	mask = {ULDACTIVE};
};

bool DlgWdbeUtlMrgip::StatShrSrc::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWdbeUtlMrgipSrc");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWdbeUtlMrgipSrc";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "UldActive", UldActive)) add(ULDACTIVE);
	};

	return basefound;
};

set<uint> DlgWdbeUtlMrgip::StatShrSrc::comm(
			const StatShrSrc* comp
		) {
	set<uint> items;

	if (UldActive == comp->UldActive) insert(items, ULDACTIVE);

	return(items);
};

set<uint> DlgWdbeUtlMrgip::StatShrSrc::diff(
			const StatShrSrc* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {ULDACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeUtlMrgip::StatShrTrg
 ******************************************************************************/

DlgWdbeUtlMrgip::StatShrTrg::StatShrTrg(
			const bool UldActive
		) :
			Block()
		{
	this->UldActive = UldActive;

	mask = {ULDACTIVE};
};

bool DlgWdbeUtlMrgip::StatShrTrg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWdbeUtlMrgipTrg");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWdbeUtlMrgipTrg";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "UldActive", UldActive)) add(ULDACTIVE);
	};

	return basefound;
};

set<uint> DlgWdbeUtlMrgip::StatShrTrg::comm(
			const StatShrTrg* comp
		) {
	set<uint> items;

	if (UldActive == comp->UldActive) insert(items, ULDACTIVE);

	return(items);
};

set<uint> DlgWdbeUtlMrgip::StatShrTrg::diff(
			const StatShrTrg* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {ULDACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeUtlMrgip::Tag
 ******************************************************************************/

DlgWdbeUtlMrgip::Tag::Tag(
			const string& Cpt
			, const string& ButDne
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->ButDne = ButDne;

	mask = {CPT, BUTDNE};
};

bool DlgWdbeUtlMrgip::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWdbeUtlMrgip");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWdbeUtlMrgip";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButDne", ButDne)) add(BUTDNE);
	};

	return basefound;
};

/******************************************************************************
 class DlgWdbeUtlMrgip::TagLfi
 ******************************************************************************/

DlgWdbeUtlMrgip::TagLfi::TagLfi(
			const string& Dld
		) :
			Block()
		{
	this->Dld = Dld;

	mask = {DLD};
};

bool DlgWdbeUtlMrgip::TagLfi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWdbeUtlMrgipLfi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWdbeUtlMrgipLfi";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Dld", Dld)) add(DLD);
	};

	return basefound;
};

/******************************************************************************
 class DlgWdbeUtlMrgip::TagMrg
 ******************************************************************************/

DlgWdbeUtlMrgip::TagMrg::TagMrg(
			const string& CptPrg
			, const string& ButRun
			, const string& ButSto
		) :
			Block()
		{
	this->CptPrg = CptPrg;
	this->ButRun = ButRun;
	this->ButSto = ButSto;

	mask = {CPTPRG, BUTRUN, BUTSTO};
};

bool DlgWdbeUtlMrgip::TagMrg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWdbeUtlMrgipMrg");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWdbeUtlMrgipMrg";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrg", CptPrg)) add(CPTPRG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButRun", ButRun)) add(BUTRUN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButSto", ButSto)) add(BUTSTO);
	};

	return basefound;
};

/******************************************************************************
 class DlgWdbeUtlMrgip::TagRes
 ******************************************************************************/

DlgWdbeUtlMrgip::TagRes::TagRes(
			const string& Dld
		) :
			Block()
		{
	this->Dld = Dld;

	mask = {DLD};
};

bool DlgWdbeUtlMrgip::TagRes::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWdbeUtlMrgipRes");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWdbeUtlMrgipRes";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Dld", Dld)) add(DLD);
	};

	return basefound;
};

/******************************************************************************
 class DlgWdbeUtlMrgip::TagSrc
 ******************************************************************************/

DlgWdbeUtlMrgip::TagSrc::TagSrc(
			const string& Uld
			, const string& Cpt
		) :
			Block()
		{
	this->Uld = Uld;
	this->Cpt = Cpt;

	mask = {ULD, CPT};
};

bool DlgWdbeUtlMrgip::TagSrc::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWdbeUtlMrgipSrc");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWdbeUtlMrgipSrc";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Uld", Uld)) add(ULD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class DlgWdbeUtlMrgip::TagTrg
 ******************************************************************************/

DlgWdbeUtlMrgip::TagTrg::TagTrg(
			const string& Uld
			, const string& Cpt
		) :
			Block()
		{
	this->Uld = Uld;
	this->Cpt = Cpt;

	mask = {ULD, CPT};
};

bool DlgWdbeUtlMrgip::TagTrg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWdbeUtlMrgipTrg");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWdbeUtlMrgipTrg";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Uld", Uld)) add(ULD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class DlgWdbeUtlMrgip::DpchAppData
 ******************************************************************************/

DlgWdbeUtlMrgip::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPDLGWDBEUTLMRGIPDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string DlgWdbeUtlMrgip::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbeUtlMrgip::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgWdbeUtlMrgipData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeUtlMrgip::DpchAppDo
 ******************************************************************************/

DlgWdbeUtlMrgip::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const uint ixVDoMrg
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPDLGWDBEUTLMRGIPDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO, IXVDOMRG};
	else this->mask = mask;

	this->ixVDo = ixVDo;
	this->ixVDoMrg = ixVDoMrg;
};

string DlgWdbeUtlMrgip::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");
	if (has(IXVDOMRG)) ss.push_back("ixVDoMrg");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbeUtlMrgip::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgWdbeUtlMrgipDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
		if (has(IXVDOMRG)) writeString(wr, "srefIxVDoMrg", VecVDoMrg::getSref(ixVDoMrg));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeUtlMrgip::DpchEngData
 ******************************************************************************/

DlgWdbeUtlMrgip::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGDLGWDBEUTLMRGIPDATA)
		{
	feedFDse.tag = "FeedFDse";
	feedFSge.tag = "FeedFSge";
};

string DlgWdbeUtlMrgip::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(CONTINFLFI)) ss.push_back("continflfi");
	if (has(CONTINFMRG)) ss.push_back("continfmrg");
	if (has(CONTINFRES)) ss.push_back("continfres");
	if (has(FEEDFDSE)) ss.push_back("feedFDse");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(STATSHRLFI)) ss.push_back("statshrlfi");
	if (has(STATSHRMRG)) ss.push_back("statshrmrg");
	if (has(STATSHRRES)) ss.push_back("statshrres");
	if (has(STATSHRSRC)) ss.push_back("statshrsrc");
	if (has(STATSHRTRG)) ss.push_back("statshrtrg");
	if (has(TAG)) ss.push_back("tag");
	if (has(TAGLFI)) ss.push_back("taglfi");
	if (has(TAGMRG)) ss.push_back("tagmrg");
	if (has(TAGRES)) ss.push_back("tagres");
	if (has(TAGSRC)) ss.push_back("tagsrc");
	if (has(TAGTRG)) ss.push_back("tagtrg");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbeUtlMrgip::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngDlgWdbeUtlMrgipData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (continflfi.readXML(docctx, basexpath, true)) add(CONTINFLFI);
		if (continfmrg.readXML(docctx, basexpath, true)) add(CONTINFMRG);
		if (continfres.readXML(docctx, basexpath, true)) add(CONTINFRES);
		if (feedFDse.readXML(docctx, basexpath, true)) add(FEEDFDSE);
		if (feedFSge.readXML(docctx, basexpath, true)) add(FEEDFSGE);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (statshrlfi.readXML(docctx, basexpath, true)) add(STATSHRLFI);
		if (statshrmrg.readXML(docctx, basexpath, true)) add(STATSHRMRG);
		if (statshrres.readXML(docctx, basexpath, true)) add(STATSHRRES);
		if (statshrsrc.readXML(docctx, basexpath, true)) add(STATSHRSRC);
		if (statshrtrg.readXML(docctx, basexpath, true)) add(STATSHRTRG);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
		if (taglfi.readXML(docctx, basexpath, true)) add(TAGLFI);
		if (tagmrg.readXML(docctx, basexpath, true)) add(TAGMRG);
		if (tagres.readXML(docctx, basexpath, true)) add(TAGRES);
		if (tagsrc.readXML(docctx, basexpath, true)) add(TAGSRC);
		if (tagtrg.readXML(docctx, basexpath, true)) add(TAGTRG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		continflfi = ContInfLfi();
		continfmrg = ContInfMrg();
		continfres = ContInfRes();
		feedFDse.clear();
		feedFSge.clear();
		statapp = StatApp();
		statshr = StatShr();
		statshrlfi = StatShrLfi();
		statshrmrg = StatShrMrg();
		statshrres = StatShrRes();
		statshrsrc = StatShrSrc();
		statshrtrg = StatShrTrg();
		tag = Tag();
		taglfi = TagLfi();
		tagmrg = TagMrg();
		tagres = TagRes();
		tagsrc = TagSrc();
		tagtrg = TagTrg();
	};
};

