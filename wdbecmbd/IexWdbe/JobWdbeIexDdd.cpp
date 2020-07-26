/**
	* \file JobWdbeIexDdd.cpp
	* job handler for job JobWdbeIexDdd (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbed.h>
#endif

#include "JobWdbeIexDdd.h"

#include "JobWdbeIexDdd_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

using namespace IexWdbeDdd;

/******************************************************************************
 class JobWdbeIexDdd
 ******************************************************************************/

JobWdbeIexDdd::JobWdbeIexDdd(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::JOBWDBEIEXDDD, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	changeStage(dbswdbe, VecVSge::IDLE);

	// IP constructor.cust3 --- INSERT

};

JobWdbeIexDdd::~JobWdbeIexDdd() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void JobWdbeIexDdd::reset(
			DbsWdbe* dbswdbe
		) {
	if (ixVSge != VecVSge::IDLE) changeStage(dbswdbe, VecVSge::IDLE);
};

void JobWdbeIexDdd::parseFromFile(
			DbsWdbe* dbswdbe
			, const string& _fullpath
			, const bool _xmlNotTxt
		) {
	if (ixVSge == VecVSge::IDLE) {
		fullpath = _fullpath;
		xmlNotTxt = _xmlNotTxt;

		changeStage(dbswdbe, VecVSge::PARSE);
	};
};

void JobWdbeIexDdd::import(
			DbsWdbe* dbswdbe
		) {
	if (ixVSge == VecVSge::PRSDONE) changeStage(dbswdbe, VecVSge::IMPORT);
};

void JobWdbeIexDdd::reverse(
			DbsWdbe* dbswdbe
		) {
	if (ixVSge == VecVSge::IMPERR) changeStage(dbswdbe, VecVSge::REVERSE);
};

void JobWdbeIexDdd::collect(
			DbsWdbe* dbswdbe
			, const map<uint,uint>& _icsWdbeVIop
		) {
	if (ixVSge == VecVSge::IDLE) {
		icsWdbeVIop = _icsWdbeVIop;
		changeStage(dbswdbe, VecVSge::COLLECT);
	};
};

void JobWdbeIexDdd::exportToFile(
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

void JobWdbeIexDdd::handleRequest(
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

void JobWdbeIexDdd::changeStage(
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

string JobWdbeIexDdd::getSquawk(
			DbsWdbe* dbswdbe
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::PARSE) || (ixVSge == VecVSge::PRSDONE) || (ixVSge == VecVSge::IMPORT) || (ixVSge == VecVSge::REVERSE) || (ixVSge == VecVSge::COLLECT) || (ixVSge == VecVSge::CLTDONE) || (ixVSge == VecVSge::EXPORT) ) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing detailed device description";
			else if (ixVSge == VecVSge::PRSDONE) retval = "detailed device description parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing detailed device description (" + to_string(impcnt) + " records added)";
			else if (ixVSge == VecVSge::REVERSE) retval = "reversing detailed device description import";
			else if (ixVSge == VecVSge::COLLECT) retval = "collecting detailed device description for export";
			else if (ixVSge == VecVSge::CLTDONE) retval = "detailed device description collected for export";
			else if (ixVSge == VecVSge::EXPORT) retval = "exporting detailed device description";
		};

	} else if ( (ixVSge == VecVSge::PRSERR) || (ixVSge == VecVSge::IMPERR) ) {
		retval = lasterror;

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

uint JobWdbeIexDdd::enterSgeIdle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	fullpath = "";
	xmlNotTxt = false;

	lineno = 0;
	impcnt = 0;

	icsWdbeVIop.clear();

	imeimunit.clear();

	return retval;
};

void JobWdbeIexDdd::leaveSgeIdle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWdbeIexDdd::enterSgeParse(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::PRSDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::PRSERR;

	try {
		IexWdbeDdd::parseFromFile(fullpath, xmlNotTxt, imeimunit);

	} catch (SbeException& e) {
		if (e.ix == SbeException::PATHNF) e.vals["path"] = "<hidden>";
		lasterror = e.getSquawk(VecWdbeVError::getIx, VecWdbeVError::getTitle, ixWdbeVLocale);

		retval = nextIxVSgeFailure;
	};

	return retval;
};

void JobWdbeIexDdd::leaveSgeParse(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeParse --- INSERT
};

uint JobWdbeIexDdd::enterSgePrserr(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::PRSERR;

	// IP enterSgePrserr --- INSERT

	return retval;
};

void JobWdbeIexDdd::leaveSgePrserr(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgePrserr --- INSERT
};

uint JobWdbeIexDdd::enterSgePrsdone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::PRSDONE;

	// IP enterSgePrsdone --- INSERT

	return retval;
};

void JobWdbeIexDdd::leaveSgePrsdone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgePrsdone --- INSERT
};

uint JobWdbeIexDdd::enterSgeImport(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IMPERR;

	ImeitemIMUnit* unt = NULL;
	ImeitemIMBank* bnk = NULL;
	ImeitemIMCommand1* cmd1 = NULL;
	ImeitemIMError1* err1 = NULL;
	ImeitemIMModule* mdl = NULL;
	ImeitemIMVector1* vec1 = NULL;
	ImeitemIAMCommandInvpar1* cmdAipa1 = NULL;
	ImeitemIAMCommandRetpar1* cmdArpa1 = NULL;
	ImeitemIAMErrorPar1* errApar1 = NULL;
	ImeitemICGeneric* genC = NULL;
	ImeitemICPin* pinC = NULL;
	ImeitemICPort* prtC = NULL;
	ImeitemICSignal* sigC = NULL;
	ImeitemIMController* ctr = NULL;
	ImeitemIMGeneric* gen = NULL;
	ImeitemIMImbuf* imb = NULL;
	ImeitemIMPin* pin = NULL;
	ImeitemIMPort* prt = NULL;
	ImeitemIMProcess* prc = NULL;
	ImeitemIMSignal* sig = NULL;
	ImeitemIMVectoritem1* vit1 = NULL;
	ImeitemIAMPinPar* pinApar = NULL;
	ImeitemIAVKeylistKey* klsAkey = NULL;
	ImeitemICVariable* varC = NULL;
	ImeitemIJMPinSref* pinJsrf = NULL;
	ImeitemIMCommand2* cmd2 = NULL;
	ImeitemIMError2* err2 = NULL;
	ImeitemIMFsm* fsm = NULL;
	ImeitemIMVariable* var = NULL;
	ImeitemIMVector2* vec2 = NULL;
	ImeitemIRMCommandMController* cmdRctr = NULL;
	ImeitemIAMCommandInvpar2* cmdAipa2 = NULL;
	ImeitemIAMCommandRetpar2* cmdArpa2 = NULL;
	ImeitemIAMErrorPar2* errApar2 = NULL;
	ImeitemICFsmstate* fstC = NULL;
	ImeitemIJAVKeylistKey* kakJkey = NULL;
	ImeitemIMFsmstate* fst = NULL;
	ImeitemIMVectoritem2* vit2 = NULL;
	ImeitemIAMFsmstateStep* fstAstp = NULL;

	set<ubigint> irefs2, irefs3, irefs4;

	uint num2, num3, num4, num5;

	// IP enterSgeImport.prep --- IBEGIN
	ubigint refWdbeMVersion;
	refWdbeMVersion = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref);

	ubigint ref;

	WdbeMUnit* unt_r = NULL;
	WdbeMBank* bnk_r = NULL;
	WdbeMPin* pin_r = NULL;

	ListWdbeMModule mdl_rs;
	WdbeMModule* mdl_r = NULL;

	WdbeMImbuf* imb_r = NULL;
	WdbeMController* ctr_r = NULL;
	WdbeMGeneric* gen_r = NULL;
	WdbeMPort* prt_r = NULL;

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
						for (unsigned int i = 0; i < bnk->imeicpin.nodes.size(); i++)
							if (bnk->imeicpin.nodes[i]->iref == pin->irefRefWdbeCPin) {
								pin->refWdbeCPin = bnk->imeicpin.nodes[i]->ref;
								break;
							};
						if (pin->refWdbeCPin == 0) throw SbeException(SbeException::IEX_IREF, {{"iref",to_string(pin->irefRefWdbeCPin)}, {"iel","irefRefWdbeCPin"}, {"lineno",to_string(pin->lineno)}});
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
						mdl->Comment = mdl_r->Comment;
					};
				};
				if (mdl->ref == 0) throw SbeException(SbeException::IEX_RETR, {{"ime","ImeIMModule"}, {"lineno",to_string(mdl->lineno)}});

				for (unsigned int ix2 = 0; ix2 < mdl->imeimimbuf.nodes.size(); ix2++) {
					imb = mdl->imeimimbuf.nodes[ix2];

					// retrieve
					if (dbswdbe->tblwdbemimbuf->loadRecByRef(mdl->refWdbeMImbuf, &imb_r)) {
						imb->ref = imb_r->ref;
						//imb->refWdbeMModule = imb_r->refWdbeMModule;
						imb->corRefWdbeMModule = imb_r->corRefWdbeMModule;
						imb->sref = imb_r->sref;
						imb->ixVDir = imb_r->ixVDir;
						//imb->Prio = imb_r->Prio;

						delete imb_r;

						imb->refWdbeMModule = mdl->ref;
						//imb->Prio: TBL

						dbswdbe->tblwdbemimbuf->updateRec(imb);

					} else throw SbeException(SbeException::IEX_RETR, {{"ime","ImeIMImbuf"}, {"lineno",to_string(imb->lineno)}});
				};

				for (unsigned int ix2 = 0; ix2 < mdl->imeimcontroller.nodes.size(); ix2++) {
					ctr = mdl->imeimcontroller.nodes[ix2];

					ctr->ixWdbeVIop = VecWdbeVIop::getIx(ctr->srefIxWdbeVIop);
					if ((ctr->ixWdbeVIop != VecWdbeVIop::RETR) && (ctr->ixWdbeVIop != VecWdbeVIop::RETRUPD)) throw SbeException(SbeException::IEX_IOP, {{"iop",ctr->srefIxWdbeVIop}, {"ime","ImeIMController"}, {"lineno",to_string(ctr->lineno)}});

					// retrieve
					if (dbswdbe->tblwdbemcontroller->loadRecByRef(mdl->refWdbeMController, &ctr_r)) {
						ctr->ref = ctr_r->ref;
						//ctr->refWdbeMModule = ctr_r->refWdbeMModule;
						ctr->fwdRefWdbeMUnit = ctr_r->fwdRefWdbeMUnit;
						ctr->Fullsref = ctr_r->Fullsref;
						if (ctr->ixWdbeVIop == VecWdbeVIop::RETR) ctr->clrRefWdbeMSignal = ctr_r->clrRefWdbeMSignal;

						delete ctr_r;

						ctr->refWdbeMModule = mdl->ref;
						//ctr->clrRefWdbeMSignal: IMPPP

						if (ctr->ixWdbeVIop == VecWdbeVIop::RETRUPD) dbswdbe->tblwdbemcontroller->updateRec(ctr); // pointless, all update takes place in PP

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
						//cmd2->ivrRefWdbeMSignal: IMPPP
						//cmd2->rvrRefWdbeMSignal: IMPPP
						//cmd2->rerRefWdbeMSignal: IMPPP
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
						//cmdRctr->ivrRefWdbeMSignal: IMPPP
						//cmdRctr->rvrRefWdbeMSignal: IMPPP

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
						//err2->traRefWdbeMSignal: IMPPP
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
							//gen->Defval = gen_r->Defval;
							//gen->srcSrefWdbeMGeneric = gen_r->srcSrefWdbeMGeneric;
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
							for (unsigned int i = 0; i < mdl->imeicgeneric.nodes.size(); i++)
								if (mdl->imeicgeneric.nodes[i]->iref == gen->irefRefWdbeCGeneric) {
									gen->refWdbeCGeneric = mdl->imeicgeneric.nodes[i]->ref;
									break;
								};
							if (gen->refWdbeCGeneric == 0) throw SbeException(SbeException::IEX_IREF, {{"iref",to_string(gen->irefRefWdbeCGeneric)}, {"iel","irefRefWdbeCGeneric"}, {"lineno",to_string(gen->lineno)}});
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
							for (unsigned int i = 0; i < mdl->imeicport.nodes.size(); i++)
								if (mdl->imeicport.nodes[i]->iref == prt->irefRefWdbeCPort) {
									prt->refWdbeCPort = mdl->imeicport.nodes[i]->ref;
									break;
								};
							if (prt->refWdbeCPort == 0) throw SbeException(SbeException::IEX_IREF, {{"iref",to_string(prt->irefRefWdbeCPort)}, {"iel","irefRefWdbeCPort"}, {"lineno",to_string(prt->lineno)}});
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

				for (unsigned int ix2 = 0; ix2 < mdl->imeicsignal.nodes.size(); ix2++) {
					sigC = mdl->imeicsignal.nodes[ix2];

					if (irefs2.find(sigC->iref) != irefs2.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(sigC->iref)}, {"ime","ImeICSignal"}, {"lineno",to_string(sigC->lineno)}});
					sigC->ref = dbswdbe->tblwdbecsignal->getNewRef();
					irefs2.insert(sigC->iref);
				};

				num2 = 1;

				for (unsigned int ix2 = 0; ix2 < mdl->imeimsignal.nodes.size(); ix2++) {
					sig = mdl->imeimsignal.nodes[ix2];

					sig->ixVBasetype = VecWdbeVMSignalBasetype::getIx(sig->srefIxVBasetype);
					if (sig->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",sig->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(sig->lineno)}});
					//sig->refWdbeCSignal: PREVIMP
					if (sig->irefRefWdbeCSignal != 0) {
						for (unsigned int i = 0; i < mdl->imeicsignal.nodes.size(); i++)
							if (mdl->imeicsignal.nodes[i]->iref == sig->irefRefWdbeCSignal) {
								sig->refWdbeCSignal = mdl->imeicsignal.nodes[i]->ref;
								break;
							};
						if (sig->refWdbeCSignal == 0) throw SbeException(SbeException::IEX_IREF, {{"iref",to_string(sig->irefRefWdbeCSignal)}, {"iel","irefRefWdbeCSignal"}, {"lineno",to_string(sig->lineno)}});
					};
					sig->mdlRefWdbeMModule = mdl->ref;
					sig->mdlNum = num2++;
					sig->mgeIxVTbl = VecWdbeVMSignalMgeTbl::getIx(sig->srefMgeIxVTbl);
					if (sig->mgeIxVTbl == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",sig->srefMgeIxVTbl}, {"iel","srefMgeIxVTbl"}, {"lineno",to_string(sig->lineno)}});
					//sig->mgeUref: CUSTSQLPP
					//sig->sref: TBL
					//sig->Const: TBL
					//sig->srefWdbeKHdltype: TBL
					//sig->Width: TBL
					//sig->Minmax: TBL
					//sig->Comb: TBL
					//sig->Onval: TBL
					//sig->Offval: TBL
					//sig->Defon: TBL
					//sig->drvRefWdbeMPort: CUSTSQL
					if (sig->srefDrvRefWdbeMPort != "") {
						dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = '" + sig->srefDrvRefWdbeMPort + "'", sig->drvRefWdbeMPort);
						if (sig->drvRefWdbeMPort == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",sig->srefDrvRefWdbeMPort}, {"iel","srefDrvRefWdbeMPort"}, {"lineno",to_string(sig->lineno)}});
					};
					//sig->Comment: TBL

					dbswdbe->tblwdbemsignal->insertRec(sig);
					impcnt++;
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

					for (unsigned int ix3 = 0; ix3 < prc->imeicvariable.nodes.size(); ix3++) {
						varC = prc->imeicvariable.nodes[ix3];

						if (irefs3.find(varC->iref) != irefs3.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(varC->iref)}, {"ime","ImeICVariable"}, {"lineno",to_string(varC->lineno)}});
						varC->ref = dbswdbe->tblwdbecvariable->getNewRef();
						irefs3.insert(varC->iref);
					};

					num3 = 1;

					for (unsigned int ix3 = 0; ix3 < prc->imeimvariable.nodes.size(); ix3++) {
						var = prc->imeimvariable.nodes[ix3];

						//var->refWdbeCVariable: PREVIMP
						if (var->irefRefWdbeCVariable != 0) {
							for (unsigned int i = 0; i < prc->imeicvariable.nodes.size(); i++)
								if (prc->imeicvariable.nodes[i]->iref == var->irefRefWdbeCVariable) {
									var->refWdbeCVariable = prc->imeicvariable.nodes[i]->ref;
									break;
								};
							if (var->refWdbeCVariable == 0) throw SbeException(SbeException::IEX_IREF, {{"iref",to_string(var->irefRefWdbeCVariable)}, {"iel","irefRefWdbeCVariable"}, {"lineno",to_string(var->lineno)}});
						};
						var->prcRefWdbeMProcess = prc->ref;
						var->prcNum = num3++;
						//var->sref: TBL
						//var->Const: TBL
						//var->Falling: TBL
						//var->srefWdbeKHdltype: TBL
						//var->Width: TBL
						//var->Minmax: TBL
						//var->Onval: TBL
						//var->Offval: TBL
						//var->Defon: TBL
						//var->Comment: TBL

						dbswdbe->tblwdbemvariable->insertRec(var);
						impcnt++;
					};

					for (unsigned int ix3 = 0; ix3 < prc->imeimfsm.nodes.size(); ix3++) {
						fsm = prc->imeimfsm.nodes[ix3];

						fsm->refWdbeMProcess = prc->ref;

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
						};

						num4 = 1;

						for (unsigned int ix4 = 0; ix4 < fsm->imeimfsmstate.nodes.size(); ix4++) {
							fst = fsm->imeimfsmstate.nodes[ix4];

							//fst->refWdbeCFsmstate: PREVIMP
							if (fst->irefRefWdbeCFsmstate != 0) {
								for (unsigned int i = 0; i < fsm->imeicfsmstate.nodes.size(); i++)
									if (fsm->imeicfsmstate.nodes[i]->iref == fst->irefRefWdbeCFsmstate) {
										fst->refWdbeCFsmstate = fsm->imeicfsmstate.nodes[i]->ref;
										break;
									};
								if (fst->refWdbeCFsmstate == 0) throw SbeException(SbeException::IEX_IREF, {{"iref",to_string(fst->irefRefWdbeCFsmstate)}, {"iel","irefRefWdbeCFsmstate"}, {"lineno",to_string(fst->lineno)}});
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

								dbswdbe->tblwdbeamfsmstatestep->insertRec(fstAstp);
								impcnt++;
							};
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
								if ((ctr->ixWdbeVIop == VecWdbeVIop::RETRUPD) && (ctr->srefClrRefWdbeMSignal != "")) {
									//ctr->clrRefWdbeMSignal: IMPPP
									for (unsigned int i = 0; i < mdl->imeimsignal.nodes.size(); i++)
										if (mdl->imeimsignal.nodes[i]->sref == ctr->srefClrRefWdbeMSignal) {
											ctr->clrRefWdbeMSignal = mdl->imeimsignal.nodes[i]->ref;
											break;
										};

									dbswdbe->tblwdbemcontroller->updateRec(ctr);
								};

								for (unsigned int ix3 = 0; ix3 < ctr->imeimcommand2.nodes.size(); ix3++) {
									cmd2 = ctr->imeimcommand2.nodes[ix3];

									if ((cmd2->srefIvrRefWdbeMSignal != "") || (cmd2->srefRvrRefWdbeMSignal != "") || (cmd2->srefRerRefWdbeMSignal != "")) {
										if (cmd2->srefIvrRefWdbeMSignal != "")
											//cmd2->ivrRefWdbeMSignal: IMPPP
											for (unsigned int i = 0; i < mdl->imeimsignal.nodes.size(); i++)
												if (mdl->imeimsignal.nodes[i]->sref == cmd2->srefIvrRefWdbeMSignal) {
													cmd2->ivrRefWdbeMSignal = mdl->imeimsignal.nodes[i]->ref;
													break;
												};

										if (cmd2->srefRvrRefWdbeMSignal != "")
											//cmd2->rvrRefWdbeMSignal: IMPPP
											for (unsigned int i = 0; i < mdl->imeimsignal.nodes.size(); i++)
												if (mdl->imeimsignal.nodes[i]->sref == cmd2->srefRvrRefWdbeMSignal) {
													cmd2->rvrRefWdbeMSignal = mdl->imeimsignal.nodes[i]->ref;
													break;
												};

										if (cmd2->srefRerRefWdbeMSignal != "")
											//cmd2->rerRefWdbeMSignal: IMPPP
											for (unsigned int i = 0; i < mdl->imeimsignal.nodes.size(); i++)
												if (mdl->imeimsignal.nodes[i]->sref == cmd2->srefRerRefWdbeMSignal) {
													cmd2->rerRefWdbeMSignal = mdl->imeimsignal.nodes[i]->ref;
													break;
												};

										dbswdbe->tblwdbemcommand->updateRec(cmd2);
									};
								};

								for (unsigned int ix3 = 0; ix3 < ctr->imeirmcommandmcontroller.nodes.size(); ix3++) {
									cmdRctr = ctr->imeirmcommandmcontroller.nodes[ix3];

									//cmdRctr->refWdbeMCommand: IMPPP -> CUSTSQLPP
									ptr = cmdRctr->srefRefWdbeMCommand.find('.');
									if (ptr != string::npos)
										if (dbswdbe->loadRefBySQL("SELECT refWdbeMController FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND hkUref = " + to_string(mdl->hkUref) + " AND refWdbeMController <> 0 AND sref = '"
													+ cmdRctr->srefRefWdbeMCommand.substr(0, ptr) + "'", ref))
											dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMCommand WHERE refIxVTbl = " + to_string(VecWdbeVMCommandRefTbl::CTR) + " AND refUref = " + to_string(ref) + " AND sref = '" + cmdRctr->srefRefWdbeMCommand.substr(ptr+1) + "'", cmdRctr->refWdbeMCommand);

									if (cmdRctr->srefIvrRefWdbeMSignal != "")
										//cmdRctr->ivrRefWdbeMSignal: IMPPP
										for (unsigned int i = 0; i < mdl->imeimsignal.nodes.size(); i++)
											if (mdl->imeimsignal.nodes[i]->sref == cmdRctr->srefIvrRefWdbeMSignal) {
												cmdRctr->ivrRefWdbeMSignal = mdl->imeimsignal.nodes[i]->ref;
												break;
											};

									if (cmdRctr->srefRvrRefWdbeMSignal != "")
										//cmdRctr->rvrRefWdbeMSignal: IMPPP
										for (unsigned int i = 0; i < mdl->imeimsignal.nodes.size(); i++)
											if (mdl->imeimsignal.nodes[i]->sref == cmdRctr->srefRvrRefWdbeMSignal) {
												cmdRctr->rvrRefWdbeMSignal = mdl->imeimsignal.nodes[i]->ref;
												break;
											};

									dbswdbe->tblwdbermcommandmcontroller->updateRec(cmdRctr);
								};

								for (unsigned int ix3 = 0; ix3 < ctr->imeimerror2.nodes.size(); ix3++) {
									err2 = ctr->imeimerror2.nodes[ix3];

									if (err2->srefTraRefWdbeMSignal != "")
										//err2->traRefWdbeMSignal: IMPPP
										for (unsigned int i = 0; i < mdl->imeimsignal.nodes.size(); i++)
											if (mdl->imeimsignal.nodes[i]->sref == err2->srefTraRefWdbeMSignal) {
												err2->traRefWdbeMSignal = mdl->imeimsignal.nodes[i]->ref;
												break;
											};

									dbswdbe->tblwdbemerror->updateRec(err2);
								};
							};
						};

						for (unsigned int ix2 = 0; ix2 < mdl->imeimsignal.nodes.size(); ix2++) {
							sig = mdl->imeimsignal.nodes[ix2];

							if (sig->srefMgeUref != "") {
								//sig->mgeUref: CUSTSQLPP
								if (sig->mgeIxVTbl == VecWdbeVMSignalMgeTbl::MDL) {
									dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = '" + sig->srefMgeUref + "'", sig->mgeUref);
								} else if (sig->mgeIxVTbl == VecWdbeVMSignalMgeTbl::PRC) {
									for (unsigned int i = 0; i < mdl->imeimprocess.nodes.size(); i++)
										if (mdl->imeimprocess.nodes[i]->sref == sig->srefMgeUref) {
											sig->mgeUref = mdl->imeimprocess.nodes[i]->ref;
											break;
										};
								};

								dbswdbe->tblwdbemsignal->updateRec(sig);
							};
						};

						for (unsigned int ix2 = 0; ix2 < mdl->imeimprocess.nodes.size(); ix2++) {
							prc = mdl->imeimprocess.nodes[ix2];

							for (unsigned int ix3 = 0; ix3 < prc->imeimfsm.nodes.size(); ix3++) {
								fsm = prc->imeimfsm.nodes[ix3];

								for (unsigned int ix4 = 0; ix4 < fsm->imeimfsmstate.nodes.size(); ix4++) {
									fst = fsm->imeimfsmstate.nodes[ix4];

									for (unsigned int ix5 = 0; ix5 < fst->imeiamfsmstatestep.nodes.size(); ix5++) {
										fstAstp = fst->imeiamfsmstatestep.nodes[ix5];

										if (fstAstp->srefFnxRefWdbeMFsmstate != "") {
											//fstAstp->fnxRefWdbeMFsmstate: IMPPP
											for (unsigned int i = 0; i < fsm->imeimfsmstate.nodes.size(); i++)
												if (fsm->imeimfsmstate.nodes[i]->sref == fstAstp->srefFnxRefWdbeMFsmstate) {
													fstAstp->fnxRefWdbeMFsmstate = fsm->imeimfsmstate.nodes[i]->ref;
													break;
												};

											dbswdbe->tblwdbeamfsmstatestep->updateRec(fstAstp);
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

void JobWdbeIexDdd::leaveSgeImport(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeImport --- INSERT
};

uint JobWdbeIexDdd::enterSgeImperr(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IMPERR;

	// IP enterSgeImperr --- INSERT

	return retval;
};

void JobWdbeIexDdd::leaveSgeImperr(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeImperr --- INSERT
};

uint JobWdbeIexDdd::enterSgeReverse(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::IDLE;
	retval = nextIxVSgeSuccess;

	ImeitemIMUnit* unt = NULL;
	ImeitemIMBank* bnk = NULL;
	ImeitemIMCommand1* cmd1 = NULL;
	ImeitemIMError1* err1 = NULL;
	ImeitemIMModule* mdl = NULL;
	ImeitemIMVector1* vec1 = NULL;
	ImeitemIAMCommandInvpar1* cmdAipa1 = NULL;
	ImeitemIAMCommandRetpar1* cmdArpa1 = NULL;
	ImeitemIAMErrorPar1* errApar1 = NULL;
	ImeitemIMController* ctr = NULL;
	ImeitemIMGeneric* gen = NULL;
	ImeitemIMImbuf* imb = NULL;
	ImeitemIMPin* pin = NULL;
	ImeitemIMPort* prt = NULL;
	ImeitemIMProcess* prc = NULL;
	ImeitemIMSignal* sig = NULL;
	ImeitemIMVectoritem1* vit1 = NULL;
	ImeitemIAMPinPar* pinApar = NULL;
	ImeitemIAVKeylistKey* klsAkey = NULL;
	ImeitemIJMPinSref* pinJsrf = NULL;
	ImeitemIMCommand2* cmd2 = NULL;
	ImeitemIMError2* err2 = NULL;
	ImeitemIMFsm* fsm = NULL;
	ImeitemIMVariable* var = NULL;
	ImeitemIMVector2* vec2 = NULL;
	ImeitemIRMCommandMController* cmdRctr = NULL;
	ImeitemIAMCommandInvpar2* cmdAipa2 = NULL;
	ImeitemIAMCommandRetpar2* cmdArpa2 = NULL;
	ImeitemIAMErrorPar2* errApar2 = NULL;
	ImeitemIJAVKeylistKey* kakJkey = NULL;
	ImeitemIMFsmstate* fst = NULL;
	ImeitemIMVectoritem2* vit2 = NULL;
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

			for (unsigned int ix2 = 0; ix2 < mdl->imeimgeneric.nodes.size(); ix2++) {
				gen = mdl->imeimgeneric.nodes[ix2];
				if (gen->ref != 0) dbswdbe->tblwdbemgeneric->removeRecByRef(gen->ref);
			};

			for (unsigned int ix2 = 0; ix2 < mdl->imeimimbuf.nodes.size(); ix2++) {
				imb = mdl->imeimimbuf.nodes[ix2];
				if (imb->ref != 0) dbswdbe->tblwdbemimbuf->removeRecByRef(imb->ref);
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

				for (unsigned int ix3 = 0; ix3 < prc->imeimvariable.nodes.size(); ix3++) {
					var = prc->imeimvariable.nodes[ix3];
					if (var->ref != 0) dbswdbe->tblwdbemvariable->removeRecByRef(var->ref);
				};
			};

			for (unsigned int ix2 = 0; ix2 < mdl->imeimsignal.nodes.size(); ix2++) {
				sig = mdl->imeimsignal.nodes[ix2];
				if (sig->ref != 0) dbswdbe->tblwdbemsignal->removeRecByRef(sig->ref);
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

void JobWdbeIexDdd::leaveSgeReverse(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeReverse --- INSERT
};

uint JobWdbeIexDdd::enterSgeCollect(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::CLTDONE;
	retval = nextIxVSgeSuccess;

	ImeitemIMUnit* unt = NULL;
	ImeitemIMBank* bnk = NULL;
	ImeitemIMCommand1* cmd1 = NULL;
	ImeitemIMError1* err1 = NULL;
	ImeitemIMModule* mdl = NULL;
	ImeitemIMVector1* vec1 = NULL;
	ImeitemIAMCommandInvpar1* cmdAipa1 = NULL;
	ImeitemIAMCommandRetpar1* cmdArpa1 = NULL;
	ImeitemIAMErrorPar1* errApar1 = NULL;
	ImeitemICGeneric* genC = NULL;
	ImeitemICPin* pinC = NULL;
	ImeitemICPort* prtC = NULL;
	ImeitemICSignal* sigC = NULL;
	ImeitemIMController* ctr = NULL;
	ImeitemIMGeneric* gen = NULL;
	ImeitemIMImbuf* imb = NULL;
	ImeitemIMPin* pin = NULL;
	ImeitemIMPort* prt = NULL;
	ImeitemIMProcess* prc = NULL;
	ImeitemIMSignal* sig = NULL;
	ImeitemIMVectoritem1* vit1 = NULL;
	ImeitemIAMPinPar* pinApar = NULL;
	ImeitemIAVKeylistKey* klsAkey = NULL;
	ImeitemICVariable* varC = NULL;
	ImeitemIJMPinSref* pinJsrf = NULL;
	ImeitemIMCommand2* cmd2 = NULL;
	ImeitemIMError2* err2 = NULL;
	ImeitemIMFsm* fsm = NULL;
	ImeitemIMVariable* var = NULL;
	ImeitemIMVector2* vec2 = NULL;
	ImeitemIRMCommandMController* cmdRctr = NULL;
	ImeitemIAMCommandInvpar2* cmdAipa2 = NULL;
	ImeitemIAMCommandRetpar2* cmdArpa2 = NULL;
	ImeitemIAMErrorPar2* errApar2 = NULL;
	ImeitemICFsmstate* fstC = NULL;
	ImeitemIJAVKeylistKey* kakJkey = NULL;
	ImeitemIMFsmstate* fst = NULL;
	ImeitemIMVectoritem2* vit2 = NULL;
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

			for (unsigned int ix2 = 0; ix2 < mdl->imeicsignal.nodes.size(); ix2++) {
				sigC = mdl->imeicsignal.nodes[ix2];

				if (sigC->ref != 0) {
					sigC->iref = ix2+1;
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

				if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMCOMMAND2, ixWdbeVIop)) {
					dbswdbe->tblwdbemcommand->loadRefsByRetReu(VecWdbeVMCommandRefTbl::CTR, ctr->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) ctr->imeimcommand2.nodes.push_back(new ImeitemIMCommand2(dbswdbe, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < ctr->imeimcommand2.nodes.size(); ix3++) {
					cmd2 = ctr->imeimcommand2.nodes[ix3];

					if (cmd2->ref != 0) {
						cmd2->srefIvrRefWdbeMSignal = StubWdbe::getStubSigSref(dbswdbe, cmd2->ivrRefWdbeMSignal, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
						cmd2->srefRvrRefWdbeMSignal = StubWdbe::getStubSigSref(dbswdbe, cmd2->rvrRefWdbeMSignal, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
						cmd2->srefRerRefWdbeMSignal = StubWdbe::getStubSigSref(dbswdbe, cmd2->rerRefWdbeMSignal, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
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
						err2->srefTraRefWdbeMSignal = StubWdbe::getStubSigSref(dbswdbe, err2->traRefWdbeMSignal, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
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

			if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMIMBUF, ixWdbeVIop)) {
				dbswdbe->tblwdbemimbuf->loadRefsByMdl(mdl->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) mdl->imeimimbuf.nodes.push_back(new ImeitemIMImbuf(dbswdbe, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < mdl->imeimimbuf.nodes.size(); ix2++) {
				imb = mdl->imeimimbuf.nodes[ix2];

				if (imb->ref != 0) {
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

				for (unsigned int ix3 = 0; ix3 < prc->imeicvariable.nodes.size(); ix3++) {
					varC = prc->imeicvariable.nodes[ix3];

					if (varC->ref != 0) {
						varC->iref = ix3+1;
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

				if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMVARIABLE, ixWdbeVIop)) {
					dbswdbe->tblwdbemvariable->loadRefsByPrc(prc->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) prc->imeimvariable.nodes.push_back(new ImeitemIMVariable(dbswdbe, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < prc->imeimvariable.nodes.size(); ix3++) {
					var = prc->imeimvariable.nodes[ix3];

					if (var->ref != 0) {
						//var->irefRefWdbeCVariable: IREF
					};
				};
			};

			if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMSIGNAL, ixWdbeVIop)) {
				dbswdbe->tblwdbemsignal->loadRefsByMdl(mdl->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) mdl->imeimsignal.nodes.push_back(new ImeitemIMSignal(dbswdbe, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < mdl->imeimsignal.nodes.size(); ix2++) {
				sig = mdl->imeimsignal.nodes[ix2];

				if (sig->ref != 0) {
					//sig->irefRefWdbeCSignal: IREF
					//sig->srefMgeUref: STUB
					sig->srefDrvRefWdbeMPort = StubWdbe::getStubPrtSref(dbswdbe, sig->drvRefWdbeMPort, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
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

void JobWdbeIexDdd::leaveSgeCollect(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeCollect --- INSERT
};

uint JobWdbeIexDdd::enterSgeCltdone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::CLTDONE;

	// IP enterSgeCltdone --- INSERT

	return retval;
};

void JobWdbeIexDdd::leaveSgeCltdone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeCltdone --- INSERT
};

uint JobWdbeIexDdd::enterSgeExport(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	IexWdbeDdd::exportToFile(fullpath, xmlNotTxt, shorttags, imeimunit);

	return retval;
};

void JobWdbeIexDdd::leaveSgeExport(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeExport --- INSERT
};

uint JobWdbeIexDdd::enterSgeDone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void JobWdbeIexDdd::leaveSgeDone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeDone --- INSERT
};


