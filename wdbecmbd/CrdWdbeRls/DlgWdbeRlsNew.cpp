/**
	* \file DlgWdbeRlsNew.cpp
	* job handler for job DlgWdbeRlsNew (implementation)
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

#include "DlgWdbeRlsNew.h"

#include "DlgWdbeRlsNew_blks.cpp"
#include "DlgWdbeRlsNew_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWdbeRlsNew
 ******************************************************************************/

DlgWdbeRlsNew::DlgWdbeRlsNew(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::DLGWDBERLSNEW, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFDetPupMch.tag = "FeedFDetPupMch";
	feedFDetPupTyp.tag = "FeedFDetPupTyp";
	VecWdbeVMReleaseBasetype::fillFeed(ixWdbeVLocale, feedFDetPupTyp);
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	// IP constructor.cust1 --- IBEGIN
	ListWdbeMMachine mchs;
	WdbeMMachine* mch = NULL;

	dbswdbe->tblwdbemmachine->loadRstBySQL("SELECT * FROM TblWdbeMMachine ORDER BY sref ASC", false, mchs);
	for (unsigned int i = 0; i < mchs.nodes.size(); i++) {
		mch = mchs.nodes[i];
		feedFDetPupMch.appendRefTitles(mch->ref, mch->sref);
	};
	// IP constructor.cust1 --- IEND

	valid = false;

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswdbe, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgWdbeRlsNew::~DlgWdbeRlsNew() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* DlgWdbeRlsNew::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFDetPupMch, &feedFDetPupTyp, &feedFSge, &statshr, items);
	};

	return dpcheng;
};

void DlgWdbeRlsNew::refresh(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	StatShr oldStatshr(statshr);
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);

	// IP refresh --- BEGIN
	// statshr
	statshr.ButCncActive = evalButCncActive(dbswdbe);
	statshr.ButCreActive = evalButCreActive(dbswdbe);

	// contiac

	// continf
	continf.numFSge = ixVSge;

	// IP refresh --- END
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	muteRefresh = false;
};

void DlgWdbeRlsNew::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBERLSNEWDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswdbe, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBERLSNEWDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTCNCCLICK) {
					handleDpchAppDoButCncClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCRECLICK) {
					handleDpchAppDoButCreClick(dbswdbe, &(req->dpcheng));
				};

			};

		};
	};
};

void DlgWdbeRlsNew::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWdbeRlsNew::handleDpchAppDataContiac(
			DbsWdbe* dbswdbe
			, ContIac* _contiac
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);
	// IP handleDpchAppDataContiac --- IBEGIN

	ubigint ref;

	if (has(diffitems, ContIac::NUMFDETPUPTYP)) {
		if (feedFDetPupTyp.getIxByNum(_contiac->numFDetPupTyp) != 0) contiac.numFDetPupTyp = _contiac->numFDetPupTyp;
		else contiac.numFDetPupTyp = 0;
	};

	if (has(diffitems, ContIac::NUMFDETPUPMCH)) {
		if (feedFDetPupMch.getRefByNum(_contiac->numFDetPupMch) != 0) contiac.numFDetPupMch = _contiac->numFDetPupMch;
		else contiac.numFDetPupMch = 0;
	};

	if (has(diffitems, ContIac::DETTXFSRF)) {
		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMRelease WHERE refWdbeMVersion = " + to_string(xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref)) + " AND sref = '" + _contiac->DetTxfSrf + "'", ref)) contiac.DetTxfSrf = "";
		else contiac.DetTxfSrf = _contiac->DetTxfSrf;
	};

	valid = ((contiac.numFDetPupTyp > 0) && (contiac.numFDetPupMch > 0) && (contiac.DetTxfSrf != ""));

	refresh(dbswdbe, moditems);

	// IP handleDpchAppDataContiac --- IEND
	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgWdbeRlsNew::handleDpchAppDoButCncClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButCncClick --- IBEGIN
	if (statshr.ButCncActive) {
		*dpcheng = new DpchEngWdbeConfirm(true, jref, "");
		xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBEDLGCLOSE, jref);
	};
	// IP handleDpchAppDoButCncClick --- IEND
};

void DlgWdbeRlsNew::handleDpchAppDoButCreClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButCreClick --- RBEGIN
	if (statshr.ButCreActive) {
		if (ixVSge == VecVSge::IDLE) {
			changeStage(dbswdbe, VecVSge::CREATE, dpcheng);
		};

		if (ixVSge == VecVSge::DONE) {
			if (!*dpcheng) *dpcheng = new DpchEngWdbeConfirm(true, jref, "");
			xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBEDLGCLOSE, jref);
		};
	};
	// IP handleDpchAppDoButCreClick --- REND
};

void DlgWdbeRlsNew::changeStage(
			DbsWdbe* dbswdbe
			, uint _ixVSge
			, DpchEngWdbe** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswdbe); break;
				case VecVSge::CREATE: leaveSgeCreate(dbswdbe); break;
				case VecVSge::DONE: leaveSgeDone(dbswdbe); break;
			};

			setStage(dbswdbe, _ixVSge);
			reenter = false;
			refreshWithDpchEng(dbswdbe, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswdbe, reenter); break;
			case VecVSge::CREATE: _ixVSge = enterSgeCreate(dbswdbe, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswdbe, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWdbeRlsNew::getSquawk(
			DbsWdbe* dbswdbe
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

uint DlgWdbeRlsNew::enterSgeIdle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWdbeRlsNew::leaveSgeIdle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWdbeRlsNew::enterSgeCreate(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IDLE;

	// IP enterSgeCreate --- IBEGIN

	WdbeMRelease rls;

	rls.ixVBasetype = feedFDetPupTyp.getIxByNum(contiac.numFDetPupTyp);
	rls.refWdbeMVersion = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref);
	rls.refWdbeMMachine = feedFDetPupMch.getRefByNum(contiac.numFDetPupMch);
	rls.sref = contiac.DetTxfSrf;
//	rls.Comment = ...;

	dbswdbe->tblwdbemrelease->insertRec(&rls);

	xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBERLSMOD, jref);
	xchg->triggerRefCall(dbswdbe, VecWdbeVCall::CALLWDBERLSMOD_VEREQ, jref, rls.refWdbeMVersion);
	xchg->triggerIxRefCall(dbswdbe, VecWdbeVCall::CALLWDBEREFPRESET, jref, VecWdbeVPreset::PREWDBEREFRLS, rls.ref);

	// IP enterSgeCreate --- IEND

	return retval;
};

void DlgWdbeRlsNew::leaveSgeCreate(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeCreate --- INSERT
};

uint DlgWdbeRlsNew::enterSgeDone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void DlgWdbeRlsNew::leaveSgeDone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeDone --- INSERT
};



