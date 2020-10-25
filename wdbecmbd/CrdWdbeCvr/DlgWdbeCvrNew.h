/**
	* \file DlgWdbeCvrNew.h
	* job handler for job DlgWdbeCvrNew (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef DLGWDBECVRNEW_H
#define DLGWDBECVRNEW_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVDlgWdbeCvrNewDo DlgWdbeCvrNew::VecVDo
#define VecVDlgWdbeCvrNewSge DlgWdbeCvrNew::VecVSge
#define VecVDlgWdbeCvrNewVni DlgWdbeCvrNew::VecVVni

#define ContIacDlgWdbeCvrNew DlgWdbeCvrNew::ContIac
#define ContInfDlgWdbeCvrNew DlgWdbeCvrNew::ContInf
#define StatAppDlgWdbeCvrNew DlgWdbeCvrNew::StatApp
#define StatShrDlgWdbeCvrNew DlgWdbeCvrNew::StatShr
#define TagDlgWdbeCvrNew DlgWdbeCvrNew::Tag

#define DpchAppDlgWdbeCvrNewData DlgWdbeCvrNew::DpchAppData
#define DpchAppDlgWdbeCvrNewDo DlgWdbeCvrNew::DpchAppDo
#define DpchEngDlgWdbeCvrNewData DlgWdbeCvrNew::DpchEngData

/**
	* DlgWdbeCvrNew
	*/
class DlgWdbeCvrNew : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVDlgWdbeCvrNewDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTCNCCLICK = 1;
		static const Sbecore::uint BUTCRECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWdbeCvrNewSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint CREATE = 2;
		static const Sbecore::uint DONE = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVVni (full: VecVDlgWdbeCvrNewVni)
		*/
	class VecVVni {

	public:
		static const Sbecore::uint MAJ = 1;
		static const Sbecore::uint MIN = 2;
		static const Sbecore::uint SUB = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgWdbeCvrNew)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFDETPUPCPR = 1;
		static const Sbecore::uint NUMFDETPUPBCV = 2;
		static const Sbecore::uint NUMFDETRBUVNI = 3;

	public:
		ContIac(const Sbecore::uint numFDetPupCpr = 1, const Sbecore::uint numFDetPupBcv = 1, const Sbecore::uint numFDetRbuVni = 1);

	public:
		Sbecore::uint numFDetPupCpr;
		Sbecore::uint numFDetPupBcv;
		Sbecore::uint numFDetRbuVni;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfDlgWdbeCvrNew)
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
		* StatApp (full: StatAppDlgWdbeCvrNew)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const std::string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgWdbeCvrNew)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTCNCACTIVE = 1;
		static const Sbecore::uint BUTCREACTIVE = 2;

	public:
		StatShr(const bool ButCncActive = true, const bool ButCreActive = true);

	public:
		bool ButCncActive;
		bool ButCreActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagDlgWdbeCvrNew)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgWdbeCvrNewData)
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
		* DpchAppDo (full: DpchAppDlgWdbeCvrNewDo)
		*/
	class DpchAppDo : public DpchAppWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint IXVDO = 2;

	public:
		DpchAppDo();

	public:
		Sbecore::uint ixVDo;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgWdbeCvrNewData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFDETPUPBCV = 4;
		static const Sbecore::uint FEEDFDETPUPCPR = 5;
		static const Sbecore::uint FEEDFDETRBUVNI = 6;
		static const Sbecore::uint FEEDFSGE = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint TAG = 10;
		static const Sbecore::uint ALL = 11;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFDetPupBcv = NULL, Sbecore::Xmlio::Feed* feedFDetPupCpr = NULL, Sbecore::Xmlio::Feed* feedFDetRbuVni = NULL, Sbecore::Xmlio::Feed* feedFSge = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFDetPupBcv;
		Sbecore::Xmlio::Feed feedFDetPupCpr;
		Sbecore::Xmlio::Feed feedFDetRbuVni;
		Sbecore::Xmlio::Feed feedFSge;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalButCncActive(DbsWdbe* dbswdbe);
	bool evalButCreActive(DbsWdbe* dbswdbe);

public:
	DlgWdbeCvrNew(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~DlgWdbeCvrNew();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFDetPupBcv;
	Sbecore::Xmlio::Feed feedFDetPupCpr;
	Sbecore::Xmlio::Feed feedFDetRbuVni;
	Sbecore::Xmlio::Feed feedFSge;

	bool valid;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:

	void handleDpchAppWdbeInit(DbsWdbe* dbswdbe, DpchAppWdbeInit* dpchappwdbeinit, DpchEngWdbe** dpcheng);
	void handleDpchAppDataContiac(DbsWdbe* dbswdbe, ContIac* _contiac, DpchEngWdbe** dpcheng);

	void handleDpchAppDoButCncClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButCreClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

private:
	void changeStage(DbsWdbe* dbswdbe, Sbecore::uint _ixVSge, DpchEngWdbe** dpcheng = NULL);

public:
	std::string getSquawk(DbsWdbe* dbswdbe);

private:
	Sbecore::uint enterSgeIdle(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeIdle(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeCreate(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeCreate(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeDone(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeDone(DbsWdbe* dbswdbe);

};

#endif

