/**
	* \file PnlWdbeNavLow.cpp
	* API code for job PnlWdbeNavLow (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

#include "PnlWdbeNavLow.h"

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
	if (s == "butcdcviewclick") return BUTCDCVIEWCLICK;
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
	if (ix == BUTCDCVIEWCLICK) return("ButCdcViewClick");
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
			, const uint numFLstCdc
			, const uint numFLstPrc
			, const uint numFLstFst
		) :
			Block()
			, numFLstBnk(numFLstBnk)
			, numFLstPin(numFLstPin)
			, numFLstInt(numFLstInt)
			, numFLstSns(numFLstSns)
			, numFLstVar(numFLstVar)
			, numFLstGen(numFLstGen)
			, numFLstPrt(numFLstPrt)
			, numFLstSig(numFLstSig)
			, numFLstCdc(numFLstCdc)
			, numFLstPrc(numFLstPrc)
			, numFLstFst(numFLstFst)
		{
	mask = {NUMFLSTBNK, NUMFLSTPIN, NUMFLSTINT, NUMFLSTSNS, NUMFLSTVAR, NUMFLSTGEN, NUMFLSTPRT, NUMFLSTSIG, NUMFLSTCDC, NUMFLSTPRC, NUMFLSTFST};
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
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstCdc", numFLstCdc)) add(NUMFLSTCDC);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstPrc", numFLstPrc)) add(NUMFLSTPRC);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstFst", numFLstFst)) add(NUMFLSTFST);
	};

	return basefound;
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
		writeUintAttr(wr, itemtag, "sref", "numFLstCdc", numFLstCdc);
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
	if (numFLstCdc == comp->numFLstCdc) insert(items, NUMFLSTCDC);
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

	diffitems = {NUMFLSTBNK, NUMFLSTPIN, NUMFLSTINT, NUMFLSTSNS, NUMFLSTVAR, NUMFLSTGEN, NUMFLSTPRT, NUMFLSTSIG, NUMFLSTCDC, NUMFLSTPRC, NUMFLSTFST};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeNavLow::StatApp
 ******************************************************************************/

PnlWdbeNavLow::StatApp::StatApp(
			const uint ixWdbeVExpstate
			, const bool LstBnkAlt
			, const bool LstPinAlt
			, const bool LstIntAlt
			, const bool LstSnsAlt
			, const bool LstVarAlt
			, const bool LstGenAlt
			, const bool LstPrtAlt
			, const bool LstSigAlt
			, const bool LstCdcAlt
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
			, const uint LstCdcNumFirstdisp
			, const uint LstPrcNumFirstdisp
			, const uint LstFstNumFirstdisp
		) :
			Block()
			, ixWdbeVExpstate(ixWdbeVExpstate)
			, LstBnkAlt(LstBnkAlt)
			, LstPinAlt(LstPinAlt)
			, LstIntAlt(LstIntAlt)
			, LstSnsAlt(LstSnsAlt)
			, LstVarAlt(LstVarAlt)
			, LstGenAlt(LstGenAlt)
			, LstPrtAlt(LstPrtAlt)
			, LstSigAlt(LstSigAlt)
			, LstCdcAlt(LstCdcAlt)
			, LstPrcAlt(LstPrcAlt)
			, LstFstAlt(LstFstAlt)
			, LstBnkNumFirstdisp(LstBnkNumFirstdisp)
			, LstPinNumFirstdisp(LstPinNumFirstdisp)
			, LstIntNumFirstdisp(LstIntNumFirstdisp)
			, LstSnsNumFirstdisp(LstSnsNumFirstdisp)
			, LstVarNumFirstdisp(LstVarNumFirstdisp)
			, LstGenNumFirstdisp(LstGenNumFirstdisp)
			, LstPrtNumFirstdisp(LstPrtNumFirstdisp)
			, LstSigNumFirstdisp(LstSigNumFirstdisp)
			, LstCdcNumFirstdisp(LstCdcNumFirstdisp)
			, LstPrcNumFirstdisp(LstPrcNumFirstdisp)
			, LstFstNumFirstdisp(LstFstNumFirstdisp)
		{
	mask = {IXWDBEVEXPSTATE, LSTBNKALT, LSTPINALT, LSTINTALT, LSTSNSALT, LSTVARALT, LSTGENALT, LSTPRTALT, LSTSIGALT, LSTCDCALT, LSTPRCALT, LSTFSTALT, LSTBNKNUMFIRSTDISP, LSTPINNUMFIRSTDISP, LSTINTNUMFIRSTDISP, LSTSNSNUMFIRSTDISP, LSTVARNUMFIRSTDISP, LSTGENNUMFIRSTDISP, LSTPRTNUMFIRSTDISP, LSTSIGNUMFIRSTDISP, LSTCDCNUMFIRSTDISP, LSTPRCNUMFIRSTDISP, LSTFSTNUMFIRSTDISP};
};

bool PnlWdbeNavLow::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWdbeVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWdbeNavLow");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWdbeNavLow";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", srefIxWdbeVExpstate)) {
			ixWdbeVExpstate = VecWdbeVExpstate::getIx(srefIxWdbeVExpstate);
			add(IXWDBEVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstBnkAlt", LstBnkAlt)) add(LSTBNKALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPinAlt", LstPinAlt)) add(LSTPINALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstIntAlt", LstIntAlt)) add(LSTINTALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSnsAlt", LstSnsAlt)) add(LSTSNSALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstVarAlt", LstVarAlt)) add(LSTVARALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstGenAlt", LstGenAlt)) add(LSTGENALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrtAlt", LstPrtAlt)) add(LSTPRTALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSigAlt", LstSigAlt)) add(LSTSIGALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCdcAlt", LstCdcAlt)) add(LSTCDCALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrcAlt", LstPrcAlt)) add(LSTPRCALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFstAlt", LstFstAlt)) add(LSTFSTALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstBnkNumFirstdisp", LstBnkNumFirstdisp)) add(LSTBNKNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPinNumFirstdisp", LstPinNumFirstdisp)) add(LSTPINNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstIntNumFirstdisp", LstIntNumFirstdisp)) add(LSTINTNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSnsNumFirstdisp", LstSnsNumFirstdisp)) add(LSTSNSNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstVarNumFirstdisp", LstVarNumFirstdisp)) add(LSTVARNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstGenNumFirstdisp", LstGenNumFirstdisp)) add(LSTGENNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrtNumFirstdisp", LstPrtNumFirstdisp)) add(LSTPRTNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSigNumFirstdisp", LstSigNumFirstdisp)) add(LSTSIGNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCdcNumFirstdisp", LstCdcNumFirstdisp)) add(LSTCDCNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrcNumFirstdisp", LstPrcNumFirstdisp)) add(LSTPRCNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFstNumFirstdisp", LstFstNumFirstdisp)) add(LSTFSTNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlWdbeNavLow::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWdbeVExpstate == comp->ixWdbeVExpstate) insert(items, IXWDBEVEXPSTATE);
	if (LstBnkAlt == comp->LstBnkAlt) insert(items, LSTBNKALT);
	if (LstPinAlt == comp->LstPinAlt) insert(items, LSTPINALT);
	if (LstIntAlt == comp->LstIntAlt) insert(items, LSTINTALT);
	if (LstSnsAlt == comp->LstSnsAlt) insert(items, LSTSNSALT);
	if (LstVarAlt == comp->LstVarAlt) insert(items, LSTVARALT);
	if (LstGenAlt == comp->LstGenAlt) insert(items, LSTGENALT);
	if (LstPrtAlt == comp->LstPrtAlt) insert(items, LSTPRTALT);
	if (LstSigAlt == comp->LstSigAlt) insert(items, LSTSIGALT);
	if (LstCdcAlt == comp->LstCdcAlt) insert(items, LSTCDCALT);
	if (LstPrcAlt == comp->LstPrcAlt) insert(items, LSTPRCALT);
	if (LstFstAlt == comp->LstFstAlt) insert(items, LSTFSTALT);
	if (LstBnkNumFirstdisp == comp->LstBnkNumFirstdisp) insert(items, LSTBNKNUMFIRSTDISP);
	if (LstPinNumFirstdisp == comp->LstPinNumFirstdisp) insert(items, LSTPINNUMFIRSTDISP);
	if (LstIntNumFirstdisp == comp->LstIntNumFirstdisp) insert(items, LSTINTNUMFIRSTDISP);
	if (LstSnsNumFirstdisp == comp->LstSnsNumFirstdisp) insert(items, LSTSNSNUMFIRSTDISP);
	if (LstVarNumFirstdisp == comp->LstVarNumFirstdisp) insert(items, LSTVARNUMFIRSTDISP);
	if (LstGenNumFirstdisp == comp->LstGenNumFirstdisp) insert(items, LSTGENNUMFIRSTDISP);
	if (LstPrtNumFirstdisp == comp->LstPrtNumFirstdisp) insert(items, LSTPRTNUMFIRSTDISP);
	if (LstSigNumFirstdisp == comp->LstSigNumFirstdisp) insert(items, LSTSIGNUMFIRSTDISP);
	if (LstCdcNumFirstdisp == comp->LstCdcNumFirstdisp) insert(items, LSTCDCNUMFIRSTDISP);
	if (LstPrcNumFirstdisp == comp->LstPrcNumFirstdisp) insert(items, LSTPRCNUMFIRSTDISP);
	if (LstFstNumFirstdisp == comp->LstFstNumFirstdisp) insert(items, LSTFSTNUMFIRSTDISP);

	return(items);
};

set<uint> PnlWdbeNavLow::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWDBEVEXPSTATE, LSTBNKALT, LSTPINALT, LSTINTALT, LSTSNSALT, LSTVARALT, LSTGENALT, LSTPRTALT, LSTSIGALT, LSTCDCALT, LSTPRCALT, LSTFSTALT, LSTBNKNUMFIRSTDISP, LSTPINNUMFIRSTDISP, LSTINTNUMFIRSTDISP, LSTSNSNUMFIRSTDISP, LSTVARNUMFIRSTDISP, LSTGENNUMFIRSTDISP, LSTPRTNUMFIRSTDISP, LSTSIGNUMFIRSTDISP, LSTCDCNUMFIRSTDISP, LSTPRCNUMFIRSTDISP, LSTFSTNUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
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
			, const bool LstCdcAvail
			, const bool ButCdcViewActive
			, const bool LstPrcAvail
			, const bool ButPrcViewActive
			, const bool LstFstAvail
			, const bool ButFstViewActive
		) :
			Block()
			, LstBnkAvail(LstBnkAvail)
			, ButBnkViewActive(ButBnkViewActive)
			, ButBnkNewcrdActive(ButBnkNewcrdActive)
			, LstPinAvail(LstPinAvail)
			, ButPinViewActive(ButPinViewActive)
			, ButPinNewcrdActive(ButPinNewcrdActive)
			, LstIntAvail(LstIntAvail)
			, ButIntViewActive(ButIntViewActive)
			, ButIntNewcrdActive(ButIntNewcrdActive)
			, LstSnsAvail(LstSnsAvail)
			, ButSnsViewActive(ButSnsViewActive)
			, LstVarAvail(LstVarAvail)
			, ButVarViewActive(ButVarViewActive)
			, LstGenAvail(LstGenAvail)
			, ButGenViewActive(ButGenViewActive)
			, LstPrtAvail(LstPrtAvail)
			, ButPrtViewActive(ButPrtViewActive)
			, LstSigAvail(LstSigAvail)
			, ButSigViewActive(ButSigViewActive)
			, ButSigNewcrdActive(ButSigNewcrdActive)
			, LstCdcAvail(LstCdcAvail)
			, ButCdcViewActive(ButCdcViewActive)
			, LstPrcAvail(LstPrcAvail)
			, ButPrcViewActive(ButPrcViewActive)
			, LstFstAvail(LstFstAvail)
			, ButFstViewActive(ButFstViewActive)
		{
	mask = {LSTBNKAVAIL, BUTBNKVIEWACTIVE, BUTBNKNEWCRDACTIVE, LSTPINAVAIL, BUTPINVIEWACTIVE, BUTPINNEWCRDACTIVE, LSTINTAVAIL, BUTINTVIEWACTIVE, BUTINTNEWCRDACTIVE, LSTSNSAVAIL, BUTSNSVIEWACTIVE, LSTVARAVAIL, BUTVARVIEWACTIVE, LSTGENAVAIL, BUTGENVIEWACTIVE, LSTPRTAVAIL, BUTPRTVIEWACTIVE, LSTSIGAVAIL, BUTSIGVIEWACTIVE, BUTSIGNEWCRDACTIVE, LSTCDCAVAIL, BUTCDCVIEWACTIVE, LSTPRCAVAIL, BUTPRCVIEWACTIVE, LSTFSTAVAIL, BUTFSTVIEWACTIVE};
};

bool PnlWdbeNavLow::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWdbeNavLow");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWdbeNavLow";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstBnkAvail", LstBnkAvail)) add(LSTBNKAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButBnkViewActive", ButBnkViewActive)) add(BUTBNKVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButBnkNewcrdActive", ButBnkNewcrdActive)) add(BUTBNKNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPinAvail", LstPinAvail)) add(LSTPINAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPinViewActive", ButPinViewActive)) add(BUTPINVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPinNewcrdActive", ButPinNewcrdActive)) add(BUTPINNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstIntAvail", LstIntAvail)) add(LSTINTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButIntViewActive", ButIntViewActive)) add(BUTINTVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButIntNewcrdActive", ButIntNewcrdActive)) add(BUTINTNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSnsAvail", LstSnsAvail)) add(LSTSNSAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSnsViewActive", ButSnsViewActive)) add(BUTSNSVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstVarAvail", LstVarAvail)) add(LSTVARAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButVarViewActive", ButVarViewActive)) add(BUTVARVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstGenAvail", LstGenAvail)) add(LSTGENAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButGenViewActive", ButGenViewActive)) add(BUTGENVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrtAvail", LstPrtAvail)) add(LSTPRTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPrtViewActive", ButPrtViewActive)) add(BUTPRTVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSigAvail", LstSigAvail)) add(LSTSIGAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSigViewActive", ButSigViewActive)) add(BUTSIGVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSigNewcrdActive", ButSigNewcrdActive)) add(BUTSIGNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCdcAvail", LstCdcAvail)) add(LSTCDCAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCdcViewActive", ButCdcViewActive)) add(BUTCDCVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrcAvail", LstPrcAvail)) add(LSTPRCAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPrcViewActive", ButPrcViewActive)) add(BUTPRCVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFstAvail", LstFstAvail)) add(LSTFSTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButFstViewActive", ButFstViewActive)) add(BUTFSTVIEWACTIVE);
	};

	return basefound;
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
	if (LstCdcAvail == comp->LstCdcAvail) insert(items, LSTCDCAVAIL);
	if (ButCdcViewActive == comp->ButCdcViewActive) insert(items, BUTCDCVIEWACTIVE);
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

	diffitems = {LSTBNKAVAIL, BUTBNKVIEWACTIVE, BUTBNKNEWCRDACTIVE, LSTPINAVAIL, BUTPINVIEWACTIVE, BUTPINNEWCRDACTIVE, LSTINTAVAIL, BUTINTVIEWACTIVE, BUTINTNEWCRDACTIVE, LSTSNSAVAIL, BUTSNSVIEWACTIVE, LSTVARAVAIL, BUTVARVIEWACTIVE, LSTGENAVAIL, BUTGENVIEWACTIVE, LSTPRTAVAIL, BUTPRTVIEWACTIVE, LSTSIGAVAIL, BUTSIGVIEWACTIVE, BUTSIGNEWCRDACTIVE, LSTCDCAVAIL, BUTCDCVIEWACTIVE, LSTPRCAVAIL, BUTPRCVIEWACTIVE, LSTFSTAVAIL, BUTFSTVIEWACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeNavLow::Tag
 ******************************************************************************/

PnlWdbeNavLow::Tag::Tag(
			const string& Cpt
			, const string& CptBnk
			, const string& CptPin
			, const string& CptInt
			, const string& CptSns
			, const string& CptVar
			, const string& CptGen
			, const string& CptPrt
			, const string& CptSig
			, const string& CptCdc
			, const string& CptPrc
			, const string& CptFst
		) :
			Block()
			, Cpt(Cpt)
			, CptBnk(CptBnk)
			, CptPin(CptPin)
			, CptInt(CptInt)
			, CptSns(CptSns)
			, CptVar(CptVar)
			, CptGen(CptGen)
			, CptPrt(CptPrt)
			, CptSig(CptSig)
			, CptCdc(CptCdc)
			, CptPrc(CptPrc)
			, CptFst(CptFst)
		{
	mask = {CPT, CPTBNK, CPTPIN, CPTINT, CPTSNS, CPTVAR, CPTGEN, CPTPRT, CPTSIG, CPTCDC, CPTPRC, CPTFST};
};

bool PnlWdbeNavLow::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWdbeNavLow");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWdbeNavLow";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptBnk", CptBnk)) add(CPTBNK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPin", CptPin)) add(CPTPIN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptInt", CptInt)) add(CPTINT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSns", CptSns)) add(CPTSNS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVar", CptVar)) add(CPTVAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptGen", CptGen)) add(CPTGEN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrt", CptPrt)) add(CPTPRT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSig", CptSig)) add(CPTSIG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCdc", CptCdc)) add(CPTCDC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrc", CptPrc)) add(CPTPRC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFst", CptFst)) add(CPTFST);
	};

	return basefound;
};

/******************************************************************************
 class PnlWdbeNavLow::DpchAppData
 ******************************************************************************/

PnlWdbeNavLow::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBENAVLOWDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWdbeNavLow::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavLow::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeNavLowData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeNavLow::DpchAppDo
 ******************************************************************************/

PnlWdbeNavLow::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBENAVLOWDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string PnlWdbeNavLow::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavLow::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeNavLowDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeNavLow::DpchEngData
 ******************************************************************************/

PnlWdbeNavLow::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBENAVLOWDATA)
		{
	feedFLstBnk.tag = "FeedFLstBnk";
	feedFLstCdc.tag = "FeedFLstCdc";
	feedFLstFst.tag = "FeedFLstFst";
	feedFLstGen.tag = "FeedFLstGen";
	feedFLstInt.tag = "FeedFLstInt";
	feedFLstPin.tag = "FeedFLstPin";
	feedFLstPrc.tag = "FeedFLstPrc";
	feedFLstPrt.tag = "FeedFLstPrt";
	feedFLstSig.tag = "FeedFLstSig";
	feedFLstSns.tag = "FeedFLstSns";
	feedFLstVar.tag = "FeedFLstVar";
};

string PnlWdbeNavLow::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTBNK)) ss.push_back("feedFLstBnk");
	if (has(FEEDFLSTCDC)) ss.push_back("feedFLstCdc");
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

void PnlWdbeNavLow::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWdbeNavLowData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (feedFLstBnk.readXML(docctx, basexpath, true)) add(FEEDFLSTBNK);
		if (feedFLstCdc.readXML(docctx, basexpath, true)) add(FEEDFLSTCDC);
		if (feedFLstFst.readXML(docctx, basexpath, true)) add(FEEDFLSTFST);
		if (feedFLstGen.readXML(docctx, basexpath, true)) add(FEEDFLSTGEN);
		if (feedFLstInt.readXML(docctx, basexpath, true)) add(FEEDFLSTINT);
		if (feedFLstPin.readXML(docctx, basexpath, true)) add(FEEDFLSTPIN);
		if (feedFLstPrc.readXML(docctx, basexpath, true)) add(FEEDFLSTPRC);
		if (feedFLstPrt.readXML(docctx, basexpath, true)) add(FEEDFLSTPRT);
		if (feedFLstSig.readXML(docctx, basexpath, true)) add(FEEDFLSTSIG);
		if (feedFLstSns.readXML(docctx, basexpath, true)) add(FEEDFLSTSNS);
		if (feedFLstVar.readXML(docctx, basexpath, true)) add(FEEDFLSTVAR);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		feedFLstBnk.clear();
		feedFLstCdc.clear();
		feedFLstFst.clear();
		feedFLstGen.clear();
		feedFLstInt.clear();
		feedFLstPin.clear();
		feedFLstPrc.clear();
		feedFLstPrt.clear();
		feedFLstSig.clear();
		feedFLstSns.clear();
		feedFLstVar.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
