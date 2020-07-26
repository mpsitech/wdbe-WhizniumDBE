/**
	* \file DlgWdbeUtlIexconv.h
	* job handler for job DlgWdbeUtlIexconv (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef DLGWDBEUTLIEXCONV_H
#define DLGWDBEUTLIEXCONV_H

// IP include.spec --- INSERT

// IP include.cust --- IBEGIN
#include <sys/types.h>
#include <dirent.h>
// IP include.cust --- IEND

#define VecVDlgWdbeUtlIexconvDit DlgWdbeUtlIexconv::VecVDit
#define VecVDlgWdbeUtlIexconvDo DlgWdbeUtlIexconv::VecVDo
#define VecVDlgWdbeUtlIexconvDoCnv DlgWdbeUtlIexconv::VecVDoCnv
#define VecVDlgWdbeUtlIexconvSge DlgWdbeUtlIexconv::VecVSge

#define ContIacDlgWdbeUtlIexconv DlgWdbeUtlIexconv::ContIac
#define ContInfDlgWdbeUtlIexconv DlgWdbeUtlIexconv::ContInf
#define ContInfDlgWdbeUtlIexconvCnv DlgWdbeUtlIexconv::ContInfCnv
#define ContInfDlgWdbeUtlIexconvRes DlgWdbeUtlIexconv::ContInfRes
#define StatAppDlgWdbeUtlIexconv DlgWdbeUtlIexconv::StatApp
#define StatShrDlgWdbeUtlIexconv DlgWdbeUtlIexconv::StatShr
#define StatShrDlgWdbeUtlIexconvCnv DlgWdbeUtlIexconv::StatShrCnv
#define StatShrDlgWdbeUtlIexconvRes DlgWdbeUtlIexconv::StatShrRes
#define StatShrDlgWdbeUtlIexconvSrc DlgWdbeUtlIexconv::StatShrSrc
#define TagDlgWdbeUtlIexconv DlgWdbeUtlIexconv::Tag
#define TagDlgWdbeUtlIexconvCnv DlgWdbeUtlIexconv::TagCnv
#define TagDlgWdbeUtlIexconvRes DlgWdbeUtlIexconv::TagRes
#define TagDlgWdbeUtlIexconvSrc DlgWdbeUtlIexconv::TagSrc

#define DpchAppDlgWdbeUtlIexconvData DlgWdbeUtlIexconv::DpchAppData
#define DpchAppDlgWdbeUtlIexconvDo DlgWdbeUtlIexconv::DpchAppDo
#define DpchEngDlgWdbeUtlIexconvData DlgWdbeUtlIexconv::DpchEngData

/**
	* DlgWdbeUtlIexconv
	*/
class DlgWdbeUtlIexconv : public JobWdbe {

public:
	/**
		* VecVDit (full: VecVDlgWdbeUtlIexconvDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint SRC = 1;
		static const Sbecore::uint CNV = 2;
		static const Sbecore::uint RES = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVDo (full: VecVDlgWdbeUtlIexconvDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoCnv (full: VecVDlgWdbeUtlIexconvDoCnv)
		*/
	class VecVDoCnv {

	public:
		static const Sbecore::uint BUTRUNCLICK = 1;
		static const Sbecore::uint BUTSTOCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWdbeUtlIexconvSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint UPKIDLE = 2;
		static const Sbecore::uint UNPACK = 3;
		static const Sbecore::uint UPKDONE = 4;
		static const Sbecore::uint ULDDONE = 5;
		static const Sbecore::uint CONV = 6;
		static const Sbecore::uint PACK = 7;
		static const Sbecore::uint DONE = 8;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgWdbeUtlIexconv)
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
	  * ContInf (full: ContInfDlgWdbeUtlIexconv)
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
	  * ContInfCnv (full: ContInfDlgWdbeUtlIexconvCnv)
	  */
	class ContInfCnv : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTPRG = 1;

	public:
		ContInfCnv(const std::string& TxtPrg = "");

	public:
		std::string TxtPrg;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfCnv* comp);
		std::set<Sbecore::uint> diff(const ContInfCnv* comp);
	};

	/**
	  * ContInfRes (full: ContInfDlgWdbeUtlIexconvRes)
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
		* StatApp (full: StatAppDlgWdbeUtlIexconv)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdone = false, const std::string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgWdbeUtlIexconv)
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
		* StatShrCnv (full: StatShrDlgWdbeUtlIexconvCnv)
		*/
	class StatShrCnv : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTRUNACTIVE = 1;
		static const Sbecore::uint BUTSTOACTIVE = 2;

	public:
		StatShrCnv(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrCnv* comp);
		std::set<Sbecore::uint> diff(const StatShrCnv* comp);
	};

	/**
		* StatShrRes (full: StatShrDlgWdbeUtlIexconvRes)
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
		* StatShrSrc (full: StatShrDlgWdbeUtlIexconvSrc)
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
		* Tag (full: TagDlgWdbeUtlIexconv)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagCnv (full: TagDlgWdbeUtlIexconvCnv)
		*/
	class TagCnv {

	public:
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagRes (full: TagDlgWdbeUtlIexconvRes)
		*/
	class TagRes {

	public:
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagSrc (full: TagDlgWdbeUtlIexconvSrc)
		*/
	class TagSrc {

	public:
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgWdbeUtlIexconvData)
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
		* DpchAppDo (full: DpchAppDlgWdbeUtlIexconvDo)
		*/
	class DpchAppDo : public DpchAppWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint IXVDOCNV = 3;

	public:
		DpchAppDo();

	public:
		Sbecore::uint ixVDo;
		Sbecore::uint ixVDoCnv;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgWdbeUtlIexconvData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint CONTINFCNV = 4;
		static const Sbecore::uint CONTINFRES = 5;
		static const Sbecore::uint FEEDFDSE = 6;
		static const Sbecore::uint FEEDFSGE = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint STATSHRCNV = 10;
		static const Sbecore::uint STATSHRRES = 11;
		static const Sbecore::uint STATSHRSRC = 12;
		static const Sbecore::uint TAG = 13;
		static const Sbecore::uint TAGCNV = 14;
		static const Sbecore::uint TAGRES = 15;
		static const Sbecore::uint TAGSRC = 16;
		static const Sbecore::uint ALL = 17;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, ContInfCnv* continfcnv = NULL, ContInfRes* continfres = NULL, Sbecore::Xmlio::Feed* feedFDse = NULL, Sbecore::Xmlio::Feed* feedFSge = NULL, StatShr* statshr = NULL, StatShrCnv* statshrcnv = NULL, StatShrRes* statshrres = NULL, StatShrSrc* statshrsrc = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		ContInfCnv continfcnv;
		ContInfRes continfres;
		Sbecore::Xmlio::Feed feedFDse;
		Sbecore::Xmlio::Feed feedFSge;
		StatShr statshr;
		StatShrCnv statshrcnv;
		StatShrRes statshrres;
		StatShrSrc statshrsrc;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalButDneActive(DbsWdbe* dbswdbe);
	bool evalResDldActive(DbsWdbe* dbswdbe);
	bool evalCnvButRunActive(DbsWdbe* dbswdbe);
	bool evalCnvButStoActive(DbsWdbe* dbswdbe);
	bool evalSrcUldActive(DbsWdbe* dbswdbe);

public:
	DlgWdbeUtlIexconv(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~DlgWdbeUtlIexconv();

public:
	ContIac contiac;
	ContInf continf;
	ContInfCnv continfcnv;
	ContInfRes continfres;
	StatShr statshr;
	StatShrCnv statshrcnv;
	StatShrRes statshrres;
	StatShrSrc statshrsrc;

	Sbecore::Xmlio::Feed feedFDse;
	Sbecore::Xmlio::Feed feedFSge;

	Sbecore::uint ixVDit;

	// IP vars.cust --- IBEGIN
	std::string infilename;

	std::string infolder;
	std::string infile;
	std::string outfolder;
	std::string outfile;
	// IP vars.cust --- IEND

public:
	// IP cust --- INSERT

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshSrc(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshCnv(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshRes(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:

	void handleDpchAppWdbeInit(DbsWdbe* dbswdbe, DpchAppWdbeInit* dpchappwdbeinit, DpchEngWdbe** dpcheng);
	void handleDpchAppDataContiac(DbsWdbe* dbswdbe, ContIac* _contiac, DpchEngWdbe** dpcheng);

	void handleDpchAppDoButDneClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

	void handleDpchAppDoCnvButRunClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoCnvButStoClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

	void handleUploadInSgeIdle(DbsWdbe* dbswdbe, const std::string& filename);

	std::string handleDownloadInSgeDone(DbsWdbe* dbswdbe);

	void handleTimerInSgeUpkidle(DbsWdbe* dbswdbe, const std::string& sref);
	void handleTimerWithSrefMonInSgeConv(DbsWdbe* dbswdbe);

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
	Sbecore::uint enterSgeUlddone(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeUlddone(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeConv(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeConv(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgePack(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgePack(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeDone(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeDone(DbsWdbe* dbswdbe);

};

#endif


