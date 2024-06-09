/**
	* \file PnlWdbePrcDetail.h
	* job handler for job PnlWdbePrcDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBEPRCDETAIL_H
#define PNLWDBEPRCDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWdbePrcDetailDo PnlWdbePrcDetail::VecVDo

#define ContIacWdbePrcDetail PnlWdbePrcDetail::ContIac
#define ContInfWdbePrcDetail PnlWdbePrcDetail::ContInf
#define StatAppWdbePrcDetail PnlWdbePrcDetail::StatApp
#define StatShrWdbePrcDetail PnlWdbePrcDetail::StatShr
#define TagWdbePrcDetail PnlWdbePrcDetail::Tag

#define DpchAppWdbePrcDetailData PnlWdbePrcDetail::DpchAppData
#define DpchAppWdbePrcDetailDo PnlWdbePrcDetail::DpchAppDo
#define DpchEngWdbePrcDetailData PnlWdbePrcDetail::DpchEngData

/**
	* PnlWdbePrcDetail
	*/
class PnlWdbePrcDetail : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVWdbePrcDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTMDLVIEWCLICK = 2;
		static const Sbecore::uint BUTCLKVIEWCLICK = 3;
		static const Sbecore::uint BUTASRVIEWCLICK = 4;
		static const Sbecore::uint BUTFSMNEWCLICK = 5;
		static const Sbecore::uint BUTFSMDELETECLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbePrcDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFCLK = 1;
		static const Sbecore::uint TXFASR = 2;
		static const Sbecore::uint CHKFAL = 3;
		static const Sbecore::uint TXFSNR = 4;
		static const Sbecore::uint CHKEIP = 5;
		static const Sbecore::uint TXFCMT = 6;
		static const Sbecore::uint NUMFPUPFSMDTT = 7;

	public:
		ContIac(const std::string& TxfClk = "", const std::string& TxfAsr = "", const bool ChkFal = false, const std::string& TxfSnr = "", const bool ChkEip = false, const std::string& TxfCmt = "", const Sbecore::uint numFPupFsmDtt = 1);

	public:
		std::string TxfClk;
		std::string TxfAsr;
		bool ChkFal;
		std::string TxfSnr;
		bool ChkEip;
		std::string TxfCmt;
		Sbecore::uint numFPupFsmDtt;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWdbePrcDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTMDL = 2;
		static const Sbecore::uint TXTCLK = 3;
		static const Sbecore::uint TXTASR = 4;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtMdl = "", const std::string& TxtClk = "", const std::string& TxtAsr = "");

	public:
		std::string TxtSrf;
		std::string TxtMdl;
		std::string TxtClk;
		std::string TxtAsr;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWdbePrcDetail)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool TxtClkAlt = false, const bool TxtAsrAlt = false);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool TxtClkAlt = false, const bool TxtAsrAlt = false);
	};

	/**
		* StatShr (full: StatShrWdbePrcDetail)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFCLKVALID = 1;
		static const Sbecore::uint TXFASRVALID = 2;
		static const Sbecore::uint BUTSAVEAVAIL = 3;
		static const Sbecore::uint BUTSAVEACTIVE = 4;
		static const Sbecore::uint TXTSRFACTIVE = 5;
		static const Sbecore::uint TXTMDLACTIVE = 6;
		static const Sbecore::uint BUTMDLVIEWAVAIL = 7;
		static const Sbecore::uint BUTMDLVIEWACTIVE = 8;
		static const Sbecore::uint TXTCLKACTIVE = 9;
		static const Sbecore::uint BUTCLKVIEWAVAIL = 10;
		static const Sbecore::uint TXTASRACTIVE = 11;
		static const Sbecore::uint BUTASRVIEWAVAIL = 12;
		static const Sbecore::uint CHKFALACTIVE = 13;
		static const Sbecore::uint TXFSNRACTIVE = 14;
		static const Sbecore::uint CHKEIPACTIVE = 15;
		static const Sbecore::uint TXFCMTACTIVE = 16;
		static const Sbecore::uint BUTFSMNEWAVAIL = 17;
		static const Sbecore::uint BUTFSMDELETEAVAIL = 18;
		static const Sbecore::uint PUPFSMDTTAVAIL = 19;
		static const Sbecore::uint PUPFSMDTTACTIVE = 20;

	public:
		StatShr(const bool TxfClkValid = false, const bool TxfAsrValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxtMdlActive = true, const bool ButMdlViewAvail = true, const bool ButMdlViewActive = true, const bool TxtClkActive = true, const bool ButClkViewAvail = true, const bool TxtAsrActive = true, const bool ButAsrViewAvail = true, const bool ChkFalActive = true, const bool TxfSnrActive = true, const bool ChkEipActive = true, const bool TxfCmtActive = true, const bool ButFsmNewAvail = true, const bool ButFsmDeleteAvail = true, const bool PupFsmDttAvail = true, const bool PupFsmDttActive = true);

	public:
		bool TxfClkValid;
		bool TxfAsrValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxtMdlActive;
		bool ButMdlViewAvail;
		bool ButMdlViewActive;
		bool TxtClkActive;
		bool ButClkViewAvail;
		bool TxtAsrActive;
		bool ButAsrViewAvail;
		bool ChkFalActive;
		bool TxfSnrActive;
		bool ChkEipActive;
		bool TxfCmtActive;
		bool ButFsmNewAvail;
		bool ButFsmDeleteAvail;
		bool PupFsmDttAvail;
		bool PupFsmDttActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWdbePrcDetail)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWdbePrcDetailData)
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

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWdbePrcDetailDo)
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
		* DpchEngData (full: DpchEngWdbePrcDetailData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPFSMDTT = 4;
		static const Sbecore::uint STATAPP = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint TAG = 7;
		static const Sbecore::uint ALL = 8;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Feed* feedFPupFsmDtt = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFPupFsmDtt;
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
	bool evalTxtMdlActive(DbsWdbe* dbswdbe);
	bool evalButMdlViewAvail(DbsWdbe* dbswdbe);
	bool evalButMdlViewActive(DbsWdbe* dbswdbe);
	bool evalTxtClkActive(DbsWdbe* dbswdbe);
	bool evalButClkViewAvail(DbsWdbe* dbswdbe);
	bool evalTxtAsrActive(DbsWdbe* dbswdbe);
	bool evalButAsrViewAvail(DbsWdbe* dbswdbe);
	bool evalChkFalActive(DbsWdbe* dbswdbe);
	bool evalTxfSnrActive(DbsWdbe* dbswdbe);
	bool evalChkEipActive(DbsWdbe* dbswdbe);
	bool evalTxfCmtActive(DbsWdbe* dbswdbe);
	bool evalButFsmNewAvail(DbsWdbe* dbswdbe);
	bool evalButFsmDeleteAvail(DbsWdbe* dbswdbe);
	bool evalPupFsmDttAvail(DbsWdbe* dbswdbe);
	bool evalPupFsmDttActive(DbsWdbe* dbswdbe);

public:
	PnlWdbePrcDetail(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~PnlWdbePrcDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFPupFsmDtt;

	WdbeMProcess recPrc;

	WdbeMFsm recFsm;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshTxtClk(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshTxtAsr(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

	void refreshRecPrc(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshRecFsm(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:

	void handleDpchAppWdbeInit(DbsWdbe* dbswdbe, DpchAppWdbeInit* dpchappwdbeinit, DpchEngWdbe** dpcheng);
	void handleDpchAppDataContiac(DbsWdbe* dbswdbe, ContIac* _contiac, DpchEngWdbe** dpcheng);

	void handleDpchAppDoButSaveClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButMdlViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButClkViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButAsrViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButFsmNewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButFsmDeleteClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

public:
	void handleCall(DbsWdbe* dbswdbe, Sbecore::Call* call);

private:
	bool handleCallWdbePrcUpd_refEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);
	bool handleCallWdbeFsmUpd_refEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);
	bool handleCallWdbePrc_mdlEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbePrc_fsmEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif
