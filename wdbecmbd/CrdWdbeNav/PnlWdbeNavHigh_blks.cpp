/**
	* \file PnlWdbeNavHigh_blks.cpp
	* job handler for job PnlWdbeNavHigh (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbeNavHigh::VecVDo
 ******************************************************************************/

uint PnlWdbeNavHigh::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butpphviewclick") return BUTPPHVIEWCLICK;
	if (s == "butpphnewcrdclick") return BUTPPHNEWCRDCLICK;
	if (s == "butmodviewclick") return BUTMODVIEWCLICK;
	if (s == "butmodnewcrdclick") return BUTMODNEWCRDCLICK;
	if (s == "butvecviewclick") return BUTVECVIEWCLICK;
	if (s == "butvecnewcrdclick") return BUTVECNEWCRDCLICK;
	if (s == "butvitviewclick") return BUTVITVIEWCLICK;
	if (s == "butcmdviewclick") return BUTCMDVIEWCLICK;
	if (s == "butcmdnewcrdclick") return BUTCMDNEWCRDCLICK;
	if (s == "buterrviewclick") return BUTERRVIEWCLICK;
	if (s == "buterrnewcrdclick") return BUTERRNEWCRDCLICK;
	if (s == "butpplviewclick") return BUTPPLVIEWCLICK;
	if (s == "butpplnewcrdclick") return BUTPPLNEWCRDCLICK;
	if (s == "butsegviewclick") return BUTSEGVIEWCLICK;
	if (s == "butsegnewcrdclick") return BUTSEGNEWCRDCLICK;

	return(0);
};

string PnlWdbeNavHigh::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTPPHVIEWCLICK) return("ButPphViewClick");
	if (ix == BUTPPHNEWCRDCLICK) return("ButPphNewcrdClick");
	if (ix == BUTMODVIEWCLICK) return("ButModViewClick");
	if (ix == BUTMODNEWCRDCLICK) return("ButModNewcrdClick");
	if (ix == BUTVECVIEWCLICK) return("ButVecViewClick");
	if (ix == BUTVECNEWCRDCLICK) return("ButVecNewcrdClick");
	if (ix == BUTVITVIEWCLICK) return("ButVitViewClick");
	if (ix == BUTCMDVIEWCLICK) return("ButCmdViewClick");
	if (ix == BUTCMDNEWCRDCLICK) return("ButCmdNewcrdClick");
	if (ix == BUTERRVIEWCLICK) return("ButErrViewClick");
	if (ix == BUTERRNEWCRDCLICK) return("ButErrNewcrdClick");
	if (ix == BUTPPLVIEWCLICK) return("ButPplViewClick");
	if (ix == BUTPPLNEWCRDCLICK) return("ButPplNewcrdClick");
	if (ix == BUTSEGVIEWCLICK) return("ButSegViewClick");
	if (ix == BUTSEGNEWCRDCLICK) return("ButSegNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlWdbeNavHigh::ContIac
 ******************************************************************************/

PnlWdbeNavHigh::ContIac::ContIac(
			const uint numFLstPph
			, const uint numFLstMod
			, const uint numFLstVec
			, const uint numFLstVit
			, const uint numFLstCmd
			, const uint numFLstErr
			, const uint numFLstPpl
			, const uint numFLstSeg
		) :
			Block()
		{
	this->numFLstPph = numFLstPph;
	this->numFLstMod = numFLstMod;
	this->numFLstVec = numFLstVec;
	this->numFLstVit = numFLstVit;
	this->numFLstCmd = numFLstCmd;
	this->numFLstErr = numFLstErr;
	this->numFLstPpl = numFLstPpl;
	this->numFLstSeg = numFLstSeg;

	mask = {NUMFLSTPPH, NUMFLSTMOD, NUMFLSTVEC, NUMFLSTVIT, NUMFLSTCMD, NUMFLSTERR, NUMFLSTPPL, NUMFLSTSEG};
};

bool PnlWdbeNavHigh::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacWdbeNavHigh"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFLstPph")) {numFLstPph = me["numFLstPph"].asUInt(); add(NUMFLSTPPH);};
		if (me.isMember("numFLstMod")) {numFLstMod = me["numFLstMod"].asUInt(); add(NUMFLSTMOD);};
		if (me.isMember("numFLstVec")) {numFLstVec = me["numFLstVec"].asUInt(); add(NUMFLSTVEC);};
		if (me.isMember("numFLstVit")) {numFLstVit = me["numFLstVit"].asUInt(); add(NUMFLSTVIT);};
		if (me.isMember("numFLstCmd")) {numFLstCmd = me["numFLstCmd"].asUInt(); add(NUMFLSTCMD);};
		if (me.isMember("numFLstErr")) {numFLstErr = me["numFLstErr"].asUInt(); add(NUMFLSTERR);};
		if (me.isMember("numFLstPpl")) {numFLstPpl = me["numFLstPpl"].asUInt(); add(NUMFLSTPPL);};
		if (me.isMember("numFLstSeg")) {numFLstSeg = me["numFLstSeg"].asUInt(); add(NUMFLSTSEG);};
	};

	return basefound;
};

bool PnlWdbeNavHigh::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWdbeNavHigh");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWdbeNavHigh";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstPph", numFLstPph)) add(NUMFLSTPPH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstMod", numFLstMod)) add(NUMFLSTMOD);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstVec", numFLstVec)) add(NUMFLSTVEC);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstVit", numFLstVit)) add(NUMFLSTVIT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstCmd", numFLstCmd)) add(NUMFLSTCMD);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstErr", numFLstErr)) add(NUMFLSTERR);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstPpl", numFLstPpl)) add(NUMFLSTPPL);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstSeg", numFLstSeg)) add(NUMFLSTSEG);
	};

	return basefound;
};

void PnlWdbeNavHigh::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeNavHigh";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFLstPph"] = numFLstPph;
	me["numFLstMod"] = numFLstMod;
	me["numFLstVec"] = numFLstVec;
	me["numFLstVit"] = numFLstVit;
	me["numFLstCmd"] = numFLstCmd;
	me["numFLstErr"] = numFLstErr;
	me["numFLstPpl"] = numFLstPpl;
	me["numFLstSeg"] = numFLstSeg;
};

void PnlWdbeNavHigh::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeNavHigh";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWdbeNavHigh";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstPph", numFLstPph);
		writeUintAttr(wr, itemtag, "sref", "numFLstMod", numFLstMod);
		writeUintAttr(wr, itemtag, "sref", "numFLstVec", numFLstVec);
		writeUintAttr(wr, itemtag, "sref", "numFLstVit", numFLstVit);
		writeUintAttr(wr, itemtag, "sref", "numFLstCmd", numFLstCmd);
		writeUintAttr(wr, itemtag, "sref", "numFLstErr", numFLstErr);
		writeUintAttr(wr, itemtag, "sref", "numFLstPpl", numFLstPpl);
		writeUintAttr(wr, itemtag, "sref", "numFLstSeg", numFLstSeg);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeNavHigh::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstPph == comp->numFLstPph) insert(items, NUMFLSTPPH);
	if (numFLstMod == comp->numFLstMod) insert(items, NUMFLSTMOD);
	if (numFLstVec == comp->numFLstVec) insert(items, NUMFLSTVEC);
	if (numFLstVit == comp->numFLstVit) insert(items, NUMFLSTVIT);
	if (numFLstCmd == comp->numFLstCmd) insert(items, NUMFLSTCMD);
	if (numFLstErr == comp->numFLstErr) insert(items, NUMFLSTERR);
	if (numFLstPpl == comp->numFLstPpl) insert(items, NUMFLSTPPL);
	if (numFLstSeg == comp->numFLstSeg) insert(items, NUMFLSTSEG);

	return(items);
};

set<uint> PnlWdbeNavHigh::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTPPH, NUMFLSTMOD, NUMFLSTVEC, NUMFLSTVIT, NUMFLSTCMD, NUMFLSTERR, NUMFLSTPPL, NUMFLSTSEG};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeNavHigh::StatApp
 ******************************************************************************/

void PnlWdbeNavHigh::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWdbeVExpstate
			, const bool LstPphAlt
			, const bool LstModAlt
			, const bool LstVecAlt
			, const bool LstVitAlt
			, const bool LstCmdAlt
			, const bool LstErrAlt
			, const bool LstPplAlt
			, const bool LstSegAlt
			, const uint LstPphNumFirstdisp
			, const uint LstModNumFirstdisp
			, const uint LstVecNumFirstdisp
			, const uint LstVitNumFirstdisp
			, const uint LstCmdNumFirstdisp
			, const uint LstErrNumFirstdisp
			, const uint LstPplNumFirstdisp
			, const uint LstSegNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeNavHigh";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWdbeVExpstate"] = VecWdbeVExpstate::getSref(ixWdbeVExpstate);
	me["LstPphAlt"] = LstPphAlt;
	me["LstModAlt"] = LstModAlt;
	me["LstVecAlt"] = LstVecAlt;
	me["LstVitAlt"] = LstVitAlt;
	me["LstCmdAlt"] = LstCmdAlt;
	me["LstErrAlt"] = LstErrAlt;
	me["LstPplAlt"] = LstPplAlt;
	me["LstSegAlt"] = LstSegAlt;
	me["LstPphNumFirstdisp"] = LstPphNumFirstdisp;
	me["LstModNumFirstdisp"] = LstModNumFirstdisp;
	me["LstVecNumFirstdisp"] = LstVecNumFirstdisp;
	me["LstVitNumFirstdisp"] = LstVitNumFirstdisp;
	me["LstCmdNumFirstdisp"] = LstCmdNumFirstdisp;
	me["LstErrNumFirstdisp"] = LstErrNumFirstdisp;
	me["LstPplNumFirstdisp"] = LstPplNumFirstdisp;
	me["LstSegNumFirstdisp"] = LstSegNumFirstdisp;
};

void PnlWdbeNavHigh::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWdbeVExpstate
			, const bool LstPphAlt
			, const bool LstModAlt
			, const bool LstVecAlt
			, const bool LstVitAlt
			, const bool LstCmdAlt
			, const bool LstErrAlt
			, const bool LstPplAlt
			, const bool LstSegAlt
			, const uint LstPphNumFirstdisp
			, const uint LstModNumFirstdisp
			, const uint LstVecNumFirstdisp
			, const uint LstVitNumFirstdisp
			, const uint LstCmdNumFirstdisp
			, const uint LstErrNumFirstdisp
			, const uint LstPplNumFirstdisp
			, const uint LstSegNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeNavHigh";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWdbeNavHigh";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWdbeVExpstate", VecWdbeVExpstate::getSref(ixWdbeVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstPphAlt", LstPphAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstModAlt", LstModAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstVecAlt", LstVecAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstVitAlt", LstVitAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstCmdAlt", LstCmdAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstErrAlt", LstErrAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstPplAlt", LstPplAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstSegAlt", LstSegAlt);
		writeUintAttr(wr, itemtag, "sref", "LstPphNumFirstdisp", LstPphNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstModNumFirstdisp", LstModNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstVecNumFirstdisp", LstVecNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstVitNumFirstdisp", LstVitNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstCmdNumFirstdisp", LstCmdNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstErrNumFirstdisp", LstErrNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstPplNumFirstdisp", LstPplNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstSegNumFirstdisp", LstSegNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeNavHigh::StatShr
 ******************************************************************************/

PnlWdbeNavHigh::StatShr::StatShr(
			const bool LstPphAvail
			, const bool ButPphViewActive
			, const bool ButPphNewcrdActive
			, const bool LstModAvail
			, const bool ButModViewActive
			, const bool ButModNewcrdActive
			, const bool LstVecAvail
			, const bool ButVecViewActive
			, const bool ButVecNewcrdActive
			, const bool LstVitAvail
			, const bool ButVitViewActive
			, const bool LstCmdAvail
			, const bool ButCmdViewActive
			, const bool ButCmdNewcrdActive
			, const bool LstErrAvail
			, const bool ButErrViewActive
			, const bool ButErrNewcrdActive
			, const bool LstPplAvail
			, const bool ButPplViewActive
			, const bool ButPplNewcrdActive
			, const bool LstSegAvail
			, const bool ButSegViewActive
			, const bool ButSegNewcrdActive
		) :
			Block()
		{
	this->LstPphAvail = LstPphAvail;
	this->ButPphViewActive = ButPphViewActive;
	this->ButPphNewcrdActive = ButPphNewcrdActive;
	this->LstModAvail = LstModAvail;
	this->ButModViewActive = ButModViewActive;
	this->ButModNewcrdActive = ButModNewcrdActive;
	this->LstVecAvail = LstVecAvail;
	this->ButVecViewActive = ButVecViewActive;
	this->ButVecNewcrdActive = ButVecNewcrdActive;
	this->LstVitAvail = LstVitAvail;
	this->ButVitViewActive = ButVitViewActive;
	this->LstCmdAvail = LstCmdAvail;
	this->ButCmdViewActive = ButCmdViewActive;
	this->ButCmdNewcrdActive = ButCmdNewcrdActive;
	this->LstErrAvail = LstErrAvail;
	this->ButErrViewActive = ButErrViewActive;
	this->ButErrNewcrdActive = ButErrNewcrdActive;
	this->LstPplAvail = LstPplAvail;
	this->ButPplViewActive = ButPplViewActive;
	this->ButPplNewcrdActive = ButPplNewcrdActive;
	this->LstSegAvail = LstSegAvail;
	this->ButSegViewActive = ButSegViewActive;
	this->ButSegNewcrdActive = ButSegNewcrdActive;

	mask = {LSTPPHAVAIL, BUTPPHVIEWACTIVE, BUTPPHNEWCRDACTIVE, LSTMODAVAIL, BUTMODVIEWACTIVE, BUTMODNEWCRDACTIVE, LSTVECAVAIL, BUTVECVIEWACTIVE, BUTVECNEWCRDACTIVE, LSTVITAVAIL, BUTVITVIEWACTIVE, LSTCMDAVAIL, BUTCMDVIEWACTIVE, BUTCMDNEWCRDACTIVE, LSTERRAVAIL, BUTERRVIEWACTIVE, BUTERRNEWCRDACTIVE, LSTPPLAVAIL, BUTPPLVIEWACTIVE, BUTPPLNEWCRDACTIVE, LSTSEGAVAIL, BUTSEGVIEWACTIVE, BUTSEGNEWCRDACTIVE};
};

void PnlWdbeNavHigh::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeNavHigh";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["LstPphAvail"] = LstPphAvail;
	me["ButPphViewActive"] = ButPphViewActive;
	me["ButPphNewcrdActive"] = ButPphNewcrdActive;
	me["LstModAvail"] = LstModAvail;
	me["ButModViewActive"] = ButModViewActive;
	me["ButModNewcrdActive"] = ButModNewcrdActive;
	me["LstVecAvail"] = LstVecAvail;
	me["ButVecViewActive"] = ButVecViewActive;
	me["ButVecNewcrdActive"] = ButVecNewcrdActive;
	me["LstVitAvail"] = LstVitAvail;
	me["ButVitViewActive"] = ButVitViewActive;
	me["LstCmdAvail"] = LstCmdAvail;
	me["ButCmdViewActive"] = ButCmdViewActive;
	me["ButCmdNewcrdActive"] = ButCmdNewcrdActive;
	me["LstErrAvail"] = LstErrAvail;
	me["ButErrViewActive"] = ButErrViewActive;
	me["ButErrNewcrdActive"] = ButErrNewcrdActive;
	me["LstPplAvail"] = LstPplAvail;
	me["ButPplViewActive"] = ButPplViewActive;
	me["ButPplNewcrdActive"] = ButPplNewcrdActive;
	me["LstSegAvail"] = LstSegAvail;
	me["ButSegViewActive"] = ButSegViewActive;
	me["ButSegNewcrdActive"] = ButSegNewcrdActive;
};

void PnlWdbeNavHigh::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeNavHigh";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWdbeNavHigh";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "LstPphAvail", LstPphAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButPphViewActive", ButPphViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButPphNewcrdActive", ButPphNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstModAvail", LstModAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButModViewActive", ButModViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButModNewcrdActive", ButModNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstVecAvail", LstVecAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButVecViewActive", ButVecViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButVecNewcrdActive", ButVecNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstVitAvail", LstVitAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButVitViewActive", ButVitViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstCmdAvail", LstCmdAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButCmdViewActive", ButCmdViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButCmdNewcrdActive", ButCmdNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstErrAvail", LstErrAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButErrViewActive", ButErrViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButErrNewcrdActive", ButErrNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstPplAvail", LstPplAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButPplViewActive", ButPplViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButPplNewcrdActive", ButPplNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstSegAvail", LstSegAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSegViewActive", ButSegViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButSegNewcrdActive", ButSegNewcrdActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeNavHigh::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstPphAvail == comp->LstPphAvail) insert(items, LSTPPHAVAIL);
	if (ButPphViewActive == comp->ButPphViewActive) insert(items, BUTPPHVIEWACTIVE);
	if (ButPphNewcrdActive == comp->ButPphNewcrdActive) insert(items, BUTPPHNEWCRDACTIVE);
	if (LstModAvail == comp->LstModAvail) insert(items, LSTMODAVAIL);
	if (ButModViewActive == comp->ButModViewActive) insert(items, BUTMODVIEWACTIVE);
	if (ButModNewcrdActive == comp->ButModNewcrdActive) insert(items, BUTMODNEWCRDACTIVE);
	if (LstVecAvail == comp->LstVecAvail) insert(items, LSTVECAVAIL);
	if (ButVecViewActive == comp->ButVecViewActive) insert(items, BUTVECVIEWACTIVE);
	if (ButVecNewcrdActive == comp->ButVecNewcrdActive) insert(items, BUTVECNEWCRDACTIVE);
	if (LstVitAvail == comp->LstVitAvail) insert(items, LSTVITAVAIL);
	if (ButVitViewActive == comp->ButVitViewActive) insert(items, BUTVITVIEWACTIVE);
	if (LstCmdAvail == comp->LstCmdAvail) insert(items, LSTCMDAVAIL);
	if (ButCmdViewActive == comp->ButCmdViewActive) insert(items, BUTCMDVIEWACTIVE);
	if (ButCmdNewcrdActive == comp->ButCmdNewcrdActive) insert(items, BUTCMDNEWCRDACTIVE);
	if (LstErrAvail == comp->LstErrAvail) insert(items, LSTERRAVAIL);
	if (ButErrViewActive == comp->ButErrViewActive) insert(items, BUTERRVIEWACTIVE);
	if (ButErrNewcrdActive == comp->ButErrNewcrdActive) insert(items, BUTERRNEWCRDACTIVE);
	if (LstPplAvail == comp->LstPplAvail) insert(items, LSTPPLAVAIL);
	if (ButPplViewActive == comp->ButPplViewActive) insert(items, BUTPPLVIEWACTIVE);
	if (ButPplNewcrdActive == comp->ButPplNewcrdActive) insert(items, BUTPPLNEWCRDACTIVE);
	if (LstSegAvail == comp->LstSegAvail) insert(items, LSTSEGAVAIL);
	if (ButSegViewActive == comp->ButSegViewActive) insert(items, BUTSEGVIEWACTIVE);
	if (ButSegNewcrdActive == comp->ButSegNewcrdActive) insert(items, BUTSEGNEWCRDACTIVE);

	return(items);
};

set<uint> PnlWdbeNavHigh::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTPPHAVAIL, BUTPPHVIEWACTIVE, BUTPPHNEWCRDACTIVE, LSTMODAVAIL, BUTMODVIEWACTIVE, BUTMODNEWCRDACTIVE, LSTVECAVAIL, BUTVECVIEWACTIVE, BUTVECNEWCRDACTIVE, LSTVITAVAIL, BUTVITVIEWACTIVE, LSTCMDAVAIL, BUTCMDVIEWACTIVE, BUTCMDNEWCRDACTIVE, LSTERRAVAIL, BUTERRVIEWACTIVE, BUTERRNEWCRDACTIVE, LSTPPLAVAIL, BUTPPLVIEWACTIVE, BUTPPLNEWCRDACTIVE, LSTSEGAVAIL, BUTSEGVIEWACTIVE, BUTSEGNEWCRDACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeNavHigh::Tag
 ******************************************************************************/

void PnlWdbeNavHigh::Tag::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWdbeNavHigh";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		me["Cpt"] = "High-level description module";
		me["CptPph"] = "peripherals";
		me["CptMod"] = "modules";
		me["CptVec"] = "vectors";
		me["CptVit"] = "vector items";
		me["CptCmd"] = "commands";
		me["CptErr"] = "errors";
		me["CptPpl"] = "pipelines";
		me["CptSeg"] = "segments";
	};
};

void PnlWdbeNavHigh::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWdbeNavHigh";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWdbeNavHigh";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "High-level description module");
			writeStringAttr(wr, itemtag, "sref", "CptPph", "peripherals");
			writeStringAttr(wr, itemtag, "sref", "CptMod", "modules");
			writeStringAttr(wr, itemtag, "sref", "CptVec", "vectors");
			writeStringAttr(wr, itemtag, "sref", "CptVit", "vector items");
			writeStringAttr(wr, itemtag, "sref", "CptCmd", "commands");
			writeStringAttr(wr, itemtag, "sref", "CptErr", "errors");
			writeStringAttr(wr, itemtag, "sref", "CptPpl", "pipelines");
			writeStringAttr(wr, itemtag, "sref", "CptSeg", "segments");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeNavHigh::DpchAppData
 ******************************************************************************/

PnlWdbeNavHigh::DpchAppData::DpchAppData() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBENAVHIGHDATA)
		{
};

string PnlWdbeNavHigh::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavHigh::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWdbeNavHighData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWdbeNavHigh::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeNavHighData");
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
 class PnlWdbeNavHigh::DpchAppDo
 ******************************************************************************/

PnlWdbeNavHigh::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBENAVHIGHDO)
		{
	ixVDo = 0;
};

string PnlWdbeNavHigh::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavHigh::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWdbeNavHighDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWdbeNavHigh::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeNavHighDo");
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
 class PnlWdbeNavHigh::DpchEngData
 ******************************************************************************/

PnlWdbeNavHigh::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, Feed* feedFLstCmd
			, Feed* feedFLstErr
			, Feed* feedFLstMod
			, Feed* feedFLstPph
			, Feed* feedFLstPpl
			, Feed* feedFLstSeg
			, Feed* feedFLstVec
			, Feed* feedFLstVit
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBENAVHIGHDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, FEEDFLSTCMD, FEEDFLSTERR, FEEDFLSTMOD, FEEDFLSTPPH, FEEDFLSTPPL, FEEDFLSTSEG, FEEDFLSTVEC, FEEDFLSTVIT, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, FEEDFLSTCMD) && feedFLstCmd) this->feedFLstCmd = *feedFLstCmd;
	if (find(this->mask, FEEDFLSTERR) && feedFLstErr) this->feedFLstErr = *feedFLstErr;
	if (find(this->mask, FEEDFLSTMOD) && feedFLstMod) this->feedFLstMod = *feedFLstMod;
	if (find(this->mask, FEEDFLSTPPH) && feedFLstPph) this->feedFLstPph = *feedFLstPph;
	if (find(this->mask, FEEDFLSTPPL) && feedFLstPpl) this->feedFLstPpl = *feedFLstPpl;
	if (find(this->mask, FEEDFLSTSEG) && feedFLstSeg) this->feedFLstSeg = *feedFLstSeg;
	if (find(this->mask, FEEDFLSTVEC) && feedFLstVec) this->feedFLstVec = *feedFLstVec;
	if (find(this->mask, FEEDFLSTVIT) && feedFLstVit) this->feedFLstVit = *feedFLstVit;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWdbeNavHigh::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTCMD)) ss.push_back("feedFLstCmd");
	if (has(FEEDFLSTERR)) ss.push_back("feedFLstErr");
	if (has(FEEDFLSTMOD)) ss.push_back("feedFLstMod");
	if (has(FEEDFLSTPPH)) ss.push_back("feedFLstPph");
	if (has(FEEDFLSTPPL)) ss.push_back("feedFLstPpl");
	if (has(FEEDFLSTSEG)) ss.push_back("feedFLstSeg");
	if (has(FEEDFLSTVEC)) ss.push_back("feedFLstVec");
	if (has(FEEDFLSTVIT)) ss.push_back("feedFLstVit");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavHigh::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(FEEDFLSTCMD)) {feedFLstCmd = src->feedFLstCmd; add(FEEDFLSTCMD);};
	if (src->has(FEEDFLSTERR)) {feedFLstErr = src->feedFLstErr; add(FEEDFLSTERR);};
	if (src->has(FEEDFLSTMOD)) {feedFLstMod = src->feedFLstMod; add(FEEDFLSTMOD);};
	if (src->has(FEEDFLSTPPH)) {feedFLstPph = src->feedFLstPph; add(FEEDFLSTPPH);};
	if (src->has(FEEDFLSTPPL)) {feedFLstPpl = src->feedFLstPpl; add(FEEDFLSTPPL);};
	if (src->has(FEEDFLSTSEG)) {feedFLstSeg = src->feedFLstSeg; add(FEEDFLSTSEG);};
	if (src->has(FEEDFLSTVEC)) {feedFLstVec = src->feedFLstVec; add(FEEDFLSTVEC);};
	if (src->has(FEEDFLSTVIT)) {feedFLstVit = src->feedFLstVit; add(FEEDFLSTVIT);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWdbeNavHigh::DpchEngData::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWdbeNavHighData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(FEEDFLSTCMD)) feedFLstCmd.writeJSON(me);
	if (has(FEEDFLSTERR)) feedFLstErr.writeJSON(me);
	if (has(FEEDFLSTMOD)) feedFLstMod.writeJSON(me);
	if (has(FEEDFLSTPPH)) feedFLstPph.writeJSON(me);
	if (has(FEEDFLSTPPL)) feedFLstPpl.writeJSON(me);
	if (has(FEEDFLSTSEG)) feedFLstSeg.writeJSON(me);
	if (has(FEEDFLSTVEC)) feedFLstVec.writeJSON(me);
	if (has(FEEDFLSTVIT)) feedFLstVit.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWdbeVLocale, me);
};

void PnlWdbeNavHigh::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWdbeNavHighData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(FEEDFLSTCMD)) feedFLstCmd.writeXML(wr);
		if (has(FEEDFLSTERR)) feedFLstErr.writeXML(wr);
		if (has(FEEDFLSTMOD)) feedFLstMod.writeXML(wr);
		if (has(FEEDFLSTPPH)) feedFLstPph.writeXML(wr);
		if (has(FEEDFLSTPPL)) feedFLstPpl.writeXML(wr);
		if (has(FEEDFLSTSEG)) feedFLstSeg.writeXML(wr);
		if (has(FEEDFLSTVEC)) feedFLstVec.writeXML(wr);
		if (has(FEEDFLSTVIT)) feedFLstVit.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};
