/**
	* \file DlgWdbeRlsFinreptr.h
	* job handler for job DlgWdbeRlsFinreptr (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef DLGWDBERLSFINREPTR_H
#define DLGWDBERLSFINREPTR_H

// IP include.spec --- INSERT

// IP include.cust --- IBEGIN
#include "git2.h"
// IP include.cust --- IEND

#define VecVDlgWdbeRlsFinreptrDit DlgWdbeRlsFinreptr::VecVDit
#define VecVDlgWdbeRlsFinreptrDo DlgWdbeRlsFinreptr::VecVDo
#define VecVDlgWdbeRlsFinreptrDoFin DlgWdbeRlsFinreptr::VecVDoFin
#define VecVDlgWdbeRlsFinreptrDoRes DlgWdbeRlsFinreptr::VecVDoRes
#define VecVDlgWdbeRlsFinreptrSge DlgWdbeRlsFinreptr::VecVSge

#define ContIacDlgWdbeRlsFinreptr DlgWdbeRlsFinreptr::ContIac
#define ContInfDlgWdbeRlsFinreptr DlgWdbeRlsFinreptr::ContInf
#define ContInfDlgWdbeRlsFinreptrFin DlgWdbeRlsFinreptr::ContInfFin
#define ContInfDlgWdbeRlsFinreptrRes DlgWdbeRlsFinreptr::ContInfRes
#define StatAppDlgWdbeRlsFinreptr DlgWdbeRlsFinreptr::StatApp
#define StatShrDlgWdbeRlsFinreptr DlgWdbeRlsFinreptr::StatShr
#define StatShrDlgWdbeRlsFinreptrFin DlgWdbeRlsFinreptr::StatShrFin
#define StatShrDlgWdbeRlsFinreptrRes DlgWdbeRlsFinreptr::StatShrRes
#define TagDlgWdbeRlsFinreptr DlgWdbeRlsFinreptr::Tag
#define TagDlgWdbeRlsFinreptrFin DlgWdbeRlsFinreptr::TagFin
#define TagDlgWdbeRlsFinreptrRes DlgWdbeRlsFinreptr::TagRes

#define DpchAppDlgWdbeRlsFinreptrData DlgWdbeRlsFinreptr::DpchAppData
#define DpchAppDlgWdbeRlsFinreptrDo DlgWdbeRlsFinreptr::DpchAppDo
#define DpchEngDlgWdbeRlsFinreptrData DlgWdbeRlsFinreptr::DpchEngData

/**
	* DlgWdbeRlsFinreptr
	*/
class DlgWdbeRlsFinreptr : public JobWdbe {

public:
	/**
		* VecVDit (full: VecVDlgWdbeRlsFinreptrDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint FIN = 1;
		static const Sbecore::uint RES = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVDo (full: VecVDlgWdbeRlsFinreptrDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoFin (full: VecVDlgWdbeRlsFinreptrDoFin)
		*/
	class VecVDoFin {

	public:
		static const Sbecore::uint BUTRUNCLICK = 1;
		static const Sbecore::uint BUTSTOCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoRes (full: VecVDlgWdbeRlsFinreptrDoRes)
		*/
	class VecVDoRes {

	public:
		static const Sbecore::uint BUTPSGCLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWdbeRlsFinreptrSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRGNF = 2;
		static const Sbecore::uint ALRGAD = 3;
		static const Sbecore::uint FINIDLE = 4;
		static const Sbecore::uint PACK = 5;
		static const Sbecore::uint COMMIT = 6;
		static const Sbecore::uint FINDONE = 7;
		static const Sbecore::uint PSGIDLE = 8;
		static const Sbecore::uint PUSHGIT = 9;
		static const Sbecore::uint DONE = 10;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgWdbeRlsFinreptr)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFDSE = 1;

	public:
		ContIac(const Sbecore::uint numFDse = 1);

	public:
		Sbecore::uint numFDse;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfDlgWdbeRlsFinreptr)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;

	public:
		ContInf(const Sbecore::uint numFSge = 1);

	public:
		Sbecore::uint numFSge;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * ContInfFin (full: ContInfDlgWdbeRlsFinreptrFin)
	  */
	class ContInfFin : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTPRG = 1;

	public:
		ContInfFin(const std::string& TxtPrg = "");

	public:
		std::string TxtPrg;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfFin* comp);
		std::set<Sbecore::uint> diff(const ContInfFin* comp);
	};

	/**
	  * ContInfRes (full: ContInfDlgWdbeRlsFinreptrRes)
	  */
	class ContInfRes : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLD = 1;
		static const Sbecore::uint TXTPRG = 2;

	public:
		ContInfRes(const std::string& Dld = "file", const std::string& TxtPrg = "");

	public:
		std::string Dld;
		std::string TxtPrg;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfRes* comp);
		std::set<Sbecore::uint> diff(const ContInfRes* comp);
	};

	/**
		* StatApp (full: StatAppDlgWdbeRlsFinreptr)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdone = false, const std::string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgWdbeRlsFinreptr)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTDNEACTIVE = 1;

	public:
		StatShr(const bool ButDneActive = true);

	public:
		bool ButDneActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* StatShrFin (full: StatShrDlgWdbeRlsFinreptrFin)
		*/
	class StatShrFin : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTRUNACTIVE = 1;
		static const Sbecore::uint BUTSTOACTIVE = 2;

	public:
		StatShrFin(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrFin* comp);
		std::set<Sbecore::uint> diff(const StatShrFin* comp);
	};

	/**
		* StatShrRes (full: StatShrDlgWdbeRlsFinreptrRes)
		*/
	class StatShrRes : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLDAVAIL = 1;
		static const Sbecore::uint DLDACTIVE = 2;
		static const Sbecore::uint TXTPRGAVAIL = 3;
		static const Sbecore::uint SEP1AVAIL = 4;
		static const Sbecore::uint BUTPSGAVAIL = 5;
		static const Sbecore::uint BUTPSGACTIVE = 6;

	public:
		StatShrRes(const bool DldAvail = true, const bool DldActive = true, const bool TxtPrgAvail = true, const bool Sep1Avail = true, const bool ButPsgAvail = true, const bool ButPsgActive = true);

	public:
		bool DldAvail;
		bool DldActive;
		bool TxtPrgAvail;
		bool Sep1Avail;
		bool ButPsgAvail;
		bool ButPsgActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrRes* comp);
		std::set<Sbecore::uint> diff(const StatShrRes* comp);
	};

	/**
		* Tag (full: TagDlgWdbeRlsFinreptr)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagFin (full: TagDlgWdbeRlsFinreptrFin)
		*/
	class TagFin {

	public:
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagRes (full: TagDlgWdbeRlsFinreptrRes)
		*/
	class TagRes {

	public:
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgWdbeRlsFinreptrData)
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

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppDlgWdbeRlsFinreptrDo)
		*/
	class DpchAppDo : public DpchAppWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint IXVDOFIN = 3;
		static const Sbecore::uint IXVDORES = 4;

	public:
		DpchAppDo();

	public:
		Sbecore::uint ixVDo;
		Sbecore::uint ixVDoFin;
		Sbecore::uint ixVDoRes;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgWdbeRlsFinreptrData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint CONTINFFIN = 4;
		static const Sbecore::uint CONTINFRES = 5;
		static const Sbecore::uint FEEDFDSE = 6;
		static const Sbecore::uint FEEDFSGE = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint STATSHRFIN = 10;
		static const Sbecore::uint STATSHRRES = 11;
		static const Sbecore::uint TAG = 12;
		static const Sbecore::uint TAGFIN = 13;
		static const Sbecore::uint TAGRES = 14;
		static const Sbecore::uint ALL = 15;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, ContInfFin* continffin = NULL, ContInfRes* continfres = NULL, Sbecore::Xmlio::Feed* feedFDse = NULL, Sbecore::Xmlio::Feed* feedFSge = NULL, StatShr* statshr = NULL, StatShrFin* statshrfin = NULL, StatShrRes* statshrres = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		ContInfFin continffin;
		ContInfRes continfres;
		Sbecore::Xmlio::Feed feedFDse;
		Sbecore::Xmlio::Feed feedFSge;
		StatShr statshr;
		StatShrFin statshrfin;
		StatShrRes statshrres;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalButDneActive(DbsWdbe* dbswdbe);
	bool evalResDldAvail(DbsWdbe* dbswdbe);
	bool evalResDldActive(DbsWdbe* dbswdbe);
	bool evalResTxtPrgAvail(DbsWdbe* dbswdbe);
	bool evalResSep1Avail(DbsWdbe* dbswdbe);
	bool evalResButPsgAvail(DbsWdbe* dbswdbe);
	bool evalResButPsgActive(DbsWdbe* dbswdbe);
	bool evalFinButRunActive(DbsWdbe* dbswdbe);
	bool evalFinButStoActive(DbsWdbe* dbswdbe);

public:
	DlgWdbeRlsFinreptr(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~DlgWdbeRlsFinreptr();

public:
	ContIac contiac;
	ContInf continf;
	ContInfFin continffin;
	ContInfRes continfres;
	StatShr statshr;
	StatShrFin statshrfin;
	StatShrRes statshrres;

	Sbecore::Xmlio::Feed feedFMcbAlert;
	Sbecore::Xmlio::Feed feedFDse;
	Sbecore::Xmlio::Feed feedFSge;

	Sbecore::uint ixVDit;

	// IP vars.cust --- IBEGIN
	std::string usrsref;

	std::string vertag;

	Sbecore::Mutex mGitprg;
	std::string gitprg;

	std::string tgzfile;
	// IP vars.cust --- IEND

public:
	// IP cust --- IBEGIN
	static int gitCredCallback(git_cred** cred, const char* url, const char* username_from_url, unsigned int allowed_types, void* payload);

	static int gitIndexUpdateCallback(const char* path, const char* matched_pathspec, void* payload);
	static int gitIndexAddCallback(const char* path, const char* matched_pathspec, void* payload);

	static int gitPackCallback(int stage, unsigned int current, unsigned int total, void* payload);
	static int gitPushCallback(unsigned int current, unsigned int total, size_t bytes, void *payload);
	// IP cust --- IEND

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshFin(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshRes(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems, const bool unmute = false);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:

	void handleDpchAppWdbeInit(DbsWdbe* dbswdbe, DpchAppWdbeInit* dpchappwdbeinit, DpchEngWdbe** dpcheng);
	void handleDpchAppDataContiac(DbsWdbe* dbswdbe, ContIac* _contiac, DpchEngWdbe** dpcheng);

	void handleDpchAppDoButDneClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

	void handleDpchAppDoFinButRunClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoFinButStoClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

	void handleDpchAppDoResButPsgClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppWdbeAlert(DbsWdbe* dbswdbe, DpchAppWdbeAlert* dpchappwdbealert, DpchEngWdbe** dpcheng);

	std::string handleDownloadInSgeDone(DbsWdbe* dbswdbe);

	void handleTimerWithSrefMonInSgePushgit(DbsWdbe* dbswdbe);
	void handleTimerInSgePsgidle(DbsWdbe* dbswdbe, const std::string& sref);
	void handleTimerInSgeFinidle(DbsWdbe* dbswdbe, const std::string& sref);

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
	Sbecore::uint enterSgeFinidle(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeFinidle(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgePack(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgePack(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeCommit(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeCommit(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeFindone(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeFindone(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgePsgidle(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgePsgidle(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgePushgit(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgePushgit(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeDone(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeDone(DbsWdbe* dbswdbe);

};

#endif
