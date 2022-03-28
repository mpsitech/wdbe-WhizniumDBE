/**
	* \file PnlWdbeMtpRec.cpp
	* job handler for job PnlWdbeMtpRec (implementation)
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

#include "PnlWdbeMtpRec.h"

#include "PnlWdbeMtpRec_blks.cpp"
#include "PnlWdbeMtpRec_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWdbeMtpRec
 ******************************************************************************/

PnlWdbeMtpRec::PnlWdbeMtpRec(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::PNLWDBEMTPREC, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	pnlref1nfile = NULL;
	pnlmge1nsignal = NULL;
	pnlref1nsensitivity = NULL;
	pnlref1nvariable = NULL;
	pnlmdl1nport = NULL;
	pnlsup1nmodule = NULL;
	pnlhsm1npipeline = NULL;
	pnltpl1nmodule = NULL;
	pnlmdl1ngeneric = NULL;
	pnlapar = NULL;
	pnlkhdltype = NULL;
	pnlkparkey = NULL;
	pnldetail = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWdbeVCall::CALLWDBEMDL_TYPEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEMDL_TPLEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEMDL_SUPEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEMDL_SUP_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEMDL_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEMDL_IMBEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEMDL_HKUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEMDL_HKU_INSBS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEMDL_CTREQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEMDL_HKTEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswdbe, VecWdbeVPreset::PREWDBEREFMTP, jref);
};

PnlWdbeMtpRec::~PnlWdbeMtpRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* PnlWdbeMtpRec::getNewDpchEng(
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

void PnlWdbeMtpRec::refresh(
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
	continf.TxtRef = StubWdbe::getStubMtpStd(dbswdbe, recMdl.ref, ixWdbeVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recMdl.ref == 0) statshr.ixWdbeVExpstate = VecWdbeVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbswdbe);

	if (statshr.ixWdbeVExpstate == VecWdbeVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlkparkey) {delete pnlkparkey; pnlkparkey = NULL;};
		if (pnlkhdltype) {delete pnlkhdltype; pnlkhdltype = NULL;};
		if (pnlapar) {delete pnlapar; pnlapar = NULL;};
		if (pnlmdl1ngeneric) {delete pnlmdl1ngeneric; pnlmdl1ngeneric = NULL;};
		if (pnltpl1nmodule) {delete pnltpl1nmodule; pnltpl1nmodule = NULL;};
		if (pnlhsm1npipeline) {delete pnlhsm1npipeline; pnlhsm1npipeline = NULL;};
		if (pnlmdl1nport) {delete pnlmdl1nport; pnlmdl1nport = NULL;};
		if (pnlsup1nmodule) {delete pnlsup1nmodule; pnlsup1nmodule = NULL;};
		if (pnlref1nsensitivity) {delete pnlref1nsensitivity; pnlref1nsensitivity = NULL;};
		if (pnlref1nvariable) {delete pnlref1nvariable; pnlref1nvariable = NULL;};
		if (pnlmge1nsignal) {delete pnlmge1nsignal; pnlmge1nsignal = NULL;};
		if (pnlref1nfile) {delete pnlref1nfile; pnlref1nfile = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlWdbeMtpDetail(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlkparkey) pnlkparkey = new PnlWdbeMtpKParKey(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlkhdltype) pnlkhdltype = new PnlWdbeMtpKHdltype(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlapar) pnlapar = new PnlWdbeMtpAPar(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlmdl1ngeneric) pnlmdl1ngeneric = new PnlWdbeMtpMdl1NGeneric(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnltpl1nmodule) pnltpl1nmodule = new PnlWdbeMtpTpl1NModule(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlhsm1npipeline) pnlhsm1npipeline = new PnlWdbeMtpHsm1NPipeline(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlmdl1nport) pnlmdl1nport = new PnlWdbeMtpMdl1NPort(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlsup1nmodule) pnlsup1nmodule = new PnlWdbeMtpSup1NModule(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlref1nsensitivity) pnlref1nsensitivity = new PnlWdbeMtpRef1NSensitivity(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlref1nvariable) pnlref1nvariable = new PnlWdbeMtpRef1NVariable(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlmge1nsignal) pnlmge1nsignal = new PnlWdbeMtpMge1NSignal(xchg, dbswdbe, jref, ixWdbeVLocale);
		if (!pnlref1nfile) pnlref1nfile = new PnlWdbeMtpRef1NFile(xchg, dbswdbe, jref, ixWdbeVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefKParKey = ((pnlkparkey) ? pnlkparkey->jref : 0);
	statshr.jrefKHdltype = ((pnlkhdltype) ? pnlkhdltype->jref : 0);
	statshr.jrefAPar = ((pnlapar) ? pnlapar->jref : 0);
	statshr.jrefMdl1NGeneric = ((pnlmdl1ngeneric) ? pnlmdl1ngeneric->jref : 0);
	statshr.jrefTpl1NModule = ((pnltpl1nmodule) ? pnltpl1nmodule->jref : 0);
	statshr.jrefHsm1NPipeline = ((pnlhsm1npipeline) ? pnlhsm1npipeline->jref : 0);
	statshr.jrefMdl1NPort = ((pnlmdl1nport) ? pnlmdl1nport->jref : 0);
	statshr.jrefSup1NModule = ((pnlsup1nmodule) ? pnlsup1nmodule->jref : 0);
	statshr.jrefRef1NSensitivity = ((pnlref1nsensitivity) ? pnlref1nsensitivity->jref : 0);
	statshr.jrefRef1NVariable = ((pnlref1nvariable) ? pnlref1nvariable->jref : 0);
	statshr.jrefMge1NSignal = ((pnlmge1nsignal) ? pnlmge1nsignal->jref : 0);
	statshr.jrefRef1NFile = ((pnlref1nfile) ? pnlref1nfile->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWdbeMtpRec::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFMTP) {
		WdbeMModule* _recMdl = NULL;

		if (dbswdbe->tblwdbemmodule->loadRecByRef(xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFMTP, jref), &_recMdl)) {
			recMdl = *_recMdl;
			ixWSubsetMdl = dbswdbe->getIxWSubsetByWdbeMModule(_recMdl);
			delete _recMdl;
		} else {
			recMdl = WdbeMModule();
			ixWSubsetMdl = 0;
		};

		if (recMdl.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlkparkey) pnlkparkey->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlkhdltype) pnlkhdltype->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlapar) pnlapar->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlmdl1ngeneric) pnlmdl1ngeneric->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnltpl1nmodule) pnltpl1nmodule->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlhsm1npipeline) pnlhsm1npipeline->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlmdl1nport) pnlmdl1nport->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlsup1nmodule) pnlsup1nmodule->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlref1nsensitivity) pnlref1nsensitivity->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlref1nvariable) pnlref1nvariable->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlmge1nsignal) pnlmge1nsignal->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
			if (pnlref1nfile) pnlref1nfile->updatePreset(dbswdbe, ixWdbeVPreset, jrefTrig, notif);
		};

		refresh(dbswdbe, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWdbeMtpRec::minimize(
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

void PnlWdbeMtpRec::regularize(
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

void PnlWdbeMtpRec::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEMTPRECDO) {
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

void PnlWdbeMtpRec::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWdbeMtpRec::handleDpchAppDoButMinimizeClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	minimize(dbswdbe, true, dpcheng);
};

void PnlWdbeMtpRec::handleDpchAppDoButRegularizeClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	regularize(dbswdbe, true, dpcheng);
};

void PnlWdbeMtpRec::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBEMDLUPD_REFEQ) {
		call->abort = handleCallWdbeMdlUpd_refEq(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDL_TYPEQ) {
		call->abort = handleCallWdbeMdl_typEq(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDL_TPLEQ) {
		call->abort = handleCallWdbeMdl_tplEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDL_SUPEQ) {
		call->abort = handleCallWdbeMdl_supEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDL_SUP_INSBS) {
		call->abort = handleCallWdbeMdl_sup_inSbs(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDL_INSBS) {
		call->abort = handleCallWdbeMdl_inSbs(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDL_IMBEQ) {
		call->abort = handleCallWdbeMdl_imbEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDL_HKUEQ) {
		call->abort = handleCallWdbeMdl_hkuEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDL_HKU_INSBS) {
		call->abort = handleCallWdbeMdl_hku_inSbs(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDL_CTREQ) {
		call->abort = handleCallWdbeMdl_ctrEq(dbswdbe, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEMDL_HKTEQ) {
		call->abort = handleCallWdbeMdl_hktEq(dbswdbe, call->jref, call->argInv.ix, call->argRet.boolval);
	};
};

bool PnlWdbeMtpRec::handleCallWdbeMdlUpd_refEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWdbeMdlUpd_refEq --- INSERT
	return retval;
};

bool PnlWdbeMtpRec::handleCallWdbeMdl_typEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recMdl.ixVBasetype == ixInv); // IP handleCallWdbeMdl_typEq --- LINE
	return retval;
};

bool PnlWdbeMtpRec::handleCallWdbeMdl_tplEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recMdl.tplRefWdbeMModule == refInv); // IP handleCallWdbeMdl_tplEq --- LINE
	return retval;
};

bool PnlWdbeMtpRec::handleCallWdbeMdl_supEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recMdl.supRefWdbeMModule == refInv); // IP handleCallWdbeMdl_supEq --- LINE
	return retval;
};

bool PnlWdbeMtpRec::handleCallWdbeMdl_sup_inSbs(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((dbswdbe->getIxWSubsetByRefWdbeMModule(recMdl.supRefWdbeMModule) & ixInv) != 0); // IP handleCallWdbeMdl_sup_inSbs --- LINE
	return retval;
};

bool PnlWdbeMtpRec::handleCallWdbeMdl_inSbs(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((ixWSubsetMdl & ixInv) != 0); // IP handleCallWdbeMdl_inSbs --- LINE
	return retval;
};

bool PnlWdbeMtpRec::handleCallWdbeMdl_imbEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recMdl.refWdbeMImbuf == refInv); // IP handleCallWdbeMdl_imbEq --- LINE
	return retval;
};

bool PnlWdbeMtpRec::handleCallWdbeMdl_hkuEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recMdl.hkUref == refInv); // IP handleCallWdbeMdl_hkuEq --- LINE
	return retval;
};

bool PnlWdbeMtpRec::handleCallWdbeMdl_hku_inSbs(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = ((dbswdbe->getIxWSubsetByRefWdbeMUnit(recMdl.hkUref) & ixInv) != 0); // IP handleCallWdbeMdl_hku_inSbs --- LINE
	return retval;
};

bool PnlWdbeMtpRec::handleCallWdbeMdl_ctrEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recMdl.refWdbeMController == refInv); // IP handleCallWdbeMdl_ctrEq --- LINE
	return retval;
};

bool PnlWdbeMtpRec::handleCallWdbeMdl_hktEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recMdl.hkIxVTbl == ixInv); // IP handleCallWdbeMdl_hktEq --- LINE
	return retval;
};
