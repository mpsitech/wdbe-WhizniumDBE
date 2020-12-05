/**
	* \file JobWdbeIexBcd.cpp
	* job handler for job JobWdbeIexBcd (implementation)
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

#include "JobWdbeIexBcd.h"

#include "JobWdbeIexBcd_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

using namespace IexWdbeBcd;

/******************************************************************************
 class JobWdbeIexBcd
 ******************************************************************************/

JobWdbeIexBcd::JobWdbeIexBcd(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::JOBWDBEIEXBCD, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	changeStage(dbswdbe, VecVSge::IDLE);

	// IP constructor.cust3 --- INSERT

};

JobWdbeIexBcd::~JobWdbeIexBcd() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void JobWdbeIexBcd::reset(
			DbsWdbe* dbswdbe
		) {
	if (ixVSge != VecVSge::IDLE) changeStage(dbswdbe, VecVSge::IDLE);
};

void JobWdbeIexBcd::parseFromFile(
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

void JobWdbeIexBcd::import(
			DbsWdbe* dbswdbe
		) {
	if (ixVSge == VecVSge::PRSDONE) changeStage(dbswdbe, VecVSge::IMPORT);
};

void JobWdbeIexBcd::reverse(
			DbsWdbe* dbswdbe
		) {
	if (ixVSge == VecVSge::IMPERR) changeStage(dbswdbe, VecVSge::REVERSE);
};

void JobWdbeIexBcd::collect(
			DbsWdbe* dbswdbe
			, const map<uint,uint>& _icsWdbeVIop
		) {
	if (ixVSge == VecVSge::IDLE) {
		icsWdbeVIop = _icsWdbeVIop;
		changeStage(dbswdbe, VecVSge::COLLECT);
	};
};

void JobWdbeIexBcd::exportToFile(
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

void JobWdbeIexBcd::handleRequest(
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

void JobWdbeIexBcd::changeStage(
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

string JobWdbeIexBcd::getSquawk(
			DbsWdbe* dbswdbe
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::PARSE) || (ixVSge == VecVSge::PRSDONE) || (ixVSge == VecVSge::IMPORT) || (ixVSge == VecVSge::REVERSE) || (ixVSge == VecVSge::COLLECT) || (ixVSge == VecVSge::CLTDONE) || (ixVSge == VecVSge::EXPORT) ) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing basic core description";
			else if (ixVSge == VecVSge::PRSDONE) retval = "basic core description parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing basic core description (" + to_string(impcnt) + " records added)";
			else if (ixVSge == VecVSge::REVERSE) retval = "reversing basic core description import";
			else if (ixVSge == VecVSge::COLLECT) retval = "collecting basic core description for export";
			else if (ixVSge == VecVSge::CLTDONE) retval = "basic core description collected for export";
			else if (ixVSge == VecVSge::EXPORT) retval = "exporting basic core description";
		};

	} else if ( (ixVSge == VecVSge::PRSERR) || (ixVSge == VecVSge::IMPERR) ) {
		retval = lasterror;

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

uint JobWdbeIexBcd::enterSgeIdle(
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

	imeimmodule.clear();

	return retval;
};

void JobWdbeIexBcd::leaveSgeIdle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWdbeIexBcd::enterSgeParse(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::PRSDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::PRSERR;

	try {
		IexWdbeBcd::parseFromFile(fullpath, xmlNotTxt, rectpath, imeimmodule);

	} catch (SbeException& e) {
		if (e.ix == SbeException::PATHNF) e.vals["path"] = "<hidden>";
		lasterror = e.getSquawk(VecWdbeVError::getIx, VecWdbeVError::getTitle, ixWdbeVLocale);

		retval = nextIxVSgeFailure;
	};

	return retval;
};

void JobWdbeIexBcd::leaveSgeParse(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeParse --- INSERT
};

uint JobWdbeIexBcd::enterSgePrserr(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::PRSERR;

	// IP enterSgePrserr --- INSERT

	return retval;
};

void JobWdbeIexBcd::leaveSgePrserr(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgePrserr --- INSERT
};

uint JobWdbeIexBcd::enterSgePrsdone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::PRSDONE;

	// IP enterSgePrsdone --- INSERT

	return retval;
};

void JobWdbeIexBcd::leaveSgePrsdone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgePrsdone --- INSERT
};

uint JobWdbeIexBcd::enterSgeImport(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IMPERR;

	ImeitemIMModule* mdl = NULL;
	ImeitemIAMModulePar* mdlApar = NULL;
	ImeitemIAVKeylistKey* klsAkey = NULL;
	ImeitemIJAVKeylistKey* kakJkey = NULL;

	uint num1;

	// IP enterSgeImport.prep --- INSERT

	try {
		// IP enterSgeImport.traverse --- BEGIN

		// -- ImeIMModule
		for (unsigned int ix0 = 0; ix0 < imeimmodule.nodes.size(); ix0++) {
			mdl = imeimmodule.nodes[ix0];

			mdl->ixVBasetype = VecWdbeVMModuleBasetype::getIx(mdl->srefIxVBasetype);
			if (mdl->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",mdl->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(mdl->lineno)}});
			mdl->hkIxVTbl = VecWdbeVMModuleHkTbl::CVR;
			//mdl->hkUref: PRESET
			//mdl->supRefWdbeMModule: IMPPP
			//mdl->tplRefWdbeMModule: CUSTSQL
			//if (mdl->tplRefWdbeMModule == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",mdl->srefTplRefWdbeMModule}, {"iel","srefTplRefWdbeMModule"}, {"lineno",to_string(mdl->lineno)}});
			//mdl->sref: TBL
			//mdl->Srefrule: TBL
			//mdl->Comment: TBL

			dbswdbe->tblwdbemmodule->insertRec(mdl);
			impcnt++;

			num1 = 1;

			for (unsigned int ix1 = 0; ix1 < mdl->imeiammodulepar.nodes.size(); ix1++) {
				mdlApar = mdl->imeiammodulepar.nodes[ix1];

				mdlApar->mdlRefWdbeMModule = mdl->ref;
				mdlApar->mdlNum = num1++;
				//mdlApar->x1SrefKKey: TBL
				//mdlApar->Val: TBL

				dbswdbe->tblwdbeammodulepar->insertRec(mdlApar);
				impcnt++;
			};

			for (unsigned int ix1 = 0; ix1 < mdl->imeiavkeylistkey.nodes.size(); ix1++) {
				klsAkey = mdl->imeiavkeylistkey.nodes[ix1];

				klsAkey->klsIxWdbeVKeylist = VecWdbeVKeylist::KLSTWDBEKAMMODULEPARKEY;
				//klsAkey->klsNum: CUST
				klsAkey->x1IxWdbeVMaintable = VecWdbeVMaintable::TBLWDBEMMODULE;
				klsAkey->x1Uref = mdl->ref;
				klsAkey->Fixed = true;
				//klsAkey->sref: TBL
				//klsAkey->refJ: SUB
				//klsAkey->Title: TBL
				//klsAkey->Comment: TBL

				dbswdbe->tblwdbeavkeylistkey->insertRec(klsAkey);
				impcnt++;

				if (((klsAkey->Title != "") || (klsAkey->Comment != "")) && klsAkey->imeijavkeylistkey.nodes.empty()) {
					kakJkey = new ImeitemIJAVKeylistKey();
					kakJkey->lineno = klsAkey->lineno;
					klsAkey->imeijavkeylistkey.nodes.push_back(kakJkey);

					kakJkey->refWdbeAVKeylistKey = klsAkey->ref;
					kakJkey->Title = klsAkey->Title;
					kakJkey->Comment = klsAkey->Comment;
				};

				for (unsigned int ix2 = 0; ix2 < klsAkey->imeijavkeylistkey.nodes.size(); ix2++) {
					kakJkey = klsAkey->imeijavkeylistkey.nodes[ix2];

					kakJkey->refWdbeAVKeylistKey = klsAkey->ref;
					kakJkey->x1IxWdbeVLocale = VecWdbeVLocale::ENUS;
					//kakJkey->Title: TBL
					//kakJkey->Comment: TBL

					dbswdbe->tblwdbejavkeylistkey->insertRec(kakJkey);
					impcnt++;

					if (ix2 == 0) {
						klsAkey->refJ = kakJkey->ref;
						klsAkey->Title = kakJkey->Title;
						klsAkey->Comment = kakJkey->Comment;
						dbswdbe->tblwdbeavkeylistkey->updateRec(klsAkey);
					};
				};
			};
		};
		// IP enterSgeImport.traverse --- END

		// IP enterSgeImport.ppr --- INSERT
	} catch (SbeException& e) {
		lasterror = e.getSquawk(VecWdbeVError::getIx, VecWdbeVError::getTitle, ixWdbeVLocale);
		retval = nextIxVSgeFailure;
	};

	return retval;
};

void JobWdbeIexBcd::leaveSgeImport(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeImport --- INSERT
};

uint JobWdbeIexBcd::enterSgeImperr(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IMPERR;

	// IP enterSgeImperr --- INSERT

	return retval;
};

void JobWdbeIexBcd::leaveSgeImperr(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeImperr --- INSERT
};

uint JobWdbeIexBcd::enterSgeReverse(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::IDLE;
	retval = nextIxVSgeSuccess;

	ImeitemIMModule* mdl = NULL;
	ImeitemIAMModulePar* mdlApar = NULL;
	ImeitemIAVKeylistKey* klsAkey = NULL;
	ImeitemIJAVKeylistKey* kakJkey = NULL;

	// -- ImeIMModule
	for (unsigned int ix0 = 0; ix0 < imeimmodule.nodes.size(); ix0++) {
		mdl = imeimmodule.nodes[ix0];
		if (mdl->ref != 0) dbswdbe->tblwdbemmodule->removeRecByRef(mdl->ref);

		for (unsigned int ix1 = 0; ix1 < mdl->imeiammodulepar.nodes.size(); ix1++) {
			mdlApar = mdl->imeiammodulepar.nodes[ix1];
			if (mdlApar->ref != 0) dbswdbe->tblwdbeammodulepar->removeRecByRef(mdlApar->ref);
		};

		for (unsigned int ix1 = 0; ix1 < mdl->imeiavkeylistkey.nodes.size(); ix1++) {
			klsAkey = mdl->imeiavkeylistkey.nodes[ix1];
			if (klsAkey->ref != 0) dbswdbe->tblwdbeavkeylistkey->removeRecByRef(klsAkey->ref);

			for (unsigned int ix2 = 0; ix2 < klsAkey->imeijavkeylistkey.nodes.size(); ix2++) {
				kakJkey = klsAkey->imeijavkeylistkey.nodes[ix2];
				if (kakJkey->ref != 0) dbswdbe->tblwdbejavkeylistkey->removeRecByRef(kakJkey->ref);
			};
		};
	};

	return retval;
};

void JobWdbeIexBcd::leaveSgeReverse(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeReverse --- INSERT
};

uint JobWdbeIexBcd::enterSgeCollect(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::CLTDONE;
	retval = nextIxVSgeSuccess;

	ImeitemIMModule* mdl = NULL;
	ImeitemIAMModulePar* mdlApar = NULL;
	ImeitemIAVKeylistKey* klsAkey = NULL;
	ImeitemIJAVKeylistKey* kakJkey = NULL;

	uint ixWdbeVIop;

	vector<ubigint> refs;

	Stcch* stcch = new Stcch(false);

	// IP enterSgeCollect.traverse --- BEGIN

	// -- ImeIMModule
	for (unsigned int ix0 = 0; ix0 < imeimmodule.nodes.size(); ix0++) {
		mdl = imeimmodule.nodes[ix0];

		if (mdl->ref != 0) {
			mdl->hsrefSupRefWdbeMModule = StubWdbe::getStubMdlHsref(dbswdbe, mdl->supRefWdbeMModule, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
			mdl->srefTplRefWdbeMModule = StubWdbe::getStubMdlHsref(dbswdbe, mdl->tplRefWdbeMModule, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
		};

		if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIAMMODULEPAR, ixWdbeVIop)) {
			dbswdbe->tblwdbeammodulepar->loadRefsByMdl(mdl->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) mdl->imeiammodulepar.nodes.push_back(new ImeitemIAMModulePar(dbswdbe, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < mdl->imeiammodulepar.nodes.size(); ix1++) {
			mdlApar = mdl->imeiammodulepar.nodes[ix1];

			if (mdlApar->ref != 0) {
			};
		};

		if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIAVKEYLISTKEY, ixWdbeVIop)) {
			dbswdbe->tblwdbeavkeylistkey->loadRefsByMtbUrf(VecWdbeVMaintable::TBLWDBEMMODULE, mdl->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) mdl->imeiavkeylistkey.nodes.push_back(new ImeitemIAVKeylistKey(dbswdbe, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < mdl->imeiavkeylistkey.nodes.size(); ix1++) {
			klsAkey = mdl->imeiavkeylistkey.nodes[ix1];

			if (klsAkey->ref != 0) {
			};

			if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIJAVKEYLISTKEY, ixWdbeVIop)) {
				dbswdbe->tblwdbejavkeylistkey->loadRefsByKlk(klsAkey->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == klsAkey->refJ) {refs[i] = refs[0]; refs[0] = klsAkey->refJ; break;};
				for (unsigned int i = 0; i < refs.size(); i++) klsAkey->imeijavkeylistkey.nodes.push_back(new ImeitemIJAVKeylistKey(dbswdbe, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < klsAkey->imeijavkeylistkey.nodes.size(); ix2++) {
				kakJkey = klsAkey->imeijavkeylistkey.nodes[ix2];

				if (kakJkey->ref != 0) {
				};
			};
		};
	};
	// IP enterSgeCollect.traverse --- END
	// IP enterSgeCollect.ppr --- INSERT

	delete stcch;

	return retval;
};

void JobWdbeIexBcd::leaveSgeCollect(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeCollect --- INSERT
};

uint JobWdbeIexBcd::enterSgeCltdone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::CLTDONE;

	// IP enterSgeCltdone --- INSERT

	return retval;
};

void JobWdbeIexBcd::leaveSgeCltdone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeCltdone --- INSERT
};

uint JobWdbeIexBcd::enterSgeExport(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	IexWdbeBcd::exportToFile(fullpath, xmlNotTxt, shorttags, imeimmodule);

	return retval;
};

void JobWdbeIexBcd::leaveSgeExport(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeExport --- INSERT
};

uint JobWdbeIexBcd::enterSgeDone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void JobWdbeIexBcd::leaveSgeDone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeDone --- INSERT
};



