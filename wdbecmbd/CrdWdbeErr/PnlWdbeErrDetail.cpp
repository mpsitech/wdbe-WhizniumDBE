/**
	* \file PnlWdbeErrDetail.cpp
	* job handler for job PnlWdbeErrDetail (implementation)
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

#include "PnlWdbeErrDetail.h"

#include "PnlWdbeErrDetail_blks.cpp"
#include "PnlWdbeErrDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWdbeErrDetail
 ******************************************************************************/

PnlWdbeErrDetail::PnlWdbeErrDetail(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::PNLWDBEERRDETAIL, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFPupRet.tag = "FeedFPupRet";
	VecWdbeVMErrorRefTbl::fillFeed(ixWdbeVLocale, feedFPupRet);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWdbeVCall::CALLWDBEERR_REUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEERR_REU_MDL_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEERR_REU_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEERR_RETEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswdbe, VecWdbeVPreset::PREWDBEREFERR, jref);
};

PnlWdbeErrDetail::~PnlWdbeErrDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* PnlWdbeErrDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupRet, &statshr, items);
	};

	return dpcheng;
};

void PnlWdbeErrDetail::refreshRecErr(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WdbeMError* _recErr = NULL;

	if (dbswdbe->tblwdbemerror->loadRecByRef(recErr.ref, &_recErr)) {
		recErr = *_recErr;
		delete _recErr;
	} else recErr = WdbeMError();

	dirty = false;

	continf.TxtSrf = recErr.sref;
	contiac.TxfFsr = recErr.Fullsref;
	contiac.numFPupRet = feedFPupRet.getNumByIx(recErr.refIxVTbl);
	if (recErr.refIxVTbl == VecWdbeVMErrorRefTbl::CTR) continf.TxtReu = StubWdbe::getStubCtrStd(dbswdbe, recErr.refUref, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	else if (recErr.refIxVTbl == VecWdbeVMErrorRefTbl::UNT) continf.TxtReu = StubWdbe::getStubUntStd(dbswdbe, recErr.refUref, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	else continf.TxtReu = "-";
	continf.TxtTra = StubWdbe::getStubSigStd(dbswdbe, recErr.traRefWdbeMSignal, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfCmt = recErr.Comment;

	statshr.TxtSrfActive = evalTxtSrfActive(dbswdbe);
	statshr.TxfFsrActive = evalTxfFsrActive(dbswdbe);
	statshr.TxtReuActive = evalTxtReuActive(dbswdbe);
	statshr.ButReuViewAvail = evalButReuViewAvail(dbswdbe);
	statshr.ButReuViewActive = evalButReuViewActive(dbswdbe);
	statshr.TxtTraActive = evalTxtTraActive(dbswdbe);
	statshr.TxfCmtActive = evalTxfCmtActive(dbswdbe);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWdbeErrDetail::refresh(
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

void PnlWdbeErrDetail::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFERR) {
		recErr.ref = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFERR, jref);
		refreshRecErr(dbswdbe, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWdbeErrDetail::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEERRDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswdbe, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEERRDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREUVIEWCLICK) {
					handleDpchAppDoButReuViewClick(dbswdbe, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWdbeErrDetail::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWdbeErrDetail::handleDpchAppDataContiac(
			DbsWdbe* dbswdbe
			, ContIac* _contiac
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFFSR, ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::TXFFSR)) contiac.TxfFsr = _contiac->TxfFsr;
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWdbeErrDetail::handleDpchAppDoButSaveClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWdbeErrDetail::handleDpchAppDoButReuViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	ubigint refCvr = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCVR, jref);
	ubigint refVer = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref);

	if (statshr.ButReuViewAvail && statshr.ButReuViewActive) {
		if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCUNT, jref)) if (recErr.refIxVTbl == VecWdbeVMErrorRefTbl::UNT) if (refVer != 0) {
			sref = "CrdWdbeUnt";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, VecWdbeVPreset::PREWDBEREFVER, refVer, sref, recErr.refUref, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIL, jref)) if (recErr.refIxVTbl == VecWdbeVMErrorRefTbl::UNT) if ((dbswdbe->getIxWSubsetByRefWdbeMUnit(recErr.refUref) & VecWdbeWMUnitSubset::SBSWDBEBMUNITSIL) != 0) {
				sref = "CrdWdbeSil";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, sref, recErr.refUref, jrefNew);
			};
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref)) if (recErr.refIxVTbl == VecWdbeVMErrorRefTbl::CTR) if ((dbswdbe->getIxWSubsetByRefWdbeMModule([&](){ubigint ref; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE refWdbeMController = " + to_string(recErr.refUref), ref); return ref;}()) & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMOD) != 0) if (ixPre == VecWdbeVPreset::PREWDBEREFUNT) {
				sref = "CrdWdbeMod";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, ixPre, refPre, sref, [&](){ubigint ref = 0; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE refWdbeMController = " + to_string(recErr.refUref), ref); return ref;}(), jrefNew);
			};
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref)) if (recErr.refIxVTbl == VecWdbeVMErrorRefTbl::CTR) if ((dbswdbe->getIxWSubsetByRefWdbeMModule([&](){ubigint ref; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE refWdbeMController = " + to_string(recErr.refUref), ref); return ref;}()) & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMOD) != 0) if (refCvr != 0) {
				sref = "CrdWdbeMod";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, VecWdbeVPreset::PREWDBEREFCVR, refCvr, sref, [&](){ubigint ref = 0; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE refWdbeMController = " + to_string(recErr.refUref), ref); return ref;}(), jrefNew);
			};
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMTP, jref)) if (recErr.refIxVTbl == VecWdbeVMErrorRefTbl::CTR) if ((dbswdbe->getIxWSubsetByRefWdbeMModule([&](){ubigint ref; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE refWdbeMController = " + to_string(recErr.refUref), ref); return ref;}()) & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMTP) != 0) {
				sref = "CrdWdbeMtp";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, sref, [&](){ubigint ref = 0; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE refWdbeMController = " + to_string(recErr.refUref), ref); return ref;}(), jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, sref);
	};
};

void PnlWdbeErrDetail::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBEERRUPD_REFEQ) {
		call->abort = handleCallWdbeErrUpd_refEq(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEERR_REUEQ) {
		call->abort = handleCallWdbeErr_reuEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEERR_REU_MDL_INSBS) {
		call->abort = handleCallWdbeErr_reu_mdl_inSbs(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEERR_REU_INSBS) {
		call->abort = handleCallWdbeErr_reu_inSbs(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEERR_RETEQ) {
		call->abort = handleCallWdbeErr_retEq(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	};
};

bool PnlWdbeErrDetail::handleCallWdbeErrUpd_refEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWdbeErrUpd_refEq --- INSERT
	return retval;
};

bool PnlWdbeErrDetail::handleCallWdbeErr_reuEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recErr.refUref == refInv); // IP handleCallWdbeErr_reuEq --- LINE
	return retval;
};

bool PnlWdbeErrDetail::handleCallWdbeErr_reu_mdl_inSbs(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((dbswdbe->getIxWSubsetByRefWdbeMModule([&](){ubigint ref; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE refWdbeMController = " + to_string(recErr.refUref), ref); return ref;}()) & ixInv) != 0); // IP handleCallWdbeErr_reu_mdl_inSbs --- LINE
	return retval;
};

bool PnlWdbeErrDetail::handleCallWdbeErr_reu_inSbs(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((dbswdbe->getIxWSubsetByRefWdbeMUnit(recErr.refUref) & ixInv) != 0); // IP handleCallWdbeErr_reu_inSbs --- LINE
	return retval;
};

bool PnlWdbeErrDetail::handleCallWdbeErr_retEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recErr.refIxVTbl == ixInv); // IP handleCallWdbeErr_retEq --- LINE
	return retval;
};
