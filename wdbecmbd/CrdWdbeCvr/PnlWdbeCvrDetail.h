/**
	* \file PnlWdbeCvrDetail.h
	* job handler for job PnlWdbeCvrDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBECVRDETAIL_H
#define PNLWDBECVRDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWdbeCvrDetailDo PnlWdbeCvrDetail::VecVDo

#define ContIacWdbeCvrDetail PnlWdbeCvrDetail::ContIac
#define ContInfWdbeCvrDetail PnlWdbeCvrDetail::ContInf
#define StatAppWdbeCvrDetail PnlWdbeCvrDetail::StatApp
#define StatShrWdbeCvrDetail PnlWdbeCvrDetail::StatShr
#define TagWdbeCvrDetail PnlWdbeCvrDetail::Tag

#define DpchAppWdbeCvrDetailData PnlWdbeCvrDetail::DpchAppData
#define DpchAppWdbeCvrDetailDo PnlWdbeCvrDetail::DpchAppDo
#define DpchEngWdbeCvrDetailData PnlWdbeCvrDetail::DpchEngData

/**
	* PnlWdbeCvrDetail
	*/
class PnlWdbeCvrDetail : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVWdbeCvrDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTCPRVIEWCLICK = 2;
		static const Sbecore::uint BUTBCVVIEWCLICK = 3;
		static const Sbecore::uint BUTJSTEDITCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeCvrDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFMAJ = 1;
		static const Sbecore::uint TXFMIN = 2;
		static const Sbecore::uint TXFSUB = 3;
		static const Sbecore::uint NUMFPUPJST = 4;
		static const Sbecore::uint NUMFPUPSTE = 5;
		static const Sbecore::uint NUMSFLSTSTY = 6;

	public:
		ContIac(const std::string& TxfMaj = "", const std::string& TxfMin = "", const std::string& TxfSub = "", const Sbecore::uint numFPupJst = 1, const Sbecore::uint numFPupSte = 1, const std::vector<Sbecore::uint>& numsFLstSty = {});

	public:
		std::string TxfMaj;
		std::string TxfMin;
		std::string TxfSub;
		Sbecore::uint numFPupJst;
		Sbecore::uint numFPupSte;
		std::vector<Sbecore::uint> numsFLstSty;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWdbeCvrDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTCPR = 1;
		static const Sbecore::uint TXTBCV = 2;
		static const Sbecore::uint TXTSTY = 3;

	public:
		ContInf(const std::string& TxtCpr = "", const std::string& TxtBcv = "", const std::string& TxtSty = "");

	public:
		std::string TxtCpr;
		std::string TxtBcv;
		std::string TxtSty;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWdbeCvrDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool LstStyAlt = true, const Sbecore::uint LstStyNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWdbeCvrDetail)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTCPRACTIVE = 3;
		static const Sbecore::uint BUTCPRVIEWAVAIL = 4;
		static const Sbecore::uint BUTCPRVIEWACTIVE = 5;
		static const Sbecore::uint TXFMAJACTIVE = 6;
		static const Sbecore::uint TXFMINACTIVE = 7;
		static const Sbecore::uint TXFSUBACTIVE = 8;
		static const Sbecore::uint TXTBCVACTIVE = 9;
		static const Sbecore::uint BUTBCVVIEWAVAIL = 10;
		static const Sbecore::uint BUTBCVVIEWACTIVE = 11;
		static const Sbecore::uint PUPJSTACTIVE = 12;
		static const Sbecore::uint BUTJSTEDITAVAIL = 13;
		static const Sbecore::uint PUPSTEACTIVE = 14;
		static const Sbecore::uint LSTSTYACTIVE = 15;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtCprActive = true, const bool ButCprViewAvail = true, const bool ButCprViewActive = true, const bool TxfMajActive = true, const bool TxfMinActive = true, const bool TxfSubActive = true, const bool TxtBcvActive = true, const bool ButBcvViewAvail = true, const bool ButBcvViewActive = true, const bool PupJstActive = true, const bool ButJstEditAvail = true, const bool PupSteActive = true, const bool LstStyActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtCprActive;
		bool ButCprViewAvail;
		bool ButCprViewActive;
		bool TxfMajActive;
		bool TxfMinActive;
		bool TxfSubActive;
		bool TxtBcvActive;
		bool ButBcvViewAvail;
		bool ButBcvViewActive;
		bool PupJstActive;
		bool ButJstEditAvail;
		bool PupSteActive;
		bool LstStyActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWdbeCvrDetail)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWdbeCvrDetailData)
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
		* DpchAppDo (full: DpchAppWdbeCvrDetailDo)
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
		* DpchEngData (full: DpchEngWdbeCvrDetailData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTSTY = 4;
		static const Sbecore::uint FEEDFPUPJST = 5;
		static const Sbecore::uint FEEDFPUPSTE = 6;
		static const Sbecore::uint STATAPP = 7;
		static const Sbecore::uint STATSHR = 8;
		static const Sbecore::uint TAG = 9;
		static const Sbecore::uint ALL = 10;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFLstSty = NULL, Sbecore::Xmlio::Feed* feedFPupJst = NULL, Sbecore::Xmlio::Feed* feedFPupSte = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFLstSty;
		Sbecore::Xmlio::Feed feedFPupJst;
		Sbecore::Xmlio::Feed feedFPupSte;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsWdbe* dbswdbe);
	bool evalButSaveActive(DbsWdbe* dbswdbe);
	bool evalTxtCprActive(DbsWdbe* dbswdbe);
	bool evalButCprViewAvail(DbsWdbe* dbswdbe);
	bool evalButCprViewActive(DbsWdbe* dbswdbe);
	bool evalTxfMajActive(DbsWdbe* dbswdbe);
	bool evalTxfMinActive(DbsWdbe* dbswdbe);
	bool evalTxfSubActive(DbsWdbe* dbswdbe);
	bool evalTxtBcvActive(DbsWdbe* dbswdbe);
	bool evalButBcvViewAvail(DbsWdbe* dbswdbe);
	bool evalButBcvViewActive(DbsWdbe* dbswdbe);
	bool evalPupJstActive(DbsWdbe* dbswdbe);
	bool evalButJstEditAvail(DbsWdbe* dbswdbe);
	bool evalPupSteActive(DbsWdbe* dbswdbe);
	bool evalLstStyActive(DbsWdbe* dbswdbe);

public:
	PnlWdbeCvrDetail(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~PnlWdbeCvrDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFLstSty;
	Sbecore::Xmlio::Feed feedFPupJst;
	Sbecore::Xmlio::Feed feedFPupSte;

	WdbeMCoreversion recCvr;

	WdbeJMCoreversionState recCvrJste;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshJst(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshTxtSty(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

	void refreshRecCvr(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshRecCvrJste(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:

	void handleDpchAppWdbeInit(DbsWdbe* dbswdbe, DpchAppWdbeInit* dpchappwdbeinit, DpchEngWdbe** dpcheng);
	void handleDpchAppDataContiac(DbsWdbe* dbswdbe, ContIac* _contiac, DpchEngWdbe** dpcheng);

	void handleDpchAppDoButSaveClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButCprViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButBcvViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButJstEditClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

public:
	void handleCall(DbsWdbe* dbswdbe, Sbecore::Call* call);

private:
	bool handleCallWdbeCvr_bcvEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeCvr_cprEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeCvrUpd_refEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);
	bool handleCallWdbeCvrJsteMod_cvrEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);

};

#endif
