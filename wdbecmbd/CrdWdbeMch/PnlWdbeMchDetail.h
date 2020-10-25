/**
	* \file PnlWdbeMchDetail.h
	* job handler for job PnlWdbeMchDetail (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef PNLWDBEMCHDETAIL_H
#define PNLWDBEMCHDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWdbeMchDetailDo PnlWdbeMchDetail::VecVDo

#define ContIacWdbeMchDetail PnlWdbeMchDetail::ContIac
#define ContInfWdbeMchDetail PnlWdbeMchDetail::ContInf
#define StatAppWdbeMchDetail PnlWdbeMchDetail::StatApp
#define StatShrWdbeMchDetail PnlWdbeMchDetail::StatShr
#define TagWdbeMchDetail PnlWdbeMchDetail::Tag

#define DpchAppWdbeMchDetailData PnlWdbeMchDetail::DpchAppData
#define DpchAppWdbeMchDetailDo PnlWdbeMchDetail::DpchAppDo
#define DpchEngWdbeMchDetailData PnlWdbeMchDetail::DpchEngData

/**
	* PnlWdbeMchDetail
	*/
class PnlWdbeMchDetail : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVWdbeMchDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTPLAEDITCLICK = 2;
		static const Sbecore::uint BUTCCHVIEWCLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeMchDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFPUPPLA = 1;
		static const Sbecore::uint TXFPLA = 2;
		static const Sbecore::uint TXFCMT = 3;

	public:
		ContIac(const Sbecore::uint numFPupPla = 1, const std::string& TxfPla = "", const std::string& TxfCmt = "");

	public:
		Sbecore::uint numFPupPla;
		std::string TxfPla;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWdbeMchDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTCCH = 2;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtCch = "");

	public:
		std::string TxtSrf;
		std::string TxtCch;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWdbeMchDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool PupPlaAlt = false);
	};

	/**
		* StatShr (full: StatShrWdbeMchDetail)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFPLAVALID = 1;
		static const Sbecore::uint BUTSAVEAVAIL = 2;
		static const Sbecore::uint BUTSAVEACTIVE = 3;
		static const Sbecore::uint TXTSRFACTIVE = 4;
		static const Sbecore::uint PUPPLAACTIVE = 5;
		static const Sbecore::uint BUTPLAEDITAVAIL = 6;
		static const Sbecore::uint TXTCCHACTIVE = 7;
		static const Sbecore::uint BUTCCHVIEWAVAIL = 8;
		static const Sbecore::uint BUTCCHVIEWACTIVE = 9;
		static const Sbecore::uint TXFCMTACTIVE = 10;

	public:
		StatShr(const bool TxfPlaValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool PupPlaActive = true, const bool ButPlaEditAvail = true, const bool TxtCchActive = true, const bool ButCchViewAvail = true, const bool ButCchViewActive = true, const bool TxfCmtActive = true);

	public:
		bool TxfPlaValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool PupPlaActive;
		bool ButPlaEditAvail;
		bool TxtCchActive;
		bool ButCchViewAvail;
		bool ButCchViewActive;
		bool TxfCmtActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWdbeMchDetail)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWdbeMchDetailData)
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
		* DpchAppDo (full: DpchAppWdbeMchDetailDo)
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
		* DpchEngData (full: DpchEngWdbeMchDetailData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPPLA = 4;
		static const Sbecore::uint STATAPP = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint TAG = 7;
		static const Sbecore::uint ALL = 8;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFPupPla = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFPupPla;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsWdbe* dbswdbe);
	bool evalButSaveActive(DbsWdbe* dbswdbe);
	bool evalTxtSrfActive(DbsWdbe* dbswdbe);
	bool evalPupPlaActive(DbsWdbe* dbswdbe);
	bool evalButPlaEditAvail(DbsWdbe* dbswdbe);
	bool evalTxtCchActive(DbsWdbe* dbswdbe);
	bool evalButCchViewAvail(DbsWdbe* dbswdbe);
	bool evalButCchViewActive(DbsWdbe* dbswdbe);
	bool evalTxfCmtActive(DbsWdbe* dbswdbe);

public:
	PnlWdbeMchDetail(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~PnlWdbeMchDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFPupPla;

	WdbeMMachine recMch;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshPupPla(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshTxfPla(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshPla(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

	void refreshRecMch(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

	void updatePreset(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:

	void handleDpchAppWdbeInit(DbsWdbe* dbswdbe, DpchAppWdbeInit* dpchappwdbeinit, DpchEngWdbe** dpcheng);
	void handleDpchAppDataContiac(DbsWdbe* dbswdbe, ContIac* _contiac, DpchEngWdbe** dpcheng);

	void handleDpchAppDoButSaveClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButPlaEditClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButCchViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

public:
	void handleCall(DbsWdbe* dbswdbe, Sbecore::Call* call);

private:
	bool handleCallWdbeMch_cchEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeMchUpd_refEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);
	bool handleCallWdbeKlsAkeyMod_klsEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv);

};

#endif

