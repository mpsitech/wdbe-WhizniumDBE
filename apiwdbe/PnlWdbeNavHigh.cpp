/**
	* \file PnlWdbeNavHigh.cpp
	* API code for job PnlWdbeNavHigh (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

#include "PnlWdbeNavHigh.h"

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
			, numFLstPph(numFLstPph)
			, numFLstMod(numFLstMod)
			, numFLstVec(numFLstVec)
			, numFLstVit(numFLstVit)
			, numFLstCmd(numFLstCmd)
			, numFLstErr(numFLstErr)
			, numFLstPpl(numFLstPpl)
			, numFLstSeg(numFLstSeg)
		{
	mask = {NUMFLSTPPH, NUMFLSTMOD, NUMFLSTVEC, NUMFLSTVIT, NUMFLSTCMD, NUMFLSTERR, NUMFLSTPPL, NUMFLSTSEG};
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

PnlWdbeNavHigh::StatApp::StatApp(
			const uint ixWdbeVExpstate
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
		) :
			Block()
			, ixWdbeVExpstate(ixWdbeVExpstate)
			, LstPphAlt(LstPphAlt)
			, LstModAlt(LstModAlt)
			, LstVecAlt(LstVecAlt)
			, LstVitAlt(LstVitAlt)
			, LstCmdAlt(LstCmdAlt)
			, LstErrAlt(LstErrAlt)
			, LstPplAlt(LstPplAlt)
			, LstSegAlt(LstSegAlt)
			, LstPphNumFirstdisp(LstPphNumFirstdisp)
			, LstModNumFirstdisp(LstModNumFirstdisp)
			, LstVecNumFirstdisp(LstVecNumFirstdisp)
			, LstVitNumFirstdisp(LstVitNumFirstdisp)
			, LstCmdNumFirstdisp(LstCmdNumFirstdisp)
			, LstErrNumFirstdisp(LstErrNumFirstdisp)
			, LstPplNumFirstdisp(LstPplNumFirstdisp)
			, LstSegNumFirstdisp(LstSegNumFirstdisp)
		{
	mask = {IXWDBEVEXPSTATE, LSTPPHALT, LSTMODALT, LSTVECALT, LSTVITALT, LSTCMDALT, LSTERRALT, LSTPPLALT, LSTSEGALT, LSTPPHNUMFIRSTDISP, LSTMODNUMFIRSTDISP, LSTVECNUMFIRSTDISP, LSTVITNUMFIRSTDISP, LSTCMDNUMFIRSTDISP, LSTERRNUMFIRSTDISP, LSTPPLNUMFIRSTDISP, LSTSEGNUMFIRSTDISP};
};

bool PnlWdbeNavHigh::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWdbeVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWdbeNavHigh");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWdbeNavHigh";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", srefIxWdbeVExpstate)) {
			ixWdbeVExpstate = VecWdbeVExpstate::getIx(srefIxWdbeVExpstate);
			add(IXWDBEVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPphAlt", LstPphAlt)) add(LSTPPHALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstModAlt", LstModAlt)) add(LSTMODALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstVecAlt", LstVecAlt)) add(LSTVECALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstVitAlt", LstVitAlt)) add(LSTVITALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCmdAlt", LstCmdAlt)) add(LSTCMDALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstErrAlt", LstErrAlt)) add(LSTERRALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPplAlt", LstPplAlt)) add(LSTPPLALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSegAlt", LstSegAlt)) add(LSTSEGALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPphNumFirstdisp", LstPphNumFirstdisp)) add(LSTPPHNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstModNumFirstdisp", LstModNumFirstdisp)) add(LSTMODNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstVecNumFirstdisp", LstVecNumFirstdisp)) add(LSTVECNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstVitNumFirstdisp", LstVitNumFirstdisp)) add(LSTVITNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCmdNumFirstdisp", LstCmdNumFirstdisp)) add(LSTCMDNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstErrNumFirstdisp", LstErrNumFirstdisp)) add(LSTERRNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPplNumFirstdisp", LstPplNumFirstdisp)) add(LSTPPLNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSegNumFirstdisp", LstSegNumFirstdisp)) add(LSTSEGNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlWdbeNavHigh::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWdbeVExpstate == comp->ixWdbeVExpstate) insert(items, IXWDBEVEXPSTATE);
	if (LstPphAlt == comp->LstPphAlt) insert(items, LSTPPHALT);
	if (LstModAlt == comp->LstModAlt) insert(items, LSTMODALT);
	if (LstVecAlt == comp->LstVecAlt) insert(items, LSTVECALT);
	if (LstVitAlt == comp->LstVitAlt) insert(items, LSTVITALT);
	if (LstCmdAlt == comp->LstCmdAlt) insert(items, LSTCMDALT);
	if (LstErrAlt == comp->LstErrAlt) insert(items, LSTERRALT);
	if (LstPplAlt == comp->LstPplAlt) insert(items, LSTPPLALT);
	if (LstSegAlt == comp->LstSegAlt) insert(items, LSTSEGALT);
	if (LstPphNumFirstdisp == comp->LstPphNumFirstdisp) insert(items, LSTPPHNUMFIRSTDISP);
	if (LstModNumFirstdisp == comp->LstModNumFirstdisp) insert(items, LSTMODNUMFIRSTDISP);
	if (LstVecNumFirstdisp == comp->LstVecNumFirstdisp) insert(items, LSTVECNUMFIRSTDISP);
	if (LstVitNumFirstdisp == comp->LstVitNumFirstdisp) insert(items, LSTVITNUMFIRSTDISP);
	if (LstCmdNumFirstdisp == comp->LstCmdNumFirstdisp) insert(items, LSTCMDNUMFIRSTDISP);
	if (LstErrNumFirstdisp == comp->LstErrNumFirstdisp) insert(items, LSTERRNUMFIRSTDISP);
	if (LstPplNumFirstdisp == comp->LstPplNumFirstdisp) insert(items, LSTPPLNUMFIRSTDISP);
	if (LstSegNumFirstdisp == comp->LstSegNumFirstdisp) insert(items, LSTSEGNUMFIRSTDISP);

	return(items);
};

set<uint> PnlWdbeNavHigh::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWDBEVEXPSTATE, LSTPPHALT, LSTMODALT, LSTVECALT, LSTVITALT, LSTCMDALT, LSTERRALT, LSTPPLALT, LSTSEGALT, LSTPPHNUMFIRSTDISP, LSTMODNUMFIRSTDISP, LSTVECNUMFIRSTDISP, LSTVITNUMFIRSTDISP, LSTCMDNUMFIRSTDISP, LSTERRNUMFIRSTDISP, LSTPPLNUMFIRSTDISP, LSTSEGNUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
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
			, LstPphAvail(LstPphAvail)
			, ButPphViewActive(ButPphViewActive)
			, ButPphNewcrdActive(ButPphNewcrdActive)
			, LstModAvail(LstModAvail)
			, ButModViewActive(ButModViewActive)
			, ButModNewcrdActive(ButModNewcrdActive)
			, LstVecAvail(LstVecAvail)
			, ButVecViewActive(ButVecViewActive)
			, ButVecNewcrdActive(ButVecNewcrdActive)
			, LstVitAvail(LstVitAvail)
			, ButVitViewActive(ButVitViewActive)
			, LstCmdAvail(LstCmdAvail)
			, ButCmdViewActive(ButCmdViewActive)
			, ButCmdNewcrdActive(ButCmdNewcrdActive)
			, LstErrAvail(LstErrAvail)
			, ButErrViewActive(ButErrViewActive)
			, ButErrNewcrdActive(ButErrNewcrdActive)
			, LstPplAvail(LstPplAvail)
			, ButPplViewActive(ButPplViewActive)
			, ButPplNewcrdActive(ButPplNewcrdActive)
			, LstSegAvail(LstSegAvail)
			, ButSegViewActive(ButSegViewActive)
			, ButSegNewcrdActive(ButSegNewcrdActive)
		{
	mask = {LSTPPHAVAIL, BUTPPHVIEWACTIVE, BUTPPHNEWCRDACTIVE, LSTMODAVAIL, BUTMODVIEWACTIVE, BUTMODNEWCRDACTIVE, LSTVECAVAIL, BUTVECVIEWACTIVE, BUTVECNEWCRDACTIVE, LSTVITAVAIL, BUTVITVIEWACTIVE, LSTCMDAVAIL, BUTCMDVIEWACTIVE, BUTCMDNEWCRDACTIVE, LSTERRAVAIL, BUTERRVIEWACTIVE, BUTERRNEWCRDACTIVE, LSTPPLAVAIL, BUTPPLVIEWACTIVE, BUTPPLNEWCRDACTIVE, LSTSEGAVAIL, BUTSEGVIEWACTIVE, BUTSEGNEWCRDACTIVE};
};

bool PnlWdbeNavHigh::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWdbeNavHigh");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWdbeNavHigh";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPphAvail", LstPphAvail)) add(LSTPPHAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPphViewActive", ButPphViewActive)) add(BUTPPHVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPphNewcrdActive", ButPphNewcrdActive)) add(BUTPPHNEWCRDACTIVE);
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
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPplAvail", LstPplAvail)) add(LSTPPLAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPplViewActive", ButPplViewActive)) add(BUTPPLVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPplNewcrdActive", ButPplNewcrdActive)) add(BUTPPLNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSegAvail", LstSegAvail)) add(LSTSEGAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSegViewActive", ButSegViewActive)) add(BUTSEGVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSegNewcrdActive", ButSegNewcrdActive)) add(BUTSEGNEWCRDACTIVE);
	};

	return basefound;
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

PnlWdbeNavHigh::Tag::Tag(
			const string& Cpt
			, const string& CptPph
			, const string& CptMod
			, const string& CptVec
			, const string& CptVit
			, const string& CptCmd
			, const string& CptErr
			, const string& CptPpl
			, const string& CptSeg
		) :
			Block()
			, Cpt(Cpt)
			, CptPph(CptPph)
			, CptMod(CptMod)
			, CptVec(CptVec)
			, CptVit(CptVit)
			, CptCmd(CptCmd)
			, CptErr(CptErr)
			, CptPpl(CptPpl)
			, CptSeg(CptSeg)
		{
	mask = {CPT, CPTPPH, CPTMOD, CPTVEC, CPTVIT, CPTCMD, CPTERR, CPTPPL, CPTSEG};
};

bool PnlWdbeNavHigh::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWdbeNavHigh");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWdbeNavHigh";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPph", CptPph)) add(CPTPPH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptMod", CptMod)) add(CPTMOD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVec", CptVec)) add(CPTVEC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVit", CptVit)) add(CPTVIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCmd", CptCmd)) add(CPTCMD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptErr", CptErr)) add(CPTERR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPpl", CptPpl)) add(CPTPPL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSeg", CptSeg)) add(CPTSEG);
	};

	return basefound;
};

/******************************************************************************
 class PnlWdbeNavHigh::DpchAppData
 ******************************************************************************/

PnlWdbeNavHigh::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBENAVHIGHDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWdbeNavHigh::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavHigh::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeNavHighData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeNavHigh::DpchAppDo
 ******************************************************************************/

PnlWdbeNavHigh::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBENAVHIGHDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string PnlWdbeNavHigh::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeNavHigh::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeNavHighDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeNavHigh::DpchEngData
 ******************************************************************************/

PnlWdbeNavHigh::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBENAVHIGHDATA)
		{
	feedFLstCmd.tag = "FeedFLstCmd";
	feedFLstErr.tag = "FeedFLstErr";
	feedFLstMod.tag = "FeedFLstMod";
	feedFLstPph.tag = "FeedFLstPph";
	feedFLstPpl.tag = "FeedFLstPpl";
	feedFLstSeg.tag = "FeedFLstSeg";
	feedFLstVec.tag = "FeedFLstVec";
	feedFLstVit.tag = "FeedFLstVit";
};

string PnlWdbeNavHigh::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
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

void PnlWdbeNavHigh::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWdbeNavHighData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (feedFLstCmd.readXML(docctx, basexpath, true)) add(FEEDFLSTCMD);
		if (feedFLstErr.readXML(docctx, basexpath, true)) add(FEEDFLSTERR);
		if (feedFLstMod.readXML(docctx, basexpath, true)) add(FEEDFLSTMOD);
		if (feedFLstPph.readXML(docctx, basexpath, true)) add(FEEDFLSTPPH);
		if (feedFLstPpl.readXML(docctx, basexpath, true)) add(FEEDFLSTPPL);
		if (feedFLstSeg.readXML(docctx, basexpath, true)) add(FEEDFLSTSEG);
		if (feedFLstVec.readXML(docctx, basexpath, true)) add(FEEDFLSTVEC);
		if (feedFLstVit.readXML(docctx, basexpath, true)) add(FEEDFLSTVIT);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		feedFLstCmd.clear();
		feedFLstErr.clear();
		feedFLstMod.clear();
		feedFLstPph.clear();
		feedFLstPpl.clear();
		feedFLstSeg.clear();
		feedFLstVec.clear();
		feedFLstVit.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
