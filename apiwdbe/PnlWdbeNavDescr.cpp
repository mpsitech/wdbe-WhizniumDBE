/**
	* \file PnlWdbeNavDescr.cpp
	* API code for job PnlWdbeNavDescr (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "PnlWdbeNavDescr.h"

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

PnlWdbeNavDescr::StatApp::StatApp(
			const uint ixWdbeVExpstate
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
		) :
			Block()
		{
	this->ixWdbeVExpstate = ixWdbeVExpstate;
	this->LstModAlt = LstModAlt;
	this->LstVecAlt = LstVecAlt;
	this->LstVitAlt = LstVitAlt;
	this->LstCmdAlt = LstCmdAlt;
	this->LstErrAlt = LstErrAlt;
	this->LstPphAlt = LstPphAlt;
	this->LstBnkAlt = LstBnkAlt;
	this->LstPinAlt = LstPinAlt;
	this->LstGenAlt = LstGenAlt;
	this->LstPrtAlt = LstPrtAlt;
	this->LstSigAlt = LstSigAlt;
	this->LstPrcAlt = LstPrcAlt;
	this->LstFstAlt = LstFstAlt;
	this->LstVarAlt = LstVarAlt;
	this->LstModNumFirstdisp = LstModNumFirstdisp;
	this->LstVecNumFirstdisp = LstVecNumFirstdisp;
	this->LstVitNumFirstdisp = LstVitNumFirstdisp;
	this->LstCmdNumFirstdisp = LstCmdNumFirstdisp;
	this->LstErrNumFirstdisp = LstErrNumFirstdisp;
	this->LstPphNumFirstdisp = LstPphNumFirstdisp;
	this->LstBnkNumFirstdisp = LstBnkNumFirstdisp;
	this->LstPinNumFirstdisp = LstPinNumFirstdisp;
	this->LstGenNumFirstdisp = LstGenNumFirstdisp;
	this->LstPrtNumFirstdisp = LstPrtNumFirstdisp;
	this->LstSigNumFirstdisp = LstSigNumFirstdisp;
	this->LstPrcNumFirstdisp = LstPrcNumFirstdisp;
	this->LstFstNumFirstdisp = LstFstNumFirstdisp;
	this->LstVarNumFirstdisp = LstVarNumFirstdisp;

	mask = {IXWDBEVEXPSTATE, LSTMODALT, LSTVECALT, LSTVITALT, LSTCMDALT, LSTERRALT, LSTPPHALT, LSTBNKALT, LSTPINALT, LSTGENALT, LSTPRTALT, LSTSIGALT, LSTPRCALT, LSTFSTALT, LSTVARALT, LSTMODNUMFIRSTDISP, LSTVECNUMFIRSTDISP, LSTVITNUMFIRSTDISP, LSTCMDNUMFIRSTDISP, LSTERRNUMFIRSTDISP, LSTPPHNUMFIRSTDISP, LSTBNKNUMFIRSTDISP, LSTPINNUMFIRSTDISP, LSTGENNUMFIRSTDISP, LSTPRTNUMFIRSTDISP, LSTSIGNUMFIRSTDISP, LSTPRCNUMFIRSTDISP, LSTFSTNUMFIRSTDISP, LSTVARNUMFIRSTDISP};
};

bool PnlWdbeNavDescr::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWdbeVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWdbeNavDescr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWdbeNavDescr";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", srefIxWdbeVExpstate)) {
			ixWdbeVExpstate = VecWdbeVExpstate::getIx(srefIxWdbeVExpstate);
			add(IXWDBEVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstModAlt", LstModAlt)) add(LSTMODALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstVecAlt", LstVecAlt)) add(LSTVECALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstVitAlt", LstVitAlt)) add(LSTVITALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCmdAlt", LstCmdAlt)) add(LSTCMDALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstErrAlt", LstErrAlt)) add(LSTERRALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPphAlt", LstPphAlt)) add(LSTPPHALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstBnkAlt", LstBnkAlt)) add(LSTBNKALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPinAlt", LstPinAlt)) add(LSTPINALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstGenAlt", LstGenAlt)) add(LSTGENALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrtAlt", LstPrtAlt)) add(LSTPRTALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSigAlt", LstSigAlt)) add(LSTSIGALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrcAlt", LstPrcAlt)) add(LSTPRCALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFstAlt", LstFstAlt)) add(LSTFSTALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstVarAlt", LstVarAlt)) add(LSTVARALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstModNumFirstdisp", LstModNumFirstdisp)) add(LSTMODNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstVecNumFirstdisp", LstVecNumFirstdisp)) add(LSTVECNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstVitNumFirstdisp", LstVitNumFirstdisp)) add(LSTVITNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCmdNumFirstdisp", LstCmdNumFirstdisp)) add(LSTCMDNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstErrNumFirstdisp", LstErrNumFirstdisp)) add(LSTERRNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPphNumFirstdisp", LstPphNumFirstdisp)) add(LSTPPHNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstBnkNumFirstdisp", LstBnkNumFirstdisp)) add(LSTBNKNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPinNumFirstdisp", LstPinNumFirstdisp)) add(LSTPINNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstGenNumFirstdisp", LstGenNumFirstdisp)) add(LSTGENNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrtNumFirstdisp", LstPrtNumFirstdisp)) add(LSTPRTNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSigNumFirstdisp", LstSigNumFirstdisp)) add(LSTSIGNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrcNumFirstdisp", LstPrcNumFirstdisp)) add(LSTPRCNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFstNumFirstdisp", LstFstNumFirstdisp)) add(LSTFSTNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstVarNumFirstdisp", LstVarNumFirstdisp)) add(LSTVARNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlWdbeNavDescr::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWdbeVExpstate == comp->ixWdbeVExpstate) insert(items, IXWDBEVEXPSTATE);
	if (LstModAlt == comp->LstModAlt) insert(items, LSTMODALT);
	if (LstVecAlt == comp->LstVecAlt) insert(items, LSTVECALT);
	if (LstVitAlt == comp->LstVitAlt) insert(items, LSTVITALT);
	if (LstCmdAlt == comp->LstCmdAlt) insert(items, LSTCMDALT);
	if (LstErrAlt == comp->LstErrAlt) insert(items, LSTERRALT);
	if (LstPphAlt == comp->LstPphAlt) insert(items, LSTPPHALT);
	if (LstBnkAlt == comp->LstBnkAlt) insert(items, LSTBNKALT);
	if (LstPinAlt == comp->LstPinAlt) insert(items, LSTPINALT);
	if (LstGenAlt == comp->LstGenAlt) insert(items, LSTGENALT);
	if (LstPrtAlt == comp->LstPrtAlt) insert(items, LSTPRTALT);
	if (LstSigAlt == comp->LstSigAlt) insert(items, LSTSIGALT);
	if (LstPrcAlt == comp->LstPrcAlt) insert(items, LSTPRCALT);
	if (LstFstAlt == comp->LstFstAlt) insert(items, LSTFSTALT);
	if (LstVarAlt == comp->LstVarAlt) insert(items, LSTVARALT);
	if (LstModNumFirstdisp == comp->LstModNumFirstdisp) insert(items, LSTMODNUMFIRSTDISP);
	if (LstVecNumFirstdisp == comp->LstVecNumFirstdisp) insert(items, LSTVECNUMFIRSTDISP);
	if (LstVitNumFirstdisp == comp->LstVitNumFirstdisp) insert(items, LSTVITNUMFIRSTDISP);
	if (LstCmdNumFirstdisp == comp->LstCmdNumFirstdisp) insert(items, LSTCMDNUMFIRSTDISP);
	if (LstErrNumFirstdisp == comp->LstErrNumFirstdisp) insert(items, LSTERRNUMFIRSTDISP);
	if (LstPphNumFirstdisp == comp->LstPphNumFirstdisp) insert(items, LSTPPHNUMFIRSTDISP);
	if (LstBnkNumFirstdisp == comp->LstBnkNumFirstdisp) insert(items, LSTBNKNUMFIRSTDISP);
	if (LstPinNumFirstdisp == comp->LstPinNumFirstdisp) insert(items, LSTPINNUMFIRSTDISP);
	if (LstGenNumFirstdisp == comp->LstGenNumFirstdisp) insert(items, LSTGENNUMFIRSTDISP);
	if (LstPrtNumFirstdisp == comp->LstPrtNumFirstdisp) insert(items, LSTPRTNUMFIRSTDISP);
	if (LstSigNumFirstdisp == comp->LstSigNumFirstdisp) insert(items, LSTSIGNUMFIRSTDISP);
	if (LstPrcNumFirstdisp == comp->LstPrcNumFirstdisp) insert(items, LSTPRCNUMFIRSTDISP);
	if (LstFstNumFirstdisp == comp->LstFstNumFirstdisp) insert(items, LSTFSTNUMFIRSTDISP);
	if (LstVarNumFirstdisp == comp->LstVarNumFirstdisp) insert(items, LSTVARNUMFIRSTDISP);

	return(items);
};

set<uint> PnlWdbeNavDescr::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWDBEVEXPSTATE, LSTMODALT, LSTVECALT, LSTVITALT, LSTCMDALT, LSTERRALT, LSTPPHALT, LSTBNKALT, LSTPINALT, LSTGENALT, LSTPRTALT, LSTSIGALT, LSTPRCALT, LSTFSTALT, LSTVARALT, LSTMODNUMFIRSTDISP, LSTVECNUMFIRSTDISP, LSTVITNUMFIRSTDISP, LSTCMDNUMFIRSTDISP, LSTERRNUMFIRSTDISP, LSTPPHNUMFIRSTDISP, LSTBNKNUMFIRSTDISP, LSTPINNUMFIRSTDISP, LSTGENNUMFIRSTDISP, LSTPRTNUMFIRSTDISP, LSTSIGNUMFIRSTDISP, LSTPRCNUMFIRSTDISP, LSTFSTNUMFIRSTDISP, LSTVARNUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
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

bool PnlWdbeNavDescr::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWdbeNavDescr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWdbeNavDescr";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstModAvail", LstModAvail)) add(LSTMODAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButModViewActive", ButModViewActive)) add(BUTMODVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButModNewcrdActive", ButModNewcrdActive)) add(BUTMODNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstVecAvail", LstVecAvail)) add(LSTVECAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButVecViewActive", ButVecViewActive)) add(BUTVECVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButVecNewcrdActive", ButVecNewcrdActive)) add(BUTVECNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstVitAvail", LstVitAvail)) add(LSTVITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButVitViewActive", ButVitViewActive)) add(BUTVITVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCmdAvail", LstCmdAvail)) add(LSTCMDAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCmdViewActive", ButCmdViewActive)) add(BUTCMDVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCmdNewcrdActive", ButCmdNewcrdActive)) add(BUTCMDNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstErrAvail", LstErrAvail)) add(LSTERRAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButErrViewActive", ButErrViewActive)) add(BUTERRVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButErrNewcrdActive", ButErrNewcrdActive)) add(BUTERRNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPphAvail", LstPphAvail)) add(LSTPPHAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPphViewActive", ButPphViewActive)) add(BUTPPHVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPphNewcrdActive", ButPphNewcrdActive)) add(BUTPPHNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstBnkAvail", LstBnkAvail)) add(LSTBNKAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButBnkViewActive", ButBnkViewActive)) add(BUTBNKVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButBnkNewcrdActive", ButBnkNewcrdActive)) add(BUTBNKNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPinAvail", LstPinAvail)) add(LSTPINAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPinViewActive", ButPinViewActive)) add(BUTPINVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPinNewcrdActive", ButPinNewcrdActive)) add(BUTPINNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstGenAvail", LstGenAvail)) add(LSTGENAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButGenViewActive", ButGenViewActive)) add(BUTGENVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrtAvail", LstPrtAvail)) add(LSTPRTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPrtViewActive", ButPrtViewActive)) add(BUTPRTVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSigAvail", LstSigAvail)) add(LSTSIGAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSigViewActive", ButSigViewActive)) add(BUTSIGVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrcAvail", LstPrcAvail)) add(LSTPRCAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPrcViewActive", ButPrcViewActive)) add(BUTPRCVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFstAvail", LstFstAvail)) add(LSTFSTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButFstViewActive", ButFstViewActive)) add(BUTFSTVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstVarAvail", LstVarAvail)) add(LSTVARAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButVarViewActive", ButVarViewActive)) add(BUTVARVIEWACTIVE);
	};

	return basefound;
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

PnlWdbeNavDescr::Tag::Tag(
			const string& Cpt
			, const string& CptMod
			, const string& CptVec
			, const string& CptVit
			, const string& CptCmd
			, const string& CptErr
			, const string& CptPph
			, const string& CptBnk
			, const string& CptPin
			, const string& CptGen
			, const string& CptPrt
			, const string& CptSig
			, const string& CptPrc
			, const string& CptFst
			, const string& CptVar
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptMod = CptMod;
	this->CptVec = CptVec;
	this->CptVit = CptVit;
	this->CptCmd = CptCmd;
	this->CptErr = CptErr;
	this->CptPph = CptPph;
	this->CptBnk = CptBnk;
	this->CptPin = CptPin;
	this->CptGen = CptGen;
	this->CptPrt = CptPrt;
	this->CptSig = CptSig;
	this->CptPrc = CptPrc;
	this->CptFst = CptFst;
	this->CptVar = CptVar;

	mask = {CPT, CPTMOD, CPTVEC, CPTVIT, CPTCMD, CPTERR, CPTPPH, CPTBNK, CPTPIN, CPTGEN, CPTPRT, CPTSIG, CPTPRC, CPTFST, CPTVAR};
};

bool PnlWdbeNavDescr::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWdbeNavDescr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWdbeNavDescr";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptMod", CptMod)) add(CPTMOD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVec", CptVec)) add(CPTVEC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVit", CptVit)) add(CPTVIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCmd", CptCmd)) add(CPTCMD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptErr", CptErr)) add(CPTERR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPph", CptPph)) add(CPTPPH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptBnk", CptBnk)) add(CPTBNK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPin", CptPin)) add(CPTPIN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptGen", CptGen)) add(CPTGEN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrt", CptPrt)) add(CPTPRT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSig", CptSig)) add(CPTSIG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrc", CptPrc)) add(CPTPRC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFst", CptFst)) add(CPTFST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVar", CptVar)) add(CPTVAR);
	};

	return basefound;
};

/******************************************************************************
 class PnlWdbeNavDescr::DpchAppData
 ******************************************************************************/

PnlWdbeNavDescr::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBENAVDESCRDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWdbeNavDescr::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavDescr::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeNavDescrData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeNavDescr::DpchAppDo
 ******************************************************************************/

PnlWdbeNavDescr::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBENAVDESCRDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWdbeNavDescr::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavDescr::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeNavDescrDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeNavDescr::DpchEngData
 ******************************************************************************/

PnlWdbeNavDescr::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBENAVDESCRDATA)
		{
	feedFLstBnk.tag = "FeedFLstBnk";
	feedFLstCmd.tag = "FeedFLstCmd";
	feedFLstErr.tag = "FeedFLstErr";
	feedFLstFst.tag = "FeedFLstFst";
	feedFLstGen.tag = "FeedFLstGen";
	feedFLstMod.tag = "FeedFLstMod";
	feedFLstPin.tag = "FeedFLstPin";
	feedFLstPph.tag = "FeedFLstPph";
	feedFLstPrc.tag = "FeedFLstPrc";
	feedFLstPrt.tag = "FeedFLstPrt";
	feedFLstSig.tag = "FeedFLstSig";
	feedFLstVar.tag = "FeedFLstVar";
	feedFLstVec.tag = "FeedFLstVec";
	feedFLstVit.tag = "FeedFLstVit";
};

string PnlWdbeNavDescr::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
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

void PnlWdbeNavDescr::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWdbeNavDescrData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (feedFLstBnk.readXML(docctx, basexpath, true)) add(FEEDFLSTBNK);
		if (feedFLstCmd.readXML(docctx, basexpath, true)) add(FEEDFLSTCMD);
		if (feedFLstErr.readXML(docctx, basexpath, true)) add(FEEDFLSTERR);
		if (feedFLstFst.readXML(docctx, basexpath, true)) add(FEEDFLSTFST);
		if (feedFLstGen.readXML(docctx, basexpath, true)) add(FEEDFLSTGEN);
		if (feedFLstMod.readXML(docctx, basexpath, true)) add(FEEDFLSTMOD);
		if (feedFLstPin.readXML(docctx, basexpath, true)) add(FEEDFLSTPIN);
		if (feedFLstPph.readXML(docctx, basexpath, true)) add(FEEDFLSTPPH);
		if (feedFLstPrc.readXML(docctx, basexpath, true)) add(FEEDFLSTPRC);
		if (feedFLstPrt.readXML(docctx, basexpath, true)) add(FEEDFLSTPRT);
		if (feedFLstSig.readXML(docctx, basexpath, true)) add(FEEDFLSTSIG);
		if (feedFLstVar.readXML(docctx, basexpath, true)) add(FEEDFLSTVAR);
		if (feedFLstVec.readXML(docctx, basexpath, true)) add(FEEDFLSTVEC);
		if (feedFLstVit.readXML(docctx, basexpath, true)) add(FEEDFLSTVIT);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		feedFLstBnk.clear();
		feedFLstCmd.clear();
		feedFLstErr.clear();
		feedFLstFst.clear();
		feedFLstGen.clear();
		feedFLstMod.clear();
		feedFLstPin.clear();
		feedFLstPph.clear();
		feedFLstPrc.clear();
		feedFLstPrt.clear();
		feedFLstSig.clear();
		feedFLstVar.clear();
		feedFLstVec.clear();
		feedFLstVit.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

