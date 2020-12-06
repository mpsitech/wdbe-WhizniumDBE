/**
	* \file PnlWdbeSilDetail.h
	* job handler for job PnlWdbeSilDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBESILDETAIL_H
#define PNLWDBESILDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWdbeSilDetailDo PnlWdbeSilDetail::VecVDo

#define ContIacWdbeSilDetail PnlWdbeSilDetail::ContIac
#define ContInfWdbeSilDetail PnlWdbeSilDetail::ContInf
#define StatAppWdbeSilDetail PnlWdbeSilDetail::StatApp
#define StatShrWdbeSilDetail PnlWdbeSilDetail::StatShr
#define TagWdbeSilDetail PnlWdbeSilDetail::Tag

#define DpchAppWdbeSilDetailData PnlWdbeSilDetail::DpchAppData
#define DpchAppWdbeSilDetailDo PnlWdbeSilDetail::DpchAppDo
#define DpchEngWdbeSilDetailData PnlWdbeSilDetail::DpchEngData

/**
	* PnlWdbeSilDetail
	*/
class PnlWdbeSilDetail : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVWdbeSilDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTREUVIEWCLICK = 2;
		static const Sbecore::uint BUTSYSVIEWCLICK = 3;
		static const Sbecore::uint BUTMDLVIEWCLICK = 4;
		static const Sbecore::uint BUTPKGEDITCLICK = 5;
		static const Sbecore::uint BUTTCHEDITCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeSilDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFTIT = 1;
		static const Sbecore::uint TXFFSR = 2;
		static const Sbecore::uint NUMFPUPTYP = 3;
		static const Sbecore::uint NUMFPUPRET = 4;
		static const Sbecore::uint NUMFPUPPKG = 5;
		static const Sbecore::uint TXFPKG = 6;
		static const Sbecore::uint CHKESY = 7;
		static const Sbecore::uint NUMFPUPTCH = 8;
		static const Sbecore::uint TXFTCH = 9;
		static const Sbecore::uint TXFCMT = 10;

	public:
		ContIac(const std::string& TxfTit = "", const std::string& TxfFsr = "", const Sbecore::uint numFPupTyp = 1, const Sbecore::uint numFPupRet = 1, const Sbecore::uint numFPupPkg = 1, const std::string& TxfPkg = "", const bool ChkEsy = false, const Sbecore::uint numFPupTch = 1, const std::string& TxfTch = "", const std::string& TxfCmt = "");

	public:
		std::string TxfTit;
		std::string TxfFsr;
		Sbecore::uint numFPupTyp;
		Sbecore::uint numFPupRet;
		Sbecore::uint numFPupPkg;
		std::string TxfPkg;
		bool ChkEsy;
		Sbecore::uint numFPupTch;
		std::string TxfTch;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWdbeSilDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTREU = 2;
		static const Sbecore::uint TXTSYS = 3;
		static const Sbecore::uint TXTMDL = 4;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtReu = "", const std::string& TxtSys = "", const std::string& TxtMdl = "");

	public:
		std::string TxtSrf;
		std::string TxtReu;
		std::string TxtSys;
		std::string TxtMdl;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWdbeSilDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool PupPkgAlt = false, const bool PupTchAlt = false);
	};

	/**
		* StatShr (full: StatShrWdbeSilDetail)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFPKGVALID = 1;
		static const Sbecore::uint TXFTCHVALID = 2;
		static const Sbecore::uint BUTSAVEAVAIL = 3;
		static const Sbecore::uint BUTSAVEACTIVE = 4;
		static const Sbecore::uint TXTSRFACTIVE = 5;
		static const Sbecore::uint TXFTITACTIVE = 6;
		static const Sbecore::uint TXFFSRACTIVE = 7;
		static const Sbecore::uint PUPTYPACTIVE = 8;
		static const Sbecore::uint TXTREUACTIVE = 9;
		static const Sbecore::uint BUTREUVIEWAVAIL = 10;
		static const Sbecore::uint BUTREUVIEWACTIVE = 11;
		static const Sbecore::uint TXTSYSACTIVE = 12;
		static const Sbecore::uint BUTSYSVIEWAVAIL = 13;
		static const Sbecore::uint BUTSYSVIEWACTIVE = 14;
		static const Sbecore::uint TXTMDLACTIVE = 15;
		static const Sbecore::uint BUTMDLVIEWAVAIL = 16;
		static const Sbecore::uint BUTMDLVIEWACTIVE = 17;
		static const Sbecore::uint PUPPKGACTIVE = 18;
		static const Sbecore::uint BUTPKGEDITAVAIL = 19;
		static const Sbecore::uint CHKESYACTIVE = 20;
		static const Sbecore::uint PUPTCHACTIVE = 21;
		static const Sbecore::uint BUTTCHEDITAVAIL = 22;
		static const Sbecore::uint TXFCMTACTIVE = 23;

	public:
		StatShr(const bool TxfPkgValid = false, const bool TxfTchValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxfTitActive = true, const bool TxfFsrActive = true, const bool PupTypActive = true, const bool TxtReuActive = true, const bool ButReuViewAvail = true, const bool ButReuViewActive = true, const bool TxtSysActive = true, const bool ButSysViewAvail = true, const bool ButSysViewActive = true, const bool TxtMdlActive = true, const bool ButMdlViewAvail = true, const bool ButMdlViewActive = true, const bool PupPkgActive = true, const bool ButPkgEditAvail = true, const bool ChkEsyActive = true, const bool PupTchActive = true, const bool ButTchEditAvail = true, const bool TxfCmtActive = true);

	public:
		bool TxfPkgValid;
		bool TxfTchValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxfTitActive;
		bool TxfFsrActive;
		bool PupTypActive;
		bool TxtReuActive;
		bool ButReuViewAvail;
		bool ButReuViewActive;
		bool TxtSysActive;
		bool ButSysViewAvail;
		bool ButSysViewActive;
		bool TxtMdlActive;
		bool ButMdlViewAvail;
		bool ButMdlViewActive;
		bool PupPkgActive;
		bool ButPkgEditAvail;
		bool ChkEsyActive;
		bool PupTchActive;
		bool ButTchEditAvail;
		bool TxfCmtActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWdbeSilDetail)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWdbeSilDetailData)
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
		* DpchAppDo (full: DpchAppWdbeSilDetailDo)
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
		* DpchEngData (full: DpchEngWdbeSilDetailData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPPKG = 4;
		static const Sbecore::uint FEEDFPUPRET = 5;
		static const Sbecore::uint FEEDFPUPTCH = 6;
		static const Sbecore::uint FEEDFPUPTYP = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint TAG = 10;
		static const Sbecore::uint ALL = 11;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFPupPkg = NULL, Sbecore::Xmlio::Feed* feedFPupRet = NULL, Sbecore::Xmlio::Feed* feedFPupTch = NULL, Sbecore::Xmlio::Feed* feedFPupTyp = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFPupPkg;
		Sbecore::Xmlio::Feed feedFPupRet;
		Sbecore::Xmlio::Feed feedFPupTch;
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
	bool evalTxfTitActive(DbsWdbe* dbswdbe);
	bool evalTxfFsrActive(DbsWdbe* dbswdbe);
	bool evalPupTypActive(DbsWdbe* dbswdbe);
	bool evalTxtReuActive(DbsWdbe* dbswdbe);
	bool evalButReuViewAvail(DbsWdbe* dbswdbe);
	bool evalButReuViewActive(DbsWdbe* dbswdbe);
	bool evalTxtSysActive(DbsWdbe* dbswdbe);
	bool evalButSysViewAvail(DbsWdbe* dbswdbe);
	bool evalButSysViewActive(DbsWdbe* dbswdbe);
	bool evalTxtMdlActive(DbsWdbe* dbswdbe);
	bool evalButMdlViewAvail(DbsWdbe* dbswdbe);
	bool evalButMdlViewActive(DbsWdbe* dbswdbe);
	bool evalPupPkgActive(DbsWdbe* dbswdbe);
	bool evalButPkgEditAvail(DbsWdbe* dbswdbe);
	bool evalChkEsyActive(DbsWdbe* dbswdbe);
	bool evalPupTchActive(DbsWdbe* dbswdbe);
	bool evalButTchEditAvail(DbsWdbe* dbswdbe);
	bool evalTxfCmtActive(DbsWdbe* dbswdbe);

public:
	PnlWdbeSilDetail(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~PnlWdbeSilDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFPupPkg;
	Sbecore::Xmlio::Feed feedFPupRet;
	Sbecore::Xmlio::Feed feedFPupTch;
	Sbecore::Xmlio::Feed feedFPupTyp;

	WdbeMUnit recUnt;
	Sbecore::uint ixWSubsetUnt;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshPupPkg(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshTxfPkg(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshPkg(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshPupTch(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshTxfTch(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshTch(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

	void refreshRecUnt(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:

	void handleDpchAppWdbeInit(DbsWdbe* dbswdbe, DpchAppWdbeInit* dpchappwdbeinit, DpchEngWdbe** dpcheng);
	void handleDpchAppDataContiac(DbsWdbe* dbswdbe, ContIac* _contiac, DpchEngWdbe** dpcheng);

	void handleDpchAppDoButSaveClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButReuViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButSysViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButMdlViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButPkgEditClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButTchEditClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

public:
	void handleCall(DbsWdbe* dbswdbe, Sbecore::Call* call);

private:
	bool handleCallWdbeKlsAkeyMod_klsEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv);
	bool handleCallWdbeUntUpd_refEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);
	bool handleCallWdbeUnt_sysEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeUnt_silEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeUnt_reuEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeUnt_retEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWdbeUnt_mdlEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeUnt_inSbs(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);

};

#endif
