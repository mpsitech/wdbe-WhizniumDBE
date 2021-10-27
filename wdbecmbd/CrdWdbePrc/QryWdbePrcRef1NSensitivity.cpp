/**
	* \file QryWdbePrcRef1NSensitivity.cpp
	* job handler for job QryWdbePrcRef1NSensitivity (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbed.h>
#endif

#include "QryWdbePrcRef1NSensitivity.h"

#include "QryWdbePrcRef1NSensitivity_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWdbePrcRef1NSensitivity
 ******************************************************************************/

QryWdbePrcRef1NSensitivity::QryWdbePrcRef1NSensitivity(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::QRYWDBEPRCREF1NSENSITIVITY, jrefSup, ixWdbeVLocale)
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

QryWdbePrcRef1NSensitivity::~QryWdbePrcRef1NSensitivity() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWdbePrcRef1NSensitivity::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWdbePrcRef1NSensitivity::rerun(
			DbsWdbe* dbswdbe
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefPrc = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFPRC, jref);

	xchg->removeClstns(VecWdbeVCall::CALLWDBESNSMOD_RETREUEQ, jref);

	dbswdbe->tblwdbeqselect->removeRstByJref(jref);
	dbswdbe->tblwdbeqprcref1nsensitivity->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWdbeMSensitivity.ref)";
	sqlstr += " FROM TblWdbeMSensitivity";
	sqlstr += " WHERE TblWdbeMSensitivity.refIxVTbl = " + to_string(VecWdbeVMSensitivityRefTbl::PRC);
	sqlstr += " AND TblWdbeMSensitivity.refUref = " + to_string(preRefPrc) + "";
	dbswdbe->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWdbeQPrcRef1NSensitivity(jref, jnum, ref)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWdbeMSensitivity.ref";
	sqlstr += " FROM TblWdbeMSensitivity";
	sqlstr += " WHERE TblWdbeMSensitivity.refIxVTbl = " + to_string(VecWdbeVMSensitivityRefTbl::PRC);
	sqlstr += " AND TblWdbeMSensitivity.refUref = " + to_string(preRefPrc) + "";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswdbe->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWdbeQPrcRef1NSensitivity SET jnum = qref WHERE jref = " + to_string(jref);
	dbswdbe->executeQuery(sqlstr);

	ixWdbeVQrystate = VecWdbeVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswdbe);

	if (call) xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBESTATCHG, jref);

	xchg->addIxRefClstn(VecWdbeVCall::CALLWDBESNSMOD_RETREUEQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWdbeVMSensitivityRefTbl::PRC, preRefPrc);
};

void QryWdbePrcRef1NSensitivity::fetch(
			DbsWdbe* dbswdbe
		) {
	string sqlstr;

	StmgrWdbe* stmgr = NULL;
	Stcch* stcch = NULL;

	WdbeQPrcRef1NSensitivity* rec = NULL;

	dbswdbe->tblwdbeqprcref1nsensitivity->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRef = StubWdbe::getStubSnsStd(dbswdbe, rec->ref, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWdbePrcRef1NSensitivity", "fetch");
	};

	refreshJnum();
};

uint QryWdbePrcRef1NSensitivity::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WdbeQPrcRef1NSensitivity* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWdbePrcRef1NSensitivity::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WdbeQPrcRef1NSensitivity* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WdbeQPrcRef1NSensitivity* QryWdbePrcRef1NSensitivity::getRecByJnum(
			const uint jnum
		) {
	WdbeQPrcRef1NSensitivity* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWdbePrcRef1NSensitivity::handleRequest(
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

bool QryWdbePrcRef1NSensitivity::handleRerun(
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

bool QryWdbePrcRef1NSensitivity::handleShow(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	WdbeQPrcRef1NSensitivity* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tstubRef";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->stubRef;
		cout << endl;
	};
	return retval;
};

void QryWdbePrcRef1NSensitivity::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if ((call->ixVCall == VecWdbeVCall::CALLWDBESTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWdbeStubChgFromSelf(dbswdbe);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBESNSMOD_RETREUEQ) {
		call->abort = handleCallWdbeSnsMod_retReuEq(dbswdbe, call->jref);
	};
};

bool QryWdbePrcRef1NSensitivity::handleCallWdbeStubChgFromSelf(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleCallWdbeStubChgFromSelf --- INSERT
	return retval;
};

bool QryWdbePrcRef1NSensitivity::handleCallWdbeSnsMod_retReuEq(
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
