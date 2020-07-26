/**
	* \file DlgWdbeFilNew.h
	* job handler for job DlgWdbeFilNew (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef DLGWDBEFILNEW_H
#define DLGWDBEFILNEW_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVDlgWdbeFilNewDit DlgWdbeFilNew::VecVDit
#define VecVDlgWdbeFilNewDo DlgWdbeFilNew::VecVDo
#define VecVDlgWdbeFilNewDoDet DlgWdbeFilNew::VecVDoDet
#define VecVDlgWdbeFilNewSge DlgWdbeFilNew::VecVSge

#define ContIacDlgWdbeFilNew DlgWdbeFilNew::ContIac
#define ContIacDlgWdbeFilNewDet DlgWdbeFilNew::ContIacDet
#define ContInfDlgWdbeFilNew DlgWdbeFilNew::ContInf
#define StatAppDlgWdbeFilNew DlgWdbeFilNew::StatApp
#define StatShrDlgWdbeFilNew DlgWdbeFilNew::StatShr
#define StatShrDlgWdbeFilNewDet DlgWdbeFilNew::StatShrDet
#define StatShrDlgWdbeFilNewFil DlgWdbeFilNew::StatShrFil
#define TagDlgWdbeFilNew DlgWdbeFilNew::Tag
#define TagDlgWdbeFilNewDet DlgWdbeFilNew::TagDet
#define TagDlgWdbeFilNewFil DlgWdbeFilNew::TagFil

#define DpchAppDlgWdbeFilNewData DlgWdbeFilNew::DpchAppData
#define DpchAppDlgWdbeFilNewDo DlgWdbeFilNew::DpchAppDo
#define DpchEngDlgWdbeFilNewData DlgWdbeFilNew::DpchEngData

/**
	* DlgWdbeFilNew
	*/
class DlgWdbeFilNew : public JobWdbe {

public:
	/**
		* VecVDit (full: VecVDlgWdbeFilNewDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint DET = 1;
		static const Sbecore::uint FIL = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVDo (full: VecVDlgWdbeFilNewDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoDet (full: VecVDlgWdbeFilNewDoDet)
		*/
	class VecVDoDet {

	public:
		static const Sbecore::uint BUTCRECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWdbeFilNewSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint CREATE = 2;
		static const Sbecore::uint CREDONE = 3;
		static const Sbecore::uint DONE = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgWdbeFilNew)
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
	  * ContIacDet (full: ContIacDlgWdbeFilNewDet)
	  */
	class ContIacDet : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFFNM = 1;
		static const Sbecore::uint NUMFPUPRET = 2;
		static const Sbecore::uint TXFREU = 3;
		static const Sbecore::uint NUMFPUPCNT = 4;
		static const Sbecore::uint NUMFPUPMIM = 5;
		static const Sbecore::uint TXFCMT = 6;

	public:
		ContIacDet(const std::string& TxfFnm = "", const Sbecore::uint numFPupRet = 1, const std::string& TxfReu = "", const Sbecore::uint numFPupCnt = 1, const Sbecore::uint numFPupMim = 1, const std::string& TxfCmt = "");

	public:
		std::string TxfFnm;
		Sbecore::uint numFPupRet;
		std::string TxfReu;
		Sbecore::uint numFPupCnt;
		Sbecore::uint numFPupMim;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIacDet* comp);
		std::set<Sbecore::uint> diff(const ContIacDet* comp);
	};

	/**
	  * ContInf (full: ContInfDlgWdbeFilNew)
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
		* StatApp (full: StatAppDlgWdbeFilNew)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdone = false, const std::string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgWdbeFilNew)
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
		* StatShrDet (full: StatShrDlgWdbeFilNewDet)
		*/
	class StatShrDet : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTCREACTIVE = 1;

	public:
		StatShrDet(const bool ButCreActive = true);

	public:
		bool ButCreActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrDet* comp);
		std::set<Sbecore::uint> diff(const StatShrDet* comp);
	};

	/**
		* StatShrFil (full: StatShrDlgWdbeFilNewFil)
		*/
	class StatShrFil : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint ULDACTIVE = 1;

	public:
		StatShrFil(const bool UldActive = true);

	public:
		bool UldActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrFil* comp);
		std::set<Sbecore::uint> diff(const StatShrFil* comp);
	};

	/**
		* Tag (full: TagDlgWdbeFilNew)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagDet (full: TagDlgWdbeFilNewDet)
		*/
	class TagDet {

	public:
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagFil (full: TagDlgWdbeFilNewFil)
		*/
	class TagFil {

	public:
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgWdbeFilNewData)
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

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppDlgWdbeFilNewDo)
		*/
	class DpchAppDo : public DpchAppWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint IXVDODET = 3;

	public:
		DpchAppDo();

	public:
		Sbecore::uint ixVDo;
		Sbecore::uint ixVDoDet;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgWdbeFilNewData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTIACDET = 3;
		static const Sbecore::uint CONTINF = 4;
		static const Sbecore::uint FEEDFDETPUPCNT = 5;
		static const Sbecore::uint FEEDFDETPUPMIM = 6;
		static const Sbecore::uint FEEDFDETPUPRET = 7;
		static const Sbecore::uint FEEDFDSE = 8;
		static const Sbecore::uint FEEDFSGE = 9;
		static const Sbecore::uint STATAPP = 10;
		static const Sbecore::uint STATSHR = 11;
		static const Sbecore::uint STATSHRDET = 12;
		static const Sbecore::uint STATSHRFIL = 13;
		static const Sbecore::uint TAG = 14;
		static const Sbecore::uint TAGDET = 15;
		static const Sbecore::uint TAGFIL = 16;
		static const Sbecore::uint ALL = 17;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContIacDet* contiacdet = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFDetPupCnt = NULL, Sbecore::Xmlio::Feed* feedFDetPupMim = NULL, Sbecore::Xmlio::Feed* feedFDetPupRet = NULL, Sbecore::Xmlio::Feed* feedFDse = NULL, Sbecore::Xmlio::Feed* feedFSge = NULL, StatShr* statshr = NULL, StatShrDet* statshrdet = NULL, StatShrFil* statshrfil = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContIacDet contiacdet;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFDetPupCnt;
		Sbecore::Xmlio::Feed feedFDetPupMim;
		Sbecore::Xmlio::Feed feedFDetPupRet;
		Sbecore::Xmlio::Feed feedFDse;
		Sbecore::Xmlio::Feed feedFSge;
		StatShr statshr;
		StatShrDet statshrdet;
		StatShrFil statshrfil;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalButDneActive(DbsWdbe* dbswdbe);
	bool evalFilUldActive(DbsWdbe* dbswdbe);
	bool evalDetButCreActive(DbsWdbe* dbswdbe);

public:
	DlgWdbeFilNew(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~DlgWdbeFilNew();

public:
	ContIac contiac;
	ContIacDet contiacdet;
	ContInf continf;
	StatShr statshr;
	StatShrDet statshrdet;
	StatShrFil statshrfil;

	Sbecore::Xmlio::Feed feedFDetPupCnt;
	Sbecore::Xmlio::Feed feedFDetPupMim;
	Sbecore::Xmlio::Feed feedFDetPupRet;
	Sbecore::Xmlio::Feed feedFDse;
	Sbecore::Xmlio::Feed feedFSge;

	Sbecore::uint ixVDit;

	bool valid;

	// IP vars.cust --- IBEGIN
	std::string infilename;
	// IP vars.cust --- IEND

public:
	// IP cust --- IBEGIN
	Sbecore::ubigint getRefMtp(DbsWdbe* dbswdbe, const std::string& s);
	Sbecore::ubigint getRefVer(DbsWdbe* dbswdbe, const std::string& s);
	// IP cust --- IEND

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshDet(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshFil(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:

	void handleDpchAppWdbeInit(DbsWdbe* dbswdbe, DpchAppWdbeInit* dpchappwdbeinit, DpchEngWdbe** dpcheng);
	void handleDpchAppDataContiac(DbsWdbe* dbswdbe, ContIac* _contiac, DpchEngWdbe** dpcheng);
	void handleDpchAppDataContiacdet(DbsWdbe* dbswdbe, ContIacDet* _contiacdet, DpchEngWdbe** dpcheng);

	void handleDpchAppDoButDneClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

	void handleDpchAppDoDetButCreClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

	void handleUploadInSgeCredone(DbsWdbe* dbswdbe, const std::string& filename);

private:
	void changeStage(DbsWdbe* dbswdbe, Sbecore::uint _ixVSge, DpchEngWdbe** dpcheng = NULL);

public:
	std::string getSquawk(DbsWdbe* dbswdbe);

private:
	Sbecore::uint enterSgeIdle(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeIdle(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeCreate(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeCreate(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeCredone(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeCredone(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeDone(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeDone(DbsWdbe* dbswdbe);

};

#endif


