/**
	* \file PnlWdbeBnkDetail.cpp
	* job handler for job PnlWdbeBnkDetail (implementation)
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

#include "PnlWdbeBnkDetail.h"

#include "PnlWdbeBnkDetail_blks.cpp"
#include "PnlWdbeBnkDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWdbeBnkDetail
 ******************************************************************************/

PnlWdbeBnkDetail::PnlWdbeBnkDetail(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::PNLWDBEBNKDETAIL, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFPupVst.tag = "FeedFPupVst";
	dbswdbe->fillFeedFromKlst(VecWdbeVKeylist::KLSTWDBEKMBANKVOLTSTD, ixWdbeVLocale, feedFPupVst);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWdbeVCall::CALLWDBEKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEBNK_UNT_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEBNK_UNTEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	xchg->addIxClstn(VecWdbeVCall::CALLWDBEKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWdbeVKeylist::KLSTWDBEKMBANKVOLTSTD);

	updatePreset(dbswdbe, VecWdbeVPreset::PREWDBEREFBNK, jref);
};

PnlWdbeBnkDetail::~PnlWdbeBnkDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* PnlWdbeBnkDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupVst, &statshr, items);
	};

	return dpcheng;
};

void PnlWdbeBnkDetail::refreshPupVst(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.numFPupVst = 0;

	for (unsigned int i = 0; i < feedFPupVst.size(); i++) {
		if (feedFPupVst.getSrefByNum(i+1) == contiac.TxfVst) {
			contiac.numFPupVst = i+1;
			break;
		};
	};

	// statshr
	statshr.TxfVstValid = (contiac.numFPupVst != 0);
	statshr.PupVstActive = evalPupVstActive(dbswdbe);
	statshr.ButVstEditAvail = evalButVstEditAvail(dbswdbe);

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeBnkDetail::refreshTxfVst(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.TxfVst = feedFPupVst.getSrefByNum(contiac.numFPupVst);

	// statshr
	statshr.TxfVstValid = true;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeBnkDetail::refreshVst(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	// feedFPupVst
	dbswdbe->fillFeedFromKlst(VecWdbeVKeylist::KLSTWDBEKMBANKVOLTSTD, ixWdbeVLocale, feedFPupVst);

	insert(moditems, DpchEngData::FEEDFPUPVST);

	refreshPupVst(dbswdbe, moditems);
};

void PnlWdbeBnkDetail::refreshRecBnk(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WdbeMBank* _recBnk = NULL;

	if (dbswdbe->tblwdbembank->loadRecByRef(recBnk.ref, &_recBnk)) {
		recBnk = *_recBnk;
		delete _recBnk;
	} else recBnk = WdbeMBank();

	dirty = false;

	continf.TxtSrf = recBnk.sref;
	continf.TxtUnt = StubWdbe::getStubUntStd(dbswdbe, recBnk.refWdbeMUnit, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfVst = recBnk.srefKVoltstd;

	statshr.TxtSrfActive = evalTxtSrfActive(dbswdbe);
	statshr.TxtUntActive = evalTxtUntActive(dbswdbe);
	statshr.ButUntViewAvail = evalButUntViewAvail(dbswdbe);
	statshr.ButUntViewActive = evalButUntViewActive(dbswdbe);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshPupVst(dbswdbe, moditems);

};

void PnlWdbeBnkDetail::refresh(
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

void PnlWdbeBnkDetail::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFBNK) {
		recBnk.ref = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFBNK, jref);
		refreshRecBnk(dbswdbe, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWdbeBnkDetail::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEBNKDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswdbe, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEBNKDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTUNTVIEWCLICK) {
					handleDpchAppDoButUntViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTVSTEDITCLICK) {
					handleDpchAppDoButVstEditClick(dbswdbe, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWdbeBnkDetail::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWdbeBnkDetail::handleDpchAppDataContiac(
			DbsWdbe* dbswdbe
			, ContIac* _contiac
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::TXFVST)) {
		contiac.TxfVst = _contiac->TxfVst;
		refreshPupVst(dbswdbe, moditems);
	} else if (has(diffitems, ContIac::NUMFPUPVST)) {
		contiac.numFPupVst = _contiac->numFPupVst;
		refreshTxfVst(dbswdbe, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWdbeBnkDetail::handleDpchAppDoButSaveClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWdbeBnkDetail::handleDpchAppDoButUntViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	ubigint refVer = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref);

	if (statshr.ButUntViewAvail && statshr.ButUntViewActive) {
		if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCUNT, jref)) if (refVer != 0) {
			sref = "CrdWdbeUnt";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, VecWdbeVPreset::PREWDBEREFVER, refVer, sref, recBnk.refWdbeMUnit, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIL, jref)) if ((dbswdbe->getIxWSubsetByRefWdbeMUnit(recBnk.refWdbeMUnit) & VecWdbeWMUnitSubset::SBSWDBEBMUNITSIL) != 0) {
				sref = "CrdWdbeSil";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, sref, recBnk.refWdbeMUnit, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, sref);
	};
};

void PnlWdbeBnkDetail::handleDpchAppDoButVstEditClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButVstEditClick --- INSERT
};

void PnlWdbeBnkDetail::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBEKLSAKEYMOD_KLSEQ) {
		call->abort = handleCallWdbeKlsAkeyMod_klsEq(dbswdbe, call->jref, call->argInv.ix);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEBNKUPD_REFEQ) {
		call->abort = handleCallWdbeBnkUpd_refEq(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEBNK_UNT_INSBS) {
		call->abort = handleCallWdbeBnk_unt_inSbs(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEBNK_UNTEQ) {
		call->abort = handleCallWdbeBnk_untEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWdbeBnkDetail::handleCallWdbeKlsAkeyMod_klsEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecWdbeVKeylist::KLSTWDBEKMBANKVOLTSTD) {
		refreshVst(dbswdbe, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

bool PnlWdbeBnkDetail::handleCallWdbeBnkUpd_refEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWdbeBnkUpd_refEq --- INSERT
	return retval;
};

bool PnlWdbeBnkDetail::handleCallWdbeBnk_unt_inSbs(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((dbswdbe->getIxWSubsetByRefWdbeMUnit(recBnk.refWdbeMUnit) & ixInv) != 0); // IP handleCallWdbeBnk_unt_inSbs --- LINE
	return retval;
};

bool PnlWdbeBnkDetail::handleCallWdbeBnk_untEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recBnk.refWdbeMUnit == refInv); // IP handleCallWdbeBnk_untEq --- LINE
	return retval;
};
