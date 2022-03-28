/**
	* \file DlgWdbeVerFinmod.h
	* job handler for job DlgWdbeVerFinmod (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

#ifndef DLGWDBEVERFINMOD_H
#define DLGWDBEVERFINMOD_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWdbeLicense.h"

#define VecVDlgWdbeVerFinmodDit DlgWdbeVerFinmod::VecVDit
#define VecVDlgWdbeVerFinmodDo DlgWdbeVerFinmod::VecVDo
#define VecVDlgWdbeVerFinmodDoFnm DlgWdbeVerFinmod::VecVDoFnm
#define VecVDlgWdbeVerFinmodSge DlgWdbeVerFinmod::VecVSge

#define ContIacDlgWdbeVerFinmod DlgWdbeVerFinmod::ContIac
#define ContInfDlgWdbeVerFinmod DlgWdbeVerFinmod::ContInf
#define ContInfDlgWdbeVerFinmodFnm DlgWdbeVerFinmod::ContInfFnm
#define ContInfDlgWdbeVerFinmodLfi DlgWdbeVerFinmod::ContInfLfi
#define StatAppDlgWdbeVerFinmod DlgWdbeVerFinmod::StatApp
#define StatShrDlgWdbeVerFinmod DlgWdbeVerFinmod::StatShr
#define StatShrDlgWdbeVerFinmodFnm DlgWdbeVerFinmod::StatShrFnm
#define StatShrDlgWdbeVerFinmodLfi DlgWdbeVerFinmod::StatShrLfi
#define TagDlgWdbeVerFinmod DlgWdbeVerFinmod::Tag
#define TagDlgWdbeVerFinmodFnm DlgWdbeVerFinmod::TagFnm
#define TagDlgWdbeVerFinmodLfi DlgWdbeVerFinmod::TagLfi

#define DpchAppDlgWdbeVerFinmodData DlgWdbeVerFinmod::DpchAppData
#define DpchAppDlgWdbeVerFinmodDo DlgWdbeVerFinmod::DpchAppDo
#define DpchEngDlgWdbeVerFinmodData DlgWdbeVerFinmod::DpchEngData

/**
	* DlgWdbeVerFinmod
	*/
class DlgWdbeVerFinmod : public JobWdbe {

public:
	/**
		* VecVDit (full: VecVDlgWdbeVerFinmodDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint FNM = 1;
		static const Sbecore::uint LFI = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVDo (full: VecVDlgWdbeVerFinmodDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoFnm (full: VecVDlgWdbeVerFinmodDoFnm)
		*/
	class VecVDoFnm {

	public:
		static const Sbecore::uint BUTRUNCLICK = 1;
		static const Sbecore::uint BUTSTOCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWdbeVerFinmodSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRWER = 2;
		static const Sbecore::uint GENTST = 3;
		static const Sbecore::uint GENWRI = 4;
		static const Sbecore::uint ASMLFI = 5;
		static const Sbecore::uint GENSV = 6;
		static const Sbecore::uint SYNC = 7;
		static const Sbecore::uint FAIL = 8;
		static const Sbecore::uint DONE = 9;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgWdbeVerFinmod)
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
	  * ContInf (full: ContInfDlgWdbeVerFinmod)
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
	  * ContInfFnm (full: ContInfDlgWdbeVerFinmodFnm)
	  */
	class ContInfFnm : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTPRG = 1;

	public:
		ContInfFnm(const std::string& TxtPrg = "");

	public:
		std::string TxtPrg;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfFnm* comp);
		std::set<Sbecore::uint> diff(const ContInfFnm* comp);
	};

	/**
	  * ContInfLfi (full: ContInfDlgWdbeVerFinmodLfi)
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
		* StatApp (full: StatAppDlgWdbeVerFinmod)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const bool initdone = false, const std::string& shortMenu = "");
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdone = false, const std::string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgWdbeVerFinmod)
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
		* StatShrFnm (full: StatShrDlgWdbeVerFinmodFnm)
		*/
	class StatShrFnm : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTRUNACTIVE = 1;
		static const Sbecore::uint BUTSTOACTIVE = 2;

	public:
		StatShrFnm(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrFnm* comp);
		std::set<Sbecore::uint> diff(const StatShrFnm* comp);
	};

	/**
		* StatShrLfi (full: StatShrDlgWdbeVerFinmodLfi)
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
		* Tag (full: TagDlgWdbeVerFinmod)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagFnm (full: TagDlgWdbeVerFinmodFnm)
		*/
	class TagFnm {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagLfi (full: TagDlgWdbeVerFinmodLfi)
		*/
	class TagLfi {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgWdbeVerFinmodData)
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
		* DpchAppDo (full: DpchAppDlgWdbeVerFinmodDo)
		*/
	class DpchAppDo : public DpchAppWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint IXVDOFNM = 3;

	public:
		DpchAppDo();

	public:
		Sbecore::uint ixVDo;
		Sbecore::uint ixVDoFnm;

	public:
		std::string getSrefsMask();

		void readJSON(Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgWdbeVerFinmodData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint CONTINFFNM = 4;
		static const Sbecore::uint CONTINFLFI = 5;
		static const Sbecore::uint FEEDFDSE = 6;
		static const Sbecore::uint FEEDFSGE = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint STATSHRFNM = 10;
		static const Sbecore::uint STATSHRLFI = 11;
		static const Sbecore::uint TAG = 12;
		static const Sbecore::uint TAGFNM = 13;
		static const Sbecore::uint TAGLFI = 14;
		static const Sbecore::uint ALL = 15;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, ContInfFnm* continffnm = NULL, ContInfLfi* continflfi = NULL, Sbecore::Feed* feedFDse = NULL, Sbecore::Feed* feedFSge = NULL, StatShr* statshr = NULL, StatShrFnm* statshrfnm = NULL, StatShrLfi* statshrlfi = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		ContInfFnm continffnm;
		ContInfLfi continflfi;
		Sbecore::Feed feedFDse;
		Sbecore::Feed feedFSge;
		StatShr statshr;
		StatShrFnm statshrfnm;
		StatShrLfi statshrlfi;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalButDneActive(DbsWdbe* dbswdbe);
	bool evalLfiDldActive(DbsWdbe* dbswdbe);
	bool evalFnmButRunActive(DbsWdbe* dbswdbe);
	bool evalFnmButStoActive(DbsWdbe* dbswdbe);

public:
	DlgWdbeVerFinmod(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~DlgWdbeVerFinmod();

public:
	ContIac contiac;
	ContInf continf;
	ContInfFnm continffnm;
	ContInfLfi continflfi;
	StatShr statshr;
	StatShrFnm statshrfnm;
	StatShrLfi statshrlfi;

	Sbecore::Feed feedFMcbAlert;
	Sbecore::Feed feedFDse;
	Sbecore::Feed feedFSge;

	JobWdbeLicense* license;

	Sbecore::uint ixVDit;

	// IP vars.cust --- IBEGIN
	// level-adjusted list of modules used for genwri
	ListWdbeMModule mdls;
	std::vector<unsigned int> lvlsMdls;

	// refs of modules already processed in genwri
	std::set<Sbecore::ubigint> refsMod;

	std::map<Sbecore::ubigint,Sbecore::ubigint> orefsToRefs;

	std::vector<std::string> logfiles;
	std::vector<std::string> logheaders;

	std::string logfile;
	// IP vars.cust --- IEND

public:
	// IP cust --- INSERT

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshFnm(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshLfi(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems, const bool unmute = false);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:

	void handleDpchAppWdbeInit(DbsWdbe* dbswdbe, DpchAppWdbeInit* dpchappwdbeinit, DpchEngWdbe** dpcheng);
	void handleDpchAppDataContiac(DbsWdbe* dbswdbe, ContIac* _contiac, DpchEngWdbe** dpcheng);

	void handleDpchAppDoButDneClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

	void handleDpchAppDoFnmButRunClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoFnmButStoClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppWdbeAlert(DbsWdbe* dbswdbe, DpchAppWdbeAlert* dpchappwdbealert, DpchEngWdbe** dpcheng);

	std::string handleDownloadInSgeFail(DbsWdbe* dbswdbe);
	std::string handleDownloadInSgeDone(DbsWdbe* dbswdbe);

	void handleDpchRetWdbe(DbsWdbe* dbswdbe, DpchRetWdbe* dpchret);
	void handleDpchRetWdbeGenTest(DbsWdbe* dbswdbe, DpchRetWdbeGenTest* dpchret);
	void handleDpchRetWdbeGenWiring(DbsWdbe* dbswdbe, DpchRetWdbeGenWiring* dpchret);

	void handleTimerWithSrefMonInSgeGentst(DbsWdbe* dbswdbe);
	void handleTimerWithSrefMonInSgeGenwri(DbsWdbe* dbswdbe);
	void handleTimerWithSrefMonInSgeGensv(DbsWdbe* dbswdbe);

private:
	void changeStage(DbsWdbe* dbswdbe, Sbecore::uint _ixVSge, DpchEngWdbe** dpcheng = NULL);

public:
	std::string getSquawk(DbsWdbe* dbswdbe);

private:
	Sbecore::uint enterSgeIdle(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeIdle(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeAlrwer(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeAlrwer(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeGentst(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeGentst(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeGenwri(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeGenwri(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeAsmlfi(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeAsmlfi(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeGensv(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeGensv(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeSync(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeSync(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeFail(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeFail(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeDone(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeDone(DbsWdbe* dbswdbe);

};

#endif
