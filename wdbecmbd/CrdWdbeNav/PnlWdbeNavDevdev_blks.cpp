/**
	* \file PnlWdbeNavDevdev_blks.cpp
	* job handler for job PnlWdbeNavDevdev (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbeNavDevdev::VecVDo
 ******************************************************************************/

uint PnlWdbeNavDevdev::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butprjviewclick") return BUTPRJVIEWCLICK;
	if (s == "butprjnewcrdclick") return BUTPRJNEWCRDCLICK;
	if (s == "butverviewclick") return BUTVERVIEWCLICK;
	if (s == "butvernewcrdclick") return BUTVERNEWCRDCLICK;
	if (s == "butsysviewclick") return BUTSYSVIEWCLICK;
	if (s == "butsysnewcrdclick") return BUTSYSNEWCRDCLICK;
	if (s == "buttrgviewclick") return BUTTRGVIEWCLICK;
	if (s == "buttrgnewcrdclick") return BUTTRGNEWCRDCLICK;
	if (s == "butuntviewclick") return BUTUNTVIEWCLICK;
	if (s == "butuntnewcrdclick") return BUTUNTNEWCRDCLICK;
	if (s == "butrlsviewclick") return BUTRLSVIEWCLICK;
	if (s == "butrlsnewcrdclick") return BUTRLSNEWCRDCLICK;

	return(0);
};

string PnlWdbeNavDevdev::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTPRJVIEWCLICK) return("ButPrjViewClick");
	if (ix == BUTPRJNEWCRDCLICK) return("ButPrjNewcrdClick");
	if (ix == BUTVERVIEWCLICK) return("ButVerViewClick");
	if (ix == BUTVERNEWCRDCLICK) return("ButVerNewcrdClick");
	if (ix == BUTSYSVIEWCLICK) return("ButSysViewClick");
	if (ix == BUTSYSNEWCRDCLICK) return("ButSysNewcrdClick");
	if (ix == BUTTRGVIEWCLICK) return("ButTrgViewClick");
	if (ix == BUTTRGNEWCRDCLICK) return("ButTrgNewcrdClick");
	if (ix == BUTUNTVIEWCLICK) return("ButUntViewClick");
	if (ix == BUTUNTNEWCRDCLICK) return("ButUntNewcrdClick");
	if (ix == BUTRLSVIEWCLICK) return("ButRlsViewClick");
	if (ix == BUTRLSNEWCRDCLICK) return("ButRlsNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlWdbeNavDevdev::ContIac
 ******************************************************************************/

PnlWdbeNavDevdev::ContIac::ContIac(
			const uint numFLstPrj
			, const uint numFLstVer
			, const uint numFLstSys
			, const uint numFLstTrg
			, const uint numFLstUnt
			, const uint numFLstRls
		) :
			Block()
		{
	this->numFLstPrj = numFLstPrj;
	this->numFLstVer = numFLstVer;
	this->numFLstSys = numFLstSys;
	this->numFLstTrg = numFLstTrg;
	this->numFLstUnt = numFLstUnt;
	this->numFLstRls = numFLstRls;

	mask = {NUMFLSTPRJ, NUMFLSTVER, NUMFLSTSYS, NUMFLSTTRG, NUMFLSTUNT, NUMFLSTRLS};
};

bool PnlWdbeNavDevdev::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWdbeNavDevdev");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWdbeNavDevdev";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstPrj", numFLstPrj)) add(NUMFLSTPRJ);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstVer", numFLstVer)) add(NUMFLSTVER);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstSys", numFLstSys)) add(NUMFLSTSYS);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstTrg", numFLstTrg)) add(NUMFLSTTRG);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstUnt", numFLstUnt)) add(NUMFLSTUNT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstRls", numFLstRls)) add(NUMFLSTRLS);
	};

	return basefound;
};

void PnlWdbeNavDevdev::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeNavDevdev";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWdbeNavDevdev";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstPrj", numFLstPrj);
		writeUintAttr(wr, itemtag, "sref", "numFLstVer", numFLstVer);
		writeUintAttr(wr, itemtag, "sref", "numFLstSys", numFLstSys);
		writeUintAttr(wr, itemtag, "sref", "numFLstTrg", numFLstTrg);
		writeUintAttr(wr, itemtag, "sref", "numFLstUnt", numFLstUnt);
		writeUintAttr(wr, itemtag, "sref", "numFLstRls", numFLstRls);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeNavDevdev::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstPrj == comp->numFLstPrj) insert(items, NUMFLSTPRJ);
	if (numFLstVer == comp->numFLstVer) insert(items, NUMFLSTVER);
	if (numFLstSys == comp->numFLstSys) insert(items, NUMFLSTSYS);
	if (numFLstTrg == comp->numFLstTrg) insert(items, NUMFLSTTRG);
	if (numFLstUnt == comp->numFLstUnt) insert(items, NUMFLSTUNT);
	if (numFLstRls == comp->numFLstRls) insert(items, NUMFLSTRLS);

	return(items);
};

set<uint> PnlWdbeNavDevdev::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTPRJ, NUMFLSTVER, NUMFLSTSYS, NUMFLSTTRG, NUMFLSTUNT, NUMFLSTRLS};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeNavDevdev::StatApp
 ******************************************************************************/

void PnlWdbeNavDevdev::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWdbeVExpstate
			, const bool LstPrjAlt
			, const bool LstVerAlt
			, const bool LstSysAlt
			, const bool LstTrgAlt
			, const bool LstUntAlt
			, const bool LstRlsAlt
			, const uint LstPrjNumFirstdisp
			, const uint LstVerNumFirstdisp
			, const uint LstSysNumFirstdisp
			, const uint LstTrgNumFirstdisp
			, const uint LstUntNumFirstdisp
			, const uint LstRlsNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeNavDevdev";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWdbeNavDevdev";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWdbeVExpstate", VecWdbeVExpstate::getSref(ixWdbeVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstPrjAlt", LstPrjAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstVerAlt", LstVerAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstSysAlt", LstSysAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstTrgAlt", LstTrgAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstUntAlt", LstUntAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstRlsAlt", LstRlsAlt);
		writeUintAttr(wr, itemtag, "sref", "LstPrjNumFirstdisp", LstPrjNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstVerNumFirstdisp", LstVerNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstSysNumFirstdisp", LstSysNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstTrgNumFirstdisp", LstTrgNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstUntNumFirstdisp", LstUntNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstRlsNumFirstdisp", LstRlsNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeNavDevdev::StatShr
 ******************************************************************************/

PnlWdbeNavDevdev::StatShr::StatShr(
			const bool LstPrjAvail
			, const bool ButPrjViewActive
			, const bool LstVerAvail
			, const bool ButVerViewActive
			, const bool LstSysAvail
			, const bool ButSysViewActive
			, const bool ButSysNewcrdActive
			, const bool LstTrgAvail
			, const bool ButTrgViewActive
			, const bool ButTrgNewcrdActive
			, const bool LstUntAvail
			, const bool ButUntViewActive
			, const bool ButUntNewcrdActive
			, const bool LstRlsAvail
			, const bool ButRlsViewActive
			, const bool ButRlsNewcrdActive
		) :
			Block()
		{
	this->LstPrjAvail = LstPrjAvail;
	this->ButPrjViewActive = ButPrjViewActive;
	this->LstVerAvail = LstVerAvail;
	this->ButVerViewActive = ButVerViewActive;
	this->LstSysAvail = LstSysAvail;
	this->ButSysViewActive = ButSysViewActive;
	this->ButSysNewcrdActive = ButSysNewcrdActive;
	this->LstTrgAvail = LstTrgAvail;
	this->ButTrgViewActive = ButTrgViewActive;
	this->ButTrgNewcrdActive = ButTrgNewcrdActive;
	this->LstUntAvail = LstUntAvail;
	this->ButUntViewActive = ButUntViewActive;
	this->ButUntNewcrdActive = ButUntNewcrdActive;
	this->LstRlsAvail = LstRlsAvail;
	this->ButRlsViewActive = ButRlsViewActive;
	this->ButRlsNewcrdActive = ButRlsNewcrdActive;

	mask = {LSTPRJAVAIL, BUTPRJVIEWACTIVE, LSTVERAVAIL, BUTVERVIEWACTIVE, LSTSYSAVAIL, BUTSYSVIEWACTIVE, BUTSYSNEWCRDACTIVE, LSTTRGAVAIL, BUTTRGVIEWACTIVE, BUTTRGNEWCRDACTIVE, LSTUNTAVAIL, BUTUNTVIEWACTIVE, BUTUNTNEWCRDACTIVE, LSTRLSAVAIL, BUTRLSVIEWACTIVE, BUTRLSNEWCRDACTIVE};
};

void PnlWdbeNavDevdev::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeNavDevdev";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWdbeNavDevdev";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "LstPrjAvail", LstPrjAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButPrjViewActive", ButPrjViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstVerAvail", LstVerAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButVerViewActive", ButVerViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstSysAvail", LstSysAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSysViewActive", ButSysViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButSysNewcrdActive", ButSysNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstTrgAvail", LstTrgAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButTrgViewActive", ButTrgViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButTrgNewcrdActive", ButTrgNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstUntAvail", LstUntAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButUntViewActive", ButUntViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButUntNewcrdActive", ButUntNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstRlsAvail", LstRlsAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButRlsViewActive", ButRlsViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButRlsNewcrdActive", ButRlsNewcrdActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeNavDevdev::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstPrjAvail == comp->LstPrjAvail) insert(items, LSTPRJAVAIL);
	if (ButPrjViewActive == comp->ButPrjViewActive) insert(items, BUTPRJVIEWACTIVE);
	if (LstVerAvail == comp->LstVerAvail) insert(items, LSTVERAVAIL);
	if (ButVerViewActive == comp->ButVerViewActive) insert(items, BUTVERVIEWACTIVE);
	if (LstSysAvail == comp->LstSysAvail) insert(items, LSTSYSAVAIL);
	if (ButSysViewActive == comp->ButSysViewActive) insert(items, BUTSYSVIEWACTIVE);
	if (ButSysNewcrdActive == comp->ButSysNewcrdActive) insert(items, BUTSYSNEWCRDACTIVE);
	if (LstTrgAvail == comp->LstTrgAvail) insert(items, LSTTRGAVAIL);
	if (ButTrgViewActive == comp->ButTrgViewActive) insert(items, BUTTRGVIEWACTIVE);
	if (ButTrgNewcrdActive == comp->ButTrgNewcrdActive) insert(items, BUTTRGNEWCRDACTIVE);
	if (LstUntAvail == comp->LstUntAvail) insert(items, LSTUNTAVAIL);
	if (ButUntViewActive == comp->ButUntViewActive) insert(items, BUTUNTVIEWACTIVE);
	if (ButUntNewcrdActive == comp->ButUntNewcrdActive) insert(items, BUTUNTNEWCRDACTIVE);
	if (LstRlsAvail == comp->LstRlsAvail) insert(items, LSTRLSAVAIL);
	if (ButRlsViewActive == comp->ButRlsViewActive) insert(items, BUTRLSVIEWACTIVE);
	if (ButRlsNewcrdActive == comp->ButRlsNewcrdActive) insert(items, BUTRLSNEWCRDACTIVE);

	return(items);
};

set<uint> PnlWdbeNavDevdev::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTPRJAVAIL, BUTPRJVIEWACTIVE, LSTVERAVAIL, BUTVERVIEWACTIVE, LSTSYSAVAIL, BUTSYSVIEWACTIVE, BUTSYSNEWCRDACTIVE, LSTTRGAVAIL, BUTTRGVIEWACTIVE, BUTTRGNEWCRDACTIVE, LSTUNTAVAIL, BUTUNTVIEWACTIVE, BUTUNTNEWCRDACTIVE, LSTRLSAVAIL, BUTRLSVIEWACTIVE, BUTRLSNEWCRDACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeNavDevdev::Tag
 ******************************************************************************/

void PnlWdbeNavDevdev::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWdbeNavDevdev";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWdbeNavDevdev";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Device development module");
			writeStringAttr(wr, itemtag, "sref", "CptPrj", "projects");
			writeStringAttr(wr, itemtag, "sref", "CptVer", "versions");
			writeStringAttr(wr, itemtag, "sref", "CptSys", "systems");
			writeStringAttr(wr, itemtag, "sref", "CptTrg", "targets");
			writeStringAttr(wr, itemtag, "sref", "CptUnt", "units");
			writeStringAttr(wr, itemtag, "sref", "CptRls", "releases");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeNavDevdev::DpchAppData
 ******************************************************************************/

PnlWdbeNavDevdev::DpchAppData::DpchAppData() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBENAVDEVDEVDATA)
		{
};

string PnlWdbeNavDevdev::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavDevdev::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeNavDevdevData");
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
 class PnlWdbeNavDevdev::DpchAppDo
 ******************************************************************************/

PnlWdbeNavDevdev::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBENAVDEVDEVDO)
		{
	ixVDo = 0;
};

string PnlWdbeNavDevdev::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavDevdev::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeNavDevdevDo");
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
 class PnlWdbeNavDevdev::DpchEngData
 ******************************************************************************/

PnlWdbeNavDevdev::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, Feed* feedFLstPrj
			, Feed* feedFLstRls
			, Feed* feedFLstSys
			, Feed* feedFLstTrg
			, Feed* feedFLstUnt
			, Feed* feedFLstVer
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBENAVDEVDEVDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, FEEDFLSTPRJ, FEEDFLSTRLS, FEEDFLSTSYS, FEEDFLSTTRG, FEEDFLSTUNT, FEEDFLSTVER, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, FEEDFLSTPRJ) && feedFLstPrj) this->feedFLstPrj = *feedFLstPrj;
	if (find(this->mask, FEEDFLSTRLS) && feedFLstRls) this->feedFLstRls = *feedFLstRls;
	if (find(this->mask, FEEDFLSTSYS) && feedFLstSys) this->feedFLstSys = *feedFLstSys;
	if (find(this->mask, FEEDFLSTTRG) && feedFLstTrg) this->feedFLstTrg = *feedFLstTrg;
	if (find(this->mask, FEEDFLSTUNT) && feedFLstUnt) this->feedFLstUnt = *feedFLstUnt;
	if (find(this->mask, FEEDFLSTVER) && feedFLstVer) this->feedFLstVer = *feedFLstVer;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWdbeNavDevdev::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTPRJ)) ss.push_back("feedFLstPrj");
	if (has(FEEDFLSTRLS)) ss.push_back("feedFLstRls");
	if (has(FEEDFLSTSYS)) ss.push_back("feedFLstSys");
	if (has(FEEDFLSTTRG)) ss.push_back("feedFLstTrg");
	if (has(FEEDFLSTUNT)) ss.push_back("feedFLstUnt");
	if (has(FEEDFLSTVER)) ss.push_back("feedFLstVer");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavDevdev::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(FEEDFLSTPRJ)) {feedFLstPrj = src->feedFLstPrj; add(FEEDFLSTPRJ);};
	if (src->has(FEEDFLSTRLS)) {feedFLstRls = src->feedFLstRls; add(FEEDFLSTRLS);};
	if (src->has(FEEDFLSTSYS)) {feedFLstSys = src->feedFLstSys; add(FEEDFLSTSYS);};
	if (src->has(FEEDFLSTTRG)) {feedFLstTrg = src->feedFLstTrg; add(FEEDFLSTTRG);};
	if (src->has(FEEDFLSTUNT)) {feedFLstUnt = src->feedFLstUnt; add(FEEDFLSTUNT);};
	if (src->has(FEEDFLSTVER)) {feedFLstVer = src->feedFLstVer; add(FEEDFLSTVER);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWdbeNavDevdev::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWdbeNavDevdevData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(FEEDFLSTPRJ)) feedFLstPrj.writeXML(wr);
		if (has(FEEDFLSTRLS)) feedFLstRls.writeXML(wr);
		if (has(FEEDFLSTSYS)) feedFLstSys.writeXML(wr);
		if (has(FEEDFLSTTRG)) feedFLstTrg.writeXML(wr);
		if (has(FEEDFLSTUNT)) feedFLstUnt.writeXML(wr);
		if (has(FEEDFLSTVER)) feedFLstVer.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};
