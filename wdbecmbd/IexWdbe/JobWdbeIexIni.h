/**
	* \file JobWdbeIexIni.h
	* job handler for job JobWdbeIexIni (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef JOBWDBEIEXINI_H
#define JOBWDBEIEXINI_H

#include "IexWdbeIni.h"

// IP include.cust --- INSERT

#define VecVJobWdbeIexIniSge JobWdbeIexIni::VecVSge

/**
	* JobWdbeIexIni
	*/
class JobWdbeIexIni : public JobWdbe {

public:
	/**
		* VecVSge (full: VecVJobWdbeIexIniSge)
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
	JobWdbeIexIni(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~JobWdbeIexIni();

public:

	std::string fullpath;
	bool xmlNotTxt;
	std::string rectpath;

	Sbecore::uint lineno;
	Sbecore::uint impcnt;

	std::map<Sbecore::uint,Sbecore::uint> icsWdbeVIop;

	bool shorttags;

	IexWdbeIni::ImeIAVControlPar imeiavcontrolpar;
	IexWdbeIni::ImeIAVKeylistKey1 imeiavkeylistkey1;
	IexWdbeIni::ImeIAVValuelistVal imeiavvaluelistval;
	IexWdbeIni::ImeIMCoreproject imeimcoreproject;
	IexWdbeIni::ImeIMFamily imeimfamily;
	IexWdbeIni::ImeIMFile1 imeimfile1;
	IexWdbeIni::ImeIMLibrary imeimlibrary;
	IexWdbeIni::ImeIMMachine imeimmachine;
	IexWdbeIni::ImeIMModule imeimmodule;
	IexWdbeIni::ImeIMUnit imeimunit;
	IexWdbeIni::ImeIMUsergroup imeimusergroup;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	void reset(DbsWdbe* dbswdbe);

	void parseFromFile(DbsWdbe* dbswdbe, const std::string& _fullpath, const bool _xmlNotTxt, const std::string& _rectpath = "");
	void import(DbsWdbe* dbswdbe);
	void reverse(DbsWdbe* dbswdbe);
	void collect(DbsWdbe* dbswdbe, const std::map<Sbecore::uint,Sbecore::uint>& _icsWdbeVIop = IexWdbeIni::icsWdbeVIopInsAll());
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
