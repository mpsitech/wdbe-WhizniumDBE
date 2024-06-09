/**
	* \file CrdWdbeNav.cpp
	* API code for job CrdWdbeNav (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "CrdWdbeNav.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class CrdWdbeNav::VecVDo
 ******************************************************************************/

uint CrdWdbeNav::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "close") return CLOSE;
	if (s == "mitappabtclick") return MITAPPABTCLICK;
	if (s == "mitsesspsclick") return MITSESSPSCLICK;
	if (s == "mitsestrmclick") return MITSESTRMCLICK;
	if (s == "mitcrdusgclick") return MITCRDUSGCLICK;
	if (s == "mitcrdusrclick") return MITCRDUSRCLICK;
	if (s == "mitcrdprsclick") return MITCRDPRSCLICK;
	if (s == "mitcrdfilclick") return MITCRDFILCLICK;
	if (s == "mitcrdmchclick") return MITCRDMCHCLICK;
	if (s == "mitcrdlibclick") return MITCRDLIBCLICK;
	if (s == "mitcrdfamclick") return MITCRDFAMCLICK;
	if (s == "mitcrdsilclick") return MITCRDSILCLICK;
	if (s == "mitcrdmtpclick") return MITCRDMTPCLICK;
	if (s == "mitcrdprjclick") return MITCRDPRJCLICK;
	if (s == "mitcrdverclick") return MITCRDVERCLICK;
	if (s == "mitcrduntclick") return MITCRDUNTCLICK;
	if (s == "mitcrdcprclick") return MITCRDCPRCLICK;
	if (s == "mitcrdcvrclick") return MITCRDCVRCLICK;
	if (s == "mitcrdpphclick") return MITCRDPPHCLICK;
	if (s == "mitcrdmodclick") return MITCRDMODCLICK;
	if (s == "mitcrdvecclick") return MITCRDVECCLICK;
	if (s == "mitcrdcmdclick") return MITCRDCMDCLICK;
	if (s == "mitcrderrclick") return MITCRDERRCLICK;
	if (s == "mitcrdpplclick") return MITCRDPPLCLICK;
	if (s == "mitcrdsegclick") return MITCRDSEGCLICK;
	if (s == "mitcrdbnkclick") return MITCRDBNKCLICK;
	if (s == "mitcrdpinclick") return MITCRDPINCLICK;
	if (s == "mitcrdintclick") return MITCRDINTCLICK;
	if (s == "mitcrdsigclick") return MITCRDSIGCLICK;
	if (s == "mitcrdcmpclick") return MITCRDCMPCLICK;
	if (s == "mitcrdrlsclick") return MITCRDRLSCLICK;
	if (s == "mitcrdutlclick") return MITCRDUTLCLICK;
	if (s == "mitappmlcclick") return MITAPPMLCCLICK;
	if (s == "mitapploiclick") return MITAPPLOICLICK;

	return(0);
};

string CrdWdbeNav::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
	if (ix == MITSESSPSCLICK) return("MitSesSpsClick");
	if (ix == MITSESTRMCLICK) return("MitSesTrmClick");
	if (ix == MITCRDUSGCLICK) return("MitCrdUsgClick");
	if (ix == MITCRDUSRCLICK) return("MitCrdUsrClick");
	if (ix == MITCRDPRSCLICK) return("MitCrdPrsClick");
	if (ix == MITCRDFILCLICK) return("MitCrdFilClick");
	if (ix == MITCRDMCHCLICK) return("MitCrdMchClick");
	if (ix == MITCRDLIBCLICK) return("MitCrdLibClick");
	if (ix == MITCRDFAMCLICK) return("MitCrdFamClick");
	if (ix == MITCRDSILCLICK) return("MitCrdSilClick");
	if (ix == MITCRDMTPCLICK) return("MitCrdMtpClick");
	if (ix == MITCRDPRJCLICK) return("MitCrdPrjClick");
	if (ix == MITCRDVERCLICK) return("MitCrdVerClick");
	if (ix == MITCRDUNTCLICK) return("MitCrdUntClick");
	if (ix == MITCRDCPRCLICK) return("MitCrdCprClick");
	if (ix == MITCRDCVRCLICK) return("MitCrdCvrClick");
	if (ix == MITCRDPPHCLICK) return("MitCrdPphClick");
	if (ix == MITCRDMODCLICK) return("MitCrdModClick");
	if (ix == MITCRDVECCLICK) return("MitCrdVecClick");
	if (ix == MITCRDCMDCLICK) return("MitCrdCmdClick");
	if (ix == MITCRDERRCLICK) return("MitCrdErrClick");
	if (ix == MITCRDPPLCLICK) return("MitCrdPplClick");
	if (ix == MITCRDSEGCLICK) return("MitCrdSegClick");
	if (ix == MITCRDBNKCLICK) return("MitCrdBnkClick");
	if (ix == MITCRDPINCLICK) return("MitCrdPinClick");
	if (ix == MITCRDINTCLICK) return("MitCrdIntClick");
	if (ix == MITCRDSIGCLICK) return("MitCrdSigClick");
	if (ix == MITCRDCMPCLICK) return("MitCrdCmpClick");
	if (ix == MITCRDRLSCLICK) return("MitCrdRlsClick");
	if (ix == MITCRDUTLCLICK) return("MitCrdUtlClick");
	if (ix == MITAPPMLCCLICK) return("MitAppMlcClick");
	if (ix == MITAPPLOICLICK) return("MitAppLoiClick");

	return("");
};

/******************************************************************************
 class CrdWdbeNav::VecVSge
 ******************************************************************************/

uint CrdWdbeNav::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "alrwdbeabt") return ALRWDBEABT;
	if (s == "alrwdbetrm") return ALRWDBETRM;

	return(0);
};

string CrdWdbeNav::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRWDBEABT) return("alrwdbeabt");
	if (ix == ALRWDBETRM) return("alrwdbetrm");

	return("");
};

/******************************************************************************
 class CrdWdbeNav::ContInf
 ******************************************************************************/

CrdWdbeNav::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
			, const string& MtxSesSes1
			, const string& MtxSesSes2
			, const string& MtxSesSes3
		) :
			Block()
		{
	this->numFSge = numFSge;
	this->MrlAppHlp = MrlAppHlp;
	this->MtxSesSes1 = MtxSesSes1;
	this->MtxSesSes2 = MtxSesSes2;
	this->MtxSesSes3 = MtxSesSes3;

	mask = {NUMFSGE, MRLAPPHLP, MTXSESSES1, MTXSESSES2, MTXSESSES3};
};

bool CrdWdbeNav::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWdbeNav");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWdbeNav";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MtxSesSes1", MtxSesSes1)) add(MTXSESSES1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MtxSesSes2", MtxSesSes2)) add(MTXSESSES2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MtxSesSes3", MtxSesSes3)) add(MTXSESSES3);
	};

	return basefound;
};

set<uint> CrdWdbeNav::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp == comp->MrlAppHlp) insert(items, MRLAPPHLP);
	if (MtxSesSes1 == comp->MtxSesSes1) insert(items, MTXSESSES1);
	if (MtxSesSes2 == comp->MtxSesSes2) insert(items, MTXSESSES2);
	if (MtxSesSes3 == comp->MtxSesSes3) insert(items, MTXSESSES3);

	return(items);
};

set<uint> CrdWdbeNav::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, MRLAPPHLP, MTXSESSES1, MTXSESSES2, MTXSESSES3};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWdbeNav::StatApp
 ******************************************************************************/

CrdWdbeNav::StatApp::StatApp(
			const uint ixWdbeVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdonePre
			, const bool initdoneAdmin
			, const bool initdoneGlobal
			, const bool initdoneDevdev
			, const bool initdoneCoredev
			, const bool initdoneHigh
			, const bool initdoneLow
			, const bool initdoneDeploy
			, const bool initdoneAuxfct
		) :
			Block()
		{
	this->ixWdbeVReqitmode = ixWdbeVReqitmode;
	this->latency = latency;
	this->shortMenu = shortMenu;
	this->widthMenu = widthMenu;
	this->initdoneHeadbar = initdoneHeadbar;
	this->initdonePre = initdonePre;
	this->initdoneAdmin = initdoneAdmin;
	this->initdoneGlobal = initdoneGlobal;
	this->initdoneDevdev = initdoneDevdev;
	this->initdoneCoredev = initdoneCoredev;
	this->initdoneHigh = initdoneHigh;
	this->initdoneLow = initdoneLow;
	this->initdoneDeploy = initdoneDeploy;
	this->initdoneAuxfct = initdoneAuxfct;

	mask = {IXWDBEVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONEPRE, INITDONEADMIN, INITDONEGLOBAL, INITDONEDEVDEV, INITDONECOREDEV, INITDONEHIGH, INITDONELOW, INITDONEDEPLOY, INITDONEAUXFCT};
};

bool CrdWdbeNav::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWdbeVReqitmode;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWdbeNav");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWdbeNav";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWdbeVReqitmode", srefIxWdbeVReqitmode)) {
			ixWdbeVReqitmode = VecWdbeVReqitmode::getIx(srefIxWdbeVReqitmode);
			add(IXWDBEVREQITMODE);
		};
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "latency", latency)) add(LATENCY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "widthMenu", widthMenu)) add(WIDTHMENU);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHeadbar", initdoneHeadbar)) add(INITDONEHEADBAR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdonePre", initdonePre)) add(INITDONEPRE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneAdmin", initdoneAdmin)) add(INITDONEADMIN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneGlobal", initdoneGlobal)) add(INITDONEGLOBAL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDevdev", initdoneDevdev)) add(INITDONEDEVDEV);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneCoredev", initdoneCoredev)) add(INITDONECOREDEV);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHigh", initdoneHigh)) add(INITDONEHIGH);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneLow", initdoneLow)) add(INITDONELOW);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDeploy", initdoneDeploy)) add(INITDONEDEPLOY);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneAuxfct", initdoneAuxfct)) add(INITDONEAUXFCT);
	};

	return basefound;
};

set<uint> CrdWdbeNav::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWdbeVReqitmode == comp->ixWdbeVReqitmode) insert(items, IXWDBEVREQITMODE);
	if (latency == comp->latency) insert(items, LATENCY);
	if (shortMenu == comp->shortMenu) insert(items, SHORTMENU);
	if (widthMenu == comp->widthMenu) insert(items, WIDTHMENU);
	if (initdoneHeadbar == comp->initdoneHeadbar) insert(items, INITDONEHEADBAR);
	if (initdonePre == comp->initdonePre) insert(items, INITDONEPRE);
	if (initdoneAdmin == comp->initdoneAdmin) insert(items, INITDONEADMIN);
	if (initdoneGlobal == comp->initdoneGlobal) insert(items, INITDONEGLOBAL);
	if (initdoneDevdev == comp->initdoneDevdev) insert(items, INITDONEDEVDEV);
	if (initdoneCoredev == comp->initdoneCoredev) insert(items, INITDONECOREDEV);
	if (initdoneHigh == comp->initdoneHigh) insert(items, INITDONEHIGH);
	if (initdoneLow == comp->initdoneLow) insert(items, INITDONELOW);
	if (initdoneDeploy == comp->initdoneDeploy) insert(items, INITDONEDEPLOY);
	if (initdoneAuxfct == comp->initdoneAuxfct) insert(items, INITDONEAUXFCT);

	return(items);
};

set<uint> CrdWdbeNav::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWDBEVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONEPRE, INITDONEADMIN, INITDONEGLOBAL, INITDONEDEVDEV, INITDONECOREDEV, INITDONEHIGH, INITDONELOW, INITDONEDEPLOY, INITDONEAUXFCT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWdbeNav::StatShr
 ******************************************************************************/

CrdWdbeNav::StatShr::StatShr(
			const string& scrJrefDlgloaini
			, const string& scrJrefDlgmnglic
			, const string& scrJrefHeadbar
			, const string& scrJrefPre
			, const bool pnlpreAvail
			, const string& scrJrefAdmin
			, const bool pnladminAvail
			, const string& scrJrefGlobal
			, const bool pnlglobalAvail
			, const string& scrJrefDevdev
			, const bool pnldevdevAvail
			, const string& scrJrefCoredev
			, const bool pnlcoredevAvail
			, const string& scrJrefHigh
			, const bool pnlhighAvail
			, const string& scrJrefLow
			, const bool pnllowAvail
			, const string& scrJrefDeploy
			, const bool pnldeployAvail
			, const string& scrJrefAuxfct
			, const bool pnlauxfctAvail
			, const bool MitSesSpsAvail
			, const bool MspCrd1Avail
			, const bool MitCrdUsgAvail
			, const bool MitCrdUsrAvail
			, const bool MitCrdPrsAvail
			, const bool MitCrdFilAvail
			, const bool MspCrd2Avail
			, const bool MitCrdMchAvail
			, const bool MitCrdLibAvail
			, const bool MitCrdFamAvail
			, const bool MitCrdSilAvail
			, const bool MitCrdMtpAvail
			, const bool MspCrd3Avail
			, const bool MitCrdPrjAvail
			, const bool MitCrdVerAvail
			, const bool MitCrdUntAvail
			, const bool MitCrdUntActive
			, const bool MspCrd4Avail
			, const bool MitCrdCprAvail
			, const bool MitCrdCvrAvail
			, const bool MspCrd5Avail
			, const bool MitCrdPphAvail
			, const bool MitCrdPphActive
			, const bool MitCrdModAvail
			, const bool MitCrdModActive
			, const bool MitCrdVecAvail
			, const bool MitCrdVecActive
			, const bool MitCrdCmdAvail
			, const bool MitCrdCmdActive
			, const bool MitCrdErrAvail
			, const bool MitCrdErrActive
			, const bool MitCrdPplAvail
			, const bool MitCrdPplActive
			, const bool MitCrdSegAvail
			, const bool MitCrdSegActive
			, const bool MspCrd6Avail
			, const bool MitCrdBnkAvail
			, const bool MitCrdBnkActive
			, const bool MitCrdPinAvail
			, const bool MitCrdPinActive
			, const bool MitCrdIntAvail
			, const bool MitCrdIntActive
			, const bool MitCrdSigAvail
			, const bool MitCrdSigActive
			, const bool MspCrd7Avail
			, const bool MitCrdCmpAvail
			, const bool MitCrdRlsAvail
			, const bool MitCrdRlsActive
			, const bool MspCrd8Avail
			, const bool MitCrdUtlAvail
			, const bool MspApp2Avail
			, const bool MitAppMlcAvail
			, const bool MitAppLoiAvail
		) :
			Block()
		{
	this->scrJrefDlgloaini = scrJrefDlgloaini;
	this->scrJrefDlgmnglic = scrJrefDlgmnglic;
	this->scrJrefHeadbar = scrJrefHeadbar;
	this->scrJrefPre = scrJrefPre;
	this->pnlpreAvail = pnlpreAvail;
	this->scrJrefAdmin = scrJrefAdmin;
	this->pnladminAvail = pnladminAvail;
	this->scrJrefGlobal = scrJrefGlobal;
	this->pnlglobalAvail = pnlglobalAvail;
	this->scrJrefDevdev = scrJrefDevdev;
	this->pnldevdevAvail = pnldevdevAvail;
	this->scrJrefCoredev = scrJrefCoredev;
	this->pnlcoredevAvail = pnlcoredevAvail;
	this->scrJrefHigh = scrJrefHigh;
	this->pnlhighAvail = pnlhighAvail;
	this->scrJrefLow = scrJrefLow;
	this->pnllowAvail = pnllowAvail;
	this->scrJrefDeploy = scrJrefDeploy;
	this->pnldeployAvail = pnldeployAvail;
	this->scrJrefAuxfct = scrJrefAuxfct;
	this->pnlauxfctAvail = pnlauxfctAvail;
	this->MitSesSpsAvail = MitSesSpsAvail;
	this->MspCrd1Avail = MspCrd1Avail;
	this->MitCrdUsgAvail = MitCrdUsgAvail;
	this->MitCrdUsrAvail = MitCrdUsrAvail;
	this->MitCrdPrsAvail = MitCrdPrsAvail;
	this->MitCrdFilAvail = MitCrdFilAvail;
	this->MspCrd2Avail = MspCrd2Avail;
	this->MitCrdMchAvail = MitCrdMchAvail;
	this->MitCrdLibAvail = MitCrdLibAvail;
	this->MitCrdFamAvail = MitCrdFamAvail;
	this->MitCrdSilAvail = MitCrdSilAvail;
	this->MitCrdMtpAvail = MitCrdMtpAvail;
	this->MspCrd3Avail = MspCrd3Avail;
	this->MitCrdPrjAvail = MitCrdPrjAvail;
	this->MitCrdVerAvail = MitCrdVerAvail;
	this->MitCrdUntAvail = MitCrdUntAvail;
	this->MitCrdUntActive = MitCrdUntActive;
	this->MspCrd4Avail = MspCrd4Avail;
	this->MitCrdCprAvail = MitCrdCprAvail;
	this->MitCrdCvrAvail = MitCrdCvrAvail;
	this->MspCrd5Avail = MspCrd5Avail;
	this->MitCrdPphAvail = MitCrdPphAvail;
	this->MitCrdPphActive = MitCrdPphActive;
	this->MitCrdModAvail = MitCrdModAvail;
	this->MitCrdModActive = MitCrdModActive;
	this->MitCrdVecAvail = MitCrdVecAvail;
	this->MitCrdVecActive = MitCrdVecActive;
	this->MitCrdCmdAvail = MitCrdCmdAvail;
	this->MitCrdCmdActive = MitCrdCmdActive;
	this->MitCrdErrAvail = MitCrdErrAvail;
	this->MitCrdErrActive = MitCrdErrActive;
	this->MitCrdPplAvail = MitCrdPplAvail;
	this->MitCrdPplActive = MitCrdPplActive;
	this->MitCrdSegAvail = MitCrdSegAvail;
	this->MitCrdSegActive = MitCrdSegActive;
	this->MspCrd6Avail = MspCrd6Avail;
	this->MitCrdBnkAvail = MitCrdBnkAvail;
	this->MitCrdBnkActive = MitCrdBnkActive;
	this->MitCrdPinAvail = MitCrdPinAvail;
	this->MitCrdPinActive = MitCrdPinActive;
	this->MitCrdIntAvail = MitCrdIntAvail;
	this->MitCrdIntActive = MitCrdIntActive;
	this->MitCrdSigAvail = MitCrdSigAvail;
	this->MitCrdSigActive = MitCrdSigActive;
	this->MspCrd7Avail = MspCrd7Avail;
	this->MitCrdCmpAvail = MitCrdCmpAvail;
	this->MitCrdRlsAvail = MitCrdRlsAvail;
	this->MitCrdRlsActive = MitCrdRlsActive;
	this->MspCrd8Avail = MspCrd8Avail;
	this->MitCrdUtlAvail = MitCrdUtlAvail;
	this->MspApp2Avail = MspApp2Avail;
	this->MitAppMlcAvail = MitAppMlcAvail;
	this->MitAppLoiAvail = MitAppLoiAvail;

	mask = {SCRJREFDLGLOAINI, SCRJREFDLGMNGLIC, SCRJREFHEADBAR, SCRJREFPRE, PNLPREAVAIL, SCRJREFADMIN, PNLADMINAVAIL, SCRJREFGLOBAL, PNLGLOBALAVAIL, SCRJREFDEVDEV, PNLDEVDEVAVAIL, SCRJREFCOREDEV, PNLCOREDEVAVAIL, SCRJREFHIGH, PNLHIGHAVAIL, SCRJREFLOW, PNLLOWAVAIL, SCRJREFDEPLOY, PNLDEPLOYAVAIL, SCRJREFAUXFCT, PNLAUXFCTAVAIL, MITSESSPSAVAIL, MSPCRD1AVAIL, MITCRDUSGAVAIL, MITCRDUSRAVAIL, MITCRDPRSAVAIL, MITCRDFILAVAIL, MSPCRD2AVAIL, MITCRDMCHAVAIL, MITCRDLIBAVAIL, MITCRDFAMAVAIL, MITCRDSILAVAIL, MITCRDMTPAVAIL, MSPCRD3AVAIL, MITCRDPRJAVAIL, MITCRDVERAVAIL, MITCRDUNTAVAIL, MITCRDUNTACTIVE, MSPCRD4AVAIL, MITCRDCPRAVAIL, MITCRDCVRAVAIL, MSPCRD5AVAIL, MITCRDPPHAVAIL, MITCRDPPHACTIVE, MITCRDMODAVAIL, MITCRDMODACTIVE, MITCRDVECAVAIL, MITCRDVECACTIVE, MITCRDCMDAVAIL, MITCRDCMDACTIVE, MITCRDERRAVAIL, MITCRDERRACTIVE, MITCRDPPLAVAIL, MITCRDPPLACTIVE, MITCRDSEGAVAIL, MITCRDSEGACTIVE, MSPCRD6AVAIL, MITCRDBNKAVAIL, MITCRDBNKACTIVE, MITCRDPINAVAIL, MITCRDPINACTIVE, MITCRDINTAVAIL, MITCRDINTACTIVE, MITCRDSIGAVAIL, MITCRDSIGACTIVE, MSPCRD7AVAIL, MITCRDCMPAVAIL, MITCRDRLSAVAIL, MITCRDRLSACTIVE, MSPCRD8AVAIL, MITCRDUTLAVAIL, MSPAPP2AVAIL, MITAPPMLCAVAIL, MITAPPLOIAVAIL};
};

bool CrdWdbeNav::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWdbeNav");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWdbeNav";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgloaini", scrJrefDlgloaini)) add(SCRJREFDLGLOAINI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgmnglic", scrJrefDlgmnglic)) add(SCRJREFDLGMNGLIC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", scrJrefHeadbar)) add(SCRJREFHEADBAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefPre", scrJrefPre)) add(SCRJREFPRE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlpreAvail", pnlpreAvail)) add(PNLPREAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAdmin", scrJrefAdmin)) add(SCRJREFADMIN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnladminAvail", pnladminAvail)) add(PNLADMINAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefGlobal", scrJrefGlobal)) add(SCRJREFGLOBAL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlglobalAvail", pnlglobalAvail)) add(PNLGLOBALAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDevdev", scrJrefDevdev)) add(SCRJREFDEVDEV);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnldevdevAvail", pnldevdevAvail)) add(PNLDEVDEVAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefCoredev", scrJrefCoredev)) add(SCRJREFCOREDEV);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlcoredevAvail", pnlcoredevAvail)) add(PNLCOREDEVAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHigh", scrJrefHigh)) add(SCRJREFHIGH);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlhighAvail", pnlhighAvail)) add(PNLHIGHAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefLow", scrJrefLow)) add(SCRJREFLOW);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnllowAvail", pnllowAvail)) add(PNLLOWAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDeploy", scrJrefDeploy)) add(SCRJREFDEPLOY);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnldeployAvail", pnldeployAvail)) add(PNLDEPLOYAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAuxfct", scrJrefAuxfct)) add(SCRJREFAUXFCT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlauxfctAvail", pnlauxfctAvail)) add(PNLAUXFCTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitSesSpsAvail", MitSesSpsAvail)) add(MITSESSPSAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd1Avail", MspCrd1Avail)) add(MSPCRD1AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdUsgAvail", MitCrdUsgAvail)) add(MITCRDUSGAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdUsrAvail", MitCrdUsrAvail)) add(MITCRDUSRAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdPrsAvail", MitCrdPrsAvail)) add(MITCRDPRSAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdFilAvail", MitCrdFilAvail)) add(MITCRDFILAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd2Avail", MspCrd2Avail)) add(MSPCRD2AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdMchAvail", MitCrdMchAvail)) add(MITCRDMCHAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdLibAvail", MitCrdLibAvail)) add(MITCRDLIBAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdFamAvail", MitCrdFamAvail)) add(MITCRDFAMAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdSilAvail", MitCrdSilAvail)) add(MITCRDSILAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdMtpAvail", MitCrdMtpAvail)) add(MITCRDMTPAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd3Avail", MspCrd3Avail)) add(MSPCRD3AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdPrjAvail", MitCrdPrjAvail)) add(MITCRDPRJAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdVerAvail", MitCrdVerAvail)) add(MITCRDVERAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdUntAvail", MitCrdUntAvail)) add(MITCRDUNTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdUntActive", MitCrdUntActive)) add(MITCRDUNTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd4Avail", MspCrd4Avail)) add(MSPCRD4AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdCprAvail", MitCrdCprAvail)) add(MITCRDCPRAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdCvrAvail", MitCrdCvrAvail)) add(MITCRDCVRAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd5Avail", MspCrd5Avail)) add(MSPCRD5AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdPphAvail", MitCrdPphAvail)) add(MITCRDPPHAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdPphActive", MitCrdPphActive)) add(MITCRDPPHACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdModAvail", MitCrdModAvail)) add(MITCRDMODAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdModActive", MitCrdModActive)) add(MITCRDMODACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdVecAvail", MitCrdVecAvail)) add(MITCRDVECAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdVecActive", MitCrdVecActive)) add(MITCRDVECACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdCmdAvail", MitCrdCmdAvail)) add(MITCRDCMDAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdCmdActive", MitCrdCmdActive)) add(MITCRDCMDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdErrAvail", MitCrdErrAvail)) add(MITCRDERRAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdErrActive", MitCrdErrActive)) add(MITCRDERRACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdPplAvail", MitCrdPplAvail)) add(MITCRDPPLAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdPplActive", MitCrdPplActive)) add(MITCRDPPLACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdSegAvail", MitCrdSegAvail)) add(MITCRDSEGAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdSegActive", MitCrdSegActive)) add(MITCRDSEGACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd6Avail", MspCrd6Avail)) add(MSPCRD6AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdBnkAvail", MitCrdBnkAvail)) add(MITCRDBNKAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdBnkActive", MitCrdBnkActive)) add(MITCRDBNKACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdPinAvail", MitCrdPinAvail)) add(MITCRDPINAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdPinActive", MitCrdPinActive)) add(MITCRDPINACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdIntAvail", MitCrdIntAvail)) add(MITCRDINTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdIntActive", MitCrdIntActive)) add(MITCRDINTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdSigAvail", MitCrdSigAvail)) add(MITCRDSIGAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdSigActive", MitCrdSigActive)) add(MITCRDSIGACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd7Avail", MspCrd7Avail)) add(MSPCRD7AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdCmpAvail", MitCrdCmpAvail)) add(MITCRDCMPAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdRlsAvail", MitCrdRlsAvail)) add(MITCRDRLSAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdRlsActive", MitCrdRlsActive)) add(MITCRDRLSACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd8Avail", MspCrd8Avail)) add(MSPCRD8AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdUtlAvail", MitCrdUtlAvail)) add(MITCRDUTLAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspApp2Avail", MspApp2Avail)) add(MSPAPP2AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitAppMlcAvail", MitAppMlcAvail)) add(MITAPPMLCAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitAppLoiAvail", MitAppLoiAvail)) add(MITAPPLOIAVAIL);
	};

	return basefound;
};

set<uint> CrdWdbeNav::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (scrJrefDlgloaini == comp->scrJrefDlgloaini) insert(items, SCRJREFDLGLOAINI);
	if (scrJrefDlgmnglic == comp->scrJrefDlgmnglic) insert(items, SCRJREFDLGMNGLIC);
	if (scrJrefHeadbar == comp->scrJrefHeadbar) insert(items, SCRJREFHEADBAR);
	if (scrJrefPre == comp->scrJrefPre) insert(items, SCRJREFPRE);
	if (pnlpreAvail == comp->pnlpreAvail) insert(items, PNLPREAVAIL);
	if (scrJrefAdmin == comp->scrJrefAdmin) insert(items, SCRJREFADMIN);
	if (pnladminAvail == comp->pnladminAvail) insert(items, PNLADMINAVAIL);
	if (scrJrefGlobal == comp->scrJrefGlobal) insert(items, SCRJREFGLOBAL);
	if (pnlglobalAvail == comp->pnlglobalAvail) insert(items, PNLGLOBALAVAIL);
	if (scrJrefDevdev == comp->scrJrefDevdev) insert(items, SCRJREFDEVDEV);
	if (pnldevdevAvail == comp->pnldevdevAvail) insert(items, PNLDEVDEVAVAIL);
	if (scrJrefCoredev == comp->scrJrefCoredev) insert(items, SCRJREFCOREDEV);
	if (pnlcoredevAvail == comp->pnlcoredevAvail) insert(items, PNLCOREDEVAVAIL);
	if (scrJrefHigh == comp->scrJrefHigh) insert(items, SCRJREFHIGH);
	if (pnlhighAvail == comp->pnlhighAvail) insert(items, PNLHIGHAVAIL);
	if (scrJrefLow == comp->scrJrefLow) insert(items, SCRJREFLOW);
	if (pnllowAvail == comp->pnllowAvail) insert(items, PNLLOWAVAIL);
	if (scrJrefDeploy == comp->scrJrefDeploy) insert(items, SCRJREFDEPLOY);
	if (pnldeployAvail == comp->pnldeployAvail) insert(items, PNLDEPLOYAVAIL);
	if (scrJrefAuxfct == comp->scrJrefAuxfct) insert(items, SCRJREFAUXFCT);
	if (pnlauxfctAvail == comp->pnlauxfctAvail) insert(items, PNLAUXFCTAVAIL);
	if (MitSesSpsAvail == comp->MitSesSpsAvail) insert(items, MITSESSPSAVAIL);
	if (MspCrd1Avail == comp->MspCrd1Avail) insert(items, MSPCRD1AVAIL);
	if (MitCrdUsgAvail == comp->MitCrdUsgAvail) insert(items, MITCRDUSGAVAIL);
	if (MitCrdUsrAvail == comp->MitCrdUsrAvail) insert(items, MITCRDUSRAVAIL);
	if (MitCrdPrsAvail == comp->MitCrdPrsAvail) insert(items, MITCRDPRSAVAIL);
	if (MitCrdFilAvail == comp->MitCrdFilAvail) insert(items, MITCRDFILAVAIL);
	if (MspCrd2Avail == comp->MspCrd2Avail) insert(items, MSPCRD2AVAIL);
	if (MitCrdMchAvail == comp->MitCrdMchAvail) insert(items, MITCRDMCHAVAIL);
	if (MitCrdLibAvail == comp->MitCrdLibAvail) insert(items, MITCRDLIBAVAIL);
	if (MitCrdFamAvail == comp->MitCrdFamAvail) insert(items, MITCRDFAMAVAIL);
	if (MitCrdSilAvail == comp->MitCrdSilAvail) insert(items, MITCRDSILAVAIL);
	if (MitCrdMtpAvail == comp->MitCrdMtpAvail) insert(items, MITCRDMTPAVAIL);
	if (MspCrd3Avail == comp->MspCrd3Avail) insert(items, MSPCRD3AVAIL);
	if (MitCrdPrjAvail == comp->MitCrdPrjAvail) insert(items, MITCRDPRJAVAIL);
	if (MitCrdVerAvail == comp->MitCrdVerAvail) insert(items, MITCRDVERAVAIL);
	if (MitCrdUntAvail == comp->MitCrdUntAvail) insert(items, MITCRDUNTAVAIL);
	if (MitCrdUntActive == comp->MitCrdUntActive) insert(items, MITCRDUNTACTIVE);
	if (MspCrd4Avail == comp->MspCrd4Avail) insert(items, MSPCRD4AVAIL);
	if (MitCrdCprAvail == comp->MitCrdCprAvail) insert(items, MITCRDCPRAVAIL);
	if (MitCrdCvrAvail == comp->MitCrdCvrAvail) insert(items, MITCRDCVRAVAIL);
	if (MspCrd5Avail == comp->MspCrd5Avail) insert(items, MSPCRD5AVAIL);
	if (MitCrdPphAvail == comp->MitCrdPphAvail) insert(items, MITCRDPPHAVAIL);
	if (MitCrdPphActive == comp->MitCrdPphActive) insert(items, MITCRDPPHACTIVE);
	if (MitCrdModAvail == comp->MitCrdModAvail) insert(items, MITCRDMODAVAIL);
	if (MitCrdModActive == comp->MitCrdModActive) insert(items, MITCRDMODACTIVE);
	if (MitCrdVecAvail == comp->MitCrdVecAvail) insert(items, MITCRDVECAVAIL);
	if (MitCrdVecActive == comp->MitCrdVecActive) insert(items, MITCRDVECACTIVE);
	if (MitCrdCmdAvail == comp->MitCrdCmdAvail) insert(items, MITCRDCMDAVAIL);
	if (MitCrdCmdActive == comp->MitCrdCmdActive) insert(items, MITCRDCMDACTIVE);
	if (MitCrdErrAvail == comp->MitCrdErrAvail) insert(items, MITCRDERRAVAIL);
	if (MitCrdErrActive == comp->MitCrdErrActive) insert(items, MITCRDERRACTIVE);
	if (MitCrdPplAvail == comp->MitCrdPplAvail) insert(items, MITCRDPPLAVAIL);
	if (MitCrdPplActive == comp->MitCrdPplActive) insert(items, MITCRDPPLACTIVE);
	if (MitCrdSegAvail == comp->MitCrdSegAvail) insert(items, MITCRDSEGAVAIL);
	if (MitCrdSegActive == comp->MitCrdSegActive) insert(items, MITCRDSEGACTIVE);
	if (MspCrd6Avail == comp->MspCrd6Avail) insert(items, MSPCRD6AVAIL);
	if (MitCrdBnkAvail == comp->MitCrdBnkAvail) insert(items, MITCRDBNKAVAIL);
	if (MitCrdBnkActive == comp->MitCrdBnkActive) insert(items, MITCRDBNKACTIVE);
	if (MitCrdPinAvail == comp->MitCrdPinAvail) insert(items, MITCRDPINAVAIL);
	if (MitCrdPinActive == comp->MitCrdPinActive) insert(items, MITCRDPINACTIVE);
	if (MitCrdIntAvail == comp->MitCrdIntAvail) insert(items, MITCRDINTAVAIL);
	if (MitCrdIntActive == comp->MitCrdIntActive) insert(items, MITCRDINTACTIVE);
	if (MitCrdSigAvail == comp->MitCrdSigAvail) insert(items, MITCRDSIGAVAIL);
	if (MitCrdSigActive == comp->MitCrdSigActive) insert(items, MITCRDSIGACTIVE);
	if (MspCrd7Avail == comp->MspCrd7Avail) insert(items, MSPCRD7AVAIL);
	if (MitCrdCmpAvail == comp->MitCrdCmpAvail) insert(items, MITCRDCMPAVAIL);
	if (MitCrdRlsAvail == comp->MitCrdRlsAvail) insert(items, MITCRDRLSAVAIL);
	if (MitCrdRlsActive == comp->MitCrdRlsActive) insert(items, MITCRDRLSACTIVE);
	if (MspCrd8Avail == comp->MspCrd8Avail) insert(items, MSPCRD8AVAIL);
	if (MitCrdUtlAvail == comp->MitCrdUtlAvail) insert(items, MITCRDUTLAVAIL);
	if (MspApp2Avail == comp->MspApp2Avail) insert(items, MSPAPP2AVAIL);
	if (MitAppMlcAvail == comp->MitAppMlcAvail) insert(items, MITAPPMLCAVAIL);
	if (MitAppLoiAvail == comp->MitAppLoiAvail) insert(items, MITAPPLOIAVAIL);

	return(items);
};

set<uint> CrdWdbeNav::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SCRJREFDLGLOAINI, SCRJREFDLGMNGLIC, SCRJREFHEADBAR, SCRJREFPRE, PNLPREAVAIL, SCRJREFADMIN, PNLADMINAVAIL, SCRJREFGLOBAL, PNLGLOBALAVAIL, SCRJREFDEVDEV, PNLDEVDEVAVAIL, SCRJREFCOREDEV, PNLCOREDEVAVAIL, SCRJREFHIGH, PNLHIGHAVAIL, SCRJREFLOW, PNLLOWAVAIL, SCRJREFDEPLOY, PNLDEPLOYAVAIL, SCRJREFAUXFCT, PNLAUXFCTAVAIL, MITSESSPSAVAIL, MSPCRD1AVAIL, MITCRDUSGAVAIL, MITCRDUSRAVAIL, MITCRDPRSAVAIL, MITCRDFILAVAIL, MSPCRD2AVAIL, MITCRDMCHAVAIL, MITCRDLIBAVAIL, MITCRDFAMAVAIL, MITCRDSILAVAIL, MITCRDMTPAVAIL, MSPCRD3AVAIL, MITCRDPRJAVAIL, MITCRDVERAVAIL, MITCRDUNTAVAIL, MITCRDUNTACTIVE, MSPCRD4AVAIL, MITCRDCPRAVAIL, MITCRDCVRAVAIL, MSPCRD5AVAIL, MITCRDPPHAVAIL, MITCRDPPHACTIVE, MITCRDMODAVAIL, MITCRDMODACTIVE, MITCRDVECAVAIL, MITCRDVECACTIVE, MITCRDCMDAVAIL, MITCRDCMDACTIVE, MITCRDERRAVAIL, MITCRDERRACTIVE, MITCRDPPLAVAIL, MITCRDPPLACTIVE, MITCRDSEGAVAIL, MITCRDSEGACTIVE, MSPCRD6AVAIL, MITCRDBNKAVAIL, MITCRDBNKACTIVE, MITCRDPINAVAIL, MITCRDPINACTIVE, MITCRDINTAVAIL, MITCRDINTACTIVE, MITCRDSIGAVAIL, MITCRDSIGACTIVE, MSPCRD7AVAIL, MITCRDCMPAVAIL, MITCRDRLSAVAIL, MITCRDRLSACTIVE, MSPCRD8AVAIL, MITCRDUTLAVAIL, MSPAPP2AVAIL, MITAPPMLCAVAIL, MITAPPLOIAVAIL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWdbeNav::Tag
 ******************************************************************************/

CrdWdbeNav::Tag::Tag(
			const string& MitAppAbt
			, const string& MrlAppHlp
			, const string& MitSesSps
			, const string& MitSesTrm
			, const string& MitCrdUsg
			, const string& MitCrdUsr
			, const string& MitCrdPrs
			, const string& MitCrdFil
			, const string& MitCrdMch
			, const string& MitCrdLib
			, const string& MitCrdFam
			, const string& MitCrdSil
			, const string& MitCrdMtp
			, const string& MitCrdPrj
			, const string& MitCrdVer
			, const string& MitCrdUnt
			, const string& MitCrdCpr
			, const string& MitCrdCvr
			, const string& MitCrdPph
			, const string& MitCrdMod
			, const string& MitCrdVec
			, const string& MitCrdCmd
			, const string& MitCrdErr
			, const string& MitCrdPpl
			, const string& MitCrdSeg
			, const string& MitCrdBnk
			, const string& MitCrdPin
			, const string& MitCrdInt
			, const string& MitCrdSig
			, const string& MitCrdCmp
			, const string& MitCrdRls
			, const string& MitCrdUtl
			, const string& MitAppMlc
			, const string& MitAppLoi
		) :
			Block()
		{
	this->MitAppAbt = MitAppAbt;
	this->MrlAppHlp = MrlAppHlp;
	this->MitSesSps = MitSesSps;
	this->MitSesTrm = MitSesTrm;
	this->MitCrdUsg = MitCrdUsg;
	this->MitCrdUsr = MitCrdUsr;
	this->MitCrdPrs = MitCrdPrs;
	this->MitCrdFil = MitCrdFil;
	this->MitCrdMch = MitCrdMch;
	this->MitCrdLib = MitCrdLib;
	this->MitCrdFam = MitCrdFam;
	this->MitCrdSil = MitCrdSil;
	this->MitCrdMtp = MitCrdMtp;
	this->MitCrdPrj = MitCrdPrj;
	this->MitCrdVer = MitCrdVer;
	this->MitCrdUnt = MitCrdUnt;
	this->MitCrdCpr = MitCrdCpr;
	this->MitCrdCvr = MitCrdCvr;
	this->MitCrdPph = MitCrdPph;
	this->MitCrdMod = MitCrdMod;
	this->MitCrdVec = MitCrdVec;
	this->MitCrdCmd = MitCrdCmd;
	this->MitCrdErr = MitCrdErr;
	this->MitCrdPpl = MitCrdPpl;
	this->MitCrdSeg = MitCrdSeg;
	this->MitCrdBnk = MitCrdBnk;
	this->MitCrdPin = MitCrdPin;
	this->MitCrdInt = MitCrdInt;
	this->MitCrdSig = MitCrdSig;
	this->MitCrdCmp = MitCrdCmp;
	this->MitCrdRls = MitCrdRls;
	this->MitCrdUtl = MitCrdUtl;
	this->MitAppMlc = MitAppMlc;
	this->MitAppLoi = MitAppLoi;

	mask = {MITAPPABT, MRLAPPHLP, MITSESSPS, MITSESTRM, MITCRDUSG, MITCRDUSR, MITCRDPRS, MITCRDFIL, MITCRDMCH, MITCRDLIB, MITCRDFAM, MITCRDSIL, MITCRDMTP, MITCRDPRJ, MITCRDVER, MITCRDUNT, MITCRDCPR, MITCRDCVR, MITCRDPPH, MITCRDMOD, MITCRDVEC, MITCRDCMD, MITCRDERR, MITCRDPPL, MITCRDSEG, MITCRDBNK, MITCRDPIN, MITCRDINT, MITCRDSIG, MITCRDCMP, MITCRDRLS, MITCRDUTL, MITAPPMLC, MITAPPLOI};
};

bool CrdWdbeNav::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWdbeNav");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWdbeNav";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitAppAbt", MitAppAbt)) add(MITAPPABT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitSesSps", MitSesSps)) add(MITSESSPS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitSesTrm", MitSesTrm)) add(MITSESTRM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdUsg", MitCrdUsg)) add(MITCRDUSG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdUsr", MitCrdUsr)) add(MITCRDUSR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdPrs", MitCrdPrs)) add(MITCRDPRS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdFil", MitCrdFil)) add(MITCRDFIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdMch", MitCrdMch)) add(MITCRDMCH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdLib", MitCrdLib)) add(MITCRDLIB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdFam", MitCrdFam)) add(MITCRDFAM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdSil", MitCrdSil)) add(MITCRDSIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdMtp", MitCrdMtp)) add(MITCRDMTP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdPrj", MitCrdPrj)) add(MITCRDPRJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdVer", MitCrdVer)) add(MITCRDVER);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdUnt", MitCrdUnt)) add(MITCRDUNT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdCpr", MitCrdCpr)) add(MITCRDCPR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdCvr", MitCrdCvr)) add(MITCRDCVR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdPph", MitCrdPph)) add(MITCRDPPH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdMod", MitCrdMod)) add(MITCRDMOD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdVec", MitCrdVec)) add(MITCRDVEC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdCmd", MitCrdCmd)) add(MITCRDCMD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdErr", MitCrdErr)) add(MITCRDERR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdPpl", MitCrdPpl)) add(MITCRDPPL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdSeg", MitCrdSeg)) add(MITCRDSEG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdBnk", MitCrdBnk)) add(MITCRDBNK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdPin", MitCrdPin)) add(MITCRDPIN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdInt", MitCrdInt)) add(MITCRDINT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdSig", MitCrdSig)) add(MITCRDSIG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdCmp", MitCrdCmp)) add(MITCRDCMP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdRls", MitCrdRls)) add(MITCRDRLS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdUtl", MitCrdUtl)) add(MITCRDUTL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitAppMlc", MitAppMlc)) add(MITAPPMLC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitAppLoi", MitAppLoi)) add(MITAPPLOI);
	};

	return basefound;
};

/******************************************************************************
 class CrdWdbeNav::DpchAppDo
 ******************************************************************************/

CrdWdbeNav::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBENAVDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string CrdWdbeNav::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWdbeNav::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeNavDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWdbeNav::DpchEngData
 ******************************************************************************/

CrdWdbeNav::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBENAVDATA)
		{
	feedFSge.tag = "FeedFSge";
};

string CrdWdbeNav::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWdbeNav::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWdbeNavData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFSge.readXML(docctx, basexpath, true)) add(FEEDFSGE);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		continf = ContInf();
		feedFSge.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
