/**
	* \file PnlWdbePrtDetail.h
	* job handler for job PnlWdbePrtDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBEPRTDETAIL_H
#define PNLWDBEPRTDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWdbePrtDetailDo PnlWdbePrtDetail::VecVDo

#define ContIacWdbePrtDetail PnlWdbePrtDetail::ContIac
#define ContInfWdbePrtDetail PnlWdbePrtDetail::ContInf
#define StatAppWdbePrtDetail PnlWdbePrtDetail::StatApp
#define StatShrWdbePrtDetail PnlWdbePrtDetail::StatShr
#define TagWdbePrtDetail PnlWdbePrtDetail::Tag

#define DpchAppWdbePrtDetailData PnlWdbePrtDetail::DpchAppData
#define DpchAppWdbePrtDetailDo PnlWdbePrtDetail::DpchAppDo
#define DpchEngWdbePrtDetailData PnlWdbePrtDetail::DpchEngData

/**
	* PnlWdbePrtDetail
	*/
class PnlWdbePrtDetail : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVWdbePrtDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTCLUVIEWCLICK = 2;
		static const Sbecore::uint BUTCLUCLUSTERCLICK = 3;
		static const Sbecore::uint BUTCLUUNCLUSTERCLICK = 4;
		static const Sbecore::uint BUTMDLVIEWCLICK = 5;
		static const Sbecore::uint BUTHTYEDITCLICK = 6;
		static const Sbecore::uint BUTCPIVIEWCLICK = 7;
		static const Sbecore::uint BUTCPRVIEWCLICK = 8;
		static const Sbecore::uint BUTCSIVIEWCLICK = 9;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbePrtDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFLSTCLU = 1;
		static const Sbecore::uint NUMFPUPDIR = 2;
		static const Sbecore::uint NUMFPUPHTY = 3;
		static const Sbecore::uint TXFHTY = 4;
		static const Sbecore::uint TXFWID = 5;
		static const Sbecore::uint TXFMMX = 6;
		static const Sbecore::uint TXFDFV = 7;
		static const Sbecore::uint TXFCPI = 8;
		static const Sbecore::uint TXFCPR = 9;
		static const Sbecore::uint TXFCSI = 10;
		static const Sbecore::uint TXFCMT = 11;

	public:
		ContIac(const Sbecore::uint numFLstClu = 1, const Sbecore::uint numFPupDir = 1, const Sbecore::uint numFPupHty = 1, const std::string& TxfHty = "", const std::string& TxfWid = "", const std::string& TxfMmx = "", const std::string& TxfDfv = "", const std::string& TxfCpi = "", const std::string& TxfCpr = "", const std::string& TxfCsi = "", const std::string& TxfCmt = "");

	public:
		Sbecore::uint numFLstClu;
		Sbecore::uint numFPupDir;
		Sbecore::uint numFPupHty;
		std::string TxfHty;
		std::string TxfWid;
		std::string TxfMmx;
		std::string TxfDfv;
		std::string TxfCpi;
		std::string TxfCpr;
		std::string TxfCsi;
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
	  * ContInf (full: ContInfWdbePrtDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTCLU = 2;
		static const Sbecore::uint TXTMDL = 3;
		static const Sbecore::uint TXTCPI = 4;
		static const Sbecore::uint TXTCPR = 5;
		static const Sbecore::uint TXTCSI = 6;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtClu = "", const std::string& TxtMdl = "", const std::string& TxtCpi = "", const std::string& TxtCpr = "", const std::string& TxtCsi = "");

	public:
		std::string TxtSrf;
		std::string TxtClu;
		std::string TxtMdl;
		std::string TxtCpi;
		std::string TxtCpr;
		std::string TxtCsi;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWdbePrtDetail)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool LstCluAlt = true, const bool PupHtyAlt = false, const bool TxtCpiAlt = false, const bool TxtCprAlt = false, const bool TxtCsiAlt = false, const Sbecore::uint LstCluNumFirstdisp = 1);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool LstCluAlt = true, const bool PupHtyAlt = false, const bool TxtCpiAlt = false, const bool TxtCprAlt = false, const bool TxtCsiAlt = false, const Sbecore::uint LstCluNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWdbePrtDetail)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFHTYVALID = 1;
		static const Sbecore::uint TXFCPIVALID = 2;
		static const Sbecore::uint TXFCPRVALID = 3;
		static const Sbecore::uint TXFCSIVALID = 4;
		static const Sbecore::uint BUTSAVEAVAIL = 5;
		static const Sbecore::uint BUTSAVEACTIVE = 6;
		static const Sbecore::uint TXTSRFACTIVE = 7;
		static const Sbecore::uint LSTCLUACTIVE = 8;
		static const Sbecore::uint BUTCLUVIEWACTIVE = 9;
		static const Sbecore::uint BUTCLUCLUSTERAVAIL = 10;
		static const Sbecore::uint BUTCLUUNCLUSTERAVAIL = 11;
		static const Sbecore::uint TXTMDLACTIVE = 12;
		static const Sbecore::uint BUTMDLVIEWAVAIL = 13;
		static const Sbecore::uint BUTMDLVIEWACTIVE = 14;
		static const Sbecore::uint PUPDIRACTIVE = 15;
		static const Sbecore::uint PUPHTYACTIVE = 16;
		static const Sbecore::uint BUTHTYEDITAVAIL = 17;
		static const Sbecore::uint TXFWIDACTIVE = 18;
		static const Sbecore::uint TXFMMXACTIVE = 19;
		static const Sbecore::uint TXFDFVACTIVE = 20;
		static const Sbecore::uint TXTCPIACTIVE = 21;
		static const Sbecore::uint BUTCPIVIEWAVAIL = 22;
		static const Sbecore::uint TXTCPRACTIVE = 23;
		static const Sbecore::uint BUTCPRVIEWAVAIL = 24;
		static const Sbecore::uint TXTCSIACTIVE = 25;
		static const Sbecore::uint BUTCSIVIEWAVAIL = 26;
		static const Sbecore::uint TXFCMTACTIVE = 27;

	public:
		StatShr(const bool TxfHtyValid = false, const bool TxfCpiValid = false, const bool TxfCprValid = false, const bool TxfCsiValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool LstCluActive = true, const bool ButCluViewActive = true, const bool ButCluClusterAvail = true, const bool ButCluUnclusterAvail = true, const bool TxtMdlActive = true, const bool ButMdlViewAvail = true, const bool ButMdlViewActive = true, const bool PupDirActive = true, const bool PupHtyActive = true, const bool ButHtyEditAvail = true, const bool TxfWidActive = true, const bool TxfMmxActive = true, const bool TxfDfvActive = true, const bool TxtCpiActive = true, const bool ButCpiViewAvail = true, const bool TxtCprActive = true, const bool ButCprViewAvail = true, const bool TxtCsiActive = true, const bool ButCsiViewAvail = true, const bool TxfCmtActive = true);

	public:
		bool TxfHtyValid;
		bool TxfCpiValid;
		bool TxfCprValid;
		bool TxfCsiValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool LstCluActive;
		bool ButCluViewActive;
		bool ButCluClusterAvail;
		bool ButCluUnclusterAvail;
		bool TxtMdlActive;
		bool ButMdlViewAvail;
		bool ButMdlViewActive;
		bool PupDirActive;
		bool PupHtyActive;
		bool ButHtyEditAvail;
		bool TxfWidActive;
		bool TxfMmxActive;
		bool TxfDfvActive;
		bool TxtCpiActive;
		bool ButCpiViewAvail;
		bool TxtCprActive;
		bool ButCprViewAvail;
		bool TxtCsiActive;
		bool ButCsiViewAvail;
		bool TxfCmtActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWdbePrtDetail)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWdbePrtDetailData)
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
		* DpchAppDo (full: DpchAppWdbePrtDetailDo)
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
		* DpchEngData (full: DpchEngWdbePrtDetailData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTCLU = 4;
		static const Sbecore::uint FEEDFPUPDIR = 5;
		static const Sbecore::uint FEEDFPUPHTY = 6;
		static const Sbecore::uint STATAPP = 7;
		static const Sbecore::uint STATSHR = 8;
		static const Sbecore::uint TAG = 9;
		static const Sbecore::uint ALL = 10;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Feed* feedFLstClu = NULL, Sbecore::Feed* feedFPupDir = NULL, Sbecore::Feed* feedFPupHty = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFLstClu;
		Sbecore::Feed feedFPupDir;
		Sbecore::Feed feedFPupHty;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsWdbe* dbswdbe);
	bool evalButSaveActive(DbsWdbe* dbswdbe);
	bool evalTxtSrfActive(DbsWdbe* dbswdbe);
	bool evalLstCluActive(DbsWdbe* dbswdbe);
	bool evalButCluViewActive(DbsWdbe* dbswdbe);
	bool evalButCluClusterAvail(DbsWdbe* dbswdbe);
	bool evalButCluUnclusterAvail(DbsWdbe* dbswdbe);
	bool evalTxtMdlActive(DbsWdbe* dbswdbe);
	bool evalButMdlViewAvail(DbsWdbe* dbswdbe);
	bool evalButMdlViewActive(DbsWdbe* dbswdbe);
	bool evalPupDirActive(DbsWdbe* dbswdbe);
	bool evalPupHtyActive(DbsWdbe* dbswdbe);
	bool evalButHtyEditAvail(DbsWdbe* dbswdbe);
	bool evalTxfWidActive(DbsWdbe* dbswdbe);
	bool evalTxfMmxActive(DbsWdbe* dbswdbe);
	bool evalTxfDfvActive(DbsWdbe* dbswdbe);
	bool evalTxtCpiActive(DbsWdbe* dbswdbe);
	bool evalButCpiViewAvail(DbsWdbe* dbswdbe);
	bool evalTxtCprActive(DbsWdbe* dbswdbe);
	bool evalButCprViewAvail(DbsWdbe* dbswdbe);
	bool evalTxtCsiActive(DbsWdbe* dbswdbe);
	bool evalButCsiViewAvail(DbsWdbe* dbswdbe);
	bool evalTxfCmtActive(DbsWdbe* dbswdbe);

public:
	PnlWdbePrtDetail(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~PnlWdbePrtDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFLstClu;
	Sbecore::Feed feedFPupDir;
	Sbecore::Feed feedFPupHty;

	WdbeMPort recPrt;

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
	void refreshTxtCpi(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshTxtCpr(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshTxtCsi(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

	void refreshRecPrt(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

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
	void handleDpchAppDoButMdlViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButHtyEditClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButCpiViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButCprViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButCsiViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

public:
	void handleCall(DbsWdbe* dbswdbe, Sbecore::Call* call);

private:
	bool handleCallWdbePrtMod_cluEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);
	bool handleCallWdbeKlsAkeyMod_klsMtbUrfEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, const std::string& srefInv);
	bool handleCallWdbePrtUpd_refEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);
	bool handleCallWdbePrt_mdlEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbePrt_mdl_inSbs(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWdbePrt_cluEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif
