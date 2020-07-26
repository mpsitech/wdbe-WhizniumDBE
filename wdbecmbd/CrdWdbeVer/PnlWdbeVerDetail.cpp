/**
	* \file PnlWdbeVerDetail.cpp
	* job handler for job PnlWdbeVerDetail (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbed.h>
#endif

#include "PnlWdbeVerDetail.h"

#include "PnlWdbeVerDetail_blks.cpp"
#include "PnlWdbeVerDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWdbeVerDetail
 ******************************************************************************/

PnlWdbeVerDetail::PnlWdbeVerDetail(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::PNLWDBEVERDETAIL, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFPupJst.tag = "FeedFPupJst";
	feedFPupSte.tag = "FeedFPupSte";
	VecWdbeVMVersionState::fillFeed(ixWdbeVLocale, feedFPupSte);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWdbeVCall::CALLWDBEVER_STEEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEVER_PRJEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEVER_BVREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswdbe, VecWdbeVPreset::PREWDBEREFVER, jref);
};

PnlWdbeVerDetail::~PnlWdbeVerDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* PnlWdbeVerDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupJst, &feedFPupSte, &statshr, items);
	};

	return dpcheng;
};

void PnlWdbeVerDetail::refreshJst(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ListWdbeJMVersionState verJstes;
	WdbeJMVersionState* verJste = NULL;

	string s;

	// feedFPupJst
	feedFPupJst.clear();

	dbswdbe->tblwdbejmversionstate->loadRstByVer(recVer.ref, false, verJstes);

	for (unsigned int i = 0; i < verJstes.nodes.size(); i++) {
		verJste = verJstes.nodes[i];

		s = "";
		if (verJste->x1Start != 0) {
			s = Ftm::stamp(verJste->x1Start) + " -";
			if ((i+2) < verJstes.nodes.size()) if (verJstes.nodes[i+1]->x1Start != 0) s += " " + Ftm::stamp(verJstes.nodes[i+1]->x1Start);
		} else s = "(" + VecWdbeVTag::getTitle(VecWdbeVTag::ALWAYS, ixWdbeVLocale) + ")";
		feedFPupJst.appendRefTitles(verJste->ref, s);
	};

	insert(moditems, DpchEngData::FEEDFPUPJST);

	refreshRecVerJste(dbswdbe, moditems);

};

void PnlWdbeVerDetail::refreshRecVer(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WdbeMVersion* _recVer = NULL;

	if (dbswdbe->tblwdbemversion->loadRecByRef(recVer.ref, &_recVer)) {
		recVer = *_recVer;
		delete _recVer;
	} else recVer = WdbeMVersion();

	dirty = false;

	recVerJste.ref = recVer.refJState;
	if (recVer.ref == 0) xchg->removeClstns(VecWdbeVCall::CALLWDBEVERJSTEMOD_VEREQ, jref);
	else xchg->addRefClstn(VecWdbeVCall::CALLWDBEVERJSTEMOD_VEREQ, jref, Clstn::VecVJobmask::ALL, 0, true, recVer.ref);

	continf.TxtPrj = StubWdbe::getStubPrjStd(dbswdbe, recVer.refWdbeMProject, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfMaj = to_string(recVer.Major);
	contiac.TxfMin = to_string(recVer.Minor);
	contiac.TxfSub = to_string(recVer.Sub);
	continf.TxtBvr = StubWdbe::getStubVerStd(dbswdbe, recVer.bvrRefWdbeMVersion, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfAbt = recVer.About;
	contiac.TxfCmt = recVer.Comment;

	statshr.TxtPrjActive = evalTxtPrjActive(dbswdbe);
	statshr.ButPrjViewAvail = evalButPrjViewAvail(dbswdbe);
	statshr.ButPrjViewActive = evalButPrjViewActive(dbswdbe);
	statshr.TxfMajActive = evalTxfMajActive(dbswdbe);
	statshr.TxfMinActive = evalTxfMinActive(dbswdbe);
	statshr.TxfSubActive = evalTxfSubActive(dbswdbe);
	statshr.TxtBvrActive = evalTxtBvrActive(dbswdbe);
	statshr.ButBvrViewAvail = evalButBvrViewAvail(dbswdbe);
	statshr.ButBvrViewActive = evalButBvrViewActive(dbswdbe);
	statshr.TxfAbtActive = evalTxfAbtActive(dbswdbe);
	statshr.TxfCmtActive = evalTxfCmtActive(dbswdbe);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshJst(dbswdbe, moditems);

};

void PnlWdbeVerDetail::refreshRecVerJste(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WdbeJMVersionState* _recVerJste = NULL;

	if (dbswdbe->tblwdbejmversionstate->loadRecByRef(recVerJste.ref, &_recVerJste)) {
		recVerJste = *_recVerJste;
		delete _recVerJste;
	} else recVerJste = WdbeJMVersionState();

	contiac.numFPupJst = feedFPupJst.getNumByRef(recVerJste.ref);
	contiac.numFPupSte = feedFPupSte.getNumByIx(recVerJste.ixVState);

	statshr.PupJstActive = evalPupJstActive(dbswdbe);
	statshr.ButJstEditAvail = evalButJstEditAvail(dbswdbe);
	statshr.PupSteActive = evalPupSteActive(dbswdbe);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWdbeVerDetail::refresh(
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

void PnlWdbeVerDetail::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFVER) {
		recVer.ref = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref);
		refreshRecVer(dbswdbe, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWdbeVerDetail::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVERDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswdbe, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVERDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRJVIEWCLICK) {
					handleDpchAppDoButPrjViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTBVRVIEWCLICK) {
					handleDpchAppDoButBvrViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTJSTEDITCLICK) {
					handleDpchAppDoButJstEditClick(dbswdbe, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWdbeVerDetail::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWdbeVerDetail::handleDpchAppDataContiac(
			DbsWdbe* dbswdbe
			, ContIac* _contiac
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFMAJ, ContIac::TXFMIN, ContIac::TXFSUB, ContIac::NUMFPUPSTE, ContIac::TXFABT, ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::TXFMAJ)) contiac.TxfMaj = _contiac->TxfMaj;
		if (has(diffitems, ContIac::TXFMIN)) contiac.TxfMin = _contiac->TxfMin;
		if (has(diffitems, ContIac::TXFSUB)) contiac.TxfSub = _contiac->TxfSub;
		if (has(diffitems, ContIac::NUMFPUPSTE)) contiac.numFPupSte = _contiac->numFPupSte;
		if (has(diffitems, ContIac::TXFABT)) contiac.TxfAbt = _contiac->TxfAbt;
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
	};

	if (has(diffitems, ContIac::NUMFPUPJST)) {
		recVerJste.ref = feedFPupJst.getRefByNum(_contiac->numFPupJst);
		refreshRecVerJste(dbswdbe, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWdbeVerDetail::handleDpchAppDoButSaveClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWdbeVerDetail::handleDpchAppDoButPrjViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButPrjViewAvail && statshr.ButPrjViewActive) {
		if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPRJ, jref)) {
			sref = "CrdWdbePrj";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, sref, recVer.refWdbeMProject, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, sref);
	};
};

void PnlWdbeVerDetail::handleDpchAppDoButBvrViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButBvrViewAvail && statshr.ButBvrViewActive) {
		if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVER, jref)) if (ixPre == VecWdbeVPreset::PREWDBEREFPRJ) {
			sref = "CrdWdbeVer";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, ixPre, refPre, sref, recVer.bvrRefWdbeMVersion, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVER, jref)) {
				sref = "CrdWdbeVer";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, sref, recVer.bvrRefWdbeMVersion, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, sref);
	};
};

void PnlWdbeVerDetail::handleDpchAppDoButJstEditClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButJstEditClick --- INSERT
};

void PnlWdbeVerDetail::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBEVERJSTEMOD_VEREQ) {
		call->abort = handleCallWdbeVerJsteMod_verEq(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEVERUPD_REFEQ) {
		call->abort = handleCallWdbeVerUpd_refEq(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEVER_STEEQ) {
		call->abort = handleCallWdbeVer_steEq(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEVER_PRJEQ) {
		call->abort = handleCallWdbeVer_prjEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEVER_BVREQ) {
		call->abort = handleCallWdbeVer_bvrEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWdbeVerDetail::handleCallWdbeVerJsteMod_verEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	set<uint> moditems;

	refreshJst(dbswdbe, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

bool PnlWdbeVerDetail::handleCallWdbeVerUpd_refEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWdbeVerUpd_refEq --- INSERT
	return retval;
};

bool PnlWdbeVerDetail::handleCallWdbeVer_steEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recVer.ixVState == ixInv); // IP handleCallWdbeVer_steEq --- LINE
	return retval;
};

bool PnlWdbeVerDetail::handleCallWdbeVer_prjEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recVer.refWdbeMProject == refInv); // IP handleCallWdbeVer_prjEq --- LINE
	return retval;
};

bool PnlWdbeVerDetail::handleCallWdbeVer_bvrEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recVer.bvrRefWdbeMVersion == refInv); // IP handleCallWdbeVer_bvrEq --- LINE
	return retval;
};

