/**
	* \file QryWdbeLibAMakefile.cpp
	* job handler for job QryWdbeLibAMakefile (implementation)
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

#include "QryWdbeLibAMakefile.h"

#include "QryWdbeLibAMakefile_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWdbeLibAMakefile
 ******************************************************************************/

QryWdbeLibAMakefile::QryWdbeLibAMakefile(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::QRYWDBELIBAMAKEFILE, jrefSup, ixWdbeVLocale)
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

QryWdbeLibAMakefile::~QryWdbeLibAMakefile() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWdbeLibAMakefile::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWdbeLibAMakefile::rerun(
			DbsWdbe* dbswdbe
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefLib = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFLIB, jref);
	ubigint preX1 = xchg->getRefPreset(VecWdbeVPreset::PREWDBELIBAMAKEFILE_X1, jref);
	string preX2 = xchg->getSrefPreset(VecWdbeVPreset::PREWDBELIBAMAKEFILE_X2, jref);

	xchg->removeClstns(VecWdbeVCall::CALLWDBELIBAMKFMOD_LIBEQ, jref);

	dbswdbe->tblwdbeqselect->removeRstByJref(jref);
	dbswdbe->tblwdbeqlibamakefile->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWdbeAMLibraryMakefile.ref)";
	sqlstr += " FROM TblWdbeAMLibraryMakefile";
	sqlstr += " WHERE TblWdbeAMLibraryMakefile.refWdbeMLibrary = " + to_string(preRefLib) + "";
	rerun_filtSQL(sqlstr, preX1, preX2, false);
	dbswdbe->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWdbeQLibAMakefile(jref, jnum, ref, x1RefWdbeMMachine, x2SrefKTag, Val)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWdbeAMLibraryMakefile.ref, TblWdbeAMLibraryMakefile.x1RefWdbeMMachine, TblWdbeAMLibraryMakefile.x2SrefKTag, TblWdbeAMLibraryMakefile.Val";
	sqlstr += " FROM TblWdbeAMLibraryMakefile";
	sqlstr += " WHERE TblWdbeAMLibraryMakefile.refWdbeMLibrary = " + to_string(preRefLib) + "";
	rerun_filtSQL(sqlstr, preX1, preX2, false);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswdbe->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWdbeQLibAMakefile SET jnum = qref WHERE jref = " + to_string(jref);
	dbswdbe->executeQuery(sqlstr);

	ixWdbeVQrystate = VecWdbeVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswdbe);

	if (call) xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBESTATCHG, jref);

	xchg->addRefClstn(VecWdbeVCall::CALLWDBELIBAMKFMOD_LIBEQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefLib);
};

void QryWdbeLibAMakefile::rerun_filtSQL(
			string& sqlstr
			, const ubigint preX1
			, const string& preX2
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1 != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeAMLibraryMakefile.x1RefWdbeMMachine = " + to_string(preX1) + "";
	};

	if (preX2.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeAMLibraryMakefile.x2SrefKTag = '" + preX2 + "'";
	};
};

void QryWdbeLibAMakefile::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWdbeLibAMakefile::fetch(
			DbsWdbe* dbswdbe
		) {
	string sqlstr;

	StmgrWdbe* stmgr = NULL;
	Stcch* stcch = NULL;

	WdbeQLibAMakefile* rec = NULL;

	dbswdbe->tblwdbeqlibamakefile->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubX1RefWdbeMMachine = StubWdbe::getStubMchStd(dbswdbe, rec->x1RefWdbeMMachine, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->titX2SrefKTag = dbswdbe->getKlstTitleBySref(VecWdbeVKeylist::KLSTWDBEKAMLIBRARYMAKEFILETAG, rec->x2SrefKTag, ixWdbeVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWdbeLibAMakefile", "fetch");
	};

	refreshJnum();
};

uint QryWdbeLibAMakefile::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WdbeQLibAMakefile* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWdbeLibAMakefile::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WdbeQLibAMakefile* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WdbeQLibAMakefile* QryWdbeLibAMakefile::getRecByJnum(
			const uint jnum
		) {
	WdbeQLibAMakefile* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWdbeLibAMakefile::handleRequest(
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

bool QryWdbeLibAMakefile::handleRerun(
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

bool QryWdbeLibAMakefile::handleShow(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	WdbeQLibAMakefile* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tx1RefWdbeMMachine";
	cout << "\tstubX1RefWdbeMMachine";
	cout << "\tx2SrefKTag";
	cout << "\ttitX2SrefKTag";
	cout << "\tVal";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->x1RefWdbeMMachine;
		cout << "\t" << rec->stubX1RefWdbeMMachine;
		cout << "\t" << rec->x2SrefKTag;
		cout << "\t" << rec->titX2SrefKTag;
		cout << "\t" << rec->Val;
		cout << endl;
	};
	return retval;
};

void QryWdbeLibAMakefile::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBELIBAMKFMOD_LIBEQ) {
		call->abort = handleCallWdbeLibAmkfMod_libEq(dbswdbe, call->jref);
	} else if ((call->ixVCall == VecWdbeVCall::CALLWDBESTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWdbeStubChgFromSelf(dbswdbe);
	};
};

bool QryWdbeLibAMakefile::handleCallWdbeLibAmkfMod_libEq(
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

bool QryWdbeLibAMakefile::handleCallWdbeStubChgFromSelf(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleCallWdbeStubChgFromSelf --- INSERT
	return retval;
};
