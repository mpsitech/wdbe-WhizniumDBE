/**
	* \file DlgWdbeCvrBsccd.cpp
	* job handler for job DlgWdbeCvrBsccd (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbed.h>
#endif

#include "DlgWdbeCvrBsccd.h"

#include "DlgWdbeCvrBsccd_blks.cpp"
#include "DlgWdbeCvrBsccd_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWdbeCvrBsccd
 ******************************************************************************/

DlgWdbeCvrBsccd::DlgWdbeCvrBsccd(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::DLGWDBECVRBSCCD, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFDse.tag = "FeedFDse";
	VecVDit::fillFeed(ixWdbeVLocale, feedFDse);
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	iex = NULL;

	// IP constructor.cust1 --- INSERT

	ixVDit = VecVDit::IFI;

	iex = new JobWdbeIexBcd(xchg, dbswdbe, jref, ixWdbeVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswdbe, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgWdbeCvrBsccd::~DlgWdbeCvrBsccd() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* DlgWdbeCvrBsccd::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &continfimp, &continflfi, &continfppr, &feedFDse, &feedFSge, &statshr, &statshrifi, &statshrimp, &statshrlfi, &statshrppr, items);
	};

	return dpcheng;
};

void DlgWdbeCvrBsccd::refreshIfi(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShrIfi oldStatshrifi(statshrifi);

	// IP refreshIfi --- BEGIN
	// statshrifi
	statshrifi.UldActive = evalIfiUldActive(dbswdbe);

	// IP refreshIfi --- END
	if (statshrifi.diff(&oldStatshrifi).size() != 0) insert(moditems, DpchEngData::STATSHRIFI);
};

void DlgWdbeCvrBsccd::refreshImp(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContInfImp oldContinfimp(continfimp);
	StatShrImp oldStatshrimp(statshrimp);

	// IP refreshImp --- BEGIN
	// continfimp

	// statshrimp
	statshrimp.ButRunActive = evalImpButRunActive(dbswdbe);
	statshrimp.ButStoActive = evalImpButStoActive(dbswdbe);

	// IP refreshImp --- END
	if (continfimp.diff(&oldContinfimp).size() != 0) insert(moditems, DpchEngData::CONTINFIMP);
	if (statshrimp.diff(&oldStatshrimp).size() != 0) insert(moditems, DpchEngData::STATSHRIMP);
};

void DlgWdbeCvrBsccd::refreshPpr(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContInfPpr oldContinfppr(continfppr);
	StatShrPpr oldStatshrppr(statshrppr);

	// IP refreshPpr --- BEGIN
	// continfppr

	// statshrppr
	statshrppr.ButRunActive = evalPprButRunActive(dbswdbe);
	statshrppr.ButStoActive = evalPprButStoActive(dbswdbe);

	// IP refreshPpr --- END
	if (continfppr.diff(&oldContinfppr).size() != 0) insert(moditems, DpchEngData::CONTINFPPR);
	if (statshrppr.diff(&oldStatshrppr).size() != 0) insert(moditems, DpchEngData::STATSHRPPR);
};

void DlgWdbeCvrBsccd::refreshLfi(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShrLfi oldStatshrlfi(statshrlfi);
	ContInfLfi oldContinflfi(continflfi);

	// IP refreshLfi --- RBEGIN
	// statshrlfi
	statshrlfi.DldActive = evalLfiDldActive(dbswdbe);

	// continflfi
	continflfi.Dld = "log.txt";

	// IP refreshLfi --- REND
	if (statshrlfi.diff(&oldStatshrlfi).size() != 0) insert(moditems, DpchEngData::STATSHRLFI);
	if (continflfi.diff(&oldContinflfi).size() != 0) insert(moditems, DpchEngData::CONTINFLFI);
};

void DlgWdbeCvrBsccd::refresh(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.numFSge = ixVSge;

	// contiac
	contiac.numFDse = ixVDit;

	// statshr
	statshr.ButDneActive = evalButDneActive(dbswdbe);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshIfi(dbswdbe, moditems);
	refreshImp(dbswdbe, moditems);
	refreshPpr(dbswdbe, moditems);
	refreshLfi(dbswdbe, moditems);
};

void DlgWdbeCvrBsccd::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBECVRBSCCDDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswdbe, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBECVRBSCCDDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbswdbe, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoImp != 0) {
				if (dpchappdo->ixVDoImp == VecVDoImp::BUTRUNCLICK) {
					handleDpchAppDoImpButRunClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDoImp == VecVDoImp::BUTSTOCLICK) {
					handleDpchAppDoImpButStoClick(dbswdbe, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoPpr != 0) {
				if (dpchappdo->ixVDoPpr == VecVDoPpr::BUTRUNCLICK) {
					handleDpchAppDoPprButRunClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDoPpr == VecVDoPpr::BUTSTOCLICK) {
					handleDpchAppDoPprButStoClick(dbswdbe, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEALERT) {
			handleDpchAppWdbeAlert(dbswdbe, (DpchAppWdbeAlert*) (req->dpchapp), &(req->dpcheng));

		};

	} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::UPLOAD) {
		if (ixVSge == VecVSge::IDLE) handleUploadInSgeIdle(dbswdbe, req->filename);

	} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::DOWNLOAD) {
		if (ixVSge == VecVSge::DONE) req->filename = handleDownloadInSgeDone(dbswdbe);

	} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::DPCHRET) {
		if (req->dpchret->ixOpVOpres == VecOpVOpres::PROGRESS) {
			// IP handleRequest.opprogress --- INSERT
		} else {
			if (req->dpchret->ixOpVOpres == VecOpVOpres::SUCCESS) opNSuccess++;
			else if (req->dpchret->ixOpVOpres == VecOpVOpres::FAILURE) opNFailure++;

			if ((opNSuccess + opNFailure) == opN) {
				clearOps();

				opN = 0;
				opNSuccess = 0;

				if (opNFailure > 0) {
					opNFailure = 0;
					changeStage(dbswdbe, nextIxVSgeFailure);
				} else changeStage(dbswdbe, nextIxVSgeSuccess);
			};
		};

	} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::TIMER) {
		if (ixVSge == VecVSge::PRSIDLE) handleTimerInSgePrsidle(dbswdbe, req->sref);
		else if (ixVSge == VecVSge::IMPIDLE) handleTimerInSgeImpidle(dbswdbe, req->sref);
		else if ((req->sref == "mon") && (ixVSge == VecVSge::IMPORT)) handleTimerWithSrefMonInSgeImport(dbswdbe);
	};
};

void DlgWdbeCvrBsccd::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWdbeCvrBsccd::handleDpchAppDataContiac(
			DbsWdbe* dbswdbe
			, ContIac* _contiac
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFDSE)) {
		if ((_contiac->numFDse >= VecVDit::IFI) && (_contiac->numFDse <= VecVDit::LFI)) ixVDit = _contiac->numFDse;
		refresh(dbswdbe, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgWdbeCvrBsccd::handleDpchAppDoButDneClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButDneClick --- INSERT
};

void DlgWdbeCvrBsccd::handleDpchAppDoImpButRunClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoImpButRunClick --- BEGIN
	if (statshrimp.ButRunActive) {
		changeStage(dbswdbe, VecVSge::IMPIDLE, dpcheng);
	};
	// IP handleDpchAppDoImpButRunClick --- END
};

void DlgWdbeCvrBsccd::handleDpchAppDoImpButStoClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoImpButStoClick --- INSERT
};

void DlgWdbeCvrBsccd::handleDpchAppDoPprButRunClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoPprButRunClick --- BEGIN
	if (statshrppr.ButRunActive) {
		changeStage(dbswdbe, VecVSge::POSTPRC, dpcheng);
	};
	// IP handleDpchAppDoPprButRunClick --- END
};

void DlgWdbeCvrBsccd::handleDpchAppDoPprButStoClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoPprButStoClick --- INSERT
};

void DlgWdbeCvrBsccd::handleDpchAppWdbeAlert(
			DbsWdbe* dbswdbe
			, DpchAppWdbeAlert* dpchappwdbealert
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppWdbeAlert --- INSERT
};

void DlgWdbeCvrBsccd::handleUploadInSgeIdle(
			DbsWdbe* dbswdbe
			, const string& filename
		) {
	// IP handleUploadInSgeIdle --- INSERT
	changeStage(dbswdbe, VecVSge::PRSIDLE);
};

string DlgWdbeCvrBsccd::handleDownloadInSgeDone(
			DbsWdbe* dbswdbe
		) {
	return(""); // IP handleDownloadInSgeDone --- LINE
};

void DlgWdbeCvrBsccd::handleTimerInSgePrsidle(
			DbsWdbe* dbswdbe
			, const string& sref
		) {
	changeStage(dbswdbe, nextIxVSgeSuccess);
};

void DlgWdbeCvrBsccd::handleTimerInSgeImpidle(
			DbsWdbe* dbswdbe
			, const string& sref
		) {
	changeStage(dbswdbe, nextIxVSgeSuccess);
};

void DlgWdbeCvrBsccd::handleTimerWithSrefMonInSgeImport(
			DbsWdbe* dbswdbe
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	// IP handleTimerWithSrefMonInSgeImport --- INSERT
};

void DlgWdbeCvrBsccd::changeStage(
			DbsWdbe* dbswdbe
			, uint _ixVSge
			, DpchEngWdbe** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswdbe); break;
				case VecVSge::PRSIDLE: leaveSgePrsidle(dbswdbe); break;
				case VecVSge::PARSE: leaveSgeParse(dbswdbe); break;
				case VecVSge::ALRWDBEPER: leaveSgeAlrwdbeper(dbswdbe); break;
				case VecVSge::PRSDONE: leaveSgePrsdone(dbswdbe); break;
				case VecVSge::IMPIDLE: leaveSgeImpidle(dbswdbe); break;
				case VecVSge::IMPORT: leaveSgeImport(dbswdbe); break;
				case VecVSge::ALRWDBEIER: leaveSgeAlrwdbeier(dbswdbe); break;
				case VecVSge::IMPDONE: leaveSgeImpdone(dbswdbe); break;
				case VecVSge::POSTPRC: leaveSgePostprc(dbswdbe); break;
				case VecVSge::DONE: leaveSgeDone(dbswdbe); break;
			};

			setStage(dbswdbe, _ixVSge);
			reenter = false;
			if (!muteRefresh) refreshWithDpchEng(dbswdbe, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswdbe, reenter); break;
			case VecVSge::PRSIDLE: _ixVSge = enterSgePrsidle(dbswdbe, reenter); break;
			case VecVSge::PARSE: _ixVSge = enterSgeParse(dbswdbe, reenter); break;
			case VecVSge::ALRWDBEPER: _ixVSge = enterSgeAlrwdbeper(dbswdbe, reenter); break;
			case VecVSge::PRSDONE: _ixVSge = enterSgePrsdone(dbswdbe, reenter); break;
			case VecVSge::IMPIDLE: _ixVSge = enterSgeImpidle(dbswdbe, reenter); break;
			case VecVSge::IMPORT: _ixVSge = enterSgeImport(dbswdbe, reenter); break;
			case VecVSge::ALRWDBEIER: _ixVSge = enterSgeAlrwdbeier(dbswdbe, reenter); break;
			case VecVSge::IMPDONE: _ixVSge = enterSgeImpdone(dbswdbe, reenter); break;
			case VecVSge::POSTPRC: _ixVSge = enterSgePostprc(dbswdbe, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswdbe, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWdbeCvrBsccd::getSquawk(
			DbsWdbe* dbswdbe
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::PARSE) || (ixVSge == VecVSge::ALRWDBEPER) || (ixVSge == VecVSge::PRSDONE) || (ixVSge == VecVSge::IMPORT) || (ixVSge == VecVSge::ALRWDBEIER) || (ixVSge == VecVSge::IMPDONE) || (ixVSge == VecVSge::POSTPRC) ) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing basic core description";
			else if (ixVSge == VecVSge::ALRWDBEPER) retval = "parse error";
			else if (ixVSge == VecVSge::PRSDONE) retval = "basic core description parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing basic core description (" + to_string(iex->impcnt) + " records added)";
			else if (ixVSge == VecVSge::ALRWDBEIER) retval = "import error";
			else if (ixVSge == VecVSge::IMPDONE) retval = "import done";
			else if (ixVSge == VecVSge::POSTPRC) retval = "postprocessing";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

uint DlgWdbeCvrBsccd::enterSgeIdle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWdbeCvrBsccd::leaveSgeIdle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWdbeCvrBsccd::enterSgePrsidle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::PRSIDLE;
	nextIxVSgeSuccess = VecVSge::PARSE;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgePrsidle --- INSERT

	return retval;
};

void DlgWdbeCvrBsccd::leaveSgePrsidle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgePrsidle --- INSERT
};

uint DlgWdbeCvrBsccd::enterSgeParse(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::PRSDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::ALRWDBEPER;

	// IP enterSgeParse --- INSERT

	return retval;
};

void DlgWdbeCvrBsccd::leaveSgeParse(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeParse --- INSERT
};

uint DlgWdbeCvrBsccd::enterSgeAlrwdbeper(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::ALRWDBEPER;
	nextIxVSgeSuccess = VecVSge::IDLE;

	xchg->submitDpch(AlrWdbe::prepareAlrPer(jref, ixWdbeVLocale, "", feedFMcbAlert)); // IP enterSgeAlrwdbeper --- LINE

	return retval;
};

void DlgWdbeCvrBsccd::leaveSgeAlrwdbeper(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAlrwdbeper --- INSERT
};

uint DlgWdbeCvrBsccd::enterSgePrsdone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::PRSDONE;

	// IP enterSgePrsdone --- INSERT

	return retval;
};

void DlgWdbeCvrBsccd::leaveSgePrsdone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgePrsdone --- INSERT
};

uint DlgWdbeCvrBsccd::enterSgeImpidle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IMPIDLE;
	nextIxVSgeSuccess = VecVSge::IMPORT;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgeImpidle --- INSERT

	return retval;
};

void DlgWdbeCvrBsccd::leaveSgeImpidle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeImpidle --- INSERT
};

uint DlgWdbeCvrBsccd::enterSgeImport(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::IMPDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::ALRWDBEIER;

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);

	// IP enterSgeImport --- INSERT

	return retval;
};

void DlgWdbeCvrBsccd::leaveSgeImport(
			DbsWdbe* dbswdbe
		) {
	invalidateWakeups();
	// IP leaveSgeImport --- INSERT
};

uint DlgWdbeCvrBsccd::enterSgeAlrwdbeier(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::ALRWDBEIER;
	nextIxVSgeSuccess = VecVSge::IDLE;

	xchg->submitDpch(AlrWdbe::prepareAlrIer(jref, ixWdbeVLocale, "", feedFMcbAlert)); // IP enterSgeAlrwdbeier --- LINE

	return retval;
};

void DlgWdbeCvrBsccd::leaveSgeAlrwdbeier(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAlrwdbeier --- INSERT
};

uint DlgWdbeCvrBsccd::enterSgeImpdone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IMPDONE;

	// IP enterSgeImpdone --- INSERT

	return retval;
};

void DlgWdbeCvrBsccd::leaveSgeImpdone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeImpdone --- INSERT
};

uint DlgWdbeCvrBsccd::enterSgePostprc(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::POSTPRC;
	nextIxVSgeSuccess = VecVSge::DONE;

	clearInvs();

	// IP enterSgePostprc --- INSERT

	submitInvs(dbswdbe, retval, retval);
	return retval;
};

void DlgWdbeCvrBsccd::leaveSgePostprc(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgePostprc --- INSERT
};

uint DlgWdbeCvrBsccd::enterSgeDone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void DlgWdbeCvrBsccd::leaveSgeDone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeDone --- INSERT
};


