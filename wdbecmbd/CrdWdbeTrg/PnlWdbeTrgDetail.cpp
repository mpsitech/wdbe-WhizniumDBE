/**
	* \file PnlWdbeTrgDetail.cpp
	* job handler for job PnlWdbeTrgDetail (implementation)
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

#include "PnlWdbeTrgDetail.h"

#include "PnlWdbeTrgDetail_blks.cpp"
#include "PnlWdbeTrgDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWdbeTrgDetail
 ******************************************************************************/

PnlWdbeTrgDetail::PnlWdbeTrgDetail(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::PNLWDBETRGDETAIL, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFLstRte.tag = "FeedFLstRte";

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWdbeVCall::CALLWDBETRG_SYSEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBETRG_UNT_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBETRG_UNTEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswdbe, VecWdbeVPreset::PREWDBEREFTRG, jref);
};

PnlWdbeTrgDetail::~PnlWdbeTrgDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* PnlWdbeTrgDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFLstRte, &statshr, items);
	};

	return dpcheng;
};

void PnlWdbeTrgDetail::refreshLstRte(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstRteActive = evalLstRteActive(dbswdbe);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeTrgDetail::refreshRte(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	vector<string> ss;

	// contiac
	contiac.numFLstRte = 0;

	// feedFLstRte
	feedFLstRte.clear();

	StrMod::srefsToVector(contiac.TxfRte, ss);

	// IP refreshRte.validate --- INSERT

	// statshr
	statshr.TxfRteValid = (ss.size() == feedFLstRte.size());

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeTrgDetail::refreshRecTrg(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WdbeMTarget* _recTrg = NULL;

	if (dbswdbe->tblwdbemtarget->loadRecByRef(recTrg.ref, &_recTrg)) {
		recTrg = *_recTrg;
		delete _recTrg;
	} else recTrg = WdbeMTarget();

	dirty = false;

	continf.TxtSrf = recTrg.sref;
	continf.TxtSys = StubWdbe::getStubSysStd(dbswdbe, recTrg.sysRefWdbeMSystem, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	continf.TxtUnt = StubWdbe::getStubUntStd(dbswdbe, recTrg.refWdbeMUnit, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfRte = recTrg.rteSrefsWdbeMModule;
	contiac.TxfCmt = recTrg.Comment;

	statshr.TxtSrfActive = evalTxtSrfActive(dbswdbe);
	statshr.TxtSysActive = evalTxtSysActive(dbswdbe);
	statshr.ButSysViewAvail = evalButSysViewAvail(dbswdbe);
	statshr.ButSysViewActive = evalButSysViewActive(dbswdbe);
	statshr.TxtUntActive = evalTxtUntActive(dbswdbe);
	statshr.ButUntViewAvail = evalButUntViewAvail(dbswdbe);
	statshr.ButUntViewActive = evalButUntViewActive(dbswdbe);
	statshr.TxfCmtActive = evalTxfCmtActive(dbswdbe);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshRte(dbswdbe, moditems);

};

void PnlWdbeTrgDetail::refresh(
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

void PnlWdbeTrgDetail::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFTRG) {
		recTrg.ref = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFTRG, jref);
		refreshRecTrg(dbswdbe, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWdbeTrgDetail::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBETRGDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswdbe, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBETRGDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSYSVIEWCLICK) {
					handleDpchAppDoButSysViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTUNTVIEWCLICK) {
					handleDpchAppDoButUntViewClick(dbswdbe, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWdbeTrgDetail::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWdbeTrgDetail::handleDpchAppDataContiac(
			DbsWdbe* dbswdbe
			, ContIac* _contiac
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
	};

	if (has(diffitems, ContIac::TXFRTE)) {
		contiac.TxfRte = _contiac->TxfRte;
		refreshRte(dbswdbe, moditems);
	} else if (has(diffitems, ContIac::NUMFLSTRTE)) {
		contiac.numFLstRte = _contiac->numFLstRte;
		refreshLstRte(dbswdbe, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWdbeTrgDetail::handleDpchAppDoButSaveClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWdbeTrgDetail::handleDpchAppDoButSysViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButSysViewAvail && statshr.ButSysViewActive) {
		if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSYS, jref)) if (ixPre == VecWdbeVPreset::PREWDBEREFVER) {
			sref = "CrdWdbeSys";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, ixPre, refPre, sref, recTrg.sysRefWdbeMSystem, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, sref);
	};
};

void PnlWdbeTrgDetail::handleDpchAppDoButUntViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButUntViewAvail && statshr.ButUntViewActive) {
		if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCUNT, jref)) if (ixPre == VecWdbeVPreset::PREWDBEREFVER) {
			sref = "CrdWdbeUnt";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, ixPre, refPre, sref, recTrg.refWdbeMUnit, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIL, jref)) if ((dbswdbe->getIxWSubsetByRefWdbeMUnit(recTrg.refWdbeMUnit) & VecWdbeWMUnitSubset::SBSWDBEBMUNITSIL) != 0) {
				sref = "CrdWdbeSil";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, sref, recTrg.refWdbeMUnit, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, sref);
	};
};

void PnlWdbeTrgDetail::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBETRG_SYSEQ) {
		call->abort = handleCallWdbeTrg_sysEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBETRG_UNT_INSBS) {
		call->abort = handleCallWdbeTrg_unt_inSbs(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBETRG_UNTEQ) {
		call->abort = handleCallWdbeTrg_untEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBETRGUPD_REFEQ) {
		call->abort = handleCallWdbeTrgUpd_refEq(dbswdbe, call->jref);
	};
};

bool PnlWdbeTrgDetail::handleCallWdbeTrg_sysEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recTrg.sysRefWdbeMSystem == refInv); // IP handleCallWdbeTrg_sysEq --- LINE
	return retval;
};

bool PnlWdbeTrgDetail::handleCallWdbeTrg_unt_inSbs(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((dbswdbe->getIxWSubsetByRefWdbeMUnit(recTrg.refWdbeMUnit) & ixInv) != 0); // IP handleCallWdbeTrg_unt_inSbs --- LINE
	return retval;
};

bool PnlWdbeTrgDetail::handleCallWdbeTrg_untEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recTrg.refWdbeMUnit == refInv); // IP handleCallWdbeTrg_untEq --- LINE
	return retval;
};

bool PnlWdbeTrgDetail::handleCallWdbeTrgUpd_refEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWdbeTrgUpd_refEq --- INSERT
	return retval;
};
