/**
	* \file PnlWdbeVerHeadbar.h
	* job handler for job PnlWdbeVerHeadbar (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef PNLWDBEVERHEADBAR_H
#define PNLWDBEVERHEADBAR_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define StgInfWdbeVerHeadbar PnlWdbeVerHeadbar::StgInf
#define TagWdbeVerHeadbar PnlWdbeVerHeadbar::Tag

#define DpchEngWdbeVerHeadbarData PnlWdbeVerHeadbar::DpchEngData

/**
	* PnlWdbeVerHeadbar
	*/
class PnlWdbeVerHeadbar : public JobWdbe {

public:
	/**
		* StgInf (full: StgInfWdbeVerHeadbar)
		*/
	class StgInf {

	public:
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* Tag (full: TagWdbeVerHeadbar)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchEngData (full: DpchEngWdbeVerHeadbarData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint STGINF = 2;
		static const Sbecore::uint TAG = 3;
		static const Sbecore::uint ALL = 4;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, const std::set<Sbecore::uint>& mask = {NONE});

	public:

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

public:
	PnlWdbeVerHeadbar(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~PnlWdbeVerHeadbar();

public:

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWdbe* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsWdbe* dbswdbe, std::set<Sbecore::uint>& moditems);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:

	void handleDpchAppWdbeInit(DbsWdbe* dbswdbe, DpchAppWdbeInit* dpchappwdbeinit, DpchEngWdbe** dpcheng);

};

#endif

