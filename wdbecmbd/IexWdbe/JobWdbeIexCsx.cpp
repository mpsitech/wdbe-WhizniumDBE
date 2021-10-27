/**
	* \file JobWdbeIexCsx.cpp
	* job handler for job JobWdbeIexCsx (implementation)
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

#include "JobWdbeIexCsx.h"

#include "JobWdbeIexCsx_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

using namespace IexWdbeCsx;

/******************************************************************************
 class JobWdbeIexCsx
 ******************************************************************************/

JobWdbeIexCsx::JobWdbeIexCsx(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::JOBWDBEIEXCSX, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	changeStage(dbswdbe, VecVSge::IDLE);

	// IP constructor.cust3 --- INSERT

};

JobWdbeIexCsx::~JobWdbeIexCsx() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void JobWdbeIexCsx::reset(
			DbsWdbe* dbswdbe
		) {
	if (ixVSge != VecVSge::IDLE) changeStage(dbswdbe, VecVSge::IDLE);
};

void JobWdbeIexCsx::parseFromFile(
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

void JobWdbeIexCsx::import(
			DbsWdbe* dbswdbe
		) {
	if (ixVSge == VecVSge::PRSDONE) changeStage(dbswdbe, VecVSge::IMPORT);
};

void JobWdbeIexCsx::reverse(
			DbsWdbe* dbswdbe
		) {
	if (ixVSge == VecVSge::IMPERR) changeStage(dbswdbe, VecVSge::REVERSE);
};

void JobWdbeIexCsx::collect(
			DbsWdbe* dbswdbe
			, const map<uint,uint>& _icsWdbeVIop
		) {
	if (ixVSge == VecVSge::IDLE) {
		icsWdbeVIop = _icsWdbeVIop;
		changeStage(dbswdbe, VecVSge::COLLECT);
	};
};

void JobWdbeIexCsx::exportToFile(
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

void JobWdbeIexCsx::handleRequest(
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

void JobWdbeIexCsx::changeStage(
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

string JobWdbeIexCsx::getSquawk(
			DbsWdbe* dbswdbe
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::PARSE) || (ixVSge == VecVSge::PRSDONE) || (ixVSge == VecVSge::IMPORT) || (ixVSge == VecVSge::REVERSE) || (ixVSge == VecVSge::COLLECT) || (ixVSge == VecVSge::CLTDONE) || (ixVSge == VecVSge::EXPORT) ) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing command set and buffer transfers";
			else if (ixVSge == VecVSge::PRSDONE) retval = "command set and buffer transfers parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing command set and buffer transfers (" + to_string(impcnt) + " records added)";
			else if (ixVSge == VecVSge::REVERSE) retval = "reversing command set and buffer transfers import";
			else if (ixVSge == VecVSge::COLLECT) retval = "collecting command set and buffer transfers for export";
			else if (ixVSge == VecVSge::CLTDONE) retval = "command set and buffer transfers collected for export";
			else if (ixVSge == VecVSge::EXPORT) retval = "exporting command set and buffer transfers";
		};

	} else if ( (ixVSge == VecVSge::PRSERR) || (ixVSge == VecVSge::IMPERR) ) {
		retval = lasterror;

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

uint JobWdbeIexCsx::enterSgeIdle(
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

void JobWdbeIexCsx::leaveSgeIdle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWdbeIexCsx::enterSgeParse(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::PRSDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::PRSERR;

	try {
		IexWdbeCsx::parseFromFile(fullpath, xmlNotTxt, rectpath, imeimunit);

	} catch (SbeException& e) {
		if (e.ix == SbeException::PATHNF) e.vals["path"] = "<hidden>";
		lasterror = e.getSquawk(VecWdbeVError::getIx, VecWdbeVError::getTitle, ixWdbeVLocale);

		retval = nextIxVSgeFailure;
	};

	return retval;
};

void JobWdbeIexCsx::leaveSgeParse(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeParse --- INSERT
};

uint JobWdbeIexCsx::enterSgePrserr(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::PRSERR;

	// IP enterSgePrserr --- INSERT

	return retval;
};

void JobWdbeIexCsx::leaveSgePrserr(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgePrserr --- INSERT
};

uint JobWdbeIexCsx::enterSgePrsdone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::PRSDONE;

	// IP enterSgePrsdone --- INSERT

	return retval;
};

void JobWdbeIexCsx::leaveSgePrsdone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgePrsdone --- INSERT
};

uint JobWdbeIexCsx::enterSgeImport(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IMPERR;

	ImeitemIMUnit* unt = NULL;
	ImeitemIMCommand1* cmd1 = NULL;
	ImeitemIMError1* err1 = NULL;
	ImeitemIMModule* mdl = NULL;
	ImeitemIMVector1* vec1 = NULL;
	ImeitemIAMCommandInvpar1* cmdAipa1 = NULL;
	ImeitemIAMCommandRetpar1* cmdArpa1 = NULL;
	ImeitemIAMErrorPar1* errApar1 = NULL;
	ImeitemIMController* ctr = NULL;
	ImeitemIMVectoritem1* vit1 = NULL;
	ImeitemIMCommand2* cmd2 = NULL;
	ImeitemIMError2* err2 = NULL;
	ImeitemIMVector2* vec2 = NULL;
	ImeitemIRMCommandMController* cmdRctr = NULL;
	ImeitemIAMCommandInvpar2* cmdAipa2 = NULL;
	ImeitemIAMCommandRetpar2* cmdArpa2 = NULL;
	ImeitemIAMErrorPar2* errApar2 = NULL;
	ImeitemIMVectoritem2* vit2 = NULL;

	uint num2, num4;

	// IP enterSgeImport.prep --- IBEGIN
	ubigint refWdbeMVersion;
	refWdbeMVersion = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref);

	ubigint ref;

	WdbeMUnit* unt_r = NULL;

	ListWdbeMModule mdl_rs;
	WdbeMModule* mdl_r = NULL;

	WdbeMController* ctr_r = NULL;

	uint refNum;

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

			for (unsigned int ix1 = 0; ix1 < unt->imeimvector1.nodes.size(); ix1++) {
				vec1 = unt->imeimvector1.nodes[ix1];

				vec1->ixVBasetype = VecWdbeVMVectorBasetype::getIx(vec1->srefIxVBasetype);
				if (vec1->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",vec1->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(vec1->lineno)}});
				vec1->hkIxVTbl = VecWdbeVMVectorHkTbl::UNT;
				vec1->hkUref = unt->ref;
				//vec1->sref: TBL
				//vec1->srefsKOption: TBL

				dbswdbe->tblwdbemvector->insertRec(vec1);
				impcnt++;

				if (vec1->ixVBasetype == VecWdbeVMVectorBasetype::TIXLIN) num2 = 0;
				else num2 = 1;

				for (unsigned int ix2 = 0; ix2 < vec1->imeimvectoritem1.nodes.size(); ix2++) {
					vit1 = vec1->imeimvectoritem1.nodes[ix2];

					vit1->vecRefWdbeMVector = vec1->ref;
					vit1->vecNum = num2;
					if (vec1->ixVBasetype == VecWdbeVMVectorBasetype::TIXOR) num2 *= 2;
					else num2++;
					//vit1->sref: TBL
					//vit1->Title: TBL
					//vit1->Comment: TBL

					dbswdbe->tblwdbemvectoritem->insertRec(vit1);
					impcnt++;
				};
			};

			refNum = 0;

			for (unsigned int ix1 = 0; ix1 < unt->imeimcommand1.nodes.size(); ix1++) {
				cmd1 = unt->imeimcommand1.nodes[ix1];

				cmd1->refIxVTbl = VecWdbeVMCommandRefTbl::UNT;
				cmd1->refUref = unt->ref;
				//cmd1->refNum: TBL
				if (cmd1->refNum < refNum) cmd1->refNum = refNum;
				refNum = cmd1->refNum + 1;
				//cmd1->sref: TBL
				//cmd1->Fullsref: CUST
				cmd1->Fullsref = "Cmd" + unt->Fullsref.substr(3) + StrMod::cap(cmd1->sref);
				cmd1->ixVRettype = VecWdbeVMCommandRettype::getIx(cmd1->srefIxVRettype);
				if (cmd1->ixVRettype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",cmd1->srefIxVRettype}, {"iel","srefIxVRettype"}, {"lineno",to_string(cmd1->lineno)}});
				//cmd1->Comment: TBL

				dbswdbe->tblwdbemcommand->insertRec(cmd1);
				impcnt++;

				num2 = 1;

				for (unsigned int ix2 = 0; ix2 < cmd1->imeiamcommandinvpar1.nodes.size(); ix2++) {
					cmdAipa1 = cmd1->imeiamcommandinvpar1.nodes[ix2];

					cmdAipa1->cmdRefWdbeMCommand = cmd1->ref;
					cmdAipa1->cmdNum = num2++;
					//cmdAipa1->sref: TBL
					cmdAipa1->ixWdbeVPartype = VecWdbeVPartype::getIx(cmdAipa1->srefIxWdbeVPartype);
					if (cmdAipa1->ixWdbeVPartype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",cmdAipa1->srefIxWdbeVPartype}, {"iel","srefIxWdbeVPartype"}, {"lineno",to_string(cmdAipa1->lineno)}});
					//cmdAipa1->refWdbeMVector: PREVIMP
					if (cmdAipa1->srefRefWdbeMVector != "") {
						for (unsigned int i = 0; i < unt->imeimvector1.nodes.size(); i++)
							if (unt->imeimvector1.nodes[i]->sref == cmdAipa1->srefRefWdbeMVector) {
								cmdAipa1->refWdbeMVector = unt->imeimvector1.nodes[i]->ref;
								break;
							};
						if (cmdAipa1->refWdbeMVector == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",cmdAipa1->srefRefWdbeMVector}, {"iel","srefRefWdbeMVector"}, {"lineno",to_string(cmdAipa1->lineno)}});
					};
					//cmdAipa1->Length: TBL
					//cmdAipa1->Defval: TBL
					//cmdAipa1->refWdbeMVectoritem: CUSTSQL
					if ((cmdAipa1->refWdbeMVector != 0) && (cmdAipa1->srefRefWdbeMVectoritem != "")) {
						dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMVectoritem WHERE vecRefWdbeMVector = " + to_string(cmdAipa1->refWdbeMVector) + " AND sref = '" + cmdAipa1->srefRefWdbeMVectoritem + "'", cmdAipa1->refWdbeMVectoritem);
						if (cmdAipa1->refWdbeMVectoritem == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",cmdAipa1->srefRefWdbeMVectoritem}, {"iel","srefRefWdbeMVectoritem"}, {"lineno",to_string(cmdAipa1->lineno)}});
					};
					//cmdAipa1->Comment: TBL

					dbswdbe->tblwdbeamcommandinvpar->insertRec(cmdAipa1);
					impcnt++;
				};

				num2 = 1;

				for (unsigned int ix2 = 0; ix2 < cmd1->imeiamcommandretpar1.nodes.size(); ix2++) {
					cmdArpa1 = cmd1->imeiamcommandretpar1.nodes[ix2];

					cmdArpa1->cmdRefWdbeMCommand = cmd1->ref;
					cmdArpa1->cmdNum = num2++;
					//cmdArpa1->sref: TBL
					cmdArpa1->ixWdbeVPartype = VecWdbeVPartype::getIx(cmdArpa1->srefIxWdbeVPartype);
					if (cmdArpa1->ixWdbeVPartype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",cmdArpa1->srefIxWdbeVPartype}, {"iel","srefIxWdbeVPartype"}, {"lineno",to_string(cmdArpa1->lineno)}});
					//cmdArpa1->refWdbeMVector: PREVIMP
					if (cmdArpa1->srefRefWdbeMVector != "") {
						for (unsigned int i = 0; i < unt->imeimvector1.nodes.size(); i++)
							if (unt->imeimvector1.nodes[i]->sref == cmdArpa1->srefRefWdbeMVector) {
								cmdArpa1->refWdbeMVector = unt->imeimvector1.nodes[i]->ref;
								break;
							};
						if (cmdArpa1->refWdbeMVector == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",cmdArpa1->srefRefWdbeMVector}, {"iel","srefRefWdbeMVector"}, {"lineno",to_string(cmdArpa1->lineno)}});
					};
					//cmdArpa1->Length: TBL
					//cmdArpa1->Comment: TBL

					dbswdbe->tblwdbeamcommandretpar->insertRec(cmdArpa1);
					impcnt++;
				};
			};

			for (unsigned int ix1 = 0; ix1 < unt->imeimerror1.nodes.size(); ix1++) {
				err1 = unt->imeimerror1.nodes[ix1];

				err1->refIxVTbl = VecWdbeVMErrorRefTbl::UNT;
				err1->refUref = unt->ref;
				//err1->refNum: TBL
				if (err1->refNum < refNum) err1->refNum = refNum;
				refNum = err1->refNum + 1;
				//err1->sref: TBL
				//err1->Fullsref: CUST
				err1->Fullsref = "Err" + unt->Fullsref.substr(3) + StrMod::cap(err1->sref);
				//err1->Comment: TBL

				dbswdbe->tblwdbemerror->insertRec(err1);
				impcnt++;

				num2 = 1;

				for (unsigned int ix2 = 0; ix2 < err1->imeiamerrorpar1.nodes.size(); ix2++) {
					errApar1 = err1->imeiamerrorpar1.nodes[ix2];

					errApar1->errRefWdbeMError = err1->ref;
					errApar1->errNum = num2++;
					//errApar1->sref: TBL
					errApar1->ixWdbeVPartype = VecWdbeVPartype::getIx(errApar1->srefIxWdbeVPartype);
					if (errApar1->ixWdbeVPartype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",errApar1->srefIxWdbeVPartype}, {"iel","srefIxWdbeVPartype"}, {"lineno",to_string(errApar1->lineno)}});
					//errApar1->refWdbeMVector: PREVIMP
					if (errApar1->srefRefWdbeMVector != "") {
						for (unsigned int i = 0; i < unt->imeimvector1.nodes.size(); i++)
							if (unt->imeimvector1.nodes[i]->sref == errApar1->srefRefWdbeMVector) {
								errApar1->refWdbeMVector = unt->imeimvector1.nodes[i]->ref;
								break;
							};
						if (errApar1->refWdbeMVector == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",errApar1->srefRefWdbeMVector}, {"iel","srefRefWdbeMVector"}, {"lineno",to_string(errApar1->lineno)}});
					};
					//errApar1->Length: TBL
					//errApar1->Comment: TBL

					dbswdbe->tblwdbeamerrorpar->insertRec(errApar1);
					impcnt++;
				};
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

				for (unsigned int ix2 = 0; ix2 < mdl->imeimcontroller.nodes.size(); ix2++) {
					ctr = mdl->imeimcontroller.nodes[ix2];

					// retrieve
					if (dbswdbe->tblwdbemcontroller->loadRecByRef(mdl->refWdbeMController, &ctr_r)) {
						ctr->ref = ctr_r->ref;
						ctr->refWdbeMModule = ctr_r->refWdbeMModule;
						ctr->fwdRefWdbeMUnit = ctr_r->fwdRefWdbeMUnit;
						ctr->Fullsref = ctr_r->Fullsref;
						ctr->clrRefWdbeMSignal = ctr_r->clrRefWdbeMSignal;

						delete ctr_r;
					} else throw SbeException(SbeException::IEX_RETR, {{"ime","ImeIMController"}, {"lineno",to_string(ctr->lineno)}});

					for (unsigned int ix3 = 0; ix3 < ctr->imeimvector2.nodes.size(); ix3++) {
						vec2 = ctr->imeimvector2.nodes[ix3];

						vec2->ixVBasetype = VecWdbeVMVectorBasetype::getIx(vec2->srefIxVBasetype);
						if (vec2->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",vec2->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(vec2->lineno)}});
						vec2->hkIxVTbl = VecWdbeVMVectorHkTbl::CTR;
						vec2->hkUref = ctr->ref;
						//vec2->sref: TBL
						//vec2->srefsKOption: TBL

						dbswdbe->tblwdbemvector->insertRec(vec2);
						impcnt++;

						if (vec2->ixVBasetype == VecWdbeVMVectorBasetype::TIXLIN) num4 = 0;
						else num4 = 1;

						for (unsigned int ix4 = 0; ix4 < vec2->imeimvectoritem2.nodes.size(); ix4++) {
							vit2 = vec2->imeimvectoritem2.nodes[ix4];

							vit2->vecRefWdbeMVector = vec2->ref;
							//vit2->vecNum: CUST
							vit2->vecNum = num4;
							if (vec2->ixVBasetype == VecWdbeVMVectorBasetype::TIXOR) num4 *= 2;
							else num4++;
							//vit2->sref: TBL
							//vit2->Title: TBL
							//vit2->Comment: TBL

							dbswdbe->tblwdbemvectoritem->insertRec(vit2);
							impcnt++;
						};
					};

					refNum = 0;

					for (unsigned int ix3 = 0; ix3 < ctr->imeimcommand2.nodes.size(); ix3++) {
						cmd2 = ctr->imeimcommand2.nodes[ix3];

						cmd2->refIxVTbl = VecWdbeVMCommandRefTbl::CTR;
						cmd2->refUref = ctr->ref;
						//cmd2->refNum: TBL
						if (cmd2->refNum < refNum) cmd2->refNum = refNum;
						refNum = cmd2->refNum + 1;
						//cmd2->sref: TBL
						//cmd2->Fullsref: CUST
						cmd2->Fullsref = "Cmd" + ctr->Fullsref.substr(3) + StrMod::cap(cmd2->sref);
						cmd2->ixVRettype = VecWdbeVMCommandRettype::getIx(cmd2->srefIxVRettype);
						if (cmd2->ixVRettype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",cmd2->srefIxVRettype}, {"iel","srefIxVRettype"}, {"lineno",to_string(cmd2->lineno)}});
						//cmd2->Comment: TBL

						dbswdbe->tblwdbemcommand->insertRec(cmd2);
						impcnt++;

						num4 = 1;

						for (unsigned int ix4 = 0; ix4 < cmd2->imeiamcommandinvpar2.nodes.size(); ix4++) {
							cmdAipa2 = cmd2->imeiamcommandinvpar2.nodes[ix4];

							cmdAipa2->cmdRefWdbeMCommand = cmd2->ref;
							cmdAipa2->cmdNum = num4++;
							//cmdAipa2->sref: TBL
							cmdAipa2->ixWdbeVPartype = VecWdbeVPartype::getIx(cmdAipa2->srefIxWdbeVPartype);
							if (cmdAipa2->ixWdbeVPartype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",cmdAipa2->srefIxWdbeVPartype}, {"iel","srefIxWdbeVPartype"}, {"lineno",to_string(cmdAipa2->lineno)}});
							//cmdAipa2->refWdbeMVector: PREVIMP
							if (cmdAipa2->srefRefWdbeMVector != "") {
								for (unsigned int i = 0; i < unt->imeimvector1.nodes.size(); i++)
									if (unt->imeimvector1.nodes[i]->sref == cmdAipa2->srefRefWdbeMVector) {
										cmdAipa2->refWdbeMVector = unt->imeimvector1.nodes[i]->ref;
										break;
									};
								if (cmdAipa2->refWdbeMVector == 0)
									for (unsigned int i = 0; i < ctr->imeimvector2.nodes.size(); i++)
										if (ctr->imeimvector2.nodes[i]->sref == cmdAipa2->srefRefWdbeMVector) {
											cmdAipa2->refWdbeMVector = ctr->imeimvector2.nodes[i]->ref;
											break;
										};
								if (cmdAipa2->refWdbeMVector == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",cmdAipa2->srefRefWdbeMVector}, {"iel","srefRefWdbeMVector"}, {"lineno",to_string(cmdAipa2->lineno)}});
							};
							//cmdAipa2->Length: TBL
							//cmdAipa2->Defval: TBL
							//cmdAipa2->refWdbeMVectoritem: CUSTSQL
							if ((cmdAipa2->refWdbeMVector != 0) && (cmdAipa2->srefRefWdbeMVectoritem != "")) {
								dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMVectoritem WHERE vecRefWdbeMVector = " + to_string(cmdAipa2->refWdbeMVector) + " AND sref = '" + cmdAipa2->srefRefWdbeMVectoritem + "'", cmdAipa2->refWdbeMVectoritem);
								if (cmdAipa2->refWdbeMVectoritem == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",cmdAipa2->srefRefWdbeMVectoritem}, {"iel","srefRefWdbeMVectoritem"}, {"lineno",to_string(cmdAipa2->lineno)}});
							};
							//cmdAipa2->Comment: TBL

							dbswdbe->tblwdbeamcommandinvpar->insertRec(cmdAipa2);
							impcnt++;
						};

						num4 = 1;

						for (unsigned int ix4 = 0; ix4 < cmd2->imeiamcommandretpar2.nodes.size(); ix4++) {
							cmdArpa2 = cmd2->imeiamcommandretpar2.nodes[ix4];

							cmdArpa2->cmdRefWdbeMCommand = cmd2->ref;
							cmdArpa2->cmdNum = num4++;
							//cmdArpa2->sref: TBL
							cmdArpa2->ixWdbeVPartype = VecWdbeVPartype::getIx(cmdArpa2->srefIxWdbeVPartype);
							if (cmdArpa2->ixWdbeVPartype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",cmdArpa2->srefIxWdbeVPartype}, {"iel","srefIxWdbeVPartype"}, {"lineno",to_string(cmdArpa2->lineno)}});
							//cmdArpa2->refWdbeMVector: PREVIMP
							if (cmdArpa2->srefRefWdbeMVector != "") {
								for (unsigned int i = 0; i < unt->imeimvector1.nodes.size(); i++)
									if (unt->imeimvector1.nodes[i]->sref == cmdArpa2->srefRefWdbeMVector) {
										cmdArpa2->refWdbeMVector = unt->imeimvector1.nodes[i]->ref;
										break;
									};
								if (cmdArpa2->refWdbeMVector == 0)
									for (unsigned int i = 0; i < ctr->imeimvector2.nodes.size(); i++)
										if (ctr->imeimvector2.nodes[i]->sref == cmdArpa2->srefRefWdbeMVector) {
											cmdArpa2->refWdbeMVector = ctr->imeimvector2.nodes[i]->ref;
											break;
										};
								if (cmdArpa2->refWdbeMVector == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",cmdArpa2->srefRefWdbeMVector}, {"iel","srefRefWdbeMVector"}, {"lineno",to_string(cmdArpa2->lineno)}});
							};
							//cmdArpa2->Length: TBL
							//cmdArpa2->Comment: TBL

							dbswdbe->tblwdbeamcommandretpar->insertRec(cmdArpa2);
							impcnt++;
						};
					};

					for (unsigned int ix3 = 0; ix3 < ctr->imeirmcommandmcontroller.nodes.size(); ix3++) {
						cmdRctr = ctr->imeirmcommandmcontroller.nodes[ix3];

						//cmdRctr->refWdbeMCommand: IMPPP
						cmdRctr->refWdbeMController = ctr->ref;

						dbswdbe->tblwdbermcommandmcontroller->insertRec(cmdRctr);
						impcnt++;
					};

					refNum = 0;

					for (unsigned int ix3 = 0; ix3 < ctr->imeimerror2.nodes.size(); ix3++) {
						err2 = ctr->imeimerror2.nodes[ix3];

						err2->refIxVTbl = VecWdbeVMErrorRefTbl::CTR;
						err2->refUref = ctr->ref;
						//err2->refNum: TBL
						if (err2->refNum < refNum) err2->refNum = refNum;
						refNum = err2->refNum + 1;
						//err2->sref: TBL
						//err2->Fullsref: CUST
						err2->Fullsref = "Err" + ctr->Fullsref.substr(3) + StrMod::cap(err2->sref);
						//err2->Comment: TBL

						dbswdbe->tblwdbemerror->insertRec(err2);
						impcnt++;

						num4 = 1;

						for (unsigned int ix4 = 0; ix4 < err2->imeiamerrorpar2.nodes.size(); ix4++) {
							errApar2 = err2->imeiamerrorpar2.nodes[ix4];

							errApar2->errRefWdbeMError = err2->ref;
							errApar2->errNum = num4++;
							//errApar2->sref: TBL
							errApar2->ixWdbeVPartype = VecWdbeVPartype::getIx(errApar2->srefIxWdbeVPartype);
							if (errApar2->ixWdbeVPartype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",errApar2->srefIxWdbeVPartype}, {"iel","srefIxWdbeVPartype"}, {"lineno",to_string(errApar2->lineno)}});
							//errApar2->refWdbeMVector: PREVIMP
							if (errApar2->srefRefWdbeMVector != "") {
								for (unsigned int i = 0; i < unt->imeimvector1.nodes.size(); i++)
									if (unt->imeimvector1.nodes[i]->sref == errApar2->srefRefWdbeMVector) {
										errApar2->refWdbeMVector = unt->imeimvector1.nodes[i]->ref;
										break;
									};
								if (errApar2->refWdbeMVector == 0)
									for (unsigned int i = 0; i < ctr->imeimvector2.nodes.size(); i++)
										if (ctr->imeimvector2.nodes[i]->sref == errApar2->srefRefWdbeMVector) {
											errApar2->refWdbeMVector = ctr->imeimvector2.nodes[i]->ref;
											break;
										};
								if (errApar2->refWdbeMVector == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",errApar2->srefRefWdbeMVector}, {"iel","srefRefWdbeMVector"}, {"lineno",to_string(errApar2->lineno)}});
							};
							//errApar2->Length: TBL
							//errApar2->Comment: TBL

							dbswdbe->tblwdbeamerrorpar->insertRec(errApar2);
							impcnt++;
						};
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
						for (unsigned int ix2 = 0; ix2 < mdl->imeimcontroller.nodes.size(); ix2++) {
							ctr = mdl->imeimcontroller.nodes[ix2];

							if (ctr->ref != 0) {
								for (unsigned int ix3 = 0; ix3 < ctr->imeirmcommandmcontroller.nodes.size(); ix3++) {
									cmdRctr = ctr->imeirmcommandmcontroller.nodes[ix3];

									if (cmdRctr->srefRefWdbeMCommand != "") {
										ptr = cmdRctr->srefRefWdbeMCommand.find('.');
										if (ptr != string::npos)
											if (dbswdbe->loadRefBySQL("SELECT refWdbeMController FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND hkUref = " + to_string(mdl->hkUref) + " AND refWdbeMController <> 0 AND sref = '"
														+ cmdRctr->srefRefWdbeMCommand.substr(0, ptr) + "'", ref))
												dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMCommand WHERE refIxVTbl = " + to_string(VecWdbeVMCommandRefTbl::CTR) + " AND refUref = " + to_string(ref) + " AND sref = '" + cmdRctr->srefRefWdbeMCommand.substr(ptr+1) + "'", cmdRctr->refWdbeMCommand);

										if (cmdRctr->refWdbeMCommand == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",cmdRctr->srefRefWdbeMCommand}, {"iel","srefRefWdbeMCommand"}, {"lineno",to_string(cmdRctr->lineno)}});
									};

									if (cmdRctr->refWdbeMCommand != 0) dbswdbe->tblwdbermcommandmcontroller->updateRec(cmdRctr);
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

void JobWdbeIexCsx::leaveSgeImport(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeImport --- INSERT
};

uint JobWdbeIexCsx::enterSgeImperr(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IMPERR;

	// IP enterSgeImperr --- INSERT

	return retval;
};

void JobWdbeIexCsx::leaveSgeImperr(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeImperr --- INSERT
};

uint JobWdbeIexCsx::enterSgeReverse(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::IDLE;
	retval = nextIxVSgeSuccess;

	ImeitemIMUnit* unt = NULL;
	ImeitemIMCommand1* cmd1 = NULL;
	ImeitemIMError1* err1 = NULL;
	ImeitemIMModule* mdl = NULL;
	ImeitemIMVector1* vec1 = NULL;
	ImeitemIAMCommandInvpar1* cmdAipa1 = NULL;
	ImeitemIAMCommandRetpar1* cmdArpa1 = NULL;
	ImeitemIAMErrorPar1* errApar1 = NULL;
	ImeitemIMController* ctr = NULL;
	ImeitemIMVectoritem1* vit1 = NULL;
	ImeitemIMCommand2* cmd2 = NULL;
	ImeitemIMError2* err2 = NULL;
	ImeitemIMVector2* vec2 = NULL;
	ImeitemIRMCommandMController* cmdRctr = NULL;
	ImeitemIAMCommandInvpar2* cmdAipa2 = NULL;
	ImeitemIAMCommandRetpar2* cmdArpa2 = NULL;
	ImeitemIAMErrorPar2* errApar2 = NULL;
	ImeitemIMVectoritem2* vit2 = NULL;

	// -- ImeIMUnit
	for (unsigned int ix0 = 0; ix0 < imeimunit.nodes.size(); ix0++) {
		unt = imeimunit.nodes[ix0];
		if (unt->ref != 0) dbswdbe->tblwdbemunit->removeRecByRef(unt->ref);

		for (unsigned int ix1 = 0; ix1 < unt->imeimcommand1.nodes.size(); ix1++) {
			cmd1 = unt->imeimcommand1.nodes[ix1];
			if (cmd1->ref != 0) dbswdbe->tblwdbemcommand->removeRecByRef(cmd1->ref);

			for (unsigned int ix2 = 0; ix2 < cmd1->imeiamcommandinvpar1.nodes.size(); ix2++) {
				cmdAipa1 = cmd1->imeiamcommandinvpar1.nodes[ix2];
				if (cmdAipa1->ref != 0) dbswdbe->tblwdbeamcommandinvpar->removeRecByRef(cmdAipa1->ref);
			};

			for (unsigned int ix2 = 0; ix2 < cmd1->imeiamcommandretpar1.nodes.size(); ix2++) {
				cmdArpa1 = cmd1->imeiamcommandretpar1.nodes[ix2];
				if (cmdArpa1->ref != 0) dbswdbe->tblwdbeamcommandretpar->removeRecByRef(cmdArpa1->ref);
			};
		};

		for (unsigned int ix1 = 0; ix1 < unt->imeimerror1.nodes.size(); ix1++) {
			err1 = unt->imeimerror1.nodes[ix1];
			if (err1->ref != 0) dbswdbe->tblwdbemerror->removeRecByRef(err1->ref);

			for (unsigned int ix2 = 0; ix2 < err1->imeiamerrorpar1.nodes.size(); ix2++) {
				errApar1 = err1->imeiamerrorpar1.nodes[ix2];
				if (errApar1->ref != 0) dbswdbe->tblwdbeamerrorpar->removeRecByRef(errApar1->ref);
			};
		};

		for (unsigned int ix1 = 0; ix1 < unt->imeimmodule.nodes.size(); ix1++) {
			mdl = unt->imeimmodule.nodes[ix1];
			if (mdl->ref != 0) dbswdbe->tblwdbemmodule->removeRecByRef(mdl->ref);

			for (unsigned int ix2 = 0; ix2 < mdl->imeimcontroller.nodes.size(); ix2++) {
				ctr = mdl->imeimcontroller.nodes[ix2];
				if (ctr->ref != 0) dbswdbe->tblwdbemcontroller->removeRecByRef(ctr->ref);

				for (unsigned int ix3 = 0; ix3 < ctr->imeimcommand2.nodes.size(); ix3++) {
					cmd2 = ctr->imeimcommand2.nodes[ix3];
					if (cmd2->ref != 0) dbswdbe->tblwdbemcommand->removeRecByRef(cmd2->ref);

					for (unsigned int ix4 = 0; ix4 < cmd2->imeiamcommandinvpar2.nodes.size(); ix4++) {
						cmdAipa2 = cmd2->imeiamcommandinvpar2.nodes[ix4];
						if (cmdAipa2->ref != 0) dbswdbe->tblwdbeamcommandinvpar->removeRecByRef(cmdAipa2->ref);
					};

					for (unsigned int ix4 = 0; ix4 < cmd2->imeiamcommandretpar2.nodes.size(); ix4++) {
						cmdArpa2 = cmd2->imeiamcommandretpar2.nodes[ix4];
						if (cmdArpa2->ref != 0) dbswdbe->tblwdbeamcommandretpar->removeRecByRef(cmdArpa2->ref);
					};
				};

				for (unsigned int ix3 = 0; ix3 < ctr->imeimerror2.nodes.size(); ix3++) {
					err2 = ctr->imeimerror2.nodes[ix3];
					if (err2->ref != 0) dbswdbe->tblwdbemerror->removeRecByRef(err2->ref);

					for (unsigned int ix4 = 0; ix4 < err2->imeiamerrorpar2.nodes.size(); ix4++) {
						errApar2 = err2->imeiamerrorpar2.nodes[ix4];
						if (errApar2->ref != 0) dbswdbe->tblwdbeamerrorpar->removeRecByRef(errApar2->ref);
					};
				};

				for (unsigned int ix3 = 0; ix3 < ctr->imeimvector2.nodes.size(); ix3++) {
					vec2 = ctr->imeimvector2.nodes[ix3];
					if (vec2->ref != 0) dbswdbe->tblwdbemvector->removeRecByRef(vec2->ref);

					for (unsigned int ix4 = 0; ix4 < vec2->imeimvectoritem2.nodes.size(); ix4++) {
						vit2 = vec2->imeimvectoritem2.nodes[ix4];
						if (vit2->ref != 0) dbswdbe->tblwdbemvectoritem->removeRecByRef(vit2->ref);
					};
				};

				for (unsigned int ix3 = 0; ix3 < ctr->imeirmcommandmcontroller.nodes.size(); ix3++) {
					cmdRctr = ctr->imeirmcommandmcontroller.nodes[ix3];
					if (cmdRctr->ref != 0) dbswdbe->tblwdbermcommandmcontroller->removeRecByRef(cmdRctr->ref);
				};
			};
		};

		for (unsigned int ix1 = 0; ix1 < unt->imeimvector1.nodes.size(); ix1++) {
			vec1 = unt->imeimvector1.nodes[ix1];
			if (vec1->ref != 0) dbswdbe->tblwdbemvector->removeRecByRef(vec1->ref);

			for (unsigned int ix2 = 0; ix2 < vec1->imeimvectoritem1.nodes.size(); ix2++) {
				vit1 = vec1->imeimvectoritem1.nodes[ix2];
				if (vit1->ref != 0) dbswdbe->tblwdbemvectoritem->removeRecByRef(vit1->ref);
			};
		};
	};

	return retval;
};

void JobWdbeIexCsx::leaveSgeReverse(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeReverse --- INSERT
};

uint JobWdbeIexCsx::enterSgeCollect(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::CLTDONE;
	retval = nextIxVSgeSuccess;

	ImeitemIMUnit* unt = NULL;
	ImeitemIMCommand1* cmd1 = NULL;
	ImeitemIMError1* err1 = NULL;
	ImeitemIMModule* mdl = NULL;
	ImeitemIMVector1* vec1 = NULL;
	ImeitemIAMCommandInvpar1* cmdAipa1 = NULL;
	ImeitemIAMCommandRetpar1* cmdArpa1 = NULL;
	ImeitemIAMErrorPar1* errApar1 = NULL;
	ImeitemIMController* ctr = NULL;
	ImeitemIMVectoritem1* vit1 = NULL;
	ImeitemIMCommand2* cmd2 = NULL;
	ImeitemIMError2* err2 = NULL;
	ImeitemIMVector2* vec2 = NULL;
	ImeitemIRMCommandMController* cmdRctr = NULL;
	ImeitemIAMCommandInvpar2* cmdAipa2 = NULL;
	ImeitemIAMCommandRetpar2* cmdArpa2 = NULL;
	ImeitemIAMErrorPar2* errApar2 = NULL;
	ImeitemIMVectoritem2* vit2 = NULL;

	uint ixWdbeVIop;

	vector<ubigint> refs;

	Stcch* stcch = new Stcch(false);

	// IP enterSgeCollect.traverse --- BEGIN

	// -- ImeIMUnit
	for (unsigned int ix0 = 0; ix0 < imeimunit.nodes.size(); ix0++) {
		unt = imeimunit.nodes[ix0];

		if (unt->ref != 0) {
		};

		if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMCOMMAND1, ixWdbeVIop)) {
			dbswdbe->tblwdbemcommand->loadRefsByRetReu(VecWdbeVMCommandRefTbl::UNT, unt->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) unt->imeimcommand1.nodes.push_back(new ImeitemIMCommand1(dbswdbe, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < unt->imeimcommand1.nodes.size(); ix1++) {
			cmd1 = unt->imeimcommand1.nodes[ix1];

			if (cmd1->ref != 0) {
			};

			if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIAMCOMMANDINVPAR1, ixWdbeVIop)) {
				dbswdbe->tblwdbeamcommandinvpar->loadRefsByCmd(cmd1->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) cmd1->imeiamcommandinvpar1.nodes.push_back(new ImeitemIAMCommandInvpar1(dbswdbe, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < cmd1->imeiamcommandinvpar1.nodes.size(); ix2++) {
				cmdAipa1 = cmd1->imeiamcommandinvpar1.nodes[ix2];

				if (cmdAipa1->ref != 0) {
					cmdAipa1->srefRefWdbeMVector = StubWdbe::getStubVecStd(dbswdbe, cmdAipa1->refWdbeMVector, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
					//cmdAipa1->srefRefWdbeMVectoritem: STUB
				};
			};

			if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIAMCOMMANDRETPAR1, ixWdbeVIop)) {
				dbswdbe->tblwdbeamcommandretpar->loadRefsByCmd(cmd1->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) cmd1->imeiamcommandretpar1.nodes.push_back(new ImeitemIAMCommandRetpar1(dbswdbe, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < cmd1->imeiamcommandretpar1.nodes.size(); ix2++) {
				cmdArpa1 = cmd1->imeiamcommandretpar1.nodes[ix2];

				if (cmdArpa1->ref != 0) {
					cmdArpa1->srefRefWdbeMVector = StubWdbe::getStubVecStd(dbswdbe, cmdArpa1->refWdbeMVector, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
				};
			};
		};

		if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMERROR1, ixWdbeVIop)) {
			dbswdbe->tblwdbemerror->loadRefsByRetReu(VecWdbeVMErrorRefTbl::UNT, unt->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) unt->imeimerror1.nodes.push_back(new ImeitemIMError1(dbswdbe, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < unt->imeimerror1.nodes.size(); ix1++) {
			err1 = unt->imeimerror1.nodes[ix1];

			if (err1->ref != 0) {
			};

			if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIAMERRORPAR1, ixWdbeVIop)) {
				dbswdbe->tblwdbeamerrorpar->loadRefsByErr(err1->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) err1->imeiamerrorpar1.nodes.push_back(new ImeitemIAMErrorPar1(dbswdbe, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < err1->imeiamerrorpar1.nodes.size(); ix2++) {
				errApar1 = err1->imeiamerrorpar1.nodes[ix2];

				if (errApar1->ref != 0) {
					errApar1->srefRefWdbeMVector = StubWdbe::getStubVecStd(dbswdbe, errApar1->refWdbeMVector, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
				};
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

			if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMCONTROLLER, ixWdbeVIop)) {
				dbswdbe->tblwdbemcontroller->loadRefsByMdl(mdl->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) mdl->imeimcontroller.nodes.push_back(new ImeitemIMController(dbswdbe, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < mdl->imeimcontroller.nodes.size(); ix2++) {
				ctr = mdl->imeimcontroller.nodes[ix2];

				if (ctr->ref != 0) {
				};

				if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMCOMMAND2, ixWdbeVIop)) {
					dbswdbe->tblwdbemcommand->loadRefsByRetReu(VecWdbeVMCommandRefTbl::CTR, ctr->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) ctr->imeimcommand2.nodes.push_back(new ImeitemIMCommand2(dbswdbe, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < ctr->imeimcommand2.nodes.size(); ix3++) {
					cmd2 = ctr->imeimcommand2.nodes[ix3];

					if (cmd2->ref != 0) {
					};

					if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIAMCOMMANDINVPAR2, ixWdbeVIop)) {
						dbswdbe->tblwdbeamcommandinvpar->loadRefsByCmd(cmd2->ref, false, refs);
						for (unsigned int i = 0; i < refs.size(); i++) cmd2->imeiamcommandinvpar2.nodes.push_back(new ImeitemIAMCommandInvpar2(dbswdbe, refs[i]));
					};

					for (unsigned int ix4 = 0; ix4 < cmd2->imeiamcommandinvpar2.nodes.size(); ix4++) {
						cmdAipa2 = cmd2->imeiamcommandinvpar2.nodes[ix4];

						if (cmdAipa2->ref != 0) {
							cmdAipa2->srefRefWdbeMVector = StubWdbe::getStubVecStd(dbswdbe, cmdAipa2->refWdbeMVector, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
							//cmdAipa2->srefRefWdbeMVectoritem: STUB
						};
					};

					if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIAMCOMMANDRETPAR2, ixWdbeVIop)) {
						dbswdbe->tblwdbeamcommandretpar->loadRefsByCmd(cmd2->ref, false, refs);
						for (unsigned int i = 0; i < refs.size(); i++) cmd2->imeiamcommandretpar2.nodes.push_back(new ImeitemIAMCommandRetpar2(dbswdbe, refs[i]));
					};

					for (unsigned int ix4 = 0; ix4 < cmd2->imeiamcommandretpar2.nodes.size(); ix4++) {
						cmdArpa2 = cmd2->imeiamcommandretpar2.nodes[ix4];

						if (cmdArpa2->ref != 0) {
							cmdArpa2->srefRefWdbeMVector = StubWdbe::getStubVecStd(dbswdbe, cmdArpa2->refWdbeMVector, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
						};
					};
				};

				if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMERROR2, ixWdbeVIop)) {
					dbswdbe->tblwdbemerror->loadRefsByRetReu(VecWdbeVMErrorRefTbl::CTR, ctr->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) ctr->imeimerror2.nodes.push_back(new ImeitemIMError2(dbswdbe, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < ctr->imeimerror2.nodes.size(); ix3++) {
					err2 = ctr->imeimerror2.nodes[ix3];

					if (err2->ref != 0) {
					};

					if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIAMERRORPAR2, ixWdbeVIop)) {
						dbswdbe->tblwdbeamerrorpar->loadRefsByErr(err2->ref, false, refs);
						for (unsigned int i = 0; i < refs.size(); i++) err2->imeiamerrorpar2.nodes.push_back(new ImeitemIAMErrorPar2(dbswdbe, refs[i]));
					};

					for (unsigned int ix4 = 0; ix4 < err2->imeiamerrorpar2.nodes.size(); ix4++) {
						errApar2 = err2->imeiamerrorpar2.nodes[ix4];

						if (errApar2->ref != 0) {
							errApar2->srefRefWdbeMVector = StubWdbe::getStubVecStd(dbswdbe, errApar2->refWdbeMVector, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
						};
					};
				};

				if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMVECTOR2, ixWdbeVIop)) {
					dbswdbe->tblwdbemvector->loadRefsByHktHku(VecWdbeVMVectorHkTbl::CTR, ctr->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) ctr->imeimvector2.nodes.push_back(new ImeitemIMVector2(dbswdbe, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < ctr->imeimvector2.nodes.size(); ix3++) {
					vec2 = ctr->imeimvector2.nodes[ix3];

					if (vec2->ref != 0) {
					};

					if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMVECTORITEM2, ixWdbeVIop)) {
						dbswdbe->tblwdbemvectoritem->loadRefsByVec(vec2->ref, false, refs);
						for (unsigned int i = 0; i < refs.size(); i++) vec2->imeimvectoritem2.nodes.push_back(new ImeitemIMVectoritem2(dbswdbe, refs[i]));
					};

					for (unsigned int ix4 = 0; ix4 < vec2->imeimvectoritem2.nodes.size(); ix4++) {
						vit2 = vec2->imeimvectoritem2.nodes[ix4];

						if (vit2->ref != 0) {
						};
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
					};
				};
			};
		};

		if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMVECTOR1, ixWdbeVIop)) {
			dbswdbe->tblwdbemvector->loadRefsByHktHku(VecWdbeVMVectorHkTbl::UNT, unt->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) unt->imeimvector1.nodes.push_back(new ImeitemIMVector1(dbswdbe, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < unt->imeimvector1.nodes.size(); ix1++) {
			vec1 = unt->imeimvector1.nodes[ix1];

			if (vec1->ref != 0) {
			};

			if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMVECTORITEM1, ixWdbeVIop)) {
				dbswdbe->tblwdbemvectoritem->loadRefsByVec(vec1->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) vec1->imeimvectoritem1.nodes.push_back(new ImeitemIMVectoritem1(dbswdbe, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < vec1->imeimvectoritem1.nodes.size(); ix2++) {
				vit1 = vec1->imeimvectoritem1.nodes[ix2];

				if (vit1->ref != 0) {
				};
			};
		};
	};
	// IP enterSgeCollect.traverse --- END
	// IP enterSgeCollect.ppr --- INSERT

	delete stcch;

	return retval;
};

void JobWdbeIexCsx::leaveSgeCollect(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeCollect --- INSERT
};

uint JobWdbeIexCsx::enterSgeCltdone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::CLTDONE;

	// IP enterSgeCltdone --- INSERT

	return retval;
};

void JobWdbeIexCsx::leaveSgeCltdone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeCltdone --- INSERT
};

uint JobWdbeIexCsx::enterSgeExport(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	IexWdbeCsx::exportToFile(fullpath, xmlNotTxt, shorttags, imeimunit);

	return retval;
};

void JobWdbeIexCsx::leaveSgeExport(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeExport --- INSERT
};

uint JobWdbeIexCsx::enterSgeDone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void JobWdbeIexCsx::leaveSgeDone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeDone --- INSERT
};
