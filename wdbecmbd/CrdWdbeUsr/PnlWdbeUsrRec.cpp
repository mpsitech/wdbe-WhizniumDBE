/**
	* \file PnlWdbeUsrRec.cpp
	* job handler for job PnlWdbeUsrRec (implementation)
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

#include "PnlWdbeUsrRec.h"

#include "PnlWdbeUsrRec_blks.cpp"
#include "PnlWdbeUsrRec_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWdbeUsrRec
 ******************************************************************************/

PnlWdbeUsrRec::PnlWdbeUsrRec(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::PNLWDBEUSRREC, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	pnlmnusergroup = NULL;
	pnl1nsession = NULL;
	pnlaaccess = NULL;
	pnldetail = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWdbeVCall::CALLWDBEUSR_USGEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEUSR_PRSEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswdbe, VecWdbeVPreset::PREWDBEREFUSR, jref);
};

PnlWdbeUsrRec::~PnlWdbeUsrRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* PnlWdbeUsrRec::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &continf, &statshr, items);
	};

	return dpcheng;
};

void PnlWdbeUsrRec::refresh(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubWdbe::getStubUsrStd(dbswdbe, recUsr.ref, ixWdbeVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recUsr.ref == 0) statshr.ixWdbeVExpstate = VecWdbeVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbswdbe);

	if (statshr.ixWdbeVExpstate == VecWdbeVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlaaccess) {delete pnlaaccess; pnlaaccess = NULL;};
		if (pnl1nsession) {delete pnl1nsession; pnl1nsession = NULL;};
		if (pnlmnusergroup) {delete pnlmnusergroup; pnlmnusergroup = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlWdbeUsrDetail(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlaaccess) pnlaaccess = new PnlWdbeUsrAAccess(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnl1nsession) pnl1nsession = new PnlWdbeUsr1NSession(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlmnusergroup) pnlmnusergroup = new PnlWdbeUsrMNUsergroup(xchg, dbswdbe, jref, ixWdbeVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefAAccess = ((pnlaaccess) ? pnlaaccess->jref : 0);
	statshr.jref1NSession = ((pnl1nsession) ? pnl1nsession->jref : 0);
	statshr.jrefMNUsergroup = ((pnlmnusergroup) ? pnlmnusergroup->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWdbeUsrRec::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFUSR) {
		WdbeMUser* _recUsr = NULL;

		if (dbswdbe->tblwdbemuser->loadRecByRef(xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUSR, jref), &_recUsr)) {
			recUsr = *_recUsr;
			delete _recUsr;
		} else recUsr = WdbeMUser();

		if (recUsr.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlaaccess) pnlaaccess->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnl1nsession) pnl1nsession->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlmnusergroup) pnlmnusergroup->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
		};

		refresh(dbswdbe, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWdbeUsrRec::minimize(
			DbsWdbe* dbswdbe
			, const bool notif
			, DpchEngWdbe** dpcheng
		) {
	set<uint> moditems;

	if (statshr.ixWdbeVExpstate != VecWdbeVExpstate::MIND) {
		statshr.ixWdbeVExpstate = VecWdbeVExpstate::MIND;
		insert(moditems, DpchEngData::STATSHR);

		refresh(dbswdbe, moditems);
	};

	if (notif) {
		if (dpcheng) *dpcheng = getNewDpchEng(moditems);
		else if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
};

void PnlWdbeUsrRec::regularize(
			DbsWdbe* dbswdbe
			, const bool notif
			, DpchEngWdbe** dpcheng
		) {
	set<uint> moditems;

	if (statshr.ixWdbeVExpstate != VecWdbeVExpstate::REGD) {
		statshr.ixWdbeVExpstate = VecWdbeVExpstate::REGD;
		insert(moditems, DpchEngData::STATSHR);

		refresh(dbswdbe, moditems);
	};

	if (notif) {
		if (dpcheng) *dpcheng = getNewDpchEng(moditems);
		else if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
};

void PnlWdbeUsrRec::handleRequest(
			DbsWdbe* dbswdbe
			, ReqWdbe* req
		) {
	if (req->ixVBasetype == ReqWdbe::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::DPCHAPP) {
		if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEINIT) {
			handleDpchAppWdbeInit(dbswdbe, (DpchAppWdbeInit*) (req->dpchapp), &(req->dpcheng));

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUSRRECDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTMINIMIZECLICK) {
					handleDpchAppDoButMinimizeClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREGULARIZECLICK) {
					handleDpchAppDoButRegularizeClick(dbswdbe, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWdbeUsrRec::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWdbeUsrRec::handleDpchAppDoButMinimizeClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	minimize(dbswdbe, true, dpcheng);
};

void PnlWdbeUsrRec::handleDpchAppDoButRegularizeClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	regularize(dbswdbe, true, dpcheng);
};

void PnlWdbeUsrRec::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBEUSRUPD_REFEQ) {
		call->abort = handleCallWdbeUsrUpd_refEq(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEUSR_USGEQ) {
		call->abort = handleCallWdbeUsr_usgEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEUSR_PRSEQ) {
		call->abort = handleCallWdbeUsr_prsEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWdbeUsrRec::handleCallWdbeUsrUpd_refEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWdbeUsrUpd_refEq --- INSERT
	return retval;
};

bool PnlWdbeUsrRec::handleCallWdbeUsr_usgEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recUsr.refWdbeMUsergroup == refInv); // IP handleCallWdbeUsr_usgEq --- LINE
	return retval;
};

bool PnlWdbeUsrRec::handleCallWdbeUsr_prsEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recUsr.refWdbeMPerson == refInv); // IP handleCallWdbeUsr_prsEq --- LINE
	return retval;
};



