/**
	* \file WdbeGenfstEhostif.cpp
	* Wdbe operation processor - add command wiring (implementation)
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

#include "WdbeGenfstEhostif.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeGenfst;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeGenfstEhostif
 ******************************************************************************/

DpchRetWdbe* WdbeGenfstEhostif::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeGenfstEhostif* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;
	bool mcuNotFpga = dpchinv->mcuNotFpga;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	vector<ubigint> refs;
	ubigint ref;
	ubigint refC = 0;

	ubigint refUnt = 0;

	ListWdbeMModule mdls;
	WdbeMModule* mdl = NULL;

	WdbeMModule* mdl2 = NULL;

	map<ubigint,unsigned int> icsMdls; // by ref

	vector<uint> mdlNumPrts;
	vector<uint> mdlNumVars;

	WdbeMPort* prt = NULL;

	vector<unsigned int> icsInvctrs; // first entry host interface

	ListWdbeMCommand cmds;
	WdbeMCommand* cmd = NULL;

	ListWdbeAMCommandInvpar ipas;
	WdbeAMCommandInvpar* ipa = NULL;

	ListWdbeAMCommandRetpar rpas;
	WdbeAMCommandRetpar* rpa = NULL;

	ubigint refTop = 0;

	ubigint refEhostif = 0;
	string srefEhostif;

	ubigint refPrcOp;

	uint untNumSig = 1;
	uint mdlNumPrtEhostif;
	uint mdlNumSigTop, mdlNumSigEhostif;

	ubigint refCprtctr = 0;
	ubigint refCprt = 0;
	ubigint refCsighostif = 0;
	ubigint refCsigtop = 0;
	ubigint refCvarctr = 0;

	unsigned int sizeInvbuf, sizeRetbuf;

	string From, To;

	string Offval;
	uint vecNum;

	unsigned int w;
	string srefWdbeKHdltype;

	string s;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		refUnt = mdl->hkUref;

		refEhostif = mdl->ref;
		srefEhostif = mdl->sref;

		dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMProcess WHERE refWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'op'", refPrcOp);

		mdlNumPrtEhostif = 1;
		if (dbswdbe->loadUintBySQL("SELECT mdlNum FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(refEhostif) + " ORDER BY mdlNum DESC LIMIT 1", mdlNumPrtEhostif)) mdlNumPrtEhostif++;

		mdlNumSigEhostif = Wdbe::getNextSigRefNum(dbswdbe, VecWdbeVMSignalRefTbl::MDL, refEhostif);
		untNumSig = Wdbe::getNextSigRefNum(dbswdbe, VecWdbeVMSignalRefTbl::UNT, refUnt);

		dbswdbe->tblwdbemmodule->loadRstByHktHku(mdl->hkIxVTbl, mdl->hkUref, false, mdls);

		delete mdl;
	};

	if (!mcuNotFpga) {
		for (unsigned int i = 0; i < mdls.nodes.size(); i++) {
			mdl = mdls.nodes[i];

			if (mdl->ixVBasetype == VecWdbeVMModuleBasetype::TOP) {
				refTop = mdl->ref;
				mdlNumSigTop = Wdbe::getNextSigRefNum(dbswdbe, VecWdbeVMSignalRefTbl::MDL, refTop);

				break;
			};
		};
	};

	if ((refTop || mcuNotFpga) && refEhostif) {
		if (refTop) {
			// --- connect reset request
			if (dbswdbe->tblwdbemport->loadRecBySQL("SELECT * FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(refEhostif) + " AND sref = 'reqReset'", &prt)) {
				s = "reqResetFrom" + StrMod::cap(srefEhostif);

				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, 0, VecWdbeVMSignalRefTbl::MDL, refTop, mdlNumSigTop++, VecWdbeVMSignalMgeTbl::MDL, refEhostif, 0, s, false, "sl", 1, "", "", "", "", 0, "");

				prt->csiSrefWdbeMSignal = s;
				dbswdbe->tblwdbemport->updateRec(prt);

				delete prt;
			};
		};

		// --- prepare controllers and their relevant features
		mdl = mdls.nodes[0];
		dbswdbe->tblwdbemmodule->loadRstBySQL("SELECT * FROM TblWdbeMModule WHERE (ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::ECTR) + " OR ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::EDBGCTR)
					+ ") AND hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref), false, mdls);

		mdlNumPrts.resize(mdls.nodes.size());
		mdlNumVars.resize(mdls.nodes.size());

		for (unsigned int i = 0; i < mdls.nodes.size(); i++) {
			mdl = mdls.nodes[i];

			icsMdls[mdl->ref] = i;

			mdlNumPrts[i] = Wdbe::getNextPrtMdlNum(dbswdbe, mdl->ref);
			mdlNumVars[i] = Wdbe::getNextVarRefNum(dbswdbe, VecWdbeVMVariableRefTbl::MDL, mdl->ref);
		};

		if (mcuNotFpga) {
			// -- receive buffer in host interface shared data
			Wdbe::getHostifSizeInvretbuf(dbswdbe, refUnt, sizeInvbuf, sizeRetbuf);

			dbswdbe->tblwdbemvariable->insertNewRec(NULL, 0, VecWdbeVMVariableRefTbl::MDL, refEhostif, 1, "invbuf", false, false, "btarr", sizeInvbuf, "", "", "", "");
		};

		// --- top/ehostif/ectr ports and signals
		for (unsigned int i = 0; i < mdls.nodes.size(); i++) {
			mdl = mdls.nodes[i];

			dbswdbe->tblwdbemcommand->loadRstByRetReu(VecWdbeVMCommandRefTbl::CTR, mdl->refWdbeMController, false, cmds);
			
			for (unsigned int j = 0; j < cmds.nodes.size(); j++) {
				cmd = cmds.nodes[j];

				icsInvctrs.clear();
				icsInvctrs.push_back(0);

				dbswdbe->loadRefsBySQL("SELECT TblWdbeMModule.ref FROM TblWdbeRMCommandMController, TblWdbeMModule WHERE TblWdbeRMCommandMController.refWdbeMCommand = " + to_string(cmd->ref)
							+ " AND TblWdbeRMCommandMController.refWdbeMController = TblWdbeMModule.refWdbeMController ORDER BY TblWdbeMModule.sref ASC", false, refs);

				for (unsigned int k = 0; k < refs.size(); k++) icsInvctrs.push_back(icsMdls[refs[k]]);

				dbswdbe->tblwdbeamcommandinvpar->loadRstByCmd(cmd->ref, false, ipas);
				dbswdbe->tblwdbeamcommandretpar->loadRstByCmd(cmd->ref, false, rpas);

				for (unsigned int k = 0; k < icsInvctrs.size(); k++) {
					if (k == 0) {
						From = "";
						To = "";

					} else {
						mdl2 = mdls.nodes[icsInvctrs[k]];

						From = "From" + StrMod::cap(mdl2->sref);
						To = StrMod::cap(mdl2->sref) + "To";
					};

					// -- handshake with host interface / invoking controller
					if ((cmd->ixVRettype == VecWdbeVMCommandRettype::VOID) || (cmd->ixVRettype == VecWdbeVMCommandRettype::IMMSNG)) {
						if (!mcuNotFpga) {
							// - ports in controller
							refC = dbswdbe->tblwdbecport->getNewRef();
							dbswdbe->tblwdbemport->insertNewRec(NULL, refC, mdl->ref, mdlNumPrts[i]++, VecWdbeVMPortMdlCat::CMDBUS, "reqInv" + From + StrMod::cap(cmd->sref), VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", "reqInv" + To + StrMod::cap(mdl->sref) + StrMod::cap(cmd->sref), "");
							dbswdbe->tblwdbemport->insertNewRec(NULL, refC, mdl->ref, mdlNumPrts[i]++, VecWdbeVMPortMdlCat::CMDBUS, "ackInv" + From + StrMod::cap(cmd->sref), VecWdbeVMPortDir::OUT, "sl", 1, "", "", "", "", "ackInv" + To + StrMod::cap(mdl->sref) + StrMod::cap(cmd->sref), "");

							refC = dbswdbe->tblwdbecport->getNewRef();

							if (k == 0) {
								// ports in host interface
								dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refEhostif, mdlNumPrtEhostif++, VecWdbeVMPortMdlCat::CMDBUS, "reqInv" + StrMod::cap(mdl->sref) + StrMod::cap(cmd->sref), VecWdbeVMPortDir::OUT, "sl", 1, "", "", "", "", "reqInv" + StrMod::cap(mdl->sref) + StrMod::cap(cmd->sref), "");
								dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refEhostif, mdlNumPrtEhostif++, VecWdbeVMPortMdlCat::CMDBUS, "ackInv" + StrMod::cap(mdl->sref) + StrMod::cap(cmd->sref), VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", "ackInv" + StrMod::cap(mdl->sref) + StrMod::cap(cmd->sref), "");

								// ehostif port reqInv... is driven by a logic combination implemented in Wrfpga

							} else {
								// ports in invoking controller
								// ex. {req/ack}InvLaserToVsetChange (same as in host interface)
								dbswdbe->tblwdbemport->insertNewRec(NULL, refC, mdl2->ref, mdlNumPrts[icsInvctrs[k]], VecWdbeVMPortMdlCat::CMDBUS, "reqInv" + StrMod::cap(mdl->sref) + StrMod::cap(cmd->sref), VecWdbeVMPortDir::OUT, "sl", 1, "", "", "", "", "reqInv" + To + StrMod::cap(mdl->sref) + StrMod::cap(cmd->sref), "");
								dbswdbe->tblwdbemport->insertNewRec(NULL, refC, mdl2->ref, mdlNumPrts[icsInvctrs[k]], VecWdbeVMPortMdlCat::CMDBUS, "ackInv" + StrMod::cap(mdl->sref) + StrMod::cap(cmd->sref), VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", "ackInv" + To + StrMod::cap(mdl->sref) + StrMod::cap(cmd->sref), "");
							};

							// signals in top module
							refC = dbswdbe->tblwdbecsignal->getNewRef();
							dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, refTop, mdlNumSigTop++, VecWdbeVMSignalMgeTbl::MDL, refEhostif, 0, "reqInv" + To + StrMod::cap(mdl->sref) + StrMod::cap(cmd->sref), false, "sl", 1, "", "", "", "", 0, "");
							dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::MDL, refTop, mdlNumSigTop++, VecWdbeVMSignalMgeTbl::MDL, mdl->ref, 0, "ackInv" + To + StrMod::cap(mdl->sref) + StrMod::cap(cmd->sref), false, "sl", 1, "", "", "", "", 0, "");

						} else {
							// signals associated with unit
							refC = dbswdbe->tblwdbecsignal->getNewRef();
							dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::UNT, refUnt, untNumSig++, VecWdbeVMSignalMgeTbl::MDL, refEhostif, 0, "reqInv" + To + StrMod::cap(mdl->sref) + StrMod::cap(cmd->sref), false, "bit", 1, "", "", "", "", 0, "");
							dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, VecWdbeVMSignalRefTbl::UNT, refUnt, untNumSig++, VecWdbeVMSignalMgeTbl::MDL, mdl->ref, 0, "ackInv" + To + StrMod::cap(mdl->sref) + StrMod::cap(cmd->sref), false, "bit", 1, "", "", "", "", 0, "");
						};

					} else if (cmd->ixVRettype == VecWdbeVMCommandRettype::STATSNG) {
						if (mcuNotFpga) {
							if (k == 0) {
								// update signal associated with unit
								dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::STRB, 0, VecWdbeVMSignalRefTbl::UNT, refUnt, untNumSig++, VecWdbeVMSignalMgeTbl::MDL, mdl->ref, 0, mdl->sref + StrMod::cap(cmd->sref), false, "bit", 1, "", "", "", "", 0, "");
							};
						};
					};
				};

				if ((ipas.nodes.size() > 0) || (rpas.nodes.size() > 0)) {
					// -- ports and signals (FPGA) vs. variables (MCU) for parameter passing
					if (!mcuNotFpga) {
						refCprtctr = dbswdbe->tblwdbecport->getNewRef();
						if (ipas.nodes.size() > 0) refCsighostif = dbswdbe->tblwdbecsignal->getNewRef();
						refCsigtop = dbswdbe->tblwdbecsignal->getNewRef();

						// - invocation parameters
						for (unsigned int k = 0; k < icsInvctrs.size(); k++) {
							if (k == 0) {
								From = cmd->sref;
								To = mdl->sref + StrMod::cap(cmd->sref);

							} else {
								mdl2 = mdls.nodes[icsInvctrs[k]];

								From = "from" + StrMod::cap(mdl2->sref) + StrMod::cap(cmd->sref);
								To = mdl2->sref + "To" + StrMod::cap(mdl->sref) + StrMod::cap(cmd->sref);
							};

							refCprt = dbswdbe->tblwdbecport->getNewRef(); // may refer to host interface or invoking controller

							for (unsigned int l = 0; l < ipas.nodes.size(); l++) {
								ipa = ipas.nodes[l];

								w = 8 * Wdbe::getParlen(ipa->ixWdbeVPartype, ipa->Length);

								// ports in controller
								if (ipa->ixWdbeVPartype == VecWdbeVPartype::VBLOB) {
									dbswdbe->tblwdbemport->insertNewRec(NULL, refCprtctr, mdl->ref, mdlNumPrts[i]++, VecWdbeVMPortMdlCat::CMDBUS, From + "Len" + StrMod::cap(ipa->sref), VecWdbeVMPortDir::IN, "slvdn", 8, "", "", "", "", To + "Len" + StrMod::cap(ipa->sref), "");
									w -= 8;
								};
								dbswdbe->tblwdbemport->insertNewRec(NULL, refCprtctr, mdl->ref, mdlNumPrts[i]++, VecWdbeVMPortMdlCat::CMDBUS, From + StrMod::cap(ipa->sref), VecWdbeVMPortDir::IN, "slvdn", w, "", "", "", "", To + StrMod::cap(ipa->sref), "");

								if (k == 0) {
									// ports and signals in host interface
									if (ipa->ixWdbeVPartype == VecWdbeVPartype::VBLOB) {
										ref = dbswdbe->tblwdbemport->insertNewRec(NULL, refCprt, refEhostif, mdlNumPrtEhostif++, VecWdbeVMPortMdlCat::CMDBUS, mdl->sref + StrMod::cap(cmd->sref) + "Len" + StrMod::cap(ipa->sref), VecWdbeVMPortDir::OUT, "slvdn", 8, "", "", "", "", mdl->sref + StrMod::cap(cmd->sref) + "Len" + StrMod::cap(ipa->sref), "");
										dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refCsighostif, VecWdbeVMSignalRefTbl::MDL, refEhostif, mdlNumSigEhostif++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, mdl->sref + StrMod::cap(cmd->sref) + "Len" + StrMod::cap(ipa->sref), false, "slvdn", 8, "", "", "", to_string(ipa->Length), ref, "");
									};

									ref = dbswdbe->tblwdbemport->insertNewRec(NULL, refCprt, refEhostif, mdlNumPrtEhostif++, VecWdbeVMPortMdlCat::CMDBUS, mdl->sref + StrMod::cap(cmd->sref) + StrMod::cap(ipa->sref), VecWdbeVMPortDir::OUT, "slvdn", w, "", "", "", "", mdl->sref + StrMod::cap(cmd->sref) + StrMod::cap(ipa->sref), "");

									Offval = ipa->Defval;
									if (ipa->refWdbeMVectoritem != 0) if (dbswdbe->loadUintBySQL("SELECT vecNum FROM TblWdbeMVectoritem WHERE ref = " + to_string(ipa->refWdbeMVectoritem), vecNum)) Offval = to_string(vecNum);

									dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refCsighostif, VecWdbeVMSignalRefTbl::MDL, refEhostif, mdlNumSigEhostif++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, mdl->sref + StrMod::cap(cmd->sref) + StrMod::cap(ipa->sref), false, "slvdn", w, "", "", "", Offval, ref, "");

								} else {
									// ports in invoking controller
									// ex. finitetxFreeIx (same as in host interface), connect to top module signel rpuifToFiniterxFreeIx

									if (ipa->ixWdbeVPartype == VecWdbeVPartype::VBLOB) dbswdbe->tblwdbemport->insertNewRec(NULL, refCprt, mdl2->ref, mdlNumPrts[icsInvctrs[k]]++, VecWdbeVMPortMdlCat::CMDBUS, mdl->sref + StrMod::cap(cmd->sref) + "Len" + StrMod::cap(ipa->sref), VecWdbeVMPortDir::OUT, "slvdn", 8, "", "", "", "", To + "Len" + StrMod::cap(ipa->sref), "");
									dbswdbe->tblwdbemport->insertNewRec(NULL, refCprt, mdl2->ref, mdlNumPrts[icsInvctrs[k]]++, VecWdbeVMPortMdlCat::CMDBUS, mdl->sref + StrMod::cap(cmd->sref) + StrMod::cap(ipa->sref), VecWdbeVMPortDir::OUT, "slvdn", w, "", "", "", "", To + StrMod::cap(ipa->sref), "");
								};

								// signals in top module
								if (ipa->ixWdbeVPartype == VecWdbeVPartype::VBLOB) dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refCsigtop, VecWdbeVMSignalRefTbl::MDL, refTop, mdlNumSigTop++, VecWdbeVMSignalMgeTbl::MDL, refEhostif, 0, To + "Len" + StrMod::cap(ipa->sref), false, "slvdn", 8, "", "", "", "", 0, "");
								dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refCsigtop, VecWdbeVMSignalRefTbl::MDL, refTop, mdlNumSigTop++, VecWdbeVMSignalMgeTbl::MDL, refEhostif, 0, To + StrMod::cap(ipa->sref), false, "slvdn", w, "", "", "", "", 0, "");
							};
						};

						// - return parameters
						for (unsigned int k = 0; k < icsInvctrs.size(); k++) {
							if (k > 0) mdl2 = mdls.nodes[icsInvctrs[k]];

							for (unsigned int l = 0; l < rpas.nodes.size(); l++) {
								rpa = rpas.nodes[l];

								w = 8 * Wdbe::getParlen(rpa->ixWdbeVPartype, rpa->Length);

								if (k == 0) {
									// ports in controller
									if (rpa->ixWdbeVPartype == VecWdbeVPartype::VBLOB) {
										dbswdbe->tblwdbemport->insertNewRec(NULL, refCprtctr, mdl->ref, mdlNumPrts[i]++, VecWdbeVMPortMdlCat::CMDBUS, cmd->sref + "Len" + StrMod::cap(rpa->sref), VecWdbeVMPortDir::OUT, "slvdn", 8, "", "", "", "", mdl->sref + StrMod::cap(cmd->sref) + "Len" + StrMod::cap(rpa->sref), "");
										w -= 8;
									};
									dbswdbe->tblwdbemport->insertNewRec(NULL, refCprtctr, mdl->ref, mdlNumPrts[i]++, VecWdbeVMPortMdlCat::CMDBUS, cmd->sref + StrMod::cap(rpa->sref), VecWdbeVMPortDir::OUT, "slvdn", w, "", "", "", "", mdl->sref + StrMod::cap(cmd->sref) + StrMod::cap(rpa->sref), "");
								};

								if (k == 0) {
									// ports in host interface
									if (rpa->ixWdbeVPartype == VecWdbeVPartype::VBLOB) dbswdbe->tblwdbemport->insertNewRec(NULL, refCprt, refEhostif, mdlNumPrtEhostif++, VecWdbeVMPortMdlCat::CMDBUS, mdl->sref + StrMod::cap(cmd->sref) + "Len" + StrMod::cap(rpa->sref), VecWdbeVMPortDir::IN, "slvdn", 8, "", "", "", "", mdl->sref + StrMod::cap(cmd->sref) + "Len" + StrMod::cap(rpa->sref), "");
									dbswdbe->tblwdbemport->insertNewRec(NULL, refCprt, refEhostif, mdlNumPrtEhostif++, VecWdbeVMPortMdlCat::CMDBUS, mdl->sref + StrMod::cap(cmd->sref) + StrMod::cap(rpa->sref), VecWdbeVMPortDir::IN, "slvdn", w, "", "", "", "", mdl->sref + StrMod::cap(cmd->sref) + StrMod::cap(rpa->sref), "");

								} else {
									// ports in invoking controller
									// ex. vsetSetVxyVxy (same as in host interface)

									if (rpa->ixWdbeVPartype == VecWdbeVPartype::VBLOB) dbswdbe->tblwdbemport->insertNewRec(NULL, refCprt, mdl2->ref, mdlNumPrts[icsInvctrs[k]]++, VecWdbeVMPortMdlCat::CMDBUS, mdl->sref + StrMod::cap(cmd->sref) + "Len" + StrMod::cap(rpa->sref), VecWdbeVMPortDir::IN, "slvdn", 8, "", "", "", "", mdl->sref + StrMod::cap(cmd->sref) + "Len" + StrMod::cap(rpa->sref), "");
									dbswdbe->tblwdbemport->insertNewRec(NULL, refCprt, mdl2->ref, mdlNumPrts[icsInvctrs[k]]++, VecWdbeVMPortMdlCat::CMDBUS, mdl->sref + StrMod::cap(cmd->sref) + StrMod::cap(rpa->sref), VecWdbeVMPortDir::IN, "slvdn", w, "", "", "", "", mdl->sref + StrMod::cap(cmd->sref) + StrMod::cap(rpa->sref), "");
								};

								if (k == 0) {
									// signals in top module (return parameters are not specific to the host interface / invoking controller)
									if (rpa->ixWdbeVPartype == VecWdbeVPartype::VBLOB) dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refCsigtop, VecWdbeVMSignalRefTbl::MDL, refTop, mdlNumSigTop++, VecWdbeVMSignalMgeTbl::MDL, mdl->ref, 0, mdl->sref + StrMod::cap(cmd->sref) + "Len" + StrMod::cap(rpa->sref), false, "slvdn", 8, "", "", "", "", 0, "");
									dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refCsigtop, VecWdbeVMSignalRefTbl::MDL, refTop, mdlNumSigTop++, VecWdbeVMSignalMgeTbl::MDL, mdl->ref, 0, mdl->sref + StrMod::cap(cmd->sref) + StrMod::cap(rpa->sref), false, "slvdn", w, "", "", "", "", 0, "");
								};
							};
						};

					} else {
						if (rpas.nodes.size() > 0) {
							// variables in shared data block
							refCvarctr = dbswdbe->tblwdbecvariable->getNewRef();

							for (unsigned int l = 0; l < rpas.nodes.size(); l++) {
								rpa = rpas.nodes[l];

								switch (rpa->ixWdbeVPartype) {
									case VecWdbeVPartype::INT8:
										srefWdbeKHdltype = "sgn";
										w = 8;
										break;
									case VecWdbeVPartype::INT16:
										srefWdbeKHdltype = "sgn";
										w = 16;
										break;
									case VecWdbeVPartype::UINT16:
										srefWdbeKHdltype = "usgn";
										w = 16;
										break;
									case VecWdbeVPartype::INT32:
										srefWdbeKHdltype = "sgn";
										w = 32;
										break;
									case VecWdbeVPartype::UINT32:
										srefWdbeKHdltype = "usgn";
										w = 32;
										break;
									case VecWdbeVPartype::BLOB:
									case VecWdbeVPartype::VBLOB:
										srefWdbeKHdltype = "btarr";
										w = rpa->Length;
										break;

									//case VecWdbeVPartype::TIX:
									//case VecWdbeVPartype::_BOOL:
									//case VecWdbeVPartype::UINT8:
									default:
										srefWdbeKHdltype = "usgn";
										w = 8;
								};

								if (rpa->ixWdbeVPartype == VecWdbeVPartype::VBLOB) dbswdbe->tblwdbemvariable->insertNewRec(NULL, refCvarctr, VecWdbeVMVariableRefTbl::MDL, mdl->ref, mdlNumVars[i]++, cmd->sref + "Len" + StrMod::cap(rpa->sref), false, false, "usgn", 8, "", "", "", "");
								dbswdbe->tblwdbemvariable->insertNewRec(NULL, refCvarctr, VecWdbeVMVariableRefTbl::MDL, mdl->ref, mdlNumVars[i]++, cmd->sref + StrMod::cap(rpa->sref), false, false, srefWdbeKHdltype, w, "", "", "", "");
							};
						};
					};
				};
			};
		};
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
