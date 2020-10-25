/**
	* \file PnlWdbeMchAPar.cpp
	* job handler for job PnlWdbeMchAPar (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbed.h>
#endif

#include "PnlWdbeMchAPar.h"

#include "PnlWdbeMchAPar_blks.cpp"
#include "PnlWdbeMchAPar_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWdbeMchAPar
 ******************************************************************************/

PnlWdbeMchAPar::PnlWdbeMchAPar(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::PNLWDBEMCHAPAR, jrefSup, ixWdbeVLocale)
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

	qry = new QryWdbeMchAPar(xchg, dbswdbe, jref, ixWdbeVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswdbe, moditems);

	xchg->addClstn(VecWdbeVCall::CALLWDBESTATCHG, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

};

PnlWdbeMchAPar::~PnlWdbeMchAPar() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* PnlWdbeMchAPar::getNewDpchEng(
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

void PnlWdbeMchAPar::refresh(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.numFCsiQst = feedFCsiQst.getNumByIx(qry->ixWdbeVQrystate);

	// statshr
	statshr.ButNewAvail = evalButNewAvail(dbswdbe);
	statshr.ButDuplicateAvail = evalButDuplicateAvail(dbswdbe);
	statshr.ButDuplicateActive = evalButDuplicateActive(dbswdbe);
	statshr.ButDeleteAvail = evalButDeleteAvail(dbswdbe);
	statshr.ButDeleteActive = evalButDeleteActive(dbswdbe);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeMchAPar::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFMCH) {
		recMchApar = WdbeAMMachinePar();

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

void PnlWdbeMchAPar::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMCHAPARDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::STGIAC)) {
				handleDpchAppDataStgiac(dbswdbe, &(dpchappdata->stgiac), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::STGIACQRY)) {
				handleDpchAppDataStgiacqry(dbswdbe, &(dpchappdata->stgiacqry), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMCHAPARDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTNEWCLICK) {
					handleDpchAppDoButNewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDUPLICATECLICK) {
					handleDpchAppDoButDuplicateClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDELETECLICK) {
					handleDpchAppDoButDeleteClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREFRESHCLICK) {
					handleDpchAppDoButRefreshClick(dbswdbe, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWdbeMchAPar::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWdbeMchAPar::handleDpchAppDataStgiac(
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

void PnlWdbeMchAPar::handleDpchAppDataStgiacqry(
			DbsWdbe* dbswdbe
			, QryWdbeMchAPar::StgIac* _stgiacqry
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _stgiacqry->diff(&(qry->stgiac));

	WdbeQMchAPar* recSelNew = NULL;

	WdbeAMMachinePar* _recMchApar = NULL;

	muteRefresh = true;

	if (!diffitems.empty()) {
		qry->stgiac = *_stgiacqry;

		if (has(diffitems, QryWdbeMchAPar::StgIac::JNUM)) recSelNew = qry->getRecByJnum(_stgiacqry->jnum);

		if (!has(diffitems, QryWdbeMchAPar::StgIac::JNUM) || (diffitems.size() > 1)) {
			qry->rerun(dbswdbe);
			insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::RST});
		};

		if (has(diffitems, QryWdbeMchAPar::StgIac::JNUM)) {
			if (!recSelNew) recSelNew = qry->getRecByJnum(_stgiacqry->jnum);

			recMchApar = WdbeAMMachinePar();

			if (recSelNew) {
				if (dbswdbe->tblwdbeammachinepar->loadRecByRef(recSelNew->ref, &_recMchApar)) {
					recMchApar = *_recMchApar;
					delete _recMchApar;
				};
			};

			xchg->addRefPreset(VecWdbeVPreset::PREWDBEREFSEL, jref, ((recSelNew) ? recSelNew->ref : 0));
			qry->refreshJnum();
		};

		refresh(dbswdbe, moditems);
	};

	muteRefresh = false;

	insert(moditems, DpchEngData::STGIACQRY);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWdbeMchAPar::handleDpchAppDoButNewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButNewClick --- INSERT
};

void PnlWdbeMchAPar::handleDpchAppDoButDuplicateClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButDuplicateClick --- INSERT
};

void PnlWdbeMchAPar::handleDpchAppDoButDeleteClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButDeleteClick --- INSERT
};

void PnlWdbeMchAPar::handleDpchAppDoButRefreshClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	set<uint> moditems;

	muteRefresh = true;

	qry->rerun(dbswdbe, false);
	refresh(dbswdbe, moditems);

	muteRefresh = false;

	insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::STGIACQRY, DpchEngData::RST});
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWdbeMchAPar::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBESTATCHG) {
		call->abort = handleCallWdbeStatChg(dbswdbe, call->jref);
	};
};

bool PnlWdbeMchAPar::handleCallWdbeStatChg(
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

