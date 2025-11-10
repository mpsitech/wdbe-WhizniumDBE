/**
	* \file PnlWdbeCdcDetail.cpp
	* job handler for job PnlWdbeCdcDetail (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 9 May 2023
	*/
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbed.h>
#endif

#include "PnlWdbeCdcDetail.h"

#include "PnlWdbeCdcDetail_blks.cpp"
#include "PnlWdbeCdcDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWdbeCdcDetail
 ******************************************************************************/

PnlWdbeCdcDetail::PnlWdbeCdcDetail(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::PNLWDBECDCDETAIL, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWdbeVCall::CALLWDBECDC_MDLEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswdbe, VecWdbeVPreset::PREWDBEREFCDC, jref);
};

PnlWdbeCdcDetail::~PnlWdbeCdcDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* PnlWdbeCdcDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &statshr, items);
	};

	return dpcheng;
};

void PnlWdbeCdcDetail::refreshTxtFck(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refreshTxtFck --- BEGIN
	ubigint refSig = 0;

	dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMSignal WHERE sref = '" + contiac.TxfFck + "'", refSig);

	continf.TxtFck = StubWdbe::getStubSigStd(dbswdbe, refSig, ixWdbeVLocale);

	statshr.TxfFckValid = (refSig != 0);
	statshr.TxtFckActive = evalTxtFckActive(dbswdbe);
	statshr.ButFckViewAvail = evalButFckViewAvail(dbswdbe);
	// IP refreshTxtFck --- END

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeCdcDetail::refreshTxtSck(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refreshTxtSck --- BEGIN
	ubigint refSig = 0;

	dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMSignal WHERE sref = '" + contiac.TxfSck + "'", refSig);

	continf.TxtSck = StubWdbe::getStubSigStd(dbswdbe, refSig, ixWdbeVLocale);

	statshr.TxfSckValid = (refSig != 0);
	statshr.TxtSckActive = evalTxtSckActive(dbswdbe);
	statshr.ButSckViewAvail = evalButSckViewAvail(dbswdbe);
	// IP refreshTxtSck --- END

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeCdcDetail::refreshTxtFar(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refreshTxtFar --- BEGIN
	ubigint refSig = 0;

	dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMSignal WHERE sref = '" + contiac.TxfFar + "'", refSig);

	continf.TxtFar = StubWdbe::getStubSigStd(dbswdbe, refSig, ixWdbeVLocale);

	statshr.TxfFarValid = (refSig != 0);
	statshr.TxtFarActive = evalTxtFarActive(dbswdbe);
	statshr.ButFarViewAvail = evalButFarViewAvail(dbswdbe);
	// IP refreshTxtFar --- END

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeCdcDetail::refreshTxtSar(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refreshTxtSar --- BEGIN
	ubigint refSig = 0;

	dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMSignal WHERE sref = '" + contiac.TxfSar + "'", refSig);

	continf.TxtSar = StubWdbe::getStubSigStd(dbswdbe, refSig, ixWdbeVLocale);

	statshr.TxfSarValid = (refSig != 0);
	statshr.TxtSarActive = evalTxtSarActive(dbswdbe);
	statshr.ButSarViewAvail = evalButSarViewAvail(dbswdbe);
	// IP refreshTxtSar --- END

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeCdcDetail::refreshRecCdc(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WdbeMCdc* _recCdc = NULL;

	if (dbswdbe->tblwdbemcdc->loadRecByRef(recCdc.ref, &_recCdc)) {
		recCdc = *_recCdc;
		delete _recCdc;
	} else recCdc = WdbeMCdc();

	dirty = false;

	contiac.TxfFck = recCdc.fckSrefWdbeMSignal;
	contiac.TxfSck = recCdc.sckSrefWdbeMSignal;
	continf.TxtMdl = StubWdbe::getStubMdlStd(dbswdbe, recCdc.refWdbeMModule, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfFar = recCdc.farSrefWdbeMSignal;
	contiac.TxfSar = recCdc.sarSrefWdbeMSignal;
	contiac.TxfRat = to_string(recCdc.Ratio);

	statshr.TxtMdlActive = evalTxtMdlActive(dbswdbe);
	statshr.ButMdlViewAvail = evalButMdlViewAvail(dbswdbe);
	statshr.ButMdlViewActive = evalButMdlViewActive(dbswdbe);
	statshr.TxfRatActive = evalTxfRatActive(dbswdbe);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshTxtFck(dbswdbe, moditems);
	refreshTxtSck(dbswdbe, moditems);
	refreshTxtFar(dbswdbe, moditems);
	refreshTxtSar(dbswdbe, moditems);

};

void PnlWdbeCdcDetail::refresh(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// statshr
	statshr.ButSaveAvail = evalButSaveAvail(dbswdbe);
	statshr.ButSaveActive = evalButSaveActive(dbswdbe);
	// IP refresh --- END

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWdbeCdcDetail::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFCDC) {
		recCdc.ref = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCDC, jref);
		refreshRecCdc(dbswdbe, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWdbeCdcDetail::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECDCDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswdbe, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECDCDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFCKVIEWCLICK) {
					handleDpchAppDoButFckViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSCKVIEWCLICK) {
					handleDpchAppDoButSckViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTMDLVIEWCLICK) {
					handleDpchAppDoButMdlViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFARVIEWCLICK) {
					handleDpchAppDoButFarViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSARVIEWCLICK) {
					handleDpchAppDoButSarViewClick(dbswdbe, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWdbeCdcDetail::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWdbeCdcDetail::handleDpchAppDataContiac(
			DbsWdbe* dbswdbe
			, ContIac* _contiac
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFRAT})) {
		if (has(diffitems, ContIac::TXFRAT)) contiac.TxfRat = _contiac->TxfRat;
	};

	if (has(diffitems, ContIac::TXFFCK)) {
		contiac.TxfFck = _contiac->TxfFck;
		refreshTxtFck(dbswdbe, moditems);
		refresh(dbswdbe, moditems);
	};

	if (has(diffitems, ContIac::TXFSCK)) {
		contiac.TxfSck = _contiac->TxfSck;
		refreshTxtSck(dbswdbe, moditems);
		refresh(dbswdbe, moditems);
	};

	if (has(diffitems, ContIac::TXFFAR)) {
		contiac.TxfFar = _contiac->TxfFar;
		refreshTxtFar(dbswdbe, moditems);
		refresh(dbswdbe, moditems);
	};

	if (has(diffitems, ContIac::TXFSAR)) {
		contiac.TxfSar = _contiac->TxfSar;
		refreshTxtSar(dbswdbe, moditems);
		refresh(dbswdbe, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWdbeCdcDetail::handleDpchAppDoButSaveClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWdbeCdcDetail::handleDpchAppDoButFckViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButFckViewClick --- INSERT
};

void PnlWdbeCdcDetail::handleDpchAppDoButSckViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButSckViewClick --- INSERT
};

void PnlWdbeCdcDetail::handleDpchAppDoButMdlViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	ubigint refCvr = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCVR, jref);
	ubigint refUnt = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref);

	if (statshr.ButMdlViewAvail && statshr.ButMdlViewActive) {
		if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref)) if (refUnt != 0) {
			sref = "CrdWdbeMod";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, VecWdbeVPreset::PREWDBEREFUNT, refUnt, sref, recCdc.refWdbeMModule, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref)) if (refCvr != 0) {
				sref = "CrdWdbeMod";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, VecWdbeVPreset::PREWDBEREFCVR, refCvr, sref, recCdc.refWdbeMModule, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, sref);
	};
};

void PnlWdbeCdcDetail::handleDpchAppDoButFarViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButFarViewClick --- INSERT
};

void PnlWdbeCdcDetail::handleDpchAppDoButSarViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButSarViewClick --- INSERT
};

void PnlWdbeCdcDetail::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBECDC_MDLEQ) {
		call->abort = handleCallWdbeCdc_mdlEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBECDCUPD_REFEQ) {
		call->abort = handleCallWdbeCdcUpd_refEq(dbswdbe, call->jref);
	};
};

bool PnlWdbeCdcDetail::handleCallWdbeCdc_mdlEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recCdc.refWdbeMModule == refInv); // IP handleCallWdbeCdc_mdlEq --- LINE
	return retval;
};

bool PnlWdbeCdcDetail::handleCallWdbeCdcUpd_refEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWdbeCdcUpd_refEq --- INSERT
	return retval;
};
