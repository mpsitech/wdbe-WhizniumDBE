/**
	* \file PnlWdbeCdcDetail_blks.cpp
	* job handler for job PnlWdbeCdcDetail (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 9 May 2023
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbeCdcDetail::VecVDo
 ******************************************************************************/

uint PnlWdbeCdcDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butfckviewclick") return BUTFCKVIEWCLICK;
	if (s == "butsckviewclick") return BUTSCKVIEWCLICK;
	if (s == "butmdlviewclick") return BUTMDLVIEWCLICK;
	if (s == "butfarviewclick") return BUTFARVIEWCLICK;
	if (s == "butsarviewclick") return BUTSARVIEWCLICK;

	return(0);
};

string PnlWdbeCdcDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTFCKVIEWCLICK) return("ButFckViewClick");
	if (ix == BUTSCKVIEWCLICK) return("ButSckViewClick");
	if (ix == BUTMDLVIEWCLICK) return("ButMdlViewClick");
	if (ix == BUTFARVIEWCLICK) return("ButFarViewClick");
	if (ix == BUTSARVIEWCLICK) return("ButSarViewClick");

	return("");
};

/******************************************************************************
 class PnlWdbeCdcDetail::ContIac
 ******************************************************************************/

PnlWdbeCdcDetail::ContIac::ContIac(
			const string& TxfFck
			, const string& TxfSck
			, const string& TxfFar
			, const string& TxfSar
			, const string& TxfRat
		) :
			Block()
			, TxfFck(TxfFck)
			, TxfSck(TxfSck)
			, TxfFar(TxfFar)
			, TxfSar(TxfSar)
			, TxfRat(TxfRat)
		{
	mask = {TXFFCK, TXFSCK, TXFFAR, TXFSAR, TXFRAT};
};

bool PnlWdbeCdcDetail::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacWdbeCdcDetail"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("TxfFck")) {TxfFck = me["TxfFck"].asString(); add(TXFFCK);};
		if (me.isMember("TxfSck")) {TxfSck = me["TxfSck"].asString(); add(TXFSCK);};
		if (me.isMember("TxfFar")) {TxfFar = me["TxfFar"].asString(); add(TXFFAR);};
		if (me.isMember("TxfSar")) {TxfSar = me["TxfSar"].asString(); add(TXFSAR);};
		if (me.isMember("TxfRat")) {TxfRat = me["TxfRat"].asString(); add(TXFRAT);};
	};

	return basefound;
};

bool PnlWdbeCdcDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWdbeCdcDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWdbeCdcDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFck", TxfFck)) add(TXFFCK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSck", TxfSck)) add(TXFSCK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFar", TxfFar)) add(TXFFAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSar", TxfSar)) add(TXFSAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfRat", TxfRat)) add(TXFRAT);
	};

	return basefound;
};

void PnlWdbeCdcDetail::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeCdcDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxfFck"] = TxfFck;
	me["TxfSck"] = TxfSck;
	me["TxfFar"] = TxfFar;
	me["TxfSar"] = TxfSar;
	me["TxfRat"] = TxfRat;
};

void PnlWdbeCdcDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeCdcDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWdbeCdcDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfFck", TxfFck);
		writeStringAttr(wr, itemtag, "sref", "TxfSck", TxfSck);
		writeStringAttr(wr, itemtag, "sref", "TxfFar", TxfFar);
		writeStringAttr(wr, itemtag, "sref", "TxfSar", TxfSar);
		writeStringAttr(wr, itemtag, "sref", "TxfRat", TxfRat);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeCdcDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfFck == comp->TxfFck) insert(items, TXFFCK);
	if (TxfSck == comp->TxfSck) insert(items, TXFSCK);
	if (TxfFar == comp->TxfFar) insert(items, TXFFAR);
	if (TxfSar == comp->TxfSar) insert(items, TXFSAR);
	if (TxfRat == comp->TxfRat) insert(items, TXFRAT);

	return(items);
};

set<uint> PnlWdbeCdcDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFFCK, TXFSCK, TXFFAR, TXFSAR, TXFRAT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeCdcDetail::ContInf
 ******************************************************************************/

PnlWdbeCdcDetail::ContInf::ContInf(
			const string& TxtFck
			, const string& TxtSck
			, const string& TxtMdl
			, const string& TxtFar
			, const string& TxtSar
		) :
			Block()
			, TxtFck(TxtFck)
			, TxtSck(TxtSck)
			, TxtMdl(TxtMdl)
			, TxtFar(TxtFar)
			, TxtSar(TxtSar)
		{
	mask = {TXTFCK, TXTSCK, TXTMDL, TXTFAR, TXTSAR};
};

void PnlWdbeCdcDetail::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbeCdcDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtFck"] = TxtFck;
	me["TxtSck"] = TxtSck;
	me["TxtMdl"] = TxtMdl;
	me["TxtFar"] = TxtFar;
	me["TxtSar"] = TxtSar;
};

void PnlWdbeCdcDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbeCdcDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWdbeCdcDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtFck", TxtFck);
		writeStringAttr(wr, itemtag, "sref", "TxtSck", TxtSck);
		writeStringAttr(wr, itemtag, "sref", "TxtMdl", TxtMdl);
		writeStringAttr(wr, itemtag, "sref", "TxtFar", TxtFar);
		writeStringAttr(wr, itemtag, "sref", "TxtSar", TxtSar);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeCdcDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtFck == comp->TxtFck) insert(items, TXTFCK);
	if (TxtSck == comp->TxtSck) insert(items, TXTSCK);
	if (TxtMdl == comp->TxtMdl) insert(items, TXTMDL);
	if (TxtFar == comp->TxtFar) insert(items, TXTFAR);
	if (TxtSar == comp->TxtSar) insert(items, TXTSAR);

	return(items);
};

set<uint> PnlWdbeCdcDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTFCK, TXTSCK, TXTMDL, TXTFAR, TXTSAR};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeCdcDetail::StatApp
 ******************************************************************************/

void PnlWdbeCdcDetail::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWdbeVExpstate
			, const bool TxtFckAlt
			, const bool TxtSckAlt
			, const bool TxtFarAlt
			, const bool TxtSarAlt
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeCdcDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWdbeVExpstate"] = VecWdbeVExpstate::getSref(ixWdbeVExpstate);
	me["TxtFckAlt"] = TxtFckAlt;
	me["TxtSckAlt"] = TxtSckAlt;
	me["TxtFarAlt"] = TxtFarAlt;
	me["TxtSarAlt"] = TxtSarAlt;
};

void PnlWdbeCdcDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWdbeVExpstate
			, const bool TxtFckAlt
			, const bool TxtSckAlt
			, const bool TxtFarAlt
			, const bool TxtSarAlt
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeCdcDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWdbeCdcDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWdbeVExpstate", VecWdbeVExpstate::getSref(ixWdbeVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "TxtFckAlt", TxtFckAlt);
		writeBoolAttr(wr, itemtag, "sref", "TxtSckAlt", TxtSckAlt);
		writeBoolAttr(wr, itemtag, "sref", "TxtFarAlt", TxtFarAlt);
		writeBoolAttr(wr, itemtag, "sref", "TxtSarAlt", TxtSarAlt);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeCdcDetail::StatShr
 ******************************************************************************/

PnlWdbeCdcDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtFckActive
			, const bool TxfFckValid
			, const bool ButFckViewAvail
			, const bool TxtSckActive
			, const bool TxfSckValid
			, const bool ButSckViewAvail
			, const bool TxtMdlActive
			, const bool ButMdlViewAvail
			, const bool ButMdlViewActive
			, const bool TxtFarActive
			, const bool TxfFarValid
			, const bool ButFarViewAvail
			, const bool TxtSarActive
			, const bool TxfSarValid
			, const bool ButSarViewAvail
			, const bool TxfRatActive
		) :
			Block()
			, ButSaveAvail(ButSaveAvail)
			, ButSaveActive(ButSaveActive)
			, TxtFckActive(TxtFckActive)
			, TxfFckValid(TxfFckValid)
			, ButFckViewAvail(ButFckViewAvail)
			, TxtSckActive(TxtSckActive)
			, TxfSckValid(TxfSckValid)
			, ButSckViewAvail(ButSckViewAvail)
			, TxtMdlActive(TxtMdlActive)
			, ButMdlViewAvail(ButMdlViewAvail)
			, ButMdlViewActive(ButMdlViewActive)
			, TxtFarActive(TxtFarActive)
			, TxfFarValid(TxfFarValid)
			, ButFarViewAvail(ButFarViewAvail)
			, TxtSarActive(TxtSarActive)
			, TxfSarValid(TxfSarValid)
			, ButSarViewAvail(ButSarViewAvail)
			, TxfRatActive(TxfRatActive)
		{
	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTFCKACTIVE, TXFFCKVALID, BUTFCKVIEWAVAIL, TXTSCKACTIVE, TXFSCKVALID, BUTSCKVIEWAVAIL, TXTMDLACTIVE, BUTMDLVIEWAVAIL, BUTMDLVIEWACTIVE, TXTFARACTIVE, TXFFARVALID, BUTFARVIEWAVAIL, TXTSARACTIVE, TXFSARVALID, BUTSARVIEWAVAIL, TXFRATACTIVE};
};

void PnlWdbeCdcDetail::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeCdcDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButSaveAvail"] = ButSaveAvail;
	me["ButSaveActive"] = ButSaveActive;
	me["TxtFckActive"] = TxtFckActive;
	me["TxfFckValid"] = TxfFckValid;
	me["ButFckViewAvail"] = ButFckViewAvail;
	me["TxtSckActive"] = TxtSckActive;
	me["TxfSckValid"] = TxfSckValid;
	me["ButSckViewAvail"] = ButSckViewAvail;
	me["TxtMdlActive"] = TxtMdlActive;
	me["ButMdlViewAvail"] = ButMdlViewAvail;
	me["ButMdlViewActive"] = ButMdlViewActive;
	me["TxtFarActive"] = TxtFarActive;
	me["TxfFarValid"] = TxfFarValid;
	me["ButFarViewAvail"] = ButFarViewAvail;
	me["TxtSarActive"] = TxtSarActive;
	me["TxfSarValid"] = TxfSarValid;
	me["ButSarViewAvail"] = ButSarViewAvail;
	me["TxfRatActive"] = TxfRatActive;
};

void PnlWdbeCdcDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeCdcDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWdbeCdcDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtFckActive", TxtFckActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfFckValid", TxfFckValid);
		writeBoolAttr(wr, itemtag, "sref", "ButFckViewAvail", ButFckViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtSckActive", TxtSckActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfSckValid", TxfSckValid);
		writeBoolAttr(wr, itemtag, "sref", "ButSckViewAvail", ButSckViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtMdlActive", TxtMdlActive);
		writeBoolAttr(wr, itemtag, "sref", "ButMdlViewAvail", ButMdlViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButMdlViewActive", ButMdlViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtFarActive", TxtFarActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfFarValid", TxfFarValid);
		writeBoolAttr(wr, itemtag, "sref", "ButFarViewAvail", ButFarViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtSarActive", TxtSarActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfSarValid", TxfSarValid);
		writeBoolAttr(wr, itemtag, "sref", "ButSarViewAvail", ButSarViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfRatActive", TxfRatActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeCdcDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtFckActive == comp->TxtFckActive) insert(items, TXTFCKACTIVE);
	if (TxfFckValid == comp->TxfFckValid) insert(items, TXFFCKVALID);
	if (ButFckViewAvail == comp->ButFckViewAvail) insert(items, BUTFCKVIEWAVAIL);
	if (TxtSckActive == comp->TxtSckActive) insert(items, TXTSCKACTIVE);
	if (TxfSckValid == comp->TxfSckValid) insert(items, TXFSCKVALID);
	if (ButSckViewAvail == comp->ButSckViewAvail) insert(items, BUTSCKVIEWAVAIL);
	if (TxtMdlActive == comp->TxtMdlActive) insert(items, TXTMDLACTIVE);
	if (ButMdlViewAvail == comp->ButMdlViewAvail) insert(items, BUTMDLVIEWAVAIL);
	if (ButMdlViewActive == comp->ButMdlViewActive) insert(items, BUTMDLVIEWACTIVE);
	if (TxtFarActive == comp->TxtFarActive) insert(items, TXTFARACTIVE);
	if (TxfFarValid == comp->TxfFarValid) insert(items, TXFFARVALID);
	if (ButFarViewAvail == comp->ButFarViewAvail) insert(items, BUTFARVIEWAVAIL);
	if (TxtSarActive == comp->TxtSarActive) insert(items, TXTSARACTIVE);
	if (TxfSarValid == comp->TxfSarValid) insert(items, TXFSARVALID);
	if (ButSarViewAvail == comp->ButSarViewAvail) insert(items, BUTSARVIEWAVAIL);
	if (TxfRatActive == comp->TxfRatActive) insert(items, TXFRATACTIVE);

	return(items);
};

set<uint> PnlWdbeCdcDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTFCKACTIVE, TXFFCKVALID, BUTFCKVIEWAVAIL, TXTSCKACTIVE, TXFSCKVALID, BUTSCKVIEWAVAIL, TXTMDLACTIVE, BUTMDLVIEWAVAIL, BUTMDLVIEWACTIVE, TXTFARACTIVE, TXFFARVALID, BUTFARVIEWAVAIL, TXTSARACTIVE, TXFSARVALID, BUTSARVIEWAVAIL, TXFRATACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeCdcDetail::Tag
 ******************************************************************************/

void PnlWdbeCdcDetail::Tag::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWdbeCdcDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		me["CptFck"] = "fast clock signal";
		me["CptSck"] = "slow clock signal";
		me["CptMdl"] = "module";
		me["CptFar"] = "fast asynchronous reset signal";
		me["CptSar"] = "slow asynchronous reset signal";
		me["CptRat"] = "clock ratio fast to slow";
	};
	me["Cpt"] = StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DETAIL, ixWdbeVLocale));
};

void PnlWdbeCdcDetail::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWdbeCdcDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWdbeCdcDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptFck", "fast clock signal");
			writeStringAttr(wr, itemtag, "sref", "CptSck", "slow clock signal");
			writeStringAttr(wr, itemtag, "sref", "CptMdl", "module");
			writeStringAttr(wr, itemtag, "sref", "CptFar", "fast asynchronous reset signal");
			writeStringAttr(wr, itemtag, "sref", "CptSar", "slow asynchronous reset signal");
			writeStringAttr(wr, itemtag, "sref", "CptRat", "clock ratio fast to slow");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DETAIL, ixWdbeVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeCdcDetail::DpchAppData
 ******************************************************************************/

PnlWdbeCdcDetail::DpchAppData::DpchAppData() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBECDCDETAILDATA)
		{
};

string PnlWdbeCdcDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeCdcDetail::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWdbeCdcDetailData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWdbeCdcDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeCdcDetailData");
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
 class PnlWdbeCdcDetail::DpchAppDo
 ******************************************************************************/

PnlWdbeCdcDetail::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBECDCDETAILDO)
		{
	ixVDo = 0;
};

string PnlWdbeCdcDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeCdcDetail::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWdbeCdcDetailDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWdbeCdcDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeCdcDetailDo");
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
 class PnlWdbeCdcDetail::DpchEngData
 ******************************************************************************/

PnlWdbeCdcDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBECDCDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWdbeCdcDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeCdcDetail::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWdbeCdcDetail::DpchEngData::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWdbeCdcDetailData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWdbeVLocale, me);
};

void PnlWdbeCdcDetail::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWdbeCdcDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};
