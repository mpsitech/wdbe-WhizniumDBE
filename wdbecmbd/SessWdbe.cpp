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
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBEPPH, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPPH, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBEMOD, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBEVEC, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVEC, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBEVIT, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVIT, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBECMD, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCMD, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBEERR, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCERR, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBEPPL, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPPL, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBESEG, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSEG, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBEBNK, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCBNK, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBEPIN, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPIN, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBEINT, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCINT, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBESNS, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSNS, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBEVAR, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVAR, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBEGEN, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCGEN, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBEPRT, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPRT, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBESIG, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIG, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBEPRC, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPRC, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBEFST, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCFST, jref, ixWdbeWAccess);
	ixWdbeWAccess = ixWdbeWAccessBase; if (!adm) getIxCrdacc(dbswdbe, VecWdbeVCard::CRDWDBEUTL, adm, urus, refWdbeMUser, ixWdbeWAccess); xchg->addIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCUTL, jref, ixWdbeWAccess);

	crdnav = new CrdWdbeNav(xchg, dbswdbe, jref, ixWdbeVLocale);

	// IP constructor.cust2 --- INSERT

	statshr.jrefCrdnav = crdnav->jref;

	xchg->addClstn(VecWdbeVCall::CALLWDBEREFPRESET, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBELOG, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBECRDACTIVE, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBERECACCESS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBECRDOPEN, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBECRDCLOSE, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

SessWdbe::~SessWdbe() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void SessWdbe::warnTerm(
			DbsWdbe* dbswdbe
		) {
	crdnav->warnTerm(dbswdbe);
};

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

void SessWdbe::eraseCrd(
			map<ubigint, JobWdbe*>& subjobs
		) {
	string input;
	ubigint iinput;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoll(input.c_str());

	if (!eraseSubjobByJref(subjobs, iinput)) cout << "\tjob reference doesn't exist!" << endl;
	else cout << "\tcard erased." << endl;
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
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPPH) return evalCrdpphActive();
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEMOD) return evalCrdmodActive();
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEVEC) return evalCrdvecActive();
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEVIT) return evalCrdvitActive();
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBECMD) return evalCrdcmdActive();
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEERR) return evalCrderrActive();
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPPL) return evalCrdpplActive();
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBESEG) return evalCrdsegActive();
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEBNK) return evalCrdbnkActive();
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPIN) return evalCrdpinActive();
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEINT) return evalCrdintActive();
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBESNS) return evalCrdsnsActive();
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEVAR) return evalCrdvarActive();
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEGEN) return evalCrdgenActive();
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPRT) return evalCrdprtActive();
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBESIG) return evalCrdsigActive();
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPRC) return evalCrdprcActive();
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEFST) return evalCrdfstActive();

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

uint SessWdbe::evalCrdpphActive() {
	// pre.refUnt()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref)) ? VecWdbeVPreset::PREWDBEREFUNT : 0);

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

uint SessWdbe::evalCrdpplActive() {
	// pre.refUnt()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref)) ? VecWdbeVPreset::PREWDBEREFUNT : 0);

	return(args.back());
};

uint SessWdbe::evalCrdsegActive() {
	// pre.refPpl() > pre.refUnt()

	vector<uint> args;
	uint a, b;

	args.push_back((xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFPPL, jref)) ? VecWdbeVPreset::PREWDBEREFPPL : 0);
	args.push_back((xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref)) ? VecWdbeVPreset::PREWDBEREFUNT : 0);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);

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

uint SessWdbe::evalCrdintActive() {
	// pre.refUnt()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref)) ? VecWdbeVPreset::PREWDBEREFUNT : 0);

	return(args.back());
};

uint SessWdbe::evalCrdsnsActive() {
	// pre.refMod() > pre.refPrc()

	vector<uint> args;
	uint a, b;

	args.push_back((xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFMOD, jref)) ? VecWdbeVPreset::PREWDBEREFMOD : 0);
	args.push_back((xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFPRC, jref)) ? VecWdbeVPreset::PREWDBEREFPRC : 0);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);

	return(args.back());
};

uint SessWdbe::evalCrdvarActive() {
	// pre.refMod() > pre.refPrc()

	vector<uint> args;
	uint a, b;

	args.push_back((xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFMOD, jref)) ? VecWdbeVPreset::PREWDBEREFMOD : 0);
	args.push_back((xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFPRC, jref)) ? VecWdbeVPreset::PREWDBEREFPRC : 0);
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
	// pre.refUnt() > pre.refMtp() > pre.refMod()

	vector<uint> args;
	uint a, b;

	args.push_back((xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFUNT, jref)) ? VecWdbeVPreset::PREWDBEREFUNT : 0);
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
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPPH) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPPH, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEMOD) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCMOD, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEVEC) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVEC, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEVIT) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVIT, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBECMD) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCCMD, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEERR) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCERR, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPPL) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPPL, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBESEG) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSEG, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEBNK) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCBNK, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPIN) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPIN, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEINT) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCINT, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBESNS) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSNS, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEVAR) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCVAR, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEGEN) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCGEN, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPRT) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPRT, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBESIG) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCSIG, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPRC) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCPRC, jref);
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEFST) return xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXCRDACCFST, jref);
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
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPPH) return VecWdbeVMaintable::TBLWDBEMPERIPHERAL;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEMOD) return VecWdbeVMaintable::TBLWDBEMMODULE;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEVEC) return VecWdbeVMaintable::TBLWDBEMVECTOR;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEVIT) return VecWdbeVMaintable::TBLWDBEMVECTORITEM;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBECMD) return VecWdbeVMaintable::TBLWDBEMCOMMAND;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEERR) return VecWdbeVMaintable::TBLWDBEMERROR;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPPL) return VecWdbeVMaintable::TBLWDBEMPIPELINE;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBESEG) return VecWdbeVMaintable::TBLWDBEMSEGMENT;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEBNK) return VecWdbeVMaintable::TBLWDBEMBANK;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPIN) return VecWdbeVMaintable::TBLWDBEMPIN;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEINT) return VecWdbeVMaintable::TBLWDBEMINTERRUPT;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBESNS) return VecWdbeVMaintable::TBLWDBEMSENSITIVITY;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEVAR) return VecWdbeVMaintable::TBLWDBEMVARIABLE;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEGEN) return VecWdbeVMaintable::TBLWDBEMGENERIC;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPRT) return VecWdbeVMaintable::TBLWDBEMPORT;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBESIG) return VecWdbeVMaintable::TBLWDBEMSIGNAL;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPRC) return VecWdbeVMaintable::TBLWDBEMPROCESS;
	else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEFST) return VecWdbeVMaintable::TBLWDBEMFSMSTATE;

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
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFINT) return VecWdbeVMaintable::TBLWDBEMINTERRUPT;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFLIB) return VecWdbeVMaintable::TBLWDBEMLIBRARY;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFMCH) return VecWdbeVMaintable::TBLWDBEMMACHINE;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFMCT) return VecWdbeVMaintable::TBLWDBEMMODULE;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFMDL) return VecWdbeVMaintable::TBLWDBEMMODULE;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFMIB) return VecWdbeVMaintable::TBLWDBEMMODULE;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFMOD) return VecWdbeVMaintable::TBLWDBEMMODULE;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFMTP) return VecWdbeVMaintable::TBLWDBEMMODULE;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFPIN) return VecWdbeVMaintable::TBLWDBEMPIN;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFPPH) return VecWdbeVMaintable::TBLWDBEMPERIPHERAL;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFPPL) return VecWdbeVMaintable::TBLWDBEMPIPELINE;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFPRC) return VecWdbeVMaintable::TBLWDBEMPROCESS;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFPRJ) return VecWdbeVMaintable::TBLWDBEMPROJECT;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFPRS) return VecWdbeVMaintable::TBLWDBEMPERSON;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFPRT) return VecWdbeVMaintable::TBLWDBEMPORT;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFRLS) return VecWdbeVMaintable::TBLWDBEMRELEASE;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFSEG) return VecWdbeVMaintable::TBLWDBEMSEGMENT;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFSES) return VecWdbeVMaintable::TBLWDBEMSESSION;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFSIG) return VecWdbeVMaintable::TBLWDBEMSIGNAL;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFSIL) return VecWdbeVMaintable::TBLWDBEMUNIT;
	else if (ixWdbeVPreset == VecWdbeVPreset::PREWDBEREFSNS) return VecWdbeVMaintable::TBLWDBEMSENSITIVITY;
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
	return((ixWdbeVCard == VecWdbeVCard::CRDWDBEVER) || (ixWdbeVCard == VecWdbeVCard::CRDWDBESYS) || (ixWdbeVCard == VecWdbeVCard::CRDWDBETRG) || (ixWdbeVCard == VecWdbeVCard::CRDWDBEUNT) || (ixWdbeVCard == VecWdbeVCard::CRDWDBERLS) || (ixWdbeVCard == VecWdbeVCard::CRDWDBECVR) || (ixWdbeVCard == VecWdbeVCard::CRDWDBEPPH) || (ixWdbeVCard == VecWdbeVCard::CRDWDBEMOD) || (ixWdbeVCard == VecWdbeVCard::CRDWDBEVEC) || (ixWdbeVCard == VecWdbeVCard::CRDWDBEVIT) || (ixWdbeVCard == VecWdbeVCard::CRDWDBECMD) || (ixWdbeVCard == VecWdbeVCard::CRDWDBEERR) || (ixWdbeVCard == VecWdbeVCard::CRDWDBEPPL) || (ixWdbeVCard == VecWdbeVCard::CRDWDBESEG) || (ixWdbeVCard == VecWdbeVCard::CRDWDBEBNK) || (ixWdbeVCard == VecWdbeVCard::CRDWDBEPIN) || (ixWdbeVCard == VecWdbeVCard::CRDWDBEINT) || (ixWdbeVCard == VecWdbeVCard::CRDWDBESNS) || (ixWdbeVCard == VecWdbeVCard::CRDWDBEVAR) || (ixWdbeVCard == VecWdbeVCard::CRDWDBEGEN) || (ixWdbeVCard == VecWdbeVCard::CRDWDBEPRT) || (ixWdbeVCard == VecWdbeVCard::CRDWDBESIG) || (ixWdbeVCard == VecWdbeVCard::CRDWDBEPRC) || (ixWdbeVCard == VecWdbeVCard::CRDWDBEFST));
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
			cout << "\tcreateCrdint" << endl;
			cout << "\tcreateCrdlib" << endl;
			cout << "\tcreateCrdmch" << endl;
			cout << "\tcreateCrdmod" << endl;
			cout << "\tcreateCrdmtp" << endl;
			cout << "\tcreateCrdpin" << endl;
			cout << "\tcreateCrdpph" << endl;
			cout << "\tcreateCrdppl" << endl;
			cout << "\tcreateCrdprc" << endl;
			cout << "\tcreateCrdprj" << endl;
			cout << "\tcreateCrdprs" << endl;
			cout << "\tcreateCrdprt" << endl;
			cout << "\tcreateCrdrls" << endl;
			cout << "\tcreateCrdseg" << endl;
			cout << "\tcreateCrdsig" << endl;
			cout << "\tcreateCrdsil" << endl;
			cout << "\tcreateCrdsns" << endl;
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
			cout << "\teraseCrdint" << endl;
			cout << "\teraseCrdlib" << endl;
			cout << "\teraseCrdmch" << endl;
			cout << "\teraseCrdmod" << endl;
			cout << "\teraseCrdmtp" << endl;
			cout << "\teraseCrdpin" << endl;
			cout << "\teraseCrdpph" << endl;
			cout << "\teraseCrdppl" << endl;
			cout << "\teraseCrdprc" << endl;
			cout << "\teraseCrdprj" << endl;
			cout << "\teraseCrdprs" << endl;
			cout << "\teraseCrdprt" << endl;
			cout << "\teraseCrdrls" << endl;
			cout << "\teraseCrdseg" << endl;
			cout << "\teraseCrdsig" << endl;
			cout << "\teraseCrdsil" << endl;
			cout << "\teraseCrdsns" << endl;
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

		} else if (req->cmd == "createCrdint") {
			req->retain = handleCreateCrdint(dbswdbe);

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

		} else if (req->cmd == "createCrdppl") {
			req->retain = handleCreateCrdppl(dbswdbe);

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

		} else if (req->cmd == "createCrdseg") {
			req->retain = handleCreateCrdseg(dbswdbe);

		} else if (req->cmd == "createCrdsig") {
			req->retain = handleCreateCrdsig(dbswdbe);

		} else if (req->cmd == "createCrdsil") {
			req->retain = handleCreateCrdsil(dbswdbe);

		} else if (req->cmd == "createCrdsns") {
			req->retain = handleCreateCrdsns(dbswdbe);

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

		} else if (req->cmd == "eraseCrdint") {
			req->retain = handleEraseCrdint(dbswdbe);

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

		} else if (req->cmd == "eraseCrdppl") {
			req->retain = handleEraseCrdppl(dbswdbe);

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

		} else if (req->cmd == "eraseCrdseg") {
			req->retain = handleEraseCrdseg(dbswdbe);

		} else if (req->cmd == "eraseCrdsig") {
			req->retain = handleEraseCrdsig(dbswdbe);

		} else if (req->cmd == "eraseCrdsil") {
			req->retain = handleEraseCrdsil(dbswdbe);

		} else if (req->cmd == "eraseCrdsns") {
			req->retain = handleEraseCrdsns(dbswdbe);

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

	uint ixWdbeVPreset = evalCrdbnkActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdbnks, new CrdWdbeBnk(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWdbe::handleCreateCrdcmd(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;

	uint ixWdbeVPreset = evalCrdcmdActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdcmds, new CrdWdbeCmd(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWdbe::handleCreateCrdcpr(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdcprs, new CrdWdbeCpr(xchg, dbswdbe, jref, ixWdbeVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessWdbe::handleCreateCrdcvr(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;

	uint ixWdbeVPreset = evalCrdcvrActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdcvrs, new CrdWdbeCvr(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWdbe::handleCreateCrderr(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;

	uint ixWdbeVPreset = evalCrderrActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crderrs, new CrdWdbeErr(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWdbe::handleCreateCrdfam(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdfams, new CrdWdbeFam(xchg, dbswdbe, jref, ixWdbeVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessWdbe::handleCreateCrdfil(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdfils, new CrdWdbeFil(xchg, dbswdbe, jref, ixWdbeVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessWdbe::handleCreateCrdfst(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;

	uint ixWdbeVPreset = evalCrdfstActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdfsts, new CrdWdbeFst(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWdbe::handleCreateCrdgen(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;

	uint ixWdbeVPreset = evalCrdgenActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdgens, new CrdWdbeGen(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWdbe::handleCreateCrdint(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;

	uint ixWdbeVPreset = evalCrdintActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdints, new CrdWdbeInt(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWdbe::handleCreateCrdlib(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdlibs, new CrdWdbeLib(xchg, dbswdbe, jref, ixWdbeVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessWdbe::handleCreateCrdmch(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdmchs, new CrdWdbeMch(xchg, dbswdbe, jref, ixWdbeVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessWdbe::handleCreateCrdmod(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;

	uint ixWdbeVPreset = evalCrdmodActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdmods, new CrdWdbeMod(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWdbe::handleCreateCrdmtp(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdmtps, new CrdWdbeMtp(xchg, dbswdbe, jref, ixWdbeVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessWdbe::handleCreateCrdpin(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;

	uint ixWdbeVPreset = evalCrdpinActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdpins, new CrdWdbePin(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWdbe::handleCreateCrdpph(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;

	uint ixWdbeVPreset = evalCrdpphActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdpphs, new CrdWdbePph(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWdbe::handleCreateCrdppl(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;

	uint ixWdbeVPreset = evalCrdpplActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdppls, new CrdWdbePpl(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWdbe::handleCreateCrdprc(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;

	uint ixWdbeVPreset = evalCrdprcActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdprcs, new CrdWdbePrc(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWdbe::handleCreateCrdprj(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdprjs, new CrdWdbePrj(xchg, dbswdbe, jref, ixWdbeVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessWdbe::handleCreateCrdprs(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdprss, new CrdWdbePrs(xchg, dbswdbe, jref, ixWdbeVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessWdbe::handleCreateCrdprt(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;

	uint ixWdbeVPreset = evalCrdprtActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdprts, new CrdWdbePrt(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWdbe::handleCreateCrdrls(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;

	uint ixWdbeVPreset = evalCrdrlsActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdrlss, new CrdWdbeRls(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWdbe::handleCreateCrdseg(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;

	uint ixWdbeVPreset = evalCrdsegActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdsegs, new CrdWdbeSeg(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWdbe::handleCreateCrdsig(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;

	uint ixWdbeVPreset = evalCrdsigActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdsigs, new CrdWdbeSig(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWdbe::handleCreateCrdsil(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdsils, new CrdWdbeSil(xchg, dbswdbe, jref, ixWdbeVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessWdbe::handleCreateCrdsns(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;

	uint ixWdbeVPreset = evalCrdsnsActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdsnss, new CrdWdbeSns(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWdbe::handleCreateCrdsys(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;

	uint ixWdbeVPreset = evalCrdsysActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdsyss, new CrdWdbeSys(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWdbe::handleCreateCrdtrg(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;

	uint ixWdbeVPreset = evalCrdtrgActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdtrgs, new CrdWdbeTrg(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWdbe::handleCreateCrdunt(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;

	uint ixWdbeVPreset = evalCrduntActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdunts, new CrdWdbeUnt(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWdbe::handleCreateCrdusg(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdusgs, new CrdWdbeUsg(xchg, dbswdbe, jref, ixWdbeVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessWdbe::handleCreateCrdusr(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdusrs, new CrdWdbeUsr(xchg, dbswdbe, jref, ixWdbeVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessWdbe::handleCreateCrdutl(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdutls, new CrdWdbeUtl(xchg, dbswdbe, jref, ixWdbeVLocale));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessWdbe::handleCreateCrdvar(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;

	uint ixWdbeVPreset = evalCrdvarActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdvars, new CrdWdbeVar(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWdbe::handleCreateCrdvec(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;

	uint ixWdbeVPreset = evalCrdvecActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdvecs, new CrdWdbeVec(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWdbe::handleCreateCrdver(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;

	uint ixWdbeVPreset = evalCrdverActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdvers, new CrdWdbeVer(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWdbe::handleCreateCrdvit(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;

	uint ixWdbeVPreset = evalCrdvitActive();

	if (ixWdbeVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdvits, new CrdWdbeVit(xchg, dbswdbe, jref, ixWdbeVLocale, 0, ixWdbeVPreset, xchg->getRefPreset(ixWdbeVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWdbe::handleEraseCrdbnk(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	eraseCrd(crdbnks);
	return retval;
};

bool SessWdbe::handleEraseCrdcmd(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	eraseCrd(crdcmds);
	return retval;
};

bool SessWdbe::handleEraseCrdcpr(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	eraseCrd(crdcprs);
	return retval;
};

bool SessWdbe::handleEraseCrdcvr(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	eraseCrd(crdcvrs);
	return retval;
};

bool SessWdbe::handleEraseCrderr(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	eraseCrd(crderrs);
	return retval;
};

bool SessWdbe::handleEraseCrdfam(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	eraseCrd(crdfams);
	return retval;
};

bool SessWdbe::handleEraseCrdfil(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	eraseCrd(crdfils);
	return retval;
};

bool SessWdbe::handleEraseCrdfst(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	eraseCrd(crdfsts);
	return retval;
};

bool SessWdbe::handleEraseCrdgen(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	eraseCrd(crdgens);
	return retval;
};

bool SessWdbe::handleEraseCrdint(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	eraseCrd(crdints);
	return retval;
};

bool SessWdbe::handleEraseCrdlib(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	eraseCrd(crdlibs);
	return retval;
};

bool SessWdbe::handleEraseCrdmch(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	eraseCrd(crdmchs);
	return retval;
};

bool SessWdbe::handleEraseCrdmod(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	eraseCrd(crdmods);
	return retval;
};

bool SessWdbe::handleEraseCrdmtp(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	eraseCrd(crdmtps);
	return retval;
};

bool SessWdbe::handleEraseCrdpin(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	eraseCrd(crdpins);
	return retval;
};

bool SessWdbe::handleEraseCrdpph(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	eraseCrd(crdpphs);
	return retval;
};

bool SessWdbe::handleEraseCrdppl(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	eraseCrd(crdppls);
	return retval;
};

bool SessWdbe::handleEraseCrdprc(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	eraseCrd(crdprcs);
	return retval;
};

bool SessWdbe::handleEraseCrdprj(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	eraseCrd(crdprjs);
	return retval;
};

bool SessWdbe::handleEraseCrdprs(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	eraseCrd(crdprss);
	return retval;
};

bool SessWdbe::handleEraseCrdprt(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	eraseCrd(crdprts);
	return retval;
};

bool SessWdbe::handleEraseCrdrls(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	eraseCrd(crdrlss);
	return retval;
};

bool SessWdbe::handleEraseCrdseg(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	eraseCrd(crdsegs);
	return retval;
};

bool SessWdbe::handleEraseCrdsig(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	eraseCrd(crdsigs);
	return retval;
};

bool SessWdbe::handleEraseCrdsil(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	eraseCrd(crdsils);
	return retval;
};

bool SessWdbe::handleEraseCrdsns(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	eraseCrd(crdsnss);
	return retval;
};

bool SessWdbe::handleEraseCrdsys(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	eraseCrd(crdsyss);
	return retval;
};

bool SessWdbe::handleEraseCrdtrg(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	eraseCrd(crdtrgs);
	return retval;
};

bool SessWdbe::handleEraseCrdunt(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	eraseCrd(crdunts);
	return retval;
};

bool SessWdbe::handleEraseCrdusg(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	eraseCrd(crdusgs);
	return retval;
};

bool SessWdbe::handleEraseCrdusr(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	eraseCrd(crdusrs);
	return retval;
};

bool SessWdbe::handleEraseCrdutl(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	eraseCrd(crdutls);
	return retval;
};

bool SessWdbe::handleEraseCrdvar(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	eraseCrd(crdvars);
	return retval;
};

bool SessWdbe::handleEraseCrdvec(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	eraseCrd(crdvecs);
	return retval;
};

bool SessWdbe::handleEraseCrdver(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	eraseCrd(crdvers);
	return retval;
};

bool SessWdbe::handleEraseCrdvit(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	eraseCrd(crdvits);
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

	for (auto it = crdusgs.begin(); it != crdusgs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWdbeUsg");
	for (auto it = crdusrs.begin(); it != crdusrs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWdbeUsr");
	for (auto it = crdprss.begin(); it != crdprss.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWdbePrs");
	for (auto it = crdfils.begin(); it != crdfils.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWdbeFil");
	for (auto it = crdmchs.begin(); it != crdmchs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWdbeMch");
	for (auto it = crdlibs.begin(); it != crdlibs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWdbeLib");
	for (auto it = crdfams.begin(); it != crdfams.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWdbeFam");
	for (auto it = crdsils.begin(); it != crdsils.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWdbeSil");
	for (auto it = crdmtps.begin(); it != crdmtps.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWdbeMtp");
	for (auto it = crdprjs.begin(); it != crdprjs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWdbePrj");
	for (auto it = crdvers.begin(); it != crdvers.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWdbeVer");
	for (auto it = crdsyss.begin(); it != crdsyss.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWdbeSys");
	for (auto it = crdtrgs.begin(); it != crdtrgs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWdbeTrg");
	for (auto it = crdunts.begin(); it != crdunts.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWdbeUnt");
	for (auto it = crdrlss.begin(); it != crdrlss.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWdbeRls");
	for (auto it = crdcprs.begin(); it != crdcprs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWdbeCpr");
	for (auto it = crdcvrs.begin(); it != crdcvrs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWdbeCvr");
	for (auto it = crdpphs.begin(); it != crdpphs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWdbePph");
	for (auto it = crdmods.begin(); it != crdmods.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWdbeMod");
	for (auto it = crdvecs.begin(); it != crdvecs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWdbeVec");
	for (auto it = crdvits.begin(); it != crdvits.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWdbeVit");
	for (auto it = crdcmds.begin(); it != crdcmds.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWdbeCmd");
	for (auto it = crderrs.begin(); it != crderrs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWdbeErr");
	for (auto it = crdppls.begin(); it != crdppls.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWdbePpl");
	for (auto it = crdsegs.begin(); it != crdsegs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWdbeSeg");
	for (auto it = crdbnks.begin(); it != crdbnks.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWdbeBnk");
	for (auto it = crdpins.begin(); it != crdpins.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWdbePin");
	for (auto it = crdints.begin(); it != crdints.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWdbeInt");
	for (auto it = crdsnss.begin(); it != crdsnss.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWdbeSns");
	for (auto it = crdvars.begin(); it != crdvars.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWdbeVar");
	for (auto it = crdgens.begin(); it != crdgens.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWdbeGen");
	for (auto it = crdprts.begin(); it != crdprts.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWdbePrt");
	for (auto it = crdsigs.begin(); it != crdsigs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWdbeSig");
	for (auto it = crdprcs.begin(); it != crdprcs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWdbePrc");
	for (auto it = crdfsts.begin(); it != crdfsts.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWdbeFst");
	for (auto it = crdutls.begin(); it != crdutls.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWdbeUtl");

	*dpcheng = new DpchEngData(jref, &feedFEnsSec, &statshr, {DpchEngData::ALL});
};

void SessWdbe::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBEREFPRESET) {
		call->abort = handleCallWdbeRefPreSet(dbswdbe, call->jref, call->argInv.ix, call->argInv.ref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBELOG) {
		call->abort = handleCallWdbeLog(dbswdbe, call->jref, call->argInv.ix, call->argInv.ref, call->argInv.sref, call->argInv.intval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBECRDACTIVE) {
		call->abort = handleCallWdbeCrdActive(dbswdbe, call->jref, call->argInv.ix, call->argRet.ix);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBERECACCESS) {
		call->abort = handleCallWdbeRecaccess(dbswdbe, call->jref, call->argInv.ix, call->argInv.ref, call->argRet.ix);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBECRDOPEN) {
		call->abort = handleCallWdbeCrdOpen(dbswdbe, call->jref, call->argInv.ix, call->argInv.ref, call->argInv.sref, call->argInv.intval, call->argRet.ref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBECRDCLOSE) {
		call->abort = handleCallWdbeCrdClose(dbswdbe, call->jref, call->argInv.ix);
	};
};

bool SessWdbe::handleCallWdbeRefPreSet(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallWdbeRefPreSet --- BEGIN
	if (ixInv == VecWdbeVPreset::PREWDBEJREFNOTIFY) {
		ubigint jrefNotify_old = xchg->getRefPreset(VecWdbeVPreset::PREWDBEJREFNOTIFY, jref);

		if (refInv != jrefNotify_old) {
			if (jrefNotify_old != 0) xchg->submitDpch(new DpchEngWdbeSuspend(jrefNotify_old));

			if (refInv == 0) xchg->removePreset(ixInv, jref);
			else xchg->addRefPreset(ixInv, jref, refInv);
		};

	} else if (ixInv == VecWdbeVPreset::PREWDBETLAST) {
		if (xchg->stgwdbeappearance.sesstterm != 0) xchg->addRefPreset(ixInv, jref, refInv);

	} else if ((ixInv == VecWdbeVPreset::PREWDBEREFCVR) || (ixInv == VecWdbeVPreset::PREWDBEREFUNT) || (ixInv == VecWdbeVPreset::PREWDBEREFVER)) {
		if (refInv == 0) xchg->removePreset(ixInv, jref);
		else xchg->addRefPreset(ixInv, jref, refInv);

		if (crdnav) crdnav->updatePreset(dbswdbe, ixInv, jrefTrig, true);
	};
// IP handleCallWdbeRefPreSet --- END
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
		if (ixWdbeVCard == VecWdbeVCard::CRDWDBEUSG) refRet = insertSubjob(crdusgs, new CrdWdbeUsg(xchg, dbswdbe, jref, ixWdbeVLocale, ref));
		else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEUSR) refRet = insertSubjob(crdusrs, new CrdWdbeUsr(xchg, dbswdbe, jref, ixWdbeVLocale, ref));
		else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPRS) refRet = insertSubjob(crdprss, new CrdWdbePrs(xchg, dbswdbe, jref, ixWdbeVLocale, ref));
		else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEFIL) refRet = insertSubjob(crdfils, new CrdWdbeFil(xchg, dbswdbe, jref, ixWdbeVLocale, ref));
		else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEMCH) refRet = insertSubjob(crdmchs, new CrdWdbeMch(xchg, dbswdbe, jref, ixWdbeVLocale, ref));
		else if (ixWdbeVCard == VecWdbeVCard::CRDWDBELIB) refRet = insertSubjob(crdlibs, new CrdWdbeLib(xchg, dbswdbe, jref, ixWdbeVLocale, ref));
		else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEFAM) refRet = insertSubjob(crdfams, new CrdWdbeFam(xchg, dbswdbe, jref, ixWdbeVLocale, ref));
		else if (ixWdbeVCard == VecWdbeVCard::CRDWDBESIL) refRet = insertSubjob(crdsils, new CrdWdbeSil(xchg, dbswdbe, jref, ixWdbeVLocale, ref));
		else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEMTP) refRet = insertSubjob(crdmtps, new CrdWdbeMtp(xchg, dbswdbe, jref, ixWdbeVLocale, ref));
		else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPRJ) refRet = insertSubjob(crdprjs, new CrdWdbePrj(xchg, dbswdbe, jref, ixWdbeVLocale, ref));
		else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEVER) refRet = insertSubjob(crdvers, new CrdWdbeVer(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref));
		else if (ixWdbeVCard == VecWdbeVCard::CRDWDBESYS) refRet = insertSubjob(crdsyss, new CrdWdbeSys(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref));
		else if (ixWdbeVCard == VecWdbeVCard::CRDWDBETRG) refRet = insertSubjob(crdtrgs, new CrdWdbeTrg(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref));
		else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEUNT) refRet = insertSubjob(crdunts, new CrdWdbeUnt(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref));
		else if (ixWdbeVCard == VecWdbeVCard::CRDWDBERLS) refRet = insertSubjob(crdrlss, new CrdWdbeRls(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref));
		else if (ixWdbeVCard == VecWdbeVCard::CRDWDBECPR) refRet = insertSubjob(crdcprs, new CrdWdbeCpr(xchg, dbswdbe, jref, ixWdbeVLocale, ref));
		else if (ixWdbeVCard == VecWdbeVCard::CRDWDBECVR) refRet = insertSubjob(crdcvrs, new CrdWdbeCvr(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref));
		else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPPH) refRet = insertSubjob(crdpphs, new CrdWdbePph(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref));
		else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEMOD) refRet = insertSubjob(crdmods, new CrdWdbeMod(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref));
		else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEVEC) refRet = insertSubjob(crdvecs, new CrdWdbeVec(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref));
		else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEVIT) refRet = insertSubjob(crdvits, new CrdWdbeVit(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref));
		else if (ixWdbeVCard == VecWdbeVCard::CRDWDBECMD) refRet = insertSubjob(crdcmds, new CrdWdbeCmd(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref));
		else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEERR) refRet = insertSubjob(crderrs, new CrdWdbeErr(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref));
		else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPPL) refRet = insertSubjob(crdppls, new CrdWdbePpl(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref));
		else if (ixWdbeVCard == VecWdbeVCard::CRDWDBESEG) refRet = insertSubjob(crdsegs, new CrdWdbeSeg(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref));
		else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEBNK) refRet = insertSubjob(crdbnks, new CrdWdbeBnk(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref));
		else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPIN) refRet = insertSubjob(crdpins, new CrdWdbePin(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref));
		else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEINT) refRet = insertSubjob(crdints, new CrdWdbeInt(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref));
		else if (ixWdbeVCard == VecWdbeVCard::CRDWDBESNS) refRet = insertSubjob(crdsnss, new CrdWdbeSns(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref));
		else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEVAR) refRet = insertSubjob(crdvars, new CrdWdbeVar(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref));
		else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEGEN) refRet = insertSubjob(crdgens, new CrdWdbeGen(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref));
		else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPRT) refRet = insertSubjob(crdprts, new CrdWdbePrt(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref));
		else if (ixWdbeVCard == VecWdbeVCard::CRDWDBESIG) refRet = insertSubjob(crdsigs, new CrdWdbeSig(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref));
		else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEPRC) refRet = insertSubjob(crdprcs, new CrdWdbePrc(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref));
		else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEFST) refRet = insertSubjob(crdfsts, new CrdWdbeFst(xchg, dbswdbe, jref, ixWdbeVLocale, ref, ixWdbeVPreset, preUref));
		else if (ixWdbeVCard == VecWdbeVCard::CRDWDBEUTL) refRet = insertSubjob(crdutls, new CrdWdbeUtl(xchg, dbswdbe, jref, ixWdbeVLocale));
	};

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

	if (ixInv == VecWdbeVCard::CRDWDBEUSG) eraseSubjobByJref(crdusgs, jrefTrig);
	else if (ixInv == VecWdbeVCard::CRDWDBEUSR) eraseSubjobByJref(crdusrs, jrefTrig);
	else if (ixInv == VecWdbeVCard::CRDWDBEPRS) eraseSubjobByJref(crdprss, jrefTrig);
	else if (ixInv == VecWdbeVCard::CRDWDBEFIL) eraseSubjobByJref(crdfils, jrefTrig);
	else if (ixInv == VecWdbeVCard::CRDWDBENAV) {
		if (crdnav) {
			delete crdnav;
			crdnav = NULL;
		};

	} 
else if (ixInv == VecWdbeVCard::CRDWDBEMCH) eraseSubjobByJref(crdmchs, jrefTrig);
	else if (ixInv == VecWdbeVCard::CRDWDBELIB) eraseSubjobByJref(crdlibs, jrefTrig);
	else if (ixInv == VecWdbeVCard::CRDWDBEFAM) eraseSubjobByJref(crdfams, jrefTrig);
	else if (ixInv == VecWdbeVCard::CRDWDBESIL) eraseSubjobByJref(crdsils, jrefTrig);
	else if (ixInv == VecWdbeVCard::CRDWDBEMTP) eraseSubjobByJref(crdmtps, jrefTrig);
	else if (ixInv == VecWdbeVCard::CRDWDBEPRJ) eraseSubjobByJref(crdprjs, jrefTrig);
	else if (ixInv == VecWdbeVCard::CRDWDBEVER) eraseSubjobByJref(crdvers, jrefTrig);
	else if (ixInv == VecWdbeVCard::CRDWDBESYS) eraseSubjobByJref(crdsyss, jrefTrig);
	else if (ixInv == VecWdbeVCard::CRDWDBETRG) eraseSubjobByJref(crdtrgs, jrefTrig);
	else if (ixInv == VecWdbeVCard::CRDWDBEUNT) eraseSubjobByJref(crdunts, jrefTrig);
	else if (ixInv == VecWdbeVCard::CRDWDBERLS) eraseSubjobByJref(crdrlss, jrefTrig);
	else if (ixInv == VecWdbeVCard::CRDWDBECPR) eraseSubjobByJref(crdcprs, jrefTrig);
	else if (ixInv == VecWdbeVCard::CRDWDBECVR) eraseSubjobByJref(crdcvrs, jrefTrig);
	else if (ixInv == VecWdbeVCard::CRDWDBEPPH) eraseSubjobByJref(crdpphs, jrefTrig);
	else if (ixInv == VecWdbeVCard::CRDWDBEMOD) eraseSubjobByJref(crdmods, jrefTrig);
	else if (ixInv == VecWdbeVCard::CRDWDBEVEC) eraseSubjobByJref(crdvecs, jrefTrig);
	else if (ixInv == VecWdbeVCard::CRDWDBEVIT) eraseSubjobByJref(crdvits, jrefTrig);
	else if (ixInv == VecWdbeVCard::CRDWDBECMD) eraseSubjobByJref(crdcmds, jrefTrig);
	else if (ixInv == VecWdbeVCard::CRDWDBEERR) eraseSubjobByJref(crderrs, jrefTrig);
	else if (ixInv == VecWdbeVCard::CRDWDBEPPL) eraseSubjobByJref(crdppls, jrefTrig);
	else if (ixInv == VecWdbeVCard::CRDWDBESEG) eraseSubjobByJref(crdsegs, jrefTrig);
	else if (ixInv == VecWdbeVCard::CRDWDBEBNK) eraseSubjobByJref(crdbnks, jrefTrig);
	else if (ixInv == VecWdbeVCard::CRDWDBEPIN) eraseSubjobByJref(crdpins, jrefTrig);
	else if (ixInv == VecWdbeVCard::CRDWDBEINT) eraseSubjobByJref(crdints, jrefTrig);
	else if (ixInv == VecWdbeVCard::CRDWDBESNS) eraseSubjobByJref(crdsnss, jrefTrig);
	else if (ixInv == VecWdbeVCard::CRDWDBEVAR) eraseSubjobByJref(crdvars, jrefTrig);
	else if (ixInv == VecWdbeVCard::CRDWDBEGEN) eraseSubjobByJref(crdgens, jrefTrig);
	else if (ixInv == VecWdbeVCard::CRDWDBEPRT) eraseSubjobByJref(crdprts, jrefTrig);
	else if (ixInv == VecWdbeVCard::CRDWDBESIG) eraseSubjobByJref(crdsigs, jrefTrig);
	else if (ixInv == VecWdbeVCard::CRDWDBEPRC) eraseSubjobByJref(crdprcs, jrefTrig);
	else if (ixInv == VecWdbeVCard::CRDWDBEFST) eraseSubjobByJref(crdfsts, jrefTrig);
	else if (ixInv == VecWdbeVCard::CRDWDBEUTL) eraseSubjobByJref(crdutls, jrefTrig);
	return retval;
};
