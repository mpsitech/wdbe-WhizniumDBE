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
	feedFLstRls.tag = "FeedFLstRls";
	feedFLstSys.tag = "FeedFLstSys";
	feedFLstTrg.tag = "FeedFLstTrg";
	feedFLstUnt.tag = "FeedFLstUnt";
	feedFLstVer.tag = "FeedFLstVer";

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refreshPrj(dbswdbe, moditems);
	refreshVer(dbswdbe, moditems);
	refreshSys(dbswdbe, moditems);
	refreshTrg(dbswdbe, moditems);
	refreshUnt(dbswdbe, moditems);
	refreshRls(dbswdbe, moditems);
	refresh(dbswdbe, moditems);

	xchg->addClstn(VecWdbeVCall::CALLWDBEHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	xchg->addIxRefClstn(VecWdbeVCall::CALLWDBEHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWdbeVCard::CRDWDBEPRJ, xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref));
	xchg->addIxRefClstn(VecWdbeVCall::CALLWDBEHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWdbeVCard::CRDWDBEVER, xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref));
	xchg->addIxRefClstn(VecWdbeVCall::CALLWDBEHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWdbeVCard::CRDWDBESYS, xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref));
	xchg->addIxRefClstn(VecWdbeVCall::CALLWDBEHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWdbeVCard::CRDWDBETRG, xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref));
	xchg->addIxRefClstn(VecWdbeVCall::CALLWDBEHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWdbeVCard::CRDWDBEUNT, xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref));
	xchg->addIxRefClstn(VecWdbeVCall::CALLWDBEHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWdbeVCard::CRDWDBERLS, xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref));
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
		dpcheng = new DpchEngData(jref, &contiac, &feedFLstPrj, &feedFLstRls, &feedFLstSys, &feedFLstTrg, &feedFLstUnt, &feedFLstVer, &statshr, items);
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

void PnlWdbeNavDevdev::refreshLstSys(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstSysAvail = evalLstSysAvail(dbswdbe);
	statshr.ButSysViewActive = evalButSysViewActive(dbswdbe);
	statshr.ButSysNewcrdActive = evalButSysNewcrdActive(dbswdbe);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeNavDevdev::refreshSys(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWdbeHistRMUserUniversal rst;
	WdbeHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstSys = 0;

	// feedFLstSys
	feedFLstSys.clear();

	dbswdbe->tblwdbehistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref), VecWdbeVCard::CRDWDBESYS, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstSys.appendRefTitles(rec->ref, StubWdbe::getStubSysStd(dbswdbe, rec->unvUref, ixWdbeVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTSYS);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstSys(dbswdbe, moditems);
};

void PnlWdbeNavDevdev::refreshLstTrg(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstTrgAvail = evalLstTrgAvail(dbswdbe);
	statshr.ButTrgViewActive = evalButTrgViewActive(dbswdbe);
	statshr.ButTrgNewcrdActive = evalButTrgNewcrdActive(dbswdbe);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeNavDevdev::refreshTrg(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWdbeHistRMUserUniversal rst;
	WdbeHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstTrg = 0;

	// feedFLstTrg
	feedFLstTrg.clear();

	dbswdbe->tblwdbehistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref), VecWdbeVCard::CRDWDBETRG, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstTrg.appendRefTitles(rec->ref, StubWdbe::getStubTrgStd(dbswdbe, rec->unvUref, ixWdbeVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTTRG);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstTrg(dbswdbe, moditems);
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

void PnlWdbeNavDevdev::refreshLstRls(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstRlsAvail = evalLstRlsAvail(dbswdbe);
	statshr.ButRlsViewActive = evalButRlsViewActive(dbswdbe);
	statshr.ButRlsNewcrdActive = evalButRlsNewcrdActive(dbswdbe);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeNavDevdev::refreshRls(
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
	refreshLstSys(dbswdbe, moditems);
	refreshLstTrg(dbswdbe, moditems);
	refreshLstUnt(dbswdbe, moditems);
	refreshLstRls(dbswdbe, moditems);
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
				} else if (dpchappdo->ixVDo == VecVDo::BUTSYSVIEWCLICK) {
					handleDpchAppDoButSysViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSYSNEWCRDCLICK) {
					handleDpchAppDoButSysNewcrdClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTTRGVIEWCLICK) {
					handleDpchAppDoButTrgViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTTRGNEWCRDCLICK) {
					handleDpchAppDoButTrgNewcrdClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTUNTVIEWCLICK) {
					handleDpchAppDoButUntViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTUNTNEWCRDCLICK) {
					handleDpchAppDoButUntNewcrdClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTRLSVIEWCLICK) {
					handleDpchAppDoButRlsViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTRLSNEWCRDCLICK) {
					handleDpchAppDoButRlsNewcrdClick(dbswdbe, &(req->dpcheng));
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

	if (has(diffitems, ContIac::NUMFLSTSYS)) {
		contiac.numFLstSys = _contiac->numFLstSys;
		refreshLstSys(dbswdbe, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTTRG)) {
		contiac.numFLstTrg = _contiac->numFLstTrg;
		refreshLstTrg(dbswdbe, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTUNT)) {
		contiac.numFLstUnt = _contiac->numFLstUnt;
		if (dbswdbe->tblwdbehistrmuseruniversal->loadUnuByRef(feedFLstUnt.getRefByNum(contiac.numFLstUnt), ref)) xchg->triggerIxRefCall(dbswdbe, VecWdbeVCall::CALLWDBEREFPRESET, jref, VecWdbeVPreset::PREWDBEREFUNT, ref);
		refreshLstUnt(dbswdbe, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTRLS)) {
		contiac.numFLstRls = _contiac->numFLstRls;
		refreshLstRls(dbswdbe, moditems);
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

void PnlWdbeNavDevdev::handleDpchAppDoButSysViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	WdbeHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstSysAvail && statshr.ButSysViewActive) {
		if (dbswdbe->tblwdbehistrmuseruniversal->loadRecByRef(feedFLstSys.getRefByNum(contiac.numFLstSys), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, husrRunv->ixWdbeVPreset, husrRunv->preUref, "CrdWdbeSys", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeSys");
	};
};

void PnlWdbeNavDevdev::handleDpchAppDoButSysNewcrdClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButSysNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbeSys", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeSys");
	};
};

void PnlWdbeNavDevdev::handleDpchAppDoButTrgViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	WdbeHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstTrgAvail && statshr.ButTrgViewActive) {
		if (dbswdbe->tblwdbehistrmuseruniversal->loadRecByRef(feedFLstTrg.getRefByNum(contiac.numFLstTrg), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, husrRunv->ixWdbeVPreset, husrRunv->preUref, "CrdWdbeTrg", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeTrg");
	};
};

void PnlWdbeNavDevdev::handleDpchAppDoButTrgNewcrdClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButTrgNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbeTrg", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeTrg");
	};
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

void PnlWdbeNavDevdev::handleDpchAppDoButRlsViewClick(
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

void PnlWdbeNavDevdev::handleDpchAppDoButRlsNewcrdClick(
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
	} else if (ixInv == VecWdbeVCard::CRDWDBESYS) {
		refreshSys(dbswdbe, moditems);
	} else if (ixInv == VecWdbeVCard::CRDWDBETRG) {
		refreshTrg(dbswdbe, moditems);
	} else if (ixInv == VecWdbeVCard::CRDWDBEUNT) {
		refreshUnt(dbswdbe, moditems);
	} else if (ixInv == VecWdbeVCard::CRDWDBERLS) {
		refreshRls(dbswdbe, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};



