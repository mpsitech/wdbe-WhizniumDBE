/**
	* \file PnlWdbeNavLow.cpp
	* job handler for job PnlWdbeNavLow (implementation)
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

#include "PnlWdbeNavLow.h"

#include "PnlWdbeNavLow_blks.cpp"
#include "PnlWdbeNavLow_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWdbeNavLow
 ******************************************************************************/

PnlWdbeNavLow::PnlWdbeNavLow(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::PNLWDBENAVLOW, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFLstBnk.tag = "FeedFLstBnk";
	feedFLstCdc.tag = "FeedFLstCdc";
	feedFLstFst.tag = "FeedFLstFst";
	feedFLstGen.tag = "FeedFLstGen";
	feedFLstInt.tag = "FeedFLstInt";
	feedFLstPin.tag = "FeedFLstPin";
	feedFLstPrc.tag = "FeedFLstPrc";
	feedFLstPrt.tag = "FeedFLstPrt";
	feedFLstSig.tag = "FeedFLstSig";
	feedFLstSns.tag = "FeedFLstSns";
	feedFLstVar.tag = "FeedFLstVar";

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refreshBnk(dbswdbe, moditems);
	refreshPin(dbswdbe, moditems);
	refreshInt(dbswdbe, moditems);
	refreshSns(dbswdbe, moditems);
	refreshVar(dbswdbe, moditems);
	refreshGen(dbswdbe, moditems);
	refreshPrt(dbswdbe, moditems);
	refreshSig(dbswdbe, moditems);
	refreshCdc(dbswdbe, moditems);
	refreshPrc(dbswdbe, moditems);
	refreshFst(dbswdbe, moditems);
	refresh(dbswdbe, moditems);

	xchg->addClstn(VecWdbeVCall::CALLWDBEHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	xchg->addIxRefClstn(VecWdbeVCall::CALLWDBEHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWdbeVCard::CRDWDBEBNK, xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref));
	xchg->addIxRefClstn(VecWdbeVCall::CALLWDBEHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWdbeVCard::CRDWDBEPIN, xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref));
	xchg->addIxRefClstn(VecWdbeVCall::CALLWDBEHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWdbeVCard::CRDWDBEINT, xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref));
	xchg->addIxRefClstn(VecWdbeVCall::CALLWDBEHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWdbeVCard::CRDWDBESNS, xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref));
	xchg->addIxRefClstn(VecWdbeVCall::CALLWDBEHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWdbeVCard::CRDWDBEVAR, xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref));
	xchg->addIxRefClstn(VecWdbeVCall::CALLWDBEHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWdbeVCard::CRDWDBEGEN, xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref));
	xchg->addIxRefClstn(VecWdbeVCall::CALLWDBEHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWdbeVCard::CRDWDBEPRT, xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref));
	xchg->addIxRefClstn(VecWdbeVCall::CALLWDBEHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWdbeVCard::CRDWDBESIG, xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref));
	xchg->addIxRefClstn(VecWdbeVCall::CALLWDBEHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWdbeVCard::CRDWDBECDC, xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref));
	xchg->addIxRefClstn(VecWdbeVCall::CALLWDBEHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWdbeVCard::CRDWDBEPRC, xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref));
	xchg->addIxRefClstn(VecWdbeVCall::CALLWDBEHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWdbeVCard::CRDWDBEFST, xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref));
};

PnlWdbeNavLow::~PnlWdbeNavLow() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWdbe* PnlWdbeNavLow::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &feedFLstBnk, &feedFLstCdc, &feedFLstFst, &feedFLstGen, &feedFLstInt, &feedFLstPin, &feedFLstPrc, &feedFLstPrt, &feedFLstSig, &feedFLstSns, &feedFLstVar, &statshr, items);
	};

	return dpcheng;
};

void PnlWdbeNavLow::refreshLstBnk(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstBnkAvail = evalLstBnkAvail(dbswdbe);
	statshr.ButBnkViewActive = evalButBnkViewActive(dbswdbe);
	statshr.ButBnkNewcrdActive = evalButBnkNewcrdActive(dbswdbe);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeNavLow::refreshBnk(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWdbeHistRMUserUniversal rst;
	WdbeHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstBnk = 0;

	// feedFLstBnk
	feedFLstBnk.clear();

	dbswdbe->tblwdbehistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref), VecWdbeVCard::CRDWDBEBNK, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstBnk.appendRefTitles(rec->ref, StubWdbe::getStubBnkStd(dbswdbe, rec->unvUref, ixWdbeVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTBNK);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstBnk(dbswdbe, moditems);
};

void PnlWdbeNavLow::refreshLstPin(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstPinAvail = evalLstPinAvail(dbswdbe);
	statshr.ButPinViewActive = evalButPinViewActive(dbswdbe);
	statshr.ButPinNewcrdActive = evalButPinNewcrdActive(dbswdbe);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeNavLow::refreshPin(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWdbeHistRMUserUniversal rst;
	WdbeHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstPin = 0;

	// feedFLstPin
	feedFLstPin.clear();

	dbswdbe->tblwdbehistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref), VecWdbeVCard::CRDWDBEPIN, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstPin.appendRefTitles(rec->ref, StubWdbe::getStubPinStd(dbswdbe, rec->unvUref, ixWdbeVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTPIN);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstPin(dbswdbe, moditems);
};

void PnlWdbeNavLow::refreshLstInt(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstIntAvail = evalLstIntAvail(dbswdbe);
	statshr.ButIntViewActive = evalButIntViewActive(dbswdbe);
	statshr.ButIntNewcrdActive = evalButIntNewcrdActive(dbswdbe);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeNavLow::refreshInt(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWdbeHistRMUserUniversal rst;
	WdbeHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstInt = 0;

	// feedFLstInt
	feedFLstInt.clear();

	dbswdbe->tblwdbehistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref), VecWdbeVCard::CRDWDBEINT, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstInt.appendRefTitles(rec->ref, StubWdbe::getStubIntStd(dbswdbe, rec->unvUref, ixWdbeVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTINT);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstInt(dbswdbe, moditems);
};

void PnlWdbeNavLow::refreshLstSns(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstSnsAvail = evalLstSnsAvail(dbswdbe);
	statshr.ButSnsViewActive = evalButSnsViewActive(dbswdbe);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeNavLow::refreshSns(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWdbeHistRMUserUniversal rst;
	WdbeHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstSns = 0;

	// feedFLstSns
	feedFLstSns.clear();

	dbswdbe->tblwdbehistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref), VecWdbeVCard::CRDWDBESNS, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstSns.appendRefTitles(rec->ref, StubWdbe::getStubSnsStd(dbswdbe, rec->unvUref, ixWdbeVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTSNS);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstSns(dbswdbe, moditems);
};

void PnlWdbeNavLow::refreshLstVar(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstVarAvail = evalLstVarAvail(dbswdbe);
	statshr.ButVarViewActive = evalButVarViewActive(dbswdbe);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeNavLow::refreshVar(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWdbeHistRMUserUniversal rst;
	WdbeHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstVar = 0;

	// feedFLstVar
	feedFLstVar.clear();

	dbswdbe->tblwdbehistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref), VecWdbeVCard::CRDWDBEVAR, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstVar.appendRefTitles(rec->ref, StubWdbe::getStubVarStd(dbswdbe, rec->unvUref, ixWdbeVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTVAR);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstVar(dbswdbe, moditems);
};

void PnlWdbeNavLow::refreshLstGen(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstGenAvail = evalLstGenAvail(dbswdbe);
	statshr.ButGenViewActive = evalButGenViewActive(dbswdbe);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeNavLow::refreshGen(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWdbeHistRMUserUniversal rst;
	WdbeHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstGen = 0;

	// feedFLstGen
	feedFLstGen.clear();

	dbswdbe->tblwdbehistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref), VecWdbeVCard::CRDWDBEGEN, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstGen.appendRefTitles(rec->ref, StubWdbe::getStubGenStd(dbswdbe, rec->unvUref, ixWdbeVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTGEN);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstGen(dbswdbe, moditems);
};

void PnlWdbeNavLow::refreshLstPrt(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstPrtAvail = evalLstPrtAvail(dbswdbe);
	statshr.ButPrtViewActive = evalButPrtViewActive(dbswdbe);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeNavLow::refreshPrt(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWdbeHistRMUserUniversal rst;
	WdbeHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstPrt = 0;

	// feedFLstPrt
	feedFLstPrt.clear();

	dbswdbe->tblwdbehistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref), VecWdbeVCard::CRDWDBEPRT, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstPrt.appendRefTitles(rec->ref, StubWdbe::getStubPrtStd(dbswdbe, rec->unvUref, ixWdbeVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTPRT);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstPrt(dbswdbe, moditems);
};

void PnlWdbeNavLow::refreshLstSig(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstSigAvail = evalLstSigAvail(dbswdbe);
	statshr.ButSigViewActive = evalButSigViewActive(dbswdbe);
	statshr.ButSigNewcrdActive = evalButSigNewcrdActive(dbswdbe);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeNavLow::refreshSig(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWdbeHistRMUserUniversal rst;
	WdbeHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstSig = 0;

	// feedFLstSig
	feedFLstSig.clear();

	dbswdbe->tblwdbehistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref), VecWdbeVCard::CRDWDBESIG, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstSig.appendRefTitles(rec->ref, StubWdbe::getStubSigStd(dbswdbe, rec->unvUref, ixWdbeVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTSIG);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstSig(dbswdbe, moditems);
};

void PnlWdbeNavLow::refreshLstCdc(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstCdcAvail = evalLstCdcAvail(dbswdbe);
	statshr.ButCdcViewActive = evalButCdcViewActive(dbswdbe);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeNavLow::refreshCdc(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWdbeHistRMUserUniversal rst;
	WdbeHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstCdc = 0;

	// feedFLstCdc
	feedFLstCdc.clear();

	dbswdbe->tblwdbehistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref), VecWdbeVCard::CRDWDBECDC, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstCdc.appendRefTitles(rec->ref, StubWdbe::getStubCdcdStd(dbswdbe, rec->unvUref, ixWdbeVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTCDC);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstCdc(dbswdbe, moditems);
};

void PnlWdbeNavLow::refreshLstPrc(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstPrcAvail = evalLstPrcAvail(dbswdbe);
	statshr.ButPrcViewActive = evalButPrcViewActive(dbswdbe);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeNavLow::refreshPrc(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWdbeHistRMUserUniversal rst;
	WdbeHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstPrc = 0;

	// feedFLstPrc
	feedFLstPrc.clear();

	dbswdbe->tblwdbehistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref), VecWdbeVCard::CRDWDBEPRC, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstPrc.appendRefTitles(rec->ref, StubWdbe::getStubPrcStd(dbswdbe, rec->unvUref, ixWdbeVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTPRC);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstPrc(dbswdbe, moditems);
};

void PnlWdbeNavLow::refreshLstFst(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstFstAvail = evalLstFstAvail(dbswdbe);
	statshr.ButFstViewActive = evalButFstViewActive(dbswdbe);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWdbeNavLow::refreshFst(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWdbeHistRMUserUniversal rst;
	WdbeHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstFst = 0;

	// feedFLstFst
	feedFLstFst.clear();

	dbswdbe->tblwdbehistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref), VecWdbeVCard::CRDWDBEFST, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstFst.appendRefTitles(rec->ref, StubWdbe::getStubFstStd(dbswdbe, rec->unvUref, ixWdbeVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTFST);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstFst(dbswdbe, moditems);
};

void PnlWdbeNavLow::refresh(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	// IP refresh --- LINE

	muteRefresh = false;
};

void PnlWdbeNavLow::updatePreset(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	refresh(dbswdbe, moditems);

	refreshLstBnk(dbswdbe, moditems);
	refreshLstPin(dbswdbe, moditems);
	refreshLstInt(dbswdbe, moditems);
	refreshLstSns(dbswdbe, moditems);
	refreshLstVar(dbswdbe, moditems);
	refreshLstGen(dbswdbe, moditems);
	refreshLstPrt(dbswdbe, moditems);
	refreshLstSig(dbswdbe, moditems);
	refreshLstCdc(dbswdbe, moditems);
	refreshLstPrc(dbswdbe, moditems);
	refreshLstFst(dbswdbe, moditems);
	if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	// IP updatePreset --- END
};

void PnlWdbeNavLow::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVLOWDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswdbe, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBENAVLOWDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTBNKVIEWCLICK) {
					handleDpchAppDoButBnkViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTBNKNEWCRDCLICK) {
					handleDpchAppDoButBnkNewcrdClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPINVIEWCLICK) {
					handleDpchAppDoButPinViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPINNEWCRDCLICK) {
					handleDpchAppDoButPinNewcrdClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTINTVIEWCLICK) {
					handleDpchAppDoButIntViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTINTNEWCRDCLICK) {
					handleDpchAppDoButIntNewcrdClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSNSVIEWCLICK) {
					handleDpchAppDoButSnsViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTVARVIEWCLICK) {
					handleDpchAppDoButVarViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTGENVIEWCLICK) {
					handleDpchAppDoButGenViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRTVIEWCLICK) {
					handleDpchAppDoButPrtViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSIGVIEWCLICK) {
					handleDpchAppDoButSigViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSIGNEWCRDCLICK) {
					handleDpchAppDoButSigNewcrdClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCDCVIEWCLICK) {
					handleDpchAppDoButCdcViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRCVIEWCLICK) {
					handleDpchAppDoButPrcViewClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFSTVIEWCLICK) {
					handleDpchAppDoButFstViewClick(dbswdbe, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWdbeNavLow::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWdbeNavLow::handleDpchAppDataContiac(
			DbsWdbe* dbswdbe
			, ContIac* _contiac
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFLSTBNK)) {
		contiac.numFLstBnk = _contiac->numFLstBnk;
		refreshLstBnk(dbswdbe, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTPIN)) {
		contiac.numFLstPin = _contiac->numFLstPin;
		refreshLstPin(dbswdbe, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTINT)) {
		contiac.numFLstInt = _contiac->numFLstInt;
		refreshLstInt(dbswdbe, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTSNS)) {
		contiac.numFLstSns = _contiac->numFLstSns;
		refreshLstSns(dbswdbe, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTVAR)) {
		contiac.numFLstVar = _contiac->numFLstVar;
		refreshLstVar(dbswdbe, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTGEN)) {
		contiac.numFLstGen = _contiac->numFLstGen;
		refreshLstGen(dbswdbe, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTPRT)) {
		contiac.numFLstPrt = _contiac->numFLstPrt;
		refreshLstPrt(dbswdbe, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTSIG)) {
		contiac.numFLstSig = _contiac->numFLstSig;
		refreshLstSig(dbswdbe, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTCDC)) {
		contiac.numFLstCdc = _contiac->numFLstCdc;
		refreshLstCdc(dbswdbe, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTPRC)) {
		contiac.numFLstPrc = _contiac->numFLstPrc;
		refreshLstPrc(dbswdbe, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTFST)) {
		contiac.numFLstFst = _contiac->numFLstFst;
		refreshLstFst(dbswdbe, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWdbeNavLow::handleDpchAppDoButBnkViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	WdbeHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstBnkAvail && statshr.ButBnkViewActive) {
		if (dbswdbe->tblwdbehistrmuseruniversal->loadRecByRef(feedFLstBnk.getRefByNum(contiac.numFLstBnk), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, husrRunv->ixWdbeVPreset, husrRunv->preUref, "CrdWdbeBnk", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeBnk");
	};
};

void PnlWdbeNavLow::handleDpchAppDoButBnkNewcrdClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButBnkNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbeBnk", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeBnk");
	};
};

void PnlWdbeNavLow::handleDpchAppDoButPinViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	WdbeHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstPinAvail && statshr.ButPinViewActive) {
		if (dbswdbe->tblwdbehistrmuseruniversal->loadRecByRef(feedFLstPin.getRefByNum(contiac.numFLstPin), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, husrRunv->ixWdbeVPreset, husrRunv->preUref, "CrdWdbePin", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbePin");
	};
};

void PnlWdbeNavLow::handleDpchAppDoButPinNewcrdClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButPinNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbePin", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbePin");
	};
};

void PnlWdbeNavLow::handleDpchAppDoButIntViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	WdbeHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstIntAvail && statshr.ButIntViewActive) {
		if (dbswdbe->tblwdbehistrmuseruniversal->loadRecByRef(feedFLstInt.getRefByNum(contiac.numFLstInt), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, husrRunv->ixWdbeVPreset, husrRunv->preUref, "CrdWdbeInt", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeInt");
	};
};

void PnlWdbeNavLow::handleDpchAppDoButIntNewcrdClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButIntNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbeInt", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeInt");
	};
};

void PnlWdbeNavLow::handleDpchAppDoButSnsViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	WdbeHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstSnsAvail && statshr.ButSnsViewActive) {
		if (dbswdbe->tblwdbehistrmuseruniversal->loadRecByRef(feedFLstSns.getRefByNum(contiac.numFLstSns), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, husrRunv->ixWdbeVPreset, husrRunv->preUref, "CrdWdbeSns", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeSns");
	};
};

void PnlWdbeNavLow::handleDpchAppDoButVarViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	WdbeHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstVarAvail && statshr.ButVarViewActive) {
		if (dbswdbe->tblwdbehistrmuseruniversal->loadRecByRef(feedFLstVar.getRefByNum(contiac.numFLstVar), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, husrRunv->ixWdbeVPreset, husrRunv->preUref, "CrdWdbeVar", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeVar");
	};
};

void PnlWdbeNavLow::handleDpchAppDoButGenViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	WdbeHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstGenAvail && statshr.ButGenViewActive) {
		if (dbswdbe->tblwdbehistrmuseruniversal->loadRecByRef(feedFLstGen.getRefByNum(contiac.numFLstGen), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, husrRunv->ixWdbeVPreset, husrRunv->preUref, "CrdWdbeGen", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeGen");
	};
};

void PnlWdbeNavLow::handleDpchAppDoButPrtViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	WdbeHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstPrtAvail && statshr.ButPrtViewActive) {
		if (dbswdbe->tblwdbehistrmuseruniversal->loadRecByRef(feedFLstPrt.getRefByNum(contiac.numFLstPrt), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, husrRunv->ixWdbeVPreset, husrRunv->preUref, "CrdWdbePrt", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbePrt");
	};
};

void PnlWdbeNavLow::handleDpchAppDoButSigViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	WdbeHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstSigAvail && statshr.ButSigViewActive) {
		if (dbswdbe->tblwdbehistrmuseruniversal->loadRecByRef(feedFLstSig.getRefByNum(contiac.numFLstSig), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, husrRunv->ixWdbeVPreset, husrRunv->preUref, "CrdWdbeSig", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeSig");
	};
};

void PnlWdbeNavLow::handleDpchAppDoButSigNewcrdClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	ubigint jrefNew = 0;

	if (statshr.ButSigNewcrdActive) {
		xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, 0, 0, "CrdWdbeSig", 0, jrefNew);

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeSig");
	};
};

void PnlWdbeNavLow::handleDpchAppDoButCdcViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	WdbeHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstCdcAvail && statshr.ButCdcViewActive) {
		if (dbswdbe->tblwdbehistrmuseruniversal->loadRecByRef(feedFLstCdc.getRefByNum(contiac.numFLstCdc), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, husrRunv->ixWdbeVPreset, husrRunv->preUref, "CrdWdbeCdc", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeCdc");
	};
};

void PnlWdbeNavLow::handleDpchAppDoButPrcViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	WdbeHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstPrcAvail && statshr.ButPrcViewActive) {
		if (dbswdbe->tblwdbehistrmuseruniversal->loadRecByRef(feedFLstPrc.getRefByNum(contiac.numFLstPrc), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, husrRunv->ixWdbeVPreset, husrRunv->preUref, "CrdWdbePrc", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbePrc");
	};
};

void PnlWdbeNavLow::handleDpchAppDoButFstViewClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	WdbeHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstFstAvail && statshr.ButFstViewActive) {
		if (dbswdbe->tblwdbehistrmuseruniversal->loadRecByRef(feedFLstFst.getRefByNum(contiac.numFLstFst), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswdbe, VecWdbeVCall::CALLWDBECRDOPEN, jref, husrRunv->ixWdbeVPreset, husrRunv->preUref, "CrdWdbeFst", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWdbeConfirm(false, 0, "");
		else *dpcheng = new DpchEngWdbeConfirm(true, jrefNew, "CrdWdbeFst");
	};
};

void PnlWdbeNavLow::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBEHUSRRUNVMOD_CRDUSREQ) {
		call->abort = handleCallWdbeHusrRunvMod_crdUsrEq(dbswdbe, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool PnlWdbeNavLow::handleCallWdbeHusrRunvMod_crdUsrEq(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecWdbeVCard::CRDWDBEBNK) {
		refreshBnk(dbswdbe, moditems);
	} else if (ixInv == VecWdbeVCard::CRDWDBEPIN) {
		refreshPin(dbswdbe, moditems);
	} else if (ixInv == VecWdbeVCard::CRDWDBEINT) {
		refreshInt(dbswdbe, moditems);
	} else if (ixInv == VecWdbeVCard::CRDWDBESNS) {
		refreshSns(dbswdbe, moditems);
	} else if (ixInv == VecWdbeVCard::CRDWDBEVAR) {
		refreshVar(dbswdbe, moditems);
	} else if (ixInv == VecWdbeVCard::CRDWDBEGEN) {
		refreshGen(dbswdbe, moditems);
	} else if (ixInv == VecWdbeVCard::CRDWDBEPRT) {
		refreshPrt(dbswdbe, moditems);
	} else if (ixInv == VecWdbeVCard::CRDWDBESIG) {
		refreshSig(dbswdbe, moditems);
	} else if (ixInv == VecWdbeVCard::CRDWDBECDC) {
		refreshCdc(dbswdbe, moditems);
	} else if (ixInv == VecWdbeVCard::CRDWDBEPRC) {
		refreshPrc(dbswdbe, moditems);
	} else if (ixInv == VecWdbeVCard::CRDWDBEFST) {
		refreshFst(dbswdbe, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};
