/**
	* \file DlgWdbeCvrWrite.h
	* job handler for job DlgWdbeCvrWrite (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef DLGWDBECVRWRITE_H
#define DLGWDBECVRWRITE_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVDlgWdbeCvrWriteDit DlgWdbeCvrWrite::VecVDit
#define VecVDlgWdbeCvrWriteDo DlgWdbeCvrWrite::VecVDo
#define VecVDlgWdbeCvrWriteDoWrc DlgWdbeCvrWrite::VecVDoWrc
#define VecVDlgWdbeCvrWriteSge DlgWdbeCvrWrite::VecVSge

#define ContIacDlgWdbeCvrWrite DlgWdbeCvrWrite::ContIac
#define ContInfDlgWdbeCvrWrite DlgWdbeCvrWrite::ContInf
#define ContInfDlgWdbeCvrWriteFia DlgWdbeCvrWrite::ContInfFia
#define ContInfDlgWdbeCvrWriteWrc DlgWdbeCvrWrite::ContInfWrc
#define StatAppDlgWdbeCvrWrite DlgWdbeCvrWrite::StatApp
#define StatShrDlgWdbeCvrWrite DlgWdbeCvrWrite::StatShr
#define StatShrDlgWdbeCvrWriteCuc DlgWdbeCvrWrite::StatShrCuc
#define StatShrDlgWdbeCvrWriteFia DlgWdbeCvrWrite::StatShrFia
#define StatShrDlgWdbeCvrWriteWrc DlgWdbeCvrWrite::StatShrWrc
#define TagDlgWdbeCvrWrite DlgWdbeCvrWrite::Tag
#define TagDlgWdbeCvrWriteCuc DlgWdbeCvrWrite::TagCuc
#define TagDlgWdbeCvrWriteFia DlgWdbeCvrWrite::TagFia
#define TagDlgWdbeCvrWriteWrc DlgWdbeCvrWrite::TagWrc

#define DpchAppDlgWdbeCvrWriteData DlgWdbeCvrWrite::DpchAppData
#define DpchAppDlgWdbeCvrWriteDo DlgWdbeCvrWrite::DpchAppDo
#define DpchEngDlgWdbeCvrWriteData DlgWdbeCvrWrite::DpchEngData

/**
	* DlgWdbeCvrWrite
	*/
class DlgWdbeCvrWrite : public JobWdbe {

public:
	/**
		* VecVDit (full: VecVDlgWdbeCvrWriteDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint CUC = 1;
		static const Sbecore::uint WRC = 2;
		static const Sbecore::uint FIA = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVDo (full: VecVDlgWdbeCvrWriteDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoWrc (full: VecVDlgWdbeCvrWriteDoWrc)
		*/
	class VecVDoWrc {

	public:
		static const Sbecore::uint BUTRUNCLICK = 1;
		static const Sbecore::uint BUTSTOCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWdbeCvrWriteSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint UPKIDLE = 2;
		static const Sbecore::uint UNPACK = 3;
		static const Sbecore::uint UPKDONE = 4;
		static const Sbecore::uint CREIDLE = 5;
		static const Sbecore::uint CREATE = 6;
		static const Sbecore::uint WRITE = 7;
		static const Sbecore::uint MRG = 8;
		static const Sbecore::uint MRGCUST = 9;
		static const Sbecore::uint PACK = 10;
		static const Sbecore::uint DONE = 11;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgWdbeCvrWrite)
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
	  * ContInf (full: ContInfDlgWdbeCvrWrite)
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
	  * ContInfFia (full: ContInfDlgWdbeCvrWriteFia)
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
	  * ContInfWrc (full: ContInfDlgWdbeCvrWriteWrc)
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
		* StatApp (full: StatAppDlgWdbeCvrWrite)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const bool initdone = false, const std::string& shortMenu = "");
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdone = false, const std::string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgWdbeCvrWrite)
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
		* StatShrCuc (full: StatShrDlgWdbeCvrWriteCuc)
		*/
	class StatShrCuc : public Sbecore::Block {

	public:
		static const Sbecore::uint ULDACTIVE = 1;

	public:
		StatShrCuc(const bool UldActive = true);

	public:
		bool UldActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrCuc* comp);
		std::set<Sbecore::uint> diff(const StatShrCuc* comp);
	};

	/**
		* StatShrFia (full: StatShrDlgWdbeCvrWriteFia)
		*/
	class StatShrFia : public Sbecore::Block {

	public:
		static const Sbecore::uint DLDACTIVE = 1;

	public:
		StatShrFia(const bool DldActive = true);

	public:
		bool DldActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrFia* comp);
		std::set<Sbecore::uint> diff(const StatShrFia* comp);
	};

	/**
		* StatShrWrc (full: StatShrDlgWdbeCvrWriteWrc)
		*/
	class StatShrWrc : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTRUNACTIVE = 1;
		static const Sbecore::uint BUTSTOACTIVE = 2;

	public:
		StatShrWrc(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrWrc* comp);
		std::set<Sbecore::uint> diff(const StatShrWrc* comp);
	};

	/**
		* Tag (full: TagDlgWdbeCvrWrite)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagCuc (full: TagDlgWdbeCvrWriteCuc)
		*/
	class TagCuc {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagFia (full: TagDlgWdbeCvrWriteFia)
		*/
	class TagFia {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagWrc (full: TagDlgWdbeCvrWriteWrc)
		*/
	class TagWrc {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgWdbeCvrWriteData)
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
		* DpchAppDo (full: DpchAppDlgWdbeCvrWriteDo)
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
		* DpchEngData (full: DpchEngDlgWdbeCvrWriteData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint CONTINFFIA = 4;
		static const Sbecore::uint CONTINFWRC = 5;
		static const Sbecore::uint FEEDFDSE = 6;
		static const Sbecore::uint FEEDFSGE = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint STATSHRCUC = 10;
		static const Sbecore::uint STATSHRFIA = 11;
		static const Sbecore::uint STATSHRWRC = 12;
		static const Sbecore::uint TAG = 13;
		static const Sbecore::uint TAGCUC = 14;
		static const Sbecore::uint TAGFIA = 15;
		static const Sbecore::uint TAGWRC = 16;
		static const Sbecore::uint ALL = 17;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, ContInfFia* continffia = NULL, ContInfWrc* continfwrc = NULL, Sbecore::Feed* feedFDse = NULL, Sbecore::Feed* feedFSge = NULL, StatShr* statshr = NULL, StatShrCuc* statshrcuc = NULL, StatShrFia* statshrfia = NULL, StatShrWrc* statshrwrc = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		ContInfFia continffia;
		ContInfWrc continfwrc;
		Sbecore::Feed feedFDse;
		Sbecore::Feed feedFSge;
		StatShr statshr;
		StatShrCuc statshrcuc;
		StatShrFia statshrfia;
		StatShrWrc statshrwrc;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalButDneActive(DbsWdbe* dbswdbe);
	bool evalFiaDldActive(DbsWdbe* dbswdbe);
	bool evalWrcButRunActive(DbsWdbe* dbswdbe);
	bool evalWrcButStoActive(DbsWdbe* dbswdbe);
	bool evalCucUldActive(DbsWdbe* dbswdbe);

public:
	DlgWdbeCvrWrite(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~DlgWdbeCvrWrite();

public:
	ContIac contiac;
	ContInf continf;
	ContInfFia continffia;
	ContInfWrc continfwrc;
	StatShr statshr;
	StatShrCuc statshrcuc;
	StatShrFia statshrfia;
	StatShrWrc statshrwrc;

	Sbecore::Feed feedFDse;
	Sbecore::Feed feedFSge;

	Sbecore::uint ixVDit;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshCuc(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshWrc(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshFia(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems, const bool unmute = false);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:

	void handleDpchAppWdbeInit(DbsWdbe* dbswdbe, DpchAppWdbeInit* dpchappwdbeinit, DpchEngWdbe** dpcheng);
	void handleDpchAppDataContiac(DbsWdbe* dbswdbe, ContIac* _contiac, DpchEngWdbe** dpcheng);

	void handleDpchAppDoButDneClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

	void handleDpchAppDoWrcButRunClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoWrcButStoClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

	void handleUploadInSgeIdle(DbsWdbe* dbswdbe, const std::string& filename);

	std::string handleDownloadInSgeDone(DbsWdbe* dbswdbe);

	void handleDpchRetWdbePrctreeMerge(DbsWdbe* dbswdbe, DpchRetWdbePrctreeMerge* dpchret);

	void handleTimerWithSrefMonInSgeWrite(DbsWdbe* dbswdbe);
	void handleTimerInSgeUpkidle(DbsWdbe* dbswdbe, const std::string& sref);
	void handleTimerInSgeCreidle(DbsWdbe* dbswdbe, const std::string& sref);
	void handleTimerWithSrefMonInSgeCreate(DbsWdbe* dbswdbe);

private:
	void changeStage(DbsWdbe* dbswdbe, Sbecore::uint _ixVSge, DpchEngWdbe** dpcheng = NULL);

public:
	std::string getSquawk(DbsWdbe* dbswdbe);

private:
	Sbecore::uint enterSgeIdle(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeIdle(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeUpkidle(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeUpkidle(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeUnpack(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeUnpack(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeUpkdone(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeUpkdone(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeCreidle(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeCreidle(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeCreate(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeCreate(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeWrite(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeWrite(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeMrg(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeMrg(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeMrgcust(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeMrgcust(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgePack(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgePack(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeDone(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeDone(DbsWdbe* dbswdbe);

};

#endif
