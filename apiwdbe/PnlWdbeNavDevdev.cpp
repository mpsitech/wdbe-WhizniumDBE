/**
	* \file PnlWdbeNavDevdev.cpp
	* API code for job PnlWdbeNavDevdev (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWdbeNavDevdev.h"

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
	if (s == "butuntviewclick") return BUTUNTVIEWCLICK;
	if (s == "butuntnewcrdclick") return BUTUNTNEWCRDCLICK;

	return(0);
};

string PnlWdbeNavDevdev::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTPRJVIEWCLICK) return("ButPrjViewClick");
	if (ix == BUTPRJNEWCRDCLICK) return("ButPrjNewcrdClick");
	if (ix == BUTVERVIEWCLICK) return("ButVerViewClick");
	if (ix == BUTVERNEWCRDCLICK) return("ButVerNewcrdClick");
	if (ix == BUTUNTVIEWCLICK) return("ButUntViewClick");
	if (ix == BUTUNTNEWCRDCLICK) return("ButUntNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlWdbeNavDevdev::ContIac
 ******************************************************************************/

PnlWdbeNavDevdev::ContIac::ContIac(
			const uint numFLstPrj
			, const uint numFLstVer
			, const uint numFLstUnt
		) :
			Block()
			, numFLstPrj(numFLstPrj)
			, numFLstVer(numFLstVer)
			, numFLstUnt(numFLstUnt)
		{
	mask = {NUMFLSTPRJ, NUMFLSTVER, NUMFLSTUNT};
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
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstUnt", numFLstUnt)) add(NUMFLSTUNT);
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
		writeUintAttr(wr, itemtag, "sref", "numFLstUnt", numFLstUnt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeNavDevdev::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstPrj == comp->numFLstPrj) insert(items, NUMFLSTPRJ);
	if (numFLstVer == comp->numFLstVer) insert(items, NUMFLSTVER);
	if (numFLstUnt == comp->numFLstUnt) insert(items, NUMFLSTUNT);

	return(items);
};

set<uint> PnlWdbeNavDevdev::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTPRJ, NUMFLSTVER, NUMFLSTUNT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeNavDevdev::StatApp
 ******************************************************************************/

PnlWdbeNavDevdev::StatApp::StatApp(
			const uint ixWdbeVExpstate
			, const bool LstPrjAlt
			, const bool LstVerAlt
			, const bool LstUntAlt
			, const uint LstPrjNumFirstdisp
			, const uint LstVerNumFirstdisp
			, const uint LstUntNumFirstdisp
		) :
			Block()
			, ixWdbeVExpstate(ixWdbeVExpstate)
			, LstPrjAlt(LstPrjAlt)
			, LstVerAlt(LstVerAlt)
			, LstUntAlt(LstUntAlt)
			, LstPrjNumFirstdisp(LstPrjNumFirstdisp)
			, LstVerNumFirstdisp(LstVerNumFirstdisp)
			, LstUntNumFirstdisp(LstUntNumFirstdisp)
		{
	mask = {IXWDBEVEXPSTATE, LSTPRJALT, LSTVERALT, LSTUNTALT, LSTPRJNUMFIRSTDISP, LSTVERNUMFIRSTDISP, LSTUNTNUMFIRSTDISP};
};

bool PnlWdbeNavDevdev::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWdbeVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWdbeNavDevdev");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWdbeNavDevdev";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", srefIxWdbeVExpstate)) {
			ixWdbeVExpstate = VecWdbeVExpstate::getIx(srefIxWdbeVExpstate);
			add(IXWDBEVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrjAlt", LstPrjAlt)) add(LSTPRJALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstVerAlt", LstVerAlt)) add(LSTVERALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstUntAlt", LstUntAlt)) add(LSTUNTALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrjNumFirstdisp", LstPrjNumFirstdisp)) add(LSTPRJNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstVerNumFirstdisp", LstVerNumFirstdisp)) add(LSTVERNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstUntNumFirstdisp", LstUntNumFirstdisp)) add(LSTUNTNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlWdbeNavDevdev::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWdbeVExpstate == comp->ixWdbeVExpstate) insert(items, IXWDBEVEXPSTATE);
	if (LstPrjAlt == comp->LstPrjAlt) insert(items, LSTPRJALT);
	if (LstVerAlt == comp->LstVerAlt) insert(items, LSTVERALT);
	if (LstUntAlt == comp->LstUntAlt) insert(items, LSTUNTALT);
	if (LstPrjNumFirstdisp == comp->LstPrjNumFirstdisp) insert(items, LSTPRJNUMFIRSTDISP);
	if (LstVerNumFirstdisp == comp->LstVerNumFirstdisp) insert(items, LSTVERNUMFIRSTDISP);
	if (LstUntNumFirstdisp == comp->LstUntNumFirstdisp) insert(items, LSTUNTNUMFIRSTDISP);

	return(items);
};

set<uint> PnlWdbeNavDevdev::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWDBEVEXPSTATE, LSTPRJALT, LSTVERALT, LSTUNTALT, LSTPRJNUMFIRSTDISP, LSTVERNUMFIRSTDISP, LSTUNTNUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeNavDevdev::StatShr
 ******************************************************************************/

PnlWdbeNavDevdev::StatShr::StatShr(
			const bool LstPrjAvail
			, const bool ButPrjViewActive
			, const bool LstVerAvail
			, const bool ButVerViewActive
			, const bool LstUntAvail
			, const bool ButUntViewActive
			, const bool ButUntNewcrdActive
		) :
			Block()
			, LstPrjAvail(LstPrjAvail)
			, ButPrjViewActive(ButPrjViewActive)
			, LstVerAvail(LstVerAvail)
			, ButVerViewActive(ButVerViewActive)
			, LstUntAvail(LstUntAvail)
			, ButUntViewActive(ButUntViewActive)
			, ButUntNewcrdActive(ButUntNewcrdActive)
		{
	mask = {LSTPRJAVAIL, BUTPRJVIEWACTIVE, LSTVERAVAIL, BUTVERVIEWACTIVE, LSTUNTAVAIL, BUTUNTVIEWACTIVE, BUTUNTNEWCRDACTIVE};
};

bool PnlWdbeNavDevdev::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWdbeNavDevdev");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWdbeNavDevdev";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrjAvail", LstPrjAvail)) add(LSTPRJAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPrjViewActive", ButPrjViewActive)) add(BUTPRJVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstVerAvail", LstVerAvail)) add(LSTVERAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButVerViewActive", ButVerViewActive)) add(BUTVERVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstUntAvail", LstUntAvail)) add(LSTUNTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButUntViewActive", ButUntViewActive)) add(BUTUNTVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButUntNewcrdActive", ButUntNewcrdActive)) add(BUTUNTNEWCRDACTIVE);
	};

	return basefound;
};

set<uint> PnlWdbeNavDevdev::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstPrjAvail == comp->LstPrjAvail) insert(items, LSTPRJAVAIL);
	if (ButPrjViewActive == comp->ButPrjViewActive) insert(items, BUTPRJVIEWACTIVE);
	if (LstVerAvail == comp->LstVerAvail) insert(items, LSTVERAVAIL);
	if (ButVerViewActive == comp->ButVerViewActive) insert(items, BUTVERVIEWACTIVE);
	if (LstUntAvail == comp->LstUntAvail) insert(items, LSTUNTAVAIL);
	if (ButUntViewActive == comp->ButUntViewActive) insert(items, BUTUNTVIEWACTIVE);
	if (ButUntNewcrdActive == comp->ButUntNewcrdActive) insert(items, BUTUNTNEWCRDACTIVE);

	return(items);
};

set<uint> PnlWdbeNavDevdev::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTPRJAVAIL, BUTPRJVIEWACTIVE, LSTVERAVAIL, BUTVERVIEWACTIVE, LSTUNTAVAIL, BUTUNTVIEWACTIVE, BUTUNTNEWCRDACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeNavDevdev::Tag
 ******************************************************************************/

PnlWdbeNavDevdev::Tag::Tag(
			const string& Cpt
			, const string& CptPrj
			, const string& CptVer
			, const string& CptUnt
		) :
			Block()
			, Cpt(Cpt)
			, CptPrj(CptPrj)
			, CptVer(CptVer)
			, CptUnt(CptUnt)
		{
	mask = {CPT, CPTPRJ, CPTVER, CPTUNT};
};

bool PnlWdbeNavDevdev::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWdbeNavDevdev");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWdbeNavDevdev";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrj", CptPrj)) add(CPTPRJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVer", CptVer)) add(CPTVER);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptUnt", CptUnt)) add(CPTUNT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWdbeNavDevdev::DpchAppData
 ******************************************************************************/

PnlWdbeNavDevdev::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBENAVDEVDEVDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWdbeNavDevdev::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavDevdev::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeNavDevdevData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeNavDevdev::DpchAppDo
 ******************************************************************************/

PnlWdbeNavDevdev::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBENAVDEVDEVDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string PnlWdbeNavDevdev::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavDevdev::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeNavDevdevDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeNavDevdev::DpchEngData
 ******************************************************************************/

PnlWdbeNavDevdev::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBENAVDEVDEVDATA)
		{
	feedFLstPrj.tag = "FeedFLstPrj";
	feedFLstUnt.tag = "FeedFLstUnt";
	feedFLstVer.tag = "FeedFLstVer";
};

string PnlWdbeNavDevdev::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTPRJ)) ss.push_back("feedFLstPrj");
	if (has(FEEDFLSTUNT)) ss.push_back("feedFLstUnt");
	if (has(FEEDFLSTVER)) ss.push_back("feedFLstVer");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavDevdev::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWdbeNavDevdevData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (feedFLstPrj.readXML(docctx, basexpath, true)) add(FEEDFLSTPRJ);
		if (feedFLstUnt.readXML(docctx, basexpath, true)) add(FEEDFLSTUNT);
		if (feedFLstVer.readXML(docctx, basexpath, true)) add(FEEDFLSTVER);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		feedFLstPrj.clear();
		feedFLstUnt.clear();
		feedFLstVer.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
