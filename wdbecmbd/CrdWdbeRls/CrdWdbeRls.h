/**
	* \file CrdWdbeRls.h
	* job handler for job CrdWdbeRls (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef CRDWDBERLS_H
#define CRDWDBERLS_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlWdbeRlsList.h"
#include "PnlWdbeRlsHeadbar.h"
#include "PnlWdbeRlsRec.h"
#include "DlgWdbeRlsFinreptr.h"
#include "DlgWdbeRlsNew.h"
#include "DlgWdbeRlsStareptr.h"
#include "DlgWdbeRlsWrite.h"

#define VecVWdbeRlsDo CrdWdbeRls::VecVDo
#define VecVWdbeRlsSge CrdWdbeRls::VecVSge

#define ContInfWdbeRls CrdWdbeRls::ContInf
#define StatAppWdbeRls CrdWdbeRls::StatApp
#define StatShrWdbeRls CrdWdbeRls::StatShr
#define TagWdbeRls CrdWdbeRls::Tag

#define DpchAppWdbeRlsDo CrdWdbeRls::DpchAppDo
#define DpchEngWdbeRlsData CrdWdbeRls::DpchEngData

/**
	* CrdWdbeRls
	*/
class CrdWdbeRls : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVWdbeRlsDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint CLOSE = 1;
		static const Sbecore::uint MITAPPABTCLICK = 2;
		static const Sbecore::uint MITCRDNEWCLICK = 3;
		static const Sbecore::uint MITCRDSRTCLICK = 4;
		static const Sbecore::uint MITCRDCRTCLICK = 5;
		static const Sbecore::uint MITCRDFRTCLICK = 6;
		static const Sbecore::uint MITCRDWCOCLICK = 7;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVWdbeRlsSge)
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
	  * ContInf (full: ContInfWdbeRls)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint MRLAPPHLP = 2;
		static const Sbecore::uint MTXCRDRLS = 3;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& MrlAppHlp = "", const std::string& MtxCrdRls = "");

	public:
		Sbecore::uint numFSge;
		std::string MrlAppHlp;
		std::string MtxCrdRls;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWdbeRls)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWdbeVReqitmode = VecWdbeVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneList = false, const bool initdoneRec = false);
	};

	/**
		* StatShr (full: StatShrWdbeRls)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint JREFDLGFINREPTR = 1;
		static const Sbecore::uint JREFDLGNEW = 2;
		static const Sbecore::uint JREFDLGSTAREPTR = 3;
		static const Sbecore::uint JREFDLGWRITE = 4;
		static const Sbecore::uint JREFHEADBAR = 5;
		static const Sbecore::uint JREFLIST = 6;
		static const Sbecore::uint JREFREC = 7;
		static const Sbecore::uint MSPCRD1AVAIL = 8;
		static const Sbecore::uint MITCRDNEWAVAIL = 9;
		static const Sbecore::uint MITCRDSRTAVAIL = 10;
		static const Sbecore::uint MITCRDSRTACTIVE = 11;
		static const Sbecore::uint MITCRDCRTAVAIL = 12;
		static const Sbecore::uint MITCRDCRTACTIVE = 13;
		static const Sbecore::uint MITCRDFRTAVAIL = 14;
		static const Sbecore::uint MITCRDFRTACTIVE = 15;
		static const Sbecore::uint MITCRDWCOAVAIL = 16;
		static const Sbecore::uint MITCRDWCOACTIVE = 17;

	public:
		StatShr(const Sbecore::ubigint jrefDlgfinreptr = 0, const Sbecore::ubigint jrefDlgnew = 0, const Sbecore::ubigint jrefDlgstareptr = 0, const Sbecore::ubigint jrefDlgwrite = 0, const Sbecore::ubigint jrefHeadbar = 0, const Sbecore::ubigint jrefList = 0, const Sbecore::ubigint jrefRec = 0, const bool MspCrd1Avail = true, const bool MitCrdNewAvail = true, const bool MitCrdSrtAvail = true, const bool MitCrdSrtActive = true, const bool MitCrdCrtAvail = true, const bool MitCrdCrtActive = true, const bool MitCrdFrtAvail = true, const bool MitCrdFrtActive = true, const bool MitCrdWcoAvail = true, const bool MitCrdWcoActive = true);

	public:
		Sbecore::ubigint jrefDlgfinreptr;
		Sbecore::ubigint jrefDlgnew;
		Sbecore::ubigint jrefDlgstareptr;
		Sbecore::ubigint jrefDlgwrite;
		Sbecore::ubigint jrefHeadbar;
		Sbecore::ubigint jrefList;
		Sbecore::ubigint jrefRec;
		bool MspCrd1Avail;
		bool MitCrdNewAvail;
		bool MitCrdSrtAvail;
		bool MitCrdSrtActive;
		bool MitCrdCrtAvail;
		bool MitCrdCrtActive;
		bool MitCrdFrtAvail;
		bool MitCrdFrtActive;
		bool MitCrdWcoAvail;
		bool MitCrdWcoActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWdbeRls)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWdbeRlsDo)
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
		* DpchEngData (full: DpchEngWdbeRlsData)
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

	bool evalMspCrd1Avail(DbsWdbe* dbswdbe);
	bool evalMitCrdNewAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdSrtAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdSrtActive(DbsWdbe* dbswdbe);
	bool evalMitCrdCrtAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdCrtActive(DbsWdbe* dbswdbe);
	bool evalMitCrdFrtAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdFrtActive(DbsWdbe* dbswdbe);
	bool evalMitCrdWcoAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdWcoActive(DbsWdbe* dbswdbe);

public:
	CrdWdbeRls(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale, const Sbecore::ubigint ref = 0, const Sbecore::uint ixWdbeVPreset = VecWdbeVPreset::VOID, const Sbecore::ubigint preUref = 0);
	~CrdWdbeRls();

public:
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFMcbAlert;
	Sbecore::Xmlio::Feed feedFSge;

	PnlWdbeRlsList* pnllist;
	PnlWdbeRlsHeadbar* pnlheadbar;
	PnlWdbeRlsRec* pnlrec;
	DlgWdbeRlsFinreptr* dlgfinreptr;
	DlgWdbeRlsNew* dlgnew;
	DlgWdbeRlsStareptr* dlgstareptr;
	DlgWdbeRlsWrite* dlgwrite;

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
	void handleDpchAppDoMitCrdSrtClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdCrtClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdFrtClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMitCrdWcoClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppWdbeAlert(DbsWdbe* dbswdbe, DpchAppWdbeAlert* dpchappwdbealert, DpchEngWdbe** dpcheng);

public:
	void handleCall(DbsWdbe* dbswdbe, Sbecore::Call* call);

private:
	bool handleCallWdbeReptrStop(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);
	bool handleCallWdbeReptrStart(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const std::string& txtvalInv);
	bool handleCallWdbeRefPreSet(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);
	bool handleCallWdbeStatChg(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);
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
