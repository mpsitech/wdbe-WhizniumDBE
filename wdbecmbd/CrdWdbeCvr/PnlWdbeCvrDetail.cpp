/**
	* \file PnlWdbeCvrDetail.cpp
	* job handler for job PnlWdbeCvrDetail (implementation)
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

#include "PnlWdbeCvrDetail.h"

#include "PnlWdbeCvrDetail_blks.cpp"
#include "PnlWdbeCvrDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWdbeCvrDetail
 ******************************************************************************/

PnlWdbeCvrDetail::PnlWdbeCvrDetail(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::PNLWDBECVRDETAIL, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFLstSty.tag = "FeedFLstSty";
	VecWdbeWMCoreversionSpectype::fillFeed(ixWdbeVLocale, feedFLstSty);
	feedFPupJst.tag = "FeedFPupJst";
	feedFPupSte.tag = "FeedFPupSte";
	VecWdbeVMCoreversionState::fillFeed(ixWdbeVLocale, feedFPupSte);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWdbeVCall::CALLWDBECVR_CPREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBECVR_BCVEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswdbe, VecWdbeVPreset::PREWDBEREFCVR, jref);
};

PnlWdbeCvrDetail::~PnlWdbeCvrDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* PnlWdbeCvrDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFLstSty, &feedFPupJst, &feedFPupSte, &statshr, items);
	};

	return dpcheng;
};

void PnlWdbeCvrDetail::refreshJst(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ListWdbeJMCoreversionState cvrJstes;
	WdbeJMCoreversionState* cvrJste = NULL;

	string s;

	// feedFPupJst
	feedFPupJst.clear();

	dbswdbe->tblwdbejmcoreversionstate->loadRstByCvr(recCvr.ref, false, cvrJstes);

	for (unsigned int i = 0; i < cvrJstes.nodes.size(); i++) {
		cvrJste = cvrJstes.nodes[i];

		s = "";
		if (cvrJste->x1Start != 0) {
			s = Ftm::stamp(cvrJste->x1Start) + " -";
			if ((i+2) < cvrJstes.nodes.size()) if (cvrJstes.nodes[i+1]->x1Start != 0) s += " " + Ftm::stamp(cvrJstes.nodes[i+1]->x1Start);
		} else s = "(" + VecWdbeVTag::getTitle(VecWdbeVTag::ALWAYS, ixWdbeVLocale) + ")";
		feedFPupJst.appendRefTitles(cvrJste->ref, s);
	};

	insert(moditems, DpchEngData::FEEDFPUPJST);

	refreshRecCvrJste(dbswdbe, moditems);

};

void PnlWdbeCvrDetail::refreshTxtSty(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);

	uint ix = 0;
	for (unsigned int i = 0; i < contiac.numsFLstSty.size(); i++) ix |= feedFLstSty.getIxByNum(contiac.numsFLstSty[i]);
	continf.TxtSty = VecWdbeWMCoreversionSpectype::getSrefs(ix);

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
};

void PnlWdbeCvrDetail::refreshRecCvr(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	set<uint> ics;

	WdbeMCoreversion* _recCvr = NULL;

	if (dbswdbe->tblwdbemcoreversion->loadRecByRef(recCvr.ref, &_recCvr)) {
		recCvr = *_recCvr;
		delete _recCvr;
	} else recCvr = WdbeMCoreversion();

	dirty = false;

	recCvrJste.ref = recCvr.refJState;
	if (recCvr.ref == 0) xchg->removeClstns(VecWdbeVCall::CALLWDBECVRJSTEMOD_CVREQ, jref);
	else xchg->addRefClstn(VecWdbeVCall::CALLWDBECVRJSTEMOD_CVREQ, jref, Clstn::VecVJobmask::ALL, 0, true, recCvr.ref);

	continf.TxtCpr = StubWdbe::getStubCprStd(dbswdbe, recCvr.refWdbeMCoreproject, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfMaj = to_string(recCvr.Major);
	contiac.TxfMin = to_string(recCvr.Minor);
	contiac.TxfSub = to_string(recCvr.Sub);
	continf.TxtBcv = StubWdbe::getStubCvrStd(dbswdbe, recCvr.bcvRefWdbeMCoreversion, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	contiac.numsFLstSty.clear();
	VecWdbeWMCoreversionSpectype::getIcs(recCvr.ixWSpectype, ics);
	for (auto it = ics.begin(); it != ics.end(); it++) contiac.numsFLstSty.push_back(feedFLstSty.getNumByIx(*it));

	statshr.TxtCprActive = evalTxtCprActive(dbswdbe);
	statshr.ButCprViewAvail = evalButCprViewAvail(dbswdbe);
	statshr.ButCprViewActive = evalButCprViewActive(dbswdbe);
	statshr.TxfMajActive = evalTxfMajActive(dbswdbe);
	statshr.TxfMinActive = evalTxfMinActive(dbswdbe);
	statshr.TxfSubActive = evalTxfSubActive(dbswdbe);
	statshr.TxtBcvActive = evalTxtBcvActive(dbswdbe);
	statshr.ButBcvViewAvail = evalButBcvViewAvail(dbswdbe);
	statshr.ButBcvViewActive = evalButBcvViewActive(dbswdbe);
	statshr.LstStyActive = evalLstStyActive(dbswdbe);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshJst(dbswdbe, moditems);
	refreshTxtSty(dbswdbe, moditems);

};

void PnlWdbeCvrDetail::refreshRecCvrJste(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	set<uint> ics;

	WdbeJMCoreversionState* _recCvrJste = NULL;

	if (dbswdbe->tblwdbejmcoreversionstate->loadRecByRef(recCvrJste.ref, &_recCvrJste)) {
		recCvrJste = *_recCvrJste;
		delete _recCvrJste;
	} else recCvrJste = WdbeJMCoreversionState();

	contiac.numFPupJst = feedFPupJst.getNumByRef(recCvrJste.ref);
	contiac.numFPupSte = feedFPupSte.getNumByIx(recCvrJste.ixVState);

	statshr.PupJstActive = evalPupJstActive(dbswdbe);
	statshr.ButJstEditAvail = evalButJstEditAvail(dbswdbe);
	statshr.PupSteActive = evalPupSteActive(dbswdbe);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWdbeCvrDetail::refresh(
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

void PnlWdbeCvrDetail::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFCVR) {
		recCvr.ref = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCVR, jref);
		refreshRecCvr(dbswdbe, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWdbeCvrDetail::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECVRDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswdbe, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBECVRDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCPRVIEWCLICK) {
					handleDpchAppDoButCprViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTBCVVIEWCLICK) {
					handleDpchAppDoButBcvViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTJSTEDITCLICK) {
					handleDpchAppDoButJstEditClick(dbswdbe, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWdbeCvrDetail::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWdbeCvrDetail::handleDpchAppDataContiac(
			DbsWdbe* dbswdbe
			, ContIac* _contiac
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFMAJ, ContIac::TXFMIN, ContIac::TXFSUB, ContIac::NUMFPUPSTE})) {
		if (has(diffitems, ContIac::TXFMAJ)) contiac.TxfMaj = _contiac->TxfMaj;
		if (has(diffitems, ContIac::TXFMIN)) contiac.TxfMin = _contiac->TxfMin;
		if (has(diffitems, ContIac::TXFSUB)) contiac.TxfSub = _contiac->TxfSub;
		if (has(diffitems, ContIac::NUMFPUPSTE)) contiac.numFPupSte = _contiac->numFPupSte;
	};

	if (has(diffitems, ContIac::NUMFPUPJST)) {
		recCvrJste.ref = feedFPupJst.getRefByNum(_contiac->numFPupJst);
		refreshRecCvrJste(dbswdbe, moditems);
	};

	if (has(diffitems, ContIac::NUMSFLSTSTY)) {
		contiac.numsFLstSty = _contiac->numsFLstSty;
		refreshTxtSty(dbswdbe, moditems);
		refresh(dbswdbe, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWdbeCvrDetail::handleDpchAppDoButSaveClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWdbeCvrDetail::handleDpchAppDoButCprViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButCprViewAvail && statshr.ButCprViewActive) {
		if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCPR, jref)) {
			sref = "CrdWdbeCpr";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, sref, recCvr.refWdbeMCoreproject, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, sref);
	};
};

void PnlWdbeCvrDetail::handleDpchAppDoButBcvViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButBcvViewAvail && statshr.ButBcvViewActive) {
		if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCVR, jref)) if (ixPre == VecWdbeVPreset::PREWDBEREFCPR) {
			sref = "CrdWdbeCvr";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, ixPre, refPre, sref, recCvr.bcvRefWdbeMCoreversion, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCVR, jref)) {
				sref = "CrdWdbeCvr";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, sref, recCvr.bcvRefWdbeMCoreversion, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, sref);
	};
};

void PnlWdbeCvrDetail::handleDpchAppDoButJstEditClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButJstEditClick --- INSERT
};

void PnlWdbeCvrDetail::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBECVRJSTEMOD_CVREQ) {
		call->abort = handleCallWdbeCvrJsteMod_cvrEq(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBECVRUPD_REFEQ) {
		call->abort = handleCallWdbeCvrUpd_refEq(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBECVR_CPREQ) {
		call->abort = handleCallWdbeCvr_cprEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBECVR_BCVEQ) {
		call->abort = handleCallWdbeCvr_bcvEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWdbeCvrDetail::handleCallWdbeCvrJsteMod_cvrEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	set<uint> moditems;

	refreshJst(dbswdbe, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

bool PnlWdbeCvrDetail::handleCallWdbeCvrUpd_refEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWdbeCvrUpd_refEq --- INSERT
	return retval;
};

bool PnlWdbeCvrDetail::handleCallWdbeCvr_cprEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recCvr.refWdbeMCoreproject == refInv); // IP handleCallWdbeCvr_cprEq --- LINE
	return retval;
};

bool PnlWdbeCvrDetail::handleCallWdbeCvr_bcvEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recCvr.bcvRefWdbeMCoreversion == refInv); // IP handleCallWdbeCvr_bcvEq --- LINE
	return retval;
};
