/**
	* \file CrdWdbeNav.h
	* job handler for job CrdWdbeNav (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef CRDWDBENAV_H
#define CRDWDBENAV_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlWdbeNavAuxfct.h"
#include "PnlWdbeNavDescr.h"
#include "PnlWdbeNavCoredev.h"
#include "PnlWdbeNavDevdev.h"
#include "PnlWdbeNavGlobal.h"
#include "PnlWdbeNavAdmin.h"
#include "PnlWdbeNavPre.h"
#include "PnlWdbeNavHeadbar.h"
#include "DlgWdbeNavLoaini.h"
#include "DlgWdbeNavMnglic.h"

#define VecVWdbeNavDo CrdWdbeNav::VecVDo
#define VecVWdbeNavSge CrdWdbeNav::VecVSge

#define ContInfWdbeNav CrdWdbeNav::ContInf
#define StatAppWdbeNav CrdWdbeNav::StatApp
#define StatShrWdbeNav CrdWdbeNav::StatShr
#define TagWdbeNav CrdWdbeNav::Tag

#define DpchAppWdbeNavDo CrdWdbeNav::DpchAppDo
#define DpchEngWdbeNavData CrdWdbeNav::DpchEngData

/**
	* CrdWdbeNav
	*/
class CrdWdbeNav : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVWdbeNavDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint CLOSE = 1;
		static const Sbecore::uint MITAPPABTCLICK = 2;
		static const Sbecore::uint MITSESSPSCLICK = 3;
		static const Sbecore::uint MITSESTRMCLICK = 4;
		static const Sbecore::uint MITCRDUSGCLICK = 5;
		static const Sbecore::uint MITCRDUSRCLICK = 6;
		static const Sbecore::uint MITCRDPRSCLICK = 7;
		static const Sbecore::uint MITCRDFILCLICK = 8;
		static const Sbecore::uint MITCRDMCHCLICK = 9;
		static const Sbecore::uint MITCRDLIBCLICK = 10;
		static const Sbecore::uint MITCRDFAMCLICK = 11;
		static const Sbecore::uint MITCRDSILCLICK = 12;
		static const Sbecore::uint MITCRDMTPCLICK = 13;
		static const Sbecore::uint MITCRDPRJCLICK = 14;
		static const Sbecore::uint MITCRDVERCLICK = 15;
		static const Sbecore::uint MITCRDSYSCLICK = 16;
		static const Sbecore::uint MITCRDTRGCLICK = 17;
		static const Sbecore::uint MITCRDUNTCLICK = 18;
		static const Sbecore::uint MITCRDRLSCLICK = 19;
		static const Sbecore::uint MITCRDCPRCLICK = 20;
		static const Sbecore::uint MITCRDCVRCLICK = 21;
		static const Sbecore::uint MITCRDMODCLICK = 22;
		static const Sbecore::uint MITCRDVECCLICK = 23;
		static const Sbecore::uint MITCRDCMDCLICK = 24;
		static const Sbecore::uint MITCRDERRCLICK = 25;
		static const Sbecore::uint MITCRDPPHCLICK = 26;
		static const Sbecore::uint MITCRDBNKCLICK = 27;
		static const Sbecore::uint MITCRDPINCLICK = 28;
		static const Sbecore::uint MITCRDUTLCLICK = 29;
		static const Sbecore::uint MITAPPMLCCLICK = 30;
		static const Sbecore::uint MITAPPLOICLICK = 31;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVWdbeNavSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRWDBEABT = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
	  * ContInf (full: ContInfWdbeNav)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint MRLAPPHLP = 2;
		static const Sbecore::uint MTXSESSES1 = 3;
		static const Sbecore::uint MTXSESSES2 = 4;
		static const Sbecore::uint MTXSESSES3 = 5;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& MrlAppHlp = "", const std::string& MtxSesSes1 = "", const std::string& MtxSesSes2 = "", const std::string& MtxSesSes3 = "");

	public:
		Sbecore::uint numFSge;
		std::string MrlAppHlp;
		std::string MtxSesSes1;
		std::string MtxSesSes2;
		std::string MtxSesSes3;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWdbeNav)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWdbeVReqitmode = VecWdbeVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdonePre = false, const bool initdoneAdmin = false, const bool initdoneGlobal = false, const bool initdoneDevdev = false, const bool initdoneCoredev = false, const bool initdoneDescr = false, const bool initdoneAuxfct = false);
	};

	/**
		* StatShr (full: StatShrWdbeNav)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint JREFDLGLOAINI = 1;
		static const Sbecore::uint JREFDLGMNGLIC = 2;
		static const Sbecore::uint JREFHEADBAR = 3;
		static const Sbecore::uint JREFPRE = 4;
		static const Sbecore::uint PNLPREAVAIL = 5;
		static const Sbecore::uint JREFADMIN = 6;
		static const Sbecore::uint PNLADMINAVAIL = 7;
		static const Sbecore::uint JREFGLOBAL = 8;
		static const Sbecore::uint PNLGLOBALAVAIL = 9;
		static const Sbecore::uint JREFDEVDEV = 10;
		static const Sbecore::uint PNLDEVDEVAVAIL = 11;
		static const Sbecore::uint JREFCOREDEV = 12;
		static const Sbecore::uint PNLCOREDEVAVAIL = 13;
		static const Sbecore::uint JREFDESCR = 14;
		static const Sbecore::uint PNLDESCRAVAIL = 15;
		static const Sbecore::uint JREFAUXFCT = 16;
		static const Sbecore::uint PNLAUXFCTAVAIL = 17;
		static const Sbecore::uint MITSESSPSAVAIL = 18;
		static const Sbecore::uint MSPCRD1AVAIL = 19;
		static const Sbecore::uint MITCRDUSGAVAIL = 20;
		static const Sbecore::uint MITCRDUSRAVAIL = 21;
		static const Sbecore::uint MITCRDPRSAVAIL = 22;
		static const Sbecore::uint MITCRDFILAVAIL = 23;
		static const Sbecore::uint MSPCRD2AVAIL = 24;
		static const Sbecore::uint MITCRDMCHAVAIL = 25;
		static const Sbecore::uint MITCRDLIBAVAIL = 26;
		static const Sbecore::uint MITCRDFAMAVAIL = 27;
		static const Sbecore::uint MITCRDSILAVAIL = 28;
		static const Sbecore::uint MITCRDMTPAVAIL = 29;
		static const Sbecore::uint MSPCRD3AVAIL = 30;
		static const Sbecore::uint MITCRDPRJAVAIL = 31;
		static const Sbecore::uint MITCRDVERAVAIL = 32;
		static const Sbecore::uint MITCRDSYSAVAIL = 33;
		static const Sbecore::uint MITCRDSYSACTIVE = 34;
		static const Sbecore::uint MITCRDTRGAVAIL = 35;
		static const Sbecore::uint MITCRDTRGACTIVE = 36;
		static const Sbecore::uint MITCRDUNTAVAIL = 37;
		static const Sbecore::uint MITCRDUNTACTIVE = 38;
		static const Sbecore::uint MITCRDRLSAVAIL = 39;
		static const Sbecore::uint MITCRDRLSACTIVE = 40;
		static const Sbecore::uint MSPCRD4AVAIL = 41;
		static const Sbecore::uint MITCRDCPRAVAIL = 42;
		static const Sbecore::uint MITCRDCVRAVAIL = 43;
		static const Sbecore::uint MSPCRD5AVAIL = 44;
		static const Sbecore::uint MITCRDMODAVAIL = 45;
		static const Sbecore::uint MITCRDMODACTIVE = 46;
		static const Sbecore::uint MITCRDVECAVAIL = 47;
		static const Sbecore::uint MITCRDVECACTIVE = 48;
		static const Sbecore::uint MITCRDCMDAVAIL = 49;
		static const Sbecore::uint MITCRDCMDACTIVE = 50;
		static const Sbecore::uint MITCRDERRAVAIL = 51;
		static const Sbecore::uint MITCRDERRACTIVE = 52;
		static const Sbecore::uint MITCRDPPHAVAIL = 53;
		static const Sbecore::uint MITCRDPPHACTIVE = 54;
		static const Sbecore::uint MITCRDBNKAVAIL = 55;
		static const Sbecore::uint MITCRDBNKACTIVE = 56;
		static const Sbecore::uint MITCRDPINAVAIL = 57;
		static const Sbecore::uint MITCRDPINACTIVE = 58;
		static const Sbecore::uint MSPCRD6AVAIL = 59;
		static const Sbecore::uint MITCRDUTLAVAIL = 60;
		static const Sbecore::uint MSPAPP2AVAIL = 61;
		static const Sbecore::uint MITAPPMLCAVAIL = 62;
		static const Sbecore::uint MITAPPLOIAVAIL = 63;

	public:
		StatShr(const Sbecore::ubigint jrefDlgloaini = 0, const Sbecore::ubigint jrefDlgmnglic = 0, const Sbecore::ubigint jrefHeadbar = 0, const Sbecore::ubigint jrefPre = 0, const bool pnlpreAvail = false, const Sbecore::ubigint jrefAdmin = 0, const bool pnladminAvail = false, const Sbecore::ubigint jrefGlobal = 0, const bool pnlglobalAvail = false, const Sbecore::ubigint jrefDevdev = 0, const bool pnldevdevAvail = false, const Sbecore::ubigint jrefCoredev = 0, const bool pnlcoredevAvail = false, const Sbecore::ubigint jrefDescr = 0, const bool pnldescrAvail = false, const Sbecore::ubigint jrefAuxfct = 0, const bool pnlauxfctAvail = false, const bool MitSesSpsAvail = true, const bool MspCrd1Avail = true, const bool MitCrdUsgAvail = true, const bool MitCrdUsrAvail = true, const bool MitCrdPrsAvail = true, const bool MitCrdFilAvail = true, const bool MspCrd2Avail = true, const bool MitCrdMchAvail = true, const bool MitCrdLibAvail = true, const bool MitCrdFamAvail = true, const bool MitCrdSilAvail = true, const bool MitCrdMtpAvail = true, const bool MspCrd3Avail = true, const bool MitCrdPrjAvail = true, const bool MitCrdVerAvail = true, const bool MitCrdSysAvail = true, const bool MitCrdSysActive = true, const bool MitCrdTrgAvail = true, const bool MitCrdTrgActive = true, const bool MitCrdUntAvail = true, const bool MitCrdUntActive = true, const bool MitCrdRlsAvail = true, const bool MitCrdRlsActive = true, const bool MspCrd4Avail = true, const bool MitCrdCprAvail = true, const bool MitCrdCvrAvail = true, const bool MspCrd5Avail = true, const bool MitCrdModAvail = true, const bool MitCrdModActive = true, const bool MitCrdVecAvail = true, const bool MitCrdVecActive = true, const bool MitCrdCmdAvail = true, const bool MitCrdCmdActive = true, const bool MitCrdErrAvail = true, const bool MitCrdErrActive = true, const bool MitCrdPphAvail = true, const bool MitCrdPphActive = true, const bool MitCrdBnkAvail = true, const bool MitCrdBnkActive = true, const bool MitCrdPinAvail = true, const bool MitCrdPinActive = true, const bool MspCrd6Avail = true, const bool MitCrdUtlAvail = true, const bool MspApp2Avail = true, const bool MitAppMlcAvail = true, const bool MitAppLoiAvail = true);

	public:
		Sbecore::ubigint jrefDlgloaini;
		Sbecore::ubigint jrefDlgmnglic;
		Sbecore::ubigint jrefHeadbar;
		Sbecore::ubigint jrefPre;
		bool pnlpreAvail;
		Sbecore::ubigint jrefAdmin;
		bool pnladminAvail;
		Sbecore::ubigint jrefGlobal;
		bool pnlglobalAvail;
		Sbecore::ubigint jrefDevdev;
		bool pnldevdevAvail;
		Sbecore::ubigint jrefCoredev;
		bool pnlcoredevAvail;
		Sbecore::ubigint jrefDescr;
		bool pnldescrAvail;
		Sbecore::ubigint jrefAuxfct;
		bool pnlauxfctAvail;
		bool MitSesSpsAvail;
		bool MspCrd1Avail;
		bool MitCrdUsgAvail;
		bool MitCrdUsrAvail;
		bool MitCrdPrsAvail;
		bool MitCrdFilAvail;
		bool MspCrd2Avail;
		bool MitCrdMchAvail;
		bool MitCrdLibAvail;
		bool MitCrdFamAvail;
		bool MitCrdSilAvail;
		bool MitCrdMtpAvail;
		bool MspCrd3Avail;
		bool MitCrdPrjAvail;
		bool MitCrdVerAvail;
		bool MitCrdSysAvail;
		bool MitCrdSysActive;
		bool MitCrdTrgAvail;
		bool MitCrdTrgActive;
		bool MitCrdUntAvail;
		bool MitCrdUntActive;
		bool MitCrdRlsAvail;
		bool MitCrdRlsActive;
		bool MspCrd4Avail;
		bool MitCrdCprAvail;
		bool MitCrdCvrAvail;
		bool MspCrd5Avail;
		bool MitCrdModAvail;
		bool MitCrdModActive;
		bool MitCrdVecAvail;
		bool MitCrdVecActive;
		bool MitCrdCmdAvail;
		bool MitCrdCmdActive;
		bool MitCrdErrAvail;
		bool MitCrdErrActive;
		bool MitCrdPphAvail;
		bool MitCrdPphActive;
		bool MitCrdBnkAvail;
		bool MitCrdBnkActive;
		bool MitCrdPinAvail;
		bool MitCrdPinActive;
		bool MspCrd6Avail;
		bool MitCrdUtlAvail;
		bool MspApp2Avail;
		bool MitAppMlcAvail;
		bool MitAppLoiAvail;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWdbeNav)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWdbeNavDo)
		*/
	class DpchAppDo : public DpchAppWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint IXVDO = 2;

	public:
		DpchAppDo();

	public:
		Sbecore::uint ixVDo;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngWdbeNavData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint FEEDFSGE = 3;
		static const Sbecore::uint STATAPP = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint TAG = 6;
		static const Sbecore::uint ALL = 7;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFSge = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContInf continf;
		Sbecore::Xmlio::Feed feedFSge;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalPnlpreAvail(DbsWdbe* dbswdbe);
	bool evalPnladminAvail(DbsWdbe* dbswdbe);
	bool evalPnlglobalAvail(DbsWdbe* dbswdbe);
	bool evalPnldevdevAvail(DbsWdbe* dbswdbe);
	bool evalPnlcoredevAvail(DbsWdbe* dbswdbe);
	bool evalPnldescrAvail(DbsWdbe* dbswdbe);
	bool evalPnlauxfctAvail(DbsWdbe* dbswdbe);
	bool evalMitSesSpsAvail(DbsWdbe* dbswdbe);
	bool evalMspCrd1Avail(DbsWdbe* dbswdbe);
	bool evalMitCrdUsgAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdUsrAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdPrsAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdFilAvail(DbsWdbe* dbswdbe);
	bool evalMspCrd2Avail(DbsWdbe* dbswdbe);
	bool evalMitCrdMchAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdLibAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdFamAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdSilAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdMtpAvail(DbsWdbe* dbswdbe);
	bool evalMspCrd3Avail(DbsWdbe* dbswdbe);
	bool evalMitCrdPrjAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdVerAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdSysAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdSysActive(DbsWdbe* dbswdbe);
	bool evalMitCrdTrgAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdTrgActive(DbsWdbe* dbswdbe);
	bool evalMitCrdUntAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdUntActive(DbsWdbe* dbswdbe);
	bool evalMitCrdRlsAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdRlsActive(DbsWdbe* dbswdbe);
	bool evalMspCrd4Avail(DbsWdbe* dbswdbe);
	bool evalMitCrdCprAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdCvrAvail(DbsWdbe* dbswdbe);
	bool evalMspCrd5Avail(DbsWdbe* dbswdbe);
	bool evalMitCrdModAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdModActive(DbsWdbe* dbswdbe);
	bool evalMitCrdVecAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdVecActive(DbsWdbe* dbswdbe);
	bool evalMitCrdCmdAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdCmdActive(DbsWdbe* dbswdbe);
	bool evalMitCrdErrAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdErrActive(DbsWdbe* dbswdbe);
	bool evalMitCrdPphAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdPphActive(DbsWdbe* dbswdbe);
	bool evalMitCrdBnkAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdBnkActive(DbsWdbe* dbswdbe);
	bool evalMitCrdPinAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdPinActive(DbsWdbe* dbswdbe);
	bool evalMspCrd6Avail(DbsWdbe* dbswdbe);
	bool evalMitCrdUtlAvail(DbsWdbe* dbswdbe);
	bool evalMspApp2Avail(DbsWdbe* dbswdbe);
	bool evalMitAppMlcAvail(DbsWdbe* dbswdbe);
	bool evalMitAppLoiAvail(DbsWdbe* dbswdbe);

public:
	CrdWdbeNav(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~CrdWdbeNav();

public:
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFMcbAlert;
	Sbecore::Xmlio::Feed feedFSge;

	PnlWdbeNavAuxfct* pnlauxfct;
	PnlWdbeNavDescr* pnldescr;
	PnlWdbeNavCoredev* pnlcoredev;
	PnlWdbeNavDevdev* pnldevdev;
	PnlWdbeNavGlobal* pnlglobal;
	PnlWdbeNavAdmin* pnladmin;
	PnlWdbeNavPre* pnlpre;
	PnlWdbeNavHeadbar* pnlheadbar;
	DlgWdbeNavLoaini* dlgloaini;
	DlgWdbeNavMnglic* dlgmnglic;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);
	void refresh(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems, const bool unmute = false);
	void updatePreset(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:

	void handleDpchAppWdbeInit(DbsWdbe* dbswdbe, DpchAppWdbeInit* dpchappwdbeinit, DpchEngWdbe** dpcheng);

	void handleDpchAppDoClose(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitAppAbtClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitSesSpsClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitSesTrmClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdUsgClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdUsrClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdPrsClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdFilClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdMchClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdLibClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdFamClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdSilClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdMtpClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdPrjClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdVerClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdSysClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdTrgClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdUntClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdRlsClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdCprClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdCvrClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdModClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdVecClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdCmdClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdErrClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdPphClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdBnkClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdPinClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdUtlClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitAppMlcClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitAppLoiClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppWdbeAlert(DbsWdbe* dbswdbe, DpchAppWdbeAlert* dpchappwdbealert, DpchEngWdbe** dpcheng);

public:
	void handleCall(DbsWdbe* dbswdbe, Sbecore::Call* call);

private:
	bool handleCallWdbeDlgClose(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);

private:
	void changeStage(DbsWdbe* dbswdbe, Sbecore::uint _ixVSge, DpchEngWdbe** dpcheng = NULL);

public:
	std::string getSquawk(DbsWdbe* dbswdbe);

private:
	Sbecore::uint enterSgeIdle(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeIdle(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeAlrwdbeabt(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeAlrwdbeabt(DbsWdbe* dbswdbe);

};

#endif



