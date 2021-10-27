/**
	* \file JobWdbeIexIni.cpp
	* job handler for job JobWdbeIexIni (implementation)
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

#include "JobWdbeIexIni.h"

#include "JobWdbeIexIni_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

using namespace IexWdbeIni;

/******************************************************************************
 class JobWdbeIexIni
 ******************************************************************************/

JobWdbeIexIni::JobWdbeIexIni(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::JOBWDBEIEXINI, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	changeStage(dbswdbe, VecVSge::IDLE);

	// IP constructor.cust3 --- INSERT

};

JobWdbeIexIni::~JobWdbeIexIni() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void JobWdbeIexIni::reset(
			DbsWdbe* dbswdbe
		) {
	if (ixVSge != VecVSge::IDLE) changeStage(dbswdbe, VecVSge::IDLE);
};

void JobWdbeIexIni::parseFromFile(
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

void JobWdbeIexIni::import(
			DbsWdbe* dbswdbe
		) {
	if (ixVSge == VecVSge::PRSDONE) changeStage(dbswdbe, VecVSge::IMPORT);
};

void JobWdbeIexIni::reverse(
			DbsWdbe* dbswdbe
		) {
	if (ixVSge == VecVSge::IMPERR) changeStage(dbswdbe, VecVSge::REVERSE);
};

void JobWdbeIexIni::collect(
			DbsWdbe* dbswdbe
			, const map<uint,uint>& _icsWdbeVIop
		) {
	if (ixVSge == VecVSge::IDLE) {
		icsWdbeVIop = _icsWdbeVIop;
		changeStage(dbswdbe, VecVSge::COLLECT);
	};
};

void JobWdbeIexIni::exportToFile(
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

void JobWdbeIexIni::handleRequest(
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

void JobWdbeIexIni::changeStage(
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

string JobWdbeIexIni::getSquawk(
			DbsWdbe* dbswdbe
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::PARSE) || (ixVSge == VecVSge::PRSDONE) || (ixVSge == VecVSge::IMPORT) || (ixVSge == VecVSge::REVERSE) || (ixVSge == VecVSge::COLLECT) || (ixVSge == VecVSge::CLTDONE) || (ixVSge == VecVSge::EXPORT) ) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing initialization data";
			else if (ixVSge == VecVSge::PRSDONE) retval = "initialization data parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing initialization data (" + to_string(impcnt) + " records added)";
			else if (ixVSge == VecVSge::REVERSE) retval = "reversing initialization data import";
			else if (ixVSge == VecVSge::COLLECT) retval = "collecting initialization data for export";
			else if (ixVSge == VecVSge::CLTDONE) retval = "initialization data collected for export";
			else if (ixVSge == VecVSge::EXPORT) retval = "exporting initialization data";
		};

	} else if ( (ixVSge == VecVSge::PRSERR) || (ixVSge == VecVSge::IMPERR) ) {
		retval = lasterror;

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

uint JobWdbeIexIni::enterSgeIdle(
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

	imeiavcontrolpar.clear();
	imeiavkeylistkey1.clear();
	imeiavvaluelistval.clear();
	imeimcoreproject.clear();
	imeimfamily.clear();
	imeimfile1.clear();
	imeimlibrary.clear();
	imeimmachine.clear();
	imeimmodule.clear();
	imeimunit.clear();
	imeimusergroup.clear();

	return retval;
};

void JobWdbeIexIni::leaveSgeIdle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWdbeIexIni::enterSgeParse(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::PRSDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::PRSERR;

	try {
		IexWdbeIni::parseFromFile(fullpath, xmlNotTxt, rectpath, imeiavcontrolpar, imeiavkeylistkey1, imeiavvaluelistval, imeimcoreproject, imeimfamily, imeimfile1, imeimlibrary, imeimmachine, imeimmodule, imeimunit, imeimusergroup);

	} catch (SbeException& e) {
		if (e.ix == SbeException::PATHNF) e.vals["path"] = "<hidden>";
		lasterror = e.getSquawk(VecWdbeVError::getIx, VecWdbeVError::getTitle, ixWdbeVLocale);

		retval = nextIxVSgeFailure;
	};

	return retval;
};

void JobWdbeIexIni::leaveSgeParse(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeParse --- INSERT
};

uint JobWdbeIexIni::enterSgePrserr(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::PRSERR;

	// IP enterSgePrserr --- INSERT

	return retval;
};

void JobWdbeIexIni::leaveSgePrserr(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgePrserr --- INSERT
};

uint JobWdbeIexIni::enterSgePrsdone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::PRSDONE;

	// IP enterSgePrsdone --- INSERT

	return retval;
};

void JobWdbeIexIni::leaveSgePrsdone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgePrsdone --- INSERT
};

uint JobWdbeIexIni::enterSgeImport(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IMPERR;

	ImeitemIAVControlPar* ctlApar = NULL;
	ImeitemIAVKeylistKey1* klsAkey1 = NULL;
	ImeitemIAVValuelistVal* vlsAval = NULL;
	ImeitemIMCoreproject* cpr = NULL;
	ImeitemIMFamily* fam = NULL;
	ImeitemIMFile1* fil1 = NULL;
	ImeitemIMLibrary* lib = NULL;
	ImeitemIMMachine* mch = NULL;
	ImeitemIMModule* mdl = NULL;
	ImeitemIMUnit* unt = NULL;
	ImeitemIMUsergroup* usg = NULL;
	ImeitemIAMLibraryMakefile* libAmkf = NULL;
	ImeitemIAMMachineMakefile* mchAmkf = NULL;
	ImeitemIAMMachinePar* mchApar = NULL;
	ImeitemIAMModulePar* mdlApar = NULL;
	ImeitemIAMUsergroupAccess* usgAacc = NULL;
	ImeitemIAVKeylistKey3* klsAkey3 = NULL;
	ImeitemICGeneric* genC = NULL;
	ImeitemICPort* prtC = NULL;
	ImeitemICVariable* varC = NULL;
	ImeitemIJAVKeylistKey1* kakJkey1 = NULL;
	ImeitemIMBank* bnk = NULL;
	ImeitemIMController* ctr = NULL;
	ImeitemIMCoreversion* cvr = NULL;
	ImeitemIMFile2* fil2 = NULL;
	ImeitemIMGeneric* gen = NULL;
	ImeitemIMPeripheral* pph = NULL;
	ImeitemIMPort* prt = NULL;
	ImeitemIMUser* usr = NULL;
	ImeitemIMVariable* var = NULL;
	ImeitemIRMCoreprojectMPerson* cprRprs = NULL;
	ImeitemIRMModuleMModule* mdlRmdl = NULL;
	ImeitemIAMUserAccess* usrAacc = NULL;
	ImeitemIAVKeylistKey2* klsAkey2 = NULL;
	ImeitemIJAVKeylistKey3* kakJkey3 = NULL;
	ImeitemIJMCoreversionState* cvrJste = NULL;
	ImeitemIJMUserState* usrJste = NULL;
	ImeitemIMCommand* cmd = NULL;
	ImeitemIMError* err = NULL;
	ImeitemIMPerson* prs = NULL;
	ImeitemIMPin* pin = NULL;
	ImeitemIMVector* vec = NULL;
	ImeitemIAMCommandInvpar* cmdAipa = NULL;
	ImeitemIAMCommandRetpar* cmdArpa = NULL;
	ImeitemIAMErrorPar* errApar = NULL;
	ImeitemIJAVKeylistKey2* kakJkey2 = NULL;
	ImeitemIJMPersonLastname* prsJlnm = NULL;
	ImeitemIJMPinSref* pinJsrf = NULL;
	ImeitemIMVectoritem* vit = NULL;

	set<ubigint> irefs0, irefs1;

	uint num0, num1, num2, num3;

	// IP enterSgeImport.prep --- IBEGIN
	WdbeRMUserMUsergroup uru;

	map<string,ubigint> refsMchs; // by hsref

	ImeitemIMModule* mdl2 = NULL;

	uint refNum;

	vector<string> ss;
	// IP enterSgeImport.prep --- IEND

	try {
		// IP enterSgeImport.traverse --- RBEGIN

		// -- ImeIAVKeylistKey1
		num0 = 1;

		for (unsigned int ix0 = 0; ix0 < imeiavkeylistkey1.nodes.size(); ix0++) {
			klsAkey1 = imeiavkeylistkey1.nodes[ix0];

			klsAkey1->klsIxWdbeVKeylist = VecWdbeVKeylist::getIx(klsAkey1->srefKlsIxWdbeVKeylist);
			if (klsAkey1->klsIxWdbeVKeylist == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",klsAkey1->srefKlsIxWdbeVKeylist}, {"iel","srefKlsIxWdbeVKeylist"}, {"lineno",to_string(klsAkey1->lineno)}});
			//klsAkey1->klsNum: CUST
			klsAkey1->klsNum = num0++; // TBD
			klsAkey1->x1IxWdbeVMaintable = VecWdbeVMaintable::VOID;
			klsAkey1->Fixed = true;
			//klsAkey1->sref: TBL
			//klsAkey1->Avail: TBL
			//klsAkey1->Implied: TBL
			//klsAkey1->refJ: SUB
			//klsAkey1->Title: TBL
			//klsAkey1->Comment: TBL

			dbswdbe->tblwdbeavkeylistkey->insertRec(klsAkey1);
			impcnt++;

			if (((klsAkey1->Title != "") || (klsAkey1->Comment != "")) && klsAkey1->imeijavkeylistkey1.nodes.empty()) {
				kakJkey1 = new ImeitemIJAVKeylistKey1();
				klsAkey1->imeijavkeylistkey1.nodes.push_back(kakJkey1);

				kakJkey1->refWdbeAVKeylistKey = klsAkey1->ref;
				kakJkey1->Title = klsAkey1->Title;
				kakJkey1->Comment = klsAkey1->Comment;
			};

			for (unsigned int ix1 = 0; ix1 < klsAkey1->imeijavkeylistkey1.nodes.size(); ix1++) {
				kakJkey1 = klsAkey1->imeijavkeylistkey1.nodes[ix1];

				kakJkey1->refWdbeAVKeylistKey = klsAkey1->ref;
				if (kakJkey1->srefX1IxWdbeVLocale == "") kakJkey1->srefX1IxWdbeVLocale = "enus";
				kakJkey1->x1IxWdbeVLocale = VecWdbeVLocale::getIx(kakJkey1->srefX1IxWdbeVLocale);
				if (kakJkey1->x1IxWdbeVLocale == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",kakJkey1->srefX1IxWdbeVLocale}, {"iel","srefX1IxWdbeVLocale"}, {"lineno",to_string(kakJkey1->lineno)}});
				//kakJkey1->Title: TBL
				//kakJkey1->Comment: TBL

				dbswdbe->tblwdbejavkeylistkey->insertRec(kakJkey1);
				impcnt++;

				if (ix1 == 0) {
					klsAkey1->refJ = kakJkey1->ref;
					klsAkey1->Title = kakJkey1->Title;
					klsAkey1->Comment = kakJkey1->Comment;
					dbswdbe->tblwdbeavkeylistkey->updateRec(klsAkey1);
				};
			};
		};

		// -- ImeIAVValuelistVal
		num0 = 1;

		for (unsigned int ix0 = 0; ix0 < imeiavvaluelistval.nodes.size(); ix0++) {
			vlsAval = imeiavvaluelistval.nodes[ix0];

			vlsAval->vlsIxWdbeVValuelist = VecWdbeVValuelist::getIx(vlsAval->srefVlsIxWdbeVValuelist);
			if (vlsAval->vlsIxWdbeVValuelist == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",vlsAval->srefVlsIxWdbeVValuelist}, {"iel","srefVlsIxWdbeVValuelist"}, {"lineno",to_string(vlsAval->lineno)}});
			//vlsAval->vlsNum: CUST
			vlsAval->vlsNum = num0++; // TBD
			vlsAval->x1IxWdbeVLocale = VecWdbeVLocale::getIx(vlsAval->srefX1IxWdbeVLocale);
			if (vlsAval->x1IxWdbeVLocale == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",vlsAval->srefX1IxWdbeVLocale}, {"iel","srefX1IxWdbeVLocale"}, {"lineno",to_string(vlsAval->lineno)}});
			//vlsAval->Val: TBL

			dbswdbe->tblwdbeavvaluelistval->insertRec(vlsAval);
			impcnt++;
		};

		// -- ImeIAVControlPar
		for (unsigned int ix0 = 0; ix0 < imeiavcontrolpar.nodes.size(); ix0++) {
			ctlApar = imeiavcontrolpar.nodes[ix0];

			ctlApar->ixWdbeVControl = VecWdbeVControl::getIx(ctlApar->srefIxWdbeVControl);
			if (ctlApar->ixWdbeVControl == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",ctlApar->srefIxWdbeVControl}, {"iel","srefIxWdbeVControl"}, {"lineno",to_string(ctlApar->lineno)}});
			//ctlApar->Par: TBL
			//ctlApar->Val: TBL

			dbswdbe->tblwdbeavcontrolpar->insertRec(ctlApar);
			impcnt++;
		};

		// -- ImeIMUsergroup
		for (unsigned int ix0 = 0; ix0 < imeimusergroup.nodes.size(); ix0++) {
			usg = imeimusergroup.nodes[ix0];

			//usg->sref: TBL
			//usg->Comment: TBL

			dbswdbe->tblwdbemusergroup->insertRec(usg);
			impcnt++;

			for (unsigned int ix1 = 0; ix1 < usg->imeiamusergroupaccess.nodes.size(); ix1++) {
				usgAacc = usg->imeiamusergroupaccess.nodes[ix1];

				usgAacc->refWdbeMUsergroup = usg->ref;
				usgAacc->x1IxWdbeVFeatgroup = VecWdbeVFeatgroup::getIx(usgAacc->srefX1IxWdbeVFeatgroup);
				if (usgAacc->x1IxWdbeVFeatgroup == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",usgAacc->srefX1IxWdbeVFeatgroup}, {"iel","srefX1IxWdbeVFeatgroup"}, {"lineno",to_string(usgAacc->lineno)}});
				//usgAacc->x2FeaSrefUix: TBL
				usgAacc->ixWdbeWAccess = VecWdbeWAccess::getIx(usgAacc->srefsIxWdbeWAccess);

				dbswdbe->tblwdbeamusergroupaccess->insertRec(usgAacc);
				impcnt++;
			};

			for (unsigned int ix1 = 0; ix1 < usg->imeimuser.nodes.size(); ix1++) {
				usr = usg->imeimuser.nodes[ix1];

				//usr->refRUsergroup: IMPPP
				usr->refWdbeMUsergroup = usg->ref;
				//usr->refWdbeMPerson: IMPPP
				//usr->sref: TBL
				//usr->refJState: SUB
				if (usr->srefIxVState != "") {
					usr->ixVState = VecWdbeVMUserState::getIx(usr->srefIxVState);
					if (usr->ixVState == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",usr->srefIxVState}, {"iel","srefIxVState"}, {"lineno",to_string(usr->lineno)}});
				};
				usr->ixWdbeVLocale = VecWdbeVLocale::getIx(usr->srefIxWdbeVLocale);
				if (usr->ixWdbeVLocale == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",usr->srefIxWdbeVLocale}, {"iel","srefIxWdbeVLocale"}, {"lineno",to_string(usr->lineno)}});
				usr->ixWdbeVUserlevel = VecWdbeVUserlevel::getIx(usr->srefIxWdbeVUserlevel);
				if (usr->ixWdbeVUserlevel == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",usr->srefIxWdbeVUserlevel}, {"iel","srefIxWdbeVUserlevel"}, {"lineno",to_string(usr->lineno)}});
				//usr->Password: TBL
				//usr->Fullkey: TBL
				//usr->Comment: TBL

				dbswdbe->tblwdbemuser->insertRec(usr);
				impcnt++;

				if (((usr->srefIxVState != "")) && usr->imeijmuserstate.nodes.empty()) {
					usrJste = new ImeitemIJMUserState();
					usr->imeijmuserstate.nodes.push_back(usrJste);

					usrJste->refWdbeMUser = usr->ref;
					usrJste->srefIxVState = usr->srefIxVState;
				};

				for (unsigned int ix2 = 0; ix2 < usr->imeijmuserstate.nodes.size(); ix2++) {
					usrJste = usr->imeijmuserstate.nodes[ix2];

					usrJste->refWdbeMUser = usr->ref;
					usrJste->x1Start = Ftm::invstamp("&now;");
					usrJste->ixVState = VecWdbeVMUserState::getIx(usrJste->srefIxVState);
					if (usrJste->ixVState == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",usrJste->srefIxVState}, {"iel","srefIxVState"}, {"lineno",to_string(usrJste->lineno)}});

					dbswdbe->tblwdbejmuserstate->insertRec(usrJste);
					impcnt++;

					if (ix2 == 0) {
						usr->refJState = usrJste->ref;
						usr->ixVState = usrJste->ixVState;
						dbswdbe->tblwdbemuser->updateRec(usr);
					};
				};

				for (unsigned int ix2 = 0; ix2 < usr->imeimperson.nodes.size(); ix2++) {
					prs = usr->imeimperson.nodes[ix2];

					prs->ixWDerivate = VecWdbeWMPersonDerivate::USR;
					prs->ixVSex = VecWdbeVMPersonSex::getIx(prs->srefIxVSex);
					if (prs->ixVSex == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",prs->srefIxVSex}, {"iel","srefIxVSex"}, {"lineno",to_string(prs->lineno)}});
					//prs->Title: TBL
					//prs->Firstname: TBL
					//prs->refJLastname: SUB
					//prs->Lastname: TBL

					dbswdbe->tblwdbemperson->insertRec(prs);
					impcnt++;

					if (((prs->Lastname != "")) && prs->imeijmpersonlastname.nodes.empty()) {
						prsJlnm = new ImeitemIJMPersonLastname();
						prs->imeijmpersonlastname.nodes.push_back(prsJlnm);

						prsJlnm->refWdbeMPerson = prs->ref;
						prsJlnm->Lastname = prs->Lastname;
					};

					if (ix2 == 0) {
						usr->refWdbeMPerson = prs->ref;
						dbswdbe->tblwdbemuser->updateRec(usr);
					};

					for (unsigned int ix3 = 0; ix3 < prs->imeijmpersonlastname.nodes.size(); ix3++) {
						prsJlnm = prs->imeijmpersonlastname.nodes[ix3];

						prsJlnm->refWdbeMPerson = prs->ref;
						prsJlnm->x1Startd = Ftm::invdate("&today;");
						//prsJlnm->Lastname: TBL

						dbswdbe->tblwdbejmpersonlastname->insertRec(prsJlnm);
						impcnt++;

						if (ix3 == 0) {
							prs->refJLastname = prsJlnm->ref;
							prs->Lastname = prsJlnm->Lastname;
							dbswdbe->tblwdbemperson->updateRec(prs);
						};
					};
				};

				for (unsigned int ix2 = 0; ix2 < usr->imeiamuseraccess.nodes.size(); ix2++) {
					usrAacc = usr->imeiamuseraccess.nodes[ix2];

					usrAacc->refWdbeMUser = usr->ref;
					usrAacc->x1IxWdbeVFeatgroup = VecWdbeVFeatgroup::getIx(usrAacc->srefX1IxWdbeVFeatgroup);
					if (usrAacc->x1IxWdbeVFeatgroup == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",usrAacc->srefX1IxWdbeVFeatgroup}, {"iel","srefX1IxWdbeVFeatgroup"}, {"lineno",to_string(usrAacc->lineno)}});
					//usrAacc->x2FeaSrefUix: TBL
					usrAacc->ixWdbeWAccess = VecWdbeWAccess::getIx(usrAacc->srefsIxWdbeWAccess);

					dbswdbe->tblwdbeamuseraccess->insertRec(usrAacc);
					impcnt++;
				};

				uru.refWdbeMUser = usr->ref;
				uru.refWdbeMUsergroup = usg->ref;
				uru.ixWdbeVUserlevel = usr->ixWdbeVUserlevel;
				dbswdbe->tblwdbermusermusergroup->insertRec(&uru);

				usr->refRUsergroup = uru.ref;
				usr->refWdbeMUsergroup = usg->ref;
				dbswdbe->tblwdbemuser->updateRec(usr);
			};
		};

		// -- ImeIMFile1
		for (unsigned int ix0 = 0; ix0 < imeimfile1.nodes.size(); ix0++) {
			fil1 = imeimfile1.nodes[ix0];

			fil1->refIxVTbl = VecWdbeVMFileRefTbl::VOID;
			//fil1->osrefKContent: TBL
			//fil1->Filename: TBL
			//fil1->srefKMimetype: TBL
			//fil1->Comment: TBL

			dbswdbe->tblwdbemfile->insertRec(fil1);
			impcnt++;
		};

		// -- ImeIMMachine
		for (unsigned int ix0 = 0; ix0 < imeimmachine.nodes.size(); ix0++) {
			mch = imeimmachine.nodes[ix0];

			//mch->supRefWdbeMMachine: IMPPP
			//mch->sref: TBL
			//mch->cchRefWdbeMMachine: IMPPP
			//mch->Comment: TBL

			dbswdbe->tblwdbemmachine->insertRec(mch);
			impcnt++;

			if (mch->hsrefSupRefWdbeMMachine == "") refsMchs[mch->sref] = mch->ref;
			else refsMchs[mch->hsrefSupRefWdbeMMachine + ";" + mch->sref] = mch->ref;

			for (unsigned int ix1 = 0; ix1 < mch->imeiammachinemakefile.nodes.size(); ix1++) {
				mchAmkf = mch->imeiammachinemakefile.nodes[ix1];

				mchAmkf->refWdbeMMachine = mch->ref;
				//mchAmkf->x1SrefKTag: TBL
				//mchAmkf->Val: TBL

				dbswdbe->tblwdbeammachinemakefile->insertRec(mchAmkf);
				impcnt++;
			};

			for (unsigned int ix1 = 0; ix1 < mch->imeiammachinepar.nodes.size(); ix1++) {
				mchApar = mch->imeiammachinepar.nodes[ix1];

				mchApar->refWdbeMMachine = mch->ref;
				//mchApar->x1SrefKKey: TBL
				//mchApar->Val: TBL

				dbswdbe->tblwdbeammachinepar->insertRec(mchApar);
				impcnt++;
			};
		};

		// -- ImeIMLibrary
		for (unsigned int ix0 = 0; ix0 < imeimlibrary.nodes.size(); ix0++) {
			lib = imeimlibrary.nodes[ix0];

			//lib->sref: TBL
			//lib->Title: TBL
			//lib->Version: TBL
			//lib->depSrefsWdbeMLibrary: TBL
			//lib->Comment: TBL

			dbswdbe->tblwdbemlibrary->insertRec(lib);
			impcnt++;

			for (unsigned int ix1 = 0; ix1 < lib->imeiamlibrarymakefile.nodes.size(); ix1++) {
				libAmkf = lib->imeiamlibrarymakefile.nodes[ix1];

				libAmkf->refWdbeMLibrary = lib->ref;
				//libAmkf->x1RefWdbeMMachine: PREVIMP
				if (libAmkf->hsrefX1RefWdbeMMachine != "") {
					auto it = refsMchs.find(libAmkf->hsrefX1RefWdbeMMachine);
					if (it != refsMchs.end()) libAmkf->x1RefWdbeMMachine = it->second;
					else throw SbeException(SbeException::IEX_TSREF, {{"tsref",libAmkf->hsrefX1RefWdbeMMachine}, {"iel","hsrefX1RefWdbeMMachine"}, {"lineno",to_string(libAmkf->lineno)}});
				};
				//libAmkf->x2SrefKTag: TBL
				//libAmkf->Val: TBL

				dbswdbe->tblwdbeamlibrarymakefile->insertRec(libAmkf);
				impcnt++;
			};
		};

		// -- ImeIMFamily
		irefs0.clear();

		for (unsigned int ix0 = 0; ix0 < imeimfamily.nodes.size(); ix0++) {
			fam = imeimfamily.nodes[ix0];

			if (irefs0.find(fam->iref) != irefs0.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(fam->iref)}, {"ime","ImeIMFamily"}, {"lineno",to_string(fam->lineno)}});
			irefs0.insert(fam->iref);
			//fam->srefWdbeKVendor: TBL
			//fam->Title: TBL
			//fam->Comment: TBL

			dbswdbe->tblwdbemfamily->insertRec(fam);
			impcnt++;
		};

		// -- ImeIMUnit
		for (unsigned int ix0 = 0; ix0 < imeimunit.nodes.size(); ix0++) {
			unt = imeimunit.nodes[ix0];

			unt->ixVBasetype = VecWdbeVMUnitBasetype::getIx(unt->srefIxVBasetype);
			if (unt->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",unt->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(unt->lineno)}});
			unt->refIxVTbl = VecWdbeVMUnitRefTbl::getIx(unt->srefRefIxVTbl);
			if (unt->refIxVTbl == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",unt->srefRefIxVTbl}, {"iel","srefRefIxVTbl"}, {"lineno",to_string(unt->lineno)}});
			//unt->refUref: PREVIMP
			if (unt->refIxVTbl == VecWdbeVMUnitRefTbl::FAM) {
				for (unsigned int i = 0; i < imeimfamily.nodes.size(); i++)
					if (imeimfamily.nodes[i]->iref == unt->irefRefUref) {
						unt->refUref = imeimfamily.nodes[i]->ref;
						break;
					}; 
				if (unt->refUref == 0) throw SbeException(SbeException::IEX_IREF, {{"iref",to_string(unt->irefRefUref)}, {"iel","irefRefUref"}, {"lineno",to_string(unt->lineno)}});
			};
			//unt->sref: TBL
			//unt->Title: TBL
			//unt->srefKPackage: TBL
			//unt->Comment: TBL

			dbswdbe->tblwdbemunit->insertRec(unt);
			impcnt++;

			for (unsigned int ix1 = 0; ix1 < unt->imeimperipheral.nodes.size(); ix1++) {
				pph = unt->imeimperipheral.nodes[ix1];

				pph->refWdbeMUnit = unt->ref;
				//pph->sref: TBL
				//pph->Comment: TBL

				dbswdbe->tblwdbemperipheral->insertRec(pph);
				impcnt++;

				num2 = 1;

				for (unsigned int ix2 = 0; ix2 < pph->imeiavkeylistkey2.nodes.size(); ix2++) {
					klsAkey2 = pph->imeiavkeylistkey2.nodes[ix2];

					klsAkey2->klsIxWdbeVKeylist = VecWdbeVKeylist::KLSTWDBEKAMPERIPHERALPARKEY;
					klsAkey2->klsNum = num2++;
					klsAkey2->x1IxWdbeVMaintable = VecWdbeVMaintable::TBLWDBEMPERIPHERAL;
					klsAkey2->x1Uref = pph->ref;
					klsAkey2->Fixed = true;
					//klsAkey2->sref: TBL
					//klsAkey2->refJ: SUB
					//klsAkey2->Title: TBL
					//klsAkey2->Comment: TBL

					dbswdbe->tblwdbeavkeylistkey->insertRec(klsAkey2);
					impcnt++;

					if (((klsAkey2->Title != "") || (klsAkey2->Comment != "")) && klsAkey2->imeijavkeylistkey2.nodes.empty()) {
						kakJkey2 = new ImeitemIJAVKeylistKey2();
						klsAkey2->imeijavkeylistkey2.nodes.push_back(kakJkey2);

						kakJkey2->refWdbeAVKeylistKey = klsAkey2->ref;
						kakJkey2->Title = klsAkey2->Title;
						kakJkey2->Comment = klsAkey2->Comment;
					};

					for (unsigned int ix3 = 0; ix3 < klsAkey2->imeijavkeylistkey2.nodes.size(); ix3++) {
						kakJkey2 = klsAkey2->imeijavkeylistkey2.nodes[ix3];

						kakJkey2->refWdbeAVKeylistKey = klsAkey2->ref;
						kakJkey2->x1IxWdbeVLocale = VecWdbeVLocale::ENUS;
						//kakJkey2->Title: TBL
						//kakJkey2->Comment: TBL

						dbswdbe->tblwdbejavkeylistkey->insertRec(kakJkey2);
						impcnt++;

						if (ix3 == 0) {
							klsAkey2->refJ = kakJkey2->ref;
							klsAkey2->Title = kakJkey2->Title;
							klsAkey2->Comment = kakJkey2->Comment;
							dbswdbe->tblwdbeavkeylistkey->updateRec(klsAkey2);
						};
					};
				};
			};

			for (unsigned int ix1 = 0; ix1 < unt->imeimbank.nodes.size(); ix1++) {
				bnk = unt->imeimbank.nodes[ix1];

				bnk->refWdbeMUnit = unt->ref;
				//bnk->sref: TBL

				dbswdbe->tblwdbembank->insertRec(bnk);
				impcnt++;

				for (unsigned int ix2 = 0; ix2 < bnk->imeimpin.nodes.size(); ix2++) {
					pin = bnk->imeimpin.nodes[ix2];

					pin->refWdbeMBank = bnk->ref;
					//pin->refJSref: SUB
					//pin->sref: TBL
					//pin->Location: TBL

					dbswdbe->tblwdbempin->insertRec(pin);
					impcnt++;

					if (((pin->sref != "")) && pin->imeijmpinsref.nodes.empty()) {
						pinJsrf = new ImeitemIJMPinSref();
						pin->imeijmpinsref.nodes.push_back(pinJsrf);

						pinJsrf->refWdbeMPin = pin->ref;
						pinJsrf->sref = pin->sref;
					};

					for (unsigned int ix3 = 0; ix3 < pin->imeijmpinsref.nodes.size(); ix3++) {
						pinJsrf = pin->imeijmpinsref.nodes[ix3];

						pinJsrf->refWdbeMPin = pin->ref;
						//pinJsrf->x1RefWdbeMPeripheral: PREVIMP
						if (pinJsrf->srefX1RefWdbeMPeripheral != "") {
							for (unsigned int i = 0; i < unt->imeimperipheral.nodes.size(); i++)
								if (unt->imeimperipheral.nodes[i]->sref == pinJsrf->srefX1RefWdbeMPeripheral) {
									pinJsrf->x1RefWdbeMPeripheral = unt->imeimperipheral.nodes[i]->ref;
									break;
								};
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
				};
			};
		};

		// -- ImeIMModule
		for (unsigned int ix0 = 0; ix0 < imeimmodule.nodes.size(); ix0++) {
			mdl = imeimmodule.nodes[ix0];

			mdl->ixVBasetype = VecWdbeVMModuleBasetype::getIx(mdl->srefIxVBasetype);
			if (mdl->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",mdl->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(mdl->lineno)}});
			mdl->hkIxVTbl = VecWdbeVMModuleHkTbl::VOID;
			//mdl->supRefWdbeMModule: IMPPP
			//mdl->tplRefWdbeMModule: IMPPP
			//mdl->refWdbeMController: SUB
			//mdl->sref: TBL
			//mdl->srefWdbeKVendor: TBL
			//mdl->Srefrule: TBL
			//mdl->Comment: TBL

			dbswdbe->tblwdbemmodule->insertRec(mdl);
			impcnt++;

			for (unsigned int ix1 = 0; ix1 < mdl->imeimcontroller.nodes.size(); ix1++) {
				ctr = mdl->imeimcontroller.nodes[ix1];

				ctr->refWdbeMModule = mdl->ref;

				dbswdbe->tblwdbemcontroller->insertRec(ctr);
				impcnt++;

				for (unsigned int ix2 = 0; ix2 < ctr->imeimvector.nodes.size(); ix2++) {
					vec = ctr->imeimvector.nodes[ix2];

					vec->ixVBasetype = VecWdbeVMVectorBasetype::getIx(vec->srefIxVBasetype);
					if (vec->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",vec->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(vec->lineno)}});
					vec->hkIxVTbl = VecWdbeVMVectorHkTbl::CTR;
					vec->hkUref = ctr->ref;
					//vec->sref: TBL
					//vec->srefsKOption: TBL

					dbswdbe->tblwdbemvector->insertRec(vec);
					impcnt++;

					if (vec->ixVBasetype == VecWdbeVMVectorBasetype::TIXLIN) num3 = 0;
					else num3 = 1;

					for (unsigned int ix3 = 0; ix3 < vec->imeimvectoritem.nodes.size(); ix3++) {
						vit = vec->imeimvectoritem.nodes[ix3];

						vit->vecRefWdbeMVector = vec->ref;
						//vit->vecNum: CUST
						vit->vecNum = num3;
						if (vec->ixVBasetype == VecWdbeVMVectorBasetype::TIXOR) num3 *= 2;
						else num3++;
						//vit->sref: TBL
						//vit->Title: TBL
						//vit->Comment: TBL

						dbswdbe->tblwdbemvectoritem->insertRec(vit);
						impcnt++;
					};
				};

				refNum = 0;

				for (unsigned int ix2 = 0; ix2 < ctr->imeimcommand.nodes.size(); ix2++) {
					cmd = ctr->imeimcommand.nodes[ix2];

					cmd->refIxVTbl = VecWdbeVMCommandRefTbl::CTR;
					cmd->refUref = ctr->ref;
					//cmd->refNum: TBL
					if (cmd->refNum < refNum) cmd->refNum = refNum;
					refNum = cmd->refNum + 1;
					//cmd->sref: TBL
					cmd->ixVRettype = VecWdbeVMCommandRettype::getIx(cmd->srefIxVRettype);
					if (cmd->ixVRettype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",cmd->srefIxVRettype}, {"iel","srefIxVRettype"}, {"lineno",to_string(cmd->lineno)}});
					//cmd->Comment: TBL

					dbswdbe->tblwdbemcommand->insertRec(cmd);
					impcnt++;

					num3 = 1;

					for (unsigned int ix3 = 0; ix3 < cmd->imeiamcommandinvpar.nodes.size(); ix3++) {
						cmdAipa = cmd->imeiamcommandinvpar.nodes[ix3];

						cmdAipa->cmdRefWdbeMCommand = cmd->ref;
						cmdAipa->cmdNum = num3++;
						//cmdAipa->sref: TBL
						cmdAipa->ixWdbeVPartype = VecWdbeVPartype::getIx(cmdAipa->srefIxWdbeVPartype);
						if (cmdAipa->ixWdbeVPartype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",cmdAipa->srefIxWdbeVPartype}, {"iel","srefIxWdbeVPartype"}, {"lineno",to_string(cmdAipa->lineno)}});
						//cmdAipa->refWdbeMVector: PREVIMP
						if (cmdAipa->srefRefWdbeMVector != "") {
							for (unsigned int i = 0; i < ctr->imeimvector.nodes.size(); i++)
								if (ctr->imeimvector.nodes[i]->sref == cmdAipa->srefRefWdbeMVector) {
									cmdAipa->refWdbeMVector = ctr->imeimvector.nodes[i]->ref;
									break;
								};
							if (cmdAipa->refWdbeMVector == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",cmdAipa->srefRefWdbeMVector}, {"iel","srefRefWdbeMVector"}, {"lineno",to_string(cmdAipa->lineno)}});
						};
						//cmdAipa->Length: TBL
						//cmdAipa->Defval: TBL
						//cmdAipa->refWdbeMVectoritem: CUSTSQL
						if ((cmdAipa->refWdbeMVector != 0) && (cmdAipa->srefRefWdbeMVectoritem != "")) {
							dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMVectoritem WHERE vecRefWdbeMVector = " + to_string(cmdAipa->refWdbeMVector) + " AND sref = '" + cmdAipa->srefRefWdbeMVectoritem + "'", cmdAipa->refWdbeMVectoritem);
							if (cmdAipa->refWdbeMVectoritem == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",cmdAipa->srefRefWdbeMVectoritem}, {"iel","srefRefWdbeMVectoritem"}, {"lineno",to_string(cmdAipa->lineno)}});
						};
						//cmdAipa->Comment: TBL

						dbswdbe->tblwdbeamcommandinvpar->insertRec(cmdAipa);
						impcnt++;
					};

					num3 = 1;

					for (unsigned int ix3 = 0; ix3 < cmd->imeiamcommandretpar.nodes.size(); ix3++) {
						cmdArpa = cmd->imeiamcommandretpar.nodes[ix3];

						cmdArpa->cmdRefWdbeMCommand = cmd->ref;
						cmdArpa->cmdNum = num3++;
						//cmdArpa->sref: TBL
						cmdArpa->ixWdbeVPartype = VecWdbeVPartype::getIx(cmdArpa->srefIxWdbeVPartype);
						if (cmdArpa->ixWdbeVPartype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",cmdArpa->srefIxWdbeVPartype}, {"iel","srefIxWdbeVPartype"}, {"lineno",to_string(cmdArpa->lineno)}});
						//cmdArpa->refWdbeMVector: PREVIMP
						if (cmdArpa->srefRefWdbeMVector != "") {
							for (unsigned int i = 0; i < ctr->imeimvector.nodes.size(); i++)
								if (ctr->imeimvector.nodes[i]->sref == cmdArpa->srefRefWdbeMVector) {
									cmdArpa->refWdbeMVector = ctr->imeimvector.nodes[i]->ref;
									break;
								};
							if (cmdArpa->refWdbeMVector == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",cmdArpa->srefRefWdbeMVector}, {"iel","srefRefWdbeMVector"}, {"lineno",to_string(cmdArpa->lineno)}});
						};
						//cmdArpa->Length: TBL
						//cmdArpa->Comment: TBL

						dbswdbe->tblwdbeamcommandretpar->insertRec(cmdArpa);
						impcnt++;
					};
				};

				refNum = 0;

				for (unsigned int ix2 = 0; ix2 < ctr->imeimerror.nodes.size(); ix2++) {
					err = ctr->imeimerror.nodes[ix2];

					err->refIxVTbl = VecWdbeVMErrorRefTbl::CTR;
					err->refUref = ctr->ref;
					//err->refNum: TBL
					if (err->refNum < refNum) err->refNum = refNum;
					refNum = err->refNum + 1;
					//err->sref: TBL
					//err->Comment: TBL

					dbswdbe->tblwdbemerror->insertRec(err);
					impcnt++;

					num3 = 1;

					for (unsigned int ix3 = 0; ix3 < err->imeiamerrorpar.nodes.size(); ix3++) {
						errApar = err->imeiamerrorpar.nodes[ix3];

						errApar->errRefWdbeMError = err->ref;
						errApar->errNum = num3++;
						//errApar->sref: TBL
						errApar->ixWdbeVPartype = VecWdbeVPartype::getIx(errApar->srefIxWdbeVPartype);
						if (errApar->ixWdbeVPartype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",errApar->srefIxWdbeVPartype}, {"iel","srefIxWdbeVPartype"}, {"lineno",to_string(errApar->lineno)}});
						//errApar->refWdbeMVector: PREVIMP
						if (errApar->srefRefWdbeMVector != "") {
							for (unsigned int i = 0; i < ctr->imeimvector.nodes.size(); i++)
								if (ctr->imeimvector.nodes[i]->sref == errApar->srefRefWdbeMVector) {
									errApar->refWdbeMVector = ctr->imeimvector.nodes[i]->ref;
									break;
								};
							if (errApar->refWdbeMVector == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",errApar->srefRefWdbeMVector}, {"iel","srefRefWdbeMVector"}, {"lineno",to_string(errApar->lineno)}});
						};
						//errApar->Length: TBL
						//errApar->Comment: TBL

						dbswdbe->tblwdbeamerrorpar->insertRec(errApar);
						impcnt++;
					};
				};
			};

			if (mdl->imeimcontroller.nodes.size() > 0) {
				ctr = mdl->imeimcontroller.nodes[0];

				dbswdbe->executeQuery("UPDATE TblWdbeMModule SET refWdbeMController = " + to_string(ctr->ref) + " WHERE ref = " + to_string(mdl->ref));
			};

			for (unsigned int ix1 = 0; ix1 < mdl->imeiavkeylistkey3.nodes.size(); ix1++) {
				klsAkey3 = mdl->imeiavkeylistkey3.nodes[ix1];

				klsAkey3->klsIxWdbeVKeylist = VecWdbeVKeylist::getIx(klsAkey3->srefKlsIxWdbeVKeylist);
				if (klsAkey3->klsIxWdbeVKeylist == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",klsAkey3->srefKlsIxWdbeVKeylist}, {"iel","srefKlsIxWdbeVKeylist"}, {"lineno",to_string(klsAkey3->lineno)}});
				klsAkey3->klsNum = (ix1+1); // TBD
				klsAkey3->x1IxWdbeVMaintable = VecWdbeVMaintable::TBLWDBEMMODULE;
				klsAkey3->x1Uref = mdl->ref;
				klsAkey3->Fixed = true;
				//klsAkey3->sref: TBL
				//klsAkey3->refJ: SUB
				//klsAkey3->Title: TBL
				//klsAkey3->Comment: TBL

				dbswdbe->tblwdbeavkeylistkey->insertRec(klsAkey3);
				impcnt++;

				if (((klsAkey3->Title != "") || (klsAkey3->Comment != "")) && klsAkey3->imeijavkeylistkey3.nodes.empty()) {
					kakJkey3 = new ImeitemIJAVKeylistKey3();
					klsAkey3->imeijavkeylistkey3.nodes.push_back(kakJkey3);

					kakJkey3->refWdbeAVKeylistKey = klsAkey3->ref;
					kakJkey3->Title = klsAkey3->Title;
					kakJkey3->Comment = klsAkey3->Comment;
				};

				for (unsigned int ix2 = 0; ix2 < klsAkey3->imeijavkeylistkey3.nodes.size(); ix2++) {
					kakJkey3 = klsAkey3->imeijavkeylistkey3.nodes[ix2];

					kakJkey3->refWdbeAVKeylistKey = klsAkey3->ref;
					kakJkey3->x1IxWdbeVLocale = VecWdbeVLocale::ENUS;
					//kakJkey3->Title: TBL
					//kakJkey3->Comment: TBL

					dbswdbe->tblwdbejavkeylistkey->insertRec(kakJkey3);
					impcnt++;

					if (ix2 == 0) {
						klsAkey3->refJ = kakJkey3->ref;
						klsAkey3->Title = kakJkey3->Title;
						klsAkey3->Comment = kakJkey3->Comment;
						dbswdbe->tblwdbeavkeylistkey->updateRec(klsAkey3);
					};
				};
			};

			for (unsigned int ix1 = 0; ix1 < mdl->imeirmmodulemmodule.nodes.size(); ix1++) {
				mdlRmdl = mdl->imeirmmodulemmodule.nodes[ix1];

				mdlRmdl->ctdRefWdbeMModule = mdl->ref;
				//mdlRmdl->srefKFunction: TBL

				dbswdbe->tblwdbermmodulemmodule->insertRec(mdlRmdl);
				impcnt++;
			};

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

			for (unsigned int ix1 = 0; ix1 < mdl->imeimfile2.nodes.size(); ix1++) {
				fil2 = mdl->imeimfile2.nodes[ix1];

				fil2->refIxVTbl = VecWdbeVMFileRefTbl::MTP;
				fil2->refUref = mdl->ref;
				//fil2->osrefKContent: TBL
				//fil2->Filename: TBL
				//fil2->srefKMimetype: TBL
				//fil2->Comment: TBL

				dbswdbe->tblwdbemfile->insertRec(fil2);
				impcnt++;
			};

			irefs1.clear();

			for (unsigned int ix1 = 0; ix1 < mdl->imeicgeneric.nodes.size(); ix1++) {
				genC = mdl->imeicgeneric.nodes[ix1];

				if (irefs1.find(genC->iref) != irefs1.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(genC->iref)}, {"ime","ImeICGeneric"}, {"lineno",to_string(genC->lineno)}});
				genC->ref = dbswdbe->tblwdbecgeneric->getNewRef();
				irefs1.insert(genC->iref);
			};

			num1 = 1;

			for (unsigned int ix1 = 0; ix1 < mdl->imeimgeneric.nodes.size(); ix1++) {
				gen = mdl->imeimgeneric.nodes[ix1];

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
				gen->mdlNum = num1++;
				//gen->sref: TBL
				//gen->srefWdbeKHdltype: TBL
				//gen->Width: TBL
				//gen->Minmax: TBL
				//gen->Defval: TBL
				//gen->Comment: TBL

				dbswdbe->tblwdbemgeneric->insertRec(gen);
				impcnt++;
			};

			irefs1.clear();

			for (unsigned int ix1 = 0; ix1 < mdl->imeicport.nodes.size(); ix1++) {
				prtC = mdl->imeicport.nodes[ix1];

				if (irefs1.find(prtC->iref) != irefs1.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(prtC->iref)}, {"ime","ImeICPort"}, {"lineno",to_string(prtC->lineno)}});
				prtC->ref = dbswdbe->tblwdbecport->getNewRef();
				irefs1.insert(prtC->iref);
			};

			num1 = 1;

			for (unsigned int ix1 = 0; ix1 < mdl->imeimport.nodes.size(); ix1++) {
				prt = mdl->imeimport.nodes[ix1];

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
				prt->mdlNum = num1++;
				prt->mdlIxVCat = VecWdbeVMPortMdlCat::getIx(prt->srefMdlIxVCat);
				if (prt->mdlIxVCat == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",prt->srefMdlIxVCat}, {"iel","srefMdlIxVCat"}, {"lineno",to_string(prt->lineno)}});
				//prt->sref: TBL
				prt->ixVDir = VecWdbeVMPortDir::getIx(prt->srefIxVDir);
				if (prt->ixVDir == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",prt->srefIxVDir}, {"iel","srefIxVDir"}, {"lineno",to_string(prt->lineno)}});
				//prt->srefWdbeKHdltype: TBL
				//prt->Width: TBL
				//prt->Minmax: TBL
				//prt->Defval: TBL
				//prt->Comment: TBL

				dbswdbe->tblwdbemport->insertRec(prt);
				impcnt++;
			};

			irefs1.clear();

			for (unsigned int ix1 = 0; ix1 < mdl->imeicvariable.nodes.size(); ix1++) {
				varC = mdl->imeicvariable.nodes[ix1];

				if (irefs1.find(varC->iref) != irefs1.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(varC->iref)}, {"ime","ImeICVariable"}, {"lineno",to_string(varC->lineno)}});
				varC->ref = dbswdbe->tblwdbecvariable->getNewRef();
				irefs1.insert(varC->iref);

				impcnt++;
			};

			num1 = 1;

			for (unsigned int ix1 = 0; ix1 < mdl->imeimvariable.nodes.size(); ix1++) {
				var = mdl->imeimvariable.nodes[ix1];

				//var->refWdbeCVariable: PREVIMP
				if (var->irefRefWdbeCVariable != 0) {
					for (unsigned int i = 0; i < mdl->imeicvariable.nodes.size(); i++)
						if (mdl->imeicvariable.nodes[i]->iref == var->irefRefWdbeCVariable) {
							var->refWdbeCVariable = mdl->imeicvariable.nodes[i]->ref;
							break;
						};
					if (var->refWdbeCVariable == 0) throw SbeException(SbeException::IEX_IREF, {{"iref",to_string(var->irefRefWdbeCVariable)}, {"iel","irefRefWdbeCVariable"}, {"lineno",to_string(var->lineno)}});
				};
				var->refIxVTbl = VecWdbeVMVariableRefTbl::MDL;
				var->refUref = mdl->ref;
				var->refNum = num1++;
				//var->sref: TBL
				//var->srefWdbeKHdltype: TBL
				//var->Width: TBL
				//var->Minmax: TBL
				//var->Comment: TBL

				dbswdbe->tblwdbemvariable->insertRec(var);
				impcnt++;
			};
		};

		// -- ImeIMCoreproject
		for (unsigned int ix0 = 0; ix0 < imeimcoreproject.nodes.size(); ix0++) {
			cpr = imeimcoreproject.nodes[ix0];

			cpr->ixVBasetype = VecWdbeVMCoreprojectBasetype::getIx(cpr->srefIxVBasetype);
			if (cpr->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",cpr->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(cpr->lineno)}});
			//cpr->refWdbeMCoreversion: SUB
			//cpr->sref: TBL
			//cpr->Title: TBL
			//cpr->Giturl: TBL
			//cpr->Comment: TBL

			dbswdbe->tblwdbemcoreproject->insertRec(cpr);
			impcnt++;

			for (unsigned int ix1 = 0; ix1 < cpr->imeimcoreversion.nodes.size(); ix1++) {
				cvr = cpr->imeimcoreversion.nodes[ix1];

				cvr->refWdbeMCoreproject = cpr->ref;
				//cvr->Major: TBL
				//cvr->Minor: TBL
				//cvr->Sub: TBL
				//cvr->refJState: SUB
				if (cvr->srefIxVState != "") {
					cvr->ixVState = VecWdbeVMCoreversionState::getIx(cvr->srefIxVState);
					if (cvr->ixVState == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",cvr->srefIxVState}, {"iel","srefIxVState"}, {"lineno",to_string(cvr->lineno)}});
				};
				cvr->ixWSpectype = VecWdbeWMCoreversionSpectype::getIx(cvr->srefsIxWSpectype);

				dbswdbe->tblwdbemcoreversion->insertRec(cvr);
				impcnt++;

				if (((cvr->srefIxVState != "")) && cvr->imeijmcoreversionstate.nodes.empty()) {
					cvrJste = new ImeitemIJMCoreversionState();
					cvr->imeijmcoreversionstate.nodes.push_back(cvrJste);

					cvrJste->refWdbeMCoreversion = cvr->ref;
					cvrJste->srefIxVState = cvr->srefIxVState;
				};

				if (ix1 == 0) {
					cpr->refWdbeMCoreversion = cvr->ref;
					dbswdbe->tblwdbemcoreproject->updateRec(cpr);
				};

				for (unsigned int ix2 = 0; ix2 < cvr->imeijmcoreversionstate.nodes.size(); ix2++) {
					cvrJste = cvr->imeijmcoreversionstate.nodes[ix2];

					cvrJste->refWdbeMCoreversion = cvr->ref;
					cvrJste->x1Start = Ftm::invstamp("&now;");
					cvrJste->ixVState = VecWdbeVMCoreversionState::getIx(cvrJste->srefIxVState);
					if (cvrJste->ixVState == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",cvrJste->srefIxVState}, {"iel","srefIxVState"}, {"lineno",to_string(cvrJste->lineno)}});

					dbswdbe->tblwdbejmcoreversionstate->insertRec(cvrJste);
					impcnt++;

					if (ix2 == 0) {
						cvr->refJState = cvrJste->ref;
						cvr->ixVState = cvrJste->ixVState;
						dbswdbe->tblwdbemcoreversion->updateRec(cvr);
					};
				};
			};

			for (unsigned int ix1 = 0; ix1 < cpr->imeirmcoreprojectmperson.nodes.size(); ix1++) {
				cprRprs = cpr->imeirmcoreprojectmperson.nodes[ix1];

				cprRprs->refWdbeMCoreproject = cpr->ref;
				//cprRprs->refWdbeMPerson: THINT ; look for any person, format StubWdbePrsStd
				StrMod::stringToVector(cprRprs->hintRefWdbeMPerson, ss, ' ');
				if (ss.size() == 2) dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMPerson WHERE Lastname = '" + StrMod::esc(ss[1]) + "' AND Firstname = '" + StrMod::esc(ss[0]) + "'", cprRprs->refWdbeMPerson);
				//cprRprs->srefKFunction: TBL

				dbswdbe->tblwdbermcoreprojectmperson->insertRec(cprRprs);
				impcnt++;
			};
		};
		// IP enterSgeImport.traverse --- REND

		// IP enterSgeImport.ppr --- IBEGIN
		// -- ImeIMMachine
		for (unsigned int ix0 = 0; ix0 < imeimmachine.nodes.size(); ix0++) {
			mch = imeimmachine.nodes[ix0];

			if (mch->hsrefSupRefWdbeMMachine != "") {
				auto it = refsMchs.find(mch->hsrefSupRefWdbeMMachine);
				if (it != refsMchs.end()) mch->supRefWdbeMMachine = it->second;
				else throw SbeException(SbeException::IEX_THSREF, {{"thsref",mch->hsrefSupRefWdbeMMachine}, {"iel","hsrefSupRefWdbeMMachine"}, {"lineno",to_string(mch->lineno)}});
			};
			if (mch->hsrefCchRefWdbeMMachine != "") {
				auto it = refsMchs.find(mch->hsrefCchRefWdbeMMachine);
				if (it != refsMchs.end()) mch->cchRefWdbeMMachine = it->second;
				else throw SbeException(SbeException::IEX_THSREF, {{"thsref",mch->hsrefCchRefWdbeMMachine}, {"iel","hsrefCchRefWdbeMMachine"}, {"lineno",to_string(mch->lineno)}});
			};

			if ((mch->supRefWdbeMMachine != 0) || (mch->cchRefWdbeMMachine != 0)) dbswdbe->tblwdbemmachine->updateRec(mch);
		};

		// -- ImeIMModule
		for (unsigned int ix0 = 0; ix0 < imeimmodule.nodes.size(); ix0++) {
			mdl = imeimmodule.nodes[ix0];

			if (mdl->hsrefSupRefWdbeMModule != "") {
				for (unsigned int i = 0; i < imeimmodule.nodes.size(); i++) {
					mdl2 = imeimmodule.nodes[i];

					if ( ((mdl2->hsrefSupRefWdbeMModule == "") && (mdl2->sref == mdl->hsrefSupRefWdbeMModule))
								|| ((mdl2->hsrefSupRefWdbeMModule != "") && ((mdl2->hsrefSupRefWdbeMModule + ";" + mdl2->sref) == mdl->hsrefSupRefWdbeMModule)) ) {
						mdl->supRefWdbeMModule = mdl2->ref;
						break;
					};
				};

				if (mdl->supRefWdbeMModule == 0) throw SbeException(SbeException::IEX_THSREF, {{"thsref",mdl->hsrefSupRefWdbeMModule}, {"iel","hsrefSupRefWdbeMModule"}, {"lineno",to_string(mdl->lineno)}});
				else dbswdbe->tblwdbemmodule->updateRec(mdl);
			};

			if (mdl->srefTplRefWdbeMModule != "") {
				for (unsigned int i = 0; i < imeimmodule.nodes.size(); i++) {
					mdl2 = imeimmodule.nodes[i];

					if ((mdl2->hsrefSupRefWdbeMModule == "") && (mdl2->sref == mdl->srefTplRefWdbeMModule)) {
						mdl->tplRefWdbeMModule = mdl2->ref;
						break;
					};
				};

				if (mdl->tplRefWdbeMModule == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",mdl->srefTplRefWdbeMModule}, {"iel","srefTplRefWdbeMModule"}, {"lineno",to_string(mdl->lineno)}});
				else dbswdbe->tblwdbemmodule->updateRec(mdl);
			};
		};
		// IP enterSgeImport.ppr --- IEND
	} catch (SbeException& e) {
		lasterror = e.getSquawk(VecWdbeVError::getIx, VecWdbeVError::getTitle, ixWdbeVLocale);
		retval = nextIxVSgeFailure;
	};

	return retval;
};

void JobWdbeIexIni::leaveSgeImport(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeImport --- INSERT
};

uint JobWdbeIexIni::enterSgeImperr(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IMPERR;

	// IP enterSgeImperr --- INSERT

	return retval;
};

void JobWdbeIexIni::leaveSgeImperr(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeImperr --- INSERT
};

uint JobWdbeIexIni::enterSgeReverse(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::IDLE;
	retval = nextIxVSgeSuccess;

	ImeitemIAVControlPar* ctlApar = NULL;
	ImeitemIAVKeylistKey1* klsAkey1 = NULL;
	ImeitemIAVValuelistVal* vlsAval = NULL;
	ImeitemIMCoreproject* cpr = NULL;
	ImeitemIMFamily* fam = NULL;
	ImeitemIMFile1* fil1 = NULL;
	ImeitemIMLibrary* lib = NULL;
	ImeitemIMMachine* mch = NULL;
	ImeitemIMModule* mdl = NULL;
	ImeitemIMUnit* unt = NULL;
	ImeitemIMUsergroup* usg = NULL;
	ImeitemIAMLibraryMakefile* libAmkf = NULL;
	ImeitemIAMMachineMakefile* mchAmkf = NULL;
	ImeitemIAMMachinePar* mchApar = NULL;
	ImeitemIAMModulePar* mdlApar = NULL;
	ImeitemIAMUsergroupAccess* usgAacc = NULL;
	ImeitemIAVKeylistKey3* klsAkey3 = NULL;
	ImeitemIJAVKeylistKey1* kakJkey1 = NULL;
	ImeitemIMBank* bnk = NULL;
	ImeitemIMController* ctr = NULL;
	ImeitemIMCoreversion* cvr = NULL;
	ImeitemIMFile2* fil2 = NULL;
	ImeitemIMGeneric* gen = NULL;
	ImeitemIMPeripheral* pph = NULL;
	ImeitemIMPort* prt = NULL;
	ImeitemIMUser* usr = NULL;
	ImeitemIMVariable* var = NULL;
	ImeitemIRMCoreprojectMPerson* cprRprs = NULL;
	ImeitemIRMModuleMModule* mdlRmdl = NULL;
	ImeitemIAMUserAccess* usrAacc = NULL;
	ImeitemIAVKeylistKey2* klsAkey2 = NULL;
	ImeitemIJAVKeylistKey3* kakJkey3 = NULL;
	ImeitemIJMCoreversionState* cvrJste = NULL;
	ImeitemIJMUserState* usrJste = NULL;
	ImeitemIMCommand* cmd = NULL;
	ImeitemIMError* err = NULL;
	ImeitemIMPerson* prs = NULL;
	ImeitemIMPin* pin = NULL;
	ImeitemIMVector* vec = NULL;
	ImeitemIAMCommandInvpar* cmdAipa = NULL;
	ImeitemIAMCommandRetpar* cmdArpa = NULL;
	ImeitemIAMErrorPar* errApar = NULL;
	ImeitemIJAVKeylistKey2* kakJkey2 = NULL;
	ImeitemIJMPersonLastname* prsJlnm = NULL;
	ImeitemIJMPinSref* pinJsrf = NULL;
	ImeitemIMVectoritem* vit = NULL;

	// -- ImeIAVControlPar
	for (unsigned int ix0 = 0; ix0 < imeiavcontrolpar.nodes.size(); ix0++) {
		ctlApar = imeiavcontrolpar.nodes[ix0];
		if (ctlApar->ref != 0) dbswdbe->tblwdbeavcontrolpar->removeRecByRef(ctlApar->ref);
	};

	// -- ImeIAVKeylistKey1
	for (unsigned int ix0 = 0; ix0 < imeiavkeylistkey1.nodes.size(); ix0++) {
		klsAkey1 = imeiavkeylistkey1.nodes[ix0];
		if (klsAkey1->ref != 0) dbswdbe->tblwdbeavkeylistkey->removeRecByRef(klsAkey1->ref);

		for (unsigned int ix1 = 0; ix1 < klsAkey1->imeijavkeylistkey1.nodes.size(); ix1++) {
			kakJkey1 = klsAkey1->imeijavkeylistkey1.nodes[ix1];
			if (kakJkey1->ref != 0) dbswdbe->tblwdbejavkeylistkey->removeRecByRef(kakJkey1->ref);
		};
	};

	// -- ImeIAVValuelistVal
	for (unsigned int ix0 = 0; ix0 < imeiavvaluelistval.nodes.size(); ix0++) {
		vlsAval = imeiavvaluelistval.nodes[ix0];
		if (vlsAval->ref != 0) dbswdbe->tblwdbeavvaluelistval->removeRecByRef(vlsAval->ref);
	};

	// -- ImeIMCoreproject
	for (unsigned int ix0 = 0; ix0 < imeimcoreproject.nodes.size(); ix0++) {
		cpr = imeimcoreproject.nodes[ix0];
		if (cpr->ref != 0) dbswdbe->tblwdbemcoreproject->removeRecByRef(cpr->ref);

		for (unsigned int ix1 = 0; ix1 < cpr->imeimcoreversion.nodes.size(); ix1++) {
			cvr = cpr->imeimcoreversion.nodes[ix1];
			if (cvr->ref != 0) dbswdbe->tblwdbemcoreversion->removeRecByRef(cvr->ref);

			for (unsigned int ix2 = 0; ix2 < cvr->imeijmcoreversionstate.nodes.size(); ix2++) {
				cvrJste = cvr->imeijmcoreversionstate.nodes[ix2];
				if (cvrJste->ref != 0) dbswdbe->tblwdbejmcoreversionstate->removeRecByRef(cvrJste->ref);
			};
		};

		for (unsigned int ix1 = 0; ix1 < cpr->imeirmcoreprojectmperson.nodes.size(); ix1++) {
			cprRprs = cpr->imeirmcoreprojectmperson.nodes[ix1];
			if (cprRprs->ref != 0) dbswdbe->tblwdbermcoreprojectmperson->removeRecByRef(cprRprs->ref);
		};
	};

	// -- ImeIMFamily
	for (unsigned int ix0 = 0; ix0 < imeimfamily.nodes.size(); ix0++) {
		fam = imeimfamily.nodes[ix0];
		if (fam->ref != 0) dbswdbe->tblwdbemfamily->removeRecByRef(fam->ref);
	};

	// -- ImeIMFile1
	for (unsigned int ix0 = 0; ix0 < imeimfile1.nodes.size(); ix0++) {
		fil1 = imeimfile1.nodes[ix0];
		if (fil1->ref != 0) dbswdbe->tblwdbemfile->removeRecByRef(fil1->ref);
	};

	// -- ImeIMLibrary
	for (unsigned int ix0 = 0; ix0 < imeimlibrary.nodes.size(); ix0++) {
		lib = imeimlibrary.nodes[ix0];
		if (lib->ref != 0) dbswdbe->tblwdbemlibrary->removeRecByRef(lib->ref);

		for (unsigned int ix1 = 0; ix1 < lib->imeiamlibrarymakefile.nodes.size(); ix1++) {
			libAmkf = lib->imeiamlibrarymakefile.nodes[ix1];
			if (libAmkf->ref != 0) dbswdbe->tblwdbeamlibrarymakefile->removeRecByRef(libAmkf->ref);
		};
	};

	// -- ImeIMMachine
	for (unsigned int ix0 = 0; ix0 < imeimmachine.nodes.size(); ix0++) {
		mch = imeimmachine.nodes[ix0];
		if (mch->ref != 0) dbswdbe->tblwdbemmachine->removeRecByRef(mch->ref);

		for (unsigned int ix1 = 0; ix1 < mch->imeiammachinemakefile.nodes.size(); ix1++) {
			mchAmkf = mch->imeiammachinemakefile.nodes[ix1];
			if (mchAmkf->ref != 0) dbswdbe->tblwdbeammachinemakefile->removeRecByRef(mchAmkf->ref);
		};

		for (unsigned int ix1 = 0; ix1 < mch->imeiammachinepar.nodes.size(); ix1++) {
			mchApar = mch->imeiammachinepar.nodes[ix1];
			if (mchApar->ref != 0) dbswdbe->tblwdbeammachinepar->removeRecByRef(mchApar->ref);
		};
	};

	// -- ImeIMModule
	for (unsigned int ix0 = 0; ix0 < imeimmodule.nodes.size(); ix0++) {
		mdl = imeimmodule.nodes[ix0];
		if (mdl->ref != 0) dbswdbe->tblwdbemmodule->removeRecByRef(mdl->ref);

		for (unsigned int ix1 = 0; ix1 < mdl->imeiammodulepar.nodes.size(); ix1++) {
			mdlApar = mdl->imeiammodulepar.nodes[ix1];
			if (mdlApar->ref != 0) dbswdbe->tblwdbeammodulepar->removeRecByRef(mdlApar->ref);
		};

		for (unsigned int ix1 = 0; ix1 < mdl->imeiavkeylistkey3.nodes.size(); ix1++) {
			klsAkey3 = mdl->imeiavkeylistkey3.nodes[ix1];
			if (klsAkey3->ref != 0) dbswdbe->tblwdbeavkeylistkey->removeRecByRef(klsAkey3->ref);

			for (unsigned int ix2 = 0; ix2 < klsAkey3->imeijavkeylistkey3.nodes.size(); ix2++) {
				kakJkey3 = klsAkey3->imeijavkeylistkey3.nodes[ix2];
				if (kakJkey3->ref != 0) dbswdbe->tblwdbejavkeylistkey->removeRecByRef(kakJkey3->ref);
			};
		};

		for (unsigned int ix1 = 0; ix1 < mdl->imeimcontroller.nodes.size(); ix1++) {
			ctr = mdl->imeimcontroller.nodes[ix1];
			if (ctr->ref != 0) dbswdbe->tblwdbemcontroller->removeRecByRef(ctr->ref);

			for (unsigned int ix2 = 0; ix2 < ctr->imeimcommand.nodes.size(); ix2++) {
				cmd = ctr->imeimcommand.nodes[ix2];
				if (cmd->ref != 0) dbswdbe->tblwdbemcommand->removeRecByRef(cmd->ref);

				for (unsigned int ix3 = 0; ix3 < cmd->imeiamcommandinvpar.nodes.size(); ix3++) {
					cmdAipa = cmd->imeiamcommandinvpar.nodes[ix3];
					if (cmdAipa->ref != 0) dbswdbe->tblwdbeamcommandinvpar->removeRecByRef(cmdAipa->ref);
				};

				for (unsigned int ix3 = 0; ix3 < cmd->imeiamcommandretpar.nodes.size(); ix3++) {
					cmdArpa = cmd->imeiamcommandretpar.nodes[ix3];
					if (cmdArpa->ref != 0) dbswdbe->tblwdbeamcommandretpar->removeRecByRef(cmdArpa->ref);
				};
			};

			for (unsigned int ix2 = 0; ix2 < ctr->imeimerror.nodes.size(); ix2++) {
				err = ctr->imeimerror.nodes[ix2];
				if (err->ref != 0) dbswdbe->tblwdbemerror->removeRecByRef(err->ref);

				for (unsigned int ix3 = 0; ix3 < err->imeiamerrorpar.nodes.size(); ix3++) {
					errApar = err->imeiamerrorpar.nodes[ix3];
					if (errApar->ref != 0) dbswdbe->tblwdbeamerrorpar->removeRecByRef(errApar->ref);
				};
			};

			for (unsigned int ix2 = 0; ix2 < ctr->imeimvector.nodes.size(); ix2++) {
				vec = ctr->imeimvector.nodes[ix2];
				if (vec->ref != 0) dbswdbe->tblwdbemvector->removeRecByRef(vec->ref);

				for (unsigned int ix3 = 0; ix3 < vec->imeimvectoritem.nodes.size(); ix3++) {
					vit = vec->imeimvectoritem.nodes[ix3];
					if (vit->ref != 0) dbswdbe->tblwdbemvectoritem->removeRecByRef(vit->ref);
				};
			};
		};

		for (unsigned int ix1 = 0; ix1 < mdl->imeimfile2.nodes.size(); ix1++) {
			fil2 = mdl->imeimfile2.nodes[ix1];
			if (fil2->ref != 0) dbswdbe->tblwdbemfile->removeRecByRef(fil2->ref);
		};

		for (unsigned int ix1 = 0; ix1 < mdl->imeimgeneric.nodes.size(); ix1++) {
			gen = mdl->imeimgeneric.nodes[ix1];
			if (gen->ref != 0) dbswdbe->tblwdbemgeneric->removeRecByRef(gen->ref);
		};

		for (unsigned int ix1 = 0; ix1 < mdl->imeimport.nodes.size(); ix1++) {
			prt = mdl->imeimport.nodes[ix1];
			if (prt->ref != 0) dbswdbe->tblwdbemport->removeRecByRef(prt->ref);
		};

		for (unsigned int ix1 = 0; ix1 < mdl->imeimvariable.nodes.size(); ix1++) {
			var = mdl->imeimvariable.nodes[ix1];
			if (var->ref != 0) dbswdbe->tblwdbemvariable->removeRecByRef(var->ref);
		};

		for (unsigned int ix1 = 0; ix1 < mdl->imeirmmodulemmodule.nodes.size(); ix1++) {
			mdlRmdl = mdl->imeirmmodulemmodule.nodes[ix1];
			if (mdlRmdl->ref != 0) dbswdbe->tblwdbermmodulemmodule->removeRecByRef(mdlRmdl->ref);
		};
	};

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

				for (unsigned int ix3 = 0; ix3 < pin->imeijmpinsref.nodes.size(); ix3++) {
					pinJsrf = pin->imeijmpinsref.nodes[ix3];
					if (pinJsrf->ref != 0) dbswdbe->tblwdbejmpinsref->removeRecByRef(pinJsrf->ref);
				};
			};
		};

		for (unsigned int ix1 = 0; ix1 < unt->imeimperipheral.nodes.size(); ix1++) {
			pph = unt->imeimperipheral.nodes[ix1];
			if (pph->ref != 0) dbswdbe->tblwdbemperipheral->removeRecByRef(pph->ref);

			for (unsigned int ix2 = 0; ix2 < pph->imeiavkeylistkey2.nodes.size(); ix2++) {
				klsAkey2 = pph->imeiavkeylistkey2.nodes[ix2];
				if (klsAkey2->ref != 0) dbswdbe->tblwdbeavkeylistkey->removeRecByRef(klsAkey2->ref);

				for (unsigned int ix3 = 0; ix3 < klsAkey2->imeijavkeylistkey2.nodes.size(); ix3++) {
					kakJkey2 = klsAkey2->imeijavkeylistkey2.nodes[ix3];
					if (kakJkey2->ref != 0) dbswdbe->tblwdbejavkeylistkey->removeRecByRef(kakJkey2->ref);
				};
			};
		};
	};

	// -- ImeIMUsergroup
	for (unsigned int ix0 = 0; ix0 < imeimusergroup.nodes.size(); ix0++) {
		usg = imeimusergroup.nodes[ix0];
		if (usg->ref != 0) dbswdbe->tblwdbemusergroup->removeRecByRef(usg->ref);

		for (unsigned int ix1 = 0; ix1 < usg->imeiamusergroupaccess.nodes.size(); ix1++) {
			usgAacc = usg->imeiamusergroupaccess.nodes[ix1];
			if (usgAacc->ref != 0) dbswdbe->tblwdbeamusergroupaccess->removeRecByRef(usgAacc->ref);
		};

		for (unsigned int ix1 = 0; ix1 < usg->imeimuser.nodes.size(); ix1++) {
			usr = usg->imeimuser.nodes[ix1];
			if (usr->ref != 0) dbswdbe->tblwdbemuser->removeRecByRef(usr->ref);

			for (unsigned int ix2 = 0; ix2 < usr->imeiamuseraccess.nodes.size(); ix2++) {
				usrAacc = usr->imeiamuseraccess.nodes[ix2];
				if (usrAacc->ref != 0) dbswdbe->tblwdbeamuseraccess->removeRecByRef(usrAacc->ref);
			};

			for (unsigned int ix2 = 0; ix2 < usr->imeijmuserstate.nodes.size(); ix2++) {
				usrJste = usr->imeijmuserstate.nodes[ix2];
				if (usrJste->ref != 0) dbswdbe->tblwdbejmuserstate->removeRecByRef(usrJste->ref);
			};

			for (unsigned int ix2 = 0; ix2 < usr->imeimperson.nodes.size(); ix2++) {
				prs = usr->imeimperson.nodes[ix2];
				if (prs->ref != 0) dbswdbe->tblwdbemperson->removeRecByRef(prs->ref);

				for (unsigned int ix3 = 0; ix3 < prs->imeijmpersonlastname.nodes.size(); ix3++) {
					prsJlnm = prs->imeijmpersonlastname.nodes[ix3];
					if (prsJlnm->ref != 0) dbswdbe->tblwdbejmpersonlastname->removeRecByRef(prsJlnm->ref);
				};
			};
		};
	};

	return retval;
};

void JobWdbeIexIni::leaveSgeReverse(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeReverse --- INSERT
};

uint JobWdbeIexIni::enterSgeCollect(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::CLTDONE;
	retval = nextIxVSgeSuccess;

	ImeitemIAVControlPar* ctlApar = NULL;
	ImeitemIAVKeylistKey1* klsAkey1 = NULL;
	ImeitemIAVValuelistVal* vlsAval = NULL;
	ImeitemIMCoreproject* cpr = NULL;
	ImeitemIMFamily* fam = NULL;
	ImeitemIMFile1* fil1 = NULL;
	ImeitemIMLibrary* lib = NULL;
	ImeitemIMMachine* mch = NULL;
	ImeitemIMModule* mdl = NULL;
	ImeitemIMUnit* unt = NULL;
	ImeitemIMUsergroup* usg = NULL;
	ImeitemIAMLibraryMakefile* libAmkf = NULL;
	ImeitemIAMMachineMakefile* mchAmkf = NULL;
	ImeitemIAMMachinePar* mchApar = NULL;
	ImeitemIAMModulePar* mdlApar = NULL;
	ImeitemIAMUsergroupAccess* usgAacc = NULL;
	ImeitemIAVKeylistKey3* klsAkey3 = NULL;
	ImeitemICGeneric* genC = NULL;
	ImeitemICPort* prtC = NULL;
	ImeitemICVariable* varC = NULL;
	ImeitemIJAVKeylistKey1* kakJkey1 = NULL;
	ImeitemIMBank* bnk = NULL;
	ImeitemIMController* ctr = NULL;
	ImeitemIMCoreversion* cvr = NULL;
	ImeitemIMFile2* fil2 = NULL;
	ImeitemIMGeneric* gen = NULL;
	ImeitemIMPeripheral* pph = NULL;
	ImeitemIMPort* prt = NULL;
	ImeitemIMUser* usr = NULL;
	ImeitemIMVariable* var = NULL;
	ImeitemIRMCoreprojectMPerson* cprRprs = NULL;
	ImeitemIRMModuleMModule* mdlRmdl = NULL;
	ImeitemIAMUserAccess* usrAacc = NULL;
	ImeitemIAVKeylistKey2* klsAkey2 = NULL;
	ImeitemIJAVKeylistKey3* kakJkey3 = NULL;
	ImeitemIJMCoreversionState* cvrJste = NULL;
	ImeitemIJMUserState* usrJste = NULL;
	ImeitemIMCommand* cmd = NULL;
	ImeitemIMError* err = NULL;
	ImeitemIMPerson* prs = NULL;
	ImeitemIMPin* pin = NULL;
	ImeitemIMVector* vec = NULL;
	ImeitemIAMCommandInvpar* cmdAipa = NULL;
	ImeitemIAMCommandRetpar* cmdArpa = NULL;
	ImeitemIAMErrorPar* errApar = NULL;
	ImeitemIJAVKeylistKey2* kakJkey2 = NULL;
	ImeitemIJMPersonLastname* prsJlnm = NULL;
	ImeitemIJMPinSref* pinJsrf = NULL;
	ImeitemIMVectoritem* vit = NULL;

	uint ixWdbeVIop;

	vector<ubigint> refs;

	Stcch* stcch = new Stcch(false);

	// IP enterSgeCollect.traverse --- BEGIN

	// -- ImeIAVControlPar
	for (unsigned int ix0 = 0; ix0 < imeiavcontrolpar.nodes.size(); ix0++) {
		ctlApar = imeiavcontrolpar.nodes[ix0];

		if (ctlApar->ref != 0) {
		};
	};

	// -- ImeIAVKeylistKey1
	for (unsigned int ix0 = 0; ix0 < imeiavkeylistkey1.nodes.size(); ix0++) {
		klsAkey1 = imeiavkeylistkey1.nodes[ix0];

		if (klsAkey1->ref != 0) {
		};

		if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIJAVKEYLISTKEY1, ixWdbeVIop)) {
			dbswdbe->tblwdbejavkeylistkey->loadRefsByKlk(klsAkey1->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == klsAkey1->refJ) {refs[i] = refs[0]; refs[0] = klsAkey1->refJ; break;};
			for (unsigned int i = 0; i < refs.size(); i++) klsAkey1->imeijavkeylistkey1.nodes.push_back(new ImeitemIJAVKeylistKey1(dbswdbe, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < klsAkey1->imeijavkeylistkey1.nodes.size(); ix1++) {
			kakJkey1 = klsAkey1->imeijavkeylistkey1.nodes[ix1];

			if (kakJkey1->ref != 0) {
			};
		};
	};

	// -- ImeIAVValuelistVal
	for (unsigned int ix0 = 0; ix0 < imeiavvaluelistval.nodes.size(); ix0++) {
		vlsAval = imeiavvaluelistval.nodes[ix0];

		if (vlsAval->ref != 0) {
		};
	};

	// -- ImeIMCoreproject
	for (unsigned int ix0 = 0; ix0 < imeimcoreproject.nodes.size(); ix0++) {
		cpr = imeimcoreproject.nodes[ix0];

		if (cpr->ref != 0) {
		};

		if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMCOREVERSION, ixWdbeVIop)) {
			dbswdbe->tblwdbemcoreversion->loadRefsByCpr(cpr->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) cpr->imeimcoreversion.nodes.push_back(new ImeitemIMCoreversion(dbswdbe, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < cpr->imeimcoreversion.nodes.size(); ix1++) {
			cvr = cpr->imeimcoreversion.nodes[ix1];

			if (cvr->ref != 0) {
			};

			if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIJMCOREVERSIONSTATE, ixWdbeVIop)) {
				dbswdbe->tblwdbejmcoreversionstate->loadRefsByCvr(cvr->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == cvr->refJState) {refs[i] = refs[0]; refs[0] = cvr->refJState; break;};
				for (unsigned int i = 0; i < refs.size(); i++) cvr->imeijmcoreversionstate.nodes.push_back(new ImeitemIJMCoreversionState(dbswdbe, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < cvr->imeijmcoreversionstate.nodes.size(); ix2++) {
				cvrJste = cvr->imeijmcoreversionstate.nodes[ix2];

				if (cvrJste->ref != 0) {
				};
			};
		};

		if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIRMCOREPROJECTMPERSON, ixWdbeVIop)) {
			dbswdbe->tblwdbermcoreprojectmperson->loadRefsByCpr(cpr->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) cpr->imeirmcoreprojectmperson.nodes.push_back(new ImeitemIRMCoreprojectMPerson(dbswdbe, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < cpr->imeirmcoreprojectmperson.nodes.size(); ix1++) {
			cprRprs = cpr->imeirmcoreprojectmperson.nodes[ix1];

			if (cprRprs->ref != 0) {
				cprRprs->hintRefWdbeMPerson = StubWdbe::getStubPrsStd(dbswdbe, cprRprs->refWdbeMPerson, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
			};
		};
	};

	// -- ImeIMFamily
	for (unsigned int ix0 = 0; ix0 < imeimfamily.nodes.size(); ix0++) {
		fam = imeimfamily.nodes[ix0];

		if (fam->ref != 0) {
			fam->iref = ix0+1;
		};
	};

	// -- ImeIMFile1
	for (unsigned int ix0 = 0; ix0 < imeimfile1.nodes.size(); ix0++) {
		fil1 = imeimfile1.nodes[ix0];

		if (fil1->ref != 0) {
		};
	};

	// -- ImeIMLibrary
	for (unsigned int ix0 = 0; ix0 < imeimlibrary.nodes.size(); ix0++) {
		lib = imeimlibrary.nodes[ix0];

		if (lib->ref != 0) {
		};

		if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIAMLIBRARYMAKEFILE, ixWdbeVIop)) {
			dbswdbe->tblwdbeamlibrarymakefile->loadRefsByLib(lib->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) lib->imeiamlibrarymakefile.nodes.push_back(new ImeitemIAMLibraryMakefile(dbswdbe, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < lib->imeiamlibrarymakefile.nodes.size(); ix1++) {
			libAmkf = lib->imeiamlibrarymakefile.nodes[ix1];

			if (libAmkf->ref != 0) {
				libAmkf->hsrefX1RefWdbeMMachine = StubWdbe::getStubMchStd(dbswdbe, libAmkf->x1RefWdbeMMachine, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
			};
		};
	};

	// -- ImeIMMachine
	for (unsigned int ix0 = 0; ix0 < imeimmachine.nodes.size(); ix0++) {
		mch = imeimmachine.nodes[ix0];

		if (mch->ref != 0) {
			mch->hsrefSupRefWdbeMMachine = StubWdbe::getStubMchStd(dbswdbe, mch->supRefWdbeMMachine, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
			//mch->hsrefCchRefWdbeMMachine: STUB
		};

		if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIAMMACHINEMAKEFILE, ixWdbeVIop)) {
			dbswdbe->tblwdbeammachinemakefile->loadRefsByMch(mch->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) mch->imeiammachinemakefile.nodes.push_back(new ImeitemIAMMachineMakefile(dbswdbe, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < mch->imeiammachinemakefile.nodes.size(); ix1++) {
			mchAmkf = mch->imeiammachinemakefile.nodes[ix1];

			if (mchAmkf->ref != 0) {
			};
		};

		if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIAMMACHINEPAR, ixWdbeVIop)) {
			dbswdbe->tblwdbeammachinepar->loadRefsByMch(mch->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) mch->imeiammachinepar.nodes.push_back(new ImeitemIAMMachinePar(dbswdbe, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < mch->imeiammachinepar.nodes.size(); ix1++) {
			mchApar = mch->imeiammachinepar.nodes[ix1];

			if (mchApar->ref != 0) {
			};
		};
	};

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

		if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIAVKEYLISTKEY3, ixWdbeVIop)) {
			dbswdbe->tblwdbeavkeylistkey->loadRefsByMtbUrf(VecWdbeVMaintable::TBLWDBEMMODULE, mdl->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) mdl->imeiavkeylistkey3.nodes.push_back(new ImeitemIAVKeylistKey3(dbswdbe, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < mdl->imeiavkeylistkey3.nodes.size(); ix1++) {
			klsAkey3 = mdl->imeiavkeylistkey3.nodes[ix1];

			if (klsAkey3->ref != 0) {
			};

			if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIJAVKEYLISTKEY3, ixWdbeVIop)) {
				dbswdbe->tblwdbejavkeylistkey->loadRefsByKlk(klsAkey3->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == klsAkey3->refJ) {refs[i] = refs[0]; refs[0] = klsAkey3->refJ; break;};
				for (unsigned int i = 0; i < refs.size(); i++) klsAkey3->imeijavkeylistkey3.nodes.push_back(new ImeitemIJAVKeylistKey3(dbswdbe, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < klsAkey3->imeijavkeylistkey3.nodes.size(); ix2++) {
				kakJkey3 = klsAkey3->imeijavkeylistkey3.nodes[ix2];

				if (kakJkey3->ref != 0) {
				};
			};
		};

		for (unsigned int ix1 = 0; ix1 < mdl->imeicgeneric.nodes.size(); ix1++) {
			genC = mdl->imeicgeneric.nodes[ix1];

			if (genC->ref != 0) {
				genC->iref = ix1+1;
			};
		};

		for (unsigned int ix1 = 0; ix1 < mdl->imeicport.nodes.size(); ix1++) {
			prtC = mdl->imeicport.nodes[ix1];

			if (prtC->ref != 0) {
				prtC->iref = ix1+1;
			};
		};

		for (unsigned int ix1 = 0; ix1 < mdl->imeicvariable.nodes.size(); ix1++) {
			varC = mdl->imeicvariable.nodes[ix1];

			if (varC->ref != 0) {
				varC->iref = ix1+1;
			};
		};

		if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMCONTROLLER, ixWdbeVIop)) {
			dbswdbe->tblwdbemcontroller->loadRefsByMdl(mdl->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) mdl->imeimcontroller.nodes.push_back(new ImeitemIMController(dbswdbe, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < mdl->imeimcontroller.nodes.size(); ix1++) {
			ctr = mdl->imeimcontroller.nodes[ix1];

			if (ctr->ref != 0) {
			};

			if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMCOMMAND, ixWdbeVIop)) {
				dbswdbe->tblwdbemcommand->loadRefsByRetReu(VecWdbeVMCommandRefTbl::CTR, ctr->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) ctr->imeimcommand.nodes.push_back(new ImeitemIMCommand(dbswdbe, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < ctr->imeimcommand.nodes.size(); ix2++) {
				cmd = ctr->imeimcommand.nodes[ix2];

				if (cmd->ref != 0) {
				};

				if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIAMCOMMANDINVPAR, ixWdbeVIop)) {
					dbswdbe->tblwdbeamcommandinvpar->loadRefsByCmd(cmd->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) cmd->imeiamcommandinvpar.nodes.push_back(new ImeitemIAMCommandInvpar(dbswdbe, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < cmd->imeiamcommandinvpar.nodes.size(); ix3++) {
					cmdAipa = cmd->imeiamcommandinvpar.nodes[ix3];

					if (cmdAipa->ref != 0) {
						cmdAipa->srefRefWdbeMVector = StubWdbe::getStubVecStd(dbswdbe, cmdAipa->refWdbeMVector, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
						//cmdAipa->srefRefWdbeMVectoritem: STUB
					};
				};

				if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIAMCOMMANDRETPAR, ixWdbeVIop)) {
					dbswdbe->tblwdbeamcommandretpar->loadRefsByCmd(cmd->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) cmd->imeiamcommandretpar.nodes.push_back(new ImeitemIAMCommandRetpar(dbswdbe, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < cmd->imeiamcommandretpar.nodes.size(); ix3++) {
					cmdArpa = cmd->imeiamcommandretpar.nodes[ix3];

					if (cmdArpa->ref != 0) {
						cmdArpa->srefRefWdbeMVector = StubWdbe::getStubVecStd(dbswdbe, cmdArpa->refWdbeMVector, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
					};
				};
			};

			if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMERROR, ixWdbeVIop)) {
				dbswdbe->tblwdbemerror->loadRefsByRetReu(VecWdbeVMErrorRefTbl::CTR, ctr->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) ctr->imeimerror.nodes.push_back(new ImeitemIMError(dbswdbe, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < ctr->imeimerror.nodes.size(); ix2++) {
				err = ctr->imeimerror.nodes[ix2];

				if (err->ref != 0) {
				};

				if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIAMERRORPAR, ixWdbeVIop)) {
					dbswdbe->tblwdbeamerrorpar->loadRefsByErr(err->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) err->imeiamerrorpar.nodes.push_back(new ImeitemIAMErrorPar(dbswdbe, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < err->imeiamerrorpar.nodes.size(); ix3++) {
					errApar = err->imeiamerrorpar.nodes[ix3];

					if (errApar->ref != 0) {
						errApar->srefRefWdbeMVector = StubWdbe::getStubVecStd(dbswdbe, errApar->refWdbeMVector, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
					};
				};
			};

			if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMVECTOR, ixWdbeVIop)) {
				dbswdbe->tblwdbemvector->loadRefsByHktHku(VecWdbeVMVectorHkTbl::CTR, ctr->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) ctr->imeimvector.nodes.push_back(new ImeitemIMVector(dbswdbe, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < ctr->imeimvector.nodes.size(); ix2++) {
				vec = ctr->imeimvector.nodes[ix2];

				if (vec->ref != 0) {
				};

				if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMVECTORITEM, ixWdbeVIop)) {
					dbswdbe->tblwdbemvectoritem->loadRefsByVec(vec->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) vec->imeimvectoritem.nodes.push_back(new ImeitemIMVectoritem(dbswdbe, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < vec->imeimvectoritem.nodes.size(); ix3++) {
					vit = vec->imeimvectoritem.nodes[ix3];

					if (vit->ref != 0) {
					};
				};
			};
		};

		if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMFILE2, ixWdbeVIop)) {
			dbswdbe->tblwdbemfile->loadRefsByRetReu(VecWdbeVMFileRefTbl::MTP, mdl->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) mdl->imeimfile2.nodes.push_back(new ImeitemIMFile2(dbswdbe, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < mdl->imeimfile2.nodes.size(); ix1++) {
			fil2 = mdl->imeimfile2.nodes[ix1];

			if (fil2->ref != 0) {
			};
		};

		if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMGENERIC, ixWdbeVIop)) {
			dbswdbe->tblwdbemgeneric->loadRefsByMdl(mdl->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) mdl->imeimgeneric.nodes.push_back(new ImeitemIMGeneric(dbswdbe, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < mdl->imeimgeneric.nodes.size(); ix1++) {
			gen = mdl->imeimgeneric.nodes[ix1];

			if (gen->ref != 0) {
				//gen->irefRefWdbeCGeneric: IREF
			};
		};

		if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMPORT, ixWdbeVIop)) {
			dbswdbe->tblwdbemport->loadRefsByMdl(mdl->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) mdl->imeimport.nodes.push_back(new ImeitemIMPort(dbswdbe, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < mdl->imeimport.nodes.size(); ix1++) {
			prt = mdl->imeimport.nodes[ix1];

			if (prt->ref != 0) {
				//prt->irefRefWdbeCPort: IREF
			};
		};

		if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMVARIABLE, ixWdbeVIop)) {
			dbswdbe->tblwdbemvariable->loadRefsByRetReu(VecWdbeVMVariableRefTbl::MDL, mdl->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) mdl->imeimvariable.nodes.push_back(new ImeitemIMVariable(dbswdbe, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < mdl->imeimvariable.nodes.size(); ix1++) {
			var = mdl->imeimvariable.nodes[ix1];

			if (var->ref != 0) {
				//var->irefRefWdbeCVariable: IREF
			};
		};

		if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIRMMODULEMMODULE, ixWdbeVIop)) {
			dbswdbe->tblwdbermmodulemmodule->loadRefsByCtd(mdl->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) mdl->imeirmmodulemmodule.nodes.push_back(new ImeitemIRMModuleMModule(dbswdbe, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < mdl->imeirmmodulemmodule.nodes.size(); ix1++) {
			mdlRmdl = mdl->imeirmmodulemmodule.nodes[ix1];

			if (mdlRmdl->ref != 0) {
			};
		};
	};

	// -- ImeIMUnit
	for (unsigned int ix0 = 0; ix0 < imeimunit.nodes.size(); ix0++) {
		unt = imeimunit.nodes[ix0];

		if (unt->ref != 0) {
			//unt->irefRefUref: IREF
		};

		if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMBANK, ixWdbeVIop)) {
			dbswdbe->tblwdbembank->loadRefsByUnt(unt->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) unt->imeimbank.nodes.push_back(new ImeitemIMBank(dbswdbe, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < unt->imeimbank.nodes.size(); ix1++) {
			bnk = unt->imeimbank.nodes[ix1];

			if (bnk->ref != 0) {
			};

			if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMPIN, ixWdbeVIop)) {
				dbswdbe->tblwdbempin->loadRefsByBnk(bnk->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) bnk->imeimpin.nodes.push_back(new ImeitemIMPin(dbswdbe, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < bnk->imeimpin.nodes.size(); ix2++) {
				pin = bnk->imeimpin.nodes[ix2];

				if (pin->ref != 0) {
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

		if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMPERIPHERAL, ixWdbeVIop)) {
			dbswdbe->tblwdbemperipheral->loadRefsByUnt(unt->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) unt->imeimperipheral.nodes.push_back(new ImeitemIMPeripheral(dbswdbe, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < unt->imeimperipheral.nodes.size(); ix1++) {
			pph = unt->imeimperipheral.nodes[ix1];

			if (pph->ref != 0) {
			};

			if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIAVKEYLISTKEY2, ixWdbeVIop)) {
				dbswdbe->tblwdbeavkeylistkey->loadRefsByMtbUrf(VecWdbeVMaintable::TBLWDBEMPERIPHERAL, pph->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) pph->imeiavkeylistkey2.nodes.push_back(new ImeitemIAVKeylistKey2(dbswdbe, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < pph->imeiavkeylistkey2.nodes.size(); ix2++) {
				klsAkey2 = pph->imeiavkeylistkey2.nodes[ix2];

				if (klsAkey2->ref != 0) {
				};

				if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIJAVKEYLISTKEY2, ixWdbeVIop)) {
					dbswdbe->tblwdbejavkeylistkey->loadRefsByKlk(klsAkey2->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == klsAkey2->refJ) {refs[i] = refs[0]; refs[0] = klsAkey2->refJ; break;};
					for (unsigned int i = 0; i < refs.size(); i++) klsAkey2->imeijavkeylistkey2.nodes.push_back(new ImeitemIJAVKeylistKey2(dbswdbe, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < klsAkey2->imeijavkeylistkey2.nodes.size(); ix3++) {
					kakJkey2 = klsAkey2->imeijavkeylistkey2.nodes[ix3];

					if (kakJkey2->ref != 0) {
					};
				};
			};
		};
	};

	// -- ImeIMUsergroup
	for (unsigned int ix0 = 0; ix0 < imeimusergroup.nodes.size(); ix0++) {
		usg = imeimusergroup.nodes[ix0];

		if (usg->ref != 0) {
		};

		if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIAMUSERGROUPACCESS, ixWdbeVIop)) {
			dbswdbe->tblwdbeamusergroupaccess->loadRefsByUsg(usg->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) usg->imeiamusergroupaccess.nodes.push_back(new ImeitemIAMUsergroupAccess(dbswdbe, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < usg->imeiamusergroupaccess.nodes.size(); ix1++) {
			usgAacc = usg->imeiamusergroupaccess.nodes[ix1];

			if (usgAacc->ref != 0) {
			};
		};

		if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMUSER, ixWdbeVIop)) {
			dbswdbe->tblwdbemuser->loadRefsByUsg(usg->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) usg->imeimuser.nodes.push_back(new ImeitemIMUser(dbswdbe, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < usg->imeimuser.nodes.size(); ix1++) {
			usr = usg->imeimuser.nodes[ix1];

			if (usr->ref != 0) {
			};

			if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIAMUSERACCESS, ixWdbeVIop)) {
				dbswdbe->tblwdbeamuseraccess->loadRefsByUsr(usr->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) usr->imeiamuseraccess.nodes.push_back(new ImeitemIAMUserAccess(dbswdbe, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < usr->imeiamuseraccess.nodes.size(); ix2++) {
				usrAacc = usr->imeiamuseraccess.nodes[ix2];

				if (usrAacc->ref != 0) {
				};
			};

			if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIJMUSERSTATE, ixWdbeVIop)) {
				dbswdbe->tblwdbejmuserstate->loadRefsByUsr(usr->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == usr->refJState) {refs[i] = refs[0]; refs[0] = usr->refJState; break;};
				for (unsigned int i = 0; i < refs.size(); i++) usr->imeijmuserstate.nodes.push_back(new ImeitemIJMUserState(dbswdbe, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < usr->imeijmuserstate.nodes.size(); ix2++) {
				usrJste = usr->imeijmuserstate.nodes[ix2];

				if (usrJste->ref != 0) {
				};
			};

			for (unsigned int ix2 = 0; ix2 < usr->imeimperson.nodes.size(); ix2++) {
				prs = usr->imeimperson.nodes[ix2];

				if (prs->ref != 0) {
				};

				if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIJMPERSONLASTNAME, ixWdbeVIop)) {
					dbswdbe->tblwdbejmpersonlastname->loadRefsByPrs(prs->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == prs->refJLastname) {refs[i] = refs[0]; refs[0] = prs->refJLastname; break;};
					for (unsigned int i = 0; i < refs.size(); i++) prs->imeijmpersonlastname.nodes.push_back(new ImeitemIJMPersonLastname(dbswdbe, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < prs->imeijmpersonlastname.nodes.size(); ix3++) {
					prsJlnm = prs->imeijmpersonlastname.nodes[ix3];

					if (prsJlnm->ref != 0) {
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

void JobWdbeIexIni::leaveSgeCollect(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeCollect --- INSERT
};

uint JobWdbeIexIni::enterSgeCltdone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::CLTDONE;

	// IP enterSgeCltdone --- INSERT

	return retval;
};

void JobWdbeIexIni::leaveSgeCltdone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeCltdone --- INSERT
};

uint JobWdbeIexIni::enterSgeExport(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	IexWdbeIni::exportToFile(fullpath, xmlNotTxt, shorttags, imeiavcontrolpar, imeiavkeylistkey1, imeiavvaluelistval, imeimcoreproject, imeimfamily, imeimfile1, imeimlibrary, imeimmachine, imeimmodule, imeimunit, imeimusergroup);

	return retval;
};

void JobWdbeIexIni::leaveSgeExport(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeExport --- INSERT
};

uint JobWdbeIexIni::enterSgeDone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void JobWdbeIexIni::leaveSgeDone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeDone --- INSERT
};
