/**
	* \file DlgWdbeRlsStareptr.h
	* job handler for job DlgWdbeRlsStareptr (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef DLGWDBERLSSTAREPTR_H
#define DLGWDBERLSSTAREPTR_H

// IP include.spec --- INSERT

// IP include.cust --- IBEGIN
#include "git2.h"
// IP include.cust --- IEND

#define VecVDlgWdbeRlsStareptrDit DlgWdbeRlsStareptr::VecVDit
#define VecVDlgWdbeRlsStareptrDo DlgWdbeRlsStareptr::VecVDo
#define VecVDlgWdbeRlsStareptrDoDet DlgWdbeRlsStareptr::VecVDoDet
#define VecVDlgWdbeRlsStareptrDoExt DlgWdbeRlsStareptr::VecVDoExt
#define VecVDlgWdbeRlsStareptrDoIni DlgWdbeRlsStareptr::VecVDoIni
#define VecVDlgWdbeRlsStareptrSge DlgWdbeRlsStareptr::VecVSge

#define ContIacDlgWdbeRlsStareptr DlgWdbeRlsStareptr::ContIac
#define ContIacDlgWdbeRlsStareptrDet DlgWdbeRlsStareptr::ContIacDet
#define ContInfDlgWdbeRlsStareptr DlgWdbeRlsStareptr::ContInf
#define ContInfDlgWdbeRlsStareptrExt DlgWdbeRlsStareptr::ContInfExt
#define ContInfDlgWdbeRlsStareptrIni DlgWdbeRlsStareptr::ContInfIni
#define ContInfDlgWdbeRlsStareptrLfi DlgWdbeRlsStareptr::ContInfLfi
#define StatAppDlgWdbeRlsStareptr DlgWdbeRlsStareptr::StatApp
#define StatShrDlgWdbeRlsStareptr DlgWdbeRlsStareptr::StatShr
#define StatShrDlgWdbeRlsStareptrDet DlgWdbeRlsStareptr::StatShrDet
#define StatShrDlgWdbeRlsStareptrExt DlgWdbeRlsStareptr::StatShrExt
#define StatShrDlgWdbeRlsStareptrIni DlgWdbeRlsStareptr::StatShrIni
#define StatShrDlgWdbeRlsStareptrLfi DlgWdbeRlsStareptr::StatShrLfi
#define TagDlgWdbeRlsStareptr DlgWdbeRlsStareptr::Tag
#define TagDlgWdbeRlsStareptrDet DlgWdbeRlsStareptr::TagDet
#define TagDlgWdbeRlsStareptrExt DlgWdbeRlsStareptr::TagExt
#define TagDlgWdbeRlsStareptrIni DlgWdbeRlsStareptr::TagIni
#define TagDlgWdbeRlsStareptrLfi DlgWdbeRlsStareptr::TagLfi

#define DpchAppDlgWdbeRlsStareptrData DlgWdbeRlsStareptr::DpchAppData
#define DpchAppDlgWdbeRlsStareptrDo DlgWdbeRlsStareptr::DpchAppDo
#define DpchEngDlgWdbeRlsStareptrData DlgWdbeRlsStareptr::DpchEngData

/**
	* DlgWdbeRlsStareptr
	*/
class DlgWdbeRlsStareptr : public JobWdbe {

public:
	/**
		* VecVDit (full: VecVDlgWdbeRlsStareptrDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint DET = 1;
		static const Sbecore::uint INI = 2;
		static const Sbecore::uint EXT = 3;
		static const Sbecore::uint LFI = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVDo (full: VecVDlgWdbeRlsStareptrDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoDet (full: VecVDlgWdbeRlsStareptrDoDet)
		*/
	class VecVDoDet {

	public:
		static const Sbecore::uint BUTSTACLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoExt (full: VecVDlgWdbeRlsStareptrDoExt)
		*/
	class VecVDoExt {

	public:
		static const Sbecore::uint BUTRUNCLICK = 1;
		static const Sbecore::uint BUTSTOCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoIni (full: VecVDlgWdbeRlsStareptrDoIni)
		*/
	class VecVDoIni {

	public:
		static const Sbecore::uint BUTCLGCLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWdbeRlsStareptrSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRGNF = 2;
		static const Sbecore::uint ALRGAD = 3;
		static const Sbecore::uint ALRGVE = 4;
		static const Sbecore::uint ALRXER = 5;
		static const Sbecore::uint STADONE = 6;
		static const Sbecore::uint UPKIDLE = 7;
		static const Sbecore::uint UNPACK = 8;
		static const Sbecore::uint UPKDONE = 9;
		static const Sbecore::uint CLGIDLE = 10;
		static const Sbecore::uint CLONEGIT = 11;
		static const Sbecore::uint CLGDONE = 12;
		static const Sbecore::uint EXTRACT = 13;
		static const Sbecore::uint PACK = 14;
		static const Sbecore::uint FAIL = 15;
		static const Sbecore::uint DONE = 16;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgWdbeRlsStareptr)
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
	  * ContIacDet (full: ContIacDlgWdbeRlsStareptrDet)
	  */
	class ContIacDet : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFRBUBRT = 1;
		static const Sbecore::uint TXFGRL = 2;

	public:
		ContIacDet(const Sbecore::uint numFRbuBrt = 1, const std::string& TxfGrl = "");

	public:
		Sbecore::uint numFRbuBrt;
		std::string TxfGrl;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIacDet* comp);
		std::set<Sbecore::uint> diff(const ContIacDet* comp);
	};

	/**
	  * ContInf (full: ContInfDlgWdbeRlsStareptr)
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
	  * ContInfExt (full: ContInfDlgWdbeRlsStareptrExt)
	  */
	class ContInfExt : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTPRG = 1;

	public:
		ContInfExt(const std::string& TxtPrg = "");

	public:
		std::string TxtPrg;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfExt* comp);
		std::set<Sbecore::uint> diff(const ContInfExt* comp);
	};

	/**
	  * ContInfIni (full: ContInfDlgWdbeRlsStareptrIni)
	  */
	class ContInfIni : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTPRG = 1;

	public:
		ContInfIni(const std::string& TxtPrg = "");

	public:
		std::string TxtPrg;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfIni* comp);
		std::set<Sbecore::uint> diff(const ContInfIni* comp);
	};

	/**
	  * ContInfLfi (full: ContInfDlgWdbeRlsStareptrLfi)
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
		* StatApp (full: StatAppDlgWdbeRlsStareptr)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const bool initdone = false, const std::string& shortMenu = "");
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdone = false, const std::string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgWdbeRlsStareptr)
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
		* StatShrDet (full: StatShrDlgWdbeRlsStareptrDet)
		*/
	class StatShrDet : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFGRLAVAIL = 1;
		static const Sbecore::uint BUTSTAACTIVE = 2;

	public:
		StatShrDet(const bool TxfGrlAvail = true, const bool ButStaActive = true);

	public:
		bool TxfGrlAvail;
		bool ButStaActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrDet* comp);
		std::set<Sbecore::uint> diff(const StatShrDet* comp);
	};

	/**
		* StatShrExt (full: StatShrDlgWdbeRlsStareptrExt)
		*/
	class StatShrExt : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTRUNACTIVE = 1;
		static const Sbecore::uint BUTSTOACTIVE = 2;

	public:
		StatShrExt(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrExt* comp);
		std::set<Sbecore::uint> diff(const StatShrExt* comp);
	};

	/**
		* StatShrIni (full: StatShrDlgWdbeRlsStareptrIni)
		*/
	class StatShrIni : public Sbecore::Block {

	public:
		static const Sbecore::uint ULDAVAIL = 1;
		static const Sbecore::uint ULDACTIVE = 2;
		static const Sbecore::uint TXTPRGAVAIL = 3;
		static const Sbecore::uint SEP1AVAIL = 4;
		static const Sbecore::uint BUTCLGAVAIL = 5;
		static const Sbecore::uint BUTCLGACTIVE = 6;

	public:
		StatShrIni(const bool UldAvail = true, const bool UldActive = true, const bool TxtPrgAvail = true, const bool Sep1Avail = true, const bool ButClgAvail = true, const bool ButClgActive = true);

	public:
		bool UldAvail;
		bool UldActive;
		bool TxtPrgAvail;
		bool Sep1Avail;
		bool ButClgAvail;
		bool ButClgActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrIni* comp);
		std::set<Sbecore::uint> diff(const StatShrIni* comp);
	};

	/**
		* StatShrLfi (full: StatShrDlgWdbeRlsStareptrLfi)
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
		* Tag (full: TagDlgWdbeRlsStareptr)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagDet (full: TagDlgWdbeRlsStareptrDet)
		*/
	class TagDet {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagExt (full: TagDlgWdbeRlsStareptrExt)
		*/
	class TagExt {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagIni (full: TagDlgWdbeRlsStareptrIni)
		*/
	class TagIni {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagLfi (full: TagDlgWdbeRlsStareptrLfi)
		*/
	class TagLfi {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgWdbeRlsStareptrData)
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
		* DpchAppDo (full: DpchAppDlgWdbeRlsStareptrDo)
		*/
	class DpchAppDo : public DpchAppWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint IXVDODET = 3;
		static const Sbecore::uint IXVDOEXT = 4;
		static const Sbecore::uint IXVDOINI = 5;

	public:
		DpchAppDo();

	public:
		Sbecore::uint ixVDo;
		Sbecore::uint ixVDoDet;
		Sbecore::uint ixVDoExt;
		Sbecore::uint ixVDoIni;

	public:
		std::string getSrefsMask();

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgWdbeRlsStareptrData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTIACDET = 3;
		static const Sbecore::uint CONTINF = 4;
		static const Sbecore::uint CONTINFEXT = 5;
		static const Sbecore::uint CONTINFINI = 6;
		static const Sbecore::uint CONTINFLFI = 7;
		static const Sbecore::uint FEEDFDETRBUBRT = 8;
		static const Sbecore::uint FEEDFDSE = 9;
		static const Sbecore::uint FEEDFSGE = 10;
		static const Sbecore::uint STATAPP = 11;
		static const Sbecore::uint STATSHR = 12;
		static const Sbecore::uint STATSHRDET = 13;
		static const Sbecore::uint STATSHREXT = 14;
		static const Sbecore::uint STATSHRINI = 15;
		static const Sbecore::uint STATSHRLFI = 16;
		static const Sbecore::uint TAG = 17;
		static const Sbecore::uint TAGDET = 18;
		static const Sbecore::uint TAGEXT = 19;
		static const Sbecore::uint TAGINI = 20;
		static const Sbecore::uint TAGLFI = 21;
		static const Sbecore::uint ALL = 22;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContIacDet* contiacdet = NULL, ContInf* continf = NULL, ContInfExt* continfext = NULL, ContInfIni* continfini = NULL, ContInfLfi* continflfi = NULL, Sbecore::Feed* feedFDetRbuBrt = NULL, Sbecore::Feed* feedFDse = NULL, Sbecore::Feed* feedFSge = NULL, StatShr* statshr = NULL, StatShrDet* statshrdet = NULL, StatShrExt* statshrext = NULL, StatShrIni* statshrini = NULL, StatShrLfi* statshrlfi = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContIacDet contiacdet;
		ContInf continf;
		ContInfExt continfext;
		ContInfIni continfini;
		ContInfLfi continflfi;
		Sbecore::Feed feedFDetRbuBrt;
		Sbecore::Feed feedFDse;
		Sbecore::Feed feedFSge;
		StatShr statshr;
		StatShrDet statshrdet;
		StatShrExt statshrext;
		StatShrIni statshrini;
		StatShrLfi statshrlfi;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalButDneActive(DbsWdbe* dbswdbe);
	bool evalLfiDldActive(DbsWdbe* dbswdbe);
	bool evalExtButRunActive(DbsWdbe* dbswdbe);
	bool evalExtButStoActive(DbsWdbe* dbswdbe);
	bool evalIniUldAvail(DbsWdbe* dbswdbe);
	bool evalIniUldActive(DbsWdbe* dbswdbe);
	bool evalIniTxtPrgAvail(DbsWdbe* dbswdbe);
	bool evalIniSep1Avail(DbsWdbe* dbswdbe);
	bool evalIniButClgAvail(DbsWdbe* dbswdbe);
	bool evalIniButClgActive(DbsWdbe* dbswdbe);
	bool evalDetTxfGrlAvail(DbsWdbe* dbswdbe);
	bool evalDetButStaActive(DbsWdbe* dbswdbe);

public:
	DlgWdbeRlsStareptr(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~DlgWdbeRlsStareptr();

public:
	ContIac contiac;
	ContIacDet contiacdet;
	ContInf continf;
	ContInfExt continfext;
	ContInfIni continfini;
	ContInfLfi continflfi;
	StatShr statshr;
	StatShrDet statshrdet;
	StatShrExt statshrext;
	StatShrIni statshrini;
	StatShrLfi statshrlfi;

	Sbecore::Feed feedFMcbAlert;
	Sbecore::Feed feedFDetRbuBrt;
	Sbecore::Feed feedFDse;
	Sbecore::Feed feedFSge;

	Sbecore::uint ixVDit;

	// IP vars.cust --- IBEGIN
	std::string usrsref;

	std::string infilename;

	std::string acttag;
	std::string exptag;

	Sbecore::Mutex mGitprg;
	std::string gitprg;

	std::string logfile;
	// IP vars.cust --- IEND

public:
	// IP cust --- IBEGIN
	static int gitCredCallback(git_cred** cred, const char* url, const char* username_from_url, unsigned int allowed_types, void* payload);

	static int gitFetchCallback(const git_transfer_progress* _stats, void* payload);
	static void gitCheckoutCallback(const char* path, size_t _cur, size_t _tot, void* payload);
	// IP cust --- IEND

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshDet(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshIni(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshExt(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshLfi(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems, const bool unmute = false);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:

	void handleDpchAppWdbeInit(DbsWdbe* dbswdbe, DpchAppWdbeInit* dpchappwdbeinit, DpchEngWdbe** dpcheng);
	void handleDpchAppDataContiac(DbsWdbe* dbswdbe, ContIac* _contiac, DpchEngWdbe** dpcheng);
	void handleDpchAppDataContiacdet(DbsWdbe* dbswdbe, ContIacDet* _contiacdet, DpchEngWdbe** dpcheng);

	void handleDpchAppDoButDneClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

	void handleDpchAppDoDetButStaClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

	void handleDpchAppDoExtButRunClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoExtButStoClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

	void handleDpchAppDoIniButClgClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppWdbeAlert(DbsWdbe* dbswdbe, DpchAppWdbeAlert* dpchappwdbealert, DpchEngWdbe** dpcheng);

	void handleUploadInSgeStadone(DbsWdbe* dbswdbe, const std::string& filename);

	std::string handleDownloadInSgeFail(DbsWdbe* dbswdbe);

	void handleDpchRetWdbePrctreeExtract(DbsWdbe* dbswdbe, DpchRetWdbePrctreeExtract* dpchret);

	void handleTimerInSgeUpkidle(DbsWdbe* dbswdbe, const std::string& sref);
	void handleTimerInSgeClgidle(DbsWdbe* dbswdbe, const std::string& sref);
	void handleTimerWithSrefMonInSgeClonegit(DbsWdbe* dbswdbe);

private:
	void changeStage(DbsWdbe* dbswdbe, Sbecore::uint _ixVSge, DpchEngWdbe** dpcheng = NULL);

public:
	std::string getSquawk(DbsWdbe* dbswdbe);

private:
	Sbecore::uint enterSgeIdle(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeIdle(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeAlrgnf(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeAlrgnf(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeAlrgad(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeAlrgad(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeAlrgve(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeAlrgve(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeAlrxer(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeAlrxer(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeStadone(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeStadone(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeUpkidle(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeUpkidle(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeUnpack(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeUnpack(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeUpkdone(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeUpkdone(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeClgidle(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeClgidle(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeClonegit(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeClonegit(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeClgdone(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeClgdone(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeExtract(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeExtract(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgePack(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgePack(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeFail(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeFail(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeDone(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeDone(DbsWdbe* dbswdbe);

};

#endif
