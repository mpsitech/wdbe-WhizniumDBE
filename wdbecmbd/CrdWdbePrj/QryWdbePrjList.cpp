/**
	* \file QryWdbePrjList.cpp
	* job handler for job QryWdbePrjList (implementation)
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

#include "QryWdbePrjList.h"

#include "QryWdbePrjList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWdbePrjList
 ******************************************************************************/

QryWdbePrjList::QryWdbePrjList(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::QRYWDBEPRJLIST, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWdbeVQrystate = VecWdbeVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswdbe);

	xchg->addClstn(VecWdbeVCall::CALLWDBEPRJMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBESTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWdbePrjList::~QryWdbePrjList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWdbePrjList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWdbeVCall::CALLWDBEPRJUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWdbeVCall::CALLWDBEPRJUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWdbePrjList::rerun(
			DbsWdbe* dbswdbe
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	bool preNoadm = xchg->getBoolvalPreset(VecWdbeVPreset::PREWDBENOADM, jref);
	ubigint preOwner = xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref);
	ubigint preJrefSess = xchg->getRefPreset(VecWdbeVPreset::PREWDBEJREFSESS, jref);
	uint preIxOrd = xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXORD, jref);
	ubigint preGrp = xchg->getRefPreset(VecWdbeVPreset::PREWDBEPRJLIST_GRP, jref);
	ubigint preOwn = xchg->getRefPreset(VecWdbeVPreset::PREWDBEPRJLIST_OWN, jref);
	string preSho = xchg->getTxtvalPreset(VecWdbeVPreset::PREWDBEPRJLIST_SHO, jref);
	string preTit = xchg->getTxtvalPreset(VecWdbeVPreset::PREWDBEPRJLIST_TIT, jref);
	ubigint preVer = xchg->getRefPreset(VecWdbeVPreset::PREWDBEPRJLIST_VER, jref);

	dbswdbe->tblwdbeqselect->removeRstByJref(jref);
	dbswdbe->tblwdbeqprjlist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWdbeMProject.ref)";
	sqlstr += " FROM TblWdbeMProject, TblWdbeQSelect";
	sqlstr += " WHERE TblWdbeQSelect.jref = " + to_string(preJrefSess) + "";
	sqlstr += " AND TblWdbeMProject.grp = TblWdbeQSelect.ref";
	sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblWdbeMProject.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
	rerun_filtSQL(sqlstr, preGrp, preOwn, preSho, preTit, preVer, false);
	dbswdbe->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWdbeQPrjList(jref, jnum, ref, grp, own, Short, Title, refWdbeMVersion, Easy, Giturl)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWdbeMProject.ref, TblWdbeMProject.grp, TblWdbeMProject.own, TblWdbeMProject.Short, TblWdbeMProject.Title, TblWdbeMProject.refWdbeMVersion, TblWdbeMProject.Easy, TblWdbeMProject.Giturl";
	sqlstr += " FROM TblWdbeMProject, TblWdbeQSelect";
	sqlstr += " WHERE TblWdbeQSelect.jref = " + to_string(preJrefSess) + "";
	sqlstr += " AND TblWdbeMProject.grp = TblWdbeQSelect.ref";
	sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblWdbeMProject.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
	rerun_filtSQL(sqlstr, preGrp, preOwn, preSho, preTit, preVer, false);
	rerun_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswdbe->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWdbeQPrjList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswdbe->executeQuery(sqlstr);

	ixWdbeVQrystate = VecWdbeVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswdbe);

	if (call) xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBESTATCHG, jref);

};

void QryWdbePrjList::rerun_filtSQL(
			string& sqlstr
			, const ubigint preGrp
			, const ubigint preOwn
			, const string& preSho
			, const string& preTit
			, const ubigint preVer
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preGrp != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMProject.grp = " + to_string(preGrp) + "";
	};

	if (preOwn != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMProject.own = " + to_string(preOwn) + "";
	};

	if (preSho.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMProject.Short LIKE '" + preSho + "'";
	};

	if (preTit.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMProject.Title LIKE '" + preTit + "'";
	};

	if (preVer != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMProject.refWdbeMVersion = " + to_string(preVer) + "";
	};
};

void QryWdbePrjList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWdbePrjList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::VER) sqlstr += " ORDER BY TblWdbeMProject.refWdbeMVersion ASC";
	else if (preIxOrd == VecVOrd::TIT) sqlstr += " ORDER BY TblWdbeMProject.Title ASC";
	else if (preIxOrd == VecVOrd::GRP) sqlstr += " ORDER BY TblWdbeMProject.grp ASC";
	else if (preIxOrd == VecVOrd::OWN) sqlstr += " ORDER BY TblWdbeMProject.own ASC";
	else if (preIxOrd == VecVOrd::SHO) sqlstr += " ORDER BY TblWdbeMProject.Short ASC";
};

void QryWdbePrjList::fetch(
			DbsWdbe* dbswdbe
		) {
	string sqlstr;

	StmgrWdbe* stmgr = NULL;
	Stcch* stcch = NULL;

	WdbeQPrjList* rec = NULL;

	dbswdbe->tblwdbeqprjlist->loadRstByJref(jref, false, rst);
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
			rec->stubRefWdbeMVersion = StubWdbe::getStubVerNo(dbswdbe, rec->refWdbeMVersion, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			if (rec->Easy) rec->yesnoEasy = VecWdbeVTag::getTitle(VecWdbeVTag::YES, ixWdbeVLocale); else rec->yesnoEasy = VecWdbeVTag::getTitle(VecWdbeVTag::NO, ixWdbeVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWdbePrjList", "fetch");
	};

	refreshJnum();
};

uint QryWdbePrjList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WdbeQPrjList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWdbePrjList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WdbeQPrjList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WdbeQPrjList* QryWdbePrjList::getRecByJnum(
			const uint jnum
		) {
	WdbeQPrjList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWdbePrjList::handleRequest(
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

bool QryWdbePrjList::handleRerun(
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

bool QryWdbePrjList::handleShow(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	WdbeQPrjList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tgrp";
	cout << "\tstubGrp";
	cout << "\town";
	cout << "\tstubOwn";
	cout << "\tShort";
	cout << "\tTitle";
	cout << "\trefWdbeMVersion";
	cout << "\tstubRefWdbeMVersion";
	cout << "\tEasy";
	cout << "\tyesnoEasy";
	cout << "\tGiturl";
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
		cout << "\t" << rec->Short;
		cout << "\t" << rec->Title;
		cout << "\t" << rec->refWdbeMVersion;
		cout << "\t" << rec->stubRefWdbeMVersion;
		cout << "\t" << rec->Easy;
		cout << "\t" << rec->yesnoEasy;
		cout << "\t" << rec->Giturl;
		cout << endl;
	};
	return retval;
};

void QryWdbePrjList::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBEPRJMOD) {
		call->abort = handleCallWdbePrjMod(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEPRJUPD_REFEQ) {
		call->abort = handleCallWdbePrjUpd_refEq(dbswdbe, call->jref);
	} else if ((call->ixVCall == VecWdbeVCall::CALLWDBESTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWdbeStubChgFromSelf(dbswdbe);
	};
};

bool QryWdbePrjList::handleCallWdbePrjMod(
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

bool QryWdbePrjList::handleCallWdbePrjUpd_refEq(
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

bool QryWdbePrjList::handleCallWdbeStubChgFromSelf(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleCallWdbeStubChgFromSelf --- INSERT
	return retval;
};
