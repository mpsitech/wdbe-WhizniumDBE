/**
	* \file QryWdbeCprMNPerson.cpp
	* job handler for job QryWdbeCprMNPerson (implementation)
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

#include "QryWdbeCprMNPerson.h"

#include "QryWdbeCprMNPerson_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWdbeCprMNPerson
 ******************************************************************************/

QryWdbeCprMNPerson::QryWdbeCprMNPerson(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::QRYWDBECPRMNPERSON, jrefSup, ixWdbeVLocale)
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

QryWdbeCprMNPerson::~QryWdbeCprMNPerson() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWdbeCprMNPerson::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWdbeCprMNPerson::rerun(
			DbsWdbe* dbswdbe
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefCpr = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCPR, jref);
	int preX1 = xchg->getIntvalPreset(VecWdbeVPreset::PREWDBECPRMNPERSON_X1, jref);

	xchg->removeClstns(VecWdbeVCall::CALLWDBECPRRPRSMOD_CPREQ, jref);

	dbswdbe->tblwdbeqselect->removeRstByJref(jref);
	dbswdbe->tblwdbeqcprmnperson->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWdbeRMCoreprojectMPerson.ref)";
	sqlstr += " FROM TblWdbeRMCoreprojectMPerson, TblWdbeMPerson";
	sqlstr += " WHERE TblWdbeRMCoreprojectMPerson.refWdbeMPerson = TblWdbeMPerson.ref";
	sqlstr += " AND TblWdbeRMCoreprojectMPerson.refWdbeMCoreproject = " + to_string(preRefCpr) + "";
	rerun_filtSQL(sqlstr, preX1, false);
	dbswdbe->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWdbeQCprMNPerson(jref, jnum, mref, ref, x1Startd, x1Stopd, srefKFunction)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWdbeMPerson.ref, TblWdbeRMCoreprojectMPerson.ref, TblWdbeRMCoreprojectMPerson.x1Startd, TblWdbeRMCoreprojectMPerson.x1Stopd, TblWdbeRMCoreprojectMPerson.srefKFunction";
	sqlstr += " FROM TblWdbeRMCoreprojectMPerson, TblWdbeMPerson";
	sqlstr += " WHERE TblWdbeRMCoreprojectMPerson.refWdbeMPerson = TblWdbeMPerson.ref";
	sqlstr += " AND TblWdbeRMCoreprojectMPerson.refWdbeMCoreproject = " + to_string(preRefCpr) + "";
	rerun_filtSQL(sqlstr, preX1, false);
	sqlstr += " ORDER BY TblWdbeMPerson.Lastname ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswdbe->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWdbeQCprMNPerson SET jnum = qref WHERE jref = " + to_string(jref);
	dbswdbe->executeQuery(sqlstr);

	ixWdbeVQrystate = VecWdbeVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswdbe);

	if (call) xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBESTATCHG, jref);

	xchg->addRefClstn(VecWdbeVCall::CALLWDBECPRRPRSMOD_CPREQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefCpr);
};

void QryWdbeCprMNPerson::rerun_filtSQL(
			string& sqlstr
			, const int preX1
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1 != numeric_limits<int>::min()) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeRMCoreprojectMPerson.x1Startd <= " + to_string(preX1) + "";
	};

	if (preX1 != numeric_limits<int>::min()) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeRMCoreprojectMPerson.x1Stopd >= " + to_string(preX1) + "";
	};
};

void QryWdbeCprMNPerson::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWdbeCprMNPerson::fetch(
			DbsWdbe* dbswdbe
		) {
	string sqlstr;

	StmgrWdbe* stmgr = NULL;
	Stcch* stcch = NULL;

	WdbeQCprMNPerson* rec = NULL;

	dbswdbe->tblwdbeqcprmnperson->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubMref = StubWdbe::getStubPrsStd(dbswdbe, rec->mref, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->ftmX1Startd = Ftm::date(rec->x1Startd);
			rec->ftmX1Stopd = Ftm::date(rec->x1Stopd);
			rec->titSrefKFunction = dbswdbe->getKlstTitleBySref(VecWdbeVKeylist::KLSTWDBEKRMCOREPROJECTMPERSONFUNCTION, rec->srefKFunction, ixWdbeVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWdbeCprMNPerson", "fetch");
	};

	refreshJnum();
};

uint QryWdbeCprMNPerson::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WdbeQCprMNPerson* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWdbeCprMNPerson::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WdbeQCprMNPerson* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WdbeQCprMNPerson* QryWdbeCprMNPerson::getRecByJnum(
			const uint jnum
		) {
	WdbeQCprMNPerson* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWdbeCprMNPerson::handleRequest(
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

bool QryWdbeCprMNPerson::handleRerun(
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

bool QryWdbeCprMNPerson::handleShow(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	WdbeQCprMNPerson* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tmref";
	cout << "\tstubMref";
	cout << "\tref";
	cout << "\tx1Startd";
	cout << "\tftmX1Startd";
	cout << "\tx1Stopd";
	cout << "\tftmX1Stopd";
	cout << "\tsrefKFunction";
	cout << "\ttitSrefKFunction";
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
		cout << "\t" << rec->x1Startd;
		cout << "\t" << rec->ftmX1Startd;
		cout << "\t" << rec->x1Stopd;
		cout << "\t" << rec->ftmX1Stopd;
		cout << "\t" << rec->srefKFunction;
		cout << "\t" << rec->titSrefKFunction;
		cout << endl;
	};
	return retval;
};

void QryWdbeCprMNPerson::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if ((call->ixVCall == VecWdbeVCall::CALLWDBESTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWdbeStubChgFromSelf(dbswdbe);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBECPRRPRSMOD_CPREQ) {
		call->abort = handleCallWdbeCprRprsMod_cprEq(dbswdbe, call->jref);
	};
};

bool QryWdbeCprMNPerson::handleCallWdbeStubChgFromSelf(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleCallWdbeStubChgFromSelf --- INSERT
	return retval;
};

bool QryWdbeCprMNPerson::handleCallWdbeCprRprsMod_cprEq(
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
