/**
	* \file QryWdbeSnsList.cpp
	* job handler for job QryWdbeSnsList (implementation)
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

#include "QryWdbeSnsList.h"

#include "QryWdbeSnsList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWdbeSnsList
 ******************************************************************************/

QryWdbeSnsList::QryWdbeSnsList(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::QRYWDBESNSLIST, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWdbeVQrystate = VecWdbeVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswdbe);

	xchg->addClstn(VecWdbeVCall::CALLWDBESTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBESNSMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWdbeSnsList::~QryWdbeSnsList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWdbeSnsList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWdbeVCall::CALLWDBESNSUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWdbeVCall::CALLWDBESNSUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWdbeSnsList::rerun(
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
	ubigint preRefMod = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFMOD, jref);
	ubigint preRefPrc = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFPRC, jref);
	uint preRet = xchg->getIxPreset(VecWdbeVPreset::PREWDBESNSLIST_RET, jref);
	ubigint preReu = xchg->getRefPreset(VecWdbeVPreset::PREWDBESNSLIST_REU, jref);
	uint preSrt = xchg->getIxPreset(VecWdbeVPreset::PREWDBESNSLIST_SRT, jref);
	ubigint preSru = xchg->getRefPreset(VecWdbeVPreset::PREWDBESNSLIST_SRU, jref);

	dbswdbe->tblwdbeqselect->removeRstByJref(jref);
	dbswdbe->tblwdbeqsnslist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecWdbeVPreset::PREWDBEREFMOD) {
		sqlstr = "SELECT COUNT(TblWdbeMSensitivity.ref)";
		sqlstr += " FROM TblWdbeMSensitivity";
		sqlstr += " WHERE TblWdbeMSensitivity.refIxVTbl = " + to_string(VecWdbeVMSensitivityRefTbl::MDL);
		sqlstr += " AND TblWdbeMSensitivity.refUref = " + to_string(preRefMod) + "";
		rerun_filtSQL(sqlstr, preRet, preReu, preSrt, preSru, false);
		dbswdbe->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

		sqlstr = "SELECT COUNT(TblWdbeMSensitivity.ref)";
		sqlstr += " FROM TblWdbeMSensitivity, TblWdbeMProcess";
		sqlstr += " WHERE TblWdbeMSensitivity.refIxVTbl = " + to_string(VecWdbeVMSensitivityRefTbl::PRC);
		sqlstr += " AND TblWdbeMSensitivity.refUref = TblWdbeMProcess.ref";
		sqlstr += " AND TblWdbeMProcess.refWdbeMModule = " + to_string(preRefMod) + "";
		rerun_filtSQL(sqlstr, preRet, preReu, preSrt, preSru, false);
		dbswdbe->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else if (preIxPre == VecWdbeVPreset::PREWDBEREFPRC) {
		sqlstr = "SELECT COUNT(TblWdbeMSensitivity.ref)";
		sqlstr += " FROM TblWdbeMSensitivity";
		sqlstr += " WHERE TblWdbeMSensitivity.refIxVTbl = " + to_string(VecWdbeVMSensitivityRefTbl::PRC);
		sqlstr += " AND TblWdbeMSensitivity.refUref = " + to_string(preRefPrc) + "";
		rerun_filtSQL(sqlstr, preRet, preReu, preSrt, preSru, false);
		dbswdbe->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblWdbeMSensitivity.ref)";
		sqlstr += " FROM TblWdbeMSensitivity";
		rerun_filtSQL(sqlstr, preRet, preReu, preSrt, preSru, true);
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

	if (preIxPre == VecWdbeVPreset::PREWDBEREFMOD) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWdbeMSensitivity";
		sqlstr += " WHERE TblWdbeMSensitivity.refIxVTbl = " + to_string(VecWdbeVMSensitivityRefTbl::MDL);
		sqlstr += " AND TblWdbeMSensitivity.refUref = " + to_string(preRefMod) + "";
		rerun_filtSQL(sqlstr, preRet, preReu, preSrt, preSru, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswdbe->executeQuery(sqlstr);

		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWdbeMSensitivity, TblWdbeMProcess";
		sqlstr += " WHERE TblWdbeMSensitivity.refIxVTbl = " + to_string(VecWdbeVMSensitivityRefTbl::PRC);
		sqlstr += " AND TblWdbeMSensitivity.refUref = TblWdbeMProcess.ref";
		sqlstr += " AND TblWdbeMProcess.refWdbeMModule = " + to_string(preRefMod) + "";
		rerun_filtSQL(sqlstr, preRet, preReu, preSrt, preSru, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[1]) + " OFFSET " + to_string(ofss[1]);
		dbswdbe->executeQuery(sqlstr);

	} else if (preIxPre == VecWdbeVPreset::PREWDBEREFPRC) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWdbeMSensitivity";
		sqlstr += " WHERE TblWdbeMSensitivity.refIxVTbl = " + to_string(VecWdbeVMSensitivityRefTbl::PRC);
		sqlstr += " AND TblWdbeMSensitivity.refUref = " + to_string(preRefPrc) + "";
		rerun_filtSQL(sqlstr, preRet, preReu, preSrt, preSru, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswdbe->executeQuery(sqlstr);

	} else {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWdbeMSensitivity";
		rerun_filtSQL(sqlstr, preRet, preReu, preSrt, preSru, true);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswdbe->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblWdbeQSnsList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswdbe->executeQuery(sqlstr);

	ixWdbeVQrystate = VecWdbeVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswdbe);

	if (call) xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBESTATCHG, jref);

};

void QryWdbeSnsList::rerun_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblWdbeQSnsList(jref, jnum, ref, refIxVTbl, refUref, srcIxVTbl, srcUref)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWdbeMSensitivity.ref, TblWdbeMSensitivity.refIxVTbl, TblWdbeMSensitivity.refUref, TblWdbeMSensitivity.srcIxVTbl, TblWdbeMSensitivity.srcUref";
};

void QryWdbeSnsList::rerun_filtSQL(
			string& sqlstr
			, const uint preRet
			, const ubigint preReu
			, const uint preSrt
			, const ubigint preSru
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preRet != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMSensitivity.refIxVTbl = " + to_string(preRet) + "";
	};

	if (preReu != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMSensitivity.refUref = " + to_string(preReu) + "";
	};

	if (preSrt != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMSensitivity.srcIxVTbl = " + to_string(preSrt) + "";
	};

	if (preSru != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMSensitivity.srcUref = " + to_string(preSru) + "";
	};
};

void QryWdbeSnsList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWdbeSnsList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::RET) sqlstr += " ORDER BY TblWdbeMSensitivity.refIxVTbl ASC";
	else if (preIxOrd == VecVOrd::REU) sqlstr += " ORDER BY TblWdbeMSensitivity.refUref ASC";
	else if (preIxOrd == VecVOrd::SRT) sqlstr += " ORDER BY TblWdbeMSensitivity.srcIxVTbl ASC";
	else if (preIxOrd == VecVOrd::SRU) sqlstr += " ORDER BY TblWdbeMSensitivity.srcUref ASC";
};

void QryWdbeSnsList::fetch(
			DbsWdbe* dbswdbe
		) {
	string sqlstr;

	StmgrWdbe* stmgr = NULL;
	Stcch* stcch = NULL;

	WdbeQSnsList* rec = NULL;

	dbswdbe->tblwdbeqsnslist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefRefIxVTbl = VecWdbeVMSensitivityRefTbl::getSref(rec->refIxVTbl);
			rec->titRefIxVTbl = VecWdbeVMSensitivityRefTbl::getTitle(rec->refIxVTbl, ixWdbeVLocale);
			if (rec->refIxVTbl == VecWdbeVMSensitivityRefTbl::MDL) {
				rec->stubRefUref = StubWdbe::getStubMdlStd(dbswdbe, rec->refUref, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else if (rec->refIxVTbl == VecWdbeVMSensitivityRefTbl::PRC) {
				rec->stubRefUref = StubWdbe::getStubPrcStd(dbswdbe, rec->refUref, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else rec->stubRefUref = "-";
			rec->srefSrcIxVTbl = VecWdbeVMSensitivitySrcTbl::getSref(rec->srcIxVTbl);
			rec->titSrcIxVTbl = VecWdbeVMSensitivitySrcTbl::getTitle(rec->srcIxVTbl, ixWdbeVLocale);
			if (rec->srcIxVTbl == VecWdbeVMSensitivitySrcTbl::INT) {
				rec->stubSrcUref = StubWdbe::getStubIntStd(dbswdbe, rec->srcUref, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else if (rec->srcIxVTbl == VecWdbeVMSensitivitySrcTbl::PRT) {
				rec->stubSrcUref = StubWdbe::getStubPrtStd(dbswdbe, rec->srcUref, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else if (rec->srcIxVTbl == VecWdbeVMSensitivitySrcTbl::SIG) {
				rec->stubSrcUref = StubWdbe::getStubSigStd(dbswdbe, rec->srcUref, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else rec->stubSrcUref = "-";
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWdbeSnsList", "fetch");
	};

	refreshJnum();
};

uint QryWdbeSnsList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WdbeQSnsList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWdbeSnsList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WdbeQSnsList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WdbeQSnsList* QryWdbeSnsList::getRecByJnum(
			const uint jnum
		) {
	WdbeQSnsList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWdbeSnsList::handleRequest(
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

bool QryWdbeSnsList::handleRerun(
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

bool QryWdbeSnsList::handleShow(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	WdbeQSnsList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\trefIxVTbl";
	cout << "\tsrefRefIxVTbl";
	cout << "\ttitRefIxVTbl";
	cout << "\trefUref";
	cout << "\tstubRefUref";
	cout << "\tsrcIxVTbl";
	cout << "\tsrefSrcIxVTbl";
	cout << "\ttitSrcIxVTbl";
	cout << "\tsrcUref";
	cout << "\tstubSrcUref";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->refIxVTbl;
		cout << "\t" << rec->srefRefIxVTbl;
		cout << "\t" << rec->titRefIxVTbl;
		cout << "\t" << rec->refUref;
		cout << "\t" << rec->stubRefUref;
		cout << "\t" << rec->srcIxVTbl;
		cout << "\t" << rec->srefSrcIxVTbl;
		cout << "\t" << rec->titSrcIxVTbl;
		cout << "\t" << rec->srcUref;
		cout << "\t" << rec->stubSrcUref;
		cout << endl;
	};
	return retval;
};

void QryWdbeSnsList::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if ((call->ixVCall == VecWdbeVCall::CALLWDBESTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWdbeStubChgFromSelf(dbswdbe);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBESNSMOD) {
		call->abort = handleCallWdbeSnsMod(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBESNSUPD_REFEQ) {
		call->abort = handleCallWdbeSnsUpd_refEq(dbswdbe, call->jref);
	};
};

bool QryWdbeSnsList::handleCallWdbeStubChgFromSelf(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleCallWdbeStubChgFromSelf --- INSERT
	return retval;
};

bool QryWdbeSnsList::handleCallWdbeSnsMod(
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

bool QryWdbeSnsList::handleCallWdbeSnsUpd_refEq(
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
