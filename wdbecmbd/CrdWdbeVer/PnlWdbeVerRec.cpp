/**
	* \file PnlWdbeVerRec.cpp
	* job handler for job PnlWdbeVerRec (implementation)
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

#include "PnlWdbeVerRec.h"

#include "PnlWdbeVerRec_blks.cpp"
#include "PnlWdbeVerRec_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWdbeVerRec
 ******************************************************************************/

PnlWdbeVerRec::PnlWdbeVerRec(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::PNLWDBEVERREC, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	pnlref1nfile = NULL;
	pnlmnlibrary = NULL;
	pnl1nunit = NULL;
	pnl1nsystem = NULL;
	pnl1nrelease = NULL;
	pnlbvr1nversion = NULL;
	pnldetail = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWdbeVCall::CALLWDBEVER_STEEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEVER_PRJEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEVER_BVREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswdbe, VecWdbeVPreset::PREWDBEREFVER, jref);
};

PnlWdbeVerRec::~PnlWdbeVerRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* PnlWdbeVerRec::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &continf, &statshr, items);
	};

	return dpcheng;
};

void PnlWdbeVerRec::refresh(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubWdbe::getStubVerStd(dbswdbe, recVer.ref, ixWdbeVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recVer.ref == 0) statshr.ixWdbeVExpstate = VecWdbeVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbswdbe);

	if (statshr.ixWdbeVExpstate == VecWdbeVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlbvr1nversion) {delete pnlbvr1nversion; pnlbvr1nversion = NULL;};
		if (pnl1nrelease) {delete pnl1nrelease; pnl1nrelease = NULL;};
		if (pnl1nsystem) {delete pnl1nsystem; pnl1nsystem = NULL;};
		if (pnl1nunit) {delete pnl1nunit; pnl1nunit = NULL;};
		if (pnlref1nfile) {delete pnlref1nfile; pnlref1nfile = NULL;};
		if (pnlmnlibrary) {delete pnlmnlibrary; pnlmnlibrary = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlWdbeVerDetail(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlbvr1nversion) pnlbvr1nversion = new PnlWdbeVerBvr1NVersion(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnl1nrelease) pnl1nrelease = new PnlWdbeVer1NRelease(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnl1nsystem) pnl1nsystem = new PnlWdbeVer1NSystem(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnl1nunit) pnl1nunit = new PnlWdbeVer1NUnit(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlref1nfile) pnlref1nfile = new PnlWdbeVerRef1NFile(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlmnlibrary) pnlmnlibrary = new PnlWdbeVerMNLibrary(xchg, dbswdbe, jref, ixWdbeVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefBvr1NVersion = ((pnlbvr1nversion) ? pnlbvr1nversion->jref : 0);
	statshr.jref1NRelease = ((pnl1nrelease) ? pnl1nrelease->jref : 0);
	statshr.jref1NSystem = ((pnl1nsystem) ? pnl1nsystem->jref : 0);
	statshr.jref1NUnit = ((pnl1nunit) ? pnl1nunit->jref : 0);
	statshr.jrefRef1NFile = ((pnlref1nfile) ? pnlref1nfile->jref : 0);
	statshr.jrefMNLibrary = ((pnlmnlibrary) ? pnlmnlibrary->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWdbeVerRec::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFVER) {
		WdbeMVersion* _recVer = NULL;

		if (dbswdbe->tblwdbemversion->loadRecByRef(xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref), &_recVer)) {
			recVer = *_recVer;
			delete _recVer;
		} else recVer = WdbeMVersion();

		if (recVer.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlbvr1nversion) pnlbvr1nversion->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnl1nrelease) pnl1nrelease->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnl1nsystem) pnl1nsystem->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnl1nunit) pnl1nunit->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlref1nfile) pnlref1nfile->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlmnlibrary) pnlmnlibrary->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
		};

		refresh(dbswdbe, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWdbeVerRec::minimize(
			DbsWdbe* dbswdbe
			, const bool notif
			, DpchEngWdbe** dpcheng
		) {
	set<uint> moditems;

	if (statshr.ixWdbeVExpstate != VecWdbeVExpstate::MIND) {
		statshr.ixWdbeVExpstate = VecWdbeVExpstate::MIND;
		insert(moditems, DpchEngData::STATSHR);

		refresh(dbswdbe, moditems);
	};

	if (notif) {
		if (dpcheng) *dpcheng = getNewDpchEng(moditems);
		else if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
};

void PnlWdbeVerRec::regularize(
			DbsWdbe* dbswdbe
			, const bool notif
			, DpchEngWdbe** dpcheng
		) {
	set<uint> moditems;

	if (statshr.ixWdbeVExpstate != VecWdbeVExpstate::REGD) {
		statshr.ixWdbeVExpstate = VecWdbeVExpstate::REGD;
		insert(moditems, DpchEngData::STATSHR);

		refresh(dbswdbe, moditems);
	};

	if (notif) {
		if (dpcheng) *dpcheng = getNewDpchEng(moditems);
		else if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
};

void PnlWdbeVerRec::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEVERRECDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTMINIMIZECLICK) {
					handleDpchAppDoButMinimizeClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREGULARIZECLICK) {
					handleDpchAppDoButRegularizeClick(dbswdbe, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWdbeVerRec::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWdbeVerRec::handleDpchAppDoButMinimizeClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	minimize(dbswdbe, true, dpcheng);
};

void PnlWdbeVerRec::handleDpchAppDoButRegularizeClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	regularize(dbswdbe, true, dpcheng);
};

void PnlWdbeVerRec::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBEVERUPD_REFEQ) {
		call->abort = handleCallWdbeVerUpd_refEq(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEVER_STEEQ) {
		call->abort = handleCallWdbeVer_steEq(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEVER_PRJEQ) {
		call->abort = handleCallWdbeVer_prjEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEVER_BVREQ) {
		call->abort = handleCallWdbeVer_bvrEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWdbeVerRec::handleCallWdbeVerUpd_refEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWdbeVerUpd_refEq --- INSERT
	return retval;
};

bool PnlWdbeVerRec::handleCallWdbeVer_steEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recVer.ixVState == ixInv); // IP handleCallWdbeVer_steEq --- LINE
	return retval;
};

bool PnlWdbeVerRec::handleCallWdbeVer_prjEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recVer.refWdbeMProject == refInv); // IP handleCallWdbeVer_prjEq --- LINE
	return retval;
};

bool PnlWdbeVerRec::handleCallWdbeVer_bvrEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recVer.bvrRefWdbeMVersion == refInv); // IP handleCallWdbeVer_bvrEq --- LINE
	return retval;
};
