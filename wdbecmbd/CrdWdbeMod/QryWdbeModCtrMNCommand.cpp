/**
	* \file QryWdbeModCtrMNCommand.cpp
	* job handler for job QryWdbeModCtrMNCommand (implementation)
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

#include "QryWdbeModCtrMNCommand.h"

#include "QryWdbeModCtrMNCommand_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWdbeModCtrMNCommand
 ******************************************************************************/

QryWdbeModCtrMNCommand::QryWdbeModCtrMNCommand(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::QRYWDBEMODCTRMNCOMMAND, jrefSup, ixWdbeVLocale)
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

QryWdbeModCtrMNCommand::~QryWdbeModCtrMNCommand() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWdbeModCtrMNCommand::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWdbeModCtrMNCommand::rerun(
			DbsWdbe* dbswdbe
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefCtr = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCTR, jref);

	xchg->removeClstns(VecWdbeVCall::CALLWDBECMDRCTRMOD_CTREQ, jref);

	dbswdbe->tblwdbeqselect->removeRstByJref(jref);
	dbswdbe->tblwdbeqmodctrmncommand->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWdbeRMCommandMController.ref)";
	sqlstr += " FROM TblWdbeMCommand, TblWdbeRMCommandMController";
	sqlstr += " WHERE TblWdbeRMCommandMController.refWdbeMCommand = TblWdbeMCommand.ref";
	sqlstr += " AND TblWdbeRMCommandMController.refWdbeMController = " + to_string(preRefCtr) + "";
	dbswdbe->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWdbeQModCtrMNCommand(jref, jnum, mref, ref, ivrRefWdbeMSignal, rvrRefWdbeMSignal)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWdbeMCommand.ref, TblWdbeRMCommandMController.ref, TblWdbeRMCommandMController.ivrRefWdbeMSignal, TblWdbeRMCommandMController.rvrRefWdbeMSignal";
	sqlstr += " FROM TblWdbeMCommand, TblWdbeRMCommandMController";
	sqlstr += " WHERE TblWdbeRMCommandMController.refWdbeMCommand = TblWdbeMCommand.ref";
	sqlstr += " AND TblWdbeRMCommandMController.refWdbeMController = " + to_string(preRefCtr) + "";
	sqlstr += " ORDER BY TblWdbeMCommand.sref ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswdbe->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWdbeQModCtrMNCommand SET jnum = qref WHERE jref = " + to_string(jref);
	dbswdbe->executeQuery(sqlstr);

	ixWdbeVQrystate = VecWdbeVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswdbe);

	if (call) xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBESTATCHG, jref);

	xchg->addRefClstn(VecWdbeVCall::CALLWDBECMDRCTRMOD_CTREQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefCtr);
};

void QryWdbeModCtrMNCommand::fetch(
			DbsWdbe* dbswdbe
		) {
	string sqlstr;

	StmgrWdbe* stmgr = NULL;
	Stcch* stcch = NULL;

	WdbeQModCtrMNCommand* rec = NULL;

	dbswdbe->tblwdbeqmodctrmncommand->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubMref = StubWdbe::getStubCmdStd(dbswdbe, rec->mref, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubIvrRefWdbeMSignal = StubWdbe::getStubSigStd(dbswdbe, rec->ivrRefWdbeMSignal, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRvrRefWdbeMSignal = StubWdbe::getStubSigStd(dbswdbe, rec->rvrRefWdbeMSignal, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWdbeModCtrMNCommand", "fetch");
	};

	refreshJnum();
};

uint QryWdbeModCtrMNCommand::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WdbeQModCtrMNCommand* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWdbeModCtrMNCommand::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WdbeQModCtrMNCommand* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WdbeQModCtrMNCommand* QryWdbeModCtrMNCommand::getRecByJnum(
			const uint jnum
		) {
	WdbeQModCtrMNCommand* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWdbeModCtrMNCommand::handleRequest(
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

bool QryWdbeModCtrMNCommand::handleRerun(
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

bool QryWdbeModCtrMNCommand::handleShow(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	WdbeQModCtrMNCommand* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tmref";
	cout << "\tstubMref";
	cout << "\tref";
	cout << "\tivrRefWdbeMSignal";
	cout << "\tstubIvrRefWdbeMSignal";
	cout << "\trvrRefWdbeMSignal";
	cout << "\tstubRvrRefWdbeMSignal";
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
		cout << "\t" << rec->ivrRefWdbeMSignal;
		cout << "\t" << rec->stubIvrRefWdbeMSignal;
		cout << "\t" << rec->rvrRefWdbeMSignal;
		cout << "\t" << rec->stubRvrRefWdbeMSignal;
		cout << endl;
	};
	return retval;
};

void QryWdbeModCtrMNCommand::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if ((call->ixVCall == VecWdbeVCall::CALLWDBESTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWdbeStubChgFromSelf(dbswdbe);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBECMDRCTRMOD_CTREQ) {
		call->abort = handleCallWdbeCmdRctrMod_ctrEq(dbswdbe, call->jref);
	};
};

bool QryWdbeModCtrMNCommand::handleCallWdbeStubChgFromSelf(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleCallWdbeStubChgFromSelf --- INSERT
	return retval;
};

bool QryWdbeModCtrMNCommand::handleCallWdbeCmdRctrMod_ctrEq(
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
