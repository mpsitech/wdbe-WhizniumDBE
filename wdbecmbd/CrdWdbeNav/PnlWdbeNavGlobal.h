/**
	* \file PnlWdbeNavGlobal.h
	* job handler for job PnlWdbeNavGlobal (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBENAVGLOBAL_H
#define PNLWDBENAVGLOBAL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWdbeNavGlobalDo PnlWdbeNavGlobal::VecVDo

#define ContIacWdbeNavGlobal PnlWdbeNavGlobal::ContIac
#define StatAppWdbeNavGlobal PnlWdbeNavGlobal::StatApp
#define StatShrWdbeNavGlobal PnlWdbeNavGlobal::StatShr
#define TagWdbeNavGlobal PnlWdbeNavGlobal::Tag

#define DpchAppWdbeNavGlobalData PnlWdbeNavGlobal::DpchAppData
#define DpchAppWdbeNavGlobalDo PnlWdbeNavGlobal::DpchAppDo
#define DpchEngWdbeNavGlobalData PnlWdbeNavGlobal::DpchEngData

/**
	* PnlWdbeNavGlobal
	*/
class PnlWdbeNavGlobal : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVWdbeNavGlobalDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMCHVIEWCLICK = 1;
		static const Sbecore::uint BUTMCHNEWCRDCLICK = 2;
		static const Sbecore::uint BUTLIBVIEWCLICK = 3;
		static const Sbecore::uint BUTLIBNEWCRDCLICK = 4;
		static const Sbecore::uint BUTFAMVIEWCLICK = 5;
		static const Sbecore::uint BUTFAMNEWCRDCLICK = 6;
		static const Sbecore::uint BUTSILVIEWCLICK = 7;
		static const Sbecore::uint BUTSILNEWCRDCLICK = 8;
		static const Sbecore::uint BUTMTPVIEWCLICK = 9;
		static const Sbecore::uint BUTMTPNEWCRDCLICK = 10;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeNavGlobal)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFLSTMCH = 1;
		static const Sbecore::uint NUMFLSTLIB = 2;
		static const Sbecore::uint NUMFLSTFAM = 3;
		static const Sbecore::uint NUMFLSTSIL = 4;
		static const Sbecore::uint NUMFLSTMTP = 5;

	public:
		ContIac(const Sbecore::uint numFLstMch = 1, const Sbecore::uint numFLstLib = 1, const Sbecore::uint numFLstFam = 1, const Sbecore::uint numFLstSil = 1, const Sbecore::uint numFLstMtp = 1);

	public:
		Sbecore::uint numFLstMch;
		Sbecore::uint numFLstLib;
		Sbecore::uint numFLstFam;
		Sbecore::uint numFLstSil;
		Sbecore::uint numFLstMtp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppWdbeNavGlobal)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool LstMchAlt = true, const bool LstLibAlt = true, const bool LstFamAlt = true, const bool LstSilAlt = true, const bool LstMtpAlt = true, const Sbecore::uint LstMchNumFirstdisp = 1, const Sbecore::uint LstLibNumFirstdisp = 1, const Sbecore::uint LstFamNumFirstdisp = 1, const Sbecore::uint LstSilNumFirstdisp = 1, const Sbecore::uint LstMtpNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWdbeNavGlobal)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint LSTMCHAVAIL = 1;
		static const Sbecore::uint BUTMCHVIEWACTIVE = 2;
		static const Sbecore::uint LSTLIBAVAIL = 3;
		static const Sbecore::uint BUTLIBVIEWACTIVE = 4;
		static const Sbecore::uint LSTFAMAVAIL = 5;
		static const Sbecore::uint BUTFAMVIEWACTIVE = 6;
		static const Sbecore::uint LSTSILAVAIL = 7;
		static const Sbecore::uint BUTSILVIEWACTIVE = 8;
		static const Sbecore::uint LSTMTPAVAIL = 9;
		static const Sbecore::uint BUTMTPVIEWACTIVE = 10;

	public:
		StatShr(const bool LstMchAvail = true, const bool ButMchViewActive = true, const bool LstLibAvail = true, const bool ButLibViewActive = true, const bool LstFamAvail = true, const bool ButFamViewActive = true, const bool LstSilAvail = true, const bool ButSilViewActive = true, const bool LstMtpAvail = true, const bool ButMtpViewActive = true);

	public:
		bool LstMchAvail;
		bool ButMchViewActive;
		bool LstLibAvail;
		bool ButLibViewActive;
		bool LstFamAvail;
		bool ButFamViewActive;
		bool LstSilAvail;
		bool ButSilViewActive;
		bool LstMtpAvail;
		bool ButMtpViewActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWdbeNavGlobal)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWdbeNavGlobalData)
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
		* DpchAppDo (full: DpchAppWdbeNavGlobalDo)
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
		* DpchEngData (full: DpchEngWdbeNavGlobalData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTFAM = 3;
		static const Sbecore::uint FEEDFLSTLIB = 4;
		static const Sbecore::uint FEEDFLSTMCH = 5;
		static const Sbecore::uint FEEDFLSTMTP = 6;
		static const Sbecore::uint FEEDFLSTSIL = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint TAG = 10;
		static const Sbecore::uint ALL = 11;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, Sbecore::Xmlio::Feed* feedFLstFam = NULL, Sbecore::Xmlio::Feed* feedFLstLib = NULL, Sbecore::Xmlio::Feed* feedFLstMch = NULL, Sbecore::Xmlio::Feed* feedFLstMtp = NULL, Sbecore::Xmlio::Feed* feedFLstSil = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		Sbecore::Xmlio::Feed feedFLstFam;
		Sbecore::Xmlio::Feed feedFLstLib;
		Sbecore::Xmlio::Feed feedFLstMch;
		Sbecore::Xmlio::Feed feedFLstMtp;
		Sbecore::Xmlio::Feed feedFLstSil;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalLstMchAvail(DbsWdbe* dbswdbe);
	bool evalButMchViewActive(DbsWdbe* dbswdbe);
	bool evalLstLibAvail(DbsWdbe* dbswdbe);
	bool evalButLibViewActive(DbsWdbe* dbswdbe);
	bool evalLstFamAvail(DbsWdbe* dbswdbe);
	bool evalButFamViewActive(DbsWdbe* dbswdbe);
	bool evalLstSilAvail(DbsWdbe* dbswdbe);
	bool evalButSilViewActive(DbsWdbe* dbswdbe);
	bool evalLstMtpAvail(DbsWdbe* dbswdbe);
	bool evalButMtpViewActive(DbsWdbe* dbswdbe);

public:
	PnlWdbeNavGlobal(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~PnlWdbeNavGlobal();

public:
	ContIac contiac;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFLstFam;
	Sbecore::Xmlio::Feed feedFLstLib;
	Sbecore::Xmlio::Feed feedFLstMch;
	Sbecore::Xmlio::Feed feedFLstMtp;
	Sbecore::Xmlio::Feed feedFLstSil;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshLstMch(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshMch(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshLstLib(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshLib(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshLstFam(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshFam(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshLstSil(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshSil(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshLstMtp(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshMtp(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refresh(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:

	void handleDpchAppWdbeInit(DbsWdbe* dbswdbe, DpchAppWdbeInit* dpchappwdbeinit, DpchEngWdbe** dpcheng);
	void handleDpchAppDataContiac(DbsWdbe* dbswdbe, ContIac* _contiac, DpchEngWdbe** dpcheng);

	void handleDpchAppDoButMchViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButMchNewcrdClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButLibViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButLibNewcrdClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButFamViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButFamNewcrdClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButSilViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButSilNewcrdClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButMtpViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButMtpNewcrdClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

public:
	void handleCall(DbsWdbe* dbswdbe, Sbecore::Call* call);

private:
	bool handleCallWdbeHusrRunvMod_crdUsrEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);

};

#endif
