/**
	* \file QryWdbeCvrAIp.cpp
	* job handler for job QryWdbeCvrAIp (implementation)
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

#include "QryWdbeCvrAIp.h"

#include "QryWdbeCvrAIp_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWdbeCvrAIp
 ******************************************************************************/

QryWdbeCvrAIp::QryWdbeCvrAIp(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::QRYWDBECVRAIP, jrefSup, ixWdbeVLocale)
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

QryWdbeCvrAIp::~QryWdbeCvrAIp() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWdbeCvrAIp::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWdbeCvrAIp::rerun(
			DbsWdbe* dbswdbe
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefCvr = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCVR, jref);

	xchg->removeClstns(VecWdbeVCall::CALLWDBECVRAIPXMOD_CVREQ, jref);

	dbswdbe->tblwdbeqselect->removeRstByJref(jref);
	dbswdbe->tblwdbeqcvraip->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWdbeAMCoreversionIp.ref)";
	sqlstr += " FROM TblWdbeAMCoreversionIp";
	sqlstr += " WHERE TblWdbeAMCoreversionIp.cvrRefWdbeMCoreversion = " + to_string(preRefCvr) + "";
	dbswdbe->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWdbeQCvrAIp(jref, jnum, ref, cvrNum, sref, ixVTagtype, Comment)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWdbeAMCoreversionIp.ref, TblWdbeAMCoreversionIp.cvrNum, TblWdbeAMCoreversionIp.sref, TblWdbeAMCoreversionIp.ixVTagtype, TblWdbeAMCoreversionIp.Comment";
	sqlstr += " FROM TblWdbeAMCoreversionIp";
	sqlstr += " WHERE TblWdbeAMCoreversionIp.cvrRefWdbeMCoreversion = " + to_string(preRefCvr) + "";
	sqlstr += " ORDER BY cvrNum ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswdbe->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWdbeQCvrAIp SET jnum = qref WHERE jref = " + to_string(jref);
	dbswdbe->executeQuery(sqlstr);

	ixWdbeVQrystate = VecWdbeVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswdbe);

	if (call) xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBESTATCHG, jref);

	xchg->addRefClstn(VecWdbeVCall::CALLWDBECVRAIPXMOD_CVREQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefCvr);
};

void QryWdbeCvrAIp::fetch(
			DbsWdbe* dbswdbe
		) {
	string sqlstr;

	StmgrWdbe* stmgr = NULL;
	Stcch* stcch = NULL;

	WdbeQCvrAIp* rec = NULL;

	dbswdbe->tblwdbeqcvraip->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefIxVTagtype = VecWdbeVAMCoreversionIpTagtype::getSref(rec->ixVTagtype);
			rec->titIxVTagtype = VecWdbeVAMCoreversionIpTagtype::getTitle(rec->ixVTagtype, ixWdbeVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWdbeCvrAIp", "fetch");
	};

	refreshJnum();
};

uint QryWdbeCvrAIp::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WdbeQCvrAIp* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWdbeCvrAIp::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WdbeQCvrAIp* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WdbeQCvrAIp* QryWdbeCvrAIp::getRecByJnum(
			const uint jnum
		) {
	WdbeQCvrAIp* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWdbeCvrAIp::handleRequest(
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

bool QryWdbeCvrAIp::handleRerun(
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

bool QryWdbeCvrAIp::handleShow(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	WdbeQCvrAIp* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tcvrNum";
	cout << "\tsref";
	cout << "\tixVTagtype";
	cout << "\tsrefIxVTagtype";
	cout << "\ttitIxVTagtype";
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
		cout << "\t" << rec->ixVTagtype;
		cout << "\t" << rec->srefIxVTagtype;
		cout << "\t" << rec->titIxVTagtype;
		cout << "\t" << rec->Comment;
		cout << endl;
	};
	return retval;
};

void QryWdbeCvrAIp::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBECVRAIPXMOD_CVREQ) {
		call->abort = handleCallWdbeCvrAipxMod_cvrEq(dbswdbe, call->jref);
	} else if ((call->ixVCall == VecWdbeVCall::CALLWDBESTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWdbeStubChgFromSelf(dbswdbe);
	};
};

bool QryWdbeCvrAIp::handleCallWdbeCvrAipxMod_cvrEq(
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

bool QryWdbeCvrAIp::handleCallWdbeStubChgFromSelf(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleCallWdbeStubChgFromSelf --- INSERT
	return retval;
};
