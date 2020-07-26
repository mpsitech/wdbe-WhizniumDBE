/**
	* \file CrdWdbeUnt.cpp
	* job handler for job CrdWdbeUnt (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbed.h>
#endif

#include "CrdWdbeUnt.h"

#include "CrdWdbeUnt_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class CrdWdbeUnt
 ******************************************************************************/

CrdWdbeUnt::CrdWdbeUnt(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
			, const ubigint ref
			, const uint ixWdbeVPreset
			, const ubigint preUref
		) :
			JobWdbe(xchg, VecWdbeVJob::CRDWDBEUNT, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	pnllist = NULL;
	pnlheadbar = NULL;
	pnlrec = NULL;

	// IP constructor.cust1 --- INSERT

	xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXPRE, jref, ixWdbeVPreset);
	if (ixWdbeVPreset != VecWdbeVPreset::VOID) xchg->addRefPreset(ixWdbeVPreset, jref, preUref);

	// initialize according to ref
	changeRef(dbswdbe, jref, ((ref+1) == 0) ? 0 : ref, false);

	pnllist = new PnlWdbeUntList(xchg, dbswdbe, jref, ixWdbeVLocale);
	pnlheadbar = new PnlWdbeUntHeadbar(xchg, dbswdbe, jref, ixWdbeVLocale);
	pnlrec = new PnlWdbeUntRec(xchg, dbswdbe, jref, ixWdbeVLocale);

	// IP constructor.cust2 --- INSERT

	statshr.jrefHeadbar = pnlheadbar->jref;
	statshr.jrefList = pnllist->jref;
	statshr.jrefRec = pnlrec->jref;

	set<uint> moditems;
	refresh(dbswdbe, moditems);

	changeStage(dbswdbe, VecVSge::IDLE);

	xchg->addClstn(VecWdbeVCall::CALLWDBEREFPRESET, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBESTATCHG, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEDLGCLOSE, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

CrdWdbeUnt::~CrdWdbeUnt() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
void CrdWdbeUnt::showSubmdls(
			DbsWdbe* dbswdbe
			, const ubigint refWdbeMModule
			, bool _gens
			, bool _prts
			, bool _sigs
			, unsigned int indent
		) {
	string id;

	string setgray = "\033[38;2;196;196;196m";
	string reset = "\033[0m";

	vector<ubigint> refs;

	ListWdbeMGeneric gens;
	WdbeMGeneric* gen = NULL;

	ListWdbeMPort prts;
	WdbeMPort* prt = NULL;

	ListWdbeMSignal sigs;
	WdbeMSignal* sig = NULL;

	string s;
	size_t ptr;

	dbswdbe->loadRefsBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " ORDER BY hkNum ASC", false, refs);

	// indentation
	for (unsigned int i = 0; i < indent;i++) id = id + "\t";

	// actual module
	if (refs.size() == 0) cout << "\t" << id << "- ";
	else cout << "\t" << id << "+ ";

	s = StubWdbe::getStubModStd(dbswdbe, refWdbeMModule);
	ptr = s.find(';');
	while (ptr != string::npos) {
		s = s.substr(ptr + 1);
		ptr = s.find(';');
	};

	cout << s << endl;

	if (_gens) {
		// generics
		cout << setgray;

		dbswdbe->tblwdbemgeneric->loadRstBySQL("SELECT * FROM TblWdbeMGeneric WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " ORDER BY mdlNum ASC", false, gens);

		for (unsigned int i = 0; i < gens.nodes.size(); i++) {
			gen = gens.nodes[i];
			cout << "\t\t" << id << gen->sref << endl;
		};

		cout << reset;
	};

	if (_prts) {
		// ports
		cout << setgray;

		dbswdbe->tblwdbemport->loadRstBySQL("SELECT * FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " ORDER BY mdlNum ASC", false, prts);

		for (unsigned int i = 0; i < prts.nodes.size(); i++) {
			prt = prts.nodes[i];
			cout << "\t\t" << id << prt->sref << endl;
		};

		cout << reset;
	};

	if (_sigs) {
		// signals
		cout << setgray;

		dbswdbe->tblwdbemsignal->loadRstBySQL("SELECT * FROM TblWdbeMSignal WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " ORDER BY mdlNum ASC", false, sigs);

		for (unsigned int i = 0; i < sigs.nodes.size(); i++) {
			sig = sigs.nodes[i];
			cout << "\t\t" << id << sig->sref << endl;
		};

		cout << reset;
	};

	// sub-modules
	for (unsigned int i = 0; i < refs.size(); i++) showSubmdls(dbswdbe, refs[i], _gens, _prts, _sigs, indent+1);
};

// IP cust --- IEND

DpchEngWdbe* CrdWdbeUnt::getNewDpchEng(
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

void CrdWdbeUnt::refresh(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);

	// IP refresh --- BEGIN
	// continf
	continf.MrlAppHlp = xchg->helpurl + "/CrdWdbeUnt/" + VecWdbeVLocale::getSref(ixWdbeVLocale);
	continf.MtxCrdUnt = StubWdbe::getStubUntStd(dbswdbe, xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref), ixWdbeVLocale, Stub::VecVNonetype::FULL);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
};

void CrdWdbeUnt::changeRef(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const ubigint ref
			, const bool notif
		) {
	set<uint> moditems;

	uint ixWdbeVPreset = xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXPRE, jref);

	if (ref != 0) xchg->triggerIxRefSrefIntvalCall(dbswdbe, VecWdbeVCall::CALLWDBELOG, jref, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref), "CrdWdbeUnt", ref);
	xchg->addRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref, ref);

	if (pnllist) pnllist->updatePreset(dbswdbe, VecWdbeVPreset::PREWDBEREFUNT, jrefTrig, notif);
	if (pnlrec) pnlrec->updatePreset(dbswdbe, VecWdbeVPreset::PREWDBEREFUNT, jrefTrig, notif);

	refresh(dbswdbe, moditems);
	if (notif) xchg->submitDpch(getNewDpchEng(moditems));
};

void CrdWdbeUnt::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- INSERT
};

void CrdWdbeUnt::handleRequest(
			DbsWdbe* dbswdbe
			, ReqWdbe* req
		) {
	if (req->ixVBasetype == ReqWdbe::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {
			cout << "\tshowCmds" << endl;
			cout << "\tshowGens" << endl;
			cout << "\tshowMdls" << endl;
			cout << "\tshowPrts" << endl;
			cout << "\tshowSigs" << endl;
		} else if (req->cmd == "showCmds") {
			req->retain = handleShowCmds(dbswdbe);

		} else if (req->cmd == "showGens") {
			req->retain = handleShowGens(dbswdbe);

		} else if (req->cmd == "showMdls") {
			req->retain = handleShowMdls(dbswdbe);

		} else if (req->cmd == "showPrts") {
			req->retain = handleShowPrts(dbswdbe);

		} else if (req->cmd == "showSigs") {
			req->retain = handleShowSigs(dbswdbe);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::DPCHAPP) {
		if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEINIT) {
			handleDpchAppWdbeInit(dbswdbe, (DpchAppWdbeInit*) (req->dpchapp), &(req->dpcheng));

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEUNTDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::CLOSE) {
					handleDpchAppDoClose(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITAPPABTCLICK) {
					handleDpchAppDoMitAppAbtClick(dbswdbe, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEALERT) {
			handleDpchAppWdbeAlert(dbswdbe, (DpchAppWdbeAlert*) (req->dpchapp), &(req->dpcheng));

		};
	};
};

bool CrdWdbeUnt::handleShowCmds(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleShowCmds --- IBEGIN
	ubigint ref;

	ListWdbeMCommand cmds;
	WdbeMCommand* cmd = NULL;

	ListWdbeMModule mdls;
	WdbeMModule* mdl = NULL;
	map<ubigint,string> srefsCmtsCtrs;

	ListWdbeAMCommandInvpar ipas;
	WdbeAMCommandInvpar* ipa = NULL;

	ListWdbeAMCommandRetpar rpas;
	WdbeAMCommandRetpar* rpa = NULL;

	ubigint refWdbeMUnit = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref);

	dbswdbe->tblwdbemcommand->loadRstByRetReu(VecWdbeVMCommandRefTbl::UNT, refWdbeMUnit, false, cmds);

	dbswdbe->tblwdbemmodule->loadRstBySQL("SELECT * FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND hkUref = " + to_string(refWdbeMUnit)
				+ " AND refWdbeMController <> 0 ORDER BY hkNum ASC", false, mdls);
	for (unsigned int i = 0; i < mdls.nodes.size(); i++) {
		mdl = mdls.nodes[i];

		if (mdl->Comment != "") srefsCmtsCtrs[mdl->refWdbeMController] = mdl->sref + ": " + mdl->Comment;
		else srefsCmtsCtrs[mdl->refWdbeMController] = mdl->sref;

		dbswdbe->tblwdbemcommand->loadRstByRetReu(VecWdbeVMCommandRefTbl::CTR, mdl->refWdbeMController, true, cmds);
	};

	ref = 0;

	for (unsigned int i = 0; i < cmds.nodes.size(); i++) {
		cmd = cmds.nodes[i];

		dbswdbe->tblwdbeamcommandinvpar->loadRstByCmd(cmd->ref, false, ipas);
		dbswdbe->tblwdbeamcommandretpar->loadRstByCmd(cmd->ref, false, rpas);

		if (cmd->refIxVTbl == VecWdbeVMCommandRefTbl::CTR) {
			if (cmd->refUref != ref) {
				cout << srefsCmtsCtrs[cmd->refUref] << endl;
				ref = cmd->refUref;
			};
			cout << "\t";
		}; 

		cout << "(";
		for (unsigned int j = 0; j < rpas.nodes.size(); j++) {
			rpa = rpas.nodes[j];

			if (j != 0) cout << ", ";
			cout << VecWdbeVPartype::getSref(rpa->ixWdbeVPartype) << " " << rpa->sref;
		};
		cout << ") = " << cmd->sref << "(";
		for (unsigned int j = 0; j < ipas.nodes.size(); j++) {
			ipa = ipas.nodes[j];

			if (j != 0) cout << ", ";
			cout << VecWdbeVPartype::getSref(ipa->ixWdbeVPartype) << " " << ipa->sref;
		};
		cout << ")" << endl;
	};

	// IP handleShowCmds --- IEND
	return retval;
};

bool CrdWdbeUnt::handleShowGens(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleShowGens --- IBEGIN
	ubigint ref;

	if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = 0 AND hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND hkUref = "
				+ to_string(xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref)), ref)) showSubmdls(dbswdbe, ref, true, false, false, 0);
	// IP handleShowGens --- IEND
	return retval;
};

bool CrdWdbeUnt::handleShowMdls(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleShowMdls --- IBEGIN
	ubigint ref;

	if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = 0 AND hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND hkUref = "
				+ to_string(xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref)), ref)) showSubmdls(dbswdbe, ref, false, false, false, 0);
	// IP handleShowMdls --- IEND
	return retval;
};

bool CrdWdbeUnt::handleShowPrts(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleShowPrts --- IBEGIN
	ubigint ref;

	if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = 0 AND hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND hkUref = "
				+ to_string(xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref)), ref)) showSubmdls(dbswdbe, ref, false, true, false, 0);
	// IP handleShowPrts --- IEND
	return retval;
};

bool CrdWdbeUnt::handleShowSigs(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleShowSigs --- IBEGIN
	ubigint ref;

	if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = 0 AND hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND hkUref = "
				+ to_string(xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref)), ref)) showSubmdls(dbswdbe, ref, false, false, true, 0);
	// IP handleShowSigs --- IEND
	return retval;
};

void CrdWdbeUnt::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void CrdWdbeUnt::handleDpchAppDoClose(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	xchg->triggerIxCall(dbswdbe, VecWdbeVCall::CALLWDBECRDCLOSE, jref, VecWdbeVCard::CRDWDBEUNT);
};

void CrdWdbeUnt::handleDpchAppDoMitAppAbtClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoMitAppAbtClick --- BEGIN
	changeStage(dbswdbe, VecVSge::ALRWDBEABT, dpcheng);
	// IP handleDpchAppDoMitAppAbtClick --- END
};

void CrdWdbeUnt::handleDpchAppWdbeAlert(
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

void CrdWdbeUnt::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBEREFPRESET) {
		call->abort = handleCallWdbeRefPreSet(dbswdbe, call->jref, call->argInv.ix, call->argInv.ref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBESTATCHG) {
		call->abort = handleCallWdbeStatChg(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEDLGCLOSE) {
		call->abort = handleCallWdbeDlgClose(dbswdbe, call->jref);
	};
};

bool CrdWdbeUnt::handleCallWdbeRefPreSet(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;

	if (ixInv == VecWdbeVPreset::PREWDBEREFUNT) {
		changeRef(dbswdbe, jrefTrig, refInv, true);

		if (refInv == 0) pnlrec->minimize(dbswdbe, true);
	};

	return retval;
};

bool CrdWdbeUnt::handleCallWdbeStatChg(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	if (jrefTrig == pnlrec->jref) if ((pnllist->statshr.ixWdbeVExpstate == VecWdbeVExpstate::REGD) && (pnlrec->statshr.ixWdbeVExpstate == VecWdbeVExpstate::REGD)) pnllist->minimize(dbswdbe, true);
	return retval;
};

bool CrdWdbeUnt::handleCallWdbeDlgClose(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWdbeDlgClose --- INSERT
	return retval;
};

void CrdWdbeUnt::changeStage(
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

string CrdWdbeUnt::getSquawk(
			DbsWdbe* dbswdbe
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

uint CrdWdbeUnt::enterSgeIdle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void CrdWdbeUnt::leaveSgeIdle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeIdle --- INSERT
};

uint CrdWdbeUnt::enterSgeAlrwdbeabt(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::ALRWDBEABT;
	nextIxVSgeSuccess = VecVSge::IDLE;

	xchg->submitDpch(AlrWdbe::prepareAlrAbt(jref, ixWdbeVLocale, feedFMcbAlert)); // IP enterSgeAlrwdbeabt --- LINE

	return retval;
};

void CrdWdbeUnt::leaveSgeAlrwdbeabt(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAlrwdbeabt --- INSERT
};


