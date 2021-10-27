/**
	* \file QryWdbeCmdMNController.cpp
	* job handler for job QryWdbeCmdMNController (implementation)
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

#include "QryWdbeCmdMNController.h"

#include "QryWdbeCmdMNController_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWdbeCmdMNController
 ******************************************************************************/

QryWdbeCmdMNController::QryWdbeCmdMNController(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::QRYWDBECMDMNCONTROLLER, jrefSup, ixWdbeVLocale)
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

QryWdbeCmdMNController::~QryWdbeCmdMNController() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWdbeCmdMNController::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWdbeCmdMNController::rerun(
			DbsWdbe* dbswdbe
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefCmd = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCMD, jref);

	xchg->removeClstns(VecWdbeVCall::CALLWDBECMDRCTRMOD_CMDEQ, jref);

	dbswdbe->tblwdbeqselect->removeRstByJref(jref);
	dbswdbe->tblwdbeqcmdmncontroller->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWdbeRMCommandMController.ref)";
	sqlstr += " FROM TblWdbeMController, TblWdbeRMCommandMController";
	sqlstr += " WHERE TblWdbeRMCommandMController.refWdbeMController = TblWdbeMController.ref";
	sqlstr += " AND TblWdbeRMCommandMController.refWdbeMCommand = " + to_string(preRefCmd) + "";
	dbswdbe->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWdbeQCmdMNController(jref, jnum, mref, ref, ivrRefWdbeMSignal, rvrRefWdbeMSignal)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWdbeMController.ref, TblWdbeRMCommandMController.ref, TblWdbeRMCommandMController.ivrRefWdbeMSignal, TblWdbeRMCommandMController.rvrRefWdbeMSignal";
	sqlstr += " FROM TblWdbeMController, TblWdbeRMCommandMController";
	sqlstr += " WHERE TblWdbeRMCommandMController.refWdbeMController = TblWdbeMController.ref";
	sqlstr += " AND TblWdbeRMCommandMController.refWdbeMCommand = " + to_string(preRefCmd) + "";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswdbe->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWdbeQCmdMNController SET jnum = qref WHERE jref = " + to_string(jref);
	dbswdbe->executeQuery(sqlstr);

	ixWdbeVQrystate = VecWdbeVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswdbe);

	if (call) xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBESTATCHG, jref);

	xchg->addRefClstn(VecWdbeVCall::CALLWDBECMDRCTRMOD_CMDEQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefCmd);
};

void QryWdbeCmdMNController::fetch(
			DbsWdbe* dbswdbe
		) {
	string sqlstr;

	StmgrWdbe* stmgr = NULL;
	Stcch* stcch = NULL;

	WdbeQCmdMNController* rec = NULL;

	dbswdbe->tblwdbeqcmdmncontroller->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubMref = StubWdbe::getStubCtrStd(dbswdbe, rec->mref, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubIvrRefWdbeMSignal = StubWdbe::getStubSigStd(dbswdbe, rec->ivrRefWdbeMSignal, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRvrRefWdbeMSignal = StubWdbe::getStubSigStd(dbswdbe, rec->rvrRefWdbeMSignal, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWdbeCmdMNController", "fetch");
	};

	refreshJnum();
};

uint QryWdbeCmdMNController::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WdbeQCmdMNController* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWdbeCmdMNController::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WdbeQCmdMNController* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WdbeQCmdMNController* QryWdbeCmdMNController::getRecByJnum(
			const uint jnum
		) {
	WdbeQCmdMNController* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWdbeCmdMNController::handleRequest(
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

bool QryWdbeCmdMNController::handleRerun(
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

bool QryWdbeCmdMNController::handleShow(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	WdbeQCmdMNController* rec = NULL;

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

void QryWdbeCmdMNController::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if ((call->ixVCall == VecWdbeVCall::CALLWDBESTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWdbeStubChgFromSelf(dbswdbe);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBECMDRCTRMOD_CMDEQ) {
		call->abort = handleCallWdbeCmdRctrMod_cmdEq(dbswdbe, call->jref);
	};
};

bool QryWdbeCmdMNController::handleCallWdbeStubChgFromSelf(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleCallWdbeStubChgFromSelf --- INSERT
	return retval;
};

bool QryWdbeCmdMNController::handleCallWdbeCmdRctrMod_cmdEq(
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
