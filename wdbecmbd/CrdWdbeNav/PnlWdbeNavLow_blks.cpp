/**
	* \file PnlWdbeNavLow_blks.cpp
	* job handler for job PnlWdbeNavLow (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbeNavLow::VecVDo
 ******************************************************************************/

uint PnlWdbeNavLow::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butbnkviewclick") return BUTBNKVIEWCLICK;
	if (s == "butbnknewcrdclick") return BUTBNKNEWCRDCLICK;
	if (s == "butpinviewclick") return BUTPINVIEWCLICK;
	if (s == "butpinnewcrdclick") return BUTPINNEWCRDCLICK;
	if (s == "butintviewclick") return BUTINTVIEWCLICK;
	if (s == "butintnewcrdclick") return BUTINTNEWCRDCLICK;
	if (s == "butsnsviewclick") return BUTSNSVIEWCLICK;
	if (s == "butvarviewclick") return BUTVARVIEWCLICK;
	if (s == "butgenviewclick") return BUTGENVIEWCLICK;
	if (s == "butprtviewclick") return BUTPRTVIEWCLICK;
	if (s == "butsigviewclick") return BUTSIGVIEWCLICK;
	if (s == "butsignewcrdclick") return BUTSIGNEWCRDCLICK;
	if (s == "butprcviewclick") return BUTPRCVIEWCLICK;
	if (s == "butfstviewclick") return BUTFSTVIEWCLICK;

	return(0);
};

string PnlWdbeNavLow::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTBNKVIEWCLICK) return("ButBnkViewClick");
	if (ix == BUTBNKNEWCRDCLICK) return("ButBnkNewcrdClick");
	if (ix == BUTPINVIEWCLICK) return("ButPinViewClick");
	if (ix == BUTPINNEWCRDCLICK) return("ButPinNewcrdClick");
	if (ix == BUTINTVIEWCLICK) return("ButIntViewClick");
	if (ix == BUTINTNEWCRDCLICK) return("ButIntNewcrdClick");
	if (ix == BUTSNSVIEWCLICK) return("ButSnsViewClick");
	if (ix == BUTVARVIEWCLICK) return("ButVarViewClick");
	if (ix == BUTGENVIEWCLICK) return("ButGenViewClick");
	if (ix == BUTPRTVIEWCLICK) return("ButPrtViewClick");
	if (ix == BUTSIGVIEWCLICK) return("ButSigViewClick");
	if (ix == BUTSIGNEWCRDCLICK) return("ButSigNewcrdClick");
	if (ix == BUTPRCVIEWCLICK) return("ButPrcViewClick");
	if (ix == BUTFSTVIEWCLICK) return("ButFstViewClick");

	return("");
};

/******************************************************************************
 class PnlWdbeNavLow::ContIac
 ******************************************************************************/

PnlWdbeNavLow::ContIac::ContIac(
			const uint numFLstBnk
			, const uint numFLstPin
			, const uint numFLstInt
			, const uint numFLstSns
			, const uint numFLstVar
			, const uint numFLstGen
			, const uint numFLstPrt
			, const uint numFLstSig
			, const uint numFLstPrc
			, const uint numFLstFst
		) :
			Block()
		{
	this->numFLstBnk = numFLstBnk;
	this->numFLstPin = numFLstPin;
	this->numFLstInt = numFLstInt;
	this->numFLstSns = numFLstSns;
	this->numFLstVar = numFLstVar;
	this->numFLstGen = numFLstGen;
	this->numFLstPrt = numFLstPrt;
	this->numFLstSig = numFLstSig;
	this->numFLstPrc = numFLstPrc;
	this->numFLstFst = numFLstFst;

	mask = {NUMFLSTBNK, NUMFLSTPIN, NUMFLSTINT, NUMFLSTSNS, NUMFLSTVAR, NUMFLSTGEN, NUMFLSTPRT, NUMFLSTSIG, NUMFLSTPRC, NUMFLSTFST};
};

bool PnlWdbeNavLow::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacWdbeNavLow"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFLstBnk")) {numFLstBnk = me["numFLstBnk"].asUInt(); add(NUMFLSTBNK);};
		if (me.isMember("numFLstPin")) {numFLstPin = me["numFLstPin"].asUInt(); add(NUMFLSTPIN);};
		if (me.isMember("numFLstInt")) {numFLstInt = me["numFLstInt"].asUInt(); add(NUMFLSTINT);};
		if (me.isMember("numFLstSns")) {numFLstSns = me["numFLstSns"].asUInt(); add(NUMFLSTSNS);};
		if (me.isMember("numFLstVar")) {numFLstVar = me["numFLstVar"].asUInt(); add(NUMFLSTVAR);};
		if (me.isMember("numFLstGen")) {numFLstGen = me["numFLstGen"].asUInt(); add(NUMFLSTGEN);};
		if (me.isMember("numFLstPrt")) {numFLstPrt = me["numFLstPrt"].asUInt(); add(NUMFLSTPRT);};
		if (me.isMember("numFLstSig")) {numFLstSig = me["numFLstSig"].asUInt(); add(NUMFLSTSIG);};
		if (me.isMember("numFLstPrc")) {numFLstPrc = me["numFLstPrc"].asUInt(); add(NUMFLSTPRC);};
		if (me.isMember("numFLstFst")) {numFLstFst = me["numFLstFst"].asUInt(); add(NUMFLSTFST);};
	};

	return basefound;
};

bool PnlWdbeNavLow::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWdbeNavLow");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWdbeNavLow";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstBnk", numFLstBnk)) add(NUMFLSTBNK);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstPin", numFLstPin)) add(NUMFLSTPIN);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstInt", numFLstInt)) add(NUMFLSTINT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstSns", numFLstSns)) add(NUMFLSTSNS);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstVar", numFLstVar)) add(NUMFLSTVAR);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstGen", numFLstGen)) add(NUMFLSTGEN);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstPrt", numFLstPrt)) add(NUMFLSTPRT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstSig", numFLstSig)) add(NUMFLSTSIG);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstPrc", numFLstPrc)) add(NUMFLSTPRC);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstFst", numFLstFst)) add(NUMFLSTFST);
	};

	return basefound;
};

void PnlWdbeNavLow::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeNavLow";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFLstBnk"] = numFLstBnk;
	me["numFLstPin"] = numFLstPin;
	me["numFLstInt"] = numFLstInt;
	me["numFLstSns"] = numFLstSns;
	me["numFLstVar"] = numFLstVar;
	me["numFLstGen"] = numFLstGen;
	me["numFLstPrt"] = numFLstPrt;
	me["numFLstSig"] = numFLstSig;
	me["numFLstPrc"] = numFLstPrc;
	me["numFLstFst"] = numFLstFst;
};

void PnlWdbeNavLow::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeNavLow";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWdbeNavLow";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstBnk", numFLstBnk);
		writeUintAttr(wr, itemtag, "sref", "numFLstPin", numFLstPin);
		writeUintAttr(wr, itemtag, "sref", "numFLstInt", numFLstInt);
		writeUintAttr(wr, itemtag, "sref", "numFLstSns", numFLstSns);
		writeUintAttr(wr, itemtag, "sref", "numFLstVar", numFLstVar);
		writeUintAttr(wr, itemtag, "sref", "numFLstGen", numFLstGen);
		writeUintAttr(wr, itemtag, "sref", "numFLstPrt", numFLstPrt);
		writeUintAttr(wr, itemtag, "sref", "numFLstSig", numFLstSig);
		writeUintAttr(wr, itemtag, "sref", "numFLstPrc", numFLstPrc);
		writeUintAttr(wr, itemtag, "sref", "numFLstFst", numFLstFst);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeNavLow::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstBnk == comp->numFLstBnk) insert(items, NUMFLSTBNK);
	if (numFLstPin == comp->numFLstPin) insert(items, NUMFLSTPIN);
	if (numFLstInt == comp->numFLstInt) insert(items, NUMFLSTINT);
	if (numFLstSns == comp->numFLstSns) insert(items, NUMFLSTSNS);
	if (numFLstVar == comp->numFLstVar) insert(items, NUMFLSTVAR);
	if (numFLstGen == comp->numFLstGen) insert(items, NUMFLSTGEN);
	if (numFLstPrt == comp->numFLstPrt) insert(items, NUMFLSTPRT);
	if (numFLstSig == comp->numFLstSig) insert(items, NUMFLSTSIG);
	if (numFLstPrc == comp->numFLstPrc) insert(items, NUMFLSTPRC);
	if (numFLstFst == comp->numFLstFst) insert(items, NUMFLSTFST);

	return(items);
};

set<uint> PnlWdbeNavLow::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTBNK, NUMFLSTPIN, NUMFLSTINT, NUMFLSTSNS, NUMFLSTVAR, NUMFLSTGEN, NUMFLSTPRT, NUMFLSTSIG, NUMFLSTPRC, NUMFLSTFST};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeNavLow::StatApp
 ******************************************************************************/

void PnlWdbeNavLow::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWdbeVExpstate
			, const bool LstBnkAlt
			, const bool LstPinAlt
			, const bool LstIntAlt
			, const bool LstSnsAlt
			, const bool LstVarAlt
			, const bool LstGenAlt
			, const bool LstPrtAlt
			, const bool LstSigAlt
			, const bool LstPrcAlt
			, const bool LstFstAlt
			, const uint LstBnkNumFirstdisp
			, const uint LstPinNumFirstdisp
			, const uint LstIntNumFirstdisp
			, const uint LstSnsNumFirstdisp
			, const uint LstVarNumFirstdisp
			, const uint LstGenNumFirstdisp
			, const uint LstPrtNumFirstdisp
			, const uint LstSigNumFirstdisp
			, const uint LstPrcNumFirstdisp
			, const uint LstFstNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeNavLow";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWdbeVExpstate"] = VecWdbeVExpstate::getSref(ixWdbeVExpstate);
	me["LstBnkAlt"] = LstBnkAlt;
	me["LstPinAlt"] = LstPinAlt;
	me["LstIntAlt"] = LstIntAlt;
	me["LstSnsAlt"] = LstSnsAlt;
	me["LstVarAlt"] = LstVarAlt;
	me["LstGenAlt"] = LstGenAlt;
	me["LstPrtAlt"] = LstPrtAlt;
	me["LstSigAlt"] = LstSigAlt;
	me["LstPrcAlt"] = LstPrcAlt;
	me["LstFstAlt"] = LstFstAlt;
	me["LstBnkNumFirstdisp"] = LstBnkNumFirstdisp;
	me["LstPinNumFirstdisp"] = LstPinNumFirstdisp;
	me["LstIntNumFirstdisp"] = LstIntNumFirstdisp;
	me["LstSnsNumFirstdisp"] = LstSnsNumFirstdisp;
	me["LstVarNumFirstdisp"] = LstVarNumFirstdisp;
	me["LstGenNumFirstdisp"] = LstGenNumFirstdisp;
	me["LstPrtNumFirstdisp"] = LstPrtNumFirstdisp;
	me["LstSigNumFirstdisp"] = LstSigNumFirstdisp;
	me["LstPrcNumFirstdisp"] = LstPrcNumFirstdisp;
	me["LstFstNumFirstdisp"] = LstFstNumFirstdisp;
};

void PnlWdbeNavLow::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWdbeVExpstate
			, const bool LstBnkAlt
			, const bool LstPinAlt
			, const bool LstIntAlt
			, const bool LstSnsAlt
			, const bool LstVarAlt
			, const bool LstGenAlt
			, const bool LstPrtAlt
			, const bool LstSigAlt
			, const bool LstPrcAlt
			, const bool LstFstAlt
			, const uint LstBnkNumFirstdisp
			, const uint LstPinNumFirstdisp
			, const uint LstIntNumFirstdisp
			, const uint LstSnsNumFirstdisp
			, const uint LstVarNumFirstdisp
			, const uint LstGenNumFirstdisp
			, const uint LstPrtNumFirstdisp
			, const uint LstSigNumFirstdisp
			, const uint LstPrcNumFirstdisp
			, const uint LstFstNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeNavLow";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWdbeNavLow";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWdbeVExpstate", VecWdbeVExpstate::getSref(ixWdbeVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstBnkAlt", LstBnkAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstPinAlt", LstPinAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstIntAlt", LstIntAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstSnsAlt", LstSnsAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstVarAlt", LstVarAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstGenAlt", LstGenAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstPrtAlt", LstPrtAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstSigAlt", LstSigAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstPrcAlt", LstPrcAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstFstAlt", LstFstAlt);
		writeUintAttr(wr, itemtag, "sref", "LstBnkNumFirstdisp", LstBnkNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstPinNumFirstdisp", LstPinNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstIntNumFirstdisp", LstIntNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstSnsNumFirstdisp", LstSnsNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstVarNumFirstdisp", LstVarNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstGenNumFirstdisp", LstGenNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstPrtNumFirstdisp", LstPrtNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstSigNumFirstdisp", LstSigNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstPrcNumFirstdisp", LstPrcNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstFstNumFirstdisp", LstFstNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeNavLow::StatShr
 ******************************************************************************/

PnlWdbeNavLow::StatShr::StatShr(
			const bool LstBnkAvail
			, const bool ButBnkViewActive
			, const bool ButBnkNewcrdActive
			, const bool LstPinAvail
			, const bool ButPinViewActive
			, const bool ButPinNewcrdActive
			, const bool LstIntAvail
			, const bool ButIntViewActive
			, const bool ButIntNewcrdActive
			, const bool LstSnsAvail
			, const bool ButSnsViewActive
			, const bool LstVarAvail
			, const bool ButVarViewActive
			, const bool LstGenAvail
			, const bool ButGenViewActive
			, const bool LstPrtAvail
			, const bool ButPrtViewActive
			, const bool LstSigAvail
			, const bool ButSigViewActive
			, const bool ButSigNewcrdActive
			, const bool LstPrcAvail
			, const bool ButPrcViewActive
			, const bool LstFstAvail
			, const bool ButFstViewActive
		) :
			Block()
		{
	this->LstBnkAvail = LstBnkAvail;
	this->ButBnkViewActive = ButBnkViewActive;
	this->ButBnkNewcrdActive = ButBnkNewcrdActive;
	this->LstPinAvail = LstPinAvail;
	this->ButPinViewActive = ButPinViewActive;
	this->ButPinNewcrdActive = ButPinNewcrdActive;
	this->LstIntAvail = LstIntAvail;
	this->ButIntViewActive = ButIntViewActive;
	this->ButIntNewcrdActive = ButIntNewcrdActive;
	this->LstSnsAvail = LstSnsAvail;
	this->ButSnsViewActive = ButSnsViewActive;
	this->LstVarAvail = LstVarAvail;
	this->ButVarViewActive = ButVarViewActive;
	this->LstGenAvail = LstGenAvail;
	this->ButGenViewActive = ButGenViewActive;
	this->LstPrtAvail = LstPrtAvail;
	this->ButPrtViewActive = ButPrtViewActive;
	this->LstSigAvail = LstSigAvail;
	this->ButSigViewActive = ButSigViewActive;
	this->ButSigNewcrdActive = ButSigNewcrdActive;
	this->LstPrcAvail = LstPrcAvail;
	this->ButPrcViewActive = ButPrcViewActive;
	this->LstFstAvail = LstFstAvail;
	this->ButFstViewActive = ButFstViewActive;

	mask = {LSTBNKAVAIL, BUTBNKVIEWACTIVE, BUTBNKNEWCRDACTIVE, LSTPINAVAIL, BUTPINVIEWACTIVE, BUTPINNEWCRDACTIVE, LSTINTAVAIL, BUTINTVIEWACTIVE, BUTINTNEWCRDACTIVE, LSTSNSAVAIL, BUTSNSVIEWACTIVE, LSTVARAVAIL, BUTVARVIEWACTIVE, LSTGENAVAIL, BUTGENVIEWACTIVE, LSTPRTAVAIL, BUTPRTVIEWACTIVE, LSTSIGAVAIL, BUTSIGVIEWACTIVE, BUTSIGNEWCRDACTIVE, LSTPRCAVAIL, BUTPRCVIEWACTIVE, LSTFSTAVAIL, BUTFSTVIEWACTIVE};
};

void PnlWdbeNavLow::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeNavLow";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["LstBnkAvail"] = LstBnkAvail;
	me["ButBnkViewActive"] = ButBnkViewActive;
	me["ButBnkNewcrdActive"] = ButBnkNewcrdActive;
	me["LstPinAvail"] = LstPinAvail;
	me["ButPinViewActive"] = ButPinViewActive;
	me["ButPinNewcrdActive"] = ButPinNewcrdActive;
	me["LstIntAvail"] = LstIntAvail;
	me["ButIntViewActive"] = ButIntViewActive;
	me["ButIntNewcrdActive"] = ButIntNewcrdActive;
	me["LstSnsAvail"] = LstSnsAvail;
	me["ButSnsViewActive"] = ButSnsViewActive;
	me["LstVarAvail"] = LstVarAvail;
	me["ButVarViewActive"] = ButVarViewActive;
	me["LstGenAvail"] = LstGenAvail;
	me["ButGenViewActive"] = ButGenViewActive;
	me["LstPrtAvail"] = LstPrtAvail;
	me["ButPrtViewActive"] = ButPrtViewActive;
	me["LstSigAvail"] = LstSigAvail;
	me["ButSigViewActive"] = ButSigViewActive;
	me["ButSigNewcrdActive"] = ButSigNewcrdActive;
	me["LstPrcAvail"] = LstPrcAvail;
	me["ButPrcViewActive"] = ButPrcViewActive;
	me["LstFstAvail"] = LstFstAvail;
	me["ButFstViewActive"] = ButFstViewActive;
};

void PnlWdbeNavLow::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeNavLow";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWdbeNavLow";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "LstBnkAvail", LstBnkAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButBnkViewActive", ButBnkViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButBnkNewcrdActive", ButBnkNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstPinAvail", LstPinAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButPinViewActive", ButPinViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButPinNewcrdActive", ButPinNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstIntAvail", LstIntAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButIntViewActive", ButIntViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButIntNewcrdActive", ButIntNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstSnsAvail", LstSnsAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSnsViewActive", ButSnsViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstVarAvail", LstVarAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButVarViewActive", ButVarViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstGenAvail", LstGenAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButGenViewActive", ButGenViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstPrtAvail", LstPrtAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButPrtViewActive", ButPrtViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstSigAvail", LstSigAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSigViewActive", ButSigViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButSigNewcrdActive", ButSigNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstPrcAvail", LstPrcAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButPrcViewActive", ButPrcViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstFstAvail", LstFstAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButFstViewActive", ButFstViewActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeNavLow::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstBnkAvail == comp->LstBnkAvail) insert(items, LSTBNKAVAIL);
	if (ButBnkViewActive == comp->ButBnkViewActive) insert(items, BUTBNKVIEWACTIVE);
	if (ButBnkNewcrdActive == comp->ButBnkNewcrdActive) insert(items, BUTBNKNEWCRDACTIVE);
	if (LstPinAvail == comp->LstPinAvail) insert(items, LSTPINAVAIL);
	if (ButPinViewActive == comp->ButPinViewActive) insert(items, BUTPINVIEWACTIVE);
	if (ButPinNewcrdActive == comp->ButPinNewcrdActive) insert(items, BUTPINNEWCRDACTIVE);
	if (LstIntAvail == comp->LstIntAvail) insert(items, LSTINTAVAIL);
	if (ButIntViewActive == comp->ButIntViewActive) insert(items, BUTINTVIEWACTIVE);
	if (ButIntNewcrdActive == comp->ButIntNewcrdActive) insert(items, BUTINTNEWCRDACTIVE);
	if (LstSnsAvail == comp->LstSnsAvail) insert(items, LSTSNSAVAIL);
	if (ButSnsViewActive == comp->ButSnsViewActive) insert(items, BUTSNSVIEWACTIVE);
	if (LstVarAvail == comp->LstVarAvail) insert(items, LSTVARAVAIL);
	if (ButVarViewActive == comp->ButVarViewActive) insert(items, BUTVARVIEWACTIVE);
	if (LstGenAvail == comp->LstGenAvail) insert(items, LSTGENAVAIL);
	if (ButGenViewActive == comp->ButGenViewActive) insert(items, BUTGENVIEWACTIVE);
	if (LstPrtAvail == comp->LstPrtAvail) insert(items, LSTPRTAVAIL);
	if (ButPrtViewActive == comp->ButPrtViewActive) insert(items, BUTPRTVIEWACTIVE);
	if (LstSigAvail == comp->LstSigAvail) insert(items, LSTSIGAVAIL);
	if (ButSigViewActive == comp->ButSigViewActive) insert(items, BUTSIGVIEWACTIVE);
	if (ButSigNewcrdActive == comp->ButSigNewcrdActive) insert(items, BUTSIGNEWCRDACTIVE);
	if (LstPrcAvail == comp->LstPrcAvail) insert(items, LSTPRCAVAIL);
	if (ButPrcViewActive == comp->ButPrcViewActive) insert(items, BUTPRCVIEWACTIVE);
	if (LstFstAvail == comp->LstFstAvail) insert(items, LSTFSTAVAIL);
	if (ButFstViewActive == comp->ButFstViewActive) insert(items, BUTFSTVIEWACTIVE);

	return(items);
};

set<uint> PnlWdbeNavLow::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTBNKAVAIL, BUTBNKVIEWACTIVE, BUTBNKNEWCRDACTIVE, LSTPINAVAIL, BUTPINVIEWACTIVE, BUTPINNEWCRDACTIVE, LSTINTAVAIL, BUTINTVIEWACTIVE, BUTINTNEWCRDACTIVE, LSTSNSAVAIL, BUTSNSVIEWACTIVE, LSTVARAVAIL, BUTVARVIEWACTIVE, LSTGENAVAIL, BUTGENVIEWACTIVE, LSTPRTAVAIL, BUTPRTVIEWACTIVE, LSTSIGAVAIL, BUTSIGVIEWACTIVE, BUTSIGNEWCRDACTIVE, LSTPRCAVAIL, BUTPRCVIEWACTIVE, LSTFSTAVAIL, BUTFSTVIEWACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeNavLow::Tag
 ******************************************************************************/

void PnlWdbeNavLow::Tag::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWdbeNavLow";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		me["Cpt"] = "Low-level description module";
		me["CptBnk"] = "I/O banks";
		me["CptPin"] = "pins";
		me["CptInt"] = "interrupts";
		me["CptSns"] = "sensitivities";
		me["CptVar"] = "variables";
		me["CptGen"] = "generics";
		me["CptPrt"] = "ports";
		me["CptSig"] = "signals";
		me["CptPrc"] = "processes";
		me["CptFst"] = "FSM states";
	};
};

void PnlWdbeNavLow::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWdbeNavLow";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWdbeNavLow";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Low-level description module");
			writeStringAttr(wr, itemtag, "sref", "CptBnk", "I/O banks");
			writeStringAttr(wr, itemtag, "sref", "CptPin", "pins");
			writeStringAttr(wr, itemtag, "sref", "CptInt", "interrupts");
			writeStringAttr(wr, itemtag, "sref", "CptSns", "sensitivities");
			writeStringAttr(wr, itemtag, "sref", "CptVar", "variables");
			writeStringAttr(wr, itemtag, "sref", "CptGen", "generics");
			writeStringAttr(wr, itemtag, "sref", "CptPrt", "ports");
			writeStringAttr(wr, itemtag, "sref", "CptSig", "signals");
			writeStringAttr(wr, itemtag, "sref", "CptPrc", "processes");
			writeStringAttr(wr, itemtag, "sref", "CptFst", "FSM states");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeNavLow::DpchAppData
 ******************************************************************************/

PnlWdbeNavLow::DpchAppData::DpchAppData() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBENAVLOWDATA)
		{
};

string PnlWdbeNavLow::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavLow::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWdbeNavLowData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWdbeNavLow::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeNavLowData");
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
 class PnlWdbeNavLow::DpchAppDo
 ******************************************************************************/

PnlWdbeNavLow::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBENAVLOWDO)
		{
	ixVDo = 0;
};

string PnlWdbeNavLow::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavLow::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWdbeNavLowDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWdbeNavLow::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeNavLowDo");
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
 class PnlWdbeNavLow::DpchEngData
 ******************************************************************************/

PnlWdbeNavLow::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, Feed* feedFLstBnk
			, Feed* feedFLstFst
			, Feed* feedFLstGen
			, Feed* feedFLstInt
			, Feed* feedFLstPin
			, Feed* feedFLstPrc
			, Feed* feedFLstPrt
			, Feed* feedFLstSig
			, Feed* feedFLstSns
			, Feed* feedFLstVar
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBENAVLOWDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, FEEDFLSTBNK, FEEDFLSTFST, FEEDFLSTGEN, FEEDFLSTINT, FEEDFLSTPIN, FEEDFLSTPRC, FEEDFLSTPRT, FEEDFLSTSIG, FEEDFLSTSNS, FEEDFLSTVAR, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, FEEDFLSTBNK) && feedFLstBnk) this->feedFLstBnk = *feedFLstBnk;
	if (find(this->mask, FEEDFLSTFST) && feedFLstFst) this->feedFLstFst = *feedFLstFst;
	if (find(this->mask, FEEDFLSTGEN) && feedFLstGen) this->feedFLstGen = *feedFLstGen;
	if (find(this->mask, FEEDFLSTINT) && feedFLstInt) this->feedFLstInt = *feedFLstInt;
	if (find(this->mask, FEEDFLSTPIN) && feedFLstPin) this->feedFLstPin = *feedFLstPin;
	if (find(this->mask, FEEDFLSTPRC) && feedFLstPrc) this->feedFLstPrc = *feedFLstPrc;
	if (find(this->mask, FEEDFLSTPRT) && feedFLstPrt) this->feedFLstPrt = *feedFLstPrt;
	if (find(this->mask, FEEDFLSTSIG) && feedFLstSig) this->feedFLstSig = *feedFLstSig;
	if (find(this->mask, FEEDFLSTSNS) && feedFLstSns) this->feedFLstSns = *feedFLstSns;
	if (find(this->mask, FEEDFLSTVAR) && feedFLstVar) this->feedFLstVar = *feedFLstVar;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWdbeNavLow::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTBNK)) ss.push_back("feedFLstBnk");
	if (has(FEEDFLSTFST)) ss.push_back("feedFLstFst");
	if (has(FEEDFLSTGEN)) ss.push_back("feedFLstGen");
	if (has(FEEDFLSTINT)) ss.push_back("feedFLstInt");
	if (has(FEEDFLSTPIN)) ss.push_back("feedFLstPin");
	if (has(FEEDFLSTPRC)) ss.push_back("feedFLstPrc");
	if (has(FEEDFLSTPRT)) ss.push_back("feedFLstPrt");
	if (has(FEEDFLSTSIG)) ss.push_back("feedFLstSig");
	if (has(FEEDFLSTSNS)) ss.push_back("feedFLstSns");
	if (has(FEEDFLSTVAR)) ss.push_back("feedFLstVar");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavLow::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(FEEDFLSTBNK)) {feedFLstBnk = src->feedFLstBnk; add(FEEDFLSTBNK);};
	if (src->has(FEEDFLSTFST)) {feedFLstFst = src->feedFLstFst; add(FEEDFLSTFST);};
	if (src->has(FEEDFLSTGEN)) {feedFLstGen = src->feedFLstGen; add(FEEDFLSTGEN);};
	if (src->has(FEEDFLSTINT)) {feedFLstInt = src->feedFLstInt; add(FEEDFLSTINT);};
	if (src->has(FEEDFLSTPIN)) {feedFLstPin = src->feedFLstPin; add(FEEDFLSTPIN);};
	if (src->has(FEEDFLSTPRC)) {feedFLstPrc = src->feedFLstPrc; add(FEEDFLSTPRC);};
	if (src->has(FEEDFLSTPRT)) {feedFLstPrt = src->feedFLstPrt; add(FEEDFLSTPRT);};
	if (src->has(FEEDFLSTSIG)) {feedFLstSig = src->feedFLstSig; add(FEEDFLSTSIG);};
	if (src->has(FEEDFLSTSNS)) {feedFLstSns = src->feedFLstSns; add(FEEDFLSTSNS);};
	if (src->has(FEEDFLSTVAR)) {feedFLstVar = src->feedFLstVar; add(FEEDFLSTVAR);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWdbeNavLow::DpchEngData::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWdbeNavLowData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(FEEDFLSTBNK)) feedFLstBnk.writeJSON(me);
	if (has(FEEDFLSTFST)) feedFLstFst.writeJSON(me);
	if (has(FEEDFLSTGEN)) feedFLstGen.writeJSON(me);
	if (has(FEEDFLSTINT)) feedFLstInt.writeJSON(me);
	if (has(FEEDFLSTPIN)) feedFLstPin.writeJSON(me);
	if (has(FEEDFLSTPRC)) feedFLstPrc.writeJSON(me);
	if (has(FEEDFLSTPRT)) feedFLstPrt.writeJSON(me);
	if (has(FEEDFLSTSIG)) feedFLstSig.writeJSON(me);
	if (has(FEEDFLSTSNS)) feedFLstSns.writeJSON(me);
	if (has(FEEDFLSTVAR)) feedFLstVar.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWdbeVLocale, me);
};

void PnlWdbeNavLow::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWdbeNavLowData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(FEEDFLSTBNK)) feedFLstBnk.writeXML(wr);
		if (has(FEEDFLSTFST)) feedFLstFst.writeXML(wr);
		if (has(FEEDFLSTGEN)) feedFLstGen.writeXML(wr);
		if (has(FEEDFLSTINT)) feedFLstInt.writeXML(wr);
		if (has(FEEDFLSTPIN)) feedFLstPin.writeXML(wr);
		if (has(FEEDFLSTPRC)) feedFLstPrc.writeXML(wr);
		if (has(FEEDFLSTPRT)) feedFLstPrt.writeXML(wr);
		if (has(FEEDFLSTSIG)) feedFLstSig.writeXML(wr);
		if (has(FEEDFLSTSNS)) feedFLstSns.writeXML(wr);
		if (has(FEEDFLSTVAR)) feedFLstVar.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};
