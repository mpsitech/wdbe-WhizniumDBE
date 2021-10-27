/**
	* \file PnlWdbeModRec.cpp
	* job handler for job PnlWdbeModRec (implementation)
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

#include "PnlWdbeModRec.h"

#include "PnlWdbeModRec_blks.cpp"
#include "PnlWdbeModRec_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWdbeModRec
 ******************************************************************************/

PnlWdbeModRec::PnlWdbeModRec(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::PNLWDBEMODREC, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	pnldetail = NULL;
	pnlkhdltype = NULL;
	pnlapar = NULL;
	pnlhsm1npipeline = NULL;
	pnl1nprocess = NULL;
	pnlmdl1nport = NULL;
	pnlmdl1ngeneric = NULL;
	pnlsup1nmodule = NULL;
	pnlref1nsignal = NULL;
	pnlref1nsensitivity = NULL;
	pnlref1nvariable = NULL;
	pnlmge1nsignal = NULL;
	pnlctrref1nerror = NULL;
	pnlctrhk1nvector = NULL;
	pnlctrref1ncommand = NULL;
	pnlmnperipheral = NULL;
	pnlctdmnmodule = NULL;
	pnlcormnmodule = NULL;
	pnlctrmncommand = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWdbeVCall::CALLWDBECTR_CLREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBECTR_FWD_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBECTR_FWDEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBECTR_MDL_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEMDL_CTREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEMDL_HKTEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEMDL_HKU_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEMDL_HKUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEMDL_IMBEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEMDL_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEMDL_SUP_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEMDL_SUPEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEMDL_TPLEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEMDL_TYPEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswdbe, VecWdbeVPreset::PREWDBEREFMOD, jref);
};

PnlWdbeModRec::~PnlWdbeModRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* PnlWdbeModRec::getNewDpchEng(
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

void PnlWdbeModRec::refresh(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubWdbe::getStubModStd(dbswdbe, recMdl.ref, ixWdbeVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recMdl.ref == 0) statshr.ixWdbeVExpstate = VecWdbeVExpstate::MIND;

	statshr.pnlctrref1nerrorAvail = evalPnlctrref1nerrorAvail(dbswdbe);
	statshr.pnlctrhk1nvectorAvail = evalPnlctrhk1nvectorAvail(dbswdbe);
	statshr.pnlctrref1ncommandAvail = evalPnlctrref1ncommandAvail(dbswdbe);
	statshr.pnlctrmncommandAvail = evalPnlctrmncommandAvail(dbswdbe);
	statshr.ButRegularizeActive = evalButRegularizeActive(dbswdbe);

	if (statshr.ixWdbeVExpstate == VecWdbeVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlkhdltype) {delete pnlkhdltype; pnlkhdltype = NULL;};
		if (pnlapar) {delete pnlapar; pnlapar = NULL;};
		if (pnlhsm1npipeline) {delete pnlhsm1npipeline; pnlhsm1npipeline = NULL;};
		if (pnl1nprocess) {delete pnl1nprocess; pnl1nprocess = NULL;};
		if (pnlmdl1nport) {delete pnlmdl1nport; pnlmdl1nport = NULL;};
		if (pnlmdl1ngeneric) {delete pnlmdl1ngeneric; pnlmdl1ngeneric = NULL;};
		if (pnlsup1nmodule) {delete pnlsup1nmodule; pnlsup1nmodule = NULL;};
		if (pnlref1nsignal) {delete pnlref1nsignal; pnlref1nsignal = NULL;};
		if (pnlref1nsensitivity) {delete pnlref1nsensitivity; pnlref1nsensitivity = NULL;};
		if (pnlref1nvariable) {delete pnlref1nvariable; pnlref1nvariable = NULL;};
		if (pnlmge1nsignal) {delete pnlmge1nsignal; pnlmge1nsignal = NULL;};
		if (pnlctrref1nerror) {delete pnlctrref1nerror; pnlctrref1nerror = NULL;};
		if (pnlctrhk1nvector) {delete pnlctrhk1nvector; pnlctrhk1nvector = NULL;};
		if (pnlctrref1ncommand) {delete pnlctrref1ncommand; pnlctrref1ncommand = NULL;};
		if (pnlmnperipheral) {delete pnlmnperipheral; pnlmnperipheral = NULL;};
		if (pnlctdmnmodule) {delete pnlctdmnmodule; pnlctdmnmodule = NULL;};
		if (pnlcormnmodule) {delete pnlcormnmodule; pnlcormnmodule = NULL;};
		if (pnlctrmncommand) {delete pnlctrmncommand; pnlctrmncommand = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlWdbeModDetail(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlkhdltype) pnlkhdltype = new PnlWdbeModKHdltype(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlapar) pnlapar = new PnlWdbeModAPar(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlhsm1npipeline) pnlhsm1npipeline = new PnlWdbeModHsm1NPipeline(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnl1nprocess) pnl1nprocess = new PnlWdbeMod1NProcess(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlmdl1nport) pnlmdl1nport = new PnlWdbeModMdl1NPort(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlmdl1ngeneric) pnlmdl1ngeneric = new PnlWdbeModMdl1NGeneric(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlsup1nmodule) pnlsup1nmodule = new PnlWdbeModSup1NModule(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlref1nsignal) pnlref1nsignal = new PnlWdbeModRef1NSignal(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlref1nsensitivity) pnlref1nsensitivity = new PnlWdbeModRef1NSensitivity(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlref1nvariable) pnlref1nvariable = new PnlWdbeModRef1NVariable(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlmge1nsignal) pnlmge1nsignal = new PnlWdbeModMge1NSignal(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlctrref1nerror) pnlctrref1nerror = new PnlWdbeModCtrRef1NError(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlctrhk1nvector) pnlctrhk1nvector = new PnlWdbeModCtrHk1NVector(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlctrref1ncommand) pnlctrref1ncommand = new PnlWdbeModCtrRef1NCommand(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlmnperipheral) pnlmnperipheral = new PnlWdbeModMNPeripheral(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlctdmnmodule) pnlctdmnmodule = new PnlWdbeModCtdMNModule(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlcormnmodule) pnlcormnmodule = new PnlWdbeModCorMNModule(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlctrmncommand) pnlctrmncommand = new PnlWdbeModCtrMNCommand(xchg, dbswdbe, jref, ixWdbeVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefKHdltype = ((pnlkhdltype) ? pnlkhdltype->jref : 0);
	statshr.jrefAPar = ((pnlapar) ? pnlapar->jref : 0);
	statshr.jrefHsm1NPipeline = ((pnlhsm1npipeline) ? pnlhsm1npipeline->jref : 0);
	statshr.jref1NProcess = ((pnl1nprocess) ? pnl1nprocess->jref : 0);
	statshr.jrefMdl1NPort = ((pnlmdl1nport) ? pnlmdl1nport->jref : 0);
	statshr.jrefMdl1NGeneric = ((pnlmdl1ngeneric) ? pnlmdl1ngeneric->jref : 0);
	statshr.jrefSup1NModule = ((pnlsup1nmodule) ? pnlsup1nmodule->jref : 0);
	statshr.jrefRef1NSignal = ((pnlref1nsignal) ? pnlref1nsignal->jref : 0);
	statshr.jrefRef1NSensitivity = ((pnlref1nsensitivity) ? pnlref1nsensitivity->jref : 0);
	statshr.jrefRef1NVariable = ((pnlref1nvariable) ? pnlref1nvariable->jref : 0);
	statshr.jrefMge1NSignal = ((pnlmge1nsignal) ? pnlmge1nsignal->jref : 0);
	statshr.jrefCtrRef1NError = ((pnlctrref1nerror) ? pnlctrref1nerror->jref : 0);
	statshr.jrefCtrHk1NVector = ((pnlctrhk1nvector) ? pnlctrhk1nvector->jref : 0);
	statshr.jrefCtrRef1NCommand = ((pnlctrref1ncommand) ? pnlctrref1ncommand->jref : 0);
	statshr.jrefMNPeripheral = ((pnlmnperipheral) ? pnlmnperipheral->jref : 0);
	statshr.jrefCtdMNModule = ((pnlctdmnmodule) ? pnlctdmnmodule->jref : 0);
	statshr.jrefCorMNModule = ((pnlcormnmodule) ? pnlcormnmodule->jref : 0);
	statshr.jrefCtrMNCommand = ((pnlctrmncommand) ? pnlctrmncommand->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWdbeModRec::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFMOD) {
		WdbeMModule* _recMdl = NULL;
		WdbeMController* _recCtr = NULL;
		WdbeMImbuf* _recImb = NULL;

		if (dbswdbe->tblwdbemmodule->loadRecByRef(xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFMOD, jref), &_recMdl)) {
			recMdl = *_recMdl;
			ixWSubsetMdl = dbswdbe->getIxWSubsetByWdbeMModule(_recMdl);
			delete _recMdl;
		} else {
			recMdl = WdbeMModule();
			ixWSubsetMdl = 0;
		};

		if (dbswdbe->tblwdbemcontroller->loadRecByRef(recMdl.refWdbeMController, &_recCtr)) {
			recCtr = *_recCtr;
			delete _recCtr;
		} else recCtr = WdbeMController();

		if (dbswdbe->tblwdbemimbuf->loadRecByRef(recMdl.refWdbeMImbuf, &_recImb)) {
			recImb = *_recImb;
			delete _recImb;
		} else recImb = WdbeMImbuf();

		if (recMdl.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlkhdltype) pnlkhdltype->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlapar) pnlapar->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlhsm1npipeline) pnlhsm1npipeline->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnl1nprocess) pnl1nprocess->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlmdl1nport) pnlmdl1nport->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlmdl1ngeneric) pnlmdl1ngeneric->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlsup1nmodule) pnlsup1nmodule->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlref1nsignal) pnlref1nsignal->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlref1nsensitivity) pnlref1nsensitivity->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlref1nvariable) pnlref1nvariable->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlmge1nsignal) pnlmge1nsignal->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlctrref1nerror) pnlctrref1nerror->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlctrhk1nvector) pnlctrhk1nvector->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlctrref1ncommand) pnlctrref1ncommand->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlmnperipheral) pnlmnperipheral->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlctdmnmodule) pnlctdmnmodule->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlcormnmodule) pnlcormnmodule->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlctrmncommand) pnlctrmncommand->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
		};

		refresh(dbswdbe, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWdbeModRec::minimize(
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

void PnlWdbeModRec::regularize(
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

void PnlWdbeModRec::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMODRECDO) {
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

void PnlWdbeModRec::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWdbeModRec::handleDpchAppDoButMinimizeClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	minimize(dbswdbe, true, dpcheng);
};

void PnlWdbeModRec::handleDpchAppDoButRegularizeClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	regularize(dbswdbe, true, dpcheng);
};

void PnlWdbeModRec::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBECTR_CLREQ) {
		call->abort = handleCallWdbeCtr_clrEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBECTR_FWD_INSBS) {
		call->abort = handleCallWdbeCtr_fwd_inSbs(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBECTR_FWDEQ) {
		call->abort = handleCallWdbeCtr_fwdEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBECTR_MDL_INSBS) {
		call->abort = handleCallWdbeCtr_mdl_inSbs(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDL_CTREQ) {
		call->abort = handleCallWdbeMdl_ctrEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDL_HKTEQ) {
		call->abort = handleCallWdbeMdl_hktEq(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDL_HKU_INSBS) {
		call->abort = handleCallWdbeMdl_hku_inSbs(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDL_HKUEQ) {
		call->abort = handleCallWdbeMdl_hkuEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDL_IMBEQ) {
		call->abort = handleCallWdbeMdl_imbEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDL_INSBS) {
		call->abort = handleCallWdbeMdl_inSbs(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDL_SUP_INSBS) {
		call->abort = handleCallWdbeMdl_sup_inSbs(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDL_SUPEQ) {
		call->abort = handleCallWdbeMdl_supEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDL_TPLEQ) {
		call->abort = handleCallWdbeMdl_tplEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDL_TYPEQ) {
		call->abort = handleCallWdbeMdl_typEq(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBECTRUPD_REFEQ) {
		call->abort = handleCallWdbeCtrUpd_refEq(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEIMBUPD_REFEQ) {
		call->abort = handleCallWdbeImbUpd_refEq(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDLUPD_REFEQ) {
		call->abort = handleCallWdbeMdlUpd_refEq(dbswdbe, call->jref);
	};
};

bool PnlWdbeModRec::handleCallWdbeCtr_clrEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recCtr.clrRefWdbeMSignal == refInv); // IP handleCallWdbeCtr_clrEq --- LINE
	return retval;
};

bool PnlWdbeModRec::handleCallWdbeCtr_fwd_inSbs(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((dbswdbe->getIxWSubsetByRefWdbeMUnit(recCtr.fwdRefWdbeMUnit) & ixInv) != 0); // IP handleCallWdbeCtr_fwd_inSbs --- LINE
	return retval;
};

bool PnlWdbeModRec::handleCallWdbeCtr_fwdEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recCtr.fwdRefWdbeMUnit == refInv); // IP handleCallWdbeCtr_fwdEq --- LINE
	return retval;
};

bool PnlWdbeModRec::handleCallWdbeCtr_mdl_inSbs(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((dbswdbe->getIxWSubsetByRefWdbeMModule(recCtr.refWdbeMModule) & ixInv) != 0); // IP handleCallWdbeCtr_mdl_inSbs --- LINE
	return retval;
};

bool PnlWdbeModRec::handleCallWdbeMdl_ctrEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recMdl.refWdbeMController == refInv); // IP handleCallWdbeMdl_ctrEq --- LINE
	return retval;
};

bool PnlWdbeModRec::handleCallWdbeMdl_hktEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recMdl.hkIxVTbl == ixInv); // IP handleCallWdbeMdl_hktEq --- LINE
	return retval;
};

bool PnlWdbeModRec::handleCallWdbeMdl_hku_inSbs(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((dbswdbe->getIxWSubsetByRefWdbeMUnit(recMdl.hkUref) & ixInv) != 0); // IP handleCallWdbeMdl_hku_inSbs --- LINE
	return retval;
};

bool PnlWdbeModRec::handleCallWdbeMdl_hkuEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recMdl.hkUref == refInv); // IP handleCallWdbeMdl_hkuEq --- LINE
	return retval;
};

bool PnlWdbeModRec::handleCallWdbeMdl_imbEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recMdl.refWdbeMImbuf == refInv); // IP handleCallWdbeMdl_imbEq --- LINE
	return retval;
};

bool PnlWdbeModRec::handleCallWdbeMdl_inSbs(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((ixWSubsetMdl & ixInv) != 0); // IP handleCallWdbeMdl_inSbs --- LINE
	return retval;
};

bool PnlWdbeModRec::handleCallWdbeMdl_sup_inSbs(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((dbswdbe->getIxWSubsetByRefWdbeMModule(recMdl.supRefWdbeMModule) & ixInv) != 0); // IP handleCallWdbeMdl_sup_inSbs --- LINE
	return retval;
};

bool PnlWdbeModRec::handleCallWdbeMdl_supEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recMdl.supRefWdbeMModule == refInv); // IP handleCallWdbeMdl_supEq --- LINE
	return retval;
};

bool PnlWdbeModRec::handleCallWdbeMdl_tplEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recMdl.tplRefWdbeMModule == refInv); // IP handleCallWdbeMdl_tplEq --- LINE
	return retval;
};

bool PnlWdbeModRec::handleCallWdbeMdl_typEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recMdl.ixVBasetype == ixInv); // IP handleCallWdbeMdl_typEq --- LINE
	return retval;
};

bool PnlWdbeModRec::handleCallWdbeCtrUpd_refEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWdbeCtrUpd_refEq --- INSERT
	return retval;
};

bool PnlWdbeModRec::handleCallWdbeImbUpd_refEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWdbeImbUpd_refEq --- INSERT
	return retval;
};

bool PnlWdbeModRec::handleCallWdbeMdlUpd_refEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWdbeMdlUpd_refEq --- INSERT
	return retval;
};
