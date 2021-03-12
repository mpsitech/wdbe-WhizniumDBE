/**
	* \file DlgWdbeVerDetdd.cpp
	* job handler for job DlgWdbeVerDetdd (implementation)
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

#include "DlgWdbeVerDetdd.h"

#include "DlgWdbeVerDetdd_blks.cpp"
#include "DlgWdbeVerDetdd_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWdbeVerDetdd
 ******************************************************************************/

DlgWdbeVerDetdd::DlgWdbeVerDetdd(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::DLGWDBEVERDETDD, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFDse.tag = "FeedFDse";
	VecVDit::fillFeed(ixWdbeVLocale, feedFDse);
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	license = NULL;
	iex = NULL;

	// IP constructor.cust1 --- INSERT

	ixVDit = VecVDit::IFI;

	license = new JobWdbeLicense(xchg, dbswdbe, jref, ixWdbeVLocale);
	iex = new JobWdbeIexDdd(xchg, dbswdbe, jref, ixWdbeVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswdbe, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgWdbeVerDetdd::~DlgWdbeVerDetdd() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* DlgWdbeVerDetdd::getNewDpchEng(
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

void DlgWdbeVerDetdd::refreshIfi(
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

void DlgWdbeVerDetdd::refreshImp(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShrImp oldStatshrimp(statshrimp);
	ContInfImp oldContinfimp(continfimp);

	// IP refreshImp --- RBEGIN
	// continfimp
	continfimp.TxtPrg = getSquawk(dbswdbe);

	// statshrimp
	statshrimp.ButRunActive = evalImpButRunActive(dbswdbe);
	statshrimp.ButStoActive = evalImpButStoActive(dbswdbe);

	// IP refreshImp --- REND
	if (statshrimp.diff(&oldStatshrimp).size() != 0) insert(moditems, DpchEngData::STATSHRIMP);
	if (continfimp.diff(&oldContinfimp).size() != 0) insert(moditems, DpchEngData::CONTINFIMP);
};

void DlgWdbeVerDetdd::refreshPpr(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShrPpr oldStatshrppr(statshrppr);
	ContInfPpr oldContinfppr(continfppr);

	// IP refreshPpr --- RBEGIN
	// continfppr
	continfppr.TxtPrg = getSquawk(dbswdbe);

	// statshrppr
	statshrppr.ButRunActive = evalPprButRunActive(dbswdbe);
	statshrppr.ButStoActive = evalPprButStoActive(dbswdbe);

	// IP refreshPpr --- REND
	if (statshrppr.diff(&oldStatshrppr).size() != 0) insert(moditems, DpchEngData::STATSHRPPR);
	if (continfppr.diff(&oldContinfppr).size() != 0) insert(moditems, DpchEngData::CONTINFPPR);
};

void DlgWdbeVerDetdd::refreshLfi(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContInfLfi oldContinflfi(continflfi);
	StatShrLfi oldStatshrlfi(statshrlfi);

	// IP refreshLfi --- RBEGIN
	// statshrlfi
	statshrlfi.DldActive = evalLfiDldActive(dbswdbe);

	// continflfi
	continflfi.Dld = "log.txt";

	// IP refreshLfi --- REND
	if (continflfi.diff(&oldContinflfi).size() != 0) insert(moditems, DpchEngData::CONTINFLFI);
	if (statshrlfi.diff(&oldStatshrlfi).size() != 0) insert(moditems, DpchEngData::STATSHRLFI);
};

void DlgWdbeVerDetdd::refresh(
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
	statshr.ButDneActive = evalButDneActive(dbswdbe);

	// contiac
	contiac.numFDse = ixVDit;

	// continf
	continf.numFSge = ixVSge;

	// IP refresh --- END
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	refreshIfi(dbswdbe, moditems);
	refreshImp(dbswdbe, moditems);
	refreshPpr(dbswdbe, moditems);
	refreshLfi(dbswdbe, moditems);

	muteRefresh = false;
};

void DlgWdbeVerDetdd::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEVERDETDDDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswdbe, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEVERDETDDDO) {
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
		else if (ixVSge == VecVSge::FAIL) req->filename = handleDownloadInSgeFail(dbswdbe);

	} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::DPCHRET) {
		if (req->dpchret->ixOpVOpres == VecOpVOpres::PROGRESS) {
			// IP handleRequest.opprogress --- INSERT
		} else {
			if (req->dpchret->ixWdbeVDpch == VecWdbeVDpch::DPCHRETWDBE) {
				handleDpchRetWdbe(dbswdbe, (DpchRetWdbe*) (req->dpchret));
			} else if (req->dpchret->ixWdbeVDpch == VecWdbeVDpch::DPCHRETWDBEMODDETWIRING) {
				handleDpchRetWdbeModdetWiring(dbswdbe, (DpchRetWdbeModdetWiring*) (req->dpchret));
			};

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
		if (ixVSge == VecVSge::IMPIDLE) handleTimerInSgeImpidle(dbswdbe, req->sref);
		else if (ixVSge == VecVSge::PRSIDLE) handleTimerInSgePrsidle(dbswdbe, req->sref);
		else if ((req->sref == "mon") && (ixVSge == VecVSge::IMPORT)) handleTimerWithSrefMonInSgeImport(dbswdbe);
		else if ((req->sref == "mon") && (ixVSge == VecVSge::POSTPRC3)) handleTimerWithSrefMonInSgePostprc3(dbswdbe);
		else if ((req->sref == "mon") && (ixVSge == VecVSge::POSTPRC2)) handleTimerWithSrefMonInSgePostprc2(dbswdbe);
		else if ((req->sref == "mon") && (ixVSge == VecVSge::POSTPRC1)) handleTimerWithSrefMonInSgePostprc1(dbswdbe);
	};
};

void DlgWdbeVerDetdd::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWdbeVerDetdd::handleDpchAppDataContiac(
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

void DlgWdbeVerDetdd::handleDpchAppDoButDneClick(
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

void DlgWdbeVerDetdd::handleDpchAppDoImpButRunClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoImpButRunClick --- BEGIN
	if (statshrimp.ButRunActive) {
		changeStage(dbswdbe, VecVSge::IMPIDLE, dpcheng);
	};
	// IP handleDpchAppDoImpButRunClick --- END
};

void DlgWdbeVerDetdd::handleDpchAppDoImpButStoClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoImpButStoClick --- INSERT
};

void DlgWdbeVerDetdd::handleDpchAppDoPprButRunClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoPprButRunClick --- BEGIN
	if (statshrppr.ButRunActive) {
		changeStage(dbswdbe, VecVSge::POSTPRC1, dpcheng);
	};
	// IP handleDpchAppDoPprButRunClick --- END
};

void DlgWdbeVerDetdd::handleDpchAppDoPprButStoClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoPprButStoClick --- INSERT
};

void DlgWdbeVerDetdd::handleDpchAppWdbeAlert(
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
	} else if (ixVSge == VecVSge::ALRWER) {
		changeStage(dbswdbe, nextIxVSgeSuccess);
	};
	// IP handleDpchAppWdbeAlert --- IEND
};

void DlgWdbeVerDetdd::handleDpchRetWdbe(
			DbsWdbe* dbswdbe
			, DpchRetWdbe* dpchret
		) {
	// IP handleDpchRetWdbe --- INSERT
};

void DlgWdbeVerDetdd::handleDpchRetWdbeModdetWiring(
			DbsWdbe* dbswdbe
			, DpchRetWdbeModdetWiring* dpchret
		) {
	// IP handleDpchRetWdbeModdetWiring --- IBEGIN
	WdbeMModule* mdl = NULL;

	string logheader;

	if (dpchret->logfile != "") {
		auto it = orefsToRefs.find(dpchret->oref);

		if (it != orefsToRefs.end()) {
			if (dbswdbe->tblwdbemmodule->loadRecByRef(it->second, &mdl)) {
				logheader = "### unit " + StubWdbe::getStubUntStd(dbswdbe, mdl->hkUref) + ", module " + StrMod::replaceChar(StubWdbe::getStubMdlHsref(dbswdbe, mdl->ref), ';', '-') + " ###";
				delete mdl;
			};
		};

		logfiles.push_back(dpchret->logfile);
		logheaders.push_back(logheader);
	};
	// IP handleDpchRetWdbeModdetWiring --- IEND
};

void DlgWdbeVerDetdd::handleUploadInSgeIdle(
			DbsWdbe* dbswdbe
			, const string& filename
		) {
	infilename = filename; // IP handleUploadInSgeIdle --- ILINE
	changeStage(dbswdbe, VecVSge::PRSIDLE);
};

string DlgWdbeVerDetdd::handleDownloadInSgeDone(
			DbsWdbe* dbswdbe
		) {
	return(""); // IP handleDownloadInSgeDone --- LINE
};

string DlgWdbeVerDetdd::handleDownloadInSgeFail(
			DbsWdbe* dbswdbe
		) {
	return(xchg->tmppath + "/" + logfile); // IP handleDownloadInSgeFail --- RLINE
};

void DlgWdbeVerDetdd::handleTimerInSgeImpidle(
			DbsWdbe* dbswdbe
			, const string& sref
		) {
	changeStage(dbswdbe, nextIxVSgeSuccess);
};

void DlgWdbeVerDetdd::handleTimerInSgePrsidle(
			DbsWdbe* dbswdbe
			, const string& sref
		) {
	changeStage(dbswdbe, nextIxVSgeSuccess);
};

void DlgWdbeVerDetdd::handleTimerWithSrefMonInSgeImport(
			DbsWdbe* dbswdbe
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	refreshWithDpchEng(dbswdbe); // IP handleTimerWithSrefMonInSgeImport --- ILINE
};

void DlgWdbeVerDetdd::handleTimerWithSrefMonInSgePostprc3(
			DbsWdbe* dbswdbe
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	refreshWithDpchEng(dbswdbe); // IP handleTimerWithSrefMonInSgePostprc3 --- ILINE
};

void DlgWdbeVerDetdd::handleTimerWithSrefMonInSgePostprc2(
			DbsWdbe* dbswdbe
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	refreshWithDpchEng(dbswdbe); // IP handleTimerWithSrefMonInSgePostprc2 --- ILINE
};

void DlgWdbeVerDetdd::handleTimerWithSrefMonInSgePostprc1(
			DbsWdbe* dbswdbe
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	refreshWithDpchEng(dbswdbe); // IP handleTimerWithSrefMonInSgePostprc1 --- ILINE
};

void DlgWdbeVerDetdd::changeStage(
			DbsWdbe* dbswdbe
			, uint _ixVSge
			, DpchEngWdbe** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswdbe); break;
				case VecVSge::ALRWER: leaveSgeAlrwer(dbswdbe); break;
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
				case VecVSge::ASMLFI: leaveSgeAsmlfi(dbswdbe); break;
				case VecVSge::POSTPRC3: leaveSgePostprc3(dbswdbe); break;
				case VecVSge::SYNC: leaveSgeSync(dbswdbe); break;
				case VecVSge::FAIL: leaveSgeFail(dbswdbe); break;
				case VecVSge::DONE: leaveSgeDone(dbswdbe); break;
			};

			setStage(dbswdbe, _ixVSge);
			reenter = false;
			refreshWithDpchEng(dbswdbe, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswdbe, reenter); break;
			case VecVSge::ALRWER: _ixVSge = enterSgeAlrwer(dbswdbe, reenter); break;
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
			case VecVSge::ASMLFI: _ixVSge = enterSgeAsmlfi(dbswdbe, reenter); break;
			case VecVSge::POSTPRC3: _ixVSge = enterSgePostprc3(dbswdbe, reenter); break;
			case VecVSge::SYNC: _ixVSge = enterSgeSync(dbswdbe, reenter); break;
			case VecVSge::FAIL: _ixVSge = enterSgeFail(dbswdbe, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswdbe, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWdbeVerDetdd::getSquawk(
			DbsWdbe* dbswdbe
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::PARSE) || (ixVSge == VecVSge::ALRWDBEPER) || (ixVSge == VecVSge::PRSDONE) || (ixVSge == VecVSge::IMPORT) || (ixVSge == VecVSge::ALRWDBEIER) || (ixVSge == VecVSge::IMPDONE) || (ixVSge == VecVSge::POSTPRC1) || (ixVSge == VecVSge::POSTPRC2) || (ixVSge == VecVSge::POSTPRC3) || (ixVSge == VecVSge::SYNC) ) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing detailed device description";
			else if (ixVSge == VecVSge::ALRWDBEPER) retval = "parse error";
			else if (ixVSge == VecVSge::PRSDONE) retval = "detailed device description parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing detailed device description (" + to_string(iex->impcnt) + " records added)";
			else if (ixVSge == VecVSge::ALRWDBEIER) retval = "import error";
			else if (ixVSge == VecVSge::IMPDONE) retval = "import done";
			else if (ixVSge == VecVSge::POSTPRC1) retval = "applying module modifications top-down (" + to_string(opNSuccess + opNFailure) + "/" + to_string(opN) + " operations completed, last: " + getOpsqkLast() + ")";
			else if (ixVSge == VecVSge::POSTPRC2) retval = "complementing inter-module wiring bottom-up (" + to_string(opNSuccess + opNFailure) + "/" + to_string(opN) + " operations completed, last: " + getOpsqkLast() + ")";
			else if (ixVSge == VecVSge::POSTPRC3) retval = "deriving detailed features (" + to_string(opNSuccess + opNFailure) + "/" + to_string(opN) + " operations completed, last: " + getOpsqkLast() + ")";
			else if (ixVSge == VecVSge::SYNC) retval = "synchronizing build-ready version with licensing server";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

uint DlgWdbeVerDetdd::enterSgeIdle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWdbeVerDetdd::leaveSgeIdle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWdbeVerDetdd::enterSgeAlrwer(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::ALRWER;
	nextIxVSgeSuccess = VecVSge::IDLE;

	ContInfWdbeAlert continf;
	// IP enterSgeAlrwer --- RBEGIN
	continf.TxtCpt = VecWdbeVTag::getTitle(VecWdbeVTag::ERROR, ixWdbeVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		continf.TxtMsg1 = "Wiring error. View log file for details.";
	};

	feedFMcbAlert.clear();

	VecWdbeVTag::appendToFeed(VecWdbeVTag::OK, ixWdbeVLocale, feedFMcbAlert);

	nextIxVSgeSuccess = VecVSge::FAIL;
	// IP enterSgeAlrwer --- REND
	xchg->submitDpch(new DpchEngWdbeAlert(jref, &continf, &feedFMcbAlert, {DpchEngWdbeAlert::ALL}));

	return retval;
};

void DlgWdbeVerDetdd::leaveSgeAlrwer(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAlrwer --- INSERT
};

uint DlgWdbeVerDetdd::enterSgePrsidle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::PRSIDLE;
	nextIxVSgeSuccess = VecVSge::PARSE;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgePrsidle --- INSERT

	return retval;
};

void DlgWdbeVerDetdd::leaveSgePrsidle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgePrsidle --- INSERT
};

uint DlgWdbeVerDetdd::enterSgeParse(
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

	ifitxt = (s.find("IexWdbeDdd") == 0);
	ifixml = (s.find("<?xml") == 0);		

	delete[] buf;
	ififile.close();

	// parse file accordingly
	if (ifitxt) {
		rectfile = Tmp::newfile(xchg->tmppath, "txt");
		iex->parseFromFile(dbswdbe, infilename, false, xchg->tmppath + "/" + rectfile);
		infilename = xchg->tmppath + "/" + rectfile;

	} else if (ifixml) iex->parseFromFile(dbswdbe, infilename, true, "");

	if (iex->ixVSge != JobWdbeIexDdd::VecVSge::PRSDONE) {
		if (reqCmd) {
			if (iex->ixVSge == JobWdbeIexDdd::VecVSge::PRSERR) cout << "\t" << iex->getSquawk(dbswdbe) << endl;
			else cout << "\tneither text-based nor XML file format recognized" << endl;

			retval = VecVSge::IDLE;

		} else {
			retval = nextIxVSgeFailure;
		};
	};
	// IP enterSgeParse --- IEND

	return retval;
};

void DlgWdbeVerDetdd::leaveSgeParse(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeParse --- INSERT
};

uint DlgWdbeVerDetdd::enterSgeAlrwdbeper(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::ALRWDBEPER;
	nextIxVSgeSuccess = VecVSge::IDLE;

	// IP enterSgeAlrwdbeper --- RBEGIN
	ContInfWdbeAlert continf;

	continf.TxtCpt = VecWdbeVTag::getTitle(VecWdbeVTag::ERROR, ixWdbeVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (iex->ixVSge == JobWdbeIexDdd::VecVSge::PRSERR) continf.TxtMsg1 = iex->getSquawk(dbswdbe);
	else continf.TxtMsg1 = "neither text-based nor XML file format recognized";

	feedFMcbAlert.clear();

	VecWdbeVTag::appendToFeed(VecWdbeVTag::OK, ixWdbeVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();

	xchg->submitDpch(new DpchEngWdbeAlert(jref, &continf, &feedFMcbAlert, {DpchEngWdbeAlert::ALL}));
	// IP enterSgeAlrwdbeper --- REND

	return retval;
};

void DlgWdbeVerDetdd::leaveSgeAlrwdbeper(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAlrwdbeper --- INSERT
};

uint DlgWdbeVerDetdd::enterSgePrsdone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::PRSDONE;

	// IP enterSgePrsdone --- INSERT

	return retval;
};

void DlgWdbeVerDetdd::leaveSgePrsdone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgePrsdone --- INSERT
};

uint DlgWdbeVerDetdd::enterSgeImpidle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IMPIDLE;
	nextIxVSgeSuccess = VecVSge::IMPORT;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgeImpidle --- INSERT

	return retval;
};

void DlgWdbeVerDetdd::leaveSgeImpidle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeImpidle --- INSERT
};

uint DlgWdbeVerDetdd::enterSgeImport(
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

	if (iex->ixVSge == JobWdbeIexDdd::VecVSge::IMPERR) retval = nextIxVSgeFailure;
	// IP enterSgeImport --- IEND

	return retval;
};

void DlgWdbeVerDetdd::leaveSgeImport(
			DbsWdbe* dbswdbe
		) {
	invalidateWakeups();
	// IP leaveSgeImport --- INSERT
};

uint DlgWdbeVerDetdd::enterSgeAlrwdbeier(
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

void DlgWdbeVerDetdd::leaveSgeAlrwdbeier(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAlrwdbeier --- INSERT
};

uint DlgWdbeVerDetdd::enterSgeImpdone(
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
		Filename = "IexWdbeDdd_" + StrMod::lc(Prjshort) + ".txt";
		srefKMimetype = "txt";
	} else if (ifixml) {
		Filename = "IexWdbeDdd_" + StrMod::lc(Prjshort) + ".xml";
		srefKMimetype = "xml";
	};

	Acv::addfile(dbswdbe, xchg->acvpath, infilename, xchg->getRefPreset(VecWdbeVPreset::PREWDBEGROUP, jref), xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref), VecWdbeVMFileRefTbl::VER, refWdbeMVersion, "mod", Filename, srefKMimetype, "");

	// IP enterSgeImpdone --- IEND

	return retval;
};

void DlgWdbeVerDetdd::leaveSgeImpdone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeImpdone --- INSERT
};

uint DlgWdbeVerDetdd::enterSgePostprc1(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::POSTPRC1;
	nextIxVSgeSuccess = VecVSge::POSTPRC1;

	clearInvs();

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);

	// IP enterSgePostprc1 --- IBEGIN

	// modules top-down order, respecting unit hierarchy bottom-up

	ubigint ref;

	ubigint refWdbeMVersion;
	string Prjshort;

	ListWdbeMUnit unts;
	WdbeMUnit* unt = NULL;

	map<ubigint,string> srefsMtpCustops;

	WdbeMModule* mdl = NULL;

	unsigned int lvl;

	string Untsref;
	bool mcuNotFpga;

	bool typmod, tplmod;

	refWdbeMVersion = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref);
	Prjshort = Wdbe::getPrjshort(dbswdbe, refWdbeMVersion);

	if (mdls.nodes.size() == 0) {
		dbswdbe->tblwdbemunit->loadRstBySQL("SELECT * FROM TblWdbeMUnit WHERE refIxVTbl = " + to_string(VecWdbeVMUnitRefTbl::VER) + " AND refUref = " + to_string(refWdbeMVersion), false, unts);
		for (unsigned int i = 0; i < unts.nodes.size(); i++) {
			unt = unts.nodes[i];

			UntsrefsUnts[unt->ref] = StrMod::cap(unt->sref);
			mcuNotFpgasUnts[unt->ref] = (unt->ixVBasetype == VecWdbeVMUnitBasetype::MCU);
		};

		Wdbe::levelMdls(dbswdbe, refWdbeMVersion, mdls, lvlsMdls, false, true, true);
		
		//cout << "DlgWdbeVerDetsd::enterSgePostprc1() order is:" << endl;
		//Wdbe::showLvlsMdls(dbswdbe, mdls, lvlsMdls);
	};

	// determine modules due for op invocation
	Wdbe::getSrefsMtpCustops(dbswdbe, srefsMtpCustops, VecWdbeVKeylist::KLSTKWDBEMTPMODDETCUSTOP);

	for (unsigned int i = 0; i < mdls.nodes.size(); i++) {
		mdl = mdls.nodes[i];
		lvl = lvlsMdls[i];

		// invs complete if at least one added on superior level
		if (opN > 0) if (i != 0) if (lvl != lvlsMdls[i-1]) break;

		// check for template-based modification
		tplmod = false;

		if (refsTplmod.find(mdl->ref) == refsTplmod.end()) {
			auto it = srefsMtpCustops.find(mdl->tplRefWdbeMModule);

			if (it != srefsMtpCustops.end()) {
				addInv(new DpchInvWdbeMtpModdet(0, it->second, 0, mdl->ref));
				tplmod = true;
			};
		};

		// check for type-based modification
		typmod = false;

		if (!tplmod) {
			if (refsTypmod.find(mdl->ref) == refsTypmod.end()) {
				if (mdl->ixVBasetype == VecWdbeVMModuleBasetype::EHOSTIF) {
					auto it = mcuNotFpgasUnts.find(mdl->hkUref);
					if (it != mcuNotFpgasUnts.end()) mcuNotFpga = it->second;
					else mcuNotFpga = false;

					addInv(new DpchInvWdbeModdetEhostif(0, 0, mdl->ref, mcuNotFpga));
					typmod = true;

				} else if (mdl->ixVBasetype == VecWdbeVMModuleBasetype::CMDBUS) {
					auto it = mcuNotFpgasUnts.find(mdl->hkUref);
					if (it != mcuNotFpgasUnts.end()) mcuNotFpga = it->second;
					else mcuNotFpga = false;

					addInv(new DpchInvWdbeModdetCmdbus(0, 0, mdl->ref, mcuNotFpga));
					typmod = true;

				} else if (mdl->ixVBasetype == VecWdbeVMModuleBasetype::IMBUF) {
					addInv(new DpchInvWdbeModdetImbuf(0, 0, mdl->ref));
					typmod = true;

				} else if ((mdl->ixVBasetype == VecWdbeVMModuleBasetype::CTR) || (mdl->ixVBasetype == VecWdbeVMModuleBasetype::FWDCTR)) {
					auto it = UntsrefsUnts.find(mdl->hkUref);
					if (it != UntsrefsUnts.end()) Untsref = it->second;
					else Untsref = "";

					addInv(new DpchInvWdbeModdetCtrFwdctr(0, 0, mdl->ref, Prjshort, Untsref));
					typmod = true;

				} else if (mdl->ixVBasetype == VecWdbeVMModuleBasetype::ECTR) {
					addInv(new DpchInvWdbeModdetEctr(0, 0, mdl->ref, Prjshort, Untsref));
					typmod = true;
				};
			};
		};

		if (tplmod) refsTplmod.insert(mdl->ref);
		if (typmod) refsTypmod.insert(mdl->ref);
	};

	// IP enterSgePostprc1 --- IEND

	submitInvs(dbswdbe, VecVSge::POSTPRC2, retval);
	return retval;
};

void DlgWdbeVerDetdd::leaveSgePostprc1(
			DbsWdbe* dbswdbe
		) {
	invalidateWakeups();
	// IP leaveSgePostprc1 --- IBEGIN
	mdls.clear();
	lvlsMdls.clear();

	refsTypmod.clear();
	refsTplmod.clear();
	// IP leaveSgePostprc1 --- IEND
};

uint DlgWdbeVerDetdd::enterSgePostprc2(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::POSTPRC2;
	nextIxVSgeSuccess = VecVSge::POSTPRC2;
	nextIxVSgeFailure = VecVSge::ASMLFI;

	clearInvs();

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);

	// IP enterSgePostprc2 --- IBEGIN

	// modules bottom-up order, not respecting unit hierarchy ; only LVDS primitives may be added in the process

	ubigint refWdbeMVersion = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref);

	WdbeMModule* mdl = NULL;

	DpchInvWdbe* dpchinv = NULL;

	unsigned int lvl;

	orefsToRefs.clear();

	logfiles.clear();
	logheaders.clear();

	if (mdls.nodes.size() == 0) {
		Wdbe::levelMdls(dbswdbe, refWdbeMVersion, mdls, lvlsMdls, true);

		//cout << "DlgWdbeVerDetsd::enterSgePostprc2() order is:" << endl;
		//Wdbe::showLvlsMdls(dbswdbe, mdls, lvlsMdls);
	};

	// determine modules due for op invocation
	for (unsigned int i = 0; i < mdls.nodes.size(); i++) {
		mdl = mdls.nodes[i];
		lvl = lvlsMdls[i];

		// invs complete if at least one added on inferior level
		if (opN > 0) if (i != 0) if (lvl != lvlsMdls[i-1]) break;

		// check for modification
		if (refsMod.find(mdl->ref) == refsMod.end()) {
			dpchinv = new DpchInvWdbeModdetWiring(0, 0, mdl->ref);
			addInv(dpchinv);
			orefsToRefs[dpchinv->oref] = mdl->ref;

			refsMod.insert(mdl->ref);
		};
	};

	// IP enterSgePostprc2 --- IEND

	submitInvs(dbswdbe, VecVSge::POSTPRC3, retval);
	return retval;
};

void DlgWdbeVerDetdd::leaveSgePostprc2(
			DbsWdbe* dbswdbe
		) {
	invalidateWakeups();
	// IP leaveSgePostprc2 --- IBEGIN
	mdls.clear();
	lvlsMdls.clear();

	refsMod.clear();
	// IP leaveSgePostprc2 --- IEND
};

uint DlgWdbeVerDetdd::enterSgeAsmlfi(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::ASMLFI;
	nextIxVSgeSuccess = VecVSge::ALRWER;

	clearInvs();

	// IP enterSgeAsmlfi --- IBEGIN
	logfile = Tmp::newfile(xchg->tmppath, "txt");

	addInv(new DpchInvWdbePrcfileConcat(0, 0, logfiles, logheaders, logfile));
	// IP enterSgeAsmlfi --- IEND

	submitInvs(dbswdbe, retval, retval);
	return retval;
};

void DlgWdbeVerDetdd::leaveSgeAsmlfi(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAsmlfi --- INSERT
};

uint DlgWdbeVerDetdd::enterSgePostprc3(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::POSTPRC3;
	nextIxVSgeSuccess = VecVSge::SYNC;

	clearInvs();

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);

	// IP enterSgePostprc3 --- IBEGIN

	vector<ubigint> refs;

	ubigint refWdbeMVersion = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref);

	dbswdbe->loadRefsBySQL("SELECT ref FROM TblWdbeMUnit WHERE refIxVTbl = " + to_string(VecWdbeVMUnitRefTbl::VER) + " AND refUref = " + to_string(refWdbeMVersion), false, refs);
	for (unsigned int i = 0; i < refs.size(); i++) addInv(new DpchInvWdbeModdetUnt(0, 0, refs[i]));

	// IP enterSgePostprc3 --- IEND

	submitInvs(dbswdbe, retval, retval);
	return retval;
};

void DlgWdbeVerDetdd::leaveSgePostprc3(
			DbsWdbe* dbswdbe
		) {
	invalidateWakeups();
	// IP leaveSgePostprc3 --- IBEGIN
	WdbeMVersion* ver = NULL;

	if (dbswdbe->tblwdbemversion->loadRecByRef(xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref), &ver)) {
		Wdbe::updateVerste(dbswdbe, ver->ref, VecWdbeVMVersionState::READY);

		// make project's current version
		dbswdbe->executeQuery("UPDATE TblWdbeMProject SET refWdbeMVersion = " + to_string(ver->ref) + " WHERE ref = " + to_string(ver->prjRefWdbeMProject));

		xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBEPRJMOD, jref);
		xchg->triggerRefCall(dbswdbe, VecWdbeVCall::CALLWDBEVERMOD_PRJEQ, jref, ver->prjRefWdbeMProject);

		delete ver;
	};
	// IP leaveSgePostprc3 --- IEND
};

uint DlgWdbeVerDetdd::enterSgeSync(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	// IP enterSgeSync --- IBEGIN
	WdbeMVersion* ver = NULL;

	if (dbswdbe->tblwdbemversion->loadRecByRef(xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref), &ver)) {
		license->syncVer(dbswdbe, ver->prjRefWdbeMProject, ver->ref);
		delete ver;
	};
	// IP enterSgeSync --- IEND

	return retval;
};

void DlgWdbeVerDetdd::leaveSgeSync(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeSync --- INSERT
};

uint DlgWdbeVerDetdd::enterSgeFail(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::FAIL;

	// IP enterSgeFail --- INSERT

	return retval;
};

void DlgWdbeVerDetdd::leaveSgeFail(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeFail --- INSERT
};

uint DlgWdbeVerDetdd::enterSgeDone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void DlgWdbeVerDetdd::leaveSgeDone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeDone --- INSERT
};
