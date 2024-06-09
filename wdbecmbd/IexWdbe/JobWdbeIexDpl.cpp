/**
	* \file JobWdbeIexDpl.cpp
	* job handler for job JobWdbeIexDpl (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Sep 2023
	*/
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbed.h>
#endif

#include "JobWdbeIexDpl.h"

#include "JobWdbeIexDpl_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

using namespace IexWdbeDpl;

/******************************************************************************
 class JobWdbeIexDpl
 ******************************************************************************/

JobWdbeIexDpl::JobWdbeIexDpl(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::JOBWDBEIEXDPL, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	changeStage(dbswdbe, VecVSge::IDLE);

	// IP constructor.cust3 --- INSERT

};

JobWdbeIexDpl::~JobWdbeIexDpl() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void JobWdbeIexDpl::reset(
			DbsWdbe* dbswdbe
		) {
	if (ixVSge != VecVSge::IDLE) changeStage(dbswdbe, VecVSge::IDLE);
};

void JobWdbeIexDpl::parseFromFile(
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

void JobWdbeIexDpl::import(
			DbsWdbe* dbswdbe
		) {
	if (ixVSge == VecVSge::PRSDONE) changeStage(dbswdbe, VecVSge::IMPORT);
};

void JobWdbeIexDpl::reverse(
			DbsWdbe* dbswdbe
		) {
	if (ixVSge == VecVSge::IMPERR) changeStage(dbswdbe, VecVSge::REVERSE);
};

void JobWdbeIexDpl::collect(
			DbsWdbe* dbswdbe
			, const map<uint,uint>& _icsWdbeVIop
		) {
	if (ixVSge == VecVSge::IDLE) {
		icsWdbeVIop = _icsWdbeVIop;
		changeStage(dbswdbe, VecVSge::COLLECT);
	};
};

void JobWdbeIexDpl::exportToFile(
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

void JobWdbeIexDpl::handleRequest(
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

void JobWdbeIexDpl::changeStage(
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

string JobWdbeIexDpl::getSquawk(
			DbsWdbe* dbswdbe
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::PARSE) || (ixVSge == VecVSge::PRSDONE) || (ixVSge == VecVSge::IMPORT) || (ixVSge == VecVSge::REVERSE) || (ixVSge == VecVSge::COLLECT) || (ixVSge == VecVSge::CLTDONE) || (ixVSge == VecVSge::EXPORT) ) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing deployment information";
			else if (ixVSge == VecVSge::PRSDONE) retval = "deployment information parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing deployment information (" + to_string(impcnt) + " records added)";
			else if (ixVSge == VecVSge::REVERSE) retval = "reversing deployment information import";
			else if (ixVSge == VecVSge::COLLECT) retval = "collecting deployment information for export";
			else if (ixVSge == VecVSge::CLTDONE) retval = "deployment information collected for export";
			else if (ixVSge == VecVSge::EXPORT) retval = "exporting deployment information";
		};

	} else if ( (ixVSge == VecVSge::PRSERR) || (ixVSge == VecVSge::IMPERR) ) {
		retval = lasterror;

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

uint JobWdbeIexDpl::enterSgeIdle(
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

	imeimcomponent.clear();

	return retval;
};

void JobWdbeIexDpl::leaveSgeIdle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWdbeIexDpl::enterSgeParse(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::PRSDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::PRSERR;

	try {
		IexWdbeDpl::parseFromFile(fullpath, xmlNotTxt, rectpath, imeimcomponent);

	} catch (SbeException& e) {
		if (e.ix == SbeException::PATHNF) e.vals["path"] = "<hidden>";
		lasterror = e.getSquawk(VecWdbeVError::getIx, VecWdbeVError::getTitle, ixWdbeVLocale);

		retval = nextIxVSgeFailure;
	};

	return retval;
};

void JobWdbeIexDpl::leaveSgeParse(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeParse --- INSERT
};

uint JobWdbeIexDpl::enterSgePrserr(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::PRSERR;

	// IP enterSgePrserr --- INSERT

	return retval;
};

void JobWdbeIexDpl::leaveSgePrserr(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgePrserr --- INSERT
};

uint JobWdbeIexDpl::enterSgePrsdone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::PRSDONE;

	// IP enterSgePrsdone --- INSERT

	return retval;
};

void JobWdbeIexDpl::leaveSgePrsdone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgePrsdone --- INSERT
};

uint JobWdbeIexDpl::enterSgeImport(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IMPERR;

	ImeitemIMComponent* cmp = NULL;
	ImeitemIMRelease* rls = NULL;
	ImeitemIRMComponentMLibrary* cmpRlib = NULL;

	// IP enterSgeImport.prep --- IBEGIN
	ubigint refWdbeMVersion;
	refWdbeMVersion = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref);

	vector<ubigint> refs;
	map<string,ubigint> refsMchs; // by hsref

	dbswdbe->loadRefsBySQL("SELECT ref FROM TblWdbeMMachine", false, refs);
	for (unsigned int i = 0; i < refs.size(); i++) refsMchs[StubWdbe::getStubMchStd(dbswdbe, refs[i])] = refs[i];
	// IP enterSgeImport.prep --- IEND

	try {
		// IP enterSgeImport.traverse --- RBEGIN

		// -- ImeIMComponent
		for (unsigned int ix0 = 0; ix0 < imeimcomponent.nodes.size(); ix0++) {
			cmp = imeimcomponent.nodes[ix0];

			cmp->ixVBasetype = VecWdbeVMComponentBasetype::getIx(cmp->srefIxVBasetype);
			if (cmp->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",cmp->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(cmp->lineno)}});
			//cmp->refWdbeMVersion: PRESET
			cmp->refWdbeMVersion = refWdbeMVersion;
			//cmp->sref: TBL
			//cmp->Comment: TBL

			dbswdbe->tblwdbemcomponent->insertRec(cmp);
			impcnt++;

			for (unsigned int ix1 = 0; ix1 < cmp->imeimrelease.nodes.size(); ix1++) {
				rls = cmp->imeimrelease.nodes[ix1];

				rls->refWdbeMComponent = cmp->ref;
				//rls->refWdbeMMachine: CUSTSQL
				if (rls->hsrefRefWdbeMMachine != "") {
					auto it = refsMchs.find(rls->hsrefRefWdbeMMachine);
					if (it != refsMchs.end()) rls->refWdbeMMachine = it->second;
					else throw SbeException(SbeException::IEX_THSREF, {{"thsref",rls->hsrefRefWdbeMMachine}, {"iel","hsrefRefWdbeMMachine"}, {"lineno",to_string(rls->lineno)}});
				};
				//rls->sref: TBL
				//rls->srefsKOption: TBL
				//rls->Comment: TBL

				dbswdbe->tblwdbemrelease->insertRec(rls);
				impcnt++;
			};

			for (unsigned int ix1 = 0; ix1 < cmp->imeirmcomponentmlibrary.nodes.size(); ix1++) {
				cmpRlib = cmp->imeirmcomponentmlibrary.nodes[ix1];

				cmpRlib->refWdbeMComponent = cmp->ref;
				//cmpRlib->refWdbeMLibrary: CUSTSQL
				dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMLibrary WHERE sref = '" + cmpRlib->srefRefWdbeMLibrary + "'", cmpRlib->refWdbeMLibrary);
				if (cmpRlib->refWdbeMLibrary == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",cmpRlib->srefRefWdbeMLibrary}, {"iel","srefRefWdbeMLibrary"}, {"lineno",to_string(cmpRlib->lineno)}});

				dbswdbe->tblwdbermcomponentmlibrary->insertRec(cmpRlib);
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

void JobWdbeIexDpl::leaveSgeImport(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeImport --- INSERT
};

uint JobWdbeIexDpl::enterSgeImperr(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IMPERR;

	// IP enterSgeImperr --- INSERT

	return retval;
};

void JobWdbeIexDpl::leaveSgeImperr(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeImperr --- INSERT
};

uint JobWdbeIexDpl::enterSgeReverse(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::IDLE;
	retval = nextIxVSgeSuccess;

	ImeitemIMComponent* cmp = NULL;
	ImeitemIMRelease* rls = NULL;
	ImeitemIRMComponentMLibrary* cmpRlib = NULL;

	// -- ImeIMComponent
	for (unsigned int ix0 = 0; ix0 < imeimcomponent.nodes.size(); ix0++) {
		cmp = imeimcomponent.nodes[ix0];
		if (cmp->ref != 0) dbswdbe->tblwdbemcomponent->removeRecByRef(cmp->ref);

		for (unsigned int ix1 = 0; ix1 < cmp->imeimrelease.nodes.size(); ix1++) {
			rls = cmp->imeimrelease.nodes[ix1];
			if (rls->ref != 0) dbswdbe->tblwdbemrelease->removeRecByRef(rls->ref);
		};

		for (unsigned int ix1 = 0; ix1 < cmp->imeirmcomponentmlibrary.nodes.size(); ix1++) {
			cmpRlib = cmp->imeirmcomponentmlibrary.nodes[ix1];
			if (cmpRlib->ref != 0) dbswdbe->tblwdbermcomponentmlibrary->removeRecByRef(cmpRlib->ref);
		};
	};

	return retval;
};

void JobWdbeIexDpl::leaveSgeReverse(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeReverse --- INSERT
};

uint JobWdbeIexDpl::enterSgeCollect(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::CLTDONE;
	retval = nextIxVSgeSuccess;

	ImeitemIMComponent* cmp = NULL;
	ImeitemIMRelease* rls = NULL;
	ImeitemIRMComponentMLibrary* cmpRlib = NULL;

	uint ixWdbeVIop;

	vector<ubigint> refs;

	Stcch* stcch = new Stcch(false);

	// IP enterSgeCollect.traverse --- BEGIN

	// -- ImeIMComponent
	for (unsigned int ix0 = 0; ix0 < imeimcomponent.nodes.size(); ix0++) {
		cmp = imeimcomponent.nodes[ix0];

		if (cmp->ref != 0) {
		};

		if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMRELEASE, ixWdbeVIop)) {
			dbswdbe->tblwdbemrelease->loadRefsByCmp(cmp->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) cmp->imeimrelease.nodes.push_back(new ImeitemIMRelease(dbswdbe, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < cmp->imeimrelease.nodes.size(); ix1++) {
			rls = cmp->imeimrelease.nodes[ix1];

			if (rls->ref != 0) {
				rls->hsrefRefWdbeMMachine = StubWdbe::getStubMchStd(dbswdbe, rls->refWdbeMMachine, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
			};
		};

		if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIRMCOMPONENTMLIBRARY, ixWdbeVIop)) {
			dbswdbe->tblwdbermcomponentmlibrary->loadRefsByCmp(cmp->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) cmp->imeirmcomponentmlibrary.nodes.push_back(new ImeitemIRMComponentMLibrary(dbswdbe, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < cmp->imeirmcomponentmlibrary.nodes.size(); ix1++) {
			cmpRlib = cmp->imeirmcomponentmlibrary.nodes[ix1];

			if (cmpRlib->ref != 0) {
				cmpRlib->srefRefWdbeMLibrary = StubWdbe::getStubLibSref(dbswdbe, cmpRlib->refWdbeMLibrary, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
			};
		};
	};
	// IP enterSgeCollect.traverse --- END
	// IP enterSgeCollect.ppr --- INSERT

	delete stcch;

	return retval;
};

void JobWdbeIexDpl::leaveSgeCollect(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeCollect --- INSERT
};

uint JobWdbeIexDpl::enterSgeCltdone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::CLTDONE;

	// IP enterSgeCltdone --- INSERT

	return retval;
};

void JobWdbeIexDpl::leaveSgeCltdone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeCltdone --- INSERT
};

uint JobWdbeIexDpl::enterSgeExport(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	IexWdbeDpl::exportToFile(fullpath, xmlNotTxt, shorttags, imeimcomponent);

	return retval;
};

void JobWdbeIexDpl::leaveSgeExport(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeExport --- INSERT
};

uint JobWdbeIexDpl::enterSgeDone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void JobWdbeIexDpl::leaveSgeDone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeDone --- INSERT
};
