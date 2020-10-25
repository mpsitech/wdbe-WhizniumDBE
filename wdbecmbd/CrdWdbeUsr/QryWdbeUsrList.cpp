/**
	* \file QryWdbeUsrList.cpp
	* job handler for job QryWdbeUsrList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbed.h>
#endif

#include "QryWdbeUsrList.h"

#include "QryWdbeUsrList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWdbeUsrList
 ******************************************************************************/

QryWdbeUsrList::QryWdbeUsrList(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::QRYWDBEUSRLIST, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWdbeVQrystate = VecWdbeVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswdbe);

	xchg->addClstn(VecWdbeVCall::CALLWDBESTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEUSRMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWdbeUsrList::~QryWdbeUsrList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWdbeUsrList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWdbeVCall::CALLWDBEUSRUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWdbeVCall::CALLWDBEUSRUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWdbeUsrList::rerun(
			DbsWdbe* dbswdbe
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	bool preNoadm = xchg->getBoolvalPreset(VecWdbeVPreset::PREWDBENOADM, jref);
	ubigint preOwner = xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref);
	ubigint preJrefSess = xchg->getRefPreset(VecWdbeVPreset::PREWDBEJREFSESS, jref);
	uint preIxOrd = xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXORD, jref);
	ubigint preGrp = xchg->getRefPreset(VecWdbeVPreset::PREWDBEUSRLIST_GRP, jref);
	ubigint preOwn = xchg->getRefPreset(VecWdbeVPreset::PREWDBEUSRLIST_OWN, jref);
	ubigint prePrs = xchg->getRefPreset(VecWdbeVPreset::PREWDBEUSRLIST_PRS, jref);
	string preSrf = xchg->getSrefPreset(VecWdbeVPreset::PREWDBEUSRLIST_SRF, jref);
	ubigint preUsg = xchg->getRefPreset(VecWdbeVPreset::PREWDBEUSRLIST_USG, jref);
	uint preSte = xchg->getIxPreset(VecWdbeVPreset::PREWDBEUSRLIST_STE, jref);

	dbswdbe->tblwdbeqselect->removeRstByJref(jref);
	dbswdbe->tblwdbequsrlist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWdbeMUser.ref)";
	sqlstr += " FROM TblWdbeMUser, TblWdbeQSelect";
	sqlstr += " WHERE TblWdbeQSelect.jref = " + to_string(preJrefSess) + "";
	sqlstr += " AND TblWdbeMUser.grp = TblWdbeQSelect.ref";
	sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblWdbeMUser.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
	rerun_filtSQL(sqlstr, preGrp, preOwn, prePrs, preSrf, preUsg, preSte, false);
	dbswdbe->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWdbeQUsrList(jref, jnum, ref, grp, own, refWdbeMPerson, sref, refWdbeMUsergroup, ixVState, ixWdbeVLocale, ixWdbeVUserlevel)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWdbeMUser.ref, TblWdbeMUser.grp, TblWdbeMUser.own, TblWdbeMUser.refWdbeMPerson, TblWdbeMUser.sref, TblWdbeMUser.refWdbeMUsergroup, TblWdbeMUser.ixVState, TblWdbeMUser.ixWdbeVLocale, TblWdbeMUser.ixWdbeVUserlevel";
	sqlstr += " FROM TblWdbeMUser, TblWdbeQSelect";
	sqlstr += " WHERE TblWdbeQSelect.jref = " + to_string(preJrefSess) + "";
	sqlstr += " AND TblWdbeMUser.grp = TblWdbeQSelect.ref";
	sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblWdbeMUser.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
	rerun_filtSQL(sqlstr, preGrp, preOwn, prePrs, preSrf, preUsg, preSte, false);
	rerun_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswdbe->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWdbeQUsrList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswdbe->executeQuery(sqlstr);

	ixWdbeVQrystate = VecWdbeVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswdbe);

	if (call) xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBESTATCHG, jref);

};

void QryWdbeUsrList::rerun_filtSQL(
			string& sqlstr
			, const ubigint preGrp
			, const ubigint preOwn
			, const ubigint prePrs
			, const string& preSrf
			, const ubigint preUsg
			, const uint preSte
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preGrp != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMUser.grp = " + to_string(preGrp) + "";
	};

	if (preOwn != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMUser.own = " + to_string(preOwn) + "";
	};

	if (prePrs != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMUser.refWdbeMPerson = " + to_string(prePrs) + "";
	};

	if (preSrf.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMUser.sref = '" + preSrf + "'";
	};

	if (preUsg != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMUser.refWdbeMUsergroup = " + to_string(preUsg) + "";
	};

	if (preSte != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMUser.ixVState = " + to_string(preSte) + "";
	};
};

void QryWdbeUsrList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWdbeUsrList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::GRP) sqlstr += " ORDER BY TblWdbeMUser.grp ASC";
	else if (preIxOrd == VecVOrd::OWN) sqlstr += " ORDER BY TblWdbeMUser.own ASC";
	else if (preIxOrd == VecVOrd::PRS) sqlstr += " ORDER BY TblWdbeMUser.refWdbeMPerson ASC";
	else if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblWdbeMUser.sref ASC";
	else if (preIxOrd == VecVOrd::USG) sqlstr += " ORDER BY TblWdbeMUser.refWdbeMUsergroup ASC";
	else if (preIxOrd == VecVOrd::STE) sqlstr += " ORDER BY TblWdbeMUser.ixVState ASC";
};

void QryWdbeUsrList::fetch(
			DbsWdbe* dbswdbe
		) {
	string sqlstr;

	StmgrWdbe* stmgr = NULL;
	Stcch* stcch = NULL;

	WdbeQUsrList* rec = NULL;

	dbswdbe->tblwdbequsrlist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubGrp = StubWdbe::getStubGroup(dbswdbe, rec->grp, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubOwn = StubWdbe::getStubOwner(dbswdbe, rec->own, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefWdbeMPerson = StubWdbe::getStubPrsStd(dbswdbe, rec->refWdbeMPerson, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefWdbeMUsergroup = StubWdbe::getStubUsgStd(dbswdbe, rec->refWdbeMUsergroup, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxVState = VecWdbeVMUserState::getSref(rec->ixVState);
			rec->titIxVState = VecWdbeVMUserState::getTitle(rec->ixVState, ixWdbeVLocale);
			rec->srefIxWdbeVLocale = VecWdbeVLocale::getSref(rec->ixWdbeVLocale);
			rec->titIxWdbeVLocale = VecWdbeVLocale::getTitle(rec->ixWdbeVLocale, ixWdbeVLocale);
			rec->srefIxWdbeVUserlevel = VecWdbeVUserlevel::getSref(rec->ixWdbeVUserlevel);
			rec->titIxWdbeVUserlevel = VecWdbeVUserlevel::getTitle(rec->ixWdbeVUserlevel, ixWdbeVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWdbeUsrList", "fetch");
	};

	refreshJnum();
};

uint QryWdbeUsrList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WdbeQUsrList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWdbeUsrList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WdbeQUsrList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WdbeQUsrList* QryWdbeUsrList::getRecByJnum(
			const uint jnum
		) {
	WdbeQUsrList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWdbeUsrList::handleRequest(
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

bool QryWdbeUsrList::handleRerun(
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

bool QryWdbeUsrList::handleShow(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	WdbeQUsrList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tgrp";
	cout << "\tstubGrp";
	cout << "\town";
	cout << "\tstubOwn";
	cout << "\trefWdbeMPerson";
	cout << "\tstubRefWdbeMPerson";
	cout << "\tsref";
	cout << "\trefWdbeMUsergroup";
	cout << "\tstubRefWdbeMUsergroup";
	cout << "\tixVState";
	cout << "\tsrefIxVState";
	cout << "\ttitIxVState";
	cout << "\tixWdbeVLocale";
	cout << "\tsrefIxWdbeVLocale";
	cout << "\ttitIxWdbeVLocale";
	cout << "\tixWdbeVUserlevel";
	cout << "\tsrefIxWdbeVUserlevel";
	cout << "\ttitIxWdbeVUserlevel";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->grp;
		cout << "\t" << rec->stubGrp;
		cout << "\t" << rec->own;
		cout << "\t" << rec->stubOwn;
		cout << "\t" << rec->refWdbeMPerson;
		cout << "\t" << rec->stubRefWdbeMPerson;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->refWdbeMUsergroup;
		cout << "\t" << rec->stubRefWdbeMUsergroup;
		cout << "\t" << rec->ixVState;
		cout << "\t" << rec->srefIxVState;
		cout << "\t" << rec->titIxVState;
		cout << "\t" << rec->ixWdbeVLocale;
		cout << "\t" << rec->srefIxWdbeVLocale;
		cout << "\t" << rec->titIxWdbeVLocale;
		cout << "\t" << rec->ixWdbeVUserlevel;
		cout << "\t" << rec->srefIxWdbeVUserlevel;
		cout << "\t" << rec->titIxWdbeVUserlevel;
		cout << endl;
	};
	return retval;
};

void QryWdbeUsrList::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if ((call->ixVCall == VecWdbeVCall::CALLWDBESTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWdbeStubChgFromSelf(dbswdbe);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEUSRMOD) {
		call->abort = handleCallWdbeUsrMod(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEUSRUPD_REFEQ) {
		call->abort = handleCallWdbeUsrUpd_refEq(dbswdbe, call->jref);
	};
};

bool QryWdbeUsrList::handleCallWdbeStubChgFromSelf(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleCallWdbeStubChgFromSelf --- INSERT
	return retval;
};

bool QryWdbeUsrList::handleCallWdbeUsrMod(
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

bool QryWdbeUsrList::handleCallWdbeUsrUpd_refEq(
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

