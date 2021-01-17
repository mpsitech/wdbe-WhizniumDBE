/**
	* \file PnlWdbeVarDetail.h
	* job handler for job PnlWdbeVarDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBEVARDETAIL_H
#define PNLWDBEVARDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWdbeVarDetailDo PnlWdbeVarDetail::VecVDo

#define ContIacWdbeVarDetail PnlWdbeVarDetail::ContIac
#define ContInfWdbeVarDetail PnlWdbeVarDetail::ContInf
#define StatAppWdbeVarDetail PnlWdbeVarDetail::StatApp
#define StatShrWdbeVarDetail PnlWdbeVarDetail::StatShr
#define TagWdbeVarDetail PnlWdbeVarDetail::Tag

#define DpchAppWdbeVarDetailData PnlWdbeVarDetail::DpchAppData
#define DpchAppWdbeVarDetailDo PnlWdbeVarDetail::DpchAppDo
#define DpchEngWdbeVarDetailData PnlWdbeVarDetail::DpchEngData

/**
	* PnlWdbeVarDetail
	*/
class PnlWdbeVarDetail : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVWdbeVarDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTCLUVIEWCLICK = 2;
		static const Sbecore::uint BUTCLUCLUSTERCLICK = 3;
		static const Sbecore::uint BUTCLUUNCLUSTERCLICK = 4;
		static const Sbecore::uint BUTHTYEDITCLICK = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeVarDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFLSTCLU = 1;
		static const Sbecore::uint CHKCON = 2;
		static const Sbecore::uint CHKFAL = 3;
		static const Sbecore::uint NUMFPUPHTY = 4;
		static const Sbecore::uint TXFHTY = 5;
		static const Sbecore::uint TXFWID = 6;
		static const Sbecore::uint TXFMMX = 7;
		static const Sbecore::uint TXFONV = 8;
		static const Sbecore::uint TXFOFV = 9;
		static const Sbecore::uint CHKDFO = 10;
		static const Sbecore::uint TXFCMT = 11;

	public:
		ContIac(const Sbecore::uint numFLstClu = 1, const bool ChkCon = false, const bool ChkFal = false, const Sbecore::uint numFPupHty = 1, const std::string& TxfHty = "", const std::string& TxfWid = "", const std::string& TxfMmx = "", const std::string& TxfOnv = "", const std::string& TxfOfv = "", const bool ChkDfo = false, const std::string& TxfCmt = "");

	public:
		Sbecore::uint numFLstClu;
		bool ChkCon;
		bool ChkFal;
		Sbecore::uint numFPupHty;
		std::string TxfHty;
		std::string TxfWid;
		std::string TxfMmx;
		std::string TxfOnv;
		std::string TxfOfv;
		bool ChkDfo;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWdbeVarDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTCLU = 2;
		static const Sbecore::uint TXTPRC = 3;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtClu = "", const std::string& TxtPrc = "");

	public:
		std::string TxtSrf;
		std::string TxtClu;
		std::string TxtPrc;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWdbeVarDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool LstCluAlt = true, const bool PupHtyAlt = false, const Sbecore::uint LstCluNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWdbeVarDetail)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFHTYVALID = 1;
		static const Sbecore::uint BUTSAVEAVAIL = 2;
		static const Sbecore::uint BUTSAVEACTIVE = 3;
		static const Sbecore::uint TXTSRFACTIVE = 4;
		static const Sbecore::uint LSTCLUACTIVE = 5;
		static const Sbecore::uint BUTCLUVIEWACTIVE = 6;
		static const Sbecore::uint BUTCLUCLUSTERAVAIL = 7;
		static const Sbecore::uint BUTCLUUNCLUSTERAVAIL = 8;
		static const Sbecore::uint TXTPRCACTIVE = 9;
		static const Sbecore::uint CHKCONACTIVE = 10;
		static const Sbecore::uint CHKFALACTIVE = 11;
		static const Sbecore::uint PUPHTYACTIVE = 12;
		static const Sbecore::uint BUTHTYEDITAVAIL = 13;
		static const Sbecore::uint TXFWIDACTIVE = 14;
		static const Sbecore::uint TXFMMXACTIVE = 15;
		static const Sbecore::uint TXFONVACTIVE = 16;
		static const Sbecore::uint TXFOFVACTIVE = 17;
		static const Sbecore::uint CHKDFOACTIVE = 18;
		static const Sbecore::uint TXFCMTACTIVE = 19;

	public:
		StatShr(const bool TxfHtyValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool LstCluActive = true, const bool ButCluViewActive = true, const bool ButCluClusterAvail = true, const bool ButCluUnclusterAvail = true, const bool TxtPrcActive = true, const bool ChkConActive = true, const bool ChkFalActive = true, const bool PupHtyActive = true, const bool ButHtyEditAvail = true, const bool TxfWidActive = true, const bool TxfMmxActive = true, const bool TxfOnvActive = true, const bool TxfOfvActive = true, const bool ChkDfoActive = true, const bool TxfCmtActive = true);

	public:
		bool TxfHtyValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool LstCluActive;
		bool ButCluViewActive;
		bool ButCluClusterAvail;
		bool ButCluUnclusterAvail;
		bool TxtPrcActive;
		bool ChkConActive;
		bool ChkFalActive;
		bool PupHtyActive;
		bool ButHtyEditAvail;
		bool TxfWidActive;
		bool TxfMmxActive;
		bool TxfOnvActive;
		bool TxfOfvActive;
		bool ChkDfoActive;
		bool TxfCmtActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWdbeVarDetail)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWdbeVarDetailData)
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

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWdbeVarDetailDo)
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
		* DpchEngData (full: DpchEngWdbeVarDetailData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTCLU = 4;
		static const Sbecore::uint FEEDFPUPHTY = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;
		static const Sbecore::uint ALL = 9;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFLstClu = NULL, Sbecore::Xmlio::Feed* feedFPupHty = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFLstClu;
		Sbecore::Xmlio::Feed feedFPupHty;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsWdbe* dbswdbe);
	bool evalButSaveActive(DbsWdbe* dbswdbe);
	bool evalTxtSrfActive(DbsWdbe* dbswdbe);
	bool evalLstCluActive(DbsWdbe* dbswdbe);
	bool evalButCluViewActive(DbsWdbe* dbswdbe);
	bool evalButCluClusterAvail(DbsWdbe* dbswdbe);
	bool evalButCluUnclusterAvail(DbsWdbe* dbswdbe);
	bool evalTxtPrcActive(DbsWdbe* dbswdbe);
	bool evalChkConActive(DbsWdbe* dbswdbe);
	bool evalChkFalActive(DbsWdbe* dbswdbe);
	bool evalPupHtyActive(DbsWdbe* dbswdbe);
	bool evalButHtyEditAvail(DbsWdbe* dbswdbe);
	bool evalTxfWidActive(DbsWdbe* dbswdbe);
	bool evalTxfMmxActive(DbsWdbe* dbswdbe);
	bool evalTxfOnvActive(DbsWdbe* dbswdbe);
	bool evalTxfOfvActive(DbsWdbe* dbswdbe);
	bool evalChkDfoActive(DbsWdbe* dbswdbe);
	bool evalTxfCmtActive(DbsWdbe* dbswdbe);

public:
	PnlWdbeVarDetail(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~PnlWdbeVarDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFLstClu;
	Sbecore::Xmlio::Feed feedFPupHty;

	WdbeMVariable recVar;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshLstClu(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshClu(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshPupHty(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshTxfHty(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshHty(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

	void refreshRecVar(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

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
	void handleDpchAppDoButHtyEditClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

public:
	void handleCall(DbsWdbe* dbswdbe, Sbecore::Call* call);

private:
	bool handleCallWdbeVar_cluEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeVarUpd_refEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);
	bool handleCallWdbeKlsAkeyMod_klsMtbUrfEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, const std::string& srefInv);
	bool handleCallWdbeVarMod_cluEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);

};

#endif
