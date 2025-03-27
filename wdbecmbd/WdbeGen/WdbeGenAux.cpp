/**
	* \file WdbeGenAux.cpp
	* Wdbe operation processor - generate auxiliary infrastructure (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 27 May 2023
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeGenAux.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeGen;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeGenAux
 ******************************************************************************/

DpchRetWdbeGenAux* WdbeGenAux::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeGenAux* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;
	string Prjshort = dpchinv->Prjshort;
	string Untsref = dpchinv->Untsref;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	std::string logfile;

	// IP run --- IBEGIN
	WdbeMModule* mdl = NULL;

	ListWdbeMCdc cdcs;
	WdbeMCdc* cdc = NULL;

	ListWdbeMPort prts;
	WdbeMPort* prt = NULL;

	ListWdbeRMCdcMSignal crss;
	WdbeRMCdcMSignal* crs = NULL;

	ListWdbeMProcess prcs;
	WdbeMProcess* prc = NULL;

	WdbeMFsm* fsm = NULL;
	ubigint refFsm;

	ListWdbeMFsmstate fsts;
	WdbeMFsmstate* fst = NULL;

	bool hasfts, hasstf;

	ubigint refVec;

	unsigned int major, minor;

	ubigint refCPrt, refCTopsig;

	uint mdlNum, refNumSig;

	string sref, sref2;
	size_t ptr;

	bool first;

	// --- clock domain crossing processes and signals
	refNumSig = Wdbe::getNextSigRefNum(dbswdbe, VecWdbeVMSignalRefTbl::MDL, refWdbeMModule);

	dbswdbe->tblwdbemcdc->loadRstByMdl(refWdbeMModule, false, cdcs);

	for (unsigned int i = 0; i < cdcs.nodes.size(); i++) {
		cdc = cdcs.nodes[i];

		dbswdbe->tblwdbermcdcmsignal->loadRstByCdc(cdc->ref, false, crss);

		hasfts = false;
		hasstf = false;

		for (unsigned int j = 0; j < crss.nodes.size(); j++) {
			crs = crss.nodes[j];

			if (crs->ixVDir == VecWdbeVRMCdcMSignalDir::FTS) hasfts = true;
			else if (crs->ixVDir == VecWdbeVRMCdcMSignalDir::STF) hasstf = true;

			if (hasfts && hasstf) break;
		};

		if (hasfts) genCdc(dbswdbe, cdc, VecWdbeVRMCdcMSignalDir::FTS, crss, refNumSig);
		if (hasstf) genCdc(dbswdbe, cdc, VecWdbeVRMCdcMSignalDir::STF, crss, refNumSig);
	};

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		// --- FSM debug tap type modification
		if ((mdl->ixVBasetype == VecWdbeVMModuleBasetype::DBG) || (mdl->ixVBasetype == VecWdbeVMModuleBasetype::DBGCTR) || (mdl->ixVBasetype == VecWdbeVMModuleBasetype::EDBGCTR)) {
			dbswdbe->tblwdbemport->loadRstBySQL("SELECT * FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(mdl->ref) + " AND mdlIxVCat = " + to_string(VecWdbeVMPortMdlCat::DBG) + " AND ixVDir = "
						+ to_string(VecWdbeVMPortDir::IN) + " AND srefWdbeKHdltype = 'slvdn' AND Width = 8 AND sref LIKE '%state%'", false, prts);

			for (unsigned int i = 0; i < prts.nodes.size(); i++) {
				prt = prts.nodes[i];

				sref = "";
				sref2 = "";

				ptr = prt->csiSrefWdbeMSignal.find("State");
				if (ptr != string::npos) {
					sref = prt->csiSrefWdbeMSignal.substr(0, ptr);
					
					sref2 = StrMod::uncap(prt->csiSrefWdbeMSignal.substr(ptr + 5));
					ptr = sref2.find("_dbg");
					if (ptr != string::npos) sref2 = sref2.substr(0, sref2.length() - 4);
				}

				if (dbswdbe->loadRefBySQL("SELECT TblWdbeMProcess.refWdbeMFsm FROM TblWdbeMModule, TblWdbeMProcess WHERE TblWdbeMModule.hkIxVTbl = "
							+ to_string(VecWdbeVMModuleHkTbl::UNT) + " AND TblWdbeMModule.hkUref = " + to_string(mdl->hkUref) + " AND TblWdbeMModule.sref = '" + sref
							+ "' AND TblWdbeMProcess.refWdbeMModule = TblWdbeMModule.ref AND TblWdbeMProcess.sref = '" + sref2 + "'", refFsm))
					if (refFsm != 0) Wdbe::setFsmDbgtaptype(dbswdbe, refFsm);
			};
		};

		// --- FSM state vectors, debug ports and top module signals
		dbswdbe->tblwdbemprocess->loadRstByMdl(refWdbeMModule, false, prcs);

		first = true;

		for (unsigned int i = 0; i < prcs.nodes.size(); i++) {
			prc = prcs.nodes[i];

			if (prc->refWdbeMFsm != 0) if (dbswdbe->tblwdbemfsm->loadRecByRef(prc->refWdbeMFsm, &fsm)) {
				if (fsm->ixVDbgtaptype != VecWdbeVMFsmDbgtaptype::VOID) {
					///
					if (first) {
						WdbeMUnit* unt = NULL;

						if (dbswdbe->tblwdbemunit->loadRecByRef(mdl->hkUref, &unt)) {
							Prjshort = Wdbe::getPrjshort(dbswdbe, unt->refUref);
							Untsref = StrMod::cap(unt->sref);

							delete unt;
						};
					};
					///

					// -- vector and vector items
					dbswdbe->tblwdbemfsmstate->loadRstByFsm(prc->refWdbeMFsm, false, fsts);

					sref = "VecV" + Prjshort + Untsref + StrMod::cap(mdl->sref) + StrMod::cap(prc->sref); 
					refVec = dbswdbe->tblwdbemvector->insertNewRec(NULL, VecWdbeVMVectorBasetype::TIXLIN, VecWdbeVMVectorHkTbl::FSM, fsm->ref, sref, "notit;filfed");

					major = 0;
					minor = 0;

					for (unsigned int i = 0; i < fsts.nodes.size(); i++) {
						fst = fsts.nodes[i];

						if (i != 0) {
							if (fsm->ixVDbgtaptype == VecWdbeVMFsmDbgtaptype::CLUST) {
								if ((fst->refWdbeCFsmstate == 0) || (fst->refWdbeCFsmstate != fsts.nodes[i-1]->refWdbeCFsmstate)) {
									major++;
									minor = 0;

								} else {
									minor++;

									if (minor == 16) {
										major++;
										minor = 0;
									};
								};

								if (major == 16) major = 0;

							} else minor++;
						};

						dbswdbe->tblwdbemvectoritem->insertNewRec(NULL, refVec, 16*major + minor, fst->sref, "", "");
					};

					// -- port and signal
					if (first) {
						refCPrt = dbswdbe->tblwdbecport->getNewRef();
						refCTopsig = dbswdbe->tblwdbecport->getNewRef();

						mdlNum = Wdbe::getNextPrtMdlNum(dbswdbe, refWdbeMModule);
						refNumSig = Wdbe::getNextSigRefNum(dbswdbe, VecWdbeVMSignalRefTbl::MDL, mdl->supRefWdbeMModule);

						first = false;
					};

					sref = "state" + StrMod::cap(prc->sref) + "_dbg";
					sref2 = mdl->sref + "State" + StrMod::cap(prc->sref) + "_dbg";

					dbswdbe->tblwdbemport->insertNewRec(NULL, refCPrt, refWdbeMModule, mdlNum++, VecWdbeVMPortMdlCat::DBG, sref, VecWdbeVMPortDir::OUT, "slvdn", 8, "", "", "", "", sref2, "");
					dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refCTopsig, VecWdbeVMSignalRefTbl::MDL, mdl->supRefWdbeMModule, refNumSig++, VecWdbeVMSignalMgeTbl::MDL, refWdbeMModule, 0, sref2, false, "slvdn", 8, "", "", "", "", false, 0, "");
				};

				delete fsm;
			};
		};

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbeGenAux("", "", ixOpVOpres, 100, logfile));
};

// IP cust --- IBEGIN
void WdbeGenAux::genCdc(
			DbsWdbe* dbswdbe
			, WdbeMCdc* cdc
			, uint ixVDir
			, ListWdbeRMCdcMSignal& crss
			, uint& refNumSig
		) {
	WdbeRMCdcMSignal* crs = NULL;

	WdbeMSignal* sig = NULL;

	ubigint refPrc;

	ubigint refCSig, refCVar;

	uint refNumVar;

	string from, fromRst;
	string to, toRst;

	string imax;

	string sigsref;

	if (ixVDir == VecWdbeVRMCdcMSignalDir::FTS) {
		from = cdc->fckSrefWdbeMSignal;
		fromRst = cdc->farSrefWdbeMSignal;

		to = cdc->sckSrefWdbeMSignal;
		toRst = cdc->sarSrefWdbeMSignal;

		imax = to_string(lround(ceil(2.0*cdc->Ratio))-1);

	} else {
		from = cdc->sckSrefWdbeMSignal;
		fromRst = cdc->sarSrefWdbeMSignal;

		to = cdc->fckSrefWdbeMSignal;
		toRst = cdc->farSrefWdbeMSignal;

		if (cdc->Ratio <= 2.0) imax = "1";
		else imax = "0";
	};

	refPrc = dbswdbe->tblwdbemprocess->insertNewRec(NULL, cdc->refWdbeMModule, 0, from + "To" + StrMod::cap(to) + "Stretch", from, fromRst, false, "", false, from + " to " + to + " CDC stretching");

	refNumVar = 1;

	if (imax != "0") dbswdbe->tblwdbemvariable->insertNewRec(NULL, 0, VecWdbeVMVariableRefTbl::PRC, refPrc, refNumVar++, "imax", true, false, "nat", 0, "", "", imax, false, "");

	refCSig = dbswdbe->tblwdbecsignal->getNewRef();
	refCVar = dbswdbe->tblwdbecvariable->getNewRef();

	for (unsigned int j = 0; j < crss.nodes.size(); j++) {
		crs = crss.nodes[j];

		if (crs->ixVDir == ixVDir) {
			if (dbswdbe->tblwdbemsignal->loadRecByRef(crs->refWdbeMSignal, &sig)) {
				if (imax != "0") dbswdbe->tblwdbemvariable->insertNewRec(NULL, refCVar, VecWdbeVMVariableRefTbl::PRC, refPrc, refNumVar++, sig->sref + "_i", false, false, "nat", 0, "0..imax", "", "0", false, "");

				sig->ref = 0;
				sig->ixVBasetype = VecWdbeVMSignalBasetype::OTH;
				sig->refWdbeCSignal = refCSig;
				sig->refNum = refNumSig++;
				sig->mgeIxVTbl = VecWdbeVMSignalMgeTbl::PRC;
				sig->mgeUref = refPrc;
				sig->sref += "_to_" + to;
				sig->Comb = "";
				if (sig->Offval == "") sig->Offval = "0";
				sig->drvRefWdbeMPort = 0;
				sig->Comment = "";

				dbswdbe->tblwdbemsignal->insertRec(sig);

				delete sig;
			};
		};
	};

	refPrc = dbswdbe->tblwdbemprocess->insertNewRec(NULL, cdc->refWdbeMModule, 0, from + "To" + StrMod::cap(to) + "Sample", to, toRst, false, "", false, from + " to " + to + " CDC sampling");

	refNumVar = 1;

	refCSig = dbswdbe->tblwdbecsignal->getNewRef();
	refCVar = dbswdbe->tblwdbecvariable->getNewRef();

	for (unsigned int j = 0; j < crss.nodes.size(); j++) {
		crs = crss.nodes[j];

		if (crs->ixVDir == ixVDir) {
			if (dbswdbe->tblwdbemsignal->loadRecByRef(crs->refWdbeMSignal, &sig)) {
				if (sig->Offval == "") {
					if (sig->srefWdbeKHdltype == "_bool") sig->Offval = "false";
					else if ((sig->srefWdbeKHdltype.rfind("_t") + 2) != sig->srefWdbeKHdltype.length()) sig->Offval = "0";
				};

				if (sig->ixVBasetype == VecWdbeVMSignalBasetype::STRB) dbswdbe->tblwdbemvariable->insertNewRec(NULL, refCVar, VecWdbeVMVariableRefTbl::PRC, refPrc, refNumVar++, sig->sref + "_wait", false, false, "_bool", 0, "", "", "false", false, "");

				sigsref = sig->sref;

				sig->ref = 0;
				sig->ixVBasetype = VecWdbeVMSignalBasetype::OTH;
				sig->refWdbeCSignal = refCSig;
				sig->refNum = refNumSig++;
				sig->mgeIxVTbl = VecWdbeVMSignalMgeTbl::PRC;
				sig->mgeUref = refPrc;
				sig->sref = sigsref + "_" + to;
				sig->Comb = "";
				sig->drvRefWdbeMPort = 0;
				sig->Comment = "";
				dbswdbe->tblwdbemsignal->insertRec(sig);

				sig->ref = 0;
				sig->refNum = refNumSig++;
				sig->sref = sigsref + "_to_" + to + "m1";
				dbswdbe->tblwdbemsignal->insertRec(sig);

				sig->ref = 0;
				sig->refNum = refNumSig++;
				sig->sref = sigsref + "_to_" + to + "m2";
				dbswdbe->tblwdbemsignal->insertRec(sig);

				delete sig;
			};
		};
	};
};
// IP cust --- IEND
