/**
	* \file QryWdbeCvrList.cpp
	* job handler for job QryWdbeCvrList (implementation)
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

#include "QryWdbeCvrList.h"

#include "QryWdbeCvrList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWdbeCvrList
 ******************************************************************************/

QryWdbeCvrList::QryWdbeCvrList(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::QRYWDBECVRLIST, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWdbeVQrystate = VecWdbeVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswdbe);

	xchg->addClstn(VecWdbeVCall::CALLWDBECVRMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBESTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWdbeCvrList::~QryWdbeCvrList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWdbeCvrList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWdbeVCall::CALLWDBECVRUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWdbeVCall::CALLWDBECVRUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWdbeCvrList::rerun(
			DbsWdbe* dbswdbe
			, const bool call
		) {
	string sqlstr;

	vector<ubigint> cnts;
	uint cnt, cntsum;

	vector<ubigint> lims;
	vector<ubigint> ofss;

	bool preNoadm = xchg->getBoolvalPreset(VecWdbeVPreset::PREWDBENOADM, jref);
	ubigint preOwner = xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref);
	ubigint preJrefSess = xchg->getRefPreset(VecWdbeVPreset::PREWDBEJREFSESS, jref);
	uint preIxPre = xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXPRE, jref);
	uint preIxOrd = xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXORD, jref);
	ubigint preRefCpr = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCPR, jref);
	ubigint preGrp = xchg->getRefPreset(VecWdbeVPreset::PREWDBECVRLIST_GRP, jref);
	ubigint preOwn = xchg->getRefPreset(VecWdbeVPreset::PREWDBECVRLIST_OWN, jref);
	ubigint preCpr = xchg->getRefPreset(VecWdbeVPreset::PREWDBECVRLIST_CPR, jref);
	ubigint preBcv = xchg->getRefPreset(VecWdbeVPreset::PREWDBECVRLIST_BCV, jref);
	uint preSte = xchg->getIxPreset(VecWdbeVPreset::PREWDBECVRLIST_STE, jref);

	dbswdbe->tblwdbeqselect->removeRstByJref(jref);
	dbswdbe->tblwdbeqcvrlist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecWdbeVPreset::PREWDBEREFCPR) {
		sqlstr = "SELECT COUNT(TblWdbeMCoreversion.ref)";
		sqlstr += " FROM TblWdbeMCoreversion, TblWdbeQSelect";
		sqlstr += " WHERE TblWdbeQSelect.jref = " + to_string(preJrefSess) + "";
		sqlstr += " AND TblWdbeMCoreversion.grp = TblWdbeQSelect.ref";
		sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblWdbeMCoreversion.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
		sqlstr += " AND TblWdbeMCoreversion.refWdbeMCoreproject = " + to_string(preRefCpr) + "";
		rerun_filtSQL(sqlstr, preGrp, preOwn, preCpr, preBcv, preSte, false);
		dbswdbe->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblWdbeMCoreversion.ref)";
		sqlstr += " FROM TblWdbeMCoreversion, TblWdbeQSelect";
		sqlstr += " WHERE TblWdbeQSelect.jref = " + to_string(preJrefSess) + "";
		sqlstr += " AND TblWdbeMCoreversion.grp = TblWdbeQSelect.ref";
		sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblWdbeMCoreversion.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
		rerun_filtSQL(sqlstr, preGrp, preOwn, preCpr, preBcv, preSte, false);
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

	if (preIxPre == VecWdbeVPreset::PREWDBEREFCPR) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWdbeMCoreversion, TblWdbeQSelect";
		sqlstr += " WHERE TblWdbeQSelect.jref = " + to_string(preJrefSess) + "";
		sqlstr += " AND TblWdbeMCoreversion.grp = TblWdbeQSelect.ref";
		sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblWdbeMCoreversion.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
		sqlstr += " AND TblWdbeMCoreversion.refWdbeMCoreproject = " + to_string(preRefCpr) + "";
		rerun_filtSQL(sqlstr, preGrp, preOwn, preCpr, preBcv, preSte, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswdbe->executeQuery(sqlstr);

	} else {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWdbeMCoreversion, TblWdbeQSelect";
		sqlstr += " WHERE TblWdbeQSelect.jref = " + to_string(preJrefSess) + "";
		sqlstr += " AND TblWdbeMCoreversion.grp = TblWdbeQSelect.ref";
		sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblWdbeMCoreversion.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
		rerun_filtSQL(sqlstr, preGrp, preOwn, preCpr, preBcv, preSte, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswdbe->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblWdbeQCvrList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswdbe->executeQuery(sqlstr);

	ixWdbeVQrystate = VecWdbeVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswdbe);

	if (call) xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBESTATCHG, jref);

};

void QryWdbeCvrList::rerun_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblWdbeQCvrList(jref, jnum, ref, grp, own, refWdbeMCoreproject, Major, Minor, Sub, bcvRefWdbeMCoreversion, ixVState)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWdbeMCoreversion.ref, TblWdbeMCoreversion.grp, TblWdbeMCoreversion.own, TblWdbeMCoreversion.refWdbeMCoreproject, TblWdbeMCoreversion.Major, TblWdbeMCoreversion.Minor, TblWdbeMCoreversion.Sub, TblWdbeMCoreversion.bcvRefWdbeMCoreversion, TblWdbeMCoreversion.ixVState";
};

void QryWdbeCvrList::rerun_filtSQL(
			string& sqlstr
			, const ubigint preGrp
			, const ubigint preOwn
			, const ubigint preCpr
			, const ubigint preBcv
			, const uint preSte
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preGrp != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMCoreversion.grp = " + to_string(preGrp) + "";
	};

	if (preOwn != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMCoreversion.own = " + to_string(preOwn) + "";
	};

	if (preCpr != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMCoreversion.refWdbeMCoreproject = " + to_string(preCpr) + "";
	};

	if (preBcv != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMCoreversion.bcvRefWdbeMCoreversion = " + to_string(preBcv) + "";
	};

	if (preSte != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMCoreversion.ixVState = " + to_string(preSte) + "";
	};
};

void QryWdbeCvrList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWdbeCvrList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::BCV) sqlstr += " ORDER BY TblWdbeMCoreversion.bcvRefWdbeMCoreversion ASC";
	else if (preIxOrd == VecVOrd::STE) sqlstr += " ORDER BY TblWdbeMCoreversion.ixVState ASC";
	else if (preIxOrd == VecVOrd::CPR) sqlstr += " ORDER BY TblWdbeMCoreversion.refWdbeMCoreproject ASC";
	else if (preIxOrd == VecVOrd::OWN) sqlstr += " ORDER BY TblWdbeMCoreversion.own ASC";
	else if (preIxOrd == VecVOrd::GRP) sqlstr += " ORDER BY TblWdbeMCoreversion.grp ASC";
};

void QryWdbeCvrList::fetch(
			DbsWdbe* dbswdbe
		) {
	string sqlstr;

	StmgrWdbe* stmgr = NULL;
	Stcch* stcch = NULL;

	WdbeQCvrList* rec = NULL;

	dbswdbe->tblwdbeqcvrlist->loadRstByJref(jref, false, rst);
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
			rec->stubRefWdbeMCoreproject = StubWdbe::getStubCprStd(dbswdbe, rec->refWdbeMCoreproject, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubBcvRefWdbeMCoreversion = StubWdbe::getStubCvrStd(dbswdbe, rec->bcvRefWdbeMCoreversion, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxVState = VecWdbeVMCoreversionState::getSref(rec->ixVState);
			rec->titIxVState = VecWdbeVMCoreversionState::getTitle(rec->ixVState, ixWdbeVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWdbeCvrList", "fetch");
	};

	refreshJnum();
};

uint QryWdbeCvrList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WdbeQCvrList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWdbeCvrList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WdbeQCvrList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WdbeQCvrList* QryWdbeCvrList::getRecByJnum(
			const uint jnum
		) {
	WdbeQCvrList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWdbeCvrList::handleRequest(
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

bool QryWdbeCvrList::handleRerun(
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

bool QryWdbeCvrList::handleShow(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	WdbeQCvrList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tgrp";
	cout << "\tstubGrp";
	cout << "\town";
	cout << "\tstubOwn";
	cout << "\trefWdbeMCoreproject";
	cout << "\tstubRefWdbeMCoreproject";
	cout << "\tMajor";
	cout << "\tMinor";
	cout << "\tSub";
	cout << "\tbcvRefWdbeMCoreversion";
	cout << "\tstubBcvRefWdbeMCoreversion";
	cout << "\tixVState";
	cout << "\tsrefIxVState";
	cout << "\ttitIxVState";
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
		cout << "\t" << rec->refWdbeMCoreproject;
		cout << "\t" << rec->stubRefWdbeMCoreproject;
		cout << "\t" << rec->Major;
		cout << "\t" << rec->Minor;
		cout << "\t" << rec->Sub;
		cout << "\t" << rec->bcvRefWdbeMCoreversion;
		cout << "\t" << rec->stubBcvRefWdbeMCoreversion;
		cout << "\t" << rec->ixVState;
		cout << "\t" << rec->srefIxVState;
		cout << "\t" << rec->titIxVState;
		cout << endl;
	};
	return retval;
};

void QryWdbeCvrList::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBECVRUPD_REFEQ) {
		call->abort = handleCallWdbeCvrUpd_refEq(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBECVRMOD) {
		call->abort = handleCallWdbeCvrMod(dbswdbe, call->jref);
	} else if ((call->ixVCall == VecWdbeVCall::CALLWDBESTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWdbeStubChgFromSelf(dbswdbe);
	};
};

bool QryWdbeCvrList::handleCallWdbeCvrUpd_refEq(
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

bool QryWdbeCvrList::handleCallWdbeCvrMod(
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

bool QryWdbeCvrList::handleCallWdbeStubChgFromSelf(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleCallWdbeStubChgFromSelf --- INSERT
	return retval;
};
