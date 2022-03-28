/**
	* \file QryWdbeUntList.cpp
	* job handler for job QryWdbeUntList (implementation)
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

#include "QryWdbeUntList.h"

#include "QryWdbeUntList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWdbeUntList
 ******************************************************************************/

QryWdbeUntList::QryWdbeUntList(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::QRYWDBEUNTLIST, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWdbeVQrystate = VecWdbeVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswdbe);

	xchg->addClstn(VecWdbeVCall::CALLWDBEUNTMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBESTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWdbeUntList::~QryWdbeUntList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWdbeUntList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWdbeVCall::CALLWDBEUNTUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWdbeVCall::CALLWDBEUNTUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWdbeUntList::rerun(
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
	ubigint preRefVer = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref);
	string preSrf = xchg->getSrefPreset(VecWdbeVPreset::PREWDBEUNTLIST_SRF, jref);
	string preTit = xchg->getTxtvalPreset(VecWdbeVPreset::PREWDBEUNTLIST_TIT, jref);
	uint preTyp = xchg->getIxPreset(VecWdbeVPreset::PREWDBEUNTLIST_TYP, jref);
	uint preRet = xchg->getIxPreset(VecWdbeVPreset::PREWDBEUNTLIST_RET, jref);
	ubigint preReu = xchg->getRefPreset(VecWdbeVPreset::PREWDBEUNTLIST_REU, jref);
	ubigint preSys = xchg->getRefPreset(VecWdbeVPreset::PREWDBEUNTLIST_SYS, jref);
	ubigint preMdl = xchg->getRefPreset(VecWdbeVPreset::PREWDBEUNTLIST_MDL, jref);

	dbswdbe->tblwdbeqselect->removeRstByJref(jref);
	dbswdbe->tblwdbequntlist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecWdbeVPreset::PREWDBEREFVER) {
		sqlstr = "SELECT COUNT(TblWdbeMUnit.ref)";
		sqlstr += " FROM TblWdbeMUnit";
		sqlstr += " WHERE TblWdbeMUnit.refIxVTbl = " + to_string(VecWdbeVMUnitRefTbl::VER);
		sqlstr += " AND TblWdbeMUnit.refUref = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preSrf, preTit, preTyp, preRet, preReu, preSys, preMdl, false);
		dbswdbe->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblWdbeMUnit.ref)";
		sqlstr += " FROM TblWdbeMUnit";
		rerun_filtSQL(sqlstr, preSrf, preTit, preTyp, preRet, preReu, preSys, preMdl, true);
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

	if (preIxPre == VecWdbeVPreset::PREWDBEREFVER) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWdbeMUnit";
		sqlstr += " WHERE TblWdbeMUnit.refIxVTbl = " + to_string(VecWdbeVMUnitRefTbl::VER);
		sqlstr += " AND TblWdbeMUnit.refUref = " + to_string(preRefVer) + "";
		rerun_filtSQL(sqlstr, preSrf, preTit, preTyp, preRet, preReu, preSys, preMdl, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswdbe->executeQuery(sqlstr);

	} else {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWdbeMUnit";
		rerun_filtSQL(sqlstr, preSrf, preTit, preTyp, preRet, preReu, preSys, preMdl, true);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswdbe->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblWdbeQUntList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswdbe->executeQuery(sqlstr);

	ixWdbeVQrystate = VecWdbeVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswdbe);

	if (call) xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBESTATCHG, jref);

};

void QryWdbeUntList::rerun_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblWdbeQUntList(jref, jnum, ref, sref, Title, Fullsref, ixVBasetype, refIxVTbl, refUref, refWdbeMSystem, refWdbeMModule, srefKPackage, Easy, srefKToolch)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWdbeMUnit.ref, TblWdbeMUnit.sref, TblWdbeMUnit.Title, TblWdbeMUnit.Fullsref, TblWdbeMUnit.ixVBasetype, TblWdbeMUnit.refIxVTbl, TblWdbeMUnit.refUref, TblWdbeMUnit.refWdbeMSystem, TblWdbeMUnit.refWdbeMModule, TblWdbeMUnit.srefKPackage, TblWdbeMUnit.Easy, TblWdbeMUnit.srefKToolch";
};

void QryWdbeUntList::rerun_filtSQL(
			string& sqlstr
			, const string& preSrf
			, const string& preTit
			, const uint preTyp
			, const uint preRet
			, const ubigint preReu
			, const ubigint preSys
			, const ubigint preMdl
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSrf.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMUnit.sref = '" + preSrf + "'";
	};

	if (preTit.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMUnit.Title LIKE '" + preTit + "'";
	};

	if (preTyp != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMUnit.ixVBasetype = " + to_string(preTyp) + "";
	};

	if (preRet != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMUnit.refIxVTbl = " + to_string(preRet) + "";
	};

	if (preReu != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMUnit.refUref = " + to_string(preReu) + "";
	};

	if (preSys != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMUnit.refWdbeMSystem = " + to_string(preSys) + "";
	};

	if (preMdl != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMUnit.refWdbeMModule = " + to_string(preMdl) + "";
	};
};

void QryWdbeUntList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWdbeUntList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::MDL) sqlstr += " ORDER BY TblWdbeMUnit.refWdbeMModule ASC";
	else if (preIxOrd == VecVOrd::REU) sqlstr += " ORDER BY TblWdbeMUnit.refUref ASC";
	else if (preIxOrd == VecVOrd::SYS) sqlstr += " ORDER BY TblWdbeMUnit.refWdbeMSystem ASC";
	else if (preIxOrd == VecVOrd::TIT) sqlstr += " ORDER BY TblWdbeMUnit.Title ASC";
	else if (preIxOrd == VecVOrd::TYP) sqlstr += " ORDER BY TblWdbeMUnit.ixVBasetype ASC";
	else if (preIxOrd == VecVOrd::RET) sqlstr += " ORDER BY TblWdbeMUnit.refIxVTbl ASC";
	else if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblWdbeMUnit.sref ASC";
};

void QryWdbeUntList::fetch(
			DbsWdbe* dbswdbe
		) {
	string sqlstr;

	StmgrWdbe* stmgr = NULL;
	Stcch* stcch = NULL;

	WdbeQUntList* rec = NULL;

	dbswdbe->tblwdbequntlist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefIxVBasetype = VecWdbeVMUnitBasetype::getSref(rec->ixVBasetype);
			rec->titIxVBasetype = VecWdbeVMUnitBasetype::getTitle(rec->ixVBasetype, ixWdbeVLocale);
			rec->srefRefIxVTbl = VecWdbeVMUnitRefTbl::getSref(rec->refIxVTbl);
			rec->titRefIxVTbl = VecWdbeVMUnitRefTbl::getTitle(rec->refIxVTbl, ixWdbeVLocale);
			if (rec->refIxVTbl == VecWdbeVMUnitRefTbl::VER) {
				rec->stubRefUref = StubWdbe::getStubVerStd(dbswdbe, rec->refUref, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else if (rec->refIxVTbl == VecWdbeVMUnitRefTbl::FAM) {
				rec->stubRefUref = StubWdbe::getStubFamStd(dbswdbe, rec->refUref, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else rec->stubRefUref = "-";
			rec->stubRefWdbeMSystem = StubWdbe::getStubSysStd(dbswdbe, rec->refWdbeMSystem, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefWdbeMModule = StubWdbe::getStubMdlSref(dbswdbe, rec->refWdbeMModule, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->titSrefKPackage = dbswdbe->getKlstTitleBySref(VecWdbeVKeylist::KLSTWDBEKMUNITPACKAGE, rec->srefKPackage, ixWdbeVLocale);
			if (rec->Easy) rec->yesnoEasy = VecWdbeVTag::getTitle(VecWdbeVTag::YES, ixWdbeVLocale); else rec->yesnoEasy = VecWdbeVTag::getTitle(VecWdbeVTag::NO, ixWdbeVLocale);
			rec->titSrefKToolch = dbswdbe->getKlstTitleBySref(VecWdbeVKeylist::KLSTWDBEKMUNITTOOLCH, rec->srefKToolch, ixWdbeVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWdbeUntList", "fetch");
	};

	refreshJnum();
};

uint QryWdbeUntList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WdbeQUntList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWdbeUntList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WdbeQUntList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WdbeQUntList* QryWdbeUntList::getRecByJnum(
			const uint jnum
		) {
	WdbeQUntList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWdbeUntList::handleRequest(
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

bool QryWdbeUntList::handleRerun(
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

bool QryWdbeUntList::handleShow(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	WdbeQUntList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsref";
	cout << "\tTitle";
	cout << "\tFullsref";
	cout << "\tixVBasetype";
	cout << "\tsrefIxVBasetype";
	cout << "\ttitIxVBasetype";
	cout << "\trefIxVTbl";
	cout << "\tsrefRefIxVTbl";
	cout << "\ttitRefIxVTbl";
	cout << "\trefUref";
	cout << "\tstubRefUref";
	cout << "\trefWdbeMSystem";
	cout << "\tstubRefWdbeMSystem";
	cout << "\trefWdbeMModule";
	cout << "\tstubRefWdbeMModule";
	cout << "\tsrefKPackage";
	cout << "\ttitSrefKPackage";
	cout << "\tEasy";
	cout << "\tyesnoEasy";
	cout << "\tsrefKToolch";
	cout << "\ttitSrefKToolch";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->Title;
		cout << "\t" << rec->Fullsref;
		cout << "\t" << rec->ixVBasetype;
		cout << "\t" << rec->srefIxVBasetype;
		cout << "\t" << rec->titIxVBasetype;
		cout << "\t" << rec->refIxVTbl;
		cout << "\t" << rec->srefRefIxVTbl;
		cout << "\t" << rec->titRefIxVTbl;
		cout << "\t" << rec->refUref;
		cout << "\t" << rec->stubRefUref;
		cout << "\t" << rec->refWdbeMSystem;
		cout << "\t" << rec->stubRefWdbeMSystem;
		cout << "\t" << rec->refWdbeMModule;
		cout << "\t" << rec->stubRefWdbeMModule;
		cout << "\t" << rec->srefKPackage;
		cout << "\t" << rec->titSrefKPackage;
		cout << "\t" << rec->Easy;
		cout << "\t" << rec->yesnoEasy;
		cout << "\t" << rec->srefKToolch;
		cout << "\t" << rec->titSrefKToolch;
		cout << endl;
	};
	return retval;
};

void QryWdbeUntList::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBEUNTMOD) {
		call->abort = handleCallWdbeUntMod(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEUNTUPD_REFEQ) {
		call->abort = handleCallWdbeUntUpd_refEq(dbswdbe, call->jref);
	} else if ((call->ixVCall == VecWdbeVCall::CALLWDBESTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWdbeStubChgFromSelf(dbswdbe);
	};
};

bool QryWdbeUntList::handleCallWdbeUntMod(
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

bool QryWdbeUntList::handleCallWdbeUntUpd_refEq(
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

bool QryWdbeUntList::handleCallWdbeStubChgFromSelf(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleCallWdbeStubChgFromSelf --- INSERT
	return retval;
};
