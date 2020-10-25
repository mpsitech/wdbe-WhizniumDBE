/**
	* \file PnlWdbePinDetail.h
	* job handler for job PnlWdbePinDetail (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef PNLWDBEPINDETAIL_H
#define PNLWDBEPINDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWdbePinDetailDo PnlWdbePinDetail::VecVDo

#define ContIacWdbePinDetail PnlWdbePinDetail::ContIac
#define ContInfWdbePinDetail PnlWdbePinDetail::ContInf
#define StatAppWdbePinDetail PnlWdbePinDetail::StatApp
#define StatShrWdbePinDetail PnlWdbePinDetail::StatShr
#define TagWdbePinDetail PnlWdbePinDetail::Tag

#define DpchAppWdbePinDetailData PnlWdbePinDetail::DpchAppData
#define DpchAppWdbePinDetailDo PnlWdbePinDetail::DpchAppDo
#define DpchEngWdbePinDetailData PnlWdbePinDetail::DpchEngData

/**
	* PnlWdbePinDetail
	*/
class PnlWdbePinDetail : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVWdbePinDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTJSREDITCLICK = 2;
		static const Sbecore::uint BUTCLUVIEWCLICK = 3;
		static const Sbecore::uint BUTCLUCLUSTERCLICK = 4;
		static const Sbecore::uint BUTCLUUNCLUSTERCLICK = 5;
		static const Sbecore::uint BUTBNKVIEWCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbePinDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFPUPJSR = 1;
		static const Sbecore::uint NUMFLSTCLU = 2;
		static const Sbecore::uint TXFLOC = 3;

	public:
		ContIac(const Sbecore::uint numFPupJsr = 1, const Sbecore::uint numFLstClu = 1, const std::string& TxfLoc = "");

	public:
		Sbecore::uint numFPupJsr;
		Sbecore::uint numFLstClu;
		std::string TxfLoc;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWdbePinDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTCLU = 2;
		static const Sbecore::uint TXTBNK = 3;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtClu = "", const std::string& TxtBnk = "");

	public:
		std::string TxtSrf;
		std::string TxtClu;
		std::string TxtBnk;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWdbePinDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool LstCluAlt = true, const Sbecore::uint LstCluNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWdbePinDetail)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint PUPJSRACTIVE = 3;
		static const Sbecore::uint BUTJSREDITAVAIL = 4;
		static const Sbecore::uint TXTSRFACTIVE = 5;
		static const Sbecore::uint LSTCLUACTIVE = 6;
		static const Sbecore::uint BUTCLUVIEWACTIVE = 7;
		static const Sbecore::uint BUTCLUCLUSTERAVAIL = 8;
		static const Sbecore::uint BUTCLUUNCLUSTERAVAIL = 9;
		static const Sbecore::uint TXTBNKACTIVE = 10;
		static const Sbecore::uint BUTBNKVIEWAVAIL = 11;
		static const Sbecore::uint BUTBNKVIEWACTIVE = 12;
		static const Sbecore::uint TXFLOCACTIVE = 13;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool PupJsrActive = true, const bool ButJsrEditAvail = true, const bool TxtSrfActive = true, const bool LstCluActive = true, const bool ButCluViewActive = true, const bool ButCluClusterAvail = true, const bool ButCluUnclusterAvail = true, const bool TxtBnkActive = true, const bool ButBnkViewAvail = true, const bool ButBnkViewActive = true, const bool TxfLocActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool PupJsrActive;
		bool ButJsrEditAvail;
		bool TxtSrfActive;
		bool LstCluActive;
		bool ButCluViewActive;
		bool ButCluClusterAvail;
		bool ButCluUnclusterAvail;
		bool TxtBnkActive;
		bool ButBnkViewAvail;
		bool ButBnkViewActive;
		bool TxfLocActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWdbePinDetail)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWdbePinDetailData)
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
		* DpchAppDo (full: DpchAppWdbePinDetailDo)
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
		* DpchEngData (full: DpchEngWdbePinDetailData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTCLU = 4;
		static const Sbecore::uint FEEDFPUPJSR = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;
		static const Sbecore::uint ALL = 9;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFLstClu = NULL, Sbecore::Xmlio::Feed* feedFPupJsr = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFLstClu;
		Sbecore::Xmlio::Feed feedFPupJsr;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsWdbe* dbswdbe);
	bool evalButSaveActive(DbsWdbe* dbswdbe);
	bool evalPupJsrActive(DbsWdbe* dbswdbe);
	bool evalButJsrEditAvail(DbsWdbe* dbswdbe);
	bool evalTxtSrfActive(DbsWdbe* dbswdbe);
	bool evalLstCluActive(DbsWdbe* dbswdbe);
	bool evalButCluViewActive(DbsWdbe* dbswdbe);
	bool evalButCluClusterAvail(DbsWdbe* dbswdbe);
	bool evalButCluUnclusterAvail(DbsWdbe* dbswdbe);
	bool evalTxtBnkActive(DbsWdbe* dbswdbe);
	bool evalButBnkViewAvail(DbsWdbe* dbswdbe);
	bool evalButBnkViewActive(DbsWdbe* dbswdbe);
	bool evalTxfLocActive(DbsWdbe* dbswdbe);

public:
	PnlWdbePinDetail(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~PnlWdbePinDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFLstClu;
	Sbecore::Xmlio::Feed feedFPupJsr;

	WdbeMPin recPin;

	WdbeJMPinSref recPinJsrf;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshJsr(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshLstClu(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshClu(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

	void refreshRecPin(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshRecPinJsrf(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

	void updatePreset(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:

	void handleDpchAppWdbeInit(DbsWdbe* dbswdbe, DpchAppWdbeInit* dpchappwdbeinit, DpchEngWdbe** dpcheng);
	void handleDpchAppDataContiac(DbsWdbe* dbswdbe, ContIac* _contiac, DpchEngWdbe** dpcheng);

	void handleDpchAppDoButSaveClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButJsrEditClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButCluViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButCluClusterClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButCluUnclusterClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButBnkViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

public:
	void handleCall(DbsWdbe* dbswdbe, Sbecore::Call* call);

private:
	bool handleCallWdbePin_bnkEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbePin_cluEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbePinUpd_refEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);
	bool handleCallWdbePinJsrfMod_pinEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);
	bool handleCallWdbePinMod_cluEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);

};

#endif

