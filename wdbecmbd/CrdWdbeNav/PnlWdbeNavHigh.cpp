/**
	* \file PnlWdbeNavHigh.cpp
	* job handler for job PnlWdbeNavHigh (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbed.h>
#endif

#include "PnlWdbeNavHigh.h"

#include "PnlWdbeNavHigh_blks.cpp"
#include "PnlWdbeNavHigh_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWdbeNavHigh
 ******************************************************************************/

PnlWdbeNavHigh::PnlWdbeNavHigh(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::PNLWDBENAVHIGH, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFLstCmd.tag = "FeedFLstCmd";
	feedFLstErr.tag = "FeedFLstErr";
	feedFLstMod.tag = "FeedFLstMod";
	feedFLstPph.tag = "FeedFLstPph";
	feedFLstPpl.tag = "FeedFLstPpl";
	feedFLstSeg.tag = "FeedFLstSeg";
	feedFLstVec.tag = "FeedFLstVec";
	feedFLstVit.tag = "FeedFLstVit";

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refreshPph(dbswdbe, moditems);
	refreshMod(dbswdbe, moditems);
	refreshVec(dbswdbe, moditems);
	refreshVit(dbswdbe, moditems);
	refreshCmd(dbswdbe, moditems);
	refreshErr(dbswdbe, moditems);
	refreshPpl(dbswdbe, moditems);
	refreshSeg(dbswdbe, moditems);
	refresh(dbswdbe, moditems);

	xchg->addClstn(VecWdbeVCall::CALLWDBEHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	xchg->addIxRefClstn(VecWdbeVCall::CALLWDBEHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWdbeVCard::CRDWDBEPPH, xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref));
	xchg->addIxRefClstn(VecWdbeVCall::CALLWDBEHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWdbeVCard::CRDWDBEMOD, xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref));
	xchg->addIxRefClstn(VecWdbeVCall::CALLWDBEHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWdbeVCard::CRDWDBEVEC, xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref));
	xchg->addIxRefClstn(VecWdbeVCall::CALLWDBEHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWdbeVCard::CRDWDBEVIT, xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref));
	xchg->addIxRefClstn(VecWdbeVCall::CALLWDBEHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWdbeVCard::CRDWDBECMD, xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref));
	xchg->addIxRefClstn(VecWdbeVCall::CALLWDBEHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWdbeVCard::CRDWDBEERR, xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref));
	xchg->addIxRefClstn(VecWdbeVCall::CALLWDBEHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWdbeVCard::CRDWDBEPPL, xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref));
	xchg->addIxRefClstn(VecWdbeVCall::CALLWDBEHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWdbeVCard::CRDWDBESEG, xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref));
};

PnlWdbeNavHigh::~PnlWdbeNavHigh() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* PnlWdbeNavHigh::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &feedFLstCmd, &feedFLstErr, &feedFLstMod, &feedFLstPph, &feedFLstPpl, &feedFLstSeg, &feedFLstVec, &feedFLstVit, &statshr, items);
	};

	return dpcheng;
};

void PnlWdbeNavHigh::refreshLstPph(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstPphAvail = evalLstPphAvail(dbswdbe);
	statshr.ButPphViewActive = evalButPphViewActive(dbswdbe);
	statshr.ButPphNewcrdActive = evalButPphNewcrdActive(dbswdbe);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeNavHigh::refreshPph(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWdbeHistRMUserUniversal rst;
	WdbeHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstPph = 0;

	// feedFLstPph
	feedFLstPph.clear();

	dbswdbe->tblwdbehistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref), VecWdbeVCard::CRDWDBEPPH, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstPph.appendRefTitles(rec->ref, StubWdbe::getStubPphStd(dbswdbe, rec->unvUref, ixWdbeVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTPPH);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstPph(dbswdbe, moditems);
};

void PnlWdbeNavHigh::refreshLstMod(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstModAvail = evalLstModAvail(dbswdbe);
	statshr.ButModViewActive = evalButModViewActive(dbswdbe);
	statshr.ButModNewcrdActive = evalButModNewcrdActive(dbswdbe);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeNavHigh::refreshMod(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWdbeHistRMUserUniversal rst;
	WdbeHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstMod = 0;

	// feedFLstMod
	feedFLstMod.clear();

	dbswdbe->tblwdbehistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref), VecWdbeVCard::CRDWDBEMOD, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstMod.appendRefTitles(rec->ref, StubWdbe::getStubModStd(dbswdbe, rec->unvUref, ixWdbeVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTMOD);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstMod(dbswdbe, moditems);
};

void PnlWdbeNavHigh::refreshLstVec(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstVecAvail = evalLstVecAvail(dbswdbe);
	statshr.ButVecViewActive = evalButVecViewActive(dbswdbe);
	statshr.ButVecNewcrdActive = evalButVecNewcrdActive(dbswdbe);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeNavHigh::refreshVec(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWdbeHistRMUserUniversal rst;
	WdbeHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstVec = 0;

	// feedFLstVec
	feedFLstVec.clear();

	dbswdbe->tblwdbehistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref), VecWdbeVCard::CRDWDBEVEC, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstVec.appendRefTitles(rec->ref, StubWdbe::getStubVecStd(dbswdbe, rec->unvUref, ixWdbeVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTVEC);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstVec(dbswdbe, moditems);
};

void PnlWdbeNavHigh::refreshLstVit(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstVitAvail = evalLstVitAvail(dbswdbe);
	statshr.ButVitViewActive = evalButVitViewActive(dbswdbe);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeNavHigh::refreshVit(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWdbeHistRMUserUniversal rst;
	WdbeHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstVit = 0;

	// feedFLstVit
	feedFLstVit.clear();

	dbswdbe->tblwdbehistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref), VecWdbeVCard::CRDWDBEVIT, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstVit.appendRefTitles(rec->ref, StubWdbe::getStubVitStd(dbswdbe, rec->unvUref, ixWdbeVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTVIT);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstVit(dbswdbe, moditems);
};

void PnlWdbeNavHigh::refreshLstCmd(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstCmdAvail = evalLstCmdAvail(dbswdbe);
	statshr.ButCmdViewActive = evalButCmdViewActive(dbswdbe);
	statshr.ButCmdNewcrdActive = evalButCmdNewcrdActive(dbswdbe);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeNavHigh::refreshCmd(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWdbeHistRMUserUniversal rst;
	WdbeHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstCmd = 0;

	// feedFLstCmd
	feedFLstCmd.clear();

	dbswdbe->tblwdbehistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref), VecWdbeVCard::CRDWDBECMD, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstCmd.appendRefTitles(rec->ref, StubWdbe::getStubCmdStd(dbswdbe, rec->unvUref, ixWdbeVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTCMD);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstCmd(dbswdbe, moditems);
};

void PnlWdbeNavHigh::refreshLstErr(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstErrAvail = evalLstErrAvail(dbswdbe);
	statshr.ButErrViewActive = evalButErrViewActive(dbswdbe);
	statshr.ButErrNewcrdActive = evalButErrNewcrdActive(dbswdbe);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeNavHigh::refreshErr(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWdbeHistRMUserUniversal rst;
	WdbeHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstErr = 0;

	// feedFLstErr
	feedFLstErr.clear();

	dbswdbe->tblwdbehistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref), VecWdbeVCard::CRDWDBEERR, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstErr.appendRefTitles(rec->ref, StubWdbe::getStubErrStd(dbswdbe, rec->unvUref, ixWdbeVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTERR);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstErr(dbswdbe, moditems);
};

void PnlWdbeNavHigh::refreshLstPpl(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstPplAvail = evalLstPplAvail(dbswdbe);
	statshr.ButPplViewActive = evalButPplViewActive(dbswdbe);
	statshr.ButPplNewcrdActive = evalButPplNewcrdActive(dbswdbe);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeNavHigh::refreshPpl(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWdbeHistRMUserUniversal rst;
	WdbeHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstPpl = 0;

	// feedFLstPpl
	feedFLstPpl.clear();

	dbswdbe->tblwdbehistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref), VecWdbeVCard::CRDWDBEPPL, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstPpl.appendRefTitles(rec->ref, StubWdbe::getStubPplStd(dbswdbe, rec->unvUref, ixWdbeVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTPPL);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstPpl(dbswdbe, moditems);
};

void PnlWdbeNavHigh::refreshLstSeg(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstSegAvail = evalLstSegAvail(dbswdbe);
	statshr.ButSegViewActive = evalButSegViewActive(dbswdbe);
	statshr.ButSegNewcrdActive = evalButSegNewcrdActive(dbswdbe);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeNavHigh::refreshSeg(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWdbeHistRMUserUniversal rst;
	WdbeHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstSeg = 0;

	// feedFLstSeg
	feedFLstSeg.clear();

	dbswdbe->tblwdbehistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref), VecWdbeVCard::CRDWDBESEG, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstSeg.appendRefTitles(rec->ref, StubWdbe::getStubSegStd(dbswdbe, rec->unvUref, ixWdbeVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTSEG);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstSeg(dbswdbe, moditems);
};

void PnlWdbeNavHigh::refresh(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	// IP refresh --- INSERT

	muteRefresh = false;
};

void PnlWdbeNavHigh::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	refresh(dbswdbe, moditems);

	refreshLstPph(dbswdbe, moditems);
	refreshLstMod(dbswdbe, moditems);
	refreshLstVec(dbswdbe, moditems);
	refreshLstVit(dbswdbe, moditems);
	refreshLstCmd(dbswdbe, moditems);
	refreshLstErr(dbswdbe, moditems);
	refreshLstPpl(dbswdbe, moditems);
	refreshLstSeg(dbswdbe, moditems);
	if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	// IP updatePreset --- END
};

void PnlWdbeNavHigh::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVHIGHDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswdbe, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVHIGHDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTPPHVIEWCLICK) {
					handleDpchAppDoButPphViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPPHNEWCRDCLICK) {
					handleDpchAppDoButPphNewcrdClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTMODVIEWCLICK) {
					handleDpchAppDoButModViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTMODNEWCRDCLICK) {
					handleDpchAppDoButModNewcrdClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTVECVIEWCLICK) {
					handleDpchAppDoButVecViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTVECNEWCRDCLICK) {
					handleDpchAppDoButVecNewcrdClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTVITVIEWCLICK) {
					handleDpchAppDoButVitViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCMDVIEWCLICK) {
					handleDpchAppDoButCmdViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCMDNEWCRDCLICK) {
					handleDpchAppDoButCmdNewcrdClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTERRVIEWCLICK) {
					handleDpchAppDoButErrViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTERRNEWCRDCLICK) {
					handleDpchAppDoButErrNewcrdClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPPLVIEWCLICK) {
					handleDpchAppDoButPplViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPPLNEWCRDCLICK) {
					handleDpchAppDoButPplNewcrdClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSEGVIEWCLICK) {
					handleDpchAppDoButSegViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSEGNEWCRDCLICK) {
					handleDpchAppDoButSegNewcrdClick(dbswdbe, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWdbeNavHigh::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWdbeNavHigh::handleDpchAppDataContiac(
			DbsWdbe* dbswdbe
			, ContIac* _contiac
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFLSTPPH)) {
		contiac.numFLstPph = _contiac->numFLstPph;
		refreshLstPph(dbswdbe, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTMOD)) {
		contiac.numFLstMod = _contiac->numFLstMod;
		refreshLstMod(dbswdbe, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTVEC)) {
		contiac.numFLstVec = _contiac->numFLstVec;
		refreshLstVec(dbswdbe, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTVIT)) {
		contiac.numFLstVit = _contiac->numFLstVit;
		refreshLstVit(dbswdbe, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTCMD)) {
		contiac.numFLstCmd = _contiac->numFLstCmd;
		refreshLstCmd(dbswdbe, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTERR)) {
		contiac.numFLstErr = _contiac->numFLstErr;
		refreshLstErr(dbswdbe, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTPPL)) {
		contiac.numFLstPpl = _contiac->numFLstPpl;
		refreshLstPpl(dbswdbe, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTSEG)) {
		contiac.numFLstSeg = _contiac->numFLstSeg;
		refreshLstSeg(dbswdbe, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWdbeNavHigh::handleDpchAppDoButPphViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	WdbeHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstPphAvail && statshr.ButPphViewActive) {
		if (dbswdbe->tblwdbehistrmuseruniversal->loadRecByRef(feedFLstPph.getRefByNum(contiac.numFLstPph), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, husrRunv->ixWdbeVPreset, husrRunv->preUref, "CrdWdbePph", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbePph");
	};
};

void PnlWdbeNavHigh::handleDpchAppDoButPphNewcrdClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButPphNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbePph", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbePph");
	};
};

void PnlWdbeNavHigh::handleDpchAppDoButModViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	WdbeHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstModAvail && statshr.ButModViewActive) {
		if (dbswdbe->tblwdbehistrmuseruniversal->loadRecByRef(feedFLstMod.getRefByNum(contiac.numFLstMod), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, husrRunv->ixWdbeVPreset, husrRunv->preUref, "CrdWdbeMod", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeMod");
	};
};

void PnlWdbeNavHigh::handleDpchAppDoButModNewcrdClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButModNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbeMod", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeMod");
	};
};

void PnlWdbeNavHigh::handleDpchAppDoButVecViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	WdbeHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstVecAvail && statshr.ButVecViewActive) {
		if (dbswdbe->tblwdbehistrmuseruniversal->loadRecByRef(feedFLstVec.getRefByNum(contiac.numFLstVec), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, husrRunv->ixWdbeVPreset, husrRunv->preUref, "CrdWdbeVec", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeVec");
	};
};

void PnlWdbeNavHigh::handleDpchAppDoButVecNewcrdClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButVecNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbeVec", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeVec");
	};
};

void PnlWdbeNavHigh::handleDpchAppDoButVitViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	WdbeHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstVitAvail && statshr.ButVitViewActive) {
		if (dbswdbe->tblwdbehistrmuseruniversal->loadRecByRef(feedFLstVit.getRefByNum(contiac.numFLstVit), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, husrRunv->ixWdbeVPreset, husrRunv->preUref, "CrdWdbeVit", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeVit");
	};
};

void PnlWdbeNavHigh::handleDpchAppDoButCmdViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	WdbeHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstCmdAvail && statshr.ButCmdViewActive) {
		if (dbswdbe->tblwdbehistrmuseruniversal->loadRecByRef(feedFLstCmd.getRefByNum(contiac.numFLstCmd), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, husrRunv->ixWdbeVPreset, husrRunv->preUref, "CrdWdbeCmd", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeCmd");
	};
};

void PnlWdbeNavHigh::handleDpchAppDoButCmdNewcrdClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButCmdNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbeCmd", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeCmd");
	};
};

void PnlWdbeNavHigh::handleDpchAppDoButErrViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	WdbeHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstErrAvail && statshr.ButErrViewActive) {
		if (dbswdbe->tblwdbehistrmuseruniversal->loadRecByRef(feedFLstErr.getRefByNum(contiac.numFLstErr), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, husrRunv->ixWdbeVPreset, husrRunv->preUref, "CrdWdbeErr", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeErr");
	};
};

void PnlWdbeNavHigh::handleDpchAppDoButErrNewcrdClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButErrNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbeErr", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeErr");
	};
};

void PnlWdbeNavHigh::handleDpchAppDoButPplViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	WdbeHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstPplAvail && statshr.ButPplViewActive) {
		if (dbswdbe->tblwdbehistrmuseruniversal->loadRecByRef(feedFLstPpl.getRefByNum(contiac.numFLstPpl), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, husrRunv->ixWdbeVPreset, husrRunv->preUref, "CrdWdbePpl", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbePpl");
	};
};

void PnlWdbeNavHigh::handleDpchAppDoButPplNewcrdClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButPplNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbePpl", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbePpl");
	};
};

void PnlWdbeNavHigh::handleDpchAppDoButSegViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	WdbeHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstSegAvail && statshr.ButSegViewActive) {
		if (dbswdbe->tblwdbehistrmuseruniversal->loadRecByRef(feedFLstSeg.getRefByNum(contiac.numFLstSeg), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, husrRunv->ixWdbeVPreset, husrRunv->preUref, "CrdWdbeSeg", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeSeg");
	};
};

void PnlWdbeNavHigh::handleDpchAppDoButSegNewcrdClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButSegNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbeSeg", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeSeg");
	};
};

void PnlWdbeNavHigh::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBEHUSRRUNVMOD_CRDUSREQ) {
		call->abort = handleCallWdbeHusrRunvMod_crdUsrEq(dbswdbe, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool PnlWdbeNavHigh::handleCallWdbeHusrRunvMod_crdUsrEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecWdbeVCard::CRDWDBEPPH) {
		refreshPph(dbswdbe, moditems);
	} else if (ixInv == VecWdbeVCard::CRDWDBEMOD) {
		refreshMod(dbswdbe, moditems);
	} else if (ixInv == VecWdbeVCard::CRDWDBEVEC) {
		refreshVec(dbswdbe, moditems);
	} else if (ixInv == VecWdbeVCard::CRDWDBEVIT) {
		refreshVit(dbswdbe, moditems);
	} else if (ixInv == VecWdbeVCard::CRDWDBECMD) {
		refreshCmd(dbswdbe, moditems);
	} else if (ixInv == VecWdbeVCard::CRDWDBEERR) {
		refreshErr(dbswdbe, moditems);
	} else if (ixInv == VecWdbeVCard::CRDWDBEPPL) {
		refreshPpl(dbswdbe, moditems);
	} else if (ixInv == VecWdbeVCard::CRDWDBESEG) {
		refreshSeg(dbswdbe, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};
