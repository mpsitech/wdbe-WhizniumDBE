/**
	* \file DlgWdbeVerFinmod.cpp
	* job handler for job DlgWdbeVerFinmod (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbed.h>
#endif

#include "DlgWdbeVerFinmod.h"

#include "DlgWdbeVerFinmod_blks.cpp"
#include "DlgWdbeVerFinmod_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWdbeVerFinmod
 ******************************************************************************/

DlgWdbeVerFinmod::DlgWdbeVerFinmod(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::DLGWDBEVERFINMOD, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFDse.tag = "FeedFDse";
	VecVDit::fillFeed(ixWdbeVLocale, feedFDse);
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	license = NULL;

	// IP constructor.cust1 --- INSERT

	ixVDit = VecVDit::FNM;

	license = new JobWdbeLicense(xchg, dbswdbe, jref, ixWdbeVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswdbe, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgWdbeVerFinmod::~DlgWdbeVerFinmod() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* DlgWdbeVerFinmod::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &continffnm, &continflfi, &feedFDse, &feedFSge, &statshr, &statshrfnm, &statshrlfi, items);
	};

	return dpcheng;
};

void DlgWdbeVerFinmod::refreshFnm(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShrFnm oldStatshrfnm(statshrfnm);
	ContInfFnm oldContinffnm(continffnm);

	// IP refreshFnm --- RBEGIN
	// continffnm
	continffnm.TxtPrg = getSquawk(dbswdbe);

	// statshrfnm
	statshrfnm.ButRunActive = evalFnmButRunActive(dbswdbe);
	statshrfnm.ButStoActive = evalFnmButStoActive(dbswdbe);

	// IP refreshFnm --- REND
	if (statshrfnm.diff(&oldStatshrfnm).size() != 0) insert(moditems, DpchEngData::STATSHRFNM);
	if (continffnm.diff(&oldContinffnm).size() != 0) insert(moditems, DpchEngData::CONTINFFNM);
};

void DlgWdbeVerFinmod::refreshLfi(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContInfLfi oldContinflfi(continflfi);
	StatShrLfi oldStatshrlfi(statshrlfi);

	// IP refreshLfi --- BEGIN
	// continflfi

	// statshrlfi
	statshrlfi.DldActive = evalLfiDldActive(dbswdbe);

	// IP refreshLfi --- END
	if (continflfi.diff(&oldContinflfi).size() != 0) insert(moditems, DpchEngData::CONTINFLFI);
	if (statshrlfi.diff(&oldStatshrlfi).size() != 0) insert(moditems, DpchEngData::STATSHRLFI);
};

void DlgWdbeVerFinmod::refresh(
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

	refreshFnm(dbswdbe, moditems);
	refreshLfi(dbswdbe, moditems);

	muteRefresh = false;
};

void DlgWdbeVerFinmod::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEVERFINMODDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswdbe, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEVERFINMODDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbswdbe, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoFnm != 0) {
				if (dpchappdo->ixVDoFnm == VecVDoFnm::BUTRUNCLICK) {
					handleDpchAppDoFnmButRunClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDoFnm == VecVDoFnm::BUTSTOCLICK) {
					handleDpchAppDoFnmButStoClick(dbswdbe, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEALERT) {
			handleDpchAppWdbeAlert(dbswdbe, (DpchAppWdbeAlert*) (req->dpchapp), &(req->dpcheng));

		};

	} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::DOWNLOAD) {
		if (ixVSge == VecVSge::FAIL) req->filename = handleDownloadInSgeFail(dbswdbe);
		else if (ixVSge == VecVSge::DONE) req->filename = handleDownloadInSgeDone(dbswdbe);

	} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::DPCHRET) {
		if (req->dpchret->ixOpVOpres == VecOpVOpres::PROGRESS) {
			// IP handleRequest.opprogress --- INSERT
		} else {
			if (req->dpchret->ixWdbeVDpch == VecWdbeVDpch::DPCHRETWDBE) {
				handleDpchRetWdbe(dbswdbe, (DpchRetWdbe*) (req->dpchret));
			} else if (req->dpchret->ixWdbeVDpch == VecWdbeVDpch::DPCHRETWDBEGENTEST) {
				handleDpchRetWdbeGenTest(dbswdbe, (DpchRetWdbeGenTest*) (req->dpchret));
			} else if (req->dpchret->ixWdbeVDpch == VecWdbeVDpch::DPCHRETWDBEGENWIRING) {
				handleDpchRetWdbeGenWiring(dbswdbe, (DpchRetWdbeGenWiring*) (req->dpchret));
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
		if ((req->sref == "mon") && (ixVSge == VecVSge::GENTST)) handleTimerWithSrefMonInSgeGentst(dbswdbe);
		else if ((req->sref == "mon") && (ixVSge == VecVSge::GENWRI)) handleTimerWithSrefMonInSgeGenwri(dbswdbe);
		else if ((req->sref == "mon") && (ixVSge == VecVSge::GENSV)) handleTimerWithSrefMonInSgeGensv(dbswdbe);
	};
};

void DlgWdbeVerFinmod::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWdbeVerFinmod::handleDpchAppDataContiac(
			DbsWdbe* dbswdbe
			, ContIac* _contiac
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFDSE)) {
		if ((_contiac->numFDse >= VecVDit::FNM) && (_contiac->numFDse <= VecVDit::LFI)) ixVDit = _contiac->numFDse;
		refresh(dbswdbe, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgWdbeVerFinmod::handleDpchAppDoButDneClick(
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

void DlgWdbeVerFinmod::handleDpchAppDoFnmButRunClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoFnmButRunClick --- BEGIN
	if (statshrfnm.ButRunActive) {
		changeStage(dbswdbe, VecVSge::GENTST, dpcheng);
	};
	// IP handleDpchAppDoFnmButRunClick --- END
};

void DlgWdbeVerFinmod::handleDpchAppDoFnmButStoClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoFnmButStoClick --- INSERT
};

void DlgWdbeVerFinmod::handleDpchAppWdbeAlert(
			DbsWdbe* dbswdbe
			, DpchAppWdbeAlert* dpchappwdbealert
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppWdbeAlert --- IBEGIN
	if (ixVSge == VecVSge::ALRWER) {
		changeStage(dbswdbe, nextIxVSgeSuccess);
	};
	// IP handleDpchAppWdbeAlert --- IEND
};

void DlgWdbeVerFinmod::handleDpchRetWdbe(
			DbsWdbe* dbswdbe
			, DpchRetWdbe* dpchret
		) {
	// IP handleDpchRetWdbe --- INSERT
};

void DlgWdbeVerFinmod::handleDpchRetWdbeGenTest(
			DbsWdbe* dbswdbe
			, DpchRetWdbeGenTest* dpchret
		) {
	// IP handleDpchRetWdbeGenTest --- INSERT
};

void DlgWdbeVerFinmod::handleDpchRetWdbeGenWiring(
			DbsWdbe* dbswdbe
			, DpchRetWdbeGenWiring* dpchret
		) {
	// IP handleDpchRetWdbeGenWiring --- IBEGIN
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
	// IP handleDpchRetWdbeGenWiring --- IEND
};

string DlgWdbeVerFinmod::handleDownloadInSgeFail(
			DbsWdbe* dbswdbe
		) {
	return(xchg->tmppath + "/" + logfile); // IP handleDownloadInSgeFail --- RLINE
};

string DlgWdbeVerFinmod::handleDownloadInSgeDone(
			DbsWdbe* dbswdbe
		) {
	return(""); // IP handleDownloadInSgeDone --- LINE
};

void DlgWdbeVerFinmod::handleTimerWithSrefMonInSgeGentst(
			DbsWdbe* dbswdbe
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	refreshWithDpchEng(dbswdbe); // IP handleTimerWithSrefMonInSgeGentst --- ILINE
};

void DlgWdbeVerFinmod::handleTimerWithSrefMonInSgeGenwri(
			DbsWdbe* dbswdbe
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	refreshWithDpchEng(dbswdbe); // IP handleTimerWithSrefMonInSgeGenwri --- ILINE
};

void DlgWdbeVerFinmod::handleTimerWithSrefMonInSgeGensv(
			DbsWdbe* dbswdbe
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	refreshWithDpchEng(dbswdbe); // IP handleTimerWithSrefMonInSgeGensv --- ILINE
};

void DlgWdbeVerFinmod::changeStage(
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
				case VecVSge::GENTST: leaveSgeGentst(dbswdbe); break;
				case VecVSge::GENWRI: leaveSgeGenwri(dbswdbe); break;
				case VecVSge::ASMLFI: leaveSgeAsmlfi(dbswdbe); break;
				case VecVSge::GENSV: leaveSgeGensv(dbswdbe); break;
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
			case VecVSge::GENTST: _ixVSge = enterSgeGentst(dbswdbe, reenter); break;
			case VecVSge::GENWRI: _ixVSge = enterSgeGenwri(dbswdbe, reenter); break;
			case VecVSge::ASMLFI: _ixVSge = enterSgeAsmlfi(dbswdbe, reenter); break;
			case VecVSge::GENSV: _ixVSge = enterSgeGensv(dbswdbe, reenter); break;
			case VecVSge::SYNC: _ixVSge = enterSgeSync(dbswdbe, reenter); break;
			case VecVSge::FAIL: _ixVSge = enterSgeFail(dbswdbe, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswdbe, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWdbeVerFinmod::getSquawk(
			DbsWdbe* dbswdbe
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::GENTST) || (ixVSge == VecVSge::GENWRI) || (ixVSge == VecVSge::ASMLFI) || (ixVSge == VecVSge::GENSV) || (ixVSge == VecVSge::SYNC) ) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			if (ixVSge == VecVSge::GENTST) retval = "generating test infrastructure (" + to_string(opNSuccess + opNFailure) + "/" + to_string(opN) + " operations completed, last: " + getOpsqkLast() + ")";
			else if (ixVSge == VecVSge::GENWRI) retval = "generating inter-module wiring bottom-up (" + to_string(opNSuccess + opNFailure) + "/" + to_string(opN) + " operations completed, last: " + getOpsqkLast() + ")";
			else if (ixVSge == VecVSge::ASMLFI) retval = "assembling log file";
			else if (ixVSge == VecVSge::GENSV) retval = "filling standard vectors (" + to_string(opNSuccess + opNFailure) + "/" + to_string(opN) + " operations completed, last: " + getOpsqkLast() + ")";
			else if (ixVSge == VecVSge::SYNC) retval = "synchronizing build-ready version with licensing server";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint DlgWdbeVerFinmod::enterSgeIdle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWdbeVerFinmod::leaveSgeIdle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWdbeVerFinmod::enterSgeAlrwer(
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

void DlgWdbeVerFinmod::leaveSgeAlrwer(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAlrwer --- INSERT
};

uint DlgWdbeVerFinmod::enterSgeGentst(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::GENTST;
	nextIxVSgeSuccess = VecVSge::GENWRI;

	clearInvs();

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);

	// IP enterSgeGentst --- IBEGIN
	vector<ubigint> refs;

	ubigint refWdbeMVersion = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref);

	dbswdbe->loadRefsBySQL("SELECT TblWdbeMModule.ref FROM TblWdbeMModule, TblWdbeMUnit WHERE TblWdbeMModule.hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND TblWdbeMModule.hkUref = TblWdbeMUnit.ref AND TblWdbeMUnit.refIxVTbl = "
				+ to_string(VecWdbeVMUnitRefTbl::VER) + " AND TblWdbeMUnit.refUref = " + to_string(refWdbeMVersion) + " AND TblWdbeMUnit.ixVBasetype = " + to_string(VecWdbeVMUnitBasetype::FPGA) + " AND ((TblWdbeMModule.ixVBasetype = "
				+ to_string(VecWdbeVMModuleBasetype::HOSTIF) + ") OR (TblWdbeMModule.ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::EHOSTIF) + ") OR (TblWdbeMModule.ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::CTR)
				+ ") OR (TblWdbeMModule.ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::FWDCTR) + ") OR (TblWdbeMModule.ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::ECTR) + ") OR (TblWdbeMModule.ixVBasetype = "
				+ to_string(VecWdbeVMModuleBasetype::OTH) + "))", false, refs);

	for (unsigned int i = 0; i < refs.size(); i++) addInv(new DpchInvWdbeGenTest(0, 0, refs[i]));
	// IP enterSgeGentst --- IEND

	submitInvs(dbswdbe, VecVSge::GENWRI, retval);
	return retval;
};

void DlgWdbeVerFinmod::leaveSgeGentst(
			DbsWdbe* dbswdbe
		) {
	invalidateWakeups();
	// IP leaveSgeGentst --- INSERT
};

uint DlgWdbeVerFinmod::enterSgeGenwri(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::GENWRI;
	nextIxVSgeSuccess = VecVSge::GENWRI;
	nextIxVSgeFailure = VecVSge::ASMLFI;

	clearInvs();

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);

	// IP enterSgeGenwri --- IBEGIN

	// modules bottom-up order, not respecting unit hierarchy ; only LVDS primitives may be added in the process

	ubigint refWdbeMVersion = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref);

	WdbeMModule* mdl = NULL;

	DpchInvWdbe* dpchinv = NULL;

	unsigned int lvl;

	map<ubigint, string> srefKToolchs; // by unt->ref
	string srefKToolch;

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
			srefKToolch = "";

			auto it = srefKToolchs.find(mdl->hkUref);

			if (it != srefKToolchs.end()) srefKToolch = it->second;
			else if (dbswdbe->loadStringBySQL("SELECT srefKToolch FROM TblWdbeMUnit WHERE ref = " + to_string(mdl->hkUref), srefKToolch)) srefKToolchs[mdl->hkUref] = srefKToolch;

			dpchinv = new DpchInvWdbeGenWiring(0, 0, mdl->ref, srefKToolch);
			addInv(dpchinv);
			orefsToRefs[dpchinv->oref] = mdl->ref;

			refsMod.insert(mdl->ref);
		};
	};

	// IP enterSgeGenwri --- IEND

	submitInvs(dbswdbe, VecVSge::GENSV, retval);
	return retval;
};

void DlgWdbeVerFinmod::leaveSgeGenwri(
			DbsWdbe* dbswdbe
		) {
	invalidateWakeups();
	// IP leaveSgeGenwri --- IBEGIN
	mdls.clear();
	lvlsMdls.clear();

	refsMod.clear();
	// IP leaveSgeGenwri --- IEND
};

uint DlgWdbeVerFinmod::enterSgeAsmlfi(
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

void DlgWdbeVerFinmod::leaveSgeAsmlfi(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAsmlfi --- INSERT
};

uint DlgWdbeVerFinmod::enterSgeGensv(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::GENSV;
	nextIxVSgeSuccess = VecVSge::SYNC;

	clearInvs();

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);

	// IP enterSgeGensv --- IBEGIN

	vector<ubigint> refs;

	ubigint refWdbeMVersion = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref);

	dbswdbe->loadRefsBySQL("SELECT ref FROM TblWdbeMUnit WHERE refIxVTbl = " + to_string(VecWdbeVMUnitRefTbl::VER) + " AND refUref = " + to_string(refWdbeMVersion), false, refs);
	for (unsigned int i = 0; i < refs.size(); i++) addInv(new DpchInvWdbeGenStdvec(0, 0, refs[i]));

	// IP enterSgeGensv --- IEND

	submitInvs(dbswdbe, retval, retval);
	return retval;
};

void DlgWdbeVerFinmod::leaveSgeGensv(
			DbsWdbe* dbswdbe
		) {
	invalidateWakeups();
	// IP leaveSgeGensv --- IBEGIN
	WdbeMVersion* ver = NULL;

	if (dbswdbe->tblwdbemversion->loadRecByRef(xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref), &ver)) {
		Wdbe::updateVerste(dbswdbe, ver->ref, VecWdbeVMVersionState::READY);

		// make project's current version
		dbswdbe->executeQuery("UPDATE TblWdbeMProject SET refWdbeMVersion = " + to_string(ver->ref) + " WHERE ref = " + to_string(ver->prjRefWdbeMProject));

		xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBEPRJMOD, jref);
		xchg->triggerRefCall(dbswdbe, VecWdbeVCall::CALLWDBEVERMOD_PRJEQ, jref, ver->prjRefWdbeMProject);

		delete ver;
	};
	// IP leaveSgeGensv --- IEND
};

uint DlgWdbeVerFinmod::enterSgeSync(
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

void DlgWdbeVerFinmod::leaveSgeSync(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeSync --- INSERT
};

uint DlgWdbeVerFinmod::enterSgeFail(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::FAIL;

	// IP enterSgeFail --- INSERT

	return retval;
};

void DlgWdbeVerFinmod::leaveSgeFail(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeFail --- INSERT
};

uint DlgWdbeVerFinmod::enterSgeDone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void DlgWdbeVerFinmod::leaveSgeDone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeDone --- INSERT
};
