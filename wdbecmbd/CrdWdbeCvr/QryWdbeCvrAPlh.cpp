/**
	* \file QryWdbeCvrAPlh.cpp
	* job handler for job QryWdbeCvrAPlh (implementation)
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

#include "QryWdbeCvrAPlh.h"

#include "QryWdbeCvrAPlh_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWdbeCvrAPlh
 ******************************************************************************/

QryWdbeCvrAPlh::QryWdbeCvrAPlh(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::QRYWDBECVRAPLH, jrefSup, ixWdbeVLocale)
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

QryWdbeCvrAPlh::~QryWdbeCvrAPlh() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWdbeCvrAPlh::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWdbeCvrAPlh::rerun(
			DbsWdbe* dbswdbe
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefCvr = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCVR, jref);

	xchg->removeClstns(VecWdbeVCall::CALLWDBECVRAPLHMOD_CVREQ, jref);

	dbswdbe->tblwdbeqselect->removeRstByJref(jref);
	dbswdbe->tblwdbeqcvraplh->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWdbeAMCoreversionPlh.ref)";
	sqlstr += " FROM TblWdbeAMCoreversionPlh";
	sqlstr += " WHERE TblWdbeAMCoreversionPlh.cvrRefWdbeMCoreversion = " + to_string(preRefCvr) + "";
	dbswdbe->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWdbeQCvrAPlh(jref, jnum, ref, cvrNum, sref, Comment)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWdbeAMCoreversionPlh.ref, TblWdbeAMCoreversionPlh.cvrNum, TblWdbeAMCoreversionPlh.sref, TblWdbeAMCoreversionPlh.Comment";
	sqlstr += " FROM TblWdbeAMCoreversionPlh";
	sqlstr += " WHERE TblWdbeAMCoreversionPlh.cvrRefWdbeMCoreversion = " + to_string(preRefCvr) + "";
	sqlstr += " ORDER BY cvrNum ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswdbe->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWdbeQCvrAPlh SET jnum = qref WHERE jref = " + to_string(jref);
	dbswdbe->executeQuery(sqlstr);

	ixWdbeVQrystate = VecWdbeVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswdbe);

	if (call) xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBESTATCHG, jref);

	xchg->addRefClstn(VecWdbeVCall::CALLWDBECVRAPLHMOD_CVREQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefCvr);
};

void QryWdbeCvrAPlh::fetch(
			DbsWdbe* dbswdbe
		) {
	string sqlstr;

	StmgrWdbe* stmgr = NULL;
	Stcch* stcch = NULL;

	WdbeQCvrAPlh* rec = NULL;

	dbswdbe->tblwdbeqcvraplh->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWdbeCvrAPlh", "fetch");
	};

	refreshJnum();
};

uint QryWdbeCvrAPlh::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WdbeQCvrAPlh* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWdbeCvrAPlh::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WdbeQCvrAPlh* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WdbeQCvrAPlh* QryWdbeCvrAPlh::getRecByJnum(
			const uint jnum
		) {
	WdbeQCvrAPlh* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWdbeCvrAPlh::handleRequest(
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

bool QryWdbeCvrAPlh::handleRerun(
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

bool QryWdbeCvrAPlh::handleShow(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	WdbeQCvrAPlh* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tcvrNum";
	cout << "\tsref";
	cout << "\tComment";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->cvrNum;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->Comment;
		cout << endl;
	};
	return retval;
};

void QryWdbeCvrAPlh::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if ((call->ixVCall == VecWdbeVCall::CALLWDBESTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWdbeStubChgFromSelf(dbswdbe);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBECVRAPLHMOD_CVREQ) {
		call->abort = handleCallWdbeCvrAplhMod_cvrEq(dbswdbe, call->jref);
	};
};

bool QryWdbeCvrAPlh::handleCallWdbeStubChgFromSelf(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleCallWdbeStubChgFromSelf --- INSERT
	return retval;
};

bool QryWdbeCvrAPlh::handleCallWdbeCvrAplhMod_cvrEq(
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
