/**
	* \file PnlWdbeFstAStep_blks.cpp
	* job handler for job PnlWdbeFstAStep (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbeFstAStep::VecVDo
 ******************************************************************************/

uint PnlWdbeFstAStep::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butupclick") return BUTUPCLICK;
	if (s == "butdownclick") return BUTDOWNCLICK;
	if (s == "butnewclick") return BUTNEWCLICK;
	if (s == "butduplicateclick") return BUTDUPLICATECLICK;
	if (s == "butdeleteclick") return BUTDELETECLICK;
	if (s == "butrefreshclick") return BUTREFRESHCLICK;

	return(0);
};

string PnlWdbeFstAStep::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTUPCLICK) return("ButUpClick");
	if (ix == BUTDOWNCLICK) return("ButDownClick");
	if (ix == BUTNEWCLICK) return("ButNewClick");
	if (ix == BUTDUPLICATECLICK) return("ButDuplicateClick");
	if (ix == BUTDELETECLICK) return("ButDeleteClick");
	if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

	return("");
};

/******************************************************************************
 class PnlWdbeFstAStep::ContInf
 ******************************************************************************/

PnlWdbeFstAStep::ContInf::ContInf(
			const uint numFCsiQst
		) :
			Block()
		{
	this->numFCsiQst = numFCsiQst;

	mask = {NUMFCSIQST};
};

void PnlWdbeFstAStep::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbeFstAStep";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWdbeFstAStep";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFCsiQst", numFCsiQst);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeFstAStep::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlWdbeFstAStep::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFCSIQST};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeFstAStep::StatApp
 ******************************************************************************/

void PnlWdbeFstAStep::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWdbeVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeFstAStep";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWdbeFstAStep";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWdbeVExpstate", VecWdbeVExpstate::getSref(ixWdbeVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeFstAStep::StatShr
 ******************************************************************************/

PnlWdbeFstAStep::StatShr::StatShr(
			const bool ButUpAvail
			, const bool ButUpActive
			, const bool ButDownAvail
			, const bool ButDownActive
			, const bool ButNewAvail
			, const bool ButDuplicateAvail
			, const bool ButDuplicateActive
			, const bool ButDeleteAvail
			, const bool ButDeleteActive
		) :
			Block()
		{
	this->ButUpAvail = ButUpAvail;
	this->ButUpActive = ButUpActive;
	this->ButDownAvail = ButDownAvail;
	this->ButDownActive = ButDownActive;
	this->ButNewAvail = ButNewAvail;
	this->ButDuplicateAvail = ButDuplicateAvail;
	this->ButDuplicateActive = ButDuplicateActive;
	this->ButDeleteAvail = ButDeleteAvail;
	this->ButDeleteActive = ButDeleteActive;

	mask = {BUTUPAVAIL, BUTUPACTIVE, BUTDOWNAVAIL, BUTDOWNACTIVE, BUTNEWAVAIL, BUTDUPLICATEAVAIL, BUTDUPLICATEACTIVE, BUTDELETEAVAIL, BUTDELETEACTIVE};
};

void PnlWdbeFstAStep::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeFstAStep";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWdbeFstAStep";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButUpAvail", ButUpAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButUpActive", ButUpActive);
		writeBoolAttr(wr, itemtag, "sref", "ButDownAvail", ButDownAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButDownActive", ButDownActive);
		writeBoolAttr(wr, itemtag, "sref", "ButNewAvail", ButNewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButDuplicateAvail", ButDuplicateAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButDuplicateActive", ButDuplicateActive);
		writeBoolAttr(wr, itemtag, "sref", "ButDeleteAvail", ButDeleteAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButDeleteActive", ButDeleteActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeFstAStep::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButUpAvail == comp->ButUpAvail) insert(items, BUTUPAVAIL);
	if (ButUpActive == comp->ButUpActive) insert(items, BUTUPACTIVE);
	if (ButDownAvail == comp->ButDownAvail) insert(items, BUTDOWNAVAIL);
	if (ButDownActive == comp->ButDownActive) insert(items, BUTDOWNACTIVE);
	if (ButNewAvail == comp->ButNewAvail) insert(items, BUTNEWAVAIL);
	if (ButDuplicateAvail == comp->ButDuplicateAvail) insert(items, BUTDUPLICATEAVAIL);
	if (ButDuplicateActive == comp->ButDuplicateActive) insert(items, BUTDUPLICATEACTIVE);
	if (ButDeleteAvail == comp->ButDeleteAvail) insert(items, BUTDELETEAVAIL);
	if (ButDeleteActive == comp->ButDeleteActive) insert(items, BUTDELETEACTIVE);

	return(items);
};

set<uint> PnlWdbeFstAStep::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTUPAVAIL, BUTUPACTIVE, BUTDOWNAVAIL, BUTDOWNACTIVE, BUTNEWAVAIL, BUTDUPLICATEAVAIL, BUTDUPLICATEACTIVE, BUTDELETEAVAIL, BUTDELETEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeFstAStep::StgIac
 ******************************************************************************/

PnlWdbeFstAStep::StgIac::StgIac(
			const uint TcoFnxWidth
			, const uint TcoCn1Width
			, const uint TcoIp1Width
			, const uint TcoCn2Width
			, const uint TcoIp2Width
			, const uint TcoCn3Width
			, const uint TcoIp3Width
			, const uint TcoCn4Width
			, const uint TcoIp4Width
		) :
			Block()
		{
	this->TcoFnxWidth = TcoFnxWidth;
	this->TcoCn1Width = TcoCn1Width;
	this->TcoIp1Width = TcoIp1Width;
	this->TcoCn2Width = TcoCn2Width;
	this->TcoIp2Width = TcoIp2Width;
	this->TcoCn3Width = TcoCn3Width;
	this->TcoIp3Width = TcoIp3Width;
	this->TcoCn4Width = TcoCn4Width;
	this->TcoIp4Width = TcoIp4Width;
	mask = {TCOFNXWIDTH, TCOCN1WIDTH, TCOIP1WIDTH, TCOCN2WIDTH, TCOIP2WIDTH, TCOCN3WIDTH, TCOIP3WIDTH, TCOCN4WIDTH, TCOIP4WIDTH};
};

bool PnlWdbeFstAStep::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacWdbeFstAStep");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacWdbeFstAStep";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoFnxWidth", TcoFnxWidth)) add(TCOFNXWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoCn1Width", TcoCn1Width)) add(TCOCN1WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoIp1Width", TcoIp1Width)) add(TCOIP1WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoCn2Width", TcoCn2Width)) add(TCOCN2WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoIp2Width", TcoIp2Width)) add(TCOIP2WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoCn3Width", TcoCn3Width)) add(TCOCN3WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoIp3Width", TcoIp3Width)) add(TCOIP3WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoCn4Width", TcoCn4Width)) add(TCOCN4WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoIp4Width", TcoIp4Width)) add(TCOIP4WIDTH);
	};

	return basefound;
};

void PnlWdbeFstAStep::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacWdbeFstAStep";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacWdbeFstAStep";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoFnxWidth", TcoFnxWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoCn1Width", TcoCn1Width);
		writeUintAttr(wr, itemtag, "sref", "TcoIp1Width", TcoIp1Width);
		writeUintAttr(wr, itemtag, "sref", "TcoCn2Width", TcoCn2Width);
		writeUintAttr(wr, itemtag, "sref", "TcoIp2Width", TcoIp2Width);
		writeUintAttr(wr, itemtag, "sref", "TcoCn3Width", TcoCn3Width);
		writeUintAttr(wr, itemtag, "sref", "TcoIp3Width", TcoIp3Width);
		writeUintAttr(wr, itemtag, "sref", "TcoCn4Width", TcoCn4Width);
		writeUintAttr(wr, itemtag, "sref", "TcoIp4Width", TcoIp4Width);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeFstAStep::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoFnxWidth == comp->TcoFnxWidth) insert(items, TCOFNXWIDTH);
	if (TcoCn1Width == comp->TcoCn1Width) insert(items, TCOCN1WIDTH);
	if (TcoIp1Width == comp->TcoIp1Width) insert(items, TCOIP1WIDTH);
	if (TcoCn2Width == comp->TcoCn2Width) insert(items, TCOCN2WIDTH);
	if (TcoIp2Width == comp->TcoIp2Width) insert(items, TCOIP2WIDTH);
	if (TcoCn3Width == comp->TcoCn3Width) insert(items, TCOCN3WIDTH);
	if (TcoIp3Width == comp->TcoIp3Width) insert(items, TCOIP3WIDTH);
	if (TcoCn4Width == comp->TcoCn4Width) insert(items, TCOCN4WIDTH);
	if (TcoIp4Width == comp->TcoIp4Width) insert(items, TCOIP4WIDTH);

	return(items);
};

set<uint> PnlWdbeFstAStep::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOFNXWIDTH, TCOCN1WIDTH, TCOIP1WIDTH, TCOCN2WIDTH, TCOIP2WIDTH, TCOCN3WIDTH, TCOIP3WIDTH, TCOCN4WIDTH, TCOIP4WIDTH};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeFstAStep::Tag
 ******************************************************************************/

void PnlWdbeFstAStep::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWdbeFstAStep";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWdbeFstAStep";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Steppings");
			writeStringAttr(wr, itemtag, "sref", "TcoFnx", "FSM state");
			writeStringAttr(wr, itemtag, "sref", "TcoCn1", "Condition 1");
			writeStringAttr(wr, itemtag, "sref", "TcoIp1", "Insertion point 1");
			writeStringAttr(wr, itemtag, "sref", "TcoCn2", "Condition 2");
			writeStringAttr(wr, itemtag, "sref", "TcoIp2", "Insertion point 2");
			writeStringAttr(wr, itemtag, "sref", "TcoCn3", "Condition 3");
			writeStringAttr(wr, itemtag, "sref", "TcoIp3", "Insertion point 3");
			writeStringAttr(wr, itemtag, "sref", "TcoCn4", "Condition 4");
			writeStringAttr(wr, itemtag, "sref", "TcoIp4", "Insertion point 4");
		};
		writeStringAttr(wr, itemtag, "sref", "TxtRecord1", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::REC, ixWdbeVLocale)));
		writeStringAttr(wr, itemtag, "sref", "TxtRecord2", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::EMPLONG, ixWdbeVLocale)));
		writeStringAttr(wr, itemtag, "sref", "Trs", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::GOTO, ixWdbeVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "TxtShowing1", VecWdbeVTag::getTitle(VecWdbeVTag::SHOWSHORT, ixWdbeVLocale));
		writeStringAttr(wr, itemtag, "sref", "TxtShowing2", VecWdbeVTag::getTitle(VecWdbeVTag::EMPSHORT, ixWdbeVLocale));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeFstAStep::DpchAppData
 ******************************************************************************/

PnlWdbeFstAStep::DpchAppData::DpchAppData() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEFSTASTEPDATA)
		{
};

string PnlWdbeFstAStep::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeFstAStep::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeFstAStepData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (stgiac.readXML(docctx, basexpath, true)) add(STGIAC);
		if (stgiacqry.readXML(docctx, basexpath, true)) add(STGIACQRY);
	} else {
		stgiac = StgIac();
		stgiacqry = QryWdbeFstAStep::StgIac();
	};
};

/******************************************************************************
 class PnlWdbeFstAStep::DpchAppDo
 ******************************************************************************/

PnlWdbeFstAStep::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEFSTASTEPDO)
		{
	ixVDo = 0;
};

string PnlWdbeFstAStep::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeFstAStep::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeFstAStepDo");
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
 class PnlWdbeFstAStep::DpchEngData
 ******************************************************************************/

PnlWdbeFstAStep::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFCsiQst
			, StatShr* statshr
			, StgIac* stgiac
			, ListWdbeQFstAStep* rst
			, QryWdbeFstAStep::StatShr* statshrqry
			, QryWdbeFstAStep::StgIac* stgiacqry
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBEFSTASTEPDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFCSIQST, STATAPP, STATSHR, STGIAC, TAG, RST, STATAPPQRY, STATSHRQRY, STGIACQRY};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFCSIQST) && feedFCsiQst) this->feedFCsiQst = *feedFCsiQst;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
	if (find(this->mask, STGIAC) && stgiac) this->stgiac = *stgiac;
	if (find(this->mask, RST) && rst) this->rst = *rst;
	if (find(this->mask, STATSHRQRY) && statshrqry) this->statshrqry = *statshrqry;
	if (find(this->mask, STGIACQRY) && stgiacqry) this->stgiacqry = *stgiacqry;
};

string PnlWdbeFstAStep::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFCSIQST)) ss.push_back("feedFCsiQst");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(TAG)) ss.push_back("tag");
	if (has(RST)) ss.push_back("rst");
	if (has(STATAPPQRY)) ss.push_back("statappqry");
	if (has(STATSHRQRY)) ss.push_back("statshrqry");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeFstAStep::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFCSIQST)) {feedFCsiQst = src->feedFCsiQst; add(FEEDFCSIQST);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(STGIAC)) {stgiac = src->stgiac; add(STGIAC);};
	if (src->has(TAG)) add(TAG);
	if (src->has(RST)) {rst = src->rst; add(RST);};
	if (src->has(STATAPPQRY)) add(STATAPPQRY);
	if (src->has(STATSHRQRY)) {statshrqry = src->statshrqry; add(STATSHRQRY);};
	if (src->has(STGIACQRY)) {stgiacqry = src->stgiacqry; add(STGIACQRY);};
};

void PnlWdbeFstAStep::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWdbeFstAStepData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFCSIQST)) feedFCsiQst.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
		if (has(RST)) rst.writeXML(wr);
		if (has(STATAPPQRY)) QryWdbeFstAStep::StatApp::writeXML(wr);
		if (has(STATSHRQRY)) statshrqry.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};



