/**
	* \file CrdWdbeNav.cpp
	* job handler for job CrdWdbeNav (implementation)
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

#include "CrdWdbeNav.h"

#include "CrdWdbeNav_blks.cpp"
#include "CrdWdbeNav_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class CrdWdbeNav
 ******************************************************************************/

CrdWdbeNav::CrdWdbeNav(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::CRDWDBENAV, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	pnlauxfct = NULL;
	pnldescr = NULL;
	pnlcoredev = NULL;
	pnldevdev = NULL;
	pnlglobal = NULL;
	pnladmin = NULL;
	pnlpre = NULL;
	pnlheadbar = NULL;
	dlgloaini = NULL;
	dlgmnglic = NULL;

	// IP constructor.cust1 --- INSERT

	set<uint> moditems;
	refresh(dbswdbe, moditems);

	pnlauxfct = new PnlWdbeNavAuxfct(xchg, dbswdbe, jref, ixWdbeVLocale);
	pnldescr = new PnlWdbeNavDescr(xchg, dbswdbe, jref, ixWdbeVLocale);
	pnlcoredev = new PnlWdbeNavCoredev(xchg, dbswdbe, jref, ixWdbeVLocale);
	pnldevdev = new PnlWdbeNavDevdev(xchg, dbswdbe, jref, ixWdbeVLocale);
	pnlglobal = new PnlWdbeNavGlobal(xchg, dbswdbe, jref, ixWdbeVLocale);
	pnladmin = new PnlWdbeNavAdmin(xchg, dbswdbe, jref, ixWdbeVLocale);
	pnlpre = new PnlWdbeNavPre(xchg, dbswdbe, jref, ixWdbeVLocale);
	pnlheadbar = new PnlWdbeNavHeadbar(xchg, dbswdbe, jref, ixWdbeVLocale);

	// IP constructor.cust2 --- INSERT

	statshr.jrefHeadbar = pnlheadbar->jref;
	statshr.jrefPre = pnlpre->jref;
	statshr.jrefAdmin = pnladmin->jref;
	statshr.jrefGlobal = pnlglobal->jref;
	statshr.jrefDevdev = pnldevdev->jref;
	statshr.jrefCoredev = pnlcoredev->jref;
	statshr.jrefDescr = pnldescr->jref;
	statshr.jrefAuxfct = pnlauxfct->jref;

	changeStage(dbswdbe, VecVSge::IDLE);

	xchg->addClstn(VecWdbeVCall::CALLWDBEDLGCLOSE, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

CrdWdbeNav::~CrdWdbeNav() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* CrdWdbeNav::getNewDpchEng(
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

void CrdWdbeNav::refresh(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	string s;
	vector<string> ss;

	// continf
	continf.MrlAppHlp = xchg->helpurl + "/CrdWdbeNav/" + VecWdbeVLocale::getSref(ixWdbeVLocale);

	s = StubWdbe::getStubSesMenu(dbswdbe, xchg->getRefPreset(VecWdbeVPreset::PREWDBESESS, jref), ixWdbeVLocale, Stub::VecVNonetype::DASH);
	StrMod::stringToVector(s, ss);

	if (ss.size() == 3) {
		continf.MtxSesSes1 = ss[0];
		continf.MtxSesSes2 = ss[1];
		continf.MtxSesSes3 = ss[2];
	};

	// statshr
	statshr.pnlpreAvail = evalPnlpreAvail(dbswdbe);
	statshr.pnladminAvail = evalPnladminAvail(dbswdbe);
	statshr.pnlglobalAvail = evalPnlglobalAvail(dbswdbe);
	statshr.pnldevdevAvail = evalPnldevdevAvail(dbswdbe);
	statshr.pnlcoredevAvail = evalPnlcoredevAvail(dbswdbe);
	statshr.pnldescrAvail = evalPnldescrAvail(dbswdbe);
	statshr.pnlauxfctAvail = evalPnlauxfctAvail(dbswdbe);
	statshr.MitSesSpsAvail = evalMitSesSpsAvail(dbswdbe);
	statshr.MspCrd1Avail = evalMspCrd1Avail(dbswdbe);
	statshr.MitCrdUsgAvail = evalMitCrdUsgAvail(dbswdbe);
	statshr.MitCrdUsrAvail = evalMitCrdUsrAvail(dbswdbe);
	statshr.MitCrdPrsAvail = evalMitCrdPrsAvail(dbswdbe);
	statshr.MitCrdFilAvail = evalMitCrdFilAvail(dbswdbe);
	statshr.MspCrd2Avail = evalMspCrd2Avail(dbswdbe);
	statshr.MitCrdMchAvail = evalMitCrdMchAvail(dbswdbe);
	statshr.MitCrdLibAvail = evalMitCrdLibAvail(dbswdbe);
	statshr.MitCrdFamAvail = evalMitCrdFamAvail(dbswdbe);
	statshr.MitCrdSilAvail = evalMitCrdSilAvail(dbswdbe);
	statshr.MitCrdMtpAvail = evalMitCrdMtpAvail(dbswdbe);
	statshr.MspCrd3Avail = evalMspCrd3Avail(dbswdbe);
	statshr.MitCrdPrjAvail = evalMitCrdPrjAvail(dbswdbe);
	statshr.MitCrdVerAvail = evalMitCrdVerAvail(dbswdbe);
	statshr.MitCrdSysAvail = evalMitCrdSysAvail(dbswdbe);
	statshr.MitCrdSysActive = evalMitCrdSysActive(dbswdbe);
	statshr.MitCrdTrgAvail = evalMitCrdTrgAvail(dbswdbe);
	statshr.MitCrdTrgActive = evalMitCrdTrgActive(dbswdbe);
	statshr.MitCrdUntAvail = evalMitCrdUntAvail(dbswdbe);
	statshr.MitCrdUntActive = evalMitCrdUntActive(dbswdbe);
	statshr.MitCrdRlsAvail = evalMitCrdRlsAvail(dbswdbe);
	statshr.MitCrdRlsActive = evalMitCrdRlsActive(dbswdbe);
	statshr.MspCrd4Avail = evalMspCrd4Avail(dbswdbe);
	statshr.MitCrdCprAvail = evalMitCrdCprAvail(dbswdbe);
	statshr.MitCrdCvrAvail = evalMitCrdCvrAvail(dbswdbe);
	statshr.MspCrd5Avail = evalMspCrd5Avail(dbswdbe);
	statshr.MitCrdModAvail = evalMitCrdModAvail(dbswdbe);
	statshr.MitCrdModActive = evalMitCrdModActive(dbswdbe);
	statshr.MitCrdVecAvail = evalMitCrdVecAvail(dbswdbe);
	statshr.MitCrdVecActive = evalMitCrdVecActive(dbswdbe);
	statshr.MitCrdCmdAvail = evalMitCrdCmdAvail(dbswdbe);
	statshr.MitCrdCmdActive = evalMitCrdCmdActive(dbswdbe);
	statshr.MitCrdErrAvail = evalMitCrdErrAvail(dbswdbe);
	statshr.MitCrdErrActive = evalMitCrdErrActive(dbswdbe);
	statshr.MitCrdPphAvail = evalMitCrdPphAvail(dbswdbe);
	statshr.MitCrdPphActive = evalMitCrdPphActive(dbswdbe);
	statshr.MitCrdBnkAvail = evalMitCrdBnkAvail(dbswdbe);
	statshr.MitCrdBnkActive = evalMitCrdBnkActive(dbswdbe);
	statshr.MitCrdPinAvail = evalMitCrdPinAvail(dbswdbe);
	statshr.MitCrdPinActive = evalMitCrdPinActive(dbswdbe);
	statshr.MspCrd6Avail = evalMspCrd6Avail(dbswdbe);
	statshr.MitCrdUtlAvail = evalMitCrdUtlAvail(dbswdbe);
	statshr.MspApp2Avail = evalMspApp2Avail(dbswdbe);
	statshr.MitAppMlcAvail = evalMitAppMlcAvail(dbswdbe);
	statshr.MitAppLoiAvail = evalMitAppLoiAvail(dbswdbe);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void CrdWdbeNav::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	refresh(dbswdbe, moditems);
	if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));

	if (pnlpre) if (jrefTrig != pnlpre->jref) pnlpre->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
	if (pnladmin) pnladmin->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
	if (pnlglobal) pnlglobal->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
	if (pnldevdev) pnldevdev->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
	if (pnlcoredev) pnlcoredev->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
	if (pnldescr) pnldescr->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
	if (pnlauxfct) pnlauxfct->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
	// IP updatePreset --- END
};

void CrdWdbeNav::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::CLOSE) {
					handleDpchAppDoClose(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITAPPABTCLICK) {
					handleDpchAppDoMitAppAbtClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITSESSPSCLICK) {
					handleDpchAppDoMitSesSpsClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITSESTRMCLICK) {
					handleDpchAppDoMitSesTrmClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDUSGCLICK) {
					handleDpchAppDoMitCrdUsgClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDUSRCLICK) {
					handleDpchAppDoMitCrdUsrClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDPRSCLICK) {
					handleDpchAppDoMitCrdPrsClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDFILCLICK) {
					handleDpchAppDoMitCrdFilClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDMCHCLICK) {
					handleDpchAppDoMitCrdMchClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDLIBCLICK) {
					handleDpchAppDoMitCrdLibClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDFAMCLICK) {
					handleDpchAppDoMitCrdFamClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDSILCLICK) {
					handleDpchAppDoMitCrdSilClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDMTPCLICK) {
					handleDpchAppDoMitCrdMtpClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDPRJCLICK) {
					handleDpchAppDoMitCrdPrjClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDVERCLICK) {
					handleDpchAppDoMitCrdVerClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDSYSCLICK) {
					handleDpchAppDoMitCrdSysClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDTRGCLICK) {
					handleDpchAppDoMitCrdTrgClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDUNTCLICK) {
					handleDpchAppDoMitCrdUntClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDRLSCLICK) {
					handleDpchAppDoMitCrdRlsClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDCPRCLICK) {
					handleDpchAppDoMitCrdCprClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDCVRCLICK) {
					handleDpchAppDoMitCrdCvrClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDMODCLICK) {
					handleDpchAppDoMitCrdModClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDVECCLICK) {
					handleDpchAppDoMitCrdVecClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDCMDCLICK) {
					handleDpchAppDoMitCrdCmdClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDERRCLICK) {
					handleDpchAppDoMitCrdErrClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDPPHCLICK) {
					handleDpchAppDoMitCrdPphClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDBNKCLICK) {
					handleDpchAppDoMitCrdBnkClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDPINCLICK) {
					handleDpchAppDoMitCrdPinClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDUTLCLICK) {
					handleDpchAppDoMitCrdUtlClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITAPPMLCCLICK) {
					handleDpchAppDoMitAppMlcClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITAPPLOICLICK) {
					handleDpchAppDoMitAppLoiClick(dbswdbe, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEALERT) {
			handleDpchAppWdbeAlert(dbswdbe, (DpchAppWdbeAlert*) (req->dpchapp), &(req->dpcheng));

		};
	};
};

void CrdWdbeNav::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void CrdWdbeNav::handleDpchAppDoClose(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngWdbeConfirm(true, jref, "");

	if (xchg->stgwdbeappearance.suspsess) xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBESUSPSESS, xchg->getRefPreset(VecWdbeVPreset::PREWDBEJREFSESS, jref));
	else xchg->triggerBoolvalCall(dbswdbe, VecWdbeVCall::CALLWDBELOGOUT, xchg->getRefPreset(VecWdbeVPreset::PREWDBEJREFSESS, jref), false);
};

void CrdWdbeNav::handleDpchAppDoMitAppAbtClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoMitAppAbtClick --- BEGIN
	changeStage(dbswdbe, VecVSge::ALRWDBEABT, dpcheng);
	// IP handleDpchAppDoMitAppAbtClick --- END
};

void CrdWdbeNav::handleDpchAppDoMitSesSpsClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngWdbeConfirm(true, jref, "");

	xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBESUSPSESS, xchg->getRefPreset(VecWdbeVPreset::PREWDBEJREFSESS, jref));
};

void CrdWdbeNav::handleDpchAppDoMitSesTrmClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngWdbeConfirm(true, jref, "");

	xchg->triggerBoolvalCall(dbswdbe, VecWdbeVCall::CALLWDBELOGOUT, xchg->getRefPreset(VecWdbeVPreset::PREWDBEJREFSESS, jref), false);
};

void CrdWdbeNav::handleDpchAppDoMitCrdUsgClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbeUsg", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
	else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeUsg");
};

void CrdWdbeNav::handleDpchAppDoMitCrdUsrClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbeUsr", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
	else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeUsr");
};

void CrdWdbeNav::handleDpchAppDoMitCrdPrsClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbePrs", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
	else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbePrs");
};

void CrdWdbeNav::handleDpchAppDoMitCrdFilClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbeFil", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
	else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeFil");
};

void CrdWdbeNav::handleDpchAppDoMitCrdMchClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbeMch", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
	else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeMch");
};

void CrdWdbeNav::handleDpchAppDoMitCrdLibClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbeLib", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
	else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeLib");
};

void CrdWdbeNav::handleDpchAppDoMitCrdFamClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbeFam", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
	else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeFam");
};

void CrdWdbeNav::handleDpchAppDoMitCrdSilClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbeSil", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
	else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeSil");
};

void CrdWdbeNav::handleDpchAppDoMitCrdMtpClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbeMtp", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
	else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeMtp");
};

void CrdWdbeNav::handleDpchAppDoMitCrdPrjClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbePrj", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
	else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbePrj");
};

void CrdWdbeNav::handleDpchAppDoMitCrdVerClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbeVer", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
	else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeVer");
};

void CrdWdbeNav::handleDpchAppDoMitCrdSysClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbeSys", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
	else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeSys");
};

void CrdWdbeNav::handleDpchAppDoMitCrdTrgClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbeTrg", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
	else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeTrg");
};

void CrdWdbeNav::handleDpchAppDoMitCrdUntClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbeUnt", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
	else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeUnt");
};

void CrdWdbeNav::handleDpchAppDoMitCrdRlsClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbeRls", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
	else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeRls");
};

void CrdWdbeNav::handleDpchAppDoMitCrdCprClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbeCpr", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
	else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeCpr");
};

void CrdWdbeNav::handleDpchAppDoMitCrdCvrClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbeCvr", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
	else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeCvr");
};

void CrdWdbeNav::handleDpchAppDoMitCrdModClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbeMod", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
	else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeMod");
};

void CrdWdbeNav::handleDpchAppDoMitCrdVecClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbeVec", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
	else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeVec");
};

void CrdWdbeNav::handleDpchAppDoMitCrdCmdClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbeCmd", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
	else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeCmd");
};

void CrdWdbeNav::handleDpchAppDoMitCrdErrClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbeErr", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
	else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeErr");
};

void CrdWdbeNav::handleDpchAppDoMitCrdPphClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbePph", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
	else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbePph");
};

void CrdWdbeNav::handleDpchAppDoMitCrdBnkClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbeBnk", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
	else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeBnk");
};

void CrdWdbeNav::handleDpchAppDoMitCrdPinClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbePin", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
	else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbePin");
};

void CrdWdbeNav::handleDpchAppDoMitCrdUtlClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbeUtl", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
	else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeUtl");
};

void CrdWdbeNav::handleDpchAppDoMitAppMlcClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoMitAppMlcClick --- INSERT
};

void CrdWdbeNav::handleDpchAppDoMitAppLoiClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	if (!dlgloaini) {
		dlgloaini = new DlgWdbeNavLoaini(xchg, dbswdbe, jref, ixWdbeVLocale);
		statshr.jrefDlgloaini = dlgloaini->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWdbeNav::handleDpchAppWdbeAlert(
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

void CrdWdbeNav::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBEDLGCLOSE) {
		call->abort = handleCallWdbeDlgClose(dbswdbe, call->jref);
	};
};

bool CrdWdbeNav::handleCallWdbeDlgClose(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if (dlgloaini) {
		delete dlgloaini;
		dlgloaini = NULL;
		statshr.jrefDlgloaini = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	} else if (dlgmnglic) {
		delete dlgmnglic;
		dlgmnglic = NULL;
		statshr.jrefDlgmnglic = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	};

	return retval;
};

void CrdWdbeNav::changeStage(
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

string CrdWdbeNav::getSquawk(
			DbsWdbe* dbswdbe
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

uint CrdWdbeNav::enterSgeIdle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void CrdWdbeNav::leaveSgeIdle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeIdle --- INSERT
};

uint CrdWdbeNav::enterSgeAlrwdbeabt(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::ALRWDBEABT;
	nextIxVSgeSuccess = VecVSge::IDLE;

	xchg->submitDpch(AlrWdbe::prepareAlrAbt(jref, ixWdbeVLocale, feedFMcbAlert)); // IP enterSgeAlrwdbeabt --- LINE

	return retval;
};

void CrdWdbeNav::leaveSgeAlrwdbeabt(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAlrwdbeabt --- INSERT
};



