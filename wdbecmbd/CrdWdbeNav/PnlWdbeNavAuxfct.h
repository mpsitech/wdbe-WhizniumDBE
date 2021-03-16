/**
	* \file PnlWdbeNavAuxfct.h
	* job handler for job PnlWdbeNavAuxfct (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBENAVAUXFCT_H
#define PNLWDBENAVAUXFCT_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWdbeNavAuxfctDo PnlWdbeNavAuxfct::VecVDo

#define StatAppWdbeNavAuxfct PnlWdbeNavAuxfct::StatApp
#define StatShrWdbeNavAuxfct PnlWdbeNavAuxfct::StatShr
#define TagWdbeNavAuxfct PnlWdbeNavAuxfct::Tag

#define DpchAppWdbeNavAuxfctDo PnlWdbeNavAuxfct::DpchAppDo
#define DpchEngWdbeNavAuxfctData PnlWdbeNavAuxfct::DpchEngData

/**
	* PnlWdbeNavAuxfct
	*/
class PnlWdbeNavAuxfct : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVWdbeNavAuxfctDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTUTLNEWCRDCLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* StatApp (full: StatAppWdbeNavAuxfct)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrWdbeNavAuxfct)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTUTLNEWCRDAVAIL = 1;

	public:
		StatShr(const bool ButUtlNewcrdAvail = true);

	public:
		bool ButUtlNewcrdAvail;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWdbeNavAuxfct)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWdbeNavAuxfctDo)
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

		void readJSON(Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngWdbeNavAuxfctData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint STATAPP = 2;
		static const Sbecore::uint STATSHR = 3;
		static const Sbecore::uint TAG = 4;
		static const Sbecore::uint ALL = 5;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalButUtlNewcrdAvail(DbsWdbe* dbswdbe);

public:
	PnlWdbeNavAuxfct(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~PnlWdbeNavAuxfct();

public:
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

	void handleDpchAppDoButUtlNewcrdClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

};

#endif
