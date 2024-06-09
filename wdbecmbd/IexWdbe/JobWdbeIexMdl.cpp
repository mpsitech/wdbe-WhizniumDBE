/**
	* \file JobWdbeIexMdl.cpp
	* job handler for job JobWdbeIexMdl (implementation)
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

#include "JobWdbeIexMdl.h"

#include "JobWdbeIexMdl_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

using namespace IexWdbeMdl;

/******************************************************************************
 class JobWdbeIexMdl
 ******************************************************************************/

JobWdbeIexMdl::JobWdbeIexMdl(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const uint ixWdbeVLocale
		) :
			JobWdbe(xchg, VecWdbeVJob::JOBWDBEIEXMDL, jrefSup, ixWdbeVLocale)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	changeStage(dbswdbe, VecVSge::IDLE);

	// IP constructor.cust3 --- INSERT

};

JobWdbeIexMdl::~JobWdbeIexMdl() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void JobWdbeIexMdl::reset(
			DbsWdbe* dbswdbe
		) {
	if (ixVSge != VecVSge::IDLE) changeStage(dbswdbe, VecVSge::IDLE);
};

void JobWdbeIexMdl::parseFromFile(
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

void JobWdbeIexMdl::import(
			DbsWdbe* dbswdbe
		) {
	if (ixVSge == VecVSge::PRSDONE) changeStage(dbswdbe, VecVSge::IMPORT);
};

void JobWdbeIexMdl::reverse(
			DbsWdbe* dbswdbe
		) {
	if (ixVSge == VecVSge::IMPERR) changeStage(dbswdbe, VecVSge::REVERSE);
};

void JobWdbeIexMdl::collect(
			DbsWdbe* dbswdbe
			, const map<uint,uint>& _icsWdbeVIop
		) {
	if (ixVSge == VecVSge::IDLE) {
		icsWdbeVIop = _icsWdbeVIop;
		changeStage(dbswdbe, VecVSge::COLLECT);
	};
};

void JobWdbeIexMdl::exportToFile(
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

void JobWdbeIexMdl::handleRequest(
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

void JobWdbeIexMdl::changeStage(
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

string JobWdbeIexMdl::getSquawk(
			DbsWdbe* dbswdbe
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::PARSE) || (ixVSge == VecVSge::PRSDONE) || (ixVSge == VecVSge::IMPORT) || (ixVSge == VecVSge::REVERSE) || (ixVSge == VecVSge::COLLECT) || (ixVSge == VecVSge::CLTDONE) || (ixVSge == VecVSge::EXPORT) ) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing modular structure";
			else if (ixVSge == VecVSge::PRSDONE) retval = "modular structure parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing modular structure (" + to_string(impcnt) + " records added)";
			else if (ixVSge == VecVSge::REVERSE) retval = "reversing modular structure import";
			else if (ixVSge == VecVSge::COLLECT) retval = "collecting modular structure for export";
			else if (ixVSge == VecVSge::CLTDONE) retval = "modular structure collected for export";
			else if (ixVSge == VecVSge::EXPORT) retval = "exporting modular structure";
		};

	} else if ( (ixVSge == VecVSge::PRSERR) || (ixVSge == VecVSge::IMPERR) ) {
		retval = lasterror;

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

uint JobWdbeIexMdl::enterSgeIdle(
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

void JobWdbeIexMdl::leaveSgeIdle(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWdbeIexMdl::enterSgeParse(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::PRSDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::PRSERR;

	try {
		IexWdbeMdl::parseFromFile(fullpath, xmlNotTxt, rectpath, imeimunit);

	} catch (SbeException& e) {
		if (e.ix == SbeException::PATHNF) e.vals["path"] = "<hidden>";
		lasterror = e.getSquawk(VecWdbeVError::getIx, VecWdbeVError::getTitle, ixWdbeVLocale);

		retval = nextIxVSgeFailure;
	};

	return retval;
};

void JobWdbeIexMdl::leaveSgeParse(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeParse --- INSERT
};

uint JobWdbeIexMdl::enterSgePrserr(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::PRSERR;

	// IP enterSgePrserr --- INSERT

	return retval;
};

void JobWdbeIexMdl::leaveSgePrserr(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgePrserr --- INSERT
};

uint JobWdbeIexMdl::enterSgePrsdone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::PRSDONE;

	// IP enterSgePrsdone --- INSERT

	return retval;
};

void JobWdbeIexMdl::leaveSgePrsdone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgePrsdone --- INSERT
};

uint JobWdbeIexMdl::enterSgeImport(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IMPERR;

	ImeitemIMUnit* unt = NULL;
	ImeitemIMModule* mdl = NULL;
	ImeitemIMPeripheral* pph = NULL;
	ImeitemIAMModulePar* mdlApar = NULL;
	ImeitemIAMPeripheralPar* pphApar = NULL;
	ImeitemIMController* ctr = NULL;
	ImeitemIMGeneric* gen = NULL;
	ImeitemIMImbuf* imb = NULL;
	ImeitemIRMModuleMModule* mdlRmdl = NULL;
	ImeitemIRMModuleMPeripheral* mdlRpph = NULL;

	uint num1, num2;

	// IP enterSgeImport.prep --- IBEGIN
	ubigint refWdbeMVersion;
	refWdbeMVersion = xchg->getRefPreset(VecWdbeVPreset::PREWDBEREFVER, jref);

	string Prjshort;

	ImeitemIMModule* mdl2 = NULL;

	string sref, srefrootMgmt, srefrootCor;

	dbswdbe->loadStringBySQL("SELECT TblWdbeMProject.Short FROM TblWdbeMProject, TblWdbeMVersion WHERE TblWdbeMProject.ref = TblWdbeMVersion.prjRefWdbeMProject AND TblWdbeMVersion.ref = " + to_string(refWdbeMVersion), Prjshort);
	Prjshort = StrMod::cap(Prjshort);
	// IP enterSgeImport.prep --- IEND

	try {
		// IP enterSgeImport.traverse --- RBEGIN

		// -- ImeIMUnit
		for (unsigned int ix0 = 0; ix0 < imeimunit.nodes.size(); ix0++) {
			unt = imeimunit.nodes[ix0];

			unt->ixVBasetype = VecWdbeVMUnitBasetype::getIx(unt->srefIxVBasetype);
			if (unt->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",unt->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(unt->lineno)}});
			unt->refIxVTbl = VecWdbeVMUnitRefTbl::VER;
			unt->refUref = refWdbeMVersion;
			//unt->silRefWdbeMUnit: CUSTSQL
			if (unt->srefSilRefWdbeMUnit != "") {
				dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMUnit WHERE refIxVTbl <> " + to_string(VecWdbeVMUnitRefTbl::VER) + " AND sref = '" + unt->srefSilRefWdbeMUnit + "'", unt->silRefWdbeMUnit);
				if (unt->silRefWdbeMUnit == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",unt->srefSilRefWdbeMUnit}, {"iel","srefSilRefWdbeMUnit"}, {"lineno",to_string(unt->lineno)}});
			};
			//unt->refWdbeMModule: SUB
			//unt->sref: TBL
			//unt->Fullsref: CUST
			unt->Fullsref = "Unt" + Prjshort + StrMod::cap(unt->sref);
			//unt->Title: TBL
			//unt->Easy: TBL
			//unt->srefKToolch: TBL
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

				for (unsigned int ix2 = 0; ix2 < pph->imeiamperipheralpar.nodes.size(); ix2++) {
					pphApar = pph->imeiamperipheralpar.nodes[ix2];

					pphApar->refWdbeMPeripheral = pph->ref;
					//pphApar->x1SrefKKey: TBL
					//pphApar->Val: TBL

					dbswdbe->tblwdbeamperipheralpar->insertRec(pphApar);
					impcnt++;
				};
			};

			num1 = 1;

			for (unsigned int ix1 = 0; ix1 < unt->imeimmodule.nodes.size(); ix1++) {
				mdl = unt->imeimmodule.nodes[ix1];

				mdl->ixVBasetype = VecWdbeVMModuleBasetype::getIx(mdl->srefIxVBasetype);
				if (mdl->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",mdl->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(mdl->lineno)}});
				mdl->hkIxVTbl = VecWdbeVMModuleHkTbl::UNT;
				mdl->hkUref = unt->ref;
				mdl->hkNum = num1++;
				//mdl->supRefWdbeMModule: IMPPP
				//mdl->tplRefWdbeMModule: CUSTSQL
				if (mdl->srefTplRefWdbeMModule != "") {
					dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::VOID) + " AND supRefWdbeMModule = 0 AND tplRefWdbeMModule = 0 AND sref = '" + mdl->srefTplRefWdbeMModule + "'", mdl->tplRefWdbeMModule);
					if (mdl->tplRefWdbeMModule == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",mdl->srefTplRefWdbeMModule}, {"iel","srefTplRefWdbeMModule"}, {"lineno",to_string(mdl->lineno)}});
				};
				//mdl->refWdbeMController: SUB
				//mdl->refWdbeMImbuf: SUB
				//mdl->sref: TBL
				//mdl->Comment: TBL

				dbswdbe->tblwdbemmodule->insertRec(mdl);
				impcnt++;

				for (unsigned int ix2 = 0; ix2 < mdl->imeirmmodulemmodule.nodes.size(); ix2++) {
					mdlRmdl = mdl->imeirmmodulemmodule.nodes[ix2];

					mdlRmdl->ctdRefWdbeMModule = mdl->ref;
					//mdlRmdl->corRefWdbeMModule: IMPPP
					//mdlRmdl->srefKFunction: TBL

					dbswdbe->tblwdbermmodulemmodule->insertRec(mdlRmdl);
					impcnt++;
				};

				for (unsigned int ix2 = 0; ix2 < mdl->imeimimbuf.nodes.size(); ix2++) {
					imb = mdl->imeimimbuf.nodes[ix2];

					imb->ixVRotype = VecWdbeVMImbufRotype::getIx(imb->srefIxVRotype);
					if (imb->ixVRotype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",imb->srefIxVRotype}, {"iel","srefIxVRotype"}, {"lineno",to_string(imb->lineno)}});
					imb->refWdbeMModule = mdl->ref;
					//imb->Fullsref: IMPPP
					//imb->Width: TBL
					//imb->Minmax: TBL
					//imb->Prio: TBL

					dbswdbe->tblwdbemimbuf->insertRec(imb);
					impcnt++;

					if (ix2 == 0) {
						mdl->refWdbeMImbuf = imb->ref;
						dbswdbe->tblwdbemmodule->updateRec(mdl);
					};
				};

				for (unsigned int ix2 = 0; ix2 < mdl->imeimcontroller.nodes.size(); ix2++) {
					ctr = mdl->imeimcontroller.nodes[ix2];

					ctr->refWdbeMModule = mdl->ref;
					//ctr->Fullsref: CUST
					ctr->Fullsref = "Ctr" + unt->Fullsref.substr(3) + StrMod::cap(mdl->sref);

					dbswdbe->tblwdbemcontroller->insertRec(ctr);
					impcnt++;

					if (ix2 == 0) {
						mdl->refWdbeMController = ctr->ref;
						dbswdbe->tblwdbemmodule->updateRec(mdl);
					};
				};

				num2 = 1;

				for (unsigned int ix2 = 0; ix2 < mdl->imeiammodulepar.nodes.size(); ix2++) {
					mdlApar = mdl->imeiammodulepar.nodes[ix2];

					mdlApar->mdlRefWdbeMModule = mdl->ref;
					mdlApar->mdlNum = num2++;
					//mdlApar->x1SrefKKey: TBL
					//mdlApar->Val: TBL

					dbswdbe->tblwdbeammodulepar->insertRec(mdlApar);
					impcnt++;
				};

				num2 = 1;

				for (unsigned int ix2 = 0; ix2 < mdl->imeimgeneric.nodes.size(); ix2++) {
					gen = mdl->imeimgeneric.nodes[ix2];

					gen->mdlRefWdbeMModule = mdl->ref;
					gen->mdlNum = num2++;
					//gen->sref: TBL
					//gen->Defval: TBL

					dbswdbe->tblwdbemgeneric->insertRec(gen);
					impcnt++;
				};

				for (unsigned int ix2 = 0; ix2 < mdl->imeirmmodulemperipheral.nodes.size(); ix2++) {
					mdlRpph = mdl->imeirmmodulemperipheral.nodes[ix2];

					mdlRpph->refWdbeMModule = mdl->ref;
					//mdlRpph->refWdbeMPeripheral: PREVIMP
					for (unsigned int i = 0; i < unt->imeimperipheral.nodes.size(); i++)
						if (unt->imeimperipheral.nodes[i]->sref == mdlRpph->srefRefWdbeMPeripheral) {
							mdlRpph->refWdbeMPeripheral = unt->imeimperipheral.nodes[i]->ref;
							break;
						};
					if (mdlRpph->refWdbeMPeripheral == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",mdlRpph->srefRefWdbeMPeripheral}, {"iel","srefRefWdbeMPeripheral"}, {"lineno",to_string(mdlRpph->lineno)}});

					dbswdbe->tblwdbermmodulemperipheral->insertRec(mdlRpph);
					impcnt++;
				};
			};

			for (unsigned int ix1 = 0; ix1 < unt->imeimmodule.nodes.size(); ix1++) {
				mdl = unt->imeimmodule.nodes[ix1];

				if (mdl->ixVBasetype == VecWdbeVMModuleBasetype::TOP) {
					unt->refWdbeMModule = mdl->ref;
					dbswdbe->tblwdbemunit->updateRec(unt);
					
					break;
				};
			};
		};
		// IP enterSgeImport.traverse --- REND

		// IP enterSgeImport.ppr --- IBEGIN
		for (unsigned int ix0 = 0; ix0 < imeimunit.nodes.size(); ix0++) {
			unt = imeimunit.nodes[ix0];

			for (unsigned int ix1 = 0; ix1 < unt->imeimmodule.nodes.size(); ix1++) {
				mdl = unt->imeimmodule.nodes[ix1];

				if (mdl->hsrefSupRefWdbeMModule != "") {
					for (unsigned int i = 0; i < unt->imeimmodule.nodes.size(); i++) {
						mdl2 = unt->imeimmodule.nodes[i];

						if ( ((mdl2->hsrefSupRefWdbeMModule == "") && (mdl2->sref == mdl->hsrefSupRefWdbeMModule))
									|| ((mdl2->hsrefSupRefWdbeMModule != "") && ((mdl2->hsrefSupRefWdbeMModule + ";" + mdl2->sref) == mdl->hsrefSupRefWdbeMModule)) ) {
							mdl->supRefWdbeMModule = mdl2->ref;
							break;
						};
					};

					if (mdl->supRefWdbeMModule == 0) throw SbeException(SbeException::IEX_THSREF, {{"thsref",mdl->hsrefSupRefWdbeMModule}, {"iel","hsrefSupRefWdbeMModule"}, {"lineno",to_string(mdl->lineno)}});
					else dbswdbe->tblwdbemmodule->updateRec(mdl);
				};

				for (unsigned int ix2 = 0; ix2 < mdl->imeirmmodulemmodule.nodes.size(); ix2++) {
					mdlRmdl = mdl->imeirmmodulemmodule.nodes[ix2];

					if (mdlRmdl->hsrefCorRefWdbeMModule != "") {
						for (unsigned int i = 0; i < unt->imeimmodule.nodes.size(); i++) {
							mdl2 = unt->imeimmodule.nodes[i];

							if ( ((mdl2->hsrefSupRefWdbeMModule == "") && (mdl2->sref == mdlRmdl->hsrefCorRefWdbeMModule))
										|| ((mdl2->hsrefSupRefWdbeMModule != "") && ((mdl2->hsrefSupRefWdbeMModule + ";" + mdl2->sref) == mdlRmdl->hsrefCorRefWdbeMModule)) ) {
								mdlRmdl->corRefWdbeMModule = mdl2->ref;
								break;
							};
						};

						if (mdlRmdl->corRefWdbeMModule == 0) throw SbeException(SbeException::IEX_THSREF, {{"thsref",mdlRmdl->hsrefCorRefWdbeMModule}, {"iel","hsrefCorRefWdbeMModule"}, {"lineno",to_string(mdlRmdl->lineno)}});
						else dbswdbe->tblwdbermmodulemmodule->updateRec(mdlRmdl);
					};
				};

				for (unsigned int ix2 = 0; ix2 < mdl->imeimimbuf.nodes.size(); ix2++) {
					imb = mdl->imeimimbuf.nodes[ix2];

					Wdbe::getImbsrefs(dbswdbe, imb->refWdbeMModule, imb->Fullsref, srefrootMgmt, srefrootCor);
					dbswdbe->tblwdbemimbuf->updateRec(imb);
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

void JobWdbeIexMdl::leaveSgeImport(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeImport --- INSERT
};

uint JobWdbeIexMdl::enterSgeImperr(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::IMPERR;

	// IP enterSgeImperr --- INSERT

	return retval;
};

void JobWdbeIexMdl::leaveSgeImperr(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeImperr --- INSERT
};

uint JobWdbeIexMdl::enterSgeReverse(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::IDLE;
	retval = nextIxVSgeSuccess;

	ImeitemIMUnit* unt = NULL;
	ImeitemIMModule* mdl = NULL;
	ImeitemIMPeripheral* pph = NULL;
	ImeitemIAMModulePar* mdlApar = NULL;
	ImeitemIAMPeripheralPar* pphApar = NULL;
	ImeitemIMController* ctr = NULL;
	ImeitemIMGeneric* gen = NULL;
	ImeitemIMImbuf* imb = NULL;
	ImeitemIRMModuleMModule* mdlRmdl = NULL;
	ImeitemIRMModuleMPeripheral* mdlRpph = NULL;

	// -- ImeIMUnit
	for (unsigned int ix0 = 0; ix0 < imeimunit.nodes.size(); ix0++) {
		unt = imeimunit.nodes[ix0];
		if (unt->ref != 0) dbswdbe->tblwdbemunit->removeRecByRef(unt->ref);

		for (unsigned int ix1 = 0; ix1 < unt->imeimmodule.nodes.size(); ix1++) {
			mdl = unt->imeimmodule.nodes[ix1];
			if (mdl->ref != 0) dbswdbe->tblwdbemmodule->removeRecByRef(mdl->ref);

			for (unsigned int ix2 = 0; ix2 < mdl->imeiammodulepar.nodes.size(); ix2++) {
				mdlApar = mdl->imeiammodulepar.nodes[ix2];
				if (mdlApar->ref != 0) dbswdbe->tblwdbeammodulepar->removeRecByRef(mdlApar->ref);
			};

			for (unsigned int ix2 = 0; ix2 < mdl->imeimcontroller.nodes.size(); ix2++) {
				ctr = mdl->imeimcontroller.nodes[ix2];
				if (ctr->ref != 0) dbswdbe->tblwdbemcontroller->removeRecByRef(ctr->ref);
			};

			for (unsigned int ix2 = 0; ix2 < mdl->imeimgeneric.nodes.size(); ix2++) {
				gen = mdl->imeimgeneric.nodes[ix2];
				if (gen->ref != 0) dbswdbe->tblwdbemgeneric->removeRecByRef(gen->ref);
			};

			for (unsigned int ix2 = 0; ix2 < mdl->imeimimbuf.nodes.size(); ix2++) {
				imb = mdl->imeimimbuf.nodes[ix2];
				if (imb->ref != 0) dbswdbe->tblwdbemimbuf->removeRecByRef(imb->ref);
			};

			for (unsigned int ix2 = 0; ix2 < mdl->imeirmmodulemmodule.nodes.size(); ix2++) {
				mdlRmdl = mdl->imeirmmodulemmodule.nodes[ix2];
				if (mdlRmdl->ref != 0) dbswdbe->tblwdbermmodulemmodule->removeRecByRef(mdlRmdl->ref);
			};

			for (unsigned int ix2 = 0; ix2 < mdl->imeirmmodulemperipheral.nodes.size(); ix2++) {
				mdlRpph = mdl->imeirmmodulemperipheral.nodes[ix2];
				if (mdlRpph->ref != 0) dbswdbe->tblwdbermmodulemperipheral->removeRecByRef(mdlRpph->ref);
			};
		};

		for (unsigned int ix1 = 0; ix1 < unt->imeimperipheral.nodes.size(); ix1++) {
			pph = unt->imeimperipheral.nodes[ix1];
			if (pph->ref != 0) dbswdbe->tblwdbemperipheral->removeRecByRef(pph->ref);

			for (unsigned int ix2 = 0; ix2 < pph->imeiamperipheralpar.nodes.size(); ix2++) {
				pphApar = pph->imeiamperipheralpar.nodes[ix2];
				if (pphApar->ref != 0) dbswdbe->tblwdbeamperipheralpar->removeRecByRef(pphApar->ref);
			};
		};
	};

	return retval;
};

void JobWdbeIexMdl::leaveSgeReverse(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeReverse --- INSERT
};

uint JobWdbeIexMdl::enterSgeCollect(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::CLTDONE;
	retval = nextIxVSgeSuccess;

	ImeitemIMUnit* unt = NULL;
	ImeitemIMModule* mdl = NULL;
	ImeitemIMPeripheral* pph = NULL;
	ImeitemIAMModulePar* mdlApar = NULL;
	ImeitemIAMPeripheralPar* pphApar = NULL;
	ImeitemIMController* ctr = NULL;
	ImeitemIMGeneric* gen = NULL;
	ImeitemIMImbuf* imb = NULL;
	ImeitemIRMModuleMModule* mdlRmdl = NULL;
	ImeitemIRMModuleMPeripheral* mdlRpph = NULL;

	uint ixWdbeVIop;

	vector<ubigint> refs;

	Stcch* stcch = new Stcch(false);

	// IP enterSgeCollect.traverse --- BEGIN

	// -- ImeIMUnit
	for (unsigned int ix0 = 0; ix0 < imeimunit.nodes.size(); ix0++) {
		unt = imeimunit.nodes[ix0];

		if (unt->ref != 0) {
			unt->srefSilRefWdbeMUnit = StubWdbe::getStubUntSref(dbswdbe, unt->silRefWdbeMUnit, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
		};

		if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMMODULE, ixWdbeVIop)) {
			dbswdbe->tblwdbemmodule->loadRefsByHktHku(VecWdbeVMModuleHkTbl::UNT, unt->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) unt->imeimmodule.nodes.push_back(new ImeitemIMModule(dbswdbe, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < unt->imeimmodule.nodes.size(); ix1++) {
			mdl = unt->imeimmodule.nodes[ix1];

			if (mdl->ref != 0) {
				mdl->hsrefSupRefWdbeMModule = StubWdbe::getStubMdlHsref(dbswdbe, mdl->supRefWdbeMModule, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
				mdl->srefTplRefWdbeMModule = StubWdbe::getStubMdlHsref(dbswdbe, mdl->tplRefWdbeMModule, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
			};

			if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIAMMODULEPAR, ixWdbeVIop)) {
				dbswdbe->tblwdbeammodulepar->loadRefsByMdl(mdl->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) mdl->imeiammodulepar.nodes.push_back(new ImeitemIAMModulePar(dbswdbe, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < mdl->imeiammodulepar.nodes.size(); ix2++) {
				mdlApar = mdl->imeiammodulepar.nodes[ix2];

				if (mdlApar->ref != 0) {
				};
			};

			if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIMCONTROLLER, ixWdbeVIop)) {
				dbswdbe->tblwdbemcontroller->loadRefsByMdl(mdl->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) mdl->imeimcontroller.nodes.push_back(new ImeitemIMController(dbswdbe, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < mdl->imeimcontroller.nodes.size(); ix2++) {
				ctr = mdl->imeimcontroller.nodes[ix2];

				if (ctr->ref != 0) {
				};
			};

			for (unsigned int ix2 = 0; ix2 < mdl->imeimgeneric.nodes.size(); ix2++) {
				gen = mdl->imeimgeneric.nodes[ix2];

				if (gen->ref != 0) {
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

			if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIRMMODULEMMODULE, ixWdbeVIop)) {
				dbswdbe->tblwdbermmodulemmodule->loadRefsByCtd(mdl->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) mdl->imeirmmodulemmodule.nodes.push_back(new ImeitemIRMModuleMModule(dbswdbe, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < mdl->imeirmmodulemmodule.nodes.size(); ix2++) {
				mdlRmdl = mdl->imeirmmodulemmodule.nodes[ix2];

				if (mdlRmdl->ref != 0) {
					mdlRmdl->hsrefCorRefWdbeMModule = StubWdbe::getStubMdlHsref(dbswdbe, mdlRmdl->corRefWdbeMModule, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
				};
			};

			if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIRMMODULEMPERIPHERAL, ixWdbeVIop)) {
				dbswdbe->tblwdbermmodulemperipheral->loadRefsByMdl(mdl->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) mdl->imeirmmodulemperipheral.nodes.push_back(new ImeitemIRMModuleMPeripheral(dbswdbe, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < mdl->imeirmmodulemperipheral.nodes.size(); ix2++) {
				mdlRpph = mdl->imeirmmodulemperipheral.nodes[ix2];

				if (mdlRpph->ref != 0) {
					mdlRpph->srefRefWdbeMPeripheral = StubWdbe::getStubPphStd(dbswdbe, mdlRpph->refWdbeMPeripheral, ixWdbeVLocale, Stub::VecVNonetype::VOID, stcch);
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

			if (getIxWdbeVIop(icsWdbeVIop, VecVIme::IMEIAMPERIPHERALPAR, ixWdbeVIop)) {
				dbswdbe->tblwdbeamperipheralpar->loadRefsByPph(pph->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) pph->imeiamperipheralpar.nodes.push_back(new ImeitemIAMPeripheralPar(dbswdbe, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < pph->imeiamperipheralpar.nodes.size(); ix2++) {
				pphApar = pph->imeiamperipheralpar.nodes[ix2];

				if (pphApar->ref != 0) {
				};
			};
		};
	};
	// IP enterSgeCollect.traverse --- END
	// IP enterSgeCollect.ppr --- INSERT

	delete stcch;

	return retval;
};

void JobWdbeIexMdl::leaveSgeCollect(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeCollect --- INSERT
};

uint JobWdbeIexMdl::enterSgeCltdone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::CLTDONE;

	// IP enterSgeCltdone --- INSERT

	return retval;
};

void JobWdbeIexMdl::leaveSgeCltdone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeCltdone --- INSERT
};

uint JobWdbeIexMdl::enterSgeExport(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	IexWdbeMdl::exportToFile(fullpath, xmlNotTxt, shorttags, imeimunit);

	return retval;
};

void JobWdbeIexMdl::leaveSgeExport(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeExport --- INSERT
};

uint JobWdbeIexMdl::enterSgeDone(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void JobWdbeIexMdl::leaveSgeDone(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeDone --- INSERT
};
