/**
	* \file PnlWdbeGenList_blks.cpp
	* job handler for job PnlWdbeGenList (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbeGenList::VecVDo
 ******************************************************************************/

uint PnlWdbeGenList::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butregularizeclick") return BUTREGULARIZECLICK;
	if (s == "butnewclick") return BUTNEWCLICK;
	if (s == "butdeleteclick") return BUTDELETECLICK;
	if (s == "butfilterclick") return BUTFILTERCLICK;
	if (s == "butrefreshclick") return BUTREFRESHCLICK;

	return(0);
};

string PnlWdbeGenList::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	if (ix == BUTNEWCLICK) return("ButNewClick");
	if (ix == BUTDELETECLICK) return("ButDeleteClick");
	if (ix == BUTFILTERCLICK) return("ButFilterClick");
	if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

	return("");
};

/******************************************************************************
 class PnlWdbeGenList::ContIac
 ******************************************************************************/

PnlWdbeGenList::ContIac::ContIac(
			const uint numFTos
		) :
			Block()
		{
	this->numFTos = numFTos;

	mask = {NUMFTOS};
};

bool PnlWdbeGenList::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacWdbeGenList"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFTos")) {numFTos = me["numFTos"].asUInt(); add(NUMFTOS);};
	};

	return basefound;
};

bool PnlWdbeGenList::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWdbeGenList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWdbeGenList";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFTos", numFTos)) add(NUMFTOS);
	};

	return basefound;
};

void PnlWdbeGenList::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeGenList";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFTos"] = (Json::Value::UInt) numFTos;
};

void PnlWdbeGenList::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeGenList";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWdbeGenList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFTos", numFTos);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeGenList::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFTos == comp->numFTos) insert(items, NUMFTOS);

	return(items);
};

set<uint> PnlWdbeGenList::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFTOS};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeGenList::ContInf
 ******************************************************************************/

PnlWdbeGenList::ContInf::ContInf(
			const string& TxtFor
			, const string& TxtPre
			, const bool ButFilterOn
			, const uint numFCsiQst
		) :
			Block()
		{
	this->TxtFor = TxtFor;
	this->TxtPre = TxtPre;
	this->ButFilterOn = ButFilterOn;
	this->numFCsiQst = numFCsiQst;

	mask = {TXTFOR, TXTPRE, BUTFILTERON, NUMFCSIQST};
};

void PnlWdbeGenList::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbeGenList";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtFor"] = TxtFor;
	me["TxtPre"] = TxtPre;
	me["ButFilterOn"] = ButFilterOn;
	me["numFCsiQst"] = (Json::Value::UInt) numFCsiQst;
};

void PnlWdbeGenList::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbeGenList";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWdbeGenList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtFor", TxtFor);
		writeStringAttr(wr, itemtag, "sref", "TxtPre", TxtPre);
		writeBoolAttr(wr, itemtag, "sref", "ButFilterOn", ButFilterOn);
		writeUintAttr(wr, itemtag, "sref", "numFCsiQst", numFCsiQst);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeGenList::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtFor == comp->TxtFor) insert(items, TXTFOR);
	if (TxtPre == comp->TxtPre) insert(items, TXTPRE);
	if (ButFilterOn == comp->ButFilterOn) insert(items, BUTFILTERON);
	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlWdbeGenList::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTFOR, TXTPRE, BUTFILTERON, NUMFCSIQST};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeGenList::StatShr
 ******************************************************************************/

PnlWdbeGenList::StatShr::StatShr(
			const uint ixWdbeVExpstate
			, const bool ButDeleteActive
		) :
			Block()
		{
	this->ixWdbeVExpstate = ixWdbeVExpstate;
	this->ButDeleteActive = ButDeleteActive;

	mask = {IXWDBEVEXPSTATE, BUTDELETEACTIVE};
};

void PnlWdbeGenList::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeGenList";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWdbeVExpstate"] = VecWdbeVExpstate::getSref(ixWdbeVExpstate);
	me["ButDeleteActive"] = ButDeleteActive;
};

void PnlWdbeGenList::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeGenList";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWdbeGenList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWdbeVExpstate", VecWdbeVExpstate::getSref(ixWdbeVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "ButDeleteActive", ButDeleteActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeGenList::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWdbeVExpstate == comp->ixWdbeVExpstate) insert(items, IXWDBEVEXPSTATE);
	if (ButDeleteActive == comp->ButDeleteActive) insert(items, BUTDELETEACTIVE);

	return(items);
};

set<uint> PnlWdbeGenList::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWDBEVEXPSTATE, BUTDELETEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeGenList::StgIac
 ******************************************************************************/

PnlWdbeGenList::StgIac::StgIac(
			const uint TcoSrfWidth
			, const uint TcoMdlWidth
			, const uint TcoHtyWidth
			, const uint TcoWidWidth
			, const uint TcoMmxWidth
		) :
			Block()
		{
	this->TcoSrfWidth = TcoSrfWidth;
	this->TcoMdlWidth = TcoMdlWidth;
	this->TcoHtyWidth = TcoHtyWidth;
	this->TcoWidWidth = TcoWidWidth;
	this->TcoMmxWidth = TcoMmxWidth;
	mask = {TCOSRFWIDTH, TCOMDLWIDTH, TCOHTYWIDTH, TCOWIDWIDTH, TCOMMXWIDTH};
};

bool PnlWdbeGenList::StgIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["StgIacWdbeGenList"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("TcoSrfWidth")) {TcoSrfWidth = me["TcoSrfWidth"].asUInt(); add(TCOSRFWIDTH);};
		if (me.isMember("TcoMdlWidth")) {TcoMdlWidth = me["TcoMdlWidth"].asUInt(); add(TCOMDLWIDTH);};
		if (me.isMember("TcoHtyWidth")) {TcoHtyWidth = me["TcoHtyWidth"].asUInt(); add(TCOHTYWIDTH);};
		if (me.isMember("TcoWidWidth")) {TcoWidWidth = me["TcoWidWidth"].asUInt(); add(TCOWIDWIDTH);};
		if (me.isMember("TcoMmxWidth")) {TcoMmxWidth = me["TcoMmxWidth"].asUInt(); add(TCOMMXWIDTH);};
	};

	return basefound;
};

bool PnlWdbeGenList::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacWdbeGenList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacWdbeGenList";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoSrfWidth", TcoSrfWidth)) add(TCOSRFWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoMdlWidth", TcoMdlWidth)) add(TCOMDLWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoHtyWidth", TcoHtyWidth)) add(TCOHTYWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoWidWidth", TcoWidWidth)) add(TCOWIDWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoMmxWidth", TcoMmxWidth)) add(TCOMMXWIDTH);
	};

	return basefound;
};

void PnlWdbeGenList::StgIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StgIacWdbeGenList";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TcoSrfWidth"] = (Json::Value::UInt) TcoSrfWidth;
	me["TcoMdlWidth"] = (Json::Value::UInt) TcoMdlWidth;
	me["TcoHtyWidth"] = (Json::Value::UInt) TcoHtyWidth;
	me["TcoWidWidth"] = (Json::Value::UInt) TcoWidWidth;
	me["TcoMmxWidth"] = (Json::Value::UInt) TcoMmxWidth;
};

void PnlWdbeGenList::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacWdbeGenList";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacWdbeGenList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoSrfWidth", TcoSrfWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoMdlWidth", TcoMdlWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoHtyWidth", TcoHtyWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoWidWidth", TcoWidWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoMmxWidth", TcoMmxWidth);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeGenList::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoSrfWidth == comp->TcoSrfWidth) insert(items, TCOSRFWIDTH);
	if (TcoMdlWidth == comp->TcoMdlWidth) insert(items, TCOMDLWIDTH);
	if (TcoHtyWidth == comp->TcoHtyWidth) insert(items, TCOHTYWIDTH);
	if (TcoWidWidth == comp->TcoWidWidth) insert(items, TCOWIDWIDTH);
	if (TcoMmxWidth == comp->TcoMmxWidth) insert(items, TCOMMXWIDTH);

	return(items);
};

set<uint> PnlWdbeGenList::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOSRFWIDTH, TCOMDLWIDTH, TCOHTYWIDTH, TCOWIDWIDTH, TCOMMXWIDTH};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeGenList::Tag
 ******************************************************************************/

void PnlWdbeGenList::Tag::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWdbeGenList";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		me["Cpt"] = "Generics";
		me["TcoSrf"] = "Identifier";
		me["TcoMdl"] = "Module";
		me["TcoHty"] = "HDL type";
		me["TcoWid"] = "Width";
		me["TcoMmx"] = "Range";
	};
	me["TxtFor"] = VecWdbeVTag::getTitle(VecWdbeVTag::FOR, ixWdbeVLocale);
	me["TxtRecord1"] = StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::REC, ixWdbeVLocale));
	me["TxtRecord2"] = StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::EMPLONG, ixWdbeVLocale));
	me["Trs"] = StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::GOTO, ixWdbeVLocale)) + " ...";
	me["TxtShowing1"] = StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::SHOWLONG, ixWdbeVLocale));
	me["TxtShowing2"] = StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::EMPLONG, ixWdbeVLocale));
};

void PnlWdbeGenList::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWdbeGenList";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWdbeGenList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Generics");
			writeStringAttr(wr, itemtag, "sref", "TcoSrf", "Identifier");
			writeStringAttr(wr, itemtag, "sref", "TcoMdl", "Module");
			writeStringAttr(wr, itemtag, "sref", "TcoHty", "HDL type");
			writeStringAttr(wr, itemtag, "sref", "TcoWid", "Width");
			writeStringAttr(wr, itemtag, "sref", "TcoMmx", "Range");
		};
		writeStringAttr(wr, itemtag, "sref", "TxtFor", VecWdbeVTag::getTitle(VecWdbeVTag::FOR, ixWdbeVLocale));
		writeStringAttr(wr, itemtag, "sref", "TxtRecord1", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::REC, ixWdbeVLocale)));
		writeStringAttr(wr, itemtag, "sref", "TxtRecord2", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::EMPLONG, ixWdbeVLocale)));
		writeStringAttr(wr, itemtag, "sref", "Trs", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::GOTO, ixWdbeVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "TxtShowing1", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::SHOWLONG, ixWdbeVLocale)));
		writeStringAttr(wr, itemtag, "sref", "TxtShowing2", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::EMPLONG, ixWdbeVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeGenList::DpchAppData
 ******************************************************************************/

PnlWdbeGenList::DpchAppData::DpchAppData() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEGENLISTDATA)
		{
};

string PnlWdbeGenList::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeGenList::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWdbeGenListData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
		if (stgiac.readJSON(me, true)) add(STGIAC);
		if (stgiacqry.readJSON(me, true)) add(STGIACQRY);
	} else {
		contiac = ContIac();
		stgiac = StgIac();
		stgiacqry = QryWdbeGenList::StgIac();
	};
};

void PnlWdbeGenList::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeGenListData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (stgiac.readXML(docctx, basexpath, true)) add(STGIAC);
		if (stgiacqry.readXML(docctx, basexpath, true)) add(STGIACQRY);
	} else {
		contiac = ContIac();
		stgiac = StgIac();
		stgiacqry = QryWdbeGenList::StgIac();
	};
};

/******************************************************************************
 class PnlWdbeGenList::DpchAppDo
 ******************************************************************************/

PnlWdbeGenList::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEGENLISTDO)
		{
	ixVDo = 0;
};

string PnlWdbeGenList::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeGenList::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWdbeGenListDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWdbeGenList::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeGenListDo");
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
 class PnlWdbeGenList::DpchEngData
 ******************************************************************************/

PnlWdbeGenList::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFCsiQst
			, Feed* feedFTos
			, StatShr* statshr
			, StgIac* stgiac
			, ListWdbeQGenList* rst
			, QryWdbeGenList::StatShr* statshrqry
			, QryWdbeGenList::StgIac* stgiacqry
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBEGENLISTDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFCSIQST, FEEDFTOS, STATSHR, STGIAC, TAG, RST, STATAPPQRY, STATSHRQRY, STGIACQRY};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFCSIQST) && feedFCsiQst) this->feedFCsiQst = *feedFCsiQst;
	if (find(this->mask, FEEDFTOS) && feedFTos) this->feedFTos = *feedFTos;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
	if (find(this->mask, STGIAC) && stgiac) this->stgiac = *stgiac;
	if (find(this->mask, RST) && rst) this->rst = *rst;
	if (find(this->mask, STATSHRQRY) && statshrqry) this->statshrqry = *statshrqry;
	if (find(this->mask, STGIACQRY) && stgiacqry) this->stgiacqry = *stgiacqry;
};

string PnlWdbeGenList::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFCSIQST)) ss.push_back("feedFCsiQst");
	if (has(FEEDFTOS)) ss.push_back("feedFTos");
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

void PnlWdbeGenList::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFCSIQST)) {feedFCsiQst = src->feedFCsiQst; add(FEEDFCSIQST);};
	if (src->has(FEEDFTOS)) {feedFTos = src->feedFTos; add(FEEDFTOS);};
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(STGIAC)) {stgiac = src->stgiac; add(STGIAC);};
	if (src->has(TAG)) add(TAG);
	if (src->has(RST)) {rst = src->rst; add(RST);};
	if (src->has(STATAPPQRY)) add(STATAPPQRY);
	if (src->has(STATSHRQRY)) {statshrqry = src->statshrqry; add(STATSHRQRY);};
	if (src->has(STGIACQRY)) {stgiacqry = src->stgiacqry; add(STGIACQRY);};
};

void PnlWdbeGenList::DpchEngData::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWdbeGenListData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFCSIQST)) feedFCsiQst.writeJSON(me);
	if (has(FEEDFTOS)) feedFTos.writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(STGIAC)) stgiac.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWdbeVLocale, me);
	if (has(RST)) rst.writeJSON(me);
	if (has(STATAPPQRY)) QryWdbeGenList::StatApp::writeJSON(me);
	if (has(STATSHRQRY)) statshrqry.writeJSON(me);
	if (has(STGIACQRY)) stgiacqry.writeJSON(me);
};

void PnlWdbeGenList::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWdbeGenListData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFCSIQST)) feedFCsiQst.writeXML(wr);
		if (has(FEEDFTOS)) feedFTos.writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
		if (has(RST)) rst.writeXML(wr);
		if (has(STATAPPQRY)) QryWdbeGenList::StatApp::writeXML(wr);
		if (has(STATSHRQRY)) statshrqry.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};
