/**
	* \file QryWdbePrcKHdltype.cpp
	* job handler for job QryWdbePrcKHdltype (implementation)
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

#include "QryWdbePrcKHdltype.h"

#include "QryWdbePrcKHdltype_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWdbePrcKHdltype
 ******************************************************************************/

QryWdbePrcKHdltype::QryWdbePrcKHdltype(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::QRYWDBEPRCKHDLTYPE, jrefSup, ixWdbeVLocale)
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

QryWdbePrcKHdltype::~QryWdbePrcKHdltype() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWdbePrcKHdltype::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWdbePrcKHdltype::rerun(
			DbsWdbe* dbswdbe
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefPrc = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFPRC, jref);

	xchg->removeClstns(VecWdbeVCall::CALLWDBEKLSAKEYMOD_KLSMTBURFEQ, jref);

	dbswdbe->tblwdbeqselect->removeRstByJref(jref);
	dbswdbe->tblwdbeqprckhdltype->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWdbeAVKeylistKey.ref)";
	sqlstr += " FROM TblWdbeAVKeylistKey";
	sqlstr += " WHERE klsIxWdbeVKeylist = " + to_string(VecWdbeVKeylist::KLSTWDBEKHDLTYPE);
	sqlstr += " AND x1IxWdbeVMaintable = " + to_string(VecWdbeVMaintable::TBLWDBEMPROCESS);
	sqlstr += " AND x1Uref = " + to_string(preRefPrc) + "";
	dbswdbe->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWdbeQPrcKHdltype(jref, jnum, ref, klsNum, Fixed, sref, Avail, Implied, refJ, Title, Comment)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWdbeAVKeylistKey.ref, TblWdbeAVKeylistKey.klsNum, TblWdbeAVKeylistKey.Fixed, TblWdbeAVKeylistKey.sref, TblWdbeAVKeylistKey.Avail, TblWdbeAVKeylistKey.Implied, TblWdbeAVKeylistKey.refJ, TblWdbeAVKeylistKey.Title, TblWdbeAVKeylistKey.Comment";
	sqlstr += " FROM TblWdbeAVKeylistKey";
	sqlstr += " WHERE klsIxWdbeVKeylist = " + to_string(VecWdbeVKeylist::KLSTWDBEKHDLTYPE);
	sqlstr += " AND x1IxWdbeVMaintable = " + to_string(VecWdbeVMaintable::TBLWDBEMPROCESS);
	sqlstr += " AND x1Uref = " + to_string(preRefPrc) + "";
	sqlstr += " ORDER BY TblWdbeAVKeylistKey.klsNum ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswdbe->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWdbeQPrcKHdltype SET jnum = qref WHERE jref = " + to_string(jref);
	dbswdbe->executeQuery(sqlstr);

	ixWdbeVQrystate = VecWdbeVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswdbe);

	if (call) xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBESTATCHG, jref);

	xchg->addIxRefSrefClstn(VecWdbeVCall::CALLWDBEKLSAKEYMOD_KLSMTBURFEQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWdbeVMaintable::TBLWDBEMPROCESS, preRefPrc, VecWdbeVKeylist::getSref(VecWdbeVKeylist::KLSTWDBEKHDLTYPE));
};

void QryWdbePrcKHdltype::fetch(
			DbsWdbe* dbswdbe
		) {
	string sqlstr;

	StmgrWdbe* stmgr = NULL;
	Stcch* stcch = NULL;

	WdbeQPrcKHdltype* rec = NULL;

	dbswdbe->tblwdbeqprckhdltype->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			if (rec->Fixed) rec->yesnoFixed = VecWdbeVTag::getTitle(VecWdbeVTag::YES, ixWdbeVLocale); else rec->yesnoFixed = VecWdbeVTag::getTitle(VecWdbeVTag::NO, ixWdbeVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWdbePrcKHdltype", "fetch");
	};

	refreshJnum();
};

uint QryWdbePrcKHdltype::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WdbeQPrcKHdltype* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWdbePrcKHdltype::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WdbeQPrcKHdltype* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WdbeQPrcKHdltype* QryWdbePrcKHdltype::getRecByJnum(
			const uint jnum
		) {
	WdbeQPrcKHdltype* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWdbePrcKHdltype::handleRequest(
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

bool QryWdbePrcKHdltype::handleRerun(
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

bool QryWdbePrcKHdltype::handleShow(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	WdbeQPrcKHdltype* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tklsNum";
	cout << "\tFixed";
	cout << "\tyesnoFixed";
	cout << "\tsref";
	cout << "\tAvail";
	cout << "\tImplied";
	cout << "\trefJ";
	cout << "\tTitle";
	cout << "\tComment";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->klsNum;
		cout << "\t" << rec->Fixed;
		cout << "\t" << rec->yesnoFixed;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->Avail;
		cout << "\t" << rec->Implied;
		cout << "\t" << rec->refJ;
		cout << "\t" << rec->Title;
		cout << "\t" << rec->Comment;
		cout << endl;
	};
	return retval;
};

void QryWdbePrcKHdltype::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if ((call->ixVCall == VecWdbeVCall::CALLWDBESTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWdbeStubChgFromSelf(dbswdbe);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEKLSAKEYMOD_KLSMTBURFEQ) {
		call->abort = handleCallWdbeKlsAkeyMod_klsMtbUrfEq(dbswdbe, call->jref);
	};
};

bool QryWdbePrcKHdltype::handleCallWdbeStubChgFromSelf(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleCallWdbeStubChgFromSelf --- INSERT
	return retval;
};

bool QryWdbePrcKHdltype::handleCallWdbeKlsAkeyMod_klsMtbUrfEq(
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
