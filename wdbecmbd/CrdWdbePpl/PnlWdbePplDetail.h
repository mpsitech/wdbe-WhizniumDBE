/**
	* \file PnlWdbePplDetail.h
	* job handler for job PnlWdbePplDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

#ifndef PNLWDBEPPLDETAIL_H
#define PNLWDBEPPLDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWdbePplDetailDo PnlWdbePplDetail::VecVDo

#define ContIacWdbePplDetail PnlWdbePplDetail::ContIac
#define ContInfWdbePplDetail PnlWdbePplDetail::ContInf
#define StatAppWdbePplDetail PnlWdbePplDetail::StatApp
#define StatShrWdbePplDetail PnlWdbePplDetail::StatShr
#define TagWdbePplDetail PnlWdbePplDetail::Tag

#define DpchAppWdbePplDetailData PnlWdbePplDetail::DpchAppData
#define DpchAppWdbePplDetailDo PnlWdbePplDetail::DpchAppDo
#define DpchEngWdbePplDetailData PnlWdbePplDetail::DpchEngData

/**
	* PnlWdbePplDetail
	*/
class PnlWdbePplDetail : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVWdbePplDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTHSMVIEWCLICK = 2;
		static const Sbecore::uint BUTCLKVIEWCLICK = 3;
		static const Sbecore::uint BUTCLGVIEWCLICK = 4;
		static const Sbecore::uint BUTASRVIEWCLICK = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbePplDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFCLK = 1;
		static const Sbecore::uint TXFCLG = 2;
		static const Sbecore::uint TXFASR = 3;
		static const Sbecore::uint TXFDPT = 4;
		static const Sbecore::uint TXFCMT = 5;

	public:
		ContIac(const std::string& TxfClk = "", const std::string& TxfClg = "", const std::string& TxfAsr = "", const std::string& TxfDpt = "", const std::string& TxfCmt = "");

	public:
		std::string TxfClk;
		std::string TxfClg;
		std::string TxfAsr;
		std::string TxfDpt;
		std::string TxfCmt;

	public:
		bool readJSON(Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWdbePplDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTHSM = 2;
		static const Sbecore::uint TXTCLK = 3;
		static const Sbecore::uint TXTCLG = 4;
		static const Sbecore::uint TXTASR = 5;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtHsm = "", const std::string& TxtClk = "", const std::string& TxtClg = "", const std::string& TxtAsr = "");

	public:
		std::string TxtSrf;
		std::string TxtHsm;
		std::string TxtClk;
		std::string TxtClg;
		std::string TxtAsr;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWdbePplDetail)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool TxtClkAlt = false, const bool TxtClgAlt = false, const bool TxtAsrAlt = false);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool TxtClkAlt = false, const bool TxtClgAlt = false, const bool TxtAsrAlt = false);
	};

	/**
		* StatShr (full: StatShrWdbePplDetail)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFCLKVALID = 1;
		static const Sbecore::uint TXFCLGVALID = 2;
		static const Sbecore::uint TXFASRVALID = 3;
		static const Sbecore::uint BUTSAVEAVAIL = 4;
		static const Sbecore::uint BUTSAVEACTIVE = 5;
		static const Sbecore::uint TXTSRFACTIVE = 6;
		static const Sbecore::uint TXTHSMACTIVE = 7;
		static const Sbecore::uint BUTHSMVIEWAVAIL = 8;
		static const Sbecore::uint BUTHSMVIEWACTIVE = 9;
		static const Sbecore::uint TXTCLKACTIVE = 10;
		static const Sbecore::uint BUTCLKVIEWAVAIL = 11;
		static const Sbecore::uint TXTCLGACTIVE = 12;
		static const Sbecore::uint BUTCLGVIEWAVAIL = 13;
		static const Sbecore::uint TXTASRACTIVE = 14;
		static const Sbecore::uint BUTASRVIEWAVAIL = 15;
		static const Sbecore::uint TXFDPTACTIVE = 16;
		static const Sbecore::uint TXFCMTACTIVE = 17;

	public:
		StatShr(const bool TxfClkValid = false, const bool TxfClgValid = false, const bool TxfAsrValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxtHsmActive = true, const bool ButHsmViewAvail = true, const bool ButHsmViewActive = true, const bool TxtClkActive = true, const bool ButClkViewAvail = true, const bool TxtClgActive = true, const bool ButClgViewAvail = true, const bool TxtAsrActive = true, const bool ButAsrViewAvail = true, const bool TxfDptActive = true, const bool TxfCmtActive = true);

	public:
		bool TxfClkValid;
		bool TxfClgValid;
		bool TxfAsrValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxtHsmActive;
		bool ButHsmViewAvail;
		bool ButHsmViewActive;
		bool TxtClkActive;
		bool ButClkViewAvail;
		bool TxtClgActive;
		bool ButClgViewAvail;
		bool TxtAsrActive;
		bool ButAsrViewAvail;
		bool TxfDptActive;
		bool TxfCmtActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWdbePplDetail)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWdbePplDetailData)
		*/
	class DpchAppData : public DpchAppWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;

	public:
		DpchAppData();

	public:
		ContIac contiac;

	public:
		std::string getSrefsMask();

		void readJSON(Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWdbePplDetailDo)
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
		* DpchEngData (full: DpchEngWdbePplDetailData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint STATAPP = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint TAG = 6;
		static const Sbecore::uint ALL = 7;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsWdbe* dbswdbe);
	bool evalButSaveActive(DbsWdbe* dbswdbe);
	bool evalTxtSrfActive(DbsWdbe* dbswdbe);
	bool evalTxtHsmActive(DbsWdbe* dbswdbe);
	bool evalButHsmViewAvail(DbsWdbe* dbswdbe);
	bool evalButHsmViewActive(DbsWdbe* dbswdbe);
	bool evalTxtClkActive(DbsWdbe* dbswdbe);
	bool evalButClkViewAvail(DbsWdbe* dbswdbe);
	bool evalTxtClgActive(DbsWdbe* dbswdbe);
	bool evalButClgViewAvail(DbsWdbe* dbswdbe);
	bool evalTxtAsrActive(DbsWdbe* dbswdbe);
	bool evalButAsrViewAvail(DbsWdbe* dbswdbe);
	bool evalTxfDptActive(DbsWdbe* dbswdbe);
	bool evalTxfCmtActive(DbsWdbe* dbswdbe);

public:
	PnlWdbePplDetail(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~PnlWdbePplDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	WdbeMPipeline recPpl;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshTxtClk(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshTxtClg(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshTxtAsr(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

	void refreshRecPpl(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:

	void handleDpchAppWdbeInit(DbsWdbe* dbswdbe, DpchAppWdbeInit* dpchappwdbeinit, DpchEngWdbe** dpcheng);
	void handleDpchAppDataContiac(DbsWdbe* dbswdbe, ContIac* _contiac, DpchEngWdbe** dpcheng);

	void handleDpchAppDoButSaveClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButHsmViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButClkViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButClgViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButAsrViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

public:
	void handleCall(DbsWdbe* dbswdbe, Sbecore::Call* call);

private:
	bool handleCallWdbePpl_hsm_inSbs(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWdbePpl_hsmEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbePplUpd_refEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);

};

#endif
