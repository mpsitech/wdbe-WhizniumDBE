/**
	* \file QryWdbeMtpList.cpp
	* job handler for job QryWdbeMtpList (implementation)
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

#include "QryWdbeMtpList.h"

#include "QryWdbeMtpList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWdbeMtpList
 ******************************************************************************/

QryWdbeMtpList::QryWdbeMtpList(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::QRYWDBEMTPLIST, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWdbeVQrystate = VecWdbeVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswdbe);

	xchg->addClstn(VecWdbeVCall::CALLWDBESTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEMDLMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWdbeMtpList::~QryWdbeMtpList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWdbeMtpList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWdbeVCall::CALLWDBEMDLUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWdbeVCall::CALLWDBEMDLUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWdbeMtpList::rerun(
			DbsWdbe* dbswdbe
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	uint preIxOrd = xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXORD, jref);
	string preSrf = xchg->getSrefPreset(VecWdbeVPreset::PREWDBEMTPLIST_SRF, jref);
	uint preTyp = xchg->getIxPreset(VecWdbeVPreset::PREWDBEMTPLIST_TYP, jref);
	uint preHkt = xchg->getIxPreset(VecWdbeVPreset::PREWDBEMTPLIST_HKT, jref);
	ubigint preHku = xchg->getRefPreset(VecWdbeVPreset::PREWDBEMTPLIST_HKU, jref);

	dbswdbe->tblwdbeqselect->removeRstByJref(jref);
	dbswdbe->tblwdbeqmtplist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWdbeMModule.ref)";
	sqlstr += " FROM TblWdbeMModule";
	sqlstr += " WHERE (TblWdbeMModule.hkIxVTbl = 1 AND (TblWdbeMModule.supRefWdbeMModule = 0 AND TblWdbeMModule.tplRefWdbeMModule = 0))";
	rerun_filtSQL(sqlstr, preSrf, preTyp, preHkt, preHku, false);
	dbswdbe->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWdbeQMtpList(jref, jnum, ref, sref, srefWdbeKVendor, ixVBasetype, hkIxVTbl, hkUref, Srefrule)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWdbeMModule.ref, TblWdbeMModule.sref, TblWdbeMModule.srefWdbeKVendor, TblWdbeMModule.ixVBasetype, TblWdbeMModule.hkIxVTbl, TblWdbeMModule.hkUref, TblWdbeMModule.Srefrule";
	sqlstr += " FROM TblWdbeMModule";
	sqlstr += " WHERE (TblWdbeMModule.hkIxVTbl = 1 AND (TblWdbeMModule.supRefWdbeMModule = 0 AND TblWdbeMModule.tplRefWdbeMModule = 0))";
	rerun_filtSQL(sqlstr, preSrf, preTyp, preHkt, preHku, false);
	rerun_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswdbe->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWdbeQMtpList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswdbe->executeQuery(sqlstr);

	ixWdbeVQrystate = VecWdbeVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswdbe);

	if (call) xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBESTATCHG, jref);

};

void QryWdbeMtpList::rerun_filtSQL(
			string& sqlstr
			, const string& preSrf
			, const uint preTyp
			, const uint preHkt
			, const ubigint preHku
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSrf.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMModule.sref = '" + preSrf + "'";
	};

	if (preTyp != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMModule.ixVBasetype = " + to_string(preTyp) + "";
	};

	if (preHkt != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMModule.hkIxVTbl = " + to_string(preHkt) + "";
	};

	if (preHku != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMModule.hkUref = " + to_string(preHku) + "";
	};
};

void QryWdbeMtpList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWdbeMtpList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblWdbeMModule.sref ASC";
	else if (preIxOrd == VecVOrd::TYP) sqlstr += " ORDER BY TblWdbeMModule.ixVBasetype ASC";
	else if (preIxOrd == VecVOrd::HKT) sqlstr += " ORDER BY TblWdbeMModule.hkIxVTbl ASC";
	else if (preIxOrd == VecVOrd::HKU) sqlstr += " ORDER BY TblWdbeMModule.hkUref ASC";
};

void QryWdbeMtpList::fetch(
			DbsWdbe* dbswdbe
		) {
	string sqlstr;

	StmgrWdbe* stmgr = NULL;
	Stcch* stcch = NULL;

	WdbeQMtpList* rec = NULL;

	dbswdbe->tblwdbeqmtplist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->titSrefWdbeKVendor = dbswdbe->getKlstTitleBySref(VecWdbeVKeylist::KLSTWDBEKVENDOR, rec->srefWdbeKVendor, ixWdbeVLocale);
			rec->srefIxVBasetype = VecWdbeVMModuleBasetype::getSref(rec->ixVBasetype);
			rec->titIxVBasetype = VecWdbeVMModuleBasetype::getTitle(rec->ixVBasetype, ixWdbeVLocale);
			rec->srefHkIxVTbl = VecWdbeVMModuleHkTbl::getSref(rec->hkIxVTbl);
			rec->titHkIxVTbl = VecWdbeVMModuleHkTbl::getTitle(rec->hkIxVTbl, ixWdbeVLocale);
			if (rec->hkIxVTbl == VecWdbeVMModuleHkTbl::CVR) {
				rec->stubHkUref = StubWdbe::getStubCvrStd(dbswdbe, rec->hkUref, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else if (rec->hkIxVTbl == VecWdbeVMModuleHkTbl::UNT) {
				rec->stubHkUref = StubWdbe::getStubUntStd(dbswdbe, rec->hkUref, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else rec->stubHkUref = "-";
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWdbeMtpList", "fetch");
	};

	refreshJnum();
};

uint QryWdbeMtpList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WdbeQMtpList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWdbeMtpList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WdbeQMtpList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WdbeQMtpList* QryWdbeMtpList::getRecByJnum(
			const uint jnum
		) {
	WdbeQMtpList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWdbeMtpList::handleRequest(
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

bool QryWdbeMtpList::handleRerun(
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

bool QryWdbeMtpList::handleShow(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	WdbeQMtpList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsref";
	cout << "\tsrefWdbeKVendor";
	cout << "\ttitSrefWdbeKVendor";
	cout << "\tixVBasetype";
	cout << "\tsrefIxVBasetype";
	cout << "\ttitIxVBasetype";
	cout << "\thkIxVTbl";
	cout << "\tsrefHkIxVTbl";
	cout << "\ttitHkIxVTbl";
	cout << "\thkUref";
	cout << "\tstubHkUref";
	cout << "\tSrefrule";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->srefWdbeKVendor;
		cout << "\t" << rec->titSrefWdbeKVendor;
		cout << "\t" << rec->ixVBasetype;
		cout << "\t" << rec->srefIxVBasetype;
		cout << "\t" << rec->titIxVBasetype;
		cout << "\t" << rec->hkIxVTbl;
		cout << "\t" << rec->srefHkIxVTbl;
		cout << "\t" << rec->titHkIxVTbl;
		cout << "\t" << rec->hkUref;
		cout << "\t" << rec->stubHkUref;
		cout << "\t" << rec->Srefrule;
		cout << endl;
	};
	return retval;
};

void QryWdbeMtpList::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if ((call->ixVCall == VecWdbeVCall::CALLWDBESTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWdbeStubChgFromSelf(dbswdbe);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDLMOD) {
		call->abort = handleCallWdbeMdlMod(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDLUPD_REFEQ) {
		call->abort = handleCallWdbeMdlUpd_refEq(dbswdbe, call->jref);
	};
};

bool QryWdbeMtpList::handleCallWdbeStubChgFromSelf(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleCallWdbeStubChgFromSelf --- INSERT
	return retval;
};

bool QryWdbeMtpList::handleCallWdbeMdlMod(
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

bool QryWdbeMtpList::handleCallWdbeMdlUpd_refEq(
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
