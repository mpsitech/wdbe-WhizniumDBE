/**
	* \file PnlWdbeSilRec.cpp
	* job handler for job PnlWdbeSilRec (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbed.h>
#endif

#include "PnlWdbeSilRec.h"

#include "PnlWdbeSilRec_blks.cpp"
#include "PnlWdbeSilRec_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWdbeSilRec
 ******************************************************************************/

PnlWdbeSilRec::PnlWdbeSilRec(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::PNLWDBESILREC, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	pnldetail = NULL;
	pnl1nbank = NULL;
	pnlfwd1ncontroller = NULL;
	pnl1ntarget = NULL;
	pnlsil1nunit = NULL;
	pnl1nperipheral = NULL;
	pnlref1ncommand = NULL;
	pnlhk1nmodule = NULL;
	pnlhk1nvector = NULL;
	pnlref1nerror = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWdbeVCall::CALLWDBEUNT_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEUNT_MDLEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEUNT_RETEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEUNT_REUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEUNT_SILEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEUNT_SYSEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswdbe, VecWdbeVPreset::PREWDBEREFSIL, jref);
};

PnlWdbeSilRec::~PnlWdbeSilRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* PnlWdbeSilRec::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &continf, &statshr, items);
	};

	return dpcheng;
};

void PnlWdbeSilRec::refresh(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubWdbe::getStubSilStd(dbswdbe, recUnt.ref, ixWdbeVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recUnt.ref == 0) statshr.ixWdbeVExpstate = VecWdbeVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbswdbe);

	if (statshr.ixWdbeVExpstate == VecWdbeVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnl1nbank) {delete pnl1nbank; pnl1nbank = NULL;};
		if (pnlfwd1ncontroller) {delete pnlfwd1ncontroller; pnlfwd1ncontroller = NULL;};
		if (pnl1ntarget) {delete pnl1ntarget; pnl1ntarget = NULL;};
		if (pnlsil1nunit) {delete pnlsil1nunit; pnlsil1nunit = NULL;};
		if (pnl1nperipheral) {delete pnl1nperipheral; pnl1nperipheral = NULL;};
		if (pnlref1ncommand) {delete pnlref1ncommand; pnlref1ncommand = NULL;};
		if (pnlhk1nmodule) {delete pnlhk1nmodule; pnlhk1nmodule = NULL;};
		if (pnlhk1nvector) {delete pnlhk1nvector; pnlhk1nvector = NULL;};
		if (pnlref1nerror) {delete pnlref1nerror; pnlref1nerror = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlWdbeSilDetail(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnl1nbank) pnl1nbank = new PnlWdbeSil1NBank(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlfwd1ncontroller) pnlfwd1ncontroller = new PnlWdbeSilFwd1NController(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnl1ntarget) pnl1ntarget = new PnlWdbeSil1NTarget(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlsil1nunit) pnlsil1nunit = new PnlWdbeSilSil1NUnit(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnl1nperipheral) pnl1nperipheral = new PnlWdbeSil1NPeripheral(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlref1ncommand) pnlref1ncommand = new PnlWdbeSilRef1NCommand(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlhk1nmodule) pnlhk1nmodule = new PnlWdbeSilHk1NModule(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlhk1nvector) pnlhk1nvector = new PnlWdbeSilHk1NVector(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlref1nerror) pnlref1nerror = new PnlWdbeSilRef1NError(xchg, dbswdbe, jref, ixWdbeVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jref1NBank = ((pnl1nbank) ? pnl1nbank->jref : 0);
	statshr.jrefFwd1NController = ((pnlfwd1ncontroller) ? pnlfwd1ncontroller->jref : 0);
	statshr.jref1NTarget = ((pnl1ntarget) ? pnl1ntarget->jref : 0);
	statshr.jrefSil1NUnit = ((pnlsil1nunit) ? pnlsil1nunit->jref : 0);
	statshr.jref1NPeripheral = ((pnl1nperipheral) ? pnl1nperipheral->jref : 0);
	statshr.jrefRef1NCommand = ((pnlref1ncommand) ? pnlref1ncommand->jref : 0);
	statshr.jrefHk1NModule = ((pnlhk1nmodule) ? pnlhk1nmodule->jref : 0);
	statshr.jrefHk1NVector = ((pnlhk1nvector) ? pnlhk1nvector->jref : 0);
	statshr.jrefRef1NError = ((pnlref1nerror) ? pnlref1nerror->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWdbeSilRec::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFSIL) {
		WdbeMUnit* _recUnt = NULL;

		if (dbswdbe->tblwdbemunit->loadRecByRef(xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFSIL, jref), &_recUnt)) {
			recUnt = *_recUnt;
			ixWSubsetUnt = dbswdbe->getIxWSubsetByWdbeMUnit(_recUnt);
			delete _recUnt;
		} else {
			recUnt = WdbeMUnit();
			ixWSubsetUnt = 0;
		};

		if (recUnt.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnl1nbank) pnl1nbank->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlfwd1ncontroller) pnlfwd1ncontroller->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnl1ntarget) pnl1ntarget->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlsil1nunit) pnlsil1nunit->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnl1nperipheral) pnl1nperipheral->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlref1ncommand) pnlref1ncommand->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlhk1nmodule) pnlhk1nmodule->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlhk1nvector) pnlhk1nvector->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlref1nerror) pnlref1nerror->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
		};

		refresh(dbswdbe, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWdbeSilRec::minimize(
			DbsWdbe* dbswdbe
			, const bool notif
			, DpchEngWdbe** dpcheng
		) {
	set<uint> moditems;

	if (statshr.ixWdbeVExpstate != VecWdbeVExpstate::MIND) {
		statshr.ixWdbeVExpstate = VecWdbeVExpstate::MIND;
		insert(moditems, DpchEngData::STATSHR);

		refresh(dbswdbe, moditems);
	};

	if (notif) {
		if (dpcheng) *dpcheng = getNewDpchEng(moditems);
		else if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
};

void PnlWdbeSilRec::regularize(
			DbsWdbe* dbswdbe
			, const bool notif
			, DpchEngWdbe** dpcheng
		) {
	set<uint> moditems;

	if (statshr.ixWdbeVExpstate != VecWdbeVExpstate::REGD) {
		statshr.ixWdbeVExpstate = VecWdbeVExpstate::REGD;
		insert(moditems, DpchEngData::STATSHR);

		refresh(dbswdbe, moditems);
	};

	if (notif) {
		if (dpcheng) *dpcheng = getNewDpchEng(moditems);
		else if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
};

void PnlWdbeSilRec::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBESILRECDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTMINIMIZECLICK) {
					handleDpchAppDoButMinimizeClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREGULARIZECLICK) {
					handleDpchAppDoButRegularizeClick(dbswdbe, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWdbeSilRec::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWdbeSilRec::handleDpchAppDoButMinimizeClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	minimize(dbswdbe, true, dpcheng);
};

void PnlWdbeSilRec::handleDpchAppDoButRegularizeClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	regularize(dbswdbe, true, dpcheng);
};

void PnlWdbeSilRec::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBEUNT_INSBS) {
		call->abort = handleCallWdbeUnt_inSbs(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEUNT_MDLEQ) {
		call->abort = handleCallWdbeUnt_mdlEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEUNT_RETEQ) {
		call->abort = handleCallWdbeUnt_retEq(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEUNT_REUEQ) {
		call->abort = handleCallWdbeUnt_reuEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEUNT_SILEQ) {
		call->abort = handleCallWdbeUnt_silEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEUNT_SYSEQ) {
		call->abort = handleCallWdbeUnt_sysEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEUNTUPD_REFEQ) {
		call->abort = handleCallWdbeUntUpd_refEq(dbswdbe, call->jref);
	};
};

bool PnlWdbeSilRec::handleCallWdbeUnt_inSbs(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((ixWSubsetUnt & ixInv) != 0); // IP handleCallWdbeUnt_inSbs --- LINE
	return retval;
};

bool PnlWdbeSilRec::handleCallWdbeUnt_mdlEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recUnt.refWdbeMModule == refInv); // IP handleCallWdbeUnt_mdlEq --- LINE
	return retval;
};

bool PnlWdbeSilRec::handleCallWdbeUnt_retEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recUnt.refIxVTbl == ixInv); // IP handleCallWdbeUnt_retEq --- LINE
	return retval;
};

bool PnlWdbeSilRec::handleCallWdbeUnt_reuEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recUnt.refUref == refInv); // IP handleCallWdbeUnt_reuEq --- LINE
	return retval;
};

bool PnlWdbeSilRec::handleCallWdbeUnt_silEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recUnt.silRefWdbeMUnit == refInv); // IP handleCallWdbeUnt_silEq --- LINE
	return retval;
};

bool PnlWdbeSilRec::handleCallWdbeUnt_sysEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recUnt.refWdbeMSystem == refInv); // IP handleCallWdbeUnt_sysEq --- LINE
	return retval;
};

bool PnlWdbeSilRec::handleCallWdbeUntUpd_refEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWdbeUntUpd_refEq --- INSERT
	return retval;
};

