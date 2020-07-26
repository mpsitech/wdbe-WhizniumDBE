/**
	* \file PnlWdbeSigDetail.h
	* job handler for job PnlWdbeSigDetail (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef PNLWDBESIGDETAIL_H
#define PNLWDBESIGDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWdbeSigDetailDo PnlWdbeSigDetail::VecVDo

#define ContIacWdbeSigDetail PnlWdbeSigDetail::ContIac
#define ContInfWdbeSigDetail PnlWdbeSigDetail::ContInf
#define StatAppWdbeSigDetail PnlWdbeSigDetail::StatApp
#define StatShrWdbeSigDetail PnlWdbeSigDetail::StatShr
#define TagWdbeSigDetail PnlWdbeSigDetail::Tag

#define DpchAppWdbeSigDetailData PnlWdbeSigDetail::DpchAppData
#define DpchAppWdbeSigDetailDo PnlWdbeSigDetail::DpchAppDo
#define DpchEngWdbeSigDetailData PnlWdbeSigDetail::DpchEngData

/**
	* PnlWdbeSigDetail
	*/
class PnlWdbeSigDetail : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVWdbeSigDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTCLUVIEWCLICK = 2;
		static const Sbecore::uint BUTCLUCLUSTERCLICK = 3;
		static const Sbecore::uint BUTCLUUNCLUSTERCLICK = 4;
		static const Sbecore::uint BUTMDLVIEWCLICK = 5;
		static const Sbecore::uint BUTMGUVIEWCLICK = 6;
		static const Sbecore::uint BUTVECVIEWCLICK = 7;
		static const Sbecore::uint BUTHTYEDITCLICK = 8;
		static const Sbecore::uint BUTDRVVIEWCLICK = 9;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeSigDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFPUPTYP = 1;
		static const Sbecore::uint NUMFLSTCLU = 2;
		static const Sbecore::uint NUMFPUPMGT = 3;
		static const Sbecore::uint CHKCON = 4;
		static const Sbecore::uint NUMFPUPHTY = 5;
		static const Sbecore::uint TXFHTY = 6;
		static const Sbecore::uint TXFWID = 7;
		static const Sbecore::uint TXFMMX = 8;
		static const Sbecore::uint TXFCMB = 9;
		static const Sbecore::uint TXFONV = 10;
		static const Sbecore::uint TXFOFV = 11;
		static const Sbecore::uint CHKDFO = 12;
		static const Sbecore::uint TXFCMT = 13;

	public:
		ContIac(const Sbecore::uint numFPupTyp = 1, const Sbecore::uint numFLstClu = 1, const Sbecore::uint numFPupMgt = 1, const bool ChkCon = false, const Sbecore::uint numFPupHty = 1, const std::string& TxfHty = "", const std::string& TxfWid = "", const std::string& TxfMmx = "", const std::string& TxfCmb = "", const std::string& TxfOnv = "", const std::string& TxfOfv = "", const bool ChkDfo = false, const std::string& TxfCmt = "");

	public:
		Sbecore::uint numFPupTyp;
		Sbecore::uint numFLstClu;
		Sbecore::uint numFPupMgt;
		bool ChkCon;
		Sbecore::uint numFPupHty;
		std::string TxfHty;
		std::string TxfWid;
		std::string TxfMmx;
		std::string TxfCmb;
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
	  * ContInf (full: ContInfWdbeSigDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTCLU = 2;
		static const Sbecore::uint TXTMDL = 3;
		static const Sbecore::uint TXTMGU = 4;
		static const Sbecore::uint TXTVEC = 5;
		static const Sbecore::uint TXTDRV = 6;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtClu = "", const std::string& TxtMdl = "", const std::string& TxtMgu = "", const std::string& TxtVec = "", const std::string& TxtDrv = "");

	public:
		std::string TxtSrf;
		std::string TxtClu;
		std::string TxtMdl;
		std::string TxtMgu;
		std::string TxtVec;
		std::string TxtDrv;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWdbeSigDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool LstCluAlt = true, const bool PupHtyAlt = false, const Sbecore::uint LstCluNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWdbeSigDetail)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFHTYVALID = 1;
		static const Sbecore::uint BUTSAVEAVAIL = 2;
		static const Sbecore::uint BUTSAVEACTIVE = 3;
		static const Sbecore::uint TXTSRFACTIVE = 4;
		static const Sbecore::uint PUPTYPACTIVE = 5;
		static const Sbecore::uint LSTCLUACTIVE = 6;
		static const Sbecore::uint BUTCLUVIEWACTIVE = 7;
		static const Sbecore::uint BUTCLUCLUSTERAVAIL = 8;
		static const Sbecore::uint BUTCLUUNCLUSTERAVAIL = 9;
		static const Sbecore::uint TXTMDLACTIVE = 10;
		static const Sbecore::uint BUTMDLVIEWAVAIL = 11;
		static const Sbecore::uint BUTMDLVIEWACTIVE = 12;
		static const Sbecore::uint TXTMGUACTIVE = 13;
		static const Sbecore::uint BUTMGUVIEWAVAIL = 14;
		static const Sbecore::uint BUTMGUVIEWACTIVE = 15;
		static const Sbecore::uint TXTVECACTIVE = 16;
		static const Sbecore::uint BUTVECVIEWAVAIL = 17;
		static const Sbecore::uint BUTVECVIEWACTIVE = 18;
		static const Sbecore::uint CHKCONACTIVE = 19;
		static const Sbecore::uint PUPHTYACTIVE = 20;
		static const Sbecore::uint BUTHTYEDITAVAIL = 21;
		static const Sbecore::uint TXFWIDACTIVE = 22;
		static const Sbecore::uint TXFMMXACTIVE = 23;
		static const Sbecore::uint TXFCMBACTIVE = 24;
		static const Sbecore::uint TXFONVACTIVE = 25;
		static const Sbecore::uint TXFOFVACTIVE = 26;
		static const Sbecore::uint CHKDFOACTIVE = 27;
		static const Sbecore::uint TXTDRVACTIVE = 28;
		static const Sbecore::uint BUTDRVVIEWAVAIL = 29;
		static const Sbecore::uint BUTDRVVIEWACTIVE = 30;
		static const Sbecore::uint TXFCMTACTIVE = 31;

	public:
		StatShr(const bool TxfHtyValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool PupTypActive = true, const bool LstCluActive = true, const bool ButCluViewActive = true, const bool ButCluClusterAvail = true, const bool ButCluUnclusterAvail = true, const bool TxtMdlActive = true, const bool ButMdlViewAvail = true, const bool ButMdlViewActive = true, const bool TxtMguActive = true, const bool ButMguViewAvail = true, const bool ButMguViewActive = true, const bool TxtVecActive = true, const bool ButVecViewAvail = true, const bool ButVecViewActive = true, const bool ChkConActive = true, const bool PupHtyActive = true, const bool ButHtyEditAvail = true, const bool TxfWidActive = true, const bool TxfMmxActive = true, const bool TxfCmbActive = true, const bool TxfOnvActive = true, const bool TxfOfvActive = true, const bool ChkDfoActive = true, const bool TxtDrvActive = true, const bool ButDrvViewAvail = true, const bool ButDrvViewActive = true, const bool TxfCmtActive = true);

	public:
		bool TxfHtyValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool PupTypActive;
		bool LstCluActive;
		bool ButCluViewActive;
		bool ButCluClusterAvail;
		bool ButCluUnclusterAvail;
		bool TxtMdlActive;
		bool ButMdlViewAvail;
		bool ButMdlViewActive;
		bool TxtMguActive;
		bool ButMguViewAvail;
		bool ButMguViewActive;
		bool TxtVecActive;
		bool ButVecViewAvail;
		bool ButVecViewActive;
		bool ChkConActive;
		bool PupHtyActive;
		bool ButHtyEditAvail;
		bool TxfWidActive;
		bool TxfMmxActive;
		bool TxfCmbActive;
		bool TxfOnvActive;
		bool TxfOfvActive;
		bool ChkDfoActive;
		bool TxtDrvActive;
		bool ButDrvViewAvail;
		bool ButDrvViewActive;
		bool TxfCmtActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWdbeSigDetail)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWdbeSigDetailData)
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
		* DpchAppDo (full: DpchAppWdbeSigDetailDo)
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
		* DpchEngData (full: DpchEngWdbeSigDetailData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTCLU = 4;
		static const Sbecore::uint FEEDFPUPHTY = 5;
		static const Sbecore::uint FEEDFPUPMGT = 6;
		static const Sbecore::uint FEEDFPUPTYP = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint TAG = 10;
		static const Sbecore::uint ALL = 11;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFLstClu = NULL, Sbecore::Xmlio::Feed* feedFPupHty = NULL, Sbecore::Xmlio::Feed* feedFPupMgt = NULL, Sbecore::Xmlio::Feed* feedFPupTyp = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFLstClu;
		Sbecore::Xmlio::Feed feedFPupHty;
		Sbecore::Xmlio::Feed feedFPupMgt;
		Sbecore::Xmlio::Feed feedFPupTyp;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsWdbe* dbswdbe);
	bool evalButSaveActive(DbsWdbe* dbswdbe);
	bool evalTxtSrfActive(DbsWdbe* dbswdbe);
	bool evalPupTypActive(DbsWdbe* dbswdbe);
	bool evalLstCluActive(DbsWdbe* dbswdbe);
	bool evalButCluViewActive(DbsWdbe* dbswdbe);
	bool evalButCluClusterAvail(DbsWdbe* dbswdbe);
	bool evalButCluUnclusterAvail(DbsWdbe* dbswdbe);
	bool evalTxtMdlActive(DbsWdbe* dbswdbe);
	bool evalButMdlViewAvail(DbsWdbe* dbswdbe);
	bool evalButMdlViewActive(DbsWdbe* dbswdbe);
	bool evalTxtMguActive(DbsWdbe* dbswdbe);
	bool evalButMguViewAvail(DbsWdbe* dbswdbe);
	bool evalButMguViewActive(DbsWdbe* dbswdbe);
	bool evalTxtVecActive(DbsWdbe* dbswdbe);
	bool evalButVecViewAvail(DbsWdbe* dbswdbe);
	bool evalButVecViewActive(DbsWdbe* dbswdbe);
	bool evalChkConActive(DbsWdbe* dbswdbe);
	bool evalPupHtyActive(DbsWdbe* dbswdbe);
	bool evalButHtyEditAvail(DbsWdbe* dbswdbe);
	bool evalTxfWidActive(DbsWdbe* dbswdbe);
	bool evalTxfMmxActive(DbsWdbe* dbswdbe);
	bool evalTxfCmbActive(DbsWdbe* dbswdbe);
	bool evalTxfOnvActive(DbsWdbe* dbswdbe);
	bool evalTxfOfvActive(DbsWdbe* dbswdbe);
	bool evalChkDfoActive(DbsWdbe* dbswdbe);
	bool evalTxtDrvActive(DbsWdbe* dbswdbe);
	bool evalButDrvViewAvail(DbsWdbe* dbswdbe);
	bool evalButDrvViewActive(DbsWdbe* dbswdbe);
	bool evalTxfCmtActive(DbsWdbe* dbswdbe);

public:
	PnlWdbeSigDetail(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~PnlWdbeSigDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFLstClu;
	Sbecore::Xmlio::Feed feedFPupHty;
	Sbecore::Xmlio::Feed feedFPupMgt;
	Sbecore::Xmlio::Feed feedFPupTyp;

	WdbeMSignal recSig;

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

	void refreshRecSig(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

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
	void handleDpchAppDoButMguViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButVecViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButHtyEditClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButDrvViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

public:
	void handleCall(DbsWdbe* dbswdbe, Sbecore::Call* call);

private:
	bool handleCallWdbeSigMod_cluEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);
	bool handleCallWdbeKlsAkeyMod_klsMtbUrfEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, const std::string& srefInv);
	bool handleCallWdbeSigUpd_refEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);
	bool handleCallWdbeSig_vecEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeSig_mguEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeSig_mgu_inSbs(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWdbeSig_mgtEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWdbeSig_mdlEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeSig_drvEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeSig_cluEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif

