/**
	* \file PnlWdbeSigDetail_blks.cpp
	* job handler for job PnlWdbeSigDetail (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbeSigDetail::VecVDo
 ******************************************************************************/

uint PnlWdbeSigDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butcluviewclick") return BUTCLUVIEWCLICK;
	if (s == "butcluclusterclick") return BUTCLUCLUSTERCLICK;
	if (s == "butcluunclusterclick") return BUTCLUUNCLUSTERCLICK;
	if (s == "butreuviewclick") return BUTREUVIEWCLICK;
	if (s == "butmguviewclick") return BUTMGUVIEWCLICK;
	if (s == "butvecviewclick") return BUTVECVIEWCLICK;
	if (s == "buthtyeditclick") return BUTHTYEDITCLICK;
	if (s == "butdrvviewclick") return BUTDRVVIEWCLICK;

	return(0);
};

string PnlWdbeSigDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTCLUVIEWCLICK) return("ButCluViewClick");
	if (ix == BUTCLUCLUSTERCLICK) return("ButCluClusterClick");
	if (ix == BUTCLUUNCLUSTERCLICK) return("ButCluUnclusterClick");
	if (ix == BUTREUVIEWCLICK) return("ButReuViewClick");
	if (ix == BUTMGUVIEWCLICK) return("ButMguViewClick");
	if (ix == BUTVECVIEWCLICK) return("ButVecViewClick");
	if (ix == BUTHTYEDITCLICK) return("ButHtyEditClick");
	if (ix == BUTDRVVIEWCLICK) return("ButDrvViewClick");

	return("");
};

/******************************************************************************
 class PnlWdbeSigDetail::ContIac
 ******************************************************************************/

PnlWdbeSigDetail::ContIac::ContIac(
			const uint numFPupTyp
			, const uint numFLstClu
			, const uint numFPupRet
			, const uint numFPupMgt
			, const bool ChkCon
			, const uint numFPupHty
			, const string& TxfHty
			, const string& TxfWid
			, const string& TxfMmx
			, const string& TxfCmb
			, const string& TxfOnv
			, const string& TxfOfv
			, const bool ChkDfo
			, const string& TxfCmt
		) :
			Block()
		{
	this->numFPupTyp = numFPupTyp;
	this->numFLstClu = numFLstClu;
	this->numFPupRet = numFPupRet;
	this->numFPupMgt = numFPupMgt;
	this->ChkCon = ChkCon;
	this->numFPupHty = numFPupHty;
	this->TxfHty = TxfHty;
	this->TxfWid = TxfWid;
	this->TxfMmx = TxfMmx;
	this->TxfCmb = TxfCmb;
	this->TxfOnv = TxfOnv;
	this->TxfOfv = TxfOfv;
	this->ChkDfo = ChkDfo;
	this->TxfCmt = TxfCmt;

	mask = {NUMFPUPTYP, NUMFLSTCLU, NUMFPUPRET, NUMFPUPMGT, CHKCON, NUMFPUPHTY, TXFHTY, TXFWID, TXFMMX, TXFCMB, TXFONV, TXFOFV, CHKDFO, TXFCMT};
};

bool PnlWdbeSigDetail::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacWdbeSigDetail"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFPupTyp")) {numFPupTyp = me["numFPupTyp"].asUInt(); add(NUMFPUPTYP);};
		if (me.isMember("numFLstClu")) {numFLstClu = me["numFLstClu"].asUInt(); add(NUMFLSTCLU);};
		if (me.isMember("numFPupRet")) {numFPupRet = me["numFPupRet"].asUInt(); add(NUMFPUPRET);};
		if (me.isMember("numFPupMgt")) {numFPupMgt = me["numFPupMgt"].asUInt(); add(NUMFPUPMGT);};
		if (me.isMember("ChkCon")) {ChkCon = me["ChkCon"].asBool(); add(CHKCON);};
		if (me.isMember("numFPupHty")) {numFPupHty = me["numFPupHty"].asUInt(); add(NUMFPUPHTY);};
		if (me.isMember("TxfHty")) {TxfHty = me["TxfHty"].asString(); add(TXFHTY);};
		if (me.isMember("TxfWid")) {TxfWid = me["TxfWid"].asString(); add(TXFWID);};
		if (me.isMember("TxfMmx")) {TxfMmx = me["TxfMmx"].asString(); add(TXFMMX);};
		if (me.isMember("TxfCmb")) {TxfCmb = me["TxfCmb"].asString(); add(TXFCMB);};
		if (me.isMember("TxfOnv")) {TxfOnv = me["TxfOnv"].asString(); add(TXFONV);};
		if (me.isMember("TxfOfv")) {TxfOfv = me["TxfOfv"].asString(); add(TXFOFV);};
		if (me.isMember("ChkDfo")) {ChkDfo = me["ChkDfo"].asBool(); add(CHKDFO);};
		if (me.isMember("TxfCmt")) {TxfCmt = me["TxfCmt"].asString(); add(TXFCMT);};
	};

	return basefound;
};

bool PnlWdbeSigDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWdbeSigDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWdbeSigDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTyp", numFPupTyp)) add(NUMFPUPTYP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstClu", numFLstClu)) add(NUMFLSTCLU);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupRet", numFPupRet)) add(NUMFPUPRET);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupMgt", numFPupMgt)) add(NUMFPUPMGT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkCon", ChkCon)) add(CHKCON);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupHty", numFPupHty)) add(NUMFPUPHTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfHty", TxfHty)) add(TXFHTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfWid", TxfWid)) add(TXFWID);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfMmx", TxfMmx)) add(TXFMMX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmb", TxfCmb)) add(TXFCMB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfOnv", TxfOnv)) add(TXFONV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfOfv", TxfOfv)) add(TXFOFV);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkDfo", ChkDfo)) add(CHKDFO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlWdbeSigDetail::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeSigDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFPupTyp"] = numFPupTyp;
	me["numFLstClu"] = numFLstClu;
	me["numFPupRet"] = numFPupRet;
	me["numFPupMgt"] = numFPupMgt;
	me["ChkCon"] = ChkCon;
	me["numFPupHty"] = numFPupHty;
	me["TxfHty"] = TxfHty;
	me["TxfWid"] = TxfWid;
	me["TxfMmx"] = TxfMmx;
	me["TxfCmb"] = TxfCmb;
	me["TxfOnv"] = TxfOnv;
	me["TxfOfv"] = TxfOfv;
	me["ChkDfo"] = ChkDfo;
	me["TxfCmt"] = TxfCmt;
};

void PnlWdbeSigDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeSigDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWdbeSigDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupTyp", numFPupTyp);
		writeUintAttr(wr, itemtag, "sref", "numFLstClu", numFLstClu);
		writeUintAttr(wr, itemtag, "sref", "numFPupRet", numFPupRet);
		writeUintAttr(wr, itemtag, "sref", "numFPupMgt", numFPupMgt);
		writeBoolAttr(wr, itemtag, "sref", "ChkCon", ChkCon);
		writeUintAttr(wr, itemtag, "sref", "numFPupHty", numFPupHty);
		writeStringAttr(wr, itemtag, "sref", "TxfHty", TxfHty);
		writeStringAttr(wr, itemtag, "sref", "TxfWid", TxfWid);
		writeStringAttr(wr, itemtag, "sref", "TxfMmx", TxfMmx);
		writeStringAttr(wr, itemtag, "sref", "TxfCmb", TxfCmb);
		writeStringAttr(wr, itemtag, "sref", "TxfOnv", TxfOnv);
		writeStringAttr(wr, itemtag, "sref", "TxfOfv", TxfOfv);
		writeBoolAttr(wr, itemtag, "sref", "ChkDfo", ChkDfo);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeSigDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupTyp == comp->numFPupTyp) insert(items, NUMFPUPTYP);
	if (numFLstClu == comp->numFLstClu) insert(items, NUMFLSTCLU);
	if (numFPupRet == comp->numFPupRet) insert(items, NUMFPUPRET);
	if (numFPupMgt == comp->numFPupMgt) insert(items, NUMFPUPMGT);
	if (ChkCon == comp->ChkCon) insert(items, CHKCON);
	if (numFPupHty == comp->numFPupHty) insert(items, NUMFPUPHTY);
	if (TxfHty == comp->TxfHty) insert(items, TXFHTY);
	if (TxfWid == comp->TxfWid) insert(items, TXFWID);
	if (TxfMmx == comp->TxfMmx) insert(items, TXFMMX);
	if (TxfCmb == comp->TxfCmb) insert(items, TXFCMB);
	if (TxfOnv == comp->TxfOnv) insert(items, TXFONV);
	if (TxfOfv == comp->TxfOfv) insert(items, TXFOFV);
	if (ChkDfo == comp->ChkDfo) insert(items, CHKDFO);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlWdbeSigDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPTYP, NUMFLSTCLU, NUMFPUPRET, NUMFPUPMGT, CHKCON, NUMFPUPHTY, TXFHTY, TXFWID, TXFMMX, TXFCMB, TXFONV, TXFOFV, CHKDFO, TXFCMT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeSigDetail::ContInf
 ******************************************************************************/

PnlWdbeSigDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtClu
			, const string& TxtReu
			, const string& TxtMgu
			, const string& TxtVec
			, const string& TxtDrv
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtClu = TxtClu;
	this->TxtReu = TxtReu;
	this->TxtMgu = TxtMgu;
	this->TxtVec = TxtVec;
	this->TxtDrv = TxtDrv;

	mask = {TXTSRF, TXTCLU, TXTREU, TXTMGU, TXTVEC, TXTDRV};
};

void PnlWdbeSigDetail::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbeSigDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtSrf"] = TxtSrf;
	me["TxtClu"] = TxtClu;
	me["TxtReu"] = TxtReu;
	me["TxtMgu"] = TxtMgu;
	me["TxtVec"] = TxtVec;
	me["TxtDrv"] = TxtDrv;
};

void PnlWdbeSigDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbeSigDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWdbeSigDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtClu", TxtClu);
		writeStringAttr(wr, itemtag, "sref", "TxtReu", TxtReu);
		writeStringAttr(wr, itemtag, "sref", "TxtMgu", TxtMgu);
		writeStringAttr(wr, itemtag, "sref", "TxtVec", TxtVec);
		writeStringAttr(wr, itemtag, "sref", "TxtDrv", TxtDrv);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeSigDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtClu == comp->TxtClu) insert(items, TXTCLU);
	if (TxtReu == comp->TxtReu) insert(items, TXTREU);
	if (TxtMgu == comp->TxtMgu) insert(items, TXTMGU);
	if (TxtVec == comp->TxtVec) insert(items, TXTVEC);
	if (TxtDrv == comp->TxtDrv) insert(items, TXTDRV);

	return(items);
};

set<uint> PnlWdbeSigDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTCLU, TXTREU, TXTMGU, TXTVEC, TXTDRV};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeSigDetail::StatApp
 ******************************************************************************/

void PnlWdbeSigDetail::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWdbeVExpstate
			, const bool LstCluAlt
			, const bool PupHtyAlt
			, const uint LstCluNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeSigDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWdbeVExpstate"] = VecWdbeVExpstate::getSref(ixWdbeVExpstate);
	me["LstCluAlt"] = LstCluAlt;
	me["PupHtyAlt"] = PupHtyAlt;
	me["LstCluNumFirstdisp"] = LstCluNumFirstdisp;
};

void PnlWdbeSigDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWdbeVExpstate
			, const bool LstCluAlt
			, const bool PupHtyAlt
			, const uint LstCluNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeSigDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWdbeSigDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWdbeVExpstate", VecWdbeVExpstate::getSref(ixWdbeVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstCluAlt", LstCluAlt);
		writeBoolAttr(wr, itemtag, "sref", "PupHtyAlt", PupHtyAlt);
		writeUintAttr(wr, itemtag, "sref", "LstCluNumFirstdisp", LstCluNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeSigDetail::StatShr
 ******************************************************************************/

PnlWdbeSigDetail::StatShr::StatShr(
			const bool TxfHtyValid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool PupTypActive
			, const bool LstCluActive
			, const bool ButCluViewActive
			, const bool ButCluClusterAvail
			, const bool ButCluUnclusterAvail
			, const bool TxtReuActive
			, const bool ButReuViewAvail
			, const bool ButReuViewActive
			, const bool TxtMguActive
			, const bool ButMguViewAvail
			, const bool ButMguViewActive
			, const bool TxtVecActive
			, const bool ButVecViewAvail
			, const bool ButVecViewActive
			, const bool ChkConActive
			, const bool PupHtyActive
			, const bool ButHtyEditAvail
			, const bool TxfWidActive
			, const bool TxfMmxActive
			, const bool TxfCmbActive
			, const bool TxfOnvActive
			, const bool TxfOfvActive
			, const bool ChkDfoActive
			, const bool TxtDrvActive
			, const bool ButDrvViewAvail
			, const bool ButDrvViewActive
			, const bool TxfCmtActive
		) :
			Block()
		{
	this->TxfHtyValid = TxfHtyValid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->PupTypActive = PupTypActive;
	this->LstCluActive = LstCluActive;
	this->ButCluViewActive = ButCluViewActive;
	this->ButCluClusterAvail = ButCluClusterAvail;
	this->ButCluUnclusterAvail = ButCluUnclusterAvail;
	this->TxtReuActive = TxtReuActive;
	this->ButReuViewAvail = ButReuViewAvail;
	this->ButReuViewActive = ButReuViewActive;
	this->TxtMguActive = TxtMguActive;
	this->ButMguViewAvail = ButMguViewAvail;
	this->ButMguViewActive = ButMguViewActive;
	this->TxtVecActive = TxtVecActive;
	this->ButVecViewAvail = ButVecViewAvail;
	this->ButVecViewActive = ButVecViewActive;
	this->ChkConActive = ChkConActive;
	this->PupHtyActive = PupHtyActive;
	this->ButHtyEditAvail = ButHtyEditAvail;
	this->TxfWidActive = TxfWidActive;
	this->TxfMmxActive = TxfMmxActive;
	this->TxfCmbActive = TxfCmbActive;
	this->TxfOnvActive = TxfOnvActive;
	this->TxfOfvActive = TxfOfvActive;
	this->ChkDfoActive = ChkDfoActive;
	this->TxtDrvActive = TxtDrvActive;
	this->ButDrvViewAvail = ButDrvViewAvail;
	this->ButDrvViewActive = ButDrvViewActive;
	this->TxfCmtActive = TxfCmtActive;

	mask = {TXFHTYVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPTYPACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, TXTMGUACTIVE, BUTMGUVIEWAVAIL, BUTMGUVIEWACTIVE, TXTVECACTIVE, BUTVECVIEWAVAIL, BUTVECVIEWACTIVE, CHKCONACTIVE, PUPHTYACTIVE, BUTHTYEDITAVAIL, TXFWIDACTIVE, TXFMMXACTIVE, TXFCMBACTIVE, TXFONVACTIVE, TXFOFVACTIVE, CHKDFOACTIVE, TXTDRVACTIVE, BUTDRVVIEWAVAIL, BUTDRVVIEWACTIVE, TXFCMTACTIVE};
};

void PnlWdbeSigDetail::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeSigDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxfHtyValid"] = TxfHtyValid;
	me["ButSaveAvail"] = ButSaveAvail;
	me["ButSaveActive"] = ButSaveActive;
	me["TxtSrfActive"] = TxtSrfActive;
	me["PupTypActive"] = PupTypActive;
	me["LstCluActive"] = LstCluActive;
	me["ButCluViewActive"] = ButCluViewActive;
	me["ButCluClusterAvail"] = ButCluClusterAvail;
	me["ButCluUnclusterAvail"] = ButCluUnclusterAvail;
	me["TxtReuActive"] = TxtReuActive;
	me["ButReuViewAvail"] = ButReuViewAvail;
	me["ButReuViewActive"] = ButReuViewActive;
	me["TxtMguActive"] = TxtMguActive;
	me["ButMguViewAvail"] = ButMguViewAvail;
	me["ButMguViewActive"] = ButMguViewActive;
	me["TxtVecActive"] = TxtVecActive;
	me["ButVecViewAvail"] = ButVecViewAvail;
	me["ButVecViewActive"] = ButVecViewActive;
	me["ChkConActive"] = ChkConActive;
	me["PupHtyActive"] = PupHtyActive;
	me["ButHtyEditAvail"] = ButHtyEditAvail;
	me["TxfWidActive"] = TxfWidActive;
	me["TxfMmxActive"] = TxfMmxActive;
	me["TxfCmbActive"] = TxfCmbActive;
	me["TxfOnvActive"] = TxfOnvActive;
	me["TxfOfvActive"] = TxfOfvActive;
	me["ChkDfoActive"] = ChkDfoActive;
	me["TxtDrvActive"] = TxtDrvActive;
	me["ButDrvViewAvail"] = ButDrvViewAvail;
	me["ButDrvViewActive"] = ButDrvViewActive;
	me["TxfCmtActive"] = TxfCmtActive;
};

void PnlWdbeSigDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeSigDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWdbeSigDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "TxfHtyValid", TxfHtyValid);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSrfActive", TxtSrfActive);
		writeBoolAttr(wr, itemtag, "sref", "PupTypActive", PupTypActive);
		writeBoolAttr(wr, itemtag, "sref", "LstCluActive", LstCluActive);
		writeBoolAttr(wr, itemtag, "sref", "ButCluViewActive", ButCluViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButCluClusterAvail", ButCluClusterAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButCluUnclusterAvail", ButCluUnclusterAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtReuActive", TxtReuActive);
		writeBoolAttr(wr, itemtag, "sref", "ButReuViewAvail", ButReuViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButReuViewActive", ButReuViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtMguActive", TxtMguActive);
		writeBoolAttr(wr, itemtag, "sref", "ButMguViewAvail", ButMguViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButMguViewActive", ButMguViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtVecActive", TxtVecActive);
		writeBoolAttr(wr, itemtag, "sref", "ButVecViewAvail", ButVecViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButVecViewActive", ButVecViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ChkConActive", ChkConActive);
		writeBoolAttr(wr, itemtag, "sref", "PupHtyActive", PupHtyActive);
		writeBoolAttr(wr, itemtag, "sref", "ButHtyEditAvail", ButHtyEditAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfWidActive", TxfWidActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfMmxActive", TxfMmxActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfCmbActive", TxfCmbActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfOnvActive", TxfOnvActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfOfvActive", TxfOfvActive);
		writeBoolAttr(wr, itemtag, "sref", "ChkDfoActive", ChkDfoActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtDrvActive", TxtDrvActive);
		writeBoolAttr(wr, itemtag, "sref", "ButDrvViewAvail", ButDrvViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButDrvViewActive", ButDrvViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfCmtActive", TxfCmtActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeSigDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfHtyValid == comp->TxfHtyValid) insert(items, TXFHTYVALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (PupTypActive == comp->PupTypActive) insert(items, PUPTYPACTIVE);
	if (LstCluActive == comp->LstCluActive) insert(items, LSTCLUACTIVE);
	if (ButCluViewActive == comp->ButCluViewActive) insert(items, BUTCLUVIEWACTIVE);
	if (ButCluClusterAvail == comp->ButCluClusterAvail) insert(items, BUTCLUCLUSTERAVAIL);
	if (ButCluUnclusterAvail == comp->ButCluUnclusterAvail) insert(items, BUTCLUUNCLUSTERAVAIL);
	if (TxtReuActive == comp->TxtReuActive) insert(items, TXTREUACTIVE);
	if (ButReuViewAvail == comp->ButReuViewAvail) insert(items, BUTREUVIEWAVAIL);
	if (ButReuViewActive == comp->ButReuViewActive) insert(items, BUTREUVIEWACTIVE);
	if (TxtMguActive == comp->TxtMguActive) insert(items, TXTMGUACTIVE);
	if (ButMguViewAvail == comp->ButMguViewAvail) insert(items, BUTMGUVIEWAVAIL);
	if (ButMguViewActive == comp->ButMguViewActive) insert(items, BUTMGUVIEWACTIVE);
	if (TxtVecActive == comp->TxtVecActive) insert(items, TXTVECACTIVE);
	if (ButVecViewAvail == comp->ButVecViewAvail) insert(items, BUTVECVIEWAVAIL);
	if (ButVecViewActive == comp->ButVecViewActive) insert(items, BUTVECVIEWACTIVE);
	if (ChkConActive == comp->ChkConActive) insert(items, CHKCONACTIVE);
	if (PupHtyActive == comp->PupHtyActive) insert(items, PUPHTYACTIVE);
	if (ButHtyEditAvail == comp->ButHtyEditAvail) insert(items, BUTHTYEDITAVAIL);
	if (TxfWidActive == comp->TxfWidActive) insert(items, TXFWIDACTIVE);
	if (TxfMmxActive == comp->TxfMmxActive) insert(items, TXFMMXACTIVE);
	if (TxfCmbActive == comp->TxfCmbActive) insert(items, TXFCMBACTIVE);
	if (TxfOnvActive == comp->TxfOnvActive) insert(items, TXFONVACTIVE);
	if (TxfOfvActive == comp->TxfOfvActive) insert(items, TXFOFVACTIVE);
	if (ChkDfoActive == comp->ChkDfoActive) insert(items, CHKDFOACTIVE);
	if (TxtDrvActive == comp->TxtDrvActive) insert(items, TXTDRVACTIVE);
	if (ButDrvViewAvail == comp->ButDrvViewAvail) insert(items, BUTDRVVIEWAVAIL);
	if (ButDrvViewActive == comp->ButDrvViewActive) insert(items, BUTDRVVIEWACTIVE);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);

	return(items);
};

set<uint> PnlWdbeSigDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFHTYVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPTYPACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, TXTMGUACTIVE, BUTMGUVIEWAVAIL, BUTMGUVIEWACTIVE, TXTVECACTIVE, BUTVECVIEWAVAIL, BUTVECVIEWACTIVE, CHKCONACTIVE, PUPHTYACTIVE, BUTHTYEDITAVAIL, TXFWIDACTIVE, TXFMMXACTIVE, TXFCMBACTIVE, TXFONVACTIVE, TXFOFVACTIVE, CHKDFOACTIVE, TXTDRVACTIVE, BUTDRVVIEWAVAIL, BUTDRVVIEWACTIVE, TXFCMTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeSigDetail::Tag
 ******************************************************************************/

void PnlWdbeSigDetail::Tag::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWdbeSigDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		me["CptSrf"] = "identifier";
		me["CptTyp"] = "type";
		me["CptReu"] = "reference";
		me["CptMgu"] = "managing entity";
		me["CptVec"] = "vector";
		me["CptCon"] = "constant";
		me["CptHty"] = "HDL data type";
		me["CptWid"] = "width";
		me["CptMmx"] = "width";
		me["CptCmb"] = "combinatorial expression";
		me["CptOnv"] = "'on' value";
		me["CptOfv"] = "'off' value";
		me["CptDfo"] = "'on' by default";
		me["CptDrv"] = "port driven";
		me["CptCmt"] = "comment";
	};
	me["Cpt"] = StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DETAIL, ixWdbeVLocale));
	me["CptClu"] = VecWdbeVTag::getTitle(VecWdbeVTag::CLUST, ixWdbeVLocale);
};

void PnlWdbeSigDetail::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWdbeSigDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWdbeSigDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptTyp", "type");
			writeStringAttr(wr, itemtag, "sref", "CptReu", "reference");
			writeStringAttr(wr, itemtag, "sref", "CptMgu", "managing entity");
			writeStringAttr(wr, itemtag, "sref", "CptVec", "vector");
			writeStringAttr(wr, itemtag, "sref", "CptCon", "constant");
			writeStringAttr(wr, itemtag, "sref", "CptHty", "HDL data type");
			writeStringAttr(wr, itemtag, "sref", "CptWid", "width");
			writeStringAttr(wr, itemtag, "sref", "CptMmx", "width");
			writeStringAttr(wr, itemtag, "sref", "CptCmb", "combinatorial expression");
			writeStringAttr(wr, itemtag, "sref", "CptOnv", "'on' value");
			writeStringAttr(wr, itemtag, "sref", "CptOfv", "'off' value");
			writeStringAttr(wr, itemtag, "sref", "CptDfo", "'on' by default");
			writeStringAttr(wr, itemtag, "sref", "CptDrv", "port driven");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "comment");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::DETAIL, ixWdbeVLocale)));
		writeStringAttr(wr, itemtag, "sref", "CptClu", VecWdbeVTag::getTitle(VecWdbeVTag::CLUST, ixWdbeVLocale));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeSigDetail::DpchAppData
 ******************************************************************************/

PnlWdbeSigDetail::DpchAppData::DpchAppData() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBESIGDETAILDATA)
		{
};

string PnlWdbeSigDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeSigDetail::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWdbeSigDetailData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWdbeSigDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeSigDetailData");
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
 class PnlWdbeSigDetail::DpchAppDo
 ******************************************************************************/

PnlWdbeSigDetail::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBESIGDETAILDO)
		{
	ixVDo = 0;
};

string PnlWdbeSigDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeSigDetail::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWdbeSigDetailDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWdbeSigDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeSigDetailDo");
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
 class PnlWdbeSigDetail::DpchEngData
 ******************************************************************************/

PnlWdbeSigDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFLstClu
			, Feed* feedFPupHty
			, Feed* feedFPupMgt
			, Feed* feedFPupRet
			, Feed* feedFPupTyp
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBESIGDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFLSTCLU, FEEDFPUPHTY, FEEDFPUPMGT, FEEDFPUPRET, FEEDFPUPTYP, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFLSTCLU) && feedFLstClu) this->feedFLstClu = *feedFLstClu;
	if (find(this->mask, FEEDFPUPHTY) && feedFPupHty) this->feedFPupHty = *feedFPupHty;
	if (find(this->mask, FEEDFPUPMGT) && feedFPupMgt) this->feedFPupMgt = *feedFPupMgt;
	if (find(this->mask, FEEDFPUPRET) && feedFPupRet) this->feedFPupRet = *feedFPupRet;
	if (find(this->mask, FEEDFPUPTYP) && feedFPupTyp) this->feedFPupTyp = *feedFPupTyp;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWdbeSigDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTCLU)) ss.push_back("feedFLstClu");
	if (has(FEEDFPUPHTY)) ss.push_back("feedFPupHty");
	if (has(FEEDFPUPMGT)) ss.push_back("feedFPupMgt");
	if (has(FEEDFPUPRET)) ss.push_back("feedFPupRet");
	if (has(FEEDFPUPTYP)) ss.push_back("feedFPupTyp");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeSigDetail::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFLSTCLU)) {feedFLstClu = src->feedFLstClu; add(FEEDFLSTCLU);};
	if (src->has(FEEDFPUPHTY)) {feedFPupHty = src->feedFPupHty; add(FEEDFPUPHTY);};
	if (src->has(FEEDFPUPMGT)) {feedFPupMgt = src->feedFPupMgt; add(FEEDFPUPMGT);};
	if (src->has(FEEDFPUPRET)) {feedFPupRet = src->feedFPupRet; add(FEEDFPUPRET);};
	if (src->has(FEEDFPUPTYP)) {feedFPupTyp = src->feedFPupTyp; add(FEEDFPUPTYP);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWdbeSigDetail::DpchEngData::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWdbeSigDetailData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFLSTCLU)) feedFLstClu.writeJSON(me);
	if (has(FEEDFPUPHTY)) feedFPupHty.writeJSON(me);
	if (has(FEEDFPUPMGT)) feedFPupMgt.writeJSON(me);
	if (has(FEEDFPUPRET)) feedFPupRet.writeJSON(me);
	if (has(FEEDFPUPTYP)) feedFPupTyp.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWdbeVLocale, me);
};

void PnlWdbeSigDetail::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWdbeSigDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFLSTCLU)) feedFLstClu.writeXML(wr);
		if (has(FEEDFPUPHTY)) feedFPupHty.writeXML(wr);
		if (has(FEEDFPUPMGT)) feedFPupMgt.writeXML(wr);
		if (has(FEEDFPUPRET)) feedFPupRet.writeXML(wr);
		if (has(FEEDFPUPTYP)) feedFPupTyp.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};
