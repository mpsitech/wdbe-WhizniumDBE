/**
	* \file QryWdbeVerList.cpp
	* job handler for job QryWdbeVerList (implementation)
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

#include "QryWdbeVerList.h"

#include "QryWdbeVerList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWdbeVerList
 ******************************************************************************/

QryWdbeVerList::QryWdbeVerList(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::QRYWDBEVERLIST, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWdbeVQrystate = VecWdbeVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswdbe);

	xchg->addClstn(VecWdbeVCall::CALLWDBESTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEVERMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWdbeVerList::~QryWdbeVerList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWdbeVerList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWdbeVCall::CALLWDBEVERUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWdbeVCall::CALLWDBEVERUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWdbeVerList::rerun(
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
	ubigint preRefPrj = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFPRJ, jref);
	ubigint preGrp = xchg->getRefPreset(VecWdbeVPreset::PREWDBEVERLIST_GRP, jref);
	ubigint preOwn = xchg->getRefPreset(VecWdbeVPreset::PREWDBEVERLIST_OWN, jref);
	ubigint prePrj = xchg->getRefPreset(VecWdbeVPreset::PREWDBEVERLIST_PRJ, jref);
	ubigint preBvr = xchg->getRefPreset(VecWdbeVPreset::PREWDBEVERLIST_BVR, jref);
	uint preSte = xchg->getIxPreset(VecWdbeVPreset::PREWDBEVERLIST_STE, jref);

	dbswdbe->tblwdbeqselect->removeRstByJref(jref);
	dbswdbe->tblwdbeqverlist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecWdbeVPreset::PREWDBEREFPRJ) {
		sqlstr = "SELECT COUNT(TblWdbeMVersion.ref)";
		sqlstr += " FROM TblWdbeMVersion, TblWdbeQSelect";
		sqlstr += " WHERE TblWdbeQSelect.jref = " + to_string(preJrefSess) + "";
		sqlstr += " AND TblWdbeMVersion.grp = TblWdbeQSelect.ref";
		sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblWdbeMVersion.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
		sqlstr += " AND TblWdbeMVersion.prjRefWdbeMProject = " + to_string(preRefPrj) + "";
		rerun_filtSQL(sqlstr, preGrp, preOwn, prePrj, preBvr, preSte, false);
		dbswdbe->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblWdbeMVersion.ref)";
		sqlstr += " FROM TblWdbeMVersion, TblWdbeQSelect";
		sqlstr += " WHERE TblWdbeQSelect.jref = " + to_string(preJrefSess) + "";
		sqlstr += " AND TblWdbeMVersion.grp = TblWdbeQSelect.ref";
		sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblWdbeMVersion.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
		rerun_filtSQL(sqlstr, preGrp, preOwn, prePrj, preBvr, preSte, false);
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

	if (preIxPre == VecWdbeVPreset::PREWDBEREFPRJ) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWdbeMVersion, TblWdbeQSelect";
		sqlstr += " WHERE TblWdbeQSelect.jref = " + to_string(preJrefSess) + "";
		sqlstr += " AND TblWdbeMVersion.grp = TblWdbeQSelect.ref";
		sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblWdbeMVersion.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
		sqlstr += " AND TblWdbeMVersion.prjRefWdbeMProject = " + to_string(preRefPrj) + "";
		rerun_filtSQL(sqlstr, preGrp, preOwn, prePrj, preBvr, preSte, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswdbe->executeQuery(sqlstr);

	} else {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWdbeMVersion, TblWdbeQSelect";
		sqlstr += " WHERE TblWdbeQSelect.jref = " + to_string(preJrefSess) + "";
		sqlstr += " AND TblWdbeMVersion.grp = TblWdbeQSelect.ref";
		sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblWdbeMVersion.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
		rerun_filtSQL(sqlstr, preGrp, preOwn, prePrj, preBvr, preSte, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswdbe->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblWdbeQVerList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswdbe->executeQuery(sqlstr);

	ixWdbeVQrystate = VecWdbeVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswdbe);

	if (call) xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBESTATCHG, jref);

};

void QryWdbeVerList::rerun_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblWdbeQVerList(jref, jnum, ref, grp, own, prjRefWdbeMProject, Major, Minor, Sub, bvrRefWdbeMVersion, ixVState)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWdbeMVersion.ref, TblWdbeMVersion.grp, TblWdbeMVersion.own, TblWdbeMVersion.prjRefWdbeMProject, TblWdbeMVersion.Major, TblWdbeMVersion.Minor, TblWdbeMVersion.Sub, TblWdbeMVersion.bvrRefWdbeMVersion, TblWdbeMVersion.ixVState";
};

void QryWdbeVerList::rerun_filtSQL(
			string& sqlstr
			, const ubigint preGrp
			, const ubigint preOwn
			, const ubigint prePrj
			, const ubigint preBvr
			, const uint preSte
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preGrp != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMVersion.grp = " + to_string(preGrp) + "";
	};

	if (preOwn != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMVersion.own = " + to_string(preOwn) + "";
	};

	if (prePrj != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMVersion.prjRefWdbeMProject = " + to_string(prePrj) + "";
	};

	if (preBvr != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMVersion.bvrRefWdbeMVersion = " + to_string(preBvr) + "";
	};

	if (preSte != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMVersion.ixVState = " + to_string(preSte) + "";
	};
};

void QryWdbeVerList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWdbeVerList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::GRP) sqlstr += " ORDER BY TblWdbeMVersion.grp ASC";
	else if (preIxOrd == VecVOrd::OWN) sqlstr += " ORDER BY TblWdbeMVersion.own ASC";
	else if (preIxOrd == VecVOrd::PRJ) sqlstr += " ORDER BY TblWdbeMVersion.prjRefWdbeMProject ASC";
	else if (preIxOrd == VecVOrd::BVR) sqlstr += " ORDER BY TblWdbeMVersion.bvrRefWdbeMVersion ASC";
	else if (preIxOrd == VecVOrd::STE) sqlstr += " ORDER BY TblWdbeMVersion.ixVState ASC";
};

void QryWdbeVerList::fetch(
			DbsWdbe* dbswdbe
		) {
	string sqlstr;

	StmgrWdbe* stmgr = NULL;
	Stcch* stcch = NULL;

	WdbeQVerList* rec = NULL;

	dbswdbe->tblwdbeqverlist->loadRstByJref(jref, false, rst);
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
			rec->stubPrjRefWdbeMProject = StubWdbe::getStubPrjStd(dbswdbe, rec->prjRefWdbeMProject, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubBvrRefWdbeMVersion = StubWdbe::getStubVerNo(dbswdbe, rec->bvrRefWdbeMVersion, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxVState = VecWdbeVMVersionState::getSref(rec->ixVState);
			rec->titIxVState = VecWdbeVMVersionState::getTitle(rec->ixVState, ixWdbeVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWdbeVerList", "fetch");
	};

	refreshJnum();
};

uint QryWdbeVerList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WdbeQVerList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWdbeVerList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WdbeQVerList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WdbeQVerList* QryWdbeVerList::getRecByJnum(
			const uint jnum
		) {
	WdbeQVerList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWdbeVerList::handleRequest(
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

bool QryWdbeVerList::handleRerun(
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

bool QryWdbeVerList::handleShow(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	WdbeQVerList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tgrp";
	cout << "\tstubGrp";
	cout << "\town";
	cout << "\tstubOwn";
	cout << "\tprjRefWdbeMProject";
	cout << "\tstubPrjRefWdbeMProject";
	cout << "\tMajor";
	cout << "\tMinor";
	cout << "\tSub";
	cout << "\tbvrRefWdbeMVersion";
	cout << "\tstubBvrRefWdbeMVersion";
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
		cout << "\t" << rec->prjRefWdbeMProject;
		cout << "\t" << rec->stubPrjRefWdbeMProject;
		cout << "\t" << rec->Major;
		cout << "\t" << rec->Minor;
		cout << "\t" << rec->Sub;
		cout << "\t" << rec->bvrRefWdbeMVersion;
		cout << "\t" << rec->stubBvrRefWdbeMVersion;
		cout << "\t" << rec->ixVState;
		cout << "\t" << rec->srefIxVState;
		cout << "\t" << rec->titIxVState;
		cout << endl;
	};
	return retval;
};

void QryWdbeVerList::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if ((call->ixVCall == VecWdbeVCall::CALLWDBESTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWdbeStubChgFromSelf(dbswdbe);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEVERMOD) {
		call->abort = handleCallWdbeVerMod(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEVERUPD_REFEQ) {
		call->abort = handleCallWdbeVerUpd_refEq(dbswdbe, call->jref);
	};
};

bool QryWdbeVerList::handleCallWdbeStubChgFromSelf(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleCallWdbeStubChgFromSelf --- INSERT
	return retval;
};

bool QryWdbeVerList::handleCallWdbeVerMod(
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

bool QryWdbeVerList::handleCallWdbeVerUpd_refEq(
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
