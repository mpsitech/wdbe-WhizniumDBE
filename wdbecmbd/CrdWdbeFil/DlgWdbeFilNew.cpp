/**
	* \file DlgWdbeFilNew.cpp
	* job handler for job DlgWdbeFilNew (implementation)
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

#include "DlgWdbeFilNew.h"

#include "DlgWdbeFilNew_blks.cpp"
#include "DlgWdbeFilNew_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWdbeFilNew
 ******************************************************************************/

DlgWdbeFilNew::DlgWdbeFilNew(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::DLGWDBEFILNEW, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFDetPupCnt.tag = "FeedFDetPupCnt";
	dbswdbe->fillFeedFromKlst(VecWdbeVKeylist::KLSTWDBEKMFILECONTENT, ixWdbeVLocale, feedFDetPupCnt);
	feedFDetPupMim.tag = "FeedFDetPupMim";
	dbswdbe->fillFeedFromKlst(VecWdbeVKeylist::KLSTWDBEKMFILEMIMETYPE, ixWdbeVLocale, feedFDetPupMim);
	feedFDetPupRet.tag = "FeedFDetPupRet";
	VecWdbeVMFileRefTbl::fillFeed(ixWdbeVLocale, feedFDetPupRet);
	feedFDse.tag = "FeedFDse";
	VecVDit::fillFeed(ixWdbeVLocale, feedFDse);
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	// IP constructor.cust1 --- INSERT

	ixVDit = VecVDit::DET;

	valid = false;

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswdbe, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgWdbeFilNew::~DlgWdbeFilNew() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
ubigint DlgWdbeFilNew::getRefMtp(
			DbsWdbe* dbswdbe
			, const string& s
		) {
	// expect module sref, ex. 'spifwd_v1_0'

	ubigint refMtp = 0;

	dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::VOID) + " AND supRefWdbeMModule = 0 AND tplRefWdbeMModule = 0 AND sref = '" + s + "'", refMtp);

	return refMtp;
};

ubigint DlgWdbeFilNew::getRefVer(
			DbsWdbe* dbswdbe
			, const string& s
		) {
	// expect StubWdbeVerStd, ex. 'ICARUSDetectorHardware 0.1'

	ubigint refVer = 0;

	ubigint refWdbeMProject = 0;
	usmallint Major = 0;
	usmallint Minor = 0;
	usmallint Sub = 0;

	vector<string> ss;

	size_t ptr;

	ptr = s.rfind(' ');
	if (ptr != string::npos) {
		dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMProject WHERE Title = '" + s.substr(0, ptr) + "'", refWdbeMProject);

		if (refWdbeMProject != 0) {
			StrMod::stringToVector(s.substr(ptr+1), ss, '.');

			if (ss.size() >= 1) {
				Major = atoi(ss[0].c_str());
				if (ss.size() >= 2) Minor = atoi(ss[1].c_str());
				if (ss.size() >= 3) Sub = atoi(ss[2].c_str());

				dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMVersion WHERE prjRefWdbeMProject = " + to_string(refWdbeMProject) + " AND Major = " + to_string(Major) + " AND Minor = " + to_string(Minor) + " AND Sub = " + to_string(Sub), refVer);
			};
		};
	};

	return refVer;
};

// IP cust --- IEND

DpchEngWdbe* DlgWdbeFilNew::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &contiacdet, &continf, &feedFDetPupCnt, &feedFDetPupMim, &feedFDetPupRet, &feedFDse, &feedFSge, &statshr, &statshrdet, &statshrfil, items);
	};

	return dpcheng;
};

void DlgWdbeFilNew::refreshDet(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShrDet oldStatshrdet(statshrdet);
	ContIacDet oldContiacdet(contiacdet);

	// IP refreshDet --- BEGIN
	// statshrdet
	statshrdet.ButCreActive = evalDetButCreActive(dbswdbe);

	// contiacdet

	// IP refreshDet --- END
	if (statshrdet.diff(&oldStatshrdet).size() != 0) insert(moditems, DpchEngData::STATSHRDET);
	if (contiacdet.diff(&oldContiacdet).size() != 0) insert(moditems, DpchEngData::CONTIACDET);
};

void DlgWdbeFilNew::refreshFil(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShrFil oldStatshrfil(statshrfil);

	// IP refreshFil --- BEGIN
	// statshrfil
	statshrfil.UldActive = evalFilUldActive(dbswdbe);

	// IP refreshFil --- END
	if (statshrfil.diff(&oldStatshrfil).size() != 0) insert(moditems, DpchEngData::STATSHRFIL);
};

void DlgWdbeFilNew::refresh(
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

	refreshDet(dbswdbe, moditems);
	refreshFil(dbswdbe, moditems);

	muteRefresh = false;
};

void DlgWdbeFilNew::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEFILNEWDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswdbe, &(dpchappdata->contiac), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::CONTIACDET)) {
				handleDpchAppDataContiacdet(dbswdbe, &(dpchappdata->contiacdet), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEFILNEWDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbswdbe, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoDet != 0) {
				if (dpchappdo->ixVDoDet == VecVDoDet::BUTCRECLICK) {
					handleDpchAppDoDetButCreClick(dbswdbe, &(req->dpcheng));
				};

			};

		};

	} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::UPLOAD) {
		if (ixVSge == VecVSge::CREDONE) handleUploadInSgeCredone(dbswdbe, req->filename);
	};
};

void DlgWdbeFilNew::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWdbeFilNew::handleDpchAppDataContiac(
			DbsWdbe* dbswdbe
			, ContIac* _contiac
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFDSE)) {
		if ((_contiac->numFDse >= VecVDit::DET) && (_contiac->numFDse <= VecVDit::FIL)) ixVDit = _contiac->numFDse;
		refresh(dbswdbe, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgWdbeFilNew::handleDpchAppDataContiacdet(
			DbsWdbe* dbswdbe
			, ContIacDet* _contiacdet
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiacdet->diff(&contiacdet);
	// IP handleDpchAppDataContiacdet --- IBEGIN

	string s;

	size_t ptr;

	if (has(diffitems, ContIacDet::TXFFNM)) {
		contiacdet.TxfFnm = _contiacdet->TxfFnm;

		if (!has(diffitems, ContIacDet::NUMFPUPMIM)) {
			ptr = contiacdet.TxfFnm.rfind('.');
			if (ptr != string::npos) {
				_contiacdet->numFPupMim = feedFDetPupMim.getNumBySref(contiacdet.TxfFnm.substr(ptr+1));
				add(diffitems, ContIacDet::NUMFPUPMIM);
			};
		};
	};

	if (has(diffitems, ContIacDet::NUMFPUPRET)) {
		if (feedFDetPupRet.getIxByNum(_contiacdet->numFPupRet) != 0) contiacdet.numFPupRet = _contiacdet->numFPupRet;
		else contiacdet.numFPupRet = 0;

		if (!has(diffitems, ContIacDet::TXFREU)) contiacdet.TxfReu = "";
	};

	if (has(diffitems, ContIacDet::TXFREU)) {
		contiacdet.TxfReu = "";

		if (contiacdet.numFPupRet == VecWdbeVMFileRefTbl::MTP) {
			if (getRefMtp(dbswdbe, _contiacdet->TxfReu) != 0) contiacdet.TxfReu = _contiacdet->TxfReu;
		} else if (contiacdet.numFPupRet == VecWdbeVMFileRefTbl::VER) {
			if (getRefVer(dbswdbe, _contiacdet->TxfReu) != 0) contiacdet.TxfReu = _contiacdet->TxfReu;
		};
	};

	if (has(diffitems, ContIacDet::NUMFPUPCNT)) {
		if (feedFDetPupCnt.getSrefByNum(_contiacdet->numFPupCnt) != "") contiacdet.numFPupCnt = _contiacdet->numFPupCnt;
		else contiacdet.numFPupCnt = 0;
	};

	if (has(diffitems, ContIacDet::NUMFPUPMIM)) {
		if (feedFDetPupMim.getSrefByNum(_contiacdet->numFPupMim) != "") contiacdet.numFPupMim = _contiacdet->numFPupMim;
		else contiacdet.numFPupMim = 0;
	};

	valid = ((contiacdet.TxfFnm != "") && (contiacdet.numFPupRet != 0) && ((contiacdet.numFPupRet == VecWdbeVMFileRefTbl::VOID)  || ((contiacdet.numFPupRet > VecWdbeVMFileRefTbl::VOID) && (contiacdet.TxfReu != "")))
				&& (contiacdet.numFPupCnt != 0) && (contiacdet.numFPupMim != 0));

	refresh(dbswdbe, moditems);

	// IP handleDpchAppDataContiacdet --- IEND
	insert(moditems, DpchEngData::CONTIACDET);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgWdbeFilNew::handleDpchAppDoButDneClick(
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

void DlgWdbeFilNew::handleDpchAppDoDetButCreClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoDetButCreClick --- BEGIN
	if (statshrdet.ButCreActive) {
		changeStage(dbswdbe, VecVSge::CREATE, dpcheng);
	};
	// IP handleDpchAppDoDetButCreClick --- END
};

void DlgWdbeFilNew::handleUploadInSgeCredone(
			DbsWdbe* dbswdbe
			, const string& filename
		) {
	infilename = filename; // IP handleUploadInSgeCredone --- ILINE
	changeStage(dbswdbe, VecVSge::DONE);
};

void DlgWdbeFilNew::changeStage(
			DbsWdbe* dbswdbe
			, uint _ixVSge
			, DpchEngWdbe** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswdbe); break;
				case VecVSge::CREATE: leaveSgeCreate(dbswdbe); break;
				case VecVSge::CREDONE: leaveSgeCredone(dbswdbe); break;
				case VecVSge::DONE: leaveSgeDone(dbswdbe); break;
			};

			setStage(dbswdbe, _ixVSge);
			reenter = false;
			refreshWithDpchEng(dbswdbe, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswdbe, reenter); break;
			case VecVSge::CREATE: _ixVSge = enterSgeCreate(dbswdbe, reenter); break;
			case VecVSge::CREDONE: _ixVSge = enterSgeCredone(dbswdbe, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswdbe, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWdbeFilNew::getSquawk(
			DbsWdbe* dbswdbe
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if (ixVSge == VecVSge::CREDONE) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			if (ixVSge == VecVSge::CREDONE) retval = "new file created";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint DlgWdbeFilNew::enterSgeIdle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWdbeFilNew::leaveSgeIdle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWdbeFilNew::enterSgeCreate(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::CREDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IDLE;

	// IP enterSgeCreate --- IBEGIN
	WdbeMFile fil;

	fil.grp = xchg->getRefPreset(VecWdbeVPreset::PREWDBEGROUP, jref);
	fil.own = xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref);
	fil.refIxVTbl = feedFDetPupRet.getIxByNum(contiacdet.numFPupRet);
	if (fil.refIxVTbl == VecWdbeVMFileRefTbl::MTP) fil.refUref = getRefMtp(dbswdbe, contiacdet.TxfReu);
	else if (fil.refIxVTbl == VecWdbeVMFileRefTbl::VER) fil.refUref = getRefVer(dbswdbe, contiacdet.TxfReu);
	fil.osrefKContent = feedFDetPupCnt.getSrefByNum(contiacdet.numFPupCnt);
	fil.Filename = contiacdet.TxfFnm;
	fil.srefKMimetype = feedFDetPupMim.getSrefByNum(contiacdet.numFPupMim);

	dbswdbe->tblwdbemfile->insertRec(&fil);

	xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBEFILMOD, jref);
	xchg->triggerIxRefCall(dbswdbe, VecWdbeVCall::CALLWDBEREFPRESET, jref, VecWdbeVPreset::PREWDBEREFFIL, fil.ref);
	// IP enterSgeCreate --- IEND

	return retval;
};

void DlgWdbeFilNew::leaveSgeCreate(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeCreate --- INSERT
};

uint DlgWdbeFilNew::enterSgeCredone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::CREDONE;

	// IP enterSgeCredone --- INSERT

	return retval;
};

void DlgWdbeFilNew::leaveSgeCredone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeCredone --- INSERT
};

uint DlgWdbeFilNew::enterSgeDone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- IBEGIN
	Acv::alterfile(dbswdbe, xchg->acvpath, infilename, xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFFIL, jref));
	// IP enterSgeDone --- IEND

	return retval;
};

void DlgWdbeFilNew::leaveSgeDone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeDone --- INSERT
};
