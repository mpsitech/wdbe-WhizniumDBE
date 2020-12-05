/**
	* \file QryWdbeErrAPar.cpp
	* job handler for job QryWdbeErrAPar (implementation)
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

#include "QryWdbeErrAPar.h"

#include "QryWdbeErrAPar_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWdbeErrAPar
 ******************************************************************************/

QryWdbeErrAPar::QryWdbeErrAPar(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::QRYWDBEERRAPAR, jrefSup, ixWdbeVLocale)
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

QryWdbeErrAPar::~QryWdbeErrAPar() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWdbeErrAPar::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWdbeErrAPar::rerun(
			DbsWdbe* dbswdbe
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefErr = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFERR, jref);

	xchg->removeClstns(VecWdbeVCall::CALLWDBEERRAPARMOD_ERREQ, jref);

	dbswdbe->tblwdbeqselect->removeRstByJref(jref);
	dbswdbe->tblwdbeqerrapar->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWdbeAMErrorPar.ref)";
	sqlstr += " FROM TblWdbeAMErrorPar";
	sqlstr += " WHERE TblWdbeAMErrorPar.errRefWdbeMError = " + to_string(preRefErr) + "";
	dbswdbe->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWdbeQErrAPar(jref, jnum, ref, errNum, sref, ixWdbeVPartype, refWdbeMVector, Length, Comment)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWdbeAMErrorPar.ref, TblWdbeAMErrorPar.errNum, TblWdbeAMErrorPar.sref, TblWdbeAMErrorPar.ixWdbeVPartype, TblWdbeAMErrorPar.refWdbeMVector, TblWdbeAMErrorPar.Length, TblWdbeAMErrorPar.Comment";
	sqlstr += " FROM TblWdbeAMErrorPar";
	sqlstr += " WHERE TblWdbeAMErrorPar.errRefWdbeMError = " + to_string(preRefErr) + "";
	sqlstr += " ORDER BY errNum ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswdbe->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWdbeQErrAPar SET jnum = qref WHERE jref = " + to_string(jref);
	dbswdbe->executeQuery(sqlstr);

	ixWdbeVQrystate = VecWdbeVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswdbe);

	if (call) xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBESTATCHG, jref);

	xchg->addRefClstn(VecWdbeVCall::CALLWDBEERRAPARMOD_ERREQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefErr);
};

void QryWdbeErrAPar::fetch(
			DbsWdbe* dbswdbe
		) {
	string sqlstr;

	StmgrWdbe* stmgr = NULL;
	Stcch* stcch = NULL;

	WdbeQErrAPar* rec = NULL;

	dbswdbe->tblwdbeqerrapar->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefIxWdbeVPartype = VecWdbeVPartype::getSref(rec->ixWdbeVPartype);
			rec->titIxWdbeVPartype = VecWdbeVPartype::getTitle(rec->ixWdbeVPartype);
			rec->stubRefWdbeMVector = StubWdbe::getStubVecStd(dbswdbe, rec->refWdbeMVector, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWdbeErrAPar", "fetch");
	};

	refreshJnum();
};

uint QryWdbeErrAPar::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WdbeQErrAPar* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWdbeErrAPar::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WdbeQErrAPar* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WdbeQErrAPar* QryWdbeErrAPar::getRecByJnum(
			const uint jnum
		) {
	WdbeQErrAPar* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWdbeErrAPar::handleRequest(
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

bool QryWdbeErrAPar::handleRerun(
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

bool QryWdbeErrAPar::handleShow(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	WdbeQErrAPar* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\terrNum";
	cout << "\tsref";
	cout << "\tixWdbeVPartype";
	cout << "\tsrefIxWdbeVPartype";
	cout << "\ttitIxWdbeVPartype";
	cout << "\trefWdbeMVector";
	cout << "\tstubRefWdbeMVector";
	cout << "\tLength";
	cout << "\tComment";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->errNum;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->ixWdbeVPartype;
		cout << "\t" << rec->srefIxWdbeVPartype;
		cout << "\t" << rec->titIxWdbeVPartype;
		cout << "\t" << rec->refWdbeMVector;
		cout << "\t" << rec->stubRefWdbeMVector;
		cout << "\t" << rec->Length;
		cout << "\t" << rec->Comment;
		cout << endl;
	};
	return retval;
};

void QryWdbeErrAPar::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBEERRAPARMOD_ERREQ) {
		call->abort = handleCallWdbeErrAparMod_errEq(dbswdbe, call->jref);
	} else if ((call->ixVCall == VecWdbeVCall::CALLWDBESTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWdbeStubChgFromSelf(dbswdbe);
	};
};

bool QryWdbeErrAPar::handleCallWdbeErrAparMod_errEq(
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

bool QryWdbeErrAPar::handleCallWdbeStubChgFromSelf(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleCallWdbeStubChgFromSelf --- INSERT
	return retval;
};



