/**
	* \file DlgWdbeNavLoaini.cpp
	* job handler for job DlgWdbeNavLoaini (implementation)
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

#include "DlgWdbeNavLoaini.h"

#include "DlgWdbeNavLoaini_blks.cpp"
#include "DlgWdbeNavLoaini_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWdbeNavLoaini
 ******************************************************************************/

DlgWdbeNavLoaini::DlgWdbeNavLoaini(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::DLGWDBENAVLOAINI, jrefSup, ixWdbeVLocale)
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

	iex = new JobWdbeIexIni(xchg, dbswdbe, jref, ixWdbeVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswdbe, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgWdbeNavLoaini::~DlgWdbeNavLoaini() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* DlgWdbeNavLoaini::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &continfimp, &continflfi, &feedFDse, &feedFSge, &statshr, &statshracv, &statshrifi, &statshrimp, &statshrlfi, items);
	};

	return dpcheng;
};

void DlgWdbeNavLoaini::refreshIfi(
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

void DlgWdbeNavLoaini::refreshImp(
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

void DlgWdbeNavLoaini::refreshAcv(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShrAcv oldStatshracv(statshracv);

	// IP refreshAcv --- BEGIN
	// statshracv
	statshracv.UldActive = evalAcvUldActive(dbswdbe);

	// IP refreshAcv --- END
	if (statshracv.diff(&oldStatshracv).size() != 0) insert(moditems, DpchEngData::STATSHRACV);
};

void DlgWdbeNavLoaini::refreshLfi(
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

void DlgWdbeNavLoaini::refresh(
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
	refreshAcv(dbswdbe, moditems);
	refreshLfi(dbswdbe, moditems);

	muteRefresh = false;
};

void DlgWdbeNavLoaini::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBENAVLOAINIDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswdbe, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBENAVLOAINIDO) {
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

			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEALERT) {
			handleDpchAppWdbeAlert(dbswdbe, (DpchAppWdbeAlert*) (req->dpchapp), &(req->dpcheng));

		};

	} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::UPLOAD) {
		if (ixVSge == VecVSge::IMPDONE) handleUploadInSgeImpdone(dbswdbe, req->filename);
		else if (ixVSge == VecVSge::IDLE) handleUploadInSgeIdle(dbswdbe, req->filename);

	} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::DOWNLOAD) {
		if (ixVSge == VecVSge::DONE) req->filename = handleDownloadInSgeDone(dbswdbe);

	} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::TIMER) {
		if (ixVSge == VecVSge::PRSIDLE) handleTimerInSgePrsidle(dbswdbe, req->sref);
		else if (ixVSge == VecVSge::IMPIDLE) handleTimerInSgeImpidle(dbswdbe, req->sref);
		else if ((req->sref == "mon") && (ixVSge == VecVSge::IMPORT)) handleTimerWithSrefMonInSgeImport(dbswdbe);
		else if (ixVSge == VecVSge::UPKIDLE) handleTimerInSgeUpkidle(dbswdbe, req->sref);
	};
};

void DlgWdbeNavLoaini::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWdbeNavLoaini::handleDpchAppDataContiac(
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

void DlgWdbeNavLoaini::handleDpchAppDoButDneClick(
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

void DlgWdbeNavLoaini::handleDpchAppDoImpButRunClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoImpButRunClick --- BEGIN
	if (statshrimp.ButRunActive) {
		changeStage(dbswdbe, VecVSge::IMPIDLE, dpcheng);
	};
	// IP handleDpchAppDoImpButRunClick --- END
};

void DlgWdbeNavLoaini::handleDpchAppDoImpButStoClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoImpButStoClick --- INSERT
};

void DlgWdbeNavLoaini::handleDpchAppWdbeAlert(
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

void DlgWdbeNavLoaini::handleUploadInSgeImpdone(
			DbsWdbe* dbswdbe
			, const string& filename
		) {
	infilename = filename; // IP handleUploadInSgeImpdone --- ILINE
	changeStage(dbswdbe, VecVSge::UPKIDLE);
};

void DlgWdbeNavLoaini::handleUploadInSgeIdle(
			DbsWdbe* dbswdbe
			, const string& filename
		) {
	infilename = filename; // IP handleUploadInSgeIdle --- ILINE
	changeStage(dbswdbe, VecVSge::PRSIDLE);
};

string DlgWdbeNavLoaini::handleDownloadInSgeDone(
			DbsWdbe* dbswdbe
		) {
	return(""); // IP handleDownloadInSgeDone --- LINE
};

void DlgWdbeNavLoaini::handleTimerInSgePrsidle(
			DbsWdbe* dbswdbe
			, const string& sref
		) {
	changeStage(dbswdbe, nextIxVSgeSuccess);
};

void DlgWdbeNavLoaini::handleTimerInSgeImpidle(
			DbsWdbe* dbswdbe
			, const string& sref
		) {
	changeStage(dbswdbe, nextIxVSgeSuccess);
};

void DlgWdbeNavLoaini::handleTimerWithSrefMonInSgeImport(
			DbsWdbe* dbswdbe
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	refreshWithDpchEng(dbswdbe); // IP handleTimerWithSrefMonInSgeImport --- ILINE
};

void DlgWdbeNavLoaini::handleTimerInSgeUpkidle(
			DbsWdbe* dbswdbe
			, const string& sref
		) {
	changeStage(dbswdbe, nextIxVSgeSuccess);
};

void DlgWdbeNavLoaini::changeStage(
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
				case VecVSge::UPKIDLE: leaveSgeUpkidle(dbswdbe); break;
				case VecVSge::UNPACK: leaveSgeUnpack(dbswdbe); break;
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
			case VecVSge::UPKIDLE: _ixVSge = enterSgeUpkidle(dbswdbe, reenter); break;
			case VecVSge::UNPACK: _ixVSge = enterSgeUnpack(dbswdbe, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswdbe, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWdbeNavLoaini::getSquawk(
			DbsWdbe* dbswdbe
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::PARSE) || (ixVSge == VecVSge::ALRWDBEPER) || (ixVSge == VecVSge::PRSDONE) || (ixVSge == VecVSge::IMPORT) || (ixVSge == VecVSge::ALRWDBEIER) || (ixVSge == VecVSge::IMPDONE) || (ixVSge == VecVSge::UNPACK) ) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing initialization data";
			else if (ixVSge == VecVSge::ALRWDBEPER) retval = "parse error";
			else if (ixVSge == VecVSge::PRSDONE) retval = "initialization data parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing initialization data (" + to_string(iex->impcnt) + " records added)";
			else if (ixVSge == VecVSge::ALRWDBEIER) retval = "import error";
			else if (ixVSge == VecVSge::IMPDONE) retval = "import done";
			else if (ixVSge == VecVSge::UNPACK) retval = "unpacking inizialization files";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

uint DlgWdbeNavLoaini::enterSgeIdle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWdbeNavLoaini::leaveSgeIdle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWdbeNavLoaini::enterSgePrsidle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::PRSIDLE;
	nextIxVSgeSuccess = VecVSge::PARSE;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgePrsidle --- INSERT

	return retval;
};

void DlgWdbeNavLoaini::leaveSgePrsidle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgePrsidle --- INSERT
};

uint DlgWdbeNavLoaini::enterSgeParse(
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

	ifitxt = (s.find("IexWdbeIni") == 0);
	ifixml = (s.find("<?xml") == 0);		

	delete[] buf;
	ififile.close();

	// parse file accordingly
	if (ifitxt) iex->parseFromFile(dbswdbe, infilename, false, "");
	else if (ifixml) iex->parseFromFile(dbswdbe, infilename, true, "");

	if (iex->ixVSge != JobWdbeIexIni::VecVSge::PRSDONE) {
		if (reqCmd) {
			if (iex->ixVSge == JobWdbeIexIni::VecVSge::PRSERR) cout << "\t" << iex->getSquawk(dbswdbe) << endl;
			else cout << "\tneither text-based nor XML file format recognized" << endl;

			retval = VecVSge::IDLE;

		} else {
			retval = nextIxVSgeFailure;
		};
	};
	// IP enterSgeParse --- IEND

	return retval;
};

void DlgWdbeNavLoaini::leaveSgeParse(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeParse --- INSERT
};

uint DlgWdbeNavLoaini::enterSgeAlrwdbeper(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::ALRWDBEPER;
	nextIxVSgeSuccess = VecVSge::IDLE;

	// IP enterSgeAlrwdbeper --- RBEGIN
	ContInfWdbeAlert continf;

	continf.TxtCpt = VecWdbeVTag::getTitle(VecWdbeVTag::ERROR, ixWdbeVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (iex->ixVSge == JobWdbeIexIni::VecVSge::PRSERR) continf.TxtMsg1 = iex->getSquawk(dbswdbe);
	else continf.TxtMsg1 = "neither text-based nor XML file format recognized";

	feedFMcbAlert.clear();

	VecWdbeVTag::appendToFeed(VecWdbeVTag::OK, ixWdbeVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();

	xchg->submitDpch(new DpchEngWdbeAlert(jref, &continf, &feedFMcbAlert, {DpchEngWdbeAlert::ALL}));
	// IP enterSgeAlrwdbeper --- REND

	return retval;
};

void DlgWdbeNavLoaini::leaveSgeAlrwdbeper(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAlrwdbeper --- INSERT
};

uint DlgWdbeNavLoaini::enterSgePrsdone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::PRSDONE;

	// IP enterSgePrsdone --- INSERT

	return retval;
};

void DlgWdbeNavLoaini::leaveSgePrsdone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgePrsdone --- INSERT
};

uint DlgWdbeNavLoaini::enterSgeImpidle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IMPIDLE;
	nextIxVSgeSuccess = VecVSge::IMPORT;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgeImpidle --- INSERT

	return retval;
};

void DlgWdbeNavLoaini::leaveSgeImpidle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeImpidle --- INSERT
};

uint DlgWdbeNavLoaini::enterSgeImport(
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

	if (iex->ixVSge == JobWdbeIexIni::VecVSge::IMPERR) retval = nextIxVSgeFailure;
	// IP enterSgeImport --- IEND

	return retval;
};

void DlgWdbeNavLoaini::leaveSgeImport(
			DbsWdbe* dbswdbe
		) {
	invalidateWakeups();
	// IP leaveSgeImport --- INSERT
};

uint DlgWdbeNavLoaini::enterSgeAlrwdbeier(
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

void DlgWdbeNavLoaini::leaveSgeAlrwdbeier(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAlrwdbeier --- INSERT
};

uint DlgWdbeNavLoaini::enterSgeImpdone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IMPDONE;

	// IP enterSgeImpdone --- INSERT

	return retval;
};

void DlgWdbeNavLoaini::leaveSgeImpdone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeImpdone --- INSERT
};

uint DlgWdbeNavLoaini::enterSgeUpkidle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::UPKIDLE;
	nextIxVSgeSuccess = VecVSge::UNPACK;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgeUpkidle --- INSERT

	return retval;
};

void DlgWdbeNavLoaini::leaveSgeUpkidle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeUpkidle --- INSERT
};

uint DlgWdbeNavLoaini::enterSgeUnpack(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	// IP enterSgeUnpack --- IBEGIN
	ubigint ref;

	DIR* dir = NULL;
	dirent* diritem = NULL;

	// collect refs of newly imported files
	dbswdbe->tblwdbeqselect->removeRstByJref(jref);

	for (unsigned int ix0 = 0; ix0 < iex->imeimfile1.nodes.size(); ix0++) dbswdbe->tblwdbeqselect->insertNewRec(NULL, jref, 0, 0, iex->imeimfile1.nodes[ix0]->ref);

	for (unsigned int ix0 = 0; ix0 < iex->imeimmodule.nodes.size(); ix0++)
		for (unsigned int ix1 = 0; ix1 < iex->imeimmodule.nodes[ix0]->imeimfile2.nodes.size(); ix1++)
			dbswdbe->tblwdbeqselect->insertNewRec(NULL, jref, 0, 0, iex->imeimmodule.nodes[ix0]->imeimfile2.nodes[ix1]->ref);

	// handle archive file containing many (or all) files
	Wdbe::run("mv " + infilename + " " + infilename + ".tgz");

	// unpack
	Wdbe::untgz(infilename + ".tgz", infilename);

	// traverse directory and match each single file to import
	dir = opendir(infilename.c_str());

	if (dir) {
		// traverse directory
		diritem = readdir(dir);
		while (diritem) {
			if (diritem->d_type == DT_REG) {
				// file: try to match
				ref = 0;

				dbswdbe->loadRefBySQL("SELECT TblWdbeMFile.ref FROM TblWdbeQSelect, TblWdbeMFile WHERE TblWdbeQSelect.jref = " + to_string(jref)
							+ " AND TblWdbeMFile.ref = TblWdbeQSelect.ref AND TblWdbeMFile.Filename = '" + diritem->d_name + "'", ref);

				if (ref != 0) {
					Acv::alterfile(dbswdbe, xchg->acvpath, infilename + "/" + diritem->d_name, ref);
					if (reqCmd) cout << "updated file '" << diritem->d_name << "'" << endl;
				};

			} else {
				// something else: do nothing
			};

			diritem = readdir(dir);
		};

		closedir(dir);
	};
	// IP enterSgeUnpack --- IEND

	return retval;
};

void DlgWdbeNavLoaini::leaveSgeUnpack(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeUnpack --- INSERT
};

uint DlgWdbeNavLoaini::enterSgeDone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void DlgWdbeNavLoaini::leaveSgeDone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeDone --- INSERT
};
