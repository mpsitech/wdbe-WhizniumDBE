/**
	* \file DlgWdbeUsrMngkeypair.cpp
	* job handler for job DlgWdbeUsrMngkeypair (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbed.h>
#endif

#include "DlgWdbeUsrMngkeypair.h"

#include "DlgWdbeUsrMngkeypair_blks.cpp"
#include "DlgWdbeUsrMngkeypair_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWdbeUsrMngkeypair
 ******************************************************************************/

DlgWdbeUsrMngkeypair::DlgWdbeUsrMngkeypair(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::DLGWDBEUSRMNGKEYPAIR, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	// IP constructor.cust1 --- IBEGIN
	dbswdbe->loadStringBySQL("SELECT sref FROM TblWdbeMUser WHERE ref = " + to_string(xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUSR, jref)), usrsref);

	string s = xchg->stgwdbepath.keypath + "/id_wdbe_" + usrsref;

	if (access(s.c_str(), R_OK) == 0) ixVSge = VecVSge::FOUND;
	else ixVSge = VecVSge::NF;
	// IP constructor.cust1 --- IEND

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswdbe, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgWdbeUsrMngkeypair::~DlgWdbeUsrMngkeypair() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* DlgWdbeUsrMngkeypair::getNewDpchEng(
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

void DlgWdbeUsrMngkeypair::refresh(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- RBEGIN
	// continf
	continf.numFSge = ixVSge;
	continf.DetTxtSte = getSquawk(dbswdbe);
	continf.DetDld = "id_wdbe_" + usrsref + ".pub";

	// statshr
	statshr.DetButDelAvail = evalDetButDelAvail(dbswdbe);
	statshr.DetButGenAvail = evalDetButGenAvail(dbswdbe);
	statshr.DetDldActive = evalDetDldActive(dbswdbe);

	// IP refresh --- REND
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void DlgWdbeUsrMngkeypair::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEUSRMNGKEYPAIRDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::DETBUTDELCLICK) {
					handleDpchAppDoDetButDelClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::DETBUTGENCLICK) {
					handleDpchAppDoDetButGenClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbswdbe, &(req->dpcheng));
				};

			};

		};

	} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::DOWNLOAD) {
		if (ixVSge == VecVSge::FOUND) req->filename = handleDownloadInSgeFound(dbswdbe);
	};
};

void DlgWdbeUsrMngkeypair::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWdbeUsrMngkeypair::handleDpchAppDoDetButDelClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoDetButDelClick --- IBEGIN
	string s;

	s = xchg->stgwdbepath.keypath + "/id_wdbe_" + usrsref;
	if (access(s.c_str(), R_OK) == 0) Wdbe::run("rm " + s);

	s = xchg->stgwdbepath.keypath + "/id_wdbe_" + usrsref + ".pub";
	if (access(s.c_str(), R_OK) == 0) Wdbe::run("rm " + s);

	changeStage(dbswdbe, VecVSge::NF, dpcheng);
	// IP handleDpchAppDoDetButDelClick --- IEND
};

void DlgWdbeUsrMngkeypair::handleDpchAppDoDetButGenClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoDetButGenClick --- IBEGIN
	string s = xchg->stgwdbepath.keypath + "/id_wdbe_" + usrsref;

	char hostname[256];
	gethostname(hostname, 256);

	Wdbe::run("ssh-keygen -t rsa -b 4096 -f " + s + " -C WhizniumDBE:" + usrsref + "@" + string(hostname) + " -N ''");

	if (access(s.c_str(), R_OK) == 0) changeStage(dbswdbe, VecVSge::FOUND, dpcheng);
	// IP handleDpchAppDoDetButGenClick --- IEND
};

void DlgWdbeUsrMngkeypair::handleDpchAppDoButDneClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoButDneClick --- IBEGIN
	*dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	xchg->triggerCall(dbswdbe, VecWdbeVCall::CALLWDBEDLGCLOSE, jref);
	// IP handleDpchAppDoButDneClick --- IEND
};

string DlgWdbeUsrMngkeypair::handleDownloadInSgeFound(
			DbsWdbe* dbswdbe
		) {
	return(xchg->stgwdbepath.keypath + "/id_wdbe_" + usrsref + ".pub"); // IP handleDownloadInSgeFound --- RLINE
};

void DlgWdbeUsrMngkeypair::changeStage(
			DbsWdbe* dbswdbe
			, uint _ixVSge
			, DpchEngWdbe** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::NF: leaveSgeNf(dbswdbe); break;
				case VecVSge::FOUND: leaveSgeFound(dbswdbe); break;
			};

			setStage(dbswdbe, _ixVSge);
			reenter = false;
			if (!muteRefresh) refreshWithDpchEng(dbswdbe, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::NF: _ixVSge = enterSgeNf(dbswdbe, reenter); break;
			case VecVSge::FOUND: _ixVSge = enterSgeFound(dbswdbe, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWdbeUsrMngkeypair::getSquawk(
			DbsWdbe* dbswdbe
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::NF) || (ixVSge == VecVSge::FOUND) ) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			if (ixVSge == VecVSge::NF) retval = "SSH key pair not found";
			else if (ixVSge == VecVSge::FOUND) retval = "SSH key pair found";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint DlgWdbeUsrMngkeypair::enterSgeNf(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::NF;

	// IP enterSgeNf --- INSERT

	return retval;
};

void DlgWdbeUsrMngkeypair::leaveSgeNf(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeNf --- INSERT
};

uint DlgWdbeUsrMngkeypair::enterSgeFound(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::FOUND;

	// IP enterSgeFound --- INSERT

	return retval;
};

void DlgWdbeUsrMngkeypair::leaveSgeFound(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeFound --- INSERT
};


