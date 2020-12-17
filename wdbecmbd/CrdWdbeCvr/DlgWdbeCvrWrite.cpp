/**
	* \file DlgWdbeCvrWrite.cpp
	* job handler for job DlgWdbeCvrWrite (implementation)
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

#include "DlgWdbeCvrWrite.h"

#include "DlgWdbeCvrWrite_blks.cpp"
#include "DlgWdbeCvrWrite_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWdbeCvrWrite
 ******************************************************************************/

DlgWdbeCvrWrite::DlgWdbeCvrWrite(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::DLGWDBECVRWRITE, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFDse.tag = "FeedFDse";
	VecVDit::fillFeed(ixWdbeVLocale, feedFDse);
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	// IP constructor.cust1 --- INSERT

	ixVDit = VecVDit::CUC;

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswdbe, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgWdbeCvrWrite::~DlgWdbeCvrWrite() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* DlgWdbeCvrWrite::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &continffia, &continfwrc, &feedFDse, &feedFSge, &statshr, &statshrcuc, &statshrfia, &statshrwrc, items);
	};

	return dpcheng;
};

void DlgWdbeCvrWrite::refreshCuc(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShrCuc oldStatshrcuc(statshrcuc);

	// IP refreshCuc --- BEGIN
	// statshrcuc
	statshrcuc.UldActive = evalCucUldActive(dbswdbe);

	// IP refreshCuc --- END
	if (statshrcuc.diff(&oldStatshrcuc).size() != 0) insert(moditems, DpchEngData::STATSHRCUC);
};

void DlgWdbeCvrWrite::refreshWrc(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContInfWrc oldContinfwrc(continfwrc);
	StatShrWrc oldStatshrwrc(statshrwrc);

	// IP refreshWrc --- BEGIN
	// continfwrc

	// statshrwrc
	statshrwrc.ButRunActive = evalWrcButRunActive(dbswdbe);
	statshrwrc.ButStoActive = evalWrcButStoActive(dbswdbe);

	// IP refreshWrc --- END
	if (continfwrc.diff(&oldContinfwrc).size() != 0) insert(moditems, DpchEngData::CONTINFWRC);
	if (statshrwrc.diff(&oldStatshrwrc).size() != 0) insert(moditems, DpchEngData::STATSHRWRC);
};

void DlgWdbeCvrWrite::refreshFia(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContInfFia oldContinffia(continffia);
	StatShrFia oldStatshrfia(statshrfia);

	// IP refreshFia --- RBEGIN
	// statshrfia
	statshrfia.DldActive = evalFiaDldActive(dbswdbe);

	// continffia
	continffia.Dld = "code.tgz";

	// IP refreshFia --- REND
	if (continffia.diff(&oldContinffia).size() != 0) insert(moditems, DpchEngData::CONTINFFIA);
	if (statshrfia.diff(&oldStatshrfia).size() != 0) insert(moditems, DpchEngData::STATSHRFIA);
};

void DlgWdbeCvrWrite::refresh(
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

	refreshCuc(dbswdbe, moditems);
	refreshWrc(dbswdbe, moditems);
	refreshFia(dbswdbe, moditems);

	muteRefresh = false;
};

void DlgWdbeCvrWrite::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBECVRWRITEDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswdbe, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBECVRWRITEDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbswdbe, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoWrc != 0) {
				if (dpchappdo->ixVDoWrc == VecVDoWrc::BUTRUNCLICK) {
					handleDpchAppDoWrcButRunClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDoWrc == VecVDoWrc::BUTSTOCLICK) {
					handleDpchAppDoWrcButStoClick(dbswdbe, &(req->dpcheng));
				};

			};

		};

	} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::UPLOAD) {
		if (ixVSge == VecVSge::IDLE) handleUploadInSgeIdle(dbswdbe, req->filename);

	} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::DOWNLOAD) {
		if (ixVSge == VecVSge::DONE) req->filename = handleDownloadInSgeDone(dbswdbe);

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
		if ((req->sref == "mon") && (ixVSge == VecVSge::WRITE)) handleTimerWithSrefMonInSgeWrite(dbswdbe);
		else if (ixVSge == VecVSge::CREIDLE) handleTimerInSgeCreidle(dbswdbe, req->sref);
		else if (ixVSge == VecVSge::UPKIDLE) handleTimerInSgeUpkidle(dbswdbe, req->sref);
		else if ((req->sref == "mon") && (ixVSge == VecVSge::CREATE)) handleTimerWithSrefMonInSgeCreate(dbswdbe);
	};
};

void DlgWdbeCvrWrite::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWdbeCvrWrite::handleDpchAppDataContiac(
			DbsWdbe* dbswdbe
			, ContIac* _contiac
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFDSE)) {
		if ((_contiac->numFDse >= VecVDit::CUC) && (_contiac->numFDse <= VecVDit::FIA)) ixVDit = _contiac->numFDse;
		refresh(dbswdbe, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgWdbeCvrWrite::handleDpchAppDoButDneClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButDneClick --- INSERT
};

void DlgWdbeCvrWrite::handleDpchAppDoWrcButRunClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoWrcButRunClick --- BEGIN
	if (statshrwrc.ButRunActive) {
		changeStage(dbswdbe, VecVSge::CREIDLE, dpcheng);
	};
	// IP handleDpchAppDoWrcButRunClick --- END
};

void DlgWdbeCvrWrite::handleDpchAppDoWrcButStoClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoWrcButStoClick --- INSERT
};

void DlgWdbeCvrWrite::handleDpchRetWdbePrctreeMerge(
			DbsWdbe* dbswdbe
			, DpchRetWdbePrctreeMerge* dpchret
		) {
	// IP handleDpchRetWdbePrctreeMerge --- INSERT
};

void DlgWdbeCvrWrite::handleUploadInSgeIdle(
			DbsWdbe* dbswdbe
			, const string& filename
		) {
	// IP handleUploadInSgeIdle --- INSERT
	changeStage(dbswdbe, VecVSge::UPKIDLE);
};

string DlgWdbeCvrWrite::handleDownloadInSgeDone(
			DbsWdbe* dbswdbe
		) {
	return(""); // IP handleDownloadInSgeDone --- LINE
};

void DlgWdbeCvrWrite::handleTimerWithSrefMonInSgeWrite(
			DbsWdbe* dbswdbe
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	// IP handleTimerWithSrefMonInSgeWrite --- INSERT
};

void DlgWdbeCvrWrite::handleTimerInSgeCreidle(
			DbsWdbe* dbswdbe
			, const string& sref
		) {
	changeStage(dbswdbe, nextIxVSgeSuccess);
};

void DlgWdbeCvrWrite::handleTimerInSgeUpkidle(
			DbsWdbe* dbswdbe
			, const string& sref
		) {
	changeStage(dbswdbe, nextIxVSgeSuccess);
};

void DlgWdbeCvrWrite::handleTimerWithSrefMonInSgeCreate(
			DbsWdbe* dbswdbe
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	// IP handleTimerWithSrefMonInSgeCreate --- INSERT
};

void DlgWdbeCvrWrite::changeStage(
			DbsWdbe* dbswdbe
			, uint _ixVSge
			, DpchEngWdbe** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswdbe); break;
				case VecVSge::UPKIDLE: leaveSgeUpkidle(dbswdbe); break;
				case VecVSge::UNPACK: leaveSgeUnpack(dbswdbe); break;
				case VecVSge::UPKDONE: leaveSgeUpkdone(dbswdbe); break;
				case VecVSge::CREIDLE: leaveSgeCreidle(dbswdbe); break;
				case VecVSge::CREATE: leaveSgeCreate(dbswdbe); break;
				case VecVSge::WRITE: leaveSgeWrite(dbswdbe); break;
				case VecVSge::MRG: leaveSgeMrg(dbswdbe); break;
				case VecVSge::MRGCUST: leaveSgeMrgcust(dbswdbe); break;
				case VecVSge::PACK: leaveSgePack(dbswdbe); break;
				case VecVSge::DONE: leaveSgeDone(dbswdbe); break;
			};

			setStage(dbswdbe, _ixVSge);
			reenter = false;
			refreshWithDpchEng(dbswdbe, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswdbe, reenter); break;
			case VecVSge::UPKIDLE: _ixVSge = enterSgeUpkidle(dbswdbe, reenter); break;
			case VecVSge::UNPACK: _ixVSge = enterSgeUnpack(dbswdbe, reenter); break;
			case VecVSge::UPKDONE: _ixVSge = enterSgeUpkdone(dbswdbe, reenter); break;
			case VecVSge::CREIDLE: _ixVSge = enterSgeCreidle(dbswdbe, reenter); break;
			case VecVSge::CREATE: _ixVSge = enterSgeCreate(dbswdbe, reenter); break;
			case VecVSge::WRITE: _ixVSge = enterSgeWrite(dbswdbe, reenter); break;
			case VecVSge::MRG: _ixVSge = enterSgeMrg(dbswdbe, reenter); break;
			case VecVSge::MRGCUST: _ixVSge = enterSgeMrgcust(dbswdbe, reenter); break;
			case VecVSge::PACK: _ixVSge = enterSgePack(dbswdbe, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswdbe, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWdbeCvrWrite::getSquawk(
			DbsWdbe* dbswdbe
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::UNPACK) || (ixVSge == VecVSge::UPKDONE) || (ixVSge == VecVSge::CREATE) || (ixVSge == VecVSge::WRITE) || (ixVSge == VecVSge::MRG) || (ixVSge == VecVSge::MRGCUST) || (ixVSge == VecVSge::PACK) ) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			if (ixVSge == VecVSge::UNPACK) retval = "unpacking custom code fragments";
			else if (ixVSge == VecVSge::UPKDONE) retval = "custom code fragments unpacked";
			else if (ixVSge == VecVSge::CREATE) retval = "creating write operations (" + to_string(opN) + " operations prepared)";
			else if (ixVSge == VecVSge::WRITE) retval = "writing code (" + to_string(opNSuccess + opNFailure) + "/" + to_string(opN) + " operations completed)";
			else if (ixVSge == VecVSge::MRG) retval = "merging code fragments";
			else if (ixVSge == VecVSge::MRGCUST) retval = "merging custom code fragments";
			else if (ixVSge == VecVSge::PACK) retval = "packing code tree";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint DlgWdbeCvrWrite::enterSgeIdle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWdbeCvrWrite::leaveSgeIdle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWdbeCvrWrite::enterSgeUpkidle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::UPKIDLE;
	nextIxVSgeSuccess = VecVSge::UNPACK;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgeUpkidle --- INSERT

	return retval;
};

void DlgWdbeCvrWrite::leaveSgeUpkidle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeUpkidle --- INSERT
};

uint DlgWdbeCvrWrite::enterSgeUnpack(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::UPKDONE;
	retval = nextIxVSgeSuccess;

	// IP enterSgeUnpack --- INSERT

	return retval;
};

void DlgWdbeCvrWrite::leaveSgeUnpack(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeUnpack --- INSERT
};

uint DlgWdbeCvrWrite::enterSgeUpkdone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::UPKDONE;

	// IP enterSgeUpkdone --- INSERT

	return retval;
};

void DlgWdbeCvrWrite::leaveSgeUpkdone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeUpkdone --- INSERT
};

uint DlgWdbeCvrWrite::enterSgeCreidle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::CREIDLE;
	nextIxVSgeSuccess = VecVSge::CREATE;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgeCreidle --- INSERT

	return retval;
};

void DlgWdbeCvrWrite::leaveSgeCreidle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeCreidle --- INSERT
};

uint DlgWdbeCvrWrite::enterSgeCreate(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::WRITE;
	retval = nextIxVSgeSuccess;

	clearInvs();

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);

	// IP enterSgeCreate --- INSERT

	return retval;
};

void DlgWdbeCvrWrite::leaveSgeCreate(
			DbsWdbe* dbswdbe
		) {
	invalidateWakeups();
	// IP leaveSgeCreate --- INSERT
};

uint DlgWdbeCvrWrite::enterSgeWrite(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::WRITE;
	nextIxVSgeSuccess = VecVSge::MRG;

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);

	// IP enterSgeWrite --- INSERT

	submitInvs(dbswdbe, VecVSge::IDLE, retval);
	return retval;
};

void DlgWdbeCvrWrite::leaveSgeWrite(
			DbsWdbe* dbswdbe
		) {
	invalidateWakeups();
	// IP leaveSgeWrite --- INSERT
};

uint DlgWdbeCvrWrite::enterSgeMrg(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::MRG;
	nextIxVSgeSuccess = VecVSge::MRGCUST;

	clearInvs();

	// IP enterSgeMrg --- INSERT

	submitInvs(dbswdbe, VecVSge::MRGCUST, retval);
	return retval;
};

void DlgWdbeCvrWrite::leaveSgeMrg(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeMrg --- INSERT
};

uint DlgWdbeCvrWrite::enterSgeMrgcust(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::MRGCUST;
	nextIxVSgeSuccess = VecVSge::PACK;

	clearInvs();

	// IP enterSgeMrgcust --- INSERT

	submitInvs(dbswdbe, VecVSge::PACK, retval);
	return retval;
};

void DlgWdbeCvrWrite::leaveSgeMrgcust(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeMrgcust --- INSERT
};

uint DlgWdbeCvrWrite::enterSgePack(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	// IP enterSgePack --- INSERT

	return retval;
};

void DlgWdbeCvrWrite::leaveSgePack(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgePack --- INSERT
};

uint DlgWdbeCvrWrite::enterSgeDone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void DlgWdbeCvrWrite::leaveSgeDone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeDone --- INSERT
};
