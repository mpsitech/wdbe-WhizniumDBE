/**
	* \file DlgWdbeVerNew.h
	* job handler for job DlgWdbeVerNew (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef DLGWDBEVERNEW_H
#define DLGWDBEVERNEW_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWdbeIexPrj.h"

#define VecVDlgWdbeVerNewDo DlgWdbeVerNew::VecVDo
#define VecVDlgWdbeVerNewSge DlgWdbeVerNew::VecVSge
#define VecVDlgWdbeVerNewVni DlgWdbeVerNew::VecVVni

#define ContIacDlgWdbeVerNew DlgWdbeVerNew::ContIac
#define ContInfDlgWdbeVerNew DlgWdbeVerNew::ContInf
#define StatAppDlgWdbeVerNew DlgWdbeVerNew::StatApp
#define StatShrDlgWdbeVerNew DlgWdbeVerNew::StatShr
#define TagDlgWdbeVerNew DlgWdbeVerNew::Tag

#define DpchAppDlgWdbeVerNewData DlgWdbeVerNew::DpchAppData
#define DpchAppDlgWdbeVerNewDo DlgWdbeVerNew::DpchAppDo
#define DpchEngDlgWdbeVerNewData DlgWdbeVerNew::DpchEngData

/**
	* DlgWdbeVerNew
	*/
class DlgWdbeVerNew : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVDlgWdbeVerNewDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTCNCCLICK = 1;
		static const Sbecore::uint BUTCRECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWdbeVerNewSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint CREATE = 2;
		static const Sbecore::uint DONE = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
		* VecVVni (full: VecVDlgWdbeVerNewVni)
		*/
	class VecVVni {

	public:
		static const Sbecore::uint MAJ = 1;
		static const Sbecore::uint MIN = 2;
		static const Sbecore::uint SUB = 3;
		static const Sbecore::uint VOID = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgWdbeVerNew)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFDETPUPPRJ = 1;
		static const Sbecore::uint NUMFDETPUPBVR = 2;
		static const Sbecore::uint NUMFDETRBUVNI = 3;
		static const Sbecore::uint DETTXFCMT = 4;

	public:
		ContIac(const Sbecore::uint numFDetPupPrj = 1, const Sbecore::uint numFDetPupBvr = 1, const Sbecore::uint numFDetRbuVni = 1, const std::string& DetTxfCmt = "");

	public:
		Sbecore::uint numFDetPupPrj;
		Sbecore::uint numFDetPupBvr;
		Sbecore::uint numFDetRbuVni;
		std::string DetTxfCmt;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfDlgWdbeVerNew)
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
		* StatApp (full: StatAppDlgWdbeVerNew)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const std::string& shortMenu = "");
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const std::string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgWdbeVerNew)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTCREACTIVE = 1;

	public:
		StatShr(const bool ButCreActive = true);

	public:
		bool ButCreActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagDlgWdbeVerNew)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgWdbeVerNewData)
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
		* DpchAppDo (full: DpchAppDlgWdbeVerNewDo)
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
		* DpchEngData (full: DpchEngDlgWdbeVerNewData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFDETPUPBVR = 4;
		static const Sbecore::uint FEEDFDETPUPPRJ = 5;
		static const Sbecore::uint FEEDFDETRBUVNI = 6;
		static const Sbecore::uint FEEDFSGE = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint TAG = 10;
		static const Sbecore::uint ALL = 11;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Feed* feedFDetPupBvr = NULL, Sbecore::Feed* feedFDetPupPrj = NULL, Sbecore::Feed* feedFDetRbuVni = NULL, Sbecore::Feed* feedFSge = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFDetPupBvr;
		Sbecore::Feed feedFDetPupPrj;
		Sbecore::Feed feedFDetRbuVni;
		Sbecore::Feed feedFSge;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalButCreActive(DbsWdbe* dbswdbe);

public:
	DlgWdbeVerNew(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~DlgWdbeVerNew();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFDetPupBvr;
	Sbecore::Feed feedFDetPupPrj;
	Sbecore::Feed feedFDetRbuVni;
	Sbecore::Feed feedFSge;

	JobWdbeIexPrj* iexprj;

	bool valid;

	// IP vars.cust --- INSERT

public:
	// IP cust --- IBEGIN
	void refreshDetBvr(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	// IP cust --- IEND

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems, const bool unmute = false);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:

	void handleDpchAppWdbeInit(DbsWdbe* dbswdbe, DpchAppWdbeInit* dpchappwdbeinit, DpchEngWdbe** dpcheng);
	void handleDpchAppDataContiac(DbsWdbe* dbswdbe, ContIac* _contiac, DpchEngWdbe** dpcheng);

	void handleDpchAppDoButCncClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButCreClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

private:
	void changeStage(DbsWdbe* dbswdbe, Sbecore::uint _ixVSge, DpchEngWdbe** dpcheng = NULL);

public:
	std::string getSquawk(DbsWdbe* dbswdbe);

private:
	Sbecore::uint enterSgeIdle(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeIdle(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeCreate(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeCreate(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeDone(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeDone(DbsWdbe* dbswdbe);

};

#endif
