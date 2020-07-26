/**
	* \file DlgWdbeNavMnglic.h
	* job handler for job DlgWdbeNavMnglic (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef DLGWDBENAVMNGLIC_H
#define DLGWDBENAVMNGLIC_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWdbeLicense.h"

#define VecVDlgWdbeNavMnglicDo DlgWdbeNavMnglic::VecVDo
#define VecVDlgWdbeNavMnglicSge DlgWdbeNavMnglic::VecVSge

#define ContIacDlgWdbeNavMnglic DlgWdbeNavMnglic::ContIac
#define ContInfDlgWdbeNavMnglic DlgWdbeNavMnglic::ContInf
#define StatAppDlgWdbeNavMnglic DlgWdbeNavMnglic::StatApp
#define StatShrDlgWdbeNavMnglic DlgWdbeNavMnglic::StatShr
#define TagDlgWdbeNavMnglic DlgWdbeNavMnglic::Tag

#define DpchAppDlgWdbeNavMnglicData DlgWdbeNavMnglic::DpchAppData
#define DpchAppDlgWdbeNavMnglicDo DlgWdbeNavMnglic::DpchAppDo
#define DpchEngDlgWdbeNavMnglicData DlgWdbeNavMnglic::DpchEngData

/**
	* DlgWdbeNavMnglic
	*/
class DlgWdbeNavMnglic : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVDlgWdbeNavMnglicDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint DETBUTSCNCLICK = 1;
		static const Sbecore::uint DETBUTSDCCLICK = 2;
		static const Sbecore::uint DETBUTACTCLICK = 3;
		static const Sbecore::uint BUTDNECLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWdbeNavMnglicSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint READY = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgWdbeNavMnglic)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFDETPUPFIS = 1;
		static const Sbecore::uint DETCHKFIS = 2;
		static const Sbecore::uint NUMFDETLSTLCS = 3;

	public:
		ContIac(const Sbecore::uint numFDetPupFis = 1, const bool DetChkFis = false, const Sbecore::uint numFDetLstLcs = 1);

	public:
		Sbecore::uint numFDetPupFis;
		bool DetChkFis;
		Sbecore::uint numFDetLstLcs;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfDlgWdbeNavMnglic)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint DETTXTSIP = 2;
		static const Sbecore::uint DETTXTSCP = 3;
		static const Sbecore::uint DETTXTLSR = 4;
		static const Sbecore::uint DETTXTLAR = 5;
		static const Sbecore::uint DETTXTLST = 6;
		static const Sbecore::uint DETTXTLEX = 7;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& DetTxtSip = "", const std::string& DetTxtScp = "", const std::string& DetTxtLsr = "", const std::string& DetTxtLar = "", const std::string& DetTxtLst = "", const std::string& DetTxtLex = "");

	public:
		Sbecore::uint numFSge;
		std::string DetTxtSip;
		std::string DetTxtScp;
		std::string DetTxtLsr;
		std::string DetTxtLar;
		std::string DetTxtLst;
		std::string DetTxtLex;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppDlgWdbeNavMnglic)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const std::string& shortMenu = "", const Sbecore::uint DetLstLcsNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrDlgWdbeNavMnglic)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DETBUTACTACTIVE = 1;

	public:
		StatShr(const bool DetButActActive = true);

	public:
		bool DetButActActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagDlgWdbeNavMnglic)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgWdbeNavMnglicData)
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
		* DpchAppDo (full: DpchAppDlgWdbeNavMnglicDo)
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
		* DpchEngData (full: DpchEngDlgWdbeNavMnglicData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFDETLSTLCS = 4;
		static const Sbecore::uint FEEDFDETPUPFIS = 5;
		static const Sbecore::uint FEEDFSGE = 6;
		static const Sbecore::uint STATAPP = 7;
		static const Sbecore::uint STATSHR = 8;
		static const Sbecore::uint TAG = 9;
		static const Sbecore::uint ALL = 10;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFDetLstLcs = NULL, Sbecore::Xmlio::Feed* feedFDetPupFis = NULL, Sbecore::Xmlio::Feed* feedFSge = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFDetLstLcs;
		Sbecore::Xmlio::Feed feedFDetPupFis;
		Sbecore::Xmlio::Feed feedFSge;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalDetButActActive(DbsWdbe* dbswdbe);

public:
	DlgWdbeNavMnglic(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~DlgWdbeNavMnglic();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFDetLstLcs;
	Sbecore::Xmlio::Feed feedFDetPupFis;
	Sbecore::Xmlio::Feed feedFSge;

	JobWdbeLicense* license;

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

	void handleDpchAppDoDetButScnClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoDetButSdcClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoDetButActClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButDneClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

private:
	void changeStage(DbsWdbe* dbswdbe, Sbecore::uint _ixVSge, DpchEngWdbe** dpcheng = NULL);

public:
	std::string getSquawk(DbsWdbe* dbswdbe);

private:
	Sbecore::uint enterSgeIdle(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeIdle(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeReady(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeReady(DbsWdbe* dbswdbe);

};

#endif

