/**
	* \file QryWdbePrsMNProject.cpp
	* job handler for job QryWdbePrsMNProject (implementation)
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

#include "QryWdbePrsMNProject.h"

#include "QryWdbePrsMNProject_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWdbePrsMNProject
 ******************************************************************************/

QryWdbePrsMNProject::QryWdbePrsMNProject(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::QRYWDBEPRSMNPROJECT, jrefSup, ixWdbeVLocale)
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

QryWdbePrsMNProject::~QryWdbePrsMNProject() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWdbePrsMNProject::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWdbePrsMNProject::rerun(
			DbsWdbe* dbswdbe
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefPrs = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFPRS, jref);
	int preX1 = xchg->getIntvalPreset(VecWdbeVPreset::PREWDBEPRSMNPROJECT_X1, jref);

	xchg->removeClstns(VecWdbeVCall::CALLWDBEPRSRPRJMOD_PRSEQ, jref);

	dbswdbe->tblwdbeqselect->removeRstByJref(jref);
	dbswdbe->tblwdbeqprsmnproject->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWdbeRMPersonMProject.ref)";
	sqlstr += " FROM TblWdbeMProject, TblWdbeRMPersonMProject";
	sqlstr += " WHERE TblWdbeRMPersonMProject.refWdbeMProject = TblWdbeMProject.ref";
	sqlstr += " AND TblWdbeRMPersonMProject.refWdbeMPerson = " + to_string(preRefPrs) + "";
	rerun_filtSQL(sqlstr, preX1, false);
	dbswdbe->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWdbeQPrsMNProject(jref, jnum, mref, ref, x1Startd, x1Stopd, srefKFunction)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWdbeMProject.ref, TblWdbeRMPersonMProject.ref, TblWdbeRMPersonMProject.x1Startd, TblWdbeRMPersonMProject.x1Stopd, TblWdbeRMPersonMProject.srefKFunction";
	sqlstr += " FROM TblWdbeMProject, TblWdbeRMPersonMProject";
	sqlstr += " WHERE TblWdbeRMPersonMProject.refWdbeMProject = TblWdbeMProject.ref";
	sqlstr += " AND TblWdbeRMPersonMProject.refWdbeMPerson = " + to_string(preRefPrs) + "";
	rerun_filtSQL(sqlstr, preX1, false);
	sqlstr += " ORDER BY TblWdbeMProject.Short ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswdbe->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWdbeQPrsMNProject SET jnum = qref WHERE jref = " + to_string(jref);
	dbswdbe->executeQuery(sqlstr);

	ixWdbeVQrystate = VecWdbeVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswdbe);

	if (call) xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBESTATCHG, jref);

	xchg->addRefClstn(VecWdbeVCall::CALLWDBEPRSRPRJMOD_PRSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefPrs);
};

void QryWdbePrsMNProject::rerun_filtSQL(
			string& sqlstr
			, const int preX1
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1 != numeric_limits<int>::min()) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeRMPersonMProject.x1Startd <= " + to_string(preX1) + "";
	};

	if (preX1 != numeric_limits<int>::min()) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeRMPersonMProject.x1Stopd >= " + to_string(preX1) + "";
	};
};

void QryWdbePrsMNProject::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWdbePrsMNProject::fetch(
			DbsWdbe* dbswdbe
		) {
	string sqlstr;

	StmgrWdbe* stmgr = NULL;
	Stcch* stcch = NULL;

	WdbeQPrsMNProject* rec = NULL;

	dbswdbe->tblwdbeqprsmnproject->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubMref = StubWdbe::getStubPrjStd(dbswdbe, rec->mref, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->ftmX1Startd = Ftm::date(rec->x1Startd);
			rec->ftmX1Stopd = Ftm::date(rec->x1Stopd);
			rec->titSrefKFunction = dbswdbe->getKlstTitleBySref(VecWdbeVKeylist::KLSTWDBEKRMPERSONMPROJECTFUNCTION, rec->srefKFunction, ixWdbeVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWdbePrsMNProject", "fetch");
	};

	refreshJnum();
};

uint QryWdbePrsMNProject::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WdbeQPrsMNProject* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWdbePrsMNProject::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WdbeQPrsMNProject* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WdbeQPrsMNProject* QryWdbePrsMNProject::getRecByJnum(
			const uint jnum
		) {
	WdbeQPrsMNProject* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWdbePrsMNProject::handleRequest(
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

bool QryWdbePrsMNProject::handleRerun(
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

bool QryWdbePrsMNProject::handleShow(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	WdbeQPrsMNProject* rec = NULL;

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

void QryWdbePrsMNProject::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBEPRSRPRJMOD_PRSEQ) {
		call->abort = handleCallWdbePrsRprjMod_prsEq(dbswdbe, call->jref);
	} else if ((call->ixVCall == VecWdbeVCall::CALLWDBESTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWdbeStubChgFromSelf(dbswdbe);
	};
};

bool QryWdbePrsMNProject::handleCallWdbePrsRprjMod_prsEq(
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

bool QryWdbePrsMNProject::handleCallWdbeStubChgFromSelf(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleCallWdbeStubChgFromSelf --- INSERT
	return retval;
};
