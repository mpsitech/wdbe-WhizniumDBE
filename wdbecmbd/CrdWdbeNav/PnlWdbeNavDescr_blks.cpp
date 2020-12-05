/**
	* \file PnlWdbeNavDescr_blks.cpp
	* job handler for job PnlWdbeNavDescr (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbeNavDescr::VecVDo
 ******************************************************************************/

uint PnlWdbeNavDescr::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butmodviewclick") return BUTMODVIEWCLICK;
	if (s == "butmodnewcrdclick") return BUTMODNEWCRDCLICK;
	if (s == "butvecviewclick") return BUTVECVIEWCLICK;
	if (s == "butvecnewcrdclick") return BUTVECNEWCRDCLICK;
	if (s == "butvitviewclick") return BUTVITVIEWCLICK;
	if (s == "butcmdviewclick") return BUTCMDVIEWCLICK;
	if (s == "butcmdnewcrdclick") return BUTCMDNEWCRDCLICK;
	if (s == "buterrviewclick") return BUTERRVIEWCLICK;
	if (s == "buterrnewcrdclick") return BUTERRNEWCRDCLICK;
	if (s == "butpphviewclick") return BUTPPHVIEWCLICK;
	if (s == "butpphnewcrdclick") return BUTPPHNEWCRDCLICK;
	if (s == "butbnkviewclick") return BUTBNKVIEWCLICK;
	if (s == "butbnknewcrdclick") return BUTBNKNEWCRDCLICK;
	if (s == "butpinviewclick") return BUTPINVIEWCLICK;
	if (s == "butpinnewcrdclick") return BUTPINNEWCRDCLICK;
	if (s == "butgenviewclick") return BUTGENVIEWCLICK;
	if (s == "butprtviewclick") return BUTPRTVIEWCLICK;
	if (s == "butsigviewclick") return BUTSIGVIEWCLICK;
	if (s == "butprcviewclick") return BUTPRCVIEWCLICK;
	if (s == "butfstviewclick") return BUTFSTVIEWCLICK;
	if (s == "butvarviewclick") return BUTVARVIEWCLICK;

	return(0);
};

string PnlWdbeNavDescr::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMODVIEWCLICK) return("ButModViewClick");
	if (ix == BUTMODNEWCRDCLICK) return("ButModNewcrdClick");
	if (ix == BUTVECVIEWCLICK) return("ButVecViewClick");
	if (ix == BUTVECNEWCRDCLICK) return("ButVecNewcrdClick");
	if (ix == BUTVITVIEWCLICK) return("ButVitViewClick");
	if (ix == BUTCMDVIEWCLICK) return("ButCmdViewClick");
	if (ix == BUTCMDNEWCRDCLICK) return("ButCmdNewcrdClick");
	if (ix == BUTERRVIEWCLICK) return("ButErrViewClick");
	if (ix == BUTERRNEWCRDCLICK) return("ButErrNewcrdClick");
	if (ix == BUTPPHVIEWCLICK) return("ButPphViewClick");
	if (ix == BUTPPHNEWCRDCLICK) return("ButPphNewcrdClick");
	if (ix == BUTBNKVIEWCLICK) return("ButBnkViewClick");
	if (ix == BUTBNKNEWCRDCLICK) return("ButBnkNewcrdClick");
	if (ix == BUTPINVIEWCLICK) return("ButPinViewClick");
	if (ix == BUTPINNEWCRDCLICK) return("ButPinNewcrdClick");
	if (ix == BUTGENVIEWCLICK) return("ButGenViewClick");
	if (ix == BUTPRTVIEWCLICK) return("ButPrtViewClick");
	if (ix == BUTSIGVIEWCLICK) return("ButSigViewClick");
	if (ix == BUTPRCVIEWCLICK) return("ButPrcViewClick");
	if (ix == BUTFSTVIEWCLICK) return("ButFstViewClick");
	if (ix == BUTVARVIEWCLICK) return("ButVarViewClick");

	return("");
};

/******************************************************************************
 class PnlWdbeNavDescr::ContIac
 ******************************************************************************/

PnlWdbeNavDescr::ContIac::ContIac(
			const uint numFLstMod
			, const uint numFLstVec
			, const uint numFLstVit
			, const uint numFLstCmd
			, const uint numFLstErr
			, const uint numFLstPph
			, const uint numFLstBnk
			, const uint numFLstPin
			, const uint numFLstGen
			, const uint numFLstPrt
			, const uint numFLstSig
			, const uint numFLstPrc
			, const uint numFLstFst
			, const uint numFLstVar
		) :
			Block()
		{
	this->numFLstMod = numFLstMod;
	this->numFLstVec = numFLstVec;
	this->numFLstVit = numFLstVit;
	this->numFLstCmd = numFLstCmd;
	this->numFLstErr = numFLstErr;
	this->numFLstPph = numFLstPph;
	this->numFLstBnk = numFLstBnk;
	this->numFLstPin = numFLstPin;
	this->numFLstGen = numFLstGen;
	this->numFLstPrt = numFLstPrt;
	this->numFLstSig = numFLstSig;
	this->numFLstPrc = numFLstPrc;
	this->numFLstFst = numFLstFst;
	this->numFLstVar = numFLstVar;

	mask = {NUMFLSTMOD, NUMFLSTVEC, NUMFLSTVIT, NUMFLSTCMD, NUMFLSTERR, NUMFLSTPPH, NUMFLSTBNK, NUMFLSTPIN, NUMFLSTGEN, NUMFLSTPRT, NUMFLSTSIG, NUMFLSTPRC, NUMFLSTFST, NUMFLSTVAR};
};

bool PnlWdbeNavDescr::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWdbeNavDescr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWdbeNavDescr";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstMod", numFLstMod)) add(NUMFLSTMOD);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstVec", numFLstVec)) add(NUMFLSTVEC);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstVit", numFLstVit)) add(NUMFLSTVIT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstCmd", numFLstCmd)) add(NUMFLSTCMD);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstErr", numFLstErr)) add(NUMFLSTERR);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstPph", numFLstPph)) add(NUMFLSTPPH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstBnk", numFLstBnk)) add(NUMFLSTBNK);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstPin", numFLstPin)) add(NUMFLSTPIN);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstGen", numFLstGen)) add(NUMFLSTGEN);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstPrt", numFLstPrt)) add(NUMFLSTPRT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstSig", numFLstSig)) add(NUMFLSTSIG);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstPrc", numFLstPrc)) add(NUMFLSTPRC);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstFst", numFLstFst)) add(NUMFLSTFST);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstVar", numFLstVar)) add(NUMFLSTVAR);
	};

	return basefound;
};

void PnlWdbeNavDescr::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbeNavDescr";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWdbeNavDescr";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstMod", numFLstMod);
		writeUintAttr(wr, itemtag, "sref", "numFLstVec", numFLstVec);
		writeUintAttr(wr, itemtag, "sref", "numFLstVit", numFLstVit);
		writeUintAttr(wr, itemtag, "sref", "numFLstCmd", numFLstCmd);
		writeUintAttr(wr, itemtag, "sref", "numFLstErr", numFLstErr);
		writeUintAttr(wr, itemtag, "sref", "numFLstPph", numFLstPph);
		writeUintAttr(wr, itemtag, "sref", "numFLstBnk", numFLstBnk);
		writeUintAttr(wr, itemtag, "sref", "numFLstPin", numFLstPin);
		writeUintAttr(wr, itemtag, "sref", "numFLstGen", numFLstGen);
		writeUintAttr(wr, itemtag, "sref", "numFLstPrt", numFLstPrt);
		writeUintAttr(wr, itemtag, "sref", "numFLstSig", numFLstSig);
		writeUintAttr(wr, itemtag, "sref", "numFLstPrc", numFLstPrc);
		writeUintAttr(wr, itemtag, "sref", "numFLstFst", numFLstFst);
		writeUintAttr(wr, itemtag, "sref", "numFLstVar", numFLstVar);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeNavDescr::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstMod == comp->numFLstMod) insert(items, NUMFLSTMOD);
	if (numFLstVec == comp->numFLstVec) insert(items, NUMFLSTVEC);
	if (numFLstVit == comp->numFLstVit) insert(items, NUMFLSTVIT);
	if (numFLstCmd == comp->numFLstCmd) insert(items, NUMFLSTCMD);
	if (numFLstErr == comp->numFLstErr) insert(items, NUMFLSTERR);
	if (numFLstPph == comp->numFLstPph) insert(items, NUMFLSTPPH);
	if (numFLstBnk == comp->numFLstBnk) insert(items, NUMFLSTBNK);
	if (numFLstPin == comp->numFLstPin) insert(items, NUMFLSTPIN);
	if (numFLstGen == comp->numFLstGen) insert(items, NUMFLSTGEN);
	if (numFLstPrt == comp->numFLstPrt) insert(items, NUMFLSTPRT);
	if (numFLstSig == comp->numFLstSig) insert(items, NUMFLSTSIG);
	if (numFLstPrc == comp->numFLstPrc) insert(items, NUMFLSTPRC);
	if (numFLstFst == comp->numFLstFst) insert(items, NUMFLSTFST);
	if (numFLstVar == comp->numFLstVar) insert(items, NUMFLSTVAR);

	return(items);
};

set<uint> PnlWdbeNavDescr::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTMOD, NUMFLSTVEC, NUMFLSTVIT, NUMFLSTCMD, NUMFLSTERR, NUMFLSTPPH, NUMFLSTBNK, NUMFLSTPIN, NUMFLSTGEN, NUMFLSTPRT, NUMFLSTSIG, NUMFLSTPRC, NUMFLSTFST, NUMFLSTVAR};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeNavDescr::StatApp
 ******************************************************************************/

void PnlWdbeNavDescr::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWdbeVExpstate
			, const bool LstModAlt
			, const bool LstVecAlt
			, const bool LstVitAlt
			, const bool LstCmdAlt
			, const bool LstErrAlt
			, const bool LstPphAlt
			, const bool LstBnkAlt
			, const bool LstPinAlt
			, const bool LstGenAlt
			, const bool LstPrtAlt
			, const bool LstSigAlt
			, const bool LstPrcAlt
			, const bool LstFstAlt
			, const bool LstVarAlt
			, const uint LstModNumFirstdisp
			, const uint LstVecNumFirstdisp
			, const uint LstVitNumFirstdisp
			, const uint LstCmdNumFirstdisp
			, const uint LstErrNumFirstdisp
			, const uint LstPphNumFirstdisp
			, const uint LstBnkNumFirstdisp
			, const uint LstPinNumFirstdisp
			, const uint LstGenNumFirstdisp
			, const uint LstPrtNumFirstdisp
			, const uint LstSigNumFirstdisp
			, const uint LstPrcNumFirstdisp
			, const uint LstFstNumFirstdisp
			, const uint LstVarNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeNavDescr";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWdbeNavDescr";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWdbeVExpstate", VecWdbeVExpstate::getSref(ixWdbeVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstModAlt", LstModAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstVecAlt", LstVecAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstVitAlt", LstVitAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstCmdAlt", LstCmdAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstErrAlt", LstErrAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstPphAlt", LstPphAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstBnkAlt", LstBnkAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstPinAlt", LstPinAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstGenAlt", LstGenAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstPrtAlt", LstPrtAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstSigAlt", LstSigAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstPrcAlt", LstPrcAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstFstAlt", LstFstAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstVarAlt", LstVarAlt);
		writeUintAttr(wr, itemtag, "sref", "LstModNumFirstdisp", LstModNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstVecNumFirstdisp", LstVecNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstVitNumFirstdisp", LstVitNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstCmdNumFirstdisp", LstCmdNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstErrNumFirstdisp", LstErrNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstPphNumFirstdisp", LstPphNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstBnkNumFirstdisp", LstBnkNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstPinNumFirstdisp", LstPinNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstGenNumFirstdisp", LstGenNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstPrtNumFirstdisp", LstPrtNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstSigNumFirstdisp", LstSigNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstPrcNumFirstdisp", LstPrcNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstFstNumFirstdisp", LstFstNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstVarNumFirstdisp", LstVarNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeNavDescr::StatShr
 ******************************************************************************/

PnlWdbeNavDescr::StatShr::StatShr(
			const bool LstModAvail
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
			, const bool LstPphAvail
			, const bool ButPphViewActive
			, const bool ButPphNewcrdActive
			, const bool LstBnkAvail
			, const bool ButBnkViewActive
			, const bool ButBnkNewcrdActive
			, const bool LstPinAvail
			, const bool ButPinViewActive
			, const bool ButPinNewcrdActive
			, const bool LstGenAvail
			, const bool ButGenViewActive
			, const bool LstPrtAvail
			, const bool ButPrtViewActive
			, const bool LstSigAvail
			, const bool ButSigViewActive
			, const bool LstPrcAvail
			, const bool ButPrcViewActive
			, const bool LstFstAvail
			, const bool ButFstViewActive
			, const bool LstVarAvail
			, const bool ButVarViewActive
		) :
			Block()
		{
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
	this->LstPphAvail = LstPphAvail;
	this->ButPphViewActive = ButPphViewActive;
	this->ButPphNewcrdActive = ButPphNewcrdActive;
	this->LstBnkAvail = LstBnkAvail;
	this->ButBnkViewActive = ButBnkViewActive;
	this->ButBnkNewcrdActive = ButBnkNewcrdActive;
	this->LstPinAvail = LstPinAvail;
	this->ButPinViewActive = ButPinViewActive;
	this->ButPinNewcrdActive = ButPinNewcrdActive;
	this->LstGenAvail = LstGenAvail;
	this->ButGenViewActive = ButGenViewActive;
	this->LstPrtAvail = LstPrtAvail;
	this->ButPrtViewActive = ButPrtViewActive;
	this->LstSigAvail = LstSigAvail;
	this->ButSigViewActive = ButSigViewActive;
	this->LstPrcAvail = LstPrcAvail;
	this->ButPrcViewActive = ButPrcViewActive;
	this->LstFstAvail = LstFstAvail;
	this->ButFstViewActive = ButFstViewActive;
	this->LstVarAvail = LstVarAvail;
	this->ButVarViewActive = ButVarViewActive;

	mask = {LSTMODAVAIL, BUTMODVIEWACTIVE, BUTMODNEWCRDACTIVE, LSTVECAVAIL, BUTVECVIEWACTIVE, BUTVECNEWCRDACTIVE, LSTVITAVAIL, BUTVITVIEWACTIVE, LSTCMDAVAIL, BUTCMDVIEWACTIVE, BUTCMDNEWCRDACTIVE, LSTERRAVAIL, BUTERRVIEWACTIVE, BUTERRNEWCRDACTIVE, LSTPPHAVAIL, BUTPPHVIEWACTIVE, BUTPPHNEWCRDACTIVE, LSTBNKAVAIL, BUTBNKVIEWACTIVE, BUTBNKNEWCRDACTIVE, LSTPINAVAIL, BUTPINVIEWACTIVE, BUTPINNEWCRDACTIVE, LSTGENAVAIL, BUTGENVIEWACTIVE, LSTPRTAVAIL, BUTPRTVIEWACTIVE, LSTSIGAVAIL, BUTSIGVIEWACTIVE, LSTPRCAVAIL, BUTPRCVIEWACTIVE, LSTFSTAVAIL, BUTFSTVIEWACTIVE, LSTVARAVAIL, BUTVARVIEWACTIVE};
};

void PnlWdbeNavDescr::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeNavDescr";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWdbeNavDescr";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
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
		writeBoolAttr(wr, itemtag, "sref", "LstPphAvail", LstPphAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButPphViewActive", ButPphViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButPphNewcrdActive", ButPphNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstBnkAvail", LstBnkAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButBnkViewActive", ButBnkViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButBnkNewcrdActive", ButBnkNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstPinAvail", LstPinAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButPinViewActive", ButPinViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButPinNewcrdActive", ButPinNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstGenAvail", LstGenAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButGenViewActive", ButGenViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstPrtAvail", LstPrtAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButPrtViewActive", ButPrtViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstSigAvail", LstSigAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSigViewActive", ButSigViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstPrcAvail", LstPrcAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButPrcViewActive", ButPrcViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstFstAvail", LstFstAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButFstViewActive", ButFstViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstVarAvail", LstVarAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButVarViewActive", ButVarViewActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeNavDescr::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

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
	if (LstPphAvail == comp->LstPphAvail) insert(items, LSTPPHAVAIL);
	if (ButPphViewActive == comp->ButPphViewActive) insert(items, BUTPPHVIEWACTIVE);
	if (ButPphNewcrdActive == comp->ButPphNewcrdActive) insert(items, BUTPPHNEWCRDACTIVE);
	if (LstBnkAvail == comp->LstBnkAvail) insert(items, LSTBNKAVAIL);
	if (ButBnkViewActive == comp->ButBnkViewActive) insert(items, BUTBNKVIEWACTIVE);
	if (ButBnkNewcrdActive == comp->ButBnkNewcrdActive) insert(items, BUTBNKNEWCRDACTIVE);
	if (LstPinAvail == comp->LstPinAvail) insert(items, LSTPINAVAIL);
	if (ButPinViewActive == comp->ButPinViewActive) insert(items, BUTPINVIEWACTIVE);
	if (ButPinNewcrdActive == comp->ButPinNewcrdActive) insert(items, BUTPINNEWCRDACTIVE);
	if (LstGenAvail == comp->LstGenAvail) insert(items, LSTGENAVAIL);
	if (ButGenViewActive == comp->ButGenViewActive) insert(items, BUTGENVIEWACTIVE);
	if (LstPrtAvail == comp->LstPrtAvail) insert(items, LSTPRTAVAIL);
	if (ButPrtViewActive == comp->ButPrtViewActive) insert(items, BUTPRTVIEWACTIVE);
	if (LstSigAvail == comp->LstSigAvail) insert(items, LSTSIGAVAIL);
	if (ButSigViewActive == comp->ButSigViewActive) insert(items, BUTSIGVIEWACTIVE);
	if (LstPrcAvail == comp->LstPrcAvail) insert(items, LSTPRCAVAIL);
	if (ButPrcViewActive == comp->ButPrcViewActive) insert(items, BUTPRCVIEWACTIVE);
	if (LstFstAvail == comp->LstFstAvail) insert(items, LSTFSTAVAIL);
	if (ButFstViewActive == comp->ButFstViewActive) insert(items, BUTFSTVIEWACTIVE);
	if (LstVarAvail == comp->LstVarAvail) insert(items, LSTVARAVAIL);
	if (ButVarViewActive == comp->ButVarViewActive) insert(items, BUTVARVIEWACTIVE);

	return(items);
};

set<uint> PnlWdbeNavDescr::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTMODAVAIL, BUTMODVIEWACTIVE, BUTMODNEWCRDACTIVE, LSTVECAVAIL, BUTVECVIEWACTIVE, BUTVECNEWCRDACTIVE, LSTVITAVAIL, BUTVITVIEWACTIVE, LSTCMDAVAIL, BUTCMDVIEWACTIVE, BUTCMDNEWCRDACTIVE, LSTERRAVAIL, BUTERRVIEWACTIVE, BUTERRNEWCRDACTIVE, LSTPPHAVAIL, BUTPPHVIEWACTIVE, BUTPPHNEWCRDACTIVE, LSTBNKAVAIL, BUTBNKVIEWACTIVE, BUTBNKNEWCRDACTIVE, LSTPINAVAIL, BUTPINVIEWACTIVE, BUTPINNEWCRDACTIVE, LSTGENAVAIL, BUTGENVIEWACTIVE, LSTPRTAVAIL, BUTPRTVIEWACTIVE, LSTSIGAVAIL, BUTSIGVIEWACTIVE, LSTPRCAVAIL, BUTPRCVIEWACTIVE, LSTFSTAVAIL, BUTFSTVIEWACTIVE, LSTVARAVAIL, BUTVARVIEWACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeNavDescr::Tag
 ******************************************************************************/

void PnlWdbeNavDescr::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWdbeNavDescr";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWdbeNavDescr";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Device/core description module");
			writeStringAttr(wr, itemtag, "sref", "CptMod", "modules");
			writeStringAttr(wr, itemtag, "sref", "CptVec", "vectors");
			writeStringAttr(wr, itemtag, "sref", "CptVit", "vector items");
			writeStringAttr(wr, itemtag, "sref", "CptCmd", "commands");
			writeStringAttr(wr, itemtag, "sref", "CptErr", "errors");
			writeStringAttr(wr, itemtag, "sref", "CptPph", "peripherals");
			writeStringAttr(wr, itemtag, "sref", "CptBnk", "I/O banks");
			writeStringAttr(wr, itemtag, "sref", "CptPin", "pins");
			writeStringAttr(wr, itemtag, "sref", "CptGen", "generics");
			writeStringAttr(wr, itemtag, "sref", "CptPrt", "ports");
			writeStringAttr(wr, itemtag, "sref", "CptSig", "signals");
			writeStringAttr(wr, itemtag, "sref", "CptPrc", "processes");
			writeStringAttr(wr, itemtag, "sref", "CptFst", "FSM states");
			writeStringAttr(wr, itemtag, "sref", "CptVar", "variables");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeNavDescr::DpchAppData
 ******************************************************************************/

PnlWdbeNavDescr::DpchAppData::DpchAppData() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBENAVDESCRDATA)
		{
};

string PnlWdbeNavDescr::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavDescr::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeNavDescrData");
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
 class PnlWdbeNavDescr::DpchAppDo
 ******************************************************************************/

PnlWdbeNavDescr::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBENAVDESCRDO)
		{
	ixVDo = 0;
};

string PnlWdbeNavDescr::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavDescr::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeNavDescrDo");
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
 class PnlWdbeNavDescr::DpchEngData
 ******************************************************************************/

PnlWdbeNavDescr::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, Feed* feedFLstBnk
			, Feed* feedFLstCmd
			, Feed* feedFLstErr
			, Feed* feedFLstFst
			, Feed* feedFLstGen
			, Feed* feedFLstMod
			, Feed* feedFLstPin
			, Feed* feedFLstPph
			, Feed* feedFLstPrc
			, Feed* feedFLstPrt
			, Feed* feedFLstSig
			, Feed* feedFLstVar
			, Feed* feedFLstVec
			, Feed* feedFLstVit
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBENAVDESCRDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, FEEDFLSTBNK, FEEDFLSTCMD, FEEDFLSTERR, FEEDFLSTFST, FEEDFLSTGEN, FEEDFLSTMOD, FEEDFLSTPIN, FEEDFLSTPPH, FEEDFLSTPRC, FEEDFLSTPRT, FEEDFLSTSIG, FEEDFLSTVAR, FEEDFLSTVEC, FEEDFLSTVIT, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, FEEDFLSTBNK) && feedFLstBnk) this->feedFLstBnk = *feedFLstBnk;
	if (find(this->mask, FEEDFLSTCMD) && feedFLstCmd) this->feedFLstCmd = *feedFLstCmd;
	if (find(this->mask, FEEDFLSTERR) && feedFLstErr) this->feedFLstErr = *feedFLstErr;
	if (find(this->mask, FEEDFLSTFST) && feedFLstFst) this->feedFLstFst = *feedFLstFst;
	if (find(this->mask, FEEDFLSTGEN) && feedFLstGen) this->feedFLstGen = *feedFLstGen;
	if (find(this->mask, FEEDFLSTMOD) && feedFLstMod) this->feedFLstMod = *feedFLstMod;
	if (find(this->mask, FEEDFLSTPIN) && feedFLstPin) this->feedFLstPin = *feedFLstPin;
	if (find(this->mask, FEEDFLSTPPH) && feedFLstPph) this->feedFLstPph = *feedFLstPph;
	if (find(this->mask, FEEDFLSTPRC) && feedFLstPrc) this->feedFLstPrc = *feedFLstPrc;
	if (find(this->mask, FEEDFLSTPRT) && feedFLstPrt) this->feedFLstPrt = *feedFLstPrt;
	if (find(this->mask, FEEDFLSTSIG) && feedFLstSig) this->feedFLstSig = *feedFLstSig;
	if (find(this->mask, FEEDFLSTVAR) && feedFLstVar) this->feedFLstVar = *feedFLstVar;
	if (find(this->mask, FEEDFLSTVEC) && feedFLstVec) this->feedFLstVec = *feedFLstVec;
	if (find(this->mask, FEEDFLSTVIT) && feedFLstVit) this->feedFLstVit = *feedFLstVit;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWdbeNavDescr::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTBNK)) ss.push_back("feedFLstBnk");
	if (has(FEEDFLSTCMD)) ss.push_back("feedFLstCmd");
	if (has(FEEDFLSTERR)) ss.push_back("feedFLstErr");
	if (has(FEEDFLSTFST)) ss.push_back("feedFLstFst");
	if (has(FEEDFLSTGEN)) ss.push_back("feedFLstGen");
	if (has(FEEDFLSTMOD)) ss.push_back("feedFLstMod");
	if (has(FEEDFLSTPIN)) ss.push_back("feedFLstPin");
	if (has(FEEDFLSTPPH)) ss.push_back("feedFLstPph");
	if (has(FEEDFLSTPRC)) ss.push_back("feedFLstPrc");
	if (has(FEEDFLSTPRT)) ss.push_back("feedFLstPrt");
	if (has(FEEDFLSTSIG)) ss.push_back("feedFLstSig");
	if (has(FEEDFLSTVAR)) ss.push_back("feedFLstVar");
	if (has(FEEDFLSTVEC)) ss.push_back("feedFLstVec");
	if (has(FEEDFLSTVIT)) ss.push_back("feedFLstVit");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavDescr::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(FEEDFLSTBNK)) {feedFLstBnk = src->feedFLstBnk; add(FEEDFLSTBNK);};
	if (src->has(FEEDFLSTCMD)) {feedFLstCmd = src->feedFLstCmd; add(FEEDFLSTCMD);};
	if (src->has(FEEDFLSTERR)) {feedFLstErr = src->feedFLstErr; add(FEEDFLSTERR);};
	if (src->has(FEEDFLSTFST)) {feedFLstFst = src->feedFLstFst; add(FEEDFLSTFST);};
	if (src->has(FEEDFLSTGEN)) {feedFLstGen = src->feedFLstGen; add(FEEDFLSTGEN);};
	if (src->has(FEEDFLSTMOD)) {feedFLstMod = src->feedFLstMod; add(FEEDFLSTMOD);};
	if (src->has(FEEDFLSTPIN)) {feedFLstPin = src->feedFLstPin; add(FEEDFLSTPIN);};
	if (src->has(FEEDFLSTPPH)) {feedFLstPph = src->feedFLstPph; add(FEEDFLSTPPH);};
	if (src->has(FEEDFLSTPRC)) {feedFLstPrc = src->feedFLstPrc; add(FEEDFLSTPRC);};
	if (src->has(FEEDFLSTPRT)) {feedFLstPrt = src->feedFLstPrt; add(FEEDFLSTPRT);};
	if (src->has(FEEDFLSTSIG)) {feedFLstSig = src->feedFLstSig; add(FEEDFLSTSIG);};
	if (src->has(FEEDFLSTVAR)) {feedFLstVar = src->feedFLstVar; add(FEEDFLSTVAR);};
	if (src->has(FEEDFLSTVEC)) {feedFLstVec = src->feedFLstVec; add(FEEDFLSTVEC);};
	if (src->has(FEEDFLSTVIT)) {feedFLstVit = src->feedFLstVit; add(FEEDFLSTVIT);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWdbeNavDescr::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWdbeNavDescrData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(FEEDFLSTBNK)) feedFLstBnk.writeXML(wr);
		if (has(FEEDFLSTCMD)) feedFLstCmd.writeXML(wr);
		if (has(FEEDFLSTERR)) feedFLstErr.writeXML(wr);
		if (has(FEEDFLSTFST)) feedFLstFst.writeXML(wr);
		if (has(FEEDFLSTGEN)) feedFLstGen.writeXML(wr);
		if (has(FEEDFLSTMOD)) feedFLstMod.writeXML(wr);
		if (has(FEEDFLSTPIN)) feedFLstPin.writeXML(wr);
		if (has(FEEDFLSTPPH)) feedFLstPph.writeXML(wr);
		if (has(FEEDFLSTPRC)) feedFLstPrc.writeXML(wr);
		if (has(FEEDFLSTPRT)) feedFLstPrt.writeXML(wr);
		if (has(FEEDFLSTSIG)) feedFLstSig.writeXML(wr);
		if (has(FEEDFLSTVAR)) feedFLstVar.writeXML(wr);
		if (has(FEEDFLSTVEC)) feedFLstVec.writeXML(wr);
		if (has(FEEDFLSTVIT)) feedFLstVit.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};



