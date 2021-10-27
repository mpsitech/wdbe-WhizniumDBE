/**
	* \file CrdWdbeVer.h
	* job handler for job CrdWdbeVer (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef CRDWDBEVER_H
#define CRDWDBEVER_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "DlgWdbeVerCmdset.h"
#include "DlgWdbeVerCustfst.h"
#include "DlgWdbeVerDflalg.h"
#include "DlgWdbeVerFinmod.h"
#include "DlgWdbeVerGenfst.h"
#include "DlgWdbeVerMdlstr.h"
#include "DlgWdbeVerNew.h"
#include "PnlWdbeVerRec.h"
#include "PnlWdbeVerHeadbar.h"
#include "PnlWdbeVerList.h"

#define VecVWdbeVerDo CrdWdbeVer::VecVDo
#define VecVWdbeVerSge CrdWdbeVer::VecVSge

#define ContInfWdbeVer CrdWdbeVer::ContInf
#define StatAppWdbeVer CrdWdbeVer::StatApp
#define StatShrWdbeVer CrdWdbeVer::StatShr
#define TagWdbeVer CrdWdbeVer::Tag

#define DpchAppWdbeVerDo CrdWdbeVer::DpchAppDo
#define DpchEngWdbeVerData CrdWdbeVer::DpchEngData

/**
	* CrdWdbeVer
	*/
class CrdWdbeVer : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVWdbeVerDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint CLOSE = 1;
		static const Sbecore::uint MITAPPABTCLICK = 2;
		static const Sbecore::uint MITCRDNEWCLICK = 3;
		static const Sbecore::uint MITCRDPCVCLICK = 4;
		static const Sbecore::uint MITCRDIMDCLICK = 5;
		static const Sbecore::uint MITCRDICSCLICK = 6;
		static const Sbecore::uint MITCRDIDACLICK = 7;
		static const Sbecore::uint MITCRDGFSCLICK = 8;
		static const Sbecore::uint MITCRDIFSCLICK = 9;
		static const Sbecore::uint MITCRDFNMCLICK = 10;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVWdbeVerSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRWDBEABT = 2;
		static const Sbecore::uint ALRCVW = 3;
		static const Sbecore::uint SETPRJCVR = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
	  * ContInf (full: ContInfWdbeVer)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint MRLAPPHLP = 2;
		static const Sbecore::uint MTXCRDVER = 3;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& MrlAppHlp = "", const std::string& MtxCrdVer = "");

	public:
		Sbecore::uint numFSge;
		std::string MrlAppHlp;
		std::string MtxCrdVer;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWdbeVer)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWdbeVReqitmode = VecWdbeVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneList = false, const bool initdoneRec = false);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWdbeVReqitmode = VecWdbeVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneList = false, const bool initdoneRec = false);
	};

	/**
		* StatShr (full: StatShrWdbeVer)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint JREFDLGCMDSET = 1;
		static const Sbecore::uint JREFDLGCUSTFST = 2;
		static const Sbecore::uint JREFDLGDFLALG = 3;
		static const Sbecore::uint JREFDLGFINMOD = 4;
		static const Sbecore::uint JREFDLGGENFST = 5;
		static const Sbecore::uint JREFDLGMDLSTR = 6;
		static const Sbecore::uint JREFDLGNEW = 7;
		static const Sbecore::uint JREFHEADBAR = 8;
		static const Sbecore::uint JREFLIST = 9;
		static const Sbecore::uint JREFREC = 10;
		static const Sbecore::uint MSPCRD1AVAIL = 11;
		static const Sbecore::uint MITCRDNEWAVAIL = 12;
		static const Sbecore::uint MITCRDPCVAVAIL = 13;
		static const Sbecore::uint MITCRDPCVACTIVE = 14;
		static const Sbecore::uint MSPCRD3AVAIL = 15;
		static const Sbecore::uint MSPCRD3ACTIVE = 16;
		static const Sbecore::uint MITCRDIMDAVAIL = 17;
		static const Sbecore::uint MITCRDIMDACTIVE = 18;
		static const Sbecore::uint MITCRDICSAVAIL = 19;
		static const Sbecore::uint MITCRDICSACTIVE = 20;
		static const Sbecore::uint MITCRDIDAAVAIL = 21;
		static const Sbecore::uint MITCRDIDAACTIVE = 22;
		static const Sbecore::uint MSPCRD4AVAIL = 23;
		static const Sbecore::uint MSPCRD4ACTIVE = 24;
		static const Sbecore::uint MITCRDGFSAVAIL = 25;
		static const Sbecore::uint MITCRDGFSACTIVE = 26;
		static const Sbecore::uint MITCRDIFSAVAIL = 27;
		static const Sbecore::uint MITCRDIFSACTIVE = 28;
		static const Sbecore::uint MSPCRD5AVAIL = 29;
		static const Sbecore::uint MSPCRD5ACTIVE = 30;
		static const Sbecore::uint MITCRDFNMAVAIL = 31;
		static const Sbecore::uint MITCRDFNMACTIVE = 32;

	public:
		StatShr(const Sbecore::ubigint jrefDlgcmdset = 0, const Sbecore::ubigint jrefDlgcustfst = 0, const Sbecore::ubigint jrefDlgdflalg = 0, const Sbecore::ubigint jrefDlgfinmod = 0, const Sbecore::ubigint jrefDlggenfst = 0, const Sbecore::ubigint jrefDlgmdlstr = 0, const Sbecore::ubigint jrefDlgnew = 0, const Sbecore::ubigint jrefHeadbar = 0, const Sbecore::ubigint jrefList = 0, const Sbecore::ubigint jrefRec = 0, const bool MspCrd1Avail = true, const bool MitCrdNewAvail = true, const bool MitCrdPcvAvail = true, const bool MitCrdPcvActive = true, const bool MspCrd3Avail = true, const bool MspCrd3Active = true, const bool MitCrdImdAvail = true, const bool MitCrdImdActive = true, const bool MitCrdIcsAvail = true, const bool MitCrdIcsActive = true, const bool MitCrdIdaAvail = true, const bool MitCrdIdaActive = true, const bool MspCrd4Avail = true, const bool MspCrd4Active = true, const bool MitCrdGfsAvail = true, const bool MitCrdGfsActive = true, const bool MitCrdIfsAvail = true, const bool MitCrdIfsActive = true, const bool MspCrd5Avail = true, const bool MspCrd5Active = true, const bool MitCrdFnmAvail = true, const bool MitCrdFnmActive = true);

	public:
		Sbecore::ubigint jrefDlgcmdset;
		Sbecore::ubigint jrefDlgcustfst;
		Sbecore::ubigint jrefDlgdflalg;
		Sbecore::ubigint jrefDlgfinmod;
		Sbecore::ubigint jrefDlggenfst;
		Sbecore::ubigint jrefDlgmdlstr;
		Sbecore::ubigint jrefDlgnew;
		Sbecore::ubigint jrefHeadbar;
		Sbecore::ubigint jrefList;
		Sbecore::ubigint jrefRec;
		bool MspCrd1Avail;
		bool MitCrdNewAvail;
		bool MitCrdPcvAvail;
		bool MitCrdPcvActive;
		bool MspCrd3Avail;
		bool MspCrd3Active;
		bool MitCrdImdAvail;
		bool MitCrdImdActive;
		bool MitCrdIcsAvail;
		bool MitCrdIcsActive;
		bool MitCrdIdaAvail;
		bool MitCrdIdaActive;
		bool MspCrd4Avail;
		bool MspCrd4Active;
		bool MitCrdGfsAvail;
		bool MitCrdGfsActive;
		bool MitCrdIfsAvail;
		bool MitCrdIfsActive;
		bool MspCrd5Avail;
		bool MspCrd5Active;
		bool MitCrdFnmAvail;
		bool MitCrdFnmActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWdbeVer)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWdbeVerDo)
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

		void readJSON(Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngWdbeVerData)
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

	bool evalMspCrd1Avail(DbsWdbe* dbswdbe);
	bool evalMitCrdNewAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdPcvAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdPcvActive(DbsWdbe* dbswdbe);
	bool evalMspCrd3Avail(DbsWdbe* dbswdbe);
	bool evalMspCrd3Active(DbsWdbe* dbswdbe);
	bool evalMitCrdImdAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdImdActive(DbsWdbe* dbswdbe);
	bool evalMitCrdIcsAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdIcsActive(DbsWdbe* dbswdbe);
	bool evalMitCrdIdaAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdIdaActive(DbsWdbe* dbswdbe);
	bool evalMspCrd4Avail(DbsWdbe* dbswdbe);
	bool evalMspCrd4Active(DbsWdbe* dbswdbe);
	bool evalMitCrdGfsAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdGfsActive(DbsWdbe* dbswdbe);
	bool evalMitCrdIfsAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdIfsActive(DbsWdbe* dbswdbe);
	bool evalMspCrd5Avail(DbsWdbe* dbswdbe);
	bool evalMspCrd5Active(DbsWdbe* dbswdbe);
	bool evalMitCrdFnmAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdFnmActive(DbsWdbe* dbswdbe);

public:
	CrdWdbeVer(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale, const Sbecore::ubigint ref = 0, const Sbecore::uint ixWdbeVPreset = VecWdbeVPreset::VOID, const Sbecore::ubigint preUref = 0);
	~CrdWdbeVer();

public:
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFMcbAlert;
	Sbecore::Feed feedFSge;

	DlgWdbeVerCmdset* dlgcmdset;
	DlgWdbeVerCustfst* dlgcustfst;
	DlgWdbeVerDflalg* dlgdflalg;
	DlgWdbeVerFinmod* dlgfinmod;
	DlgWdbeVerGenfst* dlggenfst;
	DlgWdbeVerMdlstr* dlgmdlstr;
	DlgWdbeVerNew* dlgnew;
	PnlWdbeVerRec* pnlrec;
	PnlWdbeVerHeadbar* pnlheadbar;
	PnlWdbeVerList* pnllist;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);
	void refresh(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems, const bool unmute = false);
	void changeRef(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint ref, const bool notif = false);
	void updatePreset(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:

	void handleDpchAppWdbeInit(DbsWdbe* dbswdbe, DpchAppWdbeInit* dpchappwdbeinit, DpchEngWdbe** dpcheng);

	void handleDpchAppDoClose(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitAppAbtClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdNewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdPcvClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdImdClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdIcsClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdIdaClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdGfsClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdIfsClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdFnmClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppWdbeAlert(DbsWdbe* dbswdbe, DpchAppWdbeAlert* dpchappwdbealert, DpchEngWdbe** dpcheng);

public:
	void handleCall(DbsWdbe* dbswdbe, Sbecore::Call* call);

private:
	bool handleCallWdbeDlgClose(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);
	bool handleCallWdbeStatChg(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);
	bool handleCallWdbeRefPreSet(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);

private:
	void changeStage(DbsWdbe* dbswdbe, Sbecore::uint _ixVSge, DpchEngWdbe** dpcheng = NULL);

public:
	std::string getSquawk(DbsWdbe* dbswdbe);

private:
	Sbecore::uint enterSgeIdle(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeIdle(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeAlrwdbeabt(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeAlrwdbeabt(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeAlrcvw(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeAlrcvw(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeSetprjcvr(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeSetprjcvr(DbsWdbe* dbswdbe);

};

#endif
