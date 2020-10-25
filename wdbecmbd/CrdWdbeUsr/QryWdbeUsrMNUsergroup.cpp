/**
	* \file QryWdbeUsrMNUsergroup.cpp
	* job handler for job QryWdbeUsrMNUsergroup (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbed.h>
#endif

#include "QryWdbeUsrMNUsergroup.h"

#include "QryWdbeUsrMNUsergroup_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWdbeUsrMNUsergroup
 ******************************************************************************/

QryWdbeUsrMNUsergroup::QryWdbeUsrMNUsergroup(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::QRYWDBEUSRMNUSERGROUP, jrefSup, ixWdbeVLocale)
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

QryWdbeUsrMNUsergroup::~QryWdbeUsrMNUsergroup() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWdbeUsrMNUsergroup::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWdbeUsrMNUsergroup::rerun(
			DbsWdbe* dbswdbe
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefUsr = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUSR, jref);

	xchg->removeClstns(VecWdbeVCall::CALLWDBEUSRRUSGMOD_USREQ, jref);

	dbswdbe->tblwdbeqselect->removeRstByJref(jref);
	dbswdbe->tblwdbequsrmnusergroup->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWdbeRMUserMUsergroup.ref)";
	sqlstr += " FROM TblWdbeRMUserMUsergroup, TblWdbeMUsergroup";
	sqlstr += " WHERE TblWdbeRMUserMUsergroup.refWdbeMUsergroup = TblWdbeMUsergroup.ref";
	sqlstr += " AND TblWdbeRMUserMUsergroup.refWdbeMUser = " + to_string(preRefUsr) + "";
	dbswdbe->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWdbeQUsrMNUsergroup(jref, jnum, mref, ref, ixWdbeVUserlevel)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWdbeMUsergroup.ref, TblWdbeRMUserMUsergroup.ref, TblWdbeRMUserMUsergroup.ixWdbeVUserlevel";
	sqlstr += " FROM TblWdbeRMUserMUsergroup, TblWdbeMUsergroup";
	sqlstr += " WHERE TblWdbeRMUserMUsergroup.refWdbeMUsergroup = TblWdbeMUsergroup.ref";
	sqlstr += " AND TblWdbeRMUserMUsergroup.refWdbeMUser = " + to_string(preRefUsr) + "";
	sqlstr += " ORDER BY TblWdbeMUsergroup.sref ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswdbe->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWdbeQUsrMNUsergroup SET jnum = qref WHERE jref = " + to_string(jref);
	dbswdbe->executeQuery(sqlstr);

	ixWdbeVQrystate = VecWdbeVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswdbe);

	if (call) xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBESTATCHG, jref);

	xchg->addRefClstn(VecWdbeVCall::CALLWDBEUSRRUSGMOD_USREQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefUsr);
};

void QryWdbeUsrMNUsergroup::fetch(
			DbsWdbe* dbswdbe
		) {
	string sqlstr;

	StmgrWdbe* stmgr = NULL;
	Stcch* stcch = NULL;

	WdbeQUsrMNUsergroup* rec = NULL;

	dbswdbe->tblwdbequsrmnusergroup->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubMref = StubWdbe::getStubUsgStd(dbswdbe, rec->mref, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxWdbeVUserlevel = VecWdbeVUserlevel::getSref(rec->ixWdbeVUserlevel);
			rec->titIxWdbeVUserlevel = VecWdbeVUserlevel::getTitle(rec->ixWdbeVUserlevel, ixWdbeVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWdbeUsrMNUsergroup", "fetch");
	};

	refreshJnum();
};

uint QryWdbeUsrMNUsergroup::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WdbeQUsrMNUsergroup* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWdbeUsrMNUsergroup::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WdbeQUsrMNUsergroup* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WdbeQUsrMNUsergroup* QryWdbeUsrMNUsergroup::getRecByJnum(
			const uint jnum
		) {
	WdbeQUsrMNUsergroup* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWdbeUsrMNUsergroup::handleRequest(
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

bool QryWdbeUsrMNUsergroup::handleRerun(
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

bool QryWdbeUsrMNUsergroup::handleShow(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	WdbeQUsrMNUsergroup* rec = NULL;

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

void QryWdbeUsrMNUsergroup::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if ((call->ixVCall == VecWdbeVCall::CALLWDBESTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWdbeStubChgFromSelf(dbswdbe);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEUSRRUSGMOD_USREQ) {
		call->abort = handleCallWdbeUsrRusgMod_usrEq(dbswdbe, call->jref);
	};
};

bool QryWdbeUsrMNUsergroup::handleCallWdbeStubChgFromSelf(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleCallWdbeStubChgFromSelf --- INSERT
	return retval;
};

bool QryWdbeUsrMNUsergroup::handleCallWdbeUsrRusgMod_usrEq(
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

