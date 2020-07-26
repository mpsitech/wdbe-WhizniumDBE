/**
	* \file PnlWdbeNavCoredev_blks.cpp
	* job handler for job PnlWdbeNavCoredev (implementation of blocks)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbeNavCoredev::VecVDo
 ******************************************************************************/

uint PnlWdbeNavCoredev::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butcprviewclick") return BUTCPRVIEWCLICK;
	if (s == "butcprnewcrdclick") return BUTCPRNEWCRDCLICK;
	if (s == "butcvrviewclick") return BUTCVRVIEWCLICK;
	if (s == "butcvrnewcrdclick") return BUTCVRNEWCRDCLICK;

	return(0);
};

string PnlWdbeNavCoredev::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTCPRVIEWCLICK) return("ButCprViewClick");
	if (ix == BUTCPRNEWCRDCLICK) return("ButCprNewcrdClick");
	if (ix == BUTCVRVIEWCLICK) return("ButCvrViewClick");
	if (ix == BUTCVRNEWCRDCLICK) return("ButCvrNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlWdbeNavCoredev::ContIac
 ******************************************************************************/

PnlWdbeNavCoredev::ContIac::ContIac(
			const uint numFLstCpr
			, const uint numFLstCvr
		) :
			Block()
		{
	this->numFLstCpr = numFLstCpr;
	this->numFLstCvr = numFLstCvr;

	mask = {NUMFLSTCPR, NUMFLSTCVR};
};

bool PnlWdbeNavCoredev::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWdbeNavCoredev");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWdbeNavCoredev";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstCpr", numFLstCpr)) add(NUMFLSTCPR);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstCvr", numFLstCvr)) add(NUMFLSTCVR);
	};

	return basefound;
};

void PnlWdbeNavCoredev::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeNavCoredev";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWdbeNavCoredev";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstCpr", numFLstCpr);
		writeUintAttr(wr, itemtag, "sref", "numFLstCvr", numFLstCvr);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeNavCoredev::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstCpr == comp->numFLstCpr) insert(items, NUMFLSTCPR);
	if (numFLstCvr == comp->numFLstCvr) insert(items, NUMFLSTCVR);

	return(items);
};

set<uint> PnlWdbeNavCoredev::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTCPR, NUMFLSTCVR};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeNavCoredev::StatApp
 ******************************************************************************/

void PnlWdbeNavCoredev::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWdbeVExpstate
			, const bool LstCprAlt
			, const bool LstCvrAlt
			, const uint LstCprNumFirstdisp
			, const uint LstCvrNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeNavCoredev";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWdbeNavCoredev";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWdbeVExpstate", VecWdbeVExpstate::getSref(ixWdbeVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstCprAlt", LstCprAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstCvrAlt", LstCvrAlt);
		writeUintAttr(wr, itemtag, "sref", "LstCprNumFirstdisp", LstCprNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstCvrNumFirstdisp", LstCvrNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeNavCoredev::StatShr
 ******************************************************************************/

PnlWdbeNavCoredev::StatShr::StatShr(
			const bool LstCprAvail
			, const bool ButCprViewActive
			, const bool LstCvrAvail
			, const bool ButCvrViewActive
		) :
			Block()
		{
	this->LstCprAvail = LstCprAvail;
	this->ButCprViewActive = ButCprViewActive;
	this->LstCvrAvail = LstCvrAvail;
	this->ButCvrViewActive = ButCvrViewActive;

	mask = {LSTCPRAVAIL, BUTCPRVIEWACTIVE, LSTCVRAVAIL, BUTCVRVIEWACTIVE};
};

void PnlWdbeNavCoredev::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeNavCoredev";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWdbeNavCoredev";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "LstCprAvail", LstCprAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButCprViewActive", ButCprViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstCvrAvail", LstCvrAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButCvrViewActive", ButCvrViewActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeNavCoredev::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstCprAvail == comp->LstCprAvail) insert(items, LSTCPRAVAIL);
	if (ButCprViewActive == comp->ButCprViewActive) insert(items, BUTCPRVIEWACTIVE);
	if (LstCvrAvail == comp->LstCvrAvail) insert(items, LSTCVRAVAIL);
	if (ButCvrViewActive == comp->ButCvrViewActive) insert(items, BUTCVRVIEWACTIVE);

	return(items);
};

set<uint> PnlWdbeNavCoredev::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTCPRAVAIL, BUTCPRVIEWACTIVE, LSTCVRAVAIL, BUTCVRVIEWACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeNavCoredev::Tag
 ******************************************************************************/

void PnlWdbeNavCoredev::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWdbeNavCoredev";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWdbeNavCoredev";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Core development module");
			writeStringAttr(wr, itemtag, "sref", "CptCpr", "core projects");
			writeStringAttr(wr, itemtag, "sref", "CptCvr", "core versions");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeNavCoredev::DpchAppData
 ******************************************************************************/

PnlWdbeNavCoredev::DpchAppData::DpchAppData() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBENAVCOREDEVDATA)
		{
};

string PnlWdbeNavCoredev::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavCoredev::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeNavCoredevData");
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
 class PnlWdbeNavCoredev::DpchAppDo
 ******************************************************************************/

PnlWdbeNavCoredev::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBENAVCOREDEVDO)
		{
	ixVDo = 0;
};

string PnlWdbeNavCoredev::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavCoredev::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeNavCoredevDo");
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
 class PnlWdbeNavCoredev::DpchEngData
 ******************************************************************************/

PnlWdbeNavCoredev::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, Feed* feedFLstCpr
			, Feed* feedFLstCvr
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBENAVCOREDEVDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, FEEDFLSTCPR, FEEDFLSTCVR, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, FEEDFLSTCPR) && feedFLstCpr) this->feedFLstCpr = *feedFLstCpr;
	if (find(this->mask, FEEDFLSTCVR) && feedFLstCvr) this->feedFLstCvr = *feedFLstCvr;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWdbeNavCoredev::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTCPR)) ss.push_back("feedFLstCpr");
	if (has(FEEDFLSTCVR)) ss.push_back("feedFLstCvr");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavCoredev::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(FEEDFLSTCPR)) {feedFLstCpr = src->feedFLstCpr; add(FEEDFLSTCPR);};
	if (src->has(FEEDFLSTCVR)) {feedFLstCvr = src->feedFLstCvr; add(FEEDFLSTCVR);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWdbeNavCoredev::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWdbeNavCoredevData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(FEEDFLSTCPR)) feedFLstCpr.writeXML(wr);
		if (has(FEEDFLSTCVR)) feedFLstCvr.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};

