/**
	* \file PnlWdbePrcRec.cpp
	* job handler for job PnlWdbePrcRec (implementation)
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

#include "PnlWdbePrcRec.h"

#include "PnlWdbePrcRec_blks.cpp"
#include "PnlWdbePrcRec_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWdbePrcRec
 ******************************************************************************/

PnlWdbePrcRec::PnlWdbePrcRec(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::PNLWDBEPRCREC, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	pnldetail = NULL;
	pnlkhdltype = NULL;
	pnlmge1nsignal = NULL;
	pnlref1nvariable = NULL;
	pnlref1nsensitivity = NULL;
	pnlfsmfsm1nfsmstate = NULL;
	pnlfsmhk1nvector = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWdbeVCall::CALLWDBEPRC_FSMEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEPRC_MDLEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswdbe, VecWdbeVPreset::PREWDBEREFPRC, jref);
};

PnlWdbePrcRec::~PnlWdbePrcRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* PnlWdbePrcRec::getNewDpchEng(
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

void PnlWdbePrcRec::refresh(
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
	continf.TxtRef = StubWdbe::getStubPrcStd(dbswdbe, recPrc.ref, ixWdbeVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recPrc.ref == 0) statshr.ixWdbeVExpstate = VecWdbeVExpstate::MIND;

	statshr.pnlfsmfsm1nfsmstateAvail = evalPnlfsmfsm1nfsmstateAvail(dbswdbe);
	statshr.pnlfsmhk1nvectorAvail = evalPnlfsmhk1nvectorAvail(dbswdbe);
	statshr.ButRegularizeActive = evalButRegularizeActive(dbswdbe);

	if (statshr.ixWdbeVExpstate == VecWdbeVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlkhdltype) {delete pnlkhdltype; pnlkhdltype = NULL;};
		if (pnlmge1nsignal) {delete pnlmge1nsignal; pnlmge1nsignal = NULL;};
		if (pnlref1nvariable) {delete pnlref1nvariable; pnlref1nvariable = NULL;};
		if (pnlref1nsensitivity) {delete pnlref1nsensitivity; pnlref1nsensitivity = NULL;};
		if (pnlfsmfsm1nfsmstate) {delete pnlfsmfsm1nfsmstate; pnlfsmfsm1nfsmstate = NULL;};
		if (pnlfsmhk1nvector) {delete pnlfsmhk1nvector; pnlfsmhk1nvector = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlWdbePrcDetail(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlkhdltype) pnlkhdltype = new PnlWdbePrcKHdltype(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlmge1nsignal) pnlmge1nsignal = new PnlWdbePrcMge1NSignal(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlref1nvariable) pnlref1nvariable = new PnlWdbePrcRef1NVariable(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlref1nsensitivity) pnlref1nsensitivity = new PnlWdbePrcRef1NSensitivity(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlfsmfsm1nfsmstate) pnlfsmfsm1nfsmstate = new PnlWdbePrcFsmFsm1NFsmstate(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlfsmhk1nvector) pnlfsmhk1nvector = new PnlWdbePrcFsmHk1NVector(xchg, dbswdbe, jref, ixWdbeVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefKHdltype = ((pnlkhdltype) ? pnlkhdltype->jref : 0);
	statshr.jrefMge1NSignal = ((pnlmge1nsignal) ? pnlmge1nsignal->jref : 0);
	statshr.jrefRef1NVariable = ((pnlref1nvariable) ? pnlref1nvariable->jref : 0);
	statshr.jrefRef1NSensitivity = ((pnlref1nsensitivity) ? pnlref1nsensitivity->jref : 0);
	statshr.jrefFsmFsm1NFsmstate = ((pnlfsmfsm1nfsmstate) ? pnlfsmfsm1nfsmstate->jref : 0);
	statshr.jrefFsmHk1NVector = ((pnlfsmhk1nvector) ? pnlfsmhk1nvector->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWdbePrcRec::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFPRC) {
		WdbeMProcess* _recPrc = NULL;
		WdbeMFsm* _recFsm = NULL;

		if (dbswdbe->tblwdbemprocess->loadRecByRef(xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFPRC, jref), &_recPrc)) {
			recPrc = *_recPrc;
			delete _recPrc;
		} else recPrc = WdbeMProcess();

		if (dbswdbe->tblwdbemfsm->loadRecByRef(recPrc.refWdbeMFsm, &_recFsm)) {
			recFsm = *_recFsm;
			delete _recFsm;
		} else recFsm = WdbeMFsm();

		if (recPrc.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlkhdltype) pnlkhdltype->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlmge1nsignal) pnlmge1nsignal->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlref1nvariable) pnlref1nvariable->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlref1nsensitivity) pnlref1nsensitivity->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlfsmfsm1nfsmstate) pnlfsmfsm1nfsmstate->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlfsmhk1nvector) pnlfsmhk1nvector->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
		};

		refresh(dbswdbe, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWdbePrcRec::minimize(
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

void PnlWdbePrcRec::regularize(
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

void PnlWdbePrcRec::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRCRECDO) {
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

void PnlWdbePrcRec::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWdbePrcRec::handleDpchAppDoButMinimizeClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	minimize(dbswdbe, true, dpcheng);
};

void PnlWdbePrcRec::handleDpchAppDoButRegularizeClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	regularize(dbswdbe, true, dpcheng);
};

void PnlWdbePrcRec::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBEPRC_FSMEQ) {
		call->abort = handleCallWdbePrc_fsmEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEPRC_MDLEQ) {
		call->abort = handleCallWdbePrc_mdlEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEFSMUPD_REFEQ) {
		call->abort = handleCallWdbeFsmUpd_refEq(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEPRCUPD_REFEQ) {
		call->abort = handleCallWdbePrcUpd_refEq(dbswdbe, call->jref);
	};
};

bool PnlWdbePrcRec::handleCallWdbePrc_fsmEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recPrc.refWdbeMFsm == refInv); // IP handleCallWdbePrc_fsmEq --- LINE
	return retval;
};

bool PnlWdbePrcRec::handleCallWdbePrc_mdlEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recPrc.refWdbeMModule == refInv); // IP handleCallWdbePrc_mdlEq --- LINE
	return retval;
};

bool PnlWdbePrcRec::handleCallWdbeFsmUpd_refEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWdbeFsmUpd_refEq --- INSERT
	return retval;
};

bool PnlWdbePrcRec::handleCallWdbePrcUpd_refEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWdbePrcUpd_refEq --- INSERT
	return retval;
};
