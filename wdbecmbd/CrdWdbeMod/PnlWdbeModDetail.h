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
		static const Sbecore::uint BUTHKUVIEWCLICK = 2;
		static const Sbecore::uint BUTSUPVIEWCLICK = 3;
		static const Sbecore::uint BUTTPLVIEWCLICK = 4;
		static const Sbecore::uint BUTCTRNEWCLICK = 5;
		static const Sbecore::uint BUTCTRDELETECLICK = 6;
		static const Sbecore::uint BUTCTRFWDVIEWCLICK = 7;
		static const Sbecore::uint BUTCTRCLRVIEWCLICK = 8;
		static const Sbecore::uint BUTIMBNEWCLICK = 9;
		static const Sbecore::uint BUTIMBDELETECLICK = 10;
		static const Sbecore::uint BUTIMBCORVIEWCLICK = 11;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeModDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFPUPTYP = 1;
		static const Sbecore::uint NUMFPUPHKT = 2;
		static const Sbecore::uint TXFSRR = 3;
		static const Sbecore::uint TXFCMT = 4;
		static const Sbecore::uint TXFCTRFSR = 5;
		static const Sbecore::uint NUMFPUPIMBDIR = 6;
		static const Sbecore::uint TXFIMBPRI = 7;

	public:
		ContIac(const Sbecore::uint numFPupTyp = 1, const Sbecore::uint numFPupHkt = 1, const std::string& TxfSrr = "", const std::string& TxfCmt = "", const std::string& TxfCtrFsr = "", const Sbecore::uint numFPupImbDir = 1, const std::string& TxfImbPri = "");

	public:
		Sbecore::uint numFPupTyp;
		Sbecore::uint numFPupHkt;
		std::string TxfSrr;
		std::string TxfCmt;
		std::string TxfCtrFsr;
		Sbecore::uint numFPupImbDir;
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
		static const Sbecore::uint TXTIMBSRF = 7;
		static const Sbecore::uint TXTIMBCOR = 8;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtHku = "", const std::string& TxtSup = "", const std::string& TxtTpl = "", const std::string& TxtCtrFwd = "", const std::string& TxtCtrClr = "", const std::string& TxtImbSrf = "", const std::string& TxtImbCor = "");

	public:
		std::string TxtSrf;
		std::string TxtHku;
		std::string TxtSup;
		std::string TxtTpl;
		std::string TxtCtrFwd;
		std::string TxtCtrClr;
		std::string TxtImbSrf;
		std::string TxtImbCor;

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
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrWdbeModDetail)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTSRFACTIVE = 3;
		static const Sbecore::uint PUPTYPACTIVE = 4;
		static const Sbecore::uint TXTHKUACTIVE = 5;
		static const Sbecore::uint BUTHKUVIEWAVAIL = 6;
		static const Sbecore::uint BUTHKUVIEWACTIVE = 7;
		static const Sbecore::uint TXTSUPACTIVE = 8;
		static const Sbecore::uint BUTSUPVIEWAVAIL = 9;
		static const Sbecore::uint BUTSUPVIEWACTIVE = 10;
		static const Sbecore::uint TXTTPLACTIVE = 11;
		static const Sbecore::uint BUTTPLVIEWAVAIL = 12;
		static const Sbecore::uint BUTTPLVIEWACTIVE = 13;
		static const Sbecore::uint TXFSRRACTIVE = 14;
		static const Sbecore::uint TXFCMTACTIVE = 15;
		static const Sbecore::uint SEPCTRAVAIL = 16;
		static const Sbecore::uint HDGCTRAVAIL = 17;
		static const Sbecore::uint BUTCTRNEWAVAIL = 18;
		static const Sbecore::uint BUTCTRDELETEAVAIL = 19;
		static const Sbecore::uint TXFCTRFSRAVAIL = 20;
		static const Sbecore::uint TXFCTRFSRACTIVE = 21;
		static const Sbecore::uint TXTCTRFWDAVAIL = 22;
		static const Sbecore::uint TXTCTRFWDACTIVE = 23;
		static const Sbecore::uint BUTCTRFWDVIEWAVAIL = 24;
		static const Sbecore::uint BUTCTRFWDVIEWACTIVE = 25;
		static const Sbecore::uint TXTCTRCLRAVAIL = 26;
		static const Sbecore::uint TXTCTRCLRACTIVE = 27;
		static const Sbecore::uint BUTCTRCLRVIEWAVAIL = 28;
		static const Sbecore::uint BUTCTRCLRVIEWACTIVE = 29;
		static const Sbecore::uint SEPIMBAVAIL = 30;
		static const Sbecore::uint HDGIMBAVAIL = 31;
		static const Sbecore::uint BUTIMBNEWAVAIL = 32;
		static const Sbecore::uint BUTIMBDELETEAVAIL = 33;
		static const Sbecore::uint TXTIMBSRFAVAIL = 34;
		static const Sbecore::uint TXTIMBSRFACTIVE = 35;
		static const Sbecore::uint TXTIMBCORAVAIL = 36;
		static const Sbecore::uint TXTIMBCORACTIVE = 37;
		static const Sbecore::uint BUTIMBCORVIEWAVAIL = 38;
		static const Sbecore::uint BUTIMBCORVIEWACTIVE = 39;
		static const Sbecore::uint PUPIMBDIRAVAIL = 40;
		static const Sbecore::uint PUPIMBDIRACTIVE = 41;
		static const Sbecore::uint TXFIMBPRIAVAIL = 42;
		static const Sbecore::uint TXFIMBPRIACTIVE = 43;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool PupTypActive = true, const bool TxtHkuActive = true, const bool ButHkuViewAvail = true, const bool ButHkuViewActive = true, const bool TxtSupActive = true, const bool ButSupViewAvail = true, const bool ButSupViewActive = true, const bool TxtTplActive = true, const bool ButTplViewAvail = true, const bool ButTplViewActive = true, const bool TxfSrrActive = true, const bool TxfCmtActive = true, const bool SepCtrAvail = true, const bool HdgCtrAvail = true, const bool ButCtrNewAvail = true, const bool ButCtrDeleteAvail = true, const bool TxfCtrFsrAvail = true, const bool TxfCtrFsrActive = true, const bool TxtCtrFwdAvail = true, const bool TxtCtrFwdActive = true, const bool ButCtrFwdViewAvail = true, const bool ButCtrFwdViewActive = true, const bool TxtCtrClrAvail = true, const bool TxtCtrClrActive = true, const bool ButCtrClrViewAvail = true, const bool ButCtrClrViewActive = true, const bool SepImbAvail = true, const bool HdgImbAvail = true, const bool ButImbNewAvail = true, const bool ButImbDeleteAvail = true, const bool TxtImbSrfAvail = true, const bool TxtImbSrfActive = true, const bool TxtImbCorAvail = true, const bool TxtImbCorActive = true, const bool ButImbCorViewAvail = true, const bool ButImbCorViewActive = true, const bool PupImbDirAvail = true, const bool PupImbDirActive = true, const bool TxfImbPriAvail = true, const bool TxfImbPriActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
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
		bool TxtImbSrfAvail;
		bool TxtImbSrfActive;
		bool TxtImbCorAvail;
		bool TxtImbCorActive;
		bool ButImbCorViewAvail;
		bool ButImbCorViewActive;
		bool PupImbDirAvail;
		bool PupImbDirActive;
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
		static const Sbecore::uint FEEDFPUPIMBDIR = 5;
		static const Sbecore::uint FEEDFPUPTYP = 6;
		static const Sbecore::uint STATAPP = 7;
		static const Sbecore::uint STATSHR = 8;
		static const Sbecore::uint TAG = 9;
		static const Sbecore::uint ALL = 10;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Feed* feedFPupHkt = NULL, Sbecore::Feed* feedFPupImbDir = NULL, Sbecore::Feed* feedFPupTyp = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFPupHkt;
		Sbecore::Feed feedFPupImbDir;
		Sbecore::Feed feedFPupTyp;
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
	bool evalTxtImbSrfAvail(DbsWdbe* dbswdbe);
	bool evalTxtImbSrfActive(DbsWdbe* dbswdbe);
	bool evalTxtImbCorAvail(DbsWdbe* dbswdbe);
	bool evalTxtImbCorActive(DbsWdbe* dbswdbe);
	bool evalButImbCorViewAvail(DbsWdbe* dbswdbe);
	bool evalButImbCorViewActive(DbsWdbe* dbswdbe);
	bool evalPupImbDirAvail(DbsWdbe* dbswdbe);
	bool evalPupImbDirActive(DbsWdbe* dbswdbe);
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
	Sbecore::Feed feedFPupImbDir;
	Sbecore::Feed feedFPupTyp;

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
	void handleDpchAppDoButHkuViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButSupViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButTplViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButCtrNewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButCtrDeleteClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButCtrFwdViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButCtrClrViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButImbNewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButImbDeleteClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButImbCorViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

public:
	void handleCall(DbsWdbe* dbswdbe, Sbecore::Call* call);

private:
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
	bool handleCallWdbeImb_mdl_inSbs(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWdbeImb_corEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeCtr_mdl_inSbs(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWdbeCtr_fwdEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeCtr_fwd_inSbs(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWdbeCtr_clrEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif
