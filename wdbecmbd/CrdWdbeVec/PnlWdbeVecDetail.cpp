/**
	* \file PnlWdbeVecDetail.cpp
	* job handler for job PnlWdbeVecDetail (implementation)
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

#include "PnlWdbeVecDetail.h"

#include "PnlWdbeVecDetail_blks.cpp"
#include "PnlWdbeVecDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWdbeVecDetail
 ******************************************************************************/

PnlWdbeVecDetail::PnlWdbeVecDetail(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::PNLWDBEVECDETAIL, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFLstOpt.tag = "FeedFLstOpt";
	dbswdbe->fillFeedFromKlst(VecWdbeVKeylist::KLSTWDBEKMVECTOROPTION, ixWdbeVLocale, feedFLstOpt);
	feedFPupHkt.tag = "FeedFPupHkt";
	VecWdbeVMVectorHkTbl::fillFeed(ixWdbeVLocale, feedFPupHkt);
	feedFPupTyp.tag = "FeedFPupTyp";
	VecWdbeVMVectorBasetype::fillFeed(ixWdbeVLocale, feedFPupTyp);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWdbeVCall::CALLWDBEKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEVEC_HKUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEVEC_HKU_MDL_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEVEC_HKTEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEVEC_HKU_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	xchg->addIxClstn(VecWdbeVCall::CALLWDBEKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWdbeVKeylist::KLSTWDBEKMVECTOROPTION);

	updatePreset(dbswdbe, VecWdbeVPreset::PREWDBEREFVEC, jref);
};

PnlWdbeVecDetail::~PnlWdbeVecDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* PnlWdbeVecDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFLstOpt, &feedFPupHkt, &feedFPupTyp, &statshr, items);
	};

	return dpcheng;
};

void PnlWdbeVecDetail::refreshLstOpt(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	set<uint> nums;

	vector<string> ss;
	string s;

	// contiac
	contiac.numsFLstOpt.clear();

	StrMod::srefsToVector(contiac.TxfOpt, ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		s = ss[i];

		for (unsigned int j = 0; j < feedFLstOpt.size(); j++) {
			if (feedFLstOpt.getSrefByNum(j+1) == s) {
				nums.insert(j+1);
				break;
			};
		};
	};

	for (auto it = nums.begin(); it != nums.end(); it++) contiac.numsFLstOpt.push_back(*it);

	// statshr
	statshr.TxfOptValid = ( (ss.size() == nums.size()) && (nums.size() == contiac.numsFLstOpt.size()) );
	statshr.LstOptActive = evalLstOptActive(dbswdbe);
	statshr.ButOptEditAvail = evalButOptEditAvail(dbswdbe);

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeVecDetail::refreshTxfOpt(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.TxfOpt = "";

	for (unsigned int i = 0; i < contiac.numsFLstOpt.size(); i++) {
		if (i != 0) contiac.TxfOpt += ";";
		contiac.TxfOpt += feedFLstOpt.getSrefByNum(contiac.numsFLstOpt[i]);
	};

	// statshr
	statshr.TxfOptValid = true;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeVecDetail::refreshOpt(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	// feedFLstOpt
	dbswdbe->fillFeedFromKlst(VecWdbeVKeylist::KLSTWDBEKMVECTOROPTION, ixWdbeVLocale, feedFLstOpt);

	insert(moditems, DpchEngData::FEEDFLSTOPT);

	refreshLstOpt(dbswdbe, moditems);
};

void PnlWdbeVecDetail::refreshRecVec(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WdbeMVector* _recVec = NULL;

	if (dbswdbe->tblwdbemvector->loadRecByRef(recVec.ref, &_recVec)) {
		recVec = *_recVec;
		delete _recVec;
	} else recVec = WdbeMVector();

	dirty = false;

	continf.TxtSrf = recVec.sref;
	contiac.numFPupTyp = feedFPupTyp.getNumByIx(recVec.ixVBasetype);
	contiac.numFPupHkt = feedFPupHkt.getNumByIx(recVec.hkIxVTbl);
	if (recVec.hkIxVTbl == VecWdbeVMVectorHkTbl::CTR) continf.TxtHku = StubWdbe::getStubCtrStd(dbswdbe, recVec.hkUref, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	else if (recVec.hkIxVTbl == VecWdbeVMVectorHkTbl::FSM) continf.TxtHku = StubWdbe::getStubFsmStd(dbswdbe, recVec.hkUref, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	else if (recVec.hkIxVTbl == VecWdbeVMVectorHkTbl::UNT) continf.TxtHku = StubWdbe::getStubUntStd(dbswdbe, recVec.hkUref, ixWdbeVLocale, Stub::VecVNonetype::FULL);
	else continf.TxtHku = "-";
	contiac.TxfOpt = recVec.srefsKOption;

	statshr.TxtSrfActive = evalTxtSrfActive(dbswdbe);
	statshr.PupTypActive = evalPupTypActive(dbswdbe);
	statshr.TxtHkuActive = evalTxtHkuActive(dbswdbe);
	statshr.ButHkuViewAvail = evalButHkuViewAvail(dbswdbe);
	statshr.ButHkuViewActive = evalButHkuViewActive(dbswdbe);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshLstOpt(dbswdbe, moditems);

};

void PnlWdbeVecDetail::refresh(
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

void PnlWdbeVecDetail::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFVEC) {
		recVec.ref = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVEC, jref);
		refreshRecVec(dbswdbe, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWdbeVecDetail::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVECDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswdbe, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVECDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTHKUVIEWCLICK) {
					handleDpchAppDoButHkuViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTOPTEDITCLICK) {
					handleDpchAppDoButOptEditClick(dbswdbe, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWdbeVecDetail::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWdbeVecDetail::handleDpchAppDataContiac(
			DbsWdbe* dbswdbe
			, ContIac* _contiac
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::NUMFPUPTYP})) {
		if (has(diffitems, ContIac::NUMFPUPTYP)) contiac.numFPupTyp = _contiac->numFPupTyp;
	};

	if (has(diffitems, ContIac::TXFOPT)) {
		contiac.TxfOpt = _contiac->TxfOpt;
		refreshLstOpt(dbswdbe, moditems);
	} else if (has(diffitems, ContIac::NUMSFLSTOPT)) {
		contiac.numsFLstOpt = _contiac->numsFLstOpt;
		refreshTxfOpt(dbswdbe, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWdbeVecDetail::handleDpchAppDoButSaveClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWdbeVecDetail::handleDpchAppDoButHkuViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	uint ixPre = xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXPRE, jref);
	ubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);

	if (statshr.ButHkuViewAvail && statshr.ButHkuViewActive) {
		if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref)) if (recVec.hkIxVTbl == VecWdbeVMVectorHkTbl::CTR) if ((dbswdbe->getIxWSubsetByRefWdbeMModule([&](){ubigint ref; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE refWdbeMController = " + to_string(recVec.hkUref), ref); return ref;}()) & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMOD) != 0) if (ixPre == VecWdbeVPreset::PREWDBEREFUNT) {
			sref = "CrdWdbeMod";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, ixPre, refPre, sref, [&](){ubigint ref = 0; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE refWdbeMController = " + to_string(recVec.hkUref), ref); return ref;}(), jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref)) if (recVec.hkIxVTbl == VecWdbeVMVectorHkTbl::CTR) if ((dbswdbe->getIxWSubsetByRefWdbeMModule([&](){ubigint ref; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE refWdbeMController = " + to_string(recVec.hkUref), ref); return ref;}()) & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMOD) != 0) if (ixPre == VecWdbeVPreset::PREWDBEREFCVR) {
				sref = "CrdWdbeMod";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, ixPre, refPre, sref, [&](){ubigint ref = 0; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE refWdbeMController = " + to_string(recVec.hkUref), ref); return ref;}(), jrefNew);
			};
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMTP, jref)) if (recVec.hkIxVTbl == VecWdbeVMVectorHkTbl::CTR) if ((dbswdbe->getIxWSubsetByRefWdbeMModule([&](){ubigint ref; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE refWdbeMController = " + to_string(recVec.hkUref), ref); return ref;}()) & VecWdbeWMModuleSubset::SBSWDBEBMMODULEMTP) != 0) {
				sref = "CrdWdbeMtp";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, sref, [&](){ubigint ref = 0; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE refWdbeMController = " + to_string(recVec.hkUref), ref); return ref;}(), jrefNew);
			};
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIG, jref)) if (recVec.hkIxVTbl == VecWdbeVMVectorHkTbl::SIG) if (ixPre == VecWdbeVPreset::PREWDBEREFUNT) {
				sref = "CrdWdbeSig";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, ixPre, refPre, sref, recVec.hkUref, jrefNew);
			};
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCUNT, jref)) if (recVec.hkIxVTbl == VecWdbeVMVectorHkTbl::UNT) if (ixPre == VecWdbeVPreset::PREWDBEREFVER) {
				sref = "CrdWdbeUnt";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, ixPre, refPre, sref, recVec.hkUref, jrefNew);
			};
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIL, jref)) if (recVec.hkIxVTbl == VecWdbeVMVectorHkTbl::UNT) if ((dbswdbe->getIxWSubsetByRefWdbeMUnit(recVec.hkUref) & VecWdbeWMUnitSubset::SBSWDBEBMUNITSIL) != 0) {
				sref = "CrdWdbeSil";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, sref, recVec.hkUref, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, sref);
	};
};

void PnlWdbeVecDetail::handleDpchAppDoButOptEditClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButOptEditClick --- INSERT
};

void PnlWdbeVecDetail::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBEKLSAKEYMOD_KLSEQ) {
		call->abort = handleCallWdbeKlsAkeyMod_klsEq(dbswdbe, call->jref, call->argInv.ix);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEVECUPD_REFEQ) {
		call->abort = handleCallWdbeVecUpd_refEq(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEVEC_HKUEQ) {
		call->abort = handleCallWdbeVec_hkuEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEVEC_HKU_MDL_INSBS) {
		call->abort = handleCallWdbeVec_hku_mdl_inSbs(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEVEC_HKTEQ) {
		call->abort = handleCallWdbeVec_hktEq(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEVEC_HKU_INSBS) {
		call->abort = handleCallWdbeVec_hku_inSbs(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	};
};

bool PnlWdbeVecDetail::handleCallWdbeKlsAkeyMod_klsEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecWdbeVKeylist::KLSTWDBEKMVECTOROPTION) {
		refreshOpt(dbswdbe, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

bool PnlWdbeVecDetail::handleCallWdbeVecUpd_refEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWdbeVecUpd_refEq --- INSERT
	return retval;
};

bool PnlWdbeVecDetail::handleCallWdbeVec_hkuEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recVec.hkUref == refInv); // IP handleCallWdbeVec_hkuEq --- LINE
	return retval;
};

bool PnlWdbeVecDetail::handleCallWdbeVec_hku_mdl_inSbs(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((dbswdbe->getIxWSubsetByRefWdbeMModule([&](){ubigint ref; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE refWdbeMController = " + to_string(recVec.hkUref), ref); return ref;}()) & ixInv) != 0); // IP handleCallWdbeVec_hku_mdl_inSbs --- LINE
	return retval;
};

bool PnlWdbeVecDetail::handleCallWdbeVec_hktEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recVec.hkIxVTbl == ixInv); // IP handleCallWdbeVec_hktEq --- LINE
	return retval;
};

bool PnlWdbeVecDetail::handleCallWdbeVec_hku_inSbs(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((dbswdbe->getIxWSubsetByRefWdbeMUnit(recVec.hkUref) & ixInv) != 0); // IP handleCallWdbeVec_hku_inSbs --- LINE
	return retval;
};
