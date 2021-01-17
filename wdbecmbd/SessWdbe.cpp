/**
	* \file SessWdbe.cpp
	* job handler for job SessWdbe (implementation)
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

#include "SessWdbe.h"

#include "SessWdbe_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

// IP ns.spec --- INSERT

/******************************************************************************
 class SessWdbe
 ******************************************************************************/

SessWdbe::SessWdbe(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const ubigint refWdbeMUser
			, const string& ip
		) :
			JobWdbe(xchg, VecWdbeVJob::SESSWDBE, jrefSup)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	crdnav = NULL;

	// IP constructor.cust1 --- INSERT

	vector<ubigint> refs;

	ubigint refSes;

	WdbeMUser* usr = NULL;

	bool adm;

	ListWdbeRMUserMUsergroup urus;
	WdbeRMUserMUsergroup* uru = NULL;

	uint ixWdbeWAccessBase, ixWdbeWAccess;

	uint jnum;

	// create new session with start time
	time_t rawtime;
	time(&rawtime);

	refSes = dbswdbe->tblwdbemsession->insertNewRec(NULL, refWdbeMUser, (uint) rawtime, 0, ip);

	xchg->addRefPreset(VecWdbeVPreset::PREWDBESESS, jref, refSes);
	xchg->addTxtvalPreset(VecWdbeVPreset::PREWDBEIP, jref, ip);

	// set locale and presetings corresponding to user
	dbswdbe->tblwdbemuser->loadRecByRef(refWdbeMUser, &usr);

	ixWdbeVLocale = usr->ixWdbeVLocale;
	adm = (usr->ixWdbeVUserlevel == VecWdbeVUserlevel::ADM);

	xchg->addBoolvalPreset(VecWdbeVPreset::PREWDBEADMIN, jref, adm);
	xchg->addBoolvalPreset(VecWdbeVPreset::PREWDBENOADM, jref, (usr->ixWdbeVUserlevel == VecWdbeVUserlevel::REG));

	xchg->addRefPreset(VecWdbeVPreset::PREWDBEGROUP, jref, usr->refWdbeMUsergroup);
	xchg->addRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref, refWdbeMUser);

	delete usr;

	// set jrefSess (for access to WdbeQSelect from rst-type panel queries)
	xchg->addRefPreset(VecWdbeVPreset::PREWDBEJREFSESS, jref, jref);

	// fill query in WdbeQSelect with all applicable user groups
	jnum = 1;

	dbswdbe->tblwdbeqselect->insertNewRec(NULL, jref, jnum++, 0, 0);

	if (adm) {
		dbswdbe->loadRefsBySQL("SELECT ref FROM TblWdbeMUsergroup ORDER BY ref ASC", false, refs);

		for (unsigned int i = 0; i < refs.size(); i++) dbswdbe->tblwdbeqselect->insertNewRec(NULL, jref, jnum++, 0, refs[i]);

	} else {
		dbswdbe->tblwdbermusermusergroup->loadRstByUsr(refWdbeMUser, false, urus);

		for (unsigned int i = 0; i < urus.nodes.size(); i++) {
			uru = urus.nodes[i];

			usgaccs[uru->refWdbeMUsergroup] = uru->ixWdbeVUserlevel;
			dbswdbe->tblwdbeqselect->insertNewRec(NULL, jref, jnum++, 0, uru->refWdbeMUsergroup);
		};
	};

	// determine access rights for each card
	ixWdbeWAccessBase = 0;
	getIxCrdacc(dbswdbe, 0, adm, urus, refWdbeMUser, ixWdbeWAccessBase);

	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBEUSG, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCUSG, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBEUSR, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCUSR, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBEPRS, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPRS, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBEFIL, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCFIL, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBEMCH, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMCH, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBELIB, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCLIB, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBEFAM, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCFAM, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBESIL, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIL, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBEMTP, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMTP, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBEPRJ, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPRJ, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBEVER, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVER, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBESYS, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSYS, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBETRG, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCTRG, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBEUNT, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCUNT, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBERLS, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCRLS, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBECPR, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCPR, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBECVR, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCVR, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBEMOD, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBEVEC, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVEC, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBEVIT, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVIT, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBECMD, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCMD, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBEERR, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCERR, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBEPPH, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPPH, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBEBNK, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCBNK, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBEPIN, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPIN, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBEGEN, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCGEN, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBEPRT, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPRT, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBESIG, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIG, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBEPRC, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPRC, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBEFST, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCFST, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBEVAR, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVAR, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBEUTL, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCUTL, jref, ixWdbeWAccess);

	crdnav = new CrdWdbeNav(xchg, dbswdbe, jref, ixWdbeVLocale);

	// IP constructor.cust2 --- INSERT

	statshr.jrefCrdnav = crdnav->jref;

	xchg->addClstn(VecWdbeVCall::CALLWDBECRDACTIVE, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBECRDCLOSE, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBECRDOPEN, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBELOG, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBERECACCESS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEREFPRESET, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

SessWdbe::~SessWdbe() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void SessWdbe::term(
			DbsWdbe* dbswdbe
		) {
	WdbeMSession* ses = NULL;

	time_t rawtime;

	// update session with stop time
	time(&rawtime);

	if (dbswdbe->tblwdbemsession->loadRecByRef(xchg->getRefPreset(VecWdbeVPreset::PREWDBESESS, jref), &ses)) {
		ses->stop = rawtime;
		dbswdbe->tblwdbemsession->updateRec(ses);

		delete ses;
	};
};

uint SessWdbe::checkCrdActive(
			const uint ixWdbeVCard
		) {
	if (ixWdbeVCard == VecWdbeVCard::CRDWDBEVER) return evalCrdverActive();
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBESYS) return evalCrdsysActive();
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBETRG) return evalCrdtrgActive();
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEUNT) return evalCrduntActive();
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBERLS) return evalCrdrlsActive();
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBECVR) return evalCrdcvrActive();
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEMOD) return evalCrdmodActive();
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEVEC) return evalCrdvecActive();
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEVIT) return evalCrdvitActive();
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBECMD) return evalCrdcmdActive();
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEERR) return evalCrderrActive();
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPPH) return evalCrdpphActive();
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEBNK) return evalCrdbnkActive();
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPIN) return evalCrdpinActive();
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEGEN) return evalCrdgenActive();
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPRT) return evalCrdprtActive();
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBESIG) return evalCrdsigActive();
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPRC) return evalCrdprcActive();
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEFST) return evalCrdfstActive();
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEVAR) return evalCrdvarActive();

	return 0;
};

uint SessWdbe::evalCrdverActive() {
	// pre.refPrj() > pre.void()

	vector<uint> args;
	uint a, b;

	args.push_back((xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFPRJ, jref)) ? VecWdbeVPreset::PREWDBEREFPRJ : 0);
	args.push_back([](){uint preVoid = VecWdbeVPreset::VOID; return preVoid;}());
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);

	return(args.back());
};

uint SessWdbe::evalCrdsysActive() {
	// pre.refVer()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref)) ? VecWdbeVPreset::PREWDBEREFVER : 0);

	return(args.back());
};

uint SessWdbe::evalCrdtrgActive() {
	// pre.refVer()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref)) ? VecWdbeVPreset::PREWDBEREFVER : 0);

	return(args.back());
};

uint SessWdbe::evalCrduntActive() {
	// pre.refVer()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref)) ? VecWdbeVPreset::PREWDBEREFVER : 0);

	return(args.back());
};

uint SessWdbe::evalCrdrlsActive() {
	// pre.refVer()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref)) ? VecWdbeVPreset::PREWDBEREFVER : 0);

	return(args.back());
};

uint SessWdbe::evalCrdcvrActive() {
	// pre.refCpr() > pre.void()

	vector<uint> args;
	uint a, b;

	args.push_back((xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCPR, jref)) ? VecWdbeVPreset::PREWDBEREFCPR : 0);
	args.push_back([](){uint preVoid = VecWdbeVPreset::VOID; return preVoid;}());
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);

	return(args.back());
};

uint SessWdbe::evalCrdmodActive() {
	// pre.refUnt() > pre.refCvr()

	vector<uint> args;
	uint a, b;

	args.push_back((xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref)) ? VecWdbeVPreset::PREWDBEREFUNT : 0);
	args.push_back((xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCVR, jref)) ? VecWdbeVPreset::PREWDBEREFCVR : 0);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);

	return(args.back());
};

uint SessWdbe::evalCrdvecActive() {
	// pre.refUnt() > pre.refCvr() > pre.refVer()

	vector<uint> args;
	uint a, b;

	args.push_back((xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref)) ? VecWdbeVPreset::PREWDBEREFUNT : 0);
	args.push_back((xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCVR, jref)) ? VecWdbeVPreset::PREWDBEREFCVR : 0);
	args.push_back((xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref)) ? VecWdbeVPreset::PREWDBEREFVER : 0);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);

	return(args.back());
};

uint SessWdbe::evalCrdvitActive() {
	// pre.refVec()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVEC, jref)) ? VecWdbeVPreset::PREWDBEREFVEC : 0);

	return(args.back());
};

uint SessWdbe::evalCrdcmdActive() {
	// pre.refUnt() > pre.refCtr()

	vector<uint> args;
	uint a, b;

	args.push_back((xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref)) ? VecWdbeVPreset::PREWDBEREFUNT : 0);
	args.push_back((xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCTR, jref)) ? VecWdbeVPreset::PREWDBEREFCTR : 0);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);

	return(args.back());
};

uint SessWdbe::evalCrderrActive() {
	// pre.refUnt() > pre.refCtr()

	vector<uint> args;
	uint a, b;

	args.push_back((xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref)) ? VecWdbeVPreset::PREWDBEREFUNT : 0);
	args.push_back((xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFCTR, jref)) ? VecWdbeVPreset::PREWDBEREFCTR : 0);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);

	return(args.back());
};

uint SessWdbe::evalCrdpphActive() {
	// pre.refUnt()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref)) ? VecWdbeVPreset::PREWDBEREFUNT : 0);

	return(args.back());
};

uint SessWdbe::evalCrdbnkActive() {
	// pre.refUnt()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref)) ? VecWdbeVPreset::PREWDBEREFUNT : 0);

	return(args.back());
};

uint SessWdbe::evalCrdpinActive() {
	// pre.refBnk() > pre.refUnt()

	vector<uint> args;
	uint a, b;

	args.push_back((xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFBNK, jref)) ? VecWdbeVPreset::PREWDBEREFBNK : 0);
	args.push_back((xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref)) ? VecWdbeVPreset::PREWDBEREFUNT : 0);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);

	return(args.back());
};

uint SessWdbe::evalCrdgenActive() {
	// pre.refMtp() > pre.refMod()

	vector<uint> args;
	uint a, b;

	args.push_back((xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFMTP, jref)) ? VecWdbeVPreset::PREWDBEREFMTP : 0);
	args.push_back((xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFMOD, jref)) ? VecWdbeVPreset::PREWDBEREFMOD : 0);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);

	return(args.back());
};

uint SessWdbe::evalCrdprtActive() {
	// pre.refMtp() > pre.refMod()

	vector<uint> args;
	uint a, b;

	args.push_back((xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFMTP, jref)) ? VecWdbeVPreset::PREWDBEREFMTP : 0);
	args.push_back((xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFMOD, jref)) ? VecWdbeVPreset::PREWDBEREFMOD : 0);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);

	return(args.back());
};

uint SessWdbe::evalCrdsigActive() {
	// pre.refMtp() > pre.refMod()

	vector<uint> args;
	uint a, b;

	args.push_back((xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFMTP, jref)) ? VecWdbeVPreset::PREWDBEREFMTP : 0);
	args.push_back((xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFMOD, jref)) ? VecWdbeVPreset::PREWDBEREFMOD : 0);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);

	return(args.back());
};

uint SessWdbe::evalCrdprcActive() {
	// pre.refMtp() > pre.refMod()

	vector<uint> args;
	uint a, b;

	args.push_back((xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFMTP, jref)) ? VecWdbeVPreset::PREWDBEREFMTP : 0);
	args.push_back((xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFMOD, jref)) ? VecWdbeVPreset::PREWDBEREFMOD : 0);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);

	return(args.back());
};

uint SessWdbe::evalCrdfstActive() {
	// pre.refFsm() > pre.refMtp() > pre.refMod()

	vector<uint> args;
	uint a, b;

	args.push_back((xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFFSM, jref)) ? VecWdbeVPreset::PREWDBEREFFSM : 0);
	args.push_back((xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFMTP, jref)) ? VecWdbeVPreset::PREWDBEREFMTP : 0);
	args.push_back((xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFMOD, jref)) ? VecWdbeVPreset::PREWDBEREFMOD : 0);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);

	return(args.back());
};

uint SessWdbe::evalCrdvarActive() {
	// pre.refPrc()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFPRC, jref)) ? VecWdbeVPreset::PREWDBEREFPRC : 0);

	return(args.back());
};

uint SessWdbe::checkCrdaccess(
			const uint ixWdbeVCard
		) {
	if (ixWdbeVCard == VecWdbeVCard::CRDWDBEUSG) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCUSG, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEUSR) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCUSR, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPRS) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPRS, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEFIL) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCFIL, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEMCH) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMCH, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBELIB) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCLIB, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEFAM) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCFAM, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBESIL) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIL, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEMTP) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMTP, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPRJ) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPRJ, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEVER) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVER, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBESYS) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSYS, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBETRG) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCTRG, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEUNT) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCUNT, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBERLS) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCRLS, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBECPR) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCPR, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBECVR) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCVR, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEMOD) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEVEC) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVEC, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEVIT) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVIT, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBECMD) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCMD, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEERR) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCERR, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPPH) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPPH, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEBNK) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCBNK, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPIN) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPIN, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEGEN) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCGEN, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPRT) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPRT, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBESIG) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIG, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPRC) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPRC, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEFST) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCFST, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEVAR) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVAR, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEUTL) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCUTL, jref);

	return 0;
};

void SessWdbe::getIxCrdacc(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVCard
			, const bool adm
			, ListWdbeRMUserMUsergroup& urus
			, const ubigint refWdbeMUser
			, uint& ixWdbeWAccess
		) {
	WdbeRMUserMUsergroup* uru = NULL;
	WdbeAMUsergroupAccess* usgAacc = NULL;
	WdbeAMUserAccess* usrAacc = NULL;

	uint ixCrdacc = 0;

	bool first = true;

	if (adm) {
		ixWdbeWAccess = VecWdbeWAccess::EDIT + VecWdbeWAccess::EXEC + VecWdbeWAccess::VIEW;
		return;
	};

	// check for access rights override by any of the applicable user groups
	for (unsigned int i = 0; i < urus.nodes.size(); i++) {
		uru = urus.nodes[i];

		if (dbswdbe->tblwdbeamusergroupaccess->loadRecBySQL("SELECT * FROM TblWdbeAMUsergroupAccess WHERE refWdbeMUsergroup = " + to_string(uru->refWdbeMUsergroup) + " AND x1IxWdbeVFeatgroup = " + to_string(VecWdbeVFeatgroup::VECWDBEVCARD) + " AND x2FeaSrefUix = '" + VecWdbeVCard::getSref(ixWdbeVCard) + "'", &usgAacc)) {
			ixCrdacc |= usgAacc->ixWdbeWAccess;
			first = false;

			delete usgAacc;
			if (ixCrdacc == (VecWdbeWAccess::EDIT + VecWdbeWAccess::EXEC + VecWdbeWAccess::VIEW)) break;
		};
	};

	if (!first) ixWdbeWAccess = ixCrdacc;

	// user access rights override user group access rights
	if (dbswdbe->tblwdbeamuseraccess->loadRecBySQL("SELECT * FROM TblWdbeAMUserAccess WHERE refWdbeMUser = " + to_string(refWdbeMUser) + " AND x1IxWdbeVFeatgroup = " + to_string(VecWdbeVFeatgroup::VECWDBEVCARD) + " AND x2FeaSrefUix = '" + VecWdbeVCard::getSref(ixWdbeVCard) + "'", &usrAacc)) {
		ixWdbeWAccess = usrAacc->ixWdbeWAccess;
		delete usrAacc;
	};

};

uint SessWdbe::checkRecaccess(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVCard
			, const ubigint ref
		) {
	uint retval = VecWdbeVRecaccess::NONE;

	ubigint grp;
	ubigint own;

	map<ubigint,uint>::iterator it;

	ubigint refWdbeMUser;
	uint ixWdbeVMaintable;

	WdbeAccRMUserUniversal* ausrRunv = NULL;
	WdbeRMUsergroupUniversal* usgRunv = NULL;

	ixWdbeVMaintable = crdToMtb(ixWdbeVCard);

	if (ixWdbeVMaintable == VecWdbeVMaintable::VOID) {
		retval = VecWdbeVRecaccess::FULL;

	} else if (hasGrpown(ixWdbeVMaintable) && (ref != 0)) {
		// find record's group and owner
		dbswdbe->loadRefBySQL("SELECT grp FROM " + VecWdbeVMaintable::getSref(ixWdbeVMaintable) + " WHERE ref = " + to_string(ref), grp);
		dbswdbe->loadRefBySQL("SELECT own FROM " + VecWdbeVMaintable::getSref(ixWdbeVMaintable) + " WHERE ref = " + to_string(ref), own);

		// administrators can edit any record
		if (xchg->getBoolvalPreset(VecWdbeVPreset::PREWDBEADMIN, jref)) retval = VecWdbeVRecaccess::FULL;

		if (retval == VecWdbeVRecaccess::NONE) {
			refWdbeMUser = xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref);

			// a record's owner has full rights on his records
			if (refWdbeMUser == own) retval = VecWdbeVRecaccess::FULL;

			if (retval != VecWdbeVRecaccess::FULL) {
				// individual record access right
				if (dbswdbe->tblwdbeaccrmuseruniversal->loadRecByUsrMtbUnv(refWdbeMUser, ixWdbeVMaintable, ref, &ausrRunv)) {
					retval = ausrRunv->ixWdbeVRecaccess;
					delete ausrRunv;
				};
			};

			if (retval != VecWdbeVRecaccess::FULL) {
				it = usgaccs.find(grp);
				if (it != usgaccs.end()) {
					if (it->second == VecWdbeVUserlevel::GADM) {
						// group admins have full access to all of the group's records
						retval = VecWdbeVRecaccess::FULL;
					};
				};
			};

			if (retval != VecWdbeVRecaccess::FULL) {
				// individual record access right due to group membership
				for (it = usgaccs.begin(); it != usgaccs.end(); it++) {

					if (it->second == VecWdbeVUserlevel::GADM) {
						if (dbswdbe->tblwdbermusergroupuniversal->loadRecByUsgMtbUnv(it->second, ixWdbeVMaintable, ref, &usgRunv)) {
							if (usgRunv->ixWdbeVRecaccess == VecWdbeVRecaccess::FULL) retval = VecWdbeVRecaccess::FULL;
							else retval = VecWdbeVRecaccess::VIEW;

							delete usgRunv;
						};
					};

					if (retval == VecWdbeVRecaccess::FULL) break;
				};
			};
		};

	} else {
		if (xchg->getBoolvalPreset(VecWdbeVPreset::PREWDBEADMIN, jref)) retval = VecWdbeVRecaccess::FULL;
		else retval = VecWdbeVRecaccess::VIEW;
	};

	return retval;
};

void SessWdbe::logRecaccess(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVPreset
			, const ubigint preUref
			, const uint ixWdbeVCard
			, const ubigint unvUref
		) {
	vector<ubigint> refs;

	ubigint refWdbeMUser;
	uint unvIxWdbeVMaintable;
	uint preIxWdbeVMaintable;

	WdbeHistRMUserUniversal* husrRunv = NULL;

	if (xchg->stgwdbeappearance.histlength > 0) {
		refWdbeMUser = xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref);
		unvIxWdbeVMaintable = crdToMtb(ixWdbeVCard);
		preIxWdbeVMaintable = preToMtb(ixWdbeVPreset);

		if (!dbswdbe->tblwdbehistrmuseruniversal->loadRecByUsrMtbUnvCrd(refWdbeMUser, unvIxWdbeVMaintable, unvUref, ixWdbeVCard, &husrRunv)) {
			husrRunv = new WdbeHistRMUserUniversal(0, refWdbeMUser, unvIxWdbeVMaintable, unvUref, ixWdbeVCard, ixWdbeVPreset, preIxWdbeVMaintable, preUref, 0);
		};

		husrRunv->start = time(NULL);

		if (husrRunv->ref == 0) {
			dbswdbe->tblwdbehistrmuseruniversal->insertRec(husrRunv);

			dbswdbe->tblwdbehistrmuseruniversal->loadRefsByUsrMtbCrd(refWdbeMUser, unvIxWdbeVMaintable, ixWdbeVCard, false, refs, 4294967296, xchg->stgwdbeappearance.histlength);
			for (unsigned int i = 0; i < refs.size(); i++) dbswdbe->tblwdbehistrmuseruniversal->removeRecByRef(refs[i]);

		} else dbswdbe->tblwdbehistrmuseruniversal->updateRec(husrRunv);

		xchg->triggerIxRefCall(dbswdbe, VecWdbeVCall::CALLWDBEHUSRRUNVMOD_CRDUSREQ, jref, ixWdbeVCard, refWdbeMUser);
	};

	delete husrRunv;
};

uint SessWdbe::crdToMtb(
			const uint ixWdbeVCard
		) {
	if (ixWdbeVCard == VecWdbeVCard::CRDWDBEUSG) return VecWdbeVMaintable::TBLWDBEMUSERGROUP;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEUSR) return VecWdbeVMaintable::TBLWDBEMUSER;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPRS) return VecWdbeVMaintable::TBLWDBEMPERSON;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEFIL) return VecWdbeVMaintable::TBLWDBEMFILE;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEMCH) return VecWdbeVMaintable::TBLWDBEMMACHINE;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBELIB) return VecWdbeVMaintable::TBLWDBEMLIBRARY;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEFAM) return VecWdbeVMaintable::TBLWDBEMFAMILY;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBESIL) return VecWdbeVMaintable::TBLWDBEMUNIT;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEMTP) return VecWdbeVMaintable::TBLWDBEMMODULE;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPRJ) return VecWdbeVMaintable::TBLWDBEMPROJECT;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEVER) return VecWdbeVMaintable::TBLWDBEMVERSION;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBESYS) return VecWdbeVMaintable::TBLWDBEMSYSTEM;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBETRG) return VecWdbeVMaintable::TBLWDBEMTARGET;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEUNT) return VecWdbeVMaintable::TBLWDBEMUNIT;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBERLS) return VecWdbeVMaintable::TBLWDBEMRELEASE;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBECPR) return VecWdbeVMaintable::TBLWDBEMCOREPROJECT;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBECVR) return VecWdbeVMaintable::TBLWDBEMCOREVERSION;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEMOD) return VecWdbeVMaintable::TBLWDBEMMODULE;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEVEC) return VecWdbeVMaintable::TBLWDBEMVECTOR;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEVIT) return VecWdbeVMaintable::TBLWDBEMVECTORITEM;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBECMD) return VecWdbeVMaintable::TBLWDBEMCOMMAND;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEERR) return VecWdbeVMaintable::TBLWDBEMERROR;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPPH) return VecWdbeVMaintable::TBLWDBEMPERIPHERAL;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEBNK) return VecWdbeVMaintable::TBLWDBEMBANK;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPIN) return VecWdbeVMaintable::TBLWDBEMPIN;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEGEN) return VecWdbeVMaintable::TBLWDBEMGENERIC;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPRT) return VecWdbeVMaintable::TBLWDBEMPORT;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBESIG) return VecWdbeVMaintable::TBLWDBEMSIGNAL;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPRC) return VecWdbeVMaintable::TBLWDBEMPROCESS;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEFST) return VecWdbeVMaintable::TBLWDBEMFSMSTATE;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEVAR) return VecWdbeVMaintable::TBLWDBEMVARIABLE;

	return VecWdbeVMaintable::VOID;
};

uint SessWdbe::preToMtb(
			const uint ixWdbeVPreset
		) {
	if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFBNK) return VecWdbeVMaintable::TBLWDBEMBANK;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFCMD) return VecWdbeVMaintable::TBLWDBEMCOMMAND;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFCPR) return VecWdbeVMaintable::TBLWDBEMCOREPROJECT;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFCTR) return VecWdbeVMaintable::TBLWDBEMCONTROLLER;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFCVR) return VecWdbeVMaintable::TBLWDBEMCOREVERSION;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFERR) return VecWdbeVMaintable::TBLWDBEMERROR;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFFAM) return VecWdbeVMaintable::TBLWDBEMFAMILY;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFFIL) return VecWdbeVMaintable::TBLWDBEMFILE;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFFSM) return VecWdbeVMaintable::TBLWDBEMFSM;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFFST) return VecWdbeVMaintable::TBLWDBEMFSMSTATE;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFGEN) return VecWdbeVMaintable::TBLWDBEMGENERIC;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFIMB) return VecWdbeVMaintable::TBLWDBEMIMBUF;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFLIB) return VecWdbeVMaintable::TBLWDBEMLIBRARY;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFMCH) return VecWdbeVMaintable::TBLWDBEMMACHINE;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFMCT) return VecWdbeVMaintable::TBLWDBEMMODULE;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFMDL) return VecWdbeVMaintable::TBLWDBEMMODULE;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFMIB) return VecWdbeVMaintable::TBLWDBEMMODULE;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFMOD) return VecWdbeVMaintable::TBLWDBEMMODULE;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFMTP) return VecWdbeVMaintable::TBLWDBEMMODULE;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFPIN) return VecWdbeVMaintable::TBLWDBEMPIN;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFPPH) return VecWdbeVMaintable::TBLWDBEMPERIPHERAL;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFPRC) return VecWdbeVMaintable::TBLWDBEMPROCESS;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFPRJ) return VecWdbeVMaintable::TBLWDBEMPROJECT;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFPRS) return VecWdbeVMaintable::TBLWDBEMPERSON;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFPRT) return VecWdbeVMaintable::TBLWDBEMPORT;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFRLS) return VecWdbeVMaintable::TBLWDBEMRELEASE;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFSES) return VecWdbeVMaintable::TBLWDBEMSESSION;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFSIG) return VecWdbeVMaintable::TBLWDBEMSIGNAL;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFSIL) return VecWdbeVMaintable::TBLWDBEMUNIT;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFSYS) return VecWdbeVMaintable::TBLWDBEMSYSTEM;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFTRG) return VecWdbeVMaintable::TBLWDBEMTARGET;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFUNI) return VecWdbeVMaintable::TBLWDBEMUNIT;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFUNT) return VecWdbeVMaintable::TBLWDBEMUNIT;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFUSG) return VecWdbeVMaintable::TBLWDBEMUSERGROUP;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFUSR) return VecWdbeVMaintable::TBLWDBEMUSER;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFVAR) return VecWdbeVMaintable::TBLWDBEMVARIABLE;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFVEC) return VecWdbeVMaintable::TBLWDBEMVECTOR;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFVER) return VecWdbeVMaintable::TBLWDBEMVERSION;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFVIT) return VecWdbeVMaintable::TBLWDBEMVECTORITEM;

	return VecWdbeVMaintable::VOID;
};

bool SessWdbe::hasActive(
			const uint ixWdbeVCard
		) {
	return((ixWdbeVCard == VecWdbeVCard::CRDWDBEVER) || (ixWdbeVCard == VecWdbeVCard::CRDWDBESYS) || (ixWdbeVCard == VecWdbeVCard::CRDWDBETRG) || (ixWdbeVCard == VecWdbeVCard::CRDWDBEUNT) || (ixWdbeVCard == VecWdbeVCard::CRDWDBERLS) || (ixWdbeVCard == VecWdbeVCard::CRDWDBECVR) || (ixWdbeVCard == VecWdbeVCard::CRDWDBEMOD) || (ixWdbeVCard == VecWdbeVCard::CRDWDBEVEC) || (ixWdbeVCard == VecWdbeVCard::CRDWDBEVIT) || (ixWdbeVCard == VecWdbeVCard::CRDWDBECMD) || (ixWdbeVCard == VecWdbeVCard::CRDWDBEERR) || (ixWdbeVCard == VecWdbeVCard::CRDWDBEPPH) || (ixWdbeVCard == VecWdbeVCard::CRDWDBEBNK) || (ixWdbeVCard == VecWdbeVCard::CRDWDBEPIN) || (ixWdbeVCard == VecWdbeVCard::CRDWDBEGEN) || (ixWdbeVCard == VecWdbeVCard::CRDWDBEPRT) || (ixWdbeVCard == VecWdbeVCard::CRDWDBESIG) || (ixWdbeVCard == VecWdbeVCard::CRDWDBEPRC) || (ixWdbeVCard == VecWdbeVCard::CRDWDBEFST) || (ixWdbeVCard == VecWdbeVCard::CRDWDBEVAR));
};

bool SessWdbe::hasGrpown(
			const uint ixWdbeVMaintable
		) {
	return((ixWdbeVMaintable == VecWdbeVMaintable::TBLWDBEMCOREPROJECT) || (ixWdbeVMaintable == VecWdbeVMaintable::TBLWDBEMCOREVERSION) || (ixWdbeVMaintable == VecWdbeVMaintable::TBLWDBEMFILE) || (ixWdbeVMaintable == VecWdbeVMaintable::TBLWDBEMPERSON) || (ixWdbeVMaintable == VecWdbeVMaintable::TBLWDBEMPROJECT) || (ixWdbeVMaintable == VecWdbeVMaintable::TBLWDBEMUSER) || (ixWdbeVMaintable == VecWdbeVMaintable::TBLWDBEMUSERGROUP) || (ixWdbeVMaintable == VecWdbeVMaintable::TBLWDBEMVERSION));
};

void SessWdbe::handleRequest(
			DbsWdbe* dbswdbe
			, ReqWdbe* req
		) {
	if (req->ixVBasetype == ReqWdbe::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {
			cout << "\tcreateCrdbnk" << endl;
			cout << "\tcreateCrdcmd" << endl;
			cout << "\tcreateCrdcpr" << endl;
			cout << "\tcreateCrdcvr" << endl;
			cout << "\tcreateCrderr" << endl;
			cout << "\tcreateCrdfam" << endl;
			cout << "\tcreateCrdfil" << endl;
			cout << "\tcreateCrdfst" << endl;
			cout << "\tcreateCrdgen" << endl;
			cout << "\tcreateCrdlib" << endl;
			cout << "\tcreateCrdmch" << endl;
			cout << "\tcreateCrdmod" << endl;
			cout << "\tcreateCrdmtp" << endl;
			cout << "\tcreateCrdpin" << endl;
			cout << "\tcreateCrdpph" << endl;
			cout << "\tcreateCrdprc" << endl;
			cout << "\tcreateCrdprj" << endl;
			cout << "\tcreateCrdprs" << endl;
			cout << "\tcreateCrdprt" << endl;
			cout << "\tcreateCrdrls" << endl;
			cout << "\tcreateCrdsig" << endl;
			cout << "\tcreateCrdsil" << endl;
			cout << "\tcreateCrdsys" << endl;
			cout << "\tcreateCrdtrg" << endl;
			cout << "\tcreateCrdunt" << endl;
			cout << "\tcreateCrdusg" << endl;
			cout << "\tcreateCrdusr" << endl;
			cout << "\tcreateCrdutl" << endl;
			cout << "\tcreateCrdvar" << endl;
			cout << "\tcreateCrdvec" << endl;
			cout << "\tcreateCrdver" << endl;
			cout << "\tcreateCrdvit" << endl;
			cout << "\teraseCrdbnk" << endl;
			cout << "\teraseCrdcmd" << endl;
			cout << "\teraseCrdcpr" << endl;
			cout << "\teraseCrdcvr" << endl;
			cout << "\teraseCrderr" << endl;
			cout << "\teraseCrdfam" << endl;
			cout << "\teraseCrdfil" << endl;
			cout << "\teraseCrdfst" << endl;
			cout << "\teraseCrdgen" << endl;
			cout << "\teraseCrdlib" << endl;
			cout << "\teraseCrdmch" << endl;
			cout << "\teraseCrdmod" << endl;
			cout << "\teraseCrdmtp" << endl;
			cout << "\teraseCrdpin" << endl;
			cout << "\teraseCrdpph" << endl;
			cout << "\teraseCrdprc" << endl;
			cout << "\teraseCrdprj" << endl;
			cout << "\teraseCrdprs" << endl;
			cout << "\teraseCrdprt" << endl;
			cout << "\teraseCrdrls" << endl;
			cout << "\teraseCrdsig" << endl;
			cout << "\teraseCrdsil" << endl;
			cout << "\teraseCrdsys" << endl;
			cout << "\teraseCrdtrg" << endl;
			cout << "\teraseCrdunt" << endl;
			cout << "\teraseCrdusg" << endl;
			cout << "\teraseCrdusr" << endl;
			cout << "\teraseCrdutl" << endl;
			cout << "\teraseCrdvar" << endl;
			cout << "\teraseCrdvec" << endl;
			cout << "\teraseCrdver" << endl;
			cout << "\teraseCrdvit" << endl;
		} else if (req->cmd == "createCrdbnk") {
			req->retain = handleCreateCrdbnk(dbswdbe);

		} else if (req->cmd == "createCrdcmd") {
			req->retain = handleCreateCrdcmd(dbswdbe);

		} else if (req->cmd == "createCrdcpr") {
			req->retain = handleCreateCrdcpr(dbswdbe);

		} else if (req->cmd == "createCrdcvr") {
			req->retain = handleCreateCrdcvr(dbswdbe);

		} else if (req->cmd == "createCrderr") {
			req->retain = handleCreateCrderr(dbswdbe);

		} else if (req->cmd == "createCrdfam") {
			req->retain = handleCreateCrdfam(dbswdbe);

		} else if (req->cmd == "createCrdfil") {
			req->retain = handleCreateCrdfil(dbswdbe);

		} else if (req->cmd == "createCrdfst") {
			req->retain = handleCreateCrdfst(dbswdbe);

		} else if (req->cmd == "createCrdgen") {
			req->retain = handleCreateCrdgen(dbswdbe);

		} else if (req->cmd == "createCrdlib") {
			req->retain = handleCreateCrdlib(dbswdbe);

		} else if (req->cmd == "createCrdmch") {
			req->retain = handleCreateCrdmch(dbswdbe);

		} else if (req->cmd == "createCrdmod") {
			req->retain = handleCreateCrdmod(dbswdbe);

		} else if (req->cmd == "createCrdmtp") {
			req->retain = handleCreateCrdmtp(dbswdbe);

		} else if (req->cmd == "createCrdpin") {
			req->retain = handleCreateCrdpin(dbswdbe);

		} else if (req->cmd == "createCrdpph") {
			req->retain = handleCreateCrdpph(dbswdbe);

		} else if (req->cmd == "createCrdprc") {
			req->retain = handleCreateCrdprc(dbswdbe);

		} else if (req->cmd == "createCrdprj") {
			req->retain = handleCreateCrdprj(dbswdbe);

		} else if (req->cmd == "createCrdprs") {
			req->retain = handleCreateCrdprs(dbswdbe);

		} else if (req->cmd == "createCrdprt") {
			req->retain = handleCreateCrdprt(dbswdbe);

		} else if (req->cmd == "createCrdrls") {
			req->retain = handleCreateCrdrls(dbswdbe);

		} else if (req->cmd == "createCrdsig") {
			req->retain = handleCreateCrdsig(dbswdbe);

		} else if (req->cmd == "createCrdsil") {
			req->retain = handleCreateCrdsil(dbswdbe);

		} else if (req->cmd == "createCrdsys") {
			req->retain = handleCreateCrdsys(dbswdbe);

		} else if (req->cmd == "createCrdtrg") {
			req->retain = handleCreateCrdtrg(dbswdbe);

		} else if (req->cmd == "createCrdunt") {
			req->retain = handleCreateCrdunt(dbswdbe);

		} else if (req->cmd == "createCrdusg") {
			req->retain = handleCreateCrdusg(dbswdbe);

		} else if (req->cmd == "createCrdusr") {
			req->retain = handleCreateCrdusr(dbswdbe);

		} else if (req->cmd == "createCrdutl") {
			req->retain = handleCreateCrdutl(dbswdbe);

		} else if (req->cmd == "createCrdvar") {
			req->retain = handleCreateCrdvar(dbswdbe);

		} else if (req->cmd == "createCrdvec") {
			req->retain = handleCreateCrdvec(dbswdbe);

		} else if (req->cmd == "createCrdver") {
			req->retain = handleCreateCrdver(dbswdbe);

		} else if (req->cmd == "createCrdvit") {
			req->retain = handleCreateCrdvit(dbswdbe);

		} else if (req->cmd == "eraseCrdbnk") {
			req->retain = handleEraseCrdbnk(dbswdbe);

		} else if (req->cmd == "eraseCrdcmd") {
			req->retain = handleEraseCrdcmd(dbswdbe);

		} else if (req->cmd == "eraseCrdcpr") {
			req->retain = handleEraseCrdcpr(dbswdbe);

		} else if (req->cmd == "eraseCrdcvr") {
			req->retain = handleEraseCrdcvr(dbswdbe);

		} else if (req->cmd == "eraseCrderr") {
			req->retain = handleEraseCrderr(dbswdbe);

		} else if (req->cmd == "eraseCrdfam") {
			req->retain = handleEraseCrdfam(dbswdbe);

		} else if (req->cmd == "eraseCrdfil") {
			req->retain = handleEraseCrdfil(dbswdbe);

		} else if (req->cmd == "eraseCrdfst") {
			req->retain = handleEraseCrdfst(dbswdbe);

		} else if (req->cmd == "eraseCrdgen") {
			req->retain = handleEraseCrdgen(dbswdbe);

		} else if (req->cmd == "eraseCrdlib") {
			req->retain = handleEraseCrdlib(dbswdbe);

		} else if (req->cmd == "eraseCrdmch") {
			req->retain = handleEraseCrdmch(dbswdbe);

		} else if (req->cmd == "eraseCrdmod") {
			req->retain = handleEraseCrdmod(dbswdbe);

		} else if (req->cmd == "eraseCrdmtp") {
			req->retain = handleEraseCrdmtp(dbswdbe);

		} else if (req->cmd == "eraseCrdpin") {
			req->retain = handleEraseCrdpin(dbswdbe);

		} else if (req->cmd == "eraseCrdpph") {
			req->retain = handleEraseCrdpph(dbswdbe);

		} else if (req->cmd == "eraseCrdprc") {
			req->retain = handleEraseCrdprc(dbswdbe);

		} else if (req->cmd == "eraseCrdprj") {
			req->retain = handleEraseCrdprj(dbswdbe);

		} else if (req->cmd == "eraseCrdprs") {
			req->retain = handleEraseCrdprs(dbswdbe);

		} else if (req->cmd == "eraseCrdprt") {
			req->retain = handleEraseCrdprt(dbswdbe);

		} else if (req->cmd == "eraseCrdrls") {
			req->retain = handleEraseCrdrls(dbswdbe);

		} else if (req->cmd == "eraseCrdsig") {
			req->retain = handleEraseCrdsig(dbswdbe);

		} else if (req->cmd == "eraseCrdsil") {
			req->retain = handleEraseCrdsil(dbswdbe);

		} else if (req->cmd == "eraseCrdsys") {
			req->retain = handleEraseCrdsys(dbswdbe);

		} else if (req->cmd == "eraseCrdtrg") {
			req->retain = handleEraseCrdtrg(dbswdbe);

		} else if (req->cmd == "eraseCrdunt") {
			req->retain = handleEraseCrdunt(dbswdbe);

		} else if (req->cmd == "eraseCrdusg") {
			req->retain = handleEraseCrdusg(dbswdbe);

		} else if (req->cmd == "eraseCrdusr") {
			req->retain = handleEraseCrdusr(dbswdbe);

		} else if (req->cmd == "eraseCrdutl") {
			req->retain = handleEraseCrdutl(dbswdbe);

		} else if (req->cmd == "eraseCrdvar") {
			req->retain = handleEraseCrdvar(dbswdbe);

		} else if (req->cmd == "eraseCrdvec") {
			req->retain = handleEraseCrdvec(dbswdbe);

		} else if (req->cmd == "eraseCrdver") {
			req->retain = handleEraseCrdver(dbswdbe);

		} else if (req->cmd == "eraseCrdvit") {
			req->retain = handleEraseCrdvit(dbswdbe);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::DPCHAPP) {
		if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEINIT) {
			handleDpchAppWdbeInit(dbswdbe, (DpchAppWdbeInit*) (req->dpchapp), &(req->dpcheng));

		};
	};
};

bool SessWdbe::handleCreateCrdbnk(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	CrdWdbeBnk* crdbnk = NULL;

	uint ixWdbeVPreset = evalCrdbnkActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdbnk = new CrdWdbeBnk(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref));
		crdbnks.push_back(crdbnk);
		cout << "\tjob reference: " << crdbnk->jref << endl;
		xchg->jrefCmd = crdbnk->jref;
	};

	return false;
	return retval;
};

bool SessWdbe::handleCreateCrdcmd(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	CrdWdbeCmd* crdcmd = NULL;

	uint ixWdbeVPreset = evalCrdcmdActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdcmd = new CrdWdbeCmd(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref));
		crdcmds.push_back(crdcmd);
		cout << "\tjob reference: " << crdcmd->jref << endl;
		xchg->jrefCmd = crdcmd->jref;
	};

	return false;
	return retval;
};

bool SessWdbe::handleCreateCrdcpr(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	CrdWdbeCpr* crdcpr = NULL;

	crdcpr = new CrdWdbeCpr(xchg, dbswdbe, jref, ixWdbeVLocale, 0);
	crdcprs.push_back(crdcpr);
	cout << "\tjob reference: " << crdcpr->jref << endl;
	xchg->jrefCmd = crdcpr->jref;

	return false;
	return retval;
};

bool SessWdbe::handleCreateCrdcvr(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	CrdWdbeCvr* crdcvr = NULL;

	uint ixWdbeVPreset = evalCrdcvrActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdcvr = new CrdWdbeCvr(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref));
		crdcvrs.push_back(crdcvr);
		cout << "\tjob reference: " << crdcvr->jref << endl;
		xchg->jrefCmd = crdcvr->jref;
	};

	return false;
	return retval;
};

bool SessWdbe::handleCreateCrderr(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	CrdWdbeErr* crderr = NULL;

	uint ixWdbeVPreset = evalCrderrActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crderr = new CrdWdbeErr(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref));
		crderrs.push_back(crderr);
		cout << "\tjob reference: " << crderr->jref << endl;
		xchg->jrefCmd = crderr->jref;
	};

	return false;
	return retval;
};

bool SessWdbe::handleCreateCrdfam(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	CrdWdbeFam* crdfam = NULL;

	crdfam = new CrdWdbeFam(xchg, dbswdbe, jref, ixWdbeVLocale, 0);
	crdfams.push_back(crdfam);
	cout << "\tjob reference: " << crdfam->jref << endl;
	xchg->jrefCmd = crdfam->jref;

	return false;
	return retval;
};

bool SessWdbe::handleCreateCrdfil(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	CrdWdbeFil* crdfil = NULL;

	crdfil = new CrdWdbeFil(xchg, dbswdbe, jref, ixWdbeVLocale, 0);
	crdfils.push_back(crdfil);
	cout << "\tjob reference: " << crdfil->jref << endl;
	xchg->jrefCmd = crdfil->jref;

	return false;
	return retval;
};

bool SessWdbe::handleCreateCrdfst(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	CrdWdbeFst* crdfst = NULL;

	uint ixWdbeVPreset = evalCrdfstActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdfst = new CrdWdbeFst(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref));
		crdfsts.push_back(crdfst);
		cout << "\tjob reference: " << crdfst->jref << endl;
		xchg->jrefCmd = crdfst->jref;
	};

	return false;
	return retval;
};

bool SessWdbe::handleCreateCrdgen(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	CrdWdbeGen* crdgen = NULL;

	uint ixWdbeVPreset = evalCrdgenActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdgen = new CrdWdbeGen(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref));
		crdgens.push_back(crdgen);
		cout << "\tjob reference: " << crdgen->jref << endl;
		xchg->jrefCmd = crdgen->jref;
	};

	return false;
	return retval;
};

bool SessWdbe::handleCreateCrdlib(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	CrdWdbeLib* crdlib = NULL;

	crdlib = new CrdWdbeLib(xchg, dbswdbe, jref, ixWdbeVLocale, 0);
	crdlibs.push_back(crdlib);
	cout << "\tjob reference: " << crdlib->jref << endl;
	xchg->jrefCmd = crdlib->jref;

	return false;
	return retval;
};

bool SessWdbe::handleCreateCrdmch(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	CrdWdbeMch* crdmch = NULL;

	crdmch = new CrdWdbeMch(xchg, dbswdbe, jref, ixWdbeVLocale, 0);
	crdmchs.push_back(crdmch);
	cout << "\tjob reference: " << crdmch->jref << endl;
	xchg->jrefCmd = crdmch->jref;

	return false;
	return retval;
};

bool SessWdbe::handleCreateCrdmod(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	CrdWdbeMod* crdmod = NULL;

	uint ixWdbeVPreset = evalCrdmodActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdmod = new CrdWdbeMod(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref));
		crdmods.push_back(crdmod);
		cout << "\tjob reference: " << crdmod->jref << endl;
		xchg->jrefCmd = crdmod->jref;
	};

	return false;
	return retval;
};

bool SessWdbe::handleCreateCrdmtp(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	CrdWdbeMtp* crdmtp = NULL;

	crdmtp = new CrdWdbeMtp(xchg, dbswdbe, jref, ixWdbeVLocale, 0);
	crdmtps.push_back(crdmtp);
	cout << "\tjob reference: " << crdmtp->jref << endl;
	xchg->jrefCmd = crdmtp->jref;

	return false;
	return retval;
};

bool SessWdbe::handleCreateCrdpin(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	CrdWdbePin* crdpin = NULL;

	uint ixWdbeVPreset = evalCrdpinActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdpin = new CrdWdbePin(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref));
		crdpins.push_back(crdpin);
		cout << "\tjob reference: " << crdpin->jref << endl;
		xchg->jrefCmd = crdpin->jref;
	};

	return false;
	return retval;
};

bool SessWdbe::handleCreateCrdpph(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	CrdWdbePph* crdpph = NULL;

	uint ixWdbeVPreset = evalCrdpphActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdpph = new CrdWdbePph(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref));
		crdpphs.push_back(crdpph);
		cout << "\tjob reference: " << crdpph->jref << endl;
		xchg->jrefCmd = crdpph->jref;
	};

	return false;
	return retval;
};

bool SessWdbe::handleCreateCrdprc(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	CrdWdbePrc* crdprc = NULL;

	uint ixWdbeVPreset = evalCrdprcActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdprc = new CrdWdbePrc(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref));
		crdprcs.push_back(crdprc);
		cout << "\tjob reference: " << crdprc->jref << endl;
		xchg->jrefCmd = crdprc->jref;
	};

	return false;
	return retval;
};

bool SessWdbe::handleCreateCrdprj(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	CrdWdbePrj* crdprj = NULL;

	crdprj = new CrdWdbePrj(xchg, dbswdbe, jref, ixWdbeVLocale, 0);
	crdprjs.push_back(crdprj);
	cout << "\tjob reference: " << crdprj->jref << endl;
	xchg->jrefCmd = crdprj->jref;

	return false;
	return retval;
};

bool SessWdbe::handleCreateCrdprs(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	CrdWdbePrs* crdprs = NULL;

	crdprs = new CrdWdbePrs(xchg, dbswdbe, jref, ixWdbeVLocale, 0);
	crdprss.push_back(crdprs);
	cout << "\tjob reference: " << crdprs->jref << endl;
	xchg->jrefCmd = crdprs->jref;

	return false;
	return retval;
};

bool SessWdbe::handleCreateCrdprt(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	CrdWdbePrt* crdprt = NULL;

	uint ixWdbeVPreset = evalCrdprtActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdprt = new CrdWdbePrt(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref));
		crdprts.push_back(crdprt);
		cout << "\tjob reference: " << crdprt->jref << endl;
		xchg->jrefCmd = crdprt->jref;
	};

	return false;
	return retval;
};

bool SessWdbe::handleCreateCrdrls(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	CrdWdbeRls* crdrls = NULL;

	uint ixWdbeVPreset = evalCrdrlsActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdrls = new CrdWdbeRls(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref));
		crdrlss.push_back(crdrls);
		cout << "\tjob reference: " << crdrls->jref << endl;
		xchg->jrefCmd = crdrls->jref;
	};

	return false;
	return retval;
};

bool SessWdbe::handleCreateCrdsig(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	CrdWdbeSig* crdsig = NULL;

	uint ixWdbeVPreset = evalCrdsigActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdsig = new CrdWdbeSig(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref));
		crdsigs.push_back(crdsig);
		cout << "\tjob reference: " << crdsig->jref << endl;
		xchg->jrefCmd = crdsig->jref;
	};

	return false;
	return retval;
};

bool SessWdbe::handleCreateCrdsil(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	CrdWdbeSil* crdsil = NULL;

	crdsil = new CrdWdbeSil(xchg, dbswdbe, jref, ixWdbeVLocale, 0);
	crdsils.push_back(crdsil);
	cout << "\tjob reference: " << crdsil->jref << endl;
	xchg->jrefCmd = crdsil->jref;

	return false;
	return retval;
};

bool SessWdbe::handleCreateCrdsys(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	CrdWdbeSys* crdsys = NULL;

	uint ixWdbeVPreset = evalCrdsysActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdsys = new CrdWdbeSys(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref));
		crdsyss.push_back(crdsys);
		cout << "\tjob reference: " << crdsys->jref << endl;
		xchg->jrefCmd = crdsys->jref;
	};

	return false;
	return retval;
};

bool SessWdbe::handleCreateCrdtrg(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	CrdWdbeTrg* crdtrg = NULL;

	uint ixWdbeVPreset = evalCrdtrgActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdtrg = new CrdWdbeTrg(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref));
		crdtrgs.push_back(crdtrg);
		cout << "\tjob reference: " << crdtrg->jref << endl;
		xchg->jrefCmd = crdtrg->jref;
	};

	return false;
	return retval;
};

bool SessWdbe::handleCreateCrdunt(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	CrdWdbeUnt* crdunt = NULL;

	uint ixWdbeVPreset = evalCrduntActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdunt = new CrdWdbeUnt(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref));
		crdunts.push_back(crdunt);
		cout << "\tjob reference: " << crdunt->jref << endl;
		xchg->jrefCmd = crdunt->jref;
	};

	return false;
	return retval;
};

bool SessWdbe::handleCreateCrdusg(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	CrdWdbeUsg* crdusg = NULL;

	crdusg = new CrdWdbeUsg(xchg, dbswdbe, jref, ixWdbeVLocale, 0);
	crdusgs.push_back(crdusg);
	cout << "\tjob reference: " << crdusg->jref << endl;
	xchg->jrefCmd = crdusg->jref;

	return false;
	return retval;
};

bool SessWdbe::handleCreateCrdusr(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	CrdWdbeUsr* crdusr = NULL;

	crdusr = new CrdWdbeUsr(xchg, dbswdbe, jref, ixWdbeVLocale, 0);
	crdusrs.push_back(crdusr);
	cout << "\tjob reference: " << crdusr->jref << endl;
	xchg->jrefCmd = crdusr->jref;

	return false;
	return retval;
};

bool SessWdbe::handleCreateCrdutl(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	CrdWdbeUtl* crdutl = NULL;

	crdutl = new CrdWdbeUtl(xchg, dbswdbe, jref, ixWdbeVLocale);
	crdutls.push_back(crdutl);
	cout << "\tjob reference: " << crdutl->jref << endl;
	xchg->jrefCmd = crdutl->jref;

	return false;
	return retval;
};

bool SessWdbe::handleCreateCrdvar(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	CrdWdbeVar* crdvar = NULL;

	uint ixWdbeVPreset = evalCrdvarActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdvar = new CrdWdbeVar(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref));
		crdvars.push_back(crdvar);
		cout << "\tjob reference: " << crdvar->jref << endl;
		xchg->jrefCmd = crdvar->jref;
	};

	return false;
	return retval;
};

bool SessWdbe::handleCreateCrdvec(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	CrdWdbeVec* crdvec = NULL;

	uint ixWdbeVPreset = evalCrdvecActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdvec = new CrdWdbeVec(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref));
		crdvecs.push_back(crdvec);
		cout << "\tjob reference: " << crdvec->jref << endl;
		xchg->jrefCmd = crdvec->jref;
	};

	return false;
	return retval;
};

bool SessWdbe::handleCreateCrdver(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	CrdWdbeVer* crdver = NULL;

	uint ixWdbeVPreset = evalCrdverActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdver = new CrdWdbeVer(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref));
		crdvers.push_back(crdver);
		cout << "\tjob reference: " << crdver->jref << endl;
		xchg->jrefCmd = crdver->jref;
	};

	return false;
	return retval;
};

bool SessWdbe::handleCreateCrdvit(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	CrdWdbeVit* crdvit = NULL;

	uint ixWdbeVPreset = evalCrdvitActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdvit = new CrdWdbeVit(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref));
		crdvits.push_back(crdvit);
		cout << "\tjob reference: " << crdvit->jref << endl;
		xchg->jrefCmd = crdvit->jref;
	};

	return false;
	return retval;
};

bool SessWdbe::handleEraseCrdbnk(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWdbeBnk* crdbnk = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdbnks.begin(); it != crdbnks.end();) {
		crdbnk = *it;
		if (crdbnk->jref == iinput) {
			it = crdbnks.erase(it);
			delete crdbnk;
			break;
		} else it++;
	};

	return retval;
};

bool SessWdbe::handleEraseCrdcmd(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWdbeCmd* crdcmd = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdcmds.begin(); it != crdcmds.end();) {
		crdcmd = *it;
		if (crdcmd->jref == iinput) {
			it = crdcmds.erase(it);
			delete crdcmd;
			break;
		} else it++;
	};

	return retval;
};

bool SessWdbe::handleEraseCrdcpr(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWdbeCpr* crdcpr = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdcprs.begin(); it != crdcprs.end();) {
		crdcpr = *it;
		if (crdcpr->jref == iinput) {
			it = crdcprs.erase(it);
			delete crdcpr;
			break;
		} else it++;
	};

	return retval;
};

bool SessWdbe::handleEraseCrdcvr(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWdbeCvr* crdcvr = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdcvrs.begin(); it != crdcvrs.end();) {
		crdcvr = *it;
		if (crdcvr->jref == iinput) {
			it = crdcvrs.erase(it);
			delete crdcvr;
			break;
		} else it++;
	};

	return retval;
};

bool SessWdbe::handleEraseCrderr(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWdbeErr* crderr = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crderrs.begin(); it != crderrs.end();) {
		crderr = *it;
		if (crderr->jref == iinput) {
			it = crderrs.erase(it);
			delete crderr;
			break;
		} else it++;
	};

	return retval;
};

bool SessWdbe::handleEraseCrdfam(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWdbeFam* crdfam = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdfams.begin(); it != crdfams.end();) {
		crdfam = *it;
		if (crdfam->jref == iinput) {
			it = crdfams.erase(it);
			delete crdfam;
			break;
		} else it++;
	};

	return retval;
};

bool SessWdbe::handleEraseCrdfil(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWdbeFil* crdfil = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdfils.begin(); it != crdfils.end();) {
		crdfil = *it;
		if (crdfil->jref == iinput) {
			it = crdfils.erase(it);
			delete crdfil;
			break;
		} else it++;
	};

	return retval;
};

bool SessWdbe::handleEraseCrdfst(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWdbeFst* crdfst = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdfsts.begin(); it != crdfsts.end();) {
		crdfst = *it;
		if (crdfst->jref == iinput) {
			it = crdfsts.erase(it);
			delete crdfst;
			break;
		} else it++;
	};

	return retval;
};

bool SessWdbe::handleEraseCrdgen(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWdbeGen* crdgen = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdgens.begin(); it != crdgens.end();) {
		crdgen = *it;
		if (crdgen->jref == iinput) {
			it = crdgens.erase(it);
			delete crdgen;
			break;
		} else it++;
	};

	return retval;
};

bool SessWdbe::handleEraseCrdlib(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWdbeLib* crdlib = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdlibs.begin(); it != crdlibs.end();) {
		crdlib = *it;
		if (crdlib->jref == iinput) {
			it = crdlibs.erase(it);
			delete crdlib;
			break;
		} else it++;
	};

	return retval;
};

bool SessWdbe::handleEraseCrdmch(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWdbeMch* crdmch = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdmchs.begin(); it != crdmchs.end();) {
		crdmch = *it;
		if (crdmch->jref == iinput) {
			it = crdmchs.erase(it);
			delete crdmch;
			break;
		} else it++;
	};

	return retval;
};

bool SessWdbe::handleEraseCrdmod(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWdbeMod* crdmod = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdmods.begin(); it != crdmods.end();) {
		crdmod = *it;
		if (crdmod->jref == iinput) {
			it = crdmods.erase(it);
			delete crdmod;
			break;
		} else it++;
	};

	return retval;
};

bool SessWdbe::handleEraseCrdmtp(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWdbeMtp* crdmtp = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdmtps.begin(); it != crdmtps.end();) {
		crdmtp = *it;
		if (crdmtp->jref == iinput) {
			it = crdmtps.erase(it);
			delete crdmtp;
			break;
		} else it++;
	};

	return retval;
};

bool SessWdbe::handleEraseCrdpin(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWdbePin* crdpin = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdpins.begin(); it != crdpins.end();) {
		crdpin = *it;
		if (crdpin->jref == iinput) {
			it = crdpins.erase(it);
			delete crdpin;
			break;
		} else it++;
	};

	return retval;
};

bool SessWdbe::handleEraseCrdpph(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWdbePph* crdpph = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdpphs.begin(); it != crdpphs.end();) {
		crdpph = *it;
		if (crdpph->jref == iinput) {
			it = crdpphs.erase(it);
			delete crdpph;
			break;
		} else it++;
	};

	return retval;
};

bool SessWdbe::handleEraseCrdprc(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWdbePrc* crdprc = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdprcs.begin(); it != crdprcs.end();) {
		crdprc = *it;
		if (crdprc->jref == iinput) {
			it = crdprcs.erase(it);
			delete crdprc;
			break;
		} else it++;
	};

	return retval;
};

bool SessWdbe::handleEraseCrdprj(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWdbePrj* crdprj = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdprjs.begin(); it != crdprjs.end();) {
		crdprj = *it;
		if (crdprj->jref == iinput) {
			it = crdprjs.erase(it);
			delete crdprj;
			break;
		} else it++;
	};

	return retval;
};

bool SessWdbe::handleEraseCrdprs(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWdbePrs* crdprs = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdprss.begin(); it != crdprss.end();) {
		crdprs = *it;
		if (crdprs->jref == iinput) {
			it = crdprss.erase(it);
			delete crdprs;
			break;
		} else it++;
	};

	return retval;
};

bool SessWdbe::handleEraseCrdprt(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWdbePrt* crdprt = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdprts.begin(); it != crdprts.end();) {
		crdprt = *it;
		if (crdprt->jref == iinput) {
			it = crdprts.erase(it);
			delete crdprt;
			break;
		} else it++;
	};

	return retval;
};

bool SessWdbe::handleEraseCrdrls(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWdbeRls* crdrls = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdrlss.begin(); it != crdrlss.end();) {
		crdrls = *it;
		if (crdrls->jref == iinput) {
			it = crdrlss.erase(it);
			delete crdrls;
			break;
		} else it++;
	};

	return retval;
};

bool SessWdbe::handleEraseCrdsig(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWdbeSig* crdsig = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdsigs.begin(); it != crdsigs.end();) {
		crdsig = *it;
		if (crdsig->jref == iinput) {
			it = crdsigs.erase(it);
			delete crdsig;
			break;
		} else it++;
	};

	return retval;
};

bool SessWdbe::handleEraseCrdsil(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWdbeSil* crdsil = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdsils.begin(); it != crdsils.end();) {
		crdsil = *it;
		if (crdsil->jref == iinput) {
			it = crdsils.erase(it);
			delete crdsil;
			break;
		} else it++;
	};

	return retval;
};

bool SessWdbe::handleEraseCrdsys(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWdbeSys* crdsys = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdsyss.begin(); it != crdsyss.end();) {
		crdsys = *it;
		if (crdsys->jref == iinput) {
			it = crdsyss.erase(it);
			delete crdsys;
			break;
		} else it++;
	};

	return retval;
};

bool SessWdbe::handleEraseCrdtrg(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWdbeTrg* crdtrg = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdtrgs.begin(); it != crdtrgs.end();) {
		crdtrg = *it;
		if (crdtrg->jref == iinput) {
			it = crdtrgs.erase(it);
			delete crdtrg;
			break;
		} else it++;
	};

	return retval;
};

bool SessWdbe::handleEraseCrdunt(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWdbeUnt* crdunt = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdunts.begin(); it != crdunts.end();) {
		crdunt = *it;
		if (crdunt->jref == iinput) {
			it = crdunts.erase(it);
			delete crdunt;
			break;
		} else it++;
	};

	return retval;
};

bool SessWdbe::handleEraseCrdusg(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWdbeUsg* crdusg = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdusgs.begin(); it != crdusgs.end();) {
		crdusg = *it;
		if (crdusg->jref == iinput) {
			it = crdusgs.erase(it);
			delete crdusg;
			break;
		} else it++;
	};

	return retval;
};

bool SessWdbe::handleEraseCrdusr(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWdbeUsr* crdusr = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdusrs.begin(); it != crdusrs.end();) {
		crdusr = *it;
		if (crdusr->jref == iinput) {
			it = crdusrs.erase(it);
			delete crdusr;
			break;
		} else it++;
	};

	return retval;
};

bool SessWdbe::handleEraseCrdutl(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWdbeUtl* crdutl = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdutls.begin(); it != crdutls.end();) {
		crdutl = *it;
		if (crdutl->jref == iinput) {
			it = crdutls.erase(it);
			delete crdutl;
			break;
		} else it++;
	};

	return retval;
};

bool SessWdbe::handleEraseCrdvar(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWdbeVar* crdvar = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdvars.begin(); it != crdvars.end();) {
		crdvar = *it;
		if (crdvar->jref == iinput) {
			it = crdvars.erase(it);
			delete crdvar;
			break;
		} else it++;
	};

	return retval;
};

bool SessWdbe::handleEraseCrdvec(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWdbeVec* crdvec = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdvecs.begin(); it != crdvecs.end();) {
		crdvec = *it;
		if (crdvec->jref == iinput) {
			it = crdvecs.erase(it);
			delete crdvec;
			break;
		} else it++;
	};

	return retval;
};

bool SessWdbe::handleEraseCrdver(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWdbeVer* crdver = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdvers.begin(); it != crdvers.end();) {
		crdver = *it;
		if (crdver->jref == iinput) {
			it = crdvers.erase(it);
			delete crdver;
			break;
		} else it++;
	};

	return retval;
};

bool SessWdbe::handleEraseCrdvit(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWdbeVit* crdvit = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdvits.begin(); it != crdvits.end();) {
		crdvit = *it;
		if (crdvit->jref == iinput) {
			it = crdvits.erase(it);
			delete crdvit;
			break;
		} else it++;
	};

	return retval;
};

void SessWdbe::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	Feed feedFEnsSec("FeedFEnsSec");

	// resume session
	xchg->removePreset(VecWdbeVPreset::PREWDBESUSPSESS, jref);

	for (auto it = crdusgs.begin(); it != crdusgs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWdbeUsg");
	for (auto it = crdusrs.begin(); it != crdusrs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWdbeUsr");
	for (auto it = crdprss.begin(); it != crdprss.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWdbePrs");
	for (auto it = crdfils.begin(); it != crdfils.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWdbeFil");
	for (auto it = crdmchs.begin(); it != crdmchs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWdbeMch");
	for (auto it = crdlibs.begin(); it != crdlibs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWdbeLib");
	for (auto it = crdfams.begin(); it != crdfams.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWdbeFam");
	for (auto it = crdsils.begin(); it != crdsils.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWdbeSil");
	for (auto it = crdmtps.begin(); it != crdmtps.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWdbeMtp");
	for (auto it = crdprjs.begin(); it != crdprjs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWdbePrj");
	for (auto it = crdvers.begin(); it != crdvers.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWdbeVer");
	for (auto it = crdsyss.begin(); it != crdsyss.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWdbeSys");
	for (auto it = crdtrgs.begin(); it != crdtrgs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWdbeTrg");
	for (auto it = crdunts.begin(); it != crdunts.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWdbeUnt");
	for (auto it = crdrlss.begin(); it != crdrlss.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWdbeRls");
	for (auto it = crdcprs.begin(); it != crdcprs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWdbeCpr");
	for (auto it = crdcvrs.begin(); it != crdcvrs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWdbeCvr");
	for (auto it = crdmods.begin(); it != crdmods.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWdbeMod");
	for (auto it = crdvecs.begin(); it != crdvecs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWdbeVec");
	for (auto it = crdvits.begin(); it != crdvits.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWdbeVit");
	for (auto it = crdcmds.begin(); it != crdcmds.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWdbeCmd");
	for (auto it = crderrs.begin(); it != crderrs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWdbeErr");
	for (auto it = crdpphs.begin(); it != crdpphs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWdbePph");
	for (auto it = crdbnks.begin(); it != crdbnks.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWdbeBnk");
	for (auto it = crdpins.begin(); it != crdpins.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWdbePin");
	for (auto it = crdgens.begin(); it != crdgens.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWdbeGen");
	for (auto it = crdprts.begin(); it != crdprts.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWdbePrt");
	for (auto it = crdsigs.begin(); it != crdsigs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWdbeSig");
	for (auto it = crdprcs.begin(); it != crdprcs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWdbePrc");
	for (auto it = crdfsts.begin(); it != crdfsts.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWdbeFst");
	for (auto it = crdvars.begin(); it != crdvars.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWdbeVar");
	for (auto it = crdutls.begin(); it != crdutls.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWdbeUtl");

	*dpcheng = new DpchEngData(jref, &feedFEnsSec, &statshr, {DpchEngData::ALL});
};

void SessWdbe::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBECRDACTIVE) {
		call->abort = handleCallWdbeCrdActive(dbswdbe, call->jref, call->argInv.ix, call->argRet.ix);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBECRDCLOSE) {
		call->abort = handleCallWdbeCrdClose(dbswdbe, call->jref, call->argInv.ix);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBECRDOPEN) {
		call->abort = handleCallWdbeCrdOpen(dbswdbe, call->jref, call->argInv.ix, call->argInv.ref, call->argInv.sref, call->argInv.intval, call->argRet.ref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBELOG) {
		call->abort = handleCallWdbeLog(dbswdbe, call->jref, call->argInv.ix, call->argInv.ref, call->argInv.sref, call->argInv.intval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBERECACCESS) {
		call->abort = handleCallWdbeRecaccess(dbswdbe, call->jref, call->argInv.ix, call->argInv.ref, call->argRet.ix);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEREFPRESET) {
		call->abort = handleCallWdbeRefPreSet(dbswdbe, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool SessWdbe::handleCallWdbeCrdActive(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, uint& ixRet
		) {
	bool retval = false;
	ixRet = checkCrdActive(ixInv);
	return retval;
};

bool SessWdbe::handleCallWdbeCrdClose(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
		) {
	bool retval = false;
	// delete only if card is not part of a suspended session
	if (xchg->getBoolvalPreset(VecWdbeVPreset::PREWDBESUSPSESS, jrefTrig)) return retval;

	ubigint jrefNotif = xchg->getRefPreset(VecWdbeVPreset::PREWDBEJREFNOTIFY, jref);
	if (jrefNotif == jrefTrig) xchg->removePreset(VecWdbeVPreset::PREWDBEJREFNOTIFY, jref);

	if (ixInv == VecWdbeVCard::CRDWDBENAV) {
		if (crdnav) {
			delete crdnav;
			crdnav = NULL;
		};

	} else if (ixInv == VecWdbeVCard::CRDWDBEUSG) {
		CrdWdbeUsg* crdusg = NULL;

		for (auto it = crdusgs.begin(); it != crdusgs.end();) {
			crdusg = *it;
			if (crdusg->jref == jrefTrig) {
				it = crdusgs.erase(it);
				delete crdusg;
				break;
			} else it++;
		};
	} else if (ixInv == VecWdbeVCard::CRDWDBEUSR) {
		CrdWdbeUsr* crdusr = NULL;

		for (auto it = crdusrs.begin(); it != crdusrs.end();) {
			crdusr = *it;
			if (crdusr->jref == jrefTrig) {
				it = crdusrs.erase(it);
				delete crdusr;
				break;
			} else it++;
		};
	} else if (ixInv == VecWdbeVCard::CRDWDBEPRS) {
		CrdWdbePrs* crdprs = NULL;

		for (auto it = crdprss.begin(); it != crdprss.end();) {
			crdprs = *it;
			if (crdprs->jref == jrefTrig) {
				it = crdprss.erase(it);
				delete crdprs;
				break;
			} else it++;
		};
	} else if (ixInv == VecWdbeVCard::CRDWDBEFIL) {
		CrdWdbeFil* crdfil = NULL;

		for (auto it = crdfils.begin(); it != crdfils.end();) {
			crdfil = *it;
			if (crdfil->jref == jrefTrig) {
				it = crdfils.erase(it);
				delete crdfil;
				break;
			} else it++;
		};
	} else if (ixInv == VecWdbeVCard::CRDWDBEMCH) {
		CrdWdbeMch* crdmch = NULL;

		for (auto it = crdmchs.begin(); it != crdmchs.end();) {
			crdmch = *it;
			if (crdmch->jref == jrefTrig) {
				it = crdmchs.erase(it);
				delete crdmch;
				break;
			} else it++;
		};
	} else if (ixInv == VecWdbeVCard::CRDWDBELIB) {
		CrdWdbeLib* crdlib = NULL;

		for (auto it = crdlibs.begin(); it != crdlibs.end();) {
			crdlib = *it;
			if (crdlib->jref == jrefTrig) {
				it = crdlibs.erase(it);
				delete crdlib;
				break;
			} else it++;
		};
	} else if (ixInv == VecWdbeVCard::CRDWDBEFAM) {
		CrdWdbeFam* crdfam = NULL;

		for (auto it = crdfams.begin(); it != crdfams.end();) {
			crdfam = *it;
			if (crdfam->jref == jrefTrig) {
				it = crdfams.erase(it);
				delete crdfam;
				break;
			} else it++;
		};
	} else if (ixInv == VecWdbeVCard::CRDWDBESIL) {
		CrdWdbeSil* crdsil = NULL;

		for (auto it = crdsils.begin(); it != crdsils.end();) {
			crdsil = *it;
			if (crdsil->jref == jrefTrig) {
				it = crdsils.erase(it);
				delete crdsil;
				break;
			} else it++;
		};
	} else if (ixInv == VecWdbeVCard::CRDWDBEMTP) {
		CrdWdbeMtp* crdmtp = NULL;

		for (auto it = crdmtps.begin(); it != crdmtps.end();) {
			crdmtp = *it;
			if (crdmtp->jref == jrefTrig) {
				it = crdmtps.erase(it);
				delete crdmtp;
				break;
			} else it++;
		};
	} else if (ixInv == VecWdbeVCard::CRDWDBEPRJ) {
		CrdWdbePrj* crdprj = NULL;

		for (auto it = crdprjs.begin(); it != crdprjs.end();) {
			crdprj = *it;
			if (crdprj->jref == jrefTrig) {
				it = crdprjs.erase(it);
				delete crdprj;
				break;
			} else it++;
		};
	} else if (ixInv == VecWdbeVCard::CRDWDBEVER) {
		CrdWdbeVer* crdver = NULL;

		for (auto it = crdvers.begin(); it != crdvers.end();) {
			crdver = *it;
			if (crdver->jref == jrefTrig) {
				it = crdvers.erase(it);
				delete crdver;
				break;
			} else it++;
		};
	} else if (ixInv == VecWdbeVCard::CRDWDBESYS) {
		CrdWdbeSys* crdsys = NULL;

		for (auto it = crdsyss.begin(); it != crdsyss.end();) {
			crdsys = *it;
			if (crdsys->jref == jrefTrig) {
				it = crdsyss.erase(it);
				delete crdsys;
				break;
			} else it++;
		};
	} else if (ixInv == VecWdbeVCard::CRDWDBETRG) {
		CrdWdbeTrg* crdtrg = NULL;

		for (auto it = crdtrgs.begin(); it != crdtrgs.end();) {
			crdtrg = *it;
			if (crdtrg->jref == jrefTrig) {
				it = crdtrgs.erase(it);
				delete crdtrg;
				break;
			} else it++;
		};
	} else if (ixInv == VecWdbeVCard::CRDWDBEUNT) {
		CrdWdbeUnt* crdunt = NULL;

		for (auto it = crdunts.begin(); it != crdunts.end();) {
			crdunt = *it;
			if (crdunt->jref == jrefTrig) {
				it = crdunts.erase(it);
				delete crdunt;
				break;
			} else it++;
		};
	} else if (ixInv == VecWdbeVCard::CRDWDBERLS) {
		CrdWdbeRls* crdrls = NULL;

		for (auto it = crdrlss.begin(); it != crdrlss.end();) {
			crdrls = *it;
			if (crdrls->jref == jrefTrig) {
				it = crdrlss.erase(it);
				delete crdrls;
				break;
			} else it++;
		};
	} else if (ixInv == VecWdbeVCard::CRDWDBECPR) {
		CrdWdbeCpr* crdcpr = NULL;

		for (auto it = crdcprs.begin(); it != crdcprs.end();) {
			crdcpr = *it;
			if (crdcpr->jref == jrefTrig) {
				it = crdcprs.erase(it);
				delete crdcpr;
				break;
			} else it++;
		};
	} else if (ixInv == VecWdbeVCard::CRDWDBECVR) {
		CrdWdbeCvr* crdcvr = NULL;

		for (auto it = crdcvrs.begin(); it != crdcvrs.end();) {
			crdcvr = *it;
			if (crdcvr->jref == jrefTrig) {
				it = crdcvrs.erase(it);
				delete crdcvr;
				break;
			} else it++;
		};
	} else if (ixInv == VecWdbeVCard::CRDWDBEMOD) {
		CrdWdbeMod* crdmod = NULL;

		for (auto it = crdmods.begin(); it != crdmods.end();) {
			crdmod = *it;
			if (crdmod->jref == jrefTrig) {
				it = crdmods.erase(it);
				delete crdmod;
				break;
			} else it++;
		};
	} else if (ixInv == VecWdbeVCard::CRDWDBEVEC) {
		CrdWdbeVec* crdvec = NULL;

		for (auto it = crdvecs.begin(); it != crdvecs.end();) {
			crdvec = *it;
			if (crdvec->jref == jrefTrig) {
				it = crdvecs.erase(it);
				delete crdvec;
				break;
			} else it++;
		};
	} else if (ixInv == VecWdbeVCard::CRDWDBEVIT) {
		CrdWdbeVit* crdvit = NULL;

		for (auto it = crdvits.begin(); it != crdvits.end();) {
			crdvit = *it;
			if (crdvit->jref == jrefTrig) {
				it = crdvits.erase(it);
				delete crdvit;
				break;
			} else it++;
		};
	} else if (ixInv == VecWdbeVCard::CRDWDBECMD) {
		CrdWdbeCmd* crdcmd = NULL;

		for (auto it = crdcmds.begin(); it != crdcmds.end();) {
			crdcmd = *it;
			if (crdcmd->jref == jrefTrig) {
				it = crdcmds.erase(it);
				delete crdcmd;
				break;
			} else it++;
		};
	} else if (ixInv == VecWdbeVCard::CRDWDBEERR) {
		CrdWdbeErr* crderr = NULL;

		for (auto it = crderrs.begin(); it != crderrs.end();) {
			crderr = *it;
			if (crderr->jref == jrefTrig) {
				it = crderrs.erase(it);
				delete crderr;
				break;
			} else it++;
		};
	} else if (ixInv == VecWdbeVCard::CRDWDBEPPH) {
		CrdWdbePph* crdpph = NULL;

		for (auto it = crdpphs.begin(); it != crdpphs.end();) {
			crdpph = *it;
			if (crdpph->jref == jrefTrig) {
				it = crdpphs.erase(it);
				delete crdpph;
				break;
			} else it++;
		};
	} else if (ixInv == VecWdbeVCard::CRDWDBEBNK) {
		CrdWdbeBnk* crdbnk = NULL;

		for (auto it = crdbnks.begin(); it != crdbnks.end();) {
			crdbnk = *it;
			if (crdbnk->jref == jrefTrig) {
				it = crdbnks.erase(it);
				delete crdbnk;
				break;
			} else it++;
		};
	} else if (ixInv == VecWdbeVCard::CRDWDBEPIN) {
		CrdWdbePin* crdpin = NULL;

		for (auto it = crdpins.begin(); it != crdpins.end();) {
			crdpin = *it;
			if (crdpin->jref == jrefTrig) {
				it = crdpins.erase(it);
				delete crdpin;
				break;
			} else it++;
		};
	} else if (ixInv == VecWdbeVCard::CRDWDBEGEN) {
		CrdWdbeGen* crdgen = NULL;

		for (auto it = crdgens.begin(); it != crdgens.end();) {
			crdgen = *it;
			if (crdgen->jref == jrefTrig) {
				it = crdgens.erase(it);
				delete crdgen;
				break;
			} else it++;
		};
	} else if (ixInv == VecWdbeVCard::CRDWDBEPRT) {
		CrdWdbePrt* crdprt = NULL;

		for (auto it = crdprts.begin(); it != crdprts.end();) {
			crdprt = *it;
			if (crdprt->jref == jrefTrig) {
				it = crdprts.erase(it);
				delete crdprt;
				break;
			} else it++;
		};
	} else if (ixInv == VecWdbeVCard::CRDWDBESIG) {
		CrdWdbeSig* crdsig = NULL;

		for (auto it = crdsigs.begin(); it != crdsigs.end();) {
			crdsig = *it;
			if (crdsig->jref == jrefTrig) {
				it = crdsigs.erase(it);
				delete crdsig;
				break;
			} else it++;
		};
	} else if (ixInv == VecWdbeVCard::CRDWDBEPRC) {
		CrdWdbePrc* crdprc = NULL;

		for (auto it = crdprcs.begin(); it != crdprcs.end();) {
			crdprc = *it;
			if (crdprc->jref == jrefTrig) {
				it = crdprcs.erase(it);
				delete crdprc;
				break;
			} else it++;
		};
	} else if (ixInv == VecWdbeVCard::CRDWDBEFST) {
		CrdWdbeFst* crdfst = NULL;

		for (auto it = crdfsts.begin(); it != crdfsts.end();) {
			crdfst = *it;
			if (crdfst->jref == jrefTrig) {
				it = crdfsts.erase(it);
				delete crdfst;
				break;
			} else it++;
		};
	} else if (ixInv == VecWdbeVCard::CRDWDBEVAR) {
		CrdWdbeVar* crdvar = NULL;

		for (auto it = crdvars.begin(); it != crdvars.end();) {
			crdvar = *it;
			if (crdvar->jref == jrefTrig) {
				it = crdvars.erase(it);
				delete crdvar;
				break;
			} else it++;
		};
	} else if (ixInv == VecWdbeVCard::CRDWDBEUTL) {
		CrdWdbeUtl* crdutl = NULL;

		for (auto it = crdutls.begin(); it != crdutls.end();) {
			crdutl = *it;
			if (crdutl->jref == jrefTrig) {
				it = crdutls.erase(it);
				delete crdutl;
				break;
			} else it++;
		};
	};
	return retval;
};

bool SessWdbe::handleCallWdbeCrdOpen(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
			, const int intvalInv
			, ubigint& refRet
		) {
	bool retval = false;
	bool denied = false;

	uint ixWdbeVCard = VecWdbeVCard::getIx(srefInv);

	ubigint ref = (ubigint) intvalInv;
	if (intvalInv == -1) {
		ref = 0;
		ref--;
	};

	uint ixWdbeVPreset;
	ubigint preUref = 0;

	uint ixWdbeWAccess;
	uint ixWdbeVRecaccess;

	if (hasActive(ixWdbeVCard)) {
		if (ixInv == 0) {
			ixWdbeVPreset = checkCrdActive(ixWdbeVCard);
			if (ixWdbeVPreset == 0) {
				denied = true;
			} else {
				preUref = xchg->getRefPreset(ixWdbeVPreset, jref);
			};

		} else {
			ixWdbeVPreset = ixInv;
			preUref = refInv;
		};
	};

	if (!denied) {
		ixWdbeWAccess = checkCrdaccess(ixWdbeVCard);
		denied = (ixWdbeWAccess == 0);
	};

	if (!denied) {
		if (intvalInv == -1) {
			denied = (((ixWdbeWAccess & VecWdbeWAccess::EDIT) == 0) || ((ixWdbeWAccess & VecWdbeWAccess::EXEC) == 0));
		} else if (intvalInv > 0) {
			ixWdbeVRecaccess = checkRecaccess(dbswdbe, ixWdbeVCard, intvalInv);
			denied = (ixWdbeVRecaccess == VecWdbeVRecaccess::NONE);
		};
	};

	if (denied) {
		refRet = 0;

	} else {
		if (ixWdbeVCard == VecWdbeVCard::CRDWDBENAV) {
		} else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEUSG) {
			CrdWdbeUsg* crdusg = NULL;

			crdusg = new CrdWdbeUsg(xchg, dbswdbe, jref, ixWdbeVLocale, ref);
			crdusgs.push_back(crdusg);

			refRet = crdusg->jref;

		} else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEUSR) {
			CrdWdbeUsr* crdusr = NULL;

			crdusr = new CrdWdbeUsr(xchg, dbswdbe, jref, ixWdbeVLocale, ref);
			crdusrs.push_back(crdusr);

			refRet = crdusr->jref;

		} else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPRS) {
			CrdWdbePrs* crdprs = NULL;

			crdprs = new CrdWdbePrs(xchg, dbswdbe, jref, ixWdbeVLocale, ref);
			crdprss.push_back(crdprs);

			refRet = crdprs->jref;

		} else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEFIL) {
			CrdWdbeFil* crdfil = NULL;

			crdfil = new CrdWdbeFil(xchg, dbswdbe, jref, ixWdbeVLocale, ref);
			crdfils.push_back(crdfil);

			refRet = crdfil->jref;

		} else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEMCH) {
			CrdWdbeMch* crdmch = NULL;

			crdmch = new CrdWdbeMch(xchg, dbswdbe, jref, ixWdbeVLocale, ref);
			crdmchs.push_back(crdmch);

			refRet = crdmch->jref;

		} else if (ixWdbeVCard == VecWdbeVCard::CRDWDBELIB) {
			CrdWdbeLib* crdlib = NULL;

			crdlib = new CrdWdbeLib(xchg, dbswdbe, jref, ixWdbeVLocale, ref);
			crdlibs.push_back(crdlib);

			refRet = crdlib->jref;

		} else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEFAM) {
			CrdWdbeFam* crdfam = NULL;

			crdfam = new CrdWdbeFam(xchg, dbswdbe, jref, ixWdbeVLocale, ref);
			crdfams.push_back(crdfam);

			refRet = crdfam->jref;

		} else if (ixWdbeVCard == VecWdbeVCard::CRDWDBESIL) {
			CrdWdbeSil* crdsil = NULL;

			crdsil = new CrdWdbeSil(xchg, dbswdbe, jref, ixWdbeVLocale, ref);
			crdsils.push_back(crdsil);

			refRet = crdsil->jref;

		} else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEMTP) {
			CrdWdbeMtp* crdmtp = NULL;

			crdmtp = new CrdWdbeMtp(xchg, dbswdbe, jref, ixWdbeVLocale, ref);
			crdmtps.push_back(crdmtp);

			refRet = crdmtp->jref;

		} else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPRJ) {
			CrdWdbePrj* crdprj = NULL;

			crdprj = new CrdWdbePrj(xchg, dbswdbe, jref, ixWdbeVLocale, ref);
			crdprjs.push_back(crdprj);

			refRet = crdprj->jref;

		} else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEVER) {
			CrdWdbeVer* crdver = NULL;

			crdver = new CrdWdbeVer(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref);
			crdvers.push_back(crdver);

			refRet = crdver->jref;

		} else if (ixWdbeVCard == VecWdbeVCard::CRDWDBESYS) {
			CrdWdbeSys* crdsys = NULL;

			crdsys = new CrdWdbeSys(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref);
			crdsyss.push_back(crdsys);

			refRet = crdsys->jref;

		} else if (ixWdbeVCard == VecWdbeVCard::CRDWDBETRG) {
			CrdWdbeTrg* crdtrg = NULL;

			crdtrg = new CrdWdbeTrg(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref);
			crdtrgs.push_back(crdtrg);

			refRet = crdtrg->jref;

		} else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEUNT) {
			CrdWdbeUnt* crdunt = NULL;

			crdunt = new CrdWdbeUnt(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref);
			crdunts.push_back(crdunt);

			refRet = crdunt->jref;

		} else if (ixWdbeVCard == VecWdbeVCard::CRDWDBERLS) {
			CrdWdbeRls* crdrls = NULL;

			crdrls = new CrdWdbeRls(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref);
			crdrlss.push_back(crdrls);

			refRet = crdrls->jref;

		} else if (ixWdbeVCard == VecWdbeVCard::CRDWDBECPR) {
			CrdWdbeCpr* crdcpr = NULL;

			crdcpr = new CrdWdbeCpr(xchg, dbswdbe, jref, ixWdbeVLocale, ref);
			crdcprs.push_back(crdcpr);

			refRet = crdcpr->jref;

		} else if (ixWdbeVCard == VecWdbeVCard::CRDWDBECVR) {
			CrdWdbeCvr* crdcvr = NULL;

			crdcvr = new CrdWdbeCvr(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref);
			crdcvrs.push_back(crdcvr);

			refRet = crdcvr->jref;

		} else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEMOD) {
			CrdWdbeMod* crdmod = NULL;

			crdmod = new CrdWdbeMod(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref);
			crdmods.push_back(crdmod);

			refRet = crdmod->jref;

		} else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEVEC) {
			CrdWdbeVec* crdvec = NULL;

			crdvec = new CrdWdbeVec(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref);
			crdvecs.push_back(crdvec);

			refRet = crdvec->jref;

		} else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEVIT) {
			CrdWdbeVit* crdvit = NULL;

			crdvit = new CrdWdbeVit(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref);
			crdvits.push_back(crdvit);

			refRet = crdvit->jref;

		} else if (ixWdbeVCard == VecWdbeVCard::CRDWDBECMD) {
			CrdWdbeCmd* crdcmd = NULL;

			crdcmd = new CrdWdbeCmd(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref);
			crdcmds.push_back(crdcmd);

			refRet = crdcmd->jref;

		} else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEERR) {
			CrdWdbeErr* crderr = NULL;

			crderr = new CrdWdbeErr(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref);
			crderrs.push_back(crderr);

			refRet = crderr->jref;

		} else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPPH) {
			CrdWdbePph* crdpph = NULL;

			crdpph = new CrdWdbePph(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref);
			crdpphs.push_back(crdpph);

			refRet = crdpph->jref;

		} else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEBNK) {
			CrdWdbeBnk* crdbnk = NULL;

			crdbnk = new CrdWdbeBnk(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref);
			crdbnks.push_back(crdbnk);

			refRet = crdbnk->jref;

		} else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPIN) {
			CrdWdbePin* crdpin = NULL;

			crdpin = new CrdWdbePin(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref);
			crdpins.push_back(crdpin);

			refRet = crdpin->jref;

		} else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEGEN) {
			CrdWdbeGen* crdgen = NULL;

			crdgen = new CrdWdbeGen(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref);
			crdgens.push_back(crdgen);

			refRet = crdgen->jref;

		} else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPRT) {
			CrdWdbePrt* crdprt = NULL;

			crdprt = new CrdWdbePrt(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref);
			crdprts.push_back(crdprt);

			refRet = crdprt->jref;

		} else if (ixWdbeVCard == VecWdbeVCard::CRDWDBESIG) {
			CrdWdbeSig* crdsig = NULL;

			crdsig = new CrdWdbeSig(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref);
			crdsigs.push_back(crdsig);

			refRet = crdsig->jref;

		} else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPRC) {
			CrdWdbePrc* crdprc = NULL;

			crdprc = new CrdWdbePrc(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref);
			crdprcs.push_back(crdprc);

			refRet = crdprc->jref;

		} else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEFST) {
			CrdWdbeFst* crdfst = NULL;

			crdfst = new CrdWdbeFst(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref);
			crdfsts.push_back(crdfst);

			refRet = crdfst->jref;

		} else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEVAR) {
			CrdWdbeVar* crdvar = NULL;

			crdvar = new CrdWdbeVar(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref);
			crdvars.push_back(crdvar);

			refRet = crdvar->jref;

		} else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEUTL) {
			CrdWdbeUtl* crdutl = NULL;

			crdutl = new CrdWdbeUtl(xchg, dbswdbe, jref, ixWdbeVLocale);
			crdutls.push_back(crdutl);

			refRet = crdutl->jref;

		};
	};

	return retval;
};

bool SessWdbe::handleCallWdbeLog(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
			, const int intvalInv
		) {
	bool retval = false;
	logRecaccess(dbswdbe, ixInv, refInv, VecWdbeVCard::getIx(srefInv), intvalInv);
	return retval;
};

bool SessWdbe::handleCallWdbeRecaccess(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
			, uint& ixRet
		) {
	bool retval = false;
	ixRet = checkRecaccess(dbswdbe, ixInv, refInv);
	return retval;
};

bool SessWdbe::handleCallWdbeRefPreSet(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;
	if (ixInv == VecWdbeVPreset::PREWDBEJREFNOTIFY) {
		ubigint jrefNotify_old = xchg->getRefPreset(VecWdbeVPreset::PREWDBEJREFNOTIFY, jref);

		if (refInv != jrefNotify_old) {
			if (jrefNotify_old != 0) xchg->submitDpch(new DpchEngWdbeSuspend(jrefNotify_old));

			if (refInv == 0) xchg->removePreset(ixInv, jref);
			else xchg->addRefPreset(ixInv, jref, refInv);
		};

	} else if ((ixInv == VecWdbeVPreset::PREWDBEREFCVR) || (ixInv == VecWdbeVPreset::PREWDBEREFUNT) || (ixInv == VecWdbeVPreset::PREWDBEREFVER)) {
		if (refInv == 0) xchg->removePreset(ixInv, jref);
		else xchg->addRefPreset(ixInv, jref, refInv);

		if (crdnav) crdnav->updatePreset(dbswdbe, ixInv, jrefTrig, true);
	};
	return retval;
};
