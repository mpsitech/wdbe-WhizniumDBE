/**
	* \file PnlWdbeSil1NTarget.cpp
	* job handler for job PnlWdbeSil1NTarget (implementation)
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

#include "PnlWdbeSil1NTarget.h"

#include "PnlWdbeSil1NTarget_blks.cpp"
#include "PnlWdbeSil1NTarget_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWdbeSil1NTarget
 ******************************************************************************/

PnlWdbeSil1NTarget::PnlWdbeSil1NTarget(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::PNLWDBESIL1NTARGET, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFCsiQst.tag = "FeedFCsiQst";
	feedFCsiQst.appendIxSrefTitles(VecWdbeVQrystate::MNR, "ong", VecWdbeVQrystate::getTitle(VecWdbeVQrystate::MNR, ixWdbeVLocale));
	feedFCsiQst.appendIxSrefTitles(VecWdbeVQrystate::OOD, "red", VecWdbeVQrystate::getTitle(VecWdbeVQrystate::OOD, ixWdbeVLocale));
	feedFCsiQst.appendIxSrefTitles(VecWdbeVQrystate::SLM, "yel", VecWdbeVQrystate::getTitle(VecWdbeVQrystate::SLM, ixWdbeVLocale));
	feedFCsiQst.appendIxSrefTitles(VecWdbeVQrystate::UTD, "grn", VecWdbeVQrystate::getTitle(VecWdbeVQrystate::UTD, ixWdbeVLocale));

	qry = NULL;

	// IP constructor.cust1 --- INSERT

	xchg->addRefPreset(VecWdbeVPreset::PREWDBEREFSEL, jref, 0);

	qry = new QryWdbeSil1NTarget(xchg, dbswdbe, jref, ixWdbeVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswdbe, moditems);

	xchg->addClstn(VecWdbeVCall::CALLWDBESTATCHG, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

};

PnlWdbeSil1NTarget::~PnlWdbeSil1NTarget() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* PnlWdbeSil1NTarget::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &continf, &feedFCsiQst, &statshr, &stgiac, &(qry->rst), &(qry->statshr), &(qry->stgiac), items);
	};

	return dpcheng;
};

void PnlWdbeSil1NTarget::refresh(
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
	continf.numFCsiQst = feedFCsiQst.getNumByIx(qry->ixWdbeVQrystate);

	// statshr
	statshr.ButViewAvail = evalButViewAvail(dbswdbe);
	statshr.ButViewActive = evalButViewActive(dbswdbe);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWdbeSil1NTarget::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFSIL) {
		recTrg = WdbeMTarget();

		xchg->addRefPreset(VecWdbeVPreset::PREWDBEREFSEL, jref, 0);

		qry->stgiac.jnumFirstload = 1;

		qry->rerun(dbswdbe);
		refresh(dbswdbe, moditems);

		if (notif) {
			insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::STGIACQRY, DpchEngData::RST});
			xchg->submitDpch(getNewDpchEng(moditems));
		};
	};
	// IP updatePreset --- END
};

void PnlWdbeSil1NTarget::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESIL1NTARGETDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::STGIAC)) {
				handleDpchAppDataStgiac(dbswdbe, &(dpchappdata->stgiac), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::STGIACQRY)) {
				handleDpchAppDataStgiacqry(dbswdbe, &(dpchappdata->stgiacqry), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESIL1NTARGETDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTVIEWCLICK) {
					handleDpchAppDoButViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREFRESHCLICK) {
					handleDpchAppDoButRefreshClick(dbswdbe, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWdbeSil1NTarget::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWdbeSil1NTarget::handleDpchAppDataStgiac(
			DbsWdbe* dbswdbe
			, StgIac* _stgiac
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _stgiac->diff(&stgiac);
	// IP handleDpchAppDataStgiac --- INSERT
	insert(moditems, DpchEngData::STGIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWdbeSil1NTarget::handleDpchAppDataStgiacqry(
			DbsWdbe* dbswdbe
			, QryWdbeSil1NTarget::StgIac* _stgiacqry
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _stgiacqry->diff(&(qry->stgiac));

	WdbeQSil1NTarget* recSelNew = NULL;

	WdbeMTarget* _recTrg = NULL;

	if (!diffitems.empty()) {
		muteRefresh = true;

		qry->stgiac = *_stgiacqry;

		if (has(diffitems, QryWdbeSil1NTarget::StgIac::JNUM)) recSelNew = qry->getRecByJnum(_stgiacqry->jnum);

		if (!has(diffitems, QryWdbeSil1NTarget::StgIac::JNUM) || (diffitems.size() > 1)) {
			qry->rerun(dbswdbe);
			insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::RST});
		};

		if (has(diffitems, QryWdbeSil1NTarget::StgIac::JNUM)) {
			if (!recSelNew) recSelNew = qry->getRecByJnum(_stgiacqry->jnum);

			recTrg = WdbeMTarget();

			if (recSelNew) {
				if (dbswdbe->tblwdbemtarget->loadRecByRef(recSelNew->ref, &_recTrg)) {
					recTrg = *_recTrg;
					delete _recTrg;
				};
			};

			xchg->addRefPreset(VecWdbeVPreset::PREWDBEREFSEL, jref, ((recSelNew) ? recSelNew->ref : 0));
			qry->refreshJnum();
		};

		refresh(dbswdbe, moditems, true);
	};

	insert(moditems, DpchEngData::STGIACQRY);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWdbeSil1NTarget::handleDpchAppDoButViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	ubigint refVer = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref);

	if (statshr.ButViewAvail && statshr.ButViewActive) {
		if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCTRG, jref)) if (refVer != 0) {
			sref = "CrdWdbeTrg";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, VecWdbeVPreset::PREWDBEREFVER, refVer, sref, recTrg.ref, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, sref);
	};
};

void PnlWdbeSil1NTarget::handleDpchAppDoButRefreshClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	set<uint> moditems;

	muteRefresh = true;

	qry->rerun(dbswdbe, false);

	refresh(dbswdbe, moditems, true);

	insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::STGIACQRY, DpchEngData::RST});
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWdbeSil1NTarget::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBESTATCHG) {
		call->abort = handleCallWdbeStatChg(dbswdbe, call->jref);
	};
};

bool PnlWdbeSil1NTarget::handleCallWdbeStatChg(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWdbeStatChg --- BEGIN

	set<uint> moditems;

	if (jrefTrig == qry->jref) {
		if (!muteRefresh) {
			refresh(dbswdbe, moditems);
			if (qry->ixWdbeVQrystate == VecWdbeVQrystate::UTD) insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::STGIACQRY, DpchEngData::RST});
			if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
		};
	};

	// IP handleCallWdbeStatChg --- END
	return retval;
};
