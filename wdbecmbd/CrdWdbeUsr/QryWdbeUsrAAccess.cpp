/**
	* \file QryWdbeUsrAAccess.cpp
	* job handler for job QryWdbeUsrAAccess (implementation)
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

#include "QryWdbeUsrAAccess.h"

#include "QryWdbeUsrAAccess_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWdbeUsrAAccess
 ******************************************************************************/

QryWdbeUsrAAccess::QryWdbeUsrAAccess(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::QRYWDBEUSRAACCESS, jrefSup, ixWdbeVLocale)
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

QryWdbeUsrAAccess::~QryWdbeUsrAAccess() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWdbeUsrAAccess::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWdbeUsrAAccess::rerun(
			DbsWdbe* dbswdbe
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefUsr = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUSR, jref);
	uint preX1 = xchg->getIxPreset(VecWdbeVPreset::PREWDBEUSRAACCESS_X1, jref);
	string preX2 = xchg->getSrefPreset(VecWdbeVPreset::PREWDBEUSRAACCESS_X2, jref);

	xchg->removeClstns(VecWdbeVCall::CALLWDBEUSRAACCMOD_USREQ, jref);

	dbswdbe->tblwdbeqselect->removeRstByJref(jref);
	dbswdbe->tblwdbequsraaccess->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWdbeAMUserAccess.ref)";
	sqlstr += " FROM TblWdbeAMUserAccess";
	sqlstr += " WHERE TblWdbeAMUserAccess.refWdbeMUser = " + to_string(preRefUsr) + "";
	rerun_filtSQL(sqlstr, preX1, preX2, false);
	dbswdbe->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWdbeQUsrAAccess(jref, jnum, ref, x1IxWdbeVFeatgroup, x2FeaSrefUix, ixWdbeWAccess)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWdbeAMUserAccess.ref, TblWdbeAMUserAccess.x1IxWdbeVFeatgroup, TblWdbeAMUserAccess.x2FeaSrefUix, TblWdbeAMUserAccess.ixWdbeWAccess";
	sqlstr += " FROM TblWdbeAMUserAccess";
	sqlstr += " WHERE TblWdbeAMUserAccess.refWdbeMUser = " + to_string(preRefUsr) + "";
	rerun_filtSQL(sqlstr, preX1, preX2, false);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswdbe->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWdbeQUsrAAccess SET jnum = qref WHERE jref = " + to_string(jref);
	dbswdbe->executeQuery(sqlstr);

	ixWdbeVQrystate = VecWdbeVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswdbe);

	if (call) xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBESTATCHG, jref);

	xchg->addRefClstn(VecWdbeVCall::CALLWDBEUSRAACCMOD_USREQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefUsr);
};

void QryWdbeUsrAAccess::rerun_filtSQL(
			string& sqlstr
			, const uint preX1
			, const string& preX2
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1 != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeAMUserAccess.x1IxWdbeVFeatgroup = " + to_string(preX1) + "";
	};

	if (preX2.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeAMUserAccess.x2FeaSrefUix = " + preX2 + "";
	};
};

void QryWdbeUsrAAccess::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWdbeUsrAAccess::fetch(
			DbsWdbe* dbswdbe
		) {
	string sqlstr;

	StmgrWdbe* stmgr = NULL;
	Stcch* stcch = NULL;

	WdbeQUsrAAccess* rec = NULL;

	dbswdbe->tblwdbequsraaccess->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefX1IxWdbeVFeatgroup = VecWdbeVFeatgroup::getSref(rec->x1IxWdbeVFeatgroup);
			rec->titX1IxWdbeVFeatgroup = VecWdbeVFeatgroup::getTitle(rec->x1IxWdbeVFeatgroup, ixWdbeVLocale);
			rec->srefsIxWdbeWAccess = VecWdbeWAccess::getSrefs(rec->ixWdbeWAccess);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWdbeUsrAAccess", "fetch");
	};

	refreshJnum();
};

uint QryWdbeUsrAAccess::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WdbeQUsrAAccess* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWdbeUsrAAccess::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WdbeQUsrAAccess* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WdbeQUsrAAccess* QryWdbeUsrAAccess::getRecByJnum(
			const uint jnum
		) {
	WdbeQUsrAAccess* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWdbeUsrAAccess::handleRequest(
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

bool QryWdbeUsrAAccess::handleRerun(
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

bool QryWdbeUsrAAccess::handleShow(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	WdbeQUsrAAccess* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tx1IxWdbeVFeatgroup";
	cout << "\tsrefX1IxWdbeVFeatgroup";
	cout << "\ttitX1IxWdbeVFeatgroup";
	cout << "\tx2FeaSrefUix";
	cout << "\tixWdbeWAccess";
	cout << "\tsrefsIxWdbeWAccess";
	cout << "\ttitsIxWdbeWAccess";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->x1IxWdbeVFeatgroup;
		cout << "\t" << rec->srefX1IxWdbeVFeatgroup;
		cout << "\t" << rec->titX1IxWdbeVFeatgroup;
		cout << "\t" << rec->x2FeaSrefUix;
		cout << "\t" << rec->ixWdbeWAccess;
		cout << "\t" << rec->srefsIxWdbeWAccess;
		cout << "\t" << rec->titsIxWdbeWAccess;
		cout << endl;
	};
	return retval;
};

void QryWdbeUsrAAccess::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBEUSRAACCMOD_USREQ) {
		call->abort = handleCallWdbeUsrAaccMod_usrEq(dbswdbe, call->jref);
	} else if ((call->ixVCall == VecWdbeVCall::CALLWDBESTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWdbeStubChgFromSelf(dbswdbe);
	};
};

bool QryWdbeUsrAAccess::handleCallWdbeUsrAaccMod_usrEq(
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

bool QryWdbeUsrAAccess::handleCallWdbeStubChgFromSelf(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleCallWdbeStubChgFromSelf --- INSERT
	return retval;
};



