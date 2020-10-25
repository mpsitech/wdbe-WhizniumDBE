/**
	* \file PnlWdbeCvrRec.cpp
	* job handler for job PnlWdbeCvrRec (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbed.h>
#endif

#include "PnlWdbeCvrRec.h"

#include "PnlWdbeCvrRec_blks.cpp"
#include "PnlWdbeCvrRec_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWdbeCvrRec
 ******************************************************************************/

PnlWdbeCvrRec::PnlWdbeCvrRec(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::PNLWDBECVRREC, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	pnldetail = NULL;
	pnlaip = NULL;
	pnlaplh = NULL;
	pnlbcv1ncoreversion = NULL;
	pnlhk1nmodule = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWdbeVCall::CALLWDBECVR_BCVEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBECVR_CPREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswdbe, VecWdbeVPreset::PREWDBEREFCVR, jref);
};

PnlWdbeCvrRec::~PnlWdbeCvrRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* PnlWdbeCvrRec::getNewDpchEng(
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

void PnlWdbeCvrRec::refresh(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubWdbe::getStubCvrStd(dbswdbe, recCvr.ref, ixWdbeVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recCvr.ref == 0) statshr.ixWdbeVExpstate = VecWdbeVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbswdbe);

	if (statshr.ixWdbeVExpstate == VecWdbeVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlaip) {delete pnlaip; pnlaip = NULL;};
		if (pnlaplh) {delete pnlaplh; pnlaplh = NULL;};
		if (pnlbcv1ncoreversion) {delete pnlbcv1ncoreversion; pnlbcv1ncoreversion = NULL;};
		if (pnlhk1nmodule) {delete pnlhk1nmodule; pnlhk1nmodule = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlWdbeCvrDetail(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlaip) pnlaip = new PnlWdbeCvrAIp(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlaplh) pnlaplh = new PnlWdbeCvrAPlh(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlbcv1ncoreversion) pnlbcv1ncoreversion = new PnlWdbeCvrBcv1NCoreversion(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlhk1nmodule) pnlhk1nmodule = new PnlWdbeCvrHk1NModule(xchg, dbswdbe, jref, ixWdbeVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefAIp = ((pnlaip) ? pnlaip->jref : 0);
	statshr.jrefAPlh = ((pnlaplh) ? pnlaplh->jref : 0);
	statshr.jrefBcv1NCoreversion = ((pnlbcv1ncoreversion) ? pnlbcv1ncoreversion->jref : 0);
	statshr.jrefHk1NModule = ((pnlhk1nmodule) ? pnlhk1nmodule->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWdbeCvrRec::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFCVR) {
		WdbeMCoreversion* _recCvr = NULL;

		if (dbswdbe->tblwdbemcoreversion->loadRecByRef(xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCVR, jref), &_recCvr)) {
			recCvr = *_recCvr;
			delete _recCvr;
		} else recCvr = WdbeMCoreversion();

		if (recCvr.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlaip) pnlaip->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlaplh) pnlaplh->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlbcv1ncoreversion) pnlbcv1ncoreversion->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlhk1nmodule) pnlhk1nmodule->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
		};

		refresh(dbswdbe, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWdbeCvrRec::minimize(
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

void PnlWdbeCvrRec::regularize(
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

void PnlWdbeCvrRec::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECVRRECDO) {
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

void PnlWdbeCvrRec::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWdbeCvrRec::handleDpchAppDoButMinimizeClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	minimize(dbswdbe, true, dpcheng);
};

void PnlWdbeCvrRec::handleDpchAppDoButRegularizeClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	regularize(dbswdbe, true, dpcheng);
};

void PnlWdbeCvrRec::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBECVR_BCVEQ) {
		call->abort = handleCallWdbeCvr_bcvEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBECVR_CPREQ) {
		call->abort = handleCallWdbeCvr_cprEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBECVRUPD_REFEQ) {
		call->abort = handleCallWdbeCvrUpd_refEq(dbswdbe, call->jref);
	};
};

bool PnlWdbeCvrRec::handleCallWdbeCvr_bcvEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recCvr.bcvRefWdbeMCoreversion == refInv); // IP handleCallWdbeCvr_bcvEq --- LINE
	return retval;
};

bool PnlWdbeCvrRec::handleCallWdbeCvr_cprEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recCvr.refWdbeMCoreproject == refInv); // IP handleCallWdbeCvr_cprEq --- LINE
	return retval;
};

bool PnlWdbeCvrRec::handleCallWdbeCvrUpd_refEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWdbeCvrUpd_refEq --- INSERT
	return retval;
};

