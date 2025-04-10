/**
	* \file PnlWdbeNavDevdev.h
	* job handler for job PnlWdbeNavDevdev (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBENAVDEVDEV_H
#define PNLWDBENAVDEVDEV_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWdbeNavDevdevDo PnlWdbeNavDevdev::VecVDo

#define ContIacWdbeNavDevdev PnlWdbeNavDevdev::ContIac
#define StatAppWdbeNavDevdev PnlWdbeNavDevdev::StatApp
#define StatShrWdbeNavDevdev PnlWdbeNavDevdev::StatShr
#define TagWdbeNavDevdev PnlWdbeNavDevdev::Tag

#define DpchAppWdbeNavDevdevData PnlWdbeNavDevdev::DpchAppData
#define DpchAppWdbeNavDevdevDo PnlWdbeNavDevdev::DpchAppDo
#define DpchEngWdbeNavDevdevData PnlWdbeNavDevdev::DpchEngData

/**
	* PnlWdbeNavDevdev
	*/
class PnlWdbeNavDevdev : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVWdbeNavDevdevDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTPRJVIEWCLICK = 1;
		static const Sbecore::uint BUTPRJNEWCRDCLICK = 2;
		static const Sbecore::uint BUTVERVIEWCLICK = 3;
		static const Sbecore::uint BUTVERNEWCRDCLICK = 4;
		static const Sbecore::uint BUTUNTVIEWCLICK = 5;
		static const Sbecore::uint BUTUNTNEWCRDCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeNavDevdev)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFLSTPRJ = 1;
		static const Sbecore::uint NUMFLSTVER = 2;
		static const Sbecore::uint NUMFLSTUNT = 3;

	public:
		ContIac(const Sbecore::uint numFLstPrj = 1, const Sbecore::uint numFLstVer = 1, const Sbecore::uint numFLstUnt = 1);

	public:
		Sbecore::uint numFLstPrj;
		Sbecore::uint numFLstVer;
		Sbecore::uint numFLstUnt;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppWdbeNavDevdev)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool LstPrjAlt = true, const bool LstVerAlt = true, const bool LstUntAlt = true, const Sbecore::uint LstPrjNumFirstdisp = 1, const Sbecore::uint LstVerNumFirstdisp = 1, const Sbecore::uint LstUntNumFirstdisp = 1);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool LstPrjAlt = true, const bool LstVerAlt = true, const bool LstUntAlt = true, const Sbecore::uint LstPrjNumFirstdisp = 1, const Sbecore::uint LstVerNumFirstdisp = 1, const Sbecore::uint LstUntNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWdbeNavDevdev)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint LSTPRJAVAIL = 1;
		static const Sbecore::uint BUTPRJVIEWACTIVE = 2;
		static const Sbecore::uint LSTVERAVAIL = 3;
		static const Sbecore::uint BUTVERVIEWACTIVE = 4;
		static const Sbecore::uint LSTUNTAVAIL = 5;
		static const Sbecore::uint BUTUNTVIEWACTIVE = 6;
		static const Sbecore::uint BUTUNTNEWCRDACTIVE = 7;

	public:
		StatShr(const bool LstPrjAvail = true, const bool ButPrjViewActive = true, const bool LstVerAvail = true, const bool ButVerViewActive = true, const bool LstUntAvail = true, const bool ButUntViewActive = true, const bool ButUntNewcrdActive = true);

	public:
		bool LstPrjAvail;
		bool ButPrjViewActive;
		bool LstVerAvail;
		bool ButVerViewActive;
		bool LstUntAvail;
		bool ButUntViewActive;
		bool ButUntNewcrdActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWdbeNavDevdev)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWdbeNavDevdevData)
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
		* DpchAppDo (full: DpchAppWdbeNavDevdevDo)
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
		* DpchEngData (full: DpchEngWdbeNavDevdevData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTPRJ = 3;
		static const Sbecore::uint FEEDFLSTUNT = 4;
		static const Sbecore::uint FEEDFLSTVER = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;
		static const Sbecore::uint ALL = 9;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, Sbecore::Feed* feedFLstPrj = NULL, Sbecore::Feed* feedFLstUnt = NULL, Sbecore::Feed* feedFLstVer = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		Sbecore::Feed feedFLstPrj;
		Sbecore::Feed feedFLstUnt;
		Sbecore::Feed feedFLstVer;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalLstPrjAvail(DbsWdbe* dbswdbe);
	bool evalButPrjViewActive(DbsWdbe* dbswdbe);
	bool evalLstVerAvail(DbsWdbe* dbswdbe);
	bool evalButVerViewActive(DbsWdbe* dbswdbe);
	bool evalLstUntAvail(DbsWdbe* dbswdbe);
	bool evalButUntViewActive(DbsWdbe* dbswdbe);
	bool evalButUntNewcrdActive(DbsWdbe* dbswdbe);

public:
	PnlWdbeNavDevdev(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~PnlWdbeNavDevdev();

public:
	ContIac contiac;
	StatShr statshr;

	Sbecore::Feed feedFLstPrj;
	Sbecore::Feed feedFLstUnt;
	Sbecore::Feed feedFLstVer;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshLstPrj(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshPrj(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshLstVer(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshVer(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshLstUnt(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshUnt(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refresh(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:

	void handleDpchAppWdbeInit(DbsWdbe* dbswdbe, DpchAppWdbeInit* dpchappwdbeinit, DpchEngWdbe** dpcheng);
	void handleDpchAppDataContiac(DbsWdbe* dbswdbe, ContIac* _contiac, DpchEngWdbe** dpcheng);

	void handleDpchAppDoButPrjViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButPrjNewcrdClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButVerViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButVerNewcrdClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButUntViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButUntNewcrdClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

public:
	void handleCall(DbsWdbe* dbswdbe, Sbecore::Call* call);

private:
	bool handleCallWdbeHusrRunvMod_crdUsrEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);

};

#endif
