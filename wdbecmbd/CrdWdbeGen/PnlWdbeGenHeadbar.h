/**
	* \file PnlWdbeGenHeadbar.h
	* job handler for job PnlWdbeGenHeadbar (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef PNLWDBEGENHEADBAR_H
#define PNLWDBEGENHEADBAR_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define StgInfWdbeGenHeadbar PnlWdbeGenHeadbar::StgInf
#define TagWdbeGenHeadbar PnlWdbeGenHeadbar::Tag

#define DpchEngWdbeGenHeadbarData PnlWdbeGenHeadbar::DpchEngData

/**
	* PnlWdbeGenHeadbar
	*/
class PnlWdbeGenHeadbar : public JobWdbe {

public:
	/**
		* StgInf (full: StgInfWdbeGenHeadbar)
		*/
	class StgInf {

	public:
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* Tag (full: TagWdbeGenHeadbar)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchEngData (full: DpchEngWdbeGenHeadbarData)
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
	PnlWdbeGenHeadbar(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~PnlWdbeGenHeadbar();

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

