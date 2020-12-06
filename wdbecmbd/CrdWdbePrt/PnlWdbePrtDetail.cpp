/**
	* \file PnlWdbePrtDetail.cpp
	* job handler for job PnlWdbePrtDetail (implementation)
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

#include "PnlWdbePrtDetail.h"

#include "PnlWdbePrtDetail_blks.cpp"
#include "PnlWdbePrtDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWdbePrtDetail
 ******************************************************************************/

PnlWdbePrtDetail::PnlWdbePrtDetail(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::PNLWDBEPRTDETAIL, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFLstClu.tag = "FeedFLstClu";
	feedFPupDir.tag = "FeedFPupDir";
	VecWdbeVMPortDir::fillFeed(ixWdbeVLocale, feedFPupDir);
	feedFPupHty.tag = "FeedFPupHty";
	dbswdbe->fillFeedFromKlst(VecWdbeVKeylist::KLSTWDBEKHDLTYPE, ixWdbeVLocale, feedFPupHty);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWdbeVCall::CALLWDBEKLSAKEYMOD_KLSMTBURFEQ, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEPRT_CLUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEPRT_MDL_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEPRT_MDLEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	xchg->addIxClstn(VecWdbeVCall::CALLWDBEKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWdbeVKeylist::KLSTWDBEKHDLTYPE);

	updatePreset(dbswdbe, VecWdbeVPreset::PREWDBEREFPRT, jref);
};

PnlWdbePrtDetail::~PnlWdbePrtDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* PnlWdbePrtDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFLstClu, &feedFPupDir, &feedFPupHty, &statshr, items);
	};

	return dpcheng;
};

void PnlWdbePrtDetail::refreshLstClu(
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

void PnlWdbePrtDetail::refreshClu(
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

	if (recPrt.refWdbeCPort != 0) dbswdbe->tblwdbemport->loadRefsByClu(recPrt.refWdbeCPort, false, refs);

	first = true;
	for (unsigned int i = 0; i < refs.size(); i++) {
		if (refs[i] != recPrt.ref) {
			feedFLstClu.appendRefTitles(refs[i], StubWdbe::getStubPrtStd(dbswdbe, refs[i], ixWdbeVLocale));

			if (first) first = false;
			else continf.TxtClu += ";";

			continf.TxtClu += StubWdbe::getStubPrtStd(dbswdbe, refs[i], ixWdbeVLocale);
		};
	};
	if (first) continf.TxtClu = "-";

	insert(moditems, DpchEngData::FEEDFLSTCLU);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	refreshLstClu(dbswdbe, moditems);
};

void PnlWdbePrtDetail::refreshPupHty(
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

void PnlWdbePrtDetail::refreshTxfHty(
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

void PnlWdbePrtDetail::refreshHty(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	// feedFPupHty
	dbswdbe->fillFeedFromKlst(VecWdbeVKeylist::KLSTWDBEKHDLTYPE, ixWdbeVLocale, feedFPupHty);

	insert(moditems, DpchEngData::FEEDFPUPHTY);

	refreshPupHty(dbswdbe, moditems);
};

void PnlWdbePrtDetail::refreshTxtCpi(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refreshTxtCpi --- BEGIN
	ubigint refPin = 0;

	dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMPin WHERE sref = '" + contiac.TxfCpi + "'", refPin);

	continf.TxtCpi = StubWdbe::getStubPinStd(dbswdbe, refPin, ixWdbeVLocale);

	statshr.TxfCpiValid = (refPin != 0);
	statshr.TxtCpiActive = evalTxtCpiActive(dbswdbe);
	statshr.ButCpiViewAvail = evalButCpiViewAvail(dbswdbe);
	// IP refreshTxtCpi --- END

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbePrtDetail::refreshTxtCpr(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refreshTxtCpr --- BEGIN
	ubigint refPrt = 0;

	dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMPort WHERE sref = '" + contiac.TxfCpr + "'", refPrt);

	continf.TxtCpr = StubWdbe::getStubPrtStd(dbswdbe, refPrt, ixWdbeVLocale);

	statshr.TxfCprValid = (refPrt != 0);
	statshr.TxtCprActive = evalTxtCprActive(dbswdbe);
	statshr.ButCprViewAvail = evalButCprViewAvail(dbswdbe);
	// IP refreshTxtCpr --- END

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbePrtDetail::refreshTxtCsi(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refreshTxtCsi --- BEGIN
	ubigint refSig = 0;

	dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMSignal WHERE sref = '" + contiac.TxfCsi + "'", refSig);

	continf.TxtCsi = StubWdbe::getStubSigStd(dbswdbe, refSig, ixWdbeVLocale);

	statshr.TxfCsiValid = (refSig != 0);
	statshr.TxtCsiActive = evalTxtCsiActive(dbswdbe);
	statshr.ButCsiViewAvail = evalButCsiViewAvail(dbswdbe);
	// IP refreshTxtCsi --- END

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbePrtDetail::refreshRecPrt(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WdbeMPort* _recPrt = NULL;

	if (dbswdbe->tblwdbemport->loadRecByRef(recPrt.ref, &_recPrt)) {
		recPrt = *_recPrt;
		delete _recPrt;
	} else recPrt = WdbeMPort();

	dirty = false;

	if (recPrt.refWdbeCPort == 0) xchg->removeClstns(VecWdbeVCall::CALLWDBEPRTMOD_CLUEQ, jref);
	else xchg->addRefClstn(VecWdbeVCall::CALLWDBEPRTMOD_CLUEQ, jref, Clstn::VecVJobmask::ALL, 0, true, recPrt.refWdbeCPort);

	continf.TxtSrf = recPrt.sref;
	continf.TxtMdl = StubWdbe::getStubMdlStd(dbswdbe, recPrt.mdlRefWdbeMModule, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	contiac.numFPupDir = feedFPupDir.getNumByIx(recPrt.ixVDir);
	contiac.TxfHty = recPrt.srefWdbeKHdltype;
	contiac.TxfWid = to_string(recPrt.Width);
	contiac.TxfMmx = recPrt.Minmax;
	contiac.TxfDfv = recPrt.Defval;
	contiac.TxfCpi = recPrt.cpiSrefWdbeMPin;
	contiac.TxfCpr = recPrt.cprSrefWdbeMPort;
	contiac.TxfCsi = recPrt.csiSrefWdbeMSignal;
	contiac.TxfCmt = recPrt.Comment;

	statshr.TxtSrfActive = evalTxtSrfActive(dbswdbe);
	statshr.TxtMdlActive = evalTxtMdlActive(dbswdbe);
	statshr.ButMdlViewAvail = evalButMdlViewAvail(dbswdbe);
	statshr.ButMdlViewActive = evalButMdlViewActive(dbswdbe);
	statshr.PupDirActive = evalPupDirActive(dbswdbe);
	statshr.TxfWidActive = evalTxfWidActive(dbswdbe);
	statshr.TxfMmxActive = evalTxfMmxActive(dbswdbe);
	statshr.TxfDfvActive = evalTxfDfvActive(dbswdbe);
	statshr.TxfCmtActive = evalTxfCmtActive(dbswdbe);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshClu(dbswdbe, moditems);
	refreshPupHty(dbswdbe, moditems);
	refreshTxtCpi(dbswdbe, moditems);
	refreshTxtCpr(dbswdbe, moditems);
	refreshTxtCsi(dbswdbe, moditems);

};

void PnlWdbePrtDetail::refresh(
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

void PnlWdbePrtDetail::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFPRT) {
		recPrt.ref = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFPRT, jref);
		refreshRecPrt(dbswdbe, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWdbePrtDetail::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRTDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswdbe, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRTDETAILDO) {
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
				} else if (dpchappdo->ixVDo == VecVDo::BUTHTYEDITCLICK) {
					handleDpchAppDoButHtyEditClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCPIVIEWCLICK) {
					handleDpchAppDoButCpiViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCPRVIEWCLICK) {
					handleDpchAppDoButCprViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCSIVIEWCLICK) {
					handleDpchAppDoButCsiViewClick(dbswdbe, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWdbePrtDetail::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWdbePrtDetail::handleDpchAppDataContiac(
			DbsWdbe* dbswdbe
			, ContIac* _contiac
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::NUMFPUPDIR, ContIac::TXFWID, ContIac::TXFMMX, ContIac::TXFDFV, ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::NUMFPUPDIR)) contiac.numFPupDir = _contiac->numFPupDir;
		if (has(diffitems, ContIac::TXFWID)) contiac.TxfWid = _contiac->TxfWid;
		if (has(diffitems, ContIac::TXFMMX)) contiac.TxfMmx = _contiac->TxfMmx;
		if (has(diffitems, ContIac::TXFDFV)) contiac.TxfDfv = _contiac->TxfDfv;
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

	if (has(diffitems, ContIac::TXFCPI)) {
		contiac.TxfCpi = _contiac->TxfCpi;
		refreshTxtCpi(dbswdbe, moditems);
		refresh(dbswdbe, moditems);
	};

	if (has(diffitems, ContIac::TXFCPR)) {
		contiac.TxfCpr = _contiac->TxfCpr;
		refreshTxtCpr(dbswdbe, moditems);
		refresh(dbswdbe, moditems);
	};

	if (has(diffitems, ContIac::TXFCSI)) {
		contiac.TxfCsi = _contiac->TxfCsi;
		refreshTxtCsi(dbswdbe, moditems);
		refresh(dbswdbe, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWdbePrtDetail::handleDpchAppDoButSaveClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWdbePrtDetail::handleDpchAppDoButCluViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButCluViewClick --- INSERT
};

void PnlWdbePrtDetail::handleDpchAppDoButCluClusterClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButCluClusterClick --- INSERT
};

void PnlWdbePrtDetail::handleDpchAppDoButCluUnclusterClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButCluUnclusterClick --- INSERT
};

void PnlWdbePrtDetail::handleDpchAppDoButMdlViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	ubigint refCvr = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCVR, jref);
	ubigint refUnt = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref);

	if (statshr.ButMdlViewAvail && statshr.ButMdlViewActive) {
		if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref)) if ((dbswdbe->getIxWSubsetByRefWdbeMModule(recPrt.mdlRefWdbeMModule) & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMOD) != 0) if (refUnt != 0) {
			sref = "CrdWdbeMod";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, VecWdbeVPreset::PREWDBEREFUNT, refUnt, sref, recPrt.mdlRefWdbeMModule, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref)) if ((dbswdbe->getIxWSubsetByRefWdbeMModule(recPrt.mdlRefWdbeMModule) & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMOD) != 0) if (refCvr != 0) {
				sref = "CrdWdbeMod";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, VecWdbeVPreset::PREWDBEREFCVR, refCvr, sref, recPrt.mdlRefWdbeMModule, jrefNew);
			};
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMTP, jref)) if ((dbswdbe->getIxWSubsetByRefWdbeMModule(recPrt.mdlRefWdbeMModule) & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMTP) != 0) {
				sref = "CrdWdbeMtp";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, sref, recPrt.mdlRefWdbeMModule, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, sref);
	};
};

void PnlWdbePrtDetail::handleDpchAppDoButHtyEditClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButHtyEditClick --- INSERT
};

void PnlWdbePrtDetail::handleDpchAppDoButCpiViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButCpiViewClick --- INSERT
};

void PnlWdbePrtDetail::handleDpchAppDoButCprViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButCprViewClick --- INSERT
};

void PnlWdbePrtDetail::handleDpchAppDoButCsiViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButCsiViewClick --- INSERT
};

void PnlWdbePrtDetail::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBEPRTMOD_CLUEQ) {
		call->abort = handleCallWdbePrtMod_cluEq(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEKLSAKEYMOD_KLSMTBURFEQ) {
		call->abort = handleCallWdbeKlsAkeyMod_klsMtbUrfEq(dbswdbe, call->jref, call->argInv.ix, call->argInv.ref, call->argInv.sref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEPRTUPD_REFEQ) {
		call->abort = handleCallWdbePrtUpd_refEq(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEPRT_CLUEQ) {
		call->abort = handleCallWdbePrt_cluEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEPRT_MDL_INSBS) {
		call->abort = handleCallWdbePrt_mdl_inSbs(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEPRT_MDLEQ) {
		call->abort = handleCallWdbePrt_mdlEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWdbePrtDetail::handleCallWdbePrtMod_cluEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	set<uint> moditems;

	refreshClu(dbswdbe, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

bool PnlWdbePrtDetail::handleCallWdbeKlsAkeyMod_klsMtbUrfEq(
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

bool PnlWdbePrtDetail::handleCallWdbePrtUpd_refEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWdbePrtUpd_refEq --- INSERT
	return retval;
};

bool PnlWdbePrtDetail::handleCallWdbePrt_cluEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recPrt.refWdbeCPort == refInv); // IP handleCallWdbePrt_cluEq --- LINE
	return retval;
};

bool PnlWdbePrtDetail::handleCallWdbePrt_mdl_inSbs(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((dbswdbe->getIxWSubsetByRefWdbeMModule(recPrt.mdlRefWdbeMModule) & ixInv) != 0); // IP handleCallWdbePrt_mdl_inSbs --- LINE
	return retval;
};

bool PnlWdbePrtDetail::handleCallWdbePrt_mdlEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recPrt.mdlRefWdbeMModule == refInv); // IP handleCallWdbePrt_mdlEq --- LINE
	return retval;
};
