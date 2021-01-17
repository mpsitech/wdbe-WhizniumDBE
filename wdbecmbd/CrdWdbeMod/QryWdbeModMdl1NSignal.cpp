/**
	* \file QryWdbeModMdl1NSignal.cpp
	* job handler for job QryWdbeModMdl1NSignal (implementation)
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

#include "QryWdbeModMdl1NSignal.h"

#include "QryWdbeModMdl1NSignal_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWdbeModMdl1NSignal
 ******************************************************************************/

QryWdbeModMdl1NSignal::QryWdbeModMdl1NSignal(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::QRYWDBEMODMDL1NSIGNAL, jrefSup, ixWdbeVLocale)
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

QryWdbeModMdl1NSignal::~QryWdbeModMdl1NSignal() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWdbeModMdl1NSignal::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWdbeModMdl1NSignal::rerun(
			DbsWdbe* dbswdbe
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefMod = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFMOD, jref);

	xchg->removeClstns(VecWdbeVCall::CALLWDBESIGMOD_MDLEQ, jref);

	dbswdbe->tblwdbeqselect->removeRstByJref(jref);
	dbswdbe->tblwdbeqmodmdl1nsignal->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWdbeMSignal.ref)";
	sqlstr += " FROM TblWdbeMSignal";
	sqlstr += " WHERE TblWdbeMSignal.mdlRefWdbeMModule = " + to_string(preRefMod) + "";
	dbswdbe->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWdbeQModMdl1NSignal(jref, jnum, ref, mdlNum)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWdbeMSignal.ref, TblWdbeMSignal.mdlNum";
	sqlstr += " FROM TblWdbeMSignal";
	sqlstr += " WHERE TblWdbeMSignal.mdlRefWdbeMModule = " + to_string(preRefMod) + "";
	sqlstr += " ORDER BY mdlNum ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswdbe->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWdbeQModMdl1NSignal SET jnum = qref WHERE jref = " + to_string(jref);
	dbswdbe->executeQuery(sqlstr);

	ixWdbeVQrystate = VecWdbeVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswdbe);

	if (call) xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBESTATCHG, jref);

	xchg->addRefClstn(VecWdbeVCall::CALLWDBESIGMOD_MDLEQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefMod);
};

void QryWdbeModMdl1NSignal::fetch(
			DbsWdbe* dbswdbe
		) {
	string sqlstr;

	StmgrWdbe* stmgr = NULL;
	Stcch* stcch = NULL;

	WdbeQModMdl1NSignal* rec = NULL;

	dbswdbe->tblwdbeqmodmdl1nsignal->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRef = StubWdbe::getStubSigStd(dbswdbe, rec->ref, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWdbeModMdl1NSignal", "fetch");
	};

	refreshJnum();
};

uint QryWdbeModMdl1NSignal::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WdbeQModMdl1NSignal* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWdbeModMdl1NSignal::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WdbeQModMdl1NSignal* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WdbeQModMdl1NSignal* QryWdbeModMdl1NSignal::getRecByJnum(
			const uint jnum
		) {
	WdbeQModMdl1NSignal* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWdbeModMdl1NSignal::handleRequest(
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

bool QryWdbeModMdl1NSignal::handleRerun(
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

bool QryWdbeModMdl1NSignal::handleShow(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	WdbeQModMdl1NSignal* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tstubRef";
	cout << "\tmdlNum";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->stubRef;
		cout << "\t" << rec->mdlNum;
		cout << endl;
	};
	return retval;
};

void QryWdbeModMdl1NSignal::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if ((call->ixVCall == VecWdbeVCall::CALLWDBESTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWdbeStubChgFromSelf(dbswdbe);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBESIGMOD_MDLEQ) {
		call->abort = handleCallWdbeSigMod_mdlEq(dbswdbe, call->jref);
	};
};

bool QryWdbeModMdl1NSignal::handleCallWdbeStubChgFromSelf(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleCallWdbeStubChgFromSelf --- INSERT
	return retval;
};

bool QryWdbeModMdl1NSignal::handleCallWdbeSigMod_mdlEq(
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
