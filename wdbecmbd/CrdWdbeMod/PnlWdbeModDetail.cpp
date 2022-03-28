/**
	* \file PnlWdbeModDetail.cpp
	* job handler for job PnlWdbeModDetail (implementation)
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

#include "PnlWdbeModDetail.h"

#include "PnlWdbeModDetail_blks.cpp"
#include "PnlWdbeModDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWdbeModDetail
 ******************************************************************************/

PnlWdbeModDetail::PnlWdbeModDetail(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::PNLWDBEMODDETAIL, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFPupHkt.tag = "FeedFPupHkt";
	VecWdbeVMModuleHkTbl::fillFeed(ixWdbeVLocale, feedFPupHkt);
	feedFPupImbRty.tag = "FeedFPupImbRty";
	VecWdbeVMImbufRotype::fillFeed(ixWdbeVLocale, feedFPupImbRty);
	feedFPupTyp.tag = "FeedFPupTyp";
	VecWdbeVMModuleBasetype::fillFeed(ixWdbeVLocale, feedFPupTyp);
	feedFPupVnd.tag = "FeedFPupVnd";
	dbswdbe->fillFeedFromKlst(VecWdbeVKeylist::KLSTWDBEKVENDOR, ixWdbeVLocale, feedFPupVnd);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWdbeVCall::CALLWDBEKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEMDL_TYPEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEMDL_TPLEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEMDL_SUPEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEMDL_SUP_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEMDL_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEMDL_IMBEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEMDL_HKUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEMDL_HKU_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEMDL_HKTEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEMDL_CTREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBECTR_CLREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBECTR_MDL_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBECTR_FWDEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBECTR_FWD_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	xchg->addIxClstn(VecWdbeVCall::CALLWDBEKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWdbeVKeylist::KLSTWDBEKVENDOR);

	updatePreset(dbswdbe, VecWdbeVPreset::PREWDBEREFMOD, jref);
};

PnlWdbeModDetail::~PnlWdbeModDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* PnlWdbeModDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupHkt, &feedFPupImbRty, &feedFPupTyp, &feedFPupVnd, &statshr, items);
	};

	return dpcheng;
};

void PnlWdbeModDetail::refreshPupVnd(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.numFPupVnd = 0;

	for (unsigned int i = 0; i < feedFPupVnd.size(); i++) {
		if (feedFPupVnd.getSrefByNum(i+1) == contiac.TxfVnd) {
			contiac.numFPupVnd = i+1;
			break;
		};
	};

	// statshr
	statshr.TxfVndValid = (contiac.numFPupVnd != 0);
	statshr.PupVndActive = evalPupVndActive(dbswdbe);
	statshr.ButVndEditAvail = evalButVndEditAvail(dbswdbe);

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeModDetail::refreshTxfVnd(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.TxfVnd = feedFPupVnd.getSrefByNum(contiac.numFPupVnd);

	// statshr
	statshr.TxfVndValid = true;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeModDetail::refreshVnd(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	// feedFPupVnd
	dbswdbe->fillFeedFromKlst(VecWdbeVKeylist::KLSTWDBEKVENDOR, ixWdbeVLocale, feedFPupVnd);

	insert(moditems, DpchEngData::FEEDFPUPVND);

	refreshPupVnd(dbswdbe, moditems);
};

void PnlWdbeModDetail::refreshRecMdl(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WdbeMModule* _recMdl = NULL;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(recMdl.ref, &_recMdl)) {
		recMdl = *_recMdl;
		ixWSubsetMdl = dbswdbe->getIxWSubsetByWdbeMModule(_recMdl);
		delete _recMdl;
	} else {
		recMdl = WdbeMModule();
		ixWSubsetMdl = 0;
	};

	dirty = false;

	recCtr.ref = recMdl.refWdbeMController;

	recImb.ref = recMdl.refWdbeMImbuf;

	continf.TxtSrf = recMdl.sref;
	contiac.TxfVnd = recMdl.srefWdbeKVendor;
	contiac.numFPupTyp = feedFPupTyp.getNumByIx(recMdl.ixVBasetype);
	contiac.numFPupHkt = feedFPupHkt.getNumByIx(recMdl.hkIxVTbl);
	if (recMdl.hkIxVTbl == VecWdbeVMModuleHkTbl::CVR) continf.TxtHku = StubWdbe::getStubCvrStd(dbswdbe, recMdl.hkUref, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	else if (recMdl.hkIxVTbl == VecWdbeVMModuleHkTbl::UNT) continf.TxtHku = StubWdbe::getStubUntStd(dbswdbe, recMdl.hkUref, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	else continf.TxtHku = "-";
	continf.TxtSup = StubWdbe::getStubMdlStd(dbswdbe, recMdl.supRefWdbeMModule, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	continf.TxtTpl = StubWdbe::getStubMdlStd(dbswdbe, recMdl.tplRefWdbeMModule, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfSrr = recMdl.Srefrule;
	contiac.TxfCmt = recMdl.Comment;

	statshr.TxtSrfActive = evalTxtSrfActive(dbswdbe);
	statshr.PupTypActive = evalPupTypActive(dbswdbe);
	statshr.TxtHkuActive = evalTxtHkuActive(dbswdbe);
	statshr.ButHkuViewAvail = evalButHkuViewAvail(dbswdbe);
	statshr.ButHkuViewActive = evalButHkuViewActive(dbswdbe);
	statshr.TxtSupActive = evalTxtSupActive(dbswdbe);
	statshr.ButSupViewAvail = evalButSupViewAvail(dbswdbe);
	statshr.ButSupViewActive = evalButSupViewActive(dbswdbe);
	statshr.TxtTplActive = evalTxtTplActive(dbswdbe);
	statshr.ButTplViewAvail = evalButTplViewAvail(dbswdbe);
	statshr.ButTplViewActive = evalButTplViewActive(dbswdbe);
	statshr.TxfSrrActive = evalTxfSrrActive(dbswdbe);
	statshr.TxfCmtActive = evalTxfCmtActive(dbswdbe);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshRecCtr(dbswdbe, moditems);
	refreshRecImb(dbswdbe, moditems);

	refreshPupVnd(dbswdbe, moditems);

};

void PnlWdbeModDetail::refreshRecCtr(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WdbeMController* _recCtr = NULL;

	if (dbswdbe->tblwdbemcontroller->loadRecByRef(recCtr.ref, &_recCtr)) {
		recCtr = *_recCtr;
		delete _recCtr;
	} else recCtr = WdbeMController();

	contiac.TxfCtrFsr = recCtr.Fullsref;
	continf.TxtCtrFwd = StubWdbe::getStubUntStd(dbswdbe, recCtr.fwdRefWdbeMUnit, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	continf.TxtCtrClr = StubWdbe::getStubSigStd(dbswdbe, recCtr.clrRefWdbeMSignal, ixWdbeVLocale, Stub::VecVNonetype::FULL);

	statshr.SepCtrAvail = evalSepCtrAvail(dbswdbe);
	statshr.HdgCtrAvail = evalHdgCtrAvail(dbswdbe);
	statshr.ButCtrNewAvail = evalButCtrNewAvail(dbswdbe);
	statshr.ButCtrDeleteAvail = evalButCtrDeleteAvail(dbswdbe);
	statshr.TxfCtrFsrAvail = evalTxfCtrFsrAvail(dbswdbe);
	statshr.TxfCtrFsrActive = evalTxfCtrFsrActive(dbswdbe);
	statshr.TxtCtrFwdAvail = evalTxtCtrFwdAvail(dbswdbe);
	statshr.TxtCtrFwdActive = evalTxtCtrFwdActive(dbswdbe);
	statshr.ButCtrFwdViewAvail = evalButCtrFwdViewAvail(dbswdbe);
	statshr.ButCtrFwdViewActive = evalButCtrFwdViewActive(dbswdbe);
	statshr.TxtCtrClrAvail = evalTxtCtrClrAvail(dbswdbe);
	statshr.TxtCtrClrActive = evalTxtCtrClrActive(dbswdbe);
	statshr.ButCtrClrViewAvail = evalButCtrClrViewAvail(dbswdbe);
	statshr.ButCtrClrViewActive = evalButCtrClrViewActive(dbswdbe);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWdbeModDetail::refreshRecImb(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WdbeMImbuf* _recImb = NULL;

	if (dbswdbe->tblwdbemimbuf->loadRecByRef(recImb.ref, &_recImb)) {
		recImb = *_recImb;
		delete _recImb;
	} else recImb = WdbeMImbuf();

	contiac.TxfImbFsr = recImb.Fullsref;
	contiac.numFPupImbRty = feedFPupImbRty.getNumByIx(recImb.ixVRotype);
	contiac.TxfImbWid = to_string(recImb.Width);
	contiac.TxfImbMmx = recImb.Minmax;
	contiac.TxfImbPri = to_string(recImb.Prio);

	statshr.SepImbAvail = evalSepImbAvail(dbswdbe);
	statshr.HdgImbAvail = evalHdgImbAvail(dbswdbe);
	statshr.ButImbNewAvail = evalButImbNewAvail(dbswdbe);
	statshr.ButImbDeleteAvail = evalButImbDeleteAvail(dbswdbe);
	statshr.TxfImbFsrAvail = evalTxfImbFsrAvail(dbswdbe);
	statshr.TxfImbFsrActive = evalTxfImbFsrActive(dbswdbe);
	statshr.PupImbRtyAvail = evalPupImbRtyAvail(dbswdbe);
	statshr.PupImbRtyActive = evalPupImbRtyActive(dbswdbe);
	statshr.TxfImbWidAvail = evalTxfImbWidAvail(dbswdbe);
	statshr.TxfImbWidActive = evalTxfImbWidActive(dbswdbe);
	statshr.TxfImbMmxAvail = evalTxfImbMmxAvail(dbswdbe);
	statshr.TxfImbMmxActive = evalTxfImbMmxActive(dbswdbe);
	statshr.TxfImbPriAvail = evalTxfImbPriAvail(dbswdbe);
	statshr.TxfImbPriActive = evalTxfImbPriActive(dbswdbe);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWdbeModDetail::refresh(
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

void PnlWdbeModDetail::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFMOD) {
		recMdl.ref = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFMOD, jref);
		refreshRecMdl(dbswdbe, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWdbeModDetail::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswdbe, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTVNDEDITCLICK) {
					handleDpchAppDoButVndEditClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTHKUVIEWCLICK) {
					handleDpchAppDoButHkuViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSUPVIEWCLICK) {
					handleDpchAppDoButSupViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTTPLVIEWCLICK) {
					handleDpchAppDoButTplViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCTRNEWCLICK) {
					handleDpchAppDoButCtrNewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCTRDELETECLICK) {
					handleDpchAppDoButCtrDeleteClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCTRFWDVIEWCLICK) {
					handleDpchAppDoButCtrFwdViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCTRCLRVIEWCLICK) {
					handleDpchAppDoButCtrClrViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTIMBNEWCLICK) {
					handleDpchAppDoButImbNewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTIMBDELETECLICK) {
					handleDpchAppDoButImbDeleteClick(dbswdbe, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWdbeModDetail::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWdbeModDetail::handleDpchAppDataContiac(
			DbsWdbe* dbswdbe
			, ContIac* _contiac
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::NUMFPUPTYP, ContIac::TXFSRR, ContIac::TXFCMT, ContIac::TXFCTRFSR, ContIac::TXFIMBFSR, ContIac::NUMFPUPIMBRTY, ContIac::TXFIMBWID, ContIac::TXFIMBMMX, ContIac::TXFIMBPRI})) {
		if (has(diffitems, ContIac::NUMFPUPTYP)) contiac.numFPupTyp = _contiac->numFPupTyp;
		if (has(diffitems, ContIac::TXFSRR)) contiac.TxfSrr = _contiac->TxfSrr;
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
		if (has(diffitems, ContIac::TXFCTRFSR)) contiac.TxfCtrFsr = _contiac->TxfCtrFsr;
		if (has(diffitems, ContIac::TXFIMBFSR)) contiac.TxfImbFsr = _contiac->TxfImbFsr;
		if (has(diffitems, ContIac::NUMFPUPIMBRTY)) contiac.numFPupImbRty = _contiac->numFPupImbRty;
		if (has(diffitems, ContIac::TXFIMBWID)) contiac.TxfImbWid = _contiac->TxfImbWid;
		if (has(diffitems, ContIac::TXFIMBMMX)) contiac.TxfImbMmx = _contiac->TxfImbMmx;
		if (has(diffitems, ContIac::TXFIMBPRI)) contiac.TxfImbPri = _contiac->TxfImbPri;
	};

	if (has(diffitems, ContIac::TXFVND)) {
		contiac.TxfVnd = _contiac->TxfVnd;
		refreshPupVnd(dbswdbe, moditems);
	} else if (has(diffitems, ContIac::NUMFPUPVND)) {
		contiac.numFPupVnd = _contiac->numFPupVnd;
		refreshTxfVnd(dbswdbe, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWdbeModDetail::handleDpchAppDoButSaveClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWdbeModDetail::handleDpchAppDoButVndEditClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButVndEditClick --- INSERT
};

void PnlWdbeModDetail::handleDpchAppDoButHkuViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	ubigint refVer = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref);

	if (statshr.ButHkuViewAvail && statshr.ButHkuViewActive) {
		if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCUNT, jref)) if (recMdl.hkIxVTbl == VecWdbeVMModuleHkTbl::UNT) if (refVer != 0) {
			sref = "CrdWdbeUnt";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, VecWdbeVPreset::PREWDBEREFVER, refVer, sref, recMdl.hkUref, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIL, jref)) if (recMdl.hkIxVTbl == VecWdbeVMModuleHkTbl::UNT) if ((dbswdbe->getIxWSubsetByRefWdbeMUnit(recMdl.hkUref) & VecWdbeWMUnitSubset::SBSWDBEBMUNITSIL) != 0) {
				sref = "CrdWdbeSil";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, sref, recMdl.hkUref, jrefNew);
			};
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCVR, jref)) if (recMdl.hkIxVTbl == VecWdbeVMModuleHkTbl::CVR) {
				sref = "CrdWdbeCvr";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, sref, recMdl.hkUref, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, sref);
	};
};

void PnlWdbeModDetail::handleDpchAppDoButSupViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButSupViewAvail && statshr.ButSupViewActive) {
		if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref)) if ((dbswdbe->getIxWSubsetByRefWdbeMModule(recMdl.supRefWdbeMModule) & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMOD) != 0) if (ixPre == VecWdbeVPreset::PREWDBEREFUNT) {
			sref = "CrdWdbeMod";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, ixPre, refPre, sref, recMdl.supRefWdbeMModule, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref)) if ((dbswdbe->getIxWSubsetByRefWdbeMModule(recMdl.supRefWdbeMModule) & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMOD) != 0) if (ixPre == VecWdbeVPreset::PREWDBEREFCVR) {
				sref = "CrdWdbeMod";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, ixPre, refPre, sref, recMdl.supRefWdbeMModule, jrefNew);
			};
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMTP, jref)) if ((dbswdbe->getIxWSubsetByRefWdbeMModule(recMdl.supRefWdbeMModule) & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMTP) != 0) {
				sref = "CrdWdbeMtp";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, sref, recMdl.supRefWdbeMModule, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, sref);
	};
};

void PnlWdbeModDetail::handleDpchAppDoButTplViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButTplViewAvail && statshr.ButTplViewActive) {
		if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMTP, jref)) {
			sref = "CrdWdbeMtp";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, sref, recMdl.tplRefWdbeMModule, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, sref);
	};
};

void PnlWdbeModDetail::handleDpchAppDoButCtrNewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButCtrNewClick --- INSERT
};

void PnlWdbeModDetail::handleDpchAppDoButCtrDeleteClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButCtrDeleteClick --- INSERT
};

void PnlWdbeModDetail::handleDpchAppDoButCtrFwdViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	ubigint refVer = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref);

	if (statshr.ButCtrFwdViewAvail && statshr.ButCtrFwdViewActive) {
		if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCUNT, jref)) if (refVer != 0) {
			sref = "CrdWdbeUnt";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, VecWdbeVPreset::PREWDBEREFVER, refVer, sref, recCtr.fwdRefWdbeMUnit, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIL, jref)) if ((dbswdbe->getIxWSubsetByRefWdbeMUnit(recCtr.fwdRefWdbeMUnit) & VecWdbeWMUnitSubset::SBSWDBEBMUNITSIL) != 0) {
				sref = "CrdWdbeSil";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, sref, recCtr.fwdRefWdbeMUnit, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, sref);
	};
};

void PnlWdbeModDetail::handleDpchAppDoButCtrClrViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	ubigint refMod = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFMOD, jref);

	if (statshr.ButCtrClrViewAvail && statshr.ButCtrClrViewActive) {
		if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIG, jref)) if (refMod != 0) {
			sref = "CrdWdbeSig";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, VecWdbeVPreset::PREWDBEREFMOD, refMod, sref, recCtr.clrRefWdbeMSignal, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, sref);
	};
};

void PnlWdbeModDetail::handleDpchAppDoButImbNewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButImbNewClick --- INSERT
};

void PnlWdbeModDetail::handleDpchAppDoButImbDeleteClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButImbDeleteClick --- INSERT
};

void PnlWdbeModDetail::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBEKLSAKEYMOD_KLSEQ) {
		call->abort = handleCallWdbeKlsAkeyMod_klsEq(dbswdbe, call->jref, call->argInv.ix);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDLUPD_REFEQ) {
		call->abort = handleCallWdbeMdlUpd_refEq(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEIMBUPD_REFEQ) {
		call->abort = handleCallWdbeImbUpd_refEq(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBECTRUPD_REFEQ) {
		call->abort = handleCallWdbeCtrUpd_refEq(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDL_TYPEQ) {
		call->abort = handleCallWdbeMdl_typEq(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDL_TPLEQ) {
		call->abort = handleCallWdbeMdl_tplEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDL_SUPEQ) {
		call->abort = handleCallWdbeMdl_supEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDL_SUP_INSBS) {
		call->abort = handleCallWdbeMdl_sup_inSbs(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDL_INSBS) {
		call->abort = handleCallWdbeMdl_inSbs(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDL_IMBEQ) {
		call->abort = handleCallWdbeMdl_imbEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDL_HKUEQ) {
		call->abort = handleCallWdbeMdl_hkuEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDL_HKU_INSBS) {
		call->abort = handleCallWdbeMdl_hku_inSbs(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDL_HKTEQ) {
		call->abort = handleCallWdbeMdl_hktEq(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDL_CTREQ) {
		call->abort = handleCallWdbeMdl_ctrEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBECTR_CLREQ) {
		call->abort = handleCallWdbeCtr_clrEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBECTR_MDL_INSBS) {
		call->abort = handleCallWdbeCtr_mdl_inSbs(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBECTR_FWDEQ) {
		call->abort = handleCallWdbeCtr_fwdEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBECTR_FWD_INSBS) {
		call->abort = handleCallWdbeCtr_fwd_inSbs(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	};
};

bool PnlWdbeModDetail::handleCallWdbeKlsAkeyMod_klsEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecWdbeVKeylist::KLSTWDBEKVENDOR) {
		refreshVnd(dbswdbe, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

bool PnlWdbeModDetail::handleCallWdbeMdlUpd_refEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWdbeMdlUpd_refEq --- INSERT
	return retval;
};

bool PnlWdbeModDetail::handleCallWdbeImbUpd_refEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWdbeImbUpd_refEq --- INSERT
	return retval;
};

bool PnlWdbeModDetail::handleCallWdbeCtrUpd_refEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWdbeCtrUpd_refEq --- INSERT
	return retval;
};

bool PnlWdbeModDetail::handleCallWdbeMdl_typEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recMdl.ixVBasetype == ixInv); // IP handleCallWdbeMdl_typEq --- LINE
	return retval;
};

bool PnlWdbeModDetail::handleCallWdbeMdl_tplEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recMdl.tplRefWdbeMModule == refInv); // IP handleCallWdbeMdl_tplEq --- LINE
	return retval;
};

bool PnlWdbeModDetail::handleCallWdbeMdl_supEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recMdl.supRefWdbeMModule == refInv); // IP handleCallWdbeMdl_supEq --- LINE
	return retval;
};

bool PnlWdbeModDetail::handleCallWdbeMdl_sup_inSbs(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((dbswdbe->getIxWSubsetByRefWdbeMModule(recMdl.supRefWdbeMModule) & ixInv) != 0); // IP handleCallWdbeMdl_sup_inSbs --- LINE
	return retval;
};

bool PnlWdbeModDetail::handleCallWdbeMdl_inSbs(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((ixWSubsetMdl & ixInv) != 0); // IP handleCallWdbeMdl_inSbs --- LINE
	return retval;
};

bool PnlWdbeModDetail::handleCallWdbeMdl_imbEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recMdl.refWdbeMImbuf == refInv); // IP handleCallWdbeMdl_imbEq --- LINE
	return retval;
};

bool PnlWdbeModDetail::handleCallWdbeMdl_hkuEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recMdl.hkUref == refInv); // IP handleCallWdbeMdl_hkuEq --- LINE
	return retval;
};

bool PnlWdbeModDetail::handleCallWdbeMdl_hku_inSbs(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((dbswdbe->getIxWSubsetByRefWdbeMUnit(recMdl.hkUref) & ixInv) != 0); // IP handleCallWdbeMdl_hku_inSbs --- LINE
	return retval;
};

bool PnlWdbeModDetail::handleCallWdbeMdl_hktEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recMdl.hkIxVTbl == ixInv); // IP handleCallWdbeMdl_hktEq --- LINE
	return retval;
};

bool PnlWdbeModDetail::handleCallWdbeMdl_ctrEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recMdl.refWdbeMController == refInv); // IP handleCallWdbeMdl_ctrEq --- LINE
	return retval;
};

bool PnlWdbeModDetail::handleCallWdbeCtr_clrEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recCtr.clrRefWdbeMSignal == refInv); // IP handleCallWdbeCtr_clrEq --- LINE
	return retval;
};

bool PnlWdbeModDetail::handleCallWdbeCtr_mdl_inSbs(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((dbswdbe->getIxWSubsetByRefWdbeMModule(recCtr.refWdbeMModule) & ixInv) != 0); // IP handleCallWdbeCtr_mdl_inSbs --- LINE
	return retval;
};

bool PnlWdbeModDetail::handleCallWdbeCtr_fwdEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recCtr.fwdRefWdbeMUnit == refInv); // IP handleCallWdbeCtr_fwdEq --- LINE
	return retval;
};

bool PnlWdbeModDetail::handleCallWdbeCtr_fwd_inSbs(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((dbswdbe->getIxWSubsetByRefWdbeMUnit(recCtr.fwdRefWdbeMUnit) & ixInv) != 0); // IP handleCallWdbeCtr_fwd_inSbs --- LINE
	return retval;
};
