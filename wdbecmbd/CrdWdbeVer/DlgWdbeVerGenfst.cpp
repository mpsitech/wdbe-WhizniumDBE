/**
	* \file DlgWdbeVerGenfst.cpp
	* job handler for job DlgWdbeVerGenfst (implementation)
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

#include "DlgWdbeVerGenfst.h"

#include "DlgWdbeVerGenfst_blks.cpp"
#include "DlgWdbeVerGenfst_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWdbeVerGenfst
 ******************************************************************************/

DlgWdbeVerGenfst::DlgWdbeVerGenfst(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::DLGWDBEVERGENFST, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswdbe, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgWdbeVerGenfst::~DlgWdbeVerGenfst() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* DlgWdbeVerGenfst::getNewDpchEng(
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

void DlgWdbeVerGenfst::refresh(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- RBEGIN
	// continf
	continf.numFSge = ixVSge;
	continf.GfsTxtPrg = getSquawk(dbswdbe);

	// statshr
	statshr.GfsButRunActive = evalGfsButRunActive(dbswdbe);
	statshr.GfsButStoActive = evalGfsButStoActive(dbswdbe);
	statshr.ButDneActive = evalButDneActive(dbswdbe);

	// IP refresh --- REND
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void DlgWdbeVerGenfst::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBEVERGENFSTDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::GFSBUTRUNCLICK) {
					handleDpchAppDoGfsButRunClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::GFSBUTSTOCLICK) {
					handleDpchAppDoGfsButStoClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbswdbe, &(req->dpcheng));
				};

			};

		};

	} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::DPCHRET) {
		if (req->dpchret->ixOpVOpres == VecOpVOpres::PROGRESS) {
			// IP handleRequest.opprogress --- INSERT
		} else {
			if (req->dpchret->ixWdbeVDpch == VecWdbeVDpch::DPCHRETWDBE) {
				handleDpchRetWdbe(dbswdbe, (DpchRetWdbe*) (req->dpchret));
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
		if ((req->sref == "mon") && (ixVSge == VecVSge::GENFST)) handleTimerWithSrefMonInSgeGenfst(dbswdbe);
		else if ((req->sref == "mon") && (ixVSge == VecVSge::GENMTP)) handleTimerWithSrefMonInSgeGenmtp(dbswdbe);
	};
};

void DlgWdbeVerGenfst::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWdbeVerGenfst::handleDpchAppDoGfsButRunClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoGfsButRunClick --- BEGIN
	if (statshr.GfsButRunActive) {
		changeStage(dbswdbe, VecVSge::GENFST, dpcheng);
	};
	// IP handleDpchAppDoGfsButRunClick --- END
};

void DlgWdbeVerGenfst::handleDpchAppDoGfsButStoClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoGfsButStoClick --- INSERT
};

void DlgWdbeVerGenfst::handleDpchAppDoButDneClick(
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

void DlgWdbeVerGenfst::handleDpchRetWdbe(
			DbsWdbe* dbswdbe
			, DpchRetWdbe* dpchret
		) {
	// IP handleDpchRetWdbe --- INSERT
};

void DlgWdbeVerGenfst::handleTimerWithSrefMonInSgeGenfst(
			DbsWdbe* dbswdbe
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	// IP handleTimerWithSrefMonInSgeGenfst --- INSERT
};

void DlgWdbeVerGenfst::handleTimerWithSrefMonInSgeGenmtp(
			DbsWdbe* dbswdbe
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	// IP handleTimerWithSrefMonInSgeGenmtp --- INSERT
};

void DlgWdbeVerGenfst::changeStage(
			DbsWdbe* dbswdbe
			, uint _ixVSge
			, DpchEngWdbe** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswdbe); break;
				case VecVSge::GENFST: leaveSgeGenfst(dbswdbe); break;
				case VecVSge::GENMTP: leaveSgeGenmtp(dbswdbe); break;
				case VecVSge::DONE: leaveSgeDone(dbswdbe); break;
			};

			setStage(dbswdbe, _ixVSge);
			reenter = false;
			refreshWithDpchEng(dbswdbe, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswdbe, reenter); break;
			case VecVSge::GENFST: _ixVSge = enterSgeGenfst(dbswdbe, reenter); break;
			case VecVSge::GENMTP: _ixVSge = enterSgeGenmtp(dbswdbe, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswdbe, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWdbeVerGenfst::getSquawk(
			DbsWdbe* dbswdbe
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::GENFST) || (ixVSge == VecVSge::GENMTP) ) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			if (ixVSge == VecVSge::GENFST) retval = "generating fine structure top-down (" + to_string(opNSuccess + opNFailure) + "/" + to_string(opN) + " operations completed; last: " + getOpsqkLast() + ")";
			else if (ixVSge == VecVSge::GENMTP) retval = "generating module template-specific fine structure top-down (" + to_string(opNSuccess + opNFailure) + "/" + to_string(opN) + " operations completed; last: " + getOpsqkLast() + ")";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint DlgWdbeVerGenfst::enterSgeIdle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWdbeVerGenfst::leaveSgeIdle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWdbeVerGenfst::enterSgeGenfst(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::GENFST;
	nextIxVSgeSuccess = VecVSge::GENFST;

	clearInvs();

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);

	// IP enterSgeGenfst --- IBEGIN

	// modules bottom-up order

	ubigint refWdbeMVersion;
	string Prjshort;

	ListWdbeMUnit unts;
	WdbeMUnit* unt = NULL;

	WdbeMModule* mdl = NULL;

	unsigned int lvl;

	string Untsref;
	bool mcuNotFpga;

	bool typmod;

	refWdbeMVersion = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref);
	Prjshort = Wdbe::getPrjshort(dbswdbe, refWdbeMVersion);

	if (mdls.nodes.size() == 0) {
		dbswdbe->tblwdbemunit->loadRstBySQL("SELECT * FROM TblWdbeMUnit WHERE refIxVTbl = " + to_string(VecWdbeVMUnitRefTbl::VER) + " AND refUref = " + to_string(refWdbeMVersion), false, unts);
		for (unsigned int i = 0; i < unts.nodes.size(); i++) {
			unt = unts.nodes[i];

			UntsrefsUnts[unt->ref] = StrMod::cap(unt->sref);
			mcuNotFpgasUnts[unt->ref] = (unt->ixVBasetype == VecWdbeVMUnitBasetype::MCU);
		};

		Wdbe::levelMdls(dbswdbe, refWdbeMVersion, mdls, lvlsMdls, true);
		
		//cout << "DlgWdbeVerGenfst::enterSgeGenfst() order is:" << endl;
		//Wdbe::showLvlsMdls(dbswdbe, mdls, lvlsMdls);
	};

	// determine modules due for op invocation
	for (unsigned int i = 0; i < mdls.nodes.size(); i++) {
		mdl = mdls.nodes[i];
		lvl = lvlsMdls[i];

		// invs complete if at least one added on superior level
		if (opN > 0) if (i != 0) if (lvl != lvlsMdls[i-1]) break;

		// check for type-based modification
		typmod = false;

		if (refsTypmod.find(mdl->ref) == refsTypmod.end()) {
			if (mdl->ixVBasetype == VecWdbeVMModuleBasetype::TOP) {
				addInv(new DpchInvWdbeGenfstTop(0, 0, mdl->ref));
				typmod = true;

			} else if (mdl->ixVBasetype == VecWdbeVMModuleBasetype::HOSTIF) {
				addInv(new DpchInvWdbeGenfstHostif(0, 0, mdl->ref));
				typmod = true;

			} else if (mdl->ixVBasetype == VecWdbeVMModuleBasetype::EHOSTIF) {
				auto it = mcuNotFpgasUnts.find(mdl->hkUref);
				if (it != mcuNotFpgasUnts.end()) mcuNotFpga = it->second;
				else mcuNotFpga = false;

				addInv(new DpchInvWdbeGenfstEhostif(0, 0, mdl->ref, mcuNotFpga));
				typmod = true;

			} else if (mdl->ixVBasetype == VecWdbeVMModuleBasetype::CMDBUS) {
				auto it = mcuNotFpgasUnts.find(mdl->hkUref);
				if (it != mcuNotFpgasUnts.end()) mcuNotFpga = it->second;
				else mcuNotFpga = false;

				addInv(new DpchInvWdbeGenfstCmdbus(0, 0, mdl->ref, mcuNotFpga));
				typmod = true;

			} else if (mdl->ixVBasetype == VecWdbeVMModuleBasetype::IMBUF) {
				addInv(new DpchInvWdbeGenfstImbuf(0, 0, mdl->ref));
				typmod = true;

			} else if ((mdl->ixVBasetype == VecWdbeVMModuleBasetype::CTR) || (mdl->ixVBasetype == VecWdbeVMModuleBasetype::DBGCTR)) {
				auto it = UntsrefsUnts.find(mdl->hkUref);
				if (it != UntsrefsUnts.end()) Untsref = it->second;
				else Untsref = "";

				addInv(new DpchInvWdbeGenfstCtr(0, 0, mdl->ref, Prjshort, Untsref));
				typmod = true;

			} else if ((mdl->ixVBasetype == VecWdbeVMModuleBasetype::ECTR) || (mdl->ixVBasetype == VecWdbeVMModuleBasetype::EDBGCTR)) {
				addInv(new DpchInvWdbeGenfstEctr(0, 0, mdl->ref, Prjshort, Untsref));
				typmod = true;
			};
		};

		if (typmod) refsTypmod.insert(mdl->ref);
	};
	// IP enterSgeGenfst --- IEND

	submitInvs(dbswdbe, VecVSge::GENMTP, retval);
	return retval;
};

void DlgWdbeVerGenfst::leaveSgeGenfst(
			DbsWdbe* dbswdbe
		) {
	invalidateWakeups();
	// IP leaveSgeGenfst --- IBEGIN
	refsTypmod.clear();
	// IP leaveSgeGenfst --- IEND
};

uint DlgWdbeVerGenfst::enterSgeGenmtp(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::GENMTP;
	nextIxVSgeSuccess = VecVSge::GENMTP;

	clearInvs();

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);

	// IP enterSgeGenmtp --- IBEGIN
	map<ubigint,string> srefsMtpCustops;

	WdbeMModule* mdl = NULL;

	unsigned int lvl;

	bool tplmod;

	// determine modules due for op invocation
	Wdbe::getSrefsMtpCustops(dbswdbe, srefsMtpCustops, VecWdbeVKeylist::KLSTKWDBEMTPGENFSTCUSTOP);

	for (unsigned int i = 0; i < mdls.nodes.size(); i++) {
		mdl = mdls.nodes[i];
		lvl = lvlsMdls[i];

		// invs complete if at least one added on superior level
		if (opN > 0) if (i != 0) if (lvl != lvlsMdls[i-1]) break;

		// check for template-based modification
		tplmod = false;

		if (refsTplmod.find(mdl->ref) == refsTplmod.end()) {
			auto it = srefsMtpCustops.find(mdl->tplRefWdbeMModule);

			if (it != srefsMtpCustops.end()) {
				addInv(new DpchInvWdbeMtpGenfst(0, it->second, 0, mdl->ref));
				tplmod = true;
			};
		};

		if (tplmod) refsTplmod.insert(mdl->ref);
	};
	// IP enterSgeGenmtp --- IEND

	submitInvs(dbswdbe, VecVSge::DONE, retval);
	return retval;
};

void DlgWdbeVerGenfst::leaveSgeGenmtp(
			DbsWdbe* dbswdbe
		) {
	invalidateWakeups();
	// IP leaveSgeGenmtp --- IBEGIN
	mdls.clear();
	lvlsMdls.clear();

	refsTplmod.clear();
	// IP leaveSgeGenmtp --- IEND
};

uint DlgWdbeVerGenfst::enterSgeDone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- IBEGIN
	ubigint refWdbeMVersion = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref);

	Wdbe::updateVerste(dbswdbe, refWdbeMVersion, VecWdbeVMVersionState::DSNGENFST);
	// IP enterSgeDone --- IEND

	return retval;
};

void DlgWdbeVerGenfst::leaveSgeDone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeDone --- INSERT
};
