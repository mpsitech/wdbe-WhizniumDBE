/**
	* \file PnlWdbePplDetail.cpp
	* job handler for job PnlWdbePplDetail (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbed.h>
#endif

#include "PnlWdbePplDetail.h"

#include "PnlWdbePplDetail_blks.cpp"
#include "PnlWdbePplDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWdbePplDetail
 ******************************************************************************/

PnlWdbePplDetail::PnlWdbePplDetail(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::PNLWDBEPPLDETAIL, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWdbeVCall::CALLWDBEPPL_HSM_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEPPL_HSMEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswdbe, VecWdbeVPreset::PREWDBEREFPPL, jref);
};

PnlWdbePplDetail::~PnlWdbePplDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* PnlWdbePplDetail::getNewDpchEng(
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

void PnlWdbePplDetail::refreshTxtClk(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refreshTxtClk --- BEGIN
	ubigint refSig = 0;

	dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMSignal WHERE sref = '" + contiac.TxfClk + "'", refSig);

	continf.TxtClk = StubWdbe::getStubSigStd(dbswdbe, refSig, ixWdbeVLocale);

	statshr.TxfClkValid = (refSig != 0);
	statshr.TxtClkActive = evalTxtClkActive(dbswdbe);
	statshr.ButClkViewAvail = evalButClkViewAvail(dbswdbe);
	// IP refreshTxtClk --- END

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbePplDetail::refreshTxtClg(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refreshTxtClg --- BEGIN
	ubigint refSig = 0;

	dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMSignal WHERE sref = '" + contiac.TxfClg + "'", refSig);

	continf.TxtClg = StubWdbe::getStubSigStd(dbswdbe, refSig, ixWdbeVLocale);

	statshr.TxfClgValid = (refSig != 0);
	statshr.TxtClgActive = evalTxtClgActive(dbswdbe);
	statshr.ButClgViewAvail = evalButClgViewAvail(dbswdbe);
	// IP refreshTxtClg --- END

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbePplDetail::refreshTxtAsr(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refreshTxtAsr --- BEGIN
	ubigint refSig = 0;

	dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMSignal WHERE sref = '" + contiac.TxfAsr + "'", refSig);

	continf.TxtAsr = StubWdbe::getStubSigStd(dbswdbe, refSig, ixWdbeVLocale);

	statshr.TxfAsrValid = (refSig != 0);
	statshr.TxtAsrActive = evalTxtAsrActive(dbswdbe);
	statshr.ButAsrViewAvail = evalButAsrViewAvail(dbswdbe);
	// IP refreshTxtAsr --- END

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbePplDetail::refreshRecPpl(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WdbeMPipeline* _recPpl = NULL;

	if (dbswdbe->tblwdbempipeline->loadRecByRef(recPpl.ref, &_recPpl)) {
		recPpl = *_recPpl;
		delete _recPpl;
	} else recPpl = WdbeMPipeline();

	dirty = false;

	continf.TxtSrf = recPpl.sref;
	continf.TxtHsm = StubWdbe::getStubMdlStd(dbswdbe, recPpl.hsmRefWdbeMModule, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfClk = recPpl.clkSrefWdbeMSignal;
	contiac.TxfClg = recPpl.clgSrefWdbeMSignal;
	contiac.TxfAsr = recPpl.asrSrefWdbeMSignal;
	contiac.TxfDpt = to_string(recPpl.Depth);
	contiac.TxfCmt = recPpl.Comment;

	statshr.TxtSrfActive = evalTxtSrfActive(dbswdbe);
	statshr.TxtHsmActive = evalTxtHsmActive(dbswdbe);
	statshr.ButHsmViewAvail = evalButHsmViewAvail(dbswdbe);
	statshr.ButHsmViewActive = evalButHsmViewActive(dbswdbe);
	statshr.TxfDptActive = evalTxfDptActive(dbswdbe);
	statshr.TxfCmtActive = evalTxfCmtActive(dbswdbe);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshTxtClk(dbswdbe, moditems);
	refreshTxtClg(dbswdbe, moditems);
	refreshTxtAsr(dbswdbe, moditems);

};

void PnlWdbePplDetail::refresh(
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

void PnlWdbePplDetail::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFPPL) {
		recPpl.ref = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFPPL, jref);
		refreshRecPpl(dbswdbe, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWdbePplDetail::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPPLDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswdbe, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPPLDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTHSMVIEWCLICK) {
					handleDpchAppDoButHsmViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLKVIEWCLICK) {
					handleDpchAppDoButClkViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLGVIEWCLICK) {
					handleDpchAppDoButClgViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTASRVIEWCLICK) {
					handleDpchAppDoButAsrViewClick(dbswdbe, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWdbePplDetail::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWdbePplDetail::handleDpchAppDataContiac(
			DbsWdbe* dbswdbe
			, ContIac* _contiac
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFDPT, ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::TXFDPT)) contiac.TxfDpt = _contiac->TxfDpt;
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
	};

	if (has(diffitems, ContIac::TXFCLK)) {
		contiac.TxfClk = _contiac->TxfClk;
		refreshTxtClk(dbswdbe, moditems);
		refresh(dbswdbe, moditems);
	};

	if (has(diffitems, ContIac::TXFCLG)) {
		contiac.TxfClg = _contiac->TxfClg;
		refreshTxtClg(dbswdbe, moditems);
		refresh(dbswdbe, moditems);
	};

	if (has(diffitems, ContIac::TXFASR)) {
		contiac.TxfAsr = _contiac->TxfAsr;
		refreshTxtAsr(dbswdbe, moditems);
		refresh(dbswdbe, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWdbePplDetail::handleDpchAppDoButSaveClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWdbePplDetail::handleDpchAppDoButHsmViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	ubigint refCvr = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCVR, jref);

	if (statshr.ButHsmViewAvail && statshr.ButHsmViewActive) {
		if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref)) if ((dbswdbe->getIxWSubsetByRefWdbeMModule(recPpl.hsmRefWdbeMModule) & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMOD) != 0) if (ixPre == VecWdbeVPreset::PREWDBEREFUNT) {
			sref = "CrdWdbeMod";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, ixPre, refPre, sref, recPpl.hsmRefWdbeMModule, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref)) if ((dbswdbe->getIxWSubsetByRefWdbeMModule(recPpl.hsmRefWdbeMModule) & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMOD) != 0) if (refCvr != 0) {
				sref = "CrdWdbeMod";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, VecWdbeVPreset::PREWDBEREFCVR, refCvr, sref, recPpl.hsmRefWdbeMModule, jrefNew);
			};
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMTP, jref)) if ((dbswdbe->getIxWSubsetByRefWdbeMModule(recPpl.hsmRefWdbeMModule) & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMTP) != 0) {
				sref = "CrdWdbeMtp";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, sref, recPpl.hsmRefWdbeMModule, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, sref);
	};
};

void PnlWdbePplDetail::handleDpchAppDoButClkViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButClkViewClick --- INSERT
};

void PnlWdbePplDetail::handleDpchAppDoButClgViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButClgViewClick --- INSERT
};

void PnlWdbePplDetail::handleDpchAppDoButAsrViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButAsrViewClick --- INSERT
};

void PnlWdbePplDetail::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBEPPL_HSM_INSBS) {
		call->abort = handleCallWdbePpl_hsm_inSbs(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEPPL_HSMEQ) {
		call->abort = handleCallWdbePpl_hsmEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEPPLUPD_REFEQ) {
		call->abort = handleCallWdbePplUpd_refEq(dbswdbe, call->jref);
	};
};

bool PnlWdbePplDetail::handleCallWdbePpl_hsm_inSbs(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((dbswdbe->getIxWSubsetByRefWdbeMModule(recPpl.hsmRefWdbeMModule) & ixInv) != 0); // IP handleCallWdbePpl_hsm_inSbs --- LINE
	return retval;
};

bool PnlWdbePplDetail::handleCallWdbePpl_hsmEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recPpl.hsmRefWdbeMModule == refInv); // IP handleCallWdbePpl_hsmEq --- LINE
	return retval;
};

bool PnlWdbePplDetail::handleCallWdbePplUpd_refEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWdbePplUpd_refEq --- INSERT
	return retval;
};
