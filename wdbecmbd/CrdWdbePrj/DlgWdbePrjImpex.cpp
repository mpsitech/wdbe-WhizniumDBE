/**
	* \file DlgWdbePrjImpex.cpp
	* job handler for job DlgWdbePrjImpex (implementation)
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

#include "DlgWdbePrjImpex.h"

#include "DlgWdbePrjImpex_blks.cpp"
#include "DlgWdbePrjImpex_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWdbePrjImpex
 ******************************************************************************/

DlgWdbePrjImpex::DlgWdbePrjImpex(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::DLGWDBEPRJIMPEX, jrefSup, ixWdbeVLocale)
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
	iex = new JobWdbeIexPrj(xchg, dbswdbe, jref, ixWdbeVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswdbe, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgWdbePrjImpex::~DlgWdbePrjImpex() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* DlgWdbePrjImpex::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &continfimp, &continflfi, &feedFDse, &feedFSge, &statshr, &statshrifi, &statshrimp, &statshrlfi, items);
	};

	return dpcheng;
};

void DlgWdbePrjImpex::refreshIfi(
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

void DlgWdbePrjImpex::refreshImp(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShrImp oldStatshrimp(statshrimp);
	ContInfImp oldContinfimp(continfimp);

	// IP refreshImp --- RBEGIN
	// continfimp
	continfimp.TxtPrg = getSquawk(dbswdbe);

	// statshrimp
	statshrimp.ButAutActive = evalImpButAutActive(dbswdbe);
	statshrimp.ButRunActive = evalImpButRunActive(dbswdbe);
	statshrimp.ButStoActive = evalImpButStoActive(dbswdbe);

	// IP refreshImp --- REND
	if (statshrimp.diff(&oldStatshrimp).size() != 0) insert(moditems, DpchEngData::STATSHRIMP);
	if (continfimp.diff(&oldContinfimp).size() != 0) insert(moditems, DpchEngData::CONTINFIMP);
};

void DlgWdbePrjImpex::refreshLfi(
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

void DlgWdbePrjImpex::refresh(
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

	refreshIfi(dbswdbe, moditems);
	refreshImp(dbswdbe, moditems);
	refreshLfi(dbswdbe, moditems);

	muteRefresh = false;
};

void DlgWdbePrjImpex::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEPRJIMPEXDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswdbe, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEPRJIMPEXDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbswdbe, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoImp != 0) {
				if (dpchappdo->ixVDoImp == VecVDoImp::BUTAUTCLICK) {
					handleDpchAppDoImpButAutClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDoImp == VecVDoImp::BUTRUNCLICK) {
					handleDpchAppDoImpButRunClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDoImp == VecVDoImp::BUTSTOCLICK) {
					handleDpchAppDoImpButStoClick(dbswdbe, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEALERT) {
			handleDpchAppWdbeAlert(dbswdbe, (DpchAppWdbeAlert*) (req->dpchapp), &(req->dpcheng));

		};

	} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::UPLOAD) {
		if (ixVSge == VecVSge::IDLE) handleUploadInSgeIdle(dbswdbe, req->filename);

	} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::DOWNLOAD) {
		if (ixVSge == VecVSge::DONE) req->filename = handleDownloadInSgeDone(dbswdbe);

	} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::TIMER) {
		if ((req->sref == "mon") && (ixVSge == VecVSge::IMPORT)) handleTimerWithSrefMonInSgeImport(dbswdbe);
		else if (ixVSge == VecVSge::IMPIDLE) handleTimerInSgeImpidle(dbswdbe, req->sref);
		else if (ixVSge == VecVSge::PRSIDLE) handleTimerInSgePrsidle(dbswdbe, req->sref);
	};
};

void DlgWdbePrjImpex::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWdbePrjImpex::handleDpchAppDataContiac(
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

void DlgWdbePrjImpex::handleDpchAppDoButDneClick(
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

void DlgWdbePrjImpex::handleDpchAppDoImpButAutClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoImpButAutClick --- BEGIN
	if (statshrimp.ButAutActive) {
		changeStage(dbswdbe, VecVSge::AUTH, dpcheng);
	};
	// IP handleDpchAppDoImpButAutClick --- END
};

void DlgWdbePrjImpex::handleDpchAppDoImpButRunClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoImpButRunClick --- BEGIN
	if (statshrimp.ButRunActive) {
		changeStage(dbswdbe, VecVSge::IMPIDLE, dpcheng);
	};
	// IP handleDpchAppDoImpButRunClick --- END
};

void DlgWdbePrjImpex::handleDpchAppDoImpButStoClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoImpButStoClick --- INSERT
};

void DlgWdbePrjImpex::handleDpchAppWdbeAlert(
			DbsWdbe* dbswdbe
			, DpchAppWdbeAlert* dpchappwdbealert
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppWdbeAlert --- IBEGIN
	if (ixVSge == VecVSge::ALRWDBEPER) {
		changeStage(dbswdbe, nextIxVSgeSuccess);
	};
	// IP handleDpchAppWdbeAlert --- IEND
};

void DlgWdbePrjImpex::handleUploadInSgeIdle(
			DbsWdbe* dbswdbe
			, const string& filename
		) {
	infilename = filename; // IP handleUploadInSgeIdle --- ILINE
	changeStage(dbswdbe, VecVSge::PRSIDLE);
};

string DlgWdbePrjImpex::handleDownloadInSgeDone(
			DbsWdbe* dbswdbe
		) {
	return(""); // IP handleDownloadInSgeDone --- LINE
};

void DlgWdbePrjImpex::handleTimerWithSrefMonInSgeImport(
			DbsWdbe* dbswdbe
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	refreshWithDpchEng(dbswdbe); // IP handleTimerWithSrefMonInSgeImport --- ILINE
};

void DlgWdbePrjImpex::handleTimerInSgeImpidle(
			DbsWdbe* dbswdbe
			, const string& sref
		) {
	changeStage(dbswdbe, nextIxVSgeSuccess);
};

void DlgWdbePrjImpex::handleTimerInSgePrsidle(
			DbsWdbe* dbswdbe
			, const string& sref
		) {
	changeStage(dbswdbe, nextIxVSgeSuccess);
};

void DlgWdbePrjImpex::changeStage(
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
				case VecVSge::PRSIDLE: leaveSgePrsidle(dbswdbe); break;
				case VecVSge::PARSE: leaveSgeParse(dbswdbe); break;
				case VecVSge::ALRWDBEPER: leaveSgeAlrwdbeper(dbswdbe); break;
				case VecVSge::PRSDONE: leaveSgePrsdone(dbswdbe); break;
				case VecVSge::AUTH: leaveSgeAuth(dbswdbe); break;
				case VecVSge::AUTDONE: leaveSgeAutdone(dbswdbe); break;
				case VecVSge::IMPIDLE: leaveSgeImpidle(dbswdbe); break;
				case VecVSge::IMPORT: leaveSgeImport(dbswdbe); break;
				case VecVSge::ALRWDBEIER: leaveSgeAlrwdbeier(dbswdbe); break;
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
			case VecVSge::PRSIDLE: _ixVSge = enterSgePrsidle(dbswdbe, reenter); break;
			case VecVSge::PARSE: _ixVSge = enterSgeParse(dbswdbe, reenter); break;
			case VecVSge::ALRWDBEPER: _ixVSge = enterSgeAlrwdbeper(dbswdbe, reenter); break;
			case VecVSge::PRSDONE: _ixVSge = enterSgePrsdone(dbswdbe, reenter); break;
			case VecVSge::AUTH: _ixVSge = enterSgeAuth(dbswdbe, reenter); break;
			case VecVSge::AUTDONE: _ixVSge = enterSgeAutdone(dbswdbe, reenter); break;
			case VecVSge::IMPIDLE: _ixVSge = enterSgeImpidle(dbswdbe, reenter); break;
			case VecVSge::IMPORT: _ixVSge = enterSgeImport(dbswdbe, reenter); break;
			case VecVSge::ALRWDBEIER: _ixVSge = enterSgeAlrwdbeier(dbswdbe, reenter); break;
			case VecVSge::SYNC: _ixVSge = enterSgeSync(dbswdbe, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswdbe, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWdbePrjImpex::getSquawk(
			DbsWdbe* dbswdbe
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::PARSE) || (ixVSge == VecVSge::ALRWDBEPER) || (ixVSge == VecVSge::PRSDONE) || (ixVSge == VecVSge::AUTH) || (ixVSge == VecVSge::AUTDONE) || (ixVSge == VecVSge::IMPORT) || (ixVSge == VecVSge::ALRWDBEIER) || (ixVSge == VecVSge::SYNC) ) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing existing projects and versions";
			else if (ixVSge == VecVSge::ALRWDBEPER) retval = "parse error";
			else if (ixVSge == VecVSge::PRSDONE) retval = "existing projects and versions parsed";
			else if (ixVSge == VecVSge::AUTH) retval = "authenticating";
			else if (ixVSge == VecVSge::AUTDONE) retval = "authentication successful";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing existing projects and versions (" + to_string(iex->impcnt) + " records added)";
			else if (ixVSge == VecVSge::ALRWDBEIER) retval = "import error";
			else if (ixVSge == VecVSge::SYNC) retval = "synchronizing projects and versions with licensing server";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

uint DlgWdbePrjImpex::enterSgeIdle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWdbePrjImpex::leaveSgeIdle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWdbePrjImpex::enterSgeAlraer(
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

void DlgWdbePrjImpex::leaveSgeAlraer(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAlraer --- INSERT
};

uint DlgWdbePrjImpex::enterSgePrsidle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::PRSIDLE;
	nextIxVSgeSuccess = VecVSge::PARSE;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgePrsidle --- INSERT

	return retval;
};

void DlgWdbePrjImpex::leaveSgePrsidle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgePrsidle --- INSERT
};

uint DlgWdbePrjImpex::enterSgeParse(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::PRSDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::ALRWDBEPER;

	// IP enterSgeParse --- IBEGIN
	ifstream ififile;

	char* buf;
	string s;

	bool ifitxt;
	bool ifixml;

	iex->reset(dbswdbe);

	// check file type
	ififile.open(infilename.c_str(), ifstream::in);

	buf = new char[16];
	ififile.get(buf, 16);
	s = string(buf);

	ifitxt = (s.find("IexWdbePrj") == 0);
	ifixml = (s.find("<?xml") == 0);		

	delete[] buf;
	ififile.close();

	// parse file accordingly
	if (ifitxt) iex->parseFromFile(dbswdbe, infilename, false, "");
	else if (ifixml) iex->parseFromFile(dbswdbe, infilename, true, "");

	if (iex->ixVSge != JobWdbeIexPrj::VecVSge::PRSDONE) {
		if (reqCmd) {
			if (iex->ixVSge == JobWdbeIexPrj::VecVSge::PRSERR) cout << "\t" << iex->getSquawk(dbswdbe) << endl;
			else cout << "\tneither text-based nor XML file format recognized" << endl;

			retval = VecVSge::IDLE;

		} else {
			retval = nextIxVSgeFailure;
		};
	};
	// IP enterSgeParse --- IEND

	return retval;
};

void DlgWdbePrjImpex::leaveSgeParse(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeParse --- INSERT
};

uint DlgWdbePrjImpex::enterSgeAlrwdbeper(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::ALRWDBEPER;
	nextIxVSgeSuccess = VecVSge::IDLE;

	// IP enterSgeAlrwdbeper --- RBEGIN
	ContInfWdbeAlert continf;

	continf.TxtCpt = VecWdbeVTag::getTitle(VecWdbeVTag::ERROR, ixWdbeVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (iex->ixVSge == JobWdbeIexPrj::VecVSge::PRSERR) continf.TxtMsg1 = iex->getSquawk(dbswdbe);
	else continf.TxtMsg1 = "neither text-based nor XML file format recognized";

	feedFMcbAlert.clear();

	VecWdbeVTag::appendToFeed(VecWdbeVTag::OK, ixWdbeVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();

	xchg->submitDpch(new DpchEngWdbeAlert(jref, &continf, &feedFMcbAlert, {DpchEngWdbeAlert::ALL}));
	// IP enterSgeAlrwdbeper --- REND

	return retval;
};

void DlgWdbePrjImpex::leaveSgeAlrwdbeper(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAlrwdbeper --- INSERT
};

uint DlgWdbePrjImpex::enterSgePrsdone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::PRSDONE;

	// IP enterSgePrsdone --- INSERT

	return retval;
};

void DlgWdbePrjImpex::leaveSgePrsdone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgePrsdone --- INSERT
};

uint DlgWdbePrjImpex::enterSgeAuth(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::AUTDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::ALRAER;

	// IP enterSgeAuth --- IBEGIN
	if (!license->authPrjImpex(iex->imeimproject)) retval = nextIxVSgeFailure;
	// IP enterSgeAuth --- IEND

	return retval;
};

void DlgWdbePrjImpex::leaveSgeAuth(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAuth --- INSERT
};

uint DlgWdbePrjImpex::enterSgeAutdone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::AUTDONE;

	// IP enterSgeAutdone --- INSERT

	return retval;
};

void DlgWdbePrjImpex::leaveSgeAutdone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAutdone --- INSERT
};

uint DlgWdbePrjImpex::enterSgeImpidle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IMPIDLE;
	nextIxVSgeSuccess = VecVSge::IMPORT;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgeImpidle --- INSERT

	return retval;
};

void DlgWdbePrjImpex::leaveSgeImpidle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeImpidle --- INSERT
};

uint DlgWdbePrjImpex::enterSgeImport(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::SYNC;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::ALRWDBEIER;

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);

	// IP enterSgeImport --- IBEGIN
	iex->import(dbswdbe);

	if (iex->ixVSge == JobWdbeIexPrj::VecVSge::IMPERR) retval = nextIxVSgeFailure;
	else xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBEPRJMOD, jref);

	// IP enterSgeImport --- IEND

	return retval;
};

void DlgWdbePrjImpex::leaveSgeImport(
			DbsWdbe* dbswdbe
		) {
	invalidateWakeups();
	// IP leaveSgeImport --- INSERT
};

uint DlgWdbePrjImpex::enterSgeAlrwdbeier(
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

void DlgWdbePrjImpex::leaveSgeAlrwdbeier(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAlrwdbeier --- INSERT
};

uint DlgWdbePrjImpex::enterSgeSync(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	// IP enterSgeSync --- IBEGIN

	license->syncAll(dbswdbe);

	// IP enterSgeSync --- IEND

	return retval;
};

void DlgWdbePrjImpex::leaveSgeSync(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeSync --- INSERT
};

uint DlgWdbePrjImpex::enterSgeDone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void DlgWdbePrjImpex::leaveSgeDone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeDone --- INSERT
};
