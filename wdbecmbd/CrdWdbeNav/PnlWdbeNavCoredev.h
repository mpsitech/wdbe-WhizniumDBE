/**
	* \file PnlWdbeNavCoredev.h
	* job handler for job PnlWdbeNavCoredev (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef PNLWDBENAVCOREDEV_H
#define PNLWDBENAVCOREDEV_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWdbeNavCoredevDo PnlWdbeNavCoredev::VecVDo

#define ContIacWdbeNavCoredev PnlWdbeNavCoredev::ContIac
#define StatAppWdbeNavCoredev PnlWdbeNavCoredev::StatApp
#define StatShrWdbeNavCoredev PnlWdbeNavCoredev::StatShr
#define TagWdbeNavCoredev PnlWdbeNavCoredev::Tag

#define DpchAppWdbeNavCoredevData PnlWdbeNavCoredev::DpchAppData
#define DpchAppWdbeNavCoredevDo PnlWdbeNavCoredev::DpchAppDo
#define DpchEngWdbeNavCoredevData PnlWdbeNavCoredev::DpchEngData

/**
	* PnlWdbeNavCoredev
	*/
class PnlWdbeNavCoredev : public JobWdbe {

public:
	/**
		* VecVDo (full: VecVWdbeNavCoredevDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTCPRVIEWCLICK = 1;
		static const Sbecore::uint BUTCPRNEWCRDCLICK = 2;
		static const Sbecore::uint BUTCVRVIEWCLICK = 3;
		static const Sbecore::uint BUTCVRNEWCRDCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbeNavCoredev)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFLSTCPR = 1;
		static const Sbecore::uint NUMFLSTCVR = 2;

	public:
		ContIac(const Sbecore::uint numFLstCpr = 1, const Sbecore::uint numFLstCvr = 1);

	public:
		Sbecore::uint numFLstCpr;
		Sbecore::uint numFLstCvr;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppWdbeNavCoredev)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool LstCprAlt = true, const bool LstCvrAlt = true, const Sbecore::uint LstCprNumFirstdisp = 1, const Sbecore::uint LstCvrNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWdbeNavCoredev)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint LSTCPRAVAIL = 1;
		static const Sbecore::uint BUTCPRVIEWACTIVE = 2;
		static const Sbecore::uint LSTCVRAVAIL = 3;
		static const Sbecore::uint BUTCVRVIEWACTIVE = 4;

	public:
		StatShr(const bool LstCprAvail = true, const bool ButCprViewActive = true, const bool LstCvrAvail = true, const bool ButCvrViewActive = true);

	public:
		bool LstCprAvail;
		bool ButCprViewActive;
		bool LstCvrAvail;
		bool ButCvrViewActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWdbeNavCoredev)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWdbeNavCoredevData)
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
		* DpchAppDo (full: DpchAppWdbeNavCoredevDo)
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
		* DpchEngData (full: DpchEngWdbeNavCoredevData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTCPR = 3;
		static const Sbecore::uint FEEDFLSTCVR = 4;
		static const Sbecore::uint STATAPP = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint TAG = 7;
		static const Sbecore::uint ALL = 8;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, Sbecore::Xmlio::Feed* feedFLstCpr = NULL, Sbecore::Xmlio::Feed* feedFLstCvr = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		Sbecore::Xmlio::Feed feedFLstCpr;
		Sbecore::Xmlio::Feed feedFLstCvr;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalLstCprAvail(DbsWdbe* dbswdbe);
	bool evalButCprViewActive(DbsWdbe* dbswdbe);
	bool evalLstCvrAvail(DbsWdbe* dbswdbe);
	bool evalButCvrViewActive(DbsWdbe* dbswdbe);

public:
	PnlWdbeNavCoredev(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~PnlWdbeNavCoredev();

public:
	ContIac contiac;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFLstCpr;
	Sbecore::Xmlio::Feed feedFLstCvr;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshLstCpr(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshCpr(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshLstCvr(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refreshCvr(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);
	void refresh(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

	void updatePreset(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:

	void handleDpchAppWdbeInit(DbsWdbe* dbswdbe, DpchAppWdbeInit* dpchappwdbeinit, DpchEngWdbe** dpcheng);
	void handleDpchAppDataContiac(DbsWdbe* dbswdbe, ContIac* _contiac, DpchEngWdbe** dpcheng);

	void handleDpchAppDoButCprViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButCprNewcrdClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButCvrViewClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);
	void handleDpchAppDoButCvrNewcrdClick(DbsWdbe* dbswdbe, DpchEngWdbe** dpcheng);

public:
	void handleCall(DbsWdbe* dbswdbe, Sbecore::Call* call);

private:
	bool handleCallWdbeHusrRunvMod_crdUsrEq(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);

};

#endif

