/**
	* \file PnlWdbeModDetail.h
	* job handler for job PnlWdbeModDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBEMODDETAIL_H
#define PNLWDBEMODDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWdbeModDetailDo PnlWdbeModDetail::VecVDo

#define ContIacWdbeModDetail PnlWdbeModDetail::ContIac
#define ContInfWdbeModDetail PnlWdbeModDetail::ContInf
#define StatAppWdbeModDetail PnlWdbeModDetail::StatApp
#define StatShrWdbeModDetail PnlWdbeModDetail::StatShr
#define TagWdbeModDetail PnlWdbeModDetail::Tag

#define DpchAppWdbeModDetailData PnlWdbeModDetail::DpchAppData
#define DpchAppWdbeModDetailDo PnlWdbeModDetail::DpchAppDo
#define DpchEngWdbeModDetailData PnlWdbeModDetail::DpchEngData

/**
	* PnlWdbeModDetail
	*/
class PnlWdbeModDetail : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVWdbeModDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTVNDEDITCLICK = 2;
		static const Sbecore::uint BUTHKUVIEWCLICK = 3;
		static const Sbecore::uint BUTSUPVIEWCLICK = 4;
		static const Sbecore::uint BUTTPLVIEWCLICK = 5;
		static const Sbecore::uint BUTCTRNEWCLICK = 6;
		static const Sbecore::uint BUTCTRDELETECLICK = 7;
		static const Sbecore::uint BUTCTRFWDVIEWCLICK = 8;
		static const Sbecore::uint BUTCTRCLRVIEWCLICK = 9;
		static const Sbecore::uint BUTIMBNEWCLICK = 10;
		static const Sbecore::uint BUTIMBDELETECLICK = 11;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeModDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFPUPVND = 1;
		static const Sbecore::uint TXFVND = 2;
		static const Sbecore::uint NUMFPUPTYP = 3;
		static const Sbecore::uint NUMFPUPHKT = 4;
		static const Sbecore::uint TXFSRR = 5;
		static const Sbecore::uint TXFCMT = 6;
		static const Sbecore::uint TXFCTRFSR = 7;
		static const Sbecore::uint TXFIMBFSR = 8;
		static const Sbecore::uint NUMFPUPIMBRTY = 9;
		static const Sbecore::uint TXFIMBWID = 10;
		static const Sbecore::uint TXFIMBMMX = 11;
		static const Sbecore::uint TXFIMBPRI = 12;

	public:
		ContIac(const Sbecore::uint numFPupVnd = 1, const std::string& TxfVnd = "", const Sbecore::uint numFPupTyp = 1, const Sbecore::uint numFPupHkt = 1, const std::string& TxfSrr = "", const std::string& TxfCmt = "", const std::string& TxfCtrFsr = "", const std::string& TxfImbFsr = "", const Sbecore::uint numFPupImbRty = 1, const std::string& TxfImbWid = "", const std::string& TxfImbMmx = "", const std::string& TxfImbPri = "");

	public:
		Sbecore::uint numFPupVnd;
		std::string TxfVnd;
		Sbecore::uint numFPupTyp;
		Sbecore::uint numFPupHkt;
		std::string TxfSrr;
		std::string TxfCmt;
		std::string TxfCtrFsr;
		std::string TxfImbFsr;
		Sbecore::uint numFPupImbRty;
		std::string TxfImbWid;
		std::string TxfImbMmx;
		std::string TxfImbPri;

	public:
		bool readJSON(Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWdbeModDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTHKU = 2;
		static const Sbecore::uint TXTSUP = 3;
		static const Sbecore::uint TXTTPL = 4;
		static const Sbecore::uint TXTCTRFWD = 5;
		static const Sbecore::uint TXTCTRCLR = 6;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtHku = "", const std::string& TxtSup = "", const std::string& TxtTpl = "", const std::string& TxtCtrFwd = "", const std::string& TxtCtrClr = "");

	public:
		std::string TxtSrf;
		std::string TxtHku;
		std::string TxtSup;
		std::string TxtTpl;
		std::string TxtCtrFwd;
		std::string TxtCtrClr;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWdbeModDetail)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool PupVndAlt = false);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool PupVndAlt = false);
	};

	/**
		* StatShr (full: StatShrWdbeModDetail)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFVNDVALID = 1;
		static const Sbecore::uint BUTSAVEAVAIL = 2;
		static const Sbecore::uint BUTSAVEACTIVE = 3;
		static const Sbecore::uint TXTSRFACTIVE = 4;
		static const Sbecore::uint PUPVNDACTIVE = 5;
		static const Sbecore::uint BUTVNDEDITAVAIL = 6;
		static const Sbecore::uint PUPTYPACTIVE = 7;
		static const Sbecore::uint TXTHKUACTIVE = 8;
		static const Sbecore::uint BUTHKUVIEWAVAIL = 9;
		static const Sbecore::uint BUTHKUVIEWACTIVE = 10;
		static const Sbecore::uint TXTSUPACTIVE = 11;
		static const Sbecore::uint BUTSUPVIEWAVAIL = 12;
		static const Sbecore::uint BUTSUPVIEWACTIVE = 13;
		static const Sbecore::uint TXTTPLACTIVE = 14;
		static const Sbecore::uint BUTTPLVIEWAVAIL = 15;
		static const Sbecore::uint BUTTPLVIEWACTIVE = 16;
		static const Sbecore::uint TXFSRRACTIVE = 17;
		static const Sbecore::uint TXFCMTACTIVE = 18;
		static const Sbecore::uint SEPCTRAVAIL = 19;
		static const Sbecore::uint HDGCTRAVAIL = 20;
		static const Sbecore::uint BUTCTRNEWAVAIL = 21;
		static const Sbecore::uint BUTCTRDELETEAVAIL = 22;
		static const Sbecore::uint TXFCTRFSRAVAIL = 23;
		static const Sbecore::uint TXFCTRFSRACTIVE = 24;
		static const Sbecore::uint TXTCTRFWDAVAIL = 25;
		static const Sbecore::uint TXTCTRFWDACTIVE = 26;
		static const Sbecore::uint BUTCTRFWDVIEWAVAIL = 27;
		static const Sbecore::uint BUTCTRFWDVIEWACTIVE = 28;
		static const Sbecore::uint TXTCTRCLRAVAIL = 29;
		static const Sbecore::uint TXTCTRCLRACTIVE = 30;
		static const Sbecore::uint BUTCTRCLRVIEWAVAIL = 31;
		static const Sbecore::uint BUTCTRCLRVIEWACTIVE = 32;
		static const Sbecore::uint SEPIMBAVAIL = 33;
		static const Sbecore::uint HDGIMBAVAIL = 34;
		static const Sbecore::uint BUTIMBNEWAVAIL = 35;
		static const Sbecore::uint BUTIMBDELETEAVAIL = 36;
		static const Sbecore::uint TXFIMBFSRAVAIL = 37;
		static const Sbecore::uint TXFIMBFSRACTIVE = 38;
		static const Sbecore::uint PUPIMBRTYAVAIL = 39;
		static const Sbecore::uint PUPIMBRTYACTIVE = 40;
		static const Sbecore::uint TXFIMBWIDAVAIL = 41;
		static const Sbecore::uint TXFIMBWIDACTIVE = 42;
		static const Sbecore::uint TXFIMBMMXAVAIL = 43;
		static const Sbecore::uint TXFIMBMMXACTIVE = 44;
		static const Sbecore::uint TXFIMBPRIAVAIL = 45;
		static const Sbecore::uint TXFIMBPRIACTIVE = 46;

	public:
		StatShr(const bool TxfVndValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool PupVndActive = true, const bool ButVndEditAvail = true, const bool PupTypActive = true, const bool TxtHkuActive = true, const bool ButHkuViewAvail = true, const bool ButHkuViewActive = true, const bool TxtSupActive = true, const bool ButSupViewAvail = true, const bool ButSupViewActive = true, const bool TxtTplActive = true, const bool ButTplViewAvail = true, const bool ButTplViewActive = true, const bool TxfSrrActive = true, const bool TxfCmtActive = true, const bool SepCtrAvail = true, const bool HdgCtrAvail = true, const bool ButCtrNewAvail = true, const bool ButCtrDeleteAvail = true, const bool TxfCtrFsrAvail = true, const bool TxfCtrFsrActive = true, const bool TxtCtrFwdAvail = true, const bool TxtCtrFwdActive = true, const bool ButCtrFwdViewAvail = true, const bool ButCtrFwdViewActive = true, const bool TxtCtrClrAvail = true, const bool TxtCtrClrActive = true, const bool ButCtrClrViewAvail = true, const bool ButCtrClrViewActive = true, const bool SepImbAvail = true, const bool HdgImbAvail = true, const bool ButImbNewAvail = true, const bool ButImbDeleteAvail = true, const bool TxfImbFsrAvail = true, const bool TxfImbFsrActive = true, const bool PupImbRtyAvail = true, const bool PupImbRtyActive = true, const bool TxfImbWidAvail = true, const bool TxfImbWidActive = true, const bool TxfImbMmxAvail = true, const bool TxfImbMmxActive = true, const bool TxfImbPriAvail = true, const bool TxfImbPriActive = true);

	public:
		bool TxfVndValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool PupVndActive;
		bool ButVndEditAvail;
		bool PupTypActive;
		bool TxtHkuActive;
		bool ButHkuViewAvail;
		bool ButHkuViewActive;
		bool TxtSupActive;
		bool ButSupViewAvail;
		bool ButSupViewActive;
		bool TxtTplActive;
		bool ButTplViewAvail;
		bool ButTplViewActive;
		bool TxfSrrActive;
		bool TxfCmtActive;
		bool SepCtrAvail;
		bool HdgCtrAvail;
		bool ButCtrNewAvail;
		bool ButCtrDeleteAvail;
		bool TxfCtrFsrAvail;
		bool TxfCtrFsrActive;
		bool TxtCtrFwdAvail;
		bool TxtCtrFwdActive;
		bool ButCtrFwdViewAvail;
		bool ButCtrFwdViewActive;
		bool TxtCtrClrAvail;
		bool TxtCtrClrActive;
		bool ButCtrClrViewAvail;
		bool ButCtrClrViewActive;
		bool SepImbAvail;
		bool HdgImbAvail;
		bool ButImbNewAvail;
		bool ButImbDeleteAvail;
		bool TxfImbFsrAvail;
		bool TxfImbFsrActive;
		bool PupImbRtyAvail;
		bool PupImbRtyActive;
		bool TxfImbWidAvail;
		bool TxfImbWidActive;
		bool TxfImbMmxAvail;
		bool TxfImbMmxActive;
		bool TxfImbPriAvail;
		bool TxfImbPriActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWdbeModDetail)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWdbeModDetailData)
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
		* DpchAppDo (full: DpchAppWdbeModDetailDo)
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
		* DpchEngData (full: DpchEngWdbeModDetailData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPHKT = 4;
		static const Sbecore::uint FEEDFPUPIMBRTY = 5;
		static const Sbecore::uint FEEDFPUPTYP = 6;
		static const Sbecore::uint FEEDFPUPVND = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint TAG = 10;
		static const Sbecore::uint ALL = 11;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Feed* feedFPupHkt = NULL, Sbecore::Feed* feedFPupImbRty = NULL, Sbecore::Feed* feedFPupTyp = NULL, Sbecore::Feed* feedFPupVnd = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFPupHkt;
		Sbecore::Feed feedFPupImbRty;
		Sbecore::Feed feedFPupTyp;
		Sbecore::Feed feedFPupVnd;
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
	bool evalPupVndActive(DbsWdbe* dbswdbe);
	bool evalButVndEditAvail(DbsWdbe* dbswdbe);
	bool evalPupTypActive(DbsWdbe* dbswdbe);
	bool evalTxtHkuActive(DbsWdbe* dbswdbe);
	bool evalButHkuViewAvail(DbsWdbe* dbswdbe);
	bool evalButHkuViewActive(DbsWdbe* dbswdbe);
	bool evalTxtSupActive(DbsWdbe* dbswdbe);
	bool evalButSupViewAvail(DbsWdbe* dbswdbe);
	bool evalButSupViewActive(DbsWdbe* dbswdbe);
	bool evalTxtTplActive(DbsWdbe* dbswdbe);
	bool evalButTplViewAvail(DbsWdbe* dbswdbe);
	bool evalButTplViewActive(DbsWdbe* dbswdbe);
	bool evalTxfSrrActive(DbsWdbe* dbswdbe);
	bool evalTxfCmtActive(DbsWdbe* dbswdbe);
	bool evalSepCtrAvail(DbsWdbe* dbswdbe);
	bool evalHdgCtrAvail(DbsWdbe* dbswdbe);
	bool evalButCtrNewAvail(DbsWdbe* dbswdbe);
	bool evalButCtrDeleteAvail(DbsWdbe* dbswdbe);
	bool evalTxfCtrFsrAvail(DbsWdbe* dbswdbe);
	bool evalTxfCtrFsrActive(DbsWdbe* dbswdbe);
	bool evalTxtCtrFwdAvail(DbsWdbe* dbswdbe);
	bool evalTxtCtrFwdActive(DbsWdbe* dbswdbe);
	bool evalButCtrFwdViewAvail(DbsWdbe* dbswdbe);
	bool evalButCtrFwdViewActive(DbsWdbe* dbswdbe);
	bool evalTxtCtrClrAvail(DbsWdbe* dbswdbe);
	bool evalTxtCtrClrActive(DbsWdbe* dbswdbe);
	bool evalButCtrClrViewAvail(DbsWdbe* dbswdbe);
	bool evalButCtrClrViewActive(DbsWdbe* dbswdbe);
	bool evalSepImbAvail(DbsWdbe* dbswdbe);
	bool evalHdgImbAvail(DbsWdbe* dbswdbe);
	bool evalButImbNewAvail(DbsWdbe* dbswdbe);
	bool evalButImbDeleteAvail(DbsWdbe* dbswdbe);
	bool evalTxfImbFsrAvail(DbsWdbe* dbswdbe);
	bool evalTxfImbFsrActive(DbsWdbe* dbswdbe);
	bool evalPupImbRtyAvail(DbsWdbe* dbswdbe);
	bool evalPupImbRtyActive(DbsWdbe* dbswdbe);
	bool evalTxfImbWidAvail(DbsWdbe* dbswdbe);
	bool evalTxfImbWidActive(DbsWdbe* dbswdbe);
	bool evalTxfImbMmxAvail(DbsWdbe* dbswdbe);
	bool evalTxfImbMmxActive(DbsWdbe* dbswdbe);
	bool evalTxfImbPriAvail(DbsWdbe* dbswdbe);
	bool evalTxfImbPriActive(DbsWdbe* dbswdbe);

public:
	PnlWdbeModDetail(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~PnlWdbeModDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFPupHkt;
	Sbecore::Feed feedFPupImbRty;
	Sbecore::Feed feedFPupTyp;
	Sbecore::Feed feedFPupVnd;

	WdbeMModule recMdl;
	Sbecore::uint ixWSubsetMdl;

	WdbeMController recCtr;

	WdbeMImbuf recImb;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshPupVnd(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshTxfVnd(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshVnd(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

	void refreshRecMdl(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshRecCtr(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshRecImb(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:

	void handleDpchAppWdbeInit(DbsWdbe* dbswdbe, DpchAppWdbeInit* dpchappwdbeinit, DpchEngWdbe** dpcheng);
	void handleDpchAppDataContiac(DbsWdbe* dbswdbe, ContIac* _contiac, DpchEngWdbe** dpcheng);

	void handleDpchAppDoButSaveClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButVndEditClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButHkuViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButSupViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButTplViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButCtrNewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButCtrDeleteClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButCtrFwdViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButCtrClrViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButImbNewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButImbDeleteClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

public:
	void handleCall(DbsWdbe* dbswdbe, Sbecore::Call* call);

private:
	bool handleCallWdbeKlsAkeyMod_klsEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv);
	bool handleCallWdbeMdlUpd_refEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);
	bool handleCallWdbeImbUpd_refEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);
	bool handleCallWdbeCtrUpd_refEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);
	bool handleCallWdbeMdl_typEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWdbeMdl_tplEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeMdl_supEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeMdl_sup_inSbs(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWdbeMdl_inSbs(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWdbeMdl_imbEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeMdl_hkuEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeMdl_hku_inSbs(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWdbeMdl_hktEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWdbeMdl_ctrEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeCtr_clrEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeCtr_mdl_inSbs(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWdbeCtr_fwdEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeCtr_fwd_inSbs(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);

};

#endif
