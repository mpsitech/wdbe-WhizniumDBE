/**
	* \file PnlWdbeSegDetail.cpp
	* job handler for job PnlWdbeSegDetail (implementation)
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

#include "PnlWdbeSegDetail.h"

#include "PnlWdbeSegDetail_blks.cpp"
#include "PnlWdbeSegDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWdbeSegDetail
 ******************************************************************************/

PnlWdbeSegDetail::PnlWdbeSegDetail(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::PNLWDBESEGDETAIL, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFLstClu.tag = "FeedFLstClu";

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWdbeVCall::CALLWDBESEG_CLUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBESEG_SUPEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBESEG_PPLEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswdbe, VecWdbeVPreset::PREWDBEREFSEG, jref);
};

PnlWdbeSegDetail::~PnlWdbeSegDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* PnlWdbeSegDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFLstClu, &statshr, items);
	};

	return dpcheng;
};

void PnlWdbeSegDetail::refreshLstClu(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstCluActive = evalLstCluActive(dbswdbe);
	statshr.ButCluViewActive = evalButCluViewActive(dbswdbe);
	statshr.ButCluClusterAvail = evalButCluClusterAvail(dbswdbe);
	statshr.ButCluUnclusterAvail = evalButCluUnclusterAvail(dbswdbe);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeSegDetail::refreshClu(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);

	vector<ubigint> refs;

	bool first;

	// contiac
	contiac.numFLstClu = 0;

	// feedFLstClu, continf
	feedFLstClu.clear();
	continf.TxtClu = "";

	if (recSeg.refWdbeCSegment != 0) dbswdbe->tblwdbemsegment->loadRefsByClu(recSeg.refWdbeCSegment, false, refs);

	first = true;
	for (unsigned int i = 0; i < refs.size(); i++) {
		if (refs[i] != recSeg.ref) {
			feedFLstClu.appendRefTitles(refs[i], StubWdbe::getStubSegStd(dbswdbe, refs[i], ixWdbeVLocale));

			if (first) first = false;
			else continf.TxtClu += ";";

			continf.TxtClu += StubWdbe::getStubSegStd(dbswdbe, refs[i], ixWdbeVLocale);
		};
	};
	if (first) continf.TxtClu = "-";

	insert(moditems, DpchEngData::FEEDFLSTCLU);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	refreshLstClu(dbswdbe, moditems);
};

void PnlWdbeSegDetail::refreshRecSeg(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WdbeMSegment* _recSeg = NULL;

	if (dbswdbe->tblwdbemsegment->loadRecByRef(recSeg.ref, &_recSeg)) {
		recSeg = *_recSeg;
		delete _recSeg;
	} else recSeg = WdbeMSegment();

	dirty = false;

	if (recSeg.refWdbeCSegment == 0) xchg->removeClstns(VecWdbeVCall::CALLWDBESEGMOD_CLUEQ, jref);
	else xchg->addRefClstn(VecWdbeVCall::CALLWDBESEGMOD_CLUEQ, jref, Clstn::VecVJobmask::ALL, 0, true, recSeg.refWdbeCSegment);

	continf.TxtSrf = recSeg.sref;
	continf.TxtPpl = StubWdbe::getStubPplStd(dbswdbe, recSeg.pplRefWdbeMPipeline, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	continf.TxtSup = StubWdbe::getStubSegStd(dbswdbe, recSeg.supRefWdbeMSegment, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfIfm = recSeg.Infmt;
	contiac.TxfOfm = recSeg.Outfmt;
	contiac.TxfLcy = to_string(recSeg.Latency);
	contiac.TxfCmt = recSeg.Comment;

	statshr.TxtSrfActive = evalTxtSrfActive(dbswdbe);
	statshr.TxtPplActive = evalTxtPplActive(dbswdbe);
	statshr.ButPplViewAvail = evalButPplViewAvail(dbswdbe);
	statshr.ButPplViewActive = evalButPplViewActive(dbswdbe);
	statshr.TxtSupActive = evalTxtSupActive(dbswdbe);
	statshr.ButSupViewAvail = evalButSupViewAvail(dbswdbe);
	statshr.ButSupViewActive = evalButSupViewActive(dbswdbe);
	statshr.TxfIfmActive = evalTxfIfmActive(dbswdbe);
	statshr.TxfOfmActive = evalTxfOfmActive(dbswdbe);
	statshr.TxfLcyActive = evalTxfLcyActive(dbswdbe);
	statshr.TxfCmtActive = evalTxfCmtActive(dbswdbe);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshClu(dbswdbe, moditems);

};

void PnlWdbeSegDetail::refresh(
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

void PnlWdbeSegDetail::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFSEG) {
		recSeg.ref = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSEG, jref);
		refreshRecSeg(dbswdbe, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWdbeSegDetail::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESEGDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswdbe, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESEGDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLUVIEWCLICK) {
					handleDpchAppDoButCluViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLUCLUSTERCLICK) {
					handleDpchAppDoButCluClusterClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLUUNCLUSTERCLICK) {
					handleDpchAppDoButCluUnclusterClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPPLVIEWCLICK) {
					handleDpchAppDoButPplViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSUPVIEWCLICK) {
					handleDpchAppDoButSupViewClick(dbswdbe, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWdbeSegDetail::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWdbeSegDetail::handleDpchAppDataContiac(
			DbsWdbe* dbswdbe
			, ContIac* _contiac
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFIFM, ContIac::TXFOFM, ContIac::TXFLCY, ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::TXFIFM)) contiac.TxfIfm = _contiac->TxfIfm;
		if (has(diffitems, ContIac::TXFOFM)) contiac.TxfOfm = _contiac->TxfOfm;
		if (has(diffitems, ContIac::TXFLCY)) contiac.TxfLcy = _contiac->TxfLcy;
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
	};

	if (has(diffitems, ContIac::NUMFLSTCLU)) {
		contiac.numFLstClu = _contiac->numFLstClu;
		refreshLstClu(dbswdbe, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWdbeSegDetail::handleDpchAppDoButSaveClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWdbeSegDetail::handleDpchAppDoButCluViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButCluViewClick --- INSERT
};

void PnlWdbeSegDetail::handleDpchAppDoButCluClusterClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButCluClusterClick --- INSERT
};

void PnlWdbeSegDetail::handleDpchAppDoButCluUnclusterClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButCluUnclusterClick --- INSERT
};

void PnlWdbeSegDetail::handleDpchAppDoButPplViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButPplViewAvail && statshr.ButPplViewActive) {
		if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPPL, jref)) if (ixPre == VecWdbeVPreset::PREWDBEREFUNT) {
			sref = "CrdWdbePpl";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, ixPre, refPre, sref, recSeg.pplRefWdbeMPipeline, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, sref);
	};
};

void PnlWdbeSegDetail::handleDpchAppDoButSupViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButSupViewAvail && statshr.ButSupViewActive) {
		if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSEG, jref)) if (ixPre == VecWdbeVPreset::PREWDBEREFPPL) {
			sref = "CrdWdbeSeg";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, ixPre, refPre, sref, recSeg.supRefWdbeMSegment, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSEG, jref)) if (ixPre == VecWdbeVPreset::PREWDBEREFUNT) {
				sref = "CrdWdbeSeg";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, ixPre, refPre, sref, recSeg.supRefWdbeMSegment, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, sref);
	};
};

void PnlWdbeSegDetail::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBESEGMOD_CLUEQ) {
		call->abort = handleCallWdbeSegMod_cluEq(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBESEGUPD_REFEQ) {
		call->abort = handleCallWdbeSegUpd_refEq(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBESEG_CLUEQ) {
		call->abort = handleCallWdbeSeg_cluEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBESEG_SUPEQ) {
		call->abort = handleCallWdbeSeg_supEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBESEG_PPLEQ) {
		call->abort = handleCallWdbeSeg_pplEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWdbeSegDetail::handleCallWdbeSegMod_cluEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	set<uint> moditems;

	refreshClu(dbswdbe, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

bool PnlWdbeSegDetail::handleCallWdbeSegUpd_refEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWdbeSegUpd_refEq --- INSERT
	return retval;
};

bool PnlWdbeSegDetail::handleCallWdbeSeg_cluEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recSeg.refWdbeCSegment == refInv); // IP handleCallWdbeSeg_cluEq --- LINE
	return retval;
};

bool PnlWdbeSegDetail::handleCallWdbeSeg_supEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recSeg.supRefWdbeMSegment == refInv); // IP handleCallWdbeSeg_supEq --- LINE
	return retval;
};

bool PnlWdbeSegDetail::handleCallWdbeSeg_pplEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recSeg.pplRefWdbeMPipeline == refInv); // IP handleCallWdbeSeg_pplEq --- LINE
	return retval;
};
