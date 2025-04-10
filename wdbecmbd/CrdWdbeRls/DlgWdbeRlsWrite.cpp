/**
	* \file DlgWdbeRlsWrite.cpp
	* job handler for job DlgWdbeRlsWrite (implementation)
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

#include "DlgWdbeRlsWrite.h"

#include "DlgWdbeRlsWrite_blks.cpp"
#include "DlgWdbeRlsWrite_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWdbeRlsWrite
 ******************************************************************************/

DlgWdbeRlsWrite::DlgWdbeRlsWrite(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::DLGWDBERLSWRITE, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFDse.tag = "FeedFDse";
	VecVDit::fillFeed(ixWdbeVLocale, feedFDse);
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	license = NULL;

	// IP constructor.cust1 --- INSERT

	ixVDit = VecVDit::DET;

	license = new JobWdbeLicense(xchg, dbswdbe, jref, ixWdbeVLocale);

	// IP constructor.cust2 --- IBEGIN
	vector<ubigint> refs;
	ubigint ref;

	WdbeMRelease* rls = NULL;
	WdbeMComponent* cmp = NULL;
	WdbeMProject* prj = NULL;

	refWdbeMRelease = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFRLS, jref);

	// -- author
	dbswdbe->loadRefBySQL("SELECT refWdbeMPerson FROM TblWdbeMUser WHERE ref = " + to_string(xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref)), ref);
	author = StubWdbe::getStubPrsStd(dbswdbe, ref);

	if (dbswdbe->tblwdbemrelease->loadRecByRef(refWdbeMRelease, &rls)) {
		// release identifier
		rlssref = rls->sref;
	
		// project, component type, component
		if (dbswdbe->tblwdbemcomponent->loadRecByRef(rls->refWdbeMComponent, &cmp)) {
			ixCmptype = cmp->ixVBasetype;

			CMPSREF = StrMod::uc(cmp->sref);
			Cmpsref = StrMod::cap(cmp->sref);
			cmpsref = StrMod::lc(cmp->sref);

			// find project short
			if (dbswdbe->tblwdbemproject->loadRecBySQL("SELECT TblWdbeMProject.* FROM TblWdbeMProject, TblWdbeMVersion WHERE TblWdbeMProject.ref = TblWdbeMVersion.prjRefWdbeMProject AND TblWdbeMVersion.ref = "
						+ to_string(cmp->refWdbeMVersion), &prj)) {

				PRJSHORT = StrMod::uc(prj->Short);
				Prjshort = StrMod::cap(prj->Short);
				prjshort = StrMod::lc(prj->Short);

				Prjeasy = prj->Easy;

				delete prj;
			};

			delete cmp;
		};

		// (cross-)compilation parameters
		if ((ixCmptype == VecWdbeVMComponentBasetype::DEV) || (ixCmptype == VecWdbeVMComponentBasetype::EZDEV) || (ixCmptype == VecWdbeVMComponentBasetype::TERM)) {
			dbswdbe->tblwdbemmachine->loadHrefsup(rls->refWdbeMMachine, refs);

			dbswdbe->loadRefBySQL("SELECT cchRefWdbeMMachine FROM TblWdbeMMachine WHERE ref = " + to_string(rls->refWdbeMMachine), ref);

			if (ref == 0) {
				for (unsigned int i = 0; i < refs.size(); i++) {
					dbswdbe->loadRefBySQL("SELECT cchRefWdbeMMachine FROM TblWdbeMMachine WHERE ref = " + to_string(refs[i]), ref);
					if (ref != 0) break;
				};
			};

			if (ref == 0) {
				Wdbe::getMchpar(dbswdbe, rls->refWdbeMMachine, refs, "ncore", ncore);

			} else {
				// cross-compilation
				Wdbe::getMchpar(dbswdbe, rls->refWdbeMMachine, refs, "sysroot", sysroot);

				cchost = " (" + StubWdbe::getStubMchSref(dbswdbe, ref) + " cross-compilation)";
				inclibeq = "=";

				dbswdbe->tblwdbemmachine->loadHrefsup(ref, refs);
				Wdbe::getMchpar(dbswdbe, ref, refs, "ncore", ncore);
			};
		};

		delete rls;
	};

	// IP constructor.cust2 --- IEND

	set<uint> moditems;
	refresh(dbswdbe, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgWdbeRlsWrite::~DlgWdbeRlsWrite() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
void DlgWdbeRlsWrite::createIpoutSubfolder(
			const bool spec
			, const string& sub1
			, const string& sub2
		) {
	string s;

	s = xchg->tmppath + "/" + ipfolder + "/" + sub1;
	if (sub2.length() > 0) s = s + "/" + sub2;
	mkdir(s.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

	if (spec) {
		s = xchg->tmppath + "/" + finefolder + "/" + sub1;
		if (sub2.length() > 0) s = s + "/" + sub2;
		mkdir(s.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

		s = xchg->tmppath + "/" + typspecfolder + "/" + sub1;
		if (sub2.length() > 0) s = s + "/" + sub2;
		mkdir(s.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

		s = xchg->tmppath + "/" + tplspecfolder + "/" + sub1;
		if (sub2.length() > 0) s = s + "/" + sub2;
		mkdir(s.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

		s = xchg->tmppath + "/" + auxfolder + "/" + sub1;
		if (sub2.length() > 0) s = s + "/" + sub2;
		mkdir(s.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	};

	s = xchg->tmppath + "/" + outfolder + "/" + sub1;
	if (sub2.length() > 0) s = s + "/" + sub2;
	mkdir(s.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
};

void DlgWdbeRlsWrite::copyAcvtmp(
			DbsWdbe* dbswdbe
			, const ubigint refWdbeMFile
			, const string& tmpfile
		) {
	Wdbe::run("cp " + xchg->acvpath + "/" +  Acv::getfile(dbswdbe, refWdbeMFile) + " " + xchg->tmppath + "/" + tmpfile);
};

void DlgWdbeRlsWrite::createFpga(
			DbsWdbe* dbswdbe
			, const bool dplonly
		) {
	ubigint ref;

	WdbeMRelease* rls = NULL;
	WdbeMComponent* cmp = NULL;
	WdbeMVersion* ver = NULL;

	vector<ubigint> hrefsMch;

	string created;
	string reproot;

	vector<string> keys;
	vector<string> vals;

	ListWdbeMUnit unts;
	WdbeMUnit* unt = NULL;

	string Untsref;

	ListWdbeMModule mtps;
	map<ubigint,WdbeMModule*> refsMtps;
	WdbeMModule* mtp = NULL;

	ListWdbeMFile mtfs;
	map<ubigint,WdbeMFile*> mtprefsMtfs;
	WdbeMFile* mtf = NULL;

	map<ubigint,string> srefsMtpPlhfpgaCustops;
	map<ubigint,string> srefsMtpWrfpgaCustops;

	ListWdbeMModule mdls;
	WdbeMModule* mdl = NULL;

	string Compsref;

	bool hassub;

	unsigned int N;

	string s;

	bool found;

	// --- load basics
	dbswdbe->tblwdbemrelease->loadRecByRef(refWdbeMRelease, &rls);
	dbswdbe->tblwdbemcomponent->loadRecByRef(rls->refWdbeMComponent, &cmp);
	dbswdbe->tblwdbemversion->loadRecByRef(cmp->refWdbeMVersion, &ver);

	dbswdbe->tblwdbemmachine->loadHrefsup(rls->refWdbeMMachine, hrefsMch);

	dbswdbe->tblwdbemunit->loadRstBySQL("SELECT * FROM TblWdbeMUnit WHERE refIxVTbl = " + to_string(VecWdbeVMUnitRefTbl::VER) + " AND refUref = " + to_string(ver->ref) + " AND ixVBasetype = " + to_string(VecWdbeVMUnitBasetype::FPGA)
				+ " ORDER BY sref ASC", false, unts);

	dbswdbe->tblwdbemmodule->loadRstBySQL("SELECT * FROM TblWdbeMModule WHERE ((hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::VOID) + ") AND (supRefWdbeMModule = 0) AND (tplRefWdbeMModule = 0)) ORDER BY sref ASC", false, mtps);
	for (unsigned int i = 0; i < mtps.nodes.size(); i++) {
		mtp = mtps.nodes[i];

		refsMtps[mtp->ref] = mtp;

		if (dbswdbe->tblwdbemfile->loadRstBySQL("SELECT * FROM TblWdbeMFile WHERE refIxVTbl = " + to_string(VecWdbeVMFileRefTbl::MTP) + " AND refUref = " + to_string(mtp->ref) + " AND Filename = '" + StrMod::cap(mtp->sref) + ".vhd'", true, mtfs) == 1)
					mtprefsMtfs[mtp->ref] = mtfs.nodes[mtfs.nodes.size()-1];
	};

	Wdbe::getSrefsMtpCustops(dbswdbe, srefsMtpPlhfpgaCustops, VecWdbeVKeylist::KLSTKWDBEMTPPLHFPGACUSTOP);
	Wdbe::getSrefsMtpCustops(dbswdbe, srefsMtpWrfpgaCustops, VecWdbeVKeylist::KLSTKWDBEMTPWRFPGACUSTOP);

	// --- find template files in archive
	ubigint refChkinisefile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'checkin_xxxx_Fpga_ise.sh'", refChkinisefile);
	ubigint refChkinvivfile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'checkin_xxxx_Fpga_vivado.sh'", refChkinvivfile);
	ubigint refChkoutfile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'checkout_Fpga.sh'", refChkoutfile);

	ubigint refUntUcffile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Xxxx.ucf'", refUntUcffile);
	ubigint refUntLttcPdcfile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Xxxx_lttc.pdc'", refUntLttcPdcfile);
	ubigint refUntMchpPdcfile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Xxxx_mchp.pdc'", refUntMchpPdcfile);
	ubigint refUntIsffile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Xxxx.isf'", refUntIsffile);
	ubigint refUntXdcfile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Xxxx.xdc'", refUntXdcfile);
	ubigint refUntVhdfile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Xxxx.vhd'", refUntVhdfile);
	ubigint refEzuntVhdfile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Xxxx_Easy.vhd'", refEzuntVhdfile);
	ubigint refMdlVhdfile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Xxxxx.vhd'", refMdlVhdfile);

	// --- generate folder structure
	ipfolder = Tmp::newfolder(xchg->tmppath);
	finefolder = Tmp::newfolder(xchg->tmppath);
	typspecfolder = Tmp::newfolder(xchg->tmppath);
	tplspecfolder = Tmp::newfolder(xchg->tmppath);
	auxfolder = Tmp::newfolder(xchg->tmppath);

	outfolder = xchg->getTxtvalPreset(VecWdbeVPreset::PREWDBEREPFOLDER, jref);
	if (outfolder == "") outfolder = Tmp::newfolder(xchg->tmppath);

	createIpoutSubfolder(false, "_rls");
	createIpoutSubfolder(false, "_rls", rlssref);

	createIpoutSubfolder(true, cmpsref);

	// -- all units
	for (unsigned int i = 0; i < unts.nodes.size(); i++) {
		unt = unts.nodes[i];
		createIpoutSubfolder(true, cmpsref, unt->sref);
	};

	// --- prepare standard key/value pairs


	// -- created date
	time_t rawtime;
	time(&rawtime);

	created = StrMod::timetToString(rawtime);

	// -- directories
	Wdbe::getMchpar(dbswdbe, rls->refWdbeMMachine, hrefsMch, "reproot", reproot);

	// --- deployment scripts (WdbeWrfpgaDeploy)
	keys.resize(0); vals.resize(0);
	keys.push_back("author"); vals.push_back(author);
	keys.push_back("created"); vals.push_back(created);
	keys.push_back("Prjshort"); vals.push_back(Prjshort);
	keys.push_back("prjshort"); vals.push_back(prjshort);
	keys.push_back("rlssref"); vals.push_back(rlssref);
	keys.push_back("reproot"); vals.push_back(reproot);

	keys.push_back("untsref"); vals.push_back("untsref");
	keys.push_back("unttit"); vals.push_back("unttit");

	found = (unts.nodes.size() > 0);

	if (found) {
		addInv(new DpchInvWdbeWrfpgaDeploy(0, 0, rls->ref, ipfolder + "/_rls/" + rlssref));
		addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refChkoutfile, "", outfolder + "/_rls/" + rlssref + "/checkout.sh", keys, vals));
	};

	for (unsigned int i = 0; i < unts.nodes.size(); i++) {
		unt = unts.nodes[i];

		vals[vals.size()-2] = unt->sref;
		vals[vals.size()-1] = unt->Title;

		if (unt->srefKToolch == "ise") addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refChkinisefile, "", outfolder + "/_rls/" + rlssref + "/checkin_" + unt->sref + ".sh", keys, vals));
		else if (unt->srefKToolch == "vivado") addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refChkinvivfile, "", outfolder + "/_rls/" + rlssref + "/checkin_" + unt->sref + ".sh", keys, vals));
	};

	if (!dplonly) {
		// --- units (WdbeWrfpgaUnt)
		keys.resize(0); vals.resize(0);
		keys.push_back("author"); vals.push_back(author);
		keys.push_back("created"); vals.push_back(created);
		keys.push_back("Prjshort"); vals.push_back(Prjshort);

		keys.push_back("Untsref"); vals.push_back("Untsref");
		keys.push_back("unttit"); vals.push_back("unttit");

		for (unsigned int i = 0; i < unts.nodes.size(); i++) {
			unt = unts.nodes[i];

			Untsref = StrMod::cap(unt->sref);

			vals[vals.size()-2] = Untsref;
			vals[vals.size()-1] = unt->Title;

			if (unt->srefKToolch == "ise") addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refUntUcffile, "", outfolder + "/" + cmpsref + "/" + unt->sref + "/" + Untsref + ".ucf", keys, vals));
			else if (unt->srefKToolch == "libero") addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refUntMchpPdcfile, "", outfolder + "/" + cmpsref + "/" + unt->sref + "/" + Untsref + ".pdc", keys, vals));
			else if (unt->srefKToolch == "radiant") addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refUntLttcPdcfile, "", outfolder + "/" + cmpsref + "/" + unt->sref + "/" + Untsref + ".pdc", keys, vals));
			else if (unt->srefKToolch == "efinity") addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refUntIsffile, "", outfolder + "/" + cmpsref + "/" + unt->sref + "/" + Untsref + ".isf", keys, vals));
			else if (unt->srefKToolch == "vivado") addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refUntXdcfile, "", outfolder + "/" + cmpsref + "/" + unt->sref + "/" + Untsref + ".xdc", keys, vals));

			if (unt->Easy) addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refEzuntVhdfile, "", outfolder + "/" + cmpsref + "/" + unt->sref + "/" + Untsref + ".vhd", keys, vals));
			else addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refUntVhdfile, "", outfolder + "/" + cmpsref + "/" + unt->sref + "/" + Untsref + ".vhd", keys, vals));

			addInv(new DpchInvWdbeWrfpgaBase(0, 0, unt->ref, ipfolder + "/" + cmpsref + "/" + unt->sref, Prjshort, Untsref));
		};

		// --- modules (WdbeWrfpga...)
		keys.resize(0); vals.resize(0);
		keys.push_back("author"); vals.push_back(author);
		keys.push_back("created"); vals.push_back(created);

		keys.push_back("Untsref"); vals.push_back("Untsref");
		keys.push_back("Compsref"); vals.push_back("Compsref");
		keys.push_back("mdltype"); vals.push_back("mdltype");

		N = keys.size();

		for (unsigned int i = 0; i < unts.nodes.size(); i++) {
			unt = unts.nodes[i];

			Untsref = StrMod::cap(unt->sref);
			vals[vals.size()-3] = Untsref;

			dbswdbe->tblwdbemmodule->loadRstBySQL("SELECT * FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND hkUref = " + to_string(unt->ref), false, mdls);

			for (unsigned int j = 0; j < mdls.nodes.size(); j++) {
				mdl = mdls.nodes[j];

				Compsref = StrMod::cap(Wdbe::getCompsref(dbswdbe, mdl));

				mtp = NULL;
				mtf = NULL;

				auto it = refsMtps.find(mdl->tplRefWdbeMModule);
				if (it != refsMtps.end()) {
					mtp = it->second;

					auto it = mtprefsMtfs.find(mtp->ref);
					if (it != mtprefsMtfs.end()) mtf = it->second;
				};

				if (mtp) if ((mtp->ixVBasetype == VecWdbeVMModuleBasetype::MNFCORE) || (mtp->ixVBasetype == VecWdbeVMModuleBasetype::MNFPRIM)) continue;

				hassub = false;
				for (unsigned int k = 0; k < mdls.nodes.size(); k++)
					if (mdls.nodes[k]->supRefWdbeMModule == mdl->ref) {
						hassub = true;
						break;
					};

				// - base file (WdbePrcfilePlhrpl)
				vals[vals.size()-2] = Compsref;

				if (mtp) vals[vals.size()-1] = StubWdbe::getStubMtpStd(dbswdbe, mtp->ref);
				else {
					vals[vals.size()-1] = VecWdbeVMModuleBasetype::getTitle(mdl->ixVBasetype, ixWdbeVLocale);
					if ((mdl->ixVBasetype == VecWdbeVMModuleBasetype::TOP) || (mdl->ixVBasetype == VecWdbeVMModuleBasetype::OTH)) vals[vals.size()-1] += " module";
				};

				// add specific placeholders
				auto it2 = ics0Typkeys.find(mdl->ref);
				auto it3 = ics1Typkeys.find(mdl->ref);
				
				if (it2 != ics0Typkeys.end()) {
					for (unsigned int k = it2->second; k < it3->second; k++) {
						keys.push_back(typkeys[k]);
						vals.push_back(typvals[k]);
					};
				};

				it2 = ics0Tplkeys.find(mdl->ref);
				it3 = ics1Tplkeys.find(mdl->ref);
				
				if (it2 != ics0Tplkeys.end()) {
					for (unsigned int k = it2->second; k < it3->second; k++) {
						keys.push_back(tplkeys[k]);
						vals.push_back(tplvals[k]);
					};
				};

				if (mtp && mtf) {
					// potentially specific placeholders or IP's
					addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, mtf->ref, "", outfolder + "/" + cmpsref + "/" + unt->sref + "/" + Compsref + ".vhd", keys, vals));

				} else {
					// empty module template file
					addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refMdlVhdfile, "", outfolder + "/" + cmpsref + "/" + unt->sref + "/" + Compsref + ".vhd", keys, vals));
				};

				// remove specific placeholders
				keys.resize(N);
				vals.resize(N);

				// - non-specific IP's (WdbeWrfpgaMdl)
				addInv(new DpchInvWdbeWrfpgaMdlraw(0, 0, mdl->ref, ipfolder + "/" + cmpsref + "/" + unt->sref, Prjshort, Untsref, unt->srefKToolch));
				addInv(new DpchInvWdbeWrfpgaMdlfine(0, 0, mdl->ref, finefolder + "/" + cmpsref + "/" + unt->sref));
				addInv(new DpchInvWdbeWrfpgaAux(0, 0, mdl->ref, auxfolder + "/" + cmpsref + "/" + unt->sref));

				// - type-specific IP's (WdbeWrfpga<type>)
				if (mdl->ixVBasetype == VecWdbeVMModuleBasetype::TOP) {
					addInv(new DpchInvWdbeWrfpgaTop(0, 0, mdl->ref, typspecfolder + "/" + cmpsref + "/" + unt->sref, Prjshort, Untsref));
				} else if ((mdl->ixVBasetype == VecWdbeVMModuleBasetype::CTR) || (mdl->ixVBasetype == VecWdbeVMModuleBasetype::DBGCTR)) {
					addInv(new DpchInvWdbeWrfpgaCtr(0, 0, mdl->ref, typspecfolder + "/" + cmpsref + "/" + unt->sref, Prjshort, Untsref));
				};

				// - template-specific IP's (WdbeMtpWrfpga<template>)
				if (mtp) {
					auto it = srefsMtpWrfpgaCustops.find(mtp->ref);
					if (it != srefsMtpWrfpgaCustops.end()) addInv(new DpchInvWdbeMtpWrfpga(0, it->second, 0, mdl->ref, tplspecfolder + "/" + cmpsref + "/" + unt->sref, Prjshort, Untsref));
				};

			};
		};
	};

	// --- clean up
	delete rls;
	delete cmp;
	delete ver;
};

void DlgWdbeRlsWrite::createMcu(
			DbsWdbe* dbswdbe
			, const bool dplonly
		) {
	ubigint ref;

	WdbeMRelease* rls = NULL;
	WdbeMComponent* cmp = NULL;
	WdbeMVersion* ver = NULL;

	vector<ubigint> hrefsMch;

	string created;
	string reproot;

	vector<string> keys;
	vector<string> vals;

	ListWdbeMUnit unts;
	WdbeMUnit* unt = NULL;

	string Untsref;

	ListWdbeMModule mtps;
	map<ubigint,WdbeMModule*> refsMtps;
	WdbeMModule* mtp = NULL;

	ListWdbeMFile mthfs;
	map<ubigint,WdbeMFile*> mtprefsMthfs;
	WdbeMFile* mthf = NULL;

	ListWdbeMFile mtfs;
	map<ubigint,WdbeMFile*> mtprefsMtfs;
	WdbeMFile* mtf = NULL;

	map<ubigint,string> srefsMtpPlhmcuCustops;
	map<ubigint,string> srefsMtpWrmcuCustops;

	ListWdbeMModule mdls;
	map<ubigint,string> srefsMdls;
	WdbeMModule* mdl = NULL;

	ListWdbeRMModuleMModule mdlRmdls;
	WdbeRMModuleMModule* mdlRmdl = NULL;

	ListWdbeAMModulePar mdlApars;
	WdbeAMModulePar* mdlApar = NULL;

	string Compsref;

	bool hassub;

	unsigned int N;

	string s;

	bool found;

	// --- load basics
	dbswdbe->tblwdbemrelease->loadRecByRef(refWdbeMRelease, &rls);
	dbswdbe->tblwdbemcomponent->loadRecByRef(rls->refWdbeMComponent, &cmp);
	dbswdbe->tblwdbemversion->loadRecByRef(cmp->refWdbeMVersion, &ver);

	dbswdbe->tblwdbemmachine->loadHrefsup(rls->refWdbeMMachine, hrefsMch);

	dbswdbe->tblwdbemunit->loadRstBySQL("SELECT * FROM TblWdbeMUnit WHERE refIxVTbl = " + to_string(VecWdbeVMUnitRefTbl::VER) + " AND refUref = " + to_string(ver->ref) + " AND ixVBasetype = " + to_string(VecWdbeVMUnitBasetype::MCU)
				+ " ORDER BY sref ASC", false, unts);

	dbswdbe->tblwdbemmodule->loadRstBySQL("SELECT * FROM TblWdbeMModule WHERE ((hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::VOID) + ") AND (supRefWdbeMModule = 0) AND (tplRefWdbeMModule = 0)) ORDER BY sref ASC", false, mtps);
	for (unsigned int i = 0; i < mtps.nodes.size(); i++) {
		mtp = mtps.nodes[i];

		refsMtps[mtp->ref] = mtp;

		if (dbswdbe->tblwdbemfile->loadRstBySQL("SELECT * FROM TblWdbeMFile WHERE refIxVTbl = " + to_string(VecWdbeVMFileRefTbl::MTP) + " AND refUref = " + to_string(mtp->ref) + " AND Filename = '" + StrMod::cap(mtp->sref) + ".h'", true, mthfs) == 1)
					mtprefsMthfs[mtp->ref] = mthfs.nodes[mthfs.nodes.size()-1];

		if (dbswdbe->tblwdbemfile->loadRstBySQL("SELECT * FROM TblWdbeMFile WHERE refIxVTbl = " + to_string(VecWdbeVMFileRefTbl::MTP) + " AND refUref = " + to_string(mtp->ref) + " AND Filename = '" + StrMod::cap(mtp->sref) + ".c'", true, mtfs) == 1)
					mtprefsMtfs[mtp->ref] = mtfs.nodes[mtfs.nodes.size()-1];
	};

	Wdbe::getSrefsMtpCustops(dbswdbe, srefsMtpPlhmcuCustops, VecWdbeVKeylist::KLSTKWDBEMTPPLHMCUCUSTOP);
	Wdbe::getSrefsMtpCustops(dbswdbe, srefsMtpWrmcuCustops, VecWdbeVKeylist::KLSTKWDBEMTPWRMCUCUSTOP);

	// --- find template files in archive
	ubigint refUntHfile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Xxxx_Mcu.h'", refUntHfile);
	ubigint refUntCfile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Xxxx_Mcu.c'", refUntCfile);
	ubigint refUntExeCfile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Xxxx_exe_Mcu.c'", refUntExeCfile);
	ubigint refMdlHfile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Xxxxx_Mcu.h'", refMdlHfile);
	ubigint refMdlCfile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Xxxxx_Mcu.c'", refMdlCfile);

	// --- generate folder structure
	ipfolder = Tmp::newfolder(xchg->tmppath);
	finefolder = Tmp::newfolder(xchg->tmppath);
	typspecfolder = Tmp::newfolder(xchg->tmppath);
	tplspecfolder = Tmp::newfolder(xchg->tmppath);

	outfolder = xchg->getTxtvalPreset(VecWdbeVPreset::PREWDBEREPFOLDER, jref);
	if (outfolder == "") outfolder = Tmp::newfolder(xchg->tmppath);

	createIpoutSubfolder(false, "_rls");
	createIpoutSubfolder(false, "_rls", rlssref);

	createIpoutSubfolder(true, cmpsref);

	// -- all units
	for (unsigned int i = 0; i < unts.nodes.size(); i++) {
		unt = unts.nodes[i];
		createIpoutSubfolder(true, cmpsref, unt->sref);
	};

	// --- prepare standard key/value pairs

	// -- created date
	time_t rawtime;
	time(&rawtime);

	created = StrMod::timetToString(rawtime);

	// -- directories and number of cores
	Wdbe::getMchpar(dbswdbe, rls->refWdbeMMachine, hrefsMch, "reproot", reproot);

	// --- deployment scripts (WdbeWrmcuDeploy)
	keys.resize(0); vals.resize(0);
	keys.push_back("author"); vals.push_back(author);
	keys.push_back("created"); vals.push_back(created);
	keys.push_back("Prjshort"); vals.push_back(Prjshort);
	keys.push_back("prjshort"); vals.push_back(prjshort);
	keys.push_back("rlssref"); vals.push_back(rlssref);
	keys.push_back("reproot"); vals.push_back(reproot);

	keys.push_back("untsref"); vals.push_back("untsref");
	keys.push_back("unttit"); vals.push_back("unttit");

	found = (unts.nodes.size() > 0);

	if (found) {
		addInv(new DpchInvWdbeWrmcuDeploy(0, 0, rls->ref, ipfolder + "/_rls/" + rlssref));
	};

	if (!dplonly) {
		// --- units (WdbeWrmcuUnt)
		keys.resize(0); vals.resize(0);
		keys.push_back("author"); vals.push_back(author);
		keys.push_back("created"); vals.push_back(created);
		keys.push_back("Prjshort"); vals.push_back(Prjshort);

		keys.push_back("UNTSREF"); vals.push_back("UNTSREF");
		keys.push_back("Untsref"); vals.push_back("Untsref");
		keys.push_back("untsref"); vals.push_back("untsref");

		for (unsigned int i = 0; i < unts.nodes.size(); i++) {
			unt = unts.nodes[i];

			Untsref = StrMod::cap(unt->sref);

			vals[vals.size()-3] = StrMod::uc(unt->sref);
			vals[vals.size()-2] = Untsref;
			vals[vals.size()-1] = StrMod::lc(unt->sref);

			addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refUntHfile, "", outfolder + "/" + cmpsref + "/" + unt->sref + "/" + Untsref + ".h", keys, vals));
			addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refUntCfile, "", outfolder + "/" + cmpsref + "/" + unt->sref + "/" + Untsref + ".c", keys, vals));

			addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refUntExeCfile, "", outfolder + "/" + cmpsref + "/" + unt->sref + "/" + Untsref + "_exe.c", keys, vals));

			addInv(new DpchInvWdbeWrmcuBase(0, 0, unt->ref, ipfolder + "/" + cmpsref + "/" + unt->sref, Prjshort, Untsref));
		};

		// --- modules (WdbeWrmcu...) ; adapted copy (no IMBUF/MNFPRIM/MNFCORE) from createFpga()
		keys.resize(0); vals.resize(0);
		keys.push_back("author"); vals.push_back(author);
		keys.push_back("created"); vals.push_back(created);

		keys.push_back("Untsref"); vals.push_back("Untsref");
		keys.push_back("COMPSREF"); vals.push_back("COMPSREF");
		keys.push_back("Compsref"); vals.push_back("Compsref");
		keys.push_back("compsref"); vals.push_back("compsref");
		keys.push_back("mdltype"); vals.push_back("mdltype");

		N = keys.size();

		for (unsigned int i = 0; i < unts.nodes.size(); i++) {
			unt = unts.nodes[i];

			Untsref = StrMod::cap(unt->sref);

			vals[vals.size()-5] = Untsref;

			dbswdbe->tblwdbemmodule->loadRstBySQL("SELECT * FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND hkUref = " + to_string(unt->ref), false, mdls);
			srefsMdls.clear();
			for (unsigned int j = 0; j < mdls.nodes.size(); j++) srefsMdls[mdls.nodes[j]->ref] = mdls.nodes[j]->sref;

			for (unsigned int j = 0; j < mdls.nodes.size(); j++) {
				mdl = mdls.nodes[j];

				if (mdl->ixVBasetype == VecWdbeVMModuleBasetype::IMBUF) continue;

				Compsref = StrMod::cap(mdl->sref);

				mtp = NULL;
				mthf = NULL;
				mtf = NULL;

				auto it = refsMtps.find(mdl->tplRefWdbeMModule);
				if (it != refsMtps.end()) {
					mtp = it->second;

					auto it2 = mtprefsMthfs.find(mtp->ref);
					if (it2 != mtprefsMthfs.end()) mthf = it2->second;

					it2 = mtprefsMtfs.find(mtp->ref);
					if (it2 != mtprefsMtfs.end()) mtf = it2->second;
				};

				hassub = false;
				for (unsigned int k = 0; k < mdls.nodes.size(); k++)
					if (mdls.nodes[k]->supRefWdbeMModule == mdl->ref) {
						hassub = true;
						break;
					};

				// - base file (WdbePrcfilePlhrpl)
				vals[vals.size()-4] = StrMod::uc(Compsref);
				vals[vals.size()-3] = Compsref;
				vals[vals.size()-2] = StrMod::lc(Compsref);

				if (mtp) vals[vals.size()-1] = StubWdbe::getStubMtpStd(dbswdbe, mtp->ref);
				else {
					vals[vals.size()-1] = VecWdbeVMModuleBasetype::getTitle(mdl->ixVBasetype, ixWdbeVLocale);
					if ((mdl->ixVBasetype == VecWdbeVMModuleBasetype::TOP) || (mdl->ixVBasetype == VecWdbeVMModuleBasetype::OTH)) vals[vals.size()-1] += " module";
				};

				// add identifiers of all corresponding modules as placeholders
				dbswdbe->tblwdbermmodulemmodule->loadRstByCtd(mdl->ref, false, mdlRmdls);

				for (unsigned int k = 0; k < mdlRmdls.nodes.size(); k++) {
					mdlRmdl = mdlRmdls.nodes[k];

					auto it = srefsMdls.find(mdlRmdl->corRefWdbeMModule);
					if (it != srefsMdls.end()) {
						keys.push_back(StrMod::lc(mdlRmdl->srefKFunction));
						vals.push_back(StrMod::lc(it->second));

						keys.push_back(StrMod::cap(mdlRmdl->srefKFunction));
						vals.push_back(StrMod::cap(it->second));

						keys.push_back(StrMod::uc(mdlRmdl->srefKFunction));
						vals.push_back(StrMod::uc(it->second));
					};
				};

				// add module parameters as placeholders
				dbswdbe->tblwdbeammodulepar->loadRstByMdl(mdl->ref, false, mdlApars);

				for (unsigned int k = 0; k < mdlApars.nodes.size(); k++) {
					mdlApar = mdlApars.nodes[k];

					keys.push_back(mdlApar->x1SrefKKey);
					vals.push_back(mdlApar->Val);
				};

				// add specific placeholders
				auto it2 = ics0Typkeys.find(mdl->ref);
				auto it3 = ics1Typkeys.find(mdl->ref);
				
				if (it2 != ics0Typkeys.end()) {
					for (unsigned int k = it2->second; k < it3->second; k++) {
						keys.push_back(typkeys[k]);
						vals.push_back(typvals[k]);
					};
				};

				it2 = ics0Tplkeys.find(mdl->ref);
				it3 = ics1Tplkeys.find(mdl->ref);
				
				if (it2 != ics0Tplkeys.end()) {
					for (unsigned int k = it2->second; k < it3->second; k++) {
						keys.push_back(tplkeys[k]);
						vals.push_back(tplvals[k]);
					};
				};

				if (mtp && mthf) addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, mthf->ref, "", outfolder + "/" + cmpsref + "/" + unt->sref + "/" + Compsref + ".h", keys, vals));
				else addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refMdlHfile, "", outfolder + "/" + cmpsref + "/" + unt->sref + "/" + Compsref + ".h", keys, vals));

				if (mtp && mtf) addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, mtf->ref, "", outfolder + "/" + cmpsref + "/" + unt->sref + "/" + Compsref + ".c", keys, vals));
				else addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refMdlCfile, "", outfolder + "/" + cmpsref + "/" + unt->sref + "/" + Compsref + ".c", keys, vals));

				// remove specific placeholders
				keys.resize(N);
				vals.resize(N);

				// - non-specific IP's (WdbeWrmcuMdl)
				addInv(new DpchInvWdbeWrmcuMdlraw(0, 0, mdl->ref, ipfolder + "/" + cmpsref + "/" + unt->sref, Prjshort, Untsref));
				addInv(new DpchInvWdbeWrmcuMdlfine(0, 0, mdl->ref, finefolder + "/" + cmpsref + "/" + unt->sref));

				// - type-specific IP's (WdbeWrmcu<type>)
				if (mdl->ixVBasetype == VecWdbeVMModuleBasetype::CTR) {
					addInv(new DpchInvWdbeWrmcuCtr(0, 0, mdl->ref, typspecfolder + "/" + cmpsref + "/" + unt->sref, Prjshort, Untsref));
				};

				// - template-specific IP's (WdbeMtpWrmcu<template>)
				if (mtp) {
					auto it = srefsMtpWrmcuCustops.find(mtp->ref);
					if (it != srefsMtpWrmcuCustops.end()) addInv(new DpchInvWdbeMtpWrmcu(0, it->second, 0, mdl->ref, tplspecfolder + "/" + cmpsref + "/" + unt->sref, Prjshort, Untsref));
				};
			};
		};
	};

	// --- clean up
	delete rls;
	delete cmp;
	delete ver;
};

void DlgWdbeRlsWrite::createDev(
			DbsWdbe* dbswdbe
			, const bool dplonly
		) {
	vector<ubigint> refs, refs2;
	ubigint ref;

	WdbeMRelease* rls = NULL;
	WdbeMComponent* cmp = NULL;
	WdbeMVersion* ver = NULL;

	vector<ubigint> hrefsMch;

	string created;
	string vermajor, verminor, versub;
	string buildroot, libroot;

	vector<string> keys;
	vector<string> vals;

	ListWdbeMUnit unts;
	WdbeMUnit* unt = NULL;

	string srefroot;

	ListWdbeMVector vecs;

	ListWdbeMController ctrs;
	WdbeMController* ctr = NULL;

	ListWdbeMImbuf imbs;
	ListWdbeMCommand cmds;
	ListWdbeMError errs;

	ubigint refHostif;
	uint ixImbCmdinv, ixImbCmdret;
	bool hasvecbuf, hasvecctr, hasveccmd, hasvecerr, hasspeccmd;

	string sref, srefrootMgmt, srefrootCor;

	uint num;

	string s;

	// --- load basics
	dbswdbe->tblwdbemrelease->loadRecByRef(refWdbeMRelease, &rls);
	dbswdbe->tblwdbemcomponent->loadRecByRef(rls->refWdbeMComponent, &cmp);
	dbswdbe->tblwdbemversion->loadRecByRef(cmp->refWdbeMVersion, &ver);

	dbswdbe->tblwdbemmachine->loadHrefsup(rls->refWdbeMMachine, hrefsMch);

	dbswdbe->tblwdbemunit->loadRstBySQL("SELECT * FROM TblWdbeMUnit WHERE refIxVTbl = " + to_string(VecWdbeVMUnitRefTbl::VER) + " AND refUref = " + to_string(ver->ref) + " ORDER BY sref ASC", false, unts);

	// --- find template files in archive
	ubigint refChkoutfile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'checkout_Dev.sh'", refChkoutfile);
	ubigint refMakefile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Makefile'", refMakefile);
	ubigint refMkallfile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'makeall.sh'", refMkallfile);

	ubigint refGblhfile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Xxxx.h'", refGblhfile);
	ubigint refGblcppfile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Xxxx.cpp'", refGblcppfile);

	ubigint refDevhfile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'DevXxxx.h'", refDevhfile);

	ubigint refUnthfile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'UntXxxxYyyy.h'", refUnthfile);
	ubigint refUntcppfile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'UntXxxxYyyy.cpp'", refUntcppfile);

	ubigint refUntvechfile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'UntXxxxYyyy_vecs.h'", refUntvechfile);
	ubigint refUntveccppfile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'UntXxxxYyyy_vecs.cpp'", refUntveccppfile);

	ubigint refCtrhfile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'CtrXxxxYyyyZzzzz.h'", refCtrhfile);
	ubigint refCtrcppfile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'CtrXxxxYyyyZzzzz.cpp'", refCtrcppfile);

	// --- generate folder structure
	ipfolder = Tmp::newfolder(xchg->tmppath);

	outfolder = xchg->getTxtvalPreset(VecWdbeVPreset::PREWDBEREPFOLDER, jref);
	if (outfolder == "") outfolder = Tmp::newfolder(xchg->tmppath);

	createIpoutSubfolder(false, "_rls");
	createIpoutSubfolder(false, "_rls", rlssref);

	createIpoutSubfolder(false, cmpsref);

	// -- all units
	for (unsigned int i = 0; i < unts.nodes.size(); i++) {
		unt = unts.nodes[i];
		createIpoutSubfolder(false, cmpsref, unt->Fullsref);
	};

	// --- prepare standard key/value pairs

	// -- created date
	time_t rawtime;
	time(&rawtime);

	created = StrMod::timetToString(rawtime);

	// -- version
	vermajor = to_string(ver->Major);
	verminor = to_string(ver->Minor);
	versub = to_string(ver->Sub);

	// -- directories
	Wdbe::getMchpar(dbswdbe, rls->refWdbeMMachine, hrefsMch, "buildroot", buildroot);
	Wdbe::getMchpar(dbswdbe, rls->refWdbeMMachine, hrefsMch, "libroot", libroot);

	// --- deployment scripts (WdbeWrdevDeploy)
	keys.resize(0); vals.resize(0);
	keys.push_back("author"); vals.push_back(author);
	keys.push_back("created"); vals.push_back(created);

	keys.push_back("inclibeq"); vals.push_back(inclibeq);
	keys.push_back("ez"); vals.push_back("");

	keys.push_back("Prjshort"); vals.push_back(Prjshort);
	keys.push_back("prjshort"); vals.push_back(prjshort);
	keys.push_back("rlssref"); vals.push_back(rlssref);
	keys.push_back("cchost"); vals.push_back(cchost);

	keys.push_back("sysroot"); vals.push_back(sysroot);
	keys.push_back("buildroot"); vals.push_back(buildroot);
	keys.push_back("libroot"); vals.push_back(libroot);
	keys.push_back("ncore"); vals.push_back(ncore);

	addInv(new DpchInvWdbeWrdevDeploy(0, 0, rls->ref, ipfolder + "/_rls/" + rlssref, false));

	addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refChkoutfile, "", outfolder + "/_rls/" + rlssref + "/checkout.sh", keys, vals));
	addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refMakefile, "", outfolder + "/_rls/" + rlssref + "/Makefile", keys, vals));
	addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refMkallfile, "", outfolder + "/_rls/" + rlssref + "/makeall.sh", keys, vals));

	if (!dplonly) {
		// --- device globals (WdbeWrdevBase)
		keys.resize(0); vals.resize(0);
		keys.push_back("author"); vals.push_back(author);
		keys.push_back("created"); vals.push_back(created);
		keys.push_back("PRJSHORT"); vals.push_back(PRJSHORT);
		keys.push_back("Prjshort"); vals.push_back(Prjshort);
		keys.push_back("vermajor"); vals.push_back(vermajor);
		keys.push_back("verminor"); vals.push_back(verminor);
		keys.push_back("versub"); vals.push_back(versub);

		addInv(new DpchInvWdbeWrdevBase(0, 0, ver->ref, ipfolder + "/" + cmpsref, Prjshort, false));

		addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refGblhfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + ".h", keys, vals));
		addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refGblcppfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + ".cpp", keys, vals));
		addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refDevhfile, "", outfolder + "/" + cmpsref + "/Dev" + Prjshort + ".h", keys, vals));

		// --- units (WdbeWrdevUnt)
		keys.resize(0); vals.resize(0);
		keys.push_back("author"); vals.push_back(author);
		keys.push_back("created"); vals.push_back(created);
		keys.push_back("Prjshort"); vals.push_back(Prjshort);

		keys.push_back("Untsref"); vals.push_back("Untsref");
		keys.push_back("UNTFULLSREF"); vals.push_back("UNTFULLSREF");
		keys.push_back("Untfullsref"); vals.push_back("Untfullsref");
		keys.push_back("unttit"); vals.push_back("unttit");

		for (unsigned int i = 0; i < unts.nodes.size(); i++) {
			unt = unts.nodes[i];

			vals[vals.size()-4] = StrMod::cap(unt->sref);
			vals[vals.size()-3] = StrMod::uc(unt->Fullsref);
			vals[vals.size()-2] = unt->Fullsref;
			vals[vals.size()-1] = unt->Title;

			addInv(new DpchInvWdbeWrdevUnt(0, 0, unt->ref, ipfolder + "/" + cmpsref + "/" + unt->Fullsref, false));

			addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refUnthfile, "", outfolder + "/" + cmpsref + "/" + unt->Fullsref + "/" + unt->Fullsref + ".h", keys, vals));
			addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refUntcppfile, "", outfolder + "/" + cmpsref + "/" + unt->Fullsref + "/" + unt->Fullsref + ".cpp", keys, vals));
			addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refUntvechfile, "", outfolder + "/" + cmpsref + "/" + unt->Fullsref + "/" + unt->Fullsref + "_vecs.h", keys, vals));
			addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refUntveccppfile, "", outfolder + "/" + cmpsref + "/" + unt->Fullsref + "/" + unt->Fullsref + "_vecs.cpp", keys, vals));
		};

		// --- controllers (WdbeWrdevCtr)
		keys.resize(0); vals.resize(0);
		keys.push_back("author"); vals.push_back(author);
		keys.push_back("created"); vals.push_back(created);
		keys.push_back("Prjshort"); vals.push_back(Prjshort);

		keys.push_back("mdlsref"); vals.push_back("mdlsref");
		keys.push_back("CTRFULLSREF"); vals.push_back("CTRFULLSREF");
		keys.push_back("Ctrfullsref"); vals.push_back("Ctrfullsref");
		keys.push_back("tix"); vals.push_back("tix");

		for (unsigned int i = 0; i < unts.nodes.size(); i++) {
			unt = unts.nodes[i];

			dbswdbe->tblwdbemcontroller->loadRstBySQL("SELECT TblWdbeMController.* FROM TblWdbeMController, TblWdbeMModule WHERE TblWdbeMController.refWdbeMModule = TblWdbeMModule.ref AND TblWdbeMModule.hkIxVTbl = "
						+ to_string(VecWdbeVMModuleHkTbl::UNT) + " AND TblWdbeMModule.hkUref = " + to_string(unt->ref), false, ctrs);

			for (unsigned int j = 0; j < ctrs.nodes.size(); j++) {
				ctr = ctrs.nodes[j];

				vals[vals.size()-4] = "mdlsref";
				dbswdbe->loadStringBySQL("SELECT sref FROM TblWdbeMModule WHERE ref = " + to_string(ctr->refWdbeMModule), vals[vals.size()-4]);

				vals[vals.size()-3] = StrMod::uc(ctr->Fullsref);
				vals[vals.size()-2] = ctr->Fullsref;

				vals[vals.size()-1] = "tix";
				if (dbswdbe->loadUintBySQL("SELECT TblWdbeMVectoritem.vecNum FROM TblWdbeMVector, TblWdbeMVectoritem WHERE TblWdbeMVector.hkIxVTbl = " + to_string(VecWdbeVMVectorHkTbl::UNT) + " AND TblWdbeMVector.hkUref = " + to_string(unt->ref)
							+ " AND TblWdbeMVectoritem.vecRefWdbeMVector = TblWdbeMVector.ref AND TblWdbeMVector.sref = 'VecV" + unt->Fullsref.substr(3) + "Controller' AND TblWdbeMVectoritem.sref = '" + vals[vals.size()-4] + "'", num))
					vals[vals.size()-1] = "0x" + Wdbe::binToHex(num);

				addInv(new DpchInvWdbeWrdevCtr(0, 0, ctr->ref, ipfolder + "/" + cmpsref + "/" + unt->Fullsref, false));

				addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refCtrhfile, "", outfolder + "/" + cmpsref + "/" + unt->Fullsref + "/" + ctr->Fullsref + ".h", keys, vals));
				addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refCtrcppfile, "", outfolder + "/" + cmpsref + "/" + unt->Fullsref + "/" + ctr->Fullsref + ".cpp", keys, vals));
			};
		};
	};

	// --- clean up
	delete rls;
	delete cmp;
	delete ver;
};

void DlgWdbeRlsWrite::createEzdev(
			DbsWdbe* dbswdbe
			, const bool dplonly
		) {
	vector<ubigint> refs;
	ubigint ref;

	WdbeMRelease* rls = NULL;
	WdbeMComponent* cmp = NULL;
	WdbeMVersion* ver = NULL;

	vector<ubigint> hrefsMch;

	string created;
	string vermajor, verminor, versub;
	string buildroot, libroot;

	vector<string> keys;
	vector<string> vals;

	ListWdbeMUnit unts;
	WdbeMUnit* unt = NULL;

	string srefroot;

	ListWdbeMVector vecs;

	ListWdbeMController ctrs;
	WdbeMController* ctr = NULL;

	unsigned int sizeInvbuf, sizeRetbuf;

	uint num;

	string s;

	// --- load basics
	dbswdbe->tblwdbemrelease->loadRecByRef(refWdbeMRelease, &rls);
	dbswdbe->tblwdbemcomponent->loadRecByRef(rls->refWdbeMComponent, &cmp);
	dbswdbe->tblwdbemversion->loadRecByRef(cmp->refWdbeMVersion, &ver);

	dbswdbe->tblwdbemmachine->loadHrefsup(rls->refWdbeMMachine, hrefsMch);

	if (Prjeasy) dbswdbe->tblwdbemunit->loadRstBySQL("SELECT * FROM TblWdbeMUnit WHERE refIxVTbl = " + to_string(VecWdbeVMUnitRefTbl::VER) + " AND refUref = " + to_string(ver->ref) + " ORDER BY sref ASC", false, unts);
	else dbswdbe->tblwdbemunit->loadRstBySQL("SELECT * FROM TblWdbeMUnit WHERE refIxVTbl = " + to_string(VecWdbeVMUnitRefTbl::VER) + " AND refUref = " + to_string(ver->ref) + " AND Easy = 1 ORDER BY sref ASC", false, unts);

	// --- find template files in archive
	ubigint refChkoutfile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'checkout_Dev.sh'", refChkoutfile);
	ubigint refMakefile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Makefile'", refMakefile);
	ubigint refMkallfile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'makeall.sh'", refMkallfile);

	ubigint refEzgblhfile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Xxxx_Easy.h'", refEzgblhfile);
	ubigint refEzgblcppfile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Xxxx_Easy.cpp'", refEzgblcppfile);

	ubigint refDevhfile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'DevXxxx.h'", refDevhfile);

	ubigint refEzunthfile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'UntXxxxYyyy_Easy.h'", refEzunthfile);
	ubigint refEzuntcppfile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'UntXxxxYyyy_Easy.cpp'", refEzuntcppfile);

	ubigint refUntvechfile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'UntXxxxYyyy_vecs.h'", refUntvechfile);
	ubigint refUntveccppfile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'UntXxxxYyyy_vecs.cpp'", refUntveccppfile);

	ubigint refCtrhfile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'CtrXxxxYyyyZzzzz.h'", refCtrhfile);
	ubigint refCtrcppfile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'CtrXxxxYyyyZzzzz.cpp'", refCtrcppfile);

	// --- generate folder structure
	ipfolder = Tmp::newfolder(xchg->tmppath);

	outfolder = xchg->getTxtvalPreset(VecWdbeVPreset::PREWDBEREPFOLDER, jref);
	if (outfolder == "") outfolder = Tmp::newfolder(xchg->tmppath);

	createIpoutSubfolder(false, "_rls");
	createIpoutSubfolder(false, "_rls", rlssref);

	createIpoutSubfolder(false, cmpsref);

	// -- all units
	for (unsigned int i = 0; i < unts.nodes.size(); i++) {
		unt = unts.nodes[i];
		createIpoutSubfolder(false, cmpsref, unt->Fullsref);
	};

	// --- prepare standard key/value pairs

	// -- created date
	time_t rawtime;
	time(&rawtime);

	created = StrMod::timetToString(rawtime);

	// -- version
	vermajor = to_string(ver->Major);
	verminor = to_string(ver->Minor);
	versub = to_string(ver->Sub);

	// -- directories
	Wdbe::getMchpar(dbswdbe, rls->refWdbeMMachine, hrefsMch, "buildroot", buildroot);
	Wdbe::getMchpar(dbswdbe, rls->refWdbeMMachine, hrefsMch, "libroot", libroot);

	// --- deployment scripts (WdbeWrdevDeploy)
	keys.resize(0); vals.resize(0);
	keys.push_back("author"); vals.push_back(author);
	keys.push_back("created"); vals.push_back(created);

	keys.push_back("inclibeq"); vals.push_back(inclibeq);
	keys.push_back("ez"); vals.push_back("ez");

	keys.push_back("Prjshort"); vals.push_back(Prjshort);
	keys.push_back("prjshort"); vals.push_back(prjshort);
	keys.push_back("rlssref"); vals.push_back(rlssref);
	keys.push_back("cchost"); vals.push_back(cchost);

	keys.push_back("sysroot"); vals.push_back(sysroot);
	keys.push_back("buildroot"); vals.push_back(buildroot);
	keys.push_back("libroot"); vals.push_back(libroot);
	keys.push_back("ncore"); vals.push_back(ncore);

	addInv(new DpchInvWdbeWrdevDeploy(0, 0, rls->ref, ipfolder + "/_rls/" + rlssref, true));

	addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refChkoutfile, "", outfolder + "/_rls/" + rlssref + "/checkout.sh", keys, vals));
	addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refMakefile, "", outfolder + "/_rls/" + rlssref + "/Makefile", keys, vals));
	addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refMkallfile, "", outfolder + "/_rls/" + rlssref + "/makeall.sh", keys, vals));

	if (!dplonly) {
		// --- device globals (WdbeWrdevBase)
		keys.resize(0); vals.resize(0);
		keys.push_back("author"); vals.push_back(author);
		keys.push_back("created"); vals.push_back(created);
		keys.push_back("PRJSHORT"); vals.push_back(PRJSHORT);
		keys.push_back("Prjshort"); vals.push_back(Prjshort);
		keys.push_back("vermajor"); vals.push_back(vermajor);
		keys.push_back("verminor"); vals.push_back(verminor);
		keys.push_back("versub"); vals.push_back(versub);

		addInv(new DpchInvWdbeWrdevBase(0, 0, ver->ref, ipfolder + "/" + cmpsref, Prjshort, true));

		addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refEzgblhfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + ".h", keys, vals));
		addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refEzgblcppfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + ".cpp", keys, vals));

		addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refDevhfile, "", outfolder + "/" + cmpsref + "/Dev" + Prjshort + ".h", keys, vals));

		// --- units (WdbeWrdevUnt)
		keys.resize(0); vals.resize(0);
		keys.push_back("author"); vals.push_back(author);
		keys.push_back("created"); vals.push_back(created);
		keys.push_back("Prjshort"); vals.push_back(Prjshort);

		keys.push_back("Untsref"); vals.push_back("Untsref");
		keys.push_back("UNTFULLSREF"); vals.push_back("UNTFULLSREF");
		keys.push_back("Untfullsref"); vals.push_back("Untfullsref");
		keys.push_back("unttit"); vals.push_back("unttit");

		for (unsigned int i = 0; i < unts.nodes.size(); i++) {
			unt = unts.nodes[i];

			vals[vals.size()-4] = StrMod::cap(unt->sref);
			vals[vals.size()-3] = StrMod::uc(unt->Fullsref);
			vals[vals.size()-2] = unt->Fullsref;
			vals[vals.size()-1] = unt->Title;

			addInv(new DpchInvWdbeWrdevUnt(0, 0, unt->ref, ipfolder + "/" + cmpsref + "/" + unt->Fullsref, true));

			addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refEzunthfile, "", outfolder + "/" + cmpsref + "/" + unt->Fullsref + "/" + unt->Fullsref + ".h", keys, vals));
			addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refEzuntcppfile, "", outfolder + "/" + cmpsref + "/" + unt->Fullsref + "/" + unt->Fullsref + ".cpp", keys, vals));

			addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refUntvechfile, "", outfolder + "/" + cmpsref + "/" + unt->Fullsref + "/" + unt->Fullsref + "_vecs.h", keys, vals));
			addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refUntveccppfile, "", outfolder + "/" + cmpsref + "/" + unt->Fullsref + "/" + unt->Fullsref + "_vecs.cpp", keys, vals));
		};

		// --- controllers (WdbeWrdevCtr)
		keys.resize(0); vals.resize(0);
		keys.push_back("author"); vals.push_back(author);
		keys.push_back("created"); vals.push_back(created);
		keys.push_back("Prjshort"); vals.push_back(Prjshort);

		keys.push_back("mdlsref"); vals.push_back("mdlsref");
		keys.push_back("CTRFULLSREF"); vals.push_back("CTRFULLSREF");
		keys.push_back("Ctrfullsref"); vals.push_back("Ctrfullsref");
		keys.push_back("tix"); vals.push_back("tix");

		for (unsigned int i = 0; i < unts.nodes.size(); i++) {
			unt = unts.nodes[i];

			dbswdbe->tblwdbemcontroller->loadRstBySQL("SELECT TblWdbeMController.* FROM TblWdbeMController, TblWdbeMModule WHERE TblWdbeMController.refWdbeMModule = TblWdbeMModule.ref AND TblWdbeMModule.hkIxVTbl = "
						+ to_string(VecWdbeVMModuleHkTbl::UNT) + " AND TblWdbeMModule.hkUref = " + to_string(unt->ref), false, ctrs);

			for (unsigned int j = 0; j < ctrs.nodes.size(); j++) {
				ctr = ctrs.nodes[j];

				vals[vals.size()-4] = "mdlsref";
				dbswdbe->loadStringBySQL("SELECT sref FROM TblWdbeMModule WHERE ref = " + to_string(ctr->refWdbeMModule), vals[vals.size()-4]);

				vals[vals.size()-3] = StrMod::uc(ctr->Fullsref);
				vals[vals.size()-2] = ctr->Fullsref;

				vals[vals.size()-1] = "tix";
				if (dbswdbe->loadUintBySQL("SELECT TblWdbeMVectoritem.vecNum FROM TblWdbeMVector, TblWdbeMVectoritem WHERE TblWdbeMVector.hkIxVTbl = " + to_string(VecWdbeVMVectorHkTbl::UNT) + " AND TblWdbeMVector.hkUref = " + to_string(unt->ref)
							+ " AND TblWdbeMVectoritem.vecRefWdbeMVector = TblWdbeMVector.ref AND TblWdbeMVector.sref = 'VecV" + unt->Fullsref.substr(3) + "Controller' AND TblWdbeMVectoritem.sref = '" + vals[vals.size()-4] + "'", num))
					vals[vals.size()-1] = "0x" + Wdbe::binToHex(num);

				addInv(new DpchInvWdbeWrdevCtr(0, 0, ctr->ref, ipfolder + "/" + cmpsref + "/" + unt->Fullsref, true));

				addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refCtrhfile, "", outfolder + "/" + cmpsref + "/" + unt->Fullsref + "/" + ctr->Fullsref + ".h", keys, vals));
				addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refCtrcppfile, "", outfolder + "/" + cmpsref + "/" + unt->Fullsref + "/" + ctr->Fullsref + ".cpp", keys, vals));
			};
		};
	};

	// --- clean up
	delete rls;
	delete cmp;
	delete ver;
};

void DlgWdbeRlsWrite::createTerm(
			DbsWdbe* dbswdbe
			, const bool dplonly
		) {
	// for the time being, Easy model only
	vector<ubigint> refs;
	ubigint ref;

	WdbeMRelease* rls = NULL;
	WdbeMComponent* cmp = NULL;
	WdbeMVersion* ver = NULL;

	vector<ubigint> hrefsMch;

	string created;
	string vermajor, verminor, versub;
	string buildroot, libroot, binroot;

	vector<string> keys;
	vector<string> vals;

	string srefroot;

	uint num;

	string s;

	// --- load basics
	dbswdbe->tblwdbemrelease->loadRecByRef(refWdbeMRelease, &rls);
	dbswdbe->tblwdbemcomponent->loadRecByRef(rls->refWdbeMComponent, &cmp);
	dbswdbe->tblwdbemversion->loadRecByRef(cmp->refWdbeMVersion, &ver);

	dbswdbe->tblwdbemmachine->loadHrefsup(rls->refWdbeMMachine, hrefsMch);

	// --- find template files in archive
	ubigint refChkoutfile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'checkout_Term.sh'", refChkoutfile);
	ubigint refMakefile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Makefile_Term'", refMakefile);

	ubigint refExehfile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Xxxxterm_exe.h'", refExehfile);
	ubigint refExecppfile; dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Xxxxterm_exe.cpp'", refExecppfile);

	// --- generate folder structure
	ipfolder = Tmp::newfolder(xchg->tmppath);

	outfolder = xchg->getTxtvalPreset(VecWdbeVPreset::PREWDBEREPFOLDER, jref);
	if (outfolder == "") outfolder = Tmp::newfolder(xchg->tmppath);

	createIpoutSubfolder(false, "_rls");
	createIpoutSubfolder(false, "_rls", rlssref);

	createIpoutSubfolder(false, cmpsref);

	// --- prepare standard key/value pairs

	// -- created date
	time_t rawtime;
	time(&rawtime);

	created = StrMod::timetToString(rawtime);

	// -- version
	vermajor = to_string(ver->Major);
	verminor = to_string(ver->Minor);
	versub = to_string(ver->Sub);

	// -- directories
	Wdbe::getMchpar(dbswdbe, rls->refWdbeMMachine, hrefsMch, "buildroot", buildroot);
	Wdbe::getMchpar(dbswdbe, rls->refWdbeMMachine, hrefsMch, "libroot", libroot);
	Wdbe::getMchpar(dbswdbe, rls->refWdbeMMachine, hrefsMch, "binroot", binroot);

	// --- deployment scripts (WdbeWrtermDeploy)
	keys.resize(0); vals.resize(0);
	keys.push_back("author"); vals.push_back(author);
	keys.push_back("created"); vals.push_back(created);

	keys.push_back("inclibeq"); vals.push_back(inclibeq);

	keys.push_back("Prjshort"); vals.push_back(Prjshort);
	keys.push_back("prjshort"); vals.push_back(prjshort);
	keys.push_back("cmpsref"); vals.push_back(cmpsref);
	keys.push_back("rlssref"); vals.push_back(rlssref);
	keys.push_back("cchost"); vals.push_back(cchost);

	keys.push_back("sysroot"); vals.push_back(sysroot);
	keys.push_back("buildroot"); vals.push_back(buildroot);
	keys.push_back("libroot"); vals.push_back(libroot);
	keys.push_back("binroot"); vals.push_back(binroot);

	addInv(new DpchInvWdbeWrtermDeploy(0, 0, rls->ref, ipfolder + "/_rls/" + rlssref, true));

	addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refChkoutfile, "", outfolder + "/_rls/" + rlssref + "/checkout.sh", keys, vals));
	addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refMakefile, "", outfolder + "/_rls/" + rlssref + "/Makefile", keys, vals));

	if (!dplonly) {
		// --- terminal globals (WdbeWrtermBase)
		keys.resize(0); vals.resize(0);
		keys.push_back("author"); vals.push_back(author);
		keys.push_back("created"); vals.push_back(created);
		keys.push_back("PRJSHORT"); vals.push_back(PRJSHORT);
		keys.push_back("Prjshort"); vals.push_back(Prjshort);
		keys.push_back("vermajor"); vals.push_back(vermajor);
		keys.push_back("verminor"); vals.push_back(verminor);
		keys.push_back("versub"); vals.push_back(versub);

		addInv(new DpchInvWdbeWrtermMain(0, 0, rls->ref, ipfolder + "/" + cmpsref, Prjshort, true));

		addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refExehfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + "term_exe.h", keys, vals));
		addInv(new DpchInvWdbePrcfilePlhrpl(0, 0, refExecppfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + "term_exe.cpp", keys, vals));
	};

	// --- clean up
	delete rls;
	delete cmp;
	delete ver;
};

void DlgWdbeRlsWrite::mergeKeysVals(
			const ubigint oref
			, vector<string>& keys
			, vector<string>& vals
			, const bool tplNotTyp
		) {
	if (keys.size() > 0) {
		auto it = orefsToRefs.find(oref);

		if (it != orefsToRefs.end()) {
			if (!tplNotTyp) {
				ics0Typkeys[it->second] = typkeys.size();

				typkeys.reserve(typkeys.size() + keys.size());
				typkeys.insert(typkeys.end(), keys.begin(), keys.end());

				typvals.reserve(typkeys.size() + keys.size());
				typvals.insert(typvals.end(), vals.begin(), vals.end());

				ics1Typkeys[it->second] = typkeys.size();

			} else {
				ics0Tplkeys[it->second] = tplkeys.size();

				tplkeys.reserve(tplkeys.size() + keys.size());
				tplkeys.insert(tplkeys.end(), keys.begin(), keys.end());

				tplvals.reserve(tplkeys.size() + keys.size());
				tplvals.insert(tplvals.end(), vals.begin(), vals.end());

				ics1Tplkeys[it->second] = tplkeys.size();
			};
		};
	};
};

// IP cust --- IEND

DpchEngWdbe* DlgWdbeRlsWrite::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWdbe* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWdbeConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &contiacdet, &continf, &continffia, &continflfi, &continfwrc, &feedFDse, &feedFSge, &statshr, &statshrcuc, &statshrfia, &statshrlfi, &statshrwrc, items);
	};

	return dpcheng;
};

void DlgWdbeRlsWrite::refreshDet(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContIacDet oldContiacdet(contiacdet);

	// IP refreshDet --- BEGIN
	// contiacdet

	// IP refreshDet --- END
	if (contiacdet.diff(&oldContiacdet).size() != 0) insert(moditems, DpchEngData::CONTIACDET);
};

void DlgWdbeRlsWrite::refreshCuc(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShrCuc oldStatshrcuc(statshrcuc);

	// IP refreshCuc --- BEGIN
	// statshrcuc
	statshrcuc.UldAvail = evalCucUldAvail(dbswdbe);
	statshrcuc.UldActive = evalCucUldActive(dbswdbe);

	// IP refreshCuc --- END
	if (statshrcuc.diff(&oldStatshrcuc).size() != 0) insert(moditems, DpchEngData::STATSHRCUC);
};

void DlgWdbeRlsWrite::refreshWrc(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	StatShrWrc oldStatshrwrc(statshrwrc);
	ContInfWrc oldContinfwrc(continfwrc);

	// IP refreshWrc --- RBEGIN
	// continfwrc
	continfwrc.TxtPrg = getSquawk(dbswdbe);

	// statshrwrc
	statshrwrc.ButAutActive = evalWrcButAutActive(dbswdbe);
	statshrwrc.ButRunActive = evalWrcButRunActive(dbswdbe);
	statshrwrc.ButStoActive = evalWrcButStoActive(dbswdbe);

	// IP refreshWrc --- REND
	if (statshrwrc.diff(&oldStatshrwrc).size() != 0) insert(moditems, DpchEngData::STATSHRWRC);
	if (continfwrc.diff(&oldContinfwrc).size() != 0) insert(moditems, DpchEngData::CONTINFWRC);
};

void DlgWdbeRlsWrite::refreshLfi(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContInfLfi oldContinflfi(continflfi);
	StatShrLfi oldStatshrlfi(statshrlfi);

	// IP refreshLfi --- RBEGIN
	// statshrlfi
	statshrlfi.DldActive = evalLfiDldActive(dbswdbe);

	// continflfi
	continflfi.Dld = "log.txt";

	// IP refreshLfi --- REND
	if (continflfi.diff(&oldContinflfi).size() != 0) insert(moditems, DpchEngData::CONTINFLFI);
	if (statshrlfi.diff(&oldStatshrlfi).size() != 0) insert(moditems, DpchEngData::STATSHRLFI);
};

void DlgWdbeRlsWrite::refreshFia(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
		) {
	ContInfFia oldContinffia(continffia);
	StatShrFia oldStatshrfia(statshrfia);

	// IP refreshFia --- RBEGIN
	// statshrfia
	statshrfia.DldActive = evalFiaDldActive(dbswdbe);

	// continffia
	continffia.Dld = StubWdbe::getStubRlsStd(dbswdbe, refWdbeMRelease) + ".tgz";

	// IP refreshFia --- REND
	if (continffia.diff(&oldContinffia).size() != 0) insert(moditems, DpchEngData::CONTINFFIA);
	if (statshrfia.diff(&oldStatshrfia).size() != 0) insert(moditems, DpchEngData::STATSHRFIA);
};

void DlgWdbeRlsWrite::refresh(
			DbsWdbe* dbswdbe
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	StatShr oldStatshr(statshr);
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);

	// IP refresh --- BEGIN
	// statshr
	statshr.ButDneActive = evalButDneActive(dbswdbe);

	// contiac
	contiac.numFDse = ixVDit;

	// continf
	continf.numFSge = ixVSge;

	// IP refresh --- END
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	refreshDet(dbswdbe, moditems);
	refreshCuc(dbswdbe, moditems);
	refreshWrc(dbswdbe, moditems);
	refreshLfi(dbswdbe, moditems);
	refreshFia(dbswdbe, moditems);

	muteRefresh = false;
};

void DlgWdbeRlsWrite::handleRequest(
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

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBERLSWRITEDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswdbe, &(dpchappdata->contiac), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::CONTIACDET)) {
				handleDpchAppDataContiacdet(dbswdbe, &(dpchappdata->contiacdet), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPDLGWDBERLSWRITEDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbswdbe, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoWrc != 0) {
				if (dpchappdo->ixVDoWrc == VecVDoWrc::BUTAUTCLICK) {
					handleDpchAppDoWrcButAutClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDoWrc == VecVDoWrc::BUTRUNCLICK) {
					handleDpchAppDoWrcButRunClick(dbswdbe, &(req->dpcheng));
				} else if (dpchappdo->ixVDoWrc == VecVDoWrc::BUTSTOCLICK) {
					handleDpchAppDoWrcButStoClick(dbswdbe, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPWDBEALERT) {
			handleDpchAppWdbeAlert(dbswdbe, (DpchAppWdbeAlert*) (req->dpchapp), &(req->dpcheng));

		};

	} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::UPLOAD) {
		if (ixVSge == VecVSge::IDLE) handleUploadInSgeIdle(dbswdbe, req->filename);

	} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::DOWNLOAD) {
		if (ixVSge == VecVSge::DONE) req->filename = handleDownloadInSgeDone(dbswdbe);
		else if (ixVSge == VecVSge::FAIL) req->filename = handleDownloadInSgeFail(dbswdbe);

	} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::DPCHRET) {
		if (req->dpchret->ixOpVOpres == VecOpVOpres::PROGRESS) {
			// IP handleRequest.opprogress --- INSERT
		} else {
			if (req->dpchret->ixWdbeVDpch == VecWdbeVDpch::DPCHRETWDBEMTPPLHFPGA) {
				handleDpchRetWdbeMtpPlhfpga(dbswdbe, (DpchRetWdbeMtpPlhfpga*) (req->dpchret));
			} else if (req->dpchret->ixWdbeVDpch == VecWdbeVDpch::DPCHRETWDBEMTPPLHMCU) {
				handleDpchRetWdbeMtpPlhmcu(dbswdbe, (DpchRetWdbeMtpPlhmcu*) (req->dpchret));
			} else if (req->dpchret->ixWdbeVDpch == VecWdbeVDpch::DPCHRETWDBEPLHFPGACMDINV) {
				handleDpchRetWdbePlhfpgaCmdinv(dbswdbe, (DpchRetWdbePlhfpgaCmdinv*) (req->dpchret));
			} else if (req->dpchret->ixWdbeVDpch == VecWdbeVDpch::DPCHRETWDBEPLHFPGACMDRET) {
				handleDpchRetWdbePlhfpgaCmdret(dbswdbe, (DpchRetWdbePlhfpgaCmdret*) (req->dpchret));
			} else if (req->dpchret->ixWdbeVDpch == VecWdbeVDpch::DPCHRETWDBEPLHMCUECTR) {
				handleDpchRetWdbePlhmcuEctr(dbswdbe, (DpchRetWdbePlhmcuEctr*) (req->dpchret));
			} else if (req->dpchret->ixWdbeVDpch == VecWdbeVDpch::DPCHRETWDBEPLHMCUEHOSTIF) {
				handleDpchRetWdbePlhmcuEhostif(dbswdbe, (DpchRetWdbePlhmcuEhostif*) (req->dpchret));
			} else if (req->dpchret->ixWdbeVDpch == VecWdbeVDpch::DPCHRETWDBEPRCTREEMERGE) {
				handleDpchRetWdbePrctreeMerge(dbswdbe, (DpchRetWdbePrctreeMerge*) (req->dpchret));
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
		if (ixVSge == VecVSge::UPKIDLE) handleTimerInSgeUpkidle(dbswdbe, req->sref);
		else if ((req->sref == "mon") && (ixVSge == VecVSge::CREATE)) handleTimerWithSrefMonInSgeCreate(dbswdbe);
		else if ((req->sref == "mon") && (ixVSge == VecVSge::WRITE)) handleTimerWithSrefMonInSgeWrite(dbswdbe);
	};
};

void DlgWdbeRlsWrite::handleDpchAppWdbeInit(
			DbsWdbe* dbswdbe
			, DpchAppWdbeInit* dpchappwdbeinit
			, DpchEngWdbe** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWdbeRlsWrite::handleDpchAppDataContiac(
			DbsWdbe* dbswdbe
			, ContIac* _contiac
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFDSE)) {
		if ((_contiac->numFDse >= VecVDit::DET) && (_contiac->numFDse <= VecVDit::FIA)) ixVDit = _contiac->numFDse;
		refresh(dbswdbe, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgWdbeRlsWrite::handleDpchAppDataContiacdet(
			DbsWdbe* dbswdbe
			, ContIacDet* _contiacdet
			, DpchEngWdbe** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiacdet->diff(&contiacdet);
	// IP handleDpchAppDataContiacdet --- IBEGIN

	contiacdet.ChkBso = _contiacdet->ChkBso;

	// IP handleDpchAppDataContiacdet --- IEND
	insert(moditems, DpchEngData::CONTIACDET);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgWdbeRlsWrite::handleDpchAppDoButDneClick(
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

void DlgWdbeRlsWrite::handleDpchAppDoWrcButAutClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoWrcButAutClick --- BEGIN
	if (statshrwrc.ButAutActive) {
		changeStage(dbswdbe, VecVSge::AUTH, dpcheng);
	};
	// IP handleDpchAppDoWrcButAutClick --- END
};

void DlgWdbeRlsWrite::handleDpchAppDoWrcButRunClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoWrcButRunClick --- BEGIN
	if (statshrwrc.ButRunActive) {
		changeStage(dbswdbe, VecVSge::FILLPLH, dpcheng);
	};
	// IP handleDpchAppDoWrcButRunClick --- END
};

void DlgWdbeRlsWrite::handleDpchAppDoWrcButStoClick(
			DbsWdbe* dbswdbe
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppDoWrcButStoClick --- INSERT
};

void DlgWdbeRlsWrite::handleDpchAppWdbeAlert(
			DbsWdbe* dbswdbe
			, DpchAppWdbeAlert* dpchappwdbealert
			, DpchEngWdbe** dpcheng
		) {
	// IP handleDpchAppWdbeAlert --- IBEGIN
	if (ixVSge == VecVSge::ALRMER) {
		changeStage(dbswdbe, nextIxVSgeSuccess);
	};
	// IP handleDpchAppWdbeAlert --- IEND
};

void DlgWdbeRlsWrite::handleDpchRetWdbeMtpPlhfpga(
			DbsWdbe* dbswdbe
			, DpchRetWdbeMtpPlhfpga* dpchret
		) {
	if (ixVSge == VecVSge::FILLPLH) mergeKeysVals(dpchret->oref, dpchret->keys, dpchret->vals, true); // IP handleDpchRetWdbeMtpPlhfpga --- ILINE
};

void DlgWdbeRlsWrite::handleDpchRetWdbeMtpPlhmcu(
			DbsWdbe* dbswdbe
			, DpchRetWdbeMtpPlhmcu* dpchret
		) {
	if (ixVSge == VecVSge::FILLPLH) mergeKeysVals(dpchret->oref, dpchret->keys, dpchret->vals, true); // IP handleDpchRetWdbeMtpPlhmcu --- ILINE
};

void DlgWdbeRlsWrite::handleDpchRetWdbePlhfpgaCmdinv(
			DbsWdbe* dbswdbe
			, DpchRetWdbePlhfpgaCmdinv* dpchret
		) {
	if (ixVSge == VecVSge::FILLPLH) mergeKeysVals(dpchret->oref, dpchret->keys, dpchret->vals, false); // IP handleDpchRetWdbePlhfpgaCmdinv --- ILINE
};

void DlgWdbeRlsWrite::handleDpchRetWdbePlhfpgaCmdret(
			DbsWdbe* dbswdbe
			, DpchRetWdbePlhfpgaCmdret* dpchret
		) {
	if (ixVSge == VecVSge::FILLPLH) mergeKeysVals(dpchret->oref, dpchret->keys, dpchret->vals, false); // IP handleDpchRetWdbePlhfpgaCmdret --- ILINE
};

void DlgWdbeRlsWrite::handleDpchRetWdbePlhmcuEctr(
			DbsWdbe* dbswdbe
			, DpchRetWdbePlhmcuEctr* dpchret
		) {
	if (ixVSge == VecVSge::FILLPLH) mergeKeysVals(dpchret->oref, dpchret->keys, dpchret->vals, false); // IP handleDpchRetWdbePlhmcuEctr --- ILINE
};

void DlgWdbeRlsWrite::handleDpchRetWdbePlhmcuEhostif(
			DbsWdbe* dbswdbe
			, DpchRetWdbePlhmcuEhostif* dpchret
		) {
	if (ixVSge == VecVSge::FILLPLH) mergeKeysVals(dpchret->oref, dpchret->keys, dpchret->vals, false); // IP handleDpchRetWdbePlhmcuEhostif --- ILINE
};

void DlgWdbeRlsWrite::handleDpchRetWdbePrctreeMerge(
			DbsWdbe* dbswdbe
			, DpchRetWdbePrctreeMerge* dpchret
		) {
	// IP handleDpchRetWdbePrctreeMerge --- IBEGIN
	logaspect = VecVSge::getSref(ixVSge);
	logfile = dpchret->logfile;
	// IP handleDpchRetWdbePrctreeMerge --- IEND
};

void DlgWdbeRlsWrite::handleUploadInSgeIdle(
			DbsWdbe* dbswdbe
			, const string& filename
		) {
	infilename = filename; // IP handleUploadInSgeIdle --- ILINE
	changeStage(dbswdbe, VecVSge::UPKIDLE);
};

string DlgWdbeRlsWrite::handleDownloadInSgeDone(
			DbsWdbe* dbswdbe
		) {
	return(xchg->tmppath + "/" + outfolder + ".tgz"); // IP handleDownloadInSgeDone --- RLINE
};

string DlgWdbeRlsWrite::handleDownloadInSgeFail(
			DbsWdbe* dbswdbe
		) {
	return(xchg->tmppath + "/" + logfile); // IP handleDownloadInSgeFail --- RLINE
};

void DlgWdbeRlsWrite::handleTimerInSgeUpkidle(
			DbsWdbe* dbswdbe
			, const string& sref
		) {
	changeStage(dbswdbe, nextIxVSgeSuccess);
};

void DlgWdbeRlsWrite::handleTimerWithSrefMonInSgeCreate(
			DbsWdbe* dbswdbe
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	refreshWithDpchEng(dbswdbe); // IP handleTimerWithSrefMonInSgeCreate --- ILINE
};

void DlgWdbeRlsWrite::handleTimerWithSrefMonInSgeWrite(
			DbsWdbe* dbswdbe
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	refreshWithDpchEng(dbswdbe); // IP handleTimerWithSrefMonInSgeWrite --- ILINE
};

void DlgWdbeRlsWrite::changeStage(
			DbsWdbe* dbswdbe
			, uint _ixVSge
			, DpchEngWdbe** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswdbe); break;
				case VecVSge::ALRAER: leaveSgeAlraer(dbswdbe); break;
				case VecVSge::ALRMER: leaveSgeAlrmer(dbswdbe); break;
				case VecVSge::UPKIDLE: leaveSgeUpkidle(dbswdbe); break;
				case VecVSge::UNPACK: leaveSgeUnpack(dbswdbe); break;
				case VecVSge::UPKDONE: leaveSgeUpkdone(dbswdbe); break;
				case VecVSge::AUTH: leaveSgeAuth(dbswdbe); break;
				case VecVSge::AUTDONE: leaveSgeAutdone(dbswdbe); break;
				case VecVSge::FILLPLH: leaveSgeFillplh(dbswdbe); break;
				case VecVSge::CREATE: leaveSgeCreate(dbswdbe); break;
				case VecVSge::WRITE: leaveSgeWrite(dbswdbe); break;
				case VecVSge::MRG: leaveSgeMrg(dbswdbe); break;
				case VecVSge::MRGFINE: leaveSgeMrgfine(dbswdbe); break;
				case VecVSge::MRGTYPSPEC: leaveSgeMrgtypspec(dbswdbe); break;
				case VecVSge::MRGTPLSPEC: leaveSgeMrgtplspec(dbswdbe); break;
				case VecVSge::CLRSPEC: leaveSgeClrspec(dbswdbe); break;
				case VecVSge::MRGCUST: leaveSgeMrgcust(dbswdbe); break;
				case VecVSge::PACK: leaveSgePack(dbswdbe); break;
				case VecVSge::FAIL: leaveSgeFail(dbswdbe); break;
				case VecVSge::DONE: leaveSgeDone(dbswdbe); break;
			};

			setStage(dbswdbe, _ixVSge);
			reenter = false;
			refreshWithDpchEng(dbswdbe, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswdbe, reenter); break;
			case VecVSge::ALRAER: _ixVSge = enterSgeAlraer(dbswdbe, reenter); break;
			case VecVSge::ALRMER: _ixVSge = enterSgeAlrmer(dbswdbe, reenter); break;
			case VecVSge::UPKIDLE: _ixVSge = enterSgeUpkidle(dbswdbe, reenter); break;
			case VecVSge::UNPACK: _ixVSge = enterSgeUnpack(dbswdbe, reenter); break;
			case VecVSge::UPKDONE: _ixVSge = enterSgeUpkdone(dbswdbe, reenter); break;
			case VecVSge::AUTH: _ixVSge = enterSgeAuth(dbswdbe, reenter); break;
			case VecVSge::AUTDONE: _ixVSge = enterSgeAutdone(dbswdbe, reenter); break;
			case VecVSge::FILLPLH: _ixVSge = enterSgeFillplh(dbswdbe, reenter); break;
			case VecVSge::CREATE: _ixVSge = enterSgeCreate(dbswdbe, reenter); break;
			case VecVSge::WRITE: _ixVSge = enterSgeWrite(dbswdbe, reenter); break;
			case VecVSge::MRG: _ixVSge = enterSgeMrg(dbswdbe, reenter); break;
			case VecVSge::MRGFINE: _ixVSge = enterSgeMrgfine(dbswdbe, reenter); break;
			case VecVSge::MRGTYPSPEC: _ixVSge = enterSgeMrgtypspec(dbswdbe, reenter); break;
			case VecVSge::MRGTPLSPEC: _ixVSge = enterSgeMrgtplspec(dbswdbe, reenter); break;
			case VecVSge::CLRSPEC: _ixVSge = enterSgeClrspec(dbswdbe, reenter); break;
			case VecVSge::MRGCUST: _ixVSge = enterSgeMrgcust(dbswdbe, reenter); break;
			case VecVSge::PACK: _ixVSge = enterSgePack(dbswdbe, reenter); break;
			case VecVSge::FAIL: _ixVSge = enterSgeFail(dbswdbe, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswdbe, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWdbeRlsWrite::getSquawk(
			DbsWdbe* dbswdbe
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::UNPACK) || (ixVSge == VecVSge::UPKDONE) || (ixVSge == VecVSge::AUTH) || (ixVSge == VecVSge::AUTDONE) || (ixVSge == VecVSge::FILLPLH) || (ixVSge == VecVSge::CREATE) || (ixVSge == VecVSge::WRITE) || (ixVSge == VecVSge::MRG) || (ixVSge == VecVSge::MRGFINE) || (ixVSge == VecVSge::MRGTYPSPEC) || (ixVSge == VecVSge::MRGTPLSPEC) || (ixVSge == VecVSge::CLRSPEC) || (ixVSge == VecVSge::MRGCUST) || (ixVSge == VecVSge::PACK) ) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			if (ixVSge == VecVSge::UNPACK) retval = "unpacking custom code fragments";
			else if (ixVSge == VecVSge::UPKDONE) retval = "custom code fragments unpacked";
			else if (ixVSge == VecVSge::AUTH) retval = "authenticating";
			else if (ixVSge == VecVSge::AUTDONE) retval = "authentication successful";
			else if (ixVSge == VecVSge::FILLPLH) retval = "filling placeholders (" + to_string(opNSuccess + opNFailure) + "/" + to_string(opN) + " operations completed, last: " + getOpsqkLast() + ")";
			else if (ixVSge == VecVSge::CREATE) retval = "creating write operations (" + to_string(opN) + " operations prepared)";
			else if (ixVSge == VecVSge::WRITE) retval = "writing code (" + to_string(opNSuccess + opNFailure) + "/" + to_string(opN) + " operations completed, last: " + getOpsqkLast() + ")";
			else if (ixVSge == VecVSge::MRG) retval = "merging code fragments";
			else if (ixVSge == VecVSge::MRGFINE) retval = "merging in-detail code fragments";
			else if (ixVSge == VecVSge::MRGTYPSPEC) retval = "merging module type specific code fragments";
			else if (ixVSge == VecVSge::MRGTPLSPEC) retval = "merging module template specific code fragments";
			else if (ixVSge == VecVSge::CLRSPEC) retval = "clearing unused specific insertion points";
			else if (ixVSge == VecVSge::MRGCUST) retval = "merging custom code fragments";
			else if (ixVSge == VecVSge::PACK) retval = "packing code tree";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint DlgWdbeRlsWrite::enterSgeIdle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWdbeRlsWrite::leaveSgeIdle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWdbeRlsWrite::enterSgeAlraer(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::ALRAER;
	nextIxVSgeSuccess = VecVSge::IDLE;

	ContInfWdbeAlert continf;
	// IP enterSgeAlraer --- BEGIN
	continf.TxtCpt = VecWdbeVTag::getTitle(VecWdbeVTag::ERROR, ixWdbeVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		continf.TxtMsg1 = "Authentication failure.";
	};

	feedFMcbAlert.clear();

	VecWdbeVTag::appendToFeed(VecWdbeVTag::OK, ixWdbeVLocale, feedFMcbAlert);
	// IP enterSgeAlraer --- END
	xchg->submitDpch(new DpchEngWdbeAlert(jref, &continf, &feedFMcbAlert, {DpchEngWdbeAlert::ALL}));

	return retval;
};

void DlgWdbeRlsWrite::leaveSgeAlraer(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAlraer --- INSERT
};

uint DlgWdbeRlsWrite::enterSgeAlrmer(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::ALRMER;
	nextIxVSgeSuccess = VecVSge::IDLE;

	ContInfWdbeAlert continf;
	// IP enterSgeAlrmer --- RBEGIN
	continf.TxtCpt = VecWdbeVTag::getTitle(VecWdbeVTag::ERROR, ixWdbeVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		continf.TxtMsg1 = "Merge error (" + logaspect + "). View log file for details.";
	};

	feedFMcbAlert.clear();

	VecWdbeVTag::appendToFeed(VecWdbeVTag::OK, ixWdbeVLocale, feedFMcbAlert);

	nextIxVSgeSuccess = VecVSge::FAIL;
	// IP enterSgeAlrmer --- REND
	xchg->submitDpch(new DpchEngWdbeAlert(jref, &continf, &feedFMcbAlert, {DpchEngWdbeAlert::ALL}));

	return retval;
};

void DlgWdbeRlsWrite::leaveSgeAlrmer(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAlrmer --- INSERT
};

uint DlgWdbeRlsWrite::enterSgeUpkidle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::UPKIDLE;
	nextIxVSgeSuccess = VecVSge::UNPACK;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgeUpkidle --- INSERT

	return retval;
};

void DlgWdbeRlsWrite::leaveSgeUpkidle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeUpkidle --- INSERT
};

uint DlgWdbeRlsWrite::enterSgeUnpack(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::UPKDONE;
	retval = nextIxVSgeSuccess;

	// IP enterSgeUnpack --- IBEGIN

	// unpack archive
	Wdbe::run("mv " + infilename + " " + infilename + ".tgz");
	Wdbe::untgz(infilename + ".tgz", infilename);

	if (infilename.rfind("/") == string::npos) custfolder = infilename;
	else custfolder = infilename.substr(infilename.rfind("/")+1);
	// IP enterSgeUnpack --- IEND

	return retval;
};

void DlgWdbeRlsWrite::leaveSgeUnpack(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeUnpack --- INSERT
};

uint DlgWdbeRlsWrite::enterSgeUpkdone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::UPKDONE;

	// IP enterSgeUpkdone --- INSERT

	return retval;
};

void DlgWdbeRlsWrite::leaveSgeUpkdone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeUpkdone --- INSERT
};

uint DlgWdbeRlsWrite::enterSgeAuth(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::AUTDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::ALRAER;

	// IP enterSgeAuth --- IBEGIN
	if (!license->authRlsWrite(dbswdbe, refWdbeMRelease)) retval = nextIxVSgeFailure;
	// IP enterSgeAuth --- IEND

	return retval;
};

void DlgWdbeRlsWrite::leaveSgeAuth(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAuth --- INSERT
};

uint DlgWdbeRlsWrite::enterSgeAutdone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::AUTDONE;

	// IP enterSgeAutdone --- INSERT

	return retval;
};

void DlgWdbeRlsWrite::leaveSgeAutdone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeAutdone --- INSERT
};

uint DlgWdbeRlsWrite::enterSgeFillplh(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::FILLPLH;
	nextIxVSgeSuccess = VecVSge::CREATE;

	clearInvs();

	// IP enterSgeFillplh --- IBEGIN
	vector<ubigint> refs;
	ubigint ref;

	ListWdbeMModule mdls;
	WdbeMModule* mdl = NULL;

	map<ubigint,string> srefsMtpCustops;

	DpchInvWdbe* dpchinv = NULL;

	if (ixCmptype == VecWdbeVMComponentBasetype::FPGA) {
		// collect modules
		dbswdbe->loadRefBySQL("SELECT TblWdbeMComponent.refWdbeMVersion FROM TblWdbeMComponent, TblWdbeMRelease WHERE TblWdbeMRelease.refWdbeMComponent = TblWdbeMComponent.ref AND TblWdbeMRelease.ref = " + to_string(refWdbeMRelease), ref);
		dbswdbe->loadRefsBySQL("SELECT ref FROM TblWdbeMUnit WHERE refIxVTbl = " + to_string(VecWdbeVMUnitRefTbl::VER) + " AND refUref = " + to_string(ref) + " AND ixVBasetype = " + to_string(VecWdbeVMUnitBasetype::FPGA), false, refs);
		for (unsigned int i = 0; i < refs.size();i++) dbswdbe->tblwdbemmodule->loadRstBySQL("SELECT * FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND hkUref = " + to_string(refs[i]), true, mdls);

		// type- and template-specific placeholders
		Wdbe::getSrefsMtpCustops(dbswdbe, srefsMtpCustops, VecWdbeVKeylist::KLSTKWDBEMTPPLHFPGACUSTOP);

		for (unsigned int i = 0; i < mdls.nodes.size(); i++) {
			mdl = mdls.nodes[i];

			if (mdl->ixVBasetype == VecWdbeVMModuleBasetype::CMDINV) {
				dpchinv = new DpchInvWdbePlhfpgaCmdinv(0, 0, mdl->ref);
				addInv(dpchinv);
				orefsToRefs[dpchinv->oref] = mdl->ref;

			} else if (mdl->ixVBasetype == VecWdbeVMModuleBasetype::CMDRET) {
				dpchinv = new DpchInvWdbePlhfpgaCmdret(0, 0, mdl->ref);
				addInv(dpchinv);
				orefsToRefs[dpchinv->oref] = mdl->ref;
			};
			
			if (mdl->tplRefWdbeMModule != 0) {
				auto it = srefsMtpCustops.find(mdl->tplRefWdbeMModule);

				if (it != srefsMtpCustops.end()) {
					dpchinv = new DpchInvWdbeMtpPlhfpga(0, it->second, 0, mdl->ref);
					addInv(dpchinv);
					orefsToRefs[dpchinv->oref] = mdl->ref;
				};
			};
		};

	} else if (ixCmptype == VecWdbeVMComponentBasetype::MCU) {
		// collect modules
		dbswdbe->loadRefBySQL("SELECT TblWdbeMComponent.refWdbeMVersion FROM TblWdbeMComponent, TblWdbeMRelease WHERE TblWdbeMRelease.refWdbeMComponent = TblWdbeMComponent.ref AND TblWdbeMRelease.ref = " + to_string(refWdbeMRelease), ref);
		dbswdbe->loadRefsBySQL("SELECT ref FROM TblWdbeMUnit WHERE refIxVTbl = " + to_string(VecWdbeVMUnitRefTbl::VER) + " AND refUref = " + to_string(ref) + " AND ixVBasetype = " + to_string(VecWdbeVMUnitBasetype::MCU), false, refs);
		for (unsigned int i = 0; i < refs.size();i++) dbswdbe->tblwdbemmodule->loadRstBySQL("SELECT * FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND hkUref = " + to_string(refs[i]), true, mdls);

		// type- and template-specific placeholders
		Wdbe::getSrefsMtpCustops(dbswdbe, srefsMtpCustops, VecWdbeVKeylist::KLSTKWDBEMTPPLHMCUCUSTOP);

		for (unsigned int i = 0; i < mdls.nodes.size(); i++) {
			mdl = mdls.nodes[i];

			if (mdl->ixVBasetype == VecWdbeVMModuleBasetype::EHOSTIF) {
				dpchinv = new DpchInvWdbePlhmcuEhostif(0, 0, mdl->ref);
				addInv(dpchinv);
				orefsToRefs[dpchinv->oref] = mdl->ref;

			} else if ((mdl->ixVBasetype == VecWdbeVMModuleBasetype::ECTR) || (mdl->ixVBasetype == VecWdbeVMModuleBasetype::EDBGCTR)) {
				dpchinv = new DpchInvWdbePlhmcuEctr(0, 0, mdl->ref);
				addInv(dpchinv);
				orefsToRefs[dpchinv->oref] = mdl->ref;
			};
			
			if (mdl->tplRefWdbeMModule != 0) {
				auto it = srefsMtpCustops.find(mdl->tplRefWdbeMModule);

				if (it != srefsMtpCustops.end()) {
					dpchinv = new DpchInvWdbeMtpPlhmcu(0, it->second, 0, mdl->ref);
					addInv(dpchinv);
					orefsToRefs[dpchinv->oref] = mdl->ref;
				};
			};
		};
	};
	// IP enterSgeFillplh --- IEND

	submitInvs(dbswdbe, VecVSge::CREATE, retval);
	return retval;
};

void DlgWdbeRlsWrite::leaveSgeFillplh(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeFillplh --- INSERT
};

uint DlgWdbeRlsWrite::enterSgeCreate(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::WRITE;
	retval = nextIxVSgeSuccess;

	clearInvs();

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);

	// IP enterSgeCreate --- IBEGIN
	if (ixCmptype == VecWdbeVMComponentBasetype::FPGA) {
		// create -> outfolder
		// IP's -> ipfolder -> outfolder
		// in-detail IP's -> finefolder -> outfolder
		// module-type specific IP's -> typspecfolder -> outfolder
		// module-template specific IP's -> tplspecfolder -> outfolder
		// auxiliary IP's -> auxfolder -> outfolder
		// (optional) custom IP's -> custfolder -> outfolder
		createFpga(dbswdbe, contiacdet.ChkBso);

	} else if (ixCmptype == VecWdbeVMComponentBasetype::MCU) {
		// create -> outfolder
		// IP's -> ipfolder -> outfolder
		// in-detail IP's -> finefolder -> outfolder
		// module-type specific IP's -> typspecfolder -> outfolder
		// module-template specific IP's -> tplspecfolder -> outfolder
		// (optional) custom IP's -> custfolder -> outfolder
		createMcu(dbswdbe, contiacdet.ChkBso);

	} else if (ixCmptype == VecWdbeVMComponentBasetype::DEV) {
		// create -> outfolder
		// IP's -> ipfolder -> outfolder
		// (optional) custom IP's -> custfolder -> outfolder
		createDev(dbswdbe, contiacdet.ChkBso);

	} else if (ixCmptype == VecWdbeVMComponentBasetype::EZDEV) {
		// create -> outfolder
		// IP's -> ipfolder -> outfolder
		// (optional) custom IP's -> custfolder -> outfolder
		createEzdev(dbswdbe, contiacdet.ChkBso);

	} else if (ixCmptype == VecWdbeVMComponentBasetype::TERM) {
		// create -> outfolder
		// IP's -> ipfolder -> outfolder
		// (optional) custom IP's -> custfolder -> outfolder
		createTerm(dbswdbe, contiacdet.ChkBso);
	};
	// IP enterSgeCreate --- IEND

	return retval;
};

void DlgWdbeRlsWrite::leaveSgeCreate(
			DbsWdbe* dbswdbe
		) {
	invalidateWakeups();
	// IP leaveSgeCreate --- INSERT
};

uint DlgWdbeRlsWrite::enterSgeWrite(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::WRITE;
	nextIxVSgeSuccess = VecVSge::MRG;

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);

	// IP enterSgeWrite --- INSERT

	submitInvs(dbswdbe, VecVSge::IDLE, retval);
	return retval;
};

void DlgWdbeRlsWrite::leaveSgeWrite(
			DbsWdbe* dbswdbe
		) {
	invalidateWakeups();
	// IP leaveSgeWrite --- INSERT
};

uint DlgWdbeRlsWrite::enterSgeMrg(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::MRG;
	nextIxVSgeSuccess = VecVSge::MRGFINE;
	nextIxVSgeFailure = VecVSge::ALRMER;

	clearInvs();

	// IP enterSgeMrg --- IBEGIN
	if ((ixCmptype == VecWdbeVMComponentBasetype::FPGA) || (ixCmptype == VecWdbeVMComponentBasetype::MCU) || (ixCmptype == VecWdbeVMComponentBasetype::DEV) || (ixCmptype == VecWdbeVMComponentBasetype::EZDEV) || (ixCmptype == VecWdbeVMComponentBasetype::TERM)) {
		// IP's -> ipfolder -> outfolder
		addInv(new DpchInvWdbePrctreeMerge(0, 0, "", ipfolder, "", outfolder, true, true));
	};
	// IP enterSgeMrg --- IEND

	submitInvs(dbswdbe, retval, retval);
	return retval;
};

void DlgWdbeRlsWrite::leaveSgeMrg(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeMrg --- INSERT
};

uint DlgWdbeRlsWrite::enterSgeMrgfine(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::MRGFINE;
	nextIxVSgeSuccess = VecVSge::MRGTYPSPEC;
	nextIxVSgeFailure = VecVSge::ALRMER;

	clearInvs();

	// IP enterSgeMrgfine --- IBEGIN
	if ((ixCmptype == VecWdbeVMComponentBasetype::FPGA) || (ixCmptype == VecWdbeVMComponentBasetype::MCU)) {
		// in-detail IP's -> finefolder -> outfolder
		if (!contiacdet.ChkBso) addInv(new DpchInvWdbePrctreeMerge(0, 0, "", finefolder, "", outfolder, true, true));
	};
	// IP enterSgeMrgfine --- IEND

	submitInvs(dbswdbe, VecVSge::MRGTYPSPEC, retval);
	return retval;
};

void DlgWdbeRlsWrite::leaveSgeMrgfine(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeMrgfine --- INSERT
};

uint DlgWdbeRlsWrite::enterSgeMrgtypspec(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::MRGTYPSPEC;
	nextIxVSgeSuccess = VecVSge::MRGTPLSPEC;
	nextIxVSgeFailure = VecVSge::ALRMER;

	clearInvs();

	// IP enterSgeMrgtypspec --- IBEGIN
	if ((ixCmptype == VecWdbeVMComponentBasetype::FPGA) || (ixCmptype == VecWdbeVMComponentBasetype::MCU)) {
		// module-type specific IP's -> typspecfolder -> outfolder
		if (!contiacdet.ChkBso) addInv(new DpchInvWdbePrctreeMerge(0, 0, "", typspecfolder, "", outfolder, true, true));
	};
	// IP enterSgeMrgtypspec --- IEND

	submitInvs(dbswdbe, VecVSge::MRGTPLSPEC, retval);
	return retval;
};

void DlgWdbeRlsWrite::leaveSgeMrgtypspec(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeMrgtypspec --- INSERT
};

uint DlgWdbeRlsWrite::enterSgeMrgtplspec(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::MRGTPLSPEC;
	nextIxVSgeSuccess = VecVSge::CLRSPEC;
	nextIxVSgeFailure = VecVSge::ALRMER;

	clearInvs();

	// IP enterSgeMrgtplspec --- IBEGIN
	if ((ixCmptype == VecWdbeVMComponentBasetype::FPGA) || (ixCmptype == VecWdbeVMComponentBasetype::MCU)) {
		// module-template specific IP's -> tplspecfolder -> outfolder
		if (!contiacdet.ChkBso) addInv(new DpchInvWdbePrctreeMerge(0, 0, "", tplspecfolder, "", outfolder, true, true));
	};
	// IP enterSgeMrgtplspec --- IEND

	submitInvs(dbswdbe, VecVSge::CLRSPEC, retval);
	return retval;
};

void DlgWdbeRlsWrite::leaveSgeMrgtplspec(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeMrgtplspec --- INSERT
};

uint DlgWdbeRlsWrite::enterSgeClrspec(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::CLRSPEC;
	nextIxVSgeSuccess = VecVSge::MRGCUST;

	clearInvs();

	// IP enterSgeClrspec --- IBEGIN
	if (ixCmptype == VecWdbeVMComponentBasetype::FPGA) {
		// clearing IP's -> auxfolder -> outfolder
		if (!contiacdet.ChkBso) addInv(new DpchInvWdbePrctreeMerge(0, 0, "", auxfolder, "", outfolder, true, true));
	};
	// IP enterSgeClrspec --- IEND

	submitInvs(dbswdbe, VecVSge::MRGCUST, retval);
	return retval;
};

void DlgWdbeRlsWrite::leaveSgeClrspec(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeClrspec --- INSERT
};

uint DlgWdbeRlsWrite::enterSgeMrgcust(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::MRGCUST;
	nextIxVSgeSuccess = VecVSge::PACK;
	nextIxVSgeFailure = VecVSge::ALRMER;

	clearInvs();

	// IP enterSgeMrgcust --- IBEGIN

	if (!contiacdet.ChkBso) {
		if (custfolder == "") {
			custfolder = xchg->getTxtvalPreset(VecWdbeVPreset::PREWDBEEXTFOLDER, jref);
			if (custfolder != "") custfolder += "/" + cmpsref;
		};

		if (custfolder != "") addInv(new DpchInvWdbePrctreeMerge(0, 0, "", custfolder, "", outfolder + "/" + cmpsref, false, false));
	};

	// IP enterSgeMrgcust --- IEND

	submitInvs(dbswdbe, VecVSge::PACK, retval);
	return retval;
};

void DlgWdbeRlsWrite::leaveSgeMrgcust(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeMrgcust --- INSERT
};

uint DlgWdbeRlsWrite::enterSgePack(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	// IP enterSgePack --- IBEGIN

	if (xchg->getIxPreset(VecWdbeVPreset::PREWDBEIXBASEREPTYPE, jref) == 0) {
		// .tgz result folder
		Wdbe::tgz(xchg->tmppath + "/" + outfolder, xchg->tmppath + "/" + outfolder + ".tgz");
	};

	// IP enterSgePack --- IEND

	return retval;
};

void DlgWdbeRlsWrite::leaveSgePack(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgePack --- INSERT
};

uint DlgWdbeRlsWrite::enterSgeFail(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::FAIL;

	// IP enterSgeFail --- INSERT

	return retval;
};

void DlgWdbeRlsWrite::leaveSgeFail(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeFail --- INSERT
};

uint DlgWdbeRlsWrite::enterSgeDone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void DlgWdbeRlsWrite::leaveSgeDone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeDone --- INSERT
};
