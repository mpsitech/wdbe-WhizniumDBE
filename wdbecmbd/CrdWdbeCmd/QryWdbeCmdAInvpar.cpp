/**
	* \file QryWdbeCmdAInvpar.cpp
	* job handler for job QryWdbeCmdAInvpar (implementation)
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

#include "QryWdbeCmdAInvpar.h"

#include "QryWdbeCmdAInvpar_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWdbeCmdAInvpar
 ******************************************************************************/

QryWdbeCmdAInvpar::QryWdbeCmdAInvpar(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::QRYWDBECMDAINVPAR, jrefSup, ixWdbeVLocale)
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

QryWdbeCmdAInvpar::~QryWdbeCmdAInvpar() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWdbeCmdAInvpar::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWdbeCmdAInvpar::rerun(
			DbsWdbe* dbswdbe
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefCmd = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCMD, jref);

	xchg->removeClstns(VecWdbeVCall::CALLWDBECMDAIPAMOD_CMDEQ, jref);

	dbswdbe->tblwdbeqselect->removeRstByJref(jref);
	dbswdbe->tblwdbeqcmdainvpar->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWdbeAMCommandInvpar.ref)";
	sqlstr += " FROM TblWdbeAMCommandInvpar";
	sqlstr += " WHERE TblWdbeAMCommandInvpar.cmdRefWdbeMCommand = " + to_string(preRefCmd) + "";
	dbswdbe->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWdbeQCmdAInvpar(jref, jnum, ref, cmdNum, sref, ixWdbeVPartype, refWdbeMVector, Length, Defval, refWdbeMVectoritem, Comment)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWdbeAMCommandInvpar.ref, TblWdbeAMCommandInvpar.cmdNum, TblWdbeAMCommandInvpar.sref, TblWdbeAMCommandInvpar.ixWdbeVPartype, TblWdbeAMCommandInvpar.refWdbeMVector, TblWdbeAMCommandInvpar.Length, TblWdbeAMCommandInvpar.Defval, TblWdbeAMCommandInvpar.refWdbeMVectoritem, TblWdbeAMCommandInvpar.Comment";
	sqlstr += " FROM TblWdbeAMCommandInvpar";
	sqlstr += " WHERE TblWdbeAMCommandInvpar.cmdRefWdbeMCommand = " + to_string(preRefCmd) + "";
	sqlstr += " ORDER BY cmdNum ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswdbe->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWdbeQCmdAInvpar SET jnum = qref WHERE jref = " + to_string(jref);
	dbswdbe->executeQuery(sqlstr);

	ixWdbeVQrystate = VecWdbeVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswdbe);

	if (call) xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBESTATCHG, jref);

	xchg->addRefClstn(VecWdbeVCall::CALLWDBECMDAIPAMOD_CMDEQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefCmd);
};

void QryWdbeCmdAInvpar::fetch(
			DbsWdbe* dbswdbe
		) {
	string sqlstr;

	StmgrWdbe* stmgr = NULL;
	Stcch* stcch = NULL;

	WdbeQCmdAInvpar* rec = NULL;

	dbswdbe->tblwdbeqcmdainvpar->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefIxWdbeVPartype = VecWdbeVPartype::getSref(rec->ixWdbeVPartype);
			rec->titIxWdbeVPartype = VecWdbeVPartype::getTitle(rec->ixWdbeVPartype);
			rec->stubRefWdbeMVector = StubWdbe::getStubVecStd(dbswdbe, rec->refWdbeMVector, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefWdbeMVectoritem = StubWdbe::getStubVitStd(dbswdbe, rec->refWdbeMVectoritem, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWdbeCmdAInvpar", "fetch");
	};

	refreshJnum();
};

uint QryWdbeCmdAInvpar::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WdbeQCmdAInvpar* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWdbeCmdAInvpar::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WdbeQCmdAInvpar* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WdbeQCmdAInvpar* QryWdbeCmdAInvpar::getRecByJnum(
			const uint jnum
		) {
	WdbeQCmdAInvpar* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWdbeCmdAInvpar::handleRequest(
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

bool QryWdbeCmdAInvpar::handleRerun(
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

bool QryWdbeCmdAInvpar::handleShow(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	WdbeQCmdAInvpar* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tcmdNum";
	cout << "\tsref";
	cout << "\tixWdbeVPartype";
	cout << "\tsrefIxWdbeVPartype";
	cout << "\ttitIxWdbeVPartype";
	cout << "\trefWdbeMVector";
	cout << "\tstubRefWdbeMVector";
	cout << "\tLength";
	cout << "\tDefval";
	cout << "\trefWdbeMVectoritem";
	cout << "\tstubRefWdbeMVectoritem";
	cout << "\tComment";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->cmdNum;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->ixWdbeVPartype;
		cout << "\t" << rec->srefIxWdbeVPartype;
		cout << "\t" << rec->titIxWdbeVPartype;
		cout << "\t" << rec->refWdbeMVector;
		cout << "\t" << rec->stubRefWdbeMVector;
		cout << "\t" << rec->Length;
		cout << "\t" << rec->Defval;
		cout << "\t" << rec->refWdbeMVectoritem;
		cout << "\t" << rec->stubRefWdbeMVectoritem;
		cout << "\t" << rec->Comment;
		cout << endl;
	};
	return retval;
};

void QryWdbeCmdAInvpar::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBECMDAIPAMOD_CMDEQ) {
		call->abort = handleCallWdbeCmdAipaMod_cmdEq(dbswdbe, call->jref);
	} else if ((call->ixVCall == VecWdbeVCall::CALLWDBESTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWdbeStubChgFromSelf(dbswdbe);
	};
};

bool QryWdbeCmdAInvpar::handleCallWdbeCmdAipaMod_cmdEq(
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

bool QryWdbeCmdAInvpar::handleCallWdbeStubChgFromSelf(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleCallWdbeStubChgFromSelf --- INSERT
	return retval;
};



