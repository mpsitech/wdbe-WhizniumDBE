/**
	* \file CrdWdbeCmd.cpp
	* job handler for job CrdWdbeCmd (implementation)
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

#include "CrdWdbeCmd.h"

#include "CrdWdbeCmd_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class CrdWdbeCmd
 ******************************************************************************/

CrdWdbeCmd::CrdWdbeCmd(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
			, const ubigint ref
			, const uint ixWdbeVPreset
			, const ubigint preUref
		) :
			JobWdbe(xchg, VecWdbeVJob::CRDWDBECMD, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	pnlrec = NULL;
	pnlheadbar = NULL;
	pnllist = NULL;

	// IP constructor.cust1 --- INSERT

	xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXPRE, jref, ixWdbeVPreset);
	if (ixWdbeVPreset != VecWdbeVPreset::VOID) xchg->addRefPreset(ixWdbeVPreset, jref, preUref);

	if ((ref + 1) != 0) xchg->triggerIxRefCall(dbswdbe, VecWdbeVCall::CALLWDBEREFPRESET, jref, VecWdbeVPreset::PREWDBEREFCMD, ref);

	// initialize according to ref
	changeRef(dbswdbe, jref, ((ref + 1) == 0) ? 0 : ref, false);

	pnlrec = new PnlWdbeCmdRec(xchg, dbswdbe, jref, ixWdbeVLocale);
	pnlheadbar = new PnlWdbeCmdHeadbar(xchg, dbswdbe, jref, ixWdbeVLocale);
	pnllist = new PnlWdbeCmdList(xchg, dbswdbe, jref, ixWdbeVLocale);

	// IP constructor.cust2 --- INSERT

	statshr.jrefHeadbar = pnlheadbar->jref;
	statshr.jrefList = pnllist->jref;
	statshr.jrefRec = pnlrec->jref;

	set<uint> moditems;
	refresh(dbswdbe, moditems);

	changeStage(dbswdbe, VecVSge::IDLE);

	xchg->addClstn(VecWdbeVCall::CALLWDBEDLGCLOSE, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBESTATCHG, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEREFPRESET, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

CrdWdbeCmd::~CrdWdbeCmd() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* CrdWdbeCmd::getNewDpchEng(
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

void CrdWdbeCmd::refresh(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	ContInf oldContinf(continf);

	// IP refresh --- BEGIN
	// continf
	continf.MrlAppHlp = xchg->helpurl + "/CrdWdbeCmd/" + VecWdbeVLocale::getSref(ixWdbeVLocale);
	continf.MtxCrdCmd = StubWdbe::getStubCmdStd(dbswdbe, xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCMD, jref), ixWdbeVLocale, Stub::VecVNonetype::FULL);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	muteRefresh = false;
};

void CrdWdbeCmd::changeRef(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint ref
			, const bool notif
		) {
	set<uint> moditems;

	uint ixWdbeVPreset = xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXPRE, jref);

	if (ref != 0) xchg->triggerIxRefSrefIntvalCall(dbswdbe, VecWdbeVCall::CALLWDBELOG, jref, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref), "CrdWdbeCmd", ref);
	xchg->addRefPreset(VecWdbeVPreset::PREWDBEREFCMD, jref, ref);

	if (pnllist) pnllist->updatePreset(dbswdbe, VecWdbeVPreset::PREWDBEREFCMD, jrefTrig, notif);
	if (pnlrec) pnlrec->updatePreset(dbswdbe, VecWdbeVPreset::PREWDBEREFCMD, jrefTrig, notif);

	refresh(dbswdbe, moditems);
	if (notif) xchg->submitDpch(getNewDpchEng(moditems));
};

void CrdWdbeCmd::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- INSERT
};

void CrdWdbeCmd::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMDDO) {
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

void CrdWdbeCmd::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void CrdWdbeCmd::handleDpchAppDoClose(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	xchg->triggerIxCall(dbswdbe, VecWdbeVCall::CALLWDBECRDCLOSE, jref, VecWdbeVCard::CRDWDBECMD);
};

void CrdWdbeCmd::handleDpchAppDoMitAppAbtClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoMitAppAbtClick --- BEGIN
	changeStage(dbswdbe, VecVSge::ALRWDBEABT, dpcheng);
	// IP handleDpchAppDoMitAppAbtClick --- END
};

void CrdWdbeCmd::handleDpchAppWdbeAlert(
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

void CrdWdbeCmd::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBEDLGCLOSE) {
		call->abort = handleCallWdbeDlgClose(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBESTATCHG) {
		call->abort = handleCallWdbeStatChg(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEREFPRESET) {
		call->abort = handleCallWdbeRefPreSet(dbswdbe, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool CrdWdbeCmd::handleCallWdbeDlgClose(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWdbeDlgClose --- INSERT
	return retval;
};

bool CrdWdbeCmd::handleCallWdbeStatChg(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	if (jrefTrig == pnlrec->jref) if ((pnllist->statshr.ixWdbeVExpstate == VecWdbeVExpstate::REGD) && (pnlrec->statshr.ixWdbeVExpstate == VecWdbeVExpstate::REGD)) pnllist->minimize(dbswdbe, true);
	return retval;
};

bool CrdWdbeCmd::handleCallWdbeRefPreSet(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;

	if (ixInv == VecWdbeVPreset::PREWDBEREFCMD) {
		changeRef(dbswdbe, jrefTrig, refInv, true);

		if (refInv == 0) pnlrec->minimize(dbswdbe, true);
	};

	return retval;
};

void CrdWdbeCmd::changeStage(
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

string CrdWdbeCmd::getSquawk(
			DbsWdbe* dbswdbe
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

uint CrdWdbeCmd::enterSgeIdle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void CrdWdbeCmd::leaveSgeIdle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeIdle --- INSERT
};

uint CrdWdbeCmd::enterSgeAlrwdbeabt(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::ALRWDBEABT;
	nextIxVSgeSuccess = VecVSge::IDLE;

	xchg->submitDpch(AlrWdbe::prepareAlrAbt(jref, ixWdbeVLocale, feedFMcbAlert)); // IP enterSgeAlrwdbeabt --- LINE

	return retval;
};

void CrdWdbeCmd::leaveSgeAlrwdbeabt(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAlrwdbeabt --- INSERT
};
