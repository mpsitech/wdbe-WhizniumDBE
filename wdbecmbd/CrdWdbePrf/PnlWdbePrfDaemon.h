/**
	* \file PnlWdbePrfDaemon.h
	* job handler for job PnlWdbePrfDaemon (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 8 Jan 2025
	*/
// IP header --- ABOVE

#ifndef PNLWDBEPRFDAEMON_H
#define PNLWDBEPRFDAEMON_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWdbePrfDaemonDo PnlWdbePrfDaemon::VecVDo

#define ContIacWdbePrfDaemon PnlWdbePrfDaemon::ContIac
#define StatShrWdbePrfDaemon PnlWdbePrfDaemon::StatShr
#define TagWdbePrfDaemon PnlWdbePrfDaemon::Tag

#define DpchAppWdbePrfDaemonData PnlWdbePrfDaemon::DpchAppData
#define DpchAppWdbePrfDaemonDo PnlWdbePrfDaemon::DpchAppDo
#define DpchEngWdbePrfDaemonData PnlWdbePrfDaemon::DpchEngData

/**
	* PnlWdbePrfDaemon
	*/
class PnlWdbePrfDaemon : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVWdbePrfDaemonDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTREGULARIZECLICK = 1;
		static const Sbecore::uint BUTMINIMIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbePrfDaemon)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TXF2 = 1;
		static const Sbecore::uint CHK3 = 2;
		static const Sbecore::uint TXF4 = 3;
		static const Sbecore::uint TXF5 = 4;
		static const Sbecore::uint TXF6 = 5;
		static const Sbecore::uint TXF102 = 6;
		static const Sbecore::uint CHK103 = 7;
		static const Sbecore::uint TXF104 = 8;
		static const Sbecore::uint TXF202 = 9;
		static const Sbecore::uint TXF203 = 10;
		static const Sbecore::uint CHK204 = 11;
		static const Sbecore::uint TXF302 = 12;
		static const Sbecore::uint TXF303 = 13;
		static const Sbecore::uint CHK304 = 14;
		static const Sbecore::uint NUMFPUP402 = 15;
		static const Sbecore::uint TXF403 = 16;
		static const Sbecore::uint TXF404 = 17;
		static const Sbecore::uint TXF405 = 18;
		static const Sbecore::uint TXF406 = 19;
		static const Sbecore::uint TXF407 = 20;
		static const Sbecore::uint TXF408 = 21;
		static const Sbecore::uint TXF502 = 22;
		static const Sbecore::uint TXF503 = 23;
		static const Sbecore::uint TXF504 = 24;
		static const Sbecore::uint TXF505 = 25;
		static const Sbecore::uint TXF506 = 26;
		static const Sbecore::uint TXF507 = 27;
		static const Sbecore::uint TXF602 = 28;
		static const Sbecore::uint TXF603 = 29;
		static const Sbecore::uint TXF702 = 30;
		static const Sbecore::uint TXF703 = 31;
		static const Sbecore::uint TXF704 = 32;
		static const Sbecore::uint TXF705 = 33;
		static const Sbecore::uint NUMFPUP706 = 34;
		static const Sbecore::uint TXF707 = 35;
		static const Sbecore::uint TXF708 = 36;
		static const Sbecore::uint TXF709 = 37;
		static const Sbecore::uint TXF710 = 38;

	public:
		ContIac(const std::string& Txf2 = "", const bool Chk3 = false, const std::string& Txf4 = "", const std::string& Txf5 = "", const std::string& Txf6 = "", const std::string& Txf102 = "", const bool Chk103 = false, const std::string& Txf104 = "", const std::string& Txf202 = "", const std::string& Txf203 = "", const bool Chk204 = false, const std::string& Txf302 = "", const std::string& Txf303 = "", const bool Chk304 = false, const Sbecore::uint numFPup402 = 1, const std::string& Txf403 = "", const std::string& Txf404 = "", const std::string& Txf405 = "", const std::string& Txf406 = "", const std::string& Txf407 = "", const std::string& Txf408 = "", const std::string& Txf502 = "", const std::string& Txf503 = "", const std::string& Txf504 = "", const std::string& Txf505 = "", const std::string& Txf506 = "", const std::string& Txf507 = "", const std::string& Txf602 = "", const std::string& Txf603 = "", const std::string& Txf702 = "", const std::string& Txf703 = "", const std::string& Txf704 = "", const std::string& Txf705 = "", const Sbecore::uint numFPup706 = 1, const std::string& Txf707 = "", const std::string& Txf708 = "", const std::string& Txf709 = "", const std::string& Txf710 = "");

	public:
		std::string Txf2;
		bool Chk3;
		std::string Txf4;
		std::string Txf5;
		std::string Txf6;
		std::string Txf102;
		bool Chk103;
		std::string Txf104;
		std::string Txf202;
		std::string Txf203;
		bool Chk204;
		std::string Txf302;
		std::string Txf303;
		bool Chk304;
		Sbecore::uint numFPup402;
		std::string Txf403;
		std::string Txf404;
		std::string Txf405;
		std::string Txf406;
		std::string Txf407;
		std::string Txf408;
		std::string Txf502;
		std::string Txf503;
		std::string Txf504;
		std::string Txf505;
		std::string Txf506;
		std::string Txf507;
		std::string Txf602;
		std::string Txf603;
		std::string Txf702;
		std::string Txf703;
		std::string Txf704;
		std::string Txf705;
		Sbecore::uint numFPup706;
		std::string Txf707;
		std::string Txf708;
		std::string Txf709;
		std::string Txf710;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
		* StatShr (full: StatShrWdbePrfDaemon)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint TXF2CLEAN = 2;
		static const Sbecore::uint CHK3CLEAN = 3;
		static const Sbecore::uint TXF4CLEAN = 4;
		static const Sbecore::uint TXF5CLEAN = 5;
		static const Sbecore::uint TXF6CLEAN = 6;
		static const Sbecore::uint TXF102CLEAN = 7;
		static const Sbecore::uint CHK103CLEAN = 8;
		static const Sbecore::uint TXF104CLEAN = 9;
		static const Sbecore::uint SEP2AVAIL = 10;
		static const Sbecore::uint HDG201AVAIL = 11;
		static const Sbecore::uint TXF202AVAIL = 12;
		static const Sbecore::uint TXF202CLEAN = 13;
		static const Sbecore::uint TXF203AVAIL = 14;
		static const Sbecore::uint TXF203CLEAN = 15;
		static const Sbecore::uint CHK204AVAIL = 16;
		static const Sbecore::uint CHK204CLEAN = 17;
		static const Sbecore::uint SEP3AVAIL = 18;
		static const Sbecore::uint HDG301AVAIL = 19;
		static const Sbecore::uint TXF302AVAIL = 20;
		static const Sbecore::uint TXF302CLEAN = 21;
		static const Sbecore::uint TXF303AVAIL = 22;
		static const Sbecore::uint TXF303CLEAN = 23;
		static const Sbecore::uint CHK304AVAIL = 24;
		static const Sbecore::uint CHK304CLEAN = 25;
		static const Sbecore::uint PUP402CLEAN = 26;
		static const Sbecore::uint TXF403CLEAN = 27;
		static const Sbecore::uint TXF404CLEAN = 28;
		static const Sbecore::uint TXF405CLEAN = 29;
		static const Sbecore::uint TXF406CLEAN = 30;
		static const Sbecore::uint TXF407CLEAN = 31;
		static const Sbecore::uint TXF408CLEAN = 32;
		static const Sbecore::uint TXF502CLEAN = 33;
		static const Sbecore::uint TXF503CLEAN = 34;
		static const Sbecore::uint TXF504CLEAN = 35;
		static const Sbecore::uint TXF505CLEAN = 36;
		static const Sbecore::uint TXF506CLEAN = 37;
		static const Sbecore::uint TXF507CLEAN = 38;
		static const Sbecore::uint TXF602CLEAN = 39;
		static const Sbecore::uint TXF603CLEAN = 40;
		static const Sbecore::uint TXF702CLEAN = 41;
		static const Sbecore::uint TXF703CLEAN = 42;
		static const Sbecore::uint TXF704CLEAN = 43;
		static const Sbecore::uint TXF705CLEAN = 44;
		static const Sbecore::uint PUP706CLEAN = 45;
		static const Sbecore::uint TXF707CLEAN = 46;
		static const Sbecore::uint TXF708CLEAN = 47;
		static const Sbecore::uint TXF709CLEAN = 48;
		static const Sbecore::uint TXF710CLEAN = 49;

	public:
		StatShr(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool Txf2Clean = false, const bool Chk3Clean = false, const bool Txf4Clean = false, const bool Txf5Clean = false, const bool Txf6Clean = false, const bool Txf102Clean = false, const bool Chk103Clean = false, const bool Txf104Clean = false, const bool Sep2Avail = true, const bool Hdg201Avail = true, const bool Txf202Avail = true, const bool Txf202Clean = false, const bool Txf203Avail = true, const bool Txf203Clean = false, const bool Chk204Avail = true, const bool Chk204Clean = false, const bool Sep3Avail = true, const bool Hdg301Avail = true, const bool Txf302Avail = true, const bool Txf302Clean = false, const bool Txf303Avail = true, const bool Txf303Clean = false, const bool Chk304Avail = true, const bool Chk304Clean = false, const bool Pup402Clean = false, const bool Txf403Clean = false, const bool Txf404Clean = false, const bool Txf405Clean = false, const bool Txf406Clean = false, const bool Txf407Clean = false, const bool Txf408Clean = false, const bool Txf502Clean = false, const bool Txf503Clean = false, const bool Txf504Clean = false, const bool Txf505Clean = false, const bool Txf506Clean = false, const bool Txf507Clean = false, const bool Txf602Clean = false, const bool Txf603Clean = false, const bool Txf702Clean = false, const bool Txf703Clean = false, const bool Txf704Clean = false, const bool Txf705Clean = false, const bool Pup706Clean = false, const bool Txf707Clean = false, const bool Txf708Clean = false, const bool Txf709Clean = false, const bool Txf710Clean = false);

	public:
		Sbecore::uint ixWdbeVExpstate;
		bool Txf2Clean;
		bool Chk3Clean;
		bool Txf4Clean;
		bool Txf5Clean;
		bool Txf6Clean;
		bool Txf102Clean;
		bool Chk103Clean;
		bool Txf104Clean;
		bool Sep2Avail;
		bool Hdg201Avail;
		bool Txf202Avail;
		bool Txf202Clean;
		bool Txf203Avail;
		bool Txf203Clean;
		bool Chk204Avail;
		bool Chk204Clean;
		bool Sep3Avail;
		bool Hdg301Avail;
		bool Txf302Avail;
		bool Txf302Clean;
		bool Txf303Avail;
		bool Txf303Clean;
		bool Chk304Avail;
		bool Chk304Clean;
		bool Pup402Clean;
		bool Txf403Clean;
		bool Txf404Clean;
		bool Txf405Clean;
		bool Txf406Clean;
		bool Txf407Clean;
		bool Txf408Clean;
		bool Txf502Clean;
		bool Txf503Clean;
		bool Txf504Clean;
		bool Txf505Clean;
		bool Txf506Clean;
		bool Txf507Clean;
		bool Txf602Clean;
		bool Txf603Clean;
		bool Txf702Clean;
		bool Txf703Clean;
		bool Txf704Clean;
		bool Txf705Clean;
		bool Pup706Clean;
		bool Txf707Clean;
		bool Txf708Clean;
		bool Txf709Clean;
		bool Txf710Clean;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWdbePrfDaemon)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWdbePrfDaemonData)
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
		* DpchAppDo (full: DpchAppWdbePrfDaemonDo)
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
		* DpchEngData (full: DpchEngWdbePrfDaemonData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFPUP402 = 3;
		static const Sbecore::uint FEEDFPUP706 = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint TAG = 6;
		static const Sbecore::uint ALL = 7;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, Sbecore::Feed* feedFPup402 = NULL, Sbecore::Feed* feedFPup706 = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		Sbecore::Feed feedFPup402;
		Sbecore::Feed feedFPup706;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalSep2Avail(DbsWdbe* dbswdbe);
	bool evalHdg201Avail(DbsWdbe* dbswdbe);
	bool evalTxf202Avail(DbsWdbe* dbswdbe);
	bool evalTxf203Avail(DbsWdbe* dbswdbe);
	bool evalChk204Avail(DbsWdbe* dbswdbe);
	bool evalSep3Avail(DbsWdbe* dbswdbe);
	bool evalHdg301Avail(DbsWdbe* dbswdbe);
	bool evalTxf302Avail(DbsWdbe* dbswdbe);
	bool evalTxf303Avail(DbsWdbe* dbswdbe);
	bool evalChk304Avail(DbsWdbe* dbswdbe);

public:
	PnlWdbePrfDaemon(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~PnlWdbePrfDaemon();

public:
	ContIac contiac;
	StatShr statshr;

	Sbecore::Feed feedFPup402;
	Sbecore::Feed feedFPup706;

	// IP vars.cust --- BEGIN
	StgWdbeBehavior stgwdbebehavior;
	StgWdbeAppsrv stgwdbeappsrv;
#ifdef WDBED
	StgWdbed stgwdbed;
#endif
#ifdef WDBECMBD
	StgWdbecmbd stgwdbecmbd;
#endif
	StgWdbeDatabase stgwdbedatabase;
	StgWdbePath stgwdbepath;
	StgWdbeTenant stgwdbetenant;
	StgWdbeMonitor stgwdbemonitor;
	// IP vars.cust --- END

public:
	// IP cust --- BEGIN
#ifdef WDBED
	void getPref(StgWdbeBehavior*& _stgwdbebehavior, StgWdbeAppsrv*& _stgwdbeappsrv, StgWdbed*& _stgwdbed, StgWdbeDatabase*& _stgwdbedatabase, StgWdbePath*& _stgwdbepath, StgWdbeTenant*& _stgwdbetenant, StgWdbeMonitor*& _stgwdbemonitor);
#endif
#ifdef WDBECMBD
	void getPref(StgWdbeBehavior*& _stgwdbebehavior, StgWdbeAppsrv*& _stgwdbeappsrv, StgWdbecmbd*& _stgwdbecmbd, StgWdbeDatabase*& _stgwdbedatabase, StgWdbePath*& _stgwdbepath, StgWdbeTenant*& _stgwdbetenant, StgWdbeMonitor*& _stgwdbemonitor);
#endif
	void setPref(DbsWdbe* dbswdbe, const bool _refresh = false);
	// IP cust --- END

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems, const bool unmute = false);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:

	void handleDpchAppWdbeInit(DbsWdbe* dbswdbe, DpchAppWdbeInit* dpchappwdbeinit, DpchEngWdbe** dpcheng);
	void handleDpchAppDataContiac(DbsWdbe* dbswdbe, ContIac* _contiac, DpchEngWdbe** dpcheng);

	void handleDpchAppDoButRegularizeClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButMinimizeClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

};

#endif
