/**
	* \file RootWdbe.h
	* job handler for job RootWdbe (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef ROOTWDBE_H
#define ROOTWDBE_H

// IP include.spec --- INSERT

// IP include.cust --- IBEGIN
#include <openssl/sha.h>
// IP include.cust --- IEND

#include "JobWdbeLicense.h"
#include "SessWdbe.h"

#define VecVRootWdbeSge RootWdbe::VecVSge

#define DpchAppRootWdbeLogin RootWdbe::DpchAppLogin
#define DpchEngRootWdbeData RootWdbe::DpchEngData

/**
	* RootWdbe
	*/
class RootWdbe : public JobWdbe {

public:
	/**
		* VecVSge (full: VecVRootWdbeSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint SYNC = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
		* DpchAppLogin (full: DpchAppRootWdbeLogin)
		*/
	class DpchAppLogin : public DpchAppWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint USERNAME = 2;
		static const Sbecore::uint PASSWORD = 3;
		static const Sbecore::uint M2MNOTREG = 4;
		static const Sbecore::uint CHKSUSPSESS = 5;

	public:
		DpchAppLogin();

	public:
		std::string username;
		std::string password;
		bool m2mNotReg;
		bool chksuspsess;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngRootWdbeData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint FEEDFENSSPS = 2;
		static const Sbecore::uint ALL = 3;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, Sbecore::Xmlio::Feed* feedFEnsSps = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		Sbecore::Xmlio::Feed feedFEnsSps;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWdbe* dpcheng);

		void writeXML(const Sbecore::uint ixWdbeVLocale, xmlTextWriter* wr);
	};

public:
	RootWdbe(XchgWdbe* xchg, DbsWdbe* dbswdbe, const Sbecore::ubigint jrefSup, const bool _clearAll);
	~RootWdbe();

public:

	JobWdbeLicense* license;
	std::list<SessWdbe*> sesss;

	// IP vars.spec --- INSERT

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	void clearAll(DbsWdbe* dbswdbe);
	void clearQtb(DbsWdbe* dbswdbe);

	bool authenticate(DbsWdbe* dbswdbe, const std::string& username, const std::string& password, Sbecore::ubigint& refWdbeMUser);

public:

public:
	void handleRequest(DbsWdbe* dbswdbe, ReqWdbe* req);

private:
	bool handleClearAll(DbsWdbe* dbswdbe);
	bool handleCreateSess(DbsWdbe* dbswdbe);
	bool handleEraseSess(DbsWdbe* dbswdbe);
	bool handleExportIni(DbsWdbe* dbswdbe);
	bool handleTest(DbsWdbe* dbswdbe);

	void handleDpchAppLogin(DbsWdbe* dbswdbe, DpchAppLogin* dpchapplogin, const std::string ip, DpchEngWdbe** dpcheng);

	void handleTimerWithSrefMonInSgeIdle(DbsWdbe* dbswdbe);

public:
	void handleCall(DbsWdbe* dbswdbe, Sbecore::Call* call);

private:
	bool handleCallWdbeSuspsess(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig);
	bool handleCallWdbeLogout(DbsWdbe* dbswdbe, const Sbecore::ubigint jrefTrig, const bool boolvalInv);

private:
	void changeStage(DbsWdbe* dbswdbe, Sbecore::uint _ixVSge, DpchEngWdbe** dpcheng = NULL);

public:
	std::string getSquawk(DbsWdbe* dbswdbe);

private:
	Sbecore::uint enterSgeIdle(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeIdle(DbsWdbe* dbswdbe);
	Sbecore::uint enterSgeSync(DbsWdbe* dbswdbe, const bool reenter);
	void leaveSgeSync(DbsWdbe* dbswdbe);

};

#endif



