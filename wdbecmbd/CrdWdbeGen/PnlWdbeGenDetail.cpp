/**
	* \file PnlWdbeGenDetail.cpp
	* job handler for job PnlWdbeGenDetail (implementation)
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

#include "PnlWdbeGenDetail.h"

#include "PnlWdbeGenDetail_blks.cpp"
#include "PnlWdbeGenDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWdbeGenDetail
 ******************************************************************************/

PnlWdbeGenDetail::PnlWdbeGenDetail(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::PNLWDBEGENDETAIL, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFLstClu.tag = "FeedFLstClu";
	feedFPupHty.tag = "FeedFPupHty";
	dbswdbe->fillFeedFromKlst(VecWdbeVKeylist::KLSTWDBEKHDLTYPE, ixWdbeVLocale, feedFPupHty);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWdbeVCall::CALLWDBEKLSAKEYMOD_KLSMTBURFEQ, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEGEN_MDLEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEGEN_MDL_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEGEN_CLUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	xchg->addIxClstn(VecWdbeVCall::CALLWDBEKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWdbeVKeylist::KLSTWDBEKHDLTYPE);

	updatePreset(dbswdbe, VecWdbeVPreset::PREWDBEREFGEN, jref);
};

PnlWdbeGenDetail::~PnlWdbeGenDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* PnlWdbeGenDetail::getNewDpchEng(
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

void PnlWdbeGenDetail::refreshLstClu(
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

void PnlWdbeGenDetail::refreshClu(
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

	if (recGen.refWdbeCGeneric != 0) dbswdbe->tblwdbemgeneric->loadRefsByClu(recGen.refWdbeCGeneric, false, refs);

	first = true;
	for (unsigned int i = 0; i < refs.size(); i++) {
		if (refs[i] != recGen.ref) {
			feedFLstClu.appendRefTitles(refs[i], StubWdbe::getStubGenStd(dbswdbe, refs[i], ixWdbeVLocale));

			if (first) first = false;
			else continf.TxtClu += ";";

			continf.TxtClu += StubWdbe::getStubGenStd(dbswdbe, refs[i], ixWdbeVLocale);
		};
	};
	if (first) continf.TxtClu = "-";

	insert(moditems, DpchEngData::FEEDFLSTCLU);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	refreshLstClu(dbswdbe, moditems);
};

void PnlWdbeGenDetail::refreshPupHty(
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

void PnlWdbeGenDetail::refreshTxfHty(
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

void PnlWdbeGenDetail::refreshHty(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	// feedFPupHty
	dbswdbe->fillFeedFromKlst(VecWdbeVKeylist::KLSTWDBEKHDLTYPE, ixWdbeVLocale, feedFPupHty);

	insert(moditems, DpchEngData::FEEDFPUPHTY);

	refreshPupHty(dbswdbe, moditems);
};

void PnlWdbeGenDetail::refreshTxtSrc(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refreshTxtSrc --- BEGIN
	ubigint refGen = 0;

	dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMGeneric WHERE sref = '" + contiac.TxfSrc + "'", refGen);

	continf.TxtSrc = StubWdbe::getStubGenStd(dbswdbe, refGen, ixWdbeVLocale);

	statshr.TxfSrcValid = (refGen != 0);
	statshr.TxtSrcActive = evalTxtSrcActive(dbswdbe);
	statshr.ButSrcViewAvail = evalButSrcViewAvail(dbswdbe);
	// IP refreshTxtSrc --- END

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeGenDetail::refreshRecGen(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WdbeMGeneric* _recGen = NULL;

	if (dbswdbe->tblwdbemgeneric->loadRecByRef(recGen.ref, &_recGen)) {
		recGen = *_recGen;
		delete _recGen;
	} else recGen = WdbeMGeneric();

	dirty = false;

	if (recGen.refWdbeCGeneric == 0) xchg->removeClstns(VecWdbeVCall::CALLWDBEGENMOD_CLUEQ, jref);
	else xchg->addRefClstn(VecWdbeVCall::CALLWDBEGENMOD_CLUEQ, jref, Clstn::VecVJobmask::ALL, 0, true, recGen.refWdbeCGeneric);

	continf.TxtSrf = recGen.sref;
	continf.TxtMdl = StubWdbe::getStubMdlStd(dbswdbe, recGen.mdlRefWdbeMModule, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfHty = recGen.srefWdbeKHdltype;
	contiac.TxfWid = to_string(recGen.Width);
	contiac.TxfMmx = recGen.Minmax;
	contiac.TxfDfv = recGen.Defval;
	contiac.TxfSrc = recGen.srcSrefWdbeMGeneric;
	contiac.TxfCmt = recGen.Comment;

	statshr.TxtSrfActive = evalTxtSrfActive(dbswdbe);
	statshr.TxtMdlActive = evalTxtMdlActive(dbswdbe);
	statshr.ButMdlViewAvail = evalButMdlViewAvail(dbswdbe);
	statshr.ButMdlViewActive = evalButMdlViewActive(dbswdbe);
	statshr.TxfWidActive = evalTxfWidActive(dbswdbe);
	statshr.TxfMmxActive = evalTxfMmxActive(dbswdbe);
	statshr.TxfDfvActive = evalTxfDfvActive(dbswdbe);
	statshr.TxfCmtActive = evalTxfCmtActive(dbswdbe);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshClu(dbswdbe, moditems);
	refreshPupHty(dbswdbe, moditems);
	refreshTxtSrc(dbswdbe, moditems);

};

void PnlWdbeGenDetail::refresh(
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

void PnlWdbeGenDetail::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFGEN) {
		recGen.ref = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFGEN, jref);
		refreshRecGen(dbswdbe, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWdbeGenDetail::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEGENDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswdbe, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEGENDETAILDO) {
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
				} else if (dpchappdo->ixVDo == VecVDo::BUTSRCVIEWCLICK) {
					handleDpchAppDoButSrcViewClick(dbswdbe, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWdbeGenDetail::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWdbeGenDetail::handleDpchAppDataContiac(
			DbsWdbe* dbswdbe
			, ContIac* _contiac
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFWID, ContIac::TXFMMX, ContIac::TXFDFV, ContIac::TXFCMT})) {
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

	if (has(diffitems, ContIac::TXFSRC)) {
		contiac.TxfSrc = _contiac->TxfSrc;
		refreshTxtSrc(dbswdbe, moditems);
		refresh(dbswdbe, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWdbeGenDetail::handleDpchAppDoButSaveClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWdbeGenDetail::handleDpchAppDoButCluViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButCluViewClick --- INSERT
};

void PnlWdbeGenDetail::handleDpchAppDoButCluClusterClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButCluClusterClick --- INSERT
};

void PnlWdbeGenDetail::handleDpchAppDoButCluUnclusterClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButCluUnclusterClick --- INSERT
};

void PnlWdbeGenDetail::handleDpchAppDoButMdlViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	ubigint refCvr = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCVR, jref);
	ubigint refUnt = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref);

	if (statshr.ButMdlViewAvail && statshr.ButMdlViewActive) {
		if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref)) if ((dbswdbe->getIxWSubsetByRefWdbeMModule(recGen.mdlRefWdbeMModule) & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMOD) != 0) if (refUnt != 0) {
			sref = "CrdWdbeMod";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, VecWdbeVPreset::PREWDBEREFUNT, refUnt, sref, recGen.mdlRefWdbeMModule, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref)) if ((dbswdbe->getIxWSubsetByRefWdbeMModule(recGen.mdlRefWdbeMModule) & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMOD) != 0) if (refCvr != 0) {
				sref = "CrdWdbeMod";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, VecWdbeVPreset::PREWDBEREFCVR, refCvr, sref, recGen.mdlRefWdbeMModule, jrefNew);
			};
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMTP, jref)) if ((dbswdbe->getIxWSubsetByRefWdbeMModule(recGen.mdlRefWdbeMModule) & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMTP) != 0) {
				sref = "CrdWdbeMtp";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, sref, recGen.mdlRefWdbeMModule, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, sref);
	};
};

void PnlWdbeGenDetail::handleDpchAppDoButHtyEditClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButHtyEditClick --- INSERT
};

void PnlWdbeGenDetail::handleDpchAppDoButSrcViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButSrcViewClick --- INSERT
};

void PnlWdbeGenDetail::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBEGENMOD_CLUEQ) {
		call->abort = handleCallWdbeGenMod_cluEq(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEKLSAKEYMOD_KLSMTBURFEQ) {
		call->abort = handleCallWdbeKlsAkeyMod_klsMtbUrfEq(dbswdbe, call->jref, call->argInv.ix, call->argInv.ref, call->argInv.sref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEGENUPD_REFEQ) {
		call->abort = handleCallWdbeGenUpd_refEq(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEGEN_MDLEQ) {
		call->abort = handleCallWdbeGen_mdlEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEGEN_MDL_INSBS) {
		call->abort = handleCallWdbeGen_mdl_inSbs(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEGEN_CLUEQ) {
		call->abort = handleCallWdbeGen_cluEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWdbeGenDetail::handleCallWdbeGenMod_cluEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	set<uint> moditems;

	refreshClu(dbswdbe, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

bool PnlWdbeGenDetail::handleCallWdbeKlsAkeyMod_klsMtbUrfEq(
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

bool PnlWdbeGenDetail::handleCallWdbeGenUpd_refEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWdbeGenUpd_refEq --- INSERT
	return retval;
};

bool PnlWdbeGenDetail::handleCallWdbeGen_mdlEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recGen.mdlRefWdbeMModule == refInv); // IP handleCallWdbeGen_mdlEq --- LINE
	return retval;
};

bool PnlWdbeGenDetail::handleCallWdbeGen_mdl_inSbs(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((dbswdbe->getIxWSubsetByRefWdbeMModule(recGen.mdlRefWdbeMModule) & ixInv) != 0); // IP handleCallWdbeGen_mdl_inSbs --- LINE
	return retval;
};

bool PnlWdbeGenDetail::handleCallWdbeGen_cluEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recGen.refWdbeCGeneric == refInv); // IP handleCallWdbeGen_cluEq --- LINE
	return retval;
};
