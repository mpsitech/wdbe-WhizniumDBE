/**
	* \file PnlWdbeNavAuxfct_blks.cpp
	* job handler for job PnlWdbeNavAuxfct (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbeNavAuxfct::VecVDo
 ******************************************************************************/

uint PnlWdbeNavAuxfct::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "bututlnewcrdclick") return BUTUTLNEWCRDCLICK;

	return(0);
};

string PnlWdbeNavAuxfct::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTUTLNEWCRDCLICK) return("ButUtlNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlWdbeNavAuxfct::StatApp
 ******************************************************************************/

void PnlWdbeNavAuxfct::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWdbeVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeNavAuxfct";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWdbeNavAuxfct";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWdbeVExpstate", VecWdbeVExpstate::getSref(ixWdbeVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeNavAuxfct::StatShr
 ******************************************************************************/

PnlWdbeNavAuxfct::StatShr::StatShr(
			const bool ButUtlNewcrdAvail
		) :
			Block()
		{
	this->ButUtlNewcrdAvail = ButUtlNewcrdAvail;

	mask = {BUTUTLNEWCRDAVAIL};
};

void PnlWdbeNavAuxfct::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeNavAuxfct";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWdbeNavAuxfct";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButUtlNewcrdAvail", ButUtlNewcrdAvail);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeNavAuxfct::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButUtlNewcrdAvail == comp->ButUtlNewcrdAvail) insert(items, BUTUTLNEWCRDAVAIL);

	return(items);
};

set<uint> PnlWdbeNavAuxfct::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTUTLNEWCRDAVAIL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeNavAuxfct::Tag
 ******************************************************************************/

void PnlWdbeNavAuxfct::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWdbeNavAuxfct";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWdbeNavAuxfct";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Auxiliary functionality");
			writeStringAttr(wr, itemtag, "sref", "CptUtl", "utilities");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeNavAuxfct::DpchAppDo
 ******************************************************************************/

PnlWdbeNavAuxfct::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBENAVAUXFCTDO)
		{
	ixVDo = 0;
};

string PnlWdbeNavAuxfct::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavAuxfct::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeNavAuxfctDo");
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
 class PnlWdbeNavAuxfct::DpchEngData
 ******************************************************************************/

PnlWdbeNavAuxfct::DpchEngData::DpchEngData(
			const ubigint jref
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBENAVAUXFCTDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWdbeNavAuxfct::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavAuxfct::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWdbeNavAuxfct::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWdbeNavAuxfctData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};



