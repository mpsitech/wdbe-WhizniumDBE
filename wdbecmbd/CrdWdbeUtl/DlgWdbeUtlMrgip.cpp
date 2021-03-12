/**
	* \file DlgWdbeUtlMrgip.cpp
	* job handler for job DlgWdbeUtlMrgip (implementation)
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

#include "DlgWdbeUtlMrgip.h"

#include "DlgWdbeUtlMrgip_blks.cpp"
#include "DlgWdbeUtlMrgip_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWdbeUtlMrgip
 ******************************************************************************/

DlgWdbeUtlMrgip::DlgWdbeUtlMrgip(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::DLGWDBEUTLMRGIP, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFDse.tag = "FeedFDse";
	VecVDit::fillFeed(ixWdbeVLocale, feedFDse);
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	// IP constructor.cust1 --- INSERT

	ixVDit = VecVDit::SRC;

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswdbe, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgWdbeUtlMrgip::~DlgWdbeUtlMrgip() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* DlgWdbeUtlMrgip::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &continflfi, &continfmrg, &continfres, &feedFDse, &feedFSge, &statshr, &statshrlfi, &statshrmrg, &statshrres, &statshrsrc, &statshrtrg, items);
	};

	return dpcheng;
};

void DlgWdbeUtlMrgip::refreshSrc(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShrSrc oldStatshrsrc(statshrsrc);

	// IP refreshSrc --- BEGIN
	// statshrsrc
	statshrsrc.UldActive = evalSrcUldActive(dbswdbe);

	// IP refreshSrc --- END
	if (statshrsrc.diff(&oldStatshrsrc).size() != 0) insert(moditems, DpchEngData::STATSHRSRC);
};

void DlgWdbeUtlMrgip::refreshTrg(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShrTrg oldStatshrtrg(statshrtrg);

	// IP refreshTrg --- BEGIN
	// statshrtrg
	statshrtrg.UldActive = evalTrgUldActive(dbswdbe);

	// IP refreshTrg --- END
	if (statshrtrg.diff(&oldStatshrtrg).size() != 0) insert(moditems, DpchEngData::STATSHRTRG);
};

void DlgWdbeUtlMrgip::refreshMrg(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContInfMrg oldContinfmrg(continfmrg);
	StatShrMrg oldStatshrmrg(statshrmrg);

	// IP refreshMrg --- RBEGIN
	// continfmrg
	continfmrg.TxtPrg = getSquawk(dbswdbe);

	// statshrmrg
	statshrmrg.ButRunActive = evalMrgButRunActive(dbswdbe);
	statshrmrg.ButStoActive = evalMrgButStoActive(dbswdbe);

	// IP refreshMrg --- REND
	if (continfmrg.diff(&oldContinfmrg).size() != 0) insert(moditems, DpchEngData::CONTINFMRG);
	if (statshrmrg.diff(&oldStatshrmrg).size() != 0) insert(moditems, DpchEngData::STATSHRMRG);
};

void DlgWdbeUtlMrgip::refreshLfi(
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

void DlgWdbeUtlMrgip::refreshRes(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContInfRes oldContinfres(continfres);
	StatShrRes oldStatshrres(statshrres);

	// IP refreshRes --- RBEGIN
	// statshrres
	statshrres.DldActive = evalResDldActive(dbswdbe);

	// continfres
	if (outfolder == "") continfres.Dld = "merged";
	else continfres.Dld = "merged.tgz";

	// IP refreshRes --- REND
	if (continfres.diff(&oldContinfres).size() != 0) insert(moditems, DpchEngData::CONTINFRES);
	if (statshrres.diff(&oldStatshrres).size() != 0) insert(moditems, DpchEngData::STATSHRRES);
};

void DlgWdbeUtlMrgip::refresh(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	StatShr oldStatshr(statshr);
	ContInf oldContinf(continf);
	ContIac oldContiac(contiac);

	// IP refresh --- BEGIN
	// statshr
	statshr.ButDneActive = evalButDneActive(dbswdbe);

	// continf
	continf.numFSge = ixVSge;

	// contiac
	contiac.numFDse = ixVDit;

	// IP refresh --- END
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshSrc(dbswdbe, moditems);
	refreshTrg(dbswdbe, moditems);
	refreshMrg(dbswdbe, moditems);
	refreshLfi(dbswdbe, moditems);
	refreshRes(dbswdbe, moditems);

	muteRefresh = false;
};

void DlgWdbeUtlMrgip::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEUTLMRGIPDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswdbe, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEUTLMRGIPDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbswdbe, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoMrg != 0) {
				if (dpchappdo->ixVDoMrg == VecVDoMrg::BUTRUNCLICK) {
					handleDpchAppDoMrgButRunClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDoMrg == VecVDoMrg::BUTSTOCLICK) {
					handleDpchAppDoMrgButStoClick(dbswdbe, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEALERT) {
			handleDpchAppWdbeAlert(dbswdbe, (DpchAppWdbeAlert*) (req->dpchapp), &(req->dpcheng));

		};

	} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::UPLOAD) {
		if (ixVSge == VecVSge::SULDONE) handleUploadInSgeSuldone(dbswdbe, req->filename);
		else if (ixVSge == VecVSge::SUPDONE) handleUploadInSgeSupdone(dbswdbe, req->filename);
		else if (ixVSge == VecVSge::IDLE) handleUploadInSgeIdle(dbswdbe, req->filename);

	} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::DOWNLOAD) {
		if (ixVSge == VecVSge::DONE) req->filename = handleDownloadInSgeDone(dbswdbe);
		else if (ixVSge == VecVSge::FAIL) req->filename = handleDownloadInSgeFail(dbswdbe);

	} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::DPCHRET) {
		if (req->dpchret->ixOpVOpres == VecOpVOpres::PROGRESS) {
			// IP handleRequest.opprogress --- INSERT
		} else {
			if (req->dpchret->ixWdbeVDpch == VecWdbeVDpch::DPCHRETWDBEPRCTREEMERGE) {
				handleDpchRetWdbePrctreeMerge(dbswdbe, (DpchRetWdbePrctreeMerge*) (req->dpchret));
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
		if (ixVSge == VecVSge::SUPIDLE) handleTimerInSgeSupidle(dbswdbe, req->sref);
		else if (ixVSge == VecVSge::TUPIDLE) handleTimerInSgeTupidle(dbswdbe, req->sref);
	};
};

void DlgWdbeUtlMrgip::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWdbeUtlMrgip::handleDpchAppDataContiac(
			DbsWdbe* dbswdbe
			, ContIac* _contiac
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFDSE)) {
		if ((_contiac->numFDse >= VecVDit::SRC) && (_contiac->numFDse <= VecVDit::RES)) ixVDit = _contiac->numFDse;
		refresh(dbswdbe, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgWdbeUtlMrgip::handleDpchAppDoButDneClick(
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

void DlgWdbeUtlMrgip::handleDpchAppDoMrgButRunClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoMrgButRunClick --- BEGIN
	if (statshrmrg.ButRunActive) {
		changeStage(dbswdbe, VecVSge::MERGE, dpcheng);
	};
	// IP handleDpchAppDoMrgButRunClick --- END
};

void DlgWdbeUtlMrgip::handleDpchAppDoMrgButStoClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoMrgButStoClick --- INSERT
};

void DlgWdbeUtlMrgip::handleDpchAppWdbeAlert(
			DbsWdbe* dbswdbe
			, DpchAppWdbeAlert* dpchappwdbealert
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppWdbeAlert --- IBEGIN
	if (ixVSge == VecVSge::ALRMER) {
		changeStage(dbswdbe, nextIxVSgeSuccess);
	};
	// IP handleDpchAppWdbeAlert --- IEND
};

void DlgWdbeUtlMrgip::handleDpchRetWdbePrctreeMerge(
			DbsWdbe* dbswdbe
			, DpchRetWdbePrctreeMerge* dpchret
		) {
	logfile = dpchret->logfile; // IP handleDpchRetWdbePrctreeMerge --- ILINE
};

void DlgWdbeUtlMrgip::handleUploadInSgeSuldone(
			DbsWdbe* dbswdbe
			, const string& filename
		) {
	outfilename = filename; // IP handleUploadInSgeSuldone --- ILINE
	changeStage(dbswdbe, VecVSge::TUPIDLE);
};

void DlgWdbeUtlMrgip::handleUploadInSgeSupdone(
			DbsWdbe* dbswdbe
			, const string& filename
		) {
	outfilename = filename; // IP handleUploadInSgeSupdone --- ILINE
	changeStage(dbswdbe, VecVSge::TUPIDLE);
};

void DlgWdbeUtlMrgip::handleUploadInSgeIdle(
			DbsWdbe* dbswdbe
			, const string& filename
		) {
	infilename = filename; // IP handleUploadInSgeIdle --- ILINE
	changeStage(dbswdbe, VecVSge::SUPIDLE);
};

string DlgWdbeUtlMrgip::handleDownloadInSgeDone(
			DbsWdbe* dbswdbe
		) {
	return(xchg->tmppath + "/" + outfile); // IP handleDownloadInSgeDone --- RLINE
};

string DlgWdbeUtlMrgip::handleDownloadInSgeFail(
			DbsWdbe* dbswdbe
		) {
	return(xchg->tmppath + "/" + logfile); // IP handleDownloadInSgeFail --- RLINE
};

void DlgWdbeUtlMrgip::handleTimerInSgeSupidle(
			DbsWdbe* dbswdbe
			, const string& sref
		) {
	changeStage(dbswdbe, nextIxVSgeSuccess);
};

void DlgWdbeUtlMrgip::handleTimerInSgeTupidle(
			DbsWdbe* dbswdbe
			, const string& sref
		) {
	changeStage(dbswdbe, nextIxVSgeSuccess);
};

void DlgWdbeUtlMrgip::changeStage(
			DbsWdbe* dbswdbe
			, uint _ixVSge
			, DpchEngWdbe** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswdbe); break;
				case VecVSge::ALRMER: leaveSgeAlrmer(dbswdbe); break;
				case VecVSge::SUPIDLE: leaveSgeSupidle(dbswdbe); break;
				case VecVSge::SRCUNPACK: leaveSgeSrcunpack(dbswdbe); break;
				case VecVSge::SUPDONE: leaveSgeSupdone(dbswdbe); break;
				case VecVSge::SULDONE: leaveSgeSuldone(dbswdbe); break;
				case VecVSge::TUPIDLE: leaveSgeTupidle(dbswdbe); break;
				case VecVSge::TRGUNPACK: leaveSgeTrgunpack(dbswdbe); break;
				case VecVSge::TUPDONE: leaveSgeTupdone(dbswdbe); break;
				case VecVSge::TULDONE: leaveSgeTuldone(dbswdbe); break;
				case VecVSge::MERGE: leaveSgeMerge(dbswdbe); break;
				case VecVSge::PACK: leaveSgePack(dbswdbe); break;
				case VecVSge::FAIL: leaveSgeFail(dbswdbe); break;
				case VecVSge::DONE: leaveSgeDone(dbswdbe); break;
			};

			setStage(dbswdbe, _ixVSge);
			reenter = false;
			refreshWithDpchEng(dbswdbe, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswdbe, reenter); break;
			case VecVSge::ALRMER: _ixVSge = enterSgeAlrmer(dbswdbe, reenter); break;
			case VecVSge::SUPIDLE: _ixVSge = enterSgeSupidle(dbswdbe, reenter); break;
			case VecVSge::SRCUNPACK: _ixVSge = enterSgeSrcunpack(dbswdbe, reenter); break;
			case VecVSge::SUPDONE: _ixVSge = enterSgeSupdone(dbswdbe, reenter); break;
			case VecVSge::SULDONE: _ixVSge = enterSgeSuldone(dbswdbe, reenter); break;
			case VecVSge::TUPIDLE: _ixVSge = enterSgeTupidle(dbswdbe, reenter); break;
			case VecVSge::TRGUNPACK: _ixVSge = enterSgeTrgunpack(dbswdbe, reenter); break;
			case VecVSge::TUPDONE: _ixVSge = enterSgeTupdone(dbswdbe, reenter); break;
			case VecVSge::TULDONE: _ixVSge = enterSgeTuldone(dbswdbe, reenter); break;
			case VecVSge::MERGE: _ixVSge = enterSgeMerge(dbswdbe, reenter); break;
			case VecVSge::PACK: _ixVSge = enterSgePack(dbswdbe, reenter); break;
			case VecVSge::FAIL: _ixVSge = enterSgeFail(dbswdbe, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswdbe, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWdbeUtlMrgip::getSquawk(
			DbsWdbe* dbswdbe
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::SRCUNPACK) || (ixVSge == VecVSge::SUPDONE) || (ixVSge == VecVSge::SULDONE) || (ixVSge == VecVSge::TRGUNPACK) || (ixVSge == VecVSge::TUPDONE) || (ixVSge == VecVSge::TULDONE) || (ixVSge == VecVSge::MERGE) || (ixVSge == VecVSge::PACK) ) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			if (ixVSge == VecVSge::SRCUNPACK) retval = "unpacking source";
			else if (ixVSge == VecVSge::SUPDONE) retval = "source unpacked";
			else if (ixVSge == VecVSge::SULDONE) retval = "source uploaded";
			else if (ixVSge == VecVSge::TRGUNPACK) retval = "unpacking target";
			else if (ixVSge == VecVSge::TUPDONE) retval = "target unpacked";
			else if (ixVSge == VecVSge::TULDONE) retval = "target uploaded";
			else if (ixVSge == VecVSge::MERGE) retval = "merging";
			else if (ixVSge == VecVSge::PACK) retval = "packing result";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint DlgWdbeUtlMrgip::enterSgeIdle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWdbeUtlMrgip::leaveSgeIdle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWdbeUtlMrgip::enterSgeAlrmer(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::ALRMER;
	nextIxVSgeSuccess = VecVSge::IDLE;

	ContInfWdbeAlert continf;
	// IP enterSgeAlrmer --- RBEGIN
	continf.TxtCpt = VecWdbeVTag::getTitle(VecWdbeVTag::ERROR, ixWdbeVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		continf.TxtMsg1 = "Merge error. View log file for details.";
	};

	feedFMcbAlert.clear();

	VecWdbeVTag::appendToFeed(VecWdbeVTag::OK, ixWdbeVLocale, feedFMcbAlert);

	nextIxVSgeSuccess = VecVSge::FAIL;
	// IP enterSgeAlrmer --- REND
	xchg->submitDpch(new DpchEngWdbeAlert(jref, &continf, &feedFMcbAlert, {DpchEngWdbeAlert::ALL}));

	return retval;
};

void DlgWdbeUtlMrgip::leaveSgeAlrmer(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAlrmer --- INSERT
};

uint DlgWdbeUtlMrgip::enterSgeSupidle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::SUPIDLE;
	nextIxVSgeSuccess = VecVSge::SRCUNPACK;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgeSupidle --- INSERT

	return retval;
};

void DlgWdbeUtlMrgip::leaveSgeSupidle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeSupidle --- INSERT
};

uint DlgWdbeUtlMrgip::enterSgeSrcunpack(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::SUPDONE;
	retval = nextIxVSgeSuccess;

	// IP enterSgeSrcunpack --- IBEGIN
	// 1st try: assume .tgz input file archive
	infolder = infilename.substr(infilename.rfind("/")+1);
	infile = infolder + ".tgz";

	Wdbe::run("mv " + infilename + " " + infilename + ".tgz");

	if (!Wdbe::untgz(xchg->tmppath + "/" + infile, xchg->tmppath + "/" + infolder)) {
		// 2nd try: single input file
		infolder = "";
		
		Wdbe::run("mv " + infilename + ".tgz " + infilename);
		infile = infilename.substr(infilename.rfind("/")+1);

		retval = VecVSge::SULDONE;
	};
	// IP enterSgeSrcunpack --- IEND

	return retval;
};

void DlgWdbeUtlMrgip::leaveSgeSrcunpack(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeSrcunpack --- INSERT
};

uint DlgWdbeUtlMrgip::enterSgeSupdone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::SUPDONE;

	// IP enterSgeSupdone --- INSERT

	return retval;
};

void DlgWdbeUtlMrgip::leaveSgeSupdone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeSupdone --- INSERT
};

uint DlgWdbeUtlMrgip::enterSgeSuldone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::SULDONE;

	// IP enterSgeSuldone --- INSERT

	return retval;
};

void DlgWdbeUtlMrgip::leaveSgeSuldone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeSuldone --- INSERT
};

uint DlgWdbeUtlMrgip::enterSgeTupidle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::TUPIDLE;
	nextIxVSgeSuccess = VecVSge::TRGUNPACK;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgeTupidle --- INSERT

	return retval;
};

void DlgWdbeUtlMrgip::leaveSgeTupidle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeTupidle --- INSERT
};

uint DlgWdbeUtlMrgip::enterSgeTrgunpack(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::TUPDONE;
	retval = nextIxVSgeSuccess;

	// IP enterSgeTrgunpack --- IBEGIN
	// .tgz target file archive vs. single target file based on file uploaded previously
	if (infolder.length() > 0) {
		outfolder = outfilename.substr(outfilename.rfind("/")+1);
		outfile = outfolder + ".tgz";

		Wdbe::run("mv " + outfilename + " " + outfilename + ".tgz");
		Wdbe::untgz(xchg->tmppath + "/" + outfile, xchg->tmppath + "/" + outfolder);

	} else {
		outfolder = "";
		outfile = outfilename.substr(outfilename.rfind("/")+1);

		retval = VecVSge::TULDONE;
	};
	// IP enterSgeTrgunpack --- IEND

	return retval;
};

void DlgWdbeUtlMrgip::leaveSgeTrgunpack(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeTrgunpack --- INSERT
};

uint DlgWdbeUtlMrgip::enterSgeTupdone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::TUPDONE;

	// IP enterSgeTupdone --- INSERT

	return retval;
};

void DlgWdbeUtlMrgip::leaveSgeTupdone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeTupdone --- INSERT
};

uint DlgWdbeUtlMrgip::enterSgeTuldone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::TULDONE;

	// IP enterSgeTuldone --- INSERT

	return retval;
};

void DlgWdbeUtlMrgip::leaveSgeTuldone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeTuldone --- INSERT
};

uint DlgWdbeUtlMrgip::enterSgeMerge(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::MERGE;
	nextIxVSgeSuccess = VecVSge::PACK;
	nextIxVSgeFailure = VecVSge::ALRMER;

	clearInvs();

	// IP enterSgeMerge --- IBEGIN

	// invoke WdbePrctreeMerge

	if (infolder == "") {
		// single file
		addInv(new DpchInvWdbePrctreeMerge(0, 0, infile, "", outfile, "", false, false));
	} else {
		// multiple files
		addInv(new DpchInvWdbePrctreeMerge(0, 0, "", infolder, "", outfolder, false, false));
	};

	// IP enterSgeMerge --- IEND

	submitInvs(dbswdbe, retval, retval);
	return retval;
};

void DlgWdbeUtlMrgip::leaveSgeMerge(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeMerge --- INSERT
};

uint DlgWdbeUtlMrgip::enterSgePack(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	// IP enterSgePack --- IBEGIN

	// .tgz result folder
	if (outfolder != "") Wdbe::tgz(xchg->tmppath + "/" + outfolder, xchg->tmppath + "/" + outfile);

	// IP enterSgePack --- IEND

	return retval;
};

void DlgWdbeUtlMrgip::leaveSgePack(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgePack --- INSERT
};

uint DlgWdbeUtlMrgip::enterSgeFail(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::FAIL;

	// IP enterSgeFail --- INSERT

	return retval;
};

void DlgWdbeUtlMrgip::leaveSgeFail(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeFail --- INSERT
};

uint DlgWdbeUtlMrgip::enterSgeDone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void DlgWdbeUtlMrgip::leaveSgeDone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeDone --- INSERT
};
