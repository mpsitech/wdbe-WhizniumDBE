/**
	* \file CrdWdbeRls_blks.cpp
	* job handler for job CrdWdbeRls (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class CrdWdbeRls::VecVDo
 ******************************************************************************/

uint CrdWdbeRls::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "close") return CLOSE;
	if (s == "mitappabtclick") return MITAPPABTCLICK;
	if (s == "mitcrdnewclick") return MITCRDNEWCLICK;
	if (s == "mitcrdsrtclick") return MITCRDSRTCLICK;
	if (s == "mitcrdcrtclick") return MITCRDCRTCLICK;
	if (s == "mitcrdfrtclick") return MITCRDFRTCLICK;
	if (s == "mitcrdwcoclick") return MITCRDWCOCLICK;

	return(0);
};

string CrdWdbeRls::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
	if (ix == MITCRDNEWCLICK) return("MitCrdNewClick");
	if (ix == MITCRDSRTCLICK) return("MitCrdSrtClick");
	if (ix == MITCRDCRTCLICK) return("MitCrdCrtClick");
	if (ix == MITCRDFRTCLICK) return("MitCrdFrtClick");
	if (ix == MITCRDWCOCLICK) return("MitCrdWcoClick");

	return("");
};

/******************************************************************************
 class CrdWdbeRls::VecVSge
 ******************************************************************************/

uint CrdWdbeRls::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "alrwdbeabt") return ALRWDBEABT;

	return(0);
};

string CrdWdbeRls::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRWDBEABT) return("alrwdbeabt");

	return("");
};

void CrdWdbeRls::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class CrdWdbeRls::ContInf
 ******************************************************************************/

CrdWdbeRls::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
			, const string& MtxCrdRls
		) :
			Block()
		{
	this->numFSge = numFSge;
	this->MrlAppHlp = MrlAppHlp;
	this->MtxCrdRls = MtxCrdRls;

	mask = {NUMFSGE, MRLAPPHLP, MTXCRDRLS};
};

void CrdWdbeRls::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbeRls";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWdbeRls";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", MrlAppHlp);
		writeStringAttr(wr, itemtag, "sref", "MtxCrdRls", MtxCrdRls);
	xmlTextWriterEndElement(wr);
};

set<uint> CrdWdbeRls::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp == comp->MrlAppHlp) insert(items, MRLAPPHLP);
	if (MtxCrdRls == comp->MtxCrdRls) insert(items, MTXCRDRLS);

	return(items);
};

set<uint> CrdWdbeRls::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, MRLAPPHLP, MTXCRDRLS};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWdbeRls::StatApp
 ******************************************************************************/

void CrdWdbeRls::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWdbeVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdoneList
			, const bool initdoneRec
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeRls";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWdbeRls";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWdbeVReqitmode", VecWdbeVReqitmode::getSref(ixWdbeVReqitmode));
		writeUsmallintAttr(wr, itemtag, "sref", "latency", latency);
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
		writeUintAttr(wr, itemtag, "sref", "widthMenu", widthMenu);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHeadbar", initdoneHeadbar);
		writeBoolAttr(wr, itemtag, "sref", "initdoneList", initdoneList);
		writeBoolAttr(wr, itemtag, "sref", "initdoneRec", initdoneRec);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWdbeRls::StatShr
 ******************************************************************************/

CrdWdbeRls::StatShr::StatShr(
			const ubigint jrefDlgfinreptr
			, const ubigint jrefDlgnew
			, const ubigint jrefDlgstareptr
			, const ubigint jrefDlgwrite
			, const ubigint jrefHeadbar
			, const ubigint jrefList
			, const ubigint jrefRec
			, const bool MspCrd1Avail
			, const bool MitCrdNewAvail
			, const bool MitCrdSrtAvail
			, const bool MitCrdSrtActive
			, const bool MitCrdCrtAvail
			, const bool MitCrdCrtActive
			, const bool MitCrdFrtAvail
			, const bool MitCrdFrtActive
			, const bool MitCrdWcoAvail
			, const bool MitCrdWcoActive
		) :
			Block()
		{
	this->jrefDlgfinreptr = jrefDlgfinreptr;
	this->jrefDlgnew = jrefDlgnew;
	this->jrefDlgstareptr = jrefDlgstareptr;
	this->jrefDlgwrite = jrefDlgwrite;
	this->jrefHeadbar = jrefHeadbar;
	this->jrefList = jrefList;
	this->jrefRec = jrefRec;
	this->MspCrd1Avail = MspCrd1Avail;
	this->MitCrdNewAvail = MitCrdNewAvail;
	this->MitCrdSrtAvail = MitCrdSrtAvail;
	this->MitCrdSrtActive = MitCrdSrtActive;
	this->MitCrdCrtAvail = MitCrdCrtAvail;
	this->MitCrdCrtActive = MitCrdCrtActive;
	this->MitCrdFrtAvail = MitCrdFrtAvail;
	this->MitCrdFrtActive = MitCrdFrtActive;
	this->MitCrdWcoAvail = MitCrdWcoAvail;
	this->MitCrdWcoActive = MitCrdWcoActive;

	mask = {JREFDLGFINREPTR, JREFDLGNEW, JREFDLGSTAREPTR, JREFDLGWRITE, JREFHEADBAR, JREFLIST, JREFREC, MSPCRD1AVAIL, MITCRDNEWAVAIL, MITCRDSRTAVAIL, MITCRDSRTACTIVE, MITCRDCRTAVAIL, MITCRDCRTACTIVE, MITCRDFRTAVAIL, MITCRDFRTACTIVE, MITCRDWCOAVAIL, MITCRDWCOACTIVE};
};

void CrdWdbeRls::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeRls";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWdbeRls";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgfinreptr", Scr::scramble(jrefDlgfinreptr));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgnew", Scr::scramble(jrefDlgnew));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgstareptr", Scr::scramble(jrefDlgstareptr));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgwrite", Scr::scramble(jrefDlgwrite));
		writeStringAttr(wr, itemtag, "sref", "scrJrefHeadbar", Scr::scramble(jrefHeadbar));
		writeStringAttr(wr, itemtag, "sref", "scrJrefList", Scr::scramble(jrefList));
		writeStringAttr(wr, itemtag, "sref", "scrJrefRec", Scr::scramble(jrefRec));
		writeBoolAttr(wr, itemtag, "sref", "MspCrd1Avail", MspCrd1Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdNewAvail", MitCrdNewAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdSrtAvail", MitCrdSrtAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdSrtActive", MitCrdSrtActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdCrtAvail", MitCrdCrtAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdCrtActive", MitCrdCrtActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdFrtAvail", MitCrdFrtAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdFrtActive", MitCrdFrtActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdWcoAvail", MitCrdWcoAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdWcoActive", MitCrdWcoActive);
	xmlTextWriterEndElement(wr);
};

set<uint> CrdWdbeRls::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (jrefDlgfinreptr == comp->jrefDlgfinreptr) insert(items, JREFDLGFINREPTR);
	if (jrefDlgnew == comp->jrefDlgnew) insert(items, JREFDLGNEW);
	if (jrefDlgstareptr == comp->jrefDlgstareptr) insert(items, JREFDLGSTAREPTR);
	if (jrefDlgwrite == comp->jrefDlgwrite) insert(items, JREFDLGWRITE);
	if (jrefHeadbar == comp->jrefHeadbar) insert(items, JREFHEADBAR);
	if (jrefList == comp->jrefList) insert(items, JREFLIST);
	if (jrefRec == comp->jrefRec) insert(items, JREFREC);
	if (MspCrd1Avail == comp->MspCrd1Avail) insert(items, MSPCRD1AVAIL);
	if (MitCrdNewAvail == comp->MitCrdNewAvail) insert(items, MITCRDNEWAVAIL);
	if (MitCrdSrtAvail == comp->MitCrdSrtAvail) insert(items, MITCRDSRTAVAIL);
	if (MitCrdSrtActive == comp->MitCrdSrtActive) insert(items, MITCRDSRTACTIVE);
	if (MitCrdCrtAvail == comp->MitCrdCrtAvail) insert(items, MITCRDCRTAVAIL);
	if (MitCrdCrtActive == comp->MitCrdCrtActive) insert(items, MITCRDCRTACTIVE);
	if (MitCrdFrtAvail == comp->MitCrdFrtAvail) insert(items, MITCRDFRTAVAIL);
	if (MitCrdFrtActive == comp->MitCrdFrtActive) insert(items, MITCRDFRTACTIVE);
	if (MitCrdWcoAvail == comp->MitCrdWcoAvail) insert(items, MITCRDWCOAVAIL);
	if (MitCrdWcoActive == comp->MitCrdWcoActive) insert(items, MITCRDWCOACTIVE);

	return(items);
};

set<uint> CrdWdbeRls::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JREFDLGFINREPTR, JREFDLGNEW, JREFDLGSTAREPTR, JREFDLGWRITE, JREFHEADBAR, JREFLIST, JREFREC, MSPCRD1AVAIL, MITCRDNEWAVAIL, MITCRDSRTAVAIL, MITCRDSRTACTIVE, MITCRDCRTAVAIL, MITCRDCRTACTIVE, MITCRDFRTAVAIL, MITCRDFRTACTIVE, MITCRDWCOAVAIL, MITCRDWCOACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWdbeRls::Tag
 ******************************************************************************/

void CrdWdbeRls::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWdbeRls";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWdbeRls";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MitCrdSrt", "Start repository transaction ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdCrt", "Cancel repository transaction");
			writeStringAttr(wr, itemtag, "sref", "MitCrdFrt", "Finalize repository transaction ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdWco", "Write code ...");
		};
		writeStringAttr(wr, itemtag, "sref", "MitAppAbt", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::ABOUT, ixWdbeVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::HELP, ixWdbeVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "MitCrdNew", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::NEW, ixWdbeVLocale)) + " ...");
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWdbeRls::DpchAppDo
 ******************************************************************************/

CrdWdbeRls::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBERLSDO)
		{
	ixVDo = 0;
};

string CrdWdbeRls::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWdbeRls::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeRlsDo");
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
 class CrdWdbeRls::DpchEngData
 ******************************************************************************/

CrdWdbeRls::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFSge
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBERLSDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFSGE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string CrdWdbeRls::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWdbeRls::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void CrdWdbeRls::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWdbeRlsData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};



