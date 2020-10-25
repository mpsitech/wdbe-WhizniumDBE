/**
	* \file QryWdbeVecList.cpp
	* job handler for job QryWdbeVecList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbed.h>
#endif

#include "QryWdbeVecList.h"

#include "QryWdbeVecList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWdbeVecList
 ******************************************************************************/

QryWdbeVecList::QryWdbeVecList(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::QRYWDBEVECLIST, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWdbeVQrystate = VecWdbeVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswdbe);

	xchg->addClstn(VecWdbeVCall::CALLWDBESTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEVECMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWdbeVecList::~QryWdbeVecList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWdbeVecList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWdbeVCall::CALLWDBEVECUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWdbeVCall::CALLWDBEVECUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWdbeVecList::rerun(
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
	ubigint preRefUnt = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref);
	ubigint preRefVer = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref);
	string preSrf = xchg->getSrefPreset(VecWdbeVPreset::PREWDBEVECLIST_SRF, jref);
	uint preTyp = xchg->getIxPreset(VecWdbeVPreset::PREWDBEVECLIST_TYP, jref);
	uint preHkt = xchg->getIxPreset(VecWdbeVPreset::PREWDBEVECLIST_HKT, jref);
	ubigint preHku = xchg->getRefPreset(VecWdbeVPreset::PREWDBEVECLIST_HKU, jref);

	dbswdbe->tblwdbeqselect->removeRstByJref(jref);
	dbswdbe->tblwdbeqveclist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecWdbeVPreset::PREWDBEREFUNT) {
		sqlstr = "SELECT COUNT(TblWdbeMVector.ref)";
		sqlstr += " FROM TblWdbeMVector";
		sqlstr += " WHERE TblWdbeMVector.hkIxVTbl = " + to_string(VecWdbeVMVectorHkTbl::UNT);
		sqlstr += " AND TblWdbeMVector.hkUref = " + to_string(preRefUnt) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preHkt, preHku, false);
		dbswdbe->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else if (preIxPre == VecWdbeVPreset::PREWDBEREFVER) {
		sqlstr = "SELECT COUNT(TblWdbeMVector.ref)";
		sqlstr += " FROM TblWdbeMVector, TblWdbeMSystem";
		sqlstr += " WHERE TblWdbeMVector.hkIxVTbl = " + to_string(VecWdbeVMVectorHkTbl::SYS);
		sqlstr += " AND TblWdbeMVector.hkUref = TblWdbeMSystem.ref";
		sqlstr += " AND TblWdbeMSystem.refWdbeMVersion = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preHkt, preHku, false);
		dbswdbe->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

		sqlstr = "SELECT COUNT(TblWdbeMVector.ref)";
		sqlstr += " FROM TblWdbeMVector, TblWdbeMUnit";
		sqlstr += " WHERE TblWdbeMVector.hkIxVTbl = " + to_string(VecWdbeVMVectorHkTbl::UNT);
		sqlstr += " AND TblWdbeMVector.hkUref = TblWdbeMUnit.ref";
		sqlstr += " AND TblWdbeMUnit.refIxVTbl = " + to_string(VecWdbeVMUnitRefTbl::VER);
		sqlstr += " AND TblWdbeMUnit.refUref = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preHkt, preHku, false);
		dbswdbe->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblWdbeMVector.ref)";
		sqlstr += " FROM TblWdbeMVector";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preHkt, preHku, true);
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
		sqlstr += " FROM TblWdbeMVector";
		sqlstr += " WHERE TblWdbeMVector.hkIxVTbl = " + to_string(VecWdbeVMVectorHkTbl::UNT);
		sqlstr += " AND TblWdbeMVector.hkUref = " + to_string(preRefUnt) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preHkt, preHku, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswdbe->executeQuery(sqlstr);

	} else if (preIxPre == VecWdbeVPreset::PREWDBEREFVER) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWdbeMVector, TblWdbeMSystem";
		sqlstr += " WHERE TblWdbeMVector.hkIxVTbl = " + to_string(VecWdbeVMVectorHkTbl::SYS);
		sqlstr += " AND TblWdbeMVector.hkUref = TblWdbeMSystem.ref";
		sqlstr += " AND TblWdbeMSystem.refWdbeMVersion = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preHkt, preHku, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswdbe->executeQuery(sqlstr);

		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWdbeMVector, TblWdbeMUnit";
		sqlstr += " WHERE TblWdbeMVector.hkIxVTbl = " + to_string(VecWdbeVMVectorHkTbl::UNT);
		sqlstr += " AND TblWdbeMVector.hkUref = TblWdbeMUnit.ref";
		sqlstr += " AND TblWdbeMUnit.refIxVTbl = " + to_string(VecWdbeVMUnitRefTbl::VER);
		sqlstr += " AND TblWdbeMUnit.refUref = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preHkt, preHku, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[1]) + " OFFSET " + to_string(ofss[1]);
		dbswdbe->executeQuery(sqlstr);

	} else {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWdbeMVector";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preHkt, preHku, true);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswdbe->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblWdbeQVecList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswdbe->executeQuery(sqlstr);

	ixWdbeVQrystate = VecWdbeVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswdbe);

	if (call) xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBESTATCHG, jref);

};

void QryWdbeVecList::rerun_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblWdbeQVecList(jref, jnum, ref, sref, ixVBasetype, hkIxVTbl, hkUref)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWdbeMVector.ref, TblWdbeMVector.sref, TblWdbeMVector.ixVBasetype, TblWdbeMVector.hkIxVTbl, TblWdbeMVector.hkUref";
};

void QryWdbeVecList::rerun_filtSQL(
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
		sqlstr += "TblWdbeMVector.sref = '" + preSrf + "'";
	};

	if (preTyp != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMVector.ixVBasetype = " + to_string(preTyp) + "";
	};

	if (preHkt != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMVector.hkIxVTbl = " + to_string(preHkt) + "";
	};

	if (preHku != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMVector.hkUref = " + to_string(preHku) + "";
	};
};

void QryWdbeVecList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWdbeVecList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblWdbeMVector.sref ASC";
	else if (preIxOrd == VecVOrd::TYP) sqlstr += " ORDER BY TblWdbeMVector.ixVBasetype ASC";
	else if (preIxOrd == VecVOrd::HKT) sqlstr += " ORDER BY TblWdbeMVector.hkIxVTbl ASC";
	else if (preIxOrd == VecVOrd::HKU) sqlstr += " ORDER BY TblWdbeMVector.hkUref ASC";
};

void QryWdbeVecList::fetch(
			DbsWdbe* dbswdbe
		) {
	string sqlstr;

	StmgrWdbe* stmgr = NULL;
	Stcch* stcch = NULL;

	WdbeQVecList* rec = NULL;

	dbswdbe->tblwdbeqveclist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefIxVBasetype = VecWdbeVMVectorBasetype::getSref(rec->ixVBasetype);
			rec->titIxVBasetype = VecWdbeVMVectorBasetype::getTitle(rec->ixVBasetype, ixWdbeVLocale);
			rec->srefHkIxVTbl = VecWdbeVMVectorHkTbl::getSref(rec->hkIxVTbl);
			rec->titHkIxVTbl = VecWdbeVMVectorHkTbl::getTitle(rec->hkIxVTbl, ixWdbeVLocale);
			if (rec->hkIxVTbl == VecWdbeVMVectorHkTbl::CTR) {
				rec->stubHkUref = StubWdbe::getStubCtrStd(dbswdbe, rec->hkUref, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else if (rec->hkIxVTbl == VecWdbeVMVectorHkTbl::SYS) {
				rec->stubHkUref = StubWdbe::getStubSysStd(dbswdbe, rec->hkUref, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else if (rec->hkIxVTbl == VecWdbeVMVectorHkTbl::UNT) {
				rec->stubHkUref = StubWdbe::getStubUntStd(dbswdbe, rec->hkUref, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else rec->stubHkUref = "-";
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWdbeVecList", "fetch");
	};

	refreshJnum();
};

uint QryWdbeVecList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WdbeQVecList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWdbeVecList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WdbeQVecList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WdbeQVecList* QryWdbeVecList::getRecByJnum(
			const uint jnum
		) {
	WdbeQVecList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWdbeVecList::handleRequest(
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

bool QryWdbeVecList::handleRerun(
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

bool QryWdbeVecList::handleShow(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	WdbeQVecList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsref";
	cout << "\tixVBasetype";
	cout << "\tsrefIxVBasetype";
	cout << "\ttitIxVBasetype";
	cout << "\thkIxVTbl";
	cout << "\tsrefHkIxVTbl";
	cout << "\ttitHkIxVTbl";
	cout << "\thkUref";
	cout << "\tstubHkUref";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->ixVBasetype;
		cout << "\t" << rec->srefIxVBasetype;
		cout << "\t" << rec->titIxVBasetype;
		cout << "\t" << rec->hkIxVTbl;
		cout << "\t" << rec->srefHkIxVTbl;
		cout << "\t" << rec->titHkIxVTbl;
		cout << "\t" << rec->hkUref;
		cout << "\t" << rec->stubHkUref;
		cout << endl;
	};
	return retval;
};

void QryWdbeVecList::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if ((call->ixVCall == VecWdbeVCall::CALLWDBESTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWdbeStubChgFromSelf(dbswdbe);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEVECMOD) {
		call->abort = handleCallWdbeVecMod(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEVECUPD_REFEQ) {
		call->abort = handleCallWdbeVecUpd_refEq(dbswdbe, call->jref);
	};
};

bool QryWdbeVecList::handleCallWdbeStubChgFromSelf(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleCallWdbeStubChgFromSelf --- INSERT
	return retval;
};

bool QryWdbeVecList::handleCallWdbeVecMod(
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

bool QryWdbeVecList::handleCallWdbeVecUpd_refEq(
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

