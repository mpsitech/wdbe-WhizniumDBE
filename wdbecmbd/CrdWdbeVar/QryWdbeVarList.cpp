/**
	* \file QryWdbeVarList.cpp
	* job handler for job QryWdbeVarList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbed.h>
#endif

#include "QryWdbeVarList.h"

#include "QryWdbeVarList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWdbeVarList
 ******************************************************************************/

QryWdbeVarList::QryWdbeVarList(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::QRYWDBEVARLIST, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWdbeVQrystate = VecWdbeVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswdbe);

	xchg->addClstn(VecWdbeVCall::CALLWDBESTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEVARMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWdbeVarList::~QryWdbeVarList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWdbeVarList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWdbeVCall::CALLWDBEVARUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWdbeVCall::CALLWDBEVARUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWdbeVarList::rerun(
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
	ubigint preRefPrc = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFPRC, jref);
	string preSrf = xchg->getSrefPreset(VecWdbeVPreset::PREWDBEVARLIST_SRF, jref);
	ubigint prePrc = xchg->getRefPreset(VecWdbeVPreset::PREWDBEVARLIST_PRC, jref);

	dbswdbe->tblwdbeqselect->removeRstByJref(jref);
	dbswdbe->tblwdbeqvarlist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecWdbeVPreset::PREWDBEREFPRC) {
		sqlstr = "SELECT COUNT(TblWdbeMVariable.ref)";
		sqlstr += " FROM TblWdbeMVariable";
		sqlstr += " WHERE TblWdbeMVariable.prcRefWdbeMProcess = " + to_string(preRefPrc) + "";
		rerun_filtSQL(sqlstr, preSrf, prePrc, false);
		dbswdbe->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblWdbeMVariable.ref)";
		sqlstr += " FROM TblWdbeMVariable";
		rerun_filtSQL(sqlstr, preSrf, prePrc, true);
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

	if (preIxPre == VecWdbeVPreset::PREWDBEREFPRC) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWdbeMVariable";
		sqlstr += " WHERE TblWdbeMVariable.prcRefWdbeMProcess = " + to_string(preRefPrc) + "";
		rerun_filtSQL(sqlstr, preSrf, prePrc, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswdbe->executeQuery(sqlstr);

	} else {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWdbeMVariable";
		rerun_filtSQL(sqlstr, preSrf, prePrc, true);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswdbe->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblWdbeQVarList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswdbe->executeQuery(sqlstr);

	ixWdbeVQrystate = VecWdbeVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswdbe);

	if (call) xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBESTATCHG, jref);

};

void QryWdbeVarList::rerun_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblWdbeQVarList(jref, jnum, ref, sref, prcRefWdbeMProcess, Const, Falling, srefWdbeKHdltype, Width, Minmax)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWdbeMVariable.ref, TblWdbeMVariable.sref, TblWdbeMVariable.prcRefWdbeMProcess, TblWdbeMVariable.Const, TblWdbeMVariable.Falling, TblWdbeMVariable.srefWdbeKHdltype, TblWdbeMVariable.Width, TblWdbeMVariable.Minmax";
};

void QryWdbeVarList::rerun_filtSQL(
			string& sqlstr
			, const string& preSrf
			, const ubigint prePrc
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSrf.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMVariable.sref = '" + preSrf + "'";
	};

	if (prePrc != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMVariable.prcRefWdbeMProcess = " + to_string(prePrc) + "";
	};
};

void QryWdbeVarList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWdbeVarList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblWdbeMVariable.sref ASC";
	else if (preIxOrd == VecVOrd::PRC) sqlstr += " ORDER BY TblWdbeMVariable.prcRefWdbeMProcess ASC";
};

void QryWdbeVarList::fetch(
			DbsWdbe* dbswdbe
		) {
	string sqlstr;

	StmgrWdbe* stmgr = NULL;
	Stcch* stcch = NULL;

	WdbeQVarList* rec = NULL;

	dbswdbe->tblwdbeqvarlist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubPrcRefWdbeMProcess = StubWdbe::getStubPrcStd(dbswdbe, rec->prcRefWdbeMProcess, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			if (rec->Const) rec->yesnoConst = VecWdbeVTag::getTitle(VecWdbeVTag::YES, ixWdbeVLocale); else rec->yesnoConst = VecWdbeVTag::getTitle(VecWdbeVTag::NO, ixWdbeVLocale);
			if (rec->Falling) rec->yesnoFalling = VecWdbeVTag::getTitle(VecWdbeVTag::YES, ixWdbeVLocale); else rec->yesnoFalling = VecWdbeVTag::getTitle(VecWdbeVTag::NO, ixWdbeVLocale);
			rec->titSrefWdbeKHdltype = dbswdbe->getKlstTitleBySref(VecWdbeVKeylist::KLSTWDBEKHDLTYPE, rec->srefWdbeKHdltype, ixWdbeVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWdbeVarList", "fetch");
	};

	refreshJnum();
};

uint QryWdbeVarList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WdbeQVarList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWdbeVarList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WdbeQVarList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WdbeQVarList* QryWdbeVarList::getRecByJnum(
			const uint jnum
		) {
	WdbeQVarList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWdbeVarList::handleRequest(
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

bool QryWdbeVarList::handleRerun(
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

bool QryWdbeVarList::handleShow(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	WdbeQVarList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsref";
	cout << "\tprcRefWdbeMProcess";
	cout << "\tstubPrcRefWdbeMProcess";
	cout << "\tConst";
	cout << "\tyesnoConst";
	cout << "\tFalling";
	cout << "\tyesnoFalling";
	cout << "\tsrefWdbeKHdltype";
	cout << "\ttitSrefWdbeKHdltype";
	cout << "\tWidth";
	cout << "\tMinmax";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->prcRefWdbeMProcess;
		cout << "\t" << rec->stubPrcRefWdbeMProcess;
		cout << "\t" << rec->Const;
		cout << "\t" << rec->yesnoConst;
		cout << "\t" << rec->Falling;
		cout << "\t" << rec->yesnoFalling;
		cout << "\t" << rec->srefWdbeKHdltype;
		cout << "\t" << rec->titSrefWdbeKHdltype;
		cout << "\t" << rec->Width;
		cout << "\t" << rec->Minmax;
		cout << endl;
	};
	return retval;
};

void QryWdbeVarList::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if ((call->ixVCall == VecWdbeVCall::CALLWDBESTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWdbeStubChgFromSelf(dbswdbe);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEVARMOD) {
		call->abort = handleCallWdbeVarMod(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEVARUPD_REFEQ) {
		call->abort = handleCallWdbeVarUpd_refEq(dbswdbe, call->jref);
	};
};

bool QryWdbeVarList::handleCallWdbeStubChgFromSelf(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleCallWdbeStubChgFromSelf --- INSERT
	return retval;
};

bool QryWdbeVarList::handleCallWdbeVarMod(
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

bool QryWdbeVarList::handleCallWdbeVarUpd_refEq(
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

