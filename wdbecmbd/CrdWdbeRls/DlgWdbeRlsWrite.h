/**
	* \file DlgWdbeRlsWrite.h
	* job handler for job DlgWdbeRlsWrite (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef DLGWDBERLSWRITE_H
#define DLGWDBERLSWRITE_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWdbeLicense.h"

#define VecVDlgWdbeRlsWriteDit DlgWdbeRlsWrite::VecVDit
#define VecVDlgWdbeRlsWriteDo DlgWdbeRlsWrite::VecVDo
#define VecVDlgWdbeRlsWriteDoWrc DlgWdbeRlsWrite::VecVDoWrc
#define VecVDlgWdbeRlsWriteSge DlgWdbeRlsWrite::VecVSge

#define ContIacDlgWdbeRlsWrite DlgWdbeRlsWrite::ContIac
#define ContIacDlgWdbeRlsWriteDet DlgWdbeRlsWrite::ContIacDet
#define ContInfDlgWdbeRlsWrite DlgWdbeRlsWrite::ContInf
#define ContInfDlgWdbeRlsWriteFia DlgWdbeRlsWrite::ContInfFia
#define ContInfDlgWdbeRlsWriteLfi DlgWdbeRlsWrite::ContInfLfi
#define ContInfDlgWdbeRlsWriteWrc DlgWdbeRlsWrite::ContInfWrc
#define StatAppDlgWdbeRlsWrite DlgWdbeRlsWrite::StatApp
#define StatShrDlgWdbeRlsWrite DlgWdbeRlsWrite::StatShr
#define StatShrDlgWdbeRlsWriteCuc DlgWdbeRlsWrite::StatShrCuc
#define StatShrDlgWdbeRlsWriteFia DlgWdbeRlsWrite::StatShrFia
#define StatShrDlgWdbeRlsWriteLfi DlgWdbeRlsWrite::StatShrLfi
#define StatShrDlgWdbeRlsWriteWrc DlgWdbeRlsWrite::StatShrWrc
#define TagDlgWdbeRlsWrite DlgWdbeRlsWrite::Tag
#define TagDlgWdbeRlsWriteCuc DlgWdbeRlsWrite::TagCuc
#define TagDlgWdbeRlsWriteDet DlgWdbeRlsWrite::TagDet
#define TagDlgWdbeRlsWriteFia DlgWdbeRlsWrite::TagFia
#define TagDlgWdbeRlsWriteLfi DlgWdbeRlsWrite::TagLfi
#define TagDlgWdbeRlsWriteWrc DlgWdbeRlsWrite::TagWrc

#define DpchAppDlgWdbeRlsWriteData DlgWdbeRlsWrite::DpchAppData
#define DpchAppDlgWdbeRlsWriteDo DlgWdbeRlsWrite::DpchAppDo
#define DpchEngDlgWdbeRlsWriteData DlgWdbeRlsWrite::DpchEngData

/**
	* DlgWdbeRlsWrite
	*/
class DlgWdbeRlsWrite : public JobWdbe {

public:
	/**
		* VecVDit (full: VecVDlgWdbeRlsWriteDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint DET = 1;
		static const Sbecore::uint CUC = 2;
		static const Sbecore::uint WRC = 3;
		static const Sbecore::uint LFI = 4;
		static const Sbecore::uint FIA = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVDo (full: VecVDlgWdbeRlsWriteDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoWrc (full: VecVDlgWdbeRlsWriteDoWrc)
		*/
	class VecVDoWrc {

	public:
		static const Sbecore::uint BUTAUTCLICK = 1;
		static const Sbecore::uint BUTRUNCLICK = 2;
		static const Sbecore::uint BUTSTOCLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWdbeRlsWriteSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRAER = 2;
		static const Sbecore::uint ALRMER = 3;
		static const Sbecore::uint UPKIDLE = 4;
		static const Sbecore::uint UNPACK = 5;
		static const Sbecore::uint UPKDONE = 6;
		static const Sbecore::uint AUTH = 7;
		static const Sbecore::uint AUTDONE = 8;
		static const Sbecore::uint FILLPLH = 9;
		static const Sbecore::uint CREATE = 10;
		static const Sbecore::uint WRITE = 11;
		static const Sbecore::uint MRG = 12;
		static const Sbecore::uint MRGFINE = 13;
		static const Sbecore::uint MRGTYPSPEC = 14;
		static const Sbecore::uint MRGTPLSPEC = 15;
		static const Sbecore::uint CLRSPEC = 16;
		static const Sbecore::uint MRGCUST = 17;
		static const Sbecore::uint PACK = 18;
		static const Sbecore::uint FAIL = 19;
		static const Sbecore::uint DONE = 20;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgWdbeRlsWrite)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFDSE = 1;

	public:
		ContIac(const Sbecore::uint numFDse = 1);

	public:
		Sbecore::uint numFDse;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContIacDet (full: ContIacDlgWdbeRlsWriteDet)
	  */
	class ContIacDet : public Sbecore::Block {

	public:
		static const Sbecore::uint CHKBSO = 1;

	public:
		ContIacDet(const bool ChkBso = false);

	public:
		bool ChkBso;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIacDet* comp);
		std::set<Sbecore::uint> diff(const ContIacDet* comp);
	};

	/**
	  * ContInf (full: ContInfDlgWdbeRlsWrite)
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
	  * ContInfFia (full: ContInfDlgWdbeRlsWriteFia)
	  */
	class ContInfFia : public Sbecore::Block {

	public:
		static const Sbecore::uint DLD = 1;

	public:
		ContInfFia(const std::string& Dld = "file");

	public:
		std::string Dld;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfFia* comp);
		std::set<Sbecore::uint> diff(const ContInfFia* comp);
	};

	/**
	  * ContInfLfi (full: ContInfDlgWdbeRlsWriteLfi)
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
	  * ContInfWrc (full: ContInfDlgWdbeRlsWriteWrc)
	  */
	class ContInfWrc : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTPRG = 1;

	public:
		ContInfWrc(const std::string& TxtPrg = "");

	public:
		std::string TxtPrg;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfWrc* comp);
		std::set<Sbecore::uint> diff(const ContInfWrc* comp);
	};

	/**
		* StatApp (full: StatAppDlgWdbeRlsWrite)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const bool initdone = false, const std::string& shortMenu = "");
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdone = false, const std::string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgWdbeRlsWrite)
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
		* StatShrCuc (full: StatShrDlgWdbeRlsWriteCuc)
		*/
	class StatShrCuc : public Sbecore::Block {

	public:
		static const Sbecore::uint ULDAVAIL = 1;
		static const Sbecore::uint ULDACTIVE = 2;

	public:
		StatShrCuc(const bool UldAvail = true, const bool UldActive = true);

	public:
		bool UldAvail;
		bool UldActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrCuc* comp);
		std::set<Sbecore::uint> diff(const StatShrCuc* comp);
	};

	/**
		* StatShrFia (full: StatShrDlgWdbeRlsWriteFia)
		*/
	class StatShrFia : public Sbecore::Block {

	public:
		static const Sbecore::uint DLDAVAIL = 1;
		static const Sbecore::uint DLDACTIVE = 2;

	public:
		StatShrFia(const bool DldAvail = true, const bool DldActive = true);

	public:
		bool DldAvail;
		bool DldActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrFia* comp);
		std::set<Sbecore::uint> diff(const StatShrFia* comp);
	};

	/**
		* StatShrLfi (full: StatShrDlgWdbeRlsWriteLfi)
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
		* StatShrWrc (full: StatShrDlgWdbeRlsWriteWrc)
		*/
	class StatShrWrc : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTAUTACTIVE = 1;
		static const Sbecore::uint BUTRUNACTIVE = 2;
		static const Sbecore::uint BUTSTOACTIVE = 3;

	public:
		StatShrWrc(const bool ButAutActive = true, const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButAutActive;
		bool ButRunActive;
		bool ButStoActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrWrc* comp);
		std::set<Sbecore::uint> diff(const StatShrWrc* comp);
	};

	/**
		* Tag (full: TagDlgWdbeRlsWrite)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagCuc (full: TagDlgWdbeRlsWriteCuc)
		*/
	class TagCuc {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagDet (full: TagDlgWdbeRlsWriteDet)
		*/
	class TagDet {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagFia (full: TagDlgWdbeRlsWriteFia)
		*/
	class TagFia {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagLfi (full: TagDlgWdbeRlsWriteLfi)
		*/
	class TagLfi {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagWrc (full: TagDlgWdbeRlsWriteWrc)
		*/
	class TagWrc {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgWdbeRlsWriteData)
		*/
	class DpchAppData : public DpchAppWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTIACDET = 3;

	public:
		DpchAppData();

	public:
		ContIac contiac;
		ContIacDet contiacdet;

	public:
		std::string getSrefsMask();

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppDlgWdbeRlsWriteDo)
		*/
	class DpchAppDo : public DpchAppWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint IXVDOWRC = 3;

	public:
		DpchAppDo();

	public:
		Sbecore::uint ixVDo;
		Sbecore::uint ixVDoWrc;

	public:
		std::string getSrefsMask();

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgWdbeRlsWriteData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTIACDET = 3;
		static const Sbecore::uint CONTINF = 4;
		static const Sbecore::uint CONTINFFIA = 5;
		static const Sbecore::uint CONTINFLFI = 6;
		static const Sbecore::uint CONTINFWRC = 7;
		static const Sbecore::uint FEEDFDSE = 8;
		static const Sbecore::uint FEEDFSGE = 9;
		static const Sbecore::uint STATAPP = 10;
		static const Sbecore::uint STATSHR = 11;
		static const Sbecore::uint STATSHRCUC = 12;
		static const Sbecore::uint STATSHRFIA = 13;
		static const Sbecore::uint STATSHRLFI = 14;
		static const Sbecore::uint STATSHRWRC = 15;
		static const Sbecore::uint TAG = 16;
		static const Sbecore::uint TAGCUC = 17;
		static const Sbecore::uint TAGDET = 18;
		static const Sbecore::uint TAGFIA = 19;
		static const Sbecore::uint TAGLFI = 20;
		static const Sbecore::uint TAGWRC = 21;
		static const Sbecore::uint ALL = 22;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContIacDet* contiacdet = NULL, ContInf* continf = NULL, ContInfFia* continffia = NULL, ContInfLfi* continflfi = NULL, ContInfWrc* continfwrc = NULL, Sbecore::Feed* feedFDse = NULL, Sbecore::Feed* feedFSge = NULL, StatShr* statshr = NULL, StatShrCuc* statshrcuc = NULL, StatShrFia* statshrfia = NULL, StatShrLfi* statshrlfi = NULL, StatShrWrc* statshrwrc = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContIacDet contiacdet;
		ContInf continf;
		ContInfFia continffia;
		ContInfLfi continflfi;
		ContInfWrc continfwrc;
		Sbecore::Feed feedFDse;
		Sbecore::Feed feedFSge;
		StatShr statshr;
		StatShrCuc statshrcuc;
		StatShrFia statshrfia;
		StatShrLfi statshrlfi;
		StatShrWrc statshrwrc;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalCucUldAvail(DbsWdbe* dbswdbe);
	bool evalCucUldActive(DbsWdbe* dbswdbe);
	bool evalWrcButAutActive(DbsWdbe* dbswdbe);
	bool evalWrcButRunActive(DbsWdbe* dbswdbe);
	bool evalWrcButStoActive(DbsWdbe* dbswdbe);
	bool evalLfiDldActive(DbsWdbe* dbswdbe);
	bool evalFiaDldAvail(DbsWdbe* dbswdbe);
	bool evalFiaDldActive(DbsWdbe* dbswdbe);
	bool evalButDneActive(DbsWdbe* dbswdbe);

public:
	DlgWdbeRlsWrite(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~DlgWdbeRlsWrite();

public:
	ContIac contiac;
	ContIacDet contiacdet;
	ContInf continf;
	ContInfFia continffia;
	ContInfLfi continflfi;
	ContInfWrc continfwrc;
	StatShr statshr;
	StatShrCuc statshrcuc;
	StatShrFia statshrfia;
	StatShrLfi statshrlfi;
	StatShrWrc statshrwrc;

	Sbecore::Feed feedFMcbAlert;
	Sbecore::Feed feedFDse;
	Sbecore::Feed feedFSge;

	JobWdbeLicense* license;

	Sbecore::uint ixVDit;

	// IP vars.cust --- IBEGIN
	Sbecore::ubigint refWdbeMRelease;
	std::string rlssref;

	std::string author;

	std::string PRJSHORT;
	std::string Prjshort;
	std::string prjshort;

	bool Prjeasy;

	Sbecore::uint ixCmptype;

	std::string CMPSREF;
	std::string Cmpsref;
	std::string cmpsref;

	std::string cchost;
	std::string ncore;
	std::string sysroot;
	std::string inclibeq;

	std::string infilename;
	std::string outfolder; // working directory
	std::string ipfolder; // IP's
	std::string finefolder; // IP's
	std::string typspecfolder; // module-type specific IP's
	std::string tplspecfolder; // module-template specific IP's
	std::string auxfolder; // auxiliary IP's
	std::string custfolder; // custom IP's

	std::map<Sbecore::ubigint,Sbecore::ubigint> orefsToRefs;

	std::vector<std::string> typkeys, typvals;
	std::map<Sbecore::ubigint, unsigned int> ics0Typkeys, ics1Typkeys; // by refMdl

	std::vector<std::string> tplkeys, tplvals;
	std::map<Sbecore::ubigint, unsigned int> ics0Tplkeys, ics1Tplkeys; // by refMdl

	std::string logaspect;
	std::string logfile;
	// IP vars.cust --- IEND

public:
	// IP cust --- IBEGIN
	void createIpoutSubfolder(const bool spec, const std::string& sub1, const std::string& sub2 = "");
	void copyAcvtmp(DbsWdbe* dbswdbe, const Sbecore::ubigint refWdbeMFile, const std::string& tmpfile);

	void createFpga(DbsWdbe* dbswdbe, const bool dplonly);
	void createMcu(DbsWdbe* dbswdbe, const bool dplonly);
	void createDev(DbsWdbe* dbswdbe, const bool dplonly);
	void createEzdev(DbsWdbe* dbswdbe, const bool dplonly);
	void createTerm(DbsWdbe* dbswdbe, const bool dplonly);

	void mergeKeysVals(const Sbecore::ubigint oref, std::vector<std::string>& keys, std::vector<std::string>& vals, const bool tplNotTyp);
	// IP cust --- IEND

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshDet(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshCuc(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshWrc(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshLfi(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshFia(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems, const bool unmute = false);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:

	void handleDpchAppWdbeInit(DbsWdbe* dbswdbe, DpchAppWdbeInit* dpchappwdbeinit, DpchEngWdbe** dpcheng);
	void handleDpchAppDataContiac(DbsWdbe* dbswdbe, ContIac* _contiac, DpchEngWdbe** dpcheng);
	void handleDpchAppDataContiacdet(DbsWdbe* dbswdbe, ContIacDet* _contiacdet, DpchEngWdbe** dpcheng);

	void handleDpchAppDoButDneClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

	void handleDpchAppDoWrcButAutClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoWrcButRunClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoWrcButStoClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppWdbeAlert(DbsWdbe* dbswdbe, DpchAppWdbeAlert* dpchappwdbealert, DpchEngWdbe** dpcheng);

	void handleUploadInSgeIdle(DbsWdbe* dbswdbe, const std::string& filename);

	std::string handleDownloadInSgeFail(DbsWdbe* dbswdbe);
	std::string handleDownloadInSgeDone(DbsWdbe* dbswdbe);

	void handleDpchRetWdbeMtpPlhfpga(DbsWdbe* dbswdbe, DpchRetWdbeMtpPlhfpga* dpchret);
	void handleDpchRetWdbeMtpPlhmcu(DbsWdbe* dbswdbe, DpchRetWdbeMtpPlhmcu* dpchret);
	void handleDpchRetWdbePlhfpgaCmdinv(DbsWdbe* dbswdbe, DpchRetWdbePlhfpgaCmdinv* dpchret);
	void handleDpchRetWdbePlhfpgaCmdret(DbsWdbe* dbswdbe, DpchRetWdbePlhfpgaCmdret* dpchret);
	void handleDpchRetWdbePlhmcuEctr(DbsWdbe* dbswdbe, DpchRetWdbePlhmcuEctr* dpchret);
	void handleDpchRetWdbePlhmcuEhostif(DbsWdbe* dbswdbe, DpchRetWdbePlhmcuEhostif* dpchret);
	void handleDpchRetWdbePrctreeMerge(DbsWdbe* dbswdbe, DpchRetWdbePrctreeMerge* dpchret);

	void handleTimerInSgeUpkidle(DbsWdbe* dbswdbe, const std::string& sref);
	void handleTimerWithSrefMonInSgeCreate(DbsWdbe* dbswdbe);
	void handleTimerWithSrefMonInSgeWrite(DbsWdbe* dbswdbe);

private:
	void changeStage(DbsWdbe* dbswdbe, Sbecore::uint _ixVSge, DpchEngWdbe** dpcheng = NULL);

public:
	std::string getSquawk(DbsWdbe* dbswdbe);

private:
	Sbecore::uint enterSgeIdle(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeIdle(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeAlraer(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeAlraer(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeAlrmer(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeAlrmer(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeUpkidle(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeUpkidle(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeUnpack(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeUnpack(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeUpkdone(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeUpkdone(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeAuth(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeAuth(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeAutdone(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeAutdone(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeFillplh(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeFillplh(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeCreate(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeCreate(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeWrite(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeWrite(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeMrg(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeMrg(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeMrgfine(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeMrgfine(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeMrgtypspec(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeMrgtypspec(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeMrgtplspec(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeMrgtplspec(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeClrspec(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeClrspec(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeMrgcust(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeMrgcust(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgePack(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgePack(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeFail(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeFail(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeDone(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeDone(DbsWdbe* dbswdbe);

};

#endif
