/**
	* \file DlgWdbeRlsStareptr.cpp
	* job handler for job DlgWdbeRlsStareptr (implementation)
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

#include "DlgWdbeRlsStareptr.h"

#include "DlgWdbeRlsStareptr_blks.cpp"
#include "DlgWdbeRlsStareptr_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWdbeRlsStareptr
 ******************************************************************************/

DlgWdbeRlsStareptr::DlgWdbeRlsStareptr(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::DLGWDBERLSSTAREPTR, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFDetRbuBrt.tag = "FeedFDetRbuBrt";
	VecWdbeVBasereptype::fillFeed(ixWdbeVLocale, feedFDetRbuBrt);
	feedFDse.tag = "FeedFDse";
	VecVDit::fillFeed(ixWdbeVLocale, feedFDse);
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	// IP constructor.cust1 --- IBEGIN
	dbswdbe->loadStringBySQL("SELECT sref FROM TblWdbeMUser WHERE ref = " + to_string(xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref)), usrsref);

	mGitprg = Mutex("mGitprg", "DlgWdbeRlsStareptr(" + to_string(jref) + ")", "DlgWdbeRlsStareptr");
	// IP constructor.cust1 --- IEND

	ixVDit = VecVDit::DET;

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswdbe, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgWdbeRlsStareptr::~DlgWdbeRlsStareptr() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
int DlgWdbeRlsStareptr::gitCredCallback(
			git_cred** cred
			, const char* url
			, const char* username_from_url
			, unsigned int allowed_types
			, void* payload
		) {
	DlgWdbeRlsStareptr* inst = (DlgWdbeRlsStareptr*) payload;

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

int DlgWdbeRlsStareptr::gitFetchCallback(
			const git_transfer_progress* _stats
			, void* payload
		) {
	DlgWdbeRlsStareptr* inst = (DlgWdbeRlsStareptr*) payload;

	inst->mGitprg.lock("DlgWdbeRlsStareptr", "gitFetchCallback");
	inst->gitprg = " (fetch: " + to_string(_stats->received_bytes/1024) + "kB received)";
	inst->mGitprg.unlock("DlgWdbeRlsStareptr", "gitFetchCallback");

	return 0;
};

void DlgWdbeRlsStareptr::gitCheckoutCallback(
			const char* path
			, size_t _cur
			, size_t _tot
			, void* payload
		) {
	DlgWdbeRlsStareptr* inst = (DlgWdbeRlsStareptr*) payload;

	inst->mGitprg.lock("DlgWdbeRlsStareptr", "gitCheckoutCallback");
	inst->gitprg = " (checkout: " + to_string(_cur) + "/" + to_string(_tot) + " steps completed)";
	inst->mGitprg.unlock("DlgWdbeRlsStareptr", "gitCheckoutCallback");
};

// IP cust --- IEND

DpchEngWdbe* DlgWdbeRlsStareptr::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &contiacdet, &continf, &continfext, &continfini, &continflfi, &feedFDetRbuBrt, &feedFDse, &feedFSge, &statshr, &statshrdet, &statshrext, &statshrini, &statshrlfi, items);
	};

	return dpcheng;
};

void DlgWdbeRlsStareptr::refreshDet(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIacDet oldContiacdet(contiacdet);
	StatShrDet oldStatshrdet(statshrdet);

	// IP refreshDet --- RBEGIN
	// contiacdet

	// statshrdet
	statshrdet.TxfGrlAvail = (feedFDetRbuBrt.getIxByNum(contiacdet.numFRbuBrt) == VecWdbeVBasereptype::CUSTGIT);
	statshrdet.ButStaActive = evalDetButStaActive(dbswdbe);

	// IP refreshDet --- REND
	if (contiacdet.diff(&oldContiacdet).size() != 0) insert(moditems, DpchEngData::CONTIACDET);
	if (statshrdet.diff(&oldStatshrdet).size() != 0) insert(moditems, DpchEngData::STATSHRDET);
};

void DlgWdbeRlsStareptr::refreshIni(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShrIni oldStatshrini(statshrini);
	ContInfIni oldContinfini(continfini);

	// IP refreshIni --- RBEGIN

	// statshrini
	statshrini.UldAvail = evalIniUldAvail(dbswdbe);
	statshrini.UldActive = evalIniUldActive(dbswdbe);
	statshrini.TxtPrgAvail = evalIniTxtPrgAvail(dbswdbe);
	statshrini.Sep1Avail = evalIniSep1Avail(dbswdbe);
	statshrini.ButClgAvail = evalIniButClgAvail(dbswdbe);
	statshrini.ButClgActive = evalIniButClgActive(dbswdbe);

	// continfini
	continfini.TxtPrg = getSquawk(dbswdbe);

	// IP refreshIni --- REND
	if (statshrini.diff(&oldStatshrini).size() != 0) insert(moditems, DpchEngData::STATSHRINI);
	if (continfini.diff(&oldContinfini).size() != 0) insert(moditems, DpchEngData::CONTINFINI);
};

void DlgWdbeRlsStareptr::refreshExt(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContInfExt oldContinfext(continfext);
	StatShrExt oldStatshrext(statshrext);

	// IP refreshExt --- RBEGIN
	// continfext
	continfext.TxtPrg = getSquawk(dbswdbe);

	// statshrext
	statshrext.ButRunActive = evalExtButRunActive(dbswdbe);
	statshrext.ButStoActive = evalExtButStoActive(dbswdbe);

	// IP refreshExt --- REND
	if (continfext.diff(&oldContinfext).size() != 0) insert(moditems, DpchEngData::CONTINFEXT);
	if (statshrext.diff(&oldStatshrext).size() != 0) insert(moditems, DpchEngData::STATSHREXT);
};

void DlgWdbeRlsStareptr::refreshLfi(
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

void DlgWdbeRlsStareptr::refresh(
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

	refreshDet(dbswdbe, moditems);
	refreshIni(dbswdbe, moditems);
	refreshExt(dbswdbe, moditems);
	refreshLfi(dbswdbe, moditems);

	muteRefresh = false;
};

void DlgWdbeRlsStareptr::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBERLSSTAREPTRDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswdbe, &(dpchappdata->contiac), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::CONTIACDET)) {
				handleDpchAppDataContiacdet(dbswdbe, &(dpchappdata->contiacdet), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBERLSSTAREPTRDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbswdbe, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoDet != 0) {
				if (dpchappdo->ixVDoDet == VecVDoDet::BUTSTACLICK) {
					handleDpchAppDoDetButStaClick(dbswdbe, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoExt != 0) {
				if (dpchappdo->ixVDoExt == VecVDoExt::BUTRUNCLICK) {
					handleDpchAppDoExtButRunClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDoExt == VecVDoExt::BUTSTOCLICK) {
					handleDpchAppDoExtButStoClick(dbswdbe, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoIni != 0) {
				if (dpchappdo->ixVDoIni == VecVDoIni::BUTCLGCLICK) {
					handleDpchAppDoIniButClgClick(dbswdbe, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEALERT) {
			handleDpchAppWdbeAlert(dbswdbe, (DpchAppWdbeAlert*) (req->dpchapp), &(req->dpcheng));

		};

	} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::UPLOAD) {
		if (ixVSge == VecVSge::STADONE) handleUploadInSgeStadone(dbswdbe, req->filename);

	} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::DOWNLOAD) {
		if (ixVSge == VecVSge::FAIL) req->filename = handleDownloadInSgeFail(dbswdbe);

	} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::DPCHRET) {
		if (req->dpchret->ixOpVOpres == VecOpVOpres::PROGRESS) {
			// IP handleRequest.opprogress --- INSERT
		} else {
			if (req->dpchret->ixWdbeVDpch == VecWdbeVDpch::DPCHRETWDBEPRCTREEEXTRACT) {
				handleDpchRetWdbePrctreeExtract(dbswdbe, (DpchRetWdbePrctreeExtract*) (req->dpchret));
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
		if (ixVSge == VecVSge::UPKIDLE) handleTimerInSgeUpkidle(dbswdbe, req->sref);
		else if (ixVSge == VecVSge::CLGIDLE) handleTimerInSgeClgidle(dbswdbe, req->sref);
		else if ((req->sref == "mon") && (ixVSge == VecVSge::CLONEGIT)) handleTimerWithSrefMonInSgeClonegit(dbswdbe);
	};
};

void DlgWdbeRlsStareptr::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWdbeRlsStareptr::handleDpchAppDataContiac(
			DbsWdbe* dbswdbe
			, ContIac* _contiac
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFDSE)) {
		if ((_contiac->numFDse >= VecVDit::DET) && (_contiac->numFDse <= VecVDit::LFI)) ixVDit = _contiac->numFDse;
		refresh(dbswdbe, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgWdbeRlsStareptr::handleDpchAppDataContiacdet(
			DbsWdbe* dbswdbe
			, ContIacDet* _contiacdet
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiacdet->diff(&contiacdet);
	// IP handleDpchAppDataContiacdet --- IBEGIN

	if (has(diffitems, ContIacDet::NUMFRBUBRT)) {
		if ((_contiacdet->numFRbuBrt >= VecWdbeVBasereptype::VOID) && (_contiacdet->numFRbuBrt <= VecWdbeVBasereptype::ULD)) contiacdet.numFRbuBrt = _contiacdet->numFRbuBrt;
		else contiacdet.numFRbuBrt = VecWdbeVBasereptype::VOID;
	};

	if (has(diffitems, ContIacDet::TXFGRL)) contiacdet.TxfGrl = _contiacdet->TxfGrl;

	refresh(dbswdbe, moditems);

	// IP handleDpchAppDataContiacdet --- IEND
	insert(moditems, DpchEngData::CONTIACDET);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgWdbeRlsStareptr::handleDpchAppDoButDneClick(
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

void DlgWdbeRlsStareptr::handleDpchAppDoDetButStaClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoDetButStaClick --- IBEGIN

	WdbeMProject* prj = NULL;

	string giturl;

	if (feedFDetRbuBrt.getIxByNum(contiacdet.numFRbuBrt) == VecWdbeVBasereptype::PRJGIT) {
		if (dbswdbe->tblwdbemproject->loadRecBySQL("SELECT TblWdbeMProject.* FROM TblWdbeMProject, TblWdbeMVersion WHERE TblWdbeMProject.ref = TblWdbeMVersion.prjRefWdbeMProject AND TblWdbeMVersion.ref = "
					+ to_string(xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref)), &prj)) {

			giturl = prj->Giturl;
			delete prj;
		};

	} else if (feedFDetRbuBrt.getIxByNum(contiacdet.numFRbuBrt) == VecWdbeVBasereptype::CUSTGIT) giturl = contiacdet.TxfGrl;

	xchg->triggerIxTxtvalCall(dbswdbe, VecWdbeVCall::CALLWDBEREPTRSTART, jref, feedFDetRbuBrt.getIxByNum(contiacdet.numFRbuBrt), giturl);

	changeStage(dbswdbe, VecVSge::STADONE, dpcheng);

	// IP handleDpchAppDoDetButStaClick --- IEND
};

void DlgWdbeRlsStareptr::handleDpchAppDoExtButRunClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoExtButRunClick --- BEGIN
	if (statshrext.ButRunActive) {
		changeStage(dbswdbe, VecVSge::EXTRACT, dpcheng);
	};
	// IP handleDpchAppDoExtButRunClick --- END
};

void DlgWdbeRlsStareptr::handleDpchAppDoExtButStoClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoExtButStoClick --- INSERT
};

void DlgWdbeRlsStareptr::handleDpchAppDoIniButClgClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoIniButClgClick --- BEGIN
	if (statshrini.ButClgAvail && statshrini.ButClgActive) {
		changeStage(dbswdbe, VecVSge::CLGIDLE, dpcheng);
	};
	// IP handleDpchAppDoIniButClgClick --- END
};

void DlgWdbeRlsStareptr::handleDpchAppWdbeAlert(
			DbsWdbe* dbswdbe
			, DpchAppWdbeAlert* dpchappwdbealert
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppWdbeAlert --- IBEGIN
	if ((ixVSge == VecVSge::ALRGNF) || (ixVSge == VecVSge::ALRGAD) || (ixVSge == VecVSge::ALRGVE) || (ixVSge == VecVSge::ALRXER)) {
		changeStage(dbswdbe, nextIxVSgeSuccess);
	};
	// IP handleDpchAppWdbeAlert --- IEND
};

void DlgWdbeRlsStareptr::handleDpchRetWdbePrctreeExtract(
			DbsWdbe* dbswdbe
			, DpchRetWdbePrctreeExtract* dpchret
		) {
	logfile = dpchret->logfile; // IP handleDpchRetWdbePrctreeExtract --- ILINE
};

void DlgWdbeRlsStareptr::handleUploadInSgeStadone(
			DbsWdbe* dbswdbe
			, const string& filename
		) {
	infilename = filename; // IP handleUploadInSgeStadone --- ILINE
	changeStage(dbswdbe, VecVSge::UPKIDLE);
};

string DlgWdbeRlsStareptr::handleDownloadInSgeFail(
			DbsWdbe* dbswdbe
		) {
	return(xchg->tmppath + "/" + logfile); // IP handleDownloadInSgeFail --- RLINE
};

void DlgWdbeRlsStareptr::handleTimerInSgeUpkidle(
			DbsWdbe* dbswdbe
			, const string& sref
		) {
	changeStage(dbswdbe, nextIxVSgeSuccess);
};

void DlgWdbeRlsStareptr::handleTimerInSgeClgidle(
			DbsWdbe* dbswdbe
			, const string& sref
		) {
	changeStage(dbswdbe, nextIxVSgeSuccess);
};

void DlgWdbeRlsStareptr::handleTimerWithSrefMonInSgeClonegit(
			DbsWdbe* dbswdbe
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	refreshWithDpchEng(dbswdbe); // IP handleTimerWithSrefMonInSgeClonegit --- ILINE
};

void DlgWdbeRlsStareptr::changeStage(
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
				case VecVSge::ALRGVE: leaveSgeAlrgve(dbswdbe); break;
				case VecVSge::ALRXER: leaveSgeAlrxer(dbswdbe); break;
				case VecVSge::STADONE: leaveSgeStadone(dbswdbe); break;
				case VecVSge::UPKIDLE: leaveSgeUpkidle(dbswdbe); break;
				case VecVSge::UNPACK: leaveSgeUnpack(dbswdbe); break;
				case VecVSge::UPKDONE: leaveSgeUpkdone(dbswdbe); break;
				case VecVSge::CLGIDLE: leaveSgeClgidle(dbswdbe); break;
				case VecVSge::CLONEGIT: leaveSgeClonegit(dbswdbe); break;
				case VecVSge::CLGDONE: leaveSgeClgdone(dbswdbe); break;
				case VecVSge::EXTRACT: leaveSgeExtract(dbswdbe); break;
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
			case VecVSge::ALRGNF: _ixVSge = enterSgeAlrgnf(dbswdbe, reenter); break;
			case VecVSge::ALRGAD: _ixVSge = enterSgeAlrgad(dbswdbe, reenter); break;
			case VecVSge::ALRGVE: _ixVSge = enterSgeAlrgve(dbswdbe, reenter); break;
			case VecVSge::ALRXER: _ixVSge = enterSgeAlrxer(dbswdbe, reenter); break;
			case VecVSge::STADONE: _ixVSge = enterSgeStadone(dbswdbe, reenter); break;
			case VecVSge::UPKIDLE: _ixVSge = enterSgeUpkidle(dbswdbe, reenter); break;
			case VecVSge::UNPACK: _ixVSge = enterSgeUnpack(dbswdbe, reenter); break;
			case VecVSge::UPKDONE: _ixVSge = enterSgeUpkdone(dbswdbe, reenter); break;
			case VecVSge::CLGIDLE: _ixVSge = enterSgeClgidle(dbswdbe, reenter); break;
			case VecVSge::CLONEGIT: _ixVSge = enterSgeClonegit(dbswdbe, reenter); break;
			case VecVSge::CLGDONE: _ixVSge = enterSgeClgdone(dbswdbe, reenter); break;
			case VecVSge::EXTRACT: _ixVSge = enterSgeExtract(dbswdbe, reenter); break;
			case VecVSge::PACK: _ixVSge = enterSgePack(dbswdbe, reenter); break;
			case VecVSge::FAIL: _ixVSge = enterSgeFail(dbswdbe, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswdbe, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWdbeRlsStareptr::getSquawk(
			DbsWdbe* dbswdbe
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::STADONE) || (ixVSge == VecVSge::UNPACK) || (ixVSge == VecVSge::UPKDONE) || (ixVSge == VecVSge::CLONEGIT) || (ixVSge == VecVSge::CLGDONE) || (ixVSge == VecVSge::EXTRACT) || (ixVSge == VecVSge::PACK) ) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			if (ixVSge == VecVSge::STADONE) retval = "repository transaction started";
			else if (ixVSge == VecVSge::UNPACK) retval = "unpacking base repository";
			else if (ixVSge == VecVSge::UPKDONE) retval = "base repository unpacked";
			else if (ixVSge == VecVSge::CLONEGIT) {
				mGitprg.lock("DlgWdbeRlsStareptr", "getSquawk");
				retval = "cloning Git repository at " + xchg->getTxtvalPreset(VecWdbeVPreset::PREWDBEGITURL, jref) + gitprg;
				mGitprg.unlock("DlgWdbeRlsStareptr", "getSquawk");
			} else if (ixVSge == VecVSge::CLGDONE) retval = "Git repository cloned";
			else if (ixVSge == VecVSge::EXTRACT) retval = "extracting insertion points";
			else if (ixVSge == VecVSge::PACK) retval = "packing result";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

uint DlgWdbeRlsStareptr::enterSgeIdle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWdbeRlsStareptr::leaveSgeIdle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWdbeRlsStareptr::enterSgeAlrgnf(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::ALRGNF;
	nextIxVSgeSuccess = VecVSge::IDLE;

	ContInfWdbeAlert continf;
	// IP enterSgeAlrgnf --- RBEGIN
	continf.TxtCpt = VecWdbeVTag::getTitle(VecWdbeVTag::ERROR, ixWdbeVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		continf.TxtMsg1 = "Unable to locate Git repository at " + xchg->getTxtvalPreset(VecWdbeVPreset::PREWDBEGITURL, jref) + ".";
	};

	feedFMcbAlert.clear();

	VecWdbeVTag::appendToFeed(VecWdbeVTag::OK, ixWdbeVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();

	// IP enterSgeAlrgnf --- REND
	xchg->submitDpch(new DpchEngWdbeAlert(jref, &continf, &feedFMcbAlert, {DpchEngWdbeAlert::ALL}));

	return retval;
};

void DlgWdbeRlsStareptr::leaveSgeAlrgnf(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAlrgnf --- INSERT
};

uint DlgWdbeRlsStareptr::enterSgeAlrgad(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::ALRGAD;
	nextIxVSgeSuccess = VecVSge::IDLE;

	ContInfWdbeAlert continf;
	// IP enterSgeAlrgad --- RBEGIN
	continf.TxtCpt = VecWdbeVTag::getTitle(VecWdbeVTag::ERROR, ixWdbeVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		continf.TxtMsg1 = "Access to Git repository at " + xchg->getTxtvalPreset(VecWdbeVPreset::PREWDBEGITURL, jref) + " denied for user " + usrsref + ".";
	};

	feedFMcbAlert.clear();

	VecWdbeVTag::appendToFeed(VecWdbeVTag::OK, ixWdbeVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();

	// IP enterSgeAlrgad --- REND
	xchg->submitDpch(new DpchEngWdbeAlert(jref, &continf, &feedFMcbAlert, {DpchEngWdbeAlert::ALL}));

	return retval;
};

void DlgWdbeRlsStareptr::leaveSgeAlrgad(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAlrgad --- INSERT
};

uint DlgWdbeRlsStareptr::enterSgeAlrgve(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::ALRGVE;
	nextIxVSgeSuccess = VecVSge::IDLE;

	ContInfWdbeAlert continf;
	// IP enterSgeAlrgve --- RBEGIN
	continf.TxtCpt = VecWdbeVTag::getTitle(VecWdbeVTag::ERROR, ixWdbeVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		continf.TxtMsg1 = "Version error for Git repository at " + xchg->getTxtvalPreset(VecWdbeVPreset::PREWDBEGITURL, jref) + ".";
		continf.TxtMsg2 = "Tag of latest commit is " + acttag + " and not " + exptag + " as expected.";
	};

	feedFMcbAlert.clear();

	VecWdbeVTag::appendToFeed(VecWdbeVTag::OK, ixWdbeVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();

	// IP enterSgeAlrgve --- REND
	xchg->submitDpch(new DpchEngWdbeAlert(jref, &continf, &feedFMcbAlert, {DpchEngWdbeAlert::ALL}));

	return retval;
};

void DlgWdbeRlsStareptr::leaveSgeAlrgve(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAlrgve --- INSERT
};

uint DlgWdbeRlsStareptr::enterSgeAlrxer(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::ALRXER;
	nextIxVSgeSuccess = VecVSge::IDLE;

	ContInfWdbeAlert continf;
	// IP enterSgeAlrxer --- RBEGIN
	continf.TxtCpt = VecWdbeVTag::getTitle(VecWdbeVTag::ERROR, ixWdbeVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		continf.TxtMsg1 = "Extraction error. View log file for details.";
	};

	feedFMcbAlert.clear();

	VecWdbeVTag::appendToFeed(VecWdbeVTag::OK, ixWdbeVLocale, feedFMcbAlert);

	nextIxVSgeSuccess = VecVSge::FAIL;
	// IP enterSgeAlrxer --- REND
	xchg->submitDpch(new DpchEngWdbeAlert(jref, &continf, &feedFMcbAlert, {DpchEngWdbeAlert::ALL}));

	return retval;
};

void DlgWdbeRlsStareptr::leaveSgeAlrxer(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAlrxer --- INSERT
};

uint DlgWdbeRlsStareptr::enterSgeStadone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::STADONE;

	// IP enterSgeStadone --- IBEGIN

	if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXBASEREPTYPE, jref) == VecWdbeVBasereptype::VOID) retval = VecVSge::DONE;

	// IP enterSgeStadone --- IEND

	return retval;
};

void DlgWdbeRlsStareptr::leaveSgeStadone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeStadone --- INSERT
};

uint DlgWdbeRlsStareptr::enterSgeUpkidle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::UPKIDLE;
	nextIxVSgeSuccess = VecVSge::UNPACK;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgeUpkidle --- INSERT

	return retval;
};

void DlgWdbeRlsStareptr::leaveSgeUpkidle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeUpkidle --- INSERT
};

uint DlgWdbeRlsStareptr::enterSgeUnpack(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::UPKDONE;
	retval = nextIxVSgeSuccess;

	// IP enterSgeUnpack --- IBEGIN

	// assume .tgz input file archive
	Wdbe::run("mv " + infilename + " " + infilename + ".tgz");

	Wdbe::untgz(infilename + ".tgz", xchg->tmppath + "/" + xchg->getTxtvalPreset(VecWdbeVPreset::PREWDBEREPFOLDER, jref));

	// IP enterSgeUnpack --- IEND

	return retval;
};

void DlgWdbeRlsStareptr::leaveSgeUnpack(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeUnpack --- INSERT
};

uint DlgWdbeRlsStareptr::enterSgeUpkdone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::UPKDONE;

	// IP enterSgeUpkdone --- INSERT

	return retval;
};

void DlgWdbeRlsStareptr::leaveSgeUpkdone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeUpkdone --- INSERT
};

uint DlgWdbeRlsStareptr::enterSgeClgidle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::CLGIDLE;
	nextIxVSgeSuccess = VecVSge::CLONEGIT;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgeClgidle --- INSERT

	return retval;
};

void DlgWdbeRlsStareptr::leaveSgeClgidle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeClgidle --- INSERT
};

uint DlgWdbeRlsStareptr::enterSgeClonegit(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::CLGDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IDLE;

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);

	// IP enterSgeClonegit --- IBEGIN

	ubigint ref;

	WdbeMVersion* bvr = NULL;

	int res;
	bool valid;

	const git_error* err;

	char hashbuf[GIT_OID_HEXSZ+1];
	memset(hashbuf, 0, GIT_OID_HEXSZ+1);

	git_repository* rep = NULL;
	git_remote* remote = NULL;

	git_remote_callbacks cbs = GIT_REMOTE_CALLBACKS_INIT;

	const git_remote_head** ls = NULL;
	const git_remote_head* lsitem;

	git_clone_options cloneopts = GIT_CLONE_OPTIONS_INIT;
	git_checkout_options checkoutopts = GIT_CHECKOUT_OPTIONS_INIT;

	string giturl;

	string testfolder;
	string repfolder;

	string headtag;
	string bvritag;
	string bvrftag;

	string hash;

	string headhash;
	string bvrihash;
	string bvrfhash;

	string s, s2;

	size_t size;

	git_libgit2_init();

	giturl = xchg->getTxtvalPreset(VecWdbeVPreset::PREWDBEGITURL, jref);

	gitprg = "";

	testfolder = xchg->tmppath + "/" + Tmp::newfolder(xchg->tmppath);
	repfolder = xchg->tmppath + "/" + xchg->getTxtvalPreset(VecWdbeVPreset::PREWDBEREPFOLDER, jref);

	// --- assemble allowed tags for base version
	dbswdbe->loadRefBySQL("SELECT bvrRefWdbeMVersion FROM TblWdbeMVersion WHERE ref = " + to_string(xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref)), ref);

	if (dbswdbe->tblwdbemversion->loadRecByRef(ref, &bvr)) {
		bvritag = "v" + to_string(bvr->Major) + "." + to_string(bvr->Minor) + "." + to_string(bvr->Sub) + "i";
		bvrftag = "v" + to_string(bvr->Major) + "." + to_string(bvr->Minor) + "." + to_string(bvr->Sub) + "f";

		delete bvr;
	};

	// --- validate remote connectivity and tag of latest commit

	// -- connect to remote
	res = git_repository_init(&rep, testfolder.c_str(), false);
	valid = (res == 0);

	if (!valid) {
		err = giterr_last();
		cout << "error on git_repository_init(): " << err->message << endl;

		retval = nextIxVSgeFailure;
	};

	if (valid) {
		git_remote_set_url(rep, "origin", giturl.c_str());

		res = git_remote_lookup(&remote, rep, "origin"); // actually, only the parser correctnes is checked here!
		valid = (res == 0);

		if (!valid) {
			cout << "error: origin remote location not found" << endl;

			retval = VecVSge::ALRGNF;
		};
	};

	if (valid) {
		cbs.credentials = gitCredCallback;
		cbs.payload = this;

		res = git_remote_connect(remote, GIT_DIRECTION_FETCH, &cbs, NULL, NULL);
		valid = (res == 0);

		if (!valid) {
			// differentiate result - ex.:
			// Failed to connect to 192.168.0.10: Connection refused -> ALRGAD
			// fatal: 'idhx.git' does not appear to be a git repository -> ALRGNF

			err = giterr_last();
			cout << "error on git_remote_connect(): " << err->message << endl;

			retval = VecVSge::ALRGAD;
		};
	};

	// -- fetch remote listing
	if (valid) {
		res = git_remote_ls(&ls, &size, remote);
		valid = (res == 0);

		if (!valid) {
			err = giterr_last();
			cout << "error on git_remote_ls(): " << err->message << endl;

			retval = nextIxVSgeFailure;
		};
	};

	// -- look for relevant oid's
	if (valid) {
		s = "refs/tags/" + bvritag + "^{}";
		s2 = "refs/tags/" + bvrftag + "^{}";
		for (size_t i=0;i<size;i++) {
			lsitem = ls[i];

			git_oid_fmt(hashbuf, &(lsitem->oid));
			hash = hashbuf;

			if ((headhash != "") && (hash == headhash)) {
				headtag = lsitem->name;
				if (headtag.find("refs/tags/") == 0) headtag = headtag.substr(10);
				if ((headtag.length() > 3) && ((headtag.rfind("^{}")+3) == headtag.length())) headtag = headtag.substr(0, headtag.length()-3);
			};

			if (strcmp(lsitem->name, "HEAD") == 0) {
				headhash = hash;
			} else if (strcmp(lsitem->name, s.c_str()) == 0) {
				bvrihash = hash;
			} else if (strcmp(lsitem->name, s2.c_str()) == 0) {
				bvrfhash = hash;
			};
		};

		if (headhash == "") {
			valid = false;
			cout << "error: HEAD commit not listed" << endl;
			retval = nextIxVSgeFailure;

		} else if (bvrfhash != "") {
			if (headhash != bvrfhash) {
				valid = false;
				cout << "error: HEAD commit does not equal base version commit " << bvrftag << endl;

				acttag = headtag;
				exptag = bvrftag;

				retval = VecVSge::ALRGVE;
			};

		} else if (bvrihash != "") {
			if (headhash != bvrihash) {
				valid = false;
				cout << "error: HEAD commit does not equal base version commit " << bvritag << endl;

				acttag = headtag;
				exptag = bvritag;

				retval = VecVSge::ALRGVE;
			};

		} else {
			valid = false;
			cout << "error: base version commit not listed" << endl;

			retval = nextIxVSgeFailure;
		};
	};

	// -- clean up
	if (remote) {
		git_remote_disconnect(remote);
		git_remote_free(remote);
		remote = NULL;
	};

	if (rep) {
		git_repository_free(rep);
		rep = NULL;
	};

	// --- clone from remote repository using SSH
	// ex.: git clone git@github.com/mpsitech/idhw /Users/epsi/.../xyza1234

	if (valid) {
		checkoutopts.checkout_strategy = GIT_CHECKOUT_SAFE;
		checkoutopts.progress_cb = gitCheckoutCallback;
		checkoutopts.progress_payload = this;

		cloneopts.checkout_opts = checkoutopts;
		cloneopts.fetch_opts.callbacks.transfer_progress = &gitFetchCallback;
		cloneopts.fetch_opts.callbacks.credentials = gitCredCallback;
		cloneopts.fetch_opts.callbacks.payload = this;

		res = git_clone(&rep, giturl.c_str(), repfolder.c_str(), &cloneopts);
		valid = (res == 0);

		if (!valid) {
			err = giterr_last();
			cout << "error on git_clone(): " << err->message << endl;

			retval = nextIxVSgeFailure;
		};
	};

	// -- clean up
	if (rep) {
		git_repository_free(rep);
		rep = NULL;
	};

	git_libgit2_shutdown();

	// IP enterSgeClonegit --- IEND

	return retval;
};

void DlgWdbeRlsStareptr::leaveSgeClonegit(
			DbsWdbe* dbswdbe
		) {
	invalidateWakeups();
	// IP leaveSgeClonegit --- INSERT
};

uint DlgWdbeRlsStareptr::enterSgeClgdone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::CLGDONE;

	// IP enterSgeClgdone --- INSERT

	return retval;
};

void DlgWdbeRlsStareptr::leaveSgeClgdone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeClgdone --- INSERT
};

uint DlgWdbeRlsStareptr::enterSgeExtract(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::EXTRACT;
	nextIxVSgeSuccess = VecVSge::PACK;
	nextIxVSgeFailure = VecVSge::ALRXER;

	clearInvs();

	// IP enterSgeExtract --- IBEGIN

	// invoke WdbePrctreeExtract
	addInv(new DpchInvWdbePrctreeExtract(0, 0, "", xchg->getTxtvalPreset(VecWdbeVPreset::PREWDBEREPFOLDER, jref), "", xchg->getTxtvalPreset(VecWdbeVPreset::PREWDBEEXTFOLDER, jref)));

	// IP enterSgeExtract --- IEND

	submitInvs(dbswdbe, retval, retval);
	return retval;
};

void DlgWdbeRlsStareptr::leaveSgeExtract(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeExtract --- INSERT
};

uint DlgWdbeRlsStareptr::enterSgePack(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	// IP enterSgePack --- IBEGIN

	ListWdbeMFile fils;
	WdbeMFile* fil = NULL;

	ubigint refWdbeMVersion;
	string Prjshort;

	ubigint bvrRefWdbeMVersion;

	string tgzfile;

	vector<string> folders;

	string s, s2;

	refWdbeMVersion = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref);
	Prjshort = Wdbe::getPrjshort(dbswdbe, refWdbeMVersion);

	// .tgz result folder
	tgzfile = Tmp::newfile(xchg->tmppath, "tgz");
	Wdbe::tgz(xchg->tmppath + "/" + xchg->getTxtvalPreset(VecWdbeVPreset::PREWDBEEXTFOLDER, jref), xchg->tmppath + "/" + tgzfile);

	// store in archive with reference to base version
	if (dbswdbe->loadRefBySQL("SELECT bvrRefWdbeMVersion FROM TblWdbeMVersion WHERE ref = " + to_string(refWdbeMVersion), bvrRefWdbeMVersion))
				Acv::addfile(dbswdbe, xchg->acvpath, xchg->tmppath + "/" + tgzfile, xchg->getRefPreset(VecWdbeVPreset::PREWDBEGROUP, jref), xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref), VecWdbeVMFileRefTbl::VER, bvrRefWdbeMVersion, "custip", "custip.tgz", "tgz", "");

	s = xchg->getTxtvalPreset(VecWdbeVPreset::PREWDBEREPFOLDER, jref);
	if ((xchg->tmppath != "") && (s != "")) {
		s = xchg->tmppath + "/" + s;

		if (access(s.c_str(), R_OK) == 0) {
			// empty out repository folder only affecting _ini, _mdl, _rls, devxxxx and xxxx subfolders
			folders.push_back("_ini");
			folders.push_back("_mdl");
			folders.push_back("_rls");
			folders.push_back("dev" + StrMod::lc(Prjshort));
			folders.push_back(StrMod::lc(Prjshort));

			for (unsigned int i = 0; i < folders.size();i++) {
				if (folders[i] != "") {
					s2 = s + "/" + folders[i];
					if (access(s2.c_str(), R_OK) == 0) Wdbe::run("rm -rf " + s2);
				};
			};

			// copy model files into _mdl subfolder
			s2 = s + "/_mdl";
#ifdef _WIN32
			if (access(s2.c_str(), W_OK) == -1) mkdir(s2.c_str());
#else
			if (access(s2.c_str(), W_OK) == -1) mkdir(s2.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
#endif

			dbswdbe->tblwdbemfile->loadRstBySQL("SELECT * FROM TblWdbeMFile WHERE refIxVTbl = " + to_string(VecWdbeVMFileRefTbl::VER) + " AND refUref = " + to_string(refWdbeMVersion) + " AND osrefKContent = 'mod'", false, fils);
			for (unsigned int i = 0; i < fils.nodes.size(); i++) {
				fil = fils.nodes[i];
				Wdbe::run("cp " + xchg->acvpath + "/" + Acv::getfile(dbswdbe, fil->ref) + " " + s2 + "/" + fil->Filename);
			};
		};
	};

	// IP enterSgePack --- IEND

	return retval;
};

void DlgWdbeRlsStareptr::leaveSgePack(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgePack --- INSERT
};

uint DlgWdbeRlsStareptr::enterSgeFail(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::FAIL;

	// IP enterSgeFail --- INSERT

	return retval;
};

void DlgWdbeRlsStareptr::leaveSgeFail(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeFail --- INSERT
};

uint DlgWdbeRlsStareptr::enterSgeDone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void DlgWdbeRlsStareptr::leaveSgeDone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeDone --- INSERT
};
