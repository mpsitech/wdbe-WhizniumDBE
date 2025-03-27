/**
	* \file DlgWdbeRlsFinreptr.cpp
	* job handler for job DlgWdbeRlsFinreptr (implementation)
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

#include "DlgWdbeRlsFinreptr.h"

#include "DlgWdbeRlsFinreptr_blks.cpp"
#include "DlgWdbeRlsFinreptr_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWdbeRlsFinreptr
 ******************************************************************************/

DlgWdbeRlsFinreptr::DlgWdbeRlsFinreptr(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::DLGWDBERLSFINREPTR, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFDse.tag = "FeedFDse";
	VecVDit::fillFeed(ixWdbeVLocale, feedFDse);
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	// IP constructor.cust1 --- IBEGIN
	dbswdbe->loadStringBySQL("SELECT sref FROM TblWdbeMUser WHERE ref = " + to_string(xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref)), usrsref);

	mGitprg = Mutex("mGitprg", "DlgWdbeRlsFinreptr(" + to_string(jref) + ")", "DlgWdbeRlsFinreptr");
	// IP constructor.cust1 --- IEND

	ixVDit = VecVDit::FIN;

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswdbe, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgWdbeRlsFinreptr::~DlgWdbeRlsFinreptr() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
int DlgWdbeRlsFinreptr::gitCredCallback(
			git_cred** cred
			, const char* url
			, const char* username_from_url
			, unsigned int allowed_types
			, void* payload
		) {
	DlgWdbeRlsFinreptr* inst = (DlgWdbeRlsFinreptr*) payload;

	int res;

	// SSH key naming convention: id_wdbe_<usrsref>[.pub]
	string pubkey = inst->xchg->stgwdbepath.keypath + "/id_wdbe_" + inst->usrsref + ".pub";
	string privkey = inst->xchg->stgwdbepath.keypath + "/id_wdbe_" + inst->usrsref;

	res = git_cred_ssh_key_new(cred, "git", pubkey.c_str(), privkey.c_str(), "");
	if (res != 0) {
		cout << "error: SSH-based credentials can not be generated" << endl;

		return -1;
	};

	return 0;
};

int DlgWdbeRlsFinreptr::gitIndexUpdateCallback(
			const char* path
			, const char* matched_pathspec
			, void* payload
		) {
	DlgWdbeRlsFinreptr* inst = (DlgWdbeRlsFinreptr*) payload;

	return 0;
};

int DlgWdbeRlsFinreptr::gitIndexAddCallback(
			const char* path
			, const char* matched_pathspec
			, void* payload
		) {
	DlgWdbeRlsFinreptr* inst = (DlgWdbeRlsFinreptr*) payload;

	return 0;
};

int DlgWdbeRlsFinreptr::gitPackCallback(
			int stage
			, unsigned int current
			, unsigned int total
			, void* payload
		) {
	DlgWdbeRlsFinreptr* inst = (DlgWdbeRlsFinreptr*) payload;

	inst->mGitprg.lock("DlgWdbeRlsFinreptr", "gitPackCallback");
	inst->gitprg = " (pack: " + to_string(current) + "/" + to_string(total) + " steps completed)";
	inst->mGitprg.unlock("DlgWdbeRlsFinreptr", "gitPackCallback");

	return 0;
};

int DlgWdbeRlsFinreptr::gitPushCallback(
			unsigned int current
			, unsigned int total
			, size_t bytes
			, void *payload
		) {
	DlgWdbeRlsFinreptr* inst = (DlgWdbeRlsFinreptr*) payload;

	inst->mGitprg.lock("DlgWdbeRlsFinreptr", "gitPushCallback");
	inst->gitprg = " (push: " + to_string(bytes/1024) + "kB sent)";
	inst->mGitprg.unlock("DlgWdbeRlsFinreptr", "gitPushCallback");

	return 0;
};

// IP cust --- IEND

DpchEngWdbe* DlgWdbeRlsFinreptr::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &continffin, &continfres, &feedFDse, &feedFSge, &statshr, &statshrfin, &statshrres, items);
	};

	return dpcheng;
};

void DlgWdbeRlsFinreptr::refreshFin(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShrFin oldStatshrfin(statshrfin);
	ContInfFin oldContinffin(continffin);

	// IP refreshFin --- RBEGIN
	// continffin
	continffin.TxtPrg = getSquawk(dbswdbe);

	// statshrfin
	statshrfin.ButRunActive = evalFinButRunActive(dbswdbe);
	statshrfin.ButStoActive = evalFinButStoActive(dbswdbe);

	// IP refreshFin --- REND
	if (statshrfin.diff(&oldStatshrfin).size() != 0) insert(moditems, DpchEngData::STATSHRFIN);
	if (continffin.diff(&oldContinffin).size() != 0) insert(moditems, DpchEngData::CONTINFFIN);
};

void DlgWdbeRlsFinreptr::refreshRes(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContInfRes oldContinfres(continfres);
	StatShrRes oldStatshrres(statshrres);

	// IP refreshRes --- RBEGIN
	// statshrres
	statshrres.DldAvail = evalResDldAvail(dbswdbe);
	statshrres.DldActive = evalResDldActive(dbswdbe);
	statshrres.TxtPrgAvail = evalResTxtPrgAvail(dbswdbe);
	statshrres.Sep1Avail = evalResSep1Avail(dbswdbe);
	statshrres.ButPsgAvail = evalResButPsgAvail(dbswdbe);
	statshrres.ButPsgActive = evalResButPsgActive(dbswdbe);

	// continfres
	continfres.Dld = StrMod::lc(Wdbe::getPrjshort(dbswdbe, xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref))) + ".tgz";
	continfres.TxtPrg = getSquawk(dbswdbe);

	// IP refreshRes --- REND
	if (continfres.diff(&oldContinfres).size() != 0) insert(moditems, DpchEngData::CONTINFRES);
	if (statshrres.diff(&oldStatshrres).size() != 0) insert(moditems, DpchEngData::STATSHRRES);
};

void DlgWdbeRlsFinreptr::refresh(
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

	refreshFin(dbswdbe, moditems);
	refreshRes(dbswdbe, moditems);

	muteRefresh = false;
};

void DlgWdbeRlsFinreptr::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBERLSFINREPTRDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswdbe, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBERLSFINREPTRDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbswdbe, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoFin != 0) {
				if (dpchappdo->ixVDoFin == VecVDoFin::BUTRUNCLICK) {
					handleDpchAppDoFinButRunClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDoFin == VecVDoFin::BUTSTOCLICK) {
					handleDpchAppDoFinButStoClick(dbswdbe, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoRes != 0) {
				if (dpchappdo->ixVDoRes == VecVDoRes::BUTPSGCLICK) {
					handleDpchAppDoResButPsgClick(dbswdbe, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEALERT) {
			handleDpchAppWdbeAlert(dbswdbe, (DpchAppWdbeAlert*) (req->dpchapp), &(req->dpcheng));

		};

	} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::DOWNLOAD) {
		if (ixVSge == VecVSge::DONE) req->filename = handleDownloadInSgeDone(dbswdbe);

	} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::TIMER) {
		if (ixVSge == VecVSge::FINIDLE) handleTimerInSgeFinidle(dbswdbe, req->sref);
		else if (ixVSge == VecVSge::PSGIDLE) handleTimerInSgePsgidle(dbswdbe, req->sref);
		else if ((req->sref == "mon") && (ixVSge == VecVSge::PUSHGIT)) handleTimerWithSrefMonInSgePushgit(dbswdbe);
	};
};

void DlgWdbeRlsFinreptr::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWdbeRlsFinreptr::handleDpchAppDataContiac(
			DbsWdbe* dbswdbe
			, ContIac* _contiac
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFDSE)) {
		if ((_contiac->numFDse >= VecVDit::FIN) && (_contiac->numFDse <= VecVDit::RES)) ixVDit = _contiac->numFDse;
		refresh(dbswdbe, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgWdbeRlsFinreptr::handleDpchAppDoButDneClick(
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

void DlgWdbeRlsFinreptr::handleDpchAppDoFinButRunClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoFinButRunClick --- BEGIN
	if (statshrfin.ButRunActive) {
		changeStage(dbswdbe, VecVSge::PACK, dpcheng);
	};
	// IP handleDpchAppDoFinButRunClick --- END
};

void DlgWdbeRlsFinreptr::handleDpchAppDoFinButStoClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoFinButStoClick --- INSERT
};

void DlgWdbeRlsFinreptr::handleDpchAppDoResButPsgClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoResButPsgClick --- BEGIN
	if (statshrres.ButPsgAvail && statshrres.ButPsgActive) {
		changeStage(dbswdbe, VecVSge::PSGIDLE, dpcheng);
	};
	// IP handleDpchAppDoResButPsgClick --- END
};

void DlgWdbeRlsFinreptr::handleDpchAppWdbeAlert(
			DbsWdbe* dbswdbe
			, DpchAppWdbeAlert* dpchappwdbealert
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppWdbeAlert --- IBEGIN
	if ((ixVSge == VecVSge::ALRGNF) || (ixVSge == VecVSge::ALRGAD)) {
		changeStage(dbswdbe, nextIxVSgeSuccess);
	};
	// IP handleDpchAppWdbeAlert --- IEND
};

string DlgWdbeRlsFinreptr::handleDownloadInSgeDone(
			DbsWdbe* dbswdbe
		) {
	return(xchg->tmppath + "/" + tgzfile); // IP handleDownloadInSgeDone --- RLINE
};

void DlgWdbeRlsFinreptr::handleTimerInSgeFinidle(
			DbsWdbe* dbswdbe
			, const string& sref
		) {
	changeStage(dbswdbe, nextIxVSgeSuccess);
};

void DlgWdbeRlsFinreptr::handleTimerInSgePsgidle(
			DbsWdbe* dbswdbe
			, const string& sref
		) {
	changeStage(dbswdbe, nextIxVSgeSuccess);
};

void DlgWdbeRlsFinreptr::handleTimerWithSrefMonInSgePushgit(
			DbsWdbe* dbswdbe
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	refreshWithDpchEng(dbswdbe); // IP handleTimerWithSrefMonInSgePushgit --- ILINE
};

void DlgWdbeRlsFinreptr::changeStage(
			DbsWdbe* dbswdbe
			, uint _ixVSge
			, DpchEngWdbe** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswdbe); break;
				case VecVSge::ALRGNF: leaveSgeAlrgnf(dbswdbe); break;
				case VecVSge::ALRGAD: leaveSgeAlrgad(dbswdbe); break;
				case VecVSge::FINIDLE: leaveSgeFinidle(dbswdbe); break;
				case VecVSge::PACK: leaveSgePack(dbswdbe); break;
				case VecVSge::COMMIT: leaveSgeCommit(dbswdbe); break;
				case VecVSge::FINDONE: leaveSgeFindone(dbswdbe); break;
				case VecVSge::PSGIDLE: leaveSgePsgidle(dbswdbe); break;
				case VecVSge::PUSHGIT: leaveSgePushgit(dbswdbe); break;
				case VecVSge::DONE: leaveSgeDone(dbswdbe); break;
			};

			setStage(dbswdbe, _ixVSge);
			reenter = false;
			refreshWithDpchEng(dbswdbe, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswdbe, reenter); break;
			case VecVSge::ALRGNF: _ixVSge = enterSgeAlrgnf(dbswdbe, reenter); break;
			case VecVSge::ALRGAD: _ixVSge = enterSgeAlrgad(dbswdbe, reenter); break;
			case VecVSge::FINIDLE: _ixVSge = enterSgeFinidle(dbswdbe, reenter); break;
			case VecVSge::PACK: _ixVSge = enterSgePack(dbswdbe, reenter); break;
			case VecVSge::COMMIT: _ixVSge = enterSgeCommit(dbswdbe, reenter); break;
			case VecVSge::FINDONE: _ixVSge = enterSgeFindone(dbswdbe, reenter); break;
			case VecVSge::PSGIDLE: _ixVSge = enterSgePsgidle(dbswdbe, reenter); break;
			case VecVSge::PUSHGIT: _ixVSge = enterSgePushgit(dbswdbe, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswdbe, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWdbeRlsFinreptr::getSquawk(
			DbsWdbe* dbswdbe
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::PACK) || (ixVSge == VecVSge::COMMIT) || (ixVSge == VecVSge::FINDONE) || (ixVSge == VecVSge::PUSHGIT) ) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			if (ixVSge == VecVSge::PACK) retval = "packing repository";
			else if (ixVSge == VecVSge::COMMIT) retval = "commiting to local Git repository";
			else if (ixVSge == VecVSge::FINDONE) retval = "repository transaction finalized";
			else if (ixVSge == VecVSge::PUSHGIT) {
				mGitprg.lock("DlgWdbeRlsFinreptr", "getSquawk");
				retval = "pushing to Git repository at " + xchg->getTxtvalPreset(VecWdbeVPreset::PREWDBEGITURL, jref) + gitprg;
				mGitprg.unlock("DlgWdbeRlsFinreptr", "getSquawk");
			};
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

uint DlgWdbeRlsFinreptr::enterSgeIdle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWdbeRlsFinreptr::leaveSgeIdle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWdbeRlsFinreptr::enterSgeAlrgnf(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::ALRGNF;
	nextIxVSgeSuccess = VecVSge::IDLE;

	ContInfWdbeAlert continf;
	// IP enterSgeAlrgnf --- BEGIN
	string giturl = "";

	continf.TxtCpt = VecWdbeVTag::getTitle(VecWdbeVTag::ERROR, ixWdbeVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		continf.TxtMsg1 = "Unable to locate Git repository at " + giturl + ".";
	};

	feedFMcbAlert.clear();

	VecWdbeVTag::appendToFeed(VecWdbeVTag::OK, ixWdbeVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
	// IP enterSgeAlrgnf --- END
	xchg->submitDpch(new DpchEngWdbeAlert(jref, &continf, &feedFMcbAlert, {DpchEngWdbeAlert::ALL}));

	return retval;
};

void DlgWdbeRlsFinreptr::leaveSgeAlrgnf(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAlrgnf --- INSERT
};

uint DlgWdbeRlsFinreptr::enterSgeAlrgad(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::ALRGAD;
	nextIxVSgeSuccess = VecVSge::IDLE;

	ContInfWdbeAlert continf;
	// IP enterSgeAlrgad --- BEGIN
	string giturl = "";
	string usr = "";

	continf.TxtCpt = VecWdbeVTag::getTitle(VecWdbeVTag::ERROR, ixWdbeVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		continf.TxtMsg1 = "Access to Git repository at " + giturl + " denied for user " + usr + ".";
	};

	feedFMcbAlert.clear();

	VecWdbeVTag::appendToFeed(VecWdbeVTag::OK, ixWdbeVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
	// IP enterSgeAlrgad --- END
	xchg->submitDpch(new DpchEngWdbeAlert(jref, &continf, &feedFMcbAlert, {DpchEngWdbeAlert::ALL}));

	return retval;
};

void DlgWdbeRlsFinreptr::leaveSgeAlrgad(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAlrgad --- INSERT
};

uint DlgWdbeRlsFinreptr::enterSgeFinidle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::FINIDLE;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgeFinidle --- IBEGIN

	uint ixBasereptype = xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXBASEREPTYPE, jref);

	if ((ixBasereptype == VecWdbeVBasereptype::VOID) || (ixBasereptype == VecWdbeVBasereptype::ULD)) retval = VecVSge::PACK;
	else if ((ixBasereptype == VecWdbeVBasereptype::PRJGIT) || (ixBasereptype == VecWdbeVBasereptype::CUSTGIT)) retval = VecVSge::COMMIT;
	else retval = VecVSge::IDLE;

	// IP enterSgeFinidle --- IEND

	return retval;
};

void DlgWdbeRlsFinreptr::leaveSgeFinidle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeFinidle --- INSERT
};

uint DlgWdbeRlsFinreptr::enterSgePack(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	// IP enterSgePack --- IBEGIN

	tgzfile = Tmp::newfile(xchg->tmppath, "tgz");

	// .tgz result folder
	Wdbe::tgz(xchg->tmppath + "/" + xchg->getTxtvalPreset(VecWdbeVPreset::PREWDBEREPFOLDER, jref), xchg->tmppath + "/" + tgzfile);

	// IP enterSgePack --- IEND

	return retval;
};

void DlgWdbeRlsFinreptr::leaveSgePack(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgePack --- INSERT
};

uint DlgWdbeRlsFinreptr::enterSgeCommit(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::FINDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IDLE;

	// IP enterSgeCommit --- IBEGIN

	WdbeMVersion* ver = NULL;

	WdbeMUser* usr = NULL;

	int res;
	bool valid;

	const git_error* err;

	char hashbuf[GIT_OID_HEXSZ+1];
	memset(hashbuf, 0, GIT_OID_HEXSZ+1);

	git_repository* rep = NULL;

	git_index* index = NULL;
	git_tree* tree = NULL;
	git_signature* signature = NULL;
	git_commit* parent = NULL;
	git_object* obj = NULL;

	git_oid oid;

	string giturl;
	
	string repfolder;
	
	string vermsg;

	string author;

	char hostname[256];

	string email;

	time_t rawtime;
	time(&rawtime);

	git_libgit2_init();

	repfolder = xchg->tmppath + "/" + xchg->getTxtvalPreset(VecWdbeVPreset::PREWDBEREPFOLDER, jref);

	// --- assemble commit information
	if (dbswdbe->tblwdbemversion->loadRecByRef(xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref), &ver)) {
		vermsg = StubWdbe::getStubPrjStd(dbswdbe, ver->prjRefWdbeMProject) + " " + to_string(ver->Major) + "." + to_string(ver->Minor) + "." + to_string(ver->Sub) + " initial";
		vertag = "v" + to_string(ver->Major) + "." + to_string(ver->Minor) + "." + to_string(ver->Sub) + "i";

		delete ver;
	};

	if (dbswdbe->tblwdbemuser->loadRecByRef(xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref), &usr)) {
		author = StubWdbe::getStubPrsStd(dbswdbe, usr->refWdbeMPerson);

		gethostname(hostname, 256);
		email = "WhizniumDBE:" + usr->sref + "@" + string(hostname);

		delete usr;
	};

	// --- open repository
	res = git_repository_open(&rep, repfolder.c_str());
	valid = (res == 0);

	if (!valid) {
		cout << "error: repository not found" << endl;

		retval = nextIxVSgeFailure;
	};

	// --- update index
	if (valid) {
		git_repository_index(&index, rep);

		git_index_update_all(index, NULL, gitIndexUpdateCallback, this);
		git_index_add_all(index, NULL, GIT_INDEX_ADD_DISABLE_PATHSPEC_MATCH, gitIndexAddCallback, this);

		git_index_write(index);

		git_index_write_tree(&oid, index);
		git_tree_lookup(&tree, rep, &oid);

		if (index) {
			git_index_free(index);
			index = NULL;
		};
	};

	// --- commit changes
	if (valid) {
		// ex.: git commit -a -m "ICARUSDetectorHardware 0.1.2 initial"
		res = git_revparse_single(&obj, rep, "HEAD");
		valid = (res == 0);

		if (!valid) {
			cout << "error: HEAD commit not found" << endl;

			retval = nextIxVSgeFailure;
		};
	};

	if (valid) {
		git_commit_lookup(&parent, rep, git_object_id(obj));
		git_signature_new(&signature, author.c_str(), email.c_str(), rawtime, 0);

		res = git_commit_create_v(&oid, rep, "HEAD", signature, signature, NULL, vermsg.c_str(), tree, 1, parent);
		valid = (res == 0);

		if (!valid) {
			err = giterr_last();
			cout << "error on git_commit_create_v(): " << err->message << endl;
			
			retval = nextIxVSgeFailure;
		};
	};

	if (valid) git_oid_fmt(hashbuf, &oid);

	if (tree) {
		git_tree_free(tree);
		tree = NULL;
	};

	if (obj) {
		git_object_free(obj);
		obj = NULL;
	};

	if (parent) {
		git_commit_free(parent);
		parent = NULL;
	};

	// --- add tag
	// ex.: git tag -a v0.1.2i -m "ICARUSDetectorHardware 0.1.2 initial"

	if (valid) {
		git_object_lookup(&obj, rep, &oid, GIT_OBJ_COMMIT);

		res = git_tag_create(&oid, rep, vertag.c_str(), obj, signature, vermsg.c_str(), false);
		valid = (res == 0);

		if (!valid) {
			err = giterr_last();
			cout << "error on git_tag_create(): " << err->message << endl;

			retval = nextIxVSgeFailure;
		};
	};

	// --- clean up
	if (signature) {
		git_signature_free(signature);
		signature = NULL;
	};

	if (obj) {
		git_object_free(obj);
		obj = NULL;
	};

	if (rep) {
		git_repository_free(rep);
		rep = NULL;
	};

	git_libgit2_shutdown();

	// IP enterSgeCommit --- IEND

	return retval;
};

void DlgWdbeRlsFinreptr::leaveSgeCommit(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeCommit --- INSERT
};

uint DlgWdbeRlsFinreptr::enterSgeFindone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::FINDONE;

	// IP enterSgeFindone --- INSERT

	return retval;
};

void DlgWdbeRlsFinreptr::leaveSgeFindone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeFindone --- INSERT
};

uint DlgWdbeRlsFinreptr::enterSgePsgidle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::PSGIDLE;
	nextIxVSgeSuccess = VecVSge::PUSHGIT;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgePsgidle --- INSERT

	return retval;
};

void DlgWdbeRlsFinreptr::leaveSgePsgidle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgePsgidle --- INSERT
};

uint DlgWdbeRlsFinreptr::enterSgePushgit(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IDLE;

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);

	// IP enterSgePushgit --- IBEGIN

	int res;
	bool valid;

	const git_error* err;

	git_repository* rep = NULL;
	git_remote* remote = NULL;

	string refVertag = "refs/tags/" + vertag;
	const char* ss[] = {"refs/heads/master", refVertag.c_str()};
	const git_strarray refs = {(char**) ss, 2};

	git_push_options pushopts = GIT_PUSH_OPTIONS_INIT;
	pushopts.callbacks.pack_progress = gitPackCallback;
	pushopts.callbacks.push_transfer_progress = gitPushCallback;
	pushopts.callbacks.credentials = gitCredCallback;
	pushopts.callbacks.payload = this;

	string repfolder;

	git_libgit2_init();

	gitprg = "";

	repfolder = xchg->tmppath + "/" + xchg->getTxtvalPreset(VecWdbeVPreset::PREWDBEREPFOLDER, jref);

	// --- open repository
	res = git_repository_open(&rep, repfolder.c_str());
	valid = (res == 0);

	if (!valid) {
		cout << "error: repository not found" << endl;

		retval = nextIxVSgeFailure;
	};

	// --- look for remote location
	if (valid) {
		res = git_remote_lookup(&remote, rep, "origin");
		valid = (res == 0);

		if (!valid) {
			cout << "error: origin remote location not found" << endl;

			retval = VecVSge::ALRGNF;
		};
	};

	if (valid) {
		git_remote_connect(remote, GIT_DIRECTION_PUSH, NULL, NULL, NULL);

		res = git_remote_push(remote, &refs, &pushopts);
		valid = (res == 0);

		if (!valid) {
			err = giterr_last();
			cout << "error on git_remote_push(): " << err->message << endl;

			retval = VecVSge::ALRGAD;
		};
	};

	// --- clean up
	if (remote) {
		git_remote_disconnect(remote);
		git_remote_free(remote);
		remote = NULL;
	};

	if (rep) {
		git_repository_free(rep);
		rep = NULL;
	};

	git_libgit2_shutdown();

	// IP enterSgePushgit --- IEND

	return retval;
};

void DlgWdbeRlsFinreptr::leaveSgePushgit(
			DbsWdbe* dbswdbe
		) {
	invalidateWakeups();
	// IP leaveSgePushgit --- INSERT
};

uint DlgWdbeRlsFinreptr::enterSgeDone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- IBEGIN

	xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBEREPTRSTOP, jref);

	// IP enterSgeDone --- IEND

	return retval;
};

void DlgWdbeRlsFinreptr::leaveSgeDone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeDone --- INSERT
};
