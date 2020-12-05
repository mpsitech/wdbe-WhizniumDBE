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
		static const Sbecore::uint BUTSYSVIEWCLICK = 5;
		static const Sbecore::uint BUTSYSNEWCRDCLICK = 6;
		static const Sbecore::uint BUTTRGVIEWCLICK = 7;
		static const Sbecore::uint BUTTRGNEWCRDCLICK = 8;
		static const Sbecore::uint BUTUNTVIEWCLICK = 9;
		static const Sbecore::uint BUTUNTNEWCRDCLICK = 10;
		static const Sbecore::uint BUTRLSVIEWCLICK = 11;
		static const Sbecore::uint BUTRLSNEWCRDCLICK = 12;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeNavDevdev)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFLSTPRJ = 1;
		static const Sbecore::uint NUMFLSTVER = 2;
		static const Sbecore::uint NUMFLSTSYS = 3;
		static const Sbecore::uint NUMFLSTTRG = 4;
		static const Sbecore::uint NUMFLSTUNT = 5;
		static const Sbecore::uint NUMFLSTRLS = 6;

	public:
		ContIac(const Sbecore::uint numFLstPrj = 1, const Sbecore::uint numFLstVer = 1, const Sbecore::uint numFLstSys = 1, const Sbecore::uint numFLstTrg = 1, const Sbecore::uint numFLstUnt = 1, const Sbecore::uint numFLstRls = 1);

	public:
		Sbecore::uint numFLstPrj;
		Sbecore::uint numFLstVer;
		Sbecore::uint numFLstSys;
		Sbecore::uint numFLstTrg;
		Sbecore::uint numFLstUnt;
		Sbecore::uint numFLstRls;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppWdbeNavDevdev)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool LstPrjAlt = true, const bool LstVerAlt = true, const bool LstSysAlt = true, const bool LstTrgAlt = true, const bool LstUntAlt = true, const bool LstRlsAlt = true, const Sbecore::uint LstPrjNumFirstdisp = 1, const Sbecore::uint LstVerNumFirstdisp = 1, const Sbecore::uint LstSysNumFirstdisp = 1, const Sbecore::uint LstTrgNumFirstdisp = 1, const Sbecore::uint LstUntNumFirstdisp = 1, const Sbecore::uint LstRlsNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWdbeNavDevdev)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint LSTPRJAVAIL = 1;
		static const Sbecore::uint BUTPRJVIEWACTIVE = 2;
		static const Sbecore::uint LSTVERAVAIL = 3;
		static const Sbecore::uint BUTVERVIEWACTIVE = 4;
		static const Sbecore::uint LSTSYSAVAIL = 5;
		static const Sbecore::uint BUTSYSVIEWACTIVE = 6;
		static const Sbecore::uint BUTSYSNEWCRDACTIVE = 7;
		static const Sbecore::uint LSTTRGAVAIL = 8;
		static const Sbecore::uint BUTTRGVIEWACTIVE = 9;
		static const Sbecore::uint BUTTRGNEWCRDACTIVE = 10;
		static const Sbecore::uint LSTUNTAVAIL = 11;
		static const Sbecore::uint BUTUNTVIEWACTIVE = 12;
		static const Sbecore::uint BUTUNTNEWCRDACTIVE = 13;
		static const Sbecore::uint LSTRLSAVAIL = 14;
		static const Sbecore::uint BUTRLSVIEWACTIVE = 15;
		static const Sbecore::uint BUTRLSNEWCRDACTIVE = 16;

	public:
		StatShr(const bool LstPrjAvail = true, const bool ButPrjViewActive = true, const bool LstVerAvail = true, const bool ButVerViewActive = true, const bool LstSysAvail = true, const bool ButSysViewActive = true, const bool ButSysNewcrdActive = true, const bool LstTrgAvail = true, const bool ButTrgViewActive = true, const bool ButTrgNewcrdActive = true, const bool LstUntAvail = true, const bool ButUntViewActive = true, const bool ButUntNewcrdActive = true, const bool LstRlsAvail = true, const bool ButRlsViewActive = true, const bool ButRlsNewcrdActive = true);

	public:
		bool LstPrjAvail;
		bool ButPrjViewActive;
		bool LstVerAvail;
		bool ButVerViewActive;
		bool LstSysAvail;
		bool ButSysViewActive;
		bool ButSysNewcrdActive;
		bool LstTrgAvail;
		bool ButTrgViewActive;
		bool ButTrgNewcrdActive;
		bool LstUntAvail;
		bool ButUntViewActive;
		bool ButUntNewcrdActive;
		bool LstRlsAvail;
		bool ButRlsViewActive;
		bool ButRlsNewcrdActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWdbeNavDevdev)
		*/
	class Tag {

	public:
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
		static const Sbecore::uint FEEDFLSTRLS = 4;
		static const Sbecore::uint FEEDFLSTSYS = 5;
		static const Sbecore::uint FEEDFLSTTRG = 6;
		static const Sbecore::uint FEEDFLSTUNT = 7;
		static const Sbecore::uint FEEDFLSTVER = 8;
		static const Sbecore::uint STATAPP = 9;
		static const Sbecore::uint STATSHR = 10;
		static const Sbecore::uint TAG = 11;
		static const Sbecore::uint ALL = 12;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, Sbecore::Xmlio::Feed* feedFLstPrj = NULL, Sbecore::Xmlio::Feed* feedFLstRls = NULL, Sbecore::Xmlio::Feed* feedFLstSys = NULL, Sbecore::Xmlio::Feed* feedFLstTrg = NULL, Sbecore::Xmlio::Feed* feedFLstUnt = NULL, Sbecore::Xmlio::Feed* feedFLstVer = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		Sbecore::Xmlio::Feed feedFLstPrj;
		Sbecore::Xmlio::Feed feedFLstRls;
		Sbecore::Xmlio::Feed feedFLstSys;
		Sbecore::Xmlio::Feed feedFLstTrg;
		Sbecore::Xmlio::Feed feedFLstUnt;
		Sbecore::Xmlio::Feed feedFLstVer;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalLstPrjAvail(DbsWdbe* dbswdbe);
	bool evalButPrjViewActive(DbsWdbe* dbswdbe);
	bool evalLstVerAvail(DbsWdbe* dbswdbe);
	bool evalButVerViewActive(DbsWdbe* dbswdbe);
	bool evalLstSysAvail(DbsWdbe* dbswdbe);
	bool evalButSysViewActive(DbsWdbe* dbswdbe);
	bool evalButSysNewcrdActive(DbsWdbe* dbswdbe);
	bool evalLstTrgAvail(DbsWdbe* dbswdbe);
	bool evalButTrgViewActive(DbsWdbe* dbswdbe);
	bool evalButTrgNewcrdActive(DbsWdbe* dbswdbe);
	bool evalLstUntAvail(DbsWdbe* dbswdbe);
	bool evalButUntViewActive(DbsWdbe* dbswdbe);
	bool evalButUntNewcrdActive(DbsWdbe* dbswdbe);
	bool evalLstRlsAvail(DbsWdbe* dbswdbe);
	bool evalButRlsViewActive(DbsWdbe* dbswdbe);
	bool evalButRlsNewcrdActive(DbsWdbe* dbswdbe);

public:
	PnlWdbeNavDevdev(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~PnlWdbeNavDevdev();

public:
	ContIac contiac;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFLstPrj;
	Sbecore::Xmlio::Feed feedFLstRls;
	Sbecore::Xmlio::Feed feedFLstSys;
	Sbecore::Xmlio::Feed feedFLstTrg;
	Sbecore::Xmlio::Feed feedFLstUnt;
	Sbecore::Xmlio::Feed feedFLstVer;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshLstPrj(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshPrj(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshLstVer(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshVer(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshLstSys(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshSys(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshLstTrg(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshTrg(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshLstUnt(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshUnt(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
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

	void handleDpchAppDoButPrjViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButPrjNewcrdClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButVerViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButVerNewcrdClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButSysViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButSysNewcrdClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButTrgViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButTrgNewcrdClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButUntViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButUntNewcrdClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButRlsViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButRlsNewcrdClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

public:
	void handleCall(DbsWdbe* dbswdbe, Sbecore::Call* call);

private:
	bool handleCallWdbeHusrRunvMod_crdUsrEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);

};

#endif



