/**
	* \file JobWdbeLicense.cpp
	* job handler for job JobWdbeLicense (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbed.h>
#endif

#include "JobWdbeLicense.h"

#include "JobWdbeLicense_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

// IP ns.spec --- INSERT

// IP Shrdat.subs --- IBEGIN
// this is a crutch ...
#include "VecWzlaVSte.cpp"
#include "AppWzla.cpp"
// IP Shrdat.subs --- IEND

/******************************************************************************
 class JobWdbeLicense::Shrdat
 ******************************************************************************/

JobWdbeLicense::Shrdat::Shrdat() :
			ShrdatWdbe("JobWdbeLicense", "Shrdat")
		{
};

void JobWdbeLicense::Shrdat::init(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
		) {
	// IP Shrdat.init --- INSERT
};

void JobWdbeLicense::Shrdat::term(
			XchgWdbe* xchg
		) {
	// IP Shrdat.term --- INSERT
};

/******************************************************************************
 class JobWdbeLicense
 ******************************************************************************/

JobWdbeLicense::JobWdbeLicense(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			CsjobWdbe(xchg, VecWdbeVJob::JOBWDBELICENSE, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	// IP constructor.spec1 --- INSERT

	// IP constructor.cust2 --- INSERT

	// IP constructor.spec2 --- INSERT

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

JobWdbeLicense::~JobWdbeLicense() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
void JobWdbeLicense::connect(
			DbsWdbe* dbswdbe
		) {

};

void JobWdbeLicense::disconnect(
			DbsWdbe* dbswdbe
		) {

};

void JobWdbeLicense::heartbeat(
			const bool active
		) {

};

void JobWdbeLicense::syncAll(
			DbsWdbe* dbswdbe
		) {

};

void JobWdbeLicense::syncPrj(
			DbsWdbe* dbswdbe
			, const ubigint refWdbeMProject
		) {

};

void JobWdbeLicense::syncVer(
			DbsWdbe* dbswdbe
			, const ubigint refWdbeMProject
			, const ubigint refWdbeMVersion
		) {

};

bool JobWdbeLicense::authPrjImpex(
			IexWdbePrj::ImeIMProject& imeimproject
		) {
	return true;
};

bool JobWdbeLicense::authPrjNew() {
	return true;
};

bool JobWdbeLicense::authRlsWrite(
				DbsWdbe* dbswdbe
				, const ubigint refWdbeMRelease
			) {
	return true;
};

bool JobWdbeLicense::validateLicenseBase(
			const bool startup
		) {
	return true;
};

bool JobWdbeLicense::validateLicenseFull() {
	return true;
};

bool JobWdbeLicense::validateLicenseTpl() {
	return true;
};

// IP cust --- IEND

// IP spec --- INSERT

void JobWdbeLicense::handleRequest(
			DbsWdbe* dbswdbe
			, ReqWdbe* req
		) {
	if (req->ixVBasetype == ReqWdbe::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {
			cout << "\ttest" << endl;
		} else if (req->cmd == "test") {
			req->retain = handleTest(dbswdbe);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	};
};

bool JobWdbeLicense::handleTest(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleTest --- INSERT
	return retval;
};

void JobWdbeLicense::changeStage(
			DbsWdbe* dbswdbe
			, uint _ixVSge
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswdbe); break;
				case VecVSge::CONN: leaveSgeConn(dbswdbe); break;
				case VecVSge::CONERR: leaveSgeConerr(dbswdbe); break;
				case VecVSge::AUTH: leaveSgeAuth(dbswdbe); break;
				case VecVSge::AUTERR: leaveSgeAuterr(dbswdbe); break;
				case VecVSge::SYNC: leaveSgeSync(dbswdbe); break;
				case VecVSge::SNCERR: leaveSgeSncerr(dbswdbe); break;
			};

			setStage(dbswdbe, _ixVSge);
			reenter = false;
			// IP changeStage.refresh1 --- INSERT
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswdbe, reenter); break;
			case VecVSge::CONN: _ixVSge = enterSgeConn(dbswdbe, reenter); break;
			case VecVSge::CONERR: _ixVSge = enterSgeConerr(dbswdbe, reenter); break;
			case VecVSge::AUTH: _ixVSge = enterSgeAuth(dbswdbe, reenter); break;
			case VecVSge::AUTERR: _ixVSge = enterSgeAuterr(dbswdbe, reenter); break;
			case VecVSge::SYNC: _ixVSge = enterSgeSync(dbswdbe, reenter); break;
			case VecVSge::SNCERR: _ixVSge = enterSgeSncerr(dbswdbe, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string JobWdbeLicense::getSquawk(
			DbsWdbe* dbswdbe
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::IDLE) || (ixVSge == VecVSge::CONN) || (ixVSge == VecVSge::CONERR) || (ixVSge == VecVSge::AUTH) || (ixVSge == VecVSge::AUTERR) || (ixVSge == VecVSge::SYNC) || (ixVSge == VecVSge::SNCERR) ) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			if (ixVSge == VecVSge::IDLE) retval = "not connected";
			else if (ixVSge == VecVSge::CONN) retval = "connected";
			else if (ixVSge == VecVSge::CONERR) retval = "connection failure";
			else if (ixVSge == VecVSge::AUTH) retval = "authenticating";
			else if (ixVSge == VecVSge::AUTERR) retval = "authentication failure";
			else if (ixVSge == VecVSge::SYNC) retval = "synchronizing";
			else if (ixVSge == VecVSge::SNCERR) retval = "synchronization failure";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint JobWdbeLicense::enterSgeIdle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void JobWdbeLicense::leaveSgeIdle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWdbeLicense::enterSgeConn(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::CONN;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::CONERR;

	// IP enterSgeConn --- INSERT

	return retval;
};

void JobWdbeLicense::leaveSgeConn(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeConn --- INSERT
};

uint JobWdbeLicense::enterSgeConerr(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::IDLE;
	retval = nextIxVSgeSuccess;

	// IP enterSgeConerr --- INSERT

	return retval;
};

void JobWdbeLicense::leaveSgeConerr(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeConerr --- INSERT
};

uint JobWdbeLicense::enterSgeAuth(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::CONN;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::AUTERR;

	// IP enterSgeAuth --- INSERT

	return retval;
};

void JobWdbeLicense::leaveSgeAuth(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAuth --- INSERT
};

uint JobWdbeLicense::enterSgeAuterr(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::CONN;
	retval = nextIxVSgeSuccess;

	// IP enterSgeAuterr --- INSERT

	return retval;
};

void JobWdbeLicense::leaveSgeAuterr(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAuterr --- INSERT
};

uint JobWdbeLicense::enterSgeSync(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::CONN;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::SNCERR;

	// IP enterSgeSync --- INSERT

	return retval;
};

void JobWdbeLicense::leaveSgeSync(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeSync --- INSERT
};

uint JobWdbeLicense::enterSgeSncerr(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::CONN;
	retval = nextIxVSgeSuccess;

	// IP enterSgeSncerr --- INSERT

	return retval;
};

void JobWdbeLicense::leaveSgeSncerr(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeSncerr --- INSERT
};

bool JobWdbeLicense::handleClaim(
			DbsWdbe* dbswdbe
			, map<ubigint,Sbecore::Claim*>& claims
			, const ubigint jrefNewest
		) {
	bool mod = false;

	// IP handleClaim --- INSERT

	return mod;
};


