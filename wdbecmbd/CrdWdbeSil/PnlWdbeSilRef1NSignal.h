/**
	* \file PnlWdbeSilRef1NSignal.h
	* job handler for job PnlWdbeSilRef1NSignal (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Sep 2021
	*/
// IP header --- ABOVE

#ifndef PNLWDBESILREF1NSIGNAL_H
#define PNLWDBESILREF1NSIGNAL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "QryWdbeSilRef1NSignal.h"

#define VecVWdbeSilRef1NSignalDo PnlWdbeSilRef1NSignal::VecVDo

#define ContInfWdbeSilRef1NSignal PnlWdbeSilRef1NSignal::ContInf
#define StatAppWdbeSilRef1NSignal PnlWdbeSilRef1NSignal::StatApp
#define StatShrWdbeSilRef1NSignal PnlWdbeSilRef1NSignal::StatShr
#define StgIacWdbeSilRef1NSignal PnlWdbeSilRef1NSignal::StgIac
#define TagWdbeSilRef1NSignal PnlWdbeSilRef1NSignal::Tag

#define DpchAppWdbeSilRef1NSignalData PnlWdbeSilRef1NSignal::DpchAppData
#define DpchAppWdbeSilRef1NSignalDo PnlWdbeSilRef1NSignal::DpchAppDo
#define DpchEngWdbeSilRef1NSignalData PnlWdbeSilRef1NSignal::DpchEngData

/**
	* PnlWdbeSilRef1NSignal
	*/
class PnlWdbeSilRef1NSignal : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVWdbeSilRef1NSignalDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTUPCLICK = 1;
		static const Sbecore::uint BUTDOWNCLICK = 2;
		static const Sbecore::uint BUTVIEWCLICK = 3;
		static const Sbecore::uint BUTNEWCLICK = 4;
		static const Sbecore::uint BUTDELETECLICK = 5;
		static const Sbecore::uint BUTREFRESHCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWdbeSilRef1NSignal)
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
		* StatApp (full: StatAppWdbeSilRef1NSignal)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrWdbeSilRef1NSignal)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTUPAVAIL = 1;
		static const Sbecore::uint BUTUPACTIVE = 2;
		static const Sbecore::uint BUTDOWNAVAIL = 3;
		static const Sbecore::uint BUTDOWNACTIVE = 4;
		static const Sbecore::uint BUTVIEWAVAIL = 5;
		static const Sbecore::uint BUTVIEWACTIVE = 6;
		static const Sbecore::uint BUTNEWAVAIL = 7;
		static const Sbecore::uint BUTDELETEAVAIL = 8;
		static const Sbecore::uint BUTDELETEACTIVE = 9;

	public:
		StatShr(const bool ButUpAvail = true, const bool ButUpActive = true, const bool ButDownAvail = true, const bool ButDownActive = true, const bool ButViewAvail = true, const bool ButViewActive = true, const bool ButNewAvail = true, const bool ButDeleteAvail = true, const bool ButDeleteActive = true);

	public:
		bool ButUpAvail;
		bool ButUpActive;
		bool ButDownAvail;
		bool ButDownActive;
		bool ButViewAvail;
		bool ButViewActive;
		bool ButNewAvail;
		bool ButDeleteAvail;
		bool ButDeleteActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacWdbeSilRef1NSignal)
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
		* Tag (full: TagWdbeSilRef1NSignal)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWdbeSilRef1NSignalData)
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
		QryWdbeSilRef1NSignal::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWdbeSilRef1NSignalDo)
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
		* DpchEngData (full: DpchEngWdbeSilRef1NSignalData)
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
		DpchEngData(const Sbecore::ubigint jref = 0, ContInf* continf = NULL, Sbecore::Feed* feedFCsiQst = NULL, StatShr* statshr = NULL, StgIac* stgiac = NULL, ListWdbeQSilRef1NSignal* rst = NULL, QryWdbeSilRef1NSignal::StatShr* statshrqry = NULL, QryWdbeSilRef1NSignal::StgIac* stgiacqry = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContInf continf;
		Sbecore::Feed feedFCsiQst;
		StatShr statshr;
		StgIac stgiac;
		ListWdbeQSilRef1NSignal rst;
		QryWdbeSilRef1NSignal::StatShr statshrqry;
		QryWdbeSilRef1NSignal::StgIac stgiacqry;

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
	bool evalButViewAvail(DbsWdbe* dbswdbe);
	bool evalButViewActive(DbsWdbe* dbswdbe);
	bool evalButNewAvail(DbsWdbe* dbswdbe);
	bool evalButDeleteAvail(DbsWdbe* dbswdbe);
	bool evalButDeleteActive(DbsWdbe* dbswdbe);

public:
	PnlWdbeSilRef1NSignal(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~PnlWdbeSilRef1NSignal();

public:
	ContInf continf;
	StatShr statshr;
	StgIac stgiac;

	Sbecore::Feed feedFCsiQst;

	QryWdbeSilRef1NSignal* qry;

	WdbeMSignal recSig;

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
	void handleDpchAppDataStgiacqry(DbsWdbe* dbswdbe, QryWdbeSilRef1NSignal::StgIac* _stgiacqry, DpchEngWdbe** dpcheng);

	void handleDpchAppDoButUpClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButDownClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButNewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButDeleteClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButRefreshClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

public:
	void handleCall(DbsWdbe* dbswdbe, Sbecore::Call* call);

private:
	bool handleCallWdbeStatChg(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);

};

#endif
