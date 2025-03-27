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
#include "PnlWdbeNavDeploy.h"
#include "PnlWdbeNavLow.h"
#include "PnlWdbeNavHigh.h"
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
		static const Sbecore::uint MITCRDPRFCLICK = 9;
		static const Sbecore::uint MITCRDMCHCLICK = 10;
		static const Sbecore::uint MITCRDLIBCLICK = 11;
		static const Sbecore::uint MITCRDFAMCLICK = 12;
		static const Sbecore::uint MITCRDSILCLICK = 13;
		static const Sbecore::uint MITCRDMTPCLICK = 14;
		static const Sbecore::uint MITCRDPRJCLICK = 15;
		static const Sbecore::uint MITCRDVERCLICK = 16;
		static const Sbecore::uint MITCRDUNTCLICK = 17;
		static const Sbecore::uint MITCRDCPRCLICK = 18;
		static const Sbecore::uint MITCRDCVRCLICK = 19;
		static const Sbecore::uint MITCRDPPHCLICK = 20;
		static const Sbecore::uint MITCRDMODCLICK = 21;
		static const Sbecore::uint MITCRDVECCLICK = 22;
		static const Sbecore::uint MITCRDCMDCLICK = 23;
		static const Sbecore::uint MITCRDERRCLICK = 24;
		static const Sbecore::uint MITCRDPPLCLICK = 25;
		static const Sbecore::uint MITCRDSEGCLICK = 26;
		static const Sbecore::uint MITCRDBNKCLICK = 27;
		static const Sbecore::uint MITCRDPINCLICK = 28;
		static const Sbecore::uint MITCRDINTCLICK = 29;
		static const Sbecore::uint MITCRDSIGCLICK = 30;
		static const Sbecore::uint MITCRDCMPCLICK = 31;
		static const Sbecore::uint MITCRDRLSCLICK = 32;
		static const Sbecore::uint MITCRDUTLCLICK = 33;
		static const Sbecore::uint MITAPPMLCCLICK = 34;
		static const Sbecore::uint MITAPPLOICLICK = 35;

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
		static const Sbecore::uint ALRWDBETRM = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
	  * ContInf (full: ContInfWdbeNav)
	  */
	class ContInf : public Sbecore::Block {

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
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWdbeNav)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWdbeVReqitmode = VecWdbeVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdonePre = false, const bool initdoneAdmin = false, const bool initdoneGlobal = false, const bool initdoneDevdev = false, const bool initdoneCoredev = false, const bool initdoneHigh = false, const bool initdoneLow = false, const bool initdoneDeploy = false, const bool initdoneAuxfct = false);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWdbeVReqitmode = VecWdbeVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdonePre = false, const bool initdoneAdmin = false, const bool initdoneGlobal = false, const bool initdoneDevdev = false, const bool initdoneCoredev = false, const bool initdoneHigh = false, const bool initdoneLow = false, const bool initdoneDeploy = false, const bool initdoneAuxfct = false);
	};

	/**
		* StatShr (full: StatShrWdbeNav)
		*/
	class StatShr : public Sbecore::Block {

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
		static const Sbecore::uint JREFHIGH = 14;
		static const Sbecore::uint PNLHIGHAVAIL = 15;
		static const Sbecore::uint JREFLOW = 16;
		static const Sbecore::uint PNLLOWAVAIL = 17;
		static const Sbecore::uint JREFDEPLOY = 18;
		static const Sbecore::uint PNLDEPLOYAVAIL = 19;
		static const Sbecore::uint JREFAUXFCT = 20;
		static const Sbecore::uint PNLAUXFCTAVAIL = 21;
		static const Sbecore::uint MITSESSPSAVAIL = 22;
		static const Sbecore::uint MSPCRD1AVAIL = 23;
		static const Sbecore::uint MITCRDUSGAVAIL = 24;
		static const Sbecore::uint MITCRDUSRAVAIL = 25;
		static const Sbecore::uint MITCRDPRSAVAIL = 26;
		static const Sbecore::uint MITCRDFILAVAIL = 27;
		static const Sbecore::uint MITCRDPRFAVAIL = 28;
		static const Sbecore::uint MSPCRD2AVAIL = 29;
		static const Sbecore::uint MITCRDMCHAVAIL = 30;
		static const Sbecore::uint MITCRDLIBAVAIL = 31;
		static const Sbecore::uint MITCRDFAMAVAIL = 32;
		static const Sbecore::uint MITCRDSILAVAIL = 33;
		static const Sbecore::uint MITCRDMTPAVAIL = 34;
		static const Sbecore::uint MSPCRD3AVAIL = 35;
		static const Sbecore::uint MITCRDPRJAVAIL = 36;
		static const Sbecore::uint MITCRDVERAVAIL = 37;
		static const Sbecore::uint MITCRDUNTAVAIL = 38;
		static const Sbecore::uint MITCRDUNTACTIVE = 39;
		static const Sbecore::uint MSPCRD4AVAIL = 40;
		static const Sbecore::uint MITCRDCPRAVAIL = 41;
		static const Sbecore::uint MITCRDCVRAVAIL = 42;
		static const Sbecore::uint MSPCRD5AVAIL = 43;
		static const Sbecore::uint MITCRDPPHAVAIL = 44;
		static const Sbecore::uint MITCRDPPHACTIVE = 45;
		static const Sbecore::uint MITCRDMODAVAIL = 46;
		static const Sbecore::uint MITCRDMODACTIVE = 47;
		static const Sbecore::uint MITCRDVECAVAIL = 48;
		static const Sbecore::uint MITCRDVECACTIVE = 49;
		static const Sbecore::uint MITCRDCMDAVAIL = 50;
		static const Sbecore::uint MITCRDCMDACTIVE = 51;
		static const Sbecore::uint MITCRDERRAVAIL = 52;
		static const Sbecore::uint MITCRDERRACTIVE = 53;
		static const Sbecore::uint MITCRDPPLAVAIL = 54;
		static const Sbecore::uint MITCRDPPLACTIVE = 55;
		static const Sbecore::uint MITCRDSEGAVAIL = 56;
		static const Sbecore::uint MITCRDSEGACTIVE = 57;
		static const Sbecore::uint MSPCRD6AVAIL = 58;
		static const Sbecore::uint MITCRDBNKAVAIL = 59;
		static const Sbecore::uint MITCRDBNKACTIVE = 60;
		static const Sbecore::uint MITCRDPINAVAIL = 61;
		static const Sbecore::uint MITCRDPINACTIVE = 62;
		static const Sbecore::uint MITCRDINTAVAIL = 63;
		static const Sbecore::uint MITCRDINTACTIVE = 64;
		static const Sbecore::uint MITCRDSIGAVAIL = 65;
		static const Sbecore::uint MITCRDSIGACTIVE = 66;
		static const Sbecore::uint MSPCRD7AVAIL = 67;
		static const Sbecore::uint MITCRDCMPAVAIL = 68;
		static const Sbecore::uint MITCRDRLSAVAIL = 69;
		static const Sbecore::uint MITCRDRLSACTIVE = 70;
		static const Sbecore::uint MSPCRD8AVAIL = 71;
		static const Sbecore::uint MITCRDUTLAVAIL = 72;
		static const Sbecore::uint MSPAPP2AVAIL = 73;
		static const Sbecore::uint MITAPPMLCAVAIL = 74;
		static const Sbecore::uint MITAPPLOIAVAIL = 75;

	public:
		StatShr(const Sbecore::ubigint jrefDlgloaini = 0, const Sbecore::ubigint jrefDlgmnglic = 0, const Sbecore::ubigint jrefHeadbar = 0, const Sbecore::ubigint jrefPre = 0, const bool pnlpreAvail = false, const Sbecore::ubigint jrefAdmin = 0, const bool pnladminAvail = false, const Sbecore::ubigint jrefGlobal = 0, const bool pnlglobalAvail = false, const Sbecore::ubigint jrefDevdev = 0, const bool pnldevdevAvail = false, const Sbecore::ubigint jrefCoredev = 0, const bool pnlcoredevAvail = false, const Sbecore::ubigint jrefHigh = 0, const bool pnlhighAvail = false, const Sbecore::ubigint jrefLow = 0, const bool pnllowAvail = false, const Sbecore::ubigint jrefDeploy = 0, const bool pnldeployAvail = false, const Sbecore::ubigint jrefAuxfct = 0, const bool pnlauxfctAvail = false, const bool MitSesSpsAvail = true, const bool MspCrd1Avail = true, const bool MitCrdUsgAvail = true, const bool MitCrdUsrAvail = true, const bool MitCrdPrsAvail = true, const bool MitCrdFilAvail = true, const bool MitCrdPrfAvail = true, const bool MspCrd2Avail = true, const bool MitCrdMchAvail = true, const bool MitCrdLibAvail = true, const bool MitCrdFamAvail = true, const bool MitCrdSilAvail = true, const bool MitCrdMtpAvail = true, const bool MspCrd3Avail = true, const bool MitCrdPrjAvail = true, const bool MitCrdVerAvail = true, const bool MitCrdUntAvail = true, const bool MitCrdUntActive = true, const bool MspCrd4Avail = true, const bool MitCrdCprAvail = true, const bool MitCrdCvrAvail = true, const bool MspCrd5Avail = true, const bool MitCrdPphAvail = true, const bool MitCrdPphActive = true, const bool MitCrdModAvail = true, const bool MitCrdModActive = true, const bool MitCrdVecAvail = true, const bool MitCrdVecActive = true, const bool MitCrdCmdAvail = true, const bool MitCrdCmdActive = true, const bool MitCrdErrAvail = true, const bool MitCrdErrActive = true, const bool MitCrdPplAvail = true, const bool MitCrdPplActive = true, const bool MitCrdSegAvail = true, const bool MitCrdSegActive = true, const bool MspCrd6Avail = true, const bool MitCrdBnkAvail = true, const bool MitCrdBnkActive = true, const bool MitCrdPinAvail = true, const bool MitCrdPinActive = true, const bool MitCrdIntAvail = true, const bool MitCrdIntActive = true, const bool MitCrdSigAvail = true, const bool MitCrdSigActive = true, const bool MspCrd7Avail = true, const bool MitCrdCmpAvail = true, const bool MitCrdRlsAvail = true, const bool MitCrdRlsActive = true, const bool MspCrd8Avail = true, const bool MitCrdUtlAvail = true, const bool MspApp2Avail = true, const bool MitAppMlcAvail = true, const bool MitAppLoiAvail = true);

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
		Sbecore::ubigint jrefHigh;
		bool pnlhighAvail;
		Sbecore::ubigint jrefLow;
		bool pnllowAvail;
		Sbecore::ubigint jrefDeploy;
		bool pnldeployAvail;
		Sbecore::ubigint jrefAuxfct;
		bool pnlauxfctAvail;
		bool MitSesSpsAvail;
		bool MspCrd1Avail;
		bool MitCrdUsgAvail;
		bool MitCrdUsrAvail;
		bool MitCrdPrsAvail;
		bool MitCrdFilAvail;
		bool MitCrdPrfAvail;
		bool MspCrd2Avail;
		bool MitCrdMchAvail;
		bool MitCrdLibAvail;
		bool MitCrdFamAvail;
		bool MitCrdSilAvail;
		bool MitCrdMtpAvail;
		bool MspCrd3Avail;
		bool MitCrdPrjAvail;
		bool MitCrdVerAvail;
		bool MitCrdUntAvail;
		bool MitCrdUntActive;
		bool MspCrd4Avail;
		bool MitCrdCprAvail;
		bool MitCrdCvrAvail;
		bool MspCrd5Avail;
		bool MitCrdPphAvail;
		bool MitCrdPphActive;
		bool MitCrdModAvail;
		bool MitCrdModActive;
		bool MitCrdVecAvail;
		bool MitCrdVecActive;
		bool MitCrdCmdAvail;
		bool MitCrdCmdActive;
		bool MitCrdErrAvail;
		bool MitCrdErrActive;
		bool MitCrdPplAvail;
		bool MitCrdPplActive;
		bool MitCrdSegAvail;
		bool MitCrdSegActive;
		bool MspCrd6Avail;
		bool MitCrdBnkAvail;
		bool MitCrdBnkActive;
		bool MitCrdPinAvail;
		bool MitCrdPinActive;
		bool MitCrdIntAvail;
		bool MitCrdIntActive;
		bool MitCrdSigAvail;
		bool MitCrdSigActive;
		bool MspCrd7Avail;
		bool MitCrdCmpAvail;
		bool MitCrdRlsAvail;
		bool MitCrdRlsActive;
		bool MspCrd8Avail;
		bool MitCrdUtlAvail;
		bool MspApp2Avail;
		bool MitAppMlcAvail;
		bool MitAppLoiAvail;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWdbeNav)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
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

		void readJSON(const Json::Value& sup, bool addbasetag = false);
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
		DpchEngData(const Sbecore::ubigint jref = 0, ContInf* continf = NULL, Sbecore::Feed* feedFSge = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContInf continf;
		Sbecore::Feed feedFSge;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalPnlpreAvail(DbsWdbe* dbswdbe);
	bool evalPnladminAvail(DbsWdbe* dbswdbe);
	bool evalPnlglobalAvail(DbsWdbe* dbswdbe);
	bool evalPnldevdevAvail(DbsWdbe* dbswdbe);
	bool evalPnlcoredevAvail(DbsWdbe* dbswdbe);
	bool evalPnlhighAvail(DbsWdbe* dbswdbe);
	bool evalPnllowAvail(DbsWdbe* dbswdbe);
	bool evalPnldeployAvail(DbsWdbe* dbswdbe);
	bool evalPnlauxfctAvail(DbsWdbe* dbswdbe);
	bool evalMitSesSpsAvail(DbsWdbe* dbswdbe);
	bool evalMspCrd1Avail(DbsWdbe* dbswdbe);
	bool evalMitCrdUsgAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdUsrAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdPrsAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdFilAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdPrfAvail(DbsWdbe* dbswdbe);
	bool evalMspCrd2Avail(DbsWdbe* dbswdbe);
	bool evalMitCrdMchAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdLibAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdFamAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdSilAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdMtpAvail(DbsWdbe* dbswdbe);
	bool evalMspCrd3Avail(DbsWdbe* dbswdbe);
	bool evalMitCrdPrjAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdVerAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdUntAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdUntActive(DbsWdbe* dbswdbe);
	bool evalMspCrd4Avail(DbsWdbe* dbswdbe);
	bool evalMitCrdCprAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdCvrAvail(DbsWdbe* dbswdbe);
	bool evalMspCrd5Avail(DbsWdbe* dbswdbe);
	bool evalMitCrdPphAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdPphActive(DbsWdbe* dbswdbe);
	bool evalMitCrdModAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdModActive(DbsWdbe* dbswdbe);
	bool evalMitCrdVecAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdVecActive(DbsWdbe* dbswdbe);
	bool evalMitCrdCmdAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdCmdActive(DbsWdbe* dbswdbe);
	bool evalMitCrdErrAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdErrActive(DbsWdbe* dbswdbe);
	bool evalMitCrdPplAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdPplActive(DbsWdbe* dbswdbe);
	bool evalMitCrdSegAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdSegActive(DbsWdbe* dbswdbe);
	bool evalMspCrd6Avail(DbsWdbe* dbswdbe);
	bool evalMitCrdBnkAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdBnkActive(DbsWdbe* dbswdbe);
	bool evalMitCrdPinAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdPinActive(DbsWdbe* dbswdbe);
	bool evalMitCrdIntAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdIntActive(DbsWdbe* dbswdbe);
	bool evalMitCrdSigAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdSigActive(DbsWdbe* dbswdbe);
	bool evalMspCrd7Avail(DbsWdbe* dbswdbe);
	bool evalMitCrdCmpAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdRlsAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdRlsActive(DbsWdbe* dbswdbe);
	bool evalMspCrd8Avail(DbsWdbe* dbswdbe);
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

	Sbecore::Feed feedFMcbAlert;
	Sbecore::Feed feedFSge;

	PnlWdbeNavAuxfct* pnlauxfct;
	PnlWdbeNavDeploy* pnldeploy;
	PnlWdbeNavLow* pnllow;
	PnlWdbeNavHigh* pnlhigh;
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
	void warnTerm(DbsWdbe* dbswdbe);

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
	void handleDpchAppDoMitCrdPrfClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdMchClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdLibClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdFamClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdSilClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdMtpClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdPrjClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdVerClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdUntClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdCprClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdCvrClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdPphClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdModClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdVecClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdCmdClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdErrClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdPplClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdSegClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdBnkClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdPinClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdIntClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdSigClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdCmpClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdRlsClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
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
	Sbecore::uint enterSgeAlrwdbetrm(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeAlrwdbetrm(DbsWdbe* dbswdbe);

};

#endif
