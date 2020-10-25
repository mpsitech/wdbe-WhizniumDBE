/**
	* \file PnlWdbeCmdDetail.h
	* job handler for job PnlWdbeCmdDetail (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef PNLWDBECMDDETAIL_H
#define PNLWDBECMDDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWdbeCmdDetailDo PnlWdbeCmdDetail::VecVDo

#define ContIacWdbeCmdDetail PnlWdbeCmdDetail::ContIac
#define ContInfWdbeCmdDetail PnlWdbeCmdDetail::ContInf
#define StatAppWdbeCmdDetail PnlWdbeCmdDetail::StatApp
#define StatShrWdbeCmdDetail PnlWdbeCmdDetail::StatShr
#define TagWdbeCmdDetail PnlWdbeCmdDetail::Tag

#define DpchAppWdbeCmdDetailData PnlWdbeCmdDetail::DpchAppData
#define DpchAppWdbeCmdDetailDo PnlWdbeCmdDetail::DpchAppDo
#define DpchEngWdbeCmdDetailData PnlWdbeCmdDetail::DpchEngData

/**
	* PnlWdbeCmdDetail
	*/
class PnlWdbeCmdDetail : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVWdbeCmdDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTREUVIEWCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeCmdDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFFSR = 1;
		static const Sbecore::uint NUMFPUPRET = 2;
		static const Sbecore::uint NUMFPUPRTY = 3;
		static const Sbecore::uint TXFCMT = 4;

	public:
		ContIac(const std::string& TxfFsr = "", const Sbecore::uint numFPupRet = 1, const Sbecore::uint numFPupRty = 1, const std::string& TxfCmt = "");

	public:
		std::string TxfFsr;
		Sbecore::uint numFPupRet;
		Sbecore::uint numFPupRty;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWdbeCmdDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTREU = 2;
		static const Sbecore::uint TXTIVR = 3;
		static const Sbecore::uint TXTRVR = 4;
		static const Sbecore::uint TXTRER = 5;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtReu = "", const std::string& TxtIvr = "", const std::string& TxtRvr = "", const std::string& TxtRer = "");

	public:
		std::string TxtSrf;
		std::string TxtReu;
		std::string TxtIvr;
		std::string TxtRvr;
		std::string TxtRer;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWdbeCmdDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrWdbeCmdDetail)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTSRFACTIVE = 3;
		static const Sbecore::uint TXFFSRACTIVE = 4;
		static const Sbecore::uint TXTREUACTIVE = 5;
		static const Sbecore::uint BUTREUVIEWAVAIL = 6;
		static const Sbecore::uint BUTREUVIEWACTIVE = 7;
		static const Sbecore::uint PUPRTYACTIVE = 8;
		static const Sbecore::uint TXTIVRACTIVE = 9;
		static const Sbecore::uint TXTRVRACTIVE = 10;
		static const Sbecore::uint TXTRERACTIVE = 11;
		static const Sbecore::uint TXFCMTACTIVE = 12;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxfFsrActive = true, const bool TxtReuActive = true, const bool ButReuViewAvail = true, const bool ButReuViewActive = true, const bool PupRtyActive = true, const bool TxtIvrActive = true, const bool TxtRvrActive = true, const bool TxtRerActive = true, const bool TxfCmtActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxfFsrActive;
		bool TxtReuActive;
		bool ButReuViewAvail;
		bool ButReuViewActive;
		bool PupRtyActive;
		bool TxtIvrActive;
		bool TxtRvrActive;
		bool TxtRerActive;
		bool TxfCmtActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWdbeCmdDetail)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWdbeCmdDetailData)
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
		* DpchAppDo (full: DpchAppWdbeCmdDetailDo)
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
		* DpchEngData (full: DpchEngWdbeCmdDetailData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPRET = 4;
		static const Sbecore::uint FEEDFPUPRTY = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;
		static const Sbecore::uint ALL = 9;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFPupRet = NULL, Sbecore::Xmlio::Feed* feedFPupRty = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFPupRet;
		Sbecore::Xmlio::Feed feedFPupRty;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsWdbe* dbswdbe);
	bool evalButSaveActive(DbsWdbe* dbswdbe);
	bool evalTxtSrfActive(DbsWdbe* dbswdbe);
	bool evalTxfFsrActive(DbsWdbe* dbswdbe);
	bool evalTxtReuActive(DbsWdbe* dbswdbe);
	bool evalButReuViewAvail(DbsWdbe* dbswdbe);
	bool evalButReuViewActive(DbsWdbe* dbswdbe);
	bool evalPupRtyActive(DbsWdbe* dbswdbe);
	bool evalTxtIvrActive(DbsWdbe* dbswdbe);
	bool evalTxtRvrActive(DbsWdbe* dbswdbe);
	bool evalTxtRerActive(DbsWdbe* dbswdbe);
	bool evalTxfCmtActive(DbsWdbe* dbswdbe);

public:
	PnlWdbeCmdDetail(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~PnlWdbeCmdDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFPupRet;
	Sbecore::Xmlio::Feed feedFPupRty;

	WdbeMCommand recCmd;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshRecCmd(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

	void updatePreset(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:

	void handleDpchAppWdbeInit(DbsWdbe* dbswdbe, DpchAppWdbeInit* dpchappwdbeinit, DpchEngWdbe** dpcheng);
	void handleDpchAppDataContiac(DbsWdbe* dbswdbe, ContIac* _contiac, DpchEngWdbe** dpcheng);

	void handleDpchAppDoButSaveClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButReuViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

public:
	void handleCall(DbsWdbe* dbswdbe, Sbecore::Call* call);

private:
	bool handleCallWdbeCmd_retEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWdbeCmd_reu_inSbs(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWdbeCmd_reu_mdl_inSbs(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWdbeCmd_reuEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeCmdUpd_refEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);

};

#endif

