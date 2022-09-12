/**
	* \file PnlWdbeMtpKHdltype.h
	* job handler for job PnlWdbeMtpKHdltype (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBEMTPKHDLTYPE_H
#define PNLWDBEMTPKHDLTYPE_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "QryWdbeMtpKHdltype.h"

#define VecVWdbeMtpKHdltypeDo PnlWdbeMtpKHdltype::VecVDo

#define ContInfWdbeMtpKHdltype PnlWdbeMtpKHdltype::ContInf
#define StatAppWdbeMtpKHdltype PnlWdbeMtpKHdltype::StatApp
#define StatShrWdbeMtpKHdltype PnlWdbeMtpKHdltype::StatShr
#define StgIacWdbeMtpKHdltype PnlWdbeMtpKHdltype::StgIac
#define TagWdbeMtpKHdltype PnlWdbeMtpKHdltype::Tag

#define DpchAppWdbeMtpKHdltypeData PnlWdbeMtpKHdltype::DpchAppData
#define DpchAppWdbeMtpKHdltypeDo PnlWdbeMtpKHdltype::DpchAppDo
#define DpchEngWdbeMtpKHdltypeData PnlWdbeMtpKHdltype::DpchEngData

/**
	* PnlWdbeMtpKHdltype
	*/
class PnlWdbeMtpKHdltype : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVWdbeMtpKHdltypeDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTUPCLICK = 1;
		static const Sbecore::uint BUTDOWNCLICK = 2;
		static const Sbecore::uint BUTNEWCLICK = 3;
		static const Sbecore::uint BUTDUPLICATECLICK = 4;
		static const Sbecore::uint BUTDELETECLICK = 5;
		static const Sbecore::uint BUTREFRESHCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWdbeMtpKHdltype)
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
		* StatApp (full: StatAppWdbeMtpKHdltype)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrWdbeMtpKHdltype)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTUPACTIVE = 1;
		static const Sbecore::uint BUTDOWNACTIVE = 2;
		static const Sbecore::uint BUTDUPLICATEACTIVE = 3;
		static const Sbecore::uint BUTDELETEACTIVE = 4;

	public:
		StatShr(const bool ButUpActive = true, const bool ButDownActive = true, const bool ButDuplicateActive = true, const bool ButDeleteActive = true);

	public:
		bool ButUpActive;
		bool ButDownActive;
		bool ButDuplicateActive;
		bool ButDeleteActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacWdbeMtpKHdltype)
		*/
	class StgIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TCOFIXWIDTH = 1;
		static const Sbecore::uint TCOSRFWIDTH = 2;
		static const Sbecore::uint TCOAVLWIDTH = 3;
		static const Sbecore::uint TCOIMPWIDTH = 4;
		static const Sbecore::uint TCOTITWIDTH = 5;
		static const Sbecore::uint TCOCMTWIDTH = 6;

	public:
		StgIac(const Sbecore::uint TcoFixWidth = 100, const Sbecore::uint TcoSrfWidth = 100, const Sbecore::uint TcoAvlWidth = 100, const Sbecore::uint TcoImpWidth = 100, const Sbecore::uint TcoTitWidth = 100, const Sbecore::uint TcoCmtWidth = 100);

	public:
		Sbecore::uint TcoFixWidth;
		Sbecore::uint TcoSrfWidth;
		Sbecore::uint TcoAvlWidth;
		Sbecore::uint TcoImpWidth;
		Sbecore::uint TcoTitWidth;
		Sbecore::uint TcoCmtWidth;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

	/**
		* Tag (full: TagWdbeMtpKHdltype)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWdbeMtpKHdltypeData)
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
		QryWdbeMtpKHdltype::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWdbeMtpKHdltypeDo)
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
		* DpchEngData (full: DpchEngWdbeMtpKHdltypeData)
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
		DpchEngData(const Sbecore::ubigint jref = 0, ContInf* continf = NULL, Sbecore::Feed* feedFCsiQst = NULL, StatShr* statshr = NULL, StgIac* stgiac = NULL, ListWdbeQMtpKHdltype* rst = NULL, QryWdbeMtpKHdltype::StatShr* statshrqry = NULL, QryWdbeMtpKHdltype::StgIac* stgiacqry = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContInf continf;
		Sbecore::Feed feedFCsiQst;
		StatShr statshr;
		StgIac stgiac;
		ListWdbeQMtpKHdltype rst;
		QryWdbeMtpKHdltype::StatShr statshrqry;
		QryWdbeMtpKHdltype::StgIac stgiacqry;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalButUpActive(DbsWdbe* dbswdbe);
	bool evalButDownActive(DbsWdbe* dbswdbe);
	bool evalButDuplicateActive(DbsWdbe* dbswdbe);
	bool evalButDeleteActive(DbsWdbe* dbswdbe);

public:
	PnlWdbeMtpKHdltype(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~PnlWdbeMtpKHdltype();

public:
	ContInf continf;
	StatShr statshr;
	StgIac stgiac;

	Sbecore::Feed feedFCsiQst;

	QryWdbeMtpKHdltype* qry;

	WdbeAVKeylistKey recKlsAkey;

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
	void handleDpchAppDataStgiacqry(DbsWdbe* dbswdbe, QryWdbeMtpKHdltype::StgIac* _stgiacqry, DpchEngWdbe** dpcheng);

	void handleDpchAppDoButUpClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButDownClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
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
