/**
	* \file QryWdbeVerMNLibrary.cpp
	* job handler for job QryWdbeVerMNLibrary (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbed.h>
#endif

#include "QryWdbeVerMNLibrary.h"

#include "QryWdbeVerMNLibrary_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWdbeVerMNLibrary
 ******************************************************************************/

QryWdbeVerMNLibrary::QryWdbeVerMNLibrary(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::QRYWDBEVERMNLIBRARY, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWdbeVQrystate = VecWdbeVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswdbe);

	xchg->addClstn(VecWdbeVCall::CALLWDBESTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWdbeVerMNLibrary::~QryWdbeVerMNLibrary() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWdbeVerMNLibrary::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWdbeVerMNLibrary::rerun(
			DbsWdbe* dbswdbe
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefVer = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref);

	xchg->removeClstns(VecWdbeVCall::CALLWDBELIBRVERMOD_VEREQ, jref);

	dbswdbe->tblwdbeqselect->removeRstByJref(jref);
	dbswdbe->tblwdbeqvermnlibrary->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWdbeRMLibraryMVersion.ref)";
	sqlstr += " FROM TblWdbeRMLibraryMVersion, TblWdbeMLibrary";
	sqlstr += " WHERE TblWdbeRMLibraryMVersion.refWdbeMLibrary = TblWdbeMLibrary.ref";
	sqlstr += " AND TblWdbeRMLibraryMVersion.refWdbeMVersion = " + to_string(preRefVer) + "";
	dbswdbe->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWdbeQVerMNLibrary(jref, jnum, mref, ref)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWdbeMLibrary.ref, TblWdbeRMLibraryMVersion.ref";
	sqlstr += " FROM TblWdbeRMLibraryMVersion, TblWdbeMLibrary";
	sqlstr += " WHERE TblWdbeRMLibraryMVersion.refWdbeMLibrary = TblWdbeMLibrary.ref";
	sqlstr += " AND TblWdbeRMLibraryMVersion.refWdbeMVersion = " + to_string(preRefVer) + "";
	sqlstr += " ORDER BY TblWdbeMLibrary.sref ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswdbe->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWdbeQVerMNLibrary SET jnum = qref WHERE jref = " + to_string(jref);
	dbswdbe->executeQuery(sqlstr);

	ixWdbeVQrystate = VecWdbeVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswdbe);

	if (call) xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBESTATCHG, jref);

	xchg->addRefClstn(VecWdbeVCall::CALLWDBELIBRVERMOD_VEREQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefVer);
};

void QryWdbeVerMNLibrary::fetch(
			DbsWdbe* dbswdbe
		) {
	string sqlstr;

	StmgrWdbe* stmgr = NULL;
	Stcch* stcch = NULL;

	WdbeQVerMNLibrary* rec = NULL;

	dbswdbe->tblwdbeqvermnlibrary->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubMref = StubWdbe::getStubLibStd(dbswdbe, rec->mref, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWdbeVerMNLibrary", "fetch");
	};

	refreshJnum();
};

uint QryWdbeVerMNLibrary::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WdbeQVerMNLibrary* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWdbeVerMNLibrary::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WdbeQVerMNLibrary* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WdbeQVerMNLibrary* QryWdbeVerMNLibrary::getRecByJnum(
			const uint jnum
		) {
	WdbeQVerMNLibrary* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWdbeVerMNLibrary::handleRequest(
			DbsWdbe* dbswdbe
			, ReqWdbe* req
		) {
	if (req->ixVBasetype == ReqWdbe::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {
			cout << "\trerun" << endl;
			cout << "\tshow" << endl;
		} else if (req->cmd == "rerun") {
			req->retain = handleRerun(dbswdbe);

		} else if (req->cmd == "show") {
			req->retain = handleShow(dbswdbe);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	};
};

bool QryWdbeVerMNLibrary::handleRerun(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	string input;

	cout << "\tjnumFirstload (" << stgiac.jnumFirstload << "): ";
	cin >> input;
	stgiac.jnumFirstload = atol(input.c_str());
	cout << "\tnload (" << stgiac.nload << "): ";
	cin >> input;
	stgiac.nload = atol(input.c_str());

	rerun(dbswdbe);
	return retval;
};

bool QryWdbeVerMNLibrary::handleShow(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	WdbeQVerMNLibrary* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tmref";
	cout << "\tstubMref";
	cout << "\tref";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->mref;
		cout << "\t" << rec->stubMref;
		cout << "\t" << rec->ref;
		cout << endl;
	};
	return retval;
};

void QryWdbeVerMNLibrary::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if ((call->ixVCall == VecWdbeVCall::CALLWDBESTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWdbeStubChgFromSelf(dbswdbe);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBELIBRVERMOD_VEREQ) {
		call->abort = handleCallWdbeLibRverMod_verEq(dbswdbe, call->jref);
	};
};

bool QryWdbeVerMNLibrary::handleCallWdbeStubChgFromSelf(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleCallWdbeStubChgFromSelf --- INSERT
	return retval;
};

bool QryWdbeVerMNLibrary::handleCallWdbeLibRverMod_verEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if (ixWdbeVQrystate != VecWdbeVQrystate::OOD) {
		ixWdbeVQrystate = VecWdbeVQrystate::OOD;
		xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBESTATCHG, jref);
	};

	return retval;
};
