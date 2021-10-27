/**
	* \file PnlWdbeSnsDetail.cpp
	* job handler for job PnlWdbeSnsDetail (implementation)
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

#include "PnlWdbeSnsDetail.h"

#include "PnlWdbeSnsDetail_blks.cpp"
#include "PnlWdbeSnsDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWdbeSnsDetail
 ******************************************************************************/

PnlWdbeSnsDetail::PnlWdbeSnsDetail(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::PNLWDBESNSDETAIL, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFPupRet.tag = "FeedFPupRet";
	VecWdbeVMSensitivityRefTbl::fillFeed(ixWdbeVLocale, feedFPupRet);
	feedFPupSrt.tag = "FeedFPupSrt";
	VecWdbeVMSensitivitySrcTbl::fillFeed(ixWdbeVLocale, feedFPupSrt);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWdbeVCall::CALLWDBESNS_RETEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBESNS_REU_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBESNS_REUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBESNS_SRTEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBESNS_SRUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswdbe, VecWdbeVPreset::PREWDBEREFSNS, jref);
};

PnlWdbeSnsDetail::~PnlWdbeSnsDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* PnlWdbeSnsDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupRet, &feedFPupSrt, &statshr, items);
	};

	return dpcheng;
};

void PnlWdbeSnsDetail::refreshRecSns(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WdbeMSensitivity* _recSns = NULL;

	if (dbswdbe->tblwdbemsensitivity->loadRecByRef(recSns.ref, &_recSns)) {
		recSns = *_recSns;
		delete _recSns;
	} else recSns = WdbeMSensitivity();

	dirty = false;

	contiac.numFPupRet = feedFPupRet.getNumByIx(recSns.refIxVTbl);
	if (recSns.refIxVTbl == VecWdbeVMSensitivityRefTbl::MDL) continf.TxtReu = StubWdbe::getStubMdlStd(dbswdbe, recSns.refUref, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	else if (recSns.refIxVTbl == VecWdbeVMSensitivityRefTbl::PRC) continf.TxtReu = StubWdbe::getStubPrcStd(dbswdbe, recSns.refUref, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	else continf.TxtReu = "-";
	contiac.numFPupSrt = feedFPupSrt.getNumByIx(recSns.srcIxVTbl);
	if (recSns.srcIxVTbl == VecWdbeVMSensitivitySrcTbl::INT) continf.TxtSru = StubWdbe::getStubIntStd(dbswdbe, recSns.srcUref, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	else if (recSns.srcIxVTbl == VecWdbeVMSensitivitySrcTbl::PRT) continf.TxtSru = StubWdbe::getStubPrtStd(dbswdbe, recSns.srcUref, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	else if (recSns.srcIxVTbl == VecWdbeVMSensitivitySrcTbl::SIG) continf.TxtSru = StubWdbe::getStubSigStd(dbswdbe, recSns.srcUref, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	else continf.TxtSru = "-";

	statshr.TxtReuActive = evalTxtReuActive(dbswdbe);
	statshr.ButReuViewAvail = evalButReuViewAvail(dbswdbe);
	statshr.ButReuViewActive = evalButReuViewActive(dbswdbe);
	statshr.TxtSruActive = evalTxtSruActive(dbswdbe);
	statshr.ButSruViewAvail = evalButSruViewAvail(dbswdbe);
	statshr.ButSruViewActive = evalButSruViewActive(dbswdbe);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWdbeSnsDetail::refresh(
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

void PnlWdbeSnsDetail::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFSNS) {
		recSns.ref = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSNS, jref);
		refreshRecSns(dbswdbe, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWdbeSnsDetail::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESNSDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswdbe, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESNSDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREUVIEWCLICK) {
					handleDpchAppDoButReuViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSRUVIEWCLICK) {
					handleDpchAppDoButSruViewClick(dbswdbe, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWdbeSnsDetail::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWdbeSnsDetail::handleDpchAppDataContiac(
			DbsWdbe* dbswdbe
			, ContIac* _contiac
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWdbeSnsDetail::handleDpchAppDoButSaveClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWdbeSnsDetail::handleDpchAppDoButReuViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	ubigint refCvr = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCVR, jref);
	ubigint refUnt = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref);

	if (statshr.ButReuViewAvail && statshr.ButReuViewActive) {
		if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPRC, jref)) if (recSns.refIxVTbl == VecWdbeVMSensitivityRefTbl::PRC) if (ixPre == VecWdbeVPreset::PREWDBEREFMOD) {
			sref = "CrdWdbePrc";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, ixPre, refPre, sref, recSns.refUref, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref)) if (recSns.refIxVTbl == VecWdbeVMSensitivityRefTbl::MDL) if ((dbswdbe->getIxWSubsetByRefWdbeMModule(recSns.refUref) & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMOD) != 0) if (refUnt != 0) {
				sref = "CrdWdbeMod";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, VecWdbeVPreset::PREWDBEREFUNT, refUnt, sref, recSns.refUref, jrefNew);
			};
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref)) if (recSns.refIxVTbl == VecWdbeVMSensitivityRefTbl::MDL) if ((dbswdbe->getIxWSubsetByRefWdbeMModule(recSns.refUref) & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMOD) != 0) if (refCvr != 0) {
				sref = "CrdWdbeMod";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, VecWdbeVPreset::PREWDBEREFCVR, refCvr, sref, recSns.refUref, jrefNew);
			};
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMTP, jref)) if (recSns.refIxVTbl == VecWdbeVMSensitivityRefTbl::MDL) if ((dbswdbe->getIxWSubsetByRefWdbeMModule(recSns.refUref) & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMTP) != 0) {
				sref = "CrdWdbeMtp";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, sref, recSns.refUref, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, sref);
	};
};

void PnlWdbeSnsDetail::handleDpchAppDoButSruViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	ubigint refUnt = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref);

	if (statshr.ButSruViewAvail && statshr.ButSruViewActive) {
		if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIG, jref)) if (recSns.srcIxVTbl == VecWdbeVMSensitivitySrcTbl::SIG) if (ixPre == VecWdbeVPreset::PREWDBEREFMOD) {
			sref = "CrdWdbeSig";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, ixPre, refPre, sref, recSns.srcUref, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIG, jref)) if (recSns.srcIxVTbl == VecWdbeVMSensitivitySrcTbl::SIG) if (refUnt != 0) {
				sref = "CrdWdbeSig";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, VecWdbeVPreset::PREWDBEREFUNT, refUnt, sref, recSns.srcUref, jrefNew);
			};
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPRT, jref)) if (recSns.srcIxVTbl == VecWdbeVMSensitivitySrcTbl::PRT) if (ixPre == VecWdbeVPreset::PREWDBEREFMOD) {
				sref = "CrdWdbePrt";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, ixPre, refPre, sref, recSns.srcUref, jrefNew);
			};
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCINT, jref)) if (recSns.srcIxVTbl == VecWdbeVMSensitivitySrcTbl::INT) if (refUnt != 0) {
				sref = "CrdWdbeInt";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, VecWdbeVPreset::PREWDBEREFUNT, refUnt, sref, recSns.srcUref, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, sref);
	};
};

void PnlWdbeSnsDetail::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBESNS_RETEQ) {
		call->abort = handleCallWdbeSns_retEq(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBESNS_REU_INSBS) {
		call->abort = handleCallWdbeSns_reu_inSbs(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBESNS_REUEQ) {
		call->abort = handleCallWdbeSns_reuEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBESNS_SRTEQ) {
		call->abort = handleCallWdbeSns_srtEq(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBESNS_SRUEQ) {
		call->abort = handleCallWdbeSns_sruEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBESNSUPD_REFEQ) {
		call->abort = handleCallWdbeSnsUpd_refEq(dbswdbe, call->jref);
	};
};

bool PnlWdbeSnsDetail::handleCallWdbeSns_retEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recSns.refIxVTbl == ixInv); // IP handleCallWdbeSns_retEq --- LINE
	return retval;
};

bool PnlWdbeSnsDetail::handleCallWdbeSns_reu_inSbs(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((dbswdbe->getIxWSubsetByRefWdbeMModule(recSns.refUref) & ixInv) != 0); // IP handleCallWdbeSns_reu_inSbs --- LINE
	return retval;
};

bool PnlWdbeSnsDetail::handleCallWdbeSns_reuEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recSns.refUref == refInv); // IP handleCallWdbeSns_reuEq --- LINE
	return retval;
};

bool PnlWdbeSnsDetail::handleCallWdbeSns_srtEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recSns.srcIxVTbl == ixInv); // IP handleCallWdbeSns_srtEq --- LINE
	return retval;
};

bool PnlWdbeSnsDetail::handleCallWdbeSns_sruEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recSns.srcUref == refInv); // IP handleCallWdbeSns_sruEq --- LINE
	return retval;
};

bool PnlWdbeSnsDetail::handleCallWdbeSnsUpd_refEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWdbeSnsUpd_refEq --- INSERT
	return retval;
};
