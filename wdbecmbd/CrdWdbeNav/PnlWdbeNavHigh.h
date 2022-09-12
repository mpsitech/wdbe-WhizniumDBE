/**
	* \file PnlWdbeNavHigh.h
	* job handler for job PnlWdbeNavHigh (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

#ifndef PNLWDBENAVHIGH_H
#define PNLWDBENAVHIGH_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWdbeNavHighDo PnlWdbeNavHigh::VecVDo

#define ContIacWdbeNavHigh PnlWdbeNavHigh::ContIac
#define StatAppWdbeNavHigh PnlWdbeNavHigh::StatApp
#define StatShrWdbeNavHigh PnlWdbeNavHigh::StatShr
#define TagWdbeNavHigh PnlWdbeNavHigh::Tag

#define DpchAppWdbeNavHighData PnlWdbeNavHigh::DpchAppData
#define DpchAppWdbeNavHighDo PnlWdbeNavHigh::DpchAppDo
#define DpchEngWdbeNavHighData PnlWdbeNavHigh::DpchEngData

/**
	* PnlWdbeNavHigh
	*/
class PnlWdbeNavHigh : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVWdbeNavHighDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTPPHVIEWCLICK = 1;
		static const Sbecore::uint BUTPPHNEWCRDCLICK = 2;
		static const Sbecore::uint BUTMODVIEWCLICK = 3;
		static const Sbecore::uint BUTMODNEWCRDCLICK = 4;
		static const Sbecore::uint BUTVECVIEWCLICK = 5;
		static const Sbecore::uint BUTVECNEWCRDCLICK = 6;
		static const Sbecore::uint BUTVITVIEWCLICK = 7;
		static const Sbecore::uint BUTCMDVIEWCLICK = 8;
		static const Sbecore::uint BUTCMDNEWCRDCLICK = 9;
		static const Sbecore::uint BUTERRVIEWCLICK = 10;
		static const Sbecore::uint BUTERRNEWCRDCLICK = 11;
		static const Sbecore::uint BUTPPLVIEWCLICK = 12;
		static const Sbecore::uint BUTPPLNEWCRDCLICK = 13;
		static const Sbecore::uint BUTSEGVIEWCLICK = 14;
		static const Sbecore::uint BUTSEGNEWCRDCLICK = 15;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeNavHigh)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFLSTPPH = 1;
		static const Sbecore::uint NUMFLSTMOD = 2;
		static const Sbecore::uint NUMFLSTVEC = 3;
		static const Sbecore::uint NUMFLSTVIT = 4;
		static const Sbecore::uint NUMFLSTCMD = 5;
		static const Sbecore::uint NUMFLSTERR = 6;
		static const Sbecore::uint NUMFLSTPPL = 7;
		static const Sbecore::uint NUMFLSTSEG = 8;

	public:
		ContIac(const Sbecore::uint numFLstPph = 1, const Sbecore::uint numFLstMod = 1, const Sbecore::uint numFLstVec = 1, const Sbecore::uint numFLstVit = 1, const Sbecore::uint numFLstCmd = 1, const Sbecore::uint numFLstErr = 1, const Sbecore::uint numFLstPpl = 1, const Sbecore::uint numFLstSeg = 1);

	public:
		Sbecore::uint numFLstPph;
		Sbecore::uint numFLstMod;
		Sbecore::uint numFLstVec;
		Sbecore::uint numFLstVit;
		Sbecore::uint numFLstCmd;
		Sbecore::uint numFLstErr;
		Sbecore::uint numFLstPpl;
		Sbecore::uint numFLstSeg;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppWdbeNavHigh)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool LstPphAlt = true, const bool LstModAlt = true, const bool LstVecAlt = true, const bool LstVitAlt = true, const bool LstCmdAlt = true, const bool LstErrAlt = true, const bool LstPplAlt = true, const bool LstSegAlt = true, const Sbecore::uint LstPphNumFirstdisp = 1, const Sbecore::uint LstModNumFirstdisp = 1, const Sbecore::uint LstVecNumFirstdisp = 1, const Sbecore::uint LstVitNumFirstdisp = 1, const Sbecore::uint LstCmdNumFirstdisp = 1, const Sbecore::uint LstErrNumFirstdisp = 1, const Sbecore::uint LstPplNumFirstdisp = 1, const Sbecore::uint LstSegNumFirstdisp = 1);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool LstPphAlt = true, const bool LstModAlt = true, const bool LstVecAlt = true, const bool LstVitAlt = true, const bool LstCmdAlt = true, const bool LstErrAlt = true, const bool LstPplAlt = true, const bool LstSegAlt = true, const Sbecore::uint LstPphNumFirstdisp = 1, const Sbecore::uint LstModNumFirstdisp = 1, const Sbecore::uint LstVecNumFirstdisp = 1, const Sbecore::uint LstVitNumFirstdisp = 1, const Sbecore::uint LstCmdNumFirstdisp = 1, const Sbecore::uint LstErrNumFirstdisp = 1, const Sbecore::uint LstPplNumFirstdisp = 1, const Sbecore::uint LstSegNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWdbeNavHigh)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint LSTPPHAVAIL = 1;
		static const Sbecore::uint BUTPPHVIEWACTIVE = 2;
		static const Sbecore::uint BUTPPHNEWCRDACTIVE = 3;
		static const Sbecore::uint LSTMODAVAIL = 4;
		static const Sbecore::uint BUTMODVIEWACTIVE = 5;
		static const Sbecore::uint BUTMODNEWCRDACTIVE = 6;
		static const Sbecore::uint LSTVECAVAIL = 7;
		static const Sbecore::uint BUTVECVIEWACTIVE = 8;
		static const Sbecore::uint BUTVECNEWCRDACTIVE = 9;
		static const Sbecore::uint LSTVITAVAIL = 10;
		static const Sbecore::uint BUTVITVIEWACTIVE = 11;
		static const Sbecore::uint LSTCMDAVAIL = 12;
		static const Sbecore::uint BUTCMDVIEWACTIVE = 13;
		static const Sbecore::uint BUTCMDNEWCRDACTIVE = 14;
		static const Sbecore::uint LSTERRAVAIL = 15;
		static const Sbecore::uint BUTERRVIEWACTIVE = 16;
		static const Sbecore::uint BUTERRNEWCRDACTIVE = 17;
		static const Sbecore::uint LSTPPLAVAIL = 18;
		static const Sbecore::uint BUTPPLVIEWACTIVE = 19;
		static const Sbecore::uint BUTPPLNEWCRDACTIVE = 20;
		static const Sbecore::uint LSTSEGAVAIL = 21;
		static const Sbecore::uint BUTSEGVIEWACTIVE = 22;
		static const Sbecore::uint BUTSEGNEWCRDACTIVE = 23;

	public:
		StatShr(const bool LstPphAvail = true, const bool ButPphViewActive = true, const bool ButPphNewcrdActive = true, const bool LstModAvail = true, const bool ButModViewActive = true, const bool ButModNewcrdActive = true, const bool LstVecAvail = true, const bool ButVecViewActive = true, const bool ButVecNewcrdActive = true, const bool LstVitAvail = true, const bool ButVitViewActive = true, const bool LstCmdAvail = true, const bool ButCmdViewActive = true, const bool ButCmdNewcrdActive = true, const bool LstErrAvail = true, const bool ButErrViewActive = true, const bool ButErrNewcrdActive = true, const bool LstPplAvail = true, const bool ButPplViewActive = true, const bool ButPplNewcrdActive = true, const bool LstSegAvail = true, const bool ButSegViewActive = true, const bool ButSegNewcrdActive = true);

	public:
		bool LstPphAvail;
		bool ButPphViewActive;
		bool ButPphNewcrdActive;
		bool LstModAvail;
		bool ButModViewActive;
		bool ButModNewcrdActive;
		bool LstVecAvail;
		bool ButVecViewActive;
		bool ButVecNewcrdActive;
		bool LstVitAvail;
		bool ButVitViewActive;
		bool LstCmdAvail;
		bool ButCmdViewActive;
		bool ButCmdNewcrdActive;
		bool LstErrAvail;
		bool ButErrViewActive;
		bool ButErrNewcrdActive;
		bool LstPplAvail;
		bool ButPplViewActive;
		bool ButPplNewcrdActive;
		bool LstSegAvail;
		bool ButSegViewActive;
		bool ButSegNewcrdActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWdbeNavHigh)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWdbeNavHighData)
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
		* DpchAppDo (full: DpchAppWdbeNavHighDo)
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
		* DpchEngData (full: DpchEngWdbeNavHighData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTCMD = 3;
		static const Sbecore::uint FEEDFLSTERR = 4;
		static const Sbecore::uint FEEDFLSTMOD = 5;
		static const Sbecore::uint FEEDFLSTPPH = 6;
		static const Sbecore::uint FEEDFLSTPPL = 7;
		static const Sbecore::uint FEEDFLSTSEG = 8;
		static const Sbecore::uint FEEDFLSTVEC = 9;
		static const Sbecore::uint FEEDFLSTVIT = 10;
		static const Sbecore::uint STATAPP = 11;
		static const Sbecore::uint STATSHR = 12;
		static const Sbecore::uint TAG = 13;
		static const Sbecore::uint ALL = 14;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, Sbecore::Feed* feedFLstCmd = NULL, Sbecore::Feed* feedFLstErr = NULL, Sbecore::Feed* feedFLstMod = NULL, Sbecore::Feed* feedFLstPph = NULL, Sbecore::Feed* feedFLstPpl = NULL, Sbecore::Feed* feedFLstSeg = NULL, Sbecore::Feed* feedFLstVec = NULL, Sbecore::Feed* feedFLstVit = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		Sbecore::Feed feedFLstCmd;
		Sbecore::Feed feedFLstErr;
		Sbecore::Feed feedFLstMod;
		Sbecore::Feed feedFLstPph;
		Sbecore::Feed feedFLstPpl;
		Sbecore::Feed feedFLstSeg;
		Sbecore::Feed feedFLstVec;
		Sbecore::Feed feedFLstVit;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalLstPphAvail(DbsWdbe* dbswdbe);
	bool evalButPphViewActive(DbsWdbe* dbswdbe);
	bool evalButPphNewcrdActive(DbsWdbe* dbswdbe);
	bool evalLstModAvail(DbsWdbe* dbswdbe);
	bool evalButModViewActive(DbsWdbe* dbswdbe);
	bool evalButModNewcrdActive(DbsWdbe* dbswdbe);
	bool evalLstVecAvail(DbsWdbe* dbswdbe);
	bool evalButVecViewActive(DbsWdbe* dbswdbe);
	bool evalButVecNewcrdActive(DbsWdbe* dbswdbe);
	bool evalLstVitAvail(DbsWdbe* dbswdbe);
	bool evalButVitViewActive(DbsWdbe* dbswdbe);
	bool evalLstCmdAvail(DbsWdbe* dbswdbe);
	bool evalButCmdViewActive(DbsWdbe* dbswdbe);
	bool evalButCmdNewcrdActive(DbsWdbe* dbswdbe);
	bool evalLstErrAvail(DbsWdbe* dbswdbe);
	bool evalButErrViewActive(DbsWdbe* dbswdbe);
	bool evalButErrNewcrdActive(DbsWdbe* dbswdbe);
	bool evalLstPplAvail(DbsWdbe* dbswdbe);
	bool evalButPplViewActive(DbsWdbe* dbswdbe);
	bool evalButPplNewcrdActive(DbsWdbe* dbswdbe);
	bool evalLstSegAvail(DbsWdbe* dbswdbe);
	bool evalButSegViewActive(DbsWdbe* dbswdbe);
	bool evalButSegNewcrdActive(DbsWdbe* dbswdbe);

public:
	PnlWdbeNavHigh(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~PnlWdbeNavHigh();

public:
	ContIac contiac;
	StatShr statshr;

	Sbecore::Feed feedFLstCmd;
	Sbecore::Feed feedFLstErr;
	Sbecore::Feed feedFLstMod;
	Sbecore::Feed feedFLstPph;
	Sbecore::Feed feedFLstPpl;
	Sbecore::Feed feedFLstSeg;
	Sbecore::Feed feedFLstVec;
	Sbecore::Feed feedFLstVit;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshLstPph(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshPph(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshLstMod(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshMod(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshLstVec(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshVec(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshLstVit(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshVit(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshLstCmd(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshCmd(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshLstErr(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshErr(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshLstPpl(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshPpl(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshLstSeg(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshSeg(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refresh(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:

	void handleDpchAppWdbeInit(DbsWdbe* dbswdbe, DpchAppWdbeInit* dpchappwdbeinit, DpchEngWdbe** dpcheng);
	void handleDpchAppDataContiac(DbsWdbe* dbswdbe, ContIac* _contiac, DpchEngWdbe** dpcheng);

	void handleDpchAppDoButPphViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButPphNewcrdClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButModViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButModNewcrdClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButVecViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButVecNewcrdClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButVitViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButCmdViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButCmdNewcrdClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButErrViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButErrNewcrdClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButPplViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButPplNewcrdClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButSegViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButSegNewcrdClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

public:
	void handleCall(DbsWdbe* dbswdbe, Sbecore::Call* call);

private:
	bool handleCallWdbeHusrRunvMod_crdUsrEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);

};

#endif
