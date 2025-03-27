/**
	* \file PnlWdbeCdcDetail.h
	* job handler for job PnlWdbeCdcDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 9 May 2023
	*/
// IP header --- ABOVE

#ifndef PNLWDBECDCDETAIL_H
#define PNLWDBECDCDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWdbeCdcDetailDo PnlWdbeCdcDetail::VecVDo

#define ContIacWdbeCdcDetail PnlWdbeCdcDetail::ContIac
#define ContInfWdbeCdcDetail PnlWdbeCdcDetail::ContInf
#define StatAppWdbeCdcDetail PnlWdbeCdcDetail::StatApp
#define StatShrWdbeCdcDetail PnlWdbeCdcDetail::StatShr
#define TagWdbeCdcDetail PnlWdbeCdcDetail::Tag

#define DpchAppWdbeCdcDetailData PnlWdbeCdcDetail::DpchAppData
#define DpchAppWdbeCdcDetailDo PnlWdbeCdcDetail::DpchAppDo
#define DpchEngWdbeCdcDetailData PnlWdbeCdcDetail::DpchEngData

/**
	* PnlWdbeCdcDetail
	*/
class PnlWdbeCdcDetail : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVWdbeCdcDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTFCKVIEWCLICK = 2;
		static const Sbecore::uint BUTSCKVIEWCLICK = 3;
		static const Sbecore::uint BUTMDLVIEWCLICK = 4;
		static const Sbecore::uint BUTFARVIEWCLICK = 5;
		static const Sbecore::uint BUTSARVIEWCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeCdcDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFFCK = 1;
		static const Sbecore::uint TXFSCK = 2;
		static const Sbecore::uint TXFFAR = 3;
		static const Sbecore::uint TXFSAR = 4;
		static const Sbecore::uint TXFRAT = 5;

	public:
		ContIac(const std::string& TxfFck = "", const std::string& TxfSck = "", const std::string& TxfFar = "", const std::string& TxfSar = "", const std::string& TxfRat = "");

	public:
		std::string TxfFck;
		std::string TxfSck;
		std::string TxfFar;
		std::string TxfSar;
		std::string TxfRat;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWdbeCdcDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTFCK = 1;
		static const Sbecore::uint TXTSCK = 2;
		static const Sbecore::uint TXTMDL = 3;
		static const Sbecore::uint TXTFAR = 4;
		static const Sbecore::uint TXTSAR = 5;

	public:
		ContInf(const std::string& TxtFck = "", const std::string& TxtSck = "", const std::string& TxtMdl = "", const std::string& TxtFar = "", const std::string& TxtSar = "");

	public:
		std::string TxtFck;
		std::string TxtSck;
		std::string TxtMdl;
		std::string TxtFar;
		std::string TxtSar;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWdbeCdcDetail)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool TxtFckAlt = false, const bool TxtSckAlt = false, const bool TxtFarAlt = false, const bool TxtSarAlt = false);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool TxtFckAlt = false, const bool TxtSckAlt = false, const bool TxtFarAlt = false, const bool TxtSarAlt = false);
	};

	/**
		* StatShr (full: StatShrWdbeCdcDetail)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTFCKACTIVE = 3;
		static const Sbecore::uint TXFFCKVALID = 4;
		static const Sbecore::uint BUTFCKVIEWAVAIL = 5;
		static const Sbecore::uint TXTSCKACTIVE = 6;
		static const Sbecore::uint TXFSCKVALID = 7;
		static const Sbecore::uint BUTSCKVIEWAVAIL = 8;
		static const Sbecore::uint TXTMDLACTIVE = 9;
		static const Sbecore::uint BUTMDLVIEWAVAIL = 10;
		static const Sbecore::uint BUTMDLVIEWACTIVE = 11;
		static const Sbecore::uint TXTFARACTIVE = 12;
		static const Sbecore::uint TXFFARVALID = 13;
		static const Sbecore::uint BUTFARVIEWAVAIL = 14;
		static const Sbecore::uint TXTSARACTIVE = 15;
		static const Sbecore::uint TXFSARVALID = 16;
		static const Sbecore::uint BUTSARVIEWAVAIL = 17;
		static const Sbecore::uint TXFRATACTIVE = 18;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtFckActive = true, const bool TxfFckValid = false, const bool ButFckViewAvail = true, const bool TxtSckActive = true, const bool TxfSckValid = false, const bool ButSckViewAvail = true, const bool TxtMdlActive = true, const bool ButMdlViewAvail = true, const bool ButMdlViewActive = true, const bool TxtFarActive = true, const bool TxfFarValid = false, const bool ButFarViewAvail = true, const bool TxtSarActive = true, const bool TxfSarValid = false, const bool ButSarViewAvail = true, const bool TxfRatActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtFckActive;
		bool TxfFckValid;
		bool ButFckViewAvail;
		bool TxtSckActive;
		bool TxfSckValid;
		bool ButSckViewAvail;
		bool TxtMdlActive;
		bool ButMdlViewAvail;
		bool ButMdlViewActive;
		bool TxtFarActive;
		bool TxfFarValid;
		bool ButFarViewAvail;
		bool TxtSarActive;
		bool TxfSarValid;
		bool ButSarViewAvail;
		bool TxfRatActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWdbeCdcDetail)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWdbeCdcDetailData)
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
		* DpchAppDo (full: DpchAppWdbeCdcDetailDo)
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
		* DpchEngData (full: DpchEngWdbeCdcDetailData)
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
	bool evalTxtFckActive(DbsWdbe* dbswdbe);
	bool evalButFckViewAvail(DbsWdbe* dbswdbe);
	bool evalTxtSckActive(DbsWdbe* dbswdbe);
	bool evalButSckViewAvail(DbsWdbe* dbswdbe);
	bool evalTxtMdlActive(DbsWdbe* dbswdbe);
	bool evalButMdlViewAvail(DbsWdbe* dbswdbe);
	bool evalButMdlViewActive(DbsWdbe* dbswdbe);
	bool evalTxtFarActive(DbsWdbe* dbswdbe);
	bool evalButFarViewAvail(DbsWdbe* dbswdbe);
	bool evalTxtSarActive(DbsWdbe* dbswdbe);
	bool evalButSarViewAvail(DbsWdbe* dbswdbe);
	bool evalTxfRatActive(DbsWdbe* dbswdbe);

public:
	PnlWdbeCdcDetail(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~PnlWdbeCdcDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	WdbeMCdc recCdc;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshTxtFck(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshTxtSck(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshTxtFar(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshTxtSar(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

	void refreshRecCdc(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:

	void handleDpchAppWdbeInit(DbsWdbe* dbswdbe, DpchAppWdbeInit* dpchappwdbeinit, DpchEngWdbe** dpcheng);
	void handleDpchAppDataContiac(DbsWdbe* dbswdbe, ContIac* _contiac, DpchEngWdbe** dpcheng);

	void handleDpchAppDoButSaveClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButFckViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButSckViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButMdlViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButFarViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButSarViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

public:
	void handleCall(DbsWdbe* dbswdbe, Sbecore::Call* call);

private:
	bool handleCallWdbeCdcUpd_refEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);
	bool handleCallWdbeCdc_mdlEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif
