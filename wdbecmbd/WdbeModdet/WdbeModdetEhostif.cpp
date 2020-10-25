/**
	* \file WdbeModdetEhostif.cpp
	* Wdbe operation processor - add command wiring (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeModdetEhostif.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeModdet;

/******************************************************************************
 namespace WdbeModdetEhostif
 ******************************************************************************/

DpchRetWdbe* WdbeModdetEhostif::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeModdetEhostif* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;
	bool mcuNotFpga = dpchinv->mcuNotFpga;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	vector<ubigint> refs;
	ubigint ref;
	ubigint refC = 0;

	ListWdbeMModule mdls;
	WdbeMModule* mdl = NULL;

	WdbeMModule* mdl2 = NULL;

	map<ubigint,unsigned int> icsMdls; // by ref

	vector<uint> mdlNumPrts;

	ListWdbeMPort oldprts;

	vector<unsigned int> ics0Oldprts;
	vector<unsigned int> ics1Oldprts;

	vector<unsigned int> icsInvctrs; // first entry host interface
	unsigned int ixInvctr;

	ListWdbeMCommand cmds;
	WdbeMCommand* cmd = NULL;

	ListWdbeAMCommandInvpar ipas;
	WdbeAMCommandInvpar* ipa = NULL;

	ListWdbeAMCommandRetpar rpas;
	WdbeAMCommandRetpar* rpa = NULL;

	ubigint refTop = 0;
	ubigint refEhostif = 0;

	ubigint refPrcOp;

	uint mdlNumPrtEhostif;
	uint mdlNumSigTop, mdlNumSigEhostif;

	ubigint refCprtctr = 0;
	ubigint refCprt = 0;
	ubigint refCsighostif = 0;
	ubigint refCsigtop = 0;

	string From, To;

	string Offval;
	uint vecNum;

	unsigned int w;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		dbswdbe->tblwdbemmodule->loadRstByHktHku(mdl->hkIxVTbl, mdl->hkUref, false, mdls);
		delete mdl;
	};

	for (unsigned int i = 0; i < mdls.nodes.size(); i++) {
		mdl = mdls.nodes[i];

		if (mdl->ixVBasetype == VecWdbeVMModuleBasetype::TOP) {
			refTop = mdl->ref;
			
			mdlNumSigTop = 1;
			if (dbswdbe->loadUintBySQL("SELECT mdlNum FROM TblWdbeMSignal WHERE mdlRefWdbeMModule = " + to_string(refTop) + " ORDER BY mdlNum DESC LIMIT 1", mdlNumSigTop)) mdlNumSigTop++;

		} else if (mdl->ref == refWdbeMModule) {
			refEhostif = mdl->ref;

			dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMProcess WHERE refWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'op'", refPrcOp);

			mdlNumPrtEhostif = 1;
			if (dbswdbe->loadUintBySQL("SELECT mdlNum FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(refEhostif) + " ORDER BY mdlNum DESC LIMIT 1", mdlNumPrtEhostif)) mdlNumPrtEhostif++;

			mdlNumSigEhostif = 1;
			if (dbswdbe->loadUintBySQL("SELECT mdlNum FROM TblWdbeMSignal WHERE mdlRefWdbeMModule = " + to_string(refEhostif) + " ORDER BY mdlNum DESC LIMIT 1", mdlNumSigEhostif)) mdlNumSigEhostif++;
		};

		if ((refTop || mcuNotFpga) && refEhostif) break;
	};

	if ((refTop || mcuNotFpga) && refEhostif) {
		// --- prepare controllers and their relevant features
		mdl = mdls.nodes[0];
		dbswdbe->tblwdbemmodule->loadRstBySQL("SELECT * FROM TblWdbeMModule WHERE ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::ECTR) + " AND hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref), false, mdls);

		mdlNumPrts.resize(mdls.nodes.size());
		ics0Oldprts.resize(mdls.nodes.size());
		ics1Oldprts.resize(mdls.nodes.size());

		for (unsigned int i = 0; i < mdls.nodes.size(); i++) {
			mdl = mdls.nodes[i];

			icsMdls[mdl->ref] = i;

			mdlNumPrts[i] = 1;
			if (dbswdbe->loadUintBySQL("SELECT mdlNum FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(mdl->ref) + " ORDER BY mdlNum DESC LIMIT 1", mdlNumPrts[i])) mdlNumPrts[i]++;

			// pre-existing controller ports
			ics0Oldprts[i] = oldprts.nodes.size();
			dbswdbe->tblwdbemport->loadRstByMdl(mdl->ref, true, oldprts);
			ics1Oldprts[i] = oldprts.nodes.size();
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

					if ((cmd->ixVRettype == VecWdbeVMCommandRettype::VOID) || (cmd->ixVRettype == VecWdbeVMCommandRettype::IMMSNG)) {
						// -- handshake with host interface / invoking controller

						// - ports in controller
						refC = dbswdbe->tblwdbecport->getNewRef();
						dbswdbe->tblwdbemport->insertNewRec(NULL, refC, mdl->ref, mdlNumPrts[i]++, VecWdbeVMPortMdlCat::CMDBUS, "reqInv" + From + StrMod::cap(cmd->sref), VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", "reqInv" + To + StrMod::cap(mdl->sref) + StrMod::cap(cmd->sref), "");
						mergeCreateOprt(dbswdbe, refC, mdl->ref, mdlNumPrts[i], "ackInv" + From + StrMod::cap(cmd->sref), VecWdbeVMPortDir::OUT, "sl", 1, "ackInv" + To + StrMod::cap(mdl->sref) + StrMod::cap(cmd->sref), oldprts, ics0Oldprts[i], ics1Oldprts[i]);

						if (!mcuNotFpga) {
							refC = dbswdbe->tblwdbecport->getNewRef();

							if (k == 0) {
								// ports in host interface
								dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refEhostif, mdlNumPrtEhostif++, VecWdbeVMPortMdlCat::CMDBUS, "reqInv" + StrMod::cap(mdl->sref) + StrMod::cap(cmd->sref), VecWdbeVMPortDir::OUT, "sl", 1, "", "", "", "", "reqInv" + StrMod::cap(mdl->sref) + StrMod::cap(cmd->sref), "");
								dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refEhostif, mdlNumPrtEhostif++, VecWdbeVMPortMdlCat::CMDBUS, "ackInv" + StrMod::cap(mdl->sref) + StrMod::cap(cmd->sref), VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", "ackInv" + StrMod::cap(mdl->sref) + StrMod::cap(cmd->sref), "");

								// ehostif port reqInv... is driven by a logic combination implemented in Wrfpga

							} else {
								// ports in invoking controller
								// ex. {req/ack}InvLaserToVsetChange (same as in host interface)
								mergeCreateOprt(dbswdbe, refC, mdl2->ref, mdlNumPrts[icsInvctrs[k]], "reqInv" + StrMod::cap(mdl->sref) + StrMod::cap(cmd->sref), VecWdbeVMPortDir::OUT, "sl", 1, "reqInv" + To + StrMod::cap(mdl->sref) + StrMod::cap(cmd->sref), oldprts, ics0Oldprts[icsInvctrs[k]], ics1Oldprts[icsInvctrs[k]]);
								dbswdbe->tblwdbemport->insertNewRec(NULL, refC, mdl2->ref, mdlNumPrts[icsInvctrs[k]], VecWdbeVMPortMdlCat::CMDBUS, "ackInv" + StrMod::cap(mdl->sref) + StrMod::cap(cmd->sref), VecWdbeVMPortDir::IN, "sl", 1, "", "", "", "", "ackInv" + To + StrMod::cap(mdl->sref) + StrMod::cap(cmd->sref), "");
							}
						};

						if (!mcuNotFpga) {
							// signals in top module
							refC = dbswdbe->tblwdbecsignal->getNewRef();
							dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, refTop, mdlNumSigTop++, VecWdbeVMSignalMgeTbl::MDL, refEhostif, 0, "reqInv" + To + StrMod::cap(mdl->sref) + StrMod::cap(cmd->sref), false, "sl", 1, "", "", "", "", false, 0, "");
							dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::HSHK, refC, refTop, mdlNumSigTop++, VecWdbeVMSignalMgeTbl::MDL, mdl->ref, 0, "ackInv" + To + StrMod::cap(mdl->sref) + StrMod::cap(cmd->sref), false, "sl", 1, "", "", "", "", false, 0, "");
						};
					};
				};

				if ((ipas.nodes.size() > 0) || (rpas.nodes.size() > 0)) {
					// -- ports and signals for parameter passing
					refCprtctr = dbswdbe->tblwdbecport->getNewRef();
					if (!mcuNotFpga && (ipas.nodes.size() > 0)) refCsighostif = dbswdbe->tblwdbecsignal->getNewRef();
					if (!mcuNotFpga) refCsigtop = dbswdbe->tblwdbecsignal->getNewRef();

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

						// - invocation parameters
						for (unsigned int l = 0; l < ipas.nodes.size(); l++) {
							ipa = ipas.nodes[l];

							w = 8 * Wdbe::getParlen(ipa->ixWdbeVPartype, ipa->Length);

							// ports in controller
							if (ipa->ixWdbeVPartype == VecWdbeVPartype::VBLOB) {
								dbswdbe->tblwdbemport->insertNewRec(NULL, refCprtctr, mdl->ref, mdlNumPrts[i]++, VecWdbeVMPortMdlCat::CMDBUS, From + "Len" + StrMod::cap(ipa->sref), VecWdbeVMPortDir::IN, "slvdn", 8, "", "", "", "", To + "Len" + StrMod::cap(ipa->sref), "");
								w -= 8;
							};
							dbswdbe->tblwdbemport->insertNewRec(NULL, refCprtctr, mdl->ref, mdlNumPrts[i]++, VecWdbeVMPortMdlCat::CMDBUS, From + StrMod::cap(ipa->sref), VecWdbeVMPortDir::IN, "slvdn", w, "", "", "", "", To + StrMod::cap(ipa->sref), "");

							if (!mcuNotFpga && (k == 0)) {
								if (k == 0) {
									// ports and signals in host interface
									if (ipa->ixWdbeVPartype == VecWdbeVPartype::VBLOB) {
										ref = dbswdbe->tblwdbemport->insertNewRec(NULL, refCprt, refEhostif, mdlNumPrtEhostif++, VecWdbeVMPortMdlCat::CMDBUS, mdl->sref + StrMod::cap(cmd->sref) + "Len" + StrMod::cap(ipa->sref), VecWdbeVMPortDir::OUT, "slvdn", 8, "", "", "", "", mdl->sref + StrMod::cap(cmd->sref) + "Len" + StrMod::cap(ipa->sref), "");
										dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refCsighostif, refEhostif, mdlNumSigEhostif++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, mdl->sref + StrMod::cap(cmd->sref) + "Len" + StrMod::cap(ipa->sref), false, "slvdn", 8, "", "", "", to_string(ipa->Length), false, ref, "");
									};

									ref = dbswdbe->tblwdbemport->insertNewRec(NULL, refCprt, refEhostif, mdlNumPrtEhostif++, VecWdbeVMPortMdlCat::CMDBUS, mdl->sref + StrMod::cap(cmd->sref) + StrMod::cap(ipa->sref), VecWdbeVMPortDir::OUT, "slvdn", w, "", "", "", "", mdl->sref + StrMod::cap(cmd->sref) + StrMod::cap(ipa->sref), "");

									Offval = ipa->Defval;
									if (ipa->refWdbeMVectoritem != 0) if (dbswdbe->loadUintBySQL("SELECT vecNum FROM TblWdbeMVectoritem WHERE ref = " + to_string(ipa->refWdbeMVectoritem), vecNum)) Offval = to_string(vecNum);

									dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refCsighostif, refEhostif, mdlNumSigEhostif++, VecWdbeVMSignalMgeTbl::PRC, refPrcOp, 0, mdl->sref + StrMod::cap(cmd->sref) + StrMod::cap(ipa->sref), false, "slvdn", w, "", "", "", Offval, false, ref, "");

								} else {
									// ports in invoking controller
									// ex. vmonGetVpdVpd (same as in host interface)

									if (ipa->ixWdbeVPartype == VecWdbeVPartype::VBLOB) mergeCreateOprt(dbswdbe, refCprt, mdl2->ref, mdlNumPrts[icsInvctrs[k]], mdl->sref + StrMod::cap(cmd->sref) + "Len" + StrMod::cap(ipa->sref), VecWdbeVMPortDir::OUT, "slvdn", 8, mdl->sref + StrMod::cap(cmd->sref) + "Len" + StrMod::cap(ipa->sref), oldprts, ics0Oldprts[icsInvctrs[k]], ics1Oldprts[icsInvctrs[k]]);
									mergeCreateOprt(dbswdbe, refCprt, mdl2->ref, mdlNumPrts[icsInvctrs[k]], mdl->sref + StrMod::cap(cmd->sref) + StrMod::cap(ipa->sref), VecWdbeVMPortDir::OUT, "slvdn", w, mdl->sref + StrMod::cap(cmd->sref) + StrMod::cap(ipa->sref), oldprts, ics0Oldprts[icsInvctrs[k]], ics1Oldprts[icsInvctrs[k]]);
								};
							};

							if (!mcuNotFpga) {
								// signals in top module
								if (ipa->ixWdbeVPartype == VecWdbeVPartype::VBLOB) dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refCsigtop, refTop, mdlNumSigTop++, VecWdbeVMSignalMgeTbl::MDL, refEhostif, 0, To + "Len" + StrMod::cap(ipa->sref), false, "slvdn", 8, "", "", "", "", false, 0, "");
								dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refCsigtop, refTop, mdlNumSigTop++, VecWdbeVMSignalMgeTbl::MDL, refEhostif, 0, To + StrMod::cap(ipa->sref), false, "slvdn", w, "", "", "", "", false, 0, "");
							};
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
								if (rpa->ixWdbeVPartype == VecWdbeVPartype::VBLOB) mergeCreateOprt(dbswdbe, refCprtctr, mdl->ref, mdlNumPrts[i], cmd->sref + StrMod::cap(rpa->sref), VecWdbeVMPortDir::OUT, "slvdn", 8, mdl->sref + StrMod::cap(cmd->sref) + "Len" + StrMod::cap(rpa->sref), oldprts, ics0Oldprts[i], ics1Oldprts[i]);
								mergeCreateOprt(dbswdbe, refCprtctr, mdl->ref, mdlNumPrts[i], cmd->sref + StrMod::cap(rpa->sref), VecWdbeVMPortDir::OUT, "slvdn", w, mdl->sref + StrMod::cap(cmd->sref) + StrMod::cap(rpa->sref), oldprts, ics0Oldprts[i], ics1Oldprts[i]);
							};

							if (!mcuNotFpga) {
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
							};

							if (!mcuNotFpga && (k == 0)) {
								// signals in top module (return parameters are not specific to the host interface / invoking controller)
								if (rpa->ixWdbeVPartype == VecWdbeVPartype::VBLOB) dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refCsigtop, refTop, mdlNumSigTop++, VecWdbeVMSignalMgeTbl::MDL, mdl->ref, 0, mdl->sref + StrMod::cap(cmd->sref) + "Len" + StrMod::cap(rpa->sref), false, "slvdn", 8, "", "", "", "", false, 0, "");
								dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refCsigtop, refTop, mdlNumSigTop++, VecWdbeVMSignalMgeTbl::MDL, mdl->ref, 0, mdl->sref + StrMod::cap(cmd->sref) + StrMod::cap(rpa->sref), false, "slvdn", w, "", "", "", "", false, 0, "");
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

// IP cust --- IBEGIN
void WdbeModdetEhostif::mergeCreateOprt(
			DbsWdbe* dbswdbe
			, const ubigint refC
			, const ubigint refMdl
			, uint& mdlNum
			, const string& sref
			, const uint ixVDir
			, const string& srefHty
			, const usmallint Width
			, const string& srefCsi
			, ListWdbeMPort& oldprts
			, const unsigned int ix0Oldprts
			, const unsigned int ix1Oldprts
		) {
	WdbeMPort* oldprt = NULL;

	bool found = false;

	for (unsigned int i = ix0Oldprts; i < ix1Oldprts; i++) {
		oldprt = oldprts.nodes[i];

		if (oldprt->sref == sref) {
			oldprt->refWdbeCPort = refC;
			oldprt->mdlNum = mdlNum++;
			oldprt->csiSrefWdbeMSignal = srefCsi;
			dbswdbe->tblwdbemport->updateRec(oldprt);

			found = true;
			break;
		};
	};

	if (!found) dbswdbe->tblwdbemport->insertNewRec(NULL, refC, refMdl, mdlNum++, VecWdbeVMPortMdlCat::CMDBUS, sref, ixVDir, srefHty, Width, "", "", "", "", srefCsi, "");
};
// IP cust --- IEND


