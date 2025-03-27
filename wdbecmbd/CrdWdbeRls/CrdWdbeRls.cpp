/**
	* \file CrdWdbeRls.cpp
	* job handler for job CrdWdbeRls (implementation)
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

#include "CrdWdbeRls.h"

#include "CrdWdbeRls_blks.cpp"
#include "CrdWdbeRls_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class CrdWdbeRls
 ******************************************************************************/

CrdWdbeRls::CrdWdbeRls(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
			, const ubigint ref
			, const uint ixWdbeVPreset
			, const ubigint preUref
		) :
			JobWdbe(xchg, VecWdbeVJob::CRDWDBERLS, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	pnllist = NULL;
	pnlheadbar = NULL;
	pnlrec = NULL;
	dlgfinreptr = NULL;
	dlgstareptr = NULL;
	dlgwrite = NULL;

	// IP constructor.cust1 --- INSERT

	xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXPRE, jref, ixWdbeVPreset);
	if (ixWdbeVPreset != VecWdbeVPreset::VOID) xchg->addRefPreset(ixWdbeVPreset, jref, preUref);

	if ((ref + 1) != 0) xchg->triggerIxRefCall(dbswdbe, VecWdbeVCall::CALLWDBEREFPRESET, jref, VecWdbeVPreset::PREWDBEREFRLS, ref);

	// initialize according to ref
	changeRef(dbswdbe, jref, ((ref + 1) == 0) ? 0 : ref, false);

	pnllist = new PnlWdbeRlsList(xchg, dbswdbe, jref, ixWdbeVLocale);
	pnlheadbar = new PnlWdbeRlsHeadbar(xchg, dbswdbe, jref, ixWdbeVLocale);
	pnlrec = new PnlWdbeRlsRec(xchg, dbswdbe, jref, ixWdbeVLocale);

	// IP constructor.cust2 --- INSERT

	statshr.jrefHeadbar = pnlheadbar->jref;
	statshr.jrefList = pnllist->jref;
	statshr.jrefRec = pnlrec->jref;

	set<uint> moditems;
	refresh(dbswdbe, moditems);

	changeStage(dbswdbe, VecVSge::IDLE);

	xchg->addClstn(VecWdbeVCall::CALLWDBEREPTRSTOP, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEREPTRSTART, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEREFPRESET, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBESTATCHG, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEDLGCLOSE, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

CrdWdbeRls::~CrdWdbeRls() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* CrdWdbeRls::getNewDpchEng(
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

void CrdWdbeRls::refresh(
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
	continf.MrlAppHlp = xchg->helpurl + "/CrdWdbeRls/" + VecWdbeVLocale::getSref(ixWdbeVLocale);
	continf.MtxCrdRls = StubWdbe::getStubRlsStd(dbswdbe, xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFRLS, jref), ixWdbeVLocale, Stub::VecVNonetype::FULL);

	// statshr
	statshr.MspCrd1Avail = evalMspCrd1Avail(dbswdbe);
	statshr.MitCrdSrtAvail = evalMitCrdSrtAvail(dbswdbe);
	statshr.MitCrdSrtActive = evalMitCrdSrtActive(dbswdbe);
	statshr.MitCrdCrtAvail = evalMitCrdCrtAvail(dbswdbe);
	statshr.MitCrdCrtActive = evalMitCrdCrtActive(dbswdbe);
	statshr.MitCrdFrtAvail = evalMitCrdFrtAvail(dbswdbe);
	statshr.MitCrdFrtActive = evalMitCrdFrtActive(dbswdbe);
	statshr.MitCrdWcoAvail = evalMitCrdWcoAvail(dbswdbe);
	statshr.MitCrdWcoActive = evalMitCrdWcoActive(dbswdbe);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void CrdWdbeRls::changeRef(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint ref
			, const bool notif
		) {
	set<uint> moditems;

	uint ixWdbeVPreset = xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXPRE, jref);

	if (ref != 0) xchg->triggerIxRefSrefIntvalCall(dbswdbe, VecWdbeVCall::CALLWDBELOG, jref, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref), "CrdWdbeRls", ref);
	xchg->addRefPreset(VecWdbeVPreset::PREWDBEREFRLS, jref, ref);

	if (pnllist) pnllist->updatePreset(dbswdbe, VecWdbeVPreset::PREWDBEREFRLS, jrefTrig, notif);
	if (pnlrec) pnlrec->updatePreset(dbswdbe, VecWdbeVPreset::PREWDBEREFRLS, jrefTrig, notif);

	refresh(dbswdbe, moditems);
	if (notif) xchg->submitDpch(getNewDpchEng(moditems));
};

void CrdWdbeRls::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- INSERT
};

void CrdWdbeRls::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBERLSDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::CLOSE) {
					handleDpchAppDoClose(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITAPPABTCLICK) {
					handleDpchAppDoMitAppAbtClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDSRTCLICK) {
					handleDpchAppDoMitCrdSrtClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDCRTCLICK) {
					handleDpchAppDoMitCrdCrtClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDFRTCLICK) {
					handleDpchAppDoMitCrdFrtClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDWCOCLICK) {
					handleDpchAppDoMitCrdWcoClick(dbswdbe, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEALERT) {
			handleDpchAppWdbeAlert(dbswdbe, (DpchAppWdbeAlert*) (req->dpchapp), &(req->dpcheng));

		};
	};
};

void CrdWdbeRls::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void CrdWdbeRls::handleDpchAppDoClose(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	xchg->triggerIxCall(dbswdbe, VecWdbeVCall::CALLWDBECRDCLOSE, jref, VecWdbeVCard::CRDWDBERLS);
};

void CrdWdbeRls::handleDpchAppDoMitAppAbtClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoMitAppAbtClick --- BEGIN
	changeStage(dbswdbe, VecVSge::ALRWDBEABT, dpcheng);
	// IP handleDpchAppDoMitAppAbtClick --- END
};

void CrdWdbeRls::handleDpchAppDoMitCrdSrtClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	if (!dlgstareptr) {
		dlgstareptr = new DlgWdbeRlsStareptr(xchg, dbswdbe, jref, ixWdbeVLocale);
		statshr.jrefDlgstareptr = dlgstareptr->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWdbeRls::handleDpchAppDoMitCrdCrtClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoMitCrdCrtClick --- IBEGIN
	set<uint> moditems;

	xchg->removePreset(VecWdbeVPreset::PREWDBEIXBASEREPTYPE, jref);
	xchg->removePreset(VecWdbeVPreset::PREWDBEGITURL, jref);
	xchg->removePreset(VecWdbeVPreset::PREWDBEREPFOLDER, jref);
	xchg->removePreset(VecWdbeVPreset::PREWDBEEXTFOLDER, jref);

	refresh(dbswdbe, moditems);
	*dpcheng = getNewDpchEng(moditems);
	// IP handleDpchAppDoMitCrdCrtClick --- IEND
};

void CrdWdbeRls::handleDpchAppDoMitCrdFrtClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	if (!dlgfinreptr) {
		dlgfinreptr = new DlgWdbeRlsFinreptr(xchg, dbswdbe, jref, ixWdbeVLocale);
		statshr.jrefDlgfinreptr = dlgfinreptr->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWdbeRls::handleDpchAppDoMitCrdWcoClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	if (!dlgwrite) {
		dlgwrite = new DlgWdbeRlsWrite(xchg, dbswdbe, jref, ixWdbeVLocale);
		statshr.jrefDlgwrite = dlgwrite->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWdbeRls::handleDpchAppWdbeAlert(
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

void CrdWdbeRls::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBEREPTRSTOP) {
		call->abort = handleCallWdbeReptrStop(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEREPTRSTART) {
		call->abort = handleCallWdbeReptrStart(dbswdbe, call->jref, call->argInv.ix, call->argInv.txtval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEREFPRESET) {
		call->abort = handleCallWdbeRefPreSet(dbswdbe, call->jref, call->argInv.ix, call->argInv.ref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBESTATCHG) {
		call->abort = handleCallWdbeStatChg(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEDLGCLOSE) {
		call->abort = handleCallWdbeDlgClose(dbswdbe, call->jref);
	};
};

bool CrdWdbeRls::handleCallWdbeReptrStop(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWdbeReptrStop --- IBEGIN

	xchg->removePreset(VecWdbeVPreset::PREWDBEIXBASEREPTYPE, jref);
	xchg->removePreset(VecWdbeVPreset::PREWDBEGITURL, jref);
	xchg->removePreset(VecWdbeVPreset::PREWDBEREPFOLDER, jref);
	xchg->removePreset(VecWdbeVPreset::PREWDBEEXTFOLDER, jref);

	if (!muteRefresh) refreshWithDpchEng(dbswdbe);

	// IP handleCallWdbeReptrStop --- IEND
	return retval;
};

bool CrdWdbeRls::handleCallWdbeReptrStart(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, const string& txtvalInv
		) {
	bool retval = false;
	// IP handleCallWdbeReptrStart --- IBEGIN

	xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXBASEREPTYPE, jref, ixInv);
	if (txtvalInv != "") xchg->addTxtvalPreset(VecWdbeVPreset::PREWDBEGITURL, jref, txtvalInv);

	// generate source code base folders
	xchg->addTxtvalPreset(VecWdbeVPreset::PREWDBEREPFOLDER, jref, Tmp::newfolder(xchg->tmppath));
	if (ixInv != VecWdbeVBasereptype::VOID) xchg->addTxtvalPreset(VecWdbeVPreset::PREWDBEEXTFOLDER, jref, Tmp::newfolder(xchg->tmppath));

	if (!muteRefresh) refreshWithDpchEng(dbswdbe);

	// IP handleCallWdbeReptrStart --- IEND
	return retval;
};

bool CrdWdbeRls::handleCallWdbeRefPreSet(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;

	if (ixInv == VecWdbeVPreset::PREWDBEREFRLS) {
		changeRef(dbswdbe, jrefTrig, refInv, true);

		if (refInv == 0) pnlrec->minimize(dbswdbe, true);
	};

	return retval;
};

bool CrdWdbeRls::handleCallWdbeStatChg(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	if (jrefTrig == pnlrec->jref) if ((pnllist->statshr.ixWdbeVExpstate == VecWdbeVExpstate::REGD) && (pnlrec->statshr.ixWdbeVExpstate == VecWdbeVExpstate::REGD)) pnllist->minimize(dbswdbe, true);
	return retval;
};

bool CrdWdbeRls::handleCallWdbeDlgClose(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if (dlgfinreptr) {
		delete dlgfinreptr;
		dlgfinreptr = NULL;
		statshr.jrefDlgfinreptr = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	} else if (dlgstareptr) {
		delete dlgstareptr;
		dlgstareptr = NULL;
		statshr.jrefDlgstareptr = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	} else if (dlgwrite) {
		delete dlgwrite;
		dlgwrite = NULL;
		statshr.jrefDlgwrite = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	};

	return retval;
};

void CrdWdbeRls::changeStage(
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

string CrdWdbeRls::getSquawk(
			DbsWdbe* dbswdbe
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

uint CrdWdbeRls::enterSgeIdle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void CrdWdbeRls::leaveSgeIdle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeIdle --- INSERT
};

uint CrdWdbeRls::enterSgeAlrwdbeabt(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::ALRWDBEABT;
	nextIxVSgeSuccess = VecVSge::IDLE;

	xchg->submitDpch(AlrWdbe::prepareAlrAbt(jref, ixWdbeVLocale, feedFMcbAlert)); // IP enterSgeAlrwdbeabt --- LINE

	return retval;
};

void CrdWdbeRls::leaveSgeAlrwdbeabt(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAlrwdbeabt --- INSERT
};
