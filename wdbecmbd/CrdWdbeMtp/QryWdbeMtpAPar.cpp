/**
	* \file QryWdbeMtpAPar.cpp
	* job handler for job QryWdbeMtpAPar (implementation)
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

#include "QryWdbeMtpAPar.h"

#include "QryWdbeMtpAPar_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWdbeMtpAPar
 ******************************************************************************/

QryWdbeMtpAPar::QryWdbeMtpAPar(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::QRYWDBEMTPAPAR, jrefSup, ixWdbeVLocale)
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

QryWdbeMtpAPar::~QryWdbeMtpAPar() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWdbeMtpAPar::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWdbeMtpAPar::rerun(
			DbsWdbe* dbswdbe
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefMtp = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFMTP, jref);
	string preX1 = xchg->getSrefPreset(VecWdbeVPreset::PREWDBEMTPAPAR_X1, jref);

	xchg->removeClstns(VecWdbeVCall::CALLWDBEMDLAPARMOD_MDLEQ, jref);

	dbswdbe->tblwdbeqselect->removeRstByJref(jref);
	dbswdbe->tblwdbeqmtpapar->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWdbeAMModulePar.ref)";
	sqlstr += " FROM TblWdbeAMModulePar";
	sqlstr += " WHERE TblWdbeAMModulePar.mdlRefWdbeMModule = " + to_string(preRefMtp) + "";
	rerun_filtSQL(sqlstr, preX1, false);
	dbswdbe->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWdbeQMtpAPar(jref, jnum, ref, mdlNum, x1SrefKKey, Val)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWdbeAMModulePar.ref, TblWdbeAMModulePar.mdlNum, TblWdbeAMModulePar.x1SrefKKey, TblWdbeAMModulePar.Val";
	sqlstr += " FROM TblWdbeAMModulePar";
	sqlstr += " WHERE TblWdbeAMModulePar.mdlRefWdbeMModule = " + to_string(preRefMtp) + "";
	rerun_filtSQL(sqlstr, preX1, false);
	sqlstr += " ORDER BY mdlNum ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswdbe->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWdbeQMtpAPar SET jnum = qref WHERE jref = " + to_string(jref);
	dbswdbe->executeQuery(sqlstr);

	ixWdbeVQrystate = VecWdbeVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswdbe);

	if (call) xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBESTATCHG, jref);

	xchg->addRefClstn(VecWdbeVCall::CALLWDBEMDLAPARMOD_MDLEQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefMtp);
};

void QryWdbeMtpAPar::rerun_filtSQL(
			string& sqlstr
			, const string& preX1
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeAMModulePar.x1SrefKKey = '" + preX1 + "'";
	};
};

void QryWdbeMtpAPar::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWdbeMtpAPar::fetch(
			DbsWdbe* dbswdbe
		) {
	string sqlstr;

	StmgrWdbe* stmgr = NULL;
	Stcch* stcch = NULL;

	WdbeQMtpAPar* rec = NULL;

	dbswdbe->tblwdbeqmtpapar->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->titX1SrefKKey = dbswdbe->getKlstTitleBySref(VecWdbeVKeylist::KLSTWDBEKAMMODULEPARKEY, rec->x1SrefKKey, ixWdbeVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWdbeMtpAPar", "fetch");
	};

	refreshJnum();
};

uint QryWdbeMtpAPar::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WdbeQMtpAPar* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWdbeMtpAPar::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WdbeQMtpAPar* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WdbeQMtpAPar* QryWdbeMtpAPar::getRecByJnum(
			const uint jnum
		) {
	WdbeQMtpAPar* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWdbeMtpAPar::handleRequest(
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

bool QryWdbeMtpAPar::handleRerun(
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

bool QryWdbeMtpAPar::handleShow(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	WdbeQMtpAPar* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tmdlNum";
	cout << "\tx1SrefKKey";
	cout << "\ttitX1SrefKKey";
	cout << "\tVal";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->mdlNum;
		cout << "\t" << rec->x1SrefKKey;
		cout << "\t" << rec->titX1SrefKKey;
		cout << "\t" << rec->Val;
		cout << endl;
	};
	return retval;
};

void QryWdbeMtpAPar::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBEMDLAPARMOD_MDLEQ) {
		call->abort = handleCallWdbeMdlAparMod_mdlEq(dbswdbe, call->jref);
	} else if ((call->ixVCall == VecWdbeVCall::CALLWDBESTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWdbeStubChgFromSelf(dbswdbe);
	};
};

bool QryWdbeMtpAPar::handleCallWdbeMdlAparMod_mdlEq(
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

bool QryWdbeMtpAPar::handleCallWdbeStubChgFromSelf(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleCallWdbeStubChgFromSelf --- INSERT
	return retval;
};
