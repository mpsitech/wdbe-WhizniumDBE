/**
	* \file CrdWdbeVer.cpp
	* job handler for job CrdWdbeVer (implementation)
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

#include "CrdWdbeVer.h"

#include "CrdWdbeVer_blks.cpp"
#include "CrdWdbeVer_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class CrdWdbeVer
 ******************************************************************************/

CrdWdbeVer::CrdWdbeVer(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
			, const ubigint ref
			, const uint ixWdbeVPreset
			, const ubigint preUref
		) :
			JobWdbe(xchg, VecWdbeVJob::CRDWDBEVER, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	pnllist = NULL;
	pnlheadbar = NULL;
	pnlrec = NULL;
	dlgcmdset = NULL;
	dlgcustfst = NULL;
	dlgdflalg = NULL;
	dlgfinmod = NULL;
	dlggenfst = NULL;
	dlgmdlstr = NULL;
	dlgnew = NULL;

	// IP constructor.cust1 --- INSERT

	xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXPRE, jref, ixWdbeVPreset);
	if (ixWdbeVPreset != VecWdbeVPreset::VOID) xchg->addRefPreset(ixWdbeVPreset, jref, preUref);

	if ((ref + 1) != 0) xchg->triggerIxRefCall(dbswdbe, VecWdbeVCall::CALLWDBEREFPRESET, jref, VecWdbeVPreset::PREWDBEREFVER, ref);

	// initialize according to ref
	changeRef(dbswdbe, jref, ((ref + 1) == 0) ? 0 : ref, false);

	pnllist = new PnlWdbeVerList(xchg, dbswdbe, jref, ixWdbeVLocale);
	pnlheadbar = new PnlWdbeVerHeadbar(xchg, dbswdbe, jref, ixWdbeVLocale);
	pnlrec = new PnlWdbeVerRec(xchg, dbswdbe, jref, ixWdbeVLocale);

	// IP constructor.cust2 --- INSERT

	statshr.jrefHeadbar = pnlheadbar->jref;
	statshr.jrefList = pnllist->jref;
	statshr.jrefRec = pnlrec->jref;

	set<uint> moditems;
	refresh(dbswdbe, moditems);

	if ((ref + 1) == 0) {
		dlgnew = new DlgWdbeVerNew(xchg, dbswdbe, jref, ixWdbeVLocale);
		statshr.jrefDlgnew = dlgnew->jref;
	};

	changeStage(dbswdbe, VecVSge::IDLE);

	xchg->addClstn(VecWdbeVCall::CALLWDBEREFPRESET, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBESTATCHG, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEDLGCLOSE, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

CrdWdbeVer::~CrdWdbeVer() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* CrdWdbeVer::getNewDpchEng(
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

void CrdWdbeVer::refresh(
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
	continf.MrlAppHlp = xchg->helpurl + "/CrdWdbeVer/" + VecWdbeVLocale::getSref(ixWdbeVLocale);
	continf.MtxCrdVer = StubWdbe::getStubVerStd(dbswdbe, xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref), ixWdbeVLocale, Stub::VecVNonetype::FULL);

	// statshr
	statshr.MspCrd1Avail = evalMspCrd1Avail(dbswdbe);
	statshr.MitCrdNewAvail = evalMitCrdNewAvail(dbswdbe);
	statshr.MitCrdPcvAvail = evalMitCrdPcvAvail(dbswdbe);
	statshr.MitCrdPcvActive = evalMitCrdPcvActive(dbswdbe);
	statshr.MspCrd3Avail = evalMspCrd3Avail(dbswdbe);
	statshr.MspCrd3Active = evalMspCrd3Active(dbswdbe);
	statshr.MitCrdImdAvail = evalMitCrdImdAvail(dbswdbe);
	statshr.MitCrdImdActive = evalMitCrdImdActive(dbswdbe);
	statshr.MitCrdIcsAvail = evalMitCrdIcsAvail(dbswdbe);
	statshr.MitCrdIcsActive = evalMitCrdIcsActive(dbswdbe);
	statshr.MitCrdIdaAvail = evalMitCrdIdaAvail(dbswdbe);
	statshr.MitCrdIdaActive = evalMitCrdIdaActive(dbswdbe);
	statshr.MspCrd4Avail = evalMspCrd4Avail(dbswdbe);
	statshr.MspCrd4Active = evalMspCrd4Active(dbswdbe);
	statshr.MitCrdGfsAvail = evalMitCrdGfsAvail(dbswdbe);
	statshr.MitCrdGfsActive = evalMitCrdGfsActive(dbswdbe);
	statshr.MitCrdIfsAvail = evalMitCrdIfsAvail(dbswdbe);
	statshr.MitCrdIfsActive = evalMitCrdIfsActive(dbswdbe);
	statshr.MspCrd5Avail = evalMspCrd5Avail(dbswdbe);
	statshr.MspCrd5Active = evalMspCrd5Active(dbswdbe);
	statshr.MitCrdFnmAvail = evalMitCrdFnmAvail(dbswdbe);
	statshr.MitCrdFnmActive = evalMitCrdFnmActive(dbswdbe);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void CrdWdbeVer::changeRef(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint ref
			, const bool notif
		) {
	set<uint> moditems;

	uint ixWdbeVPreset = xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXPRE, jref);

	uint ixWdbeVRecaccess;
	xchg->triggerIxRefToIxCall(dbswdbe, VecWdbeVCall::CALLWDBERECACCESS, jref, VecWdbeVCard::CRDWDBEVER, ref, ixWdbeVRecaccess);

	if (ixWdbeVRecaccess != VecWdbeVRecaccess::NONE) {
		xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXRECACC, jref, ixWdbeVRecaccess);

		if (ref != 0) xchg->triggerIxRefSrefIntvalCall(dbswdbe, VecWdbeVCall::CALLWDBELOG, jref, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref), "CrdWdbeVer", ref);
		xchg->addRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref, ref);

		if (pnllist) pnllist->updatePreset(dbswdbe, VecWdbeVPreset::PREWDBEREFVER, jrefTrig, notif);
		if (pnlrec) pnlrec->updatePreset(dbswdbe, VecWdbeVPreset::PREWDBEREFVER, jrefTrig, notif);

		refresh(dbswdbe, moditems);
		if (notif) xchg->submitDpch(getNewDpchEng(moditems));
	};
};

void CrdWdbeVer::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- INSERT
};

void CrdWdbeVer::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVERDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::CLOSE) {
					handleDpchAppDoClose(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITAPPABTCLICK) {
					handleDpchAppDoMitAppAbtClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDNEWCLICK) {
					handleDpchAppDoMitCrdNewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDPCVCLICK) {
					handleDpchAppDoMitCrdPcvClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDIMDCLICK) {
					handleDpchAppDoMitCrdImdClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDICSCLICK) {
					handleDpchAppDoMitCrdIcsClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDIDACLICK) {
					handleDpchAppDoMitCrdIdaClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDGFSCLICK) {
					handleDpchAppDoMitCrdGfsClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDIFSCLICK) {
					handleDpchAppDoMitCrdIfsClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDFNMCLICK) {
					handleDpchAppDoMitCrdFnmClick(dbswdbe, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEALERT) {
			handleDpchAppWdbeAlert(dbswdbe, (DpchAppWdbeAlert*) (req->dpchapp), &(req->dpcheng));

		};
	};
};

void CrdWdbeVer::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void CrdWdbeVer::handleDpchAppDoClose(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	xchg->triggerIxCall(dbswdbe, VecWdbeVCall::CALLWDBECRDCLOSE, jref, VecWdbeVCard::CRDWDBEVER);
};

void CrdWdbeVer::handleDpchAppDoMitAppAbtClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoMitAppAbtClick --- BEGIN
	changeStage(dbswdbe, VecVSge::ALRWDBEABT, dpcheng);
	// IP handleDpchAppDoMitAppAbtClick --- END
};

void CrdWdbeVer::handleDpchAppDoMitCrdNewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	if (!dlgnew) {
		dlgnew = new DlgWdbeVerNew(xchg, dbswdbe, jref, ixWdbeVLocale);
		statshr.jrefDlgnew = dlgnew->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWdbeVer::handleDpchAppDoMitCrdPcvClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoMitCrdPcvClick --- IBEGIN
	changeStage(dbswdbe, VecVSge::ALRCVW, dpcheng);
	// IP handleDpchAppDoMitCrdPcvClick --- IEND
};

void CrdWdbeVer::handleDpchAppDoMitCrdImdClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	if (!dlgmdlstr) {
		dlgmdlstr = new DlgWdbeVerMdlstr(xchg, dbswdbe, jref, ixWdbeVLocale);
		statshr.jrefDlgmdlstr = dlgmdlstr->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWdbeVer::handleDpchAppDoMitCrdIcsClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	if (!dlgcmdset) {
		dlgcmdset = new DlgWdbeVerCmdset(xchg, dbswdbe, jref, ixWdbeVLocale);
		statshr.jrefDlgcmdset = dlgcmdset->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWdbeVer::handleDpchAppDoMitCrdIdaClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	if (!dlgdflalg) {
		dlgdflalg = new DlgWdbeVerDflalg(xchg, dbswdbe, jref, ixWdbeVLocale);
		statshr.jrefDlgdflalg = dlgdflalg->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWdbeVer::handleDpchAppDoMitCrdGfsClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	if (!dlggenfst) {
		dlggenfst = new DlgWdbeVerGenfst(xchg, dbswdbe, jref, ixWdbeVLocale);
		statshr.jrefDlggenfst = dlggenfst->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWdbeVer::handleDpchAppDoMitCrdIfsClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	if (!dlgcustfst) {
		dlgcustfst = new DlgWdbeVerCustfst(xchg, dbswdbe, jref, ixWdbeVLocale);
		statshr.jrefDlgcustfst = dlgcustfst->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWdbeVer::handleDpchAppDoMitCrdFnmClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	if (!dlgfinmod) {
		dlgfinmod = new DlgWdbeVerFinmod(xchg, dbswdbe, jref, ixWdbeVLocale);
		statshr.jrefDlgfinmod = dlgfinmod->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWdbeVer::handleDpchAppWdbeAlert(
			DbsWdbe* dbswdbe
			, DpchAppWdbeAlert* dpchappwdbealert
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppWdbeAlert --- RBEGIN
	if (ixVSge == VecVSge::ALRWDBEABT) {
		changeStage(dbswdbe, VecVSge::IDLE);
	} else if (ixVSge == VecVSge::ALRCVW) {
		if (feedFMcbAlert.getSrefByNum(dpchappwdbealert->numFMcb) == "yes") {
			changeStage(dbswdbe, VecVSge::SETPRJCVR);
		} else {
			changeStage(dbswdbe, VecVSge::IDLE);
		};
	};

	*dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	// IP handleDpchAppWdbeAlert --- REND
};

void CrdWdbeVer::handleCall(
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

bool CrdWdbeVer::handleCallWdbeRefPreSet(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;

	if (ixInv == VecWdbeVPreset::PREWDBEREFVER) {
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

bool CrdWdbeVer::handleCallWdbeStatChg(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	if (jrefTrig == pnlrec->jref) if ((pnllist->statshr.ixWdbeVExpstate == VecWdbeVExpstate::REGD) && (pnlrec->statshr.ixWdbeVExpstate == VecWdbeVExpstate::REGD)) pnllist->minimize(dbswdbe, true);
	return retval;
};

bool CrdWdbeVer::handleCallWdbeDlgClose(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if (dlgcmdset) {
		delete dlgcmdset;
		dlgcmdset = NULL;
		statshr.jrefDlgcmdset = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	} else if (dlgcustfst) {
		delete dlgcustfst;
		dlgcustfst = NULL;
		statshr.jrefDlgcustfst = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	} else if (dlgdflalg) {
		delete dlgdflalg;
		dlgdflalg = NULL;
		statshr.jrefDlgdflalg = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	} else if (dlgfinmod) {
		delete dlgfinmod;
		dlgfinmod = NULL;
		statshr.jrefDlgfinmod = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	} else if (dlggenfst) {
		delete dlggenfst;
		dlggenfst = NULL;
		statshr.jrefDlggenfst = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	} else if (dlgmdlstr) {
		delete dlgmdlstr;
		dlgmdlstr = NULL;
		statshr.jrefDlgmdlstr = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	} else if (dlgnew) {
		delete dlgnew;
		dlgnew = NULL;
		statshr.jrefDlgnew = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	};

	return retval;
};

void CrdWdbeVer::changeStage(
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
				case VecVSge::ALRCVW: leaveSgeAlrcvw(dbswdbe); break;
				case VecVSge::SETPRJCVR: leaveSgeSetprjcvr(dbswdbe); break;
			};

			setStage(dbswdbe, _ixVSge);
			reenter = false;
			refreshWithDpchEng(dbswdbe, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswdbe, reenter); break;
			case VecVSge::ALRWDBEABT: _ixVSge = enterSgeAlrwdbeabt(dbswdbe, reenter); break;
			case VecVSge::ALRCVW: _ixVSge = enterSgeAlrcvw(dbswdbe, reenter); break;
			case VecVSge::SETPRJCVR: _ixVSge = enterSgeSetprjcvr(dbswdbe, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string CrdWdbeVer::getSquawk(
			DbsWdbe* dbswdbe
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

uint CrdWdbeVer::enterSgeIdle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void CrdWdbeVer::leaveSgeIdle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeIdle --- INSERT
};

uint CrdWdbeVer::enterSgeAlrwdbeabt(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::ALRWDBEABT;
	nextIxVSgeSuccess = VecVSge::IDLE;

	xchg->submitDpch(AlrWdbe::prepareAlrAbt(jref, ixWdbeVLocale, feedFMcbAlert)); // IP enterSgeAlrwdbeabt --- LINE

	return retval;
};

void CrdWdbeVer::leaveSgeAlrwdbeabt(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAlrwdbeabt --- INSERT
};

uint CrdWdbeVer::enterSgeAlrcvw(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::ALRCVW;
	nextIxVSgeSuccess = VecVSge::IDLE;

	ContInfWdbeAlert continf;
	// IP enterSgeAlrcvw --- BEGIN
	continf.TxtCpt = VecWdbeVTag::getTitle(VecWdbeVTag::WARNING, ixWdbeVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		continf.TxtMsg1 = "Manual repository adjustments may be required.";
		continf.TxtMsg2 = "Proceed anyway?";
	};

	feedFMcbAlert.clear();

	VecWdbeVTag::appendToFeed(VecWdbeVTag::YES, ixWdbeVLocale, feedFMcbAlert);
	VecWdbeVTag::appendToFeed(VecWdbeVTag::NO, ixWdbeVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
	// IP enterSgeAlrcvw --- END
	xchg->submitDpch(new DpchEngWdbeAlert(jref, &continf, &feedFMcbAlert, {DpchEngWdbeAlert::ALL}));

	return retval;
};

void CrdWdbeVer::leaveSgeAlrcvw(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAlrcvw --- INSERT
};

uint CrdWdbeVer::enterSgeSetprjcvr(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::IDLE;
	retval = nextIxVSgeSuccess;

	// IP enterSgeSetprjcvr --- IBEGIN
	WdbeMVersion* ver = NULL;

	if (dbswdbe->tblwdbemversion->loadRecByRef(xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref), &ver)) {
		if (ver->ixVState == VecWdbeVMVersionState::ABANDON) Wdbe::updateVerste(dbswdbe, ver->ref, VecWdbeVMVersionState::READY);

		dbswdbe->executeQuery("UPDATE TblWdbeMProject SET refWdbeMVersion = " + to_string(ver->ref) + " WHERE ref = " + to_string(ver->prjRefWdbeMProject));
		xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBEPRJMOD, jref);

		delete ver;
	};
	// IP enterSgeSetprjcvr --- IEND

	return retval;
};

void CrdWdbeVer::leaveSgeSetprjcvr(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeSetprjcvr --- INSERT
};
