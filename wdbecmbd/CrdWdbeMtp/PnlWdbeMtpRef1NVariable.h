/**
	* \file PnlWdbeMtpRef1NVariable.h
	* job handler for job PnlWdbeMtpRef1NVariable (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

#ifndef PNLWDBEMTPREF1NVARIABLE_H
#define PNLWDBEMTPREF1NVARIABLE_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "QryWdbeMtpRef1NVariable.h"

#define VecVWdbeMtpRef1NVariableDo PnlWdbeMtpRef1NVariable::VecVDo

#define ContInfWdbeMtpRef1NVariable PnlWdbeMtpRef1NVariable::ContInf
#define StatAppWdbeMtpRef1NVariable PnlWdbeMtpRef1NVariable::StatApp
#define StatShrWdbeMtpRef1NVariable PnlWdbeMtpRef1NVariable::StatShr
#define StgIacWdbeMtpRef1NVariable PnlWdbeMtpRef1NVariable::StgIac
#define TagWdbeMtpRef1NVariable PnlWdbeMtpRef1NVariable::Tag

#define DpchAppWdbeMtpRef1NVariableData PnlWdbeMtpRef1NVariable::DpchAppData
#define DpchAppWdbeMtpRef1NVariableDo PnlWdbeMtpRef1NVariable::DpchAppDo
#define DpchEngWdbeMtpRef1NVariableData PnlWdbeMtpRef1NVariable::DpchEngData

/**
	* PnlWdbeMtpRef1NVariable
	*/
class PnlWdbeMtpRef1NVariable : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVWdbeMtpRef1NVariableDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTUPCLICK = 1;
		static const Sbecore::uint BUTDOWNCLICK = 2;
		static const Sbecore::uint BUTDELETECLICK = 3;
		static const Sbecore::uint BUTREFRESHCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWdbeMtpRef1NVariable)
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
		* StatApp (full: StatAppWdbeMtpRef1NVariable)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrWdbeMtpRef1NVariable)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTUPAVAIL = 1;
		static const Sbecore::uint BUTUPACTIVE = 2;
		static const Sbecore::uint BUTDOWNAVAIL = 3;
		static const Sbecore::uint BUTDOWNACTIVE = 4;
		static const Sbecore::uint BUTDELETEAVAIL = 5;
		static const Sbecore::uint BUTDELETEACTIVE = 6;

	public:
		StatShr(const bool ButUpAvail = true, const bool ButUpActive = true, const bool ButDownAvail = true, const bool ButDownActive = true, const bool ButDeleteAvail = true, const bool ButDeleteActive = true);

	public:
		bool ButUpAvail;
		bool ButUpActive;
		bool ButDownAvail;
		bool ButDownActive;
		bool ButDeleteAvail;
		bool ButDeleteActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacWdbeMtpRef1NVariable)
		*/
	class StgIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TCOREFWIDTH = 1;

	public:
		StgIac(const Sbecore::uint TcoRefWidth = 100);

	public:
		Sbecore::uint TcoRefWidth;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

	/**
		* Tag (full: TagWdbeMtpRef1NVariable)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWdbeMtpRef1NVariableData)
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
		QryWdbeMtpRef1NVariable::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWdbeMtpRef1NVariableDo)
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
		* DpchEngData (full: DpchEngWdbeMtpRef1NVariableData)
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
		DpchEngData(const Sbecore::ubigint jref = 0, ContInf* continf = NULL, Sbecore::Feed* feedFCsiQst = NULL, StatShr* statshr = NULL, StgIac* stgiac = NULL, ListWdbeQMtpRef1NVariable* rst = NULL, QryWdbeMtpRef1NVariable::StatShr* statshrqry = NULL, QryWdbeMtpRef1NVariable::StgIac* stgiacqry = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContInf continf;
		Sbecore::Feed feedFCsiQst;
		StatShr statshr;
		StgIac stgiac;
		ListWdbeQMtpRef1NVariable rst;
		QryWdbeMtpRef1NVariable::StatShr statshrqry;
		QryWdbeMtpRef1NVariable::StgIac stgiacqry;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalButUpAvail(DbsWdbe* dbswdbe);
	bool evalButUpActive(DbsWdbe* dbswdbe);
	bool evalButDownAvail(DbsWdbe* dbswdbe);
	bool evalButDownActive(DbsWdbe* dbswdbe);
	bool evalButDeleteAvail(DbsWdbe* dbswdbe);
	bool evalButDeleteActive(DbsWdbe* dbswdbe);

public:
	PnlWdbeMtpRef1NVariable(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~PnlWdbeMtpRef1NVariable();

public:
	ContInf continf;
	StatShr statshr;
	StgIac stgiac;

	Sbecore::Feed feedFCsiQst;

	QryWdbeMtpRef1NVariable* qry;

	WdbeMVariable recVar;

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
	void handleDpchAppDataStgiacqry(DbsWdbe* dbswdbe, QryWdbeMtpRef1NVariable::StgIac* _stgiacqry, DpchEngWdbe** dpcheng);

	void handleDpchAppDoButUpClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButDownClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButDeleteClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButRefreshClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

public:
	void handleCall(DbsWdbe* dbswdbe, Sbecore::Call* call);

private:
	bool handleCallWdbeStatChg(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);

};

#endif
