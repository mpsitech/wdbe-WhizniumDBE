/**
	* \file QryWdbeCmdList.cpp
	* job handler for job QryWdbeCmdList (implementation)
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

#include "QryWdbeCmdList.h"

#include "QryWdbeCmdList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWdbeCmdList
 ******************************************************************************/

QryWdbeCmdList::QryWdbeCmdList(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::QRYWDBECMDLIST, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWdbeVQrystate = VecWdbeVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswdbe);

	xchg->addClstn(VecWdbeVCall::CALLWDBECMDMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBESTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWdbeCmdList::~QryWdbeCmdList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWdbeCmdList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWdbeVCall::CALLWDBECMDUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWdbeVCall::CALLWDBECMDUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWdbeCmdList::rerun(
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
	ubigint preRefCtr = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCTR, jref);
	ubigint preRefUnt = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref);
	string preSrf = xchg->getSrefPreset(VecWdbeVPreset::PREWDBECMDLIST_SRF, jref);
	uint preRet = xchg->getIxPreset(VecWdbeVPreset::PREWDBECMDLIST_RET, jref);
	ubigint preReu = xchg->getRefPreset(VecWdbeVPreset::PREWDBECMDLIST_REU, jref);

	dbswdbe->tblwdbeqselect->removeRstByJref(jref);
	dbswdbe->tblwdbeqcmdlist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecWdbeVPreset::PREWDBEREFUNT) {
		sqlstr = "SELECT COUNT(TblWdbeMCommand.ref)";
		sqlstr += " FROM TblWdbeMCommand";
		sqlstr += " WHERE TblWdbeMCommand.refIxVTbl = " + to_string(VecWdbeVMCommandRefTbl::UNT);
		sqlstr += " AND TblWdbeMCommand.refUref = " + to_string(preRefUnt) + "";
		rerun_filtSQL(sqlstr, preSrf, preRet, preReu, false);
		dbswdbe->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else if (preIxPre == VecWdbeVPreset::PREWDBEREFCTR) {
		sqlstr = "SELECT COUNT(TblWdbeMCommand.ref)";
		sqlstr += " FROM TblWdbeMCommand";
		sqlstr += " WHERE TblWdbeMCommand.refIxVTbl = " + to_string(VecWdbeVMCommandRefTbl::CTR);
		sqlstr += " AND TblWdbeMCommand.refUref = " + to_string(preRefCtr) + "";
		rerun_filtSQL(sqlstr, preSrf, preRet, preReu, false);
		dbswdbe->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblWdbeMCommand.ref)";
		sqlstr += " FROM TblWdbeMCommand";
		rerun_filtSQL(sqlstr, preSrf, preRet, preReu, true);
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
		sqlstr += " FROM TblWdbeMCommand";
		sqlstr += " WHERE TblWdbeMCommand.refIxVTbl = " + to_string(VecWdbeVMCommandRefTbl::UNT);
		sqlstr += " AND TblWdbeMCommand.refUref = " + to_string(preRefUnt) + "";
		rerun_filtSQL(sqlstr, preSrf, preRet, preReu, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswdbe->executeQuery(sqlstr);

	} else if (preIxPre == VecWdbeVPreset::PREWDBEREFCTR) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWdbeMCommand";
		sqlstr += " WHERE TblWdbeMCommand.refIxVTbl = " + to_string(VecWdbeVMCommandRefTbl::CTR);
		sqlstr += " AND TblWdbeMCommand.refUref = " + to_string(preRefCtr) + "";
		rerun_filtSQL(sqlstr, preSrf, preRet, preReu, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswdbe->executeQuery(sqlstr);

	} else {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWdbeMCommand";
		rerun_filtSQL(sqlstr, preSrf, preRet, preReu, true);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswdbe->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblWdbeQCmdList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswdbe->executeQuery(sqlstr);

	ixWdbeVQrystate = VecWdbeVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswdbe);

	if (call) xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBESTATCHG, jref);

};

void QryWdbeCmdList::rerun_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblWdbeQCmdList(jref, jnum, ref, sref, Fullsref, refIxVTbl, refUref, ixVRettype)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWdbeMCommand.ref, TblWdbeMCommand.sref, TblWdbeMCommand.Fullsref, TblWdbeMCommand.refIxVTbl, TblWdbeMCommand.refUref, TblWdbeMCommand.ixVRettype";
};

void QryWdbeCmdList::rerun_filtSQL(
			string& sqlstr
			, const string& preSrf
			, const uint preRet
			, const ubigint preReu
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preSrf.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMCommand.sref = '" + preSrf + "'";
	};

	if (preRet != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMCommand.refIxVTbl = " + to_string(preRet) + "";
	};

	if (preReu != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWdbeMCommand.refUref = " + to_string(preReu) + "";
	};
};

void QryWdbeCmdList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWdbeCmdList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::RET) sqlstr += " ORDER BY TblWdbeMCommand.refIxVTbl ASC";
	else if (preIxOrd == VecVOrd::REU) sqlstr += " ORDER BY TblWdbeMCommand.refUref ASC";
	else if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblWdbeMCommand.sref ASC";
};

void QryWdbeCmdList::fetch(
			DbsWdbe* dbswdbe
		) {
	string sqlstr;

	StmgrWdbe* stmgr = NULL;
	Stcch* stcch = NULL;

	WdbeQCmdList* rec = NULL;

	dbswdbe->tblwdbeqcmdlist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefRefIxVTbl = VecWdbeVMCommandRefTbl::getSref(rec->refIxVTbl);
			rec->titRefIxVTbl = VecWdbeVMCommandRefTbl::getTitle(rec->refIxVTbl, ixWdbeVLocale);
			if (rec->refIxVTbl == VecWdbeVMCommandRefTbl::UNT) {
				rec->stubRefUref = StubWdbe::getStubUntStd(dbswdbe, rec->refUref, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else if (rec->refIxVTbl == VecWdbeVMCommandRefTbl::CTR) {
				rec->stubRefUref = StubWdbe::getStubCtrStd(dbswdbe, rec->refUref, ixWdbeVLocale, Stub::VecVNonetype::SHORT, stcch);
			} else rec->stubRefUref = "-";
			rec->srefIxVRettype = VecWdbeVMCommandRettype::getSref(rec->ixVRettype);
			rec->titIxVRettype = VecWdbeVMCommandRettype::getTitle(rec->ixVRettype, ixWdbeVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWdbeCmdList", "fetch");
	};

	refreshJnum();
};

uint QryWdbeCmdList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WdbeQCmdList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWdbeCmdList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WdbeQCmdList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WdbeQCmdList* QryWdbeCmdList::getRecByJnum(
			const uint jnum
		) {
	WdbeQCmdList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWdbeCmdList::handleRequest(
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

bool QryWdbeCmdList::handleRerun(
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

bool QryWdbeCmdList::handleShow(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	WdbeQCmdList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tsref";
	cout << "\tFullsref";
	cout << "\trefIxVTbl";
	cout << "\tsrefRefIxVTbl";
	cout << "\ttitRefIxVTbl";
	cout << "\trefUref";
	cout << "\tstubRefUref";
	cout << "\tixVRettype";
	cout << "\tsrefIxVRettype";
	cout << "\ttitIxVRettype";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->Fullsref;
		cout << "\t" << rec->refIxVTbl;
		cout << "\t" << rec->srefRefIxVTbl;
		cout << "\t" << rec->titRefIxVTbl;
		cout << "\t" << rec->refUref;
		cout << "\t" << rec->stubRefUref;
		cout << "\t" << rec->ixVRettype;
		cout << "\t" << rec->srefIxVRettype;
		cout << "\t" << rec->titIxVRettype;
		cout << endl;
	};
	return retval;
};

void QryWdbeCmdList::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBECMDUPD_REFEQ) {
		call->abort = handleCallWdbeCmdUpd_refEq(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBECMDMOD) {
		call->abort = handleCallWdbeCmdMod(dbswdbe, call->jref);
	} else if ((call->ixVCall == VecWdbeVCall::CALLWDBESTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWdbeStubChgFromSelf(dbswdbe);
	};
};

bool QryWdbeCmdList::handleCallWdbeCmdUpd_refEq(
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

bool QryWdbeCmdList::handleCallWdbeCmdMod(
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

bool QryWdbeCmdList::handleCallWdbeStubChgFromSelf(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleCallWdbeStubChgFromSelf --- INSERT
	return retval;
};
