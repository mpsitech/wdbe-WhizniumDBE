/**
	* \file JobWdbeIexDcd.cpp
	* job handler for job JobWdbeIexDcd (implementation)
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

#include "JobWdbeIexDcd.h"

#include "JobWdbeIexDcd_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

using namespace IexWdbeDcd;

/******************************************************************************
 class JobWdbeIexDcd
 ******************************************************************************/

JobWdbeIexDcd::JobWdbeIexDcd(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::JOBWDBEIEXDCD, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	changeStage(dbswdbe, VecVSge::IDLE);

	// IP constructor.cust3 --- INSERT

};

JobWdbeIexDcd::~JobWdbeIexDcd() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void JobWdbeIexDcd::reset(
			DbsWdbe* dbswdbe
		) {
	if (ixVSge != VecVSge::IDLE) changeStage(dbswdbe, VecVSge::IDLE);
};

void JobWdbeIexDcd::parseFromFile(
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

void JobWdbeIexDcd::import(
			DbsWdbe* dbswdbe
		) {
	if (ixVSge == VecVSge::PRSDONE) changeStage(dbswdbe, VecVSge::IMPORT);
};

void JobWdbeIexDcd::reverse(
			DbsWdbe* dbswdbe
		) {
	if (ixVSge == VecVSge::IMPERR) changeStage(dbswdbe, VecVSge::REVERSE);
};

void JobWdbeIexDcd::collect(
			DbsWdbe* dbswdbe
			, const map<uint,uint>& _icsWdbeVIop
		) {
	if (ixVSge == VecVSge::IDLE) {
		icsWdbeVIop = _icsWdbeVIop;
		changeStage(dbswdbe, VecVSge::COLLECT);
	};
};

void JobWdbeIexDcd::exportToFile(
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

void JobWdbeIexDcd::handleRequest(
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

void JobWdbeIexDcd::changeStage(
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

string JobWdbeIexDcd::getSquawk(
			DbsWdbe* dbswdbe
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::PARSE) || (ixVSge == VecVSge::PRSDONE) || (ixVSge == VecVSge::IMPORT) || (ixVSge == VecVSge::REVERSE) || (ixVSge == VecVSge::COLLECT) || (ixVSge == VecVSge::CLTDONE) || (ixVSge == VecVSge::EXPORT) ) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing detailed core description";
			else if (ixVSge == VecVSge::PRSDONE) retval = "detailed core description parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing detailed core description (" + to_string(impcnt) + " records added)";
			else if (ixVSge == VecVSge::REVERSE) retval = "reversing detailed core description import";
			else if (ixVSge == VecVSge::COLLECT) retval = "collecting detailed core description for export";
			else if (ixVSge == VecVSge::CLTDONE) retval = "detailed core description collected for export";
			else if (ixVSge == VecVSge::EXPORT) retval = "exporting detailed core description";
		};

	} else if ( (ixVSge == VecVSge::PRSERR) || (ixVSge == VecVSge::IMPERR) ) {
		retval = lasterror;

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

uint JobWdbeIexDcd::enterSgeIdle(
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

	imeiamcoreversionip.clear();
	imeiamcoreversionplh.clear();
	imeimmodule.clear();

	return retval;
};

void JobWdbeIexDcd::leaveSgeIdle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWdbeIexDcd::enterSgeParse(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::PRSDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::PRSERR;

	try {
		IexWdbeDcd::parseFromFile(fullpath, xmlNotTxt, rectpath, imeiamcoreversionip, imeiamcoreversionplh, imeimmodule);

	} catch (SbeException& e) {
		if (e.ix == SbeException::PATHNF) e.vals["path"] = "<hidden>";
		lasterror = e.getSquawk(VecWdbeVError::getIx, VecWdbeVError::getTitle, ixWdbeVLocale);

		retval = nextIxVSgeFailure;
	};

	return retval;
};

void JobWdbeIexDcd::leaveSgeParse(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeParse --- INSERT
};

uint JobWdbeIexDcd::enterSgePrserr(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::PRSERR;

	// IP enterSgePrserr --- INSERT

	return retval;
};

void JobWdbeIexDcd::leaveSgePrserr(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgePrserr --- INSERT
};

uint JobWdbeIexDcd::enterSgePrsdone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::PRSDONE;

	// IP enterSgePrsdone --- INSERT

	return retval;
};

void JobWdbeIexDcd::leaveSgePrsdone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgePrsdone --- INSERT
};

uint JobWdbeIexDcd::enterSgeImport(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IMPERR;

	ImeitemIAMCoreversionIp* cvrAipx = NULL;
	ImeitemIAMCoreversionPlh* cvrAplh = NULL;
	ImeitemIMModule* mdl = NULL;
	ImeitemICGeneric* genC = NULL;
	ImeitemICPort* prtC = NULL;
	ImeitemICSignal* sigC = NULL;
	ImeitemIMController* ctr = NULL;
	ImeitemIMGeneric* gen = NULL;
	ImeitemIMPort* prt = NULL;
	ImeitemIMProcess* prc = NULL;
	ImeitemIMSignal* sig = NULL;
	ImeitemIAVKeylistKey* klsAkey = NULL;
	ImeitemICVariable* varC = NULL;
	ImeitemIMCommand* cmd = NULL;
	ImeitemIMError* err = NULL;
	ImeitemIMFsm* fsm = NULL;
	ImeitemIMVariable* var = NULL;
	ImeitemIMVector* vec = NULL;
	ImeitemIAMCommandInvpar* cmdAipa = NULL;
	ImeitemIAMCommandRetpar* cmdArpa = NULL;
	ImeitemIAMErrorPar* errApar = NULL;
	ImeitemICFsmstate* fstC = NULL;
	ImeitemIJAVKeylistKey* kakJkey = NULL;
	ImeitemIMFsmstate* fst = NULL;
	ImeitemIAMFsmstateStep* fstAstp = NULL;

	set<ubigint> irefs1, irefs2, irefs3;

	uint num0, num1, num2, num3, num4;

	// IP enterSgeImport.prep --- INSERT

	try {
		// IP enterSgeImport.traverse --- BEGIN

		// -- ImeIAMCoreversionIp
		num0 = 1;

		for (unsigned int ix0 = 0; ix0 < imeiamcoreversionip.nodes.size(); ix0++) {
			cvrAipx = imeiamcoreversionip.nodes[ix0];

			//cvrAipx->cvrRefWdbeMCoreversion: PRESET
			cvrAipx->cvrNum = num0++;
			//cvrAipx->sref: TBL
			cvrAipx->ixVTagtype = VecWdbeVAMCoreversionIpTagtype::getIx(cvrAipx->srefIxVTagtype);
			if (cvrAipx->ixVTagtype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",cvrAipx->srefIxVTagtype}, {"iel","srefIxVTagtype"}, {"lineno",to_string(cvrAipx->lineno)}});
			//cvrAipx->Comment: TBL

			dbswdbe->tblwdbeamcoreversionip->insertRec(cvrAipx);
			impcnt++;
		};

		// -- ImeIAMCoreversionPlh
		num0 = 1;

		for (unsigned int ix0 = 0; ix0 < imeiamcoreversionplh.nodes.size(); ix0++) {
			cvrAplh = imeiamcoreversionplh.nodes[ix0];

			//cvrAplh->cvrRefWdbeMCoreversion: PRESET
			cvrAplh->cvrNum = num0++;
			//cvrAplh->sref: TBL
			//cvrAplh->Comment: TBL

			dbswdbe->tblwdbeamcoreversionplh->insertRec(cvrAplh);
			impcnt++;
		};

		// -- ImeIMModule
		for (unsigned int ix0 = 0; ix0 < imeimmodule.nodes.size(); ix0++) {
			mdl = imeimmodule.nodes[ix0];

			// retrieve
			//if (mdl->ref == 0) throw SbeException(SbeException::IEX_RETR, {{"ime","ImeIMModule"}, {"lineno",to_string(mdl->lineno)}});

			mdl->hkIxVTbl = VecWdbeVMModuleHkTbl::CVR;
			//mdl->hkUref: PRESET
			//mdl->supRefWdbeMModule: CUSTSQL
			//if (mdl->supRefWdbeMModule == 0) throw SbeException(SbeException::IEX_THSREF, {{"thsref",mdl->hsrefSupRefWdbeMModule}, {"iel","hsrefSupRefWdbeMModule"}, {"lineno",to_string(mdl->lineno)}});
			//mdl->sref: TBL

			irefs1.clear();

			for (unsigned int ix1 = 0; ix1 < mdl->imeicgeneric.nodes.size(); ix1++) {
				genC = mdl->imeicgeneric.nodes[ix1];

				if (irefs1.find(genC->iref) != irefs1.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(genC->iref)}, {"ime","ImeICGeneric"}, {"lineno",to_string(genC->lineno)}});
				genC->ref = dbswdbe->tblwdbecgeneric->getNewRef();
				irefs1.insert(genC->iref);

				impcnt++;
			};

			irefs1.clear();

			for (unsigned int ix1 = 0; ix1 < mdl->imeicport.nodes.size(); ix1++) {
				prtC = mdl->imeicport.nodes[ix1];

				if (irefs1.find(prtC->iref) != irefs1.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(prtC->iref)}, {"ime","ImeICPort"}, {"lineno",to_string(prtC->lineno)}});
				prtC->ref = dbswdbe->tblwdbecport->getNewRef();
				irefs1.insert(prtC->iref);

				impcnt++;
			};

			irefs1.clear();

			for (unsigned int ix1 = 0; ix1 < mdl->imeicsignal.nodes.size(); ix1++) {
				sigC = mdl->imeicsignal.nodes[ix1];

				if (irefs1.find(sigC->iref) != irefs1.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(sigC->iref)}, {"ime","ImeICSignal"}, {"lineno",to_string(sigC->lineno)}});
				sigC->ref = dbswdbe->tblwdbecsignal->getNewRef();
				irefs1.insert(sigC->iref);

				impcnt++;
			};

			for (unsigned int ix1 = 0; ix1 < mdl->imeimcontroller.nodes.size(); ix1++) {
				ctr = mdl->imeimcontroller.nodes[ix1];

				// retrieve
				//if (ctr->ref == 0) throw SbeException(SbeException::IEX_RETR, {{"ime","ImeIMController"}, {"lineno",to_string(ctr->lineno)}});

				ctr->ixWdbeVIop = VecWdbeVIop::getIx(ctr->srefIxWdbeVIop);
				if ((ctr->ixWdbeVIop != VecWdbeVIop::RETR) && (ctr->ixWdbeVIop != VecWdbeVIop::RETRUPD)) throw SbeException(SbeException::IEX_IOP, {{"iop",ctr->srefIxWdbeVIop}, {"ime","ImeIMController"}, {"lineno",to_string(ctr->lineno)}});
				ctr->refWdbeMModule = mdl->ref;
				//ctr->clrRefWdbeMSignal: IMPPP

				for (unsigned int ix2 = 0; ix2 < ctr->imeimcommand.nodes.size(); ix2++) {
					cmd = ctr->imeimcommand.nodes[ix2];

					cmd->refIxVTbl = VecWdbeVMCommandRefTbl::CTR;
					cmd->refUref = ctr->ref;
					//cmd->refNum: TBL
					//cmd->sref: TBL
					//cmd->Fullsref: CUST
					cmd->ixVRettype = VecWdbeVMCommandRettype::getIx(cmd->srefIxVRettype);
					if (cmd->ixVRettype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",cmd->srefIxVRettype}, {"iel","srefIxVRettype"}, {"lineno",to_string(cmd->lineno)}});
					//cmd->ivrRefWdbeMSignal: IMPPP
					//cmd->rvrRefWdbeMSignal: IMPPP
					//cmd->rerRefWdbeMSignal: IMPPP
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
						//if (cmdAipa->refWdbeMVector == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",cmdAipa->srefRefWdbeMVector}, {"iel","srefRefWdbeMVector"}, {"lineno",to_string(cmdAipa->lineno)}});
						//cmdAipa->Length: TBL
						//cmdAipa->Defval: TBL
						//cmdAipa->refWdbeMVectoritem: CUSTSQL
						//if (cmdAipa->refWdbeMVectoritem == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",cmdAipa->srefRefWdbeMVectoritem}, {"iel","srefRefWdbeMVectoritem"}, {"lineno",to_string(cmdAipa->lineno)}});
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
						//if (cmdArpa->refWdbeMVector == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",cmdArpa->srefRefWdbeMVector}, {"iel","srefRefWdbeMVector"}, {"lineno",to_string(cmdArpa->lineno)}});
						//cmdArpa->Length: TBL
						//cmdArpa->Comment: TBL

						dbswdbe->tblwdbeamcommandretpar->insertRec(cmdArpa);
						impcnt++;
					};
				};

				for (unsigned int ix2 = 0; ix2 < ctr->imeimerror.nodes.size(); ix2++) {
					err = ctr->imeimerror.nodes[ix2];

					err->refIxVTbl = VecWdbeVMErrorRefTbl::CTR;
					err->refUref = ctr->ref;
					//err->refNum: TBL
					//err->sref: TBL
					//err->Fullsref: CUST
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
						//if (errApar->refWdbeMVector == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",errApar->srefRefWdbeMVector}, {"iel","srefRefWdbeMVector"}, {"lineno",to_string(errApar->lineno)}});
						//errApar->Length: TBL
						//errApar->Comment: TBL

						dbswdbe->tblwdbeamerrorpar->insertRec(errApar);
						impcnt++;
					};
				};

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
				};
			};

			for (unsigned int ix1 = 0; ix1 < mdl->imeimgeneric.nodes.size(); ix1++) {
				gen = mdl->imeimgeneric.nodes[ix1];

				// retrieve
				//if (gen->ref == 0) throw SbeException(SbeException::IEX_RETR, {{"ime","ImeIMGeneric"}, {"lineno",to_string(gen->lineno)}});

				gen->ixWdbeVIop = VecWdbeVIop::getIx(gen->srefIxWdbeVIop);
				if ((gen->ixWdbeVIop != VecWdbeVIop::INS) && (gen->ixWdbeVIop != VecWdbeVIop::RETRUPD)) throw SbeException(SbeException::IEX_IOP, {{"iop",gen->srefIxWdbeVIop}, {"ime","ImeIMGeneric"}, {"lineno",to_string(gen->lineno)}});
				//gen->refWdbeCGeneric: PREVIMP
				//if (gen->refWdbeCGeneric == 0) throw SbeException(SbeException::IEX_IREF, {{"iref",to_string(gen->irefRefWdbeCGeneric)}, {"iel","irefRefWdbeCGeneric"}, {"lineno",to_string(gen->lineno)}});
				gen->mdlRefWdbeMModule = mdl->ref;
				//gen->mdlNum: CUST
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

			for (unsigned int ix1 = 0; ix1 < mdl->imeimport.nodes.size(); ix1++) {
				prt = mdl->imeimport.nodes[ix1];

				// retrieve
				//if (prt->ref == 0) throw SbeException(SbeException::IEX_RETR, {{"ime","ImeIMPort"}, {"lineno",to_string(prt->lineno)}});

				prt->ixWdbeVIop = VecWdbeVIop::getIx(prt->srefIxWdbeVIop);
				if ((prt->ixWdbeVIop != VecWdbeVIop::INS) && (prt->ixWdbeVIop != VecWdbeVIop::RETRUPD)) throw SbeException(SbeException::IEX_IOP, {{"iop",prt->srefIxWdbeVIop}, {"ime","ImeIMPort"}, {"lineno",to_string(prt->lineno)}});
				//prt->refWdbeCPort: PREVIMP
				//if (prt->refWdbeCPort == 0) throw SbeException(SbeException::IEX_IREF, {{"iref",to_string(prt->irefRefWdbeCPort)}, {"iel","irefRefWdbeCPort"}, {"lineno",to_string(prt->lineno)}});
				prt->mdlRefWdbeMModule = mdl->ref;
				//prt->mdlNum: CUST
				prt->mdlIxVCat = VecWdbeVMPortMdlCat::getIx(prt->srefMdlIxVCat);
				if (prt->mdlIxVCat == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",prt->srefMdlIxVCat}, {"iel","srefMdlIxVCat"}, {"lineno",to_string(prt->lineno)}});
				//prt->sref: TBL
				prt->ixVDir = VecWdbeVMPortDir::getIx(prt->srefIxVDir);
				if (prt->ixVDir == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",prt->srefIxVDir}, {"iel","srefIxVDir"}, {"lineno",to_string(prt->lineno)}});
				//prt->srefWdbeKHdltype: TBL
				//prt->Width: TBL
				//prt->Minmax: TBL
				//prt->Defval: TBL
				//prt->cprSrefWdbeMPort: TBL
				//prt->csiSrefWdbeMSignal: TBL
				//prt->Comment: TBL

				dbswdbe->tblwdbemport->insertRec(prt);
				impcnt++;
			};

			for (unsigned int ix1 = 0; ix1 < mdl->imeimprocess.nodes.size(); ix1++) {
				prc = mdl->imeimprocess.nodes[ix1];

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

				num2 = 1;

				for (unsigned int ix2 = 0; ix2 < prc->imeiavkeylistkey.nodes.size(); ix2++) {
					klsAkey = prc->imeiavkeylistkey.nodes[ix2];

					klsAkey->klsIxWdbeVKeylist = VecWdbeVKeylist::KLSTWDBEKHDLTYPE;
					klsAkey->klsNum = num2++;
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
						kakJkey->lineno = klsAkey->lineno;
						klsAkey->imeijavkeylistkey.nodes.push_back(kakJkey);

						kakJkey->refWdbeAVKeylistKey = klsAkey->ref;
						kakJkey->Title = klsAkey->Title;
						kakJkey->Comment = klsAkey->Comment;
					};

					for (unsigned int ix3 = 0; ix3 < klsAkey->imeijavkeylistkey.nodes.size(); ix3++) {
						kakJkey = klsAkey->imeijavkeylistkey.nodes[ix3];

						kakJkey->refWdbeAVKeylistKey = klsAkey->ref;
						kakJkey->x1IxWdbeVLocale = VecWdbeVLocale::ENUS;
						//kakJkey->Title: TBL
						//kakJkey->Comment: TBL

						dbswdbe->tblwdbejavkeylistkey->insertRec(kakJkey);
						impcnt++;

						if (ix3 == 0) {
							klsAkey->refJ = kakJkey->ref;
							klsAkey->Title = kakJkey->Title;
							klsAkey->Comment = kakJkey->Comment;
							dbswdbe->tblwdbeavkeylistkey->updateRec(klsAkey);
						};
					};
				};

				irefs2.clear();

				for (unsigned int ix2 = 0; ix2 < prc->imeicvariable.nodes.size(); ix2++) {
					varC = prc->imeicvariable.nodes[ix2];

					if (irefs2.find(varC->iref) != irefs2.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(varC->iref)}, {"ime","ImeICVariable"}, {"lineno",to_string(varC->lineno)}});
					varC->ref = dbswdbe->tblwdbecvariable->getNewRef();
					irefs2.insert(varC->iref);

					impcnt++;
				};

				for (unsigned int ix2 = 0; ix2 < prc->imeimfsm.nodes.size(); ix2++) {
					fsm = prc->imeimfsm.nodes[ix2];

					fsm->refWdbeMProcess = prc->ref;

					dbswdbe->tblwdbemfsm->insertRec(fsm);
					impcnt++;

					if (ix2 == 0) {
						prc->refWdbeMFsm = fsm->ref;
						dbswdbe->tblwdbemprocess->updateRec(prc);
					};

					irefs3.clear();

					for (unsigned int ix3 = 0; ix3 < fsm->imeicfsmstate.nodes.size(); ix3++) {
						fstC = fsm->imeicfsmstate.nodes[ix3];

						if (irefs3.find(fstC->iref) != irefs3.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(fstC->iref)}, {"ime","ImeICFsmstate"}, {"lineno",to_string(fstC->lineno)}});
						fstC->ref = dbswdbe->tblwdbecfsmstate->getNewRef();
						irefs3.insert(fstC->iref);

						impcnt++;
					};

					num3 = 1;

					for (unsigned int ix3 = 0; ix3 < fsm->imeimfsmstate.nodes.size(); ix3++) {
						fst = fsm->imeimfsmstate.nodes[ix3];

						//fst->refWdbeCFsmstate: PREVIMP
						//if (fst->refWdbeCFsmstate == 0) throw SbeException(SbeException::IEX_IREF, {{"iref",to_string(fst->irefRefWdbeCFsmstate)}, {"iel","irefRefWdbeCFsmstate"}, {"lineno",to_string(fst->lineno)}});
						fst->fsmRefWdbeMFsm = fsm->ref;
						fst->fsmNum = num3++;
						//fst->sref: TBL
						//fst->Extip: TBL
						//fst->Comment: TBL

						dbswdbe->tblwdbemfsmstate->insertRec(fst);
						impcnt++;

						num4 = 1;

						for (unsigned int ix4 = 0; ix4 < fst->imeiamfsmstatestep.nodes.size(); ix4++) {
							fstAstp = fst->imeiamfsmstatestep.nodes[ix4];

							fstAstp->fstRefWdbeMFsmstate = fst->ref;
							fstAstp->fstNum = num4++;
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

				num2 = 1;

				for (unsigned int ix2 = 0; ix2 < prc->imeimvariable.nodes.size(); ix2++) {
					var = prc->imeimvariable.nodes[ix2];

					//var->refWdbeCVariable: PREVIMP
					//if (var->refWdbeCVariable == 0) throw SbeException(SbeException::IEX_IREF, {{"iref",to_string(var->irefRefWdbeCVariable)}, {"iel","irefRefWdbeCVariable"}, {"lineno",to_string(var->lineno)}});
					var->refIxVTbl = VecWdbeVMVariableRefTbl::PRC;
					var->refUref = prc->ref;
					var->refNum = num2++;
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
			};

			num1 = 1;

			for (unsigned int ix1 = 0; ix1 < mdl->imeimsignal.nodes.size(); ix1++) {
				sig = mdl->imeimsignal.nodes[ix1];

				sig->ixVBasetype = VecWdbeVMSignalBasetype::getIx(sig->srefIxVBasetype);
				if (sig->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",sig->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(sig->lineno)}});
				//sig->refWdbeCSignal: PREVIMP
				//if (sig->refWdbeCSignal == 0) throw SbeException(SbeException::IEX_IREF, {{"iref",to_string(sig->irefRefWdbeCSignal)}, {"iel","irefRefWdbeCSignal"}, {"lineno",to_string(sig->lineno)}});
				sig->refIxVTbl = VecWdbeVMSignalRefTbl::MDL;
				sig->refUref = mdl->ref;
				sig->refNum = num1++;
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
				//sig->drvRefWdbeMPort: PREVIMP
				//if (sig->drvRefWdbeMPort == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",sig->srefDrvRefWdbeMPort}, {"iel","srefDrvRefWdbeMPort"}, {"lineno",to_string(sig->lineno)}});
				//sig->Comment: TBL

				dbswdbe->tblwdbemsignal->insertRec(sig);
				impcnt++;
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

void JobWdbeIexDcd::leaveSgeImport(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeImport --- INSERT
};

uint JobWdbeIexDcd::enterSgeImperr(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IMPERR;

	// IP enterSgeImperr --- INSERT

	return retval;
};

void JobWdbeIexDcd::leaveSgeImperr(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeImperr --- INSERT
};

uint JobWdbeIexDcd::enterSgeReverse(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::IDLE;
	retval = nextIxVSgeSuccess;

	ImeitemIAMCoreversionIp* cvrAipx = NULL;
	ImeitemIAMCoreversionPlh* cvrAplh = NULL;
	ImeitemIMModule* mdl = NULL;
	ImeitemIMController* ctr = NULL;
	ImeitemIMGeneric* gen = NULL;
	ImeitemIMPort* prt = NULL;
	ImeitemIMProcess* prc = NULL;
	ImeitemIMSignal* sig = NULL;
	ImeitemIAVKeylistKey* klsAkey = NULL;
	ImeitemIMCommand* cmd = NULL;
	ImeitemIMError* err = NULL;
	ImeitemIMFsm* fsm = NULL;
	ImeitemIMVariable* var = NULL;
	ImeitemIMVector* vec = NULL;
	ImeitemIAMCommandInvpar* cmdAipa = NULL;
	ImeitemIAMCommandRetpar* cmdArpa = NULL;
	ImeitemIAMErrorPar* errApar = NULL;
	ImeitemIJAVKeylistKey* kakJkey = NULL;
	ImeitemIMFsmstate* fst = NULL;
	ImeitemIAMFsmstateStep* fstAstp = NULL;

	// -- ImeIAMCoreversionIp
	for (unsigned int ix0 = 0; ix0 < imeiamcoreversionip.nodes.size(); ix0++) {
		cvrAipx = imeiamcoreversionip.nodes[ix0];
		if (cvrAipx->ref != 0) dbswdbe->tblwdbeamcoreversionip->removeRecByRef(cvrAipx->ref);
	};

	// -- ImeIAMCoreversionPlh
	for (unsigned int ix0 = 0; ix0 < imeiamcoreversionplh.nodes.size(); ix0++) {
		cvrAplh = imeiamcoreversionplh.nodes[ix0];
		if (cvrAplh->ref != 0) dbswdbe->tblwdbeamcoreversionplh->removeRecByRef(cvrAplh->ref);
	};

	// -- ImeIMModule
	for (unsigned int ix0 = 0; ix0 < imeimmodule.nodes.size(); ix0++) {
		mdl = imeimmodule.nodes[ix0];
		if (mdl->ref != 0) dbswdbe->tblwdbemmodule->removeRecByRef(mdl->ref);

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
			};
		};

		for (unsigned int ix1 = 0; ix1 < mdl->imeimgeneric.nodes.size(); ix1++) {
			gen = mdl->imeimgeneric.nodes[ix1];
			if (gen->ref != 0) dbswdbe->tblwdbemgeneric->removeRecByRef(gen->ref);
		};

		for (unsigned int ix1 = 0; ix1 < mdl->imeimport.nodes.size(); ix1++) {
			prt = mdl->imeimport.nodes[ix1];
			if (prt->ref != 0) dbswdbe->tblwdbemport->removeRecByRef(prt->ref);
		};

		for (unsigned int ix1 = 0; ix1 < mdl->imeimprocess.nodes.size(); ix1++) {
			prc = mdl->imeimprocess.nodes[ix1];
			if (prc->ref != 0) dbswdbe->tblwdbemprocess->removeRecByRef(prc->ref);

			for (unsigned int ix2 = 0; ix2 < prc->imeiavkeylistkey.nodes.size(); ix2++) {
				klsAkey = prc->imeiavkeylistkey.nodes[ix2];
				if (klsAkey->ref != 0) dbswdbe->tblwdbeavkeylistkey->removeRecByRef(klsAkey->ref);

				for (unsigned int ix3 = 0; ix3 < klsAkey->imeijavkeylistkey.nodes.size(); ix3++) {
					kakJkey = klsAkey->imeijavkeylistkey.nodes[ix3];
					if (kakJkey->ref != 0) dbswdbe->tblwdbejavkeylistkey->removeRecByRef(kakJkey->ref);
				};
			};

			for (unsigned int ix2 = 0; ix2 < prc->imeimfsm.nodes.size(); ix2++) {
				fsm = prc->imeimfsm.nodes[ix2];
				if (fsm->ref != 0) dbswdbe->tblwdbemfsm->removeRecByRef(fsm->ref);

				for (unsigned int ix3 = 0; ix3 < fsm->imeimfsmstate.nodes.size(); ix3++) {
					fst = fsm->imeimfsmstate.nodes[ix3];
					if (fst->ref != 0) dbswdbe->tblwdbemfsmstate->removeRecByRef(fst->ref);

					for (unsigned int ix4 = 0; ix4 < fst->imeiamfsmstatestep.nodes.size(); ix4++) {
						fstAstp = fst->imeiamfsmstatestep.nodes[ix4];
						if (fstAstp->ref != 0) dbswdbe->tblwdbeamfsmstatestep->removeRecByRef(fstAstp->ref);
					};
				};
			};

			for (unsigned int ix2 = 0; ix2 < prc->imeimvariable.nodes.size(); ix2++) {
				var = prc->imeimvariable.nodes[ix2];
				if (var->ref != 0) dbswdbe->tblwdbemvariable->removeRecByRef(var->ref);
			};
		};

		for (unsigned int ix1 = 0; ix1 < mdl->imeimsignal.nodes.size(); ix1++) {
			sig = mdl->imeimsignal.nodes[ix1];
			if (sig->ref != 0) dbswdbe->tblwdbemsignal->removeRecByRef(sig->ref);
		};
	};

	return retval;
};

void JobWdbeIexDcd::leaveSgeReverse(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeReverse --- INSERT
};

uint JobWdbeIexDcd::enterSgeCollect(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::CLTDONE;
	retval = nextIxVSgeSuccess;

	ImeitemIAMCoreversionIp* cvrAipx = NULL;
	ImeitemIAMCoreversionPlh* cvrAplh = NULL;
	ImeitemIMModule* mdl = NULL;
	ImeitemICGeneric* genC = NULL;
	ImeitemICPort* prtC = NULL;
	ImeitemICSignal* sigC = NULL;
	ImeitemIMController* ctr = NULL;
	ImeitemIMGeneric* gen = NULL;
	ImeitemIMPort* prt = NULL;
	ImeitemIMProcess* prc = NULL;
	ImeitemIMSignal* sig = NULL;
	ImeitemIAVKeylistKey* klsAkey = NULL;
	ImeitemICVariable* varC = NULL;
	ImeitemIMCommand* cmd = NULL;
	ImeitemIMError* err = NULL;
	ImeitemIMFsm* fsm = NULL;
	ImeitemIMVariable* var = NULL;
	ImeitemIMVector* vec = NULL;
	ImeitemIAMCommandInvpar* cmdAipa = NULL;
	ImeitemIAMCommandRetpar* cmdArpa = NULL;
	ImeitemIAMErrorPar* errApar = NULL;
	ImeitemICFsmstate* fstC = NULL;
	ImeitemIJAVKeylistKey* kakJkey = NULL;
	ImeitemIMFsmstate* fst = NULL;
	ImeitemIAMFsmstateStep* fstAstp = NULL;

	uint ixWdbeVIop;

	vector<ubigint> refs;

	Stcch* stcch = new Stcch(false);

	// IP enterSgeCollect.traverse --- BEGIN

	// -- ImeIAMCoreversionIp
	for (unsigned int ix0 = 0; ix0 < imeiamcoreversionip.nodes.size(); ix0++) {
		cvrAipx = imeiamcoreversionip.nodes[ix0];

		if (cvrAipx->ref != 0) {
		};
	};

	// -- ImeIAMCoreversionPlh
	for (unsigned int ix0 = 0; ix0 < imeiamcoreversionplh.nodes.size(); ix0++) {
		cvrAplh = imeiamcoreversionplh.nodes[ix0];

		if (cvrAplh->ref != 0) {
		};
	};

	// -- ImeIMModule
	for (unsigned int ix0 = 0; ix0 < imeimmodule.nodes.size(); ix0++) {
		mdl = imeimmodule.nodes[ix0];

		if (mdl->ref != 0) {
			mdl->hsrefSupRefWdbeMModule = StubWdbe::getStubMdlHsref(dbswdbe, mdl->supRefWdbeMModule, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
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

		for (unsigned int ix1 = 0; ix1 < mdl->imeicsignal.nodes.size(); ix1++) {
			sigC = mdl->imeicsignal.nodes[ix1];

			if (sigC->ref != 0) {
				sigC->iref = ix1+1;
			};
		};

		if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMCONTROLLER, ixWdbeVIop)) {
			dbswdbe->tblwdbemcontroller->loadRefsByMdl(mdl->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) mdl->imeimcontroller.nodes.push_back(new ImeitemIMController(dbswdbe, ixWdbeVIop, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < mdl->imeimcontroller.nodes.size(); ix1++) {
			ctr = mdl->imeimcontroller.nodes[ix1];

			if (ctr->ref != 0) {
				//ctr->srefIxWdbeVIop: IOP
				ctr->srefClrRefWdbeMSignal = StubWdbe::getStubSigSref(dbswdbe, ctr->clrRefWdbeMSignal, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
			};

			if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMCOMMAND, ixWdbeVIop)) {
				dbswdbe->tblwdbemcommand->loadRefsByRetReu(VecWdbeVMCommandRefTbl::CTR, ctr->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) ctr->imeimcommand.nodes.push_back(new ImeitemIMCommand(dbswdbe, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < ctr->imeimcommand.nodes.size(); ix2++) {
				cmd = ctr->imeimcommand.nodes[ix2];

				if (cmd->ref != 0) {
					cmd->srefIvrRefWdbeMSignal = StubWdbe::getStubSigSref(dbswdbe, cmd->ivrRefWdbeMSignal, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
					cmd->srefRvrRefWdbeMSignal = StubWdbe::getStubSigSref(dbswdbe, cmd->rvrRefWdbeMSignal, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
					cmd->srefRerRefWdbeMSignal = StubWdbe::getStubSigSref(dbswdbe, cmd->rerRefWdbeMSignal, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
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
			};
		};

		if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMGENERIC, ixWdbeVIop)) {
			dbswdbe->tblwdbemgeneric->loadRefsByMdl(mdl->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) mdl->imeimgeneric.nodes.push_back(new ImeitemIMGeneric(dbswdbe, ixWdbeVIop, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < mdl->imeimgeneric.nodes.size(); ix1++) {
			gen = mdl->imeimgeneric.nodes[ix1];

			if (gen->ref != 0) {
				//gen->srefIxWdbeVIop: IOP
				//gen->irefRefWdbeCGeneric: IREF
			};
		};

		if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMPORT, ixWdbeVIop)) {
			dbswdbe->tblwdbemport->loadRefsByMdl(mdl->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) mdl->imeimport.nodes.push_back(new ImeitemIMPort(dbswdbe, ixWdbeVIop, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < mdl->imeimport.nodes.size(); ix1++) {
			prt = mdl->imeimport.nodes[ix1];

			if (prt->ref != 0) {
				//prt->srefIxWdbeVIop: IOP
				//prt->irefRefWdbeCPort: IREF
			};
		};

		if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMPROCESS, ixWdbeVIop)) {
			dbswdbe->tblwdbemprocess->loadRefsByMdl(mdl->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) mdl->imeimprocess.nodes.push_back(new ImeitemIMProcess(dbswdbe, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < mdl->imeimprocess.nodes.size(); ix1++) {
			prc = mdl->imeimprocess.nodes[ix1];

			if (prc->ref != 0) {
			};

			if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIAVKEYLISTKEY, ixWdbeVIop)) {
				dbswdbe->tblwdbeavkeylistkey->loadRefsByMtbUrf(VecWdbeVMaintable::TBLWDBEMPROCESS, prc->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) prc->imeiavkeylistkey.nodes.push_back(new ImeitemIAVKeylistKey(dbswdbe, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < prc->imeiavkeylistkey.nodes.size(); ix2++) {
				klsAkey = prc->imeiavkeylistkey.nodes[ix2];

				if (klsAkey->ref != 0) {
				};

				if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIJAVKEYLISTKEY, ixWdbeVIop)) {
					dbswdbe->tblwdbejavkeylistkey->loadRefsByKlk(klsAkey->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == klsAkey->refJ) {refs[i] = refs[0]; refs[0] = klsAkey->refJ; break;};
					for (unsigned int i = 0; i < refs.size(); i++) klsAkey->imeijavkeylistkey.nodes.push_back(new ImeitemIJAVKeylistKey(dbswdbe, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < klsAkey->imeijavkeylistkey.nodes.size(); ix3++) {
					kakJkey = klsAkey->imeijavkeylistkey.nodes[ix3];

					if (kakJkey->ref != 0) {
					};
				};
			};

			for (unsigned int ix2 = 0; ix2 < prc->imeicvariable.nodes.size(); ix2++) {
				varC = prc->imeicvariable.nodes[ix2];

				if (varC->ref != 0) {
					varC->iref = ix2+1;
				};
			};

			if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMFSM, ixWdbeVIop)) {
				dbswdbe->tblwdbemfsm->loadRefsByPrc(prc->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) prc->imeimfsm.nodes.push_back(new ImeitemIMFsm(dbswdbe, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < prc->imeimfsm.nodes.size(); ix2++) {
				fsm = prc->imeimfsm.nodes[ix2];

				if (fsm->ref != 0) {
				};

				for (unsigned int ix3 = 0; ix3 < fsm->imeicfsmstate.nodes.size(); ix3++) {
					fstC = fsm->imeicfsmstate.nodes[ix3];

					if (fstC->ref != 0) {
						fstC->iref = ix3+1;
					};
				};

				if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMFSMSTATE, ixWdbeVIop)) {
					dbswdbe->tblwdbemfsmstate->loadRefsByFsm(fsm->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) fsm->imeimfsmstate.nodes.push_back(new ImeitemIMFsmstate(dbswdbe, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < fsm->imeimfsmstate.nodes.size(); ix3++) {
					fst = fsm->imeimfsmstate.nodes[ix3];

					if (fst->ref != 0) {
						//fst->irefRefWdbeCFsmstate: IREF
					};

					if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIAMFSMSTATESTEP, ixWdbeVIop)) {
						dbswdbe->tblwdbeamfsmstatestep->loadRefsByFst(fst->ref, false, refs);
						for (unsigned int i = 0; i < refs.size(); i++) fst->imeiamfsmstatestep.nodes.push_back(new ImeitemIAMFsmstateStep(dbswdbe, refs[i]));
					};

					for (unsigned int ix4 = 0; ix4 < fst->imeiamfsmstatestep.nodes.size(); ix4++) {
						fstAstp = fst->imeiamfsmstatestep.nodes[ix4];

						if (fstAstp->ref != 0) {
							fstAstp->srefFnxRefWdbeMFsmstate = StubWdbe::getStubFstStd(dbswdbe, fstAstp->fnxRefWdbeMFsmstate, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
						};
					};
				};
			};

			if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMVARIABLE, ixWdbeVIop)) {
				dbswdbe->tblwdbemvariable->loadRefsByRetReu(VecWdbeVMVariableRefTbl::PRC, prc->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) prc->imeimvariable.nodes.push_back(new ImeitemIMVariable(dbswdbe, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < prc->imeimvariable.nodes.size(); ix2++) {
				var = prc->imeimvariable.nodes[ix2];

				if (var->ref != 0) {
					//var->irefRefWdbeCVariable: IREF
				};
			};
		};

		if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMSIGNAL, ixWdbeVIop)) {
			dbswdbe->tblwdbemsignal->loadRefsByRetReu(VecWdbeVMSignalRefTbl::MDL, mdl->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) mdl->imeimsignal.nodes.push_back(new ImeitemIMSignal(dbswdbe, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < mdl->imeimsignal.nodes.size(); ix1++) {
			sig = mdl->imeimsignal.nodes[ix1];

			if (sig->ref != 0) {
				//sig->irefRefWdbeCSignal: IREF
				//sig->srefMgeUref: STUB
				sig->srefDrvRefWdbeMPort = StubWdbe::getStubPrtSref(dbswdbe, sig->drvRefWdbeMPort, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
			};
		};
	};
	// IP enterSgeCollect.traverse --- END
	// IP enterSgeCollect.ppr --- INSERT

	delete stcch;

	return retval;
};

void JobWdbeIexDcd::leaveSgeCollect(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeCollect --- INSERT
};

uint JobWdbeIexDcd::enterSgeCltdone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::CLTDONE;

	// IP enterSgeCltdone --- INSERT

	return retval;
};

void JobWdbeIexDcd::leaveSgeCltdone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeCltdone --- INSERT
};

uint JobWdbeIexDcd::enterSgeExport(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	IexWdbeDcd::exportToFile(fullpath, xmlNotTxt, shorttags, imeiamcoreversionip, imeiamcoreversionplh, imeimmodule);

	return retval;
};

void JobWdbeIexDcd::leaveSgeExport(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeExport --- INSERT
};

uint JobWdbeIexDcd::enterSgeDone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void JobWdbeIexDcd::leaveSgeDone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeDone --- INSERT
};
