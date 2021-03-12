/**
	* \file DlgWdbeNavLoaini.h
	* job handler for job DlgWdbeNavLoaini (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef DLGWDBENAVLOAINI_H
#define DLGWDBENAVLOAINI_H

// IP include.spec --- INSERT

// IP include.cust --- IBEGIN
#include <sys/types.h>
#include <dirent.h>
// IP include.cust --- IEND

#include "JobWdbeIexIni.h"

#define VecVDlgWdbeNavLoainiDit DlgWdbeNavLoaini::VecVDit
#define VecVDlgWdbeNavLoainiDo DlgWdbeNavLoaini::VecVDo
#define VecVDlgWdbeNavLoainiDoImp DlgWdbeNavLoaini::VecVDoImp
#define VecVDlgWdbeNavLoainiSge DlgWdbeNavLoaini::VecVSge

#define ContIacDlgWdbeNavLoaini DlgWdbeNavLoaini::ContIac
#define ContInfDlgWdbeNavLoaini DlgWdbeNavLoaini::ContInf
#define ContInfDlgWdbeNavLoainiImp DlgWdbeNavLoaini::ContInfImp
#define ContInfDlgWdbeNavLoainiLfi DlgWdbeNavLoaini::ContInfLfi
#define StatAppDlgWdbeNavLoaini DlgWdbeNavLoaini::StatApp
#define StatShrDlgWdbeNavLoaini DlgWdbeNavLoaini::StatShr
#define StatShrDlgWdbeNavLoainiAcv DlgWdbeNavLoaini::StatShrAcv
#define StatShrDlgWdbeNavLoainiIfi DlgWdbeNavLoaini::StatShrIfi
#define StatShrDlgWdbeNavLoainiImp DlgWdbeNavLoaini::StatShrImp
#define StatShrDlgWdbeNavLoainiLfi DlgWdbeNavLoaini::StatShrLfi
#define TagDlgWdbeNavLoaini DlgWdbeNavLoaini::Tag
#define TagDlgWdbeNavLoainiAcv DlgWdbeNavLoaini::TagAcv
#define TagDlgWdbeNavLoainiIfi DlgWdbeNavLoaini::TagIfi
#define TagDlgWdbeNavLoainiImp DlgWdbeNavLoaini::TagImp
#define TagDlgWdbeNavLoainiLfi DlgWdbeNavLoaini::TagLfi

#define DpchAppDlgWdbeNavLoainiData DlgWdbeNavLoaini::DpchAppData
#define DpchAppDlgWdbeNavLoainiDo DlgWdbeNavLoaini::DpchAppDo
#define DpchEngDlgWdbeNavLoainiData DlgWdbeNavLoaini::DpchEngData

/**
	* DlgWdbeNavLoaini
	*/
class DlgWdbeNavLoaini : public JobWdbe {

public:
	/**
		* VecVDit (full: VecVDlgWdbeNavLoainiDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint IFI = 1;
		static const Sbecore::uint IMP = 2;
		static const Sbecore::uint ACV = 3;
		static const Sbecore::uint LFI = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVDo (full: VecVDlgWdbeNavLoainiDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoImp (full: VecVDlgWdbeNavLoainiDoImp)
		*/
	class VecVDoImp {

	public:
		static const Sbecore::uint BUTRUNCLICK = 1;
		static const Sbecore::uint BUTSTOCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWdbeNavLoainiSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint PRSIDLE = 2;
		static const Sbecore::uint PARSE = 3;
		static const Sbecore::uint ALRWDBEPER = 4;
		static const Sbecore::uint PRSDONE = 5;
		static const Sbecore::uint IMPIDLE = 6;
		static const Sbecore::uint IMPORT = 7;
		static const Sbecore::uint ALRWDBEIER = 8;
		static const Sbecore::uint IMPDONE = 9;
		static const Sbecore::uint UPKIDLE = 10;
		static const Sbecore::uint UNPACK = 11;
		static const Sbecore::uint DONE = 12;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgWdbeNavLoaini)
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
	  * ContInf (full: ContInfDlgWdbeNavLoaini)
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
	  * ContInfImp (full: ContInfDlgWdbeNavLoainiImp)
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
	  * ContInfLfi (full: ContInfDlgWdbeNavLoainiLfi)
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
		* StatApp (full: StatAppDlgWdbeNavLoaini)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const bool initdone = false, const std::string& shortMenu = "");
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdone = false, const std::string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgWdbeNavLoaini)
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
		* StatShrAcv (full: StatShrDlgWdbeNavLoainiAcv)
		*/
	class StatShrAcv : public Sbecore::Block {

	public:
		static const Sbecore::uint ULDACTIVE = 1;

	public:
		StatShrAcv(const bool UldActive = true);

	public:
		bool UldActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrAcv* comp);
		std::set<Sbecore::uint> diff(const StatShrAcv* comp);
	};

	/**
		* StatShrIfi (full: StatShrDlgWdbeNavLoainiIfi)
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
		* StatShrImp (full: StatShrDlgWdbeNavLoainiImp)
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
		* StatShrLfi (full: StatShrDlgWdbeNavLoainiLfi)
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
		* Tag (full: TagDlgWdbeNavLoaini)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagAcv (full: TagDlgWdbeNavLoainiAcv)
		*/
	class TagAcv {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagIfi (full: TagDlgWdbeNavLoainiIfi)
		*/
	class TagIfi {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagImp (full: TagDlgWdbeNavLoainiImp)
		*/
	class TagImp {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagLfi (full: TagDlgWdbeNavLoainiLfi)
		*/
	class TagLfi {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgWdbeNavLoainiData)
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
		* DpchAppDo (full: DpchAppDlgWdbeNavLoainiDo)
		*/
	class DpchAppDo : public DpchAppWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint IXVDOIMP = 3;

	public:
		DpchAppDo();

	public:
		Sbecore::uint ixVDo;
		Sbecore::uint ixVDoImp;

	public:
		std::string getSrefsMask();

		void readJSON(Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgWdbeNavLoainiData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint CONTINFIMP = 4;
		static const Sbecore::uint CONTINFLFI = 5;
		static const Sbecore::uint FEEDFDSE = 6;
		static const Sbecore::uint FEEDFSGE = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint STATSHRACV = 10;
		static const Sbecore::uint STATSHRIFI = 11;
		static const Sbecore::uint STATSHRIMP = 12;
		static const Sbecore::uint STATSHRLFI = 13;
		static const Sbecore::uint TAG = 14;
		static const Sbecore::uint TAGACV = 15;
		static const Sbecore::uint TAGIFI = 16;
		static const Sbecore::uint TAGIMP = 17;
		static const Sbecore::uint TAGLFI = 18;
		static const Sbecore::uint ALL = 19;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, ContInfImp* continfimp = NULL, ContInfLfi* continflfi = NULL, Sbecore::Feed* feedFDse = NULL, Sbecore::Feed* feedFSge = NULL, StatShr* statshr = NULL, StatShrAcv* statshracv = NULL, StatShrIfi* statshrifi = NULL, StatShrImp* statshrimp = NULL, StatShrLfi* statshrlfi = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		ContInfImp continfimp;
		ContInfLfi continflfi;
		Sbecore::Feed feedFDse;
		Sbecore::Feed feedFSge;
		StatShr statshr;
		StatShrAcv statshracv;
		StatShrIfi statshrifi;
		StatShrImp statshrimp;
		StatShrLfi statshrlfi;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalButDneActive(DbsWdbe* dbswdbe);
	bool evalLfiDldActive(DbsWdbe* dbswdbe);
	bool evalAcvUldActive(DbsWdbe* dbswdbe);
	bool evalImpButRunActive(DbsWdbe* dbswdbe);
	bool evalImpButStoActive(DbsWdbe* dbswdbe);
	bool evalIfiUldActive(DbsWdbe* dbswdbe);

public:
	DlgWdbeNavLoaini(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~DlgWdbeNavLoaini();

public:
	ContIac contiac;
	ContInf continf;
	ContInfImp continfimp;
	ContInfLfi continflfi;
	StatShr statshr;
	StatShrAcv statshracv;
	StatShrIfi statshrifi;
	StatShrImp statshrimp;
	StatShrLfi statshrlfi;

	Sbecore::Feed feedFMcbAlert;
	Sbecore::Feed feedFDse;
	Sbecore::Feed feedFSge;

	JobWdbeIexIni* iex;

	Sbecore::uint ixVDit;

	// IP vars.cust --- IBEGIN
	std::string infilename;
	// IP vars.cust --- IEND

public:
	// IP cust --- INSERT

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshIfi(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshImp(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshAcv(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
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
	void handleDpchAppWdbeAlert(DbsWdbe* dbswdbe, DpchAppWdbeAlert* dpchappwdbealert, DpchEngWdbe** dpcheng);

	void handleUploadInSgeImpdone(DbsWdbe* dbswdbe, const std::string& filename);
	void handleUploadInSgeIdle(DbsWdbe* dbswdbe, const std::string& filename);

	std::string handleDownloadInSgeDone(DbsWdbe* dbswdbe);

	void handleTimerWithSrefMonInSgeImport(DbsWdbe* dbswdbe);
	void handleTimerInSgeUpkidle(DbsWdbe* dbswdbe, const std::string& sref);
	void handleTimerInSgeImpidle(DbsWdbe* dbswdbe, const std::string& sref);
	void handleTimerInSgePrsidle(DbsWdbe* dbswdbe, const std::string& sref);

private:
	void changeStage(DbsWdbe* dbswdbe, Sbecore::uint _ixVSge, DpchEngWdbe** dpcheng = NULL);

public:
	std::string getSquawk(DbsWdbe* dbswdbe);

private:
	Sbecore::uint enterSgeIdle(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeIdle(DbsWdbe* dbswdbe);
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
	Sbecore::uint enterSgeUpkidle(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeUpkidle(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeUnpack(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeUnpack(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeDone(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeDone(DbsWdbe* dbswdbe);

};

#endif
