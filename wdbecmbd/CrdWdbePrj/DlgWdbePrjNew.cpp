/**
	* \file DlgWdbePrjNew.cpp
	* job handler for job DlgWdbePrjNew (implementation)
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

#include "DlgWdbePrjNew.h"

#include "DlgWdbePrjNew_blks.cpp"
#include "DlgWdbePrjNew_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWdbePrjNew
 ******************************************************************************/

DlgWdbePrjNew::DlgWdbePrjNew(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::DLGWDBEPRJNEW, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	license = NULL;

	// IP constructor.cust1 --- INSERT

	valid = false;

	license = new JobWdbeLicense(xchg, dbswdbe, jref, ixWdbeVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswdbe, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgWdbePrjNew::~DlgWdbePrjNew() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* DlgWdbePrjNew::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFSge, &statshr, items);
	};

	return dpcheng;
};

void DlgWdbePrjNew::refresh(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	ContInf oldContinf(continf);
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.numFSge = ixVSge;

	// contiac

	// statshr
	statshr.DetButAutActive = evalDetButAutActive(dbswdbe);
	statshr.ButCncActive = evalButCncActive(dbswdbe);
	statshr.ButCreActive = evalButCreActive(dbswdbe);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void DlgWdbePrjNew::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEPRJNEWDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswdbe, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEPRJNEWDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::DETBUTAUTCLICK) {
					handleDpchAppDoDetButAutClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCNCCLICK) {
					handleDpchAppDoButCncClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCRECLICK) {
					handleDpchAppDoButCreClick(dbswdbe, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEALERT) {
			handleDpchAppWdbeAlert(dbswdbe, (DpchAppWdbeAlert*) (req->dpchapp), &(req->dpcheng));

		};
	};
};

void DlgWdbePrjNew::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWdbePrjNew::handleDpchAppDataContiac(
			DbsWdbe* dbswdbe
			, ContIac* _contiac
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);
	// IP handleDpchAppDataContiac --- IBEGIN

	ubigint ref;

	// validate DetTxfSho
	valid = (_contiac->DetTxfSho.length() == 4);
	if (valid) valid = (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMProject WHERE Short = '" + _contiac->DetTxfSho + "'", ref) == false);

	if (valid) contiac.DetTxfSho = _contiac->DetTxfSho;
	else contiac.DetTxfSho = "";

	if (valid) {
		// validate DetTxfTit
		valid = (_contiac->DetTxfTit.length() != 0);

		if (valid) contiac.DetTxfTit = _contiac->DetTxfTit;
		else contiac.DetTxfTit = "";
	};

	refresh(dbswdbe, moditems);

	// IP handleDpchAppDataContiac --- IEND
	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgWdbePrjNew::handleDpchAppDoDetButAutClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoDetButAutClick --- BEGIN
	if (statshr.DetButAutActive) {
		changeStage(dbswdbe, VecVSge::AUTH, dpcheng);
	};
	// IP handleDpchAppDoDetButAutClick --- END
};

void DlgWdbePrjNew::handleDpchAppDoButCncClick(
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

void DlgWdbePrjNew::handleDpchAppDoButCreClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButCreClick --- RBEGIN
	if (statshr.ButCreActive) {
		if (ixVSge == VecVSge::AUTDONE) {
			changeStage(dbswdbe, VecVSge::CREATE, dpcheng);
		};

		if (ixVSge == VecVSge::DONE) {
			if (!*dpcheng) *dpcheng = new DpchEngWdbeConfirm(true, jref, "");
			xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBEDLGCLOSE, jref);
		};
	};
	// IP handleDpchAppDoButCreClick --- REND
};

void DlgWdbePrjNew::handleDpchAppWdbeAlert(
			DbsWdbe* dbswdbe
			, DpchAppWdbeAlert* dpchappwdbealert
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppWdbeAlert --- INSERT
};

void DlgWdbePrjNew::changeStage(
			DbsWdbe* dbswdbe
			, uint _ixVSge
			, DpchEngWdbe** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswdbe); break;
				case VecVSge::ALRAER: leaveSgeAlraer(dbswdbe); break;
				case VecVSge::AUTH: leaveSgeAuth(dbswdbe); break;
				case VecVSge::AUTDONE: leaveSgeAutdone(dbswdbe); break;
				case VecVSge::CREATE: leaveSgeCreate(dbswdbe); break;
				case VecVSge::SYNC: leaveSgeSync(dbswdbe); break;
				case VecVSge::DONE: leaveSgeDone(dbswdbe); break;
			};

			setStage(dbswdbe, _ixVSge);
			reenter = false;
			refreshWithDpchEng(dbswdbe, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswdbe, reenter); break;
			case VecVSge::ALRAER: _ixVSge = enterSgeAlraer(dbswdbe, reenter); break;
			case VecVSge::AUTH: _ixVSge = enterSgeAuth(dbswdbe, reenter); break;
			case VecVSge::AUTDONE: _ixVSge = enterSgeAutdone(dbswdbe, reenter); break;
			case VecVSge::CREATE: _ixVSge = enterSgeCreate(dbswdbe, reenter); break;
			case VecVSge::SYNC: _ixVSge = enterSgeSync(dbswdbe, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswdbe, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWdbePrjNew::getSquawk(
			DbsWdbe* dbswdbe
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::AUTH) || (ixVSge == VecVSge::AUTDONE) || (ixVSge == VecVSge::SYNC) ) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			if (ixVSge == VecVSge::AUTH) retval = "authenticating";
			else if (ixVSge == VecVSge::AUTDONE) retval = "authentication successful";
			else if (ixVSge == VecVSge::SYNC) retval = "synchronizing new project with licensing server";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint DlgWdbePrjNew::enterSgeIdle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWdbePrjNew::leaveSgeIdle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWdbePrjNew::enterSgeAlraer(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::ALRAER;
	nextIxVSgeSuccess = VecVSge::IDLE;

	ContInfWdbeAlert continf;
	// IP enterSgeAlraer --- BEGIN
	continf.TxtCpt = VecWdbeVTag::getTitle(VecWdbeVTag::ERROR, ixWdbeVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		continf.TxtMsg1 = "Authentication failure.";
	};

	feedFMcbAlert.clear();

	VecWdbeVTag::appendToFeed(VecWdbeVTag::OK, ixWdbeVLocale, feedFMcbAlert);
	// IP enterSgeAlraer --- END
	xchg->submitDpch(new DpchEngWdbeAlert(jref, &continf, &feedFMcbAlert, {DpchEngWdbeAlert::ALL}));

	return retval;
};

void DlgWdbePrjNew::leaveSgeAlraer(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAlraer --- INSERT
};

uint DlgWdbePrjNew::enterSgeAuth(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::AUTDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::ALRAER;

	// IP enterSgeAuth --- IBEGIN
	if (!license->authPrjNew()) retval = nextIxVSgeFailure;
	// IP enterSgeAuth --- IEND

	return retval;
};

void DlgWdbePrjNew::leaveSgeAuth(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAuth --- INSERT
};

uint DlgWdbePrjNew::enterSgeAutdone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::AUTDONE;

	// IP enterSgeAutdone --- INSERT

	return retval;
};

void DlgWdbePrjNew::leaveSgeAutdone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAutdone --- INSERT
};

uint DlgWdbePrjNew::enterSgeCreate(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::SYNC;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IDLE;

	// IP enterSgeCreate --- IBEGIN

	WdbeMProject prj;

	prj.grp = xchg->getRefPreset(VecWdbeVPreset::PREWDBEGROUP, jref);
	prj.own = xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref);
	prj.Short = contiac.DetTxfSho;
	prj.Title = contiac.DetTxfTit;

	dbswdbe->tblwdbemproject->insertRec(&prj);

	xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBEPRJMOD, jref);
	xchg->triggerIxRefCall(dbswdbe, VecWdbeVCall::CALLWDBEREFPRESET, jref, VecWdbeVPreset::PREWDBEREFPRJ, prj.ref);

	// IP enterSgeCreate --- IEND

	return retval;
};

void DlgWdbePrjNew::leaveSgeCreate(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeCreate --- INSERT
};

uint DlgWdbePrjNew::enterSgeSync(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	// IP enterSgeSync --- IBEGIN

	license->syncPrj(dbswdbe, xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFPRJ, jref));

	// IP enterSgeSync --- IEND

	return retval;
};

void DlgWdbePrjNew::leaveSgeSync(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeSync --- INSERT
};

uint DlgWdbePrjNew::enterSgeDone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void DlgWdbePrjNew::leaveSgeDone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeDone --- INSERT
};
