/**
	* \file PnlWdbeSilDetail.cpp
	* job handler for job PnlWdbeSilDetail (implementation)
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

#include "PnlWdbeSilDetail.h"

#include "PnlWdbeSilDetail_blks.cpp"
#include "PnlWdbeSilDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWdbeSilDetail
 ******************************************************************************/

PnlWdbeSilDetail::PnlWdbeSilDetail(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::PNLWDBESILDETAIL, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFPupPkg.tag = "FeedFPupPkg";
	feedFPupRet.tag = "FeedFPupRet";
	VecWdbeVMUnitRefTbl::fillFeed(ixWdbeVLocale, feedFPupRet);
	feedFPupTch.tag = "FeedFPupTch";
	feedFPupTyp.tag = "FeedFPupTyp";
	VecWdbeVMUnitBasetype::fillFeed(ixWdbeVLocale, feedFPupTyp);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWdbeVCall::CALLWDBEKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEUNT_SYSEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEUNT_SILEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEUNT_REUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEUNT_RETEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEUNT_MDLEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEUNT_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswdbe, VecWdbeVPreset::PREWDBEREFSIL, jref);
};

PnlWdbeSilDetail::~PnlWdbeSilDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* PnlWdbeSilDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupPkg, &feedFPupRet, &feedFPupTch, &feedFPupTyp, &statshr, items);
	};

	return dpcheng;
};

void PnlWdbeSilDetail::refreshPupPkg(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.numFPupPkg = 0;

	for (unsigned int i = 0; i < feedFPupPkg.size(); i++) {
		if (feedFPupPkg.getSrefByNum(i+1) == contiac.TxfPkg) {
			contiac.numFPupPkg = i+1;
			break;
		};
	};

	// statshr
	statshr.TxfPkgValid = (contiac.numFPupPkg != 0);
	statshr.PupPkgActive = evalPupPkgActive(dbswdbe);
	statshr.ButPkgEditAvail = evalButPkgEditAvail(dbswdbe);

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeSilDetail::refreshTxfPkg(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.TxfPkg = feedFPupPkg.getSrefByNum(contiac.numFPupPkg);

	// statshr
	statshr.TxfPkgValid = true;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeSilDetail::refreshPkg(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	// feedFPupPkg

	insert(moditems, DpchEngData::FEEDFPUPPKG);

	refreshPupPkg(dbswdbe, moditems);
};

void PnlWdbeSilDetail::refreshPupTch(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.numFPupTch = 0;

	for (unsigned int i = 0; i < feedFPupTch.size(); i++) {
		if (feedFPupTch.getSrefByNum(i+1) == contiac.TxfTch) {
			contiac.numFPupTch = i+1;
			break;
		};
	};

	// statshr
	statshr.TxfTchValid = (contiac.numFPupTch != 0);
	statshr.PupTchActive = evalPupTchActive(dbswdbe);
	statshr.ButTchEditAvail = evalButTchEditAvail(dbswdbe);

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeSilDetail::refreshTxfTch(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.TxfTch = feedFPupTch.getSrefByNum(contiac.numFPupTch);

	// statshr
	statshr.TxfTchValid = true;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeSilDetail::refreshTch(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	// feedFPupTch

	insert(moditems, DpchEngData::FEEDFPUPTCH);

	refreshPupTch(dbswdbe, moditems);
};

void PnlWdbeSilDetail::refreshRecUnt(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WdbeMUnit* _recUnt = NULL;

	if (dbswdbe->tblwdbemunit->loadRecByRef(recUnt.ref, &_recUnt)) {
		recUnt = *_recUnt;
		ixWSubsetUnt = dbswdbe->getIxWSubsetByWdbeMUnit(_recUnt);
		delete _recUnt;
	} else {
		recUnt = WdbeMUnit();
		ixWSubsetUnt = 0;
	};

	dirty = false;

	continf.TxtSrf = recUnt.sref;
	contiac.TxfTit = recUnt.Title;
	contiac.TxfFsr = recUnt.Fullsref;
	contiac.numFPupTyp = feedFPupTyp.getNumByIx(recUnt.ixVBasetype);
	contiac.numFPupRet = feedFPupRet.getNumByIx(recUnt.refIxVTbl);
	if (recUnt.refIxVTbl == VecWdbeVMUnitRefTbl::FAM) continf.TxtReu = StubWdbe::getStubFamStd(dbswdbe, recUnt.refUref, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	else if (recUnt.refIxVTbl == VecWdbeVMUnitRefTbl::VER) continf.TxtReu = StubWdbe::getStubVerStd(dbswdbe, recUnt.refUref, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	else continf.TxtReu = "-";
	continf.TxtSys = StubWdbe::getStubSysStd(dbswdbe, recUnt.refWdbeMSystem, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	continf.TxtMdl = StubWdbe::getStubMdlStd(dbswdbe, recUnt.refWdbeMModule, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfPkg = recUnt.srefKPackage;
	contiac.ChkEsy = recUnt.Easy;
	contiac.TxfTch = recUnt.srefKToolch;
	contiac.TxfCmt = recUnt.Comment;

	statshr.TxtSrfActive = evalTxtSrfActive(dbswdbe);
	statshr.TxfTitActive = evalTxfTitActive(dbswdbe);
	statshr.TxfFsrActive = evalTxfFsrActive(dbswdbe);
	statshr.PupTypActive = evalPupTypActive(dbswdbe);
	statshr.TxtReuActive = evalTxtReuActive(dbswdbe);
	statshr.ButReuViewAvail = evalButReuViewAvail(dbswdbe);
	statshr.ButReuViewActive = evalButReuViewActive(dbswdbe);
	statshr.TxtSysActive = evalTxtSysActive(dbswdbe);
	statshr.ButSysViewAvail = evalButSysViewAvail(dbswdbe);
	statshr.ButSysViewActive = evalButSysViewActive(dbswdbe);
	statshr.TxtMdlActive = evalTxtMdlActive(dbswdbe);
	statshr.ButMdlViewAvail = evalButMdlViewAvail(dbswdbe);
	statshr.ButMdlViewActive = evalButMdlViewActive(dbswdbe);
	statshr.ChkEsyActive = evalChkEsyActive(dbswdbe);
	statshr.TxfCmtActive = evalTxfCmtActive(dbswdbe);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshPupPkg(dbswdbe, moditems);
	refreshPupTch(dbswdbe, moditems);

};

void PnlWdbeSilDetail::refresh(
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

void PnlWdbeSilDetail::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFSIL) {
		recUnt.ref = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSIL, jref);
		refreshRecUnt(dbswdbe, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWdbeSilDetail::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESILDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswdbe, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESILDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREUVIEWCLICK) {
					handleDpchAppDoButReuViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSYSVIEWCLICK) {
					handleDpchAppDoButSysViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTMDLVIEWCLICK) {
					handleDpchAppDoButMdlViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPKGEDITCLICK) {
					handleDpchAppDoButPkgEditClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTTCHEDITCLICK) {
					handleDpchAppDoButTchEditClick(dbswdbe, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWdbeSilDetail::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWdbeSilDetail::handleDpchAppDataContiac(
			DbsWdbe* dbswdbe
			, ContIac* _contiac
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFTIT, ContIac::TXFFSR, ContIac::NUMFPUPTYP, ContIac::CHKESY, ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::TXFTIT)) contiac.TxfTit = _contiac->TxfTit;
		if (has(diffitems, ContIac::TXFFSR)) contiac.TxfFsr = _contiac->TxfFsr;
		if (has(diffitems, ContIac::NUMFPUPTYP)) contiac.numFPupTyp = _contiac->numFPupTyp;
		if (has(diffitems, ContIac::CHKESY)) contiac.ChkEsy = _contiac->ChkEsy;
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
	};

	if (has(diffitems, ContIac::TXFPKG)) {
		contiac.TxfPkg = _contiac->TxfPkg;
		refreshPupPkg(dbswdbe, moditems);
	} else if (has(diffitems, ContIac::NUMFPUPPKG)) {
		contiac.numFPupPkg = _contiac->numFPupPkg;
		refreshTxfPkg(dbswdbe, moditems);
	};

	if (has(diffitems, ContIac::TXFTCH)) {
		contiac.TxfTch = _contiac->TxfTch;
		refreshPupTch(dbswdbe, moditems);
	} else if (has(diffitems, ContIac::NUMFPUPTCH)) {
		contiac.numFPupTch = _contiac->numFPupTch;
		refreshTxfTch(dbswdbe, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWdbeSilDetail::handleDpchAppDoButSaveClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWdbeSilDetail::handleDpchAppDoButReuViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButReuViewAvail && statshr.ButReuViewActive) {
		if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVER, jref)) if (recUnt.refIxVTbl == VecWdbeVMUnitRefTbl::VER) {
			sref = "CrdWdbeVer";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, sref, recUnt.refUref, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCFAM, jref)) if (recUnt.refIxVTbl == VecWdbeVMUnitRefTbl::FAM) {
				sref = "CrdWdbeFam";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, sref, recUnt.refUref, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, sref);
	};
};

void PnlWdbeSilDetail::handleDpchAppDoButSysViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	ubigint refVer = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref);

	if (statshr.ButSysViewAvail && statshr.ButSysViewActive) {
		if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSYS, jref)) if (refVer != 0) {
			sref = "CrdWdbeSys";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, VecWdbeVPreset::PREWDBEREFVER, refVer, sref, recUnt.refWdbeMSystem, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, sref);
	};
};

void PnlWdbeSilDetail::handleDpchAppDoButMdlViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	ubigint refUnt = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref);

	if (statshr.ButMdlViewAvail && statshr.ButMdlViewActive) {
		if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref)) if (refUnt != 0) {
			sref = "CrdWdbeMod";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, VecWdbeVPreset::PREWDBEREFUNT, refUnt, sref, recUnt.refWdbeMModule, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, sref);
	};
};

void PnlWdbeSilDetail::handleDpchAppDoButPkgEditClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButPkgEditClick --- INSERT
};

void PnlWdbeSilDetail::handleDpchAppDoButTchEditClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButTchEditClick --- INSERT
};

void PnlWdbeSilDetail::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBEKLSAKEYMOD_KLSEQ) {
		call->abort = handleCallWdbeKlsAkeyMod_klsEq(dbswdbe, call->jref, call->argInv.ix);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEUNTUPD_REFEQ) {
		call->abort = handleCallWdbeUntUpd_refEq(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEUNT_SYSEQ) {
		call->abort = handleCallWdbeUnt_sysEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEUNT_SILEQ) {
		call->abort = handleCallWdbeUnt_silEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEUNT_REUEQ) {
		call->abort = handleCallWdbeUnt_reuEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEUNT_RETEQ) {
		call->abort = handleCallWdbeUnt_retEq(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEUNT_MDLEQ) {
		call->abort = handleCallWdbeUnt_mdlEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEUNT_INSBS) {
		call->abort = handleCallWdbeUnt_inSbs(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	};
};

bool PnlWdbeSilDetail::handleCallWdbeKlsAkeyMod_klsEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
		) {
	bool retval = false;
	set<uint> moditems;

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

bool PnlWdbeSilDetail::handleCallWdbeUntUpd_refEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWdbeUntUpd_refEq --- INSERT
	return retval;
};

bool PnlWdbeSilDetail::handleCallWdbeUnt_sysEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recUnt.refWdbeMSystem == refInv); // IP handleCallWdbeUnt_sysEq --- LINE
	return retval;
};

bool PnlWdbeSilDetail::handleCallWdbeUnt_silEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recUnt.silRefWdbeMUnit == refInv); // IP handleCallWdbeUnt_silEq --- LINE
	return retval;
};

bool PnlWdbeSilDetail::handleCallWdbeUnt_reuEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recUnt.refUref == refInv); // IP handleCallWdbeUnt_reuEq --- LINE
	return retval;
};

bool PnlWdbeSilDetail::handleCallWdbeUnt_retEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recUnt.refIxVTbl == ixInv); // IP handleCallWdbeUnt_retEq --- LINE
	return retval;
};

bool PnlWdbeSilDetail::handleCallWdbeUnt_mdlEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recUnt.refWdbeMModule == refInv); // IP handleCallWdbeUnt_mdlEq --- LINE
	return retval;
};

bool PnlWdbeSilDetail::handleCallWdbeUnt_inSbs(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((ixWSubsetUnt & ixInv) != 0); // IP handleCallWdbeUnt_inSbs --- LINE
	return retval;
};
