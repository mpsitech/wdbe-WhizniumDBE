/**
	* \file CrdWdbeUtl.cpp
	* job handler for job CrdWdbeUtl (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbed.h>
#endif

#include "CrdWdbeUtl.h"

#include "CrdWdbeUtl_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class CrdWdbeUtl
 ******************************************************************************/

CrdWdbeUtl::CrdWdbeUtl(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::CRDWDBEUTL, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	dlgextrip = NULL;
	dlgiexconv = NULL;
	dlgmrgip = NULL;
	pnlheadbar = NULL;

	// IP constructor.cust1 --- INSERT

	set<uint> moditems;
	refresh(dbswdbe, moditems);

	pnlheadbar = new PnlWdbeUtlHeadbar(xchg, dbswdbe, jref, ixWdbeVLocale);

	// IP constructor.cust2 --- INSERT

	statshr.jrefHeadbar = pnlheadbar->jref;

	changeStage(dbswdbe, VecVSge::IDLE);

	xchg->addClstn(VecWdbeVCall::CALLWDBEDLGCLOSE, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

CrdWdbeUtl::~CrdWdbeUtl() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* CrdWdbeUtl::getNewDpchEng(
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

void CrdWdbeUtl::refresh(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);

	// IP refresh --- BEGIN
	// continf
	continf.MrlAppHlp = xchg->helpurl + "/CrdWdbeUtl/" + VecWdbeVLocale::getSref(ixWdbeVLocale);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
};

void CrdWdbeUtl::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- INSERT
};

void CrdWdbeUtl::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUTLDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::CLOSE) {
					handleDpchAppDoClose(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITAPPABTCLICK) {
					handleDpchAppDoMitAppAbtClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDCIFCLICK) {
					handleDpchAppDoMitCrdCifClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDXIPCLICK) {
					handleDpchAppDoMitCrdXipClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDMIPCLICK) {
					handleDpchAppDoMitCrdMipClick(dbswdbe, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEALERT) {
			handleDpchAppWdbeAlert(dbswdbe, (DpchAppWdbeAlert*) (req->dpchapp), &(req->dpcheng));

		};
	};
};

void CrdWdbeUtl::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void CrdWdbeUtl::handleDpchAppDoClose(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	xchg->triggerIxCall(dbswdbe, VecWdbeVCall::CALLWDBECRDCLOSE, jref, VecWdbeVCard::CRDWDBEUTL);
};

void CrdWdbeUtl::handleDpchAppDoMitAppAbtClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoMitAppAbtClick --- BEGIN
	changeStage(dbswdbe, VecVSge::ALRWDBEABT, dpcheng);
	// IP handleDpchAppDoMitAppAbtClick --- END
};

void CrdWdbeUtl::handleDpchAppDoMitCrdCifClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	if (!dlgiexconv) {
		dlgiexconv = new DlgWdbeUtlIexconv(xchg, dbswdbe, jref, ixWdbeVLocale);
		statshr.jrefDlgiexconv = dlgiexconv->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWdbeUtl::handleDpchAppDoMitCrdXipClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	if (!dlgextrip) {
		dlgextrip = new DlgWdbeUtlExtrip(xchg, dbswdbe, jref, ixWdbeVLocale);
		statshr.jrefDlgextrip = dlgextrip->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWdbeUtl::handleDpchAppDoMitCrdMipClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	if (!dlgmrgip) {
		dlgmrgip = new DlgWdbeUtlMrgip(xchg, dbswdbe, jref, ixWdbeVLocale);
		statshr.jrefDlgmrgip = dlgmrgip->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWdbeUtl::handleDpchAppWdbeAlert(
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

void CrdWdbeUtl::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBEDLGCLOSE) {
		call->abort = handleCallWdbeDlgClose(dbswdbe, call->jref);
	};
};

bool CrdWdbeUtl::handleCallWdbeDlgClose(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if (dlgextrip) {
		delete dlgextrip;
		dlgextrip = NULL;
		statshr.jrefDlgextrip = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	} else if (dlgiexconv) {
		delete dlgiexconv;
		dlgiexconv = NULL;
		statshr.jrefDlgiexconv = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	} else if (dlgmrgip) {
		delete dlgmrgip;
		dlgmrgip = NULL;
		statshr.jrefDlgmrgip = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	};

	return retval;
};

void CrdWdbeUtl::changeStage(
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
			if (!muteRefresh) refreshWithDpchEng(dbswdbe, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswdbe, reenter); break;
			case VecVSge::ALRWDBEABT: _ixVSge = enterSgeAlrwdbeabt(dbswdbe, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string CrdWdbeUtl::getSquawk(
			DbsWdbe* dbswdbe
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

uint CrdWdbeUtl::enterSgeIdle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void CrdWdbeUtl::leaveSgeIdle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeIdle --- INSERT
};

uint CrdWdbeUtl::enterSgeAlrwdbeabt(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::ALRWDBEABT;
	nextIxVSgeSuccess = VecVSge::IDLE;

	xchg->submitDpch(AlrWdbe::prepareAlrAbt(jref, ixWdbeVLocale, feedFMcbAlert)); // IP enterSgeAlrwdbeabt --- LINE

	return retval;
};

void CrdWdbeUtl::leaveSgeAlrwdbeabt(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAlrwdbeabt --- INSERT
};

