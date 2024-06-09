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
		{
	this->numFLstPrj = numFLstPrj;
	this->numFLstVer = numFLstVer;
	this->numFLstUnt = numFLstUnt;

	mask = {NUMFLSTPRJ, NUMFLSTVER, NUMFLSTUNT};
};

bool PnlWdbeNavDevdev::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacWdbeNavDevdev"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFLstPrj")) {numFLstPrj = me["numFLstPrj"].asUInt(); add(NUMFLSTPRJ);};
		if (me.isMember("numFLstVer")) {numFLstVer = me["numFLstVer"].asUInt(); add(NUMFLSTVER);};
		if (me.isMember("numFLstUnt")) {numFLstUnt = me["numFLstUnt"].asUInt(); add(NUMFLSTUNT);};
	};

	return basefound;
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

void PnlWdbeNavDevdev::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeNavDevdev";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFLstPrj"] = (Json::Value::UInt) numFLstPrj;
	me["numFLstVer"] = (Json::Value::UInt) numFLstVer;
	me["numFLstUnt"] = (Json::Value::UInt) numFLstUnt;
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

void PnlWdbeNavDevdev::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWdbeVExpstate
			, const bool LstPrjAlt
			, const bool LstVerAlt
			, const bool LstUntAlt
			, const uint LstPrjNumFirstdisp
			, const uint LstVerNumFirstdisp
			, const uint LstUntNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeNavDevdev";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWdbeVExpstate"] = VecWdbeVExpstate::getSref(ixWdbeVExpstate);
	me["LstPrjAlt"] = LstPrjAlt;
	me["LstVerAlt"] = LstVerAlt;
	me["LstUntAlt"] = LstUntAlt;
	me["LstPrjNumFirstdisp"] = (Json::Value::UInt) LstPrjNumFirstdisp;
	me["LstVerNumFirstdisp"] = (Json::Value::UInt) LstVerNumFirstdisp;
	me["LstUntNumFirstdisp"] = (Json::Value::UInt) LstUntNumFirstdisp;
};

void PnlWdbeNavDevdev::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWdbeVExpstate
			, const bool LstPrjAlt
			, const bool LstVerAlt
			, const bool LstUntAlt
			, const uint LstPrjNumFirstdisp
			, const uint LstVerNumFirstdisp
			, const uint LstUntNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeNavDevdev";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWdbeNavDevdev";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWdbeVExpstate", VecWdbeVExpstate::getSref(ixWdbeVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstPrjAlt", LstPrjAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstVerAlt", LstVerAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstUntAlt", LstUntAlt);
		writeUintAttr(wr, itemtag, "sref", "LstPrjNumFirstdisp", LstPrjNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstVerNumFirstdisp", LstVerNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstUntNumFirstdisp", LstUntNumFirstdisp);
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
			, const bool LstUntAvail
			, const bool ButUntViewActive
			, const bool ButUntNewcrdActive
		) :
			Block()
		{
	this->LstPrjAvail = LstPrjAvail;
	this->ButPrjViewActive = ButPrjViewActive;
	this->LstVerAvail = LstVerAvail;
	this->ButVerViewActive = ButVerViewActive;
	this->LstUntAvail = LstUntAvail;
	this->ButUntViewActive = ButUntViewActive;
	this->ButUntNewcrdActive = ButUntNewcrdActive;

	mask = {LSTPRJAVAIL, BUTPRJVIEWACTIVE, LSTVERAVAIL, BUTVERVIEWACTIVE, LSTUNTAVAIL, BUTUNTVIEWACTIVE, BUTUNTNEWCRDACTIVE};
};

void PnlWdbeNavDevdev::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeNavDevdev";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["LstPrjAvail"] = LstPrjAvail;
	me["ButPrjViewActive"] = ButPrjViewActive;
	me["LstVerAvail"] = LstVerAvail;
	me["ButVerViewActive"] = ButVerViewActive;
	me["LstUntAvail"] = LstUntAvail;
	me["ButUntViewActive"] = ButUntViewActive;
	me["ButUntNewcrdActive"] = ButUntNewcrdActive;
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
		writeBoolAttr(wr, itemtag, "sref", "LstUntAvail", LstUntAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButUntViewActive", ButUntViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButUntNewcrdActive", ButUntNewcrdActive);
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

void PnlWdbeNavDevdev::Tag::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWdbeNavDevdev";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		me["Cpt"] = "Device development module";
		me["CptPrj"] = "projects";
		me["CptVer"] = "versions";
		me["CptUnt"] = "units";
	};
};

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
			writeStringAttr(wr, itemtag, "sref", "CptUnt", "units");
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

void PnlWdbeNavDevdev::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWdbeNavDevdevData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
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

void PnlWdbeNavDevdev::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWdbeNavDevdevDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
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
			, Feed* feedFLstUnt
			, Feed* feedFLstVer
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBENAVDEVDEVDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, FEEDFLSTPRJ, FEEDFLSTUNT, FEEDFLSTVER, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, FEEDFLSTPRJ) && feedFLstPrj) this->feedFLstPrj = *feedFLstPrj;
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
	if (src->has(FEEDFLSTUNT)) {feedFLstUnt = src->feedFLstUnt; add(FEEDFLSTUNT);};
	if (src->has(FEEDFLSTVER)) {feedFLstVer = src->feedFLstVer; add(FEEDFLSTVER);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWdbeNavDevdev::DpchEngData::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWdbeNavDevdevData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(FEEDFLSTPRJ)) feedFLstPrj.writeJSON(me);
	if (has(FEEDFLSTUNT)) feedFLstUnt.writeJSON(me);
	if (has(FEEDFLSTVER)) feedFLstVer.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWdbeVLocale, me);
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
		if (has(FEEDFLSTUNT)) feedFLstUnt.writeXML(wr);
		if (has(FEEDFLSTVER)) feedFLstVer.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};
