/**
	* \file CrdWdbeCvr.h
	* job handler for job CrdWdbeCvr (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef CRDWDBECVR_H
#define CRDWDBECVR_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "DlgWdbeCvrBsccd.h"
#include "DlgWdbeCvrDetcd.h"
#include "DlgWdbeCvrNew.h"
#include "DlgWdbeCvrWrite.h"
#include "PnlWdbeCvrRec.h"
#include "PnlWdbeCvrHeadbar.h"
#include "PnlWdbeCvrList.h"

#define VecVWdbeCvrDo CrdWdbeCvr::VecVDo
#define VecVWdbeCvrSge CrdWdbeCvr::VecVSge

#define ContInfWdbeCvr CrdWdbeCvr::ContInf
#define StatAppWdbeCvr CrdWdbeCvr::StatApp
#define StatShrWdbeCvr CrdWdbeCvr::StatShr
#define TagWdbeCvr CrdWdbeCvr::Tag

#define DpchAppWdbeCvrDo CrdWdbeCvr::DpchAppDo
#define DpchEngWdbeCvrData CrdWdbeCvr::DpchEngData

/**
	* CrdWdbeCvr
	*/
class CrdWdbeCvr : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVWdbeCvrDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint CLOSE = 1;
		static const Sbecore::uint MITAPPABTCLICK = 2;
		static const Sbecore::uint MITCRDNEWCLICK = 3;
		static const Sbecore::uint MITCRDIBSCLICK = 4;
		static const Sbecore::uint MITCRDIDSCLICK = 5;
		static const Sbecore::uint MITCRDWCOCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVWdbeCvrSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRWDBEABT = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
	  * ContInf (full: ContInfWdbeCvr)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint MRLAPPHLP = 2;
		static const Sbecore::uint MTXCRDCVR = 3;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& MrlAppHlp = "", const std::string& MtxCrdCvr = "");

	public:
		Sbecore::uint numFSge;
		std::string MrlAppHlp;
		std::string MtxCrdCvr;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWdbeCvr)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWdbeVReqitmode = VecWdbeVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneList = false, const bool initdoneRec = false);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWdbeVReqitmode = VecWdbeVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneList = false, const bool initdoneRec = false);
	};

	/**
		* StatShr (full: StatShrWdbeCvr)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint JREFDLGBSCCD = 1;
		static const Sbecore::uint JREFDLGDETCD = 2;
		static const Sbecore::uint JREFDLGNEW = 3;
		static const Sbecore::uint JREFDLGWRITE = 4;
		static const Sbecore::uint JREFHEADBAR = 5;
		static const Sbecore::uint JREFLIST = 6;
		static const Sbecore::uint JREFREC = 7;
		static const Sbecore::uint MSPCRD1AVAIL = 8;
		static const Sbecore::uint MITCRDNEWAVAIL = 9;
		static const Sbecore::uint MITCRDIBSAVAIL = 10;
		static const Sbecore::uint MITCRDIBSACTIVE = 11;
		static const Sbecore::uint MITCRDIDSAVAIL = 12;
		static const Sbecore::uint MITCRDIDSACTIVE = 13;
		static const Sbecore::uint MSPCRD2AVAIL = 14;
		static const Sbecore::uint MITCRDWCOAVAIL = 15;
		static const Sbecore::uint MITCRDWCOACTIVE = 16;

	public:
		StatShr(const Sbecore::ubigint jrefDlgbsccd = 0, const Sbecore::ubigint jrefDlgdetcd = 0, const Sbecore::ubigint jrefDlgnew = 0, const Sbecore::ubigint jrefDlgwrite = 0, const Sbecore::ubigint jrefHeadbar = 0, const Sbecore::ubigint jrefList = 0, const Sbecore::ubigint jrefRec = 0, const bool MspCrd1Avail = true, const bool MitCrdNewAvail = true, const bool MitCrdIbsAvail = true, const bool MitCrdIbsActive = true, const bool MitCrdIdsAvail = true, const bool MitCrdIdsActive = true, const bool MspCrd2Avail = true, const bool MitCrdWcoAvail = true, const bool MitCrdWcoActive = true);

	public:
		Sbecore::ubigint jrefDlgbsccd;
		Sbecore::ubigint jrefDlgdetcd;
		Sbecore::ubigint jrefDlgnew;
		Sbecore::ubigint jrefDlgwrite;
		Sbecore::ubigint jrefHeadbar;
		Sbecore::ubigint jrefList;
		Sbecore::ubigint jrefRec;
		bool MspCrd1Avail;
		bool MitCrdNewAvail;
		bool MitCrdIbsAvail;
		bool MitCrdIbsActive;
		bool MitCrdIdsAvail;
		bool MitCrdIdsActive;
		bool MspCrd2Avail;
		bool MitCrdWcoAvail;
		bool MitCrdWcoActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWdbeCvr)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWdbeCvrDo)
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
		* DpchEngData (full: DpchEngWdbeCvrData)
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
	bool evalMitCrdIbsAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdIbsActive(DbsWdbe* dbswdbe);
	bool evalMitCrdIdsAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdIdsActive(DbsWdbe* dbswdbe);
	bool evalMspCrd2Avail(DbsWdbe* dbswdbe);
	bool evalMitCrdWcoAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdWcoActive(DbsWdbe* dbswdbe);

public:
	CrdWdbeCvr(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale, const Sbecore::ubigint ref = 0, const Sbecore::uint ixWdbeVPreset = VecWdbeVPreset::VOID, const Sbecore::ubigint preUref = 0);
	~CrdWdbeCvr();

public:
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFMcbAlert;
	Sbecore::Feed feedFSge;

	DlgWdbeCvrBsccd* dlgbsccd;
	DlgWdbeCvrDetcd* dlgdetcd;
	DlgWdbeCvrNew* dlgnew;
	DlgWdbeCvrWrite* dlgwrite;
	PnlWdbeCvrRec* pnlrec;
	PnlWdbeCvrHeadbar* pnlheadbar;
	PnlWdbeCvrList* pnllist;

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
	void handleDpchAppDoMitCrdIbsClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdIdsClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdWcoClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
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

};

#endif
