/**
	* \file DlgWdbeRlsFinreptr_blks.cpp
	* job handler for job DlgWdbeRlsFinreptr (implementation of blocks)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DlgWdbeRlsFinreptr::VecVDit
 ******************************************************************************/

uint DlgWdbeRlsFinreptr::VecVDit::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "fin") return FIN;
	if (s == "res") return RES;

	return(0);
};

string DlgWdbeRlsFinreptr::VecVDit::getSref(
			const uint ix
		) {
	if (ix == FIN) return("Fin");
	if (ix == RES) return("Res");

	return("");
};

string DlgWdbeRlsFinreptr::VecVDit::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == FIN) return("Details");
		if (ix == RES) return("Result");
		return(getSref(ix));
	};

	return("");
};

void DlgWdbeRlsFinreptr::VecVDit::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};

/******************************************************************************
 class DlgWdbeRlsFinreptr::VecVDo
 ******************************************************************************/

uint DlgWdbeRlsFinreptr::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butdneclick") return BUTDNECLICK;

	return(0);
};

string DlgWdbeRlsFinreptr::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgWdbeRlsFinreptr::VecVDoFin
 ******************************************************************************/

uint DlgWdbeRlsFinreptr::VecVDoFin::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butrunclick") return BUTRUNCLICK;
	if (s == "butstoclick") return BUTSTOCLICK;

	return(0);
};

string DlgWdbeRlsFinreptr::VecVDoFin::getSref(
			const uint ix
		) {
	if (ix == BUTRUNCLICK) return("ButRunClick");
	if (ix == BUTSTOCLICK) return("ButStoClick");

	return("");
};

/******************************************************************************
 class DlgWdbeRlsFinreptr::VecVDoRes
 ******************************************************************************/

uint DlgWdbeRlsFinreptr::VecVDoRes::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butpsgclick") return BUTPSGCLICK;

	return(0);
};

string DlgWdbeRlsFinreptr::VecVDoRes::getSref(
			const uint ix
		) {
	if (ix == BUTPSGCLICK) return("ButPsgClick");

	return("");
};

/******************************************************************************
 class DlgWdbeRlsFinreptr::VecVSge
 ******************************************************************************/

uint DlgWdbeRlsFinreptr::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "alrgnf") return ALRGNF;
	if (s == "alrgad") return ALRGAD;
	if (s == "finidle") return FINIDLE;
	if (s == "pack") return PACK;
	if (s == "commit") return COMMIT;
	if (s == "findone") return FINDONE;
	if (s == "psgidle") return PSGIDLE;
	if (s == "pushgit") return PUSHGIT;
	if (s == "done") return DONE;

	return(0);
};

string DlgWdbeRlsFinreptr::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRGNF) return("alrgnf");
	if (ix == ALRGAD) return("alrgad");
	if (ix == FINIDLE) return("finidle");
	if (ix == PACK) return("pack");
	if (ix == COMMIT) return("commit");
	if (ix == FINDONE) return("findone");
	if (ix == PSGIDLE) return("psgidle");
	if (ix == PUSHGIT) return("pushgit");
	if (ix == DONE) return("done");

	return("");
};

void DlgWdbeRlsFinreptr::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 10; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class DlgWdbeRlsFinreptr::ContIac
 ******************************************************************************/

DlgWdbeRlsFinreptr::ContIac::ContIac(
			const uint numFDse
		) :
			Block()
		{
	this->numFDse = numFDse;

	mask = {NUMFDSE};
};

bool DlgWdbeRlsFinreptr::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgWdbeRlsFinreptr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgWdbeRlsFinreptr";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDse", numFDse)) add(NUMFDSE);
	};

	return basefound;
};

void DlgWdbeRlsFinreptr::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWdbeRlsFinreptr";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgWdbeRlsFinreptr";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFDse", numFDse);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeRlsFinreptr::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFDse == comp->numFDse) insert(items, NUMFDSE);

	return(items);
};

set<uint> DlgWdbeRlsFinreptr::ContIac::diff(
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
 class DlgWdbeRlsFinreptr::ContInf
 ******************************************************************************/

DlgWdbeRlsFinreptr::ContInf::ContInf(
			const uint numFSge
		) :
			Block()
		{
	this->numFSge = numFSge;

	mask = {NUMFSGE};
};

void DlgWdbeRlsFinreptr::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWdbeRlsFinreptr";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWdbeRlsFinreptr";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeRlsFinreptr::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);

	return(items);
};

set<uint> DlgWdbeRlsFinreptr::ContInf::diff(
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
 class DlgWdbeRlsFinreptr::ContInfFin
 ******************************************************************************/

DlgWdbeRlsFinreptr::ContInfFin::ContInfFin(
			const string& TxtPrg
		) :
			Block()
		{
	this->TxtPrg = TxtPrg;

	mask = {TXTPRG};
};

void DlgWdbeRlsFinreptr::ContInfFin::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWdbeRlsFinreptrFin";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWdbeRlsFinreptrFin";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtPrg", TxtPrg);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeRlsFinreptr::ContInfFin::comm(
			const ContInfFin* comp
		) {
	set<uint> items;

	if (TxtPrg == comp->TxtPrg) insert(items, TXTPRG);

	return(items);
};

set<uint> DlgWdbeRlsFinreptr::ContInfFin::diff(
			const ContInfFin* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTPRG};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeRlsFinreptr::ContInfRes
 ******************************************************************************/

DlgWdbeRlsFinreptr::ContInfRes::ContInfRes(
			const string& Dld
			, const string& TxtPrg
		) :
			Block()
		{
	this->Dld = Dld;
	this->TxtPrg = TxtPrg;

	mask = {DLD, TXTPRG};
};

void DlgWdbeRlsFinreptr::ContInfRes::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWdbeRlsFinreptrRes";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWdbeRlsFinreptrRes";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "Dld", Dld);
		writeStringAttr(wr, itemtag, "sref", "TxtPrg", TxtPrg);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeRlsFinreptr::ContInfRes::comm(
			const ContInfRes* comp
		) {
	set<uint> items;

	if (Dld == comp->Dld) insert(items, DLD);
	if (TxtPrg == comp->TxtPrg) insert(items, TXTPRG);

	return(items);
};

set<uint> DlgWdbeRlsFinreptr::ContInfRes::diff(
			const ContInfRes* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {DLD, TXTPRG};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeRlsFinreptr::StatApp
 ******************************************************************************/

void DlgWdbeRlsFinreptr::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdone
			, const string& shortMenu
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgWdbeRlsFinreptr";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppDlgWdbeRlsFinreptr";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdone", initdone);
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeRlsFinreptr::StatShr
 ******************************************************************************/

DlgWdbeRlsFinreptr::StatShr::StatShr(
			const bool ButDneActive
		) :
			Block()
		{
	this->ButDneActive = ButDneActive;

	mask = {BUTDNEACTIVE};
};

void DlgWdbeRlsFinreptr::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWdbeRlsFinreptr";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWdbeRlsFinreptr";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButDneActive", ButDneActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeRlsFinreptr::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButDneActive == comp->ButDneActive) insert(items, BUTDNEACTIVE);

	return(items);
};

set<uint> DlgWdbeRlsFinreptr::StatShr::diff(
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
 class DlgWdbeRlsFinreptr::StatShrFin
 ******************************************************************************/

DlgWdbeRlsFinreptr::StatShrFin::StatShrFin(
			const bool ButRunActive
			, const bool ButStoActive
		) :
			Block()
		{
	this->ButRunActive = ButRunActive;
	this->ButStoActive = ButStoActive;

	mask = {BUTRUNACTIVE, BUTSTOACTIVE};
};

void DlgWdbeRlsFinreptr::StatShrFin::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWdbeRlsFinreptrFin";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWdbeRlsFinreptrFin";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButRunActive", ButRunActive);
		writeBoolAttr(wr, itemtag, "sref", "ButStoActive", ButStoActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeRlsFinreptr::StatShrFin::comm(
			const StatShrFin* comp
		) {
	set<uint> items;

	if (ButRunActive == comp->ButRunActive) insert(items, BUTRUNACTIVE);
	if (ButStoActive == comp->ButStoActive) insert(items, BUTSTOACTIVE);

	return(items);
};

set<uint> DlgWdbeRlsFinreptr::StatShrFin::diff(
			const StatShrFin* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTRUNACTIVE, BUTSTOACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeRlsFinreptr::StatShrRes
 ******************************************************************************/

DlgWdbeRlsFinreptr::StatShrRes::StatShrRes(
			const bool DldAvail
			, const bool DldActive
			, const bool TxtPrgAvail
			, const bool Sep1Avail
			, const bool ButPsgAvail
			, const bool ButPsgActive
		) :
			Block()
		{
	this->DldAvail = DldAvail;
	this->DldActive = DldActive;
	this->TxtPrgAvail = TxtPrgAvail;
	this->Sep1Avail = Sep1Avail;
	this->ButPsgAvail = ButPsgAvail;
	this->ButPsgActive = ButPsgActive;

	mask = {DLDAVAIL, DLDACTIVE, TXTPRGAVAIL, SEP1AVAIL, BUTPSGAVAIL, BUTPSGACTIVE};
};

void DlgWdbeRlsFinreptr::StatShrRes::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWdbeRlsFinreptrRes";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWdbeRlsFinreptrRes";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "DldAvail", DldAvail);
		writeBoolAttr(wr, itemtag, "sref", "DldActive", DldActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtPrgAvail", TxtPrgAvail);
		writeBoolAttr(wr, itemtag, "sref", "Sep1Avail", Sep1Avail);
		writeBoolAttr(wr, itemtag, "sref", "ButPsgAvail", ButPsgAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButPsgActive", ButPsgActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWdbeRlsFinreptr::StatShrRes::comm(
			const StatShrRes* comp
		) {
	set<uint> items;

	if (DldAvail == comp->DldAvail) insert(items, DLDAVAIL);
	if (DldActive == comp->DldActive) insert(items, DLDACTIVE);
	if (TxtPrgAvail == comp->TxtPrgAvail) insert(items, TXTPRGAVAIL);
	if (Sep1Avail == comp->Sep1Avail) insert(items, SEP1AVAIL);
	if (ButPsgAvail == comp->ButPsgAvail) insert(items, BUTPSGAVAIL);
	if (ButPsgActive == comp->ButPsgActive) insert(items, BUTPSGACTIVE);

	return(items);
};

set<uint> DlgWdbeRlsFinreptr::StatShrRes::diff(
			const StatShrRes* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {DLDAVAIL, DLDACTIVE, TXTPRGAVAIL, SEP1AVAIL, BUTPSGAVAIL, BUTPSGACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWdbeRlsFinreptr::Tag
 ******************************************************************************/

void DlgWdbeRlsFinreptr::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWdbeRlsFinreptr";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWdbeRlsFinreptr";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Finalize repository transaction");
		};
		writeStringAttr(wr, itemtag, "sref", "ButDne", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DONE, ixWdbeVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeRlsFinreptr::TagFin
 ******************************************************************************/

void DlgWdbeRlsFinreptr::TagFin::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWdbeRlsFinreptrFin";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWdbeRlsFinreptrFin";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		};
		writeStringAttr(wr, itemtag, "sref", "CptPrg", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::PROGRESS, ixWdbeVLocale)));
		writeStringAttr(wr, itemtag, "sref", "ButRun", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::RUN, ixWdbeVLocale)));
		writeStringAttr(wr, itemtag, "sref", "ButSto", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::STOP, ixWdbeVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeRlsFinreptr::TagRes
 ******************************************************************************/

void DlgWdbeRlsFinreptr::TagRes::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWdbeRlsFinreptrRes";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWdbeRlsFinreptrRes";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "ButPsg", "Push Git");
		};
		writeStringAttr(wr, itemtag, "sref", "Dld", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DOWNLOAD, ixWdbeVLocale)));
		writeStringAttr(wr, itemtag, "sref", "CptPrg", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::PROGRESS, ixWdbeVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWdbeRlsFinreptr::DpchAppData
 ******************************************************************************/

DlgWdbeRlsFinreptr::DpchAppData::DpchAppData() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPDLGWDBERLSFINREPTRDATA)
		{
};

string DlgWdbeRlsFinreptr::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbeRlsFinreptr::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgWdbeRlsFinreptrData");
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
 class DlgWdbeRlsFinreptr::DpchAppDo
 ******************************************************************************/

DlgWdbeRlsFinreptr::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPDLGWDBERLSFINREPTRDO)
		{
	ixVDo = 0;
	ixVDoFin = 0;
	ixVDoRes = 0;
};

string DlgWdbeRlsFinreptr::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");
	if (has(IXVDOFIN)) ss.push_back("ixVDoFin");
	if (has(IXVDORES)) ss.push_back("ixVDoRes");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbeRlsFinreptr::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;
	string srefIxVDoFin;
	string srefIxVDoRes;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgWdbeRlsFinreptrDo");
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
		if (extractStringUclc(docctx, basexpath, "srefIxVDoFin", "", srefIxVDoFin)) {
			ixVDoFin = VecVDoFin::getIx(srefIxVDoFin);
			add(IXVDOFIN);
		};
		if (extractStringUclc(docctx, basexpath, "srefIxVDoRes", "", srefIxVDoRes)) {
			ixVDoRes = VecVDoRes::getIx(srefIxVDoRes);
			add(IXVDORES);
		};
	} else {
	};
};

/******************************************************************************
 class DlgWdbeRlsFinreptr::DpchEngData
 ******************************************************************************/

DlgWdbeRlsFinreptr::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, ContInfFin* continffin
			, ContInfRes* continfres
			, Feed* feedFDse
			, Feed* feedFSge
			, StatShr* statshr
			, StatShrFin* statshrfin
			, StatShrRes* statshrres
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGDLGWDBERLSFINREPTRDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, CONTINFFIN, CONTINFRES, FEEDFDSE, FEEDFSGE, STATAPP, STATSHR, STATSHRFIN, STATSHRRES, TAG, TAGFIN, TAGRES};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, CONTINFFIN) && continffin) this->continffin = *continffin;
	if (find(this->mask, CONTINFRES) && continfres) this->continfres = *continfres;
	if (find(this->mask, FEEDFDSE) && feedFDse) this->feedFDse = *feedFDse;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
	if (find(this->mask, STATSHRFIN) && statshrfin) this->statshrfin = *statshrfin;
	if (find(this->mask, STATSHRRES) && statshrres) this->statshrres = *statshrres;
};

string DlgWdbeRlsFinreptr::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(CONTINFFIN)) ss.push_back("continffin");
	if (has(CONTINFRES)) ss.push_back("continfres");
	if (has(FEEDFDSE)) ss.push_back("feedFDse");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(STATSHRFIN)) ss.push_back("statshrfin");
	if (has(STATSHRRES)) ss.push_back("statshrres");
	if (has(TAG)) ss.push_back("tag");
	if (has(TAGFIN)) ss.push_back("tagfin");
	if (has(TAGRES)) ss.push_back("tagres");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWdbeRlsFinreptr::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(CONTINFFIN)) {continffin = src->continffin; add(CONTINFFIN);};
	if (src->has(CONTINFRES)) {continfres = src->continfres; add(CONTINFRES);};
	if (src->has(FEEDFDSE)) {feedFDse = src->feedFDse; add(FEEDFDSE);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(STATSHRFIN)) {statshrfin = src->statshrfin; add(STATSHRFIN);};
	if (src->has(STATSHRRES)) {statshrres = src->statshrres; add(STATSHRRES);};
	if (src->has(TAG)) add(TAG);
	if (src->has(TAGFIN)) add(TAGFIN);
	if (src->has(TAGRES)) add(TAGRES);
};

void DlgWdbeRlsFinreptr::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngDlgWdbeRlsFinreptrData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(CONTINFFIN)) continffin.writeXML(wr);
		if (has(CONTINFRES)) continfres.writeXML(wr);
		if (has(FEEDFDSE)) feedFDse.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STATSHRFIN)) statshrfin.writeXML(wr);
		if (has(STATSHRRES)) statshrres.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
		if (has(TAGFIN)) TagFin::writeXML(ixWdbeVLocale, wr);
		if (has(TAGRES)) TagRes::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};

