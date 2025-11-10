/**
	* \file PnlWdbePrtDetail_blks.cpp
	* job handler for job PnlWdbePrtDetail (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbePrtDetail::VecVDo
 ******************************************************************************/

uint PnlWdbePrtDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butcluviewclick") return BUTCLUVIEWCLICK;
	if (s == "butcluclusterclick") return BUTCLUCLUSTERCLICK;
	if (s == "butcluunclusterclick") return BUTCLUUNCLUSTERCLICK;
	if (s == "butmdlviewclick") return BUTMDLVIEWCLICK;
	if (s == "buthtyeditclick") return BUTHTYEDITCLICK;
	if (s == "butcpiviewclick") return BUTCPIVIEWCLICK;
	if (s == "butcprviewclick") return BUTCPRVIEWCLICK;
	if (s == "butcsiviewclick") return BUTCSIVIEWCLICK;

	return(0);
};

string PnlWdbePrtDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTCLUVIEWCLICK) return("ButCluViewClick");
	if (ix == BUTCLUCLUSTERCLICK) return("ButCluClusterClick");
	if (ix == BUTCLUUNCLUSTERCLICK) return("ButCluUnclusterClick");
	if (ix == BUTMDLVIEWCLICK) return("ButMdlViewClick");
	if (ix == BUTHTYEDITCLICK) return("ButHtyEditClick");
	if (ix == BUTCPIVIEWCLICK) return("ButCpiViewClick");
	if (ix == BUTCPRVIEWCLICK) return("ButCprViewClick");
	if (ix == BUTCSIVIEWCLICK) return("ButCsiViewClick");

	return("");
};

/******************************************************************************
 class PnlWdbePrtDetail::ContIac
 ******************************************************************************/

PnlWdbePrtDetail::ContIac::ContIac(
			const uint numFLstClu
			, const uint numFPupDir
			, const uint numFPupHty
			, const string& TxfHty
			, const string& TxfWid
			, const string& TxfMmx
			, const string& TxfDfv
			, const string& TxfCpi
			, const string& TxfCpr
			, const string& TxfCsi
			, const string& TxfCmt
		) :
			Block()
			, numFLstClu(numFLstClu)
			, numFPupDir(numFPupDir)
			, numFPupHty(numFPupHty)
			, TxfHty(TxfHty)
			, TxfWid(TxfWid)
			, TxfMmx(TxfMmx)
			, TxfDfv(TxfDfv)
			, TxfCpi(TxfCpi)
			, TxfCpr(TxfCpr)
			, TxfCsi(TxfCsi)
			, TxfCmt(TxfCmt)
		{
	mask = {NUMFLSTCLU, NUMFPUPDIR, NUMFPUPHTY, TXFHTY, TXFWID, TXFMMX, TXFDFV, TXFCPI, TXFCPR, TXFCSI, TXFCMT};
};

bool PnlWdbePrtDetail::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacWdbePrtDetail"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFLstClu")) {numFLstClu = me["numFLstClu"].asUInt(); add(NUMFLSTCLU);};
		if (me.isMember("numFPupDir")) {numFPupDir = me["numFPupDir"].asUInt(); add(NUMFPUPDIR);};
		if (me.isMember("numFPupHty")) {numFPupHty = me["numFPupHty"].asUInt(); add(NUMFPUPHTY);};
		if (me.isMember("TxfHty")) {TxfHty = me["TxfHty"].asString(); add(TXFHTY);};
		if (me.isMember("TxfWid")) {TxfWid = me["TxfWid"].asString(); add(TXFWID);};
		if (me.isMember("TxfMmx")) {TxfMmx = me["TxfMmx"].asString(); add(TXFMMX);};
		if (me.isMember("TxfDfv")) {TxfDfv = me["TxfDfv"].asString(); add(TXFDFV);};
		if (me.isMember("TxfCpi")) {TxfCpi = me["TxfCpi"].asString(); add(TXFCPI);};
		if (me.isMember("TxfCpr")) {TxfCpr = me["TxfCpr"].asString(); add(TXFCPR);};
		if (me.isMember("TxfCsi")) {TxfCsi = me["TxfCsi"].asString(); add(TXFCSI);};
		if (me.isMember("TxfCmt")) {TxfCmt = me["TxfCmt"].asString(); add(TXFCMT);};
	};

	return basefound;
};

bool PnlWdbePrtDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWdbePrtDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWdbePrtDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstClu", numFLstClu)) add(NUMFLSTCLU);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupDir", numFPupDir)) add(NUMFPUPDIR);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupHty", numFPupHty)) add(NUMFPUPHTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfHty", TxfHty)) add(TXFHTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfWid", TxfWid)) add(TXFWID);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfMmx", TxfMmx)) add(TXFMMX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfDfv", TxfDfv)) add(TXFDFV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCpi", TxfCpi)) add(TXFCPI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCpr", TxfCpr)) add(TXFCPR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCsi", TxfCsi)) add(TXFCSI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlWdbePrtDetail::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbePrtDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFLstClu"] = (Json::Value::UInt) numFLstClu;
	me["numFPupDir"] = (Json::Value::UInt) numFPupDir;
	me["numFPupHty"] = (Json::Value::UInt) numFPupHty;
	me["TxfHty"] = TxfHty;
	me["TxfWid"] = TxfWid;
	me["TxfMmx"] = TxfMmx;
	me["TxfDfv"] = TxfDfv;
	me["TxfCpi"] = TxfCpi;
	me["TxfCpr"] = TxfCpr;
	me["TxfCsi"] = TxfCsi;
	me["TxfCmt"] = TxfCmt;
};

void PnlWdbePrtDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbePrtDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWdbePrtDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstClu", numFLstClu);
		writeUintAttr(wr, itemtag, "sref", "numFPupDir", numFPupDir);
		writeUintAttr(wr, itemtag, "sref", "numFPupHty", numFPupHty);
		writeStringAttr(wr, itemtag, "sref", "TxfHty", TxfHty);
		writeStringAttr(wr, itemtag, "sref", "TxfWid", TxfWid);
		writeStringAttr(wr, itemtag, "sref", "TxfMmx", TxfMmx);
		writeStringAttr(wr, itemtag, "sref", "TxfDfv", TxfDfv);
		writeStringAttr(wr, itemtag, "sref", "TxfCpi", TxfCpi);
		writeStringAttr(wr, itemtag, "sref", "TxfCpr", TxfCpr);
		writeStringAttr(wr, itemtag, "sref", "TxfCsi", TxfCsi);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbePrtDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstClu == comp->numFLstClu) insert(items, NUMFLSTCLU);
	if (numFPupDir == comp->numFPupDir) insert(items, NUMFPUPDIR);
	if (numFPupHty == comp->numFPupHty) insert(items, NUMFPUPHTY);
	if (TxfHty == comp->TxfHty) insert(items, TXFHTY);
	if (TxfWid == comp->TxfWid) insert(items, TXFWID);
	if (TxfMmx == comp->TxfMmx) insert(items, TXFMMX);
	if (TxfDfv == comp->TxfDfv) insert(items, TXFDFV);
	if (TxfCpi == comp->TxfCpi) insert(items, TXFCPI);
	if (TxfCpr == comp->TxfCpr) insert(items, TXFCPR);
	if (TxfCsi == comp->TxfCsi) insert(items, TXFCSI);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlWdbePrtDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTCLU, NUMFPUPDIR, NUMFPUPHTY, TXFHTY, TXFWID, TXFMMX, TXFDFV, TXFCPI, TXFCPR, TXFCSI, TXFCMT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbePrtDetail::ContInf
 ******************************************************************************/

PnlWdbePrtDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtClu
			, const string& TxtMdl
			, const string& TxtCpi
			, const string& TxtCpr
			, const string& TxtCsi
		) :
			Block()
			, TxtSrf(TxtSrf)
			, TxtClu(TxtClu)
			, TxtMdl(TxtMdl)
			, TxtCpi(TxtCpi)
			, TxtCpr(TxtCpr)
			, TxtCsi(TxtCsi)
		{
	mask = {TXTSRF, TXTCLU, TXTMDL, TXTCPI, TXTCPR, TXTCSI};
};

void PnlWdbePrtDetail::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbePrtDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtSrf"] = TxtSrf;
	me["TxtClu"] = TxtClu;
	me["TxtMdl"] = TxtMdl;
	me["TxtCpi"] = TxtCpi;
	me["TxtCpr"] = TxtCpr;
	me["TxtCsi"] = TxtCsi;
};

void PnlWdbePrtDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbePrtDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWdbePrtDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtClu", TxtClu);
		writeStringAttr(wr, itemtag, "sref", "TxtMdl", TxtMdl);
		writeStringAttr(wr, itemtag, "sref", "TxtCpi", TxtCpi);
		writeStringAttr(wr, itemtag, "sref", "TxtCpr", TxtCpr);
		writeStringAttr(wr, itemtag, "sref", "TxtCsi", TxtCsi);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbePrtDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtClu == comp->TxtClu) insert(items, TXTCLU);
	if (TxtMdl == comp->TxtMdl) insert(items, TXTMDL);
	if (TxtCpi == comp->TxtCpi) insert(items, TXTCPI);
	if (TxtCpr == comp->TxtCpr) insert(items, TXTCPR);
	if (TxtCsi == comp->TxtCsi) insert(items, TXTCSI);

	return(items);
};

set<uint> PnlWdbePrtDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTCLU, TXTMDL, TXTCPI, TXTCPR, TXTCSI};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbePrtDetail::StatApp
 ******************************************************************************/

void PnlWdbePrtDetail::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWdbeVExpstate
			, const bool LstCluAlt
			, const bool PupHtyAlt
			, const bool TxtCpiAlt
			, const bool TxtCprAlt
			, const bool TxtCsiAlt
			, const uint LstCluNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbePrtDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWdbeVExpstate"] = VecWdbeVExpstate::getSref(ixWdbeVExpstate);
	me["LstCluAlt"] = LstCluAlt;
	me["PupHtyAlt"] = PupHtyAlt;
	me["TxtCpiAlt"] = TxtCpiAlt;
	me["TxtCprAlt"] = TxtCprAlt;
	me["TxtCsiAlt"] = TxtCsiAlt;
	me["LstCluNumFirstdisp"] = (Json::Value::UInt) LstCluNumFirstdisp;
};

void PnlWdbePrtDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWdbeVExpstate
			, const bool LstCluAlt
			, const bool PupHtyAlt
			, const bool TxtCpiAlt
			, const bool TxtCprAlt
			, const bool TxtCsiAlt
			, const uint LstCluNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbePrtDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWdbePrtDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWdbeVExpstate", VecWdbeVExpstate::getSref(ixWdbeVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstCluAlt", LstCluAlt);
		writeBoolAttr(wr, itemtag, "sref", "PupHtyAlt", PupHtyAlt);
		writeBoolAttr(wr, itemtag, "sref", "TxtCpiAlt", TxtCpiAlt);
		writeBoolAttr(wr, itemtag, "sref", "TxtCprAlt", TxtCprAlt);
		writeBoolAttr(wr, itemtag, "sref", "TxtCsiAlt", TxtCsiAlt);
		writeUintAttr(wr, itemtag, "sref", "LstCluNumFirstdisp", LstCluNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbePrtDetail::StatShr
 ******************************************************************************/

PnlWdbePrtDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool LstCluActive
			, const bool ButCluViewActive
			, const bool ButCluClusterAvail
			, const bool ButCluUnclusterAvail
			, const bool TxtMdlActive
			, const bool ButMdlViewAvail
			, const bool ButMdlViewActive
			, const bool PupDirActive
			, const bool PupHtyActive
			, const bool TxfHtyValid
			, const bool ButHtyEditAvail
			, const bool TxfWidActive
			, const bool TxfMmxActive
			, const bool TxfDfvActive
			, const bool TxtCpiActive
			, const bool TxfCpiValid
			, const bool ButCpiViewAvail
			, const bool TxtCprActive
			, const bool TxfCprValid
			, const bool ButCprViewAvail
			, const bool TxtCsiActive
			, const bool TxfCsiValid
			, const bool ButCsiViewAvail
			, const bool TxfCmtActive
		) :
			Block()
			, ButSaveAvail(ButSaveAvail)
			, ButSaveActive(ButSaveActive)
			, TxtSrfActive(TxtSrfActive)
			, LstCluActive(LstCluActive)
			, ButCluViewActive(ButCluViewActive)
			, ButCluClusterAvail(ButCluClusterAvail)
			, ButCluUnclusterAvail(ButCluUnclusterAvail)
			, TxtMdlActive(TxtMdlActive)
			, ButMdlViewAvail(ButMdlViewAvail)
			, ButMdlViewActive(ButMdlViewActive)
			, PupDirActive(PupDirActive)
			, PupHtyActive(PupHtyActive)
			, TxfHtyValid(TxfHtyValid)
			, ButHtyEditAvail(ButHtyEditAvail)
			, TxfWidActive(TxfWidActive)
			, TxfMmxActive(TxfMmxActive)
			, TxfDfvActive(TxfDfvActive)
			, TxtCpiActive(TxtCpiActive)
			, TxfCpiValid(TxfCpiValid)
			, ButCpiViewAvail(ButCpiViewAvail)
			, TxtCprActive(TxtCprActive)
			, TxfCprValid(TxfCprValid)
			, ButCprViewAvail(ButCprViewAvail)
			, TxtCsiActive(TxtCsiActive)
			, TxfCsiValid(TxfCsiValid)
			, ButCsiViewAvail(ButCsiViewAvail)
			, TxfCmtActive(TxfCmtActive)
		{
	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXTMDLACTIVE, BUTMDLVIEWAVAIL, BUTMDLVIEWACTIVE, PUPDIRACTIVE, PUPHTYACTIVE, TXFHTYVALID, BUTHTYEDITAVAIL, TXFWIDACTIVE, TXFMMXACTIVE, TXFDFVACTIVE, TXTCPIACTIVE, TXFCPIVALID, BUTCPIVIEWAVAIL, TXTCPRACTIVE, TXFCPRVALID, BUTCPRVIEWAVAIL, TXTCSIACTIVE, TXFCSIVALID, BUTCSIVIEWAVAIL, TXFCMTACTIVE};
};

void PnlWdbePrtDetail::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbePrtDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButSaveAvail"] = ButSaveAvail;
	me["ButSaveActive"] = ButSaveActive;
	me["TxtSrfActive"] = TxtSrfActive;
	me["LstCluActive"] = LstCluActive;
	me["ButCluViewActive"] = ButCluViewActive;
	me["ButCluClusterAvail"] = ButCluClusterAvail;
	me["ButCluUnclusterAvail"] = ButCluUnclusterAvail;
	me["TxtMdlActive"] = TxtMdlActive;
	me["ButMdlViewAvail"] = ButMdlViewAvail;
	me["ButMdlViewActive"] = ButMdlViewActive;
	me["PupDirActive"] = PupDirActive;
	me["PupHtyActive"] = PupHtyActive;
	me["TxfHtyValid"] = TxfHtyValid;
	me["ButHtyEditAvail"] = ButHtyEditAvail;
	me["TxfWidActive"] = TxfWidActive;
	me["TxfMmxActive"] = TxfMmxActive;
	me["TxfDfvActive"] = TxfDfvActive;
	me["TxtCpiActive"] = TxtCpiActive;
	me["TxfCpiValid"] = TxfCpiValid;
	me["ButCpiViewAvail"] = ButCpiViewAvail;
	me["TxtCprActive"] = TxtCprActive;
	me["TxfCprValid"] = TxfCprValid;
	me["ButCprViewAvail"] = ButCprViewAvail;
	me["TxtCsiActive"] = TxtCsiActive;
	me["TxfCsiValid"] = TxfCsiValid;
	me["ButCsiViewAvail"] = ButCsiViewAvail;
	me["TxfCmtActive"] = TxfCmtActive;
};

void PnlWdbePrtDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbePrtDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWdbePrtDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSrfActive", TxtSrfActive);
		writeBoolAttr(wr, itemtag, "sref", "LstCluActive", LstCluActive);
		writeBoolAttr(wr, itemtag, "sref", "ButCluViewActive", ButCluViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButCluClusterAvail", ButCluClusterAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButCluUnclusterAvail", ButCluUnclusterAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtMdlActive", TxtMdlActive);
		writeBoolAttr(wr, itemtag, "sref", "ButMdlViewAvail", ButMdlViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButMdlViewActive", ButMdlViewActive);
		writeBoolAttr(wr, itemtag, "sref", "PupDirActive", PupDirActive);
		writeBoolAttr(wr, itemtag, "sref", "PupHtyActive", PupHtyActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfHtyValid", TxfHtyValid);
		writeBoolAttr(wr, itemtag, "sref", "ButHtyEditAvail", ButHtyEditAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfWidActive", TxfWidActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfMmxActive", TxfMmxActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfDfvActive", TxfDfvActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtCpiActive", TxtCpiActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfCpiValid", TxfCpiValid);
		writeBoolAttr(wr, itemtag, "sref", "ButCpiViewAvail", ButCpiViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtCprActive", TxtCprActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfCprValid", TxfCprValid);
		writeBoolAttr(wr, itemtag, "sref", "ButCprViewAvail", ButCprViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtCsiActive", TxtCsiActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfCsiValid", TxfCsiValid);
		writeBoolAttr(wr, itemtag, "sref", "ButCsiViewAvail", ButCsiViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfCmtActive", TxfCmtActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbePrtDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (LstCluActive == comp->LstCluActive) insert(items, LSTCLUACTIVE);
	if (ButCluViewActive == comp->ButCluViewActive) insert(items, BUTCLUVIEWACTIVE);
	if (ButCluClusterAvail == comp->ButCluClusterAvail) insert(items, BUTCLUCLUSTERAVAIL);
	if (ButCluUnclusterAvail == comp->ButCluUnclusterAvail) insert(items, BUTCLUUNCLUSTERAVAIL);
	if (TxtMdlActive == comp->TxtMdlActive) insert(items, TXTMDLACTIVE);
	if (ButMdlViewAvail == comp->ButMdlViewAvail) insert(items, BUTMDLVIEWAVAIL);
	if (ButMdlViewActive == comp->ButMdlViewActive) insert(items, BUTMDLVIEWACTIVE);
	if (PupDirActive == comp->PupDirActive) insert(items, PUPDIRACTIVE);
	if (PupHtyActive == comp->PupHtyActive) insert(items, PUPHTYACTIVE);
	if (TxfHtyValid == comp->TxfHtyValid) insert(items, TXFHTYVALID);
	if (ButHtyEditAvail == comp->ButHtyEditAvail) insert(items, BUTHTYEDITAVAIL);
	if (TxfWidActive == comp->TxfWidActive) insert(items, TXFWIDACTIVE);
	if (TxfMmxActive == comp->TxfMmxActive) insert(items, TXFMMXACTIVE);
	if (TxfDfvActive == comp->TxfDfvActive) insert(items, TXFDFVACTIVE);
	if (TxtCpiActive == comp->TxtCpiActive) insert(items, TXTCPIACTIVE);
	if (TxfCpiValid == comp->TxfCpiValid) insert(items, TXFCPIVALID);
	if (ButCpiViewAvail == comp->ButCpiViewAvail) insert(items, BUTCPIVIEWAVAIL);
	if (TxtCprActive == comp->TxtCprActive) insert(items, TXTCPRACTIVE);
	if (TxfCprValid == comp->TxfCprValid) insert(items, TXFCPRVALID);
	if (ButCprViewAvail == comp->ButCprViewAvail) insert(items, BUTCPRVIEWAVAIL);
	if (TxtCsiActive == comp->TxtCsiActive) insert(items, TXTCSIACTIVE);
	if (TxfCsiValid == comp->TxfCsiValid) insert(items, TXFCSIVALID);
	if (ButCsiViewAvail == comp->ButCsiViewAvail) insert(items, BUTCSIVIEWAVAIL);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);

	return(items);
};

set<uint> PnlWdbePrtDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXTMDLACTIVE, BUTMDLVIEWAVAIL, BUTMDLVIEWACTIVE, PUPDIRACTIVE, PUPHTYACTIVE, TXFHTYVALID, BUTHTYEDITAVAIL, TXFWIDACTIVE, TXFMMXACTIVE, TXFDFVACTIVE, TXTCPIACTIVE, TXFCPIVALID, BUTCPIVIEWAVAIL, TXTCPRACTIVE, TXFCPRVALID, BUTCPRVIEWAVAIL, TXTCSIACTIVE, TXFCSIVALID, BUTCSIVIEWAVAIL, TXFCMTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbePrtDetail::Tag
 ******************************************************************************/

void PnlWdbePrtDetail::Tag::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWdbePrtDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		me["CptSrf"] = "identifier";
		me["CptMdl"] = "module";
		me["CptDir"] = "direction";
		me["CptHty"] = "HDL data type";
		me["CptWid"] = "width";
		me["CptMmx"] = "range";
		me["CptDfv"] = "default value";
		me["CptCpi"] = "pin connected to";
		me["CptCpr"] = "port connected to";
		me["CptCsi"] = "signal connected to";
		me["CptCmt"] = "comment";
	};
	me["Cpt"] = StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DETAIL, ixWdbeVLocale));
	me["CptClu"] = VecWdbeVTag::getTitle(VecWdbeVTag::CLUST, ixWdbeVLocale);
};

void PnlWdbePrtDetail::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWdbePrtDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWdbePrtDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptMdl", "module");
			writeStringAttr(wr, itemtag, "sref", "CptDir", "direction");
			writeStringAttr(wr, itemtag, "sref", "CptHty", "HDL data type");
			writeStringAttr(wr, itemtag, "sref", "CptWid", "width");
			writeStringAttr(wr, itemtag, "sref", "CptMmx", "range");
			writeStringAttr(wr, itemtag, "sref", "CptDfv", "default value");
			writeStringAttr(wr, itemtag, "sref", "CptCpi", "pin connected to");
			writeStringAttr(wr, itemtag, "sref", "CptCpr", "port connected to");
			writeStringAttr(wr, itemtag, "sref", "CptCsi", "signal connected to");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "comment");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DETAIL, ixWdbeVLocale)));
		writeStringAttr(wr, itemtag, "sref", "CptClu", VecWdbeVTag::getTitle(VecWdbeVTag::CLUST, ixWdbeVLocale));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbePrtDetail::DpchAppData
 ******************************************************************************/

PnlWdbePrtDetail::DpchAppData::DpchAppData() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEPRTDETAILDATA)
		{
};

string PnlWdbePrtDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbePrtDetail::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWdbePrtDetailData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWdbePrtDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbePrtDetailData");
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
 class PnlWdbePrtDetail::DpchAppDo
 ******************************************************************************/

PnlWdbePrtDetail::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEPRTDETAILDO)
		{
	ixVDo = 0;
};

string PnlWdbePrtDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbePrtDetail::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWdbePrtDetailDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWdbePrtDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbePrtDetailDo");
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
 class PnlWdbePrtDetail::DpchEngData
 ******************************************************************************/

PnlWdbePrtDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFLstClu
			, Feed* feedFPupDir
			, Feed* feedFPupHty
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBEPRTDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFLSTCLU, FEEDFPUPDIR, FEEDFPUPHTY, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFLSTCLU) && feedFLstClu) this->feedFLstClu = *feedFLstClu;
	if (find(this->mask, FEEDFPUPDIR) && feedFPupDir) this->feedFPupDir = *feedFPupDir;
	if (find(this->mask, FEEDFPUPHTY) && feedFPupHty) this->feedFPupHty = *feedFPupHty;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWdbePrtDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTCLU)) ss.push_back("feedFLstClu");
	if (has(FEEDFPUPDIR)) ss.push_back("feedFPupDir");
	if (has(FEEDFPUPHTY)) ss.push_back("feedFPupHty");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbePrtDetail::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFLSTCLU)) {feedFLstClu = src->feedFLstClu; add(FEEDFLSTCLU);};
	if (src->has(FEEDFPUPDIR)) {feedFPupDir = src->feedFPupDir; add(FEEDFPUPDIR);};
	if (src->has(FEEDFPUPHTY)) {feedFPupHty = src->feedFPupHty; add(FEEDFPUPHTY);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWdbePrtDetail::DpchEngData::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWdbePrtDetailData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFLSTCLU)) feedFLstClu.writeJSON(me);
	if (has(FEEDFPUPDIR)) feedFPupDir.writeJSON(me);
	if (has(FEEDFPUPHTY)) feedFPupHty.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWdbeVLocale, me);
};

void PnlWdbePrtDetail::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWdbePrtDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFLSTCLU)) feedFLstClu.writeXML(wr);
		if (has(FEEDFPUPDIR)) feedFPupDir.writeXML(wr);
		if (has(FEEDFPUPHTY)) feedFPupHty.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};
