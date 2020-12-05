/**
	* \file QryWdbeTrgList.cpp
	* job handler for job QryWdbeTrgList (implementation)
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

#include "QryWdbeTrgList.h"

#include "QryWdbeTrgList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWdbeTrgList
 ******************************************************************************/

QryWdbeTrgList::QryWdbeTrgList(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::QRYWDBETRGLIST, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWdbeVQrystate = VecWdbeVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswdbe);

	xchg->addClstn(VecWdbeVCall::CALLWDBETRGMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBESTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWdbeTrgList::~QryWdbeTrgList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWdbeTrgList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWdbeVCall::CALLWDBETRGUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWdbeVCall::CALLWDBETRGUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWdbeTrgList::rerun(
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
	ubigint preRefVer = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref);
	string preSrf = xchg->getSrefPreset(VecWdbeVPreset::PREWDBETRGLIST_SRF, jref);
	ubigint preSys = xchg->getRefPreset(VecWdbeVPreset::PREWDBETRGLIST_SYS, jref);
	ubigint preUnt = xchg->getRefPreset(VecWdbeVPreset::PREWDBETRGLIST_UNT, jref);

	dbswdbe->tblwdbeqselect->removeRstByJref(jref);
	dbswdbe->tblwdbeqtrglist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecWdbeVPreset::PREWDBEREFVER) {
		sqlstr = "SELECT COUNT(TblWdbeMTarget.ref)";
		sqlstr += " FROM TblWdbeMTarget, TblWdbeMSystem";
		sqlstr += " WHERE TblWdbeMTarget.sysRefWdbeMSystem = TblWdbeMSystem.ref";
		sqlstr += " AND TblWdbeMSystem.refWdbeMVersion = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preSrf, preSys, preUnt, false);
		dbswdbe->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblWdbeMTarget.ref)";
		sqlstr += " FROM TblWdbeMTarget";
		rerun_filtSQL(sqlstr, preSrf, preSys, preUnt, true);
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

	if (preIxPre == VecWdbeVPreset::PREWDBEREFVER) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWdbeMTarget, TblWdbeMSystem";
		sqlstr += " WHERE TblWdbeMTarget.sysRefWdbeMSystem = TblWdbeMSystem.ref";
		sqlstr += " AND TblWdbeMSystem.refWdbeMVersion = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preSrf, preSys, preUnt, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswdbe->executeQuery(sqlstr);

	} else {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWdbeMTarget";
		rerun_filtSQL(sqlstr, preSrf, preSys, preUnt, true);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswdbe->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblWdbeQTrgList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswdbe->executeQuery(sqlstr);

	ixWdbeVQrystate = VecWdbeVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswdbe);

	if (call) xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBESTATCHG, jref);

};

void QryWdbeTrgList::rerun_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblWdbeQTrgList(jref, jnum, ref, sref, sysRefWdbeMSystem, refWdbeMUnit)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWdbeMTarget.ref, TblWdbeMTarget.sref, TblWdbeMTarget.sysRefWdbeMSystem, TblWdbeMTarget.refWdbeMUnit";
};

void QryWdbeTrgList::rerun_filtSQL(
			string& sqlstr
			, const string& preSrf
			, const ubigint preSys
			, const ubigint preUnt
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSrf.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMTarget.sref = '" + preSrf + "'";
	};

	if (preSys != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMTarget.sysRefWdbeMSystem = " + to_string(preSys) + "";
	};

	if (preUnt != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMTarget.refWdbeMUnit = " + to_string(preUnt) + "";
	};
};

void QryWdbeTrgList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWdbeTrgList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::UNT) sqlstr += " ORDER BY TblWdbeMTarget.refWdbeMUnit ASC";
	else if (preIxOrd == VecVOrd::SYS) sqlstr += " ORDER BY TblWdbeMTarget.sysRefWdbeMSystem ASC";
	else if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblWdbeMTarget.sref ASC";
};

void QryWdbeTrgList::fetch(
			DbsWdbe* dbswdbe
		) {
	string sqlstr;

	StmgrWdbe* stmgr = NULL;
	Stcch* stcch = NULL;

	WdbeQTrgList* rec = NULL;

	dbswdbe->tblwdbeqtrglist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubSysRefWdbeMSystem = StubWdbe::getStubSysStd(dbswdbe, rec->sysRefWdbeMSystem, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefWdbeMUnit = StubWdbe::getStubUntStd(dbswdbe, rec->refWdbeMUnit, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWdbeTrgList", "fetch");
	};

	refreshJnum();
};

uint QryWdbeTrgList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WdbeQTrgList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWdbeTrgList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WdbeQTrgList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WdbeQTrgList* QryWdbeTrgList::getRecByJnum(
			const uint jnum
		) {
	WdbeQTrgList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWdbeTrgList::handleRequest(
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

bool QryWdbeTrgList::handleRerun(
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

bool QryWdbeTrgList::handleShow(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	WdbeQTrgList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsref";
	cout << "\tsysRefWdbeMSystem";
	cout << "\tstubSysRefWdbeMSystem";
	cout << "\trefWdbeMUnit";
	cout << "\tstubRefWdbeMUnit";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->sysRefWdbeMSystem;
		cout << "\t" << rec->stubSysRefWdbeMSystem;
		cout << "\t" << rec->refWdbeMUnit;
		cout << "\t" << rec->stubRefWdbeMUnit;
		cout << endl;
	};
	return retval;
};

void QryWdbeTrgList::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBETRGUPD_REFEQ) {
		call->abort = handleCallWdbeTrgUpd_refEq(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBETRGMOD) {
		call->abort = handleCallWdbeTrgMod(dbswdbe, call->jref);
	} else if ((call->ixVCall == VecWdbeVCall::CALLWDBESTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWdbeStubChgFromSelf(dbswdbe);
	};
};

bool QryWdbeTrgList::handleCallWdbeTrgUpd_refEq(
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

bool QryWdbeTrgList::handleCallWdbeTrgMod(
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

bool QryWdbeTrgList::handleCallWdbeStubChgFromSelf(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleCallWdbeStubChgFromSelf --- INSERT
	return retval;
};



