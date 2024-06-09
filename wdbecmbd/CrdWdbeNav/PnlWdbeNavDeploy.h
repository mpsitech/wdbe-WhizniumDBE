/**
	* \file PnlWdbeNavDeploy.h
	* job handler for job PnlWdbeNavDeploy (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Sep 2023
	*/
// IP header --- ABOVE

#ifndef PNLWDBENAVDEPLOY_H
#define PNLWDBENAVDEPLOY_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWdbeNavDeployDo PnlWdbeNavDeploy::VecVDo

#define ContIacWdbeNavDeploy PnlWdbeNavDeploy::ContIac
#define StatAppWdbeNavDeploy PnlWdbeNavDeploy::StatApp
#define StatShrWdbeNavDeploy PnlWdbeNavDeploy::StatShr
#define TagWdbeNavDeploy PnlWdbeNavDeploy::Tag

#define DpchAppWdbeNavDeployData PnlWdbeNavDeploy::DpchAppData
#define DpchAppWdbeNavDeployDo PnlWdbeNavDeploy::DpchAppDo
#define DpchEngWdbeNavDeployData PnlWdbeNavDeploy::DpchEngData

/**
	* PnlWdbeNavDeploy
	*/
class PnlWdbeNavDeploy : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVWdbeNavDeployDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTCMPVIEWCLICK = 1;
		static const Sbecore::uint BUTCMPNEWCRDCLICK = 2;
		static const Sbecore::uint BUTRLSVIEWCLICK = 3;
		static const Sbecore::uint BUTRLSNEWCRDCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeNavDeploy)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFLSTCMP = 1;
		static const Sbecore::uint NUMFLSTRLS = 2;

	public:
		ContIac(const Sbecore::uint numFLstCmp = 1, const Sbecore::uint numFLstRls = 1);

	public:
		Sbecore::uint numFLstCmp;
		Sbecore::uint numFLstRls;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppWdbeNavDeploy)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool LstCmpAlt = true, const bool LstRlsAlt = true, const Sbecore::uint LstCmpNumFirstdisp = 1, const Sbecore::uint LstRlsNumFirstdisp = 1);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool LstCmpAlt = true, const bool LstRlsAlt = true, const Sbecore::uint LstCmpNumFirstdisp = 1, const Sbecore::uint LstRlsNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWdbeNavDeploy)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint LSTCMPAVAIL = 1;
		static const Sbecore::uint BUTCMPVIEWACTIVE = 2;
		static const Sbecore::uint LSTRLSAVAIL = 3;
		static const Sbecore::uint BUTRLSVIEWACTIVE = 4;
		static const Sbecore::uint BUTRLSNEWCRDACTIVE = 5;

	public:
		StatShr(const bool LstCmpAvail = true, const bool ButCmpViewActive = true, const bool LstRlsAvail = true, const bool ButRlsViewActive = true, const bool ButRlsNewcrdActive = true);

	public:
		bool LstCmpAvail;
		bool ButCmpViewActive;
		bool LstRlsAvail;
		bool ButRlsViewActive;
		bool ButRlsNewcrdActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWdbeNavDeploy)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWdbeNavDeployData)
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
		* DpchAppDo (full: DpchAppWdbeNavDeployDo)
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
		* DpchEngData (full: DpchEngWdbeNavDeployData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTCMP = 3;
		static const Sbecore::uint FEEDFLSTRLS = 4;
		static const Sbecore::uint STATAPP = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint TAG = 7;
		static const Sbecore::uint ALL = 8;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, Sbecore::Feed* feedFLstCmp = NULL, Sbecore::Feed* feedFLstRls = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		Sbecore::Feed feedFLstCmp;
		Sbecore::Feed feedFLstRls;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalLstCmpAvail(DbsWdbe* dbswdbe);
	bool evalButCmpViewActive(DbsWdbe* dbswdbe);
	bool evalLstRlsAvail(DbsWdbe* dbswdbe);
	bool evalButRlsViewActive(DbsWdbe* dbswdbe);
	bool evalButRlsNewcrdActive(DbsWdbe* dbswdbe);

public:
	PnlWdbeNavDeploy(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~PnlWdbeNavDeploy();

public:
	ContIac contiac;
	StatShr statshr;

	Sbecore::Feed feedFLstCmp;
	Sbecore::Feed feedFLstRls;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshLstCmp(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshCmp(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshLstRls(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshRls(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refresh(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:

	void handleDpchAppWdbeInit(DbsWdbe* dbswdbe, DpchAppWdbeInit* dpchappwdbeinit, DpchEngWdbe** dpcheng);
	void handleDpchAppDataContiac(DbsWdbe* dbswdbe, ContIac* _contiac, DpchEngWdbe** dpcheng);

	void handleDpchAppDoButCmpViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButCmpNewcrdClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButRlsViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButRlsNewcrdClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

public:
	void handleCall(DbsWdbe* dbswdbe, Sbecore::Call* call);

private:
	bool handleCallWdbeHusrRunvMod_crdUsrEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);

};

#endif
