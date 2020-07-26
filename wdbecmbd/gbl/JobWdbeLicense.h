/**
	* \file JobWdbeLicense.h
	* job handler for job JobWdbeLicense (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef JOBWDBELICENSE_H
#define JOBWDBELICENSE_H

// IP include.spec --- INSERT

// IP include.cust --- IBEGIN
#include "AppWzla.h"
#include "IexWdbePrj.h"
// IP include.cust --- IEND

#define VecVJobWdbeLicenseSge JobWdbeLicense::VecVSge

#define StgJobWdbeLicense JobWdbeLicense::Stg

#define ShrdatJobWdbeLicense JobWdbeLicense::Shrdat

/**
	* JobWdbeLicense
	*/
class JobWdbeLicense : public CsjobWdbe {

public:
	/**
		* VecVSge (full: VecVJobWdbeLicenseSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint CONN = 2;
		static const Sbecore::uint CONERR = 3;
		static const Sbecore::uint AUTH = 4;
		static const Sbecore::uint AUTERR = 5;
		static const Sbecore::uint SYNC = 6;
		static const Sbecore::uint SNCERR = 7;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
		* Stg (full: StgJobWdbeLicense)
		*/
	class Stg : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint ENGIP = 1;
		static const Sbecore::uint ENGPORT = 2;
		static const Sbecore::uint USERNAME = 3;
		static const Sbecore::uint PASSWORD = 4;
		static const Sbecore::uint LICENSEBASE = 5;
		static const Sbecore::uint LICENSEFULL = 6;
		static const Sbecore::uint LICENSETPL = 7;
		static const Sbecore::uint LASTATTEMPT = 8;
		static const Sbecore::uint LASTSUCCESS = 9;
		static const Sbecore::uint LASTSYNC = 10;

	public:
		Stg(const std::string& engip = "license.mpsitech.cloud", const Sbecore::uint engport = 13110, const std::string& username = "", const std::string& password = "", const std::string& licenseBase = "", const std::string& licenseFull = "", const std::string& licenseTpl = "", const std::string& lastAttempt = "", const std::string& lastSuccess = "", const std::string& lastSync = "");

	public:
		std::string engip;
		Sbecore::uint engport;
		std::string username;
		std::string password;
		std::string licenseBase;
		std::string licenseFull;
		std::string licenseTpl;
		std::string lastAttempt;
		std::string lastSuccess;
		std::string lastSync;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const Stg* comp);
		std::set<Sbecore::uint> diff(const Stg* comp);
	};

	/**
		* Shrdat (full: ShrdatJobWdbeLicense)
		*/
	class Shrdat : public ShrdatWdbe {

	public:
		// IP Shrdat.subs --- INSERT

	public:
		Shrdat();

	public:

		// IP Shrdat.vars.cust --- INSERT

	public:
		void init(XchgWdbe* xchg, DbsWdbe* dbswdbe);
		void term(XchgWdbe* xchg);
	};

public:
	JobWdbeLicense(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWdbeVLocale);
	~JobWdbeLicense();

public:
	static Stg stg;
	static Shrdat shrdat;

	// IP vars.spec --- INSERT

	// IP vars.cust --- INSERT

public:
	// IP cust --- IBEGIN
	void connect(DbsWdbe* dbswdbe);
	void disconnect(DbsWdbe* dbswdbe);

	void heartbeat(const bool active);

	void syncAll(DbsWdbe* dbswdbe);
	void syncPrj(DbsWdbe* dbswdbe, const Sbecore::ubigint refWdbeMProject);
	void syncVer(DbsWdbe* dbswdbe, const Sbecore::ubigint refWdbeMProject, const Sbecore::ubigint refWdbeMVersion);

	bool authPrjImpex(IexWdbePrj::ImeIMProject& imeimproject);
	bool authPrjNew();
	bool authRlsWrite(DbsWdbe* dbswdbe, const Sbecore::ubigint refWdbeMRelease);

	// future / container-based solution only
	bool validateLicenseBase(const bool startup);
	bool validateLicenseFull();
	bool validateLicenseTpl();
	// IP cust --- IEND

public:
	// IP spec --- INSERT

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:
	bool handleTest(DbsWdbe* dbswdbe);

private:
	void changeStage(DbsWdbe* dbswdbe, Sbecore::uint _ixVSge);

public:
	std::string getSquawk(DbsWdbe* dbswdbe);

private:
	Sbecore::uint enterSgeIdle(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeIdle(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeConn(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeConn(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeConerr(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeConerr(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeAuth(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeAuth(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeAuterr(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeAuterr(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeSync(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeSync(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeSncerr(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeSncerr(DbsWdbe* dbswdbe);

public:
	bool handleClaim(DbsWdbe* dbswdbe, std::map<Sbecore::ubigint,Sbecore::Claim*>& claims, const Sbecore::ubigint jrefNewest);
};

#endif


