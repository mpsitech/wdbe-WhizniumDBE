/**
	* \file QryWdbePrtList.cpp
	* job handler for job QryWdbePrtList (implementation)
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

#include "QryWdbePrtList.h"

#include "QryWdbePrtList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWdbePrtList
 ******************************************************************************/

QryWdbePrtList::QryWdbePrtList(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::QRYWDBEPRTLIST, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWdbeVQrystate = VecWdbeVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswdbe);

	xchg->addClstn(VecWdbeVCall::CALLWDBEPRTMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBESTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWdbePrtList::~QryWdbePrtList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWdbePrtList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWdbeVCall::CALLWDBEPRTUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWdbeVCall::CALLWDBEPRTUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWdbePrtList::rerun(
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
	string preSrf = xchg->getSrefPreset(VecWdbeVPreset::PREWDBEPRTLIST_SRF, jref);
	ubigint preMdl = xchg->getRefPreset(VecWdbeVPreset::PREWDBEPRTLIST_MDL, jref);

	dbswdbe->tblwdbeqselect->removeRstByJref(jref);
	dbswdbe->tblwdbeqprtlist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecWdbeVPreset::PREWDBEREFMTP) {
		sqlstr = "SELECT COUNT(TblWdbeMPort.ref)";
		sqlstr += " FROM TblWdbeMPort";
		sqlstr += " WHERE TblWdbeMPort.mdlRefWdbeMModule = " + to_string(preRefMtp) + "";
		rerun_filtSQL(sqlstr, preSrf, preMdl, false);
		dbswdbe->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else if (preIxPre == VecWdbeVPreset::PREWDBEREFMOD) {
		sqlstr = "SELECT COUNT(TblWdbeMPort.ref)";
		sqlstr += " FROM TblWdbeMPort";
		sqlstr += " WHERE TblWdbeMPort.mdlRefWdbeMModule = " + to_string(preRefMod) + "";
		rerun_filtSQL(sqlstr, preSrf, preMdl, false);
		dbswdbe->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblWdbeMPort.ref)";
		sqlstr += " FROM TblWdbeMPort";
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
		sqlstr += " FROM TblWdbeMPort";
		sqlstr += " WHERE TblWdbeMPort.mdlRefWdbeMModule = " + to_string(preRefMtp) + "";
		rerun_filtSQL(sqlstr, preSrf, preMdl, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswdbe->executeQuery(sqlstr);

	} else if (preIxPre == VecWdbeVPreset::PREWDBEREFMOD) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWdbeMPort";
		sqlstr += " WHERE TblWdbeMPort.mdlRefWdbeMModule = " + to_string(preRefMod) + "";
		rerun_filtSQL(sqlstr, preSrf, preMdl, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswdbe->executeQuery(sqlstr);

	} else {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWdbeMPort";
		rerun_filtSQL(sqlstr, preSrf, preMdl, true);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswdbe->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblWdbeQPrtList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswdbe->executeQuery(sqlstr);

	ixWdbeVQrystate = VecWdbeVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswdbe);

	if (call) xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBESTATCHG, jref);

};

void QryWdbePrtList::rerun_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblWdbeQPrtList(jref, jnum, ref, sref, mdlRefWdbeMModule, mdlIxVCat, ixVDir, srefWdbeKHdltype, Width, Minmax)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWdbeMPort.ref, TblWdbeMPort.sref, TblWdbeMPort.mdlRefWdbeMModule, TblWdbeMPort.mdlIxVCat, TblWdbeMPort.ixVDir, TblWdbeMPort.srefWdbeKHdltype, TblWdbeMPort.Width, TblWdbeMPort.Minmax";
};

void QryWdbePrtList::rerun_filtSQL(
			string& sqlstr
			, const string& preSrf
			, const ubigint preMdl
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSrf.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMPort.sref = '" + preSrf + "'";
	};

	if (preMdl != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMPort.mdlRefWdbeMModule = " + to_string(preMdl) + "";
	};
};

void QryWdbePrtList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWdbePrtList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::MDL) sqlstr += " ORDER BY TblWdbeMPort.mdlRefWdbeMModule ASC";
	else if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblWdbeMPort.sref ASC";
};

void QryWdbePrtList::fetch(
			DbsWdbe* dbswdbe
		) {
	string sqlstr;

	StmgrWdbe* stmgr = NULL;
	Stcch* stcch = NULL;

	WdbeQPrtList* rec = NULL;

	dbswdbe->tblwdbeqprtlist->loadRstByJref(jref, false, rst);
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
			rec->srefMdlIxVCat = VecWdbeVMPortMdlCat::getSref(rec->mdlIxVCat);
			rec->titMdlIxVCat = VecWdbeVMPortMdlCat::getTitle(rec->mdlIxVCat, ixWdbeVLocale);
			rec->srefIxVDir = VecWdbeVMPortDir::getSref(rec->ixVDir);
			rec->titIxVDir = VecWdbeVMPortDir::getTitle(rec->ixVDir, ixWdbeVLocale);
			rec->titSrefWdbeKHdltype = dbswdbe->getKlstTitleBySref(VecWdbeVKeylist::KLSTWDBEKHDLTYPE, rec->srefWdbeKHdltype, ixWdbeVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWdbePrtList", "fetch");
	};

	refreshJnum();
};

uint QryWdbePrtList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WdbeQPrtList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWdbePrtList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WdbeQPrtList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WdbeQPrtList* QryWdbePrtList::getRecByJnum(
			const uint jnum
		) {
	WdbeQPrtList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWdbePrtList::handleRequest(
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

bool QryWdbePrtList::handleRerun(
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

bool QryWdbePrtList::handleShow(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	WdbeQPrtList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsref";
	cout << "\tmdlRefWdbeMModule";
	cout << "\tstubMdlRefWdbeMModule";
	cout << "\tmdlIxVCat";
	cout << "\tsrefMdlIxVCat";
	cout << "\ttitMdlIxVCat";
	cout << "\tixVDir";
	cout << "\tsrefIxVDir";
	cout << "\ttitIxVDir";
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
		cout << "\t" << rec->mdlIxVCat;
		cout << "\t" << rec->srefMdlIxVCat;
		cout << "\t" << rec->titMdlIxVCat;
		cout << "\t" << rec->ixVDir;
		cout << "\t" << rec->srefIxVDir;
		cout << "\t" << rec->titIxVDir;
		cout << "\t" << rec->srefWdbeKHdltype;
		cout << "\t" << rec->titSrefWdbeKHdltype;
		cout << "\t" << rec->Width;
		cout << "\t" << rec->Minmax;
		cout << endl;
	};
	return retval;
};

void QryWdbePrtList::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBEPRTUPD_REFEQ) {
		call->abort = handleCallWdbePrtUpd_refEq(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEPRTMOD) {
		call->abort = handleCallWdbePrtMod(dbswdbe, call->jref);
	} else if ((call->ixVCall == VecWdbeVCall::CALLWDBESTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWdbeStubChgFromSelf(dbswdbe);
	};
};

bool QryWdbePrtList::handleCallWdbePrtUpd_refEq(
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

bool QryWdbePrtList::handleCallWdbePrtMod(
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

bool QryWdbePrtList::handleCallWdbeStubChgFromSelf(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleCallWdbeStubChgFromSelf --- INSERT
	return retval;
};
