/**
	* \file QryWdbeCprList.cpp
	* job handler for job QryWdbeCprList (implementation)
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

#include "QryWdbeCprList.h"

#include "QryWdbeCprList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWdbeCprList
 ******************************************************************************/

QryWdbeCprList::QryWdbeCprList(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::QRYWDBECPRLIST, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWdbeVQrystate = VecWdbeVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswdbe);

	xchg->addClstn(VecWdbeVCall::CALLWDBECPRMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBESTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWdbeCprList::~QryWdbeCprList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWdbeCprList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWdbeVCall::CALLWDBECPRUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWdbeVCall::CALLWDBECPRUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWdbeCprList::rerun(
			DbsWdbe* dbswdbe
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	bool preNoadm = xchg->getBoolvalPreset(VecWdbeVPreset::PREWDBENOADM, jref);
	ubigint preOwner = xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref);
	ubigint preJrefSess = xchg->getRefPreset(VecWdbeVPreset::PREWDBEJREFSESS, jref);
	uint preIxOrd = xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXORD, jref);
	ubigint preGrp = xchg->getRefPreset(VecWdbeVPreset::PREWDBECPRLIST_GRP, jref);
	ubigint preOwn = xchg->getRefPreset(VecWdbeVPreset::PREWDBECPRLIST_OWN, jref);
	string preSrf = xchg->getSrefPreset(VecWdbeVPreset::PREWDBECPRLIST_SRF, jref);
	string preTit = xchg->getTxtvalPreset(VecWdbeVPreset::PREWDBECPRLIST_TIT, jref);
	uint preTyp = xchg->getIxPreset(VecWdbeVPreset::PREWDBECPRLIST_TYP, jref);
	ubigint preCvr = xchg->getRefPreset(VecWdbeVPreset::PREWDBECPRLIST_CVR, jref);

	dbswdbe->tblwdbeqselect->removeRstByJref(jref);
	dbswdbe->tblwdbeqcprlist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWdbeMCoreproject.ref)";
	sqlstr += " FROM TblWdbeMCoreproject, TblWdbeQSelect";
	sqlstr += " WHERE TblWdbeQSelect.jref = " + to_string(preJrefSess) + "";
	sqlstr += " AND TblWdbeMCoreproject.grp = TblWdbeQSelect.ref";
	sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblWdbeMCoreproject.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
	rerun_filtSQL(sqlstr, preGrp, preOwn, preSrf, preTit, preTyp, preCvr, false);
	dbswdbe->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWdbeQCprList(jref, jnum, ref, grp, own, sref, Title, ixVBasetype, refWdbeMCoreversion, Giturl)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWdbeMCoreproject.ref, TblWdbeMCoreproject.grp, TblWdbeMCoreproject.own, TblWdbeMCoreproject.sref, TblWdbeMCoreproject.Title, TblWdbeMCoreproject.ixVBasetype, TblWdbeMCoreproject.refWdbeMCoreversion, TblWdbeMCoreproject.Giturl";
	sqlstr += " FROM TblWdbeMCoreproject, TblWdbeQSelect";
	sqlstr += " WHERE TblWdbeQSelect.jref = " + to_string(preJrefSess) + "";
	sqlstr += " AND TblWdbeMCoreproject.grp = TblWdbeQSelect.ref";
	sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblWdbeMCoreproject.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
	rerun_filtSQL(sqlstr, preGrp, preOwn, preSrf, preTit, preTyp, preCvr, false);
	rerun_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswdbe->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWdbeQCprList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswdbe->executeQuery(sqlstr);

	ixWdbeVQrystate = VecWdbeVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswdbe);

	if (call) xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBESTATCHG, jref);

};

void QryWdbeCprList::rerun_filtSQL(
			string& sqlstr
			, const ubigint preGrp
			, const ubigint preOwn
			, const string& preSrf
			, const string& preTit
			, const uint preTyp
			, const ubigint preCvr
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preGrp != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMCoreproject.grp = " + to_string(preGrp) + "";
	};

	if (preOwn != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMCoreproject.own = " + to_string(preOwn) + "";
	};

	if (preSrf.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMCoreproject.sref = '" + preSrf + "'";
	};

	if (preTit.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMCoreproject.Title LIKE '" + preTit + "'";
	};

	if (preTyp != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMCoreproject.ixVBasetype = " + to_string(preTyp) + "";
	};

	if (preCvr != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMCoreproject.refWdbeMCoreversion = " + to_string(preCvr) + "";
	};
};

void QryWdbeCprList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWdbeCprList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::CVR) sqlstr += " ORDER BY TblWdbeMCoreproject.refWdbeMCoreversion ASC";
	else if (preIxOrd == VecVOrd::TYP) sqlstr += " ORDER BY TblWdbeMCoreproject.ixVBasetype ASC";
	else if (preIxOrd == VecVOrd::TIT) sqlstr += " ORDER BY TblWdbeMCoreproject.Title ASC";
	else if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblWdbeMCoreproject.sref ASC";
	else if (preIxOrd == VecVOrd::OWN) sqlstr += " ORDER BY TblWdbeMCoreproject.own ASC";
	else if (preIxOrd == VecVOrd::GRP) sqlstr += " ORDER BY TblWdbeMCoreproject.grp ASC";
};

void QryWdbeCprList::fetch(
			DbsWdbe* dbswdbe
		) {
	string sqlstr;

	StmgrWdbe* stmgr = NULL;
	Stcch* stcch = NULL;

	WdbeQCprList* rec = NULL;

	dbswdbe->tblwdbeqcprlist->loadRstByJref(jref, false, rst);
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
			rec->srefIxVBasetype = VecWdbeVMCoreprojectBasetype::getSref(rec->ixVBasetype);
			rec->titIxVBasetype = VecWdbeVMCoreprojectBasetype::getTitle(rec->ixVBasetype, ixWdbeVLocale);
			rec->stubRefWdbeMCoreversion = StubWdbe::getStubCvrStd(dbswdbe, rec->refWdbeMCoreversion, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWdbeCprList", "fetch");
	};

	refreshJnum();
};

uint QryWdbeCprList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WdbeQCprList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWdbeCprList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WdbeQCprList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WdbeQCprList* QryWdbeCprList::getRecByJnum(
			const uint jnum
		) {
	WdbeQCprList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWdbeCprList::handleRequest(
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

bool QryWdbeCprList::handleRerun(
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

bool QryWdbeCprList::handleShow(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	WdbeQCprList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tgrp";
	cout << "\tstubGrp";
	cout << "\town";
	cout << "\tstubOwn";
	cout << "\tsref";
	cout << "\tTitle";
	cout << "\tixVBasetype";
	cout << "\tsrefIxVBasetype";
	cout << "\ttitIxVBasetype";
	cout << "\trefWdbeMCoreversion";
	cout << "\tstubRefWdbeMCoreversion";
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
		cout << "\t" << rec->sref;
		cout << "\t" << rec->Title;
		cout << "\t" << rec->ixVBasetype;
		cout << "\t" << rec->srefIxVBasetype;
		cout << "\t" << rec->titIxVBasetype;
		cout << "\t" << rec->refWdbeMCoreversion;
		cout << "\t" << rec->stubRefWdbeMCoreversion;
		cout << "\t" << rec->Giturl;
		cout << endl;
	};
	return retval;
};

void QryWdbeCprList::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBECPRUPD_REFEQ) {
		call->abort = handleCallWdbeCprUpd_refEq(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBECPRMOD) {
		call->abort = handleCallWdbeCprMod(dbswdbe, call->jref);
	} else if ((call->ixVCall == VecWdbeVCall::CALLWDBESTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWdbeStubChgFromSelf(dbswdbe);
	};
};

bool QryWdbeCprList::handleCallWdbeCprUpd_refEq(
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

bool QryWdbeCprList::handleCallWdbeCprMod(
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

bool QryWdbeCprList::handleCallWdbeStubChgFromSelf(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleCallWdbeStubChgFromSelf --- INSERT
	return retval;
};



