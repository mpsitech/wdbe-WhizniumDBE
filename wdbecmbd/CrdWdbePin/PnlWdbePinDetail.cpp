/**
	* \file PnlWdbePinDetail.cpp
	* job handler for job PnlWdbePinDetail (implementation)
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

#include "PnlWdbePinDetail.h"

#include "PnlWdbePinDetail_blks.cpp"
#include "PnlWdbePinDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWdbePinDetail
 ******************************************************************************/

PnlWdbePinDetail::PnlWdbePinDetail(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::PNLWDBEPINDETAIL, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFLstClu.tag = "FeedFLstClu";
	feedFPupJsr.tag = "FeedFPupJsr";

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWdbeVCall::CALLWDBEPIN_CLUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEPIN_BNKEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswdbe, VecWdbeVPreset::PREWDBEREFPIN, jref);
};

PnlWdbePinDetail::~PnlWdbePinDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* PnlWdbePinDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFLstClu, &feedFPupJsr, &statshr, items);
	};

	return dpcheng;
};

void PnlWdbePinDetail::refreshJsr(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ListWdbeJMPinSref pinJsrfs;
	WdbeJMPinSref* pinJsrf = NULL;

	string s;

	// feedFPupJsr
	feedFPupJsr.clear();

	dbswdbe->tblwdbejmpinsref->loadRstByPin(recPin.ref, false, pinJsrfs);

	for (unsigned int i = 0; i < pinJsrfs.nodes.size(); i++) {
		pinJsrf = pinJsrfs.nodes[i];

		s = "";
		s = StubWdbe::getStubPphStd(dbswdbe, pinJsrf->x1RefWdbeMPeripheral, ixWdbeVLocale);
		if (s == "-") s = "(" + VecWdbeVTag::getTitle(VecWdbeVTag::GENERAL, ixWdbeVLocale) + ")";
		feedFPupJsr.appendRefTitles(pinJsrf->ref, s);
	};

	insert(moditems, DpchEngData::FEEDFPUPJSR);

	refreshRecPinJsrf(dbswdbe, moditems);

};

void PnlWdbePinDetail::refreshLstClu(
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

void PnlWdbePinDetail::refreshClu(
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

	if (recPin.refWdbeCPin != 0) dbswdbe->tblwdbempin->loadRefsByClu(recPin.refWdbeCPin, false, refs);

	first = true;
	for (unsigned int i = 0; i < refs.size(); i++) {
		if (refs[i] != recPin.ref) {
			feedFLstClu.appendRefTitles(refs[i], StubWdbe::getStubPinStd(dbswdbe, refs[i], ixWdbeVLocale));

			if (first) first = false;
			else continf.TxtClu += ";";

			continf.TxtClu += StubWdbe::getStubPinStd(dbswdbe, refs[i], ixWdbeVLocale);
		};
	};
	if (first) continf.TxtClu = "-";

	insert(moditems, DpchEngData::FEEDFLSTCLU);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	refreshLstClu(dbswdbe, moditems);
};

void PnlWdbePinDetail::refreshRecPin(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WdbeMPin* _recPin = NULL;

	if (dbswdbe->tblwdbempin->loadRecByRef(recPin.ref, &_recPin)) {
		recPin = *_recPin;
		delete _recPin;
	} else recPin = WdbeMPin();

	dirty = false;

	recPinJsrf.ref = recPin.refJSref;
	if (recPin.ref == 0) xchg->removeClstns(VecWdbeVCall::CALLWDBEPINJSRFMOD_PINEQ, jref);
	else xchg->addRefClstn(VecWdbeVCall::CALLWDBEPINJSRFMOD_PINEQ, jref, Clstn::VecVJobmask::ALL, 0, true, recPin.ref);

	if (recPin.refWdbeCPin == 0) xchg->removeClstns(VecWdbeVCall::CALLWDBEPINMOD_CLUEQ, jref);
	else xchg->addRefClstn(VecWdbeVCall::CALLWDBEPINMOD_CLUEQ, jref, Clstn::VecVJobmask::ALL, 0, true, recPin.refWdbeCPin);

	continf.TxtBnk = StubWdbe::getStubBnkStd(dbswdbe, recPin.refWdbeMBank, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfLoc = recPin.Location;

	statshr.TxtBnkActive = evalTxtBnkActive(dbswdbe);
	statshr.ButBnkViewAvail = evalButBnkViewAvail(dbswdbe);
	statshr.ButBnkViewActive = evalButBnkViewActive(dbswdbe);
	statshr.TxfLocActive = evalTxfLocActive(dbswdbe);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshJsr(dbswdbe, moditems);
	refreshClu(dbswdbe, moditems);

};

void PnlWdbePinDetail::refreshRecPinJsrf(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WdbeJMPinSref* _recPinJsrf = NULL;

	if (dbswdbe->tblwdbejmpinsref->loadRecByRef(recPinJsrf.ref, &_recPinJsrf)) {
		recPinJsrf = *_recPinJsrf;
		delete _recPinJsrf;
	} else recPinJsrf = WdbeJMPinSref();

	contiac.numFPupJsr = feedFPupJsr.getNumByRef(recPinJsrf.ref);
	continf.TxtSrf = recPinJsrf.sref;

	statshr.PupJsrActive = evalPupJsrActive(dbswdbe);
	statshr.ButJsrEditAvail = evalButJsrEditAvail(dbswdbe);
	statshr.TxtSrfActive = evalTxtSrfActive(dbswdbe);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWdbePinDetail::refresh(
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

void PnlWdbePinDetail::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFPIN) {
		recPin.ref = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFPIN, jref);
		refreshRecPin(dbswdbe, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWdbePinDetail::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPINDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswdbe, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPINDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTJSREDITCLICK) {
					handleDpchAppDoButJsrEditClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLUVIEWCLICK) {
					handleDpchAppDoButCluViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLUCLUSTERCLICK) {
					handleDpchAppDoButCluClusterClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLUUNCLUSTERCLICK) {
					handleDpchAppDoButCluUnclusterClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTBNKVIEWCLICK) {
					handleDpchAppDoButBnkViewClick(dbswdbe, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWdbePinDetail::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWdbePinDetail::handleDpchAppDataContiac(
			DbsWdbe* dbswdbe
			, ContIac* _contiac
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFLOC})) {
		if (has(diffitems, ContIac::TXFLOC)) contiac.TxfLoc = _contiac->TxfLoc;
	};

	if (has(diffitems, ContIac::NUMFPUPJSR)) {
		recPinJsrf.ref = feedFPupJsr.getRefByNum(_contiac->numFPupJsr);
		refreshRecPinJsrf(dbswdbe, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTCLU)) {
		contiac.numFLstClu = _contiac->numFLstClu;
		refreshLstClu(dbswdbe, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWdbePinDetail::handleDpchAppDoButSaveClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWdbePinDetail::handleDpchAppDoButJsrEditClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButJsrEditClick --- INSERT
};

void PnlWdbePinDetail::handleDpchAppDoButCluViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButCluViewClick --- INSERT
};

void PnlWdbePinDetail::handleDpchAppDoButCluClusterClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButCluClusterClick --- INSERT
};

void PnlWdbePinDetail::handleDpchAppDoButCluUnclusterClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButCluUnclusterClick --- INSERT
};

void PnlWdbePinDetail::handleDpchAppDoButBnkViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButBnkViewAvail && statshr.ButBnkViewActive) {
		if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCBNK, jref)) if (ixPre == VecWdbeVPreset::PREWDBEREFUNT) {
			sref = "CrdWdbeBnk";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, ixPre, refPre, sref, recPin.refWdbeMBank, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, sref);
	};
};

void PnlWdbePinDetail::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBEPINMOD_CLUEQ) {
		call->abort = handleCallWdbePinMod_cluEq(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEPINJSRFMOD_PINEQ) {
		call->abort = handleCallWdbePinJsrfMod_pinEq(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEPINUPD_REFEQ) {
		call->abort = handleCallWdbePinUpd_refEq(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEPIN_CLUEQ) {
		call->abort = handleCallWdbePin_cluEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEPIN_BNKEQ) {
		call->abort = handleCallWdbePin_bnkEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWdbePinDetail::handleCallWdbePinMod_cluEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	set<uint> moditems;

	refreshClu(dbswdbe, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

bool PnlWdbePinDetail::handleCallWdbePinJsrfMod_pinEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	set<uint> moditems;

	refreshJsr(dbswdbe, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

bool PnlWdbePinDetail::handleCallWdbePinUpd_refEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWdbePinUpd_refEq --- INSERT
	return retval;
};

bool PnlWdbePinDetail::handleCallWdbePin_cluEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recPin.refWdbeCPin == refInv); // IP handleCallWdbePin_cluEq --- LINE
	return retval;
};

bool PnlWdbePinDetail::handleCallWdbePin_bnkEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recPin.refWdbeMBank == refInv); // IP handleCallWdbePin_bnkEq --- LINE
	return retval;
};
