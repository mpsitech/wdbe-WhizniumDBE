/**
	* \file PnlWdbePrcDetail.cpp
	* job handler for job PnlWdbePrcDetail (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbed.h>
#endif

#include "PnlWdbePrcDetail.h"

#include "PnlWdbePrcDetail_blks.cpp"
#include "PnlWdbePrcDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWdbePrcDetail
 ******************************************************************************/

PnlWdbePrcDetail::PnlWdbePrcDetail(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::PNLWDBEPRCDETAIL, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWdbeVCall::CALLWDBEPRC_FSMEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEPRC_MDLEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswdbe, VecWdbeVPreset::PREWDBEREFPRC, jref);
};

PnlWdbePrcDetail::~PnlWdbePrcDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* PnlWdbePrcDetail::getNewDpchEng(
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

void PnlWdbePrcDetail::refreshTxtClk(
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

void PnlWdbePrcDetail::refreshTxtAsr(
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

void PnlWdbePrcDetail::refreshRecPrc(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WdbeMProcess* _recPrc = NULL;

	if (dbswdbe->tblwdbemprocess->loadRecByRef(recPrc.ref, &_recPrc)) {
		recPrc = *_recPrc;
		delete _recPrc;
	} else recPrc = WdbeMProcess();

	dirty = false;

	recFsm.ref = recPrc.refWdbeMFsm;

	continf.TxtSrf = recPrc.sref;
	continf.TxtMdl = StubWdbe::getStubMdlStd(dbswdbe, recPrc.refWdbeMModule, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfClk = recPrc.clkSrefWdbeMSignal;
	contiac.TxfAsr = recPrc.asrSrefWdbeMSignal;
	contiac.ChkFal = recPrc.Falling;
	contiac.TxfSnr = recPrc.Syncrst;
	contiac.ChkEip = recPrc.Extip;
	contiac.TxfCmt = recPrc.Comment;

	statshr.TxtSrfActive = evalTxtSrfActive(dbswdbe);
	statshr.TxtMdlActive = evalTxtMdlActive(dbswdbe);
	statshr.ButMdlViewAvail = evalButMdlViewAvail(dbswdbe);
	statshr.ButMdlViewActive = evalButMdlViewActive(dbswdbe);
	statshr.ChkFalActive = evalChkFalActive(dbswdbe);
	statshr.TxfSnrActive = evalTxfSnrActive(dbswdbe);
	statshr.ChkEipActive = evalChkEipActive(dbswdbe);
	statshr.TxfCmtActive = evalTxfCmtActive(dbswdbe);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshRecFsm(dbswdbe, moditems);

	refreshTxtClk(dbswdbe, moditems);
	refreshTxtAsr(dbswdbe, moditems);

};

void PnlWdbePrcDetail::refreshRecFsm(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WdbeMFsm* _recFsm = NULL;

	if (dbswdbe->tblwdbemfsm->loadRecByRef(recFsm.ref, &_recFsm)) {
		recFsm = *_recFsm;
		delete _recFsm;
	} else recFsm = WdbeMFsm();

	statshr.ButFsmNewAvail = evalButFsmNewAvail(dbswdbe);
	statshr.ButFsmDeleteAvail = evalButFsmDeleteAvail(dbswdbe);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWdbePrcDetail::refresh(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// statshr
	statshr.ButSaveAvail = evalButSaveAvail(dbswdbe);
	statshr.ButSaveActive = evalButSaveActive(dbswdbe);
	// IP refresh --- END

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbePrcDetail::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFPRC) {
		recPrc.ref = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFPRC, jref);
		refreshRecPrc(dbswdbe, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWdbePrcDetail::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRCDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswdbe, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRCDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTMDLVIEWCLICK) {
					handleDpchAppDoButMdlViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLKVIEWCLICK) {
					handleDpchAppDoButClkViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTASRVIEWCLICK) {
					handleDpchAppDoButAsrViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFSMNEWCLICK) {
					handleDpchAppDoButFsmNewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFSMDELETECLICK) {
					handleDpchAppDoButFsmDeleteClick(dbswdbe, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWdbePrcDetail::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWdbePrcDetail::handleDpchAppDataContiac(
			DbsWdbe* dbswdbe
			, ContIac* _contiac
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::CHKFAL, ContIac::TXFSNR, ContIac::CHKEIP, ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::CHKFAL)) contiac.ChkFal = _contiac->ChkFal;
		if (has(diffitems, ContIac::TXFSNR)) contiac.TxfSnr = _contiac->TxfSnr;
		if (has(diffitems, ContIac::CHKEIP)) contiac.ChkEip = _contiac->ChkEip;
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
	};

	if (has(diffitems, ContIac::TXFCLK)) {
		contiac.TxfClk = _contiac->TxfClk;
		refreshTxtClk(dbswdbe, moditems);
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

void PnlWdbePrcDetail::handleDpchAppDoButSaveClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWdbePrcDetail::handleDpchAppDoButMdlViewClick(
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
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, VecWdbeVPreset::PREWDBEREFUNT, refUnt, sref, recPrc.refWdbeMModule, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref)) if (refCvr != 0) {
				sref = "CrdWdbeMod";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, VecWdbeVPreset::PREWDBEREFCVR, refCvr, sref, recPrc.refWdbeMModule, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, sref);
	};
};

void PnlWdbePrcDetail::handleDpchAppDoButClkViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButClkViewClick --- INSERT
};

void PnlWdbePrcDetail::handleDpchAppDoButAsrViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButAsrViewClick --- INSERT
};

void PnlWdbePrcDetail::handleDpchAppDoButFsmNewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButFsmNewClick --- INSERT
};

void PnlWdbePrcDetail::handleDpchAppDoButFsmDeleteClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButFsmDeleteClick --- INSERT
};

void PnlWdbePrcDetail::handleCall(
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

bool PnlWdbePrcDetail::handleCallWdbePrc_fsmEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recPrc.refWdbeMFsm == refInv); // IP handleCallWdbePrc_fsmEq --- LINE
	return retval;
};

bool PnlWdbePrcDetail::handleCallWdbePrc_mdlEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recPrc.refWdbeMModule == refInv); // IP handleCallWdbePrc_mdlEq --- LINE
	return retval;
};

bool PnlWdbePrcDetail::handleCallWdbeFsmUpd_refEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWdbeFsmUpd_refEq --- INSERT
	return retval;
};

bool PnlWdbePrcDetail::handleCallWdbePrcUpd_refEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWdbePrcUpd_refEq --- INSERT
	return retval;
};

