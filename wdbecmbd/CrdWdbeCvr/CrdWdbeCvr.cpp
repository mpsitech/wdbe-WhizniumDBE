/**
	* \file CrdWdbeCvr.cpp
	* job handler for job CrdWdbeCvr (implementation)
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

#include "CrdWdbeCvr.h"

#include "CrdWdbeCvr_blks.cpp"
#include "CrdWdbeCvr_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class CrdWdbeCvr
 ******************************************************************************/

CrdWdbeCvr::CrdWdbeCvr(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
			, const ubigint ref
			, const uint ixWdbeVPreset
			, const ubigint preUref
		) :
			JobWdbe(xchg, VecWdbeVJob::CRDWDBECVR, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	pnllist = NULL;
	pnlheadbar = NULL;
	pnlrec = NULL;
	dlgwrite = NULL;
	dlgdetcd = NULL;
	dlgnew = NULL;
	dlgbsccd = NULL;

	// IP constructor.cust1 --- INSERT

	xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXPRE, jref, ixWdbeVPreset);
	if (ixWdbeVPreset != VecWdbeVPreset::VOID) xchg->addRefPreset(ixWdbeVPreset, jref, preUref);

	if ((ref + 1) != 0) xchg->triggerIxRefCall(dbswdbe, VecWdbeVCall::CALLWDBEREFPRESET, jref, VecWdbeVPreset::PREWDBEREFCVR, ref);

	// initialize according to ref
	changeRef(dbswdbe, jref, ((ref + 1) == 0) ? 0 : ref, false);

	pnllist = new PnlWdbeCvrList(xchg, dbswdbe, jref, ixWdbeVLocale);
	pnlheadbar = new PnlWdbeCvrHeadbar(xchg, dbswdbe, jref, ixWdbeVLocale);
	pnlrec = new PnlWdbeCvrRec(xchg, dbswdbe, jref, ixWdbeVLocale);

	// IP constructor.cust2 --- INSERT

	statshr.jrefHeadbar = pnlheadbar->jref;
	statshr.jrefList = pnllist->jref;
	statshr.jrefRec = pnlrec->jref;

	set<uint> moditems;
	refresh(dbswdbe, moditems);

	if ((ref + 1) == 0) {
		dlgnew = new DlgWdbeCvrNew(xchg, dbswdbe, jref, ixWdbeVLocale);
		statshr.jrefDlgnew = dlgnew->jref;
	};

	changeStage(dbswdbe, VecVSge::IDLE);

	xchg->addClstn(VecWdbeVCall::CALLWDBEREFPRESET, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBESTATCHG, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEDLGCLOSE, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

CrdWdbeCvr::~CrdWdbeCvr() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* CrdWdbeCvr::getNewDpchEng(
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

void CrdWdbeCvr::refresh(
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
	continf.MrlAppHlp = xchg->helpurl + "/CrdWdbeCvr/" + VecWdbeVLocale::getSref(ixWdbeVLocale);
	continf.MtxCrdCvr = StubWdbe::getStubCvrStd(dbswdbe, xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCVR, jref), ixWdbeVLocale, Stub::VecVNonetype::FULL);

	// statshr
	statshr.MspCrd1Avail = evalMspCrd1Avail(dbswdbe);
	statshr.MitCrdNewAvail = evalMitCrdNewAvail(dbswdbe);
	statshr.MitCrdIbsAvail = evalMitCrdIbsAvail(dbswdbe);
	statshr.MitCrdIbsActive = evalMitCrdIbsActive(dbswdbe);
	statshr.MitCrdIdsAvail = evalMitCrdIdsAvail(dbswdbe);
	statshr.MitCrdIdsActive = evalMitCrdIdsActive(dbswdbe);
	statshr.MspCrd2Avail = evalMspCrd2Avail(dbswdbe);
	statshr.MitCrdWcoAvail = evalMitCrdWcoAvail(dbswdbe);
	statshr.MitCrdWcoActive = evalMitCrdWcoActive(dbswdbe);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void CrdWdbeCvr::changeRef(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint ref
			, const bool notif
		) {
	set<uint> moditems;

	uint ixWdbeVPreset = xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXPRE, jref);

	uint ixWdbeVRecaccess;
	xchg->triggerIxRefToIxCall(dbswdbe, VecWdbeVCall::CALLWDBERECACCESS, jref, VecWdbeVCard::CRDWDBECVR, ref, ixWdbeVRecaccess);

	if (ixWdbeVRecaccess != VecWdbeVRecaccess::NONE) {
		xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXRECACC, jref, ixWdbeVRecaccess);

		if (ref != 0) xchg->triggerIxRefSrefIntvalCall(dbswdbe, VecWdbeVCall::CALLWDBELOG, jref, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref), "CrdWdbeCvr", ref);
		xchg->addRefPreset(VecWdbeVPreset::PREWDBEREFCVR, jref, ref);

		if (pnllist) pnllist->updatePreset(dbswdbe, VecWdbeVPreset::PREWDBEREFCVR, jrefTrig, notif);
		if (pnlrec) pnlrec->updatePreset(dbswdbe, VecWdbeVPreset::PREWDBEREFCVR, jrefTrig, notif);

		refresh(dbswdbe, moditems);
		if (notif) xchg->submitDpch(getNewDpchEng(moditems));
	};
};

void CrdWdbeCvr::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- INSERT
};

void CrdWdbeCvr::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECVRDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::CLOSE) {
					handleDpchAppDoClose(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITAPPABTCLICK) {
					handleDpchAppDoMitAppAbtClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDNEWCLICK) {
					handleDpchAppDoMitCrdNewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDIBSCLICK) {
					handleDpchAppDoMitCrdIbsClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDIDSCLICK) {
					handleDpchAppDoMitCrdIdsClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDWCOCLICK) {
					handleDpchAppDoMitCrdWcoClick(dbswdbe, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEALERT) {
			handleDpchAppWdbeAlert(dbswdbe, (DpchAppWdbeAlert*) (req->dpchapp), &(req->dpcheng));

		};
	};
};

void CrdWdbeCvr::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void CrdWdbeCvr::handleDpchAppDoClose(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	xchg->triggerIxCall(dbswdbe, VecWdbeVCall::CALLWDBECRDCLOSE, jref, VecWdbeVCard::CRDWDBECVR);
};

void CrdWdbeCvr::handleDpchAppDoMitAppAbtClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoMitAppAbtClick --- BEGIN
	changeStage(dbswdbe, VecVSge::ALRWDBEABT, dpcheng);
	// IP handleDpchAppDoMitAppAbtClick --- END
};

void CrdWdbeCvr::handleDpchAppDoMitCrdNewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	if (!dlgnew) {
		dlgnew = new DlgWdbeCvrNew(xchg, dbswdbe, jref, ixWdbeVLocale);
		statshr.jrefDlgnew = dlgnew->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWdbeCvr::handleDpchAppDoMitCrdIbsClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	if (!dlgbsccd) {
		dlgbsccd = new DlgWdbeCvrBsccd(xchg, dbswdbe, jref, ixWdbeVLocale);
		statshr.jrefDlgbsccd = dlgbsccd->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWdbeCvr::handleDpchAppDoMitCrdIdsClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	if (!dlgdetcd) {
		dlgdetcd = new DlgWdbeCvrDetcd(xchg, dbswdbe, jref, ixWdbeVLocale);
		statshr.jrefDlgdetcd = dlgdetcd->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWdbeCvr::handleDpchAppDoMitCrdWcoClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	if (!dlgwrite) {
		dlgwrite = new DlgWdbeCvrWrite(xchg, dbswdbe, jref, ixWdbeVLocale);
		statshr.jrefDlgwrite = dlgwrite->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWdbeCvr::handleDpchAppWdbeAlert(
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

void CrdWdbeCvr::handleCall(
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

bool CrdWdbeCvr::handleCallWdbeRefPreSet(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;

	if (ixInv == VecWdbeVPreset::PREWDBEREFCVR) {
		changeRef(dbswdbe, jrefTrig, refInv, true);

		if (refInv == 0) pnlrec->minimize(dbswdbe, true);
		else if ((jrefTrig == statshr.jrefDlgnew) && (refInv != 0)) {
			pnllist->qry->rerun(dbswdbe, true);
			pnllist->minimize(dbswdbe, true);
			pnlrec->regularize(dbswdbe, true);
		};
	};

	return retval;
};

bool CrdWdbeCvr::handleCallWdbeStatChg(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	if (jrefTrig == pnlrec->jref) if ((pnllist->statshr.ixWdbeVExpstate == VecWdbeVExpstate::REGD) && (pnlrec->statshr.ixWdbeVExpstate == VecWdbeVExpstate::REGD)) pnllist->minimize(dbswdbe, true);
	return retval;
};

bool CrdWdbeCvr::handleCallWdbeDlgClose(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if (dlgbsccd) {
		delete dlgbsccd;
		dlgbsccd = NULL;
		statshr.jrefDlgbsccd = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	} else if (dlgdetcd) {
		delete dlgdetcd;
		dlgdetcd = NULL;
		statshr.jrefDlgdetcd = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	} else if (dlgnew) {
		delete dlgnew;
		dlgnew = NULL;
		statshr.jrefDlgnew = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	} else if (dlgwrite) {
		delete dlgwrite;
		dlgwrite = NULL;
		statshr.jrefDlgwrite = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	};

	return retval;
};

void CrdWdbeCvr::changeStage(
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

string CrdWdbeCvr::getSquawk(
			DbsWdbe* dbswdbe
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

uint CrdWdbeCvr::enterSgeIdle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void CrdWdbeCvr::leaveSgeIdle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeIdle --- INSERT
};

uint CrdWdbeCvr::enterSgeAlrwdbeabt(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::ALRWDBEABT;
	nextIxVSgeSuccess = VecVSge::IDLE;

	xchg->submitDpch(AlrWdbe::prepareAlrAbt(jref, ixWdbeVLocale, feedFMcbAlert)); // IP enterSgeAlrwdbeabt --- LINE

	return retval;
};

void CrdWdbeCvr::leaveSgeAlrwdbeabt(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAlrwdbeabt --- INSERT
};



