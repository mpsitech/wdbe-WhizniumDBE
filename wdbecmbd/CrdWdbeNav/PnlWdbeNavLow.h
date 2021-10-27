/**
	* \file PnlWdbeNavLow.h
	* job handler for job PnlWdbeNavLow (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

#ifndef PNLWDBENAVLOW_H
#define PNLWDBENAVLOW_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWdbeNavLowDo PnlWdbeNavLow::VecVDo

#define ContIacWdbeNavLow PnlWdbeNavLow::ContIac
#define StatAppWdbeNavLow PnlWdbeNavLow::StatApp
#define StatShrWdbeNavLow PnlWdbeNavLow::StatShr
#define TagWdbeNavLow PnlWdbeNavLow::Tag

#define DpchAppWdbeNavLowData PnlWdbeNavLow::DpchAppData
#define DpchAppWdbeNavLowDo PnlWdbeNavLow::DpchAppDo
#define DpchEngWdbeNavLowData PnlWdbeNavLow::DpchEngData

/**
	* PnlWdbeNavLow
	*/
class PnlWdbeNavLow : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVWdbeNavLowDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTBNKVIEWCLICK = 1;
		static const Sbecore::uint BUTBNKNEWCRDCLICK = 2;
		static const Sbecore::uint BUTPINVIEWCLICK = 3;
		static const Sbecore::uint BUTPINNEWCRDCLICK = 4;
		static const Sbecore::uint BUTINTVIEWCLICK = 5;
		static const Sbecore::uint BUTINTNEWCRDCLICK = 6;
		static const Sbecore::uint BUTSNSVIEWCLICK = 7;
		static const Sbecore::uint BUTVARVIEWCLICK = 8;
		static const Sbecore::uint BUTGENVIEWCLICK = 9;
		static const Sbecore::uint BUTPRTVIEWCLICK = 10;
		static const Sbecore::uint BUTSIGVIEWCLICK = 11;
		static const Sbecore::uint BUTSIGNEWCRDCLICK = 12;
		static const Sbecore::uint BUTPRCVIEWCLICK = 13;
		static const Sbecore::uint BUTFSTVIEWCLICK = 14;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeNavLow)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFLSTBNK = 1;
		static const Sbecore::uint NUMFLSTPIN = 2;
		static const Sbecore::uint NUMFLSTINT = 3;
		static const Sbecore::uint NUMFLSTSNS = 4;
		static const Sbecore::uint NUMFLSTVAR = 5;
		static const Sbecore::uint NUMFLSTGEN = 6;
		static const Sbecore::uint NUMFLSTPRT = 7;
		static const Sbecore::uint NUMFLSTSIG = 8;
		static const Sbecore::uint NUMFLSTPRC = 9;
		static const Sbecore::uint NUMFLSTFST = 10;

	public:
		ContIac(const Sbecore::uint numFLstBnk = 1, const Sbecore::uint numFLstPin = 1, const Sbecore::uint numFLstInt = 1, const Sbecore::uint numFLstSns = 1, const Sbecore::uint numFLstVar = 1, const Sbecore::uint numFLstGen = 1, const Sbecore::uint numFLstPrt = 1, const Sbecore::uint numFLstSig = 1, const Sbecore::uint numFLstPrc = 1, const Sbecore::uint numFLstFst = 1);

	public:
		Sbecore::uint numFLstBnk;
		Sbecore::uint numFLstPin;
		Sbecore::uint numFLstInt;
		Sbecore::uint numFLstSns;
		Sbecore::uint numFLstVar;
		Sbecore::uint numFLstGen;
		Sbecore::uint numFLstPrt;
		Sbecore::uint numFLstSig;
		Sbecore::uint numFLstPrc;
		Sbecore::uint numFLstFst;

	public:
		bool readJSON(Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppWdbeNavLow)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool LstBnkAlt = true, const bool LstPinAlt = true, const bool LstIntAlt = true, const bool LstSnsAlt = true, const bool LstVarAlt = true, const bool LstGenAlt = true, const bool LstPrtAlt = true, const bool LstSigAlt = true, const bool LstPrcAlt = true, const bool LstFstAlt = true, const Sbecore::uint LstBnkNumFirstdisp = 1, const Sbecore::uint LstPinNumFirstdisp = 1, const Sbecore::uint LstIntNumFirstdisp = 1, const Sbecore::uint LstSnsNumFirstdisp = 1, const Sbecore::uint LstVarNumFirstdisp = 1, const Sbecore::uint LstGenNumFirstdisp = 1, const Sbecore::uint LstPrtNumFirstdisp = 1, const Sbecore::uint LstSigNumFirstdisp = 1, const Sbecore::uint LstPrcNumFirstdisp = 1, const Sbecore::uint LstFstNumFirstdisp = 1);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool LstBnkAlt = true, const bool LstPinAlt = true, const bool LstIntAlt = true, const bool LstSnsAlt = true, const bool LstVarAlt = true, const bool LstGenAlt = true, const bool LstPrtAlt = true, const bool LstSigAlt = true, const bool LstPrcAlt = true, const bool LstFstAlt = true, const Sbecore::uint LstBnkNumFirstdisp = 1, const Sbecore::uint LstPinNumFirstdisp = 1, const Sbecore::uint LstIntNumFirstdisp = 1, const Sbecore::uint LstSnsNumFirstdisp = 1, const Sbecore::uint LstVarNumFirstdisp = 1, const Sbecore::uint LstGenNumFirstdisp = 1, const Sbecore::uint LstPrtNumFirstdisp = 1, const Sbecore::uint LstSigNumFirstdisp = 1, const Sbecore::uint LstPrcNumFirstdisp = 1, const Sbecore::uint LstFstNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWdbeNavLow)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint LSTBNKAVAIL = 1;
		static const Sbecore::uint BUTBNKVIEWACTIVE = 2;
		static const Sbecore::uint BUTBNKNEWCRDACTIVE = 3;
		static const Sbecore::uint LSTPINAVAIL = 4;
		static const Sbecore::uint BUTPINVIEWACTIVE = 5;
		static const Sbecore::uint BUTPINNEWCRDACTIVE = 6;
		static const Sbecore::uint LSTINTAVAIL = 7;
		static const Sbecore::uint BUTINTVIEWACTIVE = 8;
		static const Sbecore::uint BUTINTNEWCRDACTIVE = 9;
		static const Sbecore::uint LSTSNSAVAIL = 10;
		static const Sbecore::uint BUTSNSVIEWACTIVE = 11;
		static const Sbecore::uint LSTVARAVAIL = 12;
		static const Sbecore::uint BUTVARVIEWACTIVE = 13;
		static const Sbecore::uint LSTGENAVAIL = 14;
		static const Sbecore::uint BUTGENVIEWACTIVE = 15;
		static const Sbecore::uint LSTPRTAVAIL = 16;
		static const Sbecore::uint BUTPRTVIEWACTIVE = 17;
		static const Sbecore::uint LSTSIGAVAIL = 18;
		static const Sbecore::uint BUTSIGVIEWACTIVE = 19;
		static const Sbecore::uint BUTSIGNEWCRDACTIVE = 20;
		static const Sbecore::uint LSTPRCAVAIL = 21;
		static const Sbecore::uint BUTPRCVIEWACTIVE = 22;
		static const Sbecore::uint LSTFSTAVAIL = 23;
		static const Sbecore::uint BUTFSTVIEWACTIVE = 24;

	public:
		StatShr(const bool LstBnkAvail = true, const bool ButBnkViewActive = true, const bool ButBnkNewcrdActive = true, const bool LstPinAvail = true, const bool ButPinViewActive = true, const bool ButPinNewcrdActive = true, const bool LstIntAvail = true, const bool ButIntViewActive = true, const bool ButIntNewcrdActive = true, const bool LstSnsAvail = true, const bool ButSnsViewActive = true, const bool LstVarAvail = true, const bool ButVarViewActive = true, const bool LstGenAvail = true, const bool ButGenViewActive = true, const bool LstPrtAvail = true, const bool ButPrtViewActive = true, const bool LstSigAvail = true, const bool ButSigViewActive = true, const bool ButSigNewcrdActive = true, const bool LstPrcAvail = true, const bool ButPrcViewActive = true, const bool LstFstAvail = true, const bool ButFstViewActive = true);

	public:
		bool LstBnkAvail;
		bool ButBnkViewActive;
		bool ButBnkNewcrdActive;
		bool LstPinAvail;
		bool ButPinViewActive;
		bool ButPinNewcrdActive;
		bool LstIntAvail;
		bool ButIntViewActive;
		bool ButIntNewcrdActive;
		bool LstSnsAvail;
		bool ButSnsViewActive;
		bool LstVarAvail;
		bool ButVarViewActive;
		bool LstGenAvail;
		bool ButGenViewActive;
		bool LstPrtAvail;
		bool ButPrtViewActive;
		bool LstSigAvail;
		bool ButSigViewActive;
		bool ButSigNewcrdActive;
		bool LstPrcAvail;
		bool ButPrcViewActive;
		bool LstFstAvail;
		bool ButFstViewActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWdbeNavLow)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWdbeNavLowData)
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

		void readJSON(Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWdbeNavLowDo)
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
		* DpchEngData (full: DpchEngWdbeNavLowData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTBNK = 3;
		static const Sbecore::uint FEEDFLSTFST = 4;
		static const Sbecore::uint FEEDFLSTGEN = 5;
		static const Sbecore::uint FEEDFLSTINT = 6;
		static const Sbecore::uint FEEDFLSTPIN = 7;
		static const Sbecore::uint FEEDFLSTPRC = 8;
		static const Sbecore::uint FEEDFLSTPRT = 9;
		static const Sbecore::uint FEEDFLSTSIG = 10;
		static const Sbecore::uint FEEDFLSTSNS = 11;
		static const Sbecore::uint FEEDFLSTVAR = 12;
		static const Sbecore::uint STATAPP = 13;
		static const Sbecore::uint STATSHR = 14;
		static const Sbecore::uint TAG = 15;
		static const Sbecore::uint ALL = 16;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, Sbecore::Feed* feedFLstBnk = NULL, Sbecore::Feed* feedFLstFst = NULL, Sbecore::Feed* feedFLstGen = NULL, Sbecore::Feed* feedFLstInt = NULL, Sbecore::Feed* feedFLstPin = NULL, Sbecore::Feed* feedFLstPrc = NULL, Sbecore::Feed* feedFLstPrt = NULL, Sbecore::Feed* feedFLstSig = NULL, Sbecore::Feed* feedFLstSns = NULL, Sbecore::Feed* feedFLstVar = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		Sbecore::Feed feedFLstBnk;
		Sbecore::Feed feedFLstFst;
		Sbecore::Feed feedFLstGen;
		Sbecore::Feed feedFLstInt;
		Sbecore::Feed feedFLstPin;
		Sbecore::Feed feedFLstPrc;
		Sbecore::Feed feedFLstPrt;
		Sbecore::Feed feedFLstSig;
		Sbecore::Feed feedFLstSns;
		Sbecore::Feed feedFLstVar;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeJSON(const Sbecore::uint ixWdbeVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalLstBnkAvail(DbsWdbe* dbswdbe);
	bool evalButBnkViewActive(DbsWdbe* dbswdbe);
	bool evalButBnkNewcrdActive(DbsWdbe* dbswdbe);
	bool evalLstPinAvail(DbsWdbe* dbswdbe);
	bool evalButPinViewActive(DbsWdbe* dbswdbe);
	bool evalButPinNewcrdActive(DbsWdbe* dbswdbe);
	bool evalLstIntAvail(DbsWdbe* dbswdbe);
	bool evalButIntViewActive(DbsWdbe* dbswdbe);
	bool evalButIntNewcrdActive(DbsWdbe* dbswdbe);
	bool evalLstSnsAvail(DbsWdbe* dbswdbe);
	bool evalButSnsViewActive(DbsWdbe* dbswdbe);
	bool evalLstVarAvail(DbsWdbe* dbswdbe);
	bool evalButVarViewActive(DbsWdbe* dbswdbe);
	bool evalLstGenAvail(DbsWdbe* dbswdbe);
	bool evalButGenViewActive(DbsWdbe* dbswdbe);
	bool evalLstPrtAvail(DbsWdbe* dbswdbe);
	bool evalButPrtViewActive(DbsWdbe* dbswdbe);
	bool evalLstSigAvail(DbsWdbe* dbswdbe);
	bool evalButSigViewActive(DbsWdbe* dbswdbe);
	bool evalButSigNewcrdActive(DbsWdbe* dbswdbe);
	bool evalLstPrcAvail(DbsWdbe* dbswdbe);
	bool evalButPrcViewActive(DbsWdbe* dbswdbe);
	bool evalLstFstAvail(DbsWdbe* dbswdbe);
	bool evalButFstViewActive(DbsWdbe* dbswdbe);

public:
	PnlWdbeNavLow(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~PnlWdbeNavLow();

public:
	ContIac contiac;
	StatShr statshr;

	Sbecore::Feed feedFLstBnk;
	Sbecore::Feed feedFLstFst;
	Sbecore::Feed feedFLstGen;
	Sbecore::Feed feedFLstInt;
	Sbecore::Feed feedFLstPin;
	Sbecore::Feed feedFLstPrc;
	Sbecore::Feed feedFLstPrt;
	Sbecore::Feed feedFLstSig;
	Sbecore::Feed feedFLstSns;
	Sbecore::Feed feedFLstVar;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshLstBnk(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshBnk(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshLstPin(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshPin(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshLstInt(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshInt(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshLstSns(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshSns(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshLstVar(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshVar(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
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
	void refresh(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:

	void handleDpchAppWdbeInit(DbsWdbe* dbswdbe, DpchAppWdbeInit* dpchappwdbeinit, DpchEngWdbe** dpcheng);
	void handleDpchAppDataContiac(DbsWdbe* dbswdbe, ContIac* _contiac, DpchEngWdbe** dpcheng);

	void handleDpchAppDoButBnkViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButBnkNewcrdClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButPinViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButPinNewcrdClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButIntViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButIntNewcrdClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButSnsViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButVarViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButGenViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButPrtViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButSigViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButSigNewcrdClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButPrcViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButFstViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

public:
	void handleCall(DbsWdbe* dbswdbe, Sbecore::Call* call);

private:
	bool handleCallWdbeHusrRunvMod_crdUsrEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);

};

#endif
