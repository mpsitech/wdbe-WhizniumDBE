/**
	* \file CrdWdbePrt.cpp
	* job handler for job CrdWdbePrt (implementation)
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

#include "CrdWdbePrt.h"

#include "CrdWdbePrt_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class CrdWdbePrt
 ******************************************************************************/

CrdWdbePrt::CrdWdbePrt(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
			, const ubigint ref
			, const uint ixWdbeVPreset
			, const ubigint preUref
		) :
			JobWdbe(xchg, VecWdbeVJob::CRDWDBEPRT, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	pnllist = NULL;
	pnlrec = NULL;
	pnlheadbar = NULL;

	// IP constructor.cust1 --- INSERT

	xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXPRE, jref, ixWdbeVPreset);
	if (ixWdbeVPreset != VecWdbeVPreset::VOID) xchg->addRefPreset(ixWdbeVPreset, jref, preUref);

	if ((ref + 1) != 0) xchg->triggerIxRefCall(dbswdbe, VecWdbeVCall::CALLWDBEREFPRESET, jref, VecWdbeVPreset::PREWDBEREFPRT, ref);

	// initialize according to ref
	changeRef(dbswdbe, jref, ((ref + 1) == 0) ? 0 : ref, false);

	pnllist = new PnlWdbePrtList(xchg, dbswdbe, jref, ixWdbeVLocale);
	pnlrec = new PnlWdbePrtRec(xchg, dbswdbe, jref, ixWdbeVLocale);
	pnlheadbar = new PnlWdbePrtHeadbar(xchg, dbswdbe, jref, ixWdbeVLocale);

	// IP constructor.cust2 --- INSERT

	statshr.jrefHeadbar = pnlheadbar->jref;
	statshr.jrefList = pnllist->jref;
	statshr.jrefRec = pnlrec->jref;

	set<uint> moditems;
	refresh(dbswdbe, moditems);

	changeStage(dbswdbe, VecVSge::IDLE);

	xchg->addClstn(VecWdbeVCall::CALLWDBEREFPRESET, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBESTATCHG, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEDLGCLOSE, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

CrdWdbePrt::~CrdWdbePrt() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* CrdWdbePrt::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &continf, &feedFSge, &statshr, items);
	};

	return dpcheng;
};

void CrdWdbePrt::refresh(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	ContInf oldContinf(continf);

	// IP refresh --- BEGIN
	// continf
	continf.MrlAppHlp = xchg->helpurl + "/CrdWdbePrt/" + VecWdbeVLocale::getSref(ixWdbeVLocale);
	continf.MtxCrdPrt = StubWdbe::getStubPrtStd(dbswdbe, xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFPRT, jref), ixWdbeVLocale, Stub::VecVNonetype::FULL);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	muteRefresh = false;
};

void CrdWdbePrt::changeRef(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint ref
			, const bool notif
		) {
	set<uint> moditems;

	uint ixWdbeVPreset = xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXPRE, jref);

	if (ref != 0) xchg->triggerIxRefSrefIntvalCall(dbswdbe, VecWdbeVCall::CALLWDBELOG, jref, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref), "CrdWdbePrt", ref);
	xchg->addRefPreset(VecWdbeVPreset::PREWDBEREFPRT, jref, ref);

	if (pnllist) pnllist->updatePreset(dbswdbe, VecWdbeVPreset::PREWDBEREFPRT, jrefTrig, notif);
	if (pnlrec) pnlrec->updatePreset(dbswdbe, VecWdbeVPreset::PREWDBEREFPRT, jrefTrig, notif);

	refresh(dbswdbe, moditems);
	if (notif) xchg->submitDpch(getNewDpchEng(moditems));
};

void CrdWdbePrt::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- INSERT
};

void CrdWdbePrt::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRTDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::CLOSE) {
					handleDpchAppDoClose(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITAPPABTCLICK) {
					handleDpchAppDoMitAppAbtClick(dbswdbe, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEALERT) {
			handleDpchAppWdbeAlert(dbswdbe, (DpchAppWdbeAlert*) (req->dpchapp), &(req->dpcheng));

		};
	};
};

void CrdWdbePrt::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void CrdWdbePrt::handleDpchAppDoClose(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	xchg->triggerIxCall(dbswdbe, VecWdbeVCall::CALLWDBECRDCLOSE, jref, VecWdbeVCard::CRDWDBEPRT);
};

void CrdWdbePrt::handleDpchAppDoMitAppAbtClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoMitAppAbtClick --- BEGIN
	changeStage(dbswdbe, VecVSge::ALRWDBEABT, dpcheng);
	// IP handleDpchAppDoMitAppAbtClick --- END
};

void CrdWdbePrt::handleDpchAppWdbeAlert(
			DbsWdbe* dbswdbe
			, DpchAppWdbeAlert* dpchappwdbealert
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppWdbeAlert --- BEGIN
	if (ixVSge == VecVSge::ALRWDBEABT) {
		changeStage(dbswdbe, nextIxVSgeSuccess);
	};

	*dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	// IP handleDpchAppWdbeAlert --- END
};

void CrdWdbePrt::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBEREFPRESET) {
		call->abort = handleCallWdbeRefPreSet(dbswdbe, call->jref, call->argInv.ix, call->argInv.ref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBESTATCHG) {
		call->abort = handleCallWdbeStatChg(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEDLGCLOSE) {
		call->abort = handleCallWdbeDlgClose(dbswdbe, call->jref);
	};
};

bool CrdWdbePrt::handleCallWdbeRefPreSet(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;

	if (ixInv == VecWdbeVPreset::PREWDBEREFPRT) {
		changeRef(dbswdbe, jrefTrig, refInv, true);

		if (refInv == 0) pnlrec->minimize(dbswdbe, true);
	};

	return retval;
};

bool CrdWdbePrt::handleCallWdbeStatChg(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	if (jrefTrig == pnlrec->jref) if ((pnllist->statshr.ixWdbeVExpstate == VecWdbeVExpstate::REGD) && (pnlrec->statshr.ixWdbeVExpstate == VecWdbeVExpstate::REGD)) pnllist->minimize(dbswdbe, true);
	return retval;
};

bool CrdWdbePrt::handleCallWdbeDlgClose(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWdbeDlgClose --- INSERT
	return retval;
};

void CrdWdbePrt::changeStage(
			DbsWdbe* dbswdbe
			, uint _ixVSge
			, DpchEngWdbe** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswdbe); break;
				case VecVSge::ALRWDBEABT: leaveSgeAlrwdbeabt(dbswdbe); break;
			};

			setStage(dbswdbe, _ixVSge);
			reenter = false;
			refreshWithDpchEng(dbswdbe, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswdbe, reenter); break;
			case VecVSge::ALRWDBEABT: _ixVSge = enterSgeAlrwdbeabt(dbswdbe, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string CrdWdbePrt::getSquawk(
			DbsWdbe* dbswdbe
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

uint CrdWdbePrt::enterSgeIdle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void CrdWdbePrt::leaveSgeIdle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeIdle --- INSERT
};

uint CrdWdbePrt::enterSgeAlrwdbeabt(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::ALRWDBEABT;
	nextIxVSgeSuccess = VecVSge::IDLE;

	xchg->submitDpch(AlrWdbe::prepareAlrAbt(jref, ixWdbeVLocale, feedFMcbAlert)); // IP enterSgeAlrwdbeabt --- LINE

	return retval;
};

void CrdWdbePrt::leaveSgeAlrwdbeabt(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAlrwdbeabt --- INSERT
};
