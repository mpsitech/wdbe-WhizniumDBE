/**
	* \file JobWdbeIexDal.cpp
	* job handler for job JobWdbeIexDal (implementation)
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

#include "JobWdbeIexDal.h"

#include "JobWdbeIexDal_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

using namespace IexWdbeDal;

/******************************************************************************
 class JobWdbeIexDal
 ******************************************************************************/

JobWdbeIexDal::JobWdbeIexDal(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::JOBWDBEIEXDAL, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	changeStage(dbswdbe, VecVSge::IDLE);

	// IP constructor.cust3 --- INSERT

};

JobWdbeIexDal::~JobWdbeIexDal() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void JobWdbeIexDal::reset(
			DbsWdbe* dbswdbe
		) {
	if (ixVSge != VecVSge::IDLE) changeStage(dbswdbe, VecVSge::IDLE);
};

void JobWdbeIexDal::parseFromFile(
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

void JobWdbeIexDal::import(
			DbsWdbe* dbswdbe
		) {
	if (ixVSge == VecVSge::PRSDONE) changeStage(dbswdbe, VecVSge::IMPORT);
};

void JobWdbeIexDal::reverse(
			DbsWdbe* dbswdbe
		) {
	if (ixVSge == VecVSge::IMPERR) changeStage(dbswdbe, VecVSge::REVERSE);
};

void JobWdbeIexDal::collect(
			DbsWdbe* dbswdbe
			, const map<uint,uint>& _icsWdbeVIop
		) {
	if (ixVSge == VecVSge::IDLE) {
		icsWdbeVIop = _icsWdbeVIop;
		changeStage(dbswdbe, VecVSge::COLLECT);
	};
};

void JobWdbeIexDal::exportToFile(
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

void JobWdbeIexDal::handleRequest(
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

void JobWdbeIexDal::changeStage(
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

string JobWdbeIexDal::getSquawk(
			DbsWdbe* dbswdbe
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::PARSE) || (ixVSge == VecVSge::PRSDONE) || (ixVSge == VecVSge::IMPORT) || (ixVSge == VecVSge::REVERSE) || (ixVSge == VecVSge::COLLECT) || (ixVSge == VecVSge::CLTDONE) || (ixVSge == VecVSge::EXPORT) ) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing data flows and algorithms";
			else if (ixVSge == VecVSge::PRSDONE) retval = "data flows and algorithms parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing data flows and algorithms (" + to_string(impcnt) + " records added)";
			else if (ixVSge == VecVSge::REVERSE) retval = "reversing data flows and algorithms import";
			else if (ixVSge == VecVSge::COLLECT) retval = "collecting data flows and algorithms for export";
			else if (ixVSge == VecVSge::CLTDONE) retval = "data flows and algorithms collected for export";
			else if (ixVSge == VecVSge::EXPORT) retval = "exporting data flows and algorithms";
		};

	} else if ( (ixVSge == VecVSge::PRSERR) || (ixVSge == VecVSge::IMPERR) ) {
		retval = lasterror;

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

uint JobWdbeIexDal::enterSgeIdle(
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

	imeimunit.clear();

	return retval;
};

void JobWdbeIexDal::leaveSgeIdle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWdbeIexDal::enterSgeParse(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::PRSDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::PRSERR;

	try {
		IexWdbeDal::parseFromFile(fullpath, xmlNotTxt, rectpath, imeimunit);

	} catch (SbeException& e) {
		if (e.ix == SbeException::PATHNF) e.vals["path"] = "<hidden>";
		lasterror = e.getSquawk(VecWdbeVError::getIx, VecWdbeVError::getTitle, ixWdbeVLocale);

		retval = nextIxVSgeFailure;
	};

	return retval;
};

void JobWdbeIexDal::leaveSgeParse(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeParse --- INSERT
};

uint JobWdbeIexDal::enterSgePrserr(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::PRSERR;

	// IP enterSgePrserr --- INSERT

	return retval;
};

void JobWdbeIexDal::leaveSgePrserr(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgePrserr --- INSERT
};

uint JobWdbeIexDal::enterSgePrsdone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::PRSDONE;

	// IP enterSgePrsdone --- INSERT

	return retval;
};

void JobWdbeIexDal::leaveSgePrsdone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgePrsdone --- INSERT
};

uint JobWdbeIexDal::enterSgeImport(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IMPERR;

	ImeitemIMUnit* unt = NULL;
	ImeitemIMModule* mdl = NULL;
	ImeitemIMPipeline* ppl = NULL;
	ImeitemICSegment* segC = NULL;
	ImeitemIMSegment* seg = NULL;

	set<ubigint> irefs3;

	uint num3;

	// IP enterSgeImport.prep --- IBEGIN
	ubigint refWdbeMVersion;
	refWdbeMVersion = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref);

	WdbeMUnit* unt_r = NULL;

	ListWdbeMModule mdl_rs;
	WdbeMModule* mdl_r = NULL;

	ImeitemIMSegment* seg2 = NULL;
	// IP enterSgeImport.prep --- IEND

	try {
		// IP enterSgeImport.traverse --- RBEGIN

		// -- ImeIMUnit
		for (unsigned int ix0 = 0; ix0 < imeimunit.nodes.size(); ix0++) {
			unt = imeimunit.nodes[ix0];

			// retrieve
			if (dbswdbe->tblwdbemunit->loadRecBySQL("SELECT * FROM TblWdbeMUnit WHERE refIxVTbl = " + to_string(VecWdbeVMUnitRefTbl::VER) + " AND refUref = " + to_string(refWdbeMVersion) + " AND sref = '" + unt->sref + "'", &unt_r)) {
				unt->ref = unt_r->ref;
				unt->ixVBasetype = unt_r->ixVBasetype;
				unt->refIxVTbl = unt_r->refIxVTbl;
				unt->refUref = unt_r->refUref;
				unt->silRefWdbeMUnit = unt_r->silRefWdbeMUnit;
				unt->refWdbeMSystem = unt_r->refWdbeMSystem;
				unt->refWdbeMModule = unt_r->refWdbeMModule;
				//unt->sref = unt_r->sref;
				unt->Fullsref = unt_r->Fullsref;
				unt->Title = unt_r->Title;
				unt->srefKPackage = unt_r->srefKPackage;
				unt->Easy = unt_r->Easy;
				unt->srefKToolch = unt_r->srefKToolch;
				unt->Comment = unt_r->Comment;

				delete unt_r;

			} else {
				throw SbeException(SbeException::IEX_RETR, {{"ime","ImeIMUnit"}, {"lineno",to_string(unt->lineno)}});
			};

			for (unsigned int ix1 = 0; ix1 < unt->imeimmodule.nodes.size(); ix1++) {
				mdl = unt->imeimmodule.nodes[ix1];

				// retrieve
				dbswdbe->tblwdbemmodule->loadRstBySQL("SELECT * FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND hkUref = " + to_string(unt->ref), false, mdl_rs);
				for (unsigned int i = 0; i < mdl_rs.nodes.size(); i++) {
					mdl_r = mdl_rs.nodes[i];

					if (mdl_r->sref == mdl->sref) {
						if (mdl->hsrefSupRefWdbeMModule != "") if (StubWdbe::getStubMdlHsref(dbswdbe, mdl_r->supRefWdbeMModule) != mdl->hsrefSupRefWdbeMModule) continue;

						mdl->ref = mdl_r->ref;
						mdl->ixVBasetype = mdl_r->ixVBasetype;
						mdl->hkIxVTbl = mdl_r->hkIxVTbl;
						mdl->hkUref = mdl_r->hkUref;
						mdl->hkNum = mdl_r->hkNum;
						mdl->supRefWdbeMModule = mdl_r->supRefWdbeMModule;
						mdl->tplRefWdbeMModule = mdl_r->tplRefWdbeMModule;
						mdl->refWdbeMController = mdl_r->refWdbeMController;
						mdl->refWdbeMImbuf = mdl_r->refWdbeMImbuf;
						mdl->sref = mdl_r->sref;
						mdl->srefWdbeKVendor = mdl_r->srefWdbeKVendor;
						mdl->Srefrule = mdl_r->Srefrule;
						mdl->Comment = mdl_r->Comment;
					};
				};
				if (mdl->ref == 0) throw SbeException(SbeException::IEX_RETR, {{"ime","ImeIMModule"}, {"lineno",to_string(mdl->lineno)}});

				for (unsigned int ix2 = 0; ix2 < mdl->imeimpipeline.nodes.size(); ix2++) {
					ppl = mdl->imeimpipeline.nodes[ix2];

					ppl->hsmRefWdbeMModule = mdl->ref;
					//ppl->sref: TBL
					//ppl->Depth: TBL
					//ppl->Comment: TBL

					dbswdbe->tblwdbempipeline->insertRec(ppl);
					impcnt++;

					irefs3.clear();

					for (unsigned int ix3 = 0; ix3 < ppl->imeicsegment.nodes.size(); ix3++) {
						segC = ppl->imeicsegment.nodes[ix3];

						if (irefs3.find(segC->iref) != irefs3.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(segC->iref)}, {"ime","ImeICSegment"}, {"lineno",to_string(segC->lineno)}});
						segC->ref = dbswdbe->tblwdbecsegment->getNewRef();
						irefs3.insert(segC->iref);

						impcnt++;
					};

					num3 = 1;

					for (unsigned int ix3 = 0; ix3 < ppl->imeimsegment.nodes.size(); ix3++) {
						seg = ppl->imeimsegment.nodes[ix3];

						//seg->refWdbeCSegment: PREVIMP
						if (seg->irefRefWdbeCSegment != 0) {
							for (unsigned int i = 0; i < ppl->imeicsegment.nodes.size(); i++)
								if (ppl->imeicsegment.nodes[i]->iref == seg->irefRefWdbeCSegment) {
									seg->refWdbeCSegment = ppl->imeicsegment.nodes[i]->ref;
									break;
								};
							if (seg->refWdbeCSegment == 0) throw SbeException(SbeException::IEX_IREF, {{"iref",to_string(seg->irefRefWdbeCSegment)}, {"iel","irefRefWdbeCSegment"}, {"lineno",to_string(seg->lineno)}});
						};
						seg->pplRefWdbeMPipeline = ppl->ref;
						seg->pplNum = num3++;
						//seg->supRefWdbeMSegment: IMPPP
						//seg->sref: TBL
						//seg->Infmt: TBL
						//seg->Outfmt: TBL
						//seg->Latency: TBL
						//seg->Comment: TBL

						dbswdbe->tblwdbemsegment->insertRec(seg);
						impcnt++;
					};
				};
			};
		};
		// IP enterSgeImport.traverse --- REND

		// IP enterSgeImport.ppr --- IBEGIN
		for (unsigned int ix0 = 0; ix0 < imeimunit.nodes.size(); ix0++) {
			unt = imeimunit.nodes[ix0];

			for (unsigned int ix1 = 0; ix1 < unt->imeimmodule.nodes.size(); ix1++) {
				mdl = unt->imeimmodule.nodes[ix1];

				for (unsigned int ix2 = 0; ix2 < mdl->imeimpipeline.nodes.size(); ix2++) {
					ppl = mdl->imeimpipeline.nodes[ix2];

					for (unsigned int ix3 = 0; ix3 < ppl->imeimsegment.nodes.size(); ix3++) {
						seg = ppl->imeimsegment.nodes[ix3];

						if (seg->hsrefSupRefWdbeMSegment != "") {
							for (unsigned int i = 0; i < ppl->imeimsegment.nodes.size(); i++) {
								seg2 = ppl->imeimsegment.nodes[i];

								if ( ((seg2->hsrefSupRefWdbeMSegment == "") && (seg2->sref == seg->hsrefSupRefWdbeMSegment))
											|| ((seg2->hsrefSupRefWdbeMSegment != "") && ((seg2->hsrefSupRefWdbeMSegment + ";" + seg2->sref) == seg->hsrefSupRefWdbeMSegment)) ) {
									seg->supRefWdbeMSegment = seg2->ref;
									break;
								};
							};

							if (seg->supRefWdbeMSegment == 0) throw SbeException(SbeException::IEX_THSREF, {{"thsref",seg->hsrefSupRefWdbeMSegment}, {"iel","hsrefSupRefWdbeMSegment"}, {"lineno",to_string(seg->lineno)}});
							else dbswdbe->tblwdbemsegment->updateRec(seg);
						};
					};
				};
			};
		};
		// IP enterSgeImport.ppr --- IEND
	} catch (SbeException& e) {
		lasterror = e.getSquawk(VecWdbeVError::getIx, VecWdbeVError::getTitle, ixWdbeVLocale);
		retval = nextIxVSgeFailure;
	};

	return retval;
};

void JobWdbeIexDal::leaveSgeImport(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeImport --- INSERT
};

uint JobWdbeIexDal::enterSgeImperr(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IMPERR;

	// IP enterSgeImperr --- INSERT

	return retval;
};

void JobWdbeIexDal::leaveSgeImperr(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeImperr --- INSERT
};

uint JobWdbeIexDal::enterSgeReverse(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::IDLE;
	retval = nextIxVSgeSuccess;

	ImeitemIMUnit* unt = NULL;
	ImeitemIMModule* mdl = NULL;
	ImeitemIMPipeline* ppl = NULL;
	ImeitemIMSegment* seg = NULL;

	// -- ImeIMUnit
	for (unsigned int ix0 = 0; ix0 < imeimunit.nodes.size(); ix0++) {
		unt = imeimunit.nodes[ix0];
		if (unt->ref != 0) dbswdbe->tblwdbemunit->removeRecByRef(unt->ref);

		for (unsigned int ix1 = 0; ix1 < unt->imeimmodule.nodes.size(); ix1++) {
			mdl = unt->imeimmodule.nodes[ix1];
			if (mdl->ref != 0) dbswdbe->tblwdbemmodule->removeRecByRef(mdl->ref);

			for (unsigned int ix2 = 0; ix2 < mdl->imeimpipeline.nodes.size(); ix2++) {
				ppl = mdl->imeimpipeline.nodes[ix2];
				if (ppl->ref != 0) dbswdbe->tblwdbempipeline->removeRecByRef(ppl->ref);

				for (unsigned int ix3 = 0; ix3 < ppl->imeimsegment.nodes.size(); ix3++) {
					seg = ppl->imeimsegment.nodes[ix3];
					if (seg->ref != 0) dbswdbe->tblwdbemsegment->removeRecByRef(seg->ref);
				};
			};
		};
	};

	return retval;
};

void JobWdbeIexDal::leaveSgeReverse(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeReverse --- INSERT
};

uint JobWdbeIexDal::enterSgeCollect(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::CLTDONE;
	retval = nextIxVSgeSuccess;

	ImeitemIMUnit* unt = NULL;
	ImeitemIMModule* mdl = NULL;
	ImeitemIMPipeline* ppl = NULL;
	ImeitemICSegment* segC = NULL;
	ImeitemIMSegment* seg = NULL;

	uint ixWdbeVIop;

	vector<ubigint> refs;

	Stcch* stcch = new Stcch(false);

	// IP enterSgeCollect.traverse --- BEGIN

	// -- ImeIMUnit
	for (unsigned int ix0 = 0; ix0 < imeimunit.nodes.size(); ix0++) {
		unt = imeimunit.nodes[ix0];

		if (unt->ref != 0) {
		};

		if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMMODULE, ixWdbeVIop)) {
			dbswdbe->tblwdbemmodule->loadRefsByHktHku(VecWdbeVMModuleHkTbl::UNT, unt->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) unt->imeimmodule.nodes.push_back(new ImeitemIMModule(dbswdbe, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < unt->imeimmodule.nodes.size(); ix1++) {
			mdl = unt->imeimmodule.nodes[ix1];

			if (mdl->ref != 0) {
				mdl->hsrefSupRefWdbeMModule = StubWdbe::getStubMdlHsref(dbswdbe, mdl->supRefWdbeMModule, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
			};

			if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMPIPELINE, ixWdbeVIop)) {
				dbswdbe->tblwdbempipeline->loadRefsByHsm(mdl->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) mdl->imeimpipeline.nodes.push_back(new ImeitemIMPipeline(dbswdbe, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < mdl->imeimpipeline.nodes.size(); ix2++) {
				ppl = mdl->imeimpipeline.nodes[ix2];

				if (ppl->ref != 0) {
				};

				for (unsigned int ix3 = 0; ix3 < ppl->imeicsegment.nodes.size(); ix3++) {
					segC = ppl->imeicsegment.nodes[ix3];

					if (segC->ref != 0) {
						segC->iref = ix3+1;
					};
				};

				if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMSEGMENT, ixWdbeVIop)) {
					dbswdbe->tblwdbemsegment->loadRefsByPpl(ppl->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) ppl->imeimsegment.nodes.push_back(new ImeitemIMSegment(dbswdbe, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < ppl->imeimsegment.nodes.size(); ix3++) {
					seg = ppl->imeimsegment.nodes[ix3];

					if (seg->ref != 0) {
						//seg->irefRefWdbeCSegment: IREF
						seg->hsrefSupRefWdbeMSegment = StubWdbe::getStubSegHsref(dbswdbe, seg->supRefWdbeMSegment, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
					};
				};
			};
		};
	};
	// IP enterSgeCollect.traverse --- END
	// IP enterSgeCollect.ppr --- INSERT

	delete stcch;

	return retval;
};

void JobWdbeIexDal::leaveSgeCollect(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeCollect --- INSERT
};

uint JobWdbeIexDal::enterSgeCltdone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::CLTDONE;

	// IP enterSgeCltdone --- INSERT

	return retval;
};

void JobWdbeIexDal::leaveSgeCltdone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeCltdone --- INSERT
};

uint JobWdbeIexDal::enterSgeExport(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	IexWdbeDal::exportToFile(fullpath, xmlNotTxt, shorttags, imeimunit);

	return retval;
};

void JobWdbeIexDal::leaveSgeExport(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeExport --- INSERT
};

uint JobWdbeIexDal::enterSgeDone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void JobWdbeIexDal::leaveSgeDone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeDone --- INSERT
};
