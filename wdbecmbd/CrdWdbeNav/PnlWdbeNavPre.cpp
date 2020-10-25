/**
	* \file PnlWdbeNavPre.cpp
	* job handler for job PnlWdbeNavPre (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbed.h>
#endif

#include "PnlWdbeNavPre.h"

#include "PnlWdbeNavPre_blks.cpp"
#include "PnlWdbeNavPre_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWdbeNavPre
 ******************************************************************************/

PnlWdbeNavPre::PnlWdbeNavPre(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::PNLWDBENAVPRE, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswdbe, moditems);

	// IP constructor.cust3 --- INSERT

};

PnlWdbeNavPre::~PnlWdbeNavPre() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* PnlWdbeNavPre::getNewDpchEng(
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

void PnlWdbeNavPre::refresh(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.TxtCvr = StubWdbe::getStubCvrStd(dbswdbe, xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCVR, jref), ixWdbeVLocale);
	continf.TxtUnt = StubWdbe::getStubUntStd(dbswdbe, xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref), ixWdbeVLocale);
	continf.TxtVer = StubWdbe::getStubVerStd(dbswdbe, xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref), ixWdbeVLocale);

	// statshr
	statshr.TxtCvrAvail = evalTxtCvrAvail(dbswdbe);
	statshr.TxtUntAvail = evalTxtUntAvail(dbswdbe);
	statshr.TxtVerAvail = evalTxtVerAvail(dbswdbe);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeNavPre::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	refresh(dbswdbe, moditems);

	if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	// IP updatePreset --- END
};

void PnlWdbeNavPre::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVPREDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTCVRREMOVECLICK) {
					handleDpchAppDoButCvrRemoveClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTUNTREMOVECLICK) {
					handleDpchAppDoButUntRemoveClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTVERREMOVECLICK) {
					handleDpchAppDoButVerRemoveClick(dbswdbe, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWdbeNavPre::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWdbeNavPre::handleDpchAppDoButCvrRemoveClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	set<uint> moditems;

	xchg->triggerIxRefCall(dbswdbe, VecWdbeVCall::CALLWDBEREFPRESET, jref, VecWdbeVPreset::PREWDBEREFCVR, 0);

	refresh(dbswdbe, moditems);

	*dpcheng = getNewDpchEng(moditems);
};

void PnlWdbeNavPre::handleDpchAppDoButUntRemoveClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	set<uint> moditems;

	xchg->triggerIxRefCall(dbswdbe, VecWdbeVCall::CALLWDBEREFPRESET, jref, VecWdbeVPreset::PREWDBEREFUNT, 0);

	refresh(dbswdbe, moditems);

	*dpcheng = getNewDpchEng(moditems);
};

void PnlWdbeNavPre::handleDpchAppDoButVerRemoveClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	set<uint> moditems;

	xchg->triggerIxRefCall(dbswdbe, VecWdbeVCall::CALLWDBEREFPRESET, jref, VecWdbeVPreset::PREWDBEREFVER, 0);

	refresh(dbswdbe, moditems);

	*dpcheng = getNewDpchEng(moditems);
};

