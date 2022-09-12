/**
	* \file PnlWdbeNavPre.h
	* job handler for job PnlWdbeNavPre (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBENAVPRE_H
#define PNLWDBENAVPRE_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWdbeNavPreDo PnlWdbeNavPre::VecVDo

#define ContInfWdbeNavPre PnlWdbeNavPre::ContInf
#define StatShrWdbeNavPre PnlWdbeNavPre::StatShr
#define TagWdbeNavPre PnlWdbeNavPre::Tag

#define DpchAppWdbeNavPreDo PnlWdbeNavPre::DpchAppDo
#define DpchEngWdbeNavPreData PnlWdbeNavPre::DpchEngData

/**
	* PnlWdbeNavPre
	*/
class PnlWdbeNavPre : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVWdbeNavPreDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTCVRREMOVECLICK = 1;
		static const Sbecore::uint BUTUNTREMOVECLICK = 2;
		static const Sbecore::uint BUTVERREMOVECLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWdbeNavPre)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTCVR = 1;
		static const Sbecore::uint TXTUNT = 2;
		static const Sbecore::uint TXTVER = 3;

	public:
		ContInf(const std::string& TxtCvr = "", const std::string& TxtUnt = "", const std::string& TxtVer = "");

	public:
		std::string TxtCvr;
		std::string TxtUnt;
		std::string TxtVer;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatShr (full: StatShrWdbeNavPre)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTCVRAVAIL = 1;
		static const Sbecore::uint TXTUNTAVAIL = 2;
		static const Sbecore::uint TXTVERAVAIL = 3;

	public:
		StatShr(const bool TxtCvrAvail = true, const bool TxtUntAvail = true, const bool TxtVerAvail = true);

	public:
		bool TxtCvrAvail;
		bool TxtUntAvail;
		bool TxtVerAvail;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWdbeNavPre)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWdbeNavPreDo)
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
		* DpchEngData (full: DpchEngWdbeNavPreData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint STATSHR = 3;
		static const Sbecore::uint TAG = 4;
		static const Sbecore::uint ALL = 5;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContInf* continf = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContInf continf;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalTxtCvrAvail(DbsWdbe* dbswdbe);
	bool evalTxtUntAvail(DbsWdbe* dbswdbe);
	bool evalTxtVerAvail(DbsWdbe* dbswdbe);

public:
	PnlWdbeNavPre(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~PnlWdbeNavPre();

public:
	ContInf continf;
	StatShr statshr;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:

	void handleDpchAppWdbeInit(DbsWdbe* dbswdbe, DpchAppWdbeInit* dpchappwdbeinit, DpchEngWdbe** dpcheng);

	void handleDpchAppDoButCvrRemoveClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButUntRemoveClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButVerRemoveClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

};

#endif
