/**
	* \file QryWdbeSigList.cpp
	* job handler for job QryWdbeSigList (implementation)
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

#include "QryWdbeSigList.h"

#include "QryWdbeSigList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWdbeSigList
 ******************************************************************************/

QryWdbeSigList::QryWdbeSigList(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::QRYWDBESIGLIST, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWdbeVQrystate = VecWdbeVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswdbe);

	xchg->addClstn(VecWdbeVCall::CALLWDBESTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBESIGMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWdbeSigList::~QryWdbeSigList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWdbeSigList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWdbeVCall::CALLWDBESIGUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWdbeVCall::CALLWDBESIGUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWdbeSigList::rerun(
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
	ubigint preRefMtp = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFMTP, jref);
	string preSrf = xchg->getSrefPreset(VecWdbeVPreset::PREWDBESIGLIST_SRF, jref);
	uint preTyp = xchg->getIxPreset(VecWdbeVPreset::PREWDBESIGLIST_TYP, jref);
	ubigint preMdl = xchg->getRefPreset(VecWdbeVPreset::PREWDBESIGLIST_MDL, jref);
	uint preMgt = xchg->getIxPreset(VecWdbeVPreset::PREWDBESIGLIST_MGT, jref);
	ubigint preMgu = xchg->getRefPreset(VecWdbeVPreset::PREWDBESIGLIST_MGU, jref);
	ubigint preVec = xchg->getRefPreset(VecWdbeVPreset::PREWDBESIGLIST_VEC, jref);
	bool preCon = xchg->getBoolvalPreset(VecWdbeVPreset::PREWDBESIGLIST_CON, jref);

	dbswdbe->tblwdbeqselect->removeRstByJref(jref);
	dbswdbe->tblwdbeqsiglist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecWdbeVPreset::PREWDBEREFMTP) {
		sqlstr = "SELECT COUNT(TblWdbeMSignal.ref)";
		sqlstr += " FROM TblWdbeMSignal";
		sqlstr += " WHERE TblWdbeMSignal.mdlRefWdbeMModule = " + to_string(preRefMtp) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preMdl, preMgt, preMgu, preVec, preCon, false);
		dbswdbe->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else if (preIxPre == VecWdbeVPreset::PREWDBEREFMOD) {
		sqlstr = "SELECT COUNT(TblWdbeMSignal.ref)";
		sqlstr += " FROM TblWdbeMSignal";
		sqlstr += " WHERE TblWdbeMSignal.mdlRefWdbeMModule = " + to_string(preRefMod) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preMdl, preMgt, preMgu, preVec, preCon, false);
		dbswdbe->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblWdbeMSignal.ref)";
		sqlstr += " FROM TblWdbeMSignal";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preMdl, preMgt, preMgu, preVec, preCon, true);
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

	if (preIxPre == VecWdbeVPreset::PREWDBEREFMTP) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWdbeMSignal";
		sqlstr += " WHERE TblWdbeMSignal.mdlRefWdbeMModule = " + to_string(preRefMtp) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preMdl, preMgt, preMgu, preVec, preCon, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswdbe->executeQuery(sqlstr);

	} else if (preIxPre == VecWdbeVPreset::PREWDBEREFMOD) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWdbeMSignal";
		sqlstr += " WHERE TblWdbeMSignal.mdlRefWdbeMModule = " + to_string(preRefMod) + "";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preMdl, preMgt, preMgu, preVec, preCon, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswdbe->executeQuery(sqlstr);

	} else {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWdbeMSignal";
		rerun_filtSQL(sqlstr, preSrf, preTyp, preMdl, preMgt, preMgu, preVec, preCon, true);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswdbe->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblWdbeQSigList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswdbe->executeQuery(sqlstr);

	ixWdbeVQrystate = VecWdbeVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswdbe);

	if (call) xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBESTATCHG, jref);

};

void QryWdbeSigList::rerun_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblWdbeQSigList(jref, jnum, ref, sref, ixVBasetype, mdlRefWdbeMModule, mgeIxVTbl, mgeUref, refWdbeMVector, Const, srefWdbeKHdltype, Width, Minmax)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWdbeMSignal.ref, TblWdbeMSignal.sref, TblWdbeMSignal.ixVBasetype, TblWdbeMSignal.mdlRefWdbeMModule, TblWdbeMSignal.mgeIxVTbl, TblWdbeMSignal.mgeUref, TblWdbeMSignal.refWdbeMVector, TblWdbeMSignal.Const, TblWdbeMSignal.srefWdbeKHdltype, TblWdbeMSignal.Width, TblWdbeMSignal.Minmax";
};

void QryWdbeSigList::rerun_filtSQL(
			string& sqlstr
			, const string& preSrf
			, const uint preTyp
			, const ubigint preMdl
			, const uint preMgt
			, const ubigint preMgu
			, const ubigint preVec
			, const bool preCon
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSrf.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMSignal.sref = '" + preSrf + "'";
	};

	if (preTyp != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMSignal.ixVBasetype = " + to_string(preTyp) + "";
	};

	if (preMdl != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMSignal.mdlRefWdbeMModule = " + to_string(preMdl) + "";
	};

	if (preMgt != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMSignal.mgeIxVTbl = " + to_string(preMgt) + "";
	};

	if (preMgu != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMSignal.mgeUref = " + to_string(preMgu) + "";
	};

	if (preVec != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMSignal.refWdbeMVector = " + to_string(preVec) + "";
	};

	if (preCon == true) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMSignal.Const = " + to_string(preCon) + "";
	};
};

void QryWdbeSigList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWdbeSigList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblWdbeMSignal.sref ASC";
	else if (preIxOrd == VecVOrd::TYP) sqlstr += " ORDER BY TblWdbeMSignal.ixVBasetype ASC";
	else if (preIxOrd == VecVOrd::MDL) sqlstr += " ORDER BY TblWdbeMSignal.mdlRefWdbeMModule ASC";
	else if (preIxOrd == VecVOrd::MGT) sqlstr += " ORDER BY TblWdbeMSignal.mgeIxVTbl ASC";
	else if (preIxOrd == VecVOrd::MGU) sqlstr += " ORDER BY TblWdbeMSignal.mgeUref ASC";
	else if (preIxOrd == VecVOrd::VEC) sqlstr += " ORDER BY TblWdbeMSignal.refWdbeMVector ASC";
	else if (preIxOrd == VecVOrd::CON) sqlstr += " ORDER BY TblWdbeMSignal.Const ASC";
};

void QryWdbeSigList::fetch(
			DbsWdbe* dbswdbe
		) {
	string sqlstr;

	StmgrWdbe* stmgr = NULL;
	Stcch* stcch = NULL;

	WdbeQSigList* rec = NULL;

	dbswdbe->tblwdbeqsiglist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefIxVBasetype = VecWdbeVMSignalBasetype::getSref(rec->ixVBasetype);
			rec->titIxVBasetype = VecWdbeVMSignalBasetype::getTitle(rec->ixVBasetype, ixWdbeVLocale);
			rec->stubMdlRefWdbeMModule = StubWdbe::getStubMdlStd(dbswdbe, rec->mdlRefWdbeMModule, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefMgeIxVTbl = VecWdbeVMSignalMgeTbl::getSref(rec->mgeIxVTbl);
			rec->titMgeIxVTbl = VecWdbeVMSignalMgeTbl::getTitle(rec->mgeIxVTbl, ixWdbeVLocale);
			if (rec->mgeIxVTbl == VecWdbeVMSignalMgeTbl::MDL) {
				rec->stubMgeUref = StubWdbe::getStubMdlStd(dbswdbe, rec->mgeUref, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else if (rec->mgeIxVTbl == VecWdbeVMSignalMgeTbl::PRC) {
				rec->stubMgeUref = StubWdbe::getStubPrcStd(dbswdbe, rec->mgeUref, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else rec->stubMgeUref = "-";
			rec->stubRefWdbeMVector = StubWdbe::getStubVecStd(dbswdbe, rec->refWdbeMVector, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			if (rec->Const) rec->yesnoConst = VecWdbeVTag::getTitle(VecWdbeVTag::YES, ixWdbeVLocale); else rec->yesnoConst = VecWdbeVTag::getTitle(VecWdbeVTag::NO, ixWdbeVLocale);
			rec->titSrefWdbeKHdltype = dbswdbe->getKlstTitleBySref(VecWdbeVKeylist::KLSTWDBEKHDLTYPE, rec->srefWdbeKHdltype, ixWdbeVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWdbeSigList", "fetch");
	};

	refreshJnum();
};

uint QryWdbeSigList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WdbeQSigList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWdbeSigList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WdbeQSigList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WdbeQSigList* QryWdbeSigList::getRecByJnum(
			const uint jnum
		) {
	WdbeQSigList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWdbeSigList::handleRequest(
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

bool QryWdbeSigList::handleRerun(
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

bool QryWdbeSigList::handleShow(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	WdbeQSigList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsref";
	cout << "\tixVBasetype";
	cout << "\tsrefIxVBasetype";
	cout << "\ttitIxVBasetype";
	cout << "\tmdlRefWdbeMModule";
	cout << "\tstubMdlRefWdbeMModule";
	cout << "\tmgeIxVTbl";
	cout << "\tsrefMgeIxVTbl";
	cout << "\ttitMgeIxVTbl";
	cout << "\tmgeUref";
	cout << "\tstubMgeUref";
	cout << "\trefWdbeMVector";
	cout << "\tstubRefWdbeMVector";
	cout << "\tConst";
	cout << "\tyesnoConst";
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
		cout << "\t" << rec->ixVBasetype;
		cout << "\t" << rec->srefIxVBasetype;
		cout << "\t" << rec->titIxVBasetype;
		cout << "\t" << rec->mdlRefWdbeMModule;
		cout << "\t" << rec->stubMdlRefWdbeMModule;
		cout << "\t" << rec->mgeIxVTbl;
		cout << "\t" << rec->srefMgeIxVTbl;
		cout << "\t" << rec->titMgeIxVTbl;
		cout << "\t" << rec->mgeUref;
		cout << "\t" << rec->stubMgeUref;
		cout << "\t" << rec->refWdbeMVector;
		cout << "\t" << rec->stubRefWdbeMVector;
		cout << "\t" << rec->Const;
		cout << "\t" << rec->yesnoConst;
		cout << "\t" << rec->srefWdbeKHdltype;
		cout << "\t" << rec->titSrefWdbeKHdltype;
		cout << "\t" << rec->Width;
		cout << "\t" << rec->Minmax;
		cout << endl;
	};
	return retval;
};

void QryWdbeSigList::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if ((call->ixVCall == VecWdbeVCall::CALLWDBESTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWdbeStubChgFromSelf(dbswdbe);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBESIGMOD) {
		call->abort = handleCallWdbeSigMod(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBESIGUPD_REFEQ) {
		call->abort = handleCallWdbeSigUpd_refEq(dbswdbe, call->jref);
	};
};

bool QryWdbeSigList::handleCallWdbeStubChgFromSelf(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleCallWdbeStubChgFromSelf --- INSERT
	return retval;
};

bool QryWdbeSigList::handleCallWdbeSigMod(
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

bool QryWdbeSigList::handleCallWdbeSigUpd_refEq(
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
