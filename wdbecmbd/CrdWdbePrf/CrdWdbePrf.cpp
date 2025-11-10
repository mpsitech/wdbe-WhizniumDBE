/**
	* \file CrdWdbePrf.cpp
	* job handler for job CrdWdbePrf (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 8 Jan 2025
	*/
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbed.h>
#endif

#include "CrdWdbePrf.h"

#include "CrdWdbePrf_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class CrdWdbePrf
 ******************************************************************************/

CrdWdbePrf::CrdWdbePrf(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::CRDWDBEPRF, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	pnlheadbar = NULL;
	pnldaemon = NULL;
	pnllicense = NULL;

	// IP constructor.cust1 --- INSERT

	set<uint> moditems;
	refresh(dbswdbe, moditems);

	pnlheadbar = new PnlWdbePrfHeadbar(xchg, dbswdbe, jref, ixWdbeVLocale);
	pnldaemon = new PnlWdbePrfDaemon(xchg, dbswdbe, jref, ixWdbeVLocale);
	pnllicense = new PnlWdbePrfLicense(xchg, dbswdbe, jref, ixWdbeVLocale);

	// IP constructor.cust2 --- INSERT

	statshr.jrefHeadbar = pnlheadbar->jref;
	statshr.jrefDaemon = pnldaemon->jref;
	statshr.jrefLicense = pnllicense->jref;

	changeStage(dbswdbe, VecVSge::IDLE);

	xchg->addClstn(VecWdbeVCall::CALLWDBEDLGCLOSE, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

CrdWdbePrf::~CrdWdbePrf() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- BEGIN
void CrdWdbePrf::setPref(
			DbsWdbe* dbswdbe
		) {
	pnldaemon->setPref(dbswdbe, true);
	pnllicense->setPref(dbswdbe, true);
};

void CrdWdbePrf::storePref() {
	xmlTextWriter* wr = NULL;

	StgWdbeBehavior* stgwdbebehavior = &(xchg->stgwdbebehavior);
	StgWdbeAppsrv* stgwdbeappsrv = &(xchg->stgwdbeappsrv);
#ifdef WDBED
	StgWdbed* stgwdbed = &(xchg->stgwdbed);
#endif
#ifdef WDBECMBD
	StgWdbecmbd* stgwdbecmbd = &(xchg->stgwdbecmbd);
#endif
	StgWdbeDatabase* stgwdbedatabase = &(xchg->stgwdbedatabase);
	StgWdbePath* stgwdbepath = &(xchg->stgwdbepath);
	StgWdbeTenant* stgwdbetenant = &(xchg->stgwdbetenant);
	StgWdbeMonitor* stgwdbemonitor = &(xchg->stgwdbemonitor);
	JobWdbeLicense::Stg* stgjobwdbelicense = &(JobWdbeLicense::stg);

	time_t now;

	int res;

	string s;

#if defined(WDBED)
	const string fileroot = "PrefWdbed";
#elif defined(WDBECMBD)
	const string fileroot = "PrefWdbecmbd";
#endif

	// create backup of current preferences file
	time(&now);
	s = "cp -p " + xchg->exedir + "/" + fileroot + ".xml " + xchg->exedir + "/" + fileroot + "_" + to_string(now) + ".xml";
	res = system(s.c_str());
	if (res != 0) throw SbeException(SbeException::PATHNF, {{"path",xchg->exedir + "/" + fileroot + ".xml"}});

#ifdef WDBED
	pnldaemon->getPref(stgwdbebehavior, stgwdbeappsrv, stgwdbed, stgwdbedatabase, stgwdbepath, stgwdbetenant, stgwdbemonitor);
#endif
#ifdef WDBECMBD
	pnldaemon->getPref(stgwdbebehavior, stgwdbeappsrv, stgwdbecmbd, stgwdbedatabase, stgwdbepath, stgwdbetenant, stgwdbemonitor);
#endif
	pnllicense->getPref(stgjobwdbelicense);

	startwriteFile(xchg->exedir + "/" + fileroot + ".xml", &wr);
	xmlTextWriterSetIndent(wr, 1);
	xmlTextWriterSetIndentString(wr, BAD_CAST "	");
	xmlTextWriterStartElement(wr, BAD_CAST fileroot.c_str());
		stgwdbebehavior->writeXML(wr);
		stgwdbeappsrv->writeXML(wr);
#ifdef WDBED
		stgwdbed->writeXML(wr);
#endif
#ifdef WDBECMBD
		stgwdbecmbd->writeXML(wr);
#endif
		stgwdbedatabase->writeXML(wr);
		stgwdbepath->writeXML(wr);
		stgwdbetenant->writeXML(wr);
		stgwdbemonitor->writeXML(wr);
		stgjobwdbelicense->writeXML(wr);
	xmlTextWriterEndElement(wr);
	closewriteFile(wr);
};
// IP cust --- END

DpchEngWdbe* CrdWdbePrf::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &continf, &feedFSge, &statshr, items);
	};

	return dpcheng;
};

void CrdWdbePrf::refresh(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	ContInf oldContinf(continf);

	// IP refresh --- BEGIN
	// continf
	continf.MrlAppHlp = xchg->helpurl + "/CrdWdbePrf/" + VecWdbeVLocale::getSref(ixWdbeVLocale);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	muteRefresh = false;
};

void CrdWdbePrf::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- INSERT
};

void CrdWdbePrf::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEPRFDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::CLOSE) {
					handleDpchAppDoClose(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITAPPABTCLICK) {
					handleDpchAppDoMitAppAbtClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDRVRCLICK) {
					handleDpchAppDoMitCrdRvrClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDSTOCLICK) {
					handleDpchAppDoMitCrdStoClick(dbswdbe, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEALERT) {
			handleDpchAppWdbeAlert(dbswdbe, (DpchAppWdbeAlert*) (req->dpchapp), &(req->dpcheng));

		};
	};
};

void CrdWdbePrf::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void CrdWdbePrf::handleDpchAppDoClose(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	xchg->triggerIxCall(dbswdbe, VecWdbeVCall::CALLWDBECRDCLOSE, jref, VecWdbeVCard::CRDWDBEPRF);
};

void CrdWdbePrf::handleDpchAppDoMitAppAbtClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoMitAppAbtClick --- BEGIN
	changeStage(dbswdbe, VecVSge::ALRWDBEABT, dpcheng);
	// IP handleDpchAppDoMitAppAbtClick --- END
};

void CrdWdbePrf::handleDpchAppDoMitCrdRvrClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	setPref(dbswdbe); // IP handleDpchAppDoMitCrdRvrClick --- LINE
};

void CrdWdbePrf::handleDpchAppDoMitCrdStoClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	storePref(); // IP handleDpchAppDoMitCrdStoClick --- LINE
};

void CrdWdbePrf::handleDpchAppWdbeAlert(
			DbsWdbe* dbswdbe
			, DpchAppWdbeAlert* dpchappwdbealert
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppWdbeAlert --- BEGIN
	if (ixVSge == VecVSge::ALRWDBEABT) {
		changeStage(dbswdbe, nextIxVSgeSuccess);
	};

	*dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	// IP handleDpchAppWdbeAlert --- END
};

void CrdWdbePrf::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBEDLGCLOSE) {
		call->abort = handleCallWdbeDlgClose(dbswdbe, call->jref);
	};
};

bool CrdWdbePrf::handleCallWdbeDlgClose(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWdbeDlgClose --- INSERT
	return retval;
};

void CrdWdbePrf::changeStage(
			DbsWdbe* dbswdbe
			, uint _ixVSge
			, DpchEngWdbe** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswdbe); break;
				case VecVSge::ALRWDBEABT: leaveSgeAlrwdbeabt(dbswdbe); break;
			};

			setStage(dbswdbe, _ixVSge);
			reenter = false;
			refreshWithDpchEng(dbswdbe, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswdbe, reenter); break;
			case VecVSge::ALRWDBEABT: _ixVSge = enterSgeAlrwdbeabt(dbswdbe, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string CrdWdbePrf::getSquawk(
			DbsWdbe* dbswdbe
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

uint CrdWdbePrf::enterSgeIdle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void CrdWdbePrf::leaveSgeIdle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeIdle --- INSERT
};

uint CrdWdbePrf::enterSgeAlrwdbeabt(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::ALRWDBEABT;
	nextIxVSgeSuccess = VecVSge::IDLE;

	xchg->submitDpch(AlrWdbe::prepareAlrAbt(jref, ixWdbeVLocale, feedFMcbAlert)); // IP enterSgeAlrwdbeabt --- LINE

	return retval;
};

void CrdWdbePrf::leaveSgeAlrwdbeabt(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAlrwdbeabt --- INSERT
};
