/**
	* \file PnlWdbeNavHeadbar.h
	* job handler for job PnlWdbeNavHeadbar (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWDBENAVHEADBAR_H
#define PNLWDBENAVHEADBAR_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define StatShrWdbeNavHeadbar PnlWdbeNavHeadbar::StatShr
#define StgInfWdbeNavHeadbar PnlWdbeNavHeadbar::StgInf
#define TagWdbeNavHeadbar PnlWdbeNavHeadbar::Tag

#define DpchEngWdbeNavHeadbarData PnlWdbeNavHeadbar::DpchEngData

/**
	* PnlWdbeNavHeadbar
	*/
class PnlWdbeNavHeadbar : public JobWdbe {

public:
	/**
		* StatShr (full: StatShrWdbeNavHeadbar)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint MENCRDAVAIL = 1;

	public:
		StatShr(const bool MenCrdAvail = true);

	public:
		bool MenCrdAvail;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* StgInf (full: StgInfWdbeNavHeadbar)
		*/
	class StgInf {

	public:
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* Tag (full: TagWdbeNavHeadbar)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchEngData (full: DpchEngWdbeNavHeadbarData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint STATSHR = 2;
		static const Sbecore::uint STGINF = 3;
		static const Sbecore::uint TAG = 4;
		static const Sbecore::uint ALL = 5;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

	bool evalMenCrdAvail(DbsWdbe* dbswdbe);
	bool evalMspCrd1Avail(DbsWdbe* dbswdbe);
	bool evalMitCrdUsgAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdUsrAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdPrsAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdFilAvail(DbsWdbe* dbswdbe);
	bool evalMspCrd2Avail(DbsWdbe* dbswdbe);
	bool evalMitCrdMchAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdLibAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdFamAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdSilAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdMtpAvail(DbsWdbe* dbswdbe);
	bool evalMspCrd3Avail(DbsWdbe* dbswdbe);
	bool evalMitCrdPrjAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdVerAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdSysAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdTrgAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdUntAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdRlsAvail(DbsWdbe* dbswdbe);
	bool evalMspCrd4Avail(DbsWdbe* dbswdbe);
	bool evalMitCrdCprAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdCvrAvail(DbsWdbe* dbswdbe);
	bool evalMspCrd5Avail(DbsWdbe* dbswdbe);
	bool evalMitCrdModAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdVecAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdCmdAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdErrAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdPphAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdBnkAvail(DbsWdbe* dbswdbe);
	bool evalMitCrdPinAvail(DbsWdbe* dbswdbe);
	bool evalMspCrd6Avail(DbsWdbe* dbswdbe);
	bool evalMitCrdUtlAvail(DbsWdbe* dbswdbe);

public:
	PnlWdbeNavHeadbar(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~PnlWdbeNavHeadbar();

public:
	StatShr statshr;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems, const bool unmute = false);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:

	void handleDpchAppWdbeInit(DbsWdbe* dbswdbe, DpchAppWdbeInit* dpchappwdbeinit, DpchEngWdbe** dpcheng);

};

#endif



