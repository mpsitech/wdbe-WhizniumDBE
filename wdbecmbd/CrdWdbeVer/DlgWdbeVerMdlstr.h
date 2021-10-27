/**
	* \file DlgWdbeVerMdlstr.h
	* job handler for job DlgWdbeVerMdlstr (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

#ifndef DLGWDBEVERMDLSTR_H
#define DLGWDBEVERMDLSTR_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWdbeIexMdl.h"

#define VecVDlgWdbeVerMdlstrDit DlgWdbeVerMdlstr::VecVDit
#define VecVDlgWdbeVerMdlstrDo DlgWdbeVerMdlstr::VecVDo
#define VecVDlgWdbeVerMdlstrDoImp DlgWdbeVerMdlstr::VecVDoImp
#define VecVDlgWdbeVerMdlstrDoPpr DlgWdbeVerMdlstr::VecVDoPpr
#define VecVDlgWdbeVerMdlstrSge DlgWdbeVerMdlstr::VecVSge

#define ContIacDlgWdbeVerMdlstr DlgWdbeVerMdlstr::ContIac
#define ContInfDlgWdbeVerMdlstr DlgWdbeVerMdlstr::ContInf
#define ContInfDlgWdbeVerMdlstrImp DlgWdbeVerMdlstr::ContInfImp
#define ContInfDlgWdbeVerMdlstrLfi DlgWdbeVerMdlstr::ContInfLfi
#define ContInfDlgWdbeVerMdlstrPpr DlgWdbeVerMdlstr::ContInfPpr
#define StatAppDlgWdbeVerMdlstr DlgWdbeVerMdlstr::StatApp
#define StatShrDlgWdbeVerMdlstr DlgWdbeVerMdlstr::StatShr
#define StatShrDlgWdbeVerMdlstrIfi DlgWdbeVerMdlstr::StatShrIfi
#define StatShrDlgWdbeVerMdlstrImp DlgWdbeVerMdlstr::StatShrImp
#define StatShrDlgWdbeVerMdlstrLfi DlgWdbeVerMdlstr::StatShrLfi
#define StatShrDlgWdbeVerMdlstrPpr DlgWdbeVerMdlstr::StatShrPpr
#define TagDlgWdbeVerMdlstr DlgWdbeVerMdlstr::Tag
#define TagDlgWdbeVerMdlstrIfi DlgWdbeVerMdlstr::TagIfi
#define TagDlgWdbeVerMdlstrImp DlgWdbeVerMdlstr::TagImp
#define TagDlgWdbeVerMdlstrLfi DlgWdbeVerMdlstr::TagLfi
#define TagDlgWdbeVerMdlstrPpr DlgWdbeVerMdlstr::TagPpr

#define DpchAppDlgWdbeVerMdlstrData DlgWdbeVerMdlstr::DpchAppData
#define DpchAppDlgWdbeVerMdlstrDo DlgWdbeVerMdlstr::DpchAppDo
#define DpchEngDlgWdbeVerMdlstrData DlgWdbeVerMdlstr::DpchEngData

/**
	* DlgWdbeVerMdlstr
	*/
class DlgWdbeVerMdlstr : public JobWdbe {

public:
	/**
		* VecVDit (full: VecVDlgWdbeVerMdlstrDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint IFI = 1;
		static const Sbecore::uint IMP = 2;
		static const Sbecore::uint PPR = 3;
		static const Sbecore::uint LFI = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVDo (full: VecVDlgWdbeVerMdlstrDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoImp (full: VecVDlgWdbeVerMdlstrDoImp)
		*/
	class VecVDoImp {

	public:
		static const Sbecore::uint BUTRUNCLICK = 1;
		static const Sbecore::uint BUTSTOCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoPpr (full: VecVDlgWdbeVerMdlstrDoPpr)
		*/
	class VecVDoPpr {

	public:
		static const Sbecore::uint BUTRUNCLICK = 1;
		static const Sbecore::uint BUTSTOCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWdbeVerMdlstrSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRFER = 2;
		static const Sbecore::uint PRSIDLE = 3;
		static const Sbecore::uint PARSE = 4;
		static const Sbecore::uint ALRWDBEPER = 5;
		static const Sbecore::uint PRSDONE = 6;
		static const Sbecore::uint IMPIDLE = 7;
		static const Sbecore::uint IMPORT = 8;
		static const Sbecore::uint ALRWDBEIER = 9;
		static const Sbecore::uint IMPDONE = 10;
		static const Sbecore::uint POSTPRC1 = 11;
		static const Sbecore::uint POSTPRC2 = 12;
		static const Sbecore::uint POSTPRC3 = 13;
		static const Sbecore::uint ASMLFI = 14;
		static const Sbecore::uint FAIL = 15;
		static const Sbecore::uint DONE = 16;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgWdbeVerMdlstr)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFDSE = 1;

	public:
		ContIac(const Sbecore::uint numFDse = 1);

	public:
		Sbecore::uint numFDse;

	public:
		bool readJSON(Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfDlgWdbeVerMdlstr)
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
	  * ContInfImp (full: ContInfDlgWdbeVerMdlstrImp)
	  */
	class ContInfImp : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTPRG = 1;

	public:
		ContInfImp(const std::string& TxtPrg = "");

	public:
		std::string TxtPrg;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfImp* comp);
		std::set<Sbecore::uint> diff(const ContInfImp* comp);
	};

	/**
	  * ContInfLfi (full: ContInfDlgWdbeVerMdlstrLfi)
	  */
	class ContInfLfi : public Sbecore::Block {

	public:
		static const Sbecore::uint DLD = 1;

	public:
		ContInfLfi(const std::string& Dld = "file");

	public:
		std::string Dld;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfLfi* comp);
		std::set<Sbecore::uint> diff(const ContInfLfi* comp);
	};

	/**
	  * ContInfPpr (full: ContInfDlgWdbeVerMdlstrPpr)
	  */
	class ContInfPpr : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTPRG = 1;

	public:
		ContInfPpr(const std::string& TxtPrg = "");

	public:
		std::string TxtPrg;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfPpr* comp);
		std::set<Sbecore::uint> diff(const ContInfPpr* comp);
	};

	/**
		* StatApp (full: StatAppDlgWdbeVerMdlstr)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const bool initdone = false, const std::string& shortMenu = "");
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdone = false, const std::string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgWdbeVerMdlstr)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTDNEACTIVE = 1;

	public:
		StatShr(const bool ButDneActive = true);

	public:
		bool ButDneActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* StatShrIfi (full: StatShrDlgWdbeVerMdlstrIfi)
		*/
	class StatShrIfi : public Sbecore::Block {

	public:
		static const Sbecore::uint ULDACTIVE = 1;

	public:
		StatShrIfi(const bool UldActive = true);

	public:
		bool UldActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrIfi* comp);
		std::set<Sbecore::uint> diff(const StatShrIfi* comp);
	};

	/**
		* StatShrImp (full: StatShrDlgWdbeVerMdlstrImp)
		*/
	class StatShrImp : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTRUNACTIVE = 1;
		static const Sbecore::uint BUTSTOACTIVE = 2;

	public:
		StatShrImp(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrImp* comp);
		std::set<Sbecore::uint> diff(const StatShrImp* comp);
	};

	/**
		* StatShrLfi (full: StatShrDlgWdbeVerMdlstrLfi)
		*/
	class StatShrLfi : public Sbecore::Block {

	public:
		static const Sbecore::uint DLDACTIVE = 1;

	public:
		StatShrLfi(const bool DldActive = true);

	public:
		bool DldActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrLfi* comp);
		std::set<Sbecore::uint> diff(const StatShrLfi* comp);
	};

	/**
		* StatShrPpr (full: StatShrDlgWdbeVerMdlstrPpr)
		*/
	class StatShrPpr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTRUNACTIVE = 1;
		static const Sbecore::uint BUTSTOACTIVE = 2;

	public:
		StatShrPpr(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrPpr* comp);
		std::set<Sbecore::uint> diff(const StatShrPpr* comp);
	};

	/**
		* Tag (full: TagDlgWdbeVerMdlstr)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagIfi (full: TagDlgWdbeVerMdlstrIfi)
		*/
	class TagIfi {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagImp (full: TagDlgWdbeVerMdlstrImp)
		*/
	class TagImp {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagLfi (full: TagDlgWdbeVerMdlstrLfi)
		*/
	class TagLfi {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagPpr (full: TagDlgWdbeVerMdlstrPpr)
		*/
	class TagPpr {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgWdbeVerMdlstrData)
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

		void readJSON(Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppDlgWdbeVerMdlstrDo)
		*/
	class DpchAppDo : public DpchAppWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint IXVDOIMP = 3;
		static const Sbecore::uint IXVDOPPR = 4;

	public:
		DpchAppDo();

	public:
		Sbecore::uint ixVDo;
		Sbecore::uint ixVDoImp;
		Sbecore::uint ixVDoPpr;

	public:
		std::string getSrefsMask();

		void readJSON(Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgWdbeVerMdlstrData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint CONTINFIMP = 4;
		static const Sbecore::uint CONTINFLFI = 5;
		static const Sbecore::uint CONTINFPPR = 6;
		static const Sbecore::uint FEEDFDSE = 7;
		static const Sbecore::uint FEEDFSGE = 8;
		static const Sbecore::uint STATAPP = 9;
		static const Sbecore::uint STATSHR = 10;
		static const Sbecore::uint STATSHRIFI = 11;
		static const Sbecore::uint STATSHRIMP = 12;
		static const Sbecore::uint STATSHRLFI = 13;
		static const Sbecore::uint STATSHRPPR = 14;
		static const Sbecore::uint TAG = 15;
		static const Sbecore::uint TAGIFI = 16;
		static const Sbecore::uint TAGIMP = 17;
		static const Sbecore::uint TAGLFI = 18;
		static const Sbecore::uint TAGPPR = 19;
		static const Sbecore::uint ALL = 20;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, ContInfImp* continfimp = NULL, ContInfLfi* continflfi = NULL, ContInfPpr* continfppr = NULL, Sbecore::Feed* feedFDse = NULL, Sbecore::Feed* feedFSge = NULL, StatShr* statshr = NULL, StatShrIfi* statshrifi = NULL, StatShrImp* statshrimp = NULL, StatShrLfi* statshrlfi = NULL, StatShrPpr* statshrppr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		ContInfImp continfimp;
		ContInfLfi continflfi;
		ContInfPpr continfppr;
		Sbecore::Feed feedFDse;
		Sbecore::Feed feedFSge;
		StatShr statshr;
		StatShrIfi statshrifi;
		StatShrImp statshrimp;
		StatShrLfi statshrlfi;
		StatShrPpr statshrppr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalIfiUldActive(DbsWdbe* dbswdbe);
	bool evalImpButRunActive(DbsWdbe* dbswdbe);
	bool evalImpButStoActive(DbsWdbe* dbswdbe);
	bool evalPprButRunActive(DbsWdbe* dbswdbe);
	bool evalPprButStoActive(DbsWdbe* dbswdbe);
	bool evalLfiDldActive(DbsWdbe* dbswdbe);
	bool evalButDneActive(DbsWdbe* dbswdbe);

public:
	DlgWdbeVerMdlstr(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~DlgWdbeVerMdlstr();

public:
	ContIac contiac;
	ContInf continf;
	ContInfImp continfimp;
	ContInfLfi continflfi;
	ContInfPpr continfppr;
	StatShr statshr;
	StatShrIfi statshrifi;
	StatShrImp statshrimp;
	StatShrLfi statshrlfi;
	StatShrPpr statshrppr;

	Sbecore::Feed feedFMcbAlert;
	Sbecore::Feed feedFDse;
	Sbecore::Feed feedFSge;

	JobWdbeIexMdl* iex;

	Sbecore::uint ixVDit;

	// IP vars.cust --- IBEGIN
	std::string infilename;
	std::string rectpath;

	bool ifitxt;
	bool ifixml;

	// level-adjusted list of modules used for postprc2/3
	ListWdbeMModule mdls;
	std::vector<unsigned int> lvlsMdls;

	// refs of modules already processed in postprc2/3
	std::set<Sbecore::ubigint> refsTplcpy;
	std::set<Sbecore::ubigint> refsTypmod;
	std::set<Sbecore::ubigint> refsTplmod;

	std::map<Sbecore::ubigint,Sbecore::ubigint> orefsToRefs;

	std::vector<std::string> logfiles;
	std::vector<std::string> logheaders;

	std::string logfile;
	// IP vars.cust --- IEND

public:
	// IP cust --- IBEGIN
	void addLogfile(DbsWdbe* dbswdbe, const Sbecore::ubigint oref, const std::string& _logfile);
	// IP cust --- IEND

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshIfi(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshImp(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshPpr(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshLfi(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems, const bool unmute = false);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:

	void handleDpchAppWdbeInit(DbsWdbe* dbswdbe, DpchAppWdbeInit* dpchappwdbeinit, DpchEngWdbe** dpcheng);
	void handleDpchAppDataContiac(DbsWdbe* dbswdbe, ContIac* _contiac, DpchEngWdbe** dpcheng);

	void handleDpchAppDoButDneClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

	void handleDpchAppDoImpButRunClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoImpButStoClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

	void handleDpchAppDoPprButRunClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoPprButStoClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppWdbeAlert(DbsWdbe* dbswdbe, DpchAppWdbeAlert* dpchappwdbealert, DpchEngWdbe** dpcheng);

	void handleUploadInSgeIdle(DbsWdbe* dbswdbe, const std::string& filename);

	std::string handleDownloadInSgeFail(DbsWdbe* dbswdbe);
	std::string handleDownloadInSgeDone(DbsWdbe* dbswdbe);

	void handleDpchRetWdbe(DbsWdbe* dbswdbe, DpchRetWdbe* dpchret);
	void handleDpchRetWdbeCplmstImbuf(DbsWdbe* dbswdbe, DpchRetWdbeCplmstImbuf* dpchret);
	void handleDpchRetWdbeCplmstTplcpy(DbsWdbe* dbswdbe, DpchRetWdbeCplmstTplcpy* dpchret);

	void handleTimerInSgePrsidle(DbsWdbe* dbswdbe, const std::string& sref);
	void handleTimerInSgeImpidle(DbsWdbe* dbswdbe, const std::string& sref);
	void handleTimerWithSrefMonInSgeImport(DbsWdbe* dbswdbe);
	void handleTimerWithSrefMonInSgePostprc1(DbsWdbe* dbswdbe);
	void handleTimerWithSrefMonInSgePostprc2(DbsWdbe* dbswdbe);
	void handleTimerWithSrefMonInSgePostprc3(DbsWdbe* dbswdbe);

private:
	void changeStage(DbsWdbe* dbswdbe, Sbecore::uint _ixVSge, DpchEngWdbe** dpcheng = NULL);

public:
	std::string getSquawk(DbsWdbe* dbswdbe);

private:
	Sbecore::uint enterSgeIdle(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeIdle(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeAlrfer(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeAlrfer(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgePrsidle(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgePrsidle(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeParse(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeParse(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeAlrwdbeper(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeAlrwdbeper(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgePrsdone(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgePrsdone(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeImpidle(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeImpidle(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeImport(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeImport(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeAlrwdbeier(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeAlrwdbeier(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeImpdone(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeImpdone(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgePostprc1(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgePostprc1(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgePostprc2(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgePostprc2(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgePostprc3(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgePostprc3(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeAsmlfi(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeAsmlfi(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeFail(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeFail(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeDone(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeDone(DbsWdbe* dbswdbe);

};

#endif
