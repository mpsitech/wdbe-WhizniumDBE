/**
	* \file DlgWdbeUtlIexconv.cpp
	* job handler for job DlgWdbeUtlIexconv (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbed.h>
#endif

#include "DlgWdbeUtlIexconv.h"

#include "DlgWdbeUtlIexconv_blks.cpp"
#include "DlgWdbeUtlIexconv_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWdbeUtlIexconv
 ******************************************************************************/

DlgWdbeUtlIexconv::DlgWdbeUtlIexconv(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::DLGWDBEUTLIEXCONV, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

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

DlgWdbeUtlIexconv::~DlgWdbeUtlIexconv() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* DlgWdbeUtlIexconv::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &continfcnv, &continfres, &feedFDse, &feedFSge, &statshr, &statshrcnv, &statshrres, &statshrsrc, items);
	};

	return dpcheng;
};

void DlgWdbeUtlIexconv::refreshSrc(
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

void DlgWdbeUtlIexconv::refreshCnv(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContInfCnv oldContinfcnv(continfcnv);
	StatShrCnv oldStatshrcnv(statshrcnv);

	// IP refreshCnv --- RBEGIN
	// continfcnv
	continfcnv.TxtPrg = getSquawk(dbswdbe);

	// statshrcnv
	statshrcnv.ButRunActive = evalCnvButRunActive(dbswdbe);
	statshrcnv.ButStoActive = evalCnvButStoActive(dbswdbe);

	// IP refreshCnv --- REND
	if (continfcnv.diff(&oldContinfcnv).size() != 0) insert(moditems, DpchEngData::CONTINFCNV);
	if (statshrcnv.diff(&oldStatshrcnv).size() != 0) insert(moditems, DpchEngData::STATSHRCNV);
};

void DlgWdbeUtlIexconv::refreshRes(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShrRes oldStatshrres(statshrres);
	ContInfRes oldContinfres(continfres);

	// IP refreshRes --- RBEGIN
	// statshrres
	statshrres.DldActive = evalResDldActive(dbswdbe);

	// continfres
	if (outfolder != "") continfres.Dld = "converted.tgz";
	else continfres.Dld = "converted";

	// IP refreshRes --- REND
	if (statshrres.diff(&oldStatshrres).size() != 0) insert(moditems, DpchEngData::STATSHRRES);
	if (continfres.diff(&oldContinfres).size() != 0) insert(moditems, DpchEngData::CONTINFRES);
};

void DlgWdbeUtlIexconv::refresh(
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

	refreshSrc(dbswdbe, moditems);
	refreshCnv(dbswdbe, moditems);
	refreshRes(dbswdbe, moditems);
};

void DlgWdbeUtlIexconv::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEUTLIEXCONVDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswdbe, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEUTLIEXCONVDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbswdbe, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoCnv != 0) {
				if (dpchappdo->ixVDoCnv == VecVDoCnv::BUTRUNCLICK) {
					handleDpchAppDoCnvButRunClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDoCnv == VecVDoCnv::BUTSTOCLICK) {
					handleDpchAppDoCnvButStoClick(dbswdbe, &(req->dpcheng));
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
		else if ((req->sref == "mon") && (ixVSge == VecVSge::CONV)) handleTimerWithSrefMonInSgeConv(dbswdbe);
	};
};

void DlgWdbeUtlIexconv::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWdbeUtlIexconv::handleDpchAppDataContiac(
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

void DlgWdbeUtlIexconv::handleDpchAppDoButDneClick(
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

void DlgWdbeUtlIexconv::handleDpchAppDoCnvButRunClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoCnvButRunClick --- BEGIN
	if (statshrcnv.ButRunActive) {
		changeStage(dbswdbe, VecVSge::CONV, dpcheng);
	};
	// IP handleDpchAppDoCnvButRunClick --- END
};

void DlgWdbeUtlIexconv::handleDpchAppDoCnvButStoClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoCnvButStoClick --- INSERT
};

void DlgWdbeUtlIexconv::handleUploadInSgeIdle(
			DbsWdbe* dbswdbe
			, const string& filename
		) {
	infilename = filename; // IP handleUploadInSgeIdle --- ILINE
	changeStage(dbswdbe, VecVSge::UPKIDLE);
};

string DlgWdbeUtlIexconv::handleDownloadInSgeDone(
			DbsWdbe* dbswdbe
		) {
	return(xchg->tmppath + "/" + outfile); // IP handleDownloadInSgeDone --- RLINE
};

void DlgWdbeUtlIexconv::handleTimerInSgeUpkidle(
			DbsWdbe* dbswdbe
			, const string& sref
		) {
	changeStage(dbswdbe, nextIxVSgeSuccess);
};

void DlgWdbeUtlIexconv::handleTimerWithSrefMonInSgeConv(
			DbsWdbe* dbswdbe
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	refreshWithDpchEng(dbswdbe); // IP handleTimerWithSrefMonInSgeConv --- ILINE
};

void DlgWdbeUtlIexconv::changeStage(
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
				case VecVSge::ULDDONE: leaveSgeUlddone(dbswdbe); break;
				case VecVSge::CONV: leaveSgeConv(dbswdbe); break;
				case VecVSge::PACK: leaveSgePack(dbswdbe); break;
				case VecVSge::DONE: leaveSgeDone(dbswdbe); break;
			};

			setStage(dbswdbe, _ixVSge);
			reenter = false;
			if (!muteRefresh) refreshWithDpchEng(dbswdbe, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswdbe, reenter); break;
			case VecVSge::UPKIDLE: _ixVSge = enterSgeUpkidle(dbswdbe, reenter); break;
			case VecVSge::UNPACK: _ixVSge = enterSgeUnpack(dbswdbe, reenter); break;
			case VecVSge::UPKDONE: _ixVSge = enterSgeUpkdone(dbswdbe, reenter); break;
			case VecVSge::ULDDONE: _ixVSge = enterSgeUlddone(dbswdbe, reenter); break;
			case VecVSge::CONV: _ixVSge = enterSgeConv(dbswdbe, reenter); break;
			case VecVSge::PACK: _ixVSge = enterSgePack(dbswdbe, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswdbe, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWdbeUtlIexconv::getSquawk(
			DbsWdbe* dbswdbe
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::UNPACK) || (ixVSge == VecVSge::UPKDONE) || (ixVSge == VecVSge::ULDDONE) || (ixVSge == VecVSge::CONV) || (ixVSge == VecVSge::PACK) ) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			if (ixVSge == VecVSge::UNPACK) retval = "unpacking source";
			else if (ixVSge == VecVSge::UPKDONE) retval = "source unpacked";
			else if (ixVSge == VecVSge::ULDDONE) retval = "source uploaded";
			else if (ixVSge == VecVSge::CONV) retval = "converting files (" + to_string(opNSuccess + opNFailure) + "/" + to_string(opN) + " operations completed, last: " + getOpsqkLast() + ")";
			else if (ixVSge == VecVSge::PACK) retval = "packing result";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint DlgWdbeUtlIexconv::enterSgeIdle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWdbeUtlIexconv::leaveSgeIdle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWdbeUtlIexconv::enterSgeUpkidle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::UPKIDLE;
	nextIxVSgeSuccess = VecVSge::UNPACK;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgeUpkidle --- INSERT

	return retval;
};

void DlgWdbeUtlIexconv::leaveSgeUpkidle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeUpkidle --- INSERT
};

uint DlgWdbeUtlIexconv::enterSgeUnpack(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::UPKDONE;
	retval = nextIxVSgeSuccess;

	// IP enterSgeUnpack --- IBEGIN
	// 1st try: assume .tgz input file archive
	infolder = infilename.substr(infilename.rfind("/")+1);
	infile = infolder + ".tgz";

	Wdbe::run("mv " + infilename + " " + infilename + ".tgz");

	outfolder = Tmp::newfolder(xchg->tmppath);
	outfile = Tmp::newfile(xchg->tmppath, "tgz");

	if (!Wdbe::untgz(xchg->tmppath + "/" + infile, xchg->tmppath + "/" + infolder)) {
		// 2nd try: single text input file
		infolder = "";
		
		Wdbe::run("mv " + infilename + ".tgz " + infilename + ".txt");
		infile = infilename.substr(infilename.rfind("/")+1) + ".txt";

		outfolder = "";
		outfile = Tmp::newfile(xchg->tmppath, "txt");

		retval = VecVSge::ULDDONE;
	};
	// IP enterSgeUnpack --- IEND

	return retval;
};

void DlgWdbeUtlIexconv::leaveSgeUnpack(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeUnpack --- INSERT
};

uint DlgWdbeUtlIexconv::enterSgeUpkdone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::UPKDONE;

	// IP enterSgeUpkdone --- INSERT

	return retval;
};

void DlgWdbeUtlIexconv::leaveSgeUpkdone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeUpkdone --- INSERT
};

uint DlgWdbeUtlIexconv::enterSgeUlddone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::ULDDONE;

	// IP enterSgeUlddone --- INSERT

	return retval;
};

void DlgWdbeUtlIexconv::leaveSgeUlddone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeUlddone --- INSERT
};

uint DlgWdbeUtlIexconv::enterSgeConv(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::CONV;
	nextIxVSgeSuccess = VecVSge::PACK;

	clearInvs();

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);

	// IP enterSgeConv --- IBEGIN

	DIR* dir = NULL;

	dirent* diritem = NULL;

	string s;

	if (infolder == "") {
		// single file
		addInv(new DpchInvWdbePrcfileIexconv(0, 0, infile, outfile));

	} else {
		// multiple files
		s = xchg->tmppath + "/" + infolder;
		dir = opendir(s.c_str());

		if (dir) {
			diritem = readdir(dir);

			while (diritem) {
				if (diritem->d_type == DT_REG) {
					s = diritem->d_name;
					if (s.rfind(".txt") == (s.length()-4)) addInv(new DpchInvWdbePrcfileIexconv(0, 0, infolder + "/" + s, outfolder + "/" + s));
				};

				diritem = readdir(dir);
			};

			closedir(dir);
		};
	};

	// IP enterSgeConv --- IEND

	submitInvs(dbswdbe, VecVSge::IDLE, retval);
	return retval;
};

void DlgWdbeUtlIexconv::leaveSgeConv(
			DbsWdbe* dbswdbe
		) {
	invalidateWakeups();
	// IP leaveSgeConv --- INSERT
};

uint DlgWdbeUtlIexconv::enterSgePack(
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

void DlgWdbeUtlIexconv::leaveSgePack(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgePack --- INSERT
};

uint DlgWdbeUtlIexconv::enterSgeDone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void DlgWdbeUtlIexconv::leaveSgeDone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeDone --- INSERT
};


