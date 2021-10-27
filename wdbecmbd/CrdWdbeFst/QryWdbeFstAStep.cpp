/**
	* \file QryWdbeFstAStep.cpp
	* job handler for job QryWdbeFstAStep (implementation)
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

#include "QryWdbeFstAStep.h"

#include "QryWdbeFstAStep_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWdbeFstAStep
 ******************************************************************************/

QryWdbeFstAStep::QryWdbeFstAStep(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::QRYWDBEFSTASTEP, jrefSup, ixWdbeVLocale)
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

QryWdbeFstAStep::~QryWdbeFstAStep() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWdbeFstAStep::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWdbeFstAStep::rerun(
			DbsWdbe* dbswdbe
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefFst = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFFST, jref);

	xchg->removeClstns(VecWdbeVCall::CALLWDBEFSTASTPMOD_FSTEQ, jref);

	dbswdbe->tblwdbeqselect->removeRstByJref(jref);
	dbswdbe->tblwdbeqfstastep->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWdbeAMFsmstateStep.ref)";
	sqlstr += " FROM TblWdbeAMFsmstateStep";
	sqlstr += " WHERE TblWdbeAMFsmstateStep.fstRefWdbeMFsmstate = " + to_string(preRefFst) + "";
	dbswdbe->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWdbeQFstAStep(jref, jnum, ref, fstNum, fnxRefWdbeMFsmstate, Cond1, Ip1, Cond2, Ip2, Cond3, Ip3, Cond4, Ip4)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWdbeAMFsmstateStep.ref, TblWdbeAMFsmstateStep.fstNum, TblWdbeAMFsmstateStep.fnxRefWdbeMFsmstate, TblWdbeAMFsmstateStep.Cond1, TblWdbeAMFsmstateStep.Ip1, TblWdbeAMFsmstateStep.Cond2, TblWdbeAMFsmstateStep.Ip2, TblWdbeAMFsmstateStep.Cond3, TblWdbeAMFsmstateStep.Ip3, TblWdbeAMFsmstateStep.Cond4, TblWdbeAMFsmstateStep.Ip4";
	sqlstr += " FROM TblWdbeAMFsmstateStep";
	sqlstr += " WHERE TblWdbeAMFsmstateStep.fstRefWdbeMFsmstate = " + to_string(preRefFst) + "";
	sqlstr += " ORDER BY fstNum ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswdbe->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWdbeQFstAStep SET jnum = qref WHERE jref = " + to_string(jref);
	dbswdbe->executeQuery(sqlstr);

	ixWdbeVQrystate = VecWdbeVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswdbe);

	if (call) xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBESTATCHG, jref);

	xchg->addRefClstn(VecWdbeVCall::CALLWDBEFSTASTPMOD_FSTEQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefFst);
};

void QryWdbeFstAStep::fetch(
			DbsWdbe* dbswdbe
		) {
	string sqlstr;

	StmgrWdbe* stmgr = NULL;
	Stcch* stcch = NULL;

	WdbeQFstAStep* rec = NULL;

	dbswdbe->tblwdbeqfstastep->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubFnxRefWdbeMFsmstate = StubWdbe::getStubFstStd(dbswdbe, rec->fnxRefWdbeMFsmstate, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWdbeFstAStep", "fetch");
	};

	refreshJnum();
};

uint QryWdbeFstAStep::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WdbeQFstAStep* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWdbeFstAStep::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WdbeQFstAStep* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WdbeQFstAStep* QryWdbeFstAStep::getRecByJnum(
			const uint jnum
		) {
	WdbeQFstAStep* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWdbeFstAStep::handleRequest(
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

bool QryWdbeFstAStep::handleRerun(
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

bool QryWdbeFstAStep::handleShow(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	WdbeQFstAStep* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tfstNum";
	cout << "\tfnxRefWdbeMFsmstate";
	cout << "\tstubFnxRefWdbeMFsmstate";
	cout << "\tCond1";
	cout << "\tIp1";
	cout << "\tCond2";
	cout << "\tIp2";
	cout << "\tCond3";
	cout << "\tIp3";
	cout << "\tCond4";
	cout << "\tIp4";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->fstNum;
		cout << "\t" << rec->fnxRefWdbeMFsmstate;
		cout << "\t" << rec->stubFnxRefWdbeMFsmstate;
		cout << "\t" << rec->Cond1;
		cout << "\t" << rec->Ip1;
		cout << "\t" << rec->Cond2;
		cout << "\t" << rec->Ip2;
		cout << "\t" << rec->Cond3;
		cout << "\t" << rec->Ip3;
		cout << "\t" << rec->Cond4;
		cout << "\t" << rec->Ip4;
		cout << endl;
	};
	return retval;
};

void QryWdbeFstAStep::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if ((call->ixVCall == VecWdbeVCall::CALLWDBESTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWdbeStubChgFromSelf(dbswdbe);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEFSTASTPMOD_FSTEQ) {
		call->abort = handleCallWdbeFstAstpMod_fstEq(dbswdbe, call->jref);
	};
};

bool QryWdbeFstAStep::handleCallWdbeStubChgFromSelf(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleCallWdbeStubChgFromSelf --- INSERT
	return retval;
};

bool QryWdbeFstAStep::handleCallWdbeFstAstpMod_fstEq(
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
