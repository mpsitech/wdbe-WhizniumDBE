/**
	* \file PnlWdbeBnk1NPin.cpp
	* job handler for job PnlWdbeBnk1NPin (implementation)
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

#include "PnlWdbeBnk1NPin.h"

#include "PnlWdbeBnk1NPin_blks.cpp"
#include "PnlWdbeBnk1NPin_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWdbeBnk1NPin
 ******************************************************************************/

PnlWdbeBnk1NPin::PnlWdbeBnk1NPin(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::PNLWDBEBNK1NPIN, jrefSup, ixWdbeVLocale)
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

	qry = new QryWdbeBnk1NPin(xchg, dbswdbe, jref, ixWdbeVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswdbe, moditems);

	xchg->addClstn(VecWdbeVCall::CALLWDBESTATCHG, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

};

PnlWdbeBnk1NPin::~PnlWdbeBnk1NPin() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* PnlWdbeBnk1NPin::getNewDpchEng(
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

void PnlWdbeBnk1NPin::refresh(
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
	statshr.ButNewAvail = evalButNewAvail(dbswdbe);
	statshr.ButDeleteAvail = evalButDeleteAvail(dbswdbe);
	statshr.ButDeleteActive = evalButDeleteActive(dbswdbe);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWdbeBnk1NPin::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFBNK) {
		recPin = WdbeMPin();

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

void PnlWdbeBnk1NPin::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEBNK1NPINDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::STGIAC)) {
				handleDpchAppDataStgiac(dbswdbe, &(dpchappdata->stgiac), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::STGIACQRY)) {
				handleDpchAppDataStgiacqry(dbswdbe, &(dpchappdata->stgiacqry), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEBNK1NPINDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTVIEWCLICK) {
					handleDpchAppDoButViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTNEWCLICK) {
					handleDpchAppDoButNewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDELETECLICK) {
					handleDpchAppDoButDeleteClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREFRESHCLICK) {
					handleDpchAppDoButRefreshClick(dbswdbe, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWdbeBnk1NPin::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWdbeBnk1NPin::handleDpchAppDataStgiac(
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

void PnlWdbeBnk1NPin::handleDpchAppDataStgiacqry(
			DbsWdbe* dbswdbe
			, QryWdbeBnk1NPin::StgIac* _stgiacqry
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _stgiacqry->diff(&(qry->stgiac));

	WdbeQBnk1NPin* recSelNew = NULL;

	WdbeMPin* _recPin = NULL;

	if (!diffitems.empty()) {
		muteRefresh = true;

		qry->stgiac = *_stgiacqry;

		if (has(diffitems, QryWdbeBnk1NPin::StgIac::JNUM)) recSelNew = qry->getRecByJnum(_stgiacqry->jnum);

		if (!has(diffitems, QryWdbeBnk1NPin::StgIac::JNUM) || (diffitems.size() > 1)) {
			qry->rerun(dbswdbe);
			insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::RST});
		};

		if (has(diffitems, QryWdbeBnk1NPin::StgIac::JNUM)) {
			if (!recSelNew) recSelNew = qry->getRecByJnum(_stgiacqry->jnum);

			recPin = WdbeMPin();

			if (recSelNew) {
				if (dbswdbe->tblwdbempin->loadRecByRef(recSelNew->ref, &_recPin)) {
					recPin = *_recPin;
					delete _recPin;
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

void PnlWdbeBnk1NPin::handleDpchAppDoButViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	ubigint refBnk = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFBNK, jref);

	if (statshr.ButViewAvail && statshr.ButViewActive) {
		if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPIN, jref)) if (refBnk != 0) {
			sref = "CrdWdbePin";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, VecWdbeVPreset::PREWDBEREFBNK, refBnk, sref, recPin.ref, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, sref);
	};
};

void PnlWdbeBnk1NPin::handleDpchAppDoButNewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	ubigint refBnk = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFBNK, jref);

	if (statshr.ButNewAvail) {
		if ((xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPIN, jref) & VecWdbeWAccess::EDIT) != 0) if (refBnk != 0) {
			sref = "CrdWdbePin";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, VecWdbeVPreset::PREWDBEREFBNK, refBnk, sref, -1, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, sref);
	};
};

void PnlWdbeBnk1NPin::handleDpchAppDoButDeleteClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButDeleteClick --- INSERT
};

void PnlWdbeBnk1NPin::handleDpchAppDoButRefreshClick(
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

void PnlWdbeBnk1NPin::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBESTATCHG) {
		call->abort = handleCallWdbeStatChg(dbswdbe, call->jref);
	};
};

bool PnlWdbeBnk1NPin::handleCallWdbeStatChg(
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
