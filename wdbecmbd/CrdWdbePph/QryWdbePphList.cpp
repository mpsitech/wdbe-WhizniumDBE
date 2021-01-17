/**
	* \file QryWdbePphList.cpp
	* job handler for job QryWdbePphList (implementation)
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

#include "QryWdbePphList.h"

#include "QryWdbePphList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWdbePphList
 ******************************************************************************/

QryWdbePphList::QryWdbePphList(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::QRYWDBEPPHLIST, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWdbeVQrystate = VecWdbeVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswdbe);

	xchg->addClstn(VecWdbeVCall::CALLWDBESTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEPPHMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWdbePphList::~QryWdbePphList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWdbePphList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWdbeVCall::CALLWDBEPPHUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWdbeVCall::CALLWDBEPPHUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWdbePphList::rerun(
			DbsWdbe* dbswdbe
			, const bool call
		) {
	string sqlstr;

	vector<ubigint> cnts;
	uint cnt, cntsum;

	vector<ubigint> lims;
	vector<ubigint> ofss;

	uint preIxPre = xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXPRE, jref);
	uint preIxOrd = xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXORD, jref);
	ubigint preRefUnt = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref);
	string preSrf = xchg->getSrefPreset(VecWdbeVPreset::PREWDBEPPHLIST_SRF, jref);
	ubigint preUnt = xchg->getRefPreset(VecWdbeVPreset::PREWDBEPPHLIST_UNT, jref);
	ubigint preMdl = xchg->getRefPreset(VecWdbeVPreset::PREWDBEPPHLIST_MDL, jref);

	dbswdbe->tblwdbeqselect->removeRstByJref(jref);
	dbswdbe->tblwdbeqpphlist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecWdbeVPreset::PREWDBEREFUNT) {
		sqlstr = "SELECT COUNT(TblWdbeMPeripheral.ref)";
		sqlstr += " FROM TblWdbeMPeripheral";
		sqlstr += " WHERE TblWdbeMPeripheral.refWdbeMUnit = " + to_string(preRefUnt) + "";
		rerun_filtSQL(sqlstr, preSrf, preUnt, preMdl, false);
		dbswdbe->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblWdbeMPeripheral.ref)";
		sqlstr += " FROM TblWdbeMPeripheral";
		rerun_filtSQL(sqlstr, preSrf, preUnt, preMdl, true);
		dbswdbe->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;
	};

	statshr.ntot = 0;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cntsum) {
		if (cntsum >= stgiac.nload) stgiac.jnumFirstload = cntsum-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	for (unsigned int i = 0; i < cnts.size(); i++) {
		if (statshr.nload < stgiac.nload) {
			if ((statshr.ntot+cnts[i]) >= stgiac.jnumFirstload) {
				if (statshr.ntot >= stgiac.jnumFirstload) {
					ofss[i] = 0;
				} else {
					ofss[i] = stgiac.jnumFirstload-statshr.ntot-1;
				};

				if ((statshr.nload+cnts[i]-ofss[i]) > stgiac.nload) lims[i] = stgiac.nload-statshr.nload;
				else lims[i] = cnts[i]-ofss[i];
			};
		};

		statshr.ntot += cnts[i];
		statshr.nload += lims[i];
	};

	if (preIxPre == VecWdbeVPreset::PREWDBEREFUNT) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWdbeMPeripheral";
		sqlstr += " WHERE TblWdbeMPeripheral.refWdbeMUnit = " + to_string(preRefUnt) + "";
		rerun_filtSQL(sqlstr, preSrf, preUnt, preMdl, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswdbe->executeQuery(sqlstr);

	} else {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWdbeMPeripheral";
		rerun_filtSQL(sqlstr, preSrf, preUnt, preMdl, true);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswdbe->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblWdbeQPphList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswdbe->executeQuery(sqlstr);

	ixWdbeVQrystate = VecWdbeVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswdbe);

	if (call) xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBESTATCHG, jref);

};

void QryWdbePphList::rerun_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblWdbeQPphList(jref, jnum, ref, sref, refWdbeMUnit, refWdbeMModule)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWdbeMPeripheral.ref, TblWdbeMPeripheral.sref, TblWdbeMPeripheral.refWdbeMUnit, TblWdbeMPeripheral.refWdbeMModule";
};

void QryWdbePphList::rerun_filtSQL(
			string& sqlstr
			, const string& preSrf
			, const ubigint preUnt
			, const ubigint preMdl
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSrf.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMPeripheral.sref = '" + preSrf + "'";
	};

	if (preUnt != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMPeripheral.refWdbeMUnit = " + to_string(preUnt) + "";
	};

	if (preMdl != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMPeripheral.refWdbeMModule = " + to_string(preMdl) + "";
	};
};

void QryWdbePphList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWdbePphList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblWdbeMPeripheral.sref ASC";
	else if (preIxOrd == VecVOrd::UNT) sqlstr += " ORDER BY TblWdbeMPeripheral.refWdbeMUnit ASC";
	else if (preIxOrd == VecVOrd::MDL) sqlstr += " ORDER BY TblWdbeMPeripheral.refWdbeMModule ASC";
};

void QryWdbePphList::fetch(
			DbsWdbe* dbswdbe
		) {
	string sqlstr;

	StmgrWdbe* stmgr = NULL;
	Stcch* stcch = NULL;

	WdbeQPphList* rec = NULL;

	dbswdbe->tblwdbeqpphlist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRefWdbeMUnit = StubWdbe::getStubUntStd(dbswdbe, rec->refWdbeMUnit, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefWdbeMModule = StubWdbe::getStubMdlStd(dbswdbe, rec->refWdbeMModule, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWdbePphList", "fetch");
	};

	refreshJnum();
};

uint QryWdbePphList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WdbeQPphList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWdbePphList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WdbeQPphList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WdbeQPphList* QryWdbePphList::getRecByJnum(
			const uint jnum
		) {
	WdbeQPphList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWdbePphList::handleRequest(
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

bool QryWdbePphList::handleRerun(
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

bool QryWdbePphList::handleShow(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	WdbeQPphList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsref";
	cout << "\trefWdbeMUnit";
	cout << "\tstubRefWdbeMUnit";
	cout << "\trefWdbeMModule";
	cout << "\tstubRefWdbeMModule";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->refWdbeMUnit;
		cout << "\t" << rec->stubRefWdbeMUnit;
		cout << "\t" << rec->refWdbeMModule;
		cout << "\t" << rec->stubRefWdbeMModule;
		cout << endl;
	};
	return retval;
};

void QryWdbePphList::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if ((call->ixVCall == VecWdbeVCall::CALLWDBESTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWdbeStubChgFromSelf(dbswdbe);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEPPHMOD) {
		call->abort = handleCallWdbePphMod(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEPPHUPD_REFEQ) {
		call->abort = handleCallWdbePphUpd_refEq(dbswdbe, call->jref);
	};
};

bool QryWdbePphList::handleCallWdbeStubChgFromSelf(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleCallWdbeStubChgFromSelf --- INSERT
	return retval;
};

bool QryWdbePphList::handleCallWdbePphMod(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if ((ixWdbeVQrystate == VecWdbeVQrystate::UTD) || (ixWdbeVQrystate == VecWdbeVQrystate::SLM)) {
		ixWdbeVQrystate = VecWdbeVQrystate::MNR;
		xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBESTATCHG, jref);
	};

	return retval;
};

bool QryWdbePphList::handleCallWdbePphUpd_refEq(
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
