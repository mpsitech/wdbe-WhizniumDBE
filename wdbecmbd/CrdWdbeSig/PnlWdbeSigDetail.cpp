/**
	* \file PnlWdbeSigDetail.cpp
	* job handler for job PnlWdbeSigDetail (implementation)
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

#include "PnlWdbeSigDetail.h"

#include "PnlWdbeSigDetail_blks.cpp"
#include "PnlWdbeSigDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWdbeSigDetail
 ******************************************************************************/

PnlWdbeSigDetail::PnlWdbeSigDetail(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::PNLWDBESIGDETAIL, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFLstClu.tag = "FeedFLstClu";
	feedFPupHty.tag = "FeedFPupHty";
	dbswdbe->fillFeedFromKlst(VecWdbeVKeylist::KLSTWDBEKHDLTYPE, ixWdbeVLocale, feedFPupHty);
	feedFPupMgt.tag = "FeedFPupMgt";
	VecWdbeVMSignalMgeTbl::fillFeed(ixWdbeVLocale, feedFPupMgt);
	feedFPupTyp.tag = "FeedFPupTyp";
	VecWdbeVMSignalBasetype::fillFeed(ixWdbeVLocale, feedFPupTyp);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWdbeVCall::CALLWDBESIG_CLUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBESIG_DRVEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBESIG_MDLEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBESIG_MGTEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBESIG_MGU_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBESIG_MGUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBESIG_VECEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEKLSAKEYMOD_KLSMTBURFEQ, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	xchg->addIxClstn(VecWdbeVCall::CALLWDBEKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWdbeVKeylist::KLSTWDBEKHDLTYPE);

	updatePreset(dbswdbe, VecWdbeVPreset::PREWDBEREFSIG, jref);
};

PnlWdbeSigDetail::~PnlWdbeSigDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* PnlWdbeSigDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFLstClu, &feedFPupHty, &feedFPupMgt, &feedFPupTyp, &statshr, items);
	};

	return dpcheng;
};

void PnlWdbeSigDetail::refreshLstClu(
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

void PnlWdbeSigDetail::refreshClu(
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

	if (recSig.refWdbeCSignal != 0) dbswdbe->tblwdbemsignal->loadRefsByClu(recSig.refWdbeCSignal, false, refs);

	first = true;
	for (unsigned int i = 0; i < refs.size(); i++) {
		if (refs[i] != recSig.ref) {
			feedFLstClu.appendRefTitles(refs[i], StubWdbe::getStubSigStd(dbswdbe, refs[i], ixWdbeVLocale));

			if (first) first = false;
			else continf.TxtClu += ";";

			continf.TxtClu += StubWdbe::getStubSigStd(dbswdbe, refs[i], ixWdbeVLocale);
		};
	};
	if (first) continf.TxtClu = "-";

	insert(moditems, DpchEngData::FEEDFLSTCLU);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	refreshLstClu(dbswdbe, moditems);
};

void PnlWdbeSigDetail::refreshPupHty(
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

void PnlWdbeSigDetail::refreshTxfHty(
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

void PnlWdbeSigDetail::refreshHty(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	// feedFPupHty
	dbswdbe->fillFeedFromKlst(VecWdbeVKeylist::KLSTWDBEKHDLTYPE, ixWdbeVLocale, feedFPupHty);

	insert(moditems, DpchEngData::FEEDFPUPHTY);

	refreshPupHty(dbswdbe, moditems);
};

void PnlWdbeSigDetail::refreshRecSig(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WdbeMSignal* _recSig = NULL;

	if (dbswdbe->tblwdbemsignal->loadRecByRef(recSig.ref, &_recSig)) {
		recSig = *_recSig;
		delete _recSig;
	} else recSig = WdbeMSignal();

	dirty = false;

	if (recSig.refWdbeCSignal == 0) xchg->removeClstns(VecWdbeVCall::CALLWDBESIGMOD_CLUEQ, jref);
	else xchg->addRefClstn(VecWdbeVCall::CALLWDBESIGMOD_CLUEQ, jref, Clstn::VecVJobmask::ALL, 0, true, recSig.refWdbeCSignal);

	continf.TxtSrf = recSig.sref;
	contiac.numFPupTyp = feedFPupTyp.getNumByIx(recSig.ixVBasetype);
	continf.TxtMdl = StubWdbe::getStubMdlStd(dbswdbe, recSig.mdlRefWdbeMModule, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	contiac.numFPupMgt = feedFPupMgt.getNumByIx(recSig.mgeIxVTbl);
	if (recSig.mgeIxVTbl == VecWdbeVMSignalMgeTbl::MDL) continf.TxtMgu = StubWdbe::getStubMdlStd(dbswdbe, recSig.mgeUref, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	else if (recSig.mgeIxVTbl == VecWdbeVMSignalMgeTbl::PRC) continf.TxtMgu = StubWdbe::getStubPrcStd(dbswdbe, recSig.mgeUref, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	else continf.TxtMgu = "-";
	continf.TxtVec = StubWdbe::getStubVecStd(dbswdbe, recSig.refWdbeMVector, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	contiac.ChkCon = recSig.Const;
	contiac.TxfHty = recSig.srefWdbeKHdltype;
	contiac.TxfWid = to_string(recSig.Width);
	contiac.TxfMmx = recSig.Minmax;
	contiac.TxfCmb = recSig.Comb;
	contiac.TxfOnv = recSig.Onval;
	contiac.TxfOfv = recSig.Offval;
	contiac.ChkDfo = recSig.Defon;
	continf.TxtDrv = StubWdbe::getStubPrtStd(dbswdbe, recSig.drvRefWdbeMPort, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfCmt = recSig.Comment;

	statshr.TxtSrfActive = evalTxtSrfActive(dbswdbe);
	statshr.PupTypActive = evalPupTypActive(dbswdbe);
	statshr.TxtMdlActive = evalTxtMdlActive(dbswdbe);
	statshr.ButMdlViewAvail = evalButMdlViewAvail(dbswdbe);
	statshr.ButMdlViewActive = evalButMdlViewActive(dbswdbe);
	statshr.TxtMguActive = evalTxtMguActive(dbswdbe);
	statshr.ButMguViewAvail = evalButMguViewAvail(dbswdbe);
	statshr.ButMguViewActive = evalButMguViewActive(dbswdbe);
	statshr.TxtVecActive = evalTxtVecActive(dbswdbe);
	statshr.ButVecViewAvail = evalButVecViewAvail(dbswdbe);
	statshr.ButVecViewActive = evalButVecViewActive(dbswdbe);
	statshr.ChkConActive = evalChkConActive(dbswdbe);
	statshr.TxfWidActive = evalTxfWidActive(dbswdbe);
	statshr.TxfMmxActive = evalTxfMmxActive(dbswdbe);
	statshr.TxfCmbActive = evalTxfCmbActive(dbswdbe);
	statshr.TxfOnvActive = evalTxfOnvActive(dbswdbe);
	statshr.TxfOfvActive = evalTxfOfvActive(dbswdbe);
	statshr.ChkDfoActive = evalChkDfoActive(dbswdbe);
	statshr.TxtDrvActive = evalTxtDrvActive(dbswdbe);
	statshr.ButDrvViewAvail = evalButDrvViewAvail(dbswdbe);
	statshr.ButDrvViewActive = evalButDrvViewActive(dbswdbe);
	statshr.TxfCmtActive = evalTxfCmtActive(dbswdbe);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshClu(dbswdbe, moditems);
	refreshPupHty(dbswdbe, moditems);

};

void PnlWdbeSigDetail::refresh(
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

void PnlWdbeSigDetail::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFSIG) {
		recSig.ref = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSIG, jref);
		refreshRecSig(dbswdbe, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWdbeSigDetail::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESIGDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswdbe, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESIGDETAILDO) {
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
				} else if (dpchappdo->ixVDo == VecVDo::BUTMDLVIEWCLICK) {
					handleDpchAppDoButMdlViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTMGUVIEWCLICK) {
					handleDpchAppDoButMguViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTVECVIEWCLICK) {
					handleDpchAppDoButVecViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTHTYEDITCLICK) {
					handleDpchAppDoButHtyEditClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDRVVIEWCLICK) {
					handleDpchAppDoButDrvViewClick(dbswdbe, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWdbeSigDetail::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWdbeSigDetail::handleDpchAppDataContiac(
			DbsWdbe* dbswdbe
			, ContIac* _contiac
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::NUMFPUPTYP, ContIac::CHKCON, ContIac::TXFWID, ContIac::TXFMMX, ContIac::TXFCMB, ContIac::TXFONV, ContIac::TXFOFV, ContIac::CHKDFO, ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::NUMFPUPTYP)) contiac.numFPupTyp = _contiac->numFPupTyp;
		if (has(diffitems, ContIac::CHKCON)) contiac.ChkCon = _contiac->ChkCon;
		if (has(diffitems, ContIac::TXFWID)) contiac.TxfWid = _contiac->TxfWid;
		if (has(diffitems, ContIac::TXFMMX)) contiac.TxfMmx = _contiac->TxfMmx;
		if (has(diffitems, ContIac::TXFCMB)) contiac.TxfCmb = _contiac->TxfCmb;
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

void PnlWdbeSigDetail::handleDpchAppDoButSaveClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWdbeSigDetail::handleDpchAppDoButCluViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButCluViewClick --- INSERT
};

void PnlWdbeSigDetail::handleDpchAppDoButCluClusterClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButCluClusterClick --- INSERT
};

void PnlWdbeSigDetail::handleDpchAppDoButCluUnclusterClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButCluUnclusterClick --- INSERT
};

void PnlWdbeSigDetail::handleDpchAppDoButMdlViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	ubigint refCvr = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCVR, jref);
	ubigint refUnt = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref);

	if (statshr.ButMdlViewAvail && statshr.ButMdlViewActive) {
		if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref)) if (refUnt != 0) {
			sref = "CrdWdbeMod";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, VecWdbeVPreset::PREWDBEREFUNT, refUnt, sref, recSig.mdlRefWdbeMModule, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref)) if (refCvr != 0) {
				sref = "CrdWdbeMod";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, VecWdbeVPreset::PREWDBEREFCVR, refCvr, sref, recSig.mdlRefWdbeMModule, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, sref);
	};
};

void PnlWdbeSigDetail::handleDpchAppDoButMguViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	ubigint refCvr = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCVR, jref);
	ubigint refUnt = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref);

	if (statshr.ButMguViewAvail && statshr.ButMguViewActive) {
		if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref)) if (recSig.mgeIxVTbl == VecWdbeVMSignalMgeTbl::MDL) if ((dbswdbe->getIxWSubsetByRefWdbeMModule(recSig.mgeUref) & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMOD) != 0) if (refUnt != 0) {
			sref = "CrdWdbeMod";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, VecWdbeVPreset::PREWDBEREFUNT, refUnt, sref, recSig.mgeUref, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref)) if (recSig.mgeIxVTbl == VecWdbeVMSignalMgeTbl::MDL) if ((dbswdbe->getIxWSubsetByRefWdbeMModule(recSig.mgeUref) & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMOD) != 0) if (refCvr != 0) {
				sref = "CrdWdbeMod";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, VecWdbeVPreset::PREWDBEREFCVR, refCvr, sref, recSig.mgeUref, jrefNew);
			};
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMTP, jref)) if (recSig.mgeIxVTbl == VecWdbeVMSignalMgeTbl::MDL) if ((dbswdbe->getIxWSubsetByRefWdbeMModule(recSig.mgeUref) & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMTP) != 0) {
				sref = "CrdWdbeMtp";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, sref, recSig.mgeUref, jrefNew);
			};
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPRC, jref)) if (recSig.mgeIxVTbl == VecWdbeVMSignalMgeTbl::PRC) if (ixPre == VecWdbeVPreset::PREWDBEREFMTP) {
				sref = "CrdWdbePrc";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, ixPre, refPre, sref, recSig.mgeUref, jrefNew);
			};
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPRC, jref)) if (recSig.mgeIxVTbl == VecWdbeVMSignalMgeTbl::PRC) if (ixPre == VecWdbeVPreset::PREWDBEREFMOD) {
				sref = "CrdWdbePrc";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, ixPre, refPre, sref, recSig.mgeUref, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, sref);
	};
};

void PnlWdbeSigDetail::handleDpchAppDoButVecViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	ubigint refCvr = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCVR, jref);
	ubigint refUnt = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref);
	ubigint refVer = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref);

	if (statshr.ButVecViewAvail && statshr.ButVecViewActive) {
		if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVEC, jref)) if (refUnt != 0) {
			sref = "CrdWdbeVec";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, VecWdbeVPreset::PREWDBEREFUNT, refUnt, sref, recSig.refWdbeMVector, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVEC, jref)) if (refCvr != 0) {
				sref = "CrdWdbeVec";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, VecWdbeVPreset::PREWDBEREFCVR, refCvr, sref, recSig.refWdbeMVector, jrefNew);
			};
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVEC, jref)) if (refVer != 0) {
				sref = "CrdWdbeVec";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, VecWdbeVPreset::PREWDBEREFVER, refVer, sref, recSig.refWdbeMVector, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, sref);
	};
};

void PnlWdbeSigDetail::handleDpchAppDoButHtyEditClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButHtyEditClick --- INSERT
};

void PnlWdbeSigDetail::handleDpchAppDoButDrvViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButDrvViewAvail && statshr.ButDrvViewActive) {
		if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPRT, jref)) if (ixPre == VecWdbeVPreset::PREWDBEREFMTP) {
			sref = "CrdWdbePrt";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, ixPre, refPre, sref, recSig.drvRefWdbeMPort, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPRT, jref)) if (ixPre == VecWdbeVPreset::PREWDBEREFMOD) {
				sref = "CrdWdbePrt";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, ixPre, refPre, sref, recSig.drvRefWdbeMPort, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, sref);
	};
};

void PnlWdbeSigDetail::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBESIG_CLUEQ) {
		call->abort = handleCallWdbeSig_cluEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBESIG_DRVEQ) {
		call->abort = handleCallWdbeSig_drvEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBESIG_MDLEQ) {
		call->abort = handleCallWdbeSig_mdlEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBESIG_MGTEQ) {
		call->abort = handleCallWdbeSig_mgtEq(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBESIG_MGU_INSBS) {
		call->abort = handleCallWdbeSig_mgu_inSbs(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBESIG_MGUEQ) {
		call->abort = handleCallWdbeSig_mguEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBESIG_VECEQ) {
		call->abort = handleCallWdbeSig_vecEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBESIGUPD_REFEQ) {
		call->abort = handleCallWdbeSigUpd_refEq(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEKLSAKEYMOD_KLSMTBURFEQ) {
		call->abort = handleCallWdbeKlsAkeyMod_klsMtbUrfEq(dbswdbe, call->jref, call->argInv.ix, call->argInv.ref, call->argInv.sref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBESIGMOD_CLUEQ) {
		call->abort = handleCallWdbeSigMod_cluEq(dbswdbe, call->jref);
	};
};

bool PnlWdbeSigDetail::handleCallWdbeSig_cluEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recSig.refWdbeCSignal == refInv); // IP handleCallWdbeSig_cluEq --- LINE
	return retval;
};

bool PnlWdbeSigDetail::handleCallWdbeSig_drvEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recSig.drvRefWdbeMPort == refInv); // IP handleCallWdbeSig_drvEq --- LINE
	return retval;
};

bool PnlWdbeSigDetail::handleCallWdbeSig_mdlEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recSig.mdlRefWdbeMModule == refInv); // IP handleCallWdbeSig_mdlEq --- LINE
	return retval;
};

bool PnlWdbeSigDetail::handleCallWdbeSig_mgtEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recSig.mgeIxVTbl == ixInv); // IP handleCallWdbeSig_mgtEq --- LINE
	return retval;
};

bool PnlWdbeSigDetail::handleCallWdbeSig_mgu_inSbs(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((dbswdbe->getIxWSubsetByRefWdbeMModule(recSig.mgeUref) & ixInv) != 0); // IP handleCallWdbeSig_mgu_inSbs --- LINE
	return retval;
};

bool PnlWdbeSigDetail::handleCallWdbeSig_mguEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recSig.mgeUref == refInv); // IP handleCallWdbeSig_mguEq --- LINE
	return retval;
};

bool PnlWdbeSigDetail::handleCallWdbeSig_vecEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recSig.refWdbeMVector == refInv); // IP handleCallWdbeSig_vecEq --- LINE
	return retval;
};

bool PnlWdbeSigDetail::handleCallWdbeSigUpd_refEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWdbeSigUpd_refEq --- INSERT
	return retval;
};

bool PnlWdbeSigDetail::handleCallWdbeKlsAkeyMod_klsMtbUrfEq(
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

bool PnlWdbeSigDetail::handleCallWdbeSigMod_cluEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	set<uint> moditems;

	refreshClu(dbswdbe, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};
