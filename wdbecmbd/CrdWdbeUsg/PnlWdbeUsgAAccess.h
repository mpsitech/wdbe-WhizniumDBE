/**
	* \file PnlWdbeUsgAAccess.h
	* job handler for job PnlWdbeUsgAAccess (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBEUSGAACCESS_H
#define PNLWDBEUSGAACCESS_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "QryWdbeUsgAAccess.h"

#define VecVWdbeUsgAAccessDo PnlWdbeUsgAAccess::VecVDo

#define ContInfWdbeUsgAAccess PnlWdbeUsgAAccess::ContInf
#define StatAppWdbeUsgAAccess PnlWdbeUsgAAccess::StatApp
#define StatShrWdbeUsgAAccess PnlWdbeUsgAAccess::StatShr
#define StgIacWdbeUsgAAccess PnlWdbeUsgAAccess::StgIac
#define TagWdbeUsgAAccess PnlWdbeUsgAAccess::Tag

#define DpchAppWdbeUsgAAccessData PnlWdbeUsgAAccess::DpchAppData
#define DpchAppWdbeUsgAAccessDo PnlWdbeUsgAAccess::DpchAppDo
#define DpchEngWdbeUsgAAccessData PnlWdbeUsgAAccess::DpchEngData

/**
	* PnlWdbeUsgAAccess
	*/
class PnlWdbeUsgAAccess : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVWdbeUsgAAccessDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTNEWCLICK = 1;
		static const Sbecore::uint BUTDUPLICATECLICK = 2;
		static const Sbecore::uint BUTDELETECLICK = 3;
		static const Sbecore::uint BUTREFRESHCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWdbeUsgAAccess)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFCSIQST = 1;

	public:
		ContInf(const Sbecore::uint numFCsiQst = 1);

	public:
		Sbecore::uint numFCsiQst;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWdbeUsgAAccess)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrWdbeUsgAAccess)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTNEWAVAIL = 1;
		static const Sbecore::uint BUTDUPLICATEAVAIL = 2;
		static const Sbecore::uint BUTDUPLICATEACTIVE = 3;
		static const Sbecore::uint BUTDELETEAVAIL = 4;
		static const Sbecore::uint BUTDELETEACTIVE = 5;

	public:
		StatShr(const bool ButNewAvail = true, const bool ButDuplicateAvail = true, const bool ButDuplicateActive = true, const bool ButDeleteAvail = true, const bool ButDeleteActive = true);

	public:
		bool ButNewAvail;
		bool ButDuplicateAvail;
		bool ButDuplicateActive;
		bool ButDeleteAvail;
		bool ButDeleteActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacWdbeUsgAAccess)
		*/
	class StgIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TCOFEGWIDTH = 1;
		static const Sbecore::uint TCOFEAWIDTH = 2;
		static const Sbecore::uint TCOACCWIDTH = 3;

	public:
		StgIac(const Sbecore::uint TcoFegWidth = 100, const Sbecore::uint TcoFeaWidth = 100, const Sbecore::uint TcoAccWidth = 100);

	public:
		Sbecore::uint TcoFegWidth;
		Sbecore::uint TcoFeaWidth;
		Sbecore::uint TcoAccWidth;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

	/**
		* Tag (full: TagWdbeUsgAAccess)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWdbeUsgAAccessData)
		*/
	class DpchAppData : public DpchAppWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint STGIAC = 2;
		static const Sbecore::uint STGIACQRY = 3;

	public:
		DpchAppData();

	public:
		StgIac stgiac;
		QryWdbeUsgAAccess::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWdbeUsgAAccessDo)
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
		* DpchEngData (full: DpchEngWdbeUsgAAccessData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint FEEDFCSIQST = 3;
		static const Sbecore::uint STATAPP = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint STGIAC = 6;
		static const Sbecore::uint TAG = 7;
		static const Sbecore::uint RST = 8;
		static const Sbecore::uint STATAPPQRY = 9;
		static const Sbecore::uint STATSHRQRY = 10;
		static const Sbecore::uint STGIACQRY = 11;
		static const Sbecore::uint ALL = 12;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContInf* continf = NULL, Sbecore::Feed* feedFCsiQst = NULL, StatShr* statshr = NULL, StgIac* stgiac = NULL, ListWdbeQUsgAAccess* rst = NULL, QryWdbeUsgAAccess::StatShr* statshrqry = NULL, QryWdbeUsgAAccess::StgIac* stgiacqry = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContInf continf;
		Sbecore::Feed feedFCsiQst;
		StatShr statshr;
		StgIac stgiac;
		ListWdbeQUsgAAccess rst;
		QryWdbeUsgAAccess::StatShr statshrqry;
		QryWdbeUsgAAccess::StgIac stgiacqry;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalButNewAvail(DbsWdbe* dbswdbe);
	bool evalButDuplicateAvail(DbsWdbe* dbswdbe);
	bool evalButDuplicateActive(DbsWdbe* dbswdbe);
	bool evalButDeleteAvail(DbsWdbe* dbswdbe);
	bool evalButDeleteActive(DbsWdbe* dbswdbe);

public:
	PnlWdbeUsgAAccess(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~PnlWdbeUsgAAccess();

public:
	ContInf continf;
	StatShr statshr;
	StgIac stgiac;

	Sbecore::Feed feedFCsiQst;

	QryWdbeUsgAAccess* qry;

	WdbeAMUsergroupAccess recUsgAacc;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:

	void handleDpchAppWdbeInit(DbsWdbe* dbswdbe, DpchAppWdbeInit* dpchappwdbeinit, DpchEngWdbe** dpcheng);
	void handleDpchAppDataStgiac(DbsWdbe* dbswdbe, StgIac* _stgiac, DpchEngWdbe** dpcheng);
	void handleDpchAppDataStgiacqry(DbsWdbe* dbswdbe, QryWdbeUsgAAccess::StgIac* _stgiacqry, DpchEngWdbe** dpcheng);

	void handleDpchAppDoButNewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButDuplicateClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButDeleteClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButRefreshClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

public:
	void handleCall(DbsWdbe* dbswdbe, Sbecore::Call* call);

private:
	bool handleCallWdbeStatChg(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);

};

#endif
