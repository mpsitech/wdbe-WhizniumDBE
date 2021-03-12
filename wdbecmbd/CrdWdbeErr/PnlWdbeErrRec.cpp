/**
	* \file PnlWdbeErrRec.cpp
	* job handler for job PnlWdbeErrRec (implementation)
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

#include "PnlWdbeErrRec.h"

#include "PnlWdbeErrRec_blks.cpp"
#include "PnlWdbeErrRec_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWdbeErrRec
 ******************************************************************************/

PnlWdbeErrRec::PnlWdbeErrRec(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::PNLWDBEERRREC, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	pnlapar = NULL;
	pnldetail = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWdbeVCall::CALLWDBEERR_REUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEERR_REU_MDL_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEERR_REU_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEERR_RETEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswdbe, VecWdbeVPreset::PREWDBEREFERR, jref);
};

PnlWdbeErrRec::~PnlWdbeErrRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* PnlWdbeErrRec::getNewDpchEng(
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

void PnlWdbeErrRec::refresh(
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
	continf.TxtRef = StubWdbe::getStubErrStd(dbswdbe, recErr.ref, ixWdbeVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recErr.ref == 0) statshr.ixWdbeVExpstate = VecWdbeVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbswdbe);

	if (statshr.ixWdbeVExpstate == VecWdbeVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlapar) {delete pnlapar; pnlapar = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlWdbeErrDetail(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlapar) pnlapar = new PnlWdbeErrAPar(xchg, dbswdbe, jref, ixWdbeVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefAPar = ((pnlapar) ? pnlapar->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWdbeErrRec::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFERR) {
		WdbeMError* _recErr = NULL;

		if (dbswdbe->tblwdbemerror->loadRecByRef(xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFERR, jref), &_recErr)) {
			recErr = *_recErr;
			delete _recErr;
		} else recErr = WdbeMError();

		if (recErr.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlapar) pnlapar->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
		};

		refresh(dbswdbe, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWdbeErrRec::minimize(
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

void PnlWdbeErrRec::regularize(
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

void PnlWdbeErrRec::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEERRRECDO) {
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

void PnlWdbeErrRec::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWdbeErrRec::handleDpchAppDoButMinimizeClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	minimize(dbswdbe, true, dpcheng);
};

void PnlWdbeErrRec::handleDpchAppDoButRegularizeClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	regularize(dbswdbe, true, dpcheng);
};

void PnlWdbeErrRec::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBEERRUPD_REFEQ) {
		call->abort = handleCallWdbeErrUpd_refEq(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEERR_REUEQ) {
		call->abort = handleCallWdbeErr_reuEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEERR_REU_MDL_INSBS) {
		call->abort = handleCallWdbeErr_reu_mdl_inSbs(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEERR_REU_INSBS) {
		call->abort = handleCallWdbeErr_reu_inSbs(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEERR_RETEQ) {
		call->abort = handleCallWdbeErr_retEq(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	};
};

bool PnlWdbeErrRec::handleCallWdbeErrUpd_refEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWdbeErrUpd_refEq --- INSERT
	return retval;
};

bool PnlWdbeErrRec::handleCallWdbeErr_reuEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recErr.refUref == refInv); // IP handleCallWdbeErr_reuEq --- LINE
	return retval;
};

bool PnlWdbeErrRec::handleCallWdbeErr_reu_mdl_inSbs(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((dbswdbe->getIxWSubsetByRefWdbeMModule([&](){ubigint ref; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE refWdbeMController = " + to_string(recErr.refUref), ref); return ref;}()) & ixInv) != 0); // IP handleCallWdbeErr_reu_mdl_inSbs --- LINE
	return retval;
};

bool PnlWdbeErrRec::handleCallWdbeErr_reu_inSbs(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((dbswdbe->getIxWSubsetByRefWdbeMUnit(recErr.refUref) & ixInv) != 0); // IP handleCallWdbeErr_reu_inSbs --- LINE
	return retval;
};

bool PnlWdbeErrRec::handleCallWdbeErr_retEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recErr.refIxVTbl == ixInv); // IP handleCallWdbeErr_retEq --- LINE
	return retval;
};
