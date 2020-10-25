/**
	* \file QryWdbeUsgMNUser.cpp
	* job handler for job QryWdbeUsgMNUser (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbed.h>
#endif

#include "QryWdbeUsgMNUser.h"

#include "QryWdbeUsgMNUser_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWdbeUsgMNUser
 ******************************************************************************/

QryWdbeUsgMNUser::QryWdbeUsgMNUser(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::QRYWDBEUSGMNUSER, jrefSup, ixWdbeVLocale)
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

QryWdbeUsgMNUser::~QryWdbeUsgMNUser() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWdbeUsgMNUser::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWdbeUsgMNUser::rerun(
			DbsWdbe* dbswdbe
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefUsg = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUSG, jref);

	xchg->removeClstns(VecWdbeVCall::CALLWDBEUSRRUSGMOD_USGEQ, jref);

	dbswdbe->tblwdbeqselect->removeRstByJref(jref);
	dbswdbe->tblwdbequsgmnuser->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWdbeRMUserMUsergroup.ref)";
	sqlstr += " FROM TblWdbeRMUserMUsergroup, TblWdbeMUser";
	sqlstr += " WHERE TblWdbeRMUserMUsergroup.refWdbeMUser = TblWdbeMUser.ref";
	sqlstr += " AND TblWdbeRMUserMUsergroup.refWdbeMUsergroup = " + to_string(preRefUsg) + "";
	dbswdbe->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWdbeQUsgMNUser(jref, jnum, mref, ref, ixWdbeVUserlevel)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWdbeMUser.ref, TblWdbeRMUserMUsergroup.ref, TblWdbeRMUserMUsergroup.ixWdbeVUserlevel";
	sqlstr += " FROM TblWdbeRMUserMUsergroup, TblWdbeMUser";
	sqlstr += " WHERE TblWdbeRMUserMUsergroup.refWdbeMUser = TblWdbeMUser.ref";
	sqlstr += " AND TblWdbeRMUserMUsergroup.refWdbeMUsergroup = " + to_string(preRefUsg) + "";
	sqlstr += " ORDER BY TblWdbeMUser.sref ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswdbe->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWdbeQUsgMNUser SET jnum = qref WHERE jref = " + to_string(jref);
	dbswdbe->executeQuery(sqlstr);

	ixWdbeVQrystate = VecWdbeVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswdbe);

	if (call) xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBESTATCHG, jref);

	xchg->addRefClstn(VecWdbeVCall::CALLWDBEUSRRUSGMOD_USGEQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefUsg);
};

void QryWdbeUsgMNUser::fetch(
			DbsWdbe* dbswdbe
		) {
	string sqlstr;

	StmgrWdbe* stmgr = NULL;
	Stcch* stcch = NULL;

	WdbeQUsgMNUser* rec = NULL;

	dbswdbe->tblwdbequsgmnuser->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubMref = StubWdbe::getStubUsrPrs(dbswdbe, rec->mref, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxWdbeVUserlevel = VecWdbeVUserlevel::getSref(rec->ixWdbeVUserlevel);
			rec->titIxWdbeVUserlevel = VecWdbeVUserlevel::getTitle(rec->ixWdbeVUserlevel, ixWdbeVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWdbeUsgMNUser", "fetch");
	};

	refreshJnum();
};

uint QryWdbeUsgMNUser::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WdbeQUsgMNUser* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWdbeUsgMNUser::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WdbeQUsgMNUser* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WdbeQUsgMNUser* QryWdbeUsgMNUser::getRecByJnum(
			const uint jnum
		) {
	WdbeQUsgMNUser* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWdbeUsgMNUser::handleRequest(
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

bool QryWdbeUsgMNUser::handleRerun(
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

bool QryWdbeUsgMNUser::handleShow(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	WdbeQUsgMNUser* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tmref";
	cout << "\tstubMref";
	cout << "\tref";
	cout << "\tixWdbeVUserlevel";
	cout << "\tsrefIxWdbeVUserlevel";
	cout << "\ttitIxWdbeVUserlevel";
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
		cout << "\t" << rec->ixWdbeVUserlevel;
		cout << "\t" << rec->srefIxWdbeVUserlevel;
		cout << "\t" << rec->titIxWdbeVUserlevel;
		cout << endl;
	};
	return retval;
};

void QryWdbeUsgMNUser::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if ((call->ixVCall == VecWdbeVCall::CALLWDBESTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWdbeStubChgFromSelf(dbswdbe);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEUSRRUSGMOD_USGEQ) {
		call->abort = handleCallWdbeUsrRusgMod_usgEq(dbswdbe, call->jref);
	};
};

bool QryWdbeUsgMNUser::handleCallWdbeStubChgFromSelf(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleCallWdbeStubChgFromSelf --- INSERT
	return retval;
};

bool QryWdbeUsgMNUser::handleCallWdbeUsrRusgMod_usgEq(
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

