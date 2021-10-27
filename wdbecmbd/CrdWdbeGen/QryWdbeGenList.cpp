/**
	* \file QryWdbeGenList.cpp
	* job handler for job QryWdbeGenList (implementation)
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

#include "QryWdbeGenList.h"

#include "QryWdbeGenList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWdbeGenList
 ******************************************************************************/

QryWdbeGenList::QryWdbeGenList(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::QRYWDBEGENLIST, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWdbeVQrystate = VecWdbeVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswdbe);

	xchg->addClstn(VecWdbeVCall::CALLWDBESTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEGENMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWdbeGenList::~QryWdbeGenList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWdbeGenList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWdbeVCall::CALLWDBEGENUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWdbeVCall::CALLWDBEGENUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWdbeGenList::rerun(
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
	string preSrf = xchg->getSrefPreset(VecWdbeVPreset::PREWDBEGENLIST_SRF, jref);
	ubigint preMdl = xchg->getRefPreset(VecWdbeVPreset::PREWDBEGENLIST_MDL, jref);

	dbswdbe->tblwdbeqselect->removeRstByJref(jref);
	dbswdbe->tblwdbeqgenlist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecWdbeVPreset::PREWDBEREFMTP) {
		sqlstr = "SELECT COUNT(TblWdbeMGeneric.ref)";
		sqlstr += " FROM TblWdbeMGeneric";
		sqlstr += " WHERE TblWdbeMGeneric.mdlRefWdbeMModule = " + to_string(preRefMtp) + "";
		rerun_filtSQL(sqlstr, preSrf, preMdl, false);
		dbswdbe->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else if (preIxPre == VecWdbeVPreset::PREWDBEREFMOD) {
		sqlstr = "SELECT COUNT(TblWdbeMGeneric.ref)";
		sqlstr += " FROM TblWdbeMGeneric";
		sqlstr += " WHERE TblWdbeMGeneric.mdlRefWdbeMModule = " + to_string(preRefMod) + "";
		rerun_filtSQL(sqlstr, preSrf, preMdl, false);
		dbswdbe->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblWdbeMGeneric.ref)";
		sqlstr += " FROM TblWdbeMGeneric";
		rerun_filtSQL(sqlstr, preSrf, preMdl, true);
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
		sqlstr += " FROM TblWdbeMGeneric";
		sqlstr += " WHERE TblWdbeMGeneric.mdlRefWdbeMModule = " + to_string(preRefMtp) + "";
		rerun_filtSQL(sqlstr, preSrf, preMdl, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswdbe->executeQuery(sqlstr);

	} else if (preIxPre == VecWdbeVPreset::PREWDBEREFMOD) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWdbeMGeneric";
		sqlstr += " WHERE TblWdbeMGeneric.mdlRefWdbeMModule = " + to_string(preRefMod) + "";
		rerun_filtSQL(sqlstr, preSrf, preMdl, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswdbe->executeQuery(sqlstr);

	} else {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWdbeMGeneric";
		rerun_filtSQL(sqlstr, preSrf, preMdl, true);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswdbe->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblWdbeQGenList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswdbe->executeQuery(sqlstr);

	ixWdbeVQrystate = VecWdbeVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswdbe);

	if (call) xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBESTATCHG, jref);

};

void QryWdbeGenList::rerun_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblWdbeQGenList(jref, jnum, ref, sref, mdlRefWdbeMModule, srefWdbeKHdltype, Width, Minmax)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWdbeMGeneric.ref, TblWdbeMGeneric.sref, TblWdbeMGeneric.mdlRefWdbeMModule, TblWdbeMGeneric.srefWdbeKHdltype, TblWdbeMGeneric.Width, TblWdbeMGeneric.Minmax";
};

void QryWdbeGenList::rerun_filtSQL(
			string& sqlstr
			, const string& preSrf
			, const ubigint preMdl
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSrf.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMGeneric.sref = '" + preSrf + "'";
	};

	if (preMdl != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMGeneric.mdlRefWdbeMModule = " + to_string(preMdl) + "";
	};
};

void QryWdbeGenList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWdbeGenList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblWdbeMGeneric.sref ASC";
	else if (preIxOrd == VecVOrd::MDL) sqlstr += " ORDER BY TblWdbeMGeneric.mdlRefWdbeMModule ASC";
};

void QryWdbeGenList::fetch(
			DbsWdbe* dbswdbe
		) {
	string sqlstr;

	StmgrWdbe* stmgr = NULL;
	Stcch* stcch = NULL;

	WdbeQGenList* rec = NULL;

	dbswdbe->tblwdbeqgenlist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubMdlRefWdbeMModule = StubWdbe::getStubMdlStd(dbswdbe, rec->mdlRefWdbeMModule, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->titSrefWdbeKHdltype = dbswdbe->getKlstTitleBySref(VecWdbeVKeylist::KLSTWDBEKHDLTYPE, rec->srefWdbeKHdltype, ixWdbeVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWdbeGenList", "fetch");
	};

	refreshJnum();
};

uint QryWdbeGenList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WdbeQGenList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWdbeGenList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WdbeQGenList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WdbeQGenList* QryWdbeGenList::getRecByJnum(
			const uint jnum
		) {
	WdbeQGenList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWdbeGenList::handleRequest(
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

bool QryWdbeGenList::handleRerun(
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

bool QryWdbeGenList::handleShow(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	WdbeQGenList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsref";
	cout << "\tmdlRefWdbeMModule";
	cout << "\tstubMdlRefWdbeMModule";
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
		cout << "\t" << rec->mdlRefWdbeMModule;
		cout << "\t" << rec->stubMdlRefWdbeMModule;
		cout << "\t" << rec->srefWdbeKHdltype;
		cout << "\t" << rec->titSrefWdbeKHdltype;
		cout << "\t" << rec->Width;
		cout << "\t" << rec->Minmax;
		cout << endl;
	};
	return retval;
};

void QryWdbeGenList::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if ((call->ixVCall == VecWdbeVCall::CALLWDBESTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWdbeStubChgFromSelf(dbswdbe);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEGENMOD) {
		call->abort = handleCallWdbeGenMod(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEGENUPD_REFEQ) {
		call->abort = handleCallWdbeGenUpd_refEq(dbswdbe, call->jref);
	};
};

bool QryWdbeGenList::handleCallWdbeStubChgFromSelf(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleCallWdbeStubChgFromSelf --- INSERT
	return retval;
};

bool QryWdbeGenList::handleCallWdbeGenMod(
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

bool QryWdbeGenList::handleCallWdbeGenUpd_refEq(
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
