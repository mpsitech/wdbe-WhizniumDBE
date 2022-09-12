/**
	* \file DlgWdbePrjNew.h
	* job handler for job DlgWdbePrjNew (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef DLGWDBEPRJNEW_H
#define DLGWDBEPRJNEW_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWdbeLicense.h"

#define VecVDlgWdbePrjNewDo DlgWdbePrjNew::VecVDo
#define VecVDlgWdbePrjNewSge DlgWdbePrjNew::VecVSge

#define ContIacDlgWdbePrjNew DlgWdbePrjNew::ContIac
#define ContInfDlgWdbePrjNew DlgWdbePrjNew::ContInf
#define StatAppDlgWdbePrjNew DlgWdbePrjNew::StatApp
#define StatShrDlgWdbePrjNew DlgWdbePrjNew::StatShr
#define TagDlgWdbePrjNew DlgWdbePrjNew::Tag

#define DpchAppDlgWdbePrjNewData DlgWdbePrjNew::DpchAppData
#define DpchAppDlgWdbePrjNewDo DlgWdbePrjNew::DpchAppDo
#define DpchEngDlgWdbePrjNewData DlgWdbePrjNew::DpchEngData

/**
	* DlgWdbePrjNew
	*/
class DlgWdbePrjNew : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVDlgWdbePrjNewDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint DETBUTAUTCLICK = 1;
		static const Sbecore::uint BUTCNCCLICK = 2;
		static const Sbecore::uint BUTCRECLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWdbePrjNewSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRAER = 2;
		static const Sbecore::uint AUTH = 3;
		static const Sbecore::uint AUTDONE = 4;
		static const Sbecore::uint CREATE = 5;
		static const Sbecore::uint SYNC = 6;
		static const Sbecore::uint DONE = 7;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgWdbePrjNew)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint DETTXFSHO = 1;
		static const Sbecore::uint DETTXFTIT = 2;

	public:
		ContIac(const std::string& DetTxfSho = "", const std::string& DetTxfTit = "");

	public:
		std::string DetTxfSho;
		std::string DetTxfTit;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfDlgWdbePrjNew)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;

	public:
		ContInf(const Sbecore::uint numFSge = 1);

	public:
		Sbecore::uint numFSge;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppDlgWdbePrjNew)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const std::string& shortMenu = "");
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const std::string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgWdbePrjNew)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint DETBUTAUTACTIVE = 1;
		static const Sbecore::uint BUTCNCACTIVE = 2;
		static const Sbecore::uint BUTCREACTIVE = 3;

	public:
		StatShr(const bool DetButAutActive = true, const bool ButCncActive = true, const bool ButCreActive = true);

	public:
		bool DetButAutActive;
		bool ButCncActive;
		bool ButCreActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagDlgWdbePrjNew)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgWdbePrjNewData)
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
		* DpchAppDo (full: DpchAppDlgWdbePrjNewDo)
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
		* DpchEngData (full: DpchEngDlgWdbePrjNewData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFSGE = 4;
		static const Sbecore::uint STATAPP = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint TAG = 7;
		static const Sbecore::uint ALL = 8;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Feed* feedFSge = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFSge;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalDetButAutActive(DbsWdbe* dbswdbe);
	bool evalButCncActive(DbsWdbe* dbswdbe);
	bool evalButCreActive(DbsWdbe* dbswdbe);

public:
	DlgWdbePrjNew(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~DlgWdbePrjNew();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFMcbAlert;
	Sbecore::Feed feedFSge;

	JobWdbeLicense* license;

	bool valid;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems, const bool unmute = false);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:

	void handleDpchAppWdbeInit(DbsWdbe* dbswdbe, DpchAppWdbeInit* dpchappwdbeinit, DpchEngWdbe** dpcheng);
	void handleDpchAppDataContiac(DbsWdbe* dbswdbe, ContIac* _contiac, DpchEngWdbe** dpcheng);

	void handleDpchAppDoDetButAutClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButCncClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButCreClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppWdbeAlert(DbsWdbe* dbswdbe, DpchAppWdbeAlert* dpchappwdbealert, DpchEngWdbe** dpcheng);

private:
	void changeStage(DbsWdbe* dbswdbe, Sbecore::uint _ixVSge, DpchEngWdbe** dpcheng = NULL);

public:
	std::string getSquawk(DbsWdbe* dbswdbe);

private:
	Sbecore::uint enterSgeIdle(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeIdle(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeAlraer(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeAlraer(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeAuth(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeAuth(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeAutdone(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeAutdone(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeCreate(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeCreate(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeSync(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeSync(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeDone(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeDone(DbsWdbe* dbswdbe);

};

#endif
