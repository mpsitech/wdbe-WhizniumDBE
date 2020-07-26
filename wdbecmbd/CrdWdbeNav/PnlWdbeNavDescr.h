/**
	* \file PnlWdbeNavDescr.h
	* job handler for job PnlWdbeNavDescr (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef PNLWDBENAVDESCR_H
#define PNLWDBENAVDESCR_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWdbeNavDescrDo PnlWdbeNavDescr::VecVDo

#define ContIacWdbeNavDescr PnlWdbeNavDescr::ContIac
#define StatAppWdbeNavDescr PnlWdbeNavDescr::StatApp
#define StatShrWdbeNavDescr PnlWdbeNavDescr::StatShr
#define TagWdbeNavDescr PnlWdbeNavDescr::Tag

#define DpchAppWdbeNavDescrData PnlWdbeNavDescr::DpchAppData
#define DpchAppWdbeNavDescrDo PnlWdbeNavDescr::DpchAppDo
#define DpchEngWdbeNavDescrData PnlWdbeNavDescr::DpchEngData

/**
	* PnlWdbeNavDescr
	*/
class PnlWdbeNavDescr : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVWdbeNavDescrDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMODVIEWCLICK = 1;
		static const Sbecore::uint BUTMODNEWCRDCLICK = 2;
		static const Sbecore::uint BUTVECVIEWCLICK = 3;
		static const Sbecore::uint BUTVECNEWCRDCLICK = 4;
		static const Sbecore::uint BUTVITVIEWCLICK = 5;
		static const Sbecore::uint BUTCMDVIEWCLICK = 6;
		static const Sbecore::uint BUTCMDNEWCRDCLICK = 7;
		static const Sbecore::uint BUTERRVIEWCLICK = 8;
		static const Sbecore::uint BUTERRNEWCRDCLICK = 9;
		static const Sbecore::uint BUTPPHVIEWCLICK = 10;
		static const Sbecore::uint BUTPPHNEWCRDCLICK = 11;
		static const Sbecore::uint BUTBNKVIEWCLICK = 12;
		static const Sbecore::uint BUTBNKNEWCRDCLICK = 13;
		static const Sbecore::uint BUTPINVIEWCLICK = 14;
		static const Sbecore::uint BUTPINNEWCRDCLICK = 15;
		static const Sbecore::uint BUTGENVIEWCLICK = 16;
		static const Sbecore::uint BUTPRTVIEWCLICK = 17;
		static const Sbecore::uint BUTSIGVIEWCLICK = 18;
		static const Sbecore::uint BUTPRCVIEWCLICK = 19;
		static const Sbecore::uint BUTFSTVIEWCLICK = 20;
		static const Sbecore::uint BUTVARVIEWCLICK = 21;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeNavDescr)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFLSTMOD = 1;
		static const Sbecore::uint NUMFLSTVEC = 2;
		static const Sbecore::uint NUMFLSTVIT = 3;
		static const Sbecore::uint NUMFLSTCMD = 4;
		static const Sbecore::uint NUMFLSTERR = 5;
		static const Sbecore::uint NUMFLSTPPH = 6;
		static const Sbecore::uint NUMFLSTBNK = 7;
		static const Sbecore::uint NUMFLSTPIN = 8;
		static const Sbecore::uint NUMFLSTGEN = 9;
		static const Sbecore::uint NUMFLSTPRT = 10;
		static const Sbecore::uint NUMFLSTSIG = 11;
		static const Sbecore::uint NUMFLSTPRC = 12;
		static const Sbecore::uint NUMFLSTFST = 13;
		static const Sbecore::uint NUMFLSTVAR = 14;

	public:
		ContIac(const Sbecore::uint numFLstMod = 1, const Sbecore::uint numFLstVec = 1, const Sbecore::uint numFLstVit = 1, const Sbecore::uint numFLstCmd = 1, const Sbecore::uint numFLstErr = 1, const Sbecore::uint numFLstPph = 1, const Sbecore::uint numFLstBnk = 1, const Sbecore::uint numFLstPin = 1, const Sbecore::uint numFLstGen = 1, const Sbecore::uint numFLstPrt = 1, const Sbecore::uint numFLstSig = 1, const Sbecore::uint numFLstPrc = 1, const Sbecore::uint numFLstFst = 1, const Sbecore::uint numFLstVar = 1);

	public:
		Sbecore::uint numFLstMod;
		Sbecore::uint numFLstVec;
		Sbecore::uint numFLstVit;
		Sbecore::uint numFLstCmd;
		Sbecore::uint numFLstErr;
		Sbecore::uint numFLstPph;
		Sbecore::uint numFLstBnk;
		Sbecore::uint numFLstPin;
		Sbecore::uint numFLstGen;
		Sbecore::uint numFLstPrt;
		Sbecore::uint numFLstSig;
		Sbecore::uint numFLstPrc;
		Sbecore::uint numFLstFst;
		Sbecore::uint numFLstVar;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppWdbeNavDescr)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool LstModAlt = true, const bool LstVecAlt = true, const bool LstVitAlt = true, const bool LstCmdAlt = true, const bool LstErrAlt = true, const bool LstPphAlt = true, const bool LstBnkAlt = true, const bool LstPinAlt = true, const bool LstGenAlt = true, const bool LstPrtAlt = true, const bool LstSigAlt = true, const bool LstPrcAlt = true, const bool LstFstAlt = true, const bool LstVarAlt = true, const Sbecore::uint LstModNumFirstdisp = 1, const Sbecore::uint LstVecNumFirstdisp = 1, const Sbecore::uint LstVitNumFirstdisp = 1, const Sbecore::uint LstCmdNumFirstdisp = 1, const Sbecore::uint LstErrNumFirstdisp = 1, const Sbecore::uint LstPphNumFirstdisp = 1, const Sbecore::uint LstBnkNumFirstdisp = 1, const Sbecore::uint LstPinNumFirstdisp = 1, const Sbecore::uint LstGenNumFirstdisp = 1, const Sbecore::uint LstPrtNumFirstdisp = 1, const Sbecore::uint LstSigNumFirstdisp = 1, const Sbecore::uint LstPrcNumFirstdisp = 1, const Sbecore::uint LstFstNumFirstdisp = 1, const Sbecore::uint LstVarNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWdbeNavDescr)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint LSTMODAVAIL = 1;
		static const Sbecore::uint BUTMODVIEWACTIVE = 2;
		static const Sbecore::uint BUTMODNEWCRDACTIVE = 3;
		static const Sbecore::uint LSTVECAVAIL = 4;
		static const Sbecore::uint BUTVECVIEWACTIVE = 5;
		static const Sbecore::uint BUTVECNEWCRDACTIVE = 6;
		static const Sbecore::uint LSTVITAVAIL = 7;
		static const Sbecore::uint BUTVITVIEWACTIVE = 8;
		static const Sbecore::uint LSTCMDAVAIL = 9;
		static const Sbecore::uint BUTCMDVIEWACTIVE = 10;
		static const Sbecore::uint BUTCMDNEWCRDACTIVE = 11;
		static const Sbecore::uint LSTERRAVAIL = 12;
		static const Sbecore::uint BUTERRVIEWACTIVE = 13;
		static const Sbecore::uint BUTERRNEWCRDACTIVE = 14;
		static const Sbecore::uint LSTPPHAVAIL = 15;
		static const Sbecore::uint BUTPPHVIEWACTIVE = 16;
		static const Sbecore::uint BUTPPHNEWCRDACTIVE = 17;
		static const Sbecore::uint LSTBNKAVAIL = 18;
		static const Sbecore::uint BUTBNKVIEWACTIVE = 19;
		static const Sbecore::uint BUTBNKNEWCRDACTIVE = 20;
		static const Sbecore::uint LSTPINAVAIL = 21;
		static const Sbecore::uint BUTPINVIEWACTIVE = 22;
		static const Sbecore::uint BUTPINNEWCRDACTIVE = 23;
		static const Sbecore::uint LSTGENAVAIL = 24;
		static const Sbecore::uint BUTGENVIEWACTIVE = 25;
		static const Sbecore::uint LSTPRTAVAIL = 26;
		static const Sbecore::uint BUTPRTVIEWACTIVE = 27;
		static const Sbecore::uint LSTSIGAVAIL = 28;
		static const Sbecore::uint BUTSIGVIEWACTIVE = 29;
		static const Sbecore::uint LSTPRCAVAIL = 30;
		static const Sbecore::uint BUTPRCVIEWACTIVE = 31;
		static const Sbecore::uint LSTFSTAVAIL = 32;
		static const Sbecore::uint BUTFSTVIEWACTIVE = 33;
		static const Sbecore::uint LSTVARAVAIL = 34;
		static const Sbecore::uint BUTVARVIEWACTIVE = 35;

	public:
		StatShr(const bool LstModAvail = true, const bool ButModViewActive = true, const bool ButModNewcrdActive = true, const bool LstVecAvail = true, const bool ButVecViewActive = true, const bool ButVecNewcrdActive = true, const bool LstVitAvail = true, const bool ButVitViewActive = true, const bool LstCmdAvail = true, const bool ButCmdViewActive = true, const bool ButCmdNewcrdActive = true, const bool LstErrAvail = true, const bool ButErrViewActive = true, const bool ButErrNewcrdActive = true, const bool LstPphAvail = true, const bool ButPphViewActive = true, const bool ButPphNewcrdActive = true, const bool LstBnkAvail = true, const bool ButBnkViewActive = true, const bool ButBnkNewcrdActive = true, const bool LstPinAvail = true, const bool ButPinViewActive = true, const bool ButPinNewcrdActive = true, const bool LstGenAvail = true, const bool ButGenViewActive = true, const bool LstPrtAvail = true, const bool ButPrtViewActive = true, const bool LstSigAvail = true, const bool ButSigViewActive = true, const bool LstPrcAvail = true, const bool ButPrcViewActive = true, const bool LstFstAvail = true, const bool ButFstViewActive = true, const bool LstVarAvail = true, const bool ButVarViewActive = true);

	public:
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
		bool LstPphAvail;
		bool ButPphViewActive;
		bool ButPphNewcrdActive;
		bool LstBnkAvail;
		bool ButBnkViewActive;
		bool ButBnkNewcrdActive;
		bool LstPinAvail;
		bool ButPinViewActive;
		bool ButPinNewcrdActive;
		bool LstGenAvail;
		bool ButGenViewActive;
		bool LstPrtAvail;
		bool ButPrtViewActive;
		bool LstSigAvail;
		bool ButSigViewActive;
		bool LstPrcAvail;
		bool ButPrcViewActive;
		bool LstFstAvail;
		bool ButFstViewActive;
		bool LstVarAvail;
		bool ButVarViewActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWdbeNavDescr)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWdbeNavDescrData)
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
		* DpchAppDo (full: DpchAppWdbeNavDescrDo)
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
		* DpchEngData (full: DpchEngWdbeNavDescrData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTBNK = 3;
		static const Sbecore::uint FEEDFLSTCMD = 4;
		static const Sbecore::uint FEEDFLSTERR = 5;
		static const Sbecore::uint FEEDFLSTFST = 6;
		static const Sbecore::uint FEEDFLSTGEN = 7;
		static const Sbecore::uint FEEDFLSTMOD = 8;
		static const Sbecore::uint FEEDFLSTPIN = 9;
		static const Sbecore::uint FEEDFLSTPPH = 10;
		static const Sbecore::uint FEEDFLSTPRC = 11;
		static const Sbecore::uint FEEDFLSTPRT = 12;
		static const Sbecore::uint FEEDFLSTSIG = 13;
		static const Sbecore::uint FEEDFLSTVAR = 14;
		static const Sbecore::uint FEEDFLSTVEC = 15;
		static const Sbecore::uint FEEDFLSTVIT = 16;
		static const Sbecore::uint STATAPP = 17;
		static const Sbecore::uint STATSHR = 18;
		static const Sbecore::uint TAG = 19;
		static const Sbecore::uint ALL = 20;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, Sbecore::Xmlio::Feed* feedFLstBnk = NULL, Sbecore::Xmlio::Feed* feedFLstCmd = NULL, Sbecore::Xmlio::Feed* feedFLstErr = NULL, Sbecore::Xmlio::Feed* feedFLstFst = NULL, Sbecore::Xmlio::Feed* feedFLstGen = NULL, Sbecore::Xmlio::Feed* feedFLstMod = NULL, Sbecore::Xmlio::Feed* feedFLstPin = NULL, Sbecore::Xmlio::Feed* feedFLstPph = NULL, Sbecore::Xmlio::Feed* feedFLstPrc = NULL, Sbecore::Xmlio::Feed* feedFLstPrt = NULL, Sbecore::Xmlio::Feed* feedFLstSig = NULL, Sbecore::Xmlio::Feed* feedFLstVar = NULL, Sbecore::Xmlio::Feed* feedFLstVec = NULL, Sbecore::Xmlio::Feed* feedFLstVit = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		Sbecore::Xmlio::Feed feedFLstBnk;
		Sbecore::Xmlio::Feed feedFLstCmd;
		Sbecore::Xmlio::Feed feedFLstErr;
		Sbecore::Xmlio::Feed feedFLstFst;
		Sbecore::Xmlio::Feed feedFLstGen;
		Sbecore::Xmlio::Feed feedFLstMod;
		Sbecore::Xmlio::Feed feedFLstPin;
		Sbecore::Xmlio::Feed feedFLstPph;
		Sbecore::Xmlio::Feed feedFLstPrc;
		Sbecore::Xmlio::Feed feedFLstPrt;
		Sbecore::Xmlio::Feed feedFLstSig;
		Sbecore::Xmlio::Feed feedFLstVar;
		Sbecore::Xmlio::Feed feedFLstVec;
		Sbecore::Xmlio::Feed feedFLstVit;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

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
	bool evalLstPphAvail(DbsWdbe* dbswdbe);
	bool evalButPphViewActive(DbsWdbe* dbswdbe);
	bool evalButPphNewcrdActive(DbsWdbe* dbswdbe);
	bool evalLstBnkAvail(DbsWdbe* dbswdbe);
	bool evalButBnkViewActive(DbsWdbe* dbswdbe);
	bool evalButBnkNewcrdActive(DbsWdbe* dbswdbe);
	bool evalLstPinAvail(DbsWdbe* dbswdbe);
	bool evalButPinViewActive(DbsWdbe* dbswdbe);
	bool evalButPinNewcrdActive(DbsWdbe* dbswdbe);
	bool evalLstGenAvail(DbsWdbe* dbswdbe);
	bool evalButGenViewActive(DbsWdbe* dbswdbe);
	bool evalLstPrtAvail(DbsWdbe* dbswdbe);
	bool evalButPrtViewActive(DbsWdbe* dbswdbe);
	bool evalLstSigAvail(DbsWdbe* dbswdbe);
	bool evalButSigViewActive(DbsWdbe* dbswdbe);
	bool evalLstPrcAvail(DbsWdbe* dbswdbe);
	bool evalButPrcViewActive(DbsWdbe* dbswdbe);
	bool evalLstFstAvail(DbsWdbe* dbswdbe);
	bool evalButFstViewActive(DbsWdbe* dbswdbe);
	bool evalLstVarAvail(DbsWdbe* dbswdbe);
	bool evalButVarViewActive(DbsWdbe* dbswdbe);

public:
	PnlWdbeNavDescr(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~PnlWdbeNavDescr();

public:
	ContIac contiac;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFLstBnk;
	Sbecore::Xmlio::Feed feedFLstCmd;
	Sbecore::Xmlio::Feed feedFLstErr;
	Sbecore::Xmlio::Feed feedFLstFst;
	Sbecore::Xmlio::Feed feedFLstGen;
	Sbecore::Xmlio::Feed feedFLstMod;
	Sbecore::Xmlio::Feed feedFLstPin;
	Sbecore::Xmlio::Feed feedFLstPph;
	Sbecore::Xmlio::Feed feedFLstPrc;
	Sbecore::Xmlio::Feed feedFLstPrt;
	Sbecore::Xmlio::Feed feedFLstSig;
	Sbecore::Xmlio::Feed feedFLstVar;
	Sbecore::Xmlio::Feed feedFLstVec;
	Sbecore::Xmlio::Feed feedFLstVit;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

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
	void refreshLstPph(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshPph(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshLstBnk(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshBnk(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshLstPin(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshPin(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshLstGen(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshGen(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshLstPrt(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshPrt(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshLstSig(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshSig(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshLstPrc(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshPrc(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshLstFst(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshFst(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshLstVar(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshVar(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refresh(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

	void updatePreset(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:

	void handleDpchAppWdbeInit(DbsWdbe* dbswdbe, DpchAppWdbeInit* dpchappwdbeinit, DpchEngWdbe** dpcheng);
	void handleDpchAppDataContiac(DbsWdbe* dbswdbe, ContIac* _contiac, DpchEngWdbe** dpcheng);

	void handleDpchAppDoButModViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButModNewcrdClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButVecViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButVecNewcrdClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButVitViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButCmdViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButCmdNewcrdClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButErrViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButErrNewcrdClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButPphViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButPphNewcrdClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButBnkViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButBnkNewcrdClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButPinViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButPinNewcrdClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButGenViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButPrtViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButSigViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButPrcViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButFstViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButVarViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

public:
	void handleCall(DbsWdbe* dbswdbe, Sbecore::Call* call);

private:
	bool handleCallWdbeHusrRunvMod_crdUsrEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);

};

#endif

