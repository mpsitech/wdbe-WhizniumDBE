/**
	* \file CrdWdbeNav_blks.cpp
	* job handler for job CrdWdbeNav (implementation of blocks)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

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
	if (s == "mitcrdsysclick") return MITCRDSYSCLICK;
	if (s == "mitcrdtrgclick") return MITCRDTRGCLICK;
	if (s == "mitcrduntclick") return MITCRDUNTCLICK;
	if (s == "mitcrdrlsclick") return MITCRDRLSCLICK;
	if (s == "mitcrdcprclick") return MITCRDCPRCLICK;
	if (s == "mitcrdcvrclick") return MITCRDCVRCLICK;
	if (s == "mitcrdmodclick") return MITCRDMODCLICK;
	if (s == "mitcrdvecclick") return MITCRDVECCLICK;
	if (s == "mitcrdcmdclick") return MITCRDCMDCLICK;
	if (s == "mitcrderrclick") return MITCRDERRCLICK;
	if (s == "mitcrdpphclick") return MITCRDPPHCLICK;
	if (s == "mitcrdbnkclick") return MITCRDBNKCLICK;
	if (s == "mitcrdpinclick") return MITCRDPINCLICK;
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
	if (ix == MITCRDSYSCLICK) return("MitCrdSysClick");
	if (ix == MITCRDTRGCLICK) return("MitCrdTrgClick");
	if (ix == MITCRDUNTCLICK) return("MitCrdUntClick");
	if (ix == MITCRDRLSCLICK) return("MitCrdRlsClick");
	if (ix == MITCRDCPRCLICK) return("MitCrdCprClick");
	if (ix == MITCRDCVRCLICK) return("MitCrdCvrClick");
	if (ix == MITCRDMODCLICK) return("MitCrdModClick");
	if (ix == MITCRDVECCLICK) return("MitCrdVecClick");
	if (ix == MITCRDCMDCLICK) return("MitCrdCmdClick");
	if (ix == MITCRDERRCLICK) return("MitCrdErrClick");
	if (ix == MITCRDPPHCLICK) return("MitCrdPphClick");
	if (ix == MITCRDBNKCLICK) return("MitCrdBnkClick");
	if (ix == MITCRDPINCLICK) return("MitCrdPinClick");
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

	return(0);
};

string CrdWdbeNav::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRWDBEABT) return("alrwdbeabt");

	return("");
};

void CrdWdbeNav::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
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

void CrdWdbeNav::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbeNav";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWdbeNav";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", MrlAppHlp);
		writeStringAttr(wr, itemtag, "sref", "MtxSesSes1", MtxSesSes1);
		writeStringAttr(wr, itemtag, "sref", "MtxSesSes2", MtxSesSes2);
		writeStringAttr(wr, itemtag, "sref", "MtxSesSes3", MtxSesSes3);
	xmlTextWriterEndElement(wr);
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

void CrdWdbeNav::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWdbeVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdonePre
			, const bool initdoneAdmin
			, const bool initdoneGlobal
			, const bool initdoneDevdev
			, const bool initdoneCoredev
			, const bool initdoneDescr
			, const bool initdoneAuxfct
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeNav";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWdbeNav";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWdbeVReqitmode", VecWdbeVReqitmode::getSref(ixWdbeVReqitmode));
		writeUsmallintAttr(wr, itemtag, "sref", "latency", latency);
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
		writeUintAttr(wr, itemtag, "sref", "widthMenu", widthMenu);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHeadbar", initdoneHeadbar);
		writeBoolAttr(wr, itemtag, "sref", "initdonePre", initdonePre);
		writeBoolAttr(wr, itemtag, "sref", "initdoneAdmin", initdoneAdmin);
		writeBoolAttr(wr, itemtag, "sref", "initdoneGlobal", initdoneGlobal);
		writeBoolAttr(wr, itemtag, "sref", "initdoneDevdev", initdoneDevdev);
		writeBoolAttr(wr, itemtag, "sref", "initdoneCoredev", initdoneCoredev);
		writeBoolAttr(wr, itemtag, "sref", "initdoneDescr", initdoneDescr);
		writeBoolAttr(wr, itemtag, "sref", "initdoneAuxfct", initdoneAuxfct);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWdbeNav::StatShr
 ******************************************************************************/

CrdWdbeNav::StatShr::StatShr(
			const ubigint jrefDlgloaini
			, const ubigint jrefDlgmnglic
			, const ubigint jrefHeadbar
			, const ubigint jrefPre
			, const bool pnlpreAvail
			, const ubigint jrefAdmin
			, const bool pnladminAvail
			, const ubigint jrefGlobal
			, const bool pnlglobalAvail
			, const ubigint jrefDevdev
			, const bool pnldevdevAvail
			, const ubigint jrefCoredev
			, const bool pnlcoredevAvail
			, const ubigint jrefDescr
			, const bool pnldescrAvail
			, const ubigint jrefAuxfct
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
			, const bool MitCrdSysAvail
			, const bool MitCrdSysActive
			, const bool MitCrdTrgAvail
			, const bool MitCrdTrgActive
			, const bool MitCrdUntAvail
			, const bool MitCrdUntActive
			, const bool MitCrdRlsAvail
			, const bool MitCrdRlsActive
			, const bool MspCrd4Avail
			, const bool MitCrdCprAvail
			, const bool MitCrdCvrAvail
			, const bool MspCrd5Avail
			, const bool MitCrdModAvail
			, const bool MitCrdModActive
			, const bool MitCrdVecAvail
			, const bool MitCrdVecActive
			, const bool MitCrdCmdAvail
			, const bool MitCrdCmdActive
			, const bool MitCrdErrAvail
			, const bool MitCrdErrActive
			, const bool MitCrdPphAvail
			, const bool MitCrdPphActive
			, const bool MitCrdBnkAvail
			, const bool MitCrdBnkActive
			, const bool MitCrdPinAvail
			, const bool MitCrdPinActive
			, const bool MspCrd6Avail
			, const bool MitCrdUtlAvail
			, const bool MspApp2Avail
			, const bool MitAppMlcAvail
			, const bool MitAppLoiAvail
		) :
			Block()
		{
	this->jrefDlgloaini = jrefDlgloaini;
	this->jrefDlgmnglic = jrefDlgmnglic;
	this->jrefHeadbar = jrefHeadbar;
	this->jrefPre = jrefPre;
	this->pnlpreAvail = pnlpreAvail;
	this->jrefAdmin = jrefAdmin;
	this->pnladminAvail = pnladminAvail;
	this->jrefGlobal = jrefGlobal;
	this->pnlglobalAvail = pnlglobalAvail;
	this->jrefDevdev = jrefDevdev;
	this->pnldevdevAvail = pnldevdevAvail;
	this->jrefCoredev = jrefCoredev;
	this->pnlcoredevAvail = pnlcoredevAvail;
	this->jrefDescr = jrefDescr;
	this->pnldescrAvail = pnldescrAvail;
	this->jrefAuxfct = jrefAuxfct;
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
	this->MitCrdSysAvail = MitCrdSysAvail;
	this->MitCrdSysActive = MitCrdSysActive;
	this->MitCrdTrgAvail = MitCrdTrgAvail;
	this->MitCrdTrgActive = MitCrdTrgActive;
	this->MitCrdUntAvail = MitCrdUntAvail;
	this->MitCrdUntActive = MitCrdUntActive;
	this->MitCrdRlsAvail = MitCrdRlsAvail;
	this->MitCrdRlsActive = MitCrdRlsActive;
	this->MspCrd4Avail = MspCrd4Avail;
	this->MitCrdCprAvail = MitCrdCprAvail;
	this->MitCrdCvrAvail = MitCrdCvrAvail;
	this->MspCrd5Avail = MspCrd5Avail;
	this->MitCrdModAvail = MitCrdModAvail;
	this->MitCrdModActive = MitCrdModActive;
	this->MitCrdVecAvail = MitCrdVecAvail;
	this->MitCrdVecActive = MitCrdVecActive;
	this->MitCrdCmdAvail = MitCrdCmdAvail;
	this->MitCrdCmdActive = MitCrdCmdActive;
	this->MitCrdErrAvail = MitCrdErrAvail;
	this->MitCrdErrActive = MitCrdErrActive;
	this->MitCrdPphAvail = MitCrdPphAvail;
	this->MitCrdPphActive = MitCrdPphActive;
	this->MitCrdBnkAvail = MitCrdBnkAvail;
	this->MitCrdBnkActive = MitCrdBnkActive;
	this->MitCrdPinAvail = MitCrdPinAvail;
	this->MitCrdPinActive = MitCrdPinActive;
	this->MspCrd6Avail = MspCrd6Avail;
	this->MitCrdUtlAvail = MitCrdUtlAvail;
	this->MspApp2Avail = MspApp2Avail;
	this->MitAppMlcAvail = MitAppMlcAvail;
	this->MitAppLoiAvail = MitAppLoiAvail;

	mask = {JREFDLGLOAINI, JREFDLGMNGLIC, JREFHEADBAR, JREFPRE, PNLPREAVAIL, JREFADMIN, PNLADMINAVAIL, JREFGLOBAL, PNLGLOBALAVAIL, JREFDEVDEV, PNLDEVDEVAVAIL, JREFCOREDEV, PNLCOREDEVAVAIL, JREFDESCR, PNLDESCRAVAIL, JREFAUXFCT, PNLAUXFCTAVAIL, MITSESSPSAVAIL, MSPCRD1AVAIL, MITCRDUSGAVAIL, MITCRDUSRAVAIL, MITCRDPRSAVAIL, MITCRDFILAVAIL, MSPCRD2AVAIL, MITCRDMCHAVAIL, MITCRDLIBAVAIL, MITCRDFAMAVAIL, MITCRDSILAVAIL, MITCRDMTPAVAIL, MSPCRD3AVAIL, MITCRDPRJAVAIL, MITCRDVERAVAIL, MITCRDSYSAVAIL, MITCRDSYSACTIVE, MITCRDTRGAVAIL, MITCRDTRGACTIVE, MITCRDUNTAVAIL, MITCRDUNTACTIVE, MITCRDRLSAVAIL, MITCRDRLSACTIVE, MSPCRD4AVAIL, MITCRDCPRAVAIL, MITCRDCVRAVAIL, MSPCRD5AVAIL, MITCRDMODAVAIL, MITCRDMODACTIVE, MITCRDVECAVAIL, MITCRDVECACTIVE, MITCRDCMDAVAIL, MITCRDCMDACTIVE, MITCRDERRAVAIL, MITCRDERRACTIVE, MITCRDPPHAVAIL, MITCRDPPHACTIVE, MITCRDBNKAVAIL, MITCRDBNKACTIVE, MITCRDPINAVAIL, MITCRDPINACTIVE, MSPCRD6AVAIL, MITCRDUTLAVAIL, MSPAPP2AVAIL, MITAPPMLCAVAIL, MITAPPLOIAVAIL};
};

void CrdWdbeNav::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeNav";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWdbeNav";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgloaini", Scr::scramble(jrefDlgloaini));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgmnglic", Scr::scramble(jrefDlgmnglic));
		writeStringAttr(wr, itemtag, "sref", "scrJrefHeadbar", Scr::scramble(jrefHeadbar));
		writeStringAttr(wr, itemtag, "sref", "scrJrefPre", Scr::scramble(jrefPre));
		writeBoolAttr(wr, itemtag, "sref", "pnlpreAvail", pnlpreAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefAdmin", Scr::scramble(jrefAdmin));
		writeBoolAttr(wr, itemtag, "sref", "pnladminAvail", pnladminAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefGlobal", Scr::scramble(jrefGlobal));
		writeBoolAttr(wr, itemtag, "sref", "pnlglobalAvail", pnlglobalAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefDevdev", Scr::scramble(jrefDevdev));
		writeBoolAttr(wr, itemtag, "sref", "pnldevdevAvail", pnldevdevAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefCoredev", Scr::scramble(jrefCoredev));
		writeBoolAttr(wr, itemtag, "sref", "pnlcoredevAvail", pnlcoredevAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefDescr", Scr::scramble(jrefDescr));
		writeBoolAttr(wr, itemtag, "sref", "pnldescrAvail", pnldescrAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefAuxfct", Scr::scramble(jrefAuxfct));
		writeBoolAttr(wr, itemtag, "sref", "pnlauxfctAvail", pnlauxfctAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitSesSpsAvail", MitSesSpsAvail);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd1Avail", MspCrd1Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdUsgAvail", MitCrdUsgAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdUsrAvail", MitCrdUsrAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdPrsAvail", MitCrdPrsAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdFilAvail", MitCrdFilAvail);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd2Avail", MspCrd2Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdMchAvail", MitCrdMchAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdLibAvail", MitCrdLibAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdFamAvail", MitCrdFamAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdSilAvail", MitCrdSilAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdMtpAvail", MitCrdMtpAvail);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd3Avail", MspCrd3Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdPrjAvail", MitCrdPrjAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdVerAvail", MitCrdVerAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdSysAvail", MitCrdSysAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdSysActive", MitCrdSysActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdTrgAvail", MitCrdTrgAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdTrgActive", MitCrdTrgActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdUntAvail", MitCrdUntAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdUntActive", MitCrdUntActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdRlsAvail", MitCrdRlsAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdRlsActive", MitCrdRlsActive);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd4Avail", MspCrd4Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdCprAvail", MitCrdCprAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdCvrAvail", MitCrdCvrAvail);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd5Avail", MspCrd5Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdModAvail", MitCrdModAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdModActive", MitCrdModActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdVecAvail", MitCrdVecAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdVecActive", MitCrdVecActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdCmdAvail", MitCrdCmdAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdCmdActive", MitCrdCmdActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdErrAvail", MitCrdErrAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdErrActive", MitCrdErrActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdPphAvail", MitCrdPphAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdPphActive", MitCrdPphActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdBnkAvail", MitCrdBnkAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdBnkActive", MitCrdBnkActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdPinAvail", MitCrdPinAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdPinActive", MitCrdPinActive);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd6Avail", MspCrd6Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdUtlAvail", MitCrdUtlAvail);
		writeBoolAttr(wr, itemtag, "sref", "MspApp2Avail", MspApp2Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitAppMlcAvail", MitAppMlcAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitAppLoiAvail", MitAppLoiAvail);
	xmlTextWriterEndElement(wr);
};

set<uint> CrdWdbeNav::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (jrefDlgloaini == comp->jrefDlgloaini) insert(items, JREFDLGLOAINI);
	if (jrefDlgmnglic == comp->jrefDlgmnglic) insert(items, JREFDLGMNGLIC);
	if (jrefHeadbar == comp->jrefHeadbar) insert(items, JREFHEADBAR);
	if (jrefPre == comp->jrefPre) insert(items, JREFPRE);
	if (pnlpreAvail == comp->pnlpreAvail) insert(items, PNLPREAVAIL);
	if (jrefAdmin == comp->jrefAdmin) insert(items, JREFADMIN);
	if (pnladminAvail == comp->pnladminAvail) insert(items, PNLADMINAVAIL);
	if (jrefGlobal == comp->jrefGlobal) insert(items, JREFGLOBAL);
	if (pnlglobalAvail == comp->pnlglobalAvail) insert(items, PNLGLOBALAVAIL);
	if (jrefDevdev == comp->jrefDevdev) insert(items, JREFDEVDEV);
	if (pnldevdevAvail == comp->pnldevdevAvail) insert(items, PNLDEVDEVAVAIL);
	if (jrefCoredev == comp->jrefCoredev) insert(items, JREFCOREDEV);
	if (pnlcoredevAvail == comp->pnlcoredevAvail) insert(items, PNLCOREDEVAVAIL);
	if (jrefDescr == comp->jrefDescr) insert(items, JREFDESCR);
	if (pnldescrAvail == comp->pnldescrAvail) insert(items, PNLDESCRAVAIL);
	if (jrefAuxfct == comp->jrefAuxfct) insert(items, JREFAUXFCT);
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
	if (MitCrdSysAvail == comp->MitCrdSysAvail) insert(items, MITCRDSYSAVAIL);
	if (MitCrdSysActive == comp->MitCrdSysActive) insert(items, MITCRDSYSACTIVE);
	if (MitCrdTrgAvail == comp->MitCrdTrgAvail) insert(items, MITCRDTRGAVAIL);
	if (MitCrdTrgActive == comp->MitCrdTrgActive) insert(items, MITCRDTRGACTIVE);
	if (MitCrdUntAvail == comp->MitCrdUntAvail) insert(items, MITCRDUNTAVAIL);
	if (MitCrdUntActive == comp->MitCrdUntActive) insert(items, MITCRDUNTACTIVE);
	if (MitCrdRlsAvail == comp->MitCrdRlsAvail) insert(items, MITCRDRLSAVAIL);
	if (MitCrdRlsActive == comp->MitCrdRlsActive) insert(items, MITCRDRLSACTIVE);
	if (MspCrd4Avail == comp->MspCrd4Avail) insert(items, MSPCRD4AVAIL);
	if (MitCrdCprAvail == comp->MitCrdCprAvail) insert(items, MITCRDCPRAVAIL);
	if (MitCrdCvrAvail == comp->MitCrdCvrAvail) insert(items, MITCRDCVRAVAIL);
	if (MspCrd5Avail == comp->MspCrd5Avail) insert(items, MSPCRD5AVAIL);
	if (MitCrdModAvail == comp->MitCrdModAvail) insert(items, MITCRDMODAVAIL);
	if (MitCrdModActive == comp->MitCrdModActive) insert(items, MITCRDMODACTIVE);
	if (MitCrdVecAvail == comp->MitCrdVecAvail) insert(items, MITCRDVECAVAIL);
	if (MitCrdVecActive == comp->MitCrdVecActive) insert(items, MITCRDVECACTIVE);
	if (MitCrdCmdAvail == comp->MitCrdCmdAvail) insert(items, MITCRDCMDAVAIL);
	if (MitCrdCmdActive == comp->MitCrdCmdActive) insert(items, MITCRDCMDACTIVE);
	if (MitCrdErrAvail == comp->MitCrdErrAvail) insert(items, MITCRDERRAVAIL);
	if (MitCrdErrActive == comp->MitCrdErrActive) insert(items, MITCRDERRACTIVE);
	if (MitCrdPphAvail == comp->MitCrdPphAvail) insert(items, MITCRDPPHAVAIL);
	if (MitCrdPphActive == comp->MitCrdPphActive) insert(items, MITCRDPPHACTIVE);
	if (MitCrdBnkAvail == comp->MitCrdBnkAvail) insert(items, MITCRDBNKAVAIL);
	if (MitCrdBnkActive == comp->MitCrdBnkActive) insert(items, MITCRDBNKACTIVE);
	if (MitCrdPinAvail == comp->MitCrdPinAvail) insert(items, MITCRDPINAVAIL);
	if (MitCrdPinActive == comp->MitCrdPinActive) insert(items, MITCRDPINACTIVE);
	if (MspCrd6Avail == comp->MspCrd6Avail) insert(items, MSPCRD6AVAIL);
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

	diffitems = {JREFDLGLOAINI, JREFDLGMNGLIC, JREFHEADBAR, JREFPRE, PNLPREAVAIL, JREFADMIN, PNLADMINAVAIL, JREFGLOBAL, PNLGLOBALAVAIL, JREFDEVDEV, PNLDEVDEVAVAIL, JREFCOREDEV, PNLCOREDEVAVAIL, JREFDESCR, PNLDESCRAVAIL, JREFAUXFCT, PNLAUXFCTAVAIL, MITSESSPSAVAIL, MSPCRD1AVAIL, MITCRDUSGAVAIL, MITCRDUSRAVAIL, MITCRDPRSAVAIL, MITCRDFILAVAIL, MSPCRD2AVAIL, MITCRDMCHAVAIL, MITCRDLIBAVAIL, MITCRDFAMAVAIL, MITCRDSILAVAIL, MITCRDMTPAVAIL, MSPCRD3AVAIL, MITCRDPRJAVAIL, MITCRDVERAVAIL, MITCRDSYSAVAIL, MITCRDSYSACTIVE, MITCRDTRGAVAIL, MITCRDTRGACTIVE, MITCRDUNTAVAIL, MITCRDUNTACTIVE, MITCRDRLSAVAIL, MITCRDRLSACTIVE, MSPCRD4AVAIL, MITCRDCPRAVAIL, MITCRDCVRAVAIL, MSPCRD5AVAIL, MITCRDMODAVAIL, MITCRDMODACTIVE, MITCRDVECAVAIL, MITCRDVECACTIVE, MITCRDCMDAVAIL, MITCRDCMDACTIVE, MITCRDERRAVAIL, MITCRDERRACTIVE, MITCRDPPHAVAIL, MITCRDPPHACTIVE, MITCRDBNKAVAIL, MITCRDBNKACTIVE, MITCRDPINAVAIL, MITCRDPINACTIVE, MSPCRD6AVAIL, MITCRDUTLAVAIL, MSPAPP2AVAIL, MITAPPMLCAVAIL, MITAPPLOIAVAIL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWdbeNav::Tag
 ******************************************************************************/

void CrdWdbeNav::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWdbeNav";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWdbeNav";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MitCrdUsg", "User groups ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdUsr", "Users ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdPrs", "Persons ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdFil", "Files ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdMch", "Machines ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdLib", "Libraries ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdFam", "Product families ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdSil", "Silicon devices ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdMtp", "Module templates ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdPrj", "Projects ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdVer", "Versions ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdSys", "Systems ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdTrg", "Targets ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdUnt", "Units ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdRls", "Releases ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdCpr", "Core projects ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdCvr", "Core versions ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdMod", "Modules ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdVec", "Vectors ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdCmd", "Commands ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdErr", "Errors ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdPph", "Peripherals ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdBnk", "I/O banks ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdPin", "Pins ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdUtl", "Utilities ...");
			writeStringAttr(wr, itemtag, "sref", "MitAppMlc", "Manage licenses ...");
		};
		writeStringAttr(wr, itemtag, "sref", "MitAppAbt", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::ABOUT, ixWdbeVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::HELP, ixWdbeVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "MitSesSps", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::SUSPSESS, ixWdbeVLocale)));
		writeStringAttr(wr, itemtag, "sref", "MitSesTrm", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::CLSESS, ixWdbeVLocale)));
		writeStringAttr(wr, itemtag, "sref", "MitAppLoi", StrMod::cap(VecWdbeVTag::getTitle(VecWdbeVTag::LOAINI, ixWdbeVLocale)) + " ...");
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWdbeNav::DpchAppDo
 ******************************************************************************/

CrdWdbeNav::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBENAVDO)
		{
	ixVDo = 0;
};

string CrdWdbeNav::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWdbeNav::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeNavDo");
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
 class CrdWdbeNav::DpchEngData
 ******************************************************************************/

CrdWdbeNav::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFSge
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBENAVDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFSGE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string CrdWdbeNav::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWdbeNav::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void CrdWdbeNav::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWdbeNavData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};

