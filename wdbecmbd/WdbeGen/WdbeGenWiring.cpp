/**
	* \file WdbeGenWiring.cpp
	* Wdbe operation processor - generate wiring (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeGenWiring.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeGen;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeGenWiring
 ******************************************************************************/

DpchRetWdbeGenWiring* WdbeGenWiring::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeGenWiring* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;
	string srefKToolch = dpchinv->srefKToolch;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	std::string logfile;

	// IP run --- IBEGIN
	fstream logfi;

	vector<ubigint> refs, refs2;
	ubigint ref;

	WdbeMModule* mdl = NULL;

	uint hkNum;

	ListWdbeMPin pins;
	map<string,WdbeMPin*> srefsPins;
	WdbeMPin* pin = NULL;

	ListWdbeMPort busprts;
	map<string,WdbeMPort*> srefsBusprts;

	ListWdbeMPort lvdsprts;
	map<string,WdbeMPort*> srefsLvdsprts;

	ListWdbeMGeneric gens;
	map<string,WdbeMGeneric*> srefsGens;
	WdbeMGeneric* gen = NULL;

	ListWdbeMPort prts;
	map<string,WdbeMPort*> srefsPrts;
	WdbeMPort* prt = NULL;

	ListWdbeMSignal sigs;
	map<string,WdbeMSignal*> srefsSigs;
	WdbeMSignal* sig = NULL;

	ListWdbeMModule submdls;
	WdbeMModule* submdl = NULL;

	ListWdbeMGeneric subgens;
	WdbeMGeneric* subgen = NULL;
	map<ubigint,ubigint> convGenCs;

	ubigint refWdbeCGeneric;
	string srcSrefWdbeMGeneric;

	ListWdbeMPort subprts;
	WdbeMPort* subprt = NULL;
	map<ubigint,ubigint> convPrtCs;
	ubigint refWdbeCPort;

	string sref;
	bool hasrng;
	utinyint from, to;
	string tix;

	usmallint Width;

	size_t ptr;

	bool match, found;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		hkNum = mdl->hkNum + 1;

		dbswdbe->tblwdbemgeneric->loadRstByMdl(mdl->ref, false, gens);
		for (unsigned int i = 0; i < gens.nodes.size(); i++) srefsGens[gens.nodes[i]->sref] = gens.nodes[i];

		dbswdbe->tblwdbemport->loadRstByMdl(mdl->ref, false, prts);
		for (unsigned int i = 0; i < prts.nodes.size(); i++) srefsPrts[prts.nodes[i]->sref] = prts.nodes[i];

		dbswdbe->tblwdbemsignal->loadRstByRetReu(VecWdbeVMSignalRefTbl::MDL, mdl->ref, false, sigs);
		for (unsigned int i = 0; i < sigs.nodes.size(); i++) srefsSigs[sigs.nodes[i]->sref] = sigs.nodes[i];

		if ((mdl->ixVBasetype == VecWdbeVMModuleBasetype::TOP) || (mdl->supRefWdbeMModule == 0)) {
			// prepare records for every possible pin-related bus-type or lvds-type port (not to be inserted at this stage)
			dbswdbe->tblwdbempin->loadRstBySQL("SELECT TblWdbeMPin.* FROM TblWdbeMBank, TblWdbeMPin WHERE TblWdbeMBank.refWdbeMUnit = " + to_string(mdl->hkUref) + " AND TblWdbeMPin.refWdbeMBank = TblWdbeMBank.ref ORDER BY TblWdbeMPin.sref ASC", false, pins);
			for (unsigned int i = 0; i < pins.nodes.size(); i++) srefsPins[pins.nodes[i]->sref] = pins.nodes[i];

			for (unsigned int i = 0; i < pins.nodes.size(); i++) {
				pin = pins.nodes[i];

				ptr = pin->sref.find('[');
				if (ptr != string::npos) {
					ptr = pin->sref.find("[0]");
					if (ptr != string::npos) {
						// bus
						Width = 1;
						while (srefsPins.find(pin->sref.substr(0, ptr) + "[" + to_string((int) Width) + "]") != srefsPins.end()) Width++;

						prt = new WdbeMPort(0, 0, mdl->ref, 0, VecWdbeVMPortMdlCat::RTEPIN, pin->sref.substr(0, ptr), 0, "slvdn", Width, "", "", pin->sref.substr(0, ptr), "", "", "");
						busprts.nodes.push_back(prt);
						srefsBusprts[pin->sref.substr(0, ptr)] = prt;
					};

				} else if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeAMPinPar WHERE refWdbeMPin = " + to_string(pin->ref) + " AND x1SrefKKey = 'lvds'", ref)) {
					if (pin->sref[pin->sref.length()-1] == 'p') {
						// LVDS pair
						if (srefsPins.find(pin->sref.substr(0, pin->sref.length()-1) + "n") == srefsPins.end()) Wdbe::appendToTmpfile(xchg->tmppath, logfile, logfi, "wiring error 1: no negative counterpart found for LVDS pin " + pin->sref + "!");

						prt = new WdbeMPort(0, 0, mdl->ref, 0, VecWdbeVMPortMdlCat::RTEPIN, pin->sref.substr(0, pin->sref.length()-1), 0, "sl", 1, "", "", "", "", "", "");
						lvdsprts.nodes.push_back(prt);
						srefsLvdsprts[pin->sref.substr(0, pin->sref.length()-1)] = prt;
					};
				};
			};

			// synchronize with ports already here
			for (unsigned int i = 0; i < busprts.nodes.size(); i++) {
				prt = busprts.nodes[i];

				auto it = srefsPrts.find(prt->sref);
				if (it != srefsPrts.end()) {
					srefsBusprts[prt->sref] = it->second;
					delete prt;
				};
			};

			for (unsigned int i = 0; i < lvdsprts.nodes.size(); i++) {
				prt = lvdsprts.nodes[i];

				auto it = srefsPrts.find(prt->sref + "p");
				if (it != srefsPrts.end()) {
					srefsLvdsprts[prt->sref] = it->second;
					delete prt;
				};
			};
		};

		// --- sub-module connection
		dbswdbe->tblwdbemmodule->loadRstBySup(mdl->ref, false, submdls);

		for (unsigned int i = 0; i < submdls.nodes.size(); i++) {
			submdl = submdls.nodes[i];

			// -- match generics of sub
			dbswdbe->tblwdbemgeneric->loadRstByMdl(submdl->ref, false, subgens);

			for (unsigned int j = 0; j < subgens.nodes.size(); j++) {
				subgen = subgens.nodes[j];

				if (subgen->srcSrefWdbeMGeneric != "") {
					auto it = srefsGens.find(subgen->srcSrefWdbeMGeneric);

					if (it != srefsGens.end()) {
						gen = it->second;

						// require matching characteristics
						match = ((gen->srefWdbeKHdltype == subgen->srefWdbeKHdltype) && (gen->Width == subgen->Width) && (gen->Minmax == subgen->Minmax));
						if (match) match = ((gen->srcSrefWdbeMGeneric == "") || (gen->srcSrefWdbeMGeneric == subgen->srcSrefWdbeMGeneric));

						if (!match) Wdbe::appendToTmpfile(xchg->tmppath, logfile, logfi, "wiring error 2: mismatch of generic " + submdl->sref + "." + subgen->sref + " characteristics with superior module " + mdl->sref + "!");

					} else {
						// insert copy of sub-module's generic with equal characteristics
						refWdbeCGeneric = 0;
						if (subgen->refWdbeCGeneric != 0) {
							auto it = convGenCs.find(subgen->refWdbeCGeneric);
							if (it != convGenCs.end()) refWdbeCGeneric = it->second;
							else {
								refWdbeCGeneric = dbswdbe->tblwdbecgeneric->getNewRef();
								convGenCs[subgen->refWdbeCGeneric] = refWdbeCGeneric;
							};
						};

						srcSrefWdbeMGeneric = subgen->srcSrefWdbeMGeneric;
						if (mdl->ixVBasetype == VecWdbeVMModuleBasetype::TOP) srcSrefWdbeMGeneric = "";

						dbswdbe->tblwdbemgeneric->appendNewRecToRst(gens, NULL, refWdbeCGeneric, mdl->ref, gens.nodes.size()+1, subgen->sref, subgen->srefWdbeKHdltype, subgen->Width, subgen->Minmax, subgen->Defval, srcSrefWdbeMGeneric, subgen->Comment);
						srefsGens[subgen->sref] = gens.nodes[gens.nodes.size()-1];
					};
				};
			};

			// -- match ports of sub to pins/ports/signals
			dbswdbe->tblwdbemport->loadRstByMdl(submdl->ref, false, subprts);

			for (unsigned int j = 0; j < subprts.nodes.size(); j++) {
				subprt = subprts.nodes[j];

				if (subprt->cpiSrefWdbeMPin != "") {
					// - connection to pin(s) ; top module: partial slv supported, others: partial slv supported for same portion using same sref
					Wdbe::getRange(subprt->cpiSrefWdbeMPin, sref, hasrng, from, to, tix);

					found = false;

					if ((mdl->ixVBasetype == VecWdbeVMModuleBasetype::WRP) || (mdl->ixVBasetype == VecWdbeVMModuleBasetype::TOP)) {
						// cpi becomes csi (in addition)
						auto it = srefsSigs.find(sref);

						if (it != srefsSigs.end()) {
							sig = it->second;

							if (sig->ixVBasetype == VecWdbeVMSignalBasetype::PSB) {
								// require matching characteristics
								match = ( ((sig->srefWdbeKHdltype == subprt->srefWdbeKHdltype) && (sig->Width == subprt->Width) && (sig->Minmax == subprt->Minmax))
											|| ((sig->srefWdbeKHdltype == "slvdn") && (subprt->srefWdbeKHdltype == "sl"))
											|| ((sig->srefWdbeKHdltype == "slvdn") && (subprt->srefWdbeKHdltype == "slvdn") && (sig->Width > subprt->Width)) );

								if (!match) {
									Wdbe::appendToTmpfile(xchg->tmppath, logfile, logfi, "wiring error 3: mismatch of port " + submdl->sref + "." + subprt->sref + " characteristics with superior module " + mdl->sref + "!");
								} else {
									subprt->csiSrefWdbeMSignal = sig->sref;
									dbswdbe->tblwdbemport->updateRec(subprt);
								};
								found = true;
							};
						};
					};

					if (!found && (mdl->ixVBasetype == VecWdbeVMModuleBasetype::TOP)) {
						// cpi becomes cpr or csi (in addition)
						found = true;

						// 1st try: bus-type port
						auto it = srefsBusprts.find(sref);

						if (it != srefsBusprts.end()) {
							prt = it->second;
							
							if (prt->ref == 0) {
								// generate port
								refWdbeCPort = 0;
								if (subprt->refWdbeCPort != 0) {
									auto it = convPrtCs.find(subprt->refWdbeCPort);
									if (it != convPrtCs.end()) refWdbeCPort = it->second;
									else {
										refWdbeCPort = dbswdbe->tblwdbecport->getNewRef();
										convPrtCs[subprt->refWdbeCPort] = refWdbeCPort;
									};
								};

								prt->refWdbeCPort = refWdbeCPort;
								prt->mdlNum = prts.nodes.size()+1;
								prt->ixVDir = subprt->ixVDir;

								dbswdbe->tblwdbemport->insertRec(prt);
								prts.nodes.push_back(prt);
								srefsPrts[prt->sref] = prt;

								if ((prt->ixVDir == VecWdbeVMPortDir::OUT) && hasrng && ((to-from+1) < prt->Width)) {
									// generate driver signal
									dbswdbe->tblwdbemsignal->appendNewRecToRst(sigs, NULL, VecWdbeVMSignalBasetype::OPRT, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, sigs.nodes.size()+1, VecWdbeVMSignalMgeTbl::VOID, 0, 0, prt->sref, false, prt->srefWdbeKHdltype, prt->Width, "", "", "", "0", false, prt->ref, "");
									srefsSigs[prt->sref] = sigs.nodes[sigs.nodes.size()-1];
								};
							};

							if ((prt->ixVDir == VecWdbeVMPortDir::OUT) && hasrng && ((to-from+1) < prt->Width)) {
								// connect to signal
								subprt->csiSrefWdbeMSignal = prt->sref + "[" + to_string((int) from);
								if (from != to) subprt->csiSrefWdbeMSignal += ".." + to_string((int) to);
								subprt->csiSrefWdbeMSignal += "]";

							} else {
								// connect to port
								if (hasrng) {
									subprt->cprSrefWdbeMPort = prt->sref + "[" + to_string((int) from);
									subprt->cprSrefWdbeMPort += ".." + to_string((int) to);
									subprt->cprSrefWdbeMPort += "]";
								}	else subprt->cprSrefWdbeMPort = prt->sref;
							};

							dbswdbe->tblwdbemport->updateRec(subprt);

						} else {
							// 2nd try: lvds-type port
							auto it = srefsLvdsprts.find(sref);
							
							if (it != srefsLvdsprts.end()) {
								prt = it->second;
								
								if (prt->ref == 0) {
									// generate set of ports (p/n suffixes)
									refWdbeCPort = dbswdbe->tblwdbecport->getNewRef();

									prt->refWdbeCPort = refWdbeCPort;
									prt->mdlNum = prts.nodes.size()+1;
									prt->sref = prt->sref + "p";
									prt->ixVDir = subprt->ixVDir;
									prt->cpiSrefWdbeMPin = prt->sref;

									dbswdbe->tblwdbemport->insertRec(prt);
									prts.nodes.push_back(prt);
									srefsPrts[prt->sref] = prt;

									prt = new WdbeMPort(*prt);
									prt->mdlNum = prts.nodes.size()+1;
									prt->sref = prt->sref.substr(0, prt->sref.length()-1) + "n";
									prt->cpiSrefWdbeMPin = prt->sref;

									dbswdbe->tblwdbemport->insertRec(prt);
									prts.nodes.push_back(prt);
									srefsPrts[prt->sref] = prt;

									prt->sref = prt->sref.substr(0, prt->sref.length()-1); // cut off suffix (not updated in database)

									// generate LVDS primitive and helper signal
									if (prt->ixVDir == VecWdbeVMPortDir::IN) {
										// instantiate input differential buffer (the unorthodox way)
										if (srefKToolch == "libero") {
											dbswdbe->executeQuery("UPDATE TblWdbeMModule SET hkNum = hkNum + 1 WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND hkNum >= " + to_string(hkNum));
											ref = dbswdbe->tblwdbemmodule->appendNewRecToRst(submdls, NULL, VecWdbeVMModuleBasetype::MNFPRIM, mdl->hkIxVTbl, mdl->hkUref, hkNum++, mdl->ref, Wdbe::getRefMtp(dbswdbe, "INBUF_DIFF"), 0, 0, "inbuf_diff" + StrMod::cap(prt->sref), "");
		
											refWdbeCPort = dbswdbe->tblwdbecport->getNewRef();
											dbswdbe->tblwdbemport->insertNewRec(NULL, refWdbeCPort, ref, 1, VecWdbeVMPortMdlCat::RTESUP, "PADP", VecWdbeVMPortDir::IN, "sl", 1, "", "", "", prt->sref + "p", "", "");
											dbswdbe->tblwdbemport->insertNewRec(NULL, refWdbeCPort, ref, 2, VecWdbeVMPortMdlCat::RTESUP, "PADN", VecWdbeVMPortDir::IN, "sl", 1, "", "", "", prt->sref + "n", "", "");
											dbswdbe->tblwdbemport->insertNewRec(NULL, refWdbeCPort, ref, 3, VecWdbeVMPortMdlCat::RTESUP, "Y", VecWdbeVMPortDir::OUT, "sl", 1, "", "", "", "", prt->sref, "");

										} else if (srefKToolch == "vivado") {
											dbswdbe->executeQuery("UPDATE TblWdbeMModule SET hkNum = hkNum + 1 WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND hkNum >= " + to_string(hkNum));
											ref = dbswdbe->tblwdbemmodule->appendNewRecToRst(submdls, NULL, VecWdbeVMModuleBasetype::MNFPRIM, mdl->hkIxVTbl, mdl->hkUref, hkNum++, mdl->ref, Wdbe::getRefMtp(dbswdbe, "IBUFDS"), 0, 0, "ibufds" + StrMod::cap(prt->sref), "");
		
											refWdbeCPort = dbswdbe->tblwdbecport->getNewRef();
											dbswdbe->tblwdbemport->insertNewRec(NULL, refWdbeCPort, ref, 1, VecWdbeVMPortMdlCat::RTESUP, "I", VecWdbeVMPortDir::IN, "sl", 1, "", "", "", prt->sref + "p", "", "");
											dbswdbe->tblwdbemport->insertNewRec(NULL, refWdbeCPort, ref, 2, VecWdbeVMPortMdlCat::RTESUP, "IB", VecWdbeVMPortDir::IN, "sl", 1, "", "", "", prt->sref + "n", "", "");
											dbswdbe->tblwdbemport->insertNewRec(NULL, refWdbeCPort, ref, 3, VecWdbeVMPortMdlCat::RTESUP, "O", VecWdbeVMPortDir::OUT, "sl", 1, "", "", "", "", prt->sref, "");
										};

									} else if (prt->ixVDir == VecWdbeVMPortDir::OUT) {
										// instantiate output differential buffer (the unorthodox way)
										if (srefKToolch == "libero") {
											dbswdbe->executeQuery("UPDATE TblWdbeMModule SET hkNum = hkNum + 1 WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND hkNum >= " + to_string(hkNum));
											ref = dbswdbe->tblwdbemmodule->appendNewRecToRst(submdls, NULL, VecWdbeVMModuleBasetype::MNFPRIM, mdl->hkIxVTbl, mdl->hkUref, hkNum++, mdl->ref, Wdbe::getRefMtp(dbswdbe, "OUTBUF_DIFF"), 0, 0, "outbuf_diff" + StrMod::cap(prt->sref), "");
		
											refWdbeCPort = dbswdbe->tblwdbecport->getNewRef();
											dbswdbe->tblwdbemport->insertNewRec(NULL, refWdbeCPort, ref, 1, VecWdbeVMPortMdlCat::RTESUP, "PADP", VecWdbeVMPortDir::OUT, "sl", 1, "", "", "", prt->sref + "p", "", "");
											dbswdbe->tblwdbemport->insertNewRec(NULL, refWdbeCPort, ref, 2, VecWdbeVMPortMdlCat::RTESUP, "PADN", VecWdbeVMPortDir::OUT, "sl", 1, "", "", "", prt->sref + "n", "", "");
											dbswdbe->tblwdbemport->insertNewRec(NULL, refWdbeCPort, ref, 3, VecWdbeVMPortMdlCat::RTESUP, "D", VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", prt->sref, "");

										} else if (srefKToolch == "vivado") {
											dbswdbe->executeQuery("UPDATE TblWdbeMModule SET hkNum = hkNum + 1 WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND hkNum >= " + to_string(hkNum));
											ref = dbswdbe->tblwdbemmodule->appendNewRecToRst(submdls, NULL, VecWdbeVMModuleBasetype::MNFPRIM, mdl->hkIxVTbl, mdl->hkUref, hkNum++, mdl->ref, Wdbe::getRefMtp(dbswdbe, "OBUFDS"), 0, 0, "obufds" + StrMod::cap(prt->sref), "");
		
											refWdbeCPort = dbswdbe->tblwdbecport->getNewRef();
											dbswdbe->tblwdbemport->insertNewRec(NULL, refWdbeCPort, ref, 1, VecWdbeVMPortMdlCat::RTESUP, "O", VecWdbeVMPortDir::OUT, "sl", 1, "", "", "", prt->sref + "p", "", "");
											dbswdbe->tblwdbemport->insertNewRec(NULL, refWdbeCPort, ref, 2, VecWdbeVMPortMdlCat::RTESUP, "OB", VecWdbeVMPortDir::OUT, "sl", 1, "", "", "", prt->sref + "n", "", "");
											dbswdbe->tblwdbemport->insertNewRec(NULL, refWdbeCPort, ref, 3, VecWdbeVMPortMdlCat::RTESUP, "I", VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", prt->sref, "");
										};
									};

									dbswdbe->tblwdbemsignal->appendNewRecToRst(sigs, NULL, VecWdbeVMSignalBasetype::OTH, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, sigs.nodes.size()+1, VecWdbeVMSignalMgeTbl::VOID, 0, 0, prt->sref, false, "sl", 1, "", "", "", "", false, 0, "");
									srefsSigs[prt->sref] = sigs.nodes[sigs.nodes.size()-1];
								};

								// connect to helper signal
								subprt->csiSrefWdbeMSignal = prt->sref;
								dbswdbe->tblwdbemport->updateRec(subprt);

							} else {
								// 3rd try: single port
								auto it = srefsPrts.find(sref);

								if (it != srefsPrts.end()) {
									prt = it->second;

									// require matching characteristics
									match = ((prt->ixVDir == subprt->ixVDir) || ((prt->ixVDir == VecWdbeVMPortDir::INOUT) && (subprt->ixVDir == VecWdbeVMPortDir::IN)));

									if (!match) {
										Wdbe::appendToTmpfile(xchg->tmppath, logfile, logfi, "wiring error 4: mismatch of port " + submdl->sref + "." + subprt->sref + " characteristics with superior module " + mdl->sref + "!");
									} else {
										subprt->cprSrefWdbeMPort = prt->sref;
										dbswdbe->tblwdbemport->updateRec(subprt);
									};

								} else {
									// 4th try: single pin not having a corresponding port yet
									auto it = srefsPins.find(sref);
									
									if (it != srefsPins.end()) {
										pin = it->second;

										dbswdbe->tblwdbemport->appendNewRecToRst(prts, NULL, 0, mdl->ref, prts.nodes.size()+1, VecWdbeVMPortMdlCat::RTEPIN, pin->sref, subprt->ixVDir, "sl", 1, "", "", pin->sref, "", "", "");
										srefsPrts[pin->sref] = prts.nodes[prts.nodes.size()-1];

										subprt->cprSrefWdbeMPort = pin->sref;
										dbswdbe->tblwdbemport->updateRec(subprt);

									} else {
										found = false;
									};
								};
							};
						};
					};

					if (!found) {
						// cpi becomes cpr (in addition)
						auto it = srefsPrts.find(subprt->sref);

						if (it != srefsPrts.end()) {
							prt = it->second;

							// require matching characteristics
							match = ((prt->ixVDir == subprt->ixVDir) || ((prt->ixVDir == VecWdbeVMPortDir::INOUT) && (subprt->ixVDir == VecWdbeVMPortDir::IN)));
							if (match) match = ((prt->srefWdbeKHdltype == subprt->srefWdbeKHdltype) && (prt->Width == subprt->Width) && (prt->Minmax == subprt->Minmax));
							if (match) match = (prt->cpiSrefWdbeMPin == subprt->cpiSrefWdbeMPin);

							if (!match) {
								Wdbe::appendToTmpfile(xchg->tmppath, logfile, logfi, "wiring error 5: mismatch of port " + submdl->sref + "." + subprt->sref + " characteristics with superior module " + mdl->sref + "!");
							} else {
								subprt->cprSrefWdbeMPort = subprt->sref;
								dbswdbe->tblwdbemport->updateRec(subprt);
							};

						} else {
							// insert copy of sub-module's port with equal characteristics
							refWdbeCPort = 0;
							if (subprt->refWdbeCPort != 0) {
								auto it = convPrtCs.find(subprt->refWdbeCPort);
								if (it != convPrtCs.end()) refWdbeCPort = it->second;
								else {
									refWdbeCPort = dbswdbe->tblwdbecport->getNewRef();
									convPrtCs[subprt->refWdbeCPort] = refWdbeCPort;
								};
							};

							dbswdbe->tblwdbemport->appendNewRecToRst(prts, NULL, refWdbeCPort, mdl->ref, prts.nodes.size()+1, VecWdbeVMPortMdlCat::RTEPIN, subprt->sref, subprt->ixVDir, subprt->srefWdbeKHdltype, subprt->Width, subprt->Minmax, subprt->Defval, subprt->cpiSrefWdbeMPin, "", "", "");
							srefsPrts[subprt->sref] = prts.nodes[prts.nodes.size()-1];

							subprt->cprSrefWdbeMPort = subprt->sref;
							dbswdbe->tblwdbemport->updateRec(subprt);
						};
					};

				} else if (subprt->cprSrefWdbeMPort != "") {
					// - connection to port (port must be present) ; partial slv supported
					Wdbe::getRange(subprt->cprSrefWdbeMPort, sref, hasrng, from, to, tix);

					auto it = srefsPrts.find(sref);

					if (it != srefsPrts.end()) {
						prt = it->second;

						// require matching characteristics
						match = ((prt->ixVDir == subprt->ixVDir) || ((prt->ixVDir == VecWdbeVMPortDir::INOUT) && (subprt->ixVDir == VecWdbeVMPortDir::IN)));
						if (match) match = ( ((prt->srefWdbeKHdltype == subprt->srefWdbeKHdltype) && (prt->Width == subprt->Width) && (prt->Minmax == subprt->Minmax))
									|| ((prt->srefWdbeKHdltype == "slvdn") && (subprt->srefWdbeKHdltype == "sl"))
									|| ((prt->srefWdbeKHdltype == "slvdn") && (subprt->srefWdbeKHdltype == "slvdn") && (prt->Width > subprt->Width)) );

						if (!match) Wdbe::appendToTmpfile(xchg->tmppath, logfile, logfi, "wiring error 6: mismatch of port " + submdl->sref + "." + subprt->sref + " characteristics with superior module " + mdl->sref + "!");

					} else {
						Wdbe::appendToTmpfile(xchg->tmppath, logfile, logfi, "wiring error 7: port connection of " + submdl->sref + "." + subprt->sref + " port does not exist in superior module " + mdl->sref + "!");
					};

				} else if (subprt->csiSrefWdbeMSignal != "") {
					// - connection to signal (signal must be present if top module unless route to wrapper) ; top module: partial slv supported, others: partial slv supported for same portion using same sref
					Wdbe::getRange(subprt->csiSrefWdbeMSignal, sref, hasrng, from, to, tix);

					auto it = srefsSigs.find(sref);

					if (it != srefsSigs.end()) {
						sig = it->second;
					
						// require matching characteristics
						match = ( ((sig->srefWdbeKHdltype == subprt->srefWdbeKHdltype) && (sig->Width == subprt->Width) && (sig->Minmax == subprt->Minmax))
									|| ((sig->srefWdbeKHdltype == "slvdn") && (subprt->srefWdbeKHdltype == "sl"))
									|| ((sig->srefWdbeKHdltype == "slvdn") && (subprt->srefWdbeKHdltype == "slvdn") && (sig->Width > subprt->Width)) );

						if (!match) Wdbe::appendToTmpfile(xchg->tmppath, logfile, logfi, "wiring error 8: mismatch of port " + submdl->sref + "." + subprt->sref + " characteristics with superior module " + mdl->sref + "!");

					} else {
						// csi becomes cpr (in addition)
						if (((mdl->ixVBasetype == VecWdbeVMModuleBasetype::TOP) && (subprt->mdlIxVCat != VecWdbeVMPortMdlCat::RTEWRP)) || (mdl->supRefWdbeMModule == 0)) {
							Wdbe::appendToTmpfile(xchg->tmppath, logfile, logfi, "wiring error 9: signal connection of " + submdl->sref + "." + subprt->sref + " port does not exist in superior module " + mdl->sref + "!");

						} else {
							match = false;

							for (auto it = srefsPrts.begin(); it != srefsPrts.end(); it++) {
								prt = it->second;

								if (prt->sref == sref) {
									// require matching characteristics
									match = (prt->csiSrefWdbeMSignal == subprt->csiSrefWdbeMSignal);
									if (match) match = ((prt->ixVDir == subprt->ixVDir) || ((prt->ixVDir == VecWdbeVMPortDir::INOUT) && (subprt->ixVDir == VecWdbeVMPortDir::IN)));
									if (match) match = ( ((prt->srefWdbeKHdltype == subprt->srefWdbeKHdltype) && (prt->Width == subprt->Width) && (prt->Minmax == subprt->Minmax))
												|| ((prt->srefWdbeKHdltype == "slvdn") && (subprt->srefWdbeKHdltype == "sl"))
												|| ((prt->srefWdbeKHdltype == "slvdn") && (subprt->srefWdbeKHdltype == "slvdn") && (prt->Width > subprt->Width)) );

									if (!match) Wdbe::appendToTmpfile(xchg->tmppath, logfile, logfi, "wiring error 10: mismatch of port " + submdl->sref + "." + subprt->sref + " characteristics with superior module " + mdl->sref + "!");

									subprt->cprSrefWdbeMPort = prt->sref;
									dbswdbe->tblwdbemport->updateRec(subprt);
								};
							};

							if (!match) {
								auto it = srefsPrts.find(subprt->sref);

								if (it != srefsPrts.end()) {
									prt = it->second;

									// require matching characteristics
									match = ((prt->ixVDir == subprt->ixVDir) || ((prt->ixVDir == VecWdbeVMPortDir::INOUT) && (subprt->ixVDir == VecWdbeVMPortDir::IN)));
									if (match) match = ( ((prt->srefWdbeKHdltype == subprt->srefWdbeKHdltype) && (prt->Width == subprt->Width) && (prt->Minmax == subprt->Minmax))
												|| ((prt->srefWdbeKHdltype == "slvdn") && (subprt->srefWdbeKHdltype == "sl"))
												|| ((prt->srefWdbeKHdltype == "slvdn") && (subprt->srefWdbeKHdltype == "slvdn") && (prt->Width > subprt->Width)) );

									if (!match) Wdbe::appendToTmpfile(xchg->tmppath, logfile, logfi, "wiring error 11: mismatch of port " + submdl->sref + "." + subprt->sref + " characteristics with superior module " + mdl->sref + "!");

									subprt->cprSrefWdbeMPort = subprt->sref;
									dbswdbe->tblwdbemport->updateRec(subprt);

								} else {
									// insert copy of sub-module's port with equal characteristics
									refWdbeCPort = 0;
									if (subprt->refWdbeCPort != 0) {
										auto it = convPrtCs.find(subprt->refWdbeCPort);
										if (it != convPrtCs.end()) refWdbeCPort = it->second;
										else {
											refWdbeCPort = dbswdbe->tblwdbecport->getNewRef();
											convPrtCs[subprt->refWdbeCPort] = refWdbeCPort;
										};
									};

									dbswdbe->tblwdbemport->appendNewRecToRst(prts, NULL, refWdbeCPort, mdl->ref, prts.nodes.size()+1, subprt->mdlIxVCat, subprt->sref, subprt->ixVDir, subprt->srefWdbeKHdltype, subprt->Width, subprt->Minmax, subprt->Defval, "", "", subprt->csiSrefWdbeMSignal, "");
									srefsPrts[subprt->sref] = prts.nodes[prts.nodes.size()-1];

									subprt->cprSrefWdbeMPort = subprt->sref;
									dbswdbe->tblwdbemport->updateRec(subprt);
								};
							};
						};
					};
				};
			};
		};

		for (unsigned int i = 0; i < busprts.nodes.size(); i++) if (busprts.nodes[i]->ref != 0) busprts.nodes[i] = NULL;
		for (unsigned int i = 0; i < lvdsprts.nodes.size(); i++) if (lvdsprts.nodes[i]->ref != 0) lvdsprts.nodes[i] = NULL;

		// --- clock buffers signal to output port
		for (unsigned int i = 0; i < sigs.nodes.size(); i++) {
			sig = sigs.nodes[i];

			if (sig->ixVBasetype == VecWdbeVMSignalBasetype::CLK) {
				// instantiate BUFG (the unorthodox way)
				dbswdbe->executeQuery("UPDATE TblWdbeMModule SET hkNum = hkNum + 1 WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND hkNum >= " + to_string(hkNum));
				ref = dbswdbe->tblwdbemmodule->appendNewRecToRst(submdls, NULL, VecWdbeVMModuleBasetype::MNFPRIM, mdl->hkIxVTbl, mdl->hkUref, hkNum++, mdl->ref, Wdbe::getRefMtp(dbswdbe, "BUFG"), 0, 0, "bufg" + StrMod::cap(sig->sref), "");

				refWdbeCPort = dbswdbe->tblwdbecport->getNewRef();
				dbswdbe->tblwdbemport->insertNewRec(NULL, refWdbeCPort, ref, 1, VecWdbeVMPortMdlCat::RTESUP, "I", VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", sig->sref, "");

				if (sig->drvRefWdbeMPort == 0) {
					dbswdbe->tblwdbemport->insertNewRec(NULL, refWdbeCPort, ref, 2, VecWdbeVMPortMdlCat::RTESUP, "O", VecWdbeVMPortDir::OUT, "sl", 1, "", "", "", "", sig->sref, "");

				} else {
					auto it = srefsPrts.begin();
					for (; it != srefsPrts.end(); it++) if (it->second->ref == sig->drvRefWdbeMPort) break;
					if (it != srefsPrts.end()) {
						dbswdbe->tblwdbemport->insertNewRec(NULL, refWdbeCPort, ref, 2, VecWdbeVMPortMdlCat::RTESUP, "O", VecWdbeVMPortDir::OUT, "sl", 1, "", "", "", it->first, "", "");
					} else {
						Wdbe::appendToTmpfile(xchg->tmppath, logfile, logfi, "wiring error 12: port for clock signal " + mdl->sref + "." + sig->sref + " doesn't exist!");
					};
				};
			};
		};

		// --- validation of top module ports vs. pins
		if (mdl->supRefWdbeMModule == 0) {
			// ...
		};

		// --- sensitivities for unit-level handshakes
		dbswdbe->loadRefsBySQL("SELECT DISTINCT refWdbeCSignal FROM TblWdbeMSignal WHERE ixVBasetype = " + to_string(VecWdbeVMSignalBasetype::HSHK) + " AND mgeIxVTbl = "
					+ to_string(VecWdbeVMSignalMgeTbl::MDL) + " AND mgeUref = " + to_string(mdl->ref), false, refs);

		for (unsigned int i = 0; i < refs.size(); i++) {
			if (refs[i] != 0) {
				dbswdbe->loadRefsBySQL("SELECT ref FROM TblWdbeMSignal WHERE refWdbeCSignal = " + to_string(refs[i]) + " AND mgeUref <> " + to_string(mdl->ref), false, refs2);

				for (unsigned int j = 0; j < refs2.size(); j++) dbswdbe->tblwdbemsensitivity->insertNewRec(NULL, VecWdbeVMSensitivityRefTbl::MDL, mdl->ref, VecWdbeVMSensitivitySrcTbl::SIG, refs2[j]);
			};
		};

		delete mdl;
	};

	if (logfi.is_open()) {
		logfi.close();

		ixOpVOpres = VecOpVOpres::FAILURE;
	};
	// IP run --- IEND

	return(new DpchRetWdbeGenWiring("", "", ixOpVOpres, 100, logfile));
};

// IP cust --- INSERT
