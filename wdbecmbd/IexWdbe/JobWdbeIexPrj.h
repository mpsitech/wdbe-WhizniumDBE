/**
	* \file JobWdbeIexPrj.h
	* job handler for job JobWdbeIexPrj (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef JOBWDBEIEXPRJ_H
#define JOBWDBEIEXPRJ_H

#include "IexWdbePrj.h"

// IP include.cust --- INSERT

#define VecVJobWdbeIexPrjSge JobWdbeIexPrj::VecVSge

/**
	* JobWdbeIexPrj
	*/
class JobWdbeIexPrj : public JobWdbe {

public:
	/**
		* VecVSge (full: VecVJobWdbeIexPrjSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint PARSE = 2;
		static const Sbecore::uint PRSERR = 3;
		static const Sbecore::uint PRSDONE = 4;
		static const Sbecore::uint IMPORT = 5;
		static const Sbecore::uint IMPERR = 6;
		static const Sbecore::uint REVERSE = 7;
		static const Sbecore::uint COLLECT = 8;
		static const Sbecore::uint CLTDONE = 9;
		static const Sbecore::uint EXPORT = 10;
		static const Sbecore::uint DONE = 11;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

public:
	JobWdbeIexPrj(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~JobWdbeIexPrj();

public:

	std::string fullpath;
	bool xmlNotTxt;

	Sbecore::uint lineno;
	Sbecore::uint impcnt;

	std::map<Sbecore::uint,Sbecore::uint> icsWdbeVIop;

	bool shorttags;

	IexWdbePrj::ImeIMProject imeimproject;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	void reset(DbsWdbe* dbswdbe);

	void parseFromFile(DbsWdbe* dbswdbe, const std::string& _fullpath, const bool _xmlNotTxt);
	void import(DbsWdbe* dbswdbe);
	void reverse(DbsWdbe* dbswdbe);
	void collect(DbsWdbe* dbswdbe, const std::map<Sbecore::uint,Sbecore::uint>& _icsWdbeVIop = IexWdbePrj::icsWdbeVIopInsAll());
	void exportToFile(DbsWdbe* dbswdbe, const std::string& _fullpath, const bool _xmlNotTxt, const bool _shorttags = true);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:

private:
	void changeStage(DbsWdbe* dbswdbe, Sbecore::uint _ixVSge);

public:
	std::string getSquawk(DbsWdbe* dbswdbe);

private:
	Sbecore::uint enterSgeIdle(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeIdle(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeParse(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeParse(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgePrserr(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgePrserr(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgePrsdone(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgePrsdone(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeImport(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeImport(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeImperr(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeImperr(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeReverse(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeReverse(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeCollect(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeCollect(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeCltdone(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeCltdone(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeExport(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeExport(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeDone(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeDone(DbsWdbe* dbswdbe);

};

#endif

