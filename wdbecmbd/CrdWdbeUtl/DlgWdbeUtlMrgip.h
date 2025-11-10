/**
	* \file DlgWdbeUtlMrgip.h
	* job handler for job DlgWdbeUtlMrgip (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef DLGWDBEUTLMRGIP_H
#define DLGWDBEUTLMRGIP_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVDlgWdbeUtlMrgipDit DlgWdbeUtlMrgip::VecVDit
#define VecVDlgWdbeUtlMrgipDo DlgWdbeUtlMrgip::VecVDo
#define VecVDlgWdbeUtlMrgipDoMrg DlgWdbeUtlMrgip::VecVDoMrg
#define VecVDlgWdbeUtlMrgipSge DlgWdbeUtlMrgip::VecVSge

#define ContIacDlgWdbeUtlMrgip DlgWdbeUtlMrgip::ContIac
#define ContInfDlgWdbeUtlMrgip DlgWdbeUtlMrgip::ContInf
#define ContInfDlgWdbeUtlMrgipLfi DlgWdbeUtlMrgip::ContInfLfi
#define ContInfDlgWdbeUtlMrgipMrg DlgWdbeUtlMrgip::ContInfMrg
#define ContInfDlgWdbeUtlMrgipRes DlgWdbeUtlMrgip::ContInfRes
#define StatAppDlgWdbeUtlMrgip DlgWdbeUtlMrgip::StatApp
#define StatShrDlgWdbeUtlMrgip DlgWdbeUtlMrgip::StatShr
#define StatShrDlgWdbeUtlMrgipLfi DlgWdbeUtlMrgip::StatShrLfi
#define StatShrDlgWdbeUtlMrgipMrg DlgWdbeUtlMrgip::StatShrMrg
#define StatShrDlgWdbeUtlMrgipRes DlgWdbeUtlMrgip::StatShrRes
#define StatShrDlgWdbeUtlMrgipSrc DlgWdbeUtlMrgip::StatShrSrc
#define StatShrDlgWdbeUtlMrgipTrg DlgWdbeUtlMrgip::StatShrTrg
#define TagDlgWdbeUtlMrgip DlgWdbeUtlMrgip::Tag
#define TagDlgWdbeUtlMrgipLfi DlgWdbeUtlMrgip::TagLfi
#define TagDlgWdbeUtlMrgipMrg DlgWdbeUtlMrgip::TagMrg
#define TagDlgWdbeUtlMrgipRes DlgWdbeUtlMrgip::TagRes
#define TagDlgWdbeUtlMrgipSrc DlgWdbeUtlMrgip::TagSrc
#define TagDlgWdbeUtlMrgipTrg DlgWdbeUtlMrgip::TagTrg

#define DpchAppDlgWdbeUtlMrgipData DlgWdbeUtlMrgip::DpchAppData
#define DpchAppDlgWdbeUtlMrgipDo DlgWdbeUtlMrgip::DpchAppDo
#define DpchEngDlgWdbeUtlMrgipData DlgWdbeUtlMrgip::DpchEngData

/**
	* DlgWdbeUtlMrgip
	*/
class DlgWdbeUtlMrgip : public JobWdbe {

public:
	/**
		* VecVDit (full: VecVDlgWdbeUtlMrgipDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint SRC = 1;
		static const Sbecore::uint TRG = 2;
		static const Sbecore::uint MRG = 3;
		static const Sbecore::uint LFI = 4;
		static const Sbecore::uint RES = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVDo (full: VecVDlgWdbeUtlMrgipDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoMrg (full: VecVDlgWdbeUtlMrgipDoMrg)
		*/
	class VecVDoMrg {

	public:
		static const Sbecore::uint BUTRUNCLICK = 1;
		static const Sbecore::uint BUTSTOCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWdbeUtlMrgipSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRMER = 2;
		static const Sbecore::uint SUPIDLE = 3;
		static const Sbecore::uint SRCUNPACK = 4;
		static const Sbecore::uint SUPDONE = 5;
		static const Sbecore::uint SULDONE = 6;
		static const Sbecore::uint TUPIDLE = 7;
		static const Sbecore::uint TRGUNPACK = 8;
		static const Sbecore::uint TUPDONE = 9;
		static const Sbecore::uint TULDONE = 10;
		static const Sbecore::uint MERGE = 11;
		static const Sbecore::uint PACK = 12;
		static const Sbecore::uint FAIL = 13;
		static const Sbecore::uint DONE = 14;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgWdbeUtlMrgip)
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
	  * ContInf (full: ContInfDlgWdbeUtlMrgip)
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
	  * ContInfLfi (full: ContInfDlgWdbeUtlMrgipLfi)
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
	  * ContInfMrg (full: ContInfDlgWdbeUtlMrgipMrg)
	  */
	class ContInfMrg : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTPRG = 1;

	public:
		ContInfMrg(const std::string& TxtPrg = "");

	public:
		std::string TxtPrg;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfMrg* comp);
		std::set<Sbecore::uint> diff(const ContInfMrg* comp);
	};

	/**
	  * ContInfRes (full: ContInfDlgWdbeUtlMrgipRes)
	  */
	class ContInfRes : public Sbecore::Block {

	public:
		static const Sbecore::uint DLD = 1;

	public:
		ContInfRes(const std::string& Dld = "file");

	public:
		std::string Dld;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfRes* comp);
		std::set<Sbecore::uint> diff(const ContInfRes* comp);
	};

	/**
		* StatApp (full: StatAppDlgWdbeUtlMrgip)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const bool initdone = false, const std::string& shortMenu = "");
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdone = false, const std::string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgWdbeUtlMrgip)
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
		* StatShrLfi (full: StatShrDlgWdbeUtlMrgipLfi)
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
		* StatShrMrg (full: StatShrDlgWdbeUtlMrgipMrg)
		*/
	class StatShrMrg : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTRUNACTIVE = 1;
		static const Sbecore::uint BUTSTOACTIVE = 2;

	public:
		StatShrMrg(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrMrg* comp);
		std::set<Sbecore::uint> diff(const StatShrMrg* comp);
	};

	/**
		* StatShrRes (full: StatShrDlgWdbeUtlMrgipRes)
		*/
	class StatShrRes : public Sbecore::Block {

	public:
		static const Sbecore::uint DLDACTIVE = 1;

	public:
		StatShrRes(const bool DldActive = true);

	public:
		bool DldActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrRes* comp);
		std::set<Sbecore::uint> diff(const StatShrRes* comp);
	};

	/**
		* StatShrSrc (full: StatShrDlgWdbeUtlMrgipSrc)
		*/
	class StatShrSrc : public Sbecore::Block {

	public:
		static const Sbecore::uint ULDACTIVE = 1;

	public:
		StatShrSrc(const bool UldActive = true);

	public:
		bool UldActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrSrc* comp);
		std::set<Sbecore::uint> diff(const StatShrSrc* comp);
	};

	/**
		* StatShrTrg (full: StatShrDlgWdbeUtlMrgipTrg)
		*/
	class StatShrTrg : public Sbecore::Block {

	public:
		static const Sbecore::uint ULDACTIVE = 1;

	public:
		StatShrTrg(const bool UldActive = true);

	public:
		bool UldActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrTrg* comp);
		std::set<Sbecore::uint> diff(const StatShrTrg* comp);
	};

	/**
		* Tag (full: TagDlgWdbeUtlMrgip)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagLfi (full: TagDlgWdbeUtlMrgipLfi)
		*/
	class TagLfi {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagMrg (full: TagDlgWdbeUtlMrgipMrg)
		*/
	class TagMrg {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagRes (full: TagDlgWdbeUtlMrgipRes)
		*/
	class TagRes {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagSrc (full: TagDlgWdbeUtlMrgipSrc)
		*/
	class TagSrc {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagTrg (full: TagDlgWdbeUtlMrgipTrg)
		*/
	class TagTrg {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgWdbeUtlMrgipData)
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
		* DpchAppDo (full: DpchAppDlgWdbeUtlMrgipDo)
		*/
	class DpchAppDo : public DpchAppWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint IXVDOMRG = 3;

	public:
		DpchAppDo();

	public:
		Sbecore::uint ixVDo;
		Sbecore::uint ixVDoMrg;

	public:
		std::string getSrefsMask();

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgWdbeUtlMrgipData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint CONTINFLFI = 4;
		static const Sbecore::uint CONTINFMRG = 5;
		static const Sbecore::uint CONTINFRES = 6;
		static const Sbecore::uint FEEDFDSE = 7;
		static const Sbecore::uint FEEDFSGE = 8;
		static const Sbecore::uint STATAPP = 9;
		static const Sbecore::uint STATSHR = 10;
		static const Sbecore::uint STATSHRLFI = 11;
		static const Sbecore::uint STATSHRMRG = 12;
		static const Sbecore::uint STATSHRRES = 13;
		static const Sbecore::uint STATSHRSRC = 14;
		static const Sbecore::uint STATSHRTRG = 15;
		static const Sbecore::uint TAG = 16;
		static const Sbecore::uint TAGLFI = 17;
		static const Sbecore::uint TAGMRG = 18;
		static const Sbecore::uint TAGRES = 19;
		static const Sbecore::uint TAGSRC = 20;
		static const Sbecore::uint TAGTRG = 21;
		static const Sbecore::uint ALL = 22;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, ContInfLfi* continflfi = NULL, ContInfMrg* continfmrg = NULL, ContInfRes* continfres = NULL, Sbecore::Feed* feedFDse = NULL, Sbecore::Feed* feedFSge = NULL, StatShr* statshr = NULL, StatShrLfi* statshrlfi = NULL, StatShrMrg* statshrmrg = NULL, StatShrRes* statshrres = NULL, StatShrSrc* statshrsrc = NULL, StatShrTrg* statshrtrg = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		ContInfLfi continflfi;
		ContInfMrg continfmrg;
		ContInfRes continfres;
		Sbecore::Feed feedFDse;
		Sbecore::Feed feedFSge;
		StatShr statshr;
		StatShrLfi statshrlfi;
		StatShrMrg statshrmrg;
		StatShrRes statshrres;
		StatShrSrc statshrsrc;
		StatShrTrg statshrtrg;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalSrcUldActive(DbsWdbe* dbswdbe);
	bool evalTrgUldActive(DbsWdbe* dbswdbe);
	bool evalMrgButRunActive(DbsWdbe* dbswdbe);
	bool evalMrgButStoActive(DbsWdbe* dbswdbe);
	bool evalLfiDldActive(DbsWdbe* dbswdbe);
	bool evalResDldActive(DbsWdbe* dbswdbe);
	bool evalButDneActive(DbsWdbe* dbswdbe);

public:
	DlgWdbeUtlMrgip(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~DlgWdbeUtlMrgip();

public:
	ContIac contiac;
	ContInf continf;
	ContInfLfi continflfi;
	ContInfMrg continfmrg;
	ContInfRes continfres;
	StatShr statshr;
	StatShrLfi statshrlfi;
	StatShrMrg statshrmrg;
	StatShrRes statshrres;
	StatShrSrc statshrsrc;
	StatShrTrg statshrtrg;

	Sbecore::Feed feedFMcbAlert;
	Sbecore::Feed feedFDse;
	Sbecore::Feed feedFSge;

	Sbecore::uint ixVDit;

	// IP vars.cust --- IBEGIN
	std::string infilename;
	std::string outfilename;

	std::string infolder;
	std::string infile;
	std::string outfolder;
	std::string outfile;

	std::string logfile;
	// IP vars.cust --- IEND

public:
	// IP cust --- INSERT

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshSrc(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshTrg(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshMrg(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshLfi(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshRes(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems, const bool unmute = false);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:

	void handleDpchAppWdbeInit(DbsWdbe* dbswdbe, DpchAppWdbeInit* dpchappwdbeinit, DpchEngWdbe** dpcheng);
	void handleDpchAppDataContiac(DbsWdbe* dbswdbe, ContIac* _contiac, DpchEngWdbe** dpcheng);

	void handleDpchAppDoButDneClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

	void handleDpchAppDoMrgButRunClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoMrgButStoClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppWdbeAlert(DbsWdbe* dbswdbe, DpchAppWdbeAlert* dpchappwdbealert, DpchEngWdbe** dpcheng);

	void handleUploadInSgeIdle(DbsWdbe* dbswdbe, const std::string& filename);
	void handleUploadInSgeSupdone(DbsWdbe* dbswdbe, const std::string& filename);
	void handleUploadInSgeSuldone(DbsWdbe* dbswdbe, const std::string& filename);

	std::string handleDownloadInSgeFail(DbsWdbe* dbswdbe);
	std::string handleDownloadInSgeDone(DbsWdbe* dbswdbe);

	void handleDpchRetWdbePrctreeMerge(DbsWdbe* dbswdbe, DpchRetWdbePrctreeMerge* dpchret);

	void handleTimerInSgeSupidle(DbsWdbe* dbswdbe, const std::string& sref);
	void handleTimerInSgeTupidle(DbsWdbe* dbswdbe, const std::string& sref);

private:
	void changeStage(DbsWdbe* dbswdbe, Sbecore::uint _ixVSge, DpchEngWdbe** dpcheng = NULL);

public:
	std::string getSquawk(DbsWdbe* dbswdbe);

private:
	Sbecore::uint enterSgeIdle(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeIdle(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeAlrmer(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeAlrmer(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeSupidle(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeSupidle(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeSrcunpack(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeSrcunpack(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeSupdone(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeSupdone(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeSuldone(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeSuldone(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeTupidle(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeTupidle(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeTrgunpack(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeTrgunpack(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeTupdone(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeTupdone(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeTuldone(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeTuldone(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeMerge(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeMerge(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgePack(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgePack(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeFail(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeFail(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeDone(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeDone(DbsWdbe* dbswdbe);

};

#endif
