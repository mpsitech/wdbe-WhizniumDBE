/**
	* \file PnlWdbeNavDeploy.cpp
	* job handler for job PnlWdbeNavDeploy (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Sep 2023
	*/
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbed.h>
#endif

#include "PnlWdbeNavDeploy.h"

#include "PnlWdbeNavDeploy_blks.cpp"
#include "PnlWdbeNavDeploy_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWdbeNavDeploy
 ******************************************************************************/

PnlWdbeNavDeploy::PnlWdbeNavDeploy(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::PNLWDBENAVDEPLOY, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFLstCmp.tag = "FeedFLstCmp";
	feedFLstRls.tag = "FeedFLstRls";

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refreshCmp(dbswdbe, moditems);
	refreshRls(dbswdbe, moditems);
	refresh(dbswdbe, moditems);

	xchg->addClstn(VecWdbeVCall::CALLWDBEHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	xchg->addIxRefClstn(VecWdbeVCall::CALLWDBEHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWdbeVCard::CRDWDBECMP, xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref));
	xchg->addIxRefClstn(VecWdbeVCall::CALLWDBEHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWdbeVCard::CRDWDBERLS, xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref));
};

PnlWdbeNavDeploy::~PnlWdbeNavDeploy() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* PnlWdbeNavDeploy::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &feedFLstCmp, &feedFLstRls, &statshr, items);
	};

	return dpcheng;
};

void PnlWdbeNavDeploy::refreshLstCmp(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstCmpAvail = evalLstCmpAvail(dbswdbe);
	statshr.ButCmpViewActive = evalButCmpViewActive(dbswdbe);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeNavDeploy::refreshCmp(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWdbeHistRMUserUniversal rst;
	WdbeHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstCmp = 0;

	// feedFLstCmp
	feedFLstCmp.clear();

	dbswdbe->tblwdbehistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref), VecWdbeVCard::CRDWDBECMP, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstCmp.appendRefTitles(rec->ref, StubWdbe::getStubCmpStd(dbswdbe, rec->unvUref, ixWdbeVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTCMP);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstCmp(dbswdbe, moditems);
};

void PnlWdbeNavDeploy::refreshLstRls(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstRlsAvail = evalLstRlsAvail(dbswdbe);
	statshr.ButRlsViewActive = evalButRlsViewActive(dbswdbe);
	statshr.ButRlsNewcrdActive = evalButRlsNewcrdActive(dbswdbe);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeNavDeploy::refreshRls(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWdbeHistRMUserUniversal rst;
	WdbeHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstRls = 0;

	// feedFLstRls
	feedFLstRls.clear();

	dbswdbe->tblwdbehistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref), VecWdbeVCard::CRDWDBERLS, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstRls.appendRefTitles(rec->ref, StubWdbe::getStubRlsStd(dbswdbe, rec->unvUref, ixWdbeVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTRLS);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstRls(dbswdbe, moditems);
};

void PnlWdbeNavDeploy::refresh(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	// IP refresh --- INSERT

	muteRefresh = false;
};

void PnlWdbeNavDeploy::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	refresh(dbswdbe, moditems);

	refreshLstCmp(dbswdbe, moditems);
	refreshLstRls(dbswdbe, moditems);
	if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	// IP updatePreset --- END
};

void PnlWdbeNavDeploy::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVDEPLOYDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswdbe, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVDEPLOYDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTCMPVIEWCLICK) {
					handleDpchAppDoButCmpViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCMPNEWCRDCLICK) {
					handleDpchAppDoButCmpNewcrdClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTRLSVIEWCLICK) {
					handleDpchAppDoButRlsViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTRLSNEWCRDCLICK) {
					handleDpchAppDoButRlsNewcrdClick(dbswdbe, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWdbeNavDeploy::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWdbeNavDeploy::handleDpchAppDataContiac(
			DbsWdbe* dbswdbe
			, ContIac* _contiac
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFLSTCMP)) {
		contiac.numFLstCmp = _contiac->numFLstCmp;
		refreshLstCmp(dbswdbe, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTRLS)) {
		contiac.numFLstRls = _contiac->numFLstRls;
		refreshLstRls(dbswdbe, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWdbeNavDeploy::handleDpchAppDoButCmpViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	WdbeHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstCmpAvail && statshr.ButCmpViewActive) {
		if (dbswdbe->tblwdbehistrmuseruniversal->loadRecByRef(feedFLstCmp.getRefByNum(contiac.numFLstCmp), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, husrRunv->ixWdbeVPreset, husrRunv->preUref, "CrdWdbeCmp", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeCmp");
	};
};

void PnlWdbeNavDeploy::handleDpchAppDoButCmpNewcrdClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbeCmp", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
	else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeCmp");
};

void PnlWdbeNavDeploy::handleDpchAppDoButRlsViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	WdbeHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstRlsAvail && statshr.ButRlsViewActive) {
		if (dbswdbe->tblwdbehistrmuseruniversal->loadRecByRef(feedFLstRls.getRefByNum(contiac.numFLstRls), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, husrRunv->ixWdbeVPreset, husrRunv->preUref, "CrdWdbeRls", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeRls");
	};
};

void PnlWdbeNavDeploy::handleDpchAppDoButRlsNewcrdClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButRlsNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbeRls", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeRls");
	};
};

void PnlWdbeNavDeploy::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBEHUSRRUNVMOD_CRDUSREQ) {
		call->abort = handleCallWdbeHusrRunvMod_crdUsrEq(dbswdbe, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool PnlWdbeNavDeploy::handleCallWdbeHusrRunvMod_crdUsrEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecWdbeVCard::CRDWDBECMP) {
		refreshCmp(dbswdbe, moditems);
	} else if (ixInv == VecWdbeVCard::CRDWDBERLS) {
		refreshRls(dbswdbe, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};
