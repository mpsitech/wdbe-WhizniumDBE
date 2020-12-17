/**
	* \file DlgWdbeVerNew.cpp
	* job handler for job DlgWdbeVerNew (implementation)
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

#include "DlgWdbeVerNew.h"

#include "DlgWdbeVerNew_blks.cpp"
#include "DlgWdbeVerNew_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWdbeVerNew
 ******************************************************************************/

DlgWdbeVerNew::DlgWdbeVerNew(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::DLGWDBEVERNEW, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFDetPupBvr.tag = "FeedFDetPupBvr";
	feedFDetPupPrj.tag = "FeedFDetPupPrj";
	feedFDetRbuVni.tag = "FeedFDetRbuVni";
	VecVVni::fillFeed(ixWdbeVLocale, feedFDetRbuVni);
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	iexprj = NULL;

	// IP constructor.cust1 --- IBEGIN
	ListWdbeMProject prjs;
	WdbeMProject* prj = NULL;

	contiac.numFDetPupPrj = 0;

	dbswdbe->tblwdbemproject->loadRstBySQL("SELECT * FROM TblWdbeMProject ORDER BY Short ASC", false, prjs);
	for (unsigned int i = 0; i < prjs.nodes.size(); i++) {
		prj = prjs.nodes[i];
		feedFDetPupPrj.appendIxRefSrefTitles(0, prj->ref, prj->Short, StubWdbe::getStubPrjStd(dbswdbe, prj->ref));
	};
	// IP constructor.cust1 --- IEND

	valid = false;

	iexprj = new JobWdbeIexPrj(xchg, dbswdbe, jref, ixWdbeVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswdbe, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgWdbeVerNew::~DlgWdbeVerNew() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
void DlgWdbeVerNew::refreshDetBvr(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	// fill feedFDetPupBvr based on selection in PupPrj
	ContIac oldContiac(contiac);

	vector<ubigint> refs;

	WdbeMProject* prj = NULL;

	feedFDetPupBvr.clear();
	contiac.numFDetPupBvr = 0;

	if (dbswdbe->tblwdbemproject->loadRecByRef(feedFDetPupPrj.getRefByNum(contiac.numFDetPupPrj), &prj)) {
		dbswdbe->loadRefsBySQL("SELECT ref FROM TblWdbeMVersion WHERE prjRefWdbeMProject = " + to_string(prj->ref) + " ORDER BY prjNum ASC", false, refs);

		for (unsigned int i = 0; i < refs.size();i++) {
			feedFDetPupBvr.appendRefTitles(refs[i], StubWdbe::getStubVerNo(dbswdbe, refs[i]));

			if (refs[i] == prj->refWdbeMVersion) contiac.numFDetPupBvr = (i+1);
		};

		delete prj;
	};

	insert(moditems, DpchEngData::FEEDFDETPUPBVR);

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
};

// IP cust --- IEND

DpchEngWdbe* DlgWdbeVerNew::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFDetPupBvr, &feedFDetPupPrj, &feedFDetRbuVni, &feedFSge, &statshr, items);
	};

	return dpcheng;
};

void DlgWdbeVerNew::refresh(
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
	statshr.ButCreActive = evalButCreActive(dbswdbe);

	// contiac

	// continf
	continf.numFSge = ixVSge;

	// IP refresh --- END
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	muteRefresh = false;
};

void DlgWdbeVerNew::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEVERNEWDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswdbe, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEVERNEWDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTCNCCLICK) {
					handleDpchAppDoButCncClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCRECLICK) {
					handleDpchAppDoButCreClick(dbswdbe, &(req->dpcheng));
				};

			};

		};
	};
};

void DlgWdbeVerNew::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWdbeVerNew::handleDpchAppDataContiac(
			DbsWdbe* dbswdbe
			, ContIac* _contiac
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);
	// IP handleDpchAppDataContiac --- IBEGIN

	if (has(diffitems, ContIac::NUMFDETRBUVNI)) {
		if ((_contiac->numFDetRbuVni >= VecVVni::MAJ) && (_contiac->numFDetRbuVni <= VecVVni::VOID)) contiac.numFDetRbuVni = _contiac->numFDetRbuVni;
		else contiac.numFDetRbuVni = VecVVni::MAJ;
	};

	if (has(diffitems, ContIac::NUMFDETPUPPRJ)) {
		if (feedFDetPupPrj.getRefByNum(_contiac->numFDetPupPrj) != 0) contiac.numFDetPupPrj = _contiac->numFDetPupPrj;
		else contiac.numFDetPupPrj = 0;

		refreshDetBvr(dbswdbe, moditems);
	};

	if (has(diffitems, ContIac::NUMFDETPUPBVR)) {
		if (feedFDetPupBvr.getRefByNum(_contiac->numFDetPupBvr) != 0) contiac.numFDetPupBvr = _contiac->numFDetPupBvr;
		else contiac.numFDetPupBvr = 0;
	};

	if (has(diffitems, ContIac::DETTXFCMT)) contiac.DetTxfCmt = _contiac->DetTxfCmt;

	valid = (contiac.numFDetPupPrj != 0);

	refresh(dbswdbe, moditems);

	// IP handleDpchAppDataContiac --- IEND
	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgWdbeVerNew::handleDpchAppDoButCncClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButCncClick --- IBEGIN
	*dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBEDLGCLOSE, jref);
	// IP handleDpchAppDoButCncClick --- IEND
};

void DlgWdbeVerNew::handleDpchAppDoButCreClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButCreClick --- RBEGIN
	if (statshr.ButCreActive) {
		if (ixVSge == VecVSge::IDLE) {
			changeStage(dbswdbe, VecVSge::CREATE, dpcheng);
		};

		if (ixVSge == VecVSge::DONE) {
			if (!*dpcheng) *dpcheng = new DpchEngWdbeConfirm(true, jref, "");
			xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBEDLGCLOSE, jref);
		};
	};
	// IP handleDpchAppDoButCreClick --- REND
};

void DlgWdbeVerNew::changeStage(
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
				case VecVSge::DONE: leaveSgeDone(dbswdbe); break;
			};

			setStage(dbswdbe, _ixVSge);
			reenter = false;
			refreshWithDpchEng(dbswdbe, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswdbe, reenter); break;
			case VecVSge::CREATE: _ixVSge = enterSgeCreate(dbswdbe, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswdbe, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWdbeVerNew::getSquawk(
			DbsWdbe* dbswdbe
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

uint DlgWdbeVerNew::enterSgeIdle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWdbeVerNew::leaveSgeIdle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWdbeVerNew::enterSgeCreate(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IDLE;

	// IP enterSgeCreate --- IBEGIN

	WdbeMVersion ver;

	WdbeMVersion* bvr = NULL;

	ListWdbeMRelease rlss;
	WdbeMRelease* rls = NULL;

	ListWdbeRMLibraryMVersion libRvers;
	WdbeRMLibraryMVersion* libRver = NULL;

	map<uint,uint> icsWdbeVIop;
	uint ixWdbeVIop;

	string xmlfile;

	time_t rawtime;
	time(&rawtime);

	ver.grp = xchg->getRefPreset(VecWdbeVPreset::PREWDBEGROUP, jref);
	ver.own = xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref);
	ver.prjRefWdbeMProject = feedFDetPupPrj.getRefByNum(contiac.numFDetPupPrj);

	ver.prjNum = 1;
	if (dbswdbe->loadUintBySQL("SELECT prjNum FROM TblWdbeMVersion WHERE prjRefWdbeMProject = " + to_string(ver.prjRefWdbeMProject) + " ORDER BY prjNum DESC LIMIT 1", ver.prjNum)) ver.prjNum++;

	ver.bvrRefWdbeMVersion = feedFDetPupBvr.getRefByNum(contiac.numFDetPupBvr);

	if (dbswdbe->tblwdbemversion->loadRecByRef(ver.bvrRefWdbeMVersion, &bvr)) {
		ver.Major = bvr->Major;
		ver.Minor = bvr->Minor;
		ver.Sub = bvr->Sub;

		ver.About = bvr->About;

		delete bvr;
	};

	if (contiac.numFDetRbuVni == 1) {
		ver.Major++;
		ver.Minor = 0;
		ver.Sub = 0;
	} else if (contiac.numFDetRbuVni == 2) {
		ver.Minor++;
		ver.Sub = 0;
	} else if (contiac.numFDetRbuVni == 3) {
		ver.Sub++;
	};

	// ver.refJState =
	ver.ixVState = VecWdbeVMVersionState::NEWCRE;

	dbswdbe->tblwdbemversion->insertRec(&ver);

	// state
	ver.refJState = dbswdbe->tblwdbejmversionstate->insertNewRec(NULL, ver.ref, rawtime, ver.ixVState);

	dbswdbe->tblwdbemversion->updateRec(&ver);

	// releases
	if (ver.bvrRefWdbeMVersion != 0) {
		// copy from base version
		dbswdbe->tblwdbemrelease->loadRstBySQL("SELECT * FROM TblWdbeMRelease WHERE refWdbeMVersion = " + to_string(ver.bvrRefWdbeMVersion) + " ORDER BY sref ASC", false, rlss);

		for (unsigned int i = 0; i < rlss.nodes.size(); i++) {
			rls = rlss.nodes[i];

			rls->ref = 0;
			rls->refWdbeMVersion = ver.ref;

			dbswdbe->tblwdbemrelease->insertRec(rls);
		};
	};

	// libraries
	if (ver.bvrRefWdbeMVersion != 0) {
		// copy from base version
		dbswdbe->tblwdbermlibrarymversion->loadRstBySQL("SELECT * FROM TblWdbeRMLibraryMVersion WHERE refWdbeMVersion = " + to_string(ver.bvrRefWdbeMVersion), false, libRvers);

		for (unsigned int i = 0; i < libRvers.nodes.size(); i++) {
			libRver = libRvers.nodes[i];

			libRver->ref = 0;
			libRver->refWdbeMVersion = ver.ref;

			dbswdbe->tblwdbermlibrarymversion->insertRec(libRver);
		};
	};

	// generate and archive project model file as source for WhizniumDBEBootstrap
	iexprj->reset(dbswdbe);

	iexprj->imeimproject.nodes.push_back(new ImeitemIWdbePrjMProject(dbswdbe, ver.prjRefWdbeMProject));

	iexprj->imeimproject.nodes[0]->imeimversion.nodes.push_back(new ImeitemIWdbePrjMVersion(dbswdbe, ver.ref));
	iexprj->imeimproject.nodes[0]->imeimversion.nodes[0]->ixVState = VecWdbeVMVersionState::NEWIMP;

	icsWdbeVIop = IexWdbePrj::icsWdbeVIopInsAll();

	ixWdbeVIop = IexWdbePrj::VecVIme::IMEIMVERSION; icsWdbeVIop.erase(ixWdbeVIop);
	ixWdbeVIop = IexWdbePrj::VecVIme::IMEIJMVERSIONSTATE; icsWdbeVIop.erase(ixWdbeVIop);

	iexprj->collect(dbswdbe, icsWdbeVIop);

	xmlfile = Tmp::newfile(xchg->tmppath, "xml");
	iexprj->exportToFile(dbswdbe, xchg->tmppath + "/" + xmlfile, true);

	Acv::addfile(dbswdbe, xchg->acvpath, xchg->tmppath + "/" + xmlfile, xchg->getRefPreset(VecWdbeVPreset::PREWDBEGROUP, jref), xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref), VecWdbeVMFileRefTbl::VER, ver.ref, "mod", "IexWdbePrj_" + StrMod::lc(feedFDetPupPrj.getSrefByNum(contiac.numFDetPupPrj)) + ".xml", "xml", "");

	xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBEVERMOD, jref);
	xchg->triggerIxRefCall(dbswdbe, VecWdbeVCall::CALLWDBEREFPRESET, jref, VecWdbeVPreset::PREWDBEREFVER, ver.ref);

	// IP enterSgeCreate --- IEND

	return retval;
};

void DlgWdbeVerNew::leaveSgeCreate(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeCreate --- INSERT
};

uint DlgWdbeVerNew::enterSgeDone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void DlgWdbeVerNew::leaveSgeDone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeDone --- INSERT
};
