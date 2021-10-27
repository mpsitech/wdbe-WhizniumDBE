/**
	* \file PnlWdbeMtpDetail.cpp
	* job handler for job PnlWdbeMtpDetail (implementation)
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

#include "PnlWdbeMtpDetail.h"

#include "PnlWdbeMtpDetail_blks.cpp"
#include "PnlWdbeMtpDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWdbeMtpDetail
 ******************************************************************************/

PnlWdbeMtpDetail::PnlWdbeMtpDetail(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::PNLWDBEMTPDETAIL, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFPupTyp.tag = "FeedFPupTyp";
	VecWdbeVMModuleBasetype::fillFeed(ixWdbeVLocale, feedFPupTyp);
	feedFPupVnd.tag = "FeedFPupVnd";
	dbswdbe->fillFeedFromKlst(VecWdbeVKeylist::KLSTWDBEKVENDOR, ixWdbeVLocale, feedFPupVnd);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWdbeVCall::CALLWDBEMDL_CTREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEMDL_HKTEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEMDL_HKU_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEMDL_HKUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEMDL_IMBEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEMDL_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEMDL_SUP_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEMDL_SUPEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEMDL_TPLEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEMDL_TYPEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	xchg->addIxClstn(VecWdbeVCall::CALLWDBEKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWdbeVKeylist::KLSTWDBEKVENDOR);

	updatePreset(dbswdbe, VecWdbeVPreset::PREWDBEREFMTP, jref);
};

PnlWdbeMtpDetail::~PnlWdbeMtpDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* PnlWdbeMtpDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupTyp, &feedFPupVnd, &statshr, items);
	};

	return dpcheng;
};

void PnlWdbeMtpDetail::refreshPupVnd(
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

void PnlWdbeMtpDetail::refreshTxfVnd(
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

void PnlWdbeMtpDetail::refreshVnd(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	// feedFPupVnd
	dbswdbe->fillFeedFromKlst(VecWdbeVKeylist::KLSTWDBEKVENDOR, ixWdbeVLocale, feedFPupVnd);

	insert(moditems, DpchEngData::FEEDFPUPVND);

	refreshPupVnd(dbswdbe, moditems);
};

void PnlWdbeMtpDetail::refreshRecMdl(
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

	continf.TxtSrf = recMdl.sref;
	contiac.TxfVnd = recMdl.srefWdbeKVendor;
	contiac.numFPupTyp = feedFPupTyp.getNumByIx(recMdl.ixVBasetype);
	contiac.TxfSrr = recMdl.Srefrule;
	contiac.TxfCmt = recMdl.Comment;

	statshr.TxtSrfActive = evalTxtSrfActive(dbswdbe);
	statshr.PupTypActive = evalPupTypActive(dbswdbe);
	statshr.TxfSrrActive = evalTxfSrrActive(dbswdbe);
	statshr.TxfCmtActive = evalTxfCmtActive(dbswdbe);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshPupVnd(dbswdbe, moditems);

};

void PnlWdbeMtpDetail::refresh(
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

void PnlWdbeMtpDetail::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFMTP) {
		recMdl.ref = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFMTP, jref);
		refreshRecMdl(dbswdbe, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWdbeMtpDetail::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswdbe, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTVNDEDITCLICK) {
					handleDpchAppDoButVndEditClick(dbswdbe, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWdbeMtpDetail::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWdbeMtpDetail::handleDpchAppDataContiac(
			DbsWdbe* dbswdbe
			, ContIac* _contiac
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::NUMFPUPTYP, ContIac::TXFSRR, ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::NUMFPUPTYP)) contiac.numFPupTyp = _contiac->numFPupTyp;
		if (has(diffitems, ContIac::TXFSRR)) contiac.TxfSrr = _contiac->TxfSrr;
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
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

void PnlWdbeMtpDetail::handleDpchAppDoButSaveClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWdbeMtpDetail::handleDpchAppDoButVndEditClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButVndEditClick --- INSERT
};

void PnlWdbeMtpDetail::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBEMDL_CTREQ) {
		call->abort = handleCallWdbeMdl_ctrEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDL_HKTEQ) {
		call->abort = handleCallWdbeMdl_hktEq(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDL_HKU_INSBS) {
		call->abort = handleCallWdbeMdl_hku_inSbs(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDL_HKUEQ) {
		call->abort = handleCallWdbeMdl_hkuEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDL_IMBEQ) {
		call->abort = handleCallWdbeMdl_imbEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDL_INSBS) {
		call->abort = handleCallWdbeMdl_inSbs(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDL_SUP_INSBS) {
		call->abort = handleCallWdbeMdl_sup_inSbs(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDL_SUPEQ) {
		call->abort = handleCallWdbeMdl_supEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDL_TPLEQ) {
		call->abort = handleCallWdbeMdl_tplEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDL_TYPEQ) {
		call->abort = handleCallWdbeMdl_typEq(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDLUPD_REFEQ) {
		call->abort = handleCallWdbeMdlUpd_refEq(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEKLSAKEYMOD_KLSEQ) {
		call->abort = handleCallWdbeKlsAkeyMod_klsEq(dbswdbe, call->jref, call->argInv.ix);
	};
};

bool PnlWdbeMtpDetail::handleCallWdbeMdl_ctrEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recMdl.refWdbeMController == refInv); // IP handleCallWdbeMdl_ctrEq --- LINE
	return retval;
};

bool PnlWdbeMtpDetail::handleCallWdbeMdl_hktEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recMdl.hkIxVTbl == ixInv); // IP handleCallWdbeMdl_hktEq --- LINE
	return retval;
};

bool PnlWdbeMtpDetail::handleCallWdbeMdl_hku_inSbs(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((dbswdbe->getIxWSubsetByRefWdbeMUnit(recMdl.hkUref) & ixInv) != 0); // IP handleCallWdbeMdl_hku_inSbs --- LINE
	return retval;
};

bool PnlWdbeMtpDetail::handleCallWdbeMdl_hkuEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recMdl.hkUref == refInv); // IP handleCallWdbeMdl_hkuEq --- LINE
	return retval;
};

bool PnlWdbeMtpDetail::handleCallWdbeMdl_imbEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recMdl.refWdbeMImbuf == refInv); // IP handleCallWdbeMdl_imbEq --- LINE
	return retval;
};

bool PnlWdbeMtpDetail::handleCallWdbeMdl_inSbs(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((ixWSubsetMdl & ixInv) != 0); // IP handleCallWdbeMdl_inSbs --- LINE
	return retval;
};

bool PnlWdbeMtpDetail::handleCallWdbeMdl_sup_inSbs(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((dbswdbe->getIxWSubsetByRefWdbeMModule(recMdl.supRefWdbeMModule) & ixInv) != 0); // IP handleCallWdbeMdl_sup_inSbs --- LINE
	return retval;
};

bool PnlWdbeMtpDetail::handleCallWdbeMdl_supEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recMdl.supRefWdbeMModule == refInv); // IP handleCallWdbeMdl_supEq --- LINE
	return retval;
};

bool PnlWdbeMtpDetail::handleCallWdbeMdl_tplEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recMdl.tplRefWdbeMModule == refInv); // IP handleCallWdbeMdl_tplEq --- LINE
	return retval;
};

bool PnlWdbeMtpDetail::handleCallWdbeMdl_typEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recMdl.ixVBasetype == ixInv); // IP handleCallWdbeMdl_typEq --- LINE
	return retval;
};

bool PnlWdbeMtpDetail::handleCallWdbeMdlUpd_refEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWdbeMdlUpd_refEq --- INSERT
	return retval;
};

bool PnlWdbeMtpDetail::handleCallWdbeKlsAkeyMod_klsEq(
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
