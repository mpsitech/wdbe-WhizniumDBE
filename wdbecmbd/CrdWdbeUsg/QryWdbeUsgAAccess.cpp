/**
	* \file QryWdbeUsgAAccess.cpp
	* job handler for job QryWdbeUsgAAccess (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbed.h>
#endif

#include "QryWdbeUsgAAccess.h"

#include "QryWdbeUsgAAccess_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWdbeUsgAAccess
 ******************************************************************************/

QryWdbeUsgAAccess::QryWdbeUsgAAccess(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::QRYWDBEUSGAACCESS, jrefSup, ixWdbeVLocale)
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

QryWdbeUsgAAccess::~QryWdbeUsgAAccess() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWdbeUsgAAccess::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWdbeUsgAAccess::rerun(
			DbsWdbe* dbswdbe
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefUsg = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUSG, jref);
	uint preX1 = xchg->getIxPreset(VecWdbeVPreset::PREWDBEUSGAACCESS_X1, jref);
	string preX2 = xchg->getSrefPreset(VecWdbeVPreset::PREWDBEUSGAACCESS_X2, jref);

	xchg->removeClstns(VecWdbeVCall::CALLWDBEUSGAACCMOD_USGEQ, jref);

	dbswdbe->tblwdbeqselect->removeRstByJref(jref);
	dbswdbe->tblwdbequsgaaccess->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWdbeAMUsergroupAccess.ref)";
	sqlstr += " FROM TblWdbeAMUsergroupAccess";
	sqlstr += " WHERE TblWdbeAMUsergroupAccess.refWdbeMUsergroup = " + to_string(preRefUsg) + "";
	rerun_filtSQL(sqlstr, preX1, preX2, false);
	dbswdbe->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWdbeQUsgAAccess(jref, jnum, ref, x1IxWdbeVFeatgroup, x2FeaSrefUix, ixWdbeWAccess)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWdbeAMUsergroupAccess.ref, TblWdbeAMUsergroupAccess.x1IxWdbeVFeatgroup, TblWdbeAMUsergroupAccess.x2FeaSrefUix, TblWdbeAMUsergroupAccess.ixWdbeWAccess";
	sqlstr += " FROM TblWdbeAMUsergroupAccess";
	sqlstr += " WHERE TblWdbeAMUsergroupAccess.refWdbeMUsergroup = " + to_string(preRefUsg) + "";
	rerun_filtSQL(sqlstr, preX1, preX2, false);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswdbe->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWdbeQUsgAAccess SET jnum = qref WHERE jref = " + to_string(jref);
	dbswdbe->executeQuery(sqlstr);

	ixWdbeVQrystate = VecWdbeVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswdbe);

	if (call) xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBESTATCHG, jref);

	xchg->addRefClstn(VecWdbeVCall::CALLWDBEUSGAACCMOD_USGEQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefUsg);
};

void QryWdbeUsgAAccess::rerun_filtSQL(
			string& sqlstr
			, const uint preX1
			, const string& preX2
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1 != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeAMUsergroupAccess.x1IxWdbeVFeatgroup = " + to_string(preX1) + "";
	};

	if (preX2.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeAMUsergroupAccess.x2FeaSrefUix = " + preX2 + "";
	};
};

void QryWdbeUsgAAccess::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWdbeUsgAAccess::fetch(
			DbsWdbe* dbswdbe
		) {
	string sqlstr;

	StmgrWdbe* stmgr = NULL;
	Stcch* stcch = NULL;

	WdbeQUsgAAccess* rec = NULL;

	dbswdbe->tblwdbequsgaaccess->loadRstByJref(jref, false, rst);
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
		stmgr->unlockAccess("QryWdbeUsgAAccess", "fetch");
	};

	refreshJnum();
};

uint QryWdbeUsgAAccess::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WdbeQUsgAAccess* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWdbeUsgAAccess::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WdbeQUsgAAccess* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WdbeQUsgAAccess* QryWdbeUsgAAccess::getRecByJnum(
			const uint jnum
		) {
	WdbeQUsgAAccess* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWdbeUsgAAccess::handleRequest(
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

bool QryWdbeUsgAAccess::handleRerun(
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

bool QryWdbeUsgAAccess::handleShow(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	WdbeQUsgAAccess* rec = NULL;

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

void QryWdbeUsgAAccess::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBEUSGAACCMOD_USGEQ) {
		call->abort = handleCallWdbeUsgAaccMod_usgEq(dbswdbe, call->jref);
	} else if ((call->ixVCall == VecWdbeVCall::CALLWDBESTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWdbeStubChgFromSelf(dbswdbe);
	};
};

bool QryWdbeUsgAAccess::handleCallWdbeUsgAaccMod_usgEq(
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

bool QryWdbeUsgAAccess::handleCallWdbeStubChgFromSelf(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleCallWdbeStubChgFromSelf --- INSERT
	return retval;
};

