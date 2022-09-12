/**
	* \file QryWdbeModList.cpp
	* job handler for job QryWdbeModList (implementation)
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

#include "QryWdbeModList.h"

#include "QryWdbeModList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWdbeModList
 ******************************************************************************/

QryWdbeModList::QryWdbeModList(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::QRYWDBEMODLIST, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWdbeVQrystate = VecWdbeVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswdbe);

	xchg->addClstn(VecWdbeVCall::CALLWDBEMDLMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBESTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWdbeModList::~QryWdbeModList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWdbeModList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWdbeVCall::CALLWDBEMDLUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWdbeVCall::CALLWDBEMDLUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWdbeModList::rerun(
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
	ubigint preRefCvr = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCVR, jref);
	ubigint preRefUnt = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref);
	string preSrf = xchg->getSrefPreset(VecWdbeVPreset::PREWDBEMODLIST_SRF, jref);
	uint preTyp = xchg->getIxPreset(VecWdbeVPreset::PREWDBEMODLIST_TYP, jref);
	uint preHkt = xchg->getIxPreset(VecWdbeVPreset::PREWDBEMODLIST_HKT, jref);
	ubigint preHku = xchg->getRefPreset(VecWdbeVPreset::PREWDBEMODLIST_HKU, jref);
	ubigint preSup = xchg->getRefPreset(VecWdbeVPreset::PREWDBEMODLIST_SUP, jref);
	ubigint preTpl = xchg->getRefPreset(VecWdbeVPreset::PREWDBEMODLIST_TPL, jref);

	dbswdbe->tblwdbeqselect->removeRstByJref(jref);
	dbswdbe->tblwdbeqmodlist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecWdbeVPreset::PREWDBEREFUNT) {
		sqlstr = "SELECT COUNT(TblWdbeMModule.ref)";
		sqlstr += " FROM TblWdbeMModule";
		sqlstr += " WHERE NOT ((TblWdbeMModule.hkIxVTbl = 1 AND (TblWdbeMModule.supRefWdbeMModule = 0 AND TblWdbeMModule.tplRefWdbeMModule = 0)))";
		sqlstr += " AND TblWdbeMModule.hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT);
		sqlstr += " AND TblWdbeMModule.hkUref = " + to_string(preRefUnt) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preHkt, preHku, preSup, preTpl, false);
		dbswdbe->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else if (preIxPre == VecWdbeVPreset::PREWDBEREFCVR) {
		sqlstr = "SELECT COUNT(TblWdbeMModule.ref)";
		sqlstr += " FROM TblWdbeMModule";
		sqlstr += " WHERE NOT ((TblWdbeMModule.hkIxVTbl = 1 AND (TblWdbeMModule.supRefWdbeMModule = 0 AND TblWdbeMModule.tplRefWdbeMModule = 0)))";
		sqlstr += " AND TblWdbeMModule.hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::CVR);
		sqlstr += " AND TblWdbeMModule.hkUref = " + to_string(preRefCvr) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preHkt, preHku, preSup, preTpl, false);
		dbswdbe->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblWdbeMModule.ref)";
		sqlstr += " FROM TblWdbeMModule";
		sqlstr += " WHERE NOT ((TblWdbeMModule.hkIxVTbl = 1 AND (TblWdbeMModule.supRefWdbeMModule = 0 AND TblWdbeMModule.tplRefWdbeMModule = 0)))";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preHkt, preHku, preSup, preTpl, false);
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
		sqlstr += " FROM TblWdbeMModule";
		sqlstr += " WHERE NOT ((TblWdbeMModule.hkIxVTbl = 1 AND (TblWdbeMModule.supRefWdbeMModule = 0 AND TblWdbeMModule.tplRefWdbeMModule = 0)))";
		sqlstr += " AND TblWdbeMModule.hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT);
		sqlstr += " AND TblWdbeMModule.hkUref = " + to_string(preRefUnt) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preHkt, preHku, preSup, preTpl, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswdbe->executeQuery(sqlstr);

	} else if (preIxPre == VecWdbeVPreset::PREWDBEREFCVR) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWdbeMModule";
		sqlstr += " WHERE NOT ((TblWdbeMModule.hkIxVTbl = 1 AND (TblWdbeMModule.supRefWdbeMModule = 0 AND TblWdbeMModule.tplRefWdbeMModule = 0)))";
		sqlstr += " AND TblWdbeMModule.hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::CVR);
		sqlstr += " AND TblWdbeMModule.hkUref = " + to_string(preRefCvr) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preHkt, preHku, preSup, preTpl, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswdbe->executeQuery(sqlstr);

	} else {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWdbeMModule";
		sqlstr += " WHERE NOT ((TblWdbeMModule.hkIxVTbl = 1 AND (TblWdbeMModule.supRefWdbeMModule = 0 AND TblWdbeMModule.tplRefWdbeMModule = 0)))";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preHkt, preHku, preSup, preTpl, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswdbe->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblWdbeQModList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswdbe->executeQuery(sqlstr);

	ixWdbeVQrystate = VecWdbeVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswdbe);

	if (call) xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBESTATCHG, jref);

};

void QryWdbeModList::rerun_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblWdbeQModList(jref, jnum, ref, sref, srefWdbeKVendor, ixVBasetype, hkIxVTbl, hkUref, supRefWdbeMModule, tplRefWdbeMModule, Srefrule)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWdbeMModule.ref, TblWdbeMModule.sref, TblWdbeMModule.srefWdbeKVendor, TblWdbeMModule.ixVBasetype, TblWdbeMModule.hkIxVTbl, TblWdbeMModule.hkUref, TblWdbeMModule.supRefWdbeMModule, TblWdbeMModule.tplRefWdbeMModule, TblWdbeMModule.Srefrule";
};

void QryWdbeModList::rerun_filtSQL(
			string& sqlstr
			, const string& preSrf
			, const uint preTyp
			, const uint preHkt
			, const ubigint preHku
			, const ubigint preSup
			, const ubigint preTpl
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

	if (preSup != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMModule.supRefWdbeMModule = " + to_string(preSup) + "";
	};

	if (preTpl != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMModule.tplRefWdbeMModule = " + to_string(preTpl) + "";
	};
};

void QryWdbeModList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWdbeModList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::TPL) sqlstr += " ORDER BY TblWdbeMModule.tplRefWdbeMModule ASC";
	else if (preIxOrd == VecVOrd::SUP) sqlstr += " ORDER BY TblWdbeMModule.supRefWdbeMModule ASC";
	else if (preIxOrd == VecVOrd::HKU) sqlstr += " ORDER BY TblWdbeMModule.hkUref ASC";
	else if (preIxOrd == VecVOrd::HKT) sqlstr += " ORDER BY TblWdbeMModule.hkIxVTbl ASC";
	else if (preIxOrd == VecVOrd::TYP) sqlstr += " ORDER BY TblWdbeMModule.ixVBasetype ASC";
	else if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblWdbeMModule.sref ASC";
};

void QryWdbeModList::fetch(
			DbsWdbe* dbswdbe
		) {
	string sqlstr;

	StmgrWdbe* stmgr = NULL;
	Stcch* stcch = NULL;

	WdbeQModList* rec = NULL;

	dbswdbe->tblwdbeqmodlist->loadRstByJref(jref, false, rst);
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
			rec->stubSupRefWdbeMModule = StubWdbe::getStubMdlStd(dbswdbe, rec->supRefWdbeMModule, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubTplRefWdbeMModule = StubWdbe::getStubMdlStd(dbswdbe, rec->tplRefWdbeMModule, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWdbeModList", "fetch");
	};

	refreshJnum();
};

uint QryWdbeModList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WdbeQModList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWdbeModList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WdbeQModList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WdbeQModList* QryWdbeModList::getRecByJnum(
			const uint jnum
		) {
	WdbeQModList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWdbeModList::handleRequest(
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

bool QryWdbeModList::handleRerun(
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

bool QryWdbeModList::handleShow(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	WdbeQModList* rec = NULL;

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
	cout << "\tsupRefWdbeMModule";
	cout << "\tstubSupRefWdbeMModule";
	cout << "\ttplRefWdbeMModule";
	cout << "\tstubTplRefWdbeMModule";
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
		cout << "\t" << rec->supRefWdbeMModule;
		cout << "\t" << rec->stubSupRefWdbeMModule;
		cout << "\t" << rec->tplRefWdbeMModule;
		cout << "\t" << rec->stubTplRefWdbeMModule;
		cout << "\t" << rec->Srefrule;
		cout << endl;
	};
	return retval;
};

void QryWdbeModList::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBEMDLUPD_REFEQ) {
		call->abort = handleCallWdbeMdlUpd_refEq(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDLMOD) {
		call->abort = handleCallWdbeMdlMod(dbswdbe, call->jref);
	} else if ((call->ixVCall == VecWdbeVCall::CALLWDBESTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWdbeStubChgFromSelf(dbswdbe);
	};
};

bool QryWdbeModList::handleCallWdbeMdlUpd_refEq(
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

bool QryWdbeModList::handleCallWdbeMdlMod(
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

bool QryWdbeModList::handleCallWdbeStubChgFromSelf(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleCallWdbeStubChgFromSelf --- INSERT
	return retval;
};
