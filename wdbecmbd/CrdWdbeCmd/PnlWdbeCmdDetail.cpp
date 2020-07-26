/**
	* \file PnlWdbeCmdDetail.cpp
	* job handler for job PnlWdbeCmdDetail (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbed.h>
#endif

#include "PnlWdbeCmdDetail.h"

#include "PnlWdbeCmdDetail_blks.cpp"
#include "PnlWdbeCmdDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWdbeCmdDetail
 ******************************************************************************/

PnlWdbeCmdDetail::PnlWdbeCmdDetail(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::PNLWDBECMDDETAIL, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFPupRet.tag = "FeedFPupRet";
	VecWdbeVMCommandRefTbl::fillFeed(ixWdbeVLocale, feedFPupRet);
	feedFPupRty.tag = "FeedFPupRty";
	VecWdbeVMCommandRettype::fillFeed(ixWdbeVLocale, feedFPupRty);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWdbeVCall::CALLWDBECMD_REUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBECMD_REU_MDL_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBECMD_REU_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBECMD_RETEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswdbe, VecWdbeVPreset::PREWDBEREFCMD, jref);
};

PnlWdbeCmdDetail::~PnlWdbeCmdDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* PnlWdbeCmdDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupRet, &feedFPupRty, &statshr, items);
	};

	return dpcheng;
};

void PnlWdbeCmdDetail::refreshRecCmd(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WdbeMCommand* _recCmd = NULL;

	if (dbswdbe->tblwdbemcommand->loadRecByRef(recCmd.ref, &_recCmd)) {
		recCmd = *_recCmd;
		delete _recCmd;
	} else recCmd = WdbeMCommand();

	dirty = false;

	continf.TxtSrf = recCmd.sref;
	contiac.TxfFsr = recCmd.Fullsref;
	contiac.numFPupRet = feedFPupRet.getNumByIx(recCmd.refIxVTbl);
	if (recCmd.refIxVTbl == VecWdbeVMCommandRefTbl::CTR) continf.TxtReu = StubWdbe::getStubCtrStd(dbswdbe, recCmd.refUref, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	else if (recCmd.refIxVTbl == VecWdbeVMCommandRefTbl::UNT) continf.TxtReu = StubWdbe::getStubUntStd(dbswdbe, recCmd.refUref, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	else continf.TxtReu = "-";
	contiac.numFPupRty = feedFPupRty.getNumByIx(recCmd.ixVRettype);
	continf.TxtIvr = StubWdbe::getStubSigStd(dbswdbe, recCmd.ivrRefWdbeMSignal, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	continf.TxtRvr = StubWdbe::getStubSigStd(dbswdbe, recCmd.rvrRefWdbeMSignal, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	continf.TxtRer = StubWdbe::getStubSigStd(dbswdbe, recCmd.rerRefWdbeMSignal, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfCmt = recCmd.Comment;

	statshr.TxtSrfActive = evalTxtSrfActive(dbswdbe);
	statshr.TxfFsrActive = evalTxfFsrActive(dbswdbe);
	statshr.TxtReuActive = evalTxtReuActive(dbswdbe);
	statshr.ButReuViewAvail = evalButReuViewAvail(dbswdbe);
	statshr.ButReuViewActive = evalButReuViewActive(dbswdbe);
	statshr.PupRtyActive = evalPupRtyActive(dbswdbe);
	statshr.TxtIvrActive = evalTxtIvrActive(dbswdbe);
	statshr.TxtRvrActive = evalTxtRvrActive(dbswdbe);
	statshr.TxtRerActive = evalTxtRerActive(dbswdbe);
	statshr.TxfCmtActive = evalTxfCmtActive(dbswdbe);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWdbeCmdDetail::refresh(
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

void PnlWdbeCmdDetail::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFCMD) {
		recCmd.ref = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCMD, jref);
		refreshRecCmd(dbswdbe, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWdbeCmdDetail::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMDDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswdbe, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECMDDETAILDO) {
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

void PnlWdbeCmdDetail::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWdbeCmdDetail::handleDpchAppDataContiac(
			DbsWdbe* dbswdbe
			, ContIac* _contiac
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFFSR, ContIac::NUMFPUPRTY, ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::TXFFSR)) contiac.TxfFsr = _contiac->TxfFsr;
		if (has(diffitems, ContIac::NUMFPUPRTY)) contiac.numFPupRty = _contiac->numFPupRty;
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWdbeCmdDetail::handleDpchAppDoButSaveClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWdbeCmdDetail::handleDpchAppDoButReuViewClick(
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
		if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref)) if (recCmd.refIxVTbl == VecWdbeVMCommandRefTbl::CTR) if ((dbswdbe->getIxWSubsetByRefWdbeMModule([&](){ubigint ref; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE refWdbeMController = " + to_string(recCmd.refUref), ref); return ref;}()) & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMOD) != 0) if (ixPre == VecWdbeVPreset::PREWDBEREFUNT) {
			sref = "CrdWdbeMod";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, ixPre, refPre, sref, [&](){ubigint ref = 0; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE refWdbeMController = " + to_string(recCmd.refUref), ref); return ref;}(), jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref)) if (recCmd.refIxVTbl == VecWdbeVMCommandRefTbl::CTR) if ((dbswdbe->getIxWSubsetByRefWdbeMModule([&](){ubigint ref; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE refWdbeMController = " + to_string(recCmd.refUref), ref); return ref;}()) & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMOD) != 0) if (refCvr != 0) {
				sref = "CrdWdbeMod";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, VecWdbeVPreset::PREWDBEREFCVR, refCvr, sref, [&](){ubigint ref = 0; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE refWdbeMController = " + to_string(recCmd.refUref), ref); return ref;}(), jrefNew);
			};
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMTP, jref)) if (recCmd.refIxVTbl == VecWdbeVMCommandRefTbl::CTR) if ((dbswdbe->getIxWSubsetByRefWdbeMModule([&](){ubigint ref; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE refWdbeMController = " + to_string(recCmd.refUref), ref); return ref;}()) & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMTP) != 0) {
				sref = "CrdWdbeMtp";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, sref, [&](){ubigint ref = 0; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE refWdbeMController = " + to_string(recCmd.refUref), ref); return ref;}(), jrefNew);
			};
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCUNT, jref)) if (recCmd.refIxVTbl == VecWdbeVMCommandRefTbl::UNT) if (refVer != 0) {
				sref = "CrdWdbeUnt";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, VecWdbeVPreset::PREWDBEREFVER, refVer, sref, recCmd.refUref, jrefNew);
			};
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIL, jref)) if (recCmd.refIxVTbl == VecWdbeVMCommandRefTbl::UNT) if ((dbswdbe->getIxWSubsetByRefWdbeMUnit(recCmd.refUref) & VecWdbeWMUnitSubset::SBSWDBEBMUNITSIL) != 0) {
				sref = "CrdWdbeSil";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, sref, recCmd.refUref, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, sref);
	};
};

void PnlWdbeCmdDetail::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBECMDUPD_REFEQ) {
		call->abort = handleCallWdbeCmdUpd_refEq(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBECMD_REUEQ) {
		call->abort = handleCallWdbeCmd_reuEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBECMD_REU_MDL_INSBS) {
		call->abort = handleCallWdbeCmd_reu_mdl_inSbs(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBECMD_REU_INSBS) {
		call->abort = handleCallWdbeCmd_reu_inSbs(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBECMD_RETEQ) {
		call->abort = handleCallWdbeCmd_retEq(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	};
};

bool PnlWdbeCmdDetail::handleCallWdbeCmdUpd_refEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWdbeCmdUpd_refEq --- INSERT
	return retval;
};

bool PnlWdbeCmdDetail::handleCallWdbeCmd_reuEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recCmd.refUref == refInv); // IP handleCallWdbeCmd_reuEq --- LINE
	return retval;
};

bool PnlWdbeCmdDetail::handleCallWdbeCmd_reu_mdl_inSbs(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((dbswdbe->getIxWSubsetByRefWdbeMModule([&](){ubigint ref; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE refWdbeMController = " + to_string(recCmd.refUref), ref); return ref;}()) & ixInv) != 0); // IP handleCallWdbeCmd_reu_mdl_inSbs --- LINE
	return retval;
};

bool PnlWdbeCmdDetail::handleCallWdbeCmd_reu_inSbs(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((dbswdbe->getIxWSubsetByRefWdbeMUnit(recCmd.refUref) & ixInv) != 0); // IP handleCallWdbeCmd_reu_inSbs --- LINE
	return retval;
};

bool PnlWdbeCmdDetail::handleCallWdbeCmd_retEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recCmd.refIxVTbl == ixInv); // IP handleCallWdbeCmd_retEq --- LINE
	return retval;
};

