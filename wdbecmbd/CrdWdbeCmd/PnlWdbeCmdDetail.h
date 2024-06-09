/**
	* \file PnlWdbeCmdDetail.h
	* job handler for job PnlWdbeCmdDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

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
		static const Sbecore::uint BUTIVRVIEWCLICK = 3;
		static const Sbecore::uint BUTRVRVIEWCLICK = 4;
		static const Sbecore::uint BUTRERVIEWCLICK = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeCmdDetail)
	  */
	class ContIac : public Sbecore::Block {

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
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWdbeCmdDetail)
	  */
	class ContInf : public Sbecore::Block {

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
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWdbeCmdDetail)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrWdbeCmdDetail)
		*/
	class StatShr : public Sbecore::Block {

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
		static const Sbecore::uint BUTIVRVIEWAVAIL = 10;
		static const Sbecore::uint BUTIVRVIEWACTIVE = 11;
		static const Sbecore::uint TXTRVRACTIVE = 12;
		static const Sbecore::uint BUTRVRVIEWAVAIL = 13;
		static const Sbecore::uint BUTRVRVIEWACTIVE = 14;
		static const Sbecore::uint TXTRERACTIVE = 15;
		static const Sbecore::uint BUTRERVIEWAVAIL = 16;
		static const Sbecore::uint BUTRERVIEWACTIVE = 17;
		static const Sbecore::uint TXFCMTACTIVE = 18;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxfFsrActive = true, const bool TxtReuActive = true, const bool ButReuViewAvail = true, const bool ButReuViewActive = true, const bool PupRtyActive = true, const bool TxtIvrActive = true, const bool ButIvrViewAvail = true, const bool ButIvrViewActive = true, const bool TxtRvrActive = true, const bool ButRvrViewAvail = true, const bool ButRvrViewActive = true, const bool TxtRerActive = true, const bool ButRerViewAvail = true, const bool ButRerViewActive = true, const bool TxfCmtActive = true);

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
		bool ButIvrViewAvail;
		bool ButIvrViewActive;
		bool TxtRvrActive;
		bool ButRvrViewAvail;
		bool ButRvrViewActive;
		bool TxtRerActive;
		bool ButRerViewAvail;
		bool ButRerViewActive;
		bool TxfCmtActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWdbeCmdDetail)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
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

		void readJSON(const Json::Value& sup, bool addbasetag = false);
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

		void readJSON(const Json::Value& sup, bool addbasetag = false);
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
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Feed* feedFPupRet = NULL, Sbecore::Feed* feedFPupRty = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFPupRet;
		Sbecore::Feed feedFPupRty;
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
	bool evalTxfFsrActive(DbsWdbe* dbswdbe);
	bool evalTxtReuActive(DbsWdbe* dbswdbe);
	bool evalButReuViewAvail(DbsWdbe* dbswdbe);
	bool evalButReuViewActive(DbsWdbe* dbswdbe);
	bool evalPupRtyActive(DbsWdbe* dbswdbe);
	bool evalTxtIvrActive(DbsWdbe* dbswdbe);
	bool evalButIvrViewAvail(DbsWdbe* dbswdbe);
	bool evalButIvrViewActive(DbsWdbe* dbswdbe);
	bool evalTxtRvrActive(DbsWdbe* dbswdbe);
	bool evalButRvrViewAvail(DbsWdbe* dbswdbe);
	bool evalButRvrViewActive(DbsWdbe* dbswdbe);
	bool evalTxtRerActive(DbsWdbe* dbswdbe);
	bool evalButRerViewAvail(DbsWdbe* dbswdbe);
	bool evalButRerViewActive(DbsWdbe* dbswdbe);
	bool evalTxfCmtActive(DbsWdbe* dbswdbe);

public:
	PnlWdbeCmdDetail(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~PnlWdbeCmdDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFPupRet;
	Sbecore::Feed feedFPupRty;

	WdbeMCommand recCmd;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshRecCmd(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

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
	void handleDpchAppDoButIvrViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButRvrViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButRerViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

public:
	void handleCall(DbsWdbe* dbswdbe, Sbecore::Call* call);

private:
	bool handleCallWdbeCmdUpd_refEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);
	bool handleCallWdbeCmd_rvrEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeCmd_reuEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeCmd_reu_mdl_inSbs(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWdbeCmd_reu_inSbs(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWdbeCmd_retEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWdbeCmd_rerEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWdbeCmd_ivrEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif
