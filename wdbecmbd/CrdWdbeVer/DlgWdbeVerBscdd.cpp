/**
	* \file DlgWdbeVerBscdd.cpp
	* job handler for job DlgWdbeVerBscdd (implementation)
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

#include "DlgWdbeVerBscdd.h"

#include "DlgWdbeVerBscdd_blks.cpp"
#include "DlgWdbeVerBscdd_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWdbeVerBscdd
 ******************************************************************************/

DlgWdbeVerBscdd::DlgWdbeVerBscdd(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::DLGWDBEVERBSCDD, jrefSup, ixWdbeVLocale)
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

	iex = new JobWdbeIexBdd(xchg, dbswdbe, jref, ixWdbeVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswdbe, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgWdbeVerBscdd::~DlgWdbeVerBscdd() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* DlgWdbeVerBscdd::getNewDpchEng(
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

void DlgWdbeVerBscdd::refreshIfi(
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

void DlgWdbeVerBscdd::refreshImp(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContInfImp oldContinfimp(continfimp);
	StatShrImp oldStatshrimp(statshrimp);

	// IP refreshImp --- RBEGIN
	// continfimp
	continfimp.TxtPrg = getSquawk(dbswdbe);

	// statshrimp
	statshrimp.ButRunActive = evalImpButRunActive(dbswdbe);
	statshrimp.ButStoActive = evalImpButStoActive(dbswdbe);

	// IP refreshImp --- REND
	if (continfimp.diff(&oldContinfimp).size() != 0) insert(moditems, DpchEngData::CONTINFIMP);
	if (statshrimp.diff(&oldStatshrimp).size() != 0) insert(moditems, DpchEngData::STATSHRIMP);
};

void DlgWdbeVerBscdd::refreshPpr(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContInfPpr oldContinfppr(continfppr);
	StatShrPpr oldStatshrppr(statshrppr);

	// IP refreshPpr --- RBEGIN
	// continfppr
	continfppr.TxtPrg = getSquawk(dbswdbe);

	// statshrppr
	statshrppr.ButRunActive = evalPprButRunActive(dbswdbe);
	statshrppr.ButStoActive = evalPprButStoActive(dbswdbe);

	// IP refreshPpr --- REND
	if (continfppr.diff(&oldContinfppr).size() != 0) insert(moditems, DpchEngData::CONTINFPPR);
	if (statshrppr.diff(&oldStatshrppr).size() != 0) insert(moditems, DpchEngData::STATSHRPPR);
};

void DlgWdbeVerBscdd::refreshLfi(
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

void DlgWdbeVerBscdd::refresh(
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

	muteRefresh = false;
};

void DlgWdbeVerBscdd::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEVERBSCDDDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswdbe, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEVERBSCDDDO) {
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
		else if ((req->sref == "mon") && (ixVSge == VecVSge::POSTPRC1)) handleTimerWithSrefMonInSgePostprc1(dbswdbe);
		else if ((req->sref == "mon") && (ixVSge == VecVSge::POSTPRC2)) handleTimerWithSrefMonInSgePostprc2(dbswdbe);
		else if ((req->sref == "mon") && (ixVSge == VecVSge::POSTPRC3)) handleTimerWithSrefMonInSgePostprc3(dbswdbe);
	};
};

void DlgWdbeVerBscdd::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWdbeVerBscdd::handleDpchAppDataContiac(
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

void DlgWdbeVerBscdd::handleDpchAppDoButDneClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButDneClick --- IBEGIN
	if (statshr.ButDneActive) {
		*dpcheng = new DpchEngWdbeConfirm(true, jref, "");
		xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBEDLGCLOSE, jref);
	};
	// IP handleDpchAppDoButDneClick --- IEND
};

void DlgWdbeVerBscdd::handleDpchAppDoImpButRunClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoImpButRunClick --- BEGIN
	if (statshrimp.ButRunActive) {
		changeStage(dbswdbe, VecVSge::IMPIDLE, dpcheng);
	};
	// IP handleDpchAppDoImpButRunClick --- END
};

void DlgWdbeVerBscdd::handleDpchAppDoImpButStoClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoImpButStoClick --- INSERT
};

void DlgWdbeVerBscdd::handleDpchAppDoPprButRunClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoPprButRunClick --- BEGIN
	if (statshrppr.ButRunActive) {
		changeStage(dbswdbe, VecVSge::POSTPRC1, dpcheng);
	};
	// IP handleDpchAppDoPprButRunClick --- END
};

void DlgWdbeVerBscdd::handleDpchAppDoPprButStoClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoPprButStoClick --- INSERT
};

void DlgWdbeVerBscdd::handleDpchAppWdbeAlert(
			DbsWdbe* dbswdbe
			, DpchAppWdbeAlert* dpchappwdbealert
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppWdbeAlert --- IBEGIN
	if (ixVSge == VecVSge::ALRWDBEPER) {
		changeStage(dbswdbe, nextIxVSgeSuccess);
	} else if (ixVSge == VecVSge::ALRWDBEIER) {
		if (dpchappwdbealert->numFMcb == 2) iex->reverse(dbswdbe);
		changeStage(dbswdbe, nextIxVSgeSuccess);
	};
	// IP handleDpchAppWdbeAlert --- IEND
};

void DlgWdbeVerBscdd::handleUploadInSgeIdle(
			DbsWdbe* dbswdbe
			, const string& filename
		) {
	infilename = filename; // IP handleUploadInSgeIdle --- ILINE
	changeStage(dbswdbe, VecVSge::PRSIDLE);
};

string DlgWdbeVerBscdd::handleDownloadInSgeDone(
			DbsWdbe* dbswdbe
		) {
	return(""); // IP handleDownloadInSgeDone --- LINE
};

void DlgWdbeVerBscdd::handleTimerInSgePrsidle(
			DbsWdbe* dbswdbe
			, const string& sref
		) {
	changeStage(dbswdbe, nextIxVSgeSuccess);
};

void DlgWdbeVerBscdd::handleTimerInSgeImpidle(
			DbsWdbe* dbswdbe
			, const string& sref
		) {
	changeStage(dbswdbe, nextIxVSgeSuccess);
};

void DlgWdbeVerBscdd::handleTimerWithSrefMonInSgeImport(
			DbsWdbe* dbswdbe
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	refreshWithDpchEng(dbswdbe); // IP handleTimerWithSrefMonInSgeImport --- ILINE
};

void DlgWdbeVerBscdd::handleTimerWithSrefMonInSgePostprc1(
			DbsWdbe* dbswdbe
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	refreshWithDpchEng(dbswdbe); // IP handleTimerWithSrefMonInSgePostprc1 --- ILINE
};

void DlgWdbeVerBscdd::handleTimerWithSrefMonInSgePostprc2(
			DbsWdbe* dbswdbe
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	refreshWithDpchEng(dbswdbe); // IP handleTimerWithSrefMonInSgePostprc2 --- ILINE
};

void DlgWdbeVerBscdd::handleTimerWithSrefMonInSgePostprc3(
			DbsWdbe* dbswdbe
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	refreshWithDpchEng(dbswdbe); // IP handleTimerWithSrefMonInSgePostprc3 --- ILINE
};

void DlgWdbeVerBscdd::changeStage(
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
				case VecVSge::POSTPRC1: leaveSgePostprc1(dbswdbe); break;
				case VecVSge::POSTPRC2: leaveSgePostprc2(dbswdbe); break;
				case VecVSge::POSTPRC3: leaveSgePostprc3(dbswdbe); break;
				case VecVSge::DONE: leaveSgeDone(dbswdbe); break;
			};

			setStage(dbswdbe, _ixVSge);
			reenter = false;
			refreshWithDpchEng(dbswdbe, dpcheng); // IP changeStage.refresh1 --- LINE
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
			case VecVSge::POSTPRC1: _ixVSge = enterSgePostprc1(dbswdbe, reenter); break;
			case VecVSge::POSTPRC2: _ixVSge = enterSgePostprc2(dbswdbe, reenter); break;
			case VecVSge::POSTPRC3: _ixVSge = enterSgePostprc3(dbswdbe, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswdbe, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWdbeVerBscdd::getSquawk(
			DbsWdbe* dbswdbe
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::PARSE) || (ixVSge == VecVSge::ALRWDBEPER) || (ixVSge == VecVSge::PRSDONE) || (ixVSge == VecVSge::IMPORT) || (ixVSge == VecVSge::ALRWDBEIER) || (ixVSge == VecVSge::IMPDONE) || (ixVSge == VecVSge::POSTPRC1) || (ixVSge == VecVSge::POSTPRC2) || (ixVSge == VecVSge::POSTPRC3) ) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			if (ixVSge == VecVSge::PARSE) retval = iex->getSquawk(dbswdbe);
			else if (ixVSge == VecVSge::ALRWDBEPER) retval = "parse error";
			else if (ixVSge == VecVSge::PRSDONE) retval = "basic device description parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing basic device description (" + to_string(iex->impcnt) + " records added)";
			else if (ixVSge == VecVSge::ALRWDBEIER) retval = "import error";
			else if (ixVSge == VecVSge::IMPDONE) retval = "import done";
			else if (ixVSge == VecVSge::POSTPRC1) retval = "complementing basic features (" + to_string(opNSuccess + opNFailure) + "/" + to_string(opN) + " operations completed, last: " + getOpsqkLast() + ")";
			else if (ixVSge == VecVSge::POSTPRC2) retval = "applying module modifications top-down (" + to_string(opNSuccess + opNFailure) + "/" + to_string(opN) + " operations completed, last: " + getOpsqkLast() + ")";
			else if (ixVSge == VecVSge::POSTPRC3) retval = "applying module modifications bottom-up (" + to_string(opNSuccess + opNFailure) + "/" + to_string(opN) + " operations completed, last: " + getOpsqkLast() + ")";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

uint DlgWdbeVerBscdd::enterSgeIdle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWdbeVerBscdd::leaveSgeIdle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWdbeVerBscdd::enterSgePrsidle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::PRSIDLE;
	nextIxVSgeSuccess = VecVSge::PARSE;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgePrsidle --- INSERT

	return retval;
};

void DlgWdbeVerBscdd::leaveSgePrsidle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgePrsidle --- INSERT
};

uint DlgWdbeVerBscdd::enterSgeParse(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::PRSDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::ALRWDBEPER;

	// IP enterSgeParse --- IBEGIN
	ifstream ififile;

	string rectfile;

	char* buf;
	string s;

	iex->reset(dbswdbe);

	// check file type
	ififile.open(infilename.c_str(), ifstream::in);

	buf = new char[16];
	ififile.get(buf, 16);
	s = string(buf);

	ifitxt = (s.find("IexWdbeBdd") == 0);
	ifixml = (s.find("<?xml") == 0);		

	delete[] buf;
	ififile.close();

	// parse file accordingly
	if (ifitxt) {
		rectfile = Tmp::newfile(xchg->tmppath, "txt");
		iex->parseFromFile(dbswdbe, infilename, false, xchg->tmppath + "/" + rectfile);
		infilename = xchg->tmppath + "/" + rectfile;

	} else if (ifixml) iex->parseFromFile(dbswdbe, infilename, true, "");

	if (iex->ixVSge != JobWdbeIexBdd::VecVSge::PRSDONE) {
		if (reqCmd) {
			if (iex->ixVSge == JobWdbeIexBdd::VecVSge::PRSERR) cout << "\t" << iex->getSquawk(dbswdbe) << endl;
			else cout << "\tneither text-based nor XML file format recognized" << endl;

			retval = VecVSge::IDLE;

		} else {
			retval = nextIxVSgeFailure;
		};
	};
	// IP enterSgeParse --- IEND

	return retval;
};

void DlgWdbeVerBscdd::leaveSgeParse(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeParse --- INSERT
};

uint DlgWdbeVerBscdd::enterSgeAlrwdbeper(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::ALRWDBEPER;
	nextIxVSgeSuccess = VecVSge::IDLE;

	// IP enterSgeAlrwdbeper --- RBEGIN
	ContInfWdbeAlert continf;

	continf.TxtCpt = VecWdbeVTag::getTitle(VecWdbeVTag::ERROR, ixWdbeVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (iex->ixVSge == JobWdbeIexBdd::VecVSge::PRSERR) continf.TxtMsg1 = iex->getSquawk(dbswdbe);
	else continf.TxtMsg1 = "neither text-based nor XML file format recognized";

	feedFMcbAlert.clear();

	VecWdbeVTag::appendToFeed(VecWdbeVTag::OK, ixWdbeVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();

	xchg->submitDpch(new DpchEngWdbeAlert(jref, &continf, &feedFMcbAlert, {DpchEngWdbeAlert::ALL}));
	// IP enterSgeAlrwdbeper --- REND

	return retval;
};

void DlgWdbeVerBscdd::leaveSgeAlrwdbeper(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAlrwdbeper --- INSERT
};

uint DlgWdbeVerBscdd::enterSgePrsdone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::PRSDONE;

	// IP enterSgePrsdone --- INSERT

	return retval;
};

void DlgWdbeVerBscdd::leaveSgePrsdone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgePrsdone --- INSERT
};

uint DlgWdbeVerBscdd::enterSgeImpidle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IMPIDLE;
	nextIxVSgeSuccess = VecVSge::IMPORT;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgeImpidle --- INSERT

	return retval;
};

void DlgWdbeVerBscdd::leaveSgeImpidle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeImpidle --- INSERT
};

uint DlgWdbeVerBscdd::enterSgeImport(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::IMPDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::ALRWDBEIER;

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);

	// IP enterSgeImport --- IBEGIN
	iex->import(dbswdbe);

	if (iex->ixVSge == JobWdbeIexBdd::VecVSge::IMPERR) retval = nextIxVSgeFailure;
	// IP enterSgeImport --- IEND

	return retval;
};

void DlgWdbeVerBscdd::leaveSgeImport(
			DbsWdbe* dbswdbe
		) {
	invalidateWakeups();
	// IP leaveSgeImport --- INSERT
};

uint DlgWdbeVerBscdd::enterSgeAlrwdbeier(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::ALRWDBEIER;
	nextIxVSgeSuccess = VecVSge::IDLE;

	// IP enterSgeAlrwdbeier --- RBEGIN

	if (reqCmd) {
		cout << "\t" << iex->getSquawk(dbswdbe) << endl;
		retval = nextIxVSgeSuccess;
	} else {
		xchg->submitDpch(AlrWdbe::prepareAlrIer(jref, ixWdbeVLocale, iex->getSquawk(dbswdbe), feedFMcbAlert));
	};

	// IP enterSgeAlrwdbeier --- REND

	return retval;
};

void DlgWdbeVerBscdd::leaveSgeAlrwdbeier(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAlrwdbeier --- INSERT
};

uint DlgWdbeVerBscdd::enterSgeImpdone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IMPDONE;

	// IP enterSgeImpdone --- IBEGIN

	ubigint refWdbeMVersion;
	string Prjshort;
	string Filename, srefKMimetype;

	refWdbeMVersion = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref);
	Prjshort = Wdbe::getPrjshort(dbswdbe, refWdbeMVersion);

	if (ifitxt) {
		Filename = "IexWdbeBdd_" + StrMod::lc(Prjshort) + ".txt";
		srefKMimetype = "txt";
	} else if (ifixml) {
		Filename = "IexWdbeBdd_" + StrMod::lc(Prjshort) + ".xml";
		srefKMimetype = "xml";
	};

	Acv::addfile(dbswdbe, xchg->acvpath, infilename, xchg->getRefPreset(VecWdbeVPreset::PREWDBEGROUP, jref), xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref), VecWdbeVMFileRefTbl::VER, refWdbeMVersion, "mod", Filename, srefKMimetype, "");

	// IP enterSgeImpdone --- IEND

	return retval;
};

void DlgWdbeVerBscdd::leaveSgeImpdone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeImpdone --- INSERT
};

uint DlgWdbeVerBscdd::enterSgePostprc1(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::POSTPRC1;
	nextIxVSgeSuccess = VecVSge::POSTPRC2;

	clearInvs();

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);

	// IP enterSgePostprc1 --- IBEGIN

	vector<ubigint> refs;

	ubigint refWdbeMVersion = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref);

	addInv(new DpchInvWdbeModbscSys(0, 0, refWdbeMVersion));

	dbswdbe->loadRefsBySQL("SELECT ref FROM TblWdbeMUnit WHERE refIxVTbl = " + to_string(VecWdbeVMUnitRefTbl::VER) + " AND refUref = " + to_string(refWdbeMVersion), false, refs);
	for (unsigned int i = 0; i < refs.size();i++) addInv(new DpchInvWdbeModbscUnt(0, 0, refs[i]));

	// IP enterSgePostprc1 --- IEND

	submitInvs(dbswdbe, retval, retval);
	return retval;
};

void DlgWdbeVerBscdd::leaveSgePostprc1(
			DbsWdbe* dbswdbe
		) {
	invalidateWakeups();
	// IP leaveSgePostprc1 --- INSERT
};

uint DlgWdbeVerBscdd::enterSgePostprc2(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::POSTPRC2;
	nextIxVSgeSuccess = VecVSge::POSTPRC2;

	clearInvs();

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);

	// IP enterSgePostprc2 --- IBEGIN

	// modules top-down order, respecting unit hierarchy bottom-up ; modules may be added in the process

	ubigint refWdbeMVersion = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref);

	WdbeMModule* mdl = NULL;

	unsigned int lvl;

	map<ubigint,string> srefsMtpCustops;

	bool tplcpy, typmod, tplmod;

	Wdbe::levelMdls(dbswdbe, refWdbeMVersion, mdls, lvlsMdls, false, true, true);

	// determine modules due for op invocation
	Wdbe::getSrefsMtpCustops(dbswdbe, srefsMtpCustops, VecWdbeVKeylist::KLSTKWDBEMTPMODBSCTDCUSTOP);

	for (unsigned int i = 0; i < mdls.nodes.size(); i++) {
		mdl = mdls.nodes[i];
		lvl = lvlsMdls[i];

		// invs complete if at least one added on superior level
		if (opN > 0) if (i != 0) if (lvl != lvlsMdls[i-1]) break;

		// check for template copy
		tplcpy = false;
		
		if ((refsTplcpy.find(mdl->ref) == refsTplcpy.end()) && (mdl->tplRefWdbeMModule != 0)) {
			addInv(new DpchInvWdbeModbscTplcpy(0, 0, mdl->ref));
			tplcpy = true;
		};

		// check for type-based modification
		typmod = false;

		if (!tplcpy) {
			if (refsTypmod.find(mdl->ref) == refsTypmod.end()) {
				if ((mdl->ixVBasetype == VecWdbeVMModuleBasetype::CTR) || (mdl->ixVBasetype == VecWdbeVMModuleBasetype::ECTR)) {
					addInv(new DpchInvWdbeModbscCtrtd(0, 0, mdl->ref));
					typmod = true;
				} else if (mdl->ixVBasetype == VecWdbeVMModuleBasetype::FWDCTR) {
					addInv(new DpchInvWdbeModbscFwdctrtd(0, 0, mdl->ref));
					typmod = true;
				} else if (mdl->ixVBasetype == VecWdbeVMModuleBasetype::IMBUF) {
					addInv(new DpchInvWdbeModbscImbuftd(0, 0, mdl->ref));
					typmod = true;
				};
			};
		};

		// check for template-based modification
		tplmod = false;

		if (!tplcpy && !typmod) {
			if (refsTplmod.find(mdl->ref) == refsTplmod.end()) {
				auto it = srefsMtpCustops.find(mdl->tplRefWdbeMModule);

				if (it != srefsMtpCustops.end()) {
					addInv(new DpchInvWdbeMtpModbsctd(0, it->second, 0, mdl->ref));
					tplmod = true;
				};
			};
		};

		if (tplcpy) refsTplcpy.insert(mdl->ref);
		if (typmod) refsTypmod.insert(mdl->ref);
		if (tplmod) refsTplmod.insert(mdl->ref);
	};

	// IP enterSgePostprc2 --- IEND

	submitInvs(dbswdbe, VecVSge::POSTPRC3, retval);
	return retval;
};

void DlgWdbeVerBscdd::leaveSgePostprc2(
			DbsWdbe* dbswdbe
		) {
	invalidateWakeups();
	// IP leaveSgePostprc2 --- IBEGIN
	mdls.clear();
	lvlsMdls.clear();

	refsTplcpy.clear();
	refsTypmod.clear();
	refsTplmod.clear();
	// IP leaveSgePostprc2 --- IEND
};

uint DlgWdbeVerBscdd::enterSgePostprc3(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::POSTPRC3;
	nextIxVSgeSuccess = VecVSge::POSTPRC3;

	clearInvs();

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);

	// IP enterSgePostprc3 --- IBEGIN

	// modules bottom-up order, not respecting unit hierarchy

	ubigint refWdbeMVersion = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref);

	WdbeMModule* mdl = NULL;

	unsigned int lvl;

	map<ubigint,string> srefsMtpCustops;

	bool typmod, tplmod;

	if (mdls.nodes.size() == 0) Wdbe::levelMdls(dbswdbe, refWdbeMVersion, mdls, lvlsMdls, true);

	// determine modules due for op invocation
	Wdbe::getSrefsMtpCustops(dbswdbe, srefsMtpCustops, VecWdbeVKeylist::KLSTKWDBEMTPMODBSCBUCUSTOP);

	for (unsigned int i = 0; i < mdls.nodes.size(); i++) {
		mdl = mdls.nodes[i];
		lvl = lvlsMdls[i];

		// invs complete if at least one added on inferior level
		if (opN > 0) if (i != 0) if (lvl != lvlsMdls[i-1]) break;

		// check for type-based modification
		typmod = false;

		if (refsTypmod.find(mdl->ref) == refsTypmod.end()) {
			// currently no corresponding ops
		};

		// check for template-based modification
		tplmod = false;

		if (!typmod) {
			if (refsTplmod.find(mdl->ref) == refsTplmod.end()) {
				auto it = srefsMtpCustops.find(mdl->tplRefWdbeMModule);

				if (it != srefsMtpCustops.end()) {
					addInv(new DpchInvWdbeMtpModbscbu(0, it->second, 0, mdl->ref));
					tplmod = true;
				};
			};
		};

		if (typmod) refsTypmod.insert(mdl->ref);
		if (tplmod) refsTplmod.insert(mdl->ref);
	};

	// IP enterSgePostprc3 --- IEND

	submitInvs(dbswdbe, VecVSge::DONE, retval);
	return retval;
};

void DlgWdbeVerBscdd::leaveSgePostprc3(
			DbsWdbe* dbswdbe
		) {
	invalidateWakeups();
	// IP leaveSgePostprc3 --- IBEGIN
	ubigint refWdbeMVersion = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref);

	Wdbe::updateVerste(dbswdbe, refWdbeMVersion, VecWdbeVMVersionState::DSNBSCDD);

	mdls.clear();
	lvlsMdls.clear();

	refsTypmod.clear();
	refsTplmod.clear();
	// IP leaveSgePostprc3 --- IEND
};

uint DlgWdbeVerBscdd::enterSgeDone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void DlgWdbeVerBscdd::leaveSgeDone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeDone --- INSERT
};
