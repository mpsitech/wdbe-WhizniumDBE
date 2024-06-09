/**
	* \file DlgWdbeVerGenfst.h
	* job handler for job DlgWdbeVerGenfst (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

#ifndef DLGWDBEVERGENFST_H
#define DLGWDBEVERGENFST_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVDlgWdbeVerGenfstDo DlgWdbeVerGenfst::VecVDo
#define VecVDlgWdbeVerGenfstSge DlgWdbeVerGenfst::VecVSge

#define ContInfDlgWdbeVerGenfst DlgWdbeVerGenfst::ContInf
#define StatAppDlgWdbeVerGenfst DlgWdbeVerGenfst::StatApp
#define StatShrDlgWdbeVerGenfst DlgWdbeVerGenfst::StatShr
#define TagDlgWdbeVerGenfst DlgWdbeVerGenfst::Tag

#define DpchAppDlgWdbeVerGenfstDo DlgWdbeVerGenfst::DpchAppDo
#define DpchEngDlgWdbeVerGenfstData DlgWdbeVerGenfst::DpchEngData

/**
	* DlgWdbeVerGenfst
	*/
class DlgWdbeVerGenfst : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVDlgWdbeVerGenfstDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint GFSBUTRUNCLICK = 1;
		static const Sbecore::uint GFSBUTSTOCLICK = 2;
		static const Sbecore::uint BUTDNECLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWdbeVerGenfstSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint GENFST = 2;
		static const Sbecore::uint GENMTP = 3;
		static const Sbecore::uint DONE = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
	  * ContInf (full: ContInfDlgWdbeVerGenfst)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint GFSTXTPRG = 2;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& GfsTxtPrg = "");

	public:
		Sbecore::uint numFSge;
		std::string GfsTxtPrg;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppDlgWdbeVerGenfst)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const std::string& shortMenu = "");
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const std::string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgWdbeVerGenfst)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint GFSBUTRUNACTIVE = 1;
		static const Sbecore::uint GFSBUTSTOACTIVE = 2;
		static const Sbecore::uint BUTDNEACTIVE = 3;

	public:
		StatShr(const bool GfsButRunActive = true, const bool GfsButStoActive = true, const bool ButDneActive = true);

	public:
		bool GfsButRunActive;
		bool GfsButStoActive;
		bool ButDneActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagDlgWdbeVerGenfst)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppDlgWdbeVerGenfstDo)
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

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgWdbeVerGenfstData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint FEEDFSGE = 3;
		static const Sbecore::uint STATAPP = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint TAG = 6;
		static const Sbecore::uint ALL = 7;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContInf* continf = NULL, Sbecore::Feed* feedFSge = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContInf continf;
		Sbecore::Feed feedFSge;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalGfsButRunActive(DbsWdbe* dbswdbe);
	bool evalGfsButStoActive(DbsWdbe* dbswdbe);
	bool evalButDneActive(DbsWdbe* dbswdbe);

public:
	DlgWdbeVerGenfst(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~DlgWdbeVerGenfst();

public:
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFSge;

	// IP vars.cust --- IBEGIN
	std::map<Sbecore::ubigint,std::string> UntsrefsUnts;
	std::map<Sbecore::ubigint,bool> mcuNotFpgasUnts;

	// level-adjusted list of modules used for genfst/genmtp
	ListWdbeMModule mdls;
	std::vector<unsigned int> lvlsMdls;

	// refs of modules already processed in genfst/genmtp
	std::set<Sbecore::ubigint> refsTypmod;
	std::set<Sbecore::ubigint> refsTplmod;
	// IP vars.cust --- IEND

public:
	// IP cust --- INSERT

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems, const bool unmute = false);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:

	void handleDpchAppWdbeInit(DbsWdbe* dbswdbe, DpchAppWdbeInit* dpchappwdbeinit, DpchEngWdbe** dpcheng);

	void handleDpchAppDoGfsButRunClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoGfsButStoClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButDneClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

	void handleDpchRetWdbe(DbsWdbe* dbswdbe, DpchRetWdbe* dpchret);

	void handleTimerWithSrefMonInSgeGenfst(DbsWdbe* dbswdbe);
	void handleTimerWithSrefMonInSgeGenmtp(DbsWdbe* dbswdbe);

private:
	void changeStage(DbsWdbe* dbswdbe, Sbecore::uint _ixVSge, DpchEngWdbe** dpcheng = NULL);

public:
	std::string getSquawk(DbsWdbe* dbswdbe);

private:
	Sbecore::uint enterSgeIdle(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeIdle(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeGenfst(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeGenfst(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeGenmtp(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeGenmtp(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeDone(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeDone(DbsWdbe* dbswdbe);

};

#endif
