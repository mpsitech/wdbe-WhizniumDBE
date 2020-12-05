/**
	* \file PnlWdbeVarDetail.cpp
	* job handler for job PnlWdbeVarDetail (implementation)
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

#include "PnlWdbeVarDetail.h"

#include "PnlWdbeVarDetail_blks.cpp"
#include "PnlWdbeVarDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWdbeVarDetail
 ******************************************************************************/

PnlWdbeVarDetail::PnlWdbeVarDetail(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::PNLWDBEVARDETAIL, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFLstClu.tag = "FeedFLstClu";
	feedFPupHty.tag = "FeedFPupHty";
	dbswdbe->fillFeedFromKlst(VecWdbeVKeylist::KLSTWDBEKHDLTYPE, ixWdbeVLocale, feedFPupHty);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWdbeVCall::CALLWDBEKLSAKEYMOD_KLSMTBURFEQ, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEVAR_CLUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	xchg->addIxClstn(VecWdbeVCall::CALLWDBEKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWdbeVKeylist::KLSTWDBEKHDLTYPE);

	updatePreset(dbswdbe, VecWdbeVPreset::PREWDBEREFVAR, jref);
};

PnlWdbeVarDetail::~PnlWdbeVarDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* PnlWdbeVarDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFLstClu, &feedFPupHty, &statshr, items);
	};

	return dpcheng;
};

void PnlWdbeVarDetail::refreshLstClu(
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

void PnlWdbeVarDetail::refreshClu(
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

	if (recVar.refWdbeCVariable != 0) dbswdbe->tblwdbemvariable->loadRefsByClu(recVar.refWdbeCVariable, false, refs);

	first = true;
	for (unsigned int i = 0; i < refs.size(); i++) {
		if (refs[i] != recVar.ref) {
			feedFLstClu.appendRefTitles(refs[i], StubWdbe::getStubVarStd(dbswdbe, refs[i], ixWdbeVLocale));

			if (first) first = false;
			else continf.TxtClu += ";";

			continf.TxtClu += StubWdbe::getStubVarStd(dbswdbe, refs[i], ixWdbeVLocale);
		};
	};
	if (first) continf.TxtClu = "-";

	insert(moditems, DpchEngData::FEEDFLSTCLU);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	refreshLstClu(dbswdbe, moditems);
};

void PnlWdbeVarDetail::refreshPupHty(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.numFPupHty = 0;

	for (unsigned int i = 0; i < feedFPupHty.size(); i++) {
		if (feedFPupHty.getSrefByNum(i+1) == contiac.TxfHty) {
			contiac.numFPupHty = i+1;
			break;
		};
	};

	// statshr
	statshr.TxfHtyValid = (contiac.numFPupHty != 0);
	statshr.PupHtyActive = evalPupHtyActive(dbswdbe);
	statshr.ButHtyEditAvail = evalButHtyEditAvail(dbswdbe);

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeVarDetail::refreshTxfHty(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.TxfHty = feedFPupHty.getSrefByNum(contiac.numFPupHty);

	// statshr
	statshr.TxfHtyValid = true;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeVarDetail::refreshHty(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	// feedFPupHty
	dbswdbe->fillFeedFromKlst(VecWdbeVKeylist::KLSTWDBEKHDLTYPE, ixWdbeVLocale, feedFPupHty);

	insert(moditems, DpchEngData::FEEDFPUPHTY);

	refreshPupHty(dbswdbe, moditems);
};

void PnlWdbeVarDetail::refreshRecVar(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WdbeMVariable* _recVar = NULL;

	if (dbswdbe->tblwdbemvariable->loadRecByRef(recVar.ref, &_recVar)) {
		recVar = *_recVar;
		delete _recVar;
	} else recVar = WdbeMVariable();

	dirty = false;

	if (recVar.refWdbeCVariable == 0) xchg->removeClstns(VecWdbeVCall::CALLWDBEVARMOD_CLUEQ, jref);
	else xchg->addRefClstn(VecWdbeVCall::CALLWDBEVARMOD_CLUEQ, jref, Clstn::VecVJobmask::ALL, 0, true, recVar.refWdbeCVariable);

	continf.TxtSrf = recVar.sref;
	continf.TxtPrc = StubWdbe::getStubPrcStd(dbswdbe, recVar.prcRefWdbeMProcess, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	contiac.ChkCon = recVar.Const;
	contiac.ChkFal = recVar.Falling;
	contiac.TxfHty = recVar.srefWdbeKHdltype;
	contiac.TxfWid = to_string(recVar.Width);
	contiac.TxfMmx = recVar.Minmax;
	contiac.TxfOnv = recVar.Onval;
	contiac.TxfOfv = recVar.Offval;
	contiac.ChkDfo = recVar.Defon;
	contiac.TxfCmt = recVar.Comment;

	statshr.TxtSrfActive = evalTxtSrfActive(dbswdbe);
	statshr.TxtPrcActive = evalTxtPrcActive(dbswdbe);
	statshr.ChkConActive = evalChkConActive(dbswdbe);
	statshr.ChkFalActive = evalChkFalActive(dbswdbe);
	statshr.TxfWidActive = evalTxfWidActive(dbswdbe);
	statshr.TxfMmxActive = evalTxfMmxActive(dbswdbe);
	statshr.TxfOnvActive = evalTxfOnvActive(dbswdbe);
	statshr.TxfOfvActive = evalTxfOfvActive(dbswdbe);
	statshr.ChkDfoActive = evalChkDfoActive(dbswdbe);
	statshr.TxfCmtActive = evalTxfCmtActive(dbswdbe);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshClu(dbswdbe, moditems);
	refreshPupHty(dbswdbe, moditems);

};

void PnlWdbeVarDetail::refresh(
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

void PnlWdbeVarDetail::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFVAR) {
		recVar.ref = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVAR, jref);
		refreshRecVar(dbswdbe, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWdbeVarDetail::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVARDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswdbe, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVARDETAILDO) {
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
				} else if (dpchappdo->ixVDo == VecVDo::BUTHTYEDITCLICK) {
					handleDpchAppDoButHtyEditClick(dbswdbe, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWdbeVarDetail::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWdbeVarDetail::handleDpchAppDataContiac(
			DbsWdbe* dbswdbe
			, ContIac* _contiac
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::CHKCON, ContIac::CHKFAL, ContIac::TXFWID, ContIac::TXFMMX, ContIac::TXFONV, ContIac::TXFOFV, ContIac::CHKDFO, ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::CHKCON)) contiac.ChkCon = _contiac->ChkCon;
		if (has(diffitems, ContIac::CHKFAL)) contiac.ChkFal = _contiac->ChkFal;
		if (has(diffitems, ContIac::TXFWID)) contiac.TxfWid = _contiac->TxfWid;
		if (has(diffitems, ContIac::TXFMMX)) contiac.TxfMmx = _contiac->TxfMmx;
		if (has(diffitems, ContIac::TXFONV)) contiac.TxfOnv = _contiac->TxfOnv;
		if (has(diffitems, ContIac::TXFOFV)) contiac.TxfOfv = _contiac->TxfOfv;
		if (has(diffitems, ContIac::CHKDFO)) contiac.ChkDfo = _contiac->ChkDfo;
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
	};

	if (has(diffitems, ContIac::NUMFLSTCLU)) {
		contiac.numFLstClu = _contiac->numFLstClu;
		refreshLstClu(dbswdbe, moditems);
	};

	if (has(diffitems, ContIac::TXFHTY)) {
		contiac.TxfHty = _contiac->TxfHty;
		refreshPupHty(dbswdbe, moditems);
	} else if (has(diffitems, ContIac::NUMFPUPHTY)) {
		contiac.numFPupHty = _contiac->numFPupHty;
		refreshTxfHty(dbswdbe, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWdbeVarDetail::handleDpchAppDoButSaveClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWdbeVarDetail::handleDpchAppDoButCluViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButCluViewClick --- INSERT
};

void PnlWdbeVarDetail::handleDpchAppDoButCluClusterClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButCluClusterClick --- INSERT
};

void PnlWdbeVarDetail::handleDpchAppDoButCluUnclusterClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButCluUnclusterClick --- INSERT
};

void PnlWdbeVarDetail::handleDpchAppDoButHtyEditClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButHtyEditClick --- INSERT
};

void PnlWdbeVarDetail::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBEVARMOD_CLUEQ) {
		call->abort = handleCallWdbeVarMod_cluEq(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEKLSAKEYMOD_KLSMTBURFEQ) {
		call->abort = handleCallWdbeKlsAkeyMod_klsMtbUrfEq(dbswdbe, call->jref, call->argInv.ix, call->argInv.ref, call->argInv.sref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEVARUPD_REFEQ) {
		call->abort = handleCallWdbeVarUpd_refEq(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEVAR_CLUEQ) {
		call->abort = handleCallWdbeVar_cluEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWdbeVarDetail::handleCallWdbeVarMod_cluEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	set<uint> moditems;

	refreshClu(dbswdbe, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

bool PnlWdbeVarDetail::handleCallWdbeKlsAkeyMod_klsMtbUrfEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
		) {
	bool retval = false;
	// IP handleCallWdbeKlsAkeyMod_klsMtbUrfEq --- INSERT
	return retval;
};

bool PnlWdbeVarDetail::handleCallWdbeVarUpd_refEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWdbeVarUpd_refEq --- INSERT
	return retval;
};

bool PnlWdbeVarDetail::handleCallWdbeVar_cluEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recVar.refWdbeCVariable == refInv); // IP handleCallWdbeVar_cluEq --- LINE
	return retval;
};



