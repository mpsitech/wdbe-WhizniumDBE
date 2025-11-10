/**
	* \file JobWdbeIexFin.cpp
	* job handler for job JobWdbeIexFin (implementation)
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

#include "JobWdbeIexFin.h"

#include "JobWdbeIexFin_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

using namespace IexWdbeFin;

/******************************************************************************
 class JobWdbeIexFin
 ******************************************************************************/

JobWdbeIexFin::JobWdbeIexFin(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::JOBWDBEIEXFIN, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	changeStage(dbswdbe, VecVSge::IDLE);

	// IP constructor.cust3 --- INSERT

};

JobWdbeIexFin::~JobWdbeIexFin() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void JobWdbeIexFin::reset(
			DbsWdbe* dbswdbe
		) {
	if (ixVSge != VecVSge::IDLE) changeStage(dbswdbe, VecVSge::IDLE);
};

void JobWdbeIexFin::parseFromFile(
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

void JobWdbeIexFin::import(
			DbsWdbe* dbswdbe
		) {
	if (ixVSge == VecVSge::PRSDONE) changeStage(dbswdbe, VecVSge::IMPORT);
};

void JobWdbeIexFin::reverse(
			DbsWdbe* dbswdbe
		) {
	if (ixVSge == VecVSge::IMPERR) changeStage(dbswdbe, VecVSge::REVERSE);
};

void JobWdbeIexFin::collect(
			DbsWdbe* dbswdbe
			, const map<uint,uint>& _icsWdbeVIop
		) {
	if (ixVSge == VecVSge::IDLE) {
		icsWdbeVIop = _icsWdbeVIop;
		changeStage(dbswdbe, VecVSge::COLLECT);
	};
};

void JobWdbeIexFin::exportToFile(
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

void JobWdbeIexFin::handleRequest(
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

void JobWdbeIexFin::changeStage(
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

string JobWdbeIexFin::getSquawk(
			DbsWdbe* dbswdbe
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::PARSE) || (ixVSge == VecVSge::PRSDONE) || (ixVSge == VecVSge::IMPORT) || (ixVSge == VecVSge::REVERSE) || (ixVSge == VecVSge::COLLECT) || (ixVSge == VecVSge::CLTDONE) || (ixVSge == VecVSge::EXPORT) ) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing fine structure";
			else if (ixVSge == VecVSge::PRSDONE) retval = "fine structure parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing fine structure (" + to_string(impcnt) + " records added)";
			else if (ixVSge == VecVSge::REVERSE) retval = "reversing fine structure import";
			else if (ixVSge == VecVSge::COLLECT) retval = "collecting fine structure for export";
			else if (ixVSge == VecVSge::CLTDONE) retval = "fine structure collected for export";
			else if (ixVSge == VecVSge::EXPORT) retval = "exporting fine structure";
		};

	} else if ( (ixVSge == VecVSge::PRSERR) || (ixVSge == VecVSge::IMPERR) ) {
		retval = lasterror;

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

uint JobWdbeIexFin::enterSgeIdle(
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

void JobWdbeIexFin::leaveSgeIdle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWdbeIexFin::enterSgeParse(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::PRSDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::PRSERR;

	try {
		IexWdbeFin::parseFromFile(fullpath, xmlNotTxt, rectpath, imeimunit);

	} catch (SbeException& e) {
		if (e.ix == SbeException::PATHNF) e.vals["path"] = "<hidden>";
		lasterror = e.getSquawk(VecWdbeVError::getIx, VecWdbeVError::getTitle, ixWdbeVLocale);

		retval = nextIxVSgeFailure;
	};

	return retval;
};

void JobWdbeIexFin::leaveSgeParse(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeParse --- INSERT
};

uint JobWdbeIexFin::enterSgePrserr(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::PRSERR;

	// IP enterSgePrserr --- INSERT

	return retval;
};

void JobWdbeIexFin::leaveSgePrserr(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgePrserr --- INSERT
};

uint JobWdbeIexFin::enterSgePrsdone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::PRSDONE;

	// IP enterSgePrsdone --- INSERT

	return retval;
};

void JobWdbeIexFin::leaveSgePrsdone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgePrsdone --- INSERT
};

uint JobWdbeIexFin::enterSgeImport(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IMPERR;

	ImeitemIMUnit* unt = NULL;
	ImeitemICSignal1* sigC1 = NULL;
	ImeitemIMBank* bnk = NULL;
	ImeitemIMInterrupt1* int1 = NULL;
	ImeitemIMModule* mdl = NULL;
	ImeitemIMSignal1* sig1 = NULL;
	ImeitemICGeneric* genC = NULL;
	ImeitemICPin* pinC = NULL;
	ImeitemICPort* prtC = NULL;
	ImeitemICSignal2* sigC2 = NULL;
	ImeitemICVariable1* varC1 = NULL;
	ImeitemIMCdc* cdc = NULL;
	ImeitemIMController* ctr = NULL;
	ImeitemIMGeneric* gen = NULL;
	ImeitemIMPin* pin = NULL;
	ImeitemIMPort* prt = NULL;
	ImeitemIMProcess* prc = NULL;
	ImeitemIMSensitivity1* sns1 = NULL;
	ImeitemIMSignal2* sig2 = NULL;
	ImeitemIMVariable1* var1 = NULL;
	ImeitemIAMPinPar* pinApar = NULL;
	ImeitemIAVKeylistKey* klsAkey = NULL;
	ImeitemICVariable2* varC2 = NULL;
	ImeitemIJMPinSref* pinJsrf = NULL;
	ImeitemIMCommand* cmd = NULL;
	ImeitemIMError* err = NULL;
	ImeitemIMFsm* fsm = NULL;
	ImeitemIMSensitivity2* sns2 = NULL;
	ImeitemIMVariable2* var2 = NULL;
	ImeitemIRMCdcMSignal* cdcRsig = NULL;
	ImeitemIRMCommandMController* cmdRctr = NULL;
	ImeitemICFsmstate* fstC = NULL;
	ImeitemIJAVKeylistKey* kakJkey = NULL;
	ImeitemIMFsmstate* fst = NULL;
	ImeitemIAMFsmstateStep* fstAstp = NULL;

	set<ubigint> irefs1, irefs2, irefs3, irefs4;

	uint num1, num2, num3, num4, num5;

	// IP enterSgeImport.prep --- IBEGIN
	ubigint refWdbeMVersion;
	refWdbeMVersion = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref);

	ubigint ref;

	WdbeMUnit* unt_r = NULL;
	WdbeMBank* bnk_r = NULL;
	WdbeMPin* pin_r = NULL;

	ListWdbeMModule mdl_rs;
	WdbeMModule* mdl_r = NULL;

	WdbeMController* ctr_r = NULL;
	WdbeMGeneric* gen_r = NULL;
	WdbeMPort* prt_r = NULL;

	size_t ptr;
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

			for (unsigned int ix1 = 0; ix1 < unt->imeimbank.nodes.size(); ix1++) {
				bnk = unt->imeimbank.nodes[ix1];

				bnk->ixWdbeVIop = VecWdbeVIop::getIx(bnk->srefIxWdbeVIop);
				if ((bnk->ixWdbeVIop != VecWdbeVIop::RETR) && (bnk->ixWdbeVIop != VecWdbeVIop::RETRUPD)) throw SbeException(SbeException::IEX_IOP, {{"iop",bnk->srefIxWdbeVIop}, {"ime","ImeIMBank"}, {"lineno",to_string(bnk->lineno)}});

				// retrieve
				if (dbswdbe->tblwdbembank->loadRecBySQL("SELECT * FROM TblWdbeMBank WHERE refWdbeMUnit = " + to_string(unt->ref) + " AND sref = '" + bnk->sref + "'", &bnk_r)) {
					bnk->ref = bnk_r->ref;
					if (bnk->srefKVoltstd == "") bnk->srefKVoltstd = bnk_r->srefKVoltstd;

					delete bnk_r;

				} else throw SbeException(SbeException::IEX_RETR, {{"ime","ImeIMBank"}, {"lineno",to_string(bnk->lineno)}});

				bnk->refWdbeMUnit = unt->ref;
				//bnk->sref: TBL
				//bnk->srefKVoltstd: TBL

				if (bnk->ixWdbeVIop == VecWdbeVIop::RETRUPD) dbswdbe->tblwdbembank->updateRec(bnk);
				impcnt++;

				irefs2.clear();

				for (unsigned int ix2 = 0; ix2 < bnk->imeicpin.nodes.size(); ix2++) {
					pinC = bnk->imeicpin.nodes[ix2];

					if (irefs2.find(pinC->iref) != irefs2.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(pinC->iref)}, {"ime","ImeICPin"}, {"lineno",to_string(pinC->lineno)}});
					pinC->ref = dbswdbe->tblwdbecpin->getNewRef();
					irefs2.insert(pinC->iref);
				};

				for (unsigned int ix2 = 0; ix2 < bnk->imeimpin.nodes.size(); ix2++) {
					pin = bnk->imeimpin.nodes[ix2];

					pin->ixWdbeVIop = VecWdbeVIop::getIx(pin->srefIxWdbeVIop);
					if ((pin->ixWdbeVIop != VecWdbeVIop::RETR) && (pin->ixWdbeVIop != VecWdbeVIop::RETRUPD)) throw SbeException(SbeException::IEX_IOP, {{"iop",pin->srefIxWdbeVIop}, {"ime","ImeIMPin"}, {"lineno",to_string(pin->lineno)}});

					// retrieve
					pin_r = NULL;
					if (!dbswdbe->tblwdbempin->loadRecBySQL("SELECT * FROM TblWdbeMPin WHERE refWdbeMBank = " + to_string(bnk->ref) + " AND sref = '" + pin->sref + "'", &pin_r))
						if (!dbswdbe->tblwdbempin->loadRecBySQL("SELECT * FROM TblWdbeMPin WHERE refWdbeMBank = " + to_string(bnk->ref) + " AND Location = '" + pin->Location + "'", &pin_r))
							dbswdbe->tblwdbempin->loadRecBySQL("SELECT TblWdbeMPin.* FROM TblWdbeMPin, TblWdbeJMPinSref WHERE TblWdbeJMPinSref.refWdbeMPin = TblWdbeMPin.ref AND TblWdbeMPin.refWdbeMBank = " + to_string(bnk->ref) + " AND TblWdbeJMPinSref.sref = '" + pin->sref + "'", &pin_r);

					if (pin_r) {
						pin->ref = pin_r->ref;
						pin->refWdbeCPin = pin_r->refWdbeCPin;
						pin->refJSref = pin_r->refJSref;
						if (pin->ixWdbeVIop == VecWdbeVIop::RETR) if (pin->sref == "") pin->sref = pin_r->sref;
						pin->Location = pin_r->Location;

						delete pin_r;

					} else throw SbeException(SbeException::IEX_RETR, {{"ime","ImeIMPin"}, {"lineno",to_string(pin->lineno)}});

					//pin->refWdbeCPin: PREVIMP
					if (pin->irefRefWdbeCPin != 0) {
						if (irefs2.find(pin->irefRefWdbeCPin) == irefs2.end()) {
							pinC = new ImeitemICPin(pin->irefRefWdbeCPin);
							pinC->ref = dbswdbe->tblwdbecpin->getNewRef();
							bnk->imeicpin.nodes.push_back(pinC);
							irefs2.insert(pinC->iref);
						} else {
							for (unsigned int i = 0; i < bnk->imeicpin.nodes.size(); i++) {
								pinC = bnk->imeicpin.nodes[i];
								if (pinC->iref == pin->irefRefWdbeCPin) break;
							};
						};
						pin->refWdbeCPin = pinC->ref;
					};
					pin->refWdbeMBank = bnk->ref;
					//pin->refJSref: SUB
					//pin->sref: TBL
					//pin->Location: TBL

					if (pin->ixWdbeVIop == VecWdbeVIop::RETRUPD) dbswdbe->tblwdbempin->updateRec(pin);
					impcnt++;

					if (pin->ixWdbeVIop == VecWdbeVIop::RETRUPD) {
						if (pin->sref != "") {
							pinJsrf = new ImeitemIJMPinSref();
							pin->imeijmpinsref.nodes.emplace(pin->imeijmpinsref.nodes.begin(), pinJsrf);

							pinJsrf->refWdbeMPin = pin->ref;
							pinJsrf->sref = pin->sref;
						};
					};

					for (unsigned int ix3 = 0; ix3 < pin->imeijmpinsref.nodes.size(); ix3++) {
						pinJsrf = pin->imeijmpinsref.nodes[ix3];

						pinJsrf->refWdbeMPin = pin->ref;
						//pinJsrf->x1RefWdbeMPeripheral: CUSTSQL
						if (pinJsrf->srefX1RefWdbeMPeripheral != "") {
							dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMPeripheral WHERE refWdbeMUnit = " + to_string(unt->ref) + " AND sref = '" + pinJsrf->srefX1RefWdbeMPeripheral + "'", pinJsrf->x1RefWdbeMPeripheral);
							if (pinJsrf->x1RefWdbeMPeripheral == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",pinJsrf->srefX1RefWdbeMPeripheral}, {"iel","srefX1RefWdbeMPeripheral"}, {"lineno",to_string(pinJsrf->lineno)}});
						};
						//pinJsrf->sref: TBL

						dbswdbe->tblwdbejmpinsref->insertRec(pinJsrf);
						impcnt++;

						if (ix3 == 0) {
							pin->refJSref = pinJsrf->ref;
							pin->sref = pinJsrf->sref;
							dbswdbe->tblwdbempin->updateRec(pin);
						};
					};

					for (unsigned int ix3 = 0; ix3 < pin->imeiampinpar.nodes.size(); ix3++) {
						pinApar = pin->imeiampinpar.nodes[ix3];

						pinApar->refWdbeMPin = pin->ref;
						//pinApar->x1SrefKKey: TBL
						//pinApar->Val: TBL

						dbswdbe->tblwdbeampinpar->insertRec(pinApar);
						impcnt++;
					};
				};
			};

			for (unsigned int ix1 = 0; ix1 < unt->imeiminterrupt1.nodes.size(); ix1++) {
				int1 = unt->imeiminterrupt1.nodes[ix1];

				int1->refWdbeMUnit = unt->ref;
				//int1->sref: TBL
				//int1->Comment: TBL

				dbswdbe->tblwdbeminterrupt->insertRec(int1);
				impcnt++;
			};

			irefs1.clear();

			for (unsigned int ix1 = 0; ix1 < unt->imeicsignal1.nodes.size(); ix1++) {
				sigC1 = unt->imeicsignal1.nodes[ix1];

				if (irefs1.find(sigC1->iref) != irefs1.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(sigC1->iref)}, {"ime","ImeICSignal1"}, {"lineno",to_string(sigC1->lineno)}});
				sigC1->ref = dbswdbe->tblwdbecsignal->getNewRef();
				irefs1.insert(sigC1->iref);

				impcnt++;
			};

			num1 = 1;

			for (unsigned int ix1 = 0; ix1 < unt->imeimsignal1.nodes.size(); ix1++) {
				sig1 = unt->imeimsignal1.nodes[ix1];

				sig1->ixVBasetype = VecWdbeVMSignalBasetype::getIx(sig1->srefIxVBasetype);
				if (sig1->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",sig1->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(sig1->lineno)}});
				//sig1->refWdbeCSignal: PREVIMP
				if (sig1->irefRefWdbeCSignal != 0) {
					if (irefs1.find(sig1->irefRefWdbeCSignal) == irefs1.end()) {
						sigC1 = new ImeitemICSignal1(sig1->irefRefWdbeCSignal);
						sigC1->ref = dbswdbe->tblwdbecsignal->getNewRef();
						unt->imeicsignal1.nodes.push_back(sigC1);
						irefs1.insert(sigC1->iref);
					} else {
						for (unsigned int i = 0; i < unt->imeicsignal1.nodes.size(); i++) {
							sigC1 = unt->imeicsignal1.nodes[i];
							if (sigC1->iref == sig1->irefRefWdbeCSignal) break;
						};
					};
					sig1->refWdbeCSignal = sigC1->ref;
				};
				sig1->refIxVTbl = VecWdbeVMSignalRefTbl::UNT;
				sig1->refUref = unt->ref;
				sig1->refNum = num1++;
				sig1->mgeIxVTbl = VecWdbeVMSignalMgeTbl::MDL;
				//sig1->mgeUref: CUSTSQL
				dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND hkUref = " + to_string(unt->ref) + " AND sref = '" + sig1->srefMgeUref + "'", sig1->mgeUref);
				if (sig1->mgeUref == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",sig1->srefMgeUref}, {"iel","srefMgeUref"}, {"lineno",to_string(sig1->lineno)}});
				//sig1->sref: TBL
				sig1->srefWdbeKHdltype = "bit";
				sig1->Width = 1;
				//sig1->Comment: TBL

				dbswdbe->tblwdbemsignal->insertRec(sig1);
				impcnt++;
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

				for (unsigned int ix2 = 0; ix2 < mdl->imeimsensitivity1.nodes.size(); ix2++) {
					sns1 = mdl->imeimsensitivity1.nodes[ix2];

					sns1->refIxVTbl = VecWdbeVMSensitivityRefTbl::MDL;
					sns1->refUref = mdl->ref;
					sns1->srcIxVTbl = VecWdbeVMSensitivitySrcTbl::getIx(sns1->srefSrcIxVTbl);
					if (sns1->srcIxVTbl == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",sns1->srefSrcIxVTbl}, {"iel","srefSrcIxVTbl"}, {"lineno",to_string(sns1->lineno)}});
					//sns1->srcUref: CUSTSQLPP

					dbswdbe->tblwdbemsensitivity->insertRec(sns1);
					impcnt++;
				};

				irefs2.clear();

				for (unsigned int ix2 = 0; ix2 < mdl->imeicvariable1.nodes.size(); ix2++) {
					varC1 = mdl->imeicvariable1.nodes[ix2];

					if (irefs2.find(varC1->iref) != irefs2.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(varC1->iref)}, {"ime","ImeICVariable1"}, {"lineno",to_string(varC1->lineno)}});
					varC1->ref = dbswdbe->tblwdbecvariable->getNewRef();
					irefs2.insert(varC1->iref);

					impcnt++;
				};

				num2 = 1;

				for (unsigned int ix2 = 0; ix2 < mdl->imeimvariable1.nodes.size(); ix2++) {
					var1 = mdl->imeimvariable1.nodes[ix2];

					//var1->refWdbeCVariable: PREVIMP
					if (var1->irefRefWdbeCVariable != 0) {
						if (irefs2.find(var1->irefRefWdbeCVariable) == irefs2.end()) {
							varC1 = new ImeitemICVariable1(var1->irefRefWdbeCVariable);
							varC1->ref = dbswdbe->tblwdbecvariable->getNewRef();
							mdl->imeicvariable1.nodes.push_back(varC1);
							irefs2.insert(varC1->iref);
						} else {
							for (unsigned int i = 0; i < mdl->imeicvariable1.nodes.size(); i++) {
								varC1 = mdl->imeicvariable1.nodes[i];
								if (varC1->iref == var1->irefRefWdbeCVariable) break;
							};
						};
						var1->refWdbeCVariable = varC1->ref;
					};
					var1->refIxVTbl = VecWdbeVMVariableRefTbl::MDL;
					var1->refUref = mdl->ref;
					var1->refNum = num2++;
					//var1->sref: TBL
					//var1->srefWdbeKHdltype: TBL
					//var1->Width: TBL
					//var1->Minmax: TBL
					//var1->Comment: TBL

					dbswdbe->tblwdbemvariable->insertRec(var1);
					impcnt++;
				};

				irefs2.clear();

				for (unsigned int ix2 = 0; ix2 < mdl->imeicgeneric.nodes.size(); ix2++) {
					genC = mdl->imeicgeneric.nodes[ix2];

					if (irefs2.find(genC->iref) != irefs2.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(genC->iref)}, {"ime","ImeICGeneric"}, {"lineno",to_string(genC->lineno)}});
					genC->ref = dbswdbe->tblwdbecgeneric->getNewRef();
					irefs2.insert(genC->iref);
				};

				num2 = 1;

				for (unsigned int ix2 = 0; ix2 < mdl->imeimgeneric.nodes.size(); ix2++) {
					gen = mdl->imeimgeneric.nodes[ix2];

					gen->ixWdbeVIop = VecWdbeVIop::getIx(gen->srefIxWdbeVIop);
					if ((gen->ixWdbeVIop != VecWdbeVIop::RETRUPD) && (gen->ixWdbeVIop != VecWdbeVIop::INS)) throw SbeException(SbeException::IEX_IOP, {{"iop",gen->srefIxWdbeVIop}, {"ime","ImeIMGeneric"}, {"lineno",to_string(gen->lineno)}});

					if (gen->ixWdbeVIop == VecWdbeVIop::RETRUPD) {
						// retrieve
						if (dbswdbe->tblwdbemgeneric->loadRecBySQL("SELECT * FROM TblWdbeMGeneric WHERE mdlRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = '" + gen->sref + "'", &gen_r)) {
							gen->ref = gen_r->ref;
							gen->refWdbeCGeneric = gen_r->refWdbeCGeneric;
							//gen->mdlRefWdbeMModule = gen_r->mdlRefWdbeMModule;
							gen->mdlNum = gen_r->mdlNum;
							gen->sref = gen_r->sref;
							gen->srefWdbeKHdltype = gen_r->srefWdbeKHdltype;
							gen->Width = gen_r->Width;
							gen->Minmax = gen_r->Minmax;
							if (gen->Defval == "") gen->Defval = gen_r->Defval;
							if (gen->srcSrefWdbeMGeneric == "") gen->srcSrefWdbeMGeneric = gen_r->srcSrefWdbeMGeneric;
							gen->Comment = gen_r->Comment;

							delete gen_r;

							gen->mdlRefWdbeMModule = mdl->ref;
							//gen->Defval: TBL
							//gen->srcSrefWdbeMGeneric: TBL

							dbswdbe->tblwdbemgeneric->updateRec(gen);
						} else throw SbeException(SbeException::IEX_RETR, {{"ime","ImeIMGeneric"}, {"lineno",to_string(gen->lineno)}});

					} else if (gen->ixWdbeVIop == VecWdbeVIop::INS) {
						//gen->refWdbeCGeneric: PREVIMP
						if (gen->irefRefWdbeCGeneric != 0) {
							if (irefs2.find(gen->irefRefWdbeCGeneric) == irefs2.end()) {
								genC = new ImeitemICGeneric(gen->irefRefWdbeCGeneric);
								genC->ref = dbswdbe->tblwdbecgeneric->getNewRef();
								mdl->imeicgeneric.nodes.push_back(genC);
								irefs2.insert(genC->iref);
							} else {
								for (unsigned int i = 0; i < mdl->imeicgeneric.nodes.size(); i++) {
									genC = mdl->imeicgeneric.nodes[i];
									if (genC->iref == gen->irefRefWdbeCGeneric) break;
								};
							};
							gen->refWdbeCGeneric = genC->ref;
						};
						gen->mdlRefWdbeMModule = mdl->ref;
						//gen->mdlNum: CUST
						gen->mdlNum = num2++; // TBD
						//gen->sref: TBL
						//gen->srefWdbeKHdltype: TBL
						//gen->Width: TBL
						//gen->Minmax: TBL
						//gen->Defval: TBL
						//gen->srcSrefWdbeMGeneric: TBL
						//gen->Comment: TBL

						dbswdbe->tblwdbemgeneric->insertRec(gen);
						impcnt++;
					};
				};

				irefs2.clear();

				for (unsigned int ix2 = 0; ix2 < mdl->imeicport.nodes.size(); ix2++) {
					prtC = mdl->imeicport.nodes[ix2];

					if (irefs2.find(prtC->iref) != irefs2.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(prtC->iref)}, {"ime","ImeICPort"}, {"lineno",to_string(prtC->lineno)}});
					prtC->ref = dbswdbe->tblwdbecport->getNewRef();
					irefs2.insert(prtC->iref);
				};

				for (unsigned int ix2 = 0; ix2 < mdl->imeimport.nodes.size(); ix2++) {
					prt = mdl->imeimport.nodes[ix2];

					prt->ixWdbeVIop = VecWdbeVIop::getIx(prt->srefIxWdbeVIop);
					if ((prt->ixWdbeVIop != VecWdbeVIop::RETRUPD) && (prt->ixWdbeVIop != VecWdbeVIop::INS)) throw SbeException(SbeException::IEX_IOP, {{"iop",prt->srefIxWdbeVIop}, {"ime","ImeIMPort"}, {"lineno",to_string(prt->lineno)}});

					if (prt->ixWdbeVIop == VecWdbeVIop::RETRUPD) {
						// retrieve
						if (dbswdbe->tblwdbemport->loadRecBySQL("SELECT * FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = '" + prt->sref + "'", &prt_r)) {
							prt->ref = prt_r->ref;
							prt->refWdbeCPort= prt_r->refWdbeCPort;
							//prt->mdlRefWdbeMModule= prt_r->mdlRefWdbeMModule;
							prt->mdlNum= prt_r->mdlNum;
							prt->mdlIxVCat= prt_r->mdlIxVCat;
							prt->sref= prt_r->sref;
							prt->ixVDir= prt_r->ixVDir;
							prt->srefWdbeKHdltype= prt_r->srefWdbeKHdltype;
							prt->Width= prt_r->Width;
							prt->Minmax= prt_r->Minmax;
							//prt->Defval= prt_r->Defval;
							//prt->cpiSrefWdbeMPin= prt_r->cpiSrefWdbeMPin;
							//prt->cprSrefWdbeMPort= prt_r->cprSrefWdbeMPort;
							//prt->csiSrefWdbeMSignal= prt_r->csiSrefWdbeMSignal;
							prt->Comment= prt_r->Comment;

							delete prt_r;

							prt->mdlRefWdbeMModule = mdl->ref;
							//prt->Defval: TBL
							//prt->cpiSrefWdbeMPin: TBL
							//prt->cprSrefWdbeMPort: TBL
							//prt->csiSrefWdbeMSignal: TBL

							dbswdbe->tblwdbemport->updateRec(prt);
						} else throw SbeException(SbeException::IEX_RETR, {{"ime","ImeIMPort"}, {"lineno",to_string(prt->lineno)}});

					} else if (prt->ixWdbeVIop == VecWdbeVIop::INS) {
						//prt->refWdbeCPort: PREVIMP
						if (prt->irefRefWdbeCPort != 0) {
							if (irefs2.find(prt->irefRefWdbeCPort) == irefs2.end()) {
								prtC = new ImeitemICPort(prt->irefRefWdbeCPort);
								prtC->ref = dbswdbe->tblwdbecport->getNewRef();
								mdl->imeicport.nodes.push_back(prtC);
								irefs2.insert(prtC->iref);
							} else {
								for (unsigned int i = 0; i < mdl->imeicport.nodes.size(); i++) {
									prtC = mdl->imeicport.nodes[i];
									if (prtC->iref == prt->irefRefWdbeCPort) break;
								};
							};
							prt->refWdbeCPort = prtC->ref;
						};
						prt->mdlRefWdbeMModule = mdl->ref;
						//prt->mdlNum: CUST
						prt->mdlNum = num2++;
						prt->mdlIxVCat = VecWdbeVMPortMdlCat::getIx(prt->srefMdlIxVCat);
						if (prt->mdlIxVCat == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",prt->srefMdlIxVCat}, {"iel","srefMdlIxVCat"}, {"lineno",to_string(prt->lineno)}});
						//prt->sref: TBL
						prt->ixVDir = VecWdbeVMPortDir::getIx(prt->srefIxVDir);
						if (prt->ixVDir == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",prt->srefIxVDir}, {"iel","srefIxVDir"}, {"lineno",to_string(prt->lineno)}});
						//prt->srefWdbeKHdltype: TBL
						//prt->Width: TBL
						//prt->Minmax: TBL
						//prt->Defval: TBL
						//prt->cpiSrefWdbeMPin: TBL
						//prt->cprSrefWdbeMPort: TBL
						//prt->csiSrefWdbeMSignal: TBL
						//prt->Comment: TBL

						dbswdbe->tblwdbemport->insertRec(prt);
						impcnt++;
					};
				};

				irefs2.clear();

				for (unsigned int ix2 = 0; ix2 < mdl->imeicsignal2.nodes.size(); ix2++) {
					sigC2 = mdl->imeicsignal2.nodes[ix2];

					if (irefs2.find(sigC2->iref) != irefs2.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(sigC2->iref)}, {"ime","ImeICSignal2"}, {"lineno",to_string(sigC2->lineno)}});
					sigC2->ref = dbswdbe->tblwdbecsignal->getNewRef();
					irefs2.insert(sigC2->iref);

					impcnt++;
				};

				num2 = 1;

				for (unsigned int ix2 = 0; ix2 < mdl->imeimsignal2.nodes.size(); ix2++) {
					sig2 = mdl->imeimsignal2.nodes[ix2];

					sig2->ixVBasetype = VecWdbeVMSignalBasetype::getIx(sig2->srefIxVBasetype);
					if (sig2->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",sig2->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(sig2->lineno)}});
					//sig2->refWdbeCSignal: PREVIMP
					if (sig2->irefRefWdbeCSignal != 0) {
						if (irefs2.find(sig2->irefRefWdbeCSignal) == irefs2.end()) {
							sigC2 = new ImeitemICSignal2(sig2->irefRefWdbeCSignal);
							sigC2->ref = dbswdbe->tblwdbecsignal->getNewRef();
							mdl->imeicsignal2.nodes.push_back(sigC2);
							irefs2.insert(sigC2->iref);
						} else {
							for (unsigned int i = 0; i < mdl->imeicsignal2.nodes.size(); i++) {
								sigC2 = mdl->imeicsignal2.nodes[i];
								if (sigC2->iref == sig2->irefRefWdbeCSignal) break;
							};
						};
						sig2->refWdbeCSignal = sigC2->ref;
					};
					sig2->refIxVTbl = VecWdbeVMSignalRefTbl::MDL;
					sig2->refUref = mdl->ref;
					sig2->refNum = num2++;
					sig2->mgeIxVTbl = VecWdbeVMSignalMgeTbl::getIx(sig2->srefMgeIxVTbl);
					if (sig2->mgeIxVTbl == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",sig2->srefMgeIxVTbl}, {"iel","srefMgeIxVTbl"}, {"lineno",to_string(sig2->lineno)}});
					//sig2->mgeUref: CUSTSQLPP
					//sig2->sref: TBL
					//sig2->Const: TBL
					//sig2->srefWdbeKHdltype: TBL
					//sig2->Width: TBL
					//sig2->Minmax: TBL
					//sig2->Comb: TBL
					//sig2->Onval: TBL
					//sig2->Offval: TBL
					//sig2->drvRefWdbeMPort: CUSTSQL
					if (sig2->srefDrvRefWdbeMPort != "") {
						dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = '" + sig2->srefDrvRefWdbeMPort + "'", sig2->drvRefWdbeMPort);
						if (sig2->drvRefWdbeMPort == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",sig2->srefDrvRefWdbeMPort}, {"iel","srefDrvRefWdbeMPort"}, {"lineno",to_string(sig2->lineno)}});
					};
					//sig2->Comment: TBL

					dbswdbe->tblwdbemsignal->insertRec(sig2);
					impcnt++;
				};

				for (unsigned int ix2 = 0; ix2 < mdl->imeimcdc.nodes.size(); ix2++) {
					cdc = mdl->imeimcdc.nodes[ix2];

					cdc->refWdbeMModule = mdl->ref;
					//cdc->fckSrefWdbeMSignal: TBL
					//cdc->farSrefWdbeMSignal: TBL
					//cdc->sckSrefWdbeMSignal: TBL
					//cdc->sarSrefWdbeMSignal: TBL

					dbswdbe->tblwdbemcdc->insertRec(cdc);
					impcnt++;

					for (unsigned int ix3 = 0; ix3 < cdc->imeirmcdcmsignal.nodes.size(); ix3++) {
						cdcRsig = cdc->imeirmcdcmsignal.nodes[ix3];

						cdcRsig->refWdbeMCdc = cdc->ref;
						//cdcRsig->refWdbeMSignal: PREVIMP
						for (unsigned int i = 0; i < mdl->imeimsignal2.nodes.size(); i++)
							if (mdl->imeimsignal2.nodes[i]->sref == cdcRsig->srefRefWdbeMSignal) {
								cdcRsig->refWdbeMSignal = mdl->imeimsignal2.nodes[i]->ref;
								break;
							};
						if (cdcRsig->refWdbeMSignal == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",cdcRsig->srefRefWdbeMSignal}, {"iel","srefRefWdbeMSignal"}, {"lineno",to_string(cdcRsig->lineno)}});
						cdcRsig->ixVDir = VecWdbeVRMCdcMSignalDir::getIx(cdcRsig->srefIxVDir);
						if (cdcRsig->ixVDir == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",cdcRsig->srefIxVDir}, {"iel","srefIxVDir"}, {"lineno",to_string(cdcRsig->lineno)}});

						dbswdbe->tblwdbermcdcmsignal->insertRec(cdcRsig);
						impcnt++;
					};
				};

				for (unsigned int ix2 = 0; ix2 < mdl->imeimprocess.nodes.size(); ix2++) {
					prc = mdl->imeimprocess.nodes[ix2];

					prc->refWdbeMModule = mdl->ref;
					//prc->refWdbeMFsm: SUB
					//prc->sref: TBL
					//prc->clkSrefWdbeMSignal: TBL
					//prc->asrSrefWdbeMSignal: TBL
					//prc->Falling: TBL
					//prc->Syncrst: TBL
					//prc->Extip: TBL
					//prc->Comment: TBL

					dbswdbe->tblwdbemprocess->insertRec(prc);
					impcnt++;

					for (unsigned int ix3 = 0; ix3 < prc->imeimsensitivity2.nodes.size(); ix3++) {
						sns2 = prc->imeimsensitivity2.nodes[ix3];

						sns2->refIxVTbl = VecWdbeVMSensitivityRefTbl::PRC;
						sns2->refUref = prc->ref;
						sns2->srcIxVTbl = VecWdbeVMSensitivitySrcTbl::getIx(sns2->srefSrcIxVTbl);
						if (sns2->srcIxVTbl == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",sns2->srefSrcIxVTbl}, {"iel","srefSrcIxVTbl"}, {"lineno",to_string(sns2->lineno)}});
						//sns2->srcUref: CUSTSQLPP

						dbswdbe->tblwdbemsensitivity->insertRec(sns2);
						impcnt++;
					};

					num3 = 1;

					for (unsigned int ix3 = 0; ix3 < prc->imeiavkeylistkey.nodes.size(); ix3++) {
						klsAkey = prc->imeiavkeylistkey.nodes[ix3];

						klsAkey->klsIxWdbeVKeylist = VecWdbeVKeylist::KLSTWDBEKHDLTYPE;
						klsAkey->klsNum = num3++;
						klsAkey->x1IxWdbeVMaintable = VecWdbeVMaintable::TBLWDBEMPROCESS;
						klsAkey->x1Uref = prc->ref;
						klsAkey->Fixed = true;
						//klsAkey->sref: TBL
						//klsAkey->refJ: SUB
						//klsAkey->Title: TBL
						//klsAkey->Comment: TBL

						dbswdbe->tblwdbeavkeylistkey->insertRec(klsAkey);
						impcnt++;

						if (((klsAkey->Title != "") || (klsAkey->Comment != "")) && klsAkey->imeijavkeylistkey.nodes.empty()) {
							kakJkey = new ImeitemIJAVKeylistKey();
							klsAkey->imeijavkeylistkey.nodes.push_back(kakJkey);

							kakJkey->refWdbeAVKeylistKey = klsAkey->ref;
							kakJkey->Title = klsAkey->Title;
							kakJkey->Comment = klsAkey->Comment;
						};

						for (unsigned int ix4 = 0; ix4 < klsAkey->imeijavkeylistkey.nodes.size(); ix4++) {
							kakJkey = klsAkey->imeijavkeylistkey.nodes[ix4];

							kakJkey->refWdbeAVKeylistKey = klsAkey->ref;
							kakJkey->x1IxWdbeVLocale = VecWdbeVLocale::ENUS;
							//kakJkey->Title: TBL
							//kakJkey->Comment: TBL

							dbswdbe->tblwdbejavkeylistkey->insertRec(kakJkey);
							impcnt++;

							if (ix4 == 0) {
								klsAkey->refJ = kakJkey->ref;
								klsAkey->Title = kakJkey->Title;
								klsAkey->Comment = kakJkey->Comment;
								dbswdbe->tblwdbeavkeylistkey->updateRec(klsAkey);
							};
						};
					};

					irefs3.clear();

					for (unsigned int ix3 = 0; ix3 < prc->imeicvariable2.nodes.size(); ix3++) {
						varC2 = prc->imeicvariable2.nodes[ix3];

						if (irefs3.find(varC2->iref) != irefs3.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(varC2->iref)}, {"ime","ImeICVariable"}, {"lineno",to_string(varC2->lineno)}});
						varC2->ref = dbswdbe->tblwdbecvariable->getNewRef();
						irefs3.insert(varC2->iref);
					};

					num3 = 1;

					for (unsigned int ix3 = 0; ix3 < prc->imeimvariable2.nodes.size(); ix3++) {
						var2 = prc->imeimvariable2.nodes[ix3];

						//var2->refWdbeCVariable: PREVIMP
						if (var2->irefRefWdbeCVariable != 0) {
							if (irefs3.find(var2->irefRefWdbeCVariable) == irefs3.end()) {
								varC2 = new ImeitemICVariable2(var2->irefRefWdbeCVariable);
								varC2->ref = dbswdbe->tblwdbecvariable->getNewRef();
								prc->imeicvariable2.nodes.push_back(varC2);
								irefs3.insert(varC2->iref);
							} else {
								for (unsigned int i = 0; i < prc->imeicvariable2.nodes.size(); i++) {
									varC2 = prc->imeicvariable2.nodes[i];
									if (varC2->iref == var2->irefRefWdbeCVariable) break;
								};
							};
							var2->refWdbeCVariable = varC2->ref;
						};
						var2->refIxVTbl = VecWdbeVMVariableRefTbl::PRC;
						var2->refUref = prc->ref;
						var2->refNum = num3++;
						//var2->sref: TBL
						//var2->Const: TBL
						//var2->Falling: TBL
						//var2->srefWdbeKHdltype: TBL
						//var2->Width: TBL
						//var2->Minmax: TBL
						//var2->Onval: TBL
						//var2->Offval: TBL
						//var2->Comment: TBL

						dbswdbe->tblwdbemvariable->insertRec(var2);
						impcnt++;
					};

					for (unsigned int ix3 = 0; ix3 < prc->imeimfsm.nodes.size(); ix3++) {
						fsm = prc->imeimfsm.nodes[ix3];

						fsm->refWdbeMProcess = prc->ref;
						if (fsm->srefIxVDbgtaptype == "") fsm->srefIxVDbgtaptype = "void";
						fsm->ixVDbgtaptype = VecWdbeVMFsmDbgtaptype::getIx(fsm->srefIxVDbgtaptype);
						if (fsm->ixVDbgtaptype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",fsm->srefIxVDbgtaptype}, {"iel","srefIxVDbgtaptype"}, {"lineno",to_string(fsm->lineno)}});

						dbswdbe->tblwdbemfsm->insertRec(fsm);
						impcnt++;

						if (ix3 == 0) {
							prc->refWdbeMFsm = fsm->ref;
							dbswdbe->tblwdbemprocess->updateRec(prc);
						};

						irefs4.clear();

						for (unsigned int ix4 = 0; ix4 < fsm->imeicfsmstate.nodes.size(); ix4++) {
							fstC = fsm->imeicfsmstate.nodes[ix4];

							if (irefs4.find(fstC->iref) != irefs4.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(fstC->iref)}, {"ime","ImeICFsmstate"}, {"lineno",to_string(fstC->lineno)}});
							fstC->ref = dbswdbe->tblwdbecfsmstate->getNewRef();
							irefs4.insert(fstC->iref);

							impcnt++;
						};

						num4 = 1;

						for (unsigned int ix4 = 0; ix4 < fsm->imeimfsmstate.nodes.size(); ix4++) {
							fst = fsm->imeimfsmstate.nodes[ix4];

							//fst->refWdbeCFsmstate: PREVIMP
							if (fst->irefRefWdbeCFsmstate != 0) {
								if (irefs4.find(fst->irefRefWdbeCFsmstate) == irefs4.end()) {
									fstC = new ImeitemICFsmstate(fst->irefRefWdbeCFsmstate);
									fstC->ref = dbswdbe->tblwdbecfsmstate->getNewRef();
									fsm->imeicfsmstate.nodes.push_back(fstC);
									irefs4.insert(fstC->iref);
								} else {
									for (unsigned int i = 0; i < fsm->imeicfsmstate.nodes.size(); i++) {
										fstC = fsm->imeicfsmstate.nodes[i];
										if (fstC->iref == fst->irefRefWdbeCFsmstate) break;
									};
								};
								fst->refWdbeCFsmstate = fstC->ref;
							};
							fst->fsmRefWdbeMFsm = fsm->ref;
							fst->fsmNum = num4++;
							//fst->sref: TBL
							//fst->Extip: TBL
							//fst->Comment: TBL

							dbswdbe->tblwdbemfsmstate->insertRec(fst);
							impcnt++;

							num5 = 1;

							for (unsigned int ix5 = 0; ix5 < fst->imeiamfsmstatestep.nodes.size(); ix5++) {
								fstAstp = fst->imeiamfsmstatestep.nodes[ix5];

								fstAstp->fstRefWdbeMFsmstate = fst->ref;
								fstAstp->fstNum = num5++;
								//fstAstp->fnxRefWdbeMFsmstate: IMPPP
								//fstAstp->Cond1: TBL
								//fstAstp->Ip1: TBL
								//fstAstp->Cond2: TBL
								//fstAstp->Ip2: TBL
								//fstAstp->Cond3: TBL
								//fstAstp->Ip3: TBL
								//fstAstp->Cond4: TBL
								//fstAstp->Ip4: TBL
								//fstAstp->Cond5: TBL
								//fstAstp->Ip5: TBL
								//fstAstp->Cond5: TBL
								//fstAstp->Ip5: TBL

								dbswdbe->tblwdbeamfsmstatestep->insertRec(fstAstp);
								impcnt++;
							};
						};
					};
				};

				for (unsigned int ix2 = 0; ix2 < mdl->imeimcontroller.nodes.size(); ix2++) {
					ctr = mdl->imeimcontroller.nodes[ix2];

					ctr->ixWdbeVIop = VecWdbeVIop::getIx(ctr->srefIxWdbeVIop);
					if ((ctr->ixWdbeVIop != VecWdbeVIop::RETR) && (ctr->ixWdbeVIop != VecWdbeVIop::RETRUPD)) throw SbeException(SbeException::IEX_IOP, {{"iop",ctr->srefIxWdbeVIop}, {"ime","ImeIMController"}, {"lineno",to_string(ctr->lineno)}});

					// retrieve
					if (dbswdbe->tblwdbemcontroller->loadRecByRef(mdl->refWdbeMController, &ctr_r)) {
						ctr->ref = ctr_r->ref;
						ctr->refWdbeMModule = mdl->ref;
						ctr->Fullsref = ctr_r->Fullsref;
						if (ctr->ixWdbeVIop == VecWdbeVIop::RETR) ctr->clrRefWdbeMSignal = ctr_r->clrRefWdbeMSignal;
						//ctr->clrRefWdbeMSignal: IMPPP

						delete ctr_r;

					} else throw SbeException(SbeException::IEX_RETR, {{"ime","ImeIMController"}, {"lineno",to_string(ctr->lineno)}});

					for (unsigned int ix3 = 0; ix3 < ctr->imeimcommand.nodes.size(); ix3++) {
						cmd = ctr->imeimcommand.nodes[ix3];

						// retrieve (pure retrupd)
						if (cmd->sref != "") dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMCommand WHERE refIxVTbl = " + to_string(VecWdbeVMCommandRefTbl::CTR) + " AND refUref = " + to_string(ctr->ref) + " AND sref = '" + cmd->sref + "'", cmd->ref);
						if (cmd->ref == 0) throw SbeException(SbeException::IEX_RETR, {{"ime","ImeIMCommand"}, {"lineno",to_string(cmd->lineno)}});

						//cmd->ivrRefWdbeMSignal: IMPPP
						//cmd->rvrRefWdbeMSignal: IMPPP
						//cmd->rerRefWdbeMSignal: IMPPP
					};

					for (unsigned int ix3 = 0; ix3 < ctr->imeirmcommandmcontroller.nodes.size(); ix3++) {
						cmdRctr = ctr->imeirmcommandmcontroller.nodes[ix3];

						// retrieve (pure retrupd)
						if (cmdRctr->srefRefWdbeMCommand != "") {
							ptr = cmdRctr->srefRefWdbeMCommand.find('.');
							if (ptr != string::npos)
								if (dbswdbe->loadRefBySQL("SELECT refWdbeMController FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND hkUref = " + to_string(mdl->hkUref) + " AND refWdbeMController <> 0 AND sref = '"
											+ cmdRctr->srefRefWdbeMCommand.substr(0, ptr) + "'", ref))
									if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMCommand WHERE refIxVTbl = " + to_string(VecWdbeVMCommandRefTbl::CTR) + " AND refUref = " + to_string(ref) + " AND sref = '" + cmdRctr->srefRefWdbeMCommand.substr(ptr+1) + "'", cmdRctr->refWdbeMCommand))
												dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeRMCommandMController WHERE refWdbeMCommand = " + to_string(cmdRctr->refWdbeMCommand) + " AND refWdbeMController = " + to_string(ctr->ref), cmdRctr->ref);
						};

						if (cmdRctr->ref == 0) throw SbeException(SbeException::IEX_RETR, {{"ime","ImeIRMCommandMController"}, {"lineno",to_string(cmdRctr->lineno)}});

						//cmdRctr->ivrRefWdbeMSignal: IMPPP
						//cmdRctr->rvrRefWdbeMSignal: IMPPP
					};

					for (unsigned int ix3 = 0; ix3 < ctr->imeimerror.nodes.size(); ix3++) {
						err = ctr->imeimerror.nodes[ix3];

						// retrieve (pure retrupd)
						if (err->sref != "") dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMError WHERE refIxVTbl = " + to_string(VecWdbeVMErrorRefTbl::CTR) + " AND refUref = " + to_string(ctr->ref) + " AND sref = '" + err->sref + "'", err->ref);
						if (err->ref == 0) throw SbeException(SbeException::IEX_RETR, {{"ime","ImeIMError"}, {"lineno",to_string(err->lineno)}});

						//err->traRefWdbeMSignal: IMPPP
					};
				};
			};
		};
		// IP enterSgeImport.traverse --- REND

		// IP enterSgeImport.ppr --- IBEGIN
		for (unsigned int ix0 = 0; ix0 < imeimunit.nodes.size(); ix0++) {
			unt = imeimunit.nodes[ix0];

			if (unt->ref != 0) {
				for (unsigned int ix1 = 0; ix1 < unt->imeimmodule.nodes.size(); ix1++) {
					mdl = unt->imeimmodule.nodes[ix1];

					if (mdl->ref != 0) {
						for (unsigned int ix2 = 0; ix2 < mdl->imeimsensitivity1.nodes.size(); ix2++) {
							sns1 = mdl->imeimsensitivity1.nodes[ix2];

							if (sns1->srcIxVTbl == VecWdbeVMSensitivitySrcTbl::INT) {
								for (unsigned int i = 0; i < unt->imeiminterrupt1.nodes.size(); i++)
									if (unt->imeiminterrupt1.nodes[i]->sref == sns1->srefSrcUref) {
										sns1->srcUref = unt->imeiminterrupt1.nodes[i]->ref;
										break;
									};
							} else if (sns1->srcIxVTbl == VecWdbeVMSensitivitySrcTbl::SIG) {
								dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMSignal WHERE refIxVTbl = " + to_string(VecWdbeVMSignalRefTbl::UNT) + " AND refUref = " + to_string(unt->ref) + " AND sref = '" + sns1->srefSrcUref + "'", sns1->srcUref);
							};

							if (sns1->srcUref == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",sns1->srefSrcUref}, {"iel","srefSrcUref"}, {"lineno",to_string(sns1->lineno)}});
							else dbswdbe->tblwdbemsensitivity->updateRec(sns1);
						};

						for (unsigned int ix2 = 0; ix2 < mdl->imeimcontroller.nodes.size(); ix2++) {
							ctr = mdl->imeimcontroller.nodes[ix2];

							if (ctr->ref != 0) {
								if ((ctr->ixWdbeVIop == VecWdbeVIop::RETRUPD) && (ctr->srefClrRefWdbeMSignal != "")) {
									for (unsigned int i = 0; i < mdl->imeimsignal2.nodes.size(); i++)
										if (mdl->imeimsignal2.nodes[i]->sref == ctr->srefClrRefWdbeMSignal) {
											ctr->clrRefWdbeMSignal = mdl->imeimsignal2.nodes[i]->ref;
											break;
										};

									if (ctr->clrRefWdbeMSignal == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",ctr->srefClrRefWdbeMSignal}, {"iel","srefClrRefWdbeMSignal"}, {"lineno",to_string(ctr->lineno)}});
									else dbswdbe->tblwdbemcontroller->updateRec(ctr);
								};

								for (unsigned int ix3 = 0; ix3 < ctr->imeimcommand.nodes.size(); ix3++) {
									cmd = ctr->imeimcommand.nodes[ix3];

									if ((cmd->srefIvrRefWdbeMSignal != "") || (cmd->srefRvrRefWdbeMSignal != "") || (cmd->srefRerRefWdbeMSignal != "")) {
										if (cmd->srefIvrRefWdbeMSignal != "") {
											for (unsigned int i = 0; i < mdl->imeimsignal2.nodes.size(); i++)
												if (mdl->imeimsignal2.nodes[i]->sref == cmd->srefIvrRefWdbeMSignal) {
													cmd->ivrRefWdbeMSignal = mdl->imeimsignal2.nodes[i]->ref;
													break;
												};

											if (cmd->ivrRefWdbeMSignal == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",cmd->srefIvrRefWdbeMSignal}, {"iel","srefIvrRefWdbeMSignal"}, {"lineno",to_string(cmd->lineno)}});
										};

										if (cmd->srefRvrRefWdbeMSignal != "") {
											for (unsigned int i = 0; i < mdl->imeimsignal2.nodes.size(); i++)
												if (mdl->imeimsignal2.nodes[i]->sref == cmd->srefRvrRefWdbeMSignal) {
													cmd->rvrRefWdbeMSignal = mdl->imeimsignal2.nodes[i]->ref;
													break;
												};

											if (cmd->rvrRefWdbeMSignal == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",cmd->srefRvrRefWdbeMSignal}, {"iel","srefRvrRefWdbeMSignal"}, {"lineno",to_string(cmd->lineno)}});
										};

										if (cmd->srefRerRefWdbeMSignal != "") {
											for (unsigned int i = 0; i < mdl->imeimsignal2.nodes.size(); i++)
												if (mdl->imeimsignal2.nodes[i]->sref == cmd->srefRerRefWdbeMSignal) {
													cmd->rerRefWdbeMSignal = mdl->imeimsignal2.nodes[i]->ref;
													break;
												};

											if (cmd->rerRefWdbeMSignal == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",cmd->srefRerRefWdbeMSignal}, {"iel","srefRerRefWdbeMSignal"}, {"lineno",to_string(cmd->lineno)}});
										};

										dbswdbe->executeQuery("UPDATE TblWdbeMCommand SET ivrRefWdbeMSignal = " + to_string(cmd->ivrRefWdbeMSignal) + ", rvrRefWdbeMSignal = " + to_string(cmd->rvrRefWdbeMSignal) + ", rerRefWdbeMSignal = "
													+ to_string(cmd->rerRefWdbeMSignal) + " WHERE ref = " + to_string(cmd->ref));
									};
								};

								for (unsigned int ix3 = 0; ix3 < ctr->imeirmcommandmcontroller.nodes.size(); ix3++) {
									cmdRctr = ctr->imeirmcommandmcontroller.nodes[ix3];

									if ((cmdRctr->srefIvrRefWdbeMSignal != "") || (cmdRctr->srefRvrRefWdbeMSignal != "")) {
										if (cmdRctr->srefIvrRefWdbeMSignal != "") {
											for (unsigned int i = 0; i < mdl->imeimsignal2.nodes.size(); i++)
												if (mdl->imeimsignal2.nodes[i]->sref == cmdRctr->srefIvrRefWdbeMSignal) {
													cmdRctr->ivrRefWdbeMSignal = mdl->imeimsignal2.nodes[i]->ref;
													break;
												};

											if (cmdRctr->ivrRefWdbeMSignal == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",cmdRctr->srefIvrRefWdbeMSignal}, {"iel","srefIvrRefWdbeMSignal"}, {"lineno",to_string(cmdRctr->lineno)}});
										};

										if (cmdRctr->srefRvrRefWdbeMSignal != "") {
											for (unsigned int i = 0; i < mdl->imeimsignal2.nodes.size(); i++)
												if (mdl->imeimsignal2.nodes[i]->sref == cmdRctr->srefRvrRefWdbeMSignal) {
													cmdRctr->rvrRefWdbeMSignal = mdl->imeimsignal2.nodes[i]->ref;
													break;
												};

											if (cmdRctr->rvrRefWdbeMSignal == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",cmdRctr->srefRvrRefWdbeMSignal}, {"iel","srefRvrRefWdbeMSignal"}, {"lineno",to_string(cmdRctr->lineno)}});
										};

										dbswdbe->executeQuery("UPDATE TblWdbeRMCommandMController SET ivrRefWdbeMSignal = " + to_string(cmdRctr->ivrRefWdbeMSignal) + ", rvrRefWdbeMSignal = " + to_string(cmdRctr->rvrRefWdbeMSignal)
													+ " WHERE ref = " + to_string(cmdRctr->ref));
									};
								};

								for (unsigned int ix3 = 0; ix3 < ctr->imeimerror.nodes.size(); ix3++) {
									err = ctr->imeimerror.nodes[ix3];

									if (err->srefTraRefWdbeMSignal != "") {
										for (unsigned int i = 0; i < mdl->imeimsignal2.nodes.size(); i++)
											if (mdl->imeimsignal2.nodes[i]->sref == err->srefTraRefWdbeMSignal) {
												err->traRefWdbeMSignal = mdl->imeimsignal2.nodes[i]->ref;
												break;
											};

										if (err->traRefWdbeMSignal == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",err->srefTraRefWdbeMSignal}, {"iel","srefTraRefWdbeMSignal"}, {"lineno",to_string(err->lineno)}});
										else dbswdbe->executeQuery("UPDATE TblWdbeMError SET traRefWdbeMSignal = " + to_string(err->traRefWdbeMSignal) + " WHERE ref = " + to_string(err->ref));
									};
								};
							};
						};

						for (unsigned int ix2 = 0; ix2 < mdl->imeimsignal2.nodes.size(); ix2++) {
							sig2 = mdl->imeimsignal2.nodes[ix2];

							if (sig2->srefMgeUref != "") {
								if (sig2->mgeIxVTbl == VecWdbeVMSignalMgeTbl::MDL) {
									dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = '" + sig2->srefMgeUref + "'", sig2->mgeUref);
								} else if (sig2->mgeIxVTbl == VecWdbeVMSignalMgeTbl::PRC) {
									for (unsigned int i = 0; i < mdl->imeimprocess.nodes.size(); i++)
										if (mdl->imeimprocess.nodes[i]->sref == sig2->srefMgeUref) {
											sig2->mgeUref = mdl->imeimprocess.nodes[i]->ref;
											break;
										};
								};

								if (sig2->mgeUref == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",sig2->srefMgeUref}, {"iel","srefMgeUref"}, {"lineno",to_string(sig2->lineno)}});
								else dbswdbe->tblwdbemsignal->updateRec(sig2);
							};
						};

						for (unsigned int ix2 = 0; ix2 < mdl->imeimprocess.nodes.size(); ix2++) {
							prc = mdl->imeimprocess.nodes[ix2];

							for (unsigned int ix3 = 0; ix3 < prc->imeimsensitivity2.nodes.size(); ix3++) {
								sns2 = prc->imeimsensitivity2.nodes[ix3];

								if (sns2->srcIxVTbl == VecWdbeVMSensitivitySrcTbl::PRT) {
									dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = '" + sns2->srefSrcUref + "'", sns2->srcUref);
								} else if (sns2->srcIxVTbl == VecWdbeVMSensitivitySrcTbl::SIG) {
									dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMSignal WHERE refIxVTbl = " + to_string(VecWdbeVMSignalRefTbl::MDL) + " AND refUref = " + to_string(mdl->ref) + " AND sref = '" + sns2->srefSrcUref + "'", sns2->srcUref);
								};

								if (sns2->srcUref == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",sns2->srefSrcUref}, {"iel","srefSrcUref"}, {"lineno",to_string(sns2->lineno)}});
								else dbswdbe->tblwdbemsensitivity->updateRec(sns2);
							};

							for (unsigned int ix3 = 0; ix3 < prc->imeimfsm.nodes.size(); ix3++) {
								fsm = prc->imeimfsm.nodes[ix3];

								for (unsigned int ix4 = 0; ix4 < fsm->imeimfsmstate.nodes.size(); ix4++) {
									fst = fsm->imeimfsmstate.nodes[ix4];

									for (unsigned int ix5 = 0; ix5 < fst->imeiamfsmstatestep.nodes.size(); ix5++) {
										fstAstp = fst->imeiamfsmstatestep.nodes[ix5];

										if (fstAstp->srefFnxRefWdbeMFsmstate != "") {
											for (unsigned int i = 0; i < fsm->imeimfsmstate.nodes.size(); i++)
												if (fsm->imeimfsmstate.nodes[i]->sref == fstAstp->srefFnxRefWdbeMFsmstate) {
													fstAstp->fnxRefWdbeMFsmstate = fsm->imeimfsmstate.nodes[i]->ref;
													break;
												};

											if (fstAstp->fnxRefWdbeMFsmstate == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",fstAstp->srefFnxRefWdbeMFsmstate}, {"iel","srefFnxRefWdbeMFsmstate"}, {"lineno",to_string(fstAstp->lineno)}});
											else dbswdbe->tblwdbeamfsmstatestep->updateRec(fstAstp);
										};
									};
								};
							};
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

void JobWdbeIexFin::leaveSgeImport(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeImport --- INSERT
};

uint JobWdbeIexFin::enterSgeImperr(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IMPERR;

	// IP enterSgeImperr --- INSERT

	return retval;
};

void JobWdbeIexFin::leaveSgeImperr(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeImperr --- INSERT
};

uint JobWdbeIexFin::enterSgeReverse(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::IDLE;
	retval = nextIxVSgeSuccess;

	ImeitemIMUnit* unt = NULL;
	ImeitemIMBank* bnk = NULL;
	ImeitemIMInterrupt1* int1 = NULL;
	ImeitemIMModule* mdl = NULL;
	ImeitemIMSignal1* sig1 = NULL;
	ImeitemIMCdc* cdc = NULL;
	ImeitemIMController* ctr = NULL;
	ImeitemIMGeneric* gen = NULL;
	ImeitemIMPin* pin = NULL;
	ImeitemIMPort* prt = NULL;
	ImeitemIMProcess* prc = NULL;
	ImeitemIMSensitivity1* sns1 = NULL;
	ImeitemIMSignal2* sig2 = NULL;
	ImeitemIMVariable1* var1 = NULL;
	ImeitemIAMPinPar* pinApar = NULL;
	ImeitemIAVKeylistKey* klsAkey = NULL;
	ImeitemIJMPinSref* pinJsrf = NULL;
	ImeitemIMCommand* cmd = NULL;
	ImeitemIMError* err = NULL;
	ImeitemIMFsm* fsm = NULL;
	ImeitemIMSensitivity2* sns2 = NULL;
	ImeitemIMVariable2* var2 = NULL;
	ImeitemIRMCdcMSignal* cdcRsig = NULL;
	ImeitemIRMCommandMController* cmdRctr = NULL;
	ImeitemIJAVKeylistKey* kakJkey = NULL;
	ImeitemIMFsmstate* fst = NULL;
	ImeitemIAMFsmstateStep* fstAstp = NULL;

	// -- ImeIMUnit
	for (unsigned int ix0 = 0; ix0 < imeimunit.nodes.size(); ix0++) {
		unt = imeimunit.nodes[ix0];
		if (unt->ref != 0) dbswdbe->tblwdbemunit->removeRecByRef(unt->ref);

		for (unsigned int ix1 = 0; ix1 < unt->imeimbank.nodes.size(); ix1++) {
			bnk = unt->imeimbank.nodes[ix1];
			if (bnk->ref != 0) dbswdbe->tblwdbembank->removeRecByRef(bnk->ref);

			for (unsigned int ix2 = 0; ix2 < bnk->imeimpin.nodes.size(); ix2++) {
				pin = bnk->imeimpin.nodes[ix2];
				if (pin->ref != 0) dbswdbe->tblwdbempin->removeRecByRef(pin->ref);

				for (unsigned int ix3 = 0; ix3 < pin->imeiampinpar.nodes.size(); ix3++) {
					pinApar = pin->imeiampinpar.nodes[ix3];
					if (pinApar->ref != 0) dbswdbe->tblwdbeampinpar->removeRecByRef(pinApar->ref);
				};

				for (unsigned int ix3 = 0; ix3 < pin->imeijmpinsref.nodes.size(); ix3++) {
					pinJsrf = pin->imeijmpinsref.nodes[ix3];
					if (pinJsrf->ref != 0) dbswdbe->tblwdbejmpinsref->removeRecByRef(pinJsrf->ref);
				};
			};
		};

		for (unsigned int ix1 = 0; ix1 < unt->imeiminterrupt1.nodes.size(); ix1++) {
			int1 = unt->imeiminterrupt1.nodes[ix1];
			if (int1->ref != 0) dbswdbe->tblwdbeminterrupt->removeRecByRef(int1->ref);
		};

		for (unsigned int ix1 = 0; ix1 < unt->imeimmodule.nodes.size(); ix1++) {
			mdl = unt->imeimmodule.nodes[ix1];
			if (mdl->ref != 0) dbswdbe->tblwdbemmodule->removeRecByRef(mdl->ref);

			for (unsigned int ix2 = 0; ix2 < mdl->imeimcdc.nodes.size(); ix2++) {
				cdc = mdl->imeimcdc.nodes[ix2];
				if (cdc->ref != 0) dbswdbe->tblwdbemcdc->removeRecByRef(cdc->ref);

				for (unsigned int ix3 = 0; ix3 < cdc->imeirmcdcmsignal.nodes.size(); ix3++) {
					cdcRsig = cdc->imeirmcdcmsignal.nodes[ix3];
					if (cdcRsig->ref != 0) dbswdbe->tblwdbermcdcmsignal->removeRecByRef(cdcRsig->ref);
				};
			};

			for (unsigned int ix2 = 0; ix2 < mdl->imeimcontroller.nodes.size(); ix2++) {
				ctr = mdl->imeimcontroller.nodes[ix2];
				if (ctr->ref != 0) dbswdbe->tblwdbemcontroller->removeRecByRef(ctr->ref);

				for (unsigned int ix3 = 0; ix3 < ctr->imeimcommand.nodes.size(); ix3++) {
					cmd = ctr->imeimcommand.nodes[ix3];
					if (cmd->ref != 0) dbswdbe->tblwdbemcommand->removeRecByRef(cmd->ref);
				};

				for (unsigned int ix3 = 0; ix3 < ctr->imeimerror.nodes.size(); ix3++) {
					err = ctr->imeimerror.nodes[ix3];
					if (err->ref != 0) dbswdbe->tblwdbemerror->removeRecByRef(err->ref);
				};

				for (unsigned int ix3 = 0; ix3 < ctr->imeirmcommandmcontroller.nodes.size(); ix3++) {
					cmdRctr = ctr->imeirmcommandmcontroller.nodes[ix3];
					if (cmdRctr->ref != 0) dbswdbe->tblwdbermcommandmcontroller->removeRecByRef(cmdRctr->ref);
				};
			};

			for (unsigned int ix2 = 0; ix2 < mdl->imeimgeneric.nodes.size(); ix2++) {
				gen = mdl->imeimgeneric.nodes[ix2];
				if (gen->ref != 0) dbswdbe->tblwdbemgeneric->removeRecByRef(gen->ref);
			};

			for (unsigned int ix2 = 0; ix2 < mdl->imeimport.nodes.size(); ix2++) {
				prt = mdl->imeimport.nodes[ix2];
				if (prt->ref != 0) dbswdbe->tblwdbemport->removeRecByRef(prt->ref);
			};

			for (unsigned int ix2 = 0; ix2 < mdl->imeimprocess.nodes.size(); ix2++) {
				prc = mdl->imeimprocess.nodes[ix2];
				if (prc->ref != 0) dbswdbe->tblwdbemprocess->removeRecByRef(prc->ref);

				for (unsigned int ix3 = 0; ix3 < prc->imeiavkeylistkey.nodes.size(); ix3++) {
					klsAkey = prc->imeiavkeylistkey.nodes[ix3];
					if (klsAkey->ref != 0) dbswdbe->tblwdbeavkeylistkey->removeRecByRef(klsAkey->ref);

					for (unsigned int ix4 = 0; ix4 < klsAkey->imeijavkeylistkey.nodes.size(); ix4++) {
						kakJkey = klsAkey->imeijavkeylistkey.nodes[ix4];
						if (kakJkey->ref != 0) dbswdbe->tblwdbejavkeylistkey->removeRecByRef(kakJkey->ref);
					};
				};

				for (unsigned int ix3 = 0; ix3 < prc->imeimfsm.nodes.size(); ix3++) {
					fsm = prc->imeimfsm.nodes[ix3];
					if (fsm->ref != 0) dbswdbe->tblwdbemfsm->removeRecByRef(fsm->ref);

					for (unsigned int ix4 = 0; ix4 < fsm->imeimfsmstate.nodes.size(); ix4++) {
						fst = fsm->imeimfsmstate.nodes[ix4];
						if (fst->ref != 0) dbswdbe->tblwdbemfsmstate->removeRecByRef(fst->ref);

						for (unsigned int ix5 = 0; ix5 < fst->imeiamfsmstatestep.nodes.size(); ix5++) {
							fstAstp = fst->imeiamfsmstatestep.nodes[ix5];
							if (fstAstp->ref != 0) dbswdbe->tblwdbeamfsmstatestep->removeRecByRef(fstAstp->ref);
						};
					};
				};

				for (unsigned int ix3 = 0; ix3 < prc->imeimsensitivity2.nodes.size(); ix3++) {
					sns2 = prc->imeimsensitivity2.nodes[ix3];
					if (sns2->ref != 0) dbswdbe->tblwdbemsensitivity->removeRecByRef(sns2->ref);
				};

				for (unsigned int ix3 = 0; ix3 < prc->imeimvariable2.nodes.size(); ix3++) {
					var2 = prc->imeimvariable2.nodes[ix3];
					if (var2->ref != 0) dbswdbe->tblwdbemvariable->removeRecByRef(var2->ref);
				};
			};

			for (unsigned int ix2 = 0; ix2 < mdl->imeimsensitivity1.nodes.size(); ix2++) {
				sns1 = mdl->imeimsensitivity1.nodes[ix2];
				if (sns1->ref != 0) dbswdbe->tblwdbemsensitivity->removeRecByRef(sns1->ref);
			};

			for (unsigned int ix2 = 0; ix2 < mdl->imeimsignal2.nodes.size(); ix2++) {
				sig2 = mdl->imeimsignal2.nodes[ix2];
				if (sig2->ref != 0) dbswdbe->tblwdbemsignal->removeRecByRef(sig2->ref);
			};

			for (unsigned int ix2 = 0; ix2 < mdl->imeimvariable1.nodes.size(); ix2++) {
				var1 = mdl->imeimvariable1.nodes[ix2];
				if (var1->ref != 0) dbswdbe->tblwdbemvariable->removeRecByRef(var1->ref);
			};
		};

		for (unsigned int ix1 = 0; ix1 < unt->imeimsignal1.nodes.size(); ix1++) {
			sig1 = unt->imeimsignal1.nodes[ix1];
			if (sig1->ref != 0) dbswdbe->tblwdbemsignal->removeRecByRef(sig1->ref);
		};
	};

	return retval;
};

void JobWdbeIexFin::leaveSgeReverse(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeReverse --- INSERT
};

uint JobWdbeIexFin::enterSgeCollect(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::CLTDONE;
	retval = nextIxVSgeSuccess;

	ImeitemIMUnit* unt = NULL;
	ImeitemICSignal1* sigC1 = NULL;
	ImeitemIMBank* bnk = NULL;
	ImeitemIMInterrupt1* int1 = NULL;
	ImeitemIMModule* mdl = NULL;
	ImeitemIMSignal1* sig1 = NULL;
	ImeitemICGeneric* genC = NULL;
	ImeitemICPin* pinC = NULL;
	ImeitemICPort* prtC = NULL;
	ImeitemICSignal2* sigC2 = NULL;
	ImeitemICVariable1* varC1 = NULL;
	ImeitemIMCdc* cdc = NULL;
	ImeitemIMController* ctr = NULL;
	ImeitemIMGeneric* gen = NULL;
	ImeitemIMPin* pin = NULL;
	ImeitemIMPort* prt = NULL;
	ImeitemIMProcess* prc = NULL;
	ImeitemIMSensitivity1* sns1 = NULL;
	ImeitemIMSignal2* sig2 = NULL;
	ImeitemIMVariable1* var1 = NULL;
	ImeitemIAMPinPar* pinApar = NULL;
	ImeitemIAVKeylistKey* klsAkey = NULL;
	ImeitemICVariable2* varC2 = NULL;
	ImeitemIJMPinSref* pinJsrf = NULL;
	ImeitemIMCommand* cmd = NULL;
	ImeitemIMError* err = NULL;
	ImeitemIMFsm* fsm = NULL;
	ImeitemIMSensitivity2* sns2 = NULL;
	ImeitemIMVariable2* var2 = NULL;
	ImeitemIRMCdcMSignal* cdcRsig = NULL;
	ImeitemIRMCommandMController* cmdRctr = NULL;
	ImeitemICFsmstate* fstC = NULL;
	ImeitemIJAVKeylistKey* kakJkey = NULL;
	ImeitemIMFsmstate* fst = NULL;
	ImeitemIAMFsmstateStep* fstAstp = NULL;

	uint ixWdbeVIop;

	vector<ubigint> refs;

	Stcch* stcch = new Stcch(false);

	// IP enterSgeCollect.traverse --- BEGIN

	// -- ImeIMUnit
	for (unsigned int ix0 = 0; ix0 < imeimunit.nodes.size(); ix0++) {
		unt = imeimunit.nodes[ix0];

		if (unt->ref != 0) {
		};

		for (unsigned int ix1 = 0; ix1 < unt->imeicsignal1.nodes.size(); ix1++) {
			sigC1 = unt->imeicsignal1.nodes[ix1];

			if (sigC1->ref != 0) {
				sigC1->iref = ix1+1;
			};
		};

		if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMBANK, ixWdbeVIop)) {
			dbswdbe->tblwdbembank->loadRefsByUnt(unt->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) unt->imeimbank.nodes.push_back(new ImeitemIMBank(dbswdbe, ixWdbeVIop, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < unt->imeimbank.nodes.size(); ix1++) {
			bnk = unt->imeimbank.nodes[ix1];

			if (bnk->ref != 0) {
				//bnk->srefIxWdbeVIop: IOP
			};

			for (unsigned int ix2 = 0; ix2 < bnk->imeicpin.nodes.size(); ix2++) {
				pinC = bnk->imeicpin.nodes[ix2];

				if (pinC->ref != 0) {
					pinC->iref = ix2+1;
				};
			};

			if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMPIN, ixWdbeVIop)) {
				dbswdbe->tblwdbempin->loadRefsByBnk(bnk->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) bnk->imeimpin.nodes.push_back(new ImeitemIMPin(dbswdbe, ixWdbeVIop, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < bnk->imeimpin.nodes.size(); ix2++) {
				pin = bnk->imeimpin.nodes[ix2];

				if (pin->ref != 0) {
					//pin->srefIxWdbeVIop: IOP
					//pin->irefRefWdbeCPin: IREF
				};

				if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIAMPINPAR, ixWdbeVIop)) {
					dbswdbe->tblwdbeampinpar->loadRefsByPin(pin->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) pin->imeiampinpar.nodes.push_back(new ImeitemIAMPinPar(dbswdbe, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < pin->imeiampinpar.nodes.size(); ix3++) {
					pinApar = pin->imeiampinpar.nodes[ix3];

					if (pinApar->ref != 0) {
					};
				};

				if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIJMPINSREF, ixWdbeVIop)) {
					dbswdbe->tblwdbejmpinsref->loadRefsByPin(pin->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == pin->refJSref) {refs[i] = refs[0]; refs[0] = pin->refJSref; break;};
					for (unsigned int i = 0; i < refs.size(); i++) pin->imeijmpinsref.nodes.push_back(new ImeitemIJMPinSref(dbswdbe, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < pin->imeijmpinsref.nodes.size(); ix3++) {
					pinJsrf = pin->imeijmpinsref.nodes[ix3];

					if (pinJsrf->ref != 0) {
						pinJsrf->srefX1RefWdbeMPeripheral = StubWdbe::getStubPphStd(dbswdbe, pinJsrf->x1RefWdbeMPeripheral, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
					};
				};
			};
		};

		if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMINTERRUPT1, ixWdbeVIop)) {
			dbswdbe->tblwdbeminterrupt->loadRefsByUnt(unt->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) unt->imeiminterrupt1.nodes.push_back(new ImeitemIMInterrupt1(dbswdbe, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < unt->imeiminterrupt1.nodes.size(); ix1++) {
			int1 = unt->imeiminterrupt1.nodes[ix1];

			if (int1->ref != 0) {
			};
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

			for (unsigned int ix2 = 0; ix2 < mdl->imeicgeneric.nodes.size(); ix2++) {
				genC = mdl->imeicgeneric.nodes[ix2];

				if (genC->ref != 0) {
					genC->iref = ix2+1;
				};
			};

			for (unsigned int ix2 = 0; ix2 < mdl->imeicport.nodes.size(); ix2++) {
				prtC = mdl->imeicport.nodes[ix2];

				if (prtC->ref != 0) {
					prtC->iref = ix2+1;
				};
			};

			for (unsigned int ix2 = 0; ix2 < mdl->imeicsignal2.nodes.size(); ix2++) {
				sigC2 = mdl->imeicsignal2.nodes[ix2];

				if (sigC2->ref != 0) {
					sigC2->iref = ix2+1;
				};
			};

			for (unsigned int ix2 = 0; ix2 < mdl->imeicvariable1.nodes.size(); ix2++) {
				varC1 = mdl->imeicvariable1.nodes[ix2];

				if (varC1->ref != 0) {
					varC1->iref = ix2+1;
				};
			};

			if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMCDC, ixWdbeVIop)) {
				dbswdbe->tblwdbemcdc->loadRefsByMdl(mdl->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) mdl->imeimcdc.nodes.push_back(new ImeitemIMCdc(dbswdbe, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < mdl->imeimcdc.nodes.size(); ix2++) {
				cdc = mdl->imeimcdc.nodes[ix2];

				if (cdc->ref != 0) {
				};

				if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIRMCDCMSIGNAL, ixWdbeVIop)) {
					dbswdbe->tblwdbermcdcmsignal->loadRefsByCdc(cdc->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) cdc->imeirmcdcmsignal.nodes.push_back(new ImeitemIRMCdcMSignal(dbswdbe, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < cdc->imeirmcdcmsignal.nodes.size(); ix3++) {
					cdcRsig = cdc->imeirmcdcmsignal.nodes[ix3];

					if (cdcRsig->ref != 0) {
						cdcRsig->srefRefWdbeMSignal = StubWdbe::getStubSigSref(dbswdbe, cdcRsig->refWdbeMSignal, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
					};
				};
			};

			if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMCONTROLLER, ixWdbeVIop)) {
				dbswdbe->tblwdbemcontroller->loadRefsByMdl(mdl->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) mdl->imeimcontroller.nodes.push_back(new ImeitemIMController(dbswdbe, ixWdbeVIop, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < mdl->imeimcontroller.nodes.size(); ix2++) {
				ctr = mdl->imeimcontroller.nodes[ix2];

				if (ctr->ref != 0) {
					//ctr->srefIxWdbeVIop: IOP
					ctr->srefClrRefWdbeMSignal = StubWdbe::getStubSigSref(dbswdbe, ctr->clrRefWdbeMSignal, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
				};

				if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMCOMMAND, ixWdbeVIop)) {
					dbswdbe->tblwdbemcommand->loadRefsByRetReu(VecWdbeVMCommandRefTbl::CTR, ctr->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) ctr->imeimcommand.nodes.push_back(new ImeitemIMCommand(dbswdbe, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < ctr->imeimcommand.nodes.size(); ix3++) {
					cmd = ctr->imeimcommand.nodes[ix3];

					if (cmd->ref != 0) {
						cmd->srefIvrRefWdbeMSignal = StubWdbe::getStubSigSref(dbswdbe, cmd->ivrRefWdbeMSignal, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
						cmd->srefRvrRefWdbeMSignal = StubWdbe::getStubSigSref(dbswdbe, cmd->rvrRefWdbeMSignal, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
						cmd->srefRerRefWdbeMSignal = StubWdbe::getStubSigSref(dbswdbe, cmd->rerRefWdbeMSignal, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
					};
				};

				if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMERROR, ixWdbeVIop)) {
					dbswdbe->tblwdbemerror->loadRefsByRetReu(VecWdbeVMErrorRefTbl::CTR, ctr->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) ctr->imeimerror.nodes.push_back(new ImeitemIMError(dbswdbe, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < ctr->imeimerror.nodes.size(); ix3++) {
					err = ctr->imeimerror.nodes[ix3];

					if (err->ref != 0) {
						err->srefTraRefWdbeMSignal = StubWdbe::getStubSigSref(dbswdbe, err->traRefWdbeMSignal, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
					};
				};

				if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIRMCOMMANDMCONTROLLER, ixWdbeVIop)) {
					dbswdbe->tblwdbermcommandmcontroller->loadRefsByCtr(ctr->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) ctr->imeirmcommandmcontroller.nodes.push_back(new ImeitemIRMCommandMController(dbswdbe, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < ctr->imeirmcommandmcontroller.nodes.size(); ix3++) {
					cmdRctr = ctr->imeirmcommandmcontroller.nodes[ix3];

					if (cmdRctr->ref != 0) {
						cmdRctr->srefRefWdbeMCommand = StubWdbe::getStubCmdStd(dbswdbe, cmdRctr->refWdbeMCommand, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
						cmdRctr->srefIvrRefWdbeMSignal = StubWdbe::getStubSigSref(dbswdbe, cmdRctr->ivrRefWdbeMSignal, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
						cmdRctr->srefRvrRefWdbeMSignal = StubWdbe::getStubSigSref(dbswdbe, cmdRctr->rvrRefWdbeMSignal, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
					};
				};
			};

			if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMGENERIC, ixWdbeVIop)) {
				dbswdbe->tblwdbemgeneric->loadRefsByMdl(mdl->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) mdl->imeimgeneric.nodes.push_back(new ImeitemIMGeneric(dbswdbe, ixWdbeVIop, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < mdl->imeimgeneric.nodes.size(); ix2++) {
				gen = mdl->imeimgeneric.nodes[ix2];

				if (gen->ref != 0) {
					//gen->srefIxWdbeVIop: IOP
					//gen->irefRefWdbeCGeneric: IREF
				};
			};

			if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMPORT, ixWdbeVIop)) {
				dbswdbe->tblwdbemport->loadRefsByMdl(mdl->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) mdl->imeimport.nodes.push_back(new ImeitemIMPort(dbswdbe, ixWdbeVIop, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < mdl->imeimport.nodes.size(); ix2++) {
				prt = mdl->imeimport.nodes[ix2];

				if (prt->ref != 0) {
					//prt->srefIxWdbeVIop: IOP
					//prt->irefRefWdbeCPort: IREF
				};
			};

			if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMPROCESS, ixWdbeVIop)) {
				dbswdbe->tblwdbemprocess->loadRefsByMdl(mdl->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) mdl->imeimprocess.nodes.push_back(new ImeitemIMProcess(dbswdbe, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < mdl->imeimprocess.nodes.size(); ix2++) {
				prc = mdl->imeimprocess.nodes[ix2];

				if (prc->ref != 0) {
				};

				if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIAVKEYLISTKEY, ixWdbeVIop)) {
					dbswdbe->tblwdbeavkeylistkey->loadRefsByMtbUrf(VecWdbeVMaintable::TBLWDBEMPROCESS, prc->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) prc->imeiavkeylistkey.nodes.push_back(new ImeitemIAVKeylistKey(dbswdbe, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < prc->imeiavkeylistkey.nodes.size(); ix3++) {
					klsAkey = prc->imeiavkeylistkey.nodes[ix3];

					if (klsAkey->ref != 0) {
					};

					if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIJAVKEYLISTKEY, ixWdbeVIop)) {
						dbswdbe->tblwdbejavkeylistkey->loadRefsByKlk(klsAkey->ref, false, refs);
						for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == klsAkey->refJ) {refs[i] = refs[0]; refs[0] = klsAkey->refJ; break;};
						for (unsigned int i = 0; i < refs.size(); i++) klsAkey->imeijavkeylistkey.nodes.push_back(new ImeitemIJAVKeylistKey(dbswdbe, refs[i]));
					};

					for (unsigned int ix4 = 0; ix4 < klsAkey->imeijavkeylistkey.nodes.size(); ix4++) {
						kakJkey = klsAkey->imeijavkeylistkey.nodes[ix4];

						if (kakJkey->ref != 0) {
						};
					};
				};

				for (unsigned int ix3 = 0; ix3 < prc->imeicvariable2.nodes.size(); ix3++) {
					varC2 = prc->imeicvariable2.nodes[ix3];

					if (varC2->ref != 0) {
						varC2->iref = ix3+1;
					};
				};

				if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMFSM, ixWdbeVIop)) {
					dbswdbe->tblwdbemfsm->loadRefsByPrc(prc->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) prc->imeimfsm.nodes.push_back(new ImeitemIMFsm(dbswdbe, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < prc->imeimfsm.nodes.size(); ix3++) {
					fsm = prc->imeimfsm.nodes[ix3];

					if (fsm->ref != 0) {
					};

					for (unsigned int ix4 = 0; ix4 < fsm->imeicfsmstate.nodes.size(); ix4++) {
						fstC = fsm->imeicfsmstate.nodes[ix4];

						if (fstC->ref != 0) {
							fstC->iref = ix4+1;
						};
					};

					if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMFSMSTATE, ixWdbeVIop)) {
						dbswdbe->tblwdbemfsmstate->loadRefsByFsm(fsm->ref, false, refs);
						for (unsigned int i = 0; i < refs.size(); i++) fsm->imeimfsmstate.nodes.push_back(new ImeitemIMFsmstate(dbswdbe, refs[i]));
					};

					for (unsigned int ix4 = 0; ix4 < fsm->imeimfsmstate.nodes.size(); ix4++) {
						fst = fsm->imeimfsmstate.nodes[ix4];

						if (fst->ref != 0) {
							//fst->irefRefWdbeCFsmstate: IREF
						};

						if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIAMFSMSTATESTEP, ixWdbeVIop)) {
							dbswdbe->tblwdbeamfsmstatestep->loadRefsByFst(fst->ref, false, refs);
							for (unsigned int i = 0; i < refs.size(); i++) fst->imeiamfsmstatestep.nodes.push_back(new ImeitemIAMFsmstateStep(dbswdbe, refs[i]));
						};

						for (unsigned int ix5 = 0; ix5 < fst->imeiamfsmstatestep.nodes.size(); ix5++) {
							fstAstp = fst->imeiamfsmstatestep.nodes[ix5];

							if (fstAstp->ref != 0) {
								fstAstp->srefFnxRefWdbeMFsmstate = StubWdbe::getStubFstStd(dbswdbe, fstAstp->fnxRefWdbeMFsmstate, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
							};
						};
					};
				};

				if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMSENSITIVITY2, ixWdbeVIop)) {
					dbswdbe->tblwdbemsensitivity->loadRefsByRetReu(VecWdbeVMSensitivityRefTbl::PRC, prc->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) prc->imeimsensitivity2.nodes.push_back(new ImeitemIMSensitivity2(dbswdbe, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < prc->imeimsensitivity2.nodes.size(); ix3++) {
					sns2 = prc->imeimsensitivity2.nodes[ix3];

					if (sns2->ref != 0) {
						//sns2->srefSrcUref: STUB
					};
				};

				if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMVARIABLE2, ixWdbeVIop)) {
					dbswdbe->tblwdbemvariable->loadRefsByRetReu(VecWdbeVMVariableRefTbl::PRC, prc->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) prc->imeimvariable2.nodes.push_back(new ImeitemIMVariable2(dbswdbe, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < prc->imeimvariable2.nodes.size(); ix3++) {
					var2 = prc->imeimvariable2.nodes[ix3];

					if (var2->ref != 0) {
						//var2->irefRefWdbeCVariable: IREF
					};
				};
			};

			if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMSENSITIVITY1, ixWdbeVIop)) {
				dbswdbe->tblwdbemsensitivity->loadRefsByRetReu(VecWdbeVMSensitivityRefTbl::MDL, mdl->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) mdl->imeimsensitivity1.nodes.push_back(new ImeitemIMSensitivity1(dbswdbe, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < mdl->imeimsensitivity1.nodes.size(); ix2++) {
				sns1 = mdl->imeimsensitivity1.nodes[ix2];

				if (sns1->ref != 0) {
					//sns1->srefSrcUref: STUB
				};
			};

			if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMSIGNAL2, ixWdbeVIop)) {
				dbswdbe->tblwdbemsignal->loadRefsByRetReu(VecWdbeVMSignalRefTbl::MDL, mdl->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) mdl->imeimsignal2.nodes.push_back(new ImeitemIMSignal2(dbswdbe, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < mdl->imeimsignal2.nodes.size(); ix2++) {
				sig2 = mdl->imeimsignal2.nodes[ix2];

				if (sig2->ref != 0) {
					//sig2->irefRefWdbeCSignal: IREF
					//sig2->srefMgeUref: STUB
					sig2->srefDrvRefWdbeMPort = StubWdbe::getStubPrtSref(dbswdbe, sig2->drvRefWdbeMPort, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
				};
			};

			if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMVARIABLE1, ixWdbeVIop)) {
				dbswdbe->tblwdbemvariable->loadRefsByRetReu(VecWdbeVMVariableRefTbl::MDL, mdl->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) mdl->imeimvariable1.nodes.push_back(new ImeitemIMVariable1(dbswdbe, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < mdl->imeimvariable1.nodes.size(); ix2++) {
				var1 = mdl->imeimvariable1.nodes[ix2];

				if (var1->ref != 0) {
					//var1->irefRefWdbeCVariable: IREF
				};
			};
		};

		if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMSIGNAL1, ixWdbeVIop)) {
			dbswdbe->tblwdbemsignal->loadRefsByRetReu(VecWdbeVMSignalRefTbl::UNT, unt->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) unt->imeimsignal1.nodes.push_back(new ImeitemIMSignal1(dbswdbe, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < unt->imeimsignal1.nodes.size(); ix1++) {
			sig1 = unt->imeimsignal1.nodes[ix1];

			if (sig1->ref != 0) {
				//sig1->irefRefWdbeCSignal: IREF
				//sig1->srefMgeUref: STUB
			};
		};
	};
	// IP enterSgeCollect.traverse --- END
	// IP enterSgeCollect.ppr --- INSERT

	delete stcch;

	return retval;
};

void JobWdbeIexFin::leaveSgeCollect(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeCollect --- INSERT
};

uint JobWdbeIexFin::enterSgeCltdone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::CLTDONE;

	// IP enterSgeCltdone --- INSERT

	return retval;
};

void JobWdbeIexFin::leaveSgeCltdone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeCltdone --- INSERT
};

uint JobWdbeIexFin::enterSgeExport(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	IexWdbeFin::exportToFile(fullpath, xmlNotTxt, shorttags, imeimunit);

	return retval;
};

void JobWdbeIexFin::leaveSgeExport(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeExport --- INSERT
};

uint JobWdbeIexFin::enterSgeDone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void JobWdbeIexFin::leaveSgeDone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeDone --- INSERT
};
