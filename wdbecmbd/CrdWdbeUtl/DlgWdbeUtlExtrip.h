/**
	* \file DlgWdbeUtlExtrip.h
	* job handler for job DlgWdbeUtlExtrip (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef DLGWDBEUTLEXTRIP_H
#define DLGWDBEUTLEXTRIP_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVDlgWdbeUtlExtripDit DlgWdbeUtlExtrip::VecVDit
#define VecVDlgWdbeUtlExtripDo DlgWdbeUtlExtrip::VecVDo
#define VecVDlgWdbeUtlExtripDoExt DlgWdbeUtlExtrip::VecVDoExt
#define VecVDlgWdbeUtlExtripSge DlgWdbeUtlExtrip::VecVSge

#define ContIacDlgWdbeUtlExtrip DlgWdbeUtlExtrip::ContIac
#define ContInfDlgWdbeUtlExtrip DlgWdbeUtlExtrip::ContInf
#define ContInfDlgWdbeUtlExtripExt DlgWdbeUtlExtrip::ContInfExt
#define ContInfDlgWdbeUtlExtripLfi DlgWdbeUtlExtrip::ContInfLfi
#define ContInfDlgWdbeUtlExtripRes DlgWdbeUtlExtrip::ContInfRes
#define StatAppDlgWdbeUtlExtrip DlgWdbeUtlExtrip::StatApp
#define StatShrDlgWdbeUtlExtrip DlgWdbeUtlExtrip::StatShr
#define StatShrDlgWdbeUtlExtripExt DlgWdbeUtlExtrip::StatShrExt
#define StatShrDlgWdbeUtlExtripLfi DlgWdbeUtlExtrip::StatShrLfi
#define StatShrDlgWdbeUtlExtripRes DlgWdbeUtlExtrip::StatShrRes
#define StatShrDlgWdbeUtlExtripSrc DlgWdbeUtlExtrip::StatShrSrc
#define TagDlgWdbeUtlExtrip DlgWdbeUtlExtrip::Tag
#define TagDlgWdbeUtlExtripExt DlgWdbeUtlExtrip::TagExt
#define TagDlgWdbeUtlExtripLfi DlgWdbeUtlExtrip::TagLfi
#define TagDlgWdbeUtlExtripRes DlgWdbeUtlExtrip::TagRes
#define TagDlgWdbeUtlExtripSrc DlgWdbeUtlExtrip::TagSrc

#define DpchAppDlgWdbeUtlExtripData DlgWdbeUtlExtrip::DpchAppData
#define DpchAppDlgWdbeUtlExtripDo DlgWdbeUtlExtrip::DpchAppDo
#define DpchEngDlgWdbeUtlExtripData DlgWdbeUtlExtrip::DpchEngData

/**
	* DlgWdbeUtlExtrip
	*/
class DlgWdbeUtlExtrip : public JobWdbe {

public:
	/**
		* VecVDit (full: VecVDlgWdbeUtlExtripDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint SRC = 1;
		static const Sbecore::uint EXT = 2;
		static const Sbecore::uint LFI = 3;
		static const Sbecore::uint RES = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVDo (full: VecVDlgWdbeUtlExtripDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoExt (full: VecVDlgWdbeUtlExtripDoExt)
		*/
	class VecVDoExt {

	public:
		static const Sbecore::uint BUTRUNCLICK = 1;
		static const Sbecore::uint BUTSTOCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWdbeUtlExtripSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRXER = 2;
		static const Sbecore::uint UPKIDLE = 3;
		static const Sbecore::uint UNPACK = 4;
		static const Sbecore::uint UPKDONE = 5;
		static const Sbecore::uint ULDDONE = 6;
		static const Sbecore::uint EXTRACT = 7;
		static const Sbecore::uint PACK = 8;
		static const Sbecore::uint FAIL = 9;
		static const Sbecore::uint DONE = 10;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgWdbeUtlExtrip)
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
	  * ContInf (full: ContInfDlgWdbeUtlExtrip)
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
	  * ContInfExt (full: ContInfDlgWdbeUtlExtripExt)
	  */
	class ContInfExt : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTPRG = 1;

	public:
		ContInfExt(const std::string& TxtPrg = "");

	public:
		std::string TxtPrg;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfExt* comp);
		std::set<Sbecore::uint> diff(const ContInfExt* comp);
	};

	/**
	  * ContInfLfi (full: ContInfDlgWdbeUtlExtripLfi)
	  */
	class ContInfLfi : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLD = 1;

	public:
		ContInfLfi(const std::string& Dld = "file");

	public:
		std::string Dld;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfLfi* comp);
		std::set<Sbecore::uint> diff(const ContInfLfi* comp);
	};

	/**
	  * ContInfRes (full: ContInfDlgWdbeUtlExtripRes)
	  */
	class ContInfRes : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLD = 1;

	public:
		ContInfRes(const std::string& Dld = "file");

	public:
		std::string Dld;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfRes* comp);
		std::set<Sbecore::uint> diff(const ContInfRes* comp);
	};

	/**
		* StatApp (full: StatAppDlgWdbeUtlExtrip)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdone = false, const std::string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgWdbeUtlExtrip)
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
		* StatShrExt (full: StatShrDlgWdbeUtlExtripExt)
		*/
	class StatShrExt : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTRUNACTIVE = 1;
		static const Sbecore::uint BUTSTOACTIVE = 2;

	public:
		StatShrExt(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrExt* comp);
		std::set<Sbecore::uint> diff(const StatShrExt* comp);
	};

	/**
		* StatShrLfi (full: StatShrDlgWdbeUtlExtripLfi)
		*/
	class StatShrLfi : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLDACTIVE = 1;

	public:
		StatShrLfi(const bool DldActive = true);

	public:
		bool DldActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrLfi* comp);
		std::set<Sbecore::uint> diff(const StatShrLfi* comp);
	};

	/**
		* StatShrRes (full: StatShrDlgWdbeUtlExtripRes)
		*/
	class StatShrRes : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLDACTIVE = 1;

	public:
		StatShrRes(const bool DldActive = true);

	public:
		bool DldActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrRes* comp);
		std::set<Sbecore::uint> diff(const StatShrRes* comp);
	};

	/**
		* StatShrSrc (full: StatShrDlgWdbeUtlExtripSrc)
		*/
	class StatShrSrc : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint ULDACTIVE = 1;

	public:
		StatShrSrc(const bool UldActive = true);

	public:
		bool UldActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrSrc* comp);
		std::set<Sbecore::uint> diff(const StatShrSrc* comp);
	};

	/**
		* Tag (full: TagDlgWdbeUtlExtrip)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagExt (full: TagDlgWdbeUtlExtripExt)
		*/
	class TagExt {

	public:
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagLfi (full: TagDlgWdbeUtlExtripLfi)
		*/
	class TagLfi {

	public:
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagRes (full: TagDlgWdbeUtlExtripRes)
		*/
	class TagRes {

	public:
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagSrc (full: TagDlgWdbeUtlExtripSrc)
		*/
	class TagSrc {

	public:
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgWdbeUtlExtripData)
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
		* DpchAppDo (full: DpchAppDlgWdbeUtlExtripDo)
		*/
	class DpchAppDo : public DpchAppWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint IXVDOEXT = 3;

	public:
		DpchAppDo();

	public:
		Sbecore::uint ixVDo;
		Sbecore::uint ixVDoExt;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgWdbeUtlExtripData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint CONTINFEXT = 4;
		static const Sbecore::uint CONTINFLFI = 5;
		static const Sbecore::uint CONTINFRES = 6;
		static const Sbecore::uint FEEDFDSE = 7;
		static const Sbecore::uint FEEDFSGE = 8;
		static const Sbecore::uint STATAPP = 9;
		static const Sbecore::uint STATSHR = 10;
		static const Sbecore::uint STATSHREXT = 11;
		static const Sbecore::uint STATSHRLFI = 12;
		static const Sbecore::uint STATSHRRES = 13;
		static const Sbecore::uint STATSHRSRC = 14;
		static const Sbecore::uint TAG = 15;
		static const Sbecore::uint TAGEXT = 16;
		static const Sbecore::uint TAGLFI = 17;
		static const Sbecore::uint TAGRES = 18;
		static const Sbecore::uint TAGSRC = 19;
		static const Sbecore::uint ALL = 20;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, ContInfExt* continfext = NULL, ContInfLfi* continflfi = NULL, ContInfRes* continfres = NULL, Sbecore::Xmlio::Feed* feedFDse = NULL, Sbecore::Xmlio::Feed* feedFSge = NULL, StatShr* statshr = NULL, StatShrExt* statshrext = NULL, StatShrLfi* statshrlfi = NULL, StatShrRes* statshrres = NULL, StatShrSrc* statshrsrc = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		ContInfExt continfext;
		ContInfLfi continflfi;
		ContInfRes continfres;
		Sbecore::Xmlio::Feed feedFDse;
		Sbecore::Xmlio::Feed feedFSge;
		StatShr statshr;
		StatShrExt statshrext;
		StatShrLfi statshrlfi;
		StatShrRes statshrres;
		StatShrSrc statshrsrc;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalSrcUldActive(DbsWdbe* dbswdbe);
	bool evalExtButRunActive(DbsWdbe* dbswdbe);
	bool evalExtButStoActive(DbsWdbe* dbswdbe);
	bool evalLfiDldActive(DbsWdbe* dbswdbe);
	bool evalResDldActive(DbsWdbe* dbswdbe);
	bool evalButDneActive(DbsWdbe* dbswdbe);

public:
	DlgWdbeUtlExtrip(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~DlgWdbeUtlExtrip();

public:
	ContIac contiac;
	ContInf continf;
	ContInfExt continfext;
	ContInfLfi continflfi;
	ContInfRes continfres;
	StatShr statshr;
	StatShrExt statshrext;
	StatShrLfi statshrlfi;
	StatShrRes statshrres;
	StatShrSrc statshrsrc;

	Sbecore::Xmlio::Feed feedFMcbAlert;
	Sbecore::Xmlio::Feed feedFDse;
	Sbecore::Xmlio::Feed feedFSge;

	Sbecore::uint ixVDit;

	// IP vars.cust --- IBEGIN
	std::string infilename;

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
	void refreshExt(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
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

	void handleDpchAppDoExtButRunClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoExtButStoClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppWdbeAlert(DbsWdbe* dbswdbe, DpchAppWdbeAlert* dpchappwdbealert, DpchEngWdbe** dpcheng);

	void handleUploadInSgeIdle(DbsWdbe* dbswdbe, const std::string& filename);

	std::string handleDownloadInSgeFail(DbsWdbe* dbswdbe);
	std::string handleDownloadInSgeDone(DbsWdbe* dbswdbe);

	void handleDpchRetWdbePrctreeExtract(DbsWdbe* dbswdbe, DpchRetWdbePrctreeExtract* dpchret);

	void handleTimerInSgeUpkidle(DbsWdbe* dbswdbe, const std::string& sref);

private:
	void changeStage(DbsWdbe* dbswdbe, Sbecore::uint _ixVSge, DpchEngWdbe** dpcheng = NULL);

public:
	std::string getSquawk(DbsWdbe* dbswdbe);

private:
	Sbecore::uint enterSgeIdle(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeIdle(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeAlrxer(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeAlrxer(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeUpkidle(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeUpkidle(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeUnpack(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeUnpack(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeUpkdone(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeUpkdone(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeUlddone(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeUlddone(DbsWdbe* dbswdbe);
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
