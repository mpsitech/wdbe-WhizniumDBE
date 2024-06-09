/**
	* \file PnlWdbeNavDevdev.cpp
	* job handler for job PnlWdbeNavDevdev (implementation)
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

#include "PnlWdbeNavDevdev.h"

#include "PnlWdbeNavDevdev_blks.cpp"
#include "PnlWdbeNavDevdev_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWdbeNavDevdev
 ******************************************************************************/

PnlWdbeNavDevdev::PnlWdbeNavDevdev(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::PNLWDBENAVDEVDEV, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFLstPrj.tag = "FeedFLstPrj";
	feedFLstUnt.tag = "FeedFLstUnt";
	feedFLstVer.tag = "FeedFLstVer";

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refreshPrj(dbswdbe, moditems);
	refreshVer(dbswdbe, moditems);
	refreshUnt(dbswdbe, moditems);
	refresh(dbswdbe, moditems);

	xchg->addClstn(VecWdbeVCall::CALLWDBEHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	xchg->addIxRefClstn(VecWdbeVCall::CALLWDBEHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWdbeVCard::CRDWDBEPRJ, xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref));
	xchg->addIxRefClstn(VecWdbeVCall::CALLWDBEHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWdbeVCard::CRDWDBEVER, xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref));
	xchg->addIxRefClstn(VecWdbeVCall::CALLWDBEHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWdbeVCard::CRDWDBEUNT, xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref));
};

PnlWdbeNavDevdev::~PnlWdbeNavDevdev() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* PnlWdbeNavDevdev::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &feedFLstPrj, &feedFLstUnt, &feedFLstVer, &statshr, items);
	};

	return dpcheng;
};

void PnlWdbeNavDevdev::refreshLstPrj(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstPrjAvail = evalLstPrjAvail(dbswdbe);
	statshr.ButPrjViewActive = evalButPrjViewActive(dbswdbe);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeNavDevdev::refreshPrj(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWdbeHistRMUserUniversal rst;
	WdbeHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstPrj = 0;

	// feedFLstPrj
	feedFLstPrj.clear();

	dbswdbe->tblwdbehistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref), VecWdbeVCard::CRDWDBEPRJ, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstPrj.appendRefTitles(rec->ref, StubWdbe::getStubPrjStd(dbswdbe, rec->unvUref, ixWdbeVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTPRJ);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstPrj(dbswdbe, moditems);
};

void PnlWdbeNavDevdev::refreshLstVer(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstVerAvail = evalLstVerAvail(dbswdbe);
	statshr.ButVerViewActive = evalButVerViewActive(dbswdbe);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeNavDevdev::refreshVer(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWdbeHistRMUserUniversal rst;
	WdbeHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstVer = 0;

	// feedFLstVer
	feedFLstVer.clear();

	dbswdbe->tblwdbehistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref), VecWdbeVCard::CRDWDBEVER, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstVer.appendRefTitles(rec->ref, StubWdbe::getStubVerStd(dbswdbe, rec->unvUref, ixWdbeVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTVER);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstVer(dbswdbe, moditems);
};

void PnlWdbeNavDevdev::refreshLstUnt(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstUntAvail = evalLstUntAvail(dbswdbe);
	statshr.ButUntViewActive = evalButUntViewActive(dbswdbe);
	statshr.ButUntNewcrdActive = evalButUntNewcrdActive(dbswdbe);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeNavDevdev::refreshUnt(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWdbeHistRMUserUniversal rst;
	WdbeHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstUnt = 0;

	// feedFLstUnt
	feedFLstUnt.clear();

	dbswdbe->tblwdbehistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref), VecWdbeVCard::CRDWDBEUNT, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstUnt.appendRefTitles(rec->ref, StubWdbe::getStubUntStd(dbswdbe, rec->unvUref, ixWdbeVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTUNT);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstUnt(dbswdbe, moditems);
};

void PnlWdbeNavDevdev::refresh(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	// IP refresh --- INSERT

	muteRefresh = false;
};

void PnlWdbeNavDevdev::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	refresh(dbswdbe, moditems);

	refreshLstPrj(dbswdbe, moditems);
	refreshLstVer(dbswdbe, moditems);
	refreshLstUnt(dbswdbe, moditems);
	if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	// IP updatePreset --- END
};

void PnlWdbeNavDevdev::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVDEVDEVDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswdbe, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVDEVDEVDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTPRJVIEWCLICK) {
					handleDpchAppDoButPrjViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRJNEWCRDCLICK) {
					handleDpchAppDoButPrjNewcrdClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTVERVIEWCLICK) {
					handleDpchAppDoButVerViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTVERNEWCRDCLICK) {
					handleDpchAppDoButVerNewcrdClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTUNTVIEWCLICK) {
					handleDpchAppDoButUntViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTUNTNEWCRDCLICK) {
					handleDpchAppDoButUntNewcrdClick(dbswdbe, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWdbeNavDevdev::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWdbeNavDevdev::handleDpchAppDataContiac(
			DbsWdbe* dbswdbe
			, ContIac* _contiac
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	ubigint ref;

	if (has(diffitems, ContIac::NUMFLSTPRJ)) {
		contiac.numFLstPrj = _contiac->numFLstPrj;
		refreshLstPrj(dbswdbe, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTVER)) {
		contiac.numFLstVer = _contiac->numFLstVer;
		if (dbswdbe->tblwdbehistrmuseruniversal->loadUnuByRef(feedFLstVer.getRefByNum(contiac.numFLstVer), ref)) xchg->triggerIxRefCall(dbswdbe, VecWdbeVCall::CALLWDBEREFPRESET, jref, VecWdbeVPreset::PREWDBEREFVER, ref);
		refreshLstVer(dbswdbe, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTUNT)) {
		contiac.numFLstUnt = _contiac->numFLstUnt;
		if (dbswdbe->tblwdbehistrmuseruniversal->loadUnuByRef(feedFLstUnt.getRefByNum(contiac.numFLstUnt), ref)) xchg->triggerIxRefCall(dbswdbe, VecWdbeVCall::CALLWDBEREFPRESET, jref, VecWdbeVPreset::PREWDBEREFUNT, ref);
		refreshLstUnt(dbswdbe, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWdbeNavDevdev::handleDpchAppDoButPrjViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	WdbeHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstPrjAvail && statshr.ButPrjViewActive) {
		if (dbswdbe->tblwdbehistrmuseruniversal->loadRecByRef(feedFLstPrj.getRefByNum(contiac.numFLstPrj), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, husrRunv->ixWdbeVPreset, husrRunv->preUref, "CrdWdbePrj", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbePrj");
	};
};

void PnlWdbeNavDevdev::handleDpchAppDoButPrjNewcrdClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbePrj", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
	else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbePrj");
};

void PnlWdbeNavDevdev::handleDpchAppDoButVerViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	WdbeHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstVerAvail && statshr.ButVerViewActive) {
		if (dbswdbe->tblwdbehistrmuseruniversal->loadRecByRef(feedFLstVer.getRefByNum(contiac.numFLstVer), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, husrRunv->ixWdbeVPreset, husrRunv->preUref, "CrdWdbeVer", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeVer");
	};
};

void PnlWdbeNavDevdev::handleDpchAppDoButVerNewcrdClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbeVer", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
	else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeVer");
};

void PnlWdbeNavDevdev::handleDpchAppDoButUntViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	WdbeHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstUntAvail && statshr.ButUntViewActive) {
		if (dbswdbe->tblwdbehistrmuseruniversal->loadRecByRef(feedFLstUnt.getRefByNum(contiac.numFLstUnt), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, husrRunv->ixWdbeVPreset, husrRunv->preUref, "CrdWdbeUnt", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeUnt");
	};
};

void PnlWdbeNavDevdev::handleDpchAppDoButUntNewcrdClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButUntNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbeUnt", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeUnt");
	};
};

void PnlWdbeNavDevdev::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBEHUSRRUNVMOD_CRDUSREQ) {
		call->abort = handleCallWdbeHusrRunvMod_crdUsrEq(dbswdbe, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool PnlWdbeNavDevdev::handleCallWdbeHusrRunvMod_crdUsrEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecWdbeVCard::CRDWDBEPRJ) {
		refreshPrj(dbswdbe, moditems);
	} else if (ixInv == VecWdbeVCard::CRDWDBEVER) {
		refreshVer(dbswdbe, moditems);
	} else if (ixInv == VecWdbeVCard::CRDWDBEUNT) {
		refreshUnt(dbswdbe, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};
