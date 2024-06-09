/**
	* \file PnlWdbeNavGlobal_blks.cpp
	* job handler for job PnlWdbeNavGlobal (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbeNavGlobal::VecVDo
 ******************************************************************************/

uint PnlWdbeNavGlobal::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butmchviewclick") return BUTMCHVIEWCLICK;
	if (s == "butmchnewcrdclick") return BUTMCHNEWCRDCLICK;
	if (s == "butlibviewclick") return BUTLIBVIEWCLICK;
	if (s == "butlibnewcrdclick") return BUTLIBNEWCRDCLICK;
	if (s == "butfamviewclick") return BUTFAMVIEWCLICK;
	if (s == "butfamnewcrdclick") return BUTFAMNEWCRDCLICK;
	if (s == "butsilviewclick") return BUTSILVIEWCLICK;
	if (s == "butsilnewcrdclick") return BUTSILNEWCRDCLICK;
	if (s == "butmtpviewclick") return BUTMTPVIEWCLICK;
	if (s == "butmtpnewcrdclick") return BUTMTPNEWCRDCLICK;

	return(0);
};

string PnlWdbeNavGlobal::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMCHVIEWCLICK) return("ButMchViewClick");
	if (ix == BUTMCHNEWCRDCLICK) return("ButMchNewcrdClick");
	if (ix == BUTLIBVIEWCLICK) return("ButLibViewClick");
	if (ix == BUTLIBNEWCRDCLICK) return("ButLibNewcrdClick");
	if (ix == BUTFAMVIEWCLICK) return("ButFamViewClick");
	if (ix == BUTFAMNEWCRDCLICK) return("ButFamNewcrdClick");
	if (ix == BUTSILVIEWCLICK) return("ButSilViewClick");
	if (ix == BUTSILNEWCRDCLICK) return("ButSilNewcrdClick");
	if (ix == BUTMTPVIEWCLICK) return("ButMtpViewClick");
	if (ix == BUTMTPNEWCRDCLICK) return("ButMtpNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlWdbeNavGlobal::ContIac
 ******************************************************************************/

PnlWdbeNavGlobal::ContIac::ContIac(
			const uint numFLstMch
			, const uint numFLstLib
			, const uint numFLstFam
			, const uint numFLstSil
			, const uint numFLstMtp
		) :
			Block()
		{
	this->numFLstMch = numFLstMch;
	this->numFLstLib = numFLstLib;
	this->numFLstFam = numFLstFam;
	this->numFLstSil = numFLstSil;
	this->numFLstMtp = numFLstMtp;

	mask = {NUMFLSTMCH, NUMFLSTLIB, NUMFLSTFAM, NUMFLSTSIL, NUMFLSTMTP};
};

bool PnlWdbeNavGlobal::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacWdbeNavGlobal"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFLstMch")) {numFLstMch = me["numFLstMch"].asUInt(); add(NUMFLSTMCH);};
		if (me.isMember("numFLstLib")) {numFLstLib = me["numFLstLib"].asUInt(); add(NUMFLSTLIB);};
		if (me.isMember("numFLstFam")) {numFLstFam = me["numFLstFam"].asUInt(); add(NUMFLSTFAM);};
		if (me.isMember("numFLstSil")) {numFLstSil = me["numFLstSil"].asUInt(); add(NUMFLSTSIL);};
		if (me.isMember("numFLstMtp")) {numFLstMtp = me["numFLstMtp"].asUInt(); add(NUMFLSTMTP);};
	};

	return basefound;
};

bool PnlWdbeNavGlobal::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWdbeNavGlobal");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWdbeNavGlobal";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstMch", numFLstMch)) add(NUMFLSTMCH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstLib", numFLstLib)) add(NUMFLSTLIB);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstFam", numFLstFam)) add(NUMFLSTFAM);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstSil", numFLstSil)) add(NUMFLSTSIL);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstMtp", numFLstMtp)) add(NUMFLSTMTP);
	};

	return basefound;
};

void PnlWdbeNavGlobal::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeNavGlobal";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFLstMch"] = (Json::Value::UInt) numFLstMch;
	me["numFLstLib"] = (Json::Value::UInt) numFLstLib;
	me["numFLstFam"] = (Json::Value::UInt) numFLstFam;
	me["numFLstSil"] = (Json::Value::UInt) numFLstSil;
	me["numFLstMtp"] = (Json::Value::UInt) numFLstMtp;
};

void PnlWdbeNavGlobal::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeNavGlobal";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWdbeNavGlobal";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstMch", numFLstMch);
		writeUintAttr(wr, itemtag, "sref", "numFLstLib", numFLstLib);
		writeUintAttr(wr, itemtag, "sref", "numFLstFam", numFLstFam);
		writeUintAttr(wr, itemtag, "sref", "numFLstSil", numFLstSil);
		writeUintAttr(wr, itemtag, "sref", "numFLstMtp", numFLstMtp);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeNavGlobal::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstMch == comp->numFLstMch) insert(items, NUMFLSTMCH);
	if (numFLstLib == comp->numFLstLib) insert(items, NUMFLSTLIB);
	if (numFLstFam == comp->numFLstFam) insert(items, NUMFLSTFAM);
	if (numFLstSil == comp->numFLstSil) insert(items, NUMFLSTSIL);
	if (numFLstMtp == comp->numFLstMtp) insert(items, NUMFLSTMTP);

	return(items);
};

set<uint> PnlWdbeNavGlobal::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTMCH, NUMFLSTLIB, NUMFLSTFAM, NUMFLSTSIL, NUMFLSTMTP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeNavGlobal::StatApp
 ******************************************************************************/

void PnlWdbeNavGlobal::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWdbeVExpstate
			, const bool LstMchAlt
			, const bool LstLibAlt
			, const bool LstFamAlt
			, const bool LstSilAlt
			, const bool LstMtpAlt
			, const uint LstMchNumFirstdisp
			, const uint LstLibNumFirstdisp
			, const uint LstFamNumFirstdisp
			, const uint LstSilNumFirstdisp
			, const uint LstMtpNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeNavGlobal";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWdbeVExpstate"] = VecWdbeVExpstate::getSref(ixWdbeVExpstate);
	me["LstMchAlt"] = LstMchAlt;
	me["LstLibAlt"] = LstLibAlt;
	me["LstFamAlt"] = LstFamAlt;
	me["LstSilAlt"] = LstSilAlt;
	me["LstMtpAlt"] = LstMtpAlt;
	me["LstMchNumFirstdisp"] = (Json::Value::UInt) LstMchNumFirstdisp;
	me["LstLibNumFirstdisp"] = (Json::Value::UInt) LstLibNumFirstdisp;
	me["LstFamNumFirstdisp"] = (Json::Value::UInt) LstFamNumFirstdisp;
	me["LstSilNumFirstdisp"] = (Json::Value::UInt) LstSilNumFirstdisp;
	me["LstMtpNumFirstdisp"] = (Json::Value::UInt) LstMtpNumFirstdisp;
};

void PnlWdbeNavGlobal::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWdbeVExpstate
			, const bool LstMchAlt
			, const bool LstLibAlt
			, const bool LstFamAlt
			, const bool LstSilAlt
			, const bool LstMtpAlt
			, const uint LstMchNumFirstdisp
			, const uint LstLibNumFirstdisp
			, const uint LstFamNumFirstdisp
			, const uint LstSilNumFirstdisp
			, const uint LstMtpNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeNavGlobal";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWdbeNavGlobal";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWdbeVExpstate", VecWdbeVExpstate::getSref(ixWdbeVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstMchAlt", LstMchAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstLibAlt", LstLibAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstFamAlt", LstFamAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstSilAlt", LstSilAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstMtpAlt", LstMtpAlt);
		writeUintAttr(wr, itemtag, "sref", "LstMchNumFirstdisp", LstMchNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstLibNumFirstdisp", LstLibNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstFamNumFirstdisp", LstFamNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstSilNumFirstdisp", LstSilNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstMtpNumFirstdisp", LstMtpNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeNavGlobal::StatShr
 ******************************************************************************/

PnlWdbeNavGlobal::StatShr::StatShr(
			const bool LstMchAvail
			, const bool ButMchViewActive
			, const bool LstLibAvail
			, const bool ButLibViewActive
			, const bool LstFamAvail
			, const bool ButFamViewActive
			, const bool LstSilAvail
			, const bool ButSilViewActive
			, const bool LstMtpAvail
			, const bool ButMtpViewActive
		) :
			Block()
		{
	this->LstMchAvail = LstMchAvail;
	this->ButMchViewActive = ButMchViewActive;
	this->LstLibAvail = LstLibAvail;
	this->ButLibViewActive = ButLibViewActive;
	this->LstFamAvail = LstFamAvail;
	this->ButFamViewActive = ButFamViewActive;
	this->LstSilAvail = LstSilAvail;
	this->ButSilViewActive = ButSilViewActive;
	this->LstMtpAvail = LstMtpAvail;
	this->ButMtpViewActive = ButMtpViewActive;

	mask = {LSTMCHAVAIL, BUTMCHVIEWACTIVE, LSTLIBAVAIL, BUTLIBVIEWACTIVE, LSTFAMAVAIL, BUTFAMVIEWACTIVE, LSTSILAVAIL, BUTSILVIEWACTIVE, LSTMTPAVAIL, BUTMTPVIEWACTIVE};
};

void PnlWdbeNavGlobal::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeNavGlobal";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["LstMchAvail"] = LstMchAvail;
	me["ButMchViewActive"] = ButMchViewActive;
	me["LstLibAvail"] = LstLibAvail;
	me["ButLibViewActive"] = ButLibViewActive;
	me["LstFamAvail"] = LstFamAvail;
	me["ButFamViewActive"] = ButFamViewActive;
	me["LstSilAvail"] = LstSilAvail;
	me["ButSilViewActive"] = ButSilViewActive;
	me["LstMtpAvail"] = LstMtpAvail;
	me["ButMtpViewActive"] = ButMtpViewActive;
};

void PnlWdbeNavGlobal::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeNavGlobal";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWdbeNavGlobal";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "LstMchAvail", LstMchAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButMchViewActive", ButMchViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstLibAvail", LstLibAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButLibViewActive", ButLibViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstFamAvail", LstFamAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButFamViewActive", ButFamViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstSilAvail", LstSilAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSilViewActive", ButSilViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstMtpAvail", LstMtpAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButMtpViewActive", ButMtpViewActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeNavGlobal::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstMchAvail == comp->LstMchAvail) insert(items, LSTMCHAVAIL);
	if (ButMchViewActive == comp->ButMchViewActive) insert(items, BUTMCHVIEWACTIVE);
	if (LstLibAvail == comp->LstLibAvail) insert(items, LSTLIBAVAIL);
	if (ButLibViewActive == comp->ButLibViewActive) insert(items, BUTLIBVIEWACTIVE);
	if (LstFamAvail == comp->LstFamAvail) insert(items, LSTFAMAVAIL);
	if (ButFamViewActive == comp->ButFamViewActive) insert(items, BUTFAMVIEWACTIVE);
	if (LstSilAvail == comp->LstSilAvail) insert(items, LSTSILAVAIL);
	if (ButSilViewActive == comp->ButSilViewActive) insert(items, BUTSILVIEWACTIVE);
	if (LstMtpAvail == comp->LstMtpAvail) insert(items, LSTMTPAVAIL);
	if (ButMtpViewActive == comp->ButMtpViewActive) insert(items, BUTMTPVIEWACTIVE);

	return(items);
};

set<uint> PnlWdbeNavGlobal::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTMCHAVAIL, BUTMCHVIEWACTIVE, LSTLIBAVAIL, BUTLIBVIEWACTIVE, LSTFAMAVAIL, BUTFAMVIEWACTIVE, LSTSILAVAIL, BUTSILVIEWACTIVE, LSTMTPAVAIL, BUTMTPVIEWACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeNavGlobal::Tag
 ******************************************************************************/

void PnlWdbeNavGlobal::Tag::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWdbeNavGlobal";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		me["Cpt"] = "Global data module";
		me["CptMch"] = "machines";
		me["CptLib"] = "libraries";
		me["CptFam"] = "product families";
		me["CptSil"] = "silicon devices";
		me["CptMtp"] = "module templates";
	};
};

void PnlWdbeNavGlobal::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWdbeNavGlobal";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWdbeNavGlobal";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Global data module");
			writeStringAttr(wr, itemtag, "sref", "CptMch", "machines");
			writeStringAttr(wr, itemtag, "sref", "CptLib", "libraries");
			writeStringAttr(wr, itemtag, "sref", "CptFam", "product families");
			writeStringAttr(wr, itemtag, "sref", "CptSil", "silicon devices");
			writeStringAttr(wr, itemtag, "sref", "CptMtp", "module templates");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeNavGlobal::DpchAppData
 ******************************************************************************/

PnlWdbeNavGlobal::DpchAppData::DpchAppData() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBENAVGLOBALDATA)
		{
};

string PnlWdbeNavGlobal::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavGlobal::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWdbeNavGlobalData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWdbeNavGlobal::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeNavGlobalData");
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
 class PnlWdbeNavGlobal::DpchAppDo
 ******************************************************************************/

PnlWdbeNavGlobal::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBENAVGLOBALDO)
		{
	ixVDo = 0;
};

string PnlWdbeNavGlobal::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavGlobal::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWdbeNavGlobalDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWdbeNavGlobal::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeNavGlobalDo");
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
 class PnlWdbeNavGlobal::DpchEngData
 ******************************************************************************/

PnlWdbeNavGlobal::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, Feed* feedFLstFam
			, Feed* feedFLstLib
			, Feed* feedFLstMch
			, Feed* feedFLstMtp
			, Feed* feedFLstSil
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBENAVGLOBALDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, FEEDFLSTFAM, FEEDFLSTLIB, FEEDFLSTMCH, FEEDFLSTMTP, FEEDFLSTSIL, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, FEEDFLSTFAM) && feedFLstFam) this->feedFLstFam = *feedFLstFam;
	if (find(this->mask, FEEDFLSTLIB) && feedFLstLib) this->feedFLstLib = *feedFLstLib;
	if (find(this->mask, FEEDFLSTMCH) && feedFLstMch) this->feedFLstMch = *feedFLstMch;
	if (find(this->mask, FEEDFLSTMTP) && feedFLstMtp) this->feedFLstMtp = *feedFLstMtp;
	if (find(this->mask, FEEDFLSTSIL) && feedFLstSil) this->feedFLstSil = *feedFLstSil;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWdbeNavGlobal::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTFAM)) ss.push_back("feedFLstFam");
	if (has(FEEDFLSTLIB)) ss.push_back("feedFLstLib");
	if (has(FEEDFLSTMCH)) ss.push_back("feedFLstMch");
	if (has(FEEDFLSTMTP)) ss.push_back("feedFLstMtp");
	if (has(FEEDFLSTSIL)) ss.push_back("feedFLstSil");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavGlobal::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(FEEDFLSTFAM)) {feedFLstFam = src->feedFLstFam; add(FEEDFLSTFAM);};
	if (src->has(FEEDFLSTLIB)) {feedFLstLib = src->feedFLstLib; add(FEEDFLSTLIB);};
	if (src->has(FEEDFLSTMCH)) {feedFLstMch = src->feedFLstMch; add(FEEDFLSTMCH);};
	if (src->has(FEEDFLSTMTP)) {feedFLstMtp = src->feedFLstMtp; add(FEEDFLSTMTP);};
	if (src->has(FEEDFLSTSIL)) {feedFLstSil = src->feedFLstSil; add(FEEDFLSTSIL);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWdbeNavGlobal::DpchEngData::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWdbeNavGlobalData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(FEEDFLSTFAM)) feedFLstFam.writeJSON(me);
	if (has(FEEDFLSTLIB)) feedFLstLib.writeJSON(me);
	if (has(FEEDFLSTMCH)) feedFLstMch.writeJSON(me);
	if (has(FEEDFLSTMTP)) feedFLstMtp.writeJSON(me);
	if (has(FEEDFLSTSIL)) feedFLstSil.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWdbeVLocale, me);
};

void PnlWdbeNavGlobal::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWdbeNavGlobalData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(FEEDFLSTFAM)) feedFLstFam.writeXML(wr);
		if (has(FEEDFLSTLIB)) feedFLstLib.writeXML(wr);
		if (has(FEEDFLSTMCH)) feedFLstMch.writeXML(wr);
		if (has(FEEDFLSTMTP)) feedFLstMtp.writeXML(wr);
		if (has(FEEDFLSTSIL)) feedFLstSil.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};
