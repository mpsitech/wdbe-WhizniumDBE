/**
	* \file PnlWdbeSegDetail.h
	* job handler for job PnlWdbeSegDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

#ifndef PNLWDBESEGDETAIL_H
#define PNLWDBESEGDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWdbeSegDetailDo PnlWdbeSegDetail::VecVDo

#define ContIacWdbeSegDetail PnlWdbeSegDetail::ContIac
#define ContInfWdbeSegDetail PnlWdbeSegDetail::ContInf
#define StatAppWdbeSegDetail PnlWdbeSegDetail::StatApp
#define StatShrWdbeSegDetail PnlWdbeSegDetail::StatShr
#define TagWdbeSegDetail PnlWdbeSegDetail::Tag

#define DpchAppWdbeSegDetailData PnlWdbeSegDetail::DpchAppData
#define DpchAppWdbeSegDetailDo PnlWdbeSegDetail::DpchAppDo
#define DpchEngWdbeSegDetailData PnlWdbeSegDetail::DpchEngData

/**
	* PnlWdbeSegDetail
	*/
class PnlWdbeSegDetail : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVWdbeSegDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTCLUVIEWCLICK = 2;
		static const Sbecore::uint BUTCLUCLUSTERCLICK = 3;
		static const Sbecore::uint BUTCLUUNCLUSTERCLICK = 4;
		static const Sbecore::uint BUTPPLVIEWCLICK = 5;
		static const Sbecore::uint BUTSUPVIEWCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeSegDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFLSTCLU = 1;
		static const Sbecore::uint TXFIFM = 2;
		static const Sbecore::uint TXFOFM = 3;
		static const Sbecore::uint TXFLCY = 4;
		static const Sbecore::uint TXFCMT = 5;

	public:
		ContIac(const Sbecore::uint numFLstClu = 1, const std::string& TxfIfm = "", const std::string& TxfOfm = "", const std::string& TxfLcy = "", const std::string& TxfCmt = "");

	public:
		Sbecore::uint numFLstClu;
		std::string TxfIfm;
		std::string TxfOfm;
		std::string TxfLcy;
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
	  * ContInf (full: ContInfWdbeSegDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTCLU = 2;
		static const Sbecore::uint TXTPPL = 3;
		static const Sbecore::uint TXTSUP = 4;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtClu = "", const std::string& TxtPpl = "", const std::string& TxtSup = "");

	public:
		std::string TxtSrf;
		std::string TxtClu;
		std::string TxtPpl;
		std::string TxtSup;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWdbeSegDetail)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool LstCluAlt = true, const Sbecore::uint LstCluNumFirstdisp = 1);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool LstCluAlt = true, const Sbecore::uint LstCluNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWdbeSegDetail)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTSRFACTIVE = 3;
		static const Sbecore::uint LSTCLUACTIVE = 4;
		static const Sbecore::uint BUTCLUVIEWACTIVE = 5;
		static const Sbecore::uint BUTCLUCLUSTERAVAIL = 6;
		static const Sbecore::uint BUTCLUUNCLUSTERAVAIL = 7;
		static const Sbecore::uint TXTPPLACTIVE = 8;
		static const Sbecore::uint BUTPPLVIEWAVAIL = 9;
		static const Sbecore::uint BUTPPLVIEWACTIVE = 10;
		static const Sbecore::uint TXTSUPACTIVE = 11;
		static const Sbecore::uint BUTSUPVIEWAVAIL = 12;
		static const Sbecore::uint BUTSUPVIEWACTIVE = 13;
		static const Sbecore::uint TXFIFMACTIVE = 14;
		static const Sbecore::uint TXFOFMACTIVE = 15;
		static const Sbecore::uint TXFLCYACTIVE = 16;
		static const Sbecore::uint TXFCMTACTIVE = 17;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool LstCluActive = true, const bool ButCluViewActive = true, const bool ButCluClusterAvail = true, const bool ButCluUnclusterAvail = true, const bool TxtPplActive = true, const bool ButPplViewAvail = true, const bool ButPplViewActive = true, const bool TxtSupActive = true, const bool ButSupViewAvail = true, const bool ButSupViewActive = true, const bool TxfIfmActive = true, const bool TxfOfmActive = true, const bool TxfLcyActive = true, const bool TxfCmtActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool LstCluActive;
		bool ButCluViewActive;
		bool ButCluClusterAvail;
		bool ButCluUnclusterAvail;
		bool TxtPplActive;
		bool ButPplViewAvail;
		bool ButPplViewActive;
		bool TxtSupActive;
		bool ButSupViewAvail;
		bool ButSupViewActive;
		bool TxfIfmActive;
		bool TxfOfmActive;
		bool TxfLcyActive;
		bool TxfCmtActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWdbeSegDetail)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWdbeSegDetailData)
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
		* DpchAppDo (full: DpchAppWdbeSegDetailDo)
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
		* DpchEngData (full: DpchEngWdbeSegDetailData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTCLU = 4;
		static const Sbecore::uint STATAPP = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint TAG = 7;
		static const Sbecore::uint ALL = 8;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Feed* feedFLstClu = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFLstClu;
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
	bool evalLstCluActive(DbsWdbe* dbswdbe);
	bool evalButCluViewActive(DbsWdbe* dbswdbe);
	bool evalButCluClusterAvail(DbsWdbe* dbswdbe);
	bool evalButCluUnclusterAvail(DbsWdbe* dbswdbe);
	bool evalTxtPplActive(DbsWdbe* dbswdbe);
	bool evalButPplViewAvail(DbsWdbe* dbswdbe);
	bool evalButPplViewActive(DbsWdbe* dbswdbe);
	bool evalTxtSupActive(DbsWdbe* dbswdbe);
	bool evalButSupViewAvail(DbsWdbe* dbswdbe);
	bool evalButSupViewActive(DbsWdbe* dbswdbe);
	bool evalTxfIfmActive(DbsWdbe* dbswdbe);
	bool evalTxfOfmActive(DbsWdbe* dbswdbe);
	bool evalTxfLcyActive(DbsWdbe* dbswdbe);
	bool evalTxfCmtActive(DbsWdbe* dbswdbe);

public:
	PnlWdbeSegDetail(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~PnlWdbeSegDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFLstClu;

	WdbeMSegment recSeg;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshLstClu(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshClu(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

	void refreshRecSeg(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:

	void handleDpchAppWdbeInit(DbsWdbe* dbswdbe, DpchAppWdbeInit* dpchappwdbeinit, DpchEngWdbe** dpcheng);
	void handleDpchAppDataContiac(DbsWdbe* dbswdbe, ContIac* _contiac, DpchEngWdbe** dpcheng);

	void handleDpchAppDoButSaveClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButCluViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButCluClusterClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButCluUnclusterClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButPplViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButSupViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

public:
	void handleCall(DbsWdbe* dbswdbe, Sbecore::Call* call);

private:
	bool handleCallWdbeSeg_cluEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeSeg_pplEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeSeg_supEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeSegUpd_refEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);
	bool handleCallWdbeSegMod_cluEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);

};

#endif
