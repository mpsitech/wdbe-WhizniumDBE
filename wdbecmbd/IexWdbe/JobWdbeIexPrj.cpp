/**
	* \file JobWdbeIexPrj.cpp
	* job handler for job JobWdbeIexPrj (implementation)
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

#include "JobWdbeIexPrj.h"

#include "JobWdbeIexPrj_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

using namespace IexWdbePrj;

/******************************************************************************
 class JobWdbeIexPrj
 ******************************************************************************/

JobWdbeIexPrj::JobWdbeIexPrj(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::JOBWDBEIEXPRJ, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	changeStage(dbswdbe, VecVSge::IDLE);

	// IP constructor.cust3 --- INSERT

};

JobWdbeIexPrj::~JobWdbeIexPrj() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void JobWdbeIexPrj::reset(
			DbsWdbe* dbswdbe
		) {
	if (ixVSge != VecVSge::IDLE) changeStage(dbswdbe, VecVSge::IDLE);
};

void JobWdbeIexPrj::parseFromFile(
			DbsWdbe* dbswdbe
			, const string& _fullpath
			, const bool _xmlNotTxt
			, const string& _rectpath
		) {
	if (ixVSge == VecVSge::IDLE) {
		fullpath = _fullpath;
		xmlNotTxt = _xmlNotTxt;
		rectpath = _rectpath;

		changeStage(dbswdbe, VecVSge::PARSE);
	};
};

void JobWdbeIexPrj::import(
			DbsWdbe* dbswdbe
		) {
	if (ixVSge == VecVSge::PRSDONE) changeStage(dbswdbe, VecVSge::IMPORT);
};

void JobWdbeIexPrj::reverse(
			DbsWdbe* dbswdbe
		) {
	if (ixVSge == VecVSge::IMPERR) changeStage(dbswdbe, VecVSge::REVERSE);
};

void JobWdbeIexPrj::collect(
			DbsWdbe* dbswdbe
			, const map<uint,uint>& _icsWdbeVIop
		) {
	if (ixVSge == VecVSge::IDLE) {
		icsWdbeVIop = _icsWdbeVIop;
		changeStage(dbswdbe, VecVSge::COLLECT);
	};
};

void JobWdbeIexPrj::exportToFile(
			DbsWdbe* dbswdbe
			, const string& _fullpath
			, const bool _xmlNotTxt
			, const bool _shorttags
		) {
	if ((ixVSge == VecVSge::IDLE) || (ixVSge == VecVSge::CLTDONE)) {
		fullpath = _fullpath;
		xmlNotTxt = _xmlNotTxt;
		shorttags = _shorttags;

		changeStage(dbswdbe, VecVSge::EXPORT);
	};
};

void JobWdbeIexPrj::handleRequest(
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

	};
};

void JobWdbeIexPrj::changeStage(
			DbsWdbe* dbswdbe
			, uint _ixVSge
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswdbe); break;
				case VecVSge::PARSE: leaveSgeParse(dbswdbe); break;
				case VecVSge::PRSERR: leaveSgePrserr(dbswdbe); break;
				case VecVSge::PRSDONE: leaveSgePrsdone(dbswdbe); break;
				case VecVSge::IMPORT: leaveSgeImport(dbswdbe); break;
				case VecVSge::IMPERR: leaveSgeImperr(dbswdbe); break;
				case VecVSge::REVERSE: leaveSgeReverse(dbswdbe); break;
				case VecVSge::COLLECT: leaveSgeCollect(dbswdbe); break;
				case VecVSge::CLTDONE: leaveSgeCltdone(dbswdbe); break;
				case VecVSge::EXPORT: leaveSgeExport(dbswdbe); break;
				case VecVSge::DONE: leaveSgeDone(dbswdbe); break;
			};

			setStage(dbswdbe, _ixVSge);
			reenter = false;
			// IP changeStage.refresh1 --- INSERT
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswdbe, reenter); break;
			case VecVSge::PARSE: _ixVSge = enterSgeParse(dbswdbe, reenter); break;
			case VecVSge::PRSERR: _ixVSge = enterSgePrserr(dbswdbe, reenter); break;
			case VecVSge::PRSDONE: _ixVSge = enterSgePrsdone(dbswdbe, reenter); break;
			case VecVSge::IMPORT: _ixVSge = enterSgeImport(dbswdbe, reenter); break;
			case VecVSge::IMPERR: _ixVSge = enterSgeImperr(dbswdbe, reenter); break;
			case VecVSge::REVERSE: _ixVSge = enterSgeReverse(dbswdbe, reenter); break;
			case VecVSge::COLLECT: _ixVSge = enterSgeCollect(dbswdbe, reenter); break;
			case VecVSge::CLTDONE: _ixVSge = enterSgeCltdone(dbswdbe, reenter); break;
			case VecVSge::EXPORT: _ixVSge = enterSgeExport(dbswdbe, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswdbe, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string JobWdbeIexPrj::getSquawk(
			DbsWdbe* dbswdbe
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::PARSE) || (ixVSge == VecVSge::PRSDONE) || (ixVSge == VecVSge::IMPORT) || (ixVSge == VecVSge::REVERSE) || (ixVSge == VecVSge::COLLECT) || (ixVSge == VecVSge::CLTDONE) || (ixVSge == VecVSge::EXPORT) ) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing projects and versions";
			else if (ixVSge == VecVSge::PRSDONE) retval = "projects and versions parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing projects and versions (" + to_string(impcnt) + " records added)";
			else if (ixVSge == VecVSge::REVERSE) retval = "reversing projects and versions import";
			else if (ixVSge == VecVSge::COLLECT) retval = "collecting projects and versions for export";
			else if (ixVSge == VecVSge::CLTDONE) retval = "projects and versions collected for export";
			else if (ixVSge == VecVSge::EXPORT) retval = "exporting projects and versions";
		};

	} else if ( (ixVSge == VecVSge::PRSERR) || (ixVSge == VecVSge::IMPERR) ) {
		retval = lasterror;

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

uint JobWdbeIexPrj::enterSgeIdle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	fullpath = "";
	xmlNotTxt = false;
	rectpath = "";

	lineno = 0;
	impcnt = 0;

	icsWdbeVIop.clear();

	imeimproject.clear();

	return retval;
};

void JobWdbeIexPrj::leaveSgeIdle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWdbeIexPrj::enterSgeParse(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::PRSDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::PRSERR;

	try {
		IexWdbePrj::parseFromFile(fullpath, xmlNotTxt, rectpath, imeimproject);

	} catch (SbeException& e) {
		if (e.ix == SbeException::PATHNF) e.vals["path"] = "<hidden>";
		lasterror = e.getSquawk(VecWdbeVError::getIx, VecWdbeVError::getTitle, ixWdbeVLocale);

		retval = nextIxVSgeFailure;
	};

	return retval;
};

void JobWdbeIexPrj::leaveSgeParse(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeParse --- INSERT
};

uint JobWdbeIexPrj::enterSgePrserr(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::PRSERR;

	// IP enterSgePrserr --- INSERT

	return retval;
};

void JobWdbeIexPrj::leaveSgePrserr(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgePrserr --- INSERT
};

uint JobWdbeIexPrj::enterSgePrsdone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::PRSDONE;

	// IP enterSgePrsdone --- INSERT

	return retval;
};

void JobWdbeIexPrj::leaveSgePrsdone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgePrsdone --- INSERT
};

uint JobWdbeIexPrj::enterSgeImport(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IMPERR;

	ImeitemIMProject* prj = NULL;
	ImeitemIMVersion* ver = NULL;
	ImeitemIRMPersonMProject* prsRprj = NULL;
	ImeitemIJMVersionState* verJste = NULL;
	ImeitemIMRelease* rls = NULL;
	ImeitemIRMLibraryMVersion* libRver = NULL;

	// IP enterSgeImport.prep --- IBEGIN
	WdbeMProject* prj_r = NULL;

	ubigint grp;
	grp = xchg->getRefPreset(VecWdbeVPreset::PREWDBEGROUP, jref);

	ubigint own;
	own = xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jref);

	vector<ubigint> refs;
	map<string,ubigint> refsMchs; // by hsref

	dbswdbe->loadRefsBySQL("SELECT ref FROM TblWdbeMMachine", false, refs);
	for (unsigned int i = 0; i < refs.size(); i++) refsMchs[StubWdbe::getStubMchStd(dbswdbe, refs[i])] = refs[i];

	time_t rawtime;
	time(&rawtime);

	vector<string> ss;
	// IP enterSgeImport.prep --- IEND

	try {
		// IP enterSgeImport.traverse --- RBEGIN

		// -- ImeIMProject
		for (unsigned int ix0 = 0; ix0 < imeimproject.nodes.size(); ix0++) {
			prj = imeimproject.nodes[ix0];

			prj->grp = grp;
			prj->own = own;
			//prj->refWdbeMVersion: SUB
			//prj->Short: TBL
			//prj->Title: TBL
			//prj->Easy: TBL
			//prj->Giturl: TBL
			//prj->Comment: TBL

			if (dbswdbe->tblwdbemproject->loadRecBySQL("SELECT * FROM TblWdbeMProject WHERE Short = '" + prj->Short + "'", &prj_r)) {
				prj->ref = prj_r->ref;
				prj->grp = prj_r->grp;
				prj->own = prj_r->own;
				prj->refWdbeMVersion = prj_r->refWdbeMVersion;
				prj->Short = prj_r->Short;
				prj->Title = prj_r->Title;
				prj->Easy = prj_r->Easy;
				prj->Giturl = prj_r->Giturl;
				prj->Comment = prj_r->Comment;

				delete prj_r;
			};

			if (prj->ref == 0) {
				dbswdbe->tblwdbemproject->insertRec(prj);
				impcnt++;
			};

			for (unsigned int ix1 = 0; ix1 < prj->imeimversion.nodes.size(); ix1++) {
				ver = prj->imeimversion.nodes[ix1];

				ver->grp = grp;
				ver->own = own;
				ver->refWdbeMProject = prj->ref;
				//ver->Major: TBL
				//ver->Minor: TBL
				//ver->Sub: TBL
				//ver->refJState: SUB
				if (ver->srefIxVState == "") ver->srefIxVState = "newimp";
				ver->ixVState = VecWdbeVMVersionState::getIx(ver->srefIxVState);
				if (ver->ixVState == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",ver->srefIxVState}, {"iel","srefIxVState"}, {"lineno",to_string(ver->lineno)}});
				//ver->About: TBL
				//ver->Comment: TBL

				dbswdbe->tblwdbemversion->insertRec(ver);
				impcnt++;

				if (((ver->srefIxVState != "")) && ver->imeijmversionstate.nodes.empty()) {
					verJste = new ImeitemIJMVersionState();
					ver->imeijmversionstate.nodes.push_back(verJste);

					verJste->refWdbeMVersion = ver->ref;
					verJste->srefIxVState = ver->srefIxVState;
				};

				if (ix1 == 0) {
					prj->refWdbeMVersion = ver->ref;
					dbswdbe->tblwdbemproject->updateRec(prj);
				};

				for (unsigned int ix2 = 0; ix2 < ver->imeijmversionstate.nodes.size(); ix2++) {
					verJste = ver->imeijmversionstate.nodes[ix2];

					verJste->refWdbeMVersion = ver->ref;
					verJste->x1Start = Ftm::invstamp("&now;");
					verJste->ixVState = VecWdbeVMVersionState::getIx(verJste->srefIxVState);
					if (verJste->ixVState == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",verJste->srefIxVState}, {"iel","srefIxVState"}, {"lineno",to_string(verJste->lineno)}});

					dbswdbe->tblwdbejmversionstate->insertRec(verJste);
					impcnt++;

					if (ix2 == 0) {
						ver->refJState = verJste->ref;
						ver->ixVState = verJste->ixVState;
						dbswdbe->tblwdbemversion->updateRec(ver);
					};
				};

				for (unsigned int ix2 = 0; ix2 < ver->imeirmlibrarymversion.nodes.size(); ix2++) {
					libRver = ver->imeirmlibrarymversion.nodes[ix2];

					//libRver->refWdbeMLibrary: CUSTSQL
					dbswdbe->tblwdbemlibrary->loadRefBySrf(libRver->srefRefWdbeMLibrary, libRver->refWdbeMLibrary);
					if (libRver->refWdbeMLibrary == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",libRver->srefRefWdbeMLibrary}, {"iel","srefRefWdbeMLibrary"}, {"lineno",to_string(libRver->lineno)}});
					libRver->refWdbeMVersion = ver->ref;

					dbswdbe->tblwdbermlibrarymversion->insertRec(libRver);
					impcnt++;
				};

				for (unsigned int ix2 = 0; ix2 < ver->imeimrelease.nodes.size(); ix2++) {
					rls = ver->imeimrelease.nodes[ix2];

					rls->ixVBasetype = VecWdbeVMReleaseBasetype::getIx(rls->srefIxVBasetype);
					if (rls->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",rls->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(rls->lineno)}});
					rls->refWdbeMVersion = ver->ref;
					//rls->refWdbeMMachine: CUST
					if (rls->hsrefRefWdbeMMachine != "") {
						auto it = refsMchs.find(rls->hsrefRefWdbeMMachine);
						if (it != refsMchs.end()) rls->refWdbeMMachine = it->second;
						else throw SbeException(SbeException::IEX_TSREF, {{"tsref",rls->hsrefRefWdbeMMachine}, {"iel","hsrefRefWdbeMMachine"}, {"lineno",to_string(rls->lineno)}});
					};
					//rls->sref: TBL
					//rls->srefsKOption: TBL
					//rls->Comment: TBL
					dbswdbe->tblwdbemrelease->insertRec(rls);
					impcnt++;
				};
			};

			for (unsigned int ix1 = 0; ix1 < prj->imeirmpersonmproject.nodes.size(); ix1++) {
				prsRprj = prj->imeirmpersonmproject.nodes[ix1];

				//prsRprj->refWdbeMPerson: THINT ; look for any person, format StubWdbePrsStd
				StrMod::stringToVector(prsRprj->hintRefWdbeMPerson, ss, ' ');
				if (ss.size() == 2) dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMPerson WHERE Lastname = '" + StrMod::esc(ss[1]) + "' AND Firstname = '" + StrMod::esc(ss[0]) + "'", prsRprj->refWdbeMPerson);
				prsRprj->refWdbeMProject = prj->ref;
				//prsRprj->srefKFunction: TBL

				dbswdbe->tblwdbermpersonmproject->insertRec(prsRprj);
				impcnt++;
			};
		};
		// IP enterSgeImport.traverse --- REND

		// IP enterSgeImport.ppr --- INSERT
	} catch (SbeException& e) {
		lasterror = e.getSquawk(VecWdbeVError::getIx, VecWdbeVError::getTitle, ixWdbeVLocale);
		retval = nextIxVSgeFailure;
	};

	return retval;
};

void JobWdbeIexPrj::leaveSgeImport(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeImport --- INSERT
};

uint JobWdbeIexPrj::enterSgeImperr(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IMPERR;

	// IP enterSgeImperr --- INSERT

	return retval;
};

void JobWdbeIexPrj::leaveSgeImperr(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeImperr --- INSERT
};

uint JobWdbeIexPrj::enterSgeReverse(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::IDLE;
	retval = nextIxVSgeSuccess;

	ImeitemIMProject* prj = NULL;
	ImeitemIMVersion* ver = NULL;
	ImeitemIRMPersonMProject* prsRprj = NULL;
	ImeitemIJMVersionState* verJste = NULL;
	ImeitemIMRelease* rls = NULL;
	ImeitemIRMLibraryMVersion* libRver = NULL;

	// -- ImeIMProject
	for (unsigned int ix0 = 0; ix0 < imeimproject.nodes.size(); ix0++) {
		prj = imeimproject.nodes[ix0];
		if (prj->ref != 0) dbswdbe->tblwdbemproject->removeRecByRef(prj->ref);

		for (unsigned int ix1 = 0; ix1 < prj->imeimversion.nodes.size(); ix1++) {
			ver = prj->imeimversion.nodes[ix1];
			if (ver->ref != 0) dbswdbe->tblwdbemversion->removeRecByRef(ver->ref);

			for (unsigned int ix2 = 0; ix2 < ver->imeijmversionstate.nodes.size(); ix2++) {
				verJste = ver->imeijmversionstate.nodes[ix2];
				if (verJste->ref != 0) dbswdbe->tblwdbejmversionstate->removeRecByRef(verJste->ref);
			};

			for (unsigned int ix2 = 0; ix2 < ver->imeimrelease.nodes.size(); ix2++) {
				rls = ver->imeimrelease.nodes[ix2];
				if (rls->ref != 0) dbswdbe->tblwdbemrelease->removeRecByRef(rls->ref);
			};

			for (unsigned int ix2 = 0; ix2 < ver->imeirmlibrarymversion.nodes.size(); ix2++) {
				libRver = ver->imeirmlibrarymversion.nodes[ix2];
				if (libRver->ref != 0) dbswdbe->tblwdbermlibrarymversion->removeRecByRef(libRver->ref);
			};
		};

		for (unsigned int ix1 = 0; ix1 < prj->imeirmpersonmproject.nodes.size(); ix1++) {
			prsRprj = prj->imeirmpersonmproject.nodes[ix1];
			if (prsRprj->ref != 0) dbswdbe->tblwdbermpersonmproject->removeRecByRef(prsRprj->ref);
		};
	};

	return retval;
};

void JobWdbeIexPrj::leaveSgeReverse(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeReverse --- INSERT
};

uint JobWdbeIexPrj::enterSgeCollect(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::CLTDONE;
	retval = nextIxVSgeSuccess;

	ImeitemIMProject* prj = NULL;
	ImeitemIMVersion* ver = NULL;
	ImeitemIRMPersonMProject* prsRprj = NULL;
	ImeitemIJMVersionState* verJste = NULL;
	ImeitemIMRelease* rls = NULL;
	ImeitemIRMLibraryMVersion* libRver = NULL;

	uint ixWdbeVIop;

	vector<ubigint> refs;

	Stcch* stcch = new Stcch(false);

	// IP enterSgeCollect.traverse --- BEGIN

	// -- ImeIMProject
	for (unsigned int ix0 = 0; ix0 < imeimproject.nodes.size(); ix0++) {
		prj = imeimproject.nodes[ix0];

		if (prj->ref != 0) {
		};

		if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMVERSION, ixWdbeVIop)) {
			dbswdbe->tblwdbemversion->loadRefsByPrj(prj->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) prj->imeimversion.nodes.push_back(new ImeitemIMVersion(dbswdbe, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < prj->imeimversion.nodes.size(); ix1++) {
			ver = prj->imeimversion.nodes[ix1];

			if (ver->ref != 0) {
			};

			if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIJMVERSIONSTATE, ixWdbeVIop)) {
				dbswdbe->tblwdbejmversionstate->loadRefsByVer(ver->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == ver->refJState) {refs[i] = refs[0]; refs[0] = ver->refJState; break;};
				for (unsigned int i = 0; i < refs.size(); i++) ver->imeijmversionstate.nodes.push_back(new ImeitemIJMVersionState(dbswdbe, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < ver->imeijmversionstate.nodes.size(); ix2++) {
				verJste = ver->imeijmversionstate.nodes[ix2];

				if (verJste->ref != 0) {
				};
			};

			if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMRELEASE, ixWdbeVIop)) {
				dbswdbe->tblwdbemrelease->loadRefsByVer(ver->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) ver->imeimrelease.nodes.push_back(new ImeitemIMRelease(dbswdbe, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < ver->imeimrelease.nodes.size(); ix2++) {
				rls = ver->imeimrelease.nodes[ix2];

				if (rls->ref != 0) {
					rls->hsrefRefWdbeMMachine = StubWdbe::getStubMchStd(dbswdbe, rls->refWdbeMMachine, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
				};
			};

			if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIRMLIBRARYMVERSION, ixWdbeVIop)) {
				dbswdbe->tblwdbermlibrarymversion->loadRefsByVer(ver->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) ver->imeirmlibrarymversion.nodes.push_back(new ImeitemIRMLibraryMVersion(dbswdbe, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < ver->imeirmlibrarymversion.nodes.size(); ix2++) {
				libRver = ver->imeirmlibrarymversion.nodes[ix2];

				if (libRver->ref != 0) {
					libRver->srefRefWdbeMLibrary = StubWdbe::getStubLibSref(dbswdbe, libRver->refWdbeMLibrary, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
				};
			};
		};

		if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIRMPERSONMPROJECT, ixWdbeVIop)) {
			dbswdbe->tblwdbermpersonmproject->loadRefsByPrj(prj->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) prj->imeirmpersonmproject.nodes.push_back(new ImeitemIRMPersonMProject(dbswdbe, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < prj->imeirmpersonmproject.nodes.size(); ix1++) {
			prsRprj = prj->imeirmpersonmproject.nodes[ix1];

			if (prsRprj->ref != 0) {
				prsRprj->hintRefWdbeMPerson = StubWdbe::getStubPrsStd(dbswdbe, prsRprj->refWdbeMPerson, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
			};
		};
	};
	// IP enterSgeCollect.traverse --- END
	// IP enterSgeCollect.ppr --- INSERT

	delete stcch;

	return retval;
};

void JobWdbeIexPrj::leaveSgeCollect(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeCollect --- INSERT
};

uint JobWdbeIexPrj::enterSgeCltdone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::CLTDONE;

	// IP enterSgeCltdone --- INSERT

	return retval;
};

void JobWdbeIexPrj::leaveSgeCltdone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeCltdone --- INSERT
};

uint JobWdbeIexPrj::enterSgeExport(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	IexWdbePrj::exportToFile(fullpath, xmlNotTxt, shorttags, imeimproject);

	return retval;
};

void JobWdbeIexPrj::leaveSgeExport(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeExport --- INSERT
};

uint JobWdbeIexPrj::enterSgeDone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void JobWdbeIexPrj::leaveSgeDone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeDone --- INSERT
};



