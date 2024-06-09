/**
	* \file QryWdbeSegList.cpp
	* job handler for job QryWdbeSegList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbed.h>
#endif

#include "QryWdbeSegList.h"

#include "QryWdbeSegList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWdbeSegList
 ******************************************************************************/

QryWdbeSegList::QryWdbeSegList(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::QRYWDBESEGLIST, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWdbeVQrystate = VecWdbeVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswdbe);

	xchg->addClstn(VecWdbeVCall::CALLWDBESEGMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBESTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWdbeSegList::~QryWdbeSegList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWdbeSegList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWdbeVCall::CALLWDBESEGUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWdbeVCall::CALLWDBESEGUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWdbeSegList::rerun(
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
	ubigint preRefPpl = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFPPL, jref);
	string preSrf = xchg->getSrefPreset(VecWdbeVPreset::PREWDBESEGLIST_SRF, jref);
	ubigint prePpl = xchg->getRefPreset(VecWdbeVPreset::PREWDBESEGLIST_PPL, jref);
	ubigint preSup = xchg->getRefPreset(VecWdbeVPreset::PREWDBESEGLIST_SUP, jref);

	dbswdbe->tblwdbeqselect->removeRstByJref(jref);
	dbswdbe->tblwdbeqseglist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecWdbeVPreset::PREWDBEREFPPL) {
		sqlstr = "SELECT COUNT(TblWdbeMSegment.ref)";
		sqlstr += " FROM TblWdbeMSegment";
		sqlstr += " WHERE TblWdbeMSegment.pplRefWdbeMPipeline = " + to_string(preRefPpl) + "";
		rerun_filtSQL(sqlstr, preSrf, prePpl, preSup, false);
		dbswdbe->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblWdbeMSegment.ref)";
		sqlstr += " FROM TblWdbeMSegment";
		rerun_filtSQL(sqlstr, preSrf, prePpl, preSup, true);
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

	if (preIxPre == VecWdbeVPreset::PREWDBEREFPPL) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWdbeMSegment";
		sqlstr += " WHERE TblWdbeMSegment.pplRefWdbeMPipeline = " + to_string(preRefPpl) + "";
		rerun_filtSQL(sqlstr, preSrf, prePpl, preSup, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswdbe->executeQuery(sqlstr);

	} else {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWdbeMSegment";
		rerun_filtSQL(sqlstr, preSrf, prePpl, preSup, true);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswdbe->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblWdbeQSegList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswdbe->executeQuery(sqlstr);

	ixWdbeVQrystate = VecWdbeVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswdbe);

	if (call) xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBESTATCHG, jref);

};

void QryWdbeSegList::rerun_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblWdbeQSegList(jref, jnum, ref, sref, pplRefWdbeMPipeline, supRefWdbeMSegment, Infmt, Outfmt, Latency)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWdbeMSegment.ref, TblWdbeMSegment.sref, TblWdbeMSegment.pplRefWdbeMPipeline, TblWdbeMSegment.supRefWdbeMSegment, TblWdbeMSegment.Infmt, TblWdbeMSegment.Outfmt, TblWdbeMSegment.Latency";
};

void QryWdbeSegList::rerun_filtSQL(
			string& sqlstr
			, const string& preSrf
			, const ubigint prePpl
			, const ubigint preSup
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSrf.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMSegment.sref = '" + preSrf + "'";
	};

	if (prePpl != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMSegment.pplRefWdbeMPipeline = " + to_string(prePpl) + "";
	};

	if (preSup != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMSegment.supRefWdbeMSegment = " + to_string(preSup) + "";
	};
};

void QryWdbeSegList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWdbeSegList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::SUP) sqlstr += " ORDER BY TblWdbeMSegment.supRefWdbeMSegment ASC";
	else if (preIxOrd == VecVOrd::PPL) sqlstr += " ORDER BY TblWdbeMSegment.pplRefWdbeMPipeline ASC";
	else if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblWdbeMSegment.sref ASC";
};

void QryWdbeSegList::fetch(
			DbsWdbe* dbswdbe
		) {
	string sqlstr;

	StmgrWdbe* stmgr = NULL;
	Stcch* stcch = NULL;

	WdbeQSegList* rec = NULL;

	dbswdbe->tblwdbeqseglist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubPplRefWdbeMPipeline = StubWdbe::getStubPplStd(dbswdbe, rec->pplRefWdbeMPipeline, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubSupRefWdbeMSegment = StubWdbe::getStubSegStd(dbswdbe, rec->supRefWdbeMSegment, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWdbeSegList", "fetch");
	};

	refreshJnum();
};

uint QryWdbeSegList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WdbeQSegList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWdbeSegList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WdbeQSegList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WdbeQSegList* QryWdbeSegList::getRecByJnum(
			const uint jnum
		) {
	WdbeQSegList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWdbeSegList::handleRequest(
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

bool QryWdbeSegList::handleRerun(
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

bool QryWdbeSegList::handleShow(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	WdbeQSegList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsref";
	cout << "\tpplRefWdbeMPipeline";
	cout << "\tstubPplRefWdbeMPipeline";
	cout << "\tsupRefWdbeMSegment";
	cout << "\tstubSupRefWdbeMSegment";
	cout << "\tInfmt";
	cout << "\tOutfmt";
	cout << "\tLatency";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->pplRefWdbeMPipeline;
		cout << "\t" << rec->stubPplRefWdbeMPipeline;
		cout << "\t" << rec->supRefWdbeMSegment;
		cout << "\t" << rec->stubSupRefWdbeMSegment;
		cout << "\t" << rec->Infmt;
		cout << "\t" << rec->Outfmt;
		cout << "\t" << rec->Latency;
		cout << endl;
	};
	return retval;
};

void QryWdbeSegList::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBESEGUPD_REFEQ) {
		call->abort = handleCallWdbeSegUpd_refEq(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBESEGMOD) {
		call->abort = handleCallWdbeSegMod(dbswdbe, call->jref);
	} else if ((call->ixVCall == VecWdbeVCall::CALLWDBESTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWdbeStubChgFromSelf(dbswdbe);
	};
};

bool QryWdbeSegList::handleCallWdbeSegUpd_refEq(
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

bool QryWdbeSegList::handleCallWdbeSegMod(
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

bool QryWdbeSegList::handleCallWdbeStubChgFromSelf(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleCallWdbeStubChgFromSelf --- INSERT
	return retval;
};
