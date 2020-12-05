/**
	* \file DlgWdbeUsrMngkeypair.h
	* job handler for job DlgWdbeUsrMngkeypair (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef DLGWDBEUSRMNGKEYPAIR_H
#define DLGWDBEUSRMNGKEYPAIR_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVDlgWdbeUsrMngkeypairDo DlgWdbeUsrMngkeypair::VecVDo
#define VecVDlgWdbeUsrMngkeypairSge DlgWdbeUsrMngkeypair::VecVSge

#define ContInfDlgWdbeUsrMngkeypair DlgWdbeUsrMngkeypair::ContInf
#define StatAppDlgWdbeUsrMngkeypair DlgWdbeUsrMngkeypair::StatApp
#define StatShrDlgWdbeUsrMngkeypair DlgWdbeUsrMngkeypair::StatShr
#define TagDlgWdbeUsrMngkeypair DlgWdbeUsrMngkeypair::Tag

#define DpchAppDlgWdbeUsrMngkeypairDo DlgWdbeUsrMngkeypair::DpchAppDo
#define DpchEngDlgWdbeUsrMngkeypairData DlgWdbeUsrMngkeypair::DpchEngData

/**
	* DlgWdbeUsrMngkeypair
	*/
class DlgWdbeUsrMngkeypair : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVDlgWdbeUsrMngkeypairDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint DETBUTDELCLICK = 1;
		static const Sbecore::uint DETBUTGENCLICK = 2;
		static const Sbecore::uint BUTDNECLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWdbeUsrMngkeypairSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint NF = 1;
		static const Sbecore::uint FOUND = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
	  * ContInf (full: ContInfDlgWdbeUsrMngkeypair)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint DETTXTSTE = 2;
		static const Sbecore::uint DETDLD = 3;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& DetTxtSte = "", const std::string& DetDld = "file");

	public:
		Sbecore::uint numFSge;
		std::string DetTxtSte;
		std::string DetDld;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppDlgWdbeUsrMngkeypair)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const std::string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgWdbeUsrMngkeypair)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DETBUTDELAVAIL = 1;
		static const Sbecore::uint DETBUTGENAVAIL = 2;
		static const Sbecore::uint DETDLDACTIVE = 3;

	public:
		StatShr(const bool DetButDelAvail = true, const bool DetButGenAvail = true, const bool DetDldActive = true);

	public:
		bool DetButDelAvail;
		bool DetButGenAvail;
		bool DetDldActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagDlgWdbeUsrMngkeypair)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppDlgWdbeUsrMngkeypairDo)
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
		* DpchEngData (full: DpchEngDlgWdbeUsrMngkeypairData)
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
		DpchEngData(const Sbecore::ubigint jref = 0, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFSge = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContInf continf;
		Sbecore::Xmlio::Feed feedFSge;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalDetButDelAvail(DbsWdbe* dbswdbe);
	bool evalDetButGenAvail(DbsWdbe* dbswdbe);
	bool evalDetDldActive(DbsWdbe* dbswdbe);

public:
	DlgWdbeUsrMngkeypair(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~DlgWdbeUsrMngkeypair();

public:
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFSge;

	// IP vars.cust --- IBEGIN
	std::string usrsref;
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

	void handleDpchAppDoDetButDelClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoDetButGenClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButDneClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

	std::string handleDownloadInSgeFound(DbsWdbe* dbswdbe);

private:
	void changeStage(DbsWdbe* dbswdbe, Sbecore::uint _ixVSge, DpchEngWdbe** dpcheng = NULL);

public:
	std::string getSquawk(DbsWdbe* dbswdbe);

private:
	Sbecore::uint enterSgeNf(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeNf(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeFound(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeFound(DbsWdbe* dbswdbe);

};

#endif



