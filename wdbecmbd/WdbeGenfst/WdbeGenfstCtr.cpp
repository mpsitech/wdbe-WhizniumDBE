/**
	* \file WdbeGenfstCtr.cpp
	* Wdbe operation processor - add command process and FSM debug ports (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 13 May 2023
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeGenfstCtr.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeGenfst;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeGenfstCtr
 ******************************************************************************/

DpchRetWdbe* WdbeGenfstCtr::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeGenfstCtr* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;
	string Prjshort = dpchinv->Prjshort;
	string Untsref = dpchinv->Untsref;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	vector<ubigint> refs;
	ubigint ref, refC;

	ListWdbeMModule mdls;
	WdbeMModule* mdl = NULL;
	WdbeMModule* mdl2 = NULL;
	uint mdlNum;

	WdbeMController* ctr = NULL;

	string Cmdbussref;

	set<pair<string,string> > pairsCmdbus;

	string condAnyrd, condNord;
	string condAnywr, condNowr;

	ListWdbeMProcess prcs;
	WdbeMProcess* prc = NULL;
	WdbeMProcess* prc2 = NULL;

	uint prcNum;
	uint fsmNum;

	ListWdbeMSignal sigs;
	WdbeMSignal* sig = NULL;
	WdbeMSignal* sig2 = NULL;

	ListWdbeMCommand cmds;
	WdbeMCommand* cmd = NULL;

	ListWdbeAMCommandInvpar ipas;

	unsigned int maxlenRecv, maxlenSend;
	unsigned int sizeCmdbuf;

	vector<string> srefsCmdSigIvr;
	vector<string> srefsCmdSigsIvas;
	vector<ubigint> refsCmdPrc;

	vector<string> srefsCmdSigRvr;
	vector<string> srefsCmdSigsRvas;

	vector<string> srefsCmdSigRer;

	vector<ubigint> refsCmdFstInv;
	vector<ubigint> refsCmdFstPrepRet;

	vector<bool> vlensCmdInv;

	ListWdbeRMCommandMController crcs;
	WdbeRMCommandMController* crc = NULL;

	ListWdbeAMCommandRetpar rpas;

	vector<string> mdlsrefsExtcmd; // ex. Pmmu
	vector<string> srefsExtcmd; // ex. Alloc

	vector<uint> rtysExtcmd;
	vector<string> srefsExtcmdSigIvr;
	vector<string> srefsExtcmdSigRvr;

	vector<ubigint> refsExtcmdFstPrepInv;
	vector<ubigint> refsExtcmdFstPrepRev;

	vector<bool> vlensExtcmdRet;

	map<ubigint,string> srefsPrcSigrootCmd; // process sref if process manages multiple commands, command sref else
	map<string,ubigint> refsSrefsPrcSigrootCmdFstPrepCreferr; // read: refs{srefsPrcSigrootCmd}FstPrepCreferr

	ListWdbeMError errs;
	WdbeMError* err = NULL;

	vector<string> srefsErrSigTra;

	vector<string> srefsErrSigsTrrs;
	vector<string> srefsPrcSigrootCmdSrefsErrSigsTrrs; // read: srefsPrcSigrootCmd{srefsErrSigsTrrs}

	vector<ubigint> refsFstPrepErr;

	map<string,ubigint> refsSrefsErrSigsTrrsFstPrepErr; // read: refs{srefsErrSigsTrrs}FstPrepErr

	ListWdbeMFsmstate oldfsts;
	map<string,unsigned int> icsOldfsts; // by sref

	ListWdbeMFsmstate fsts;
	WdbeMFsmstate* fst = NULL;
	map<ubigint,unsigned int> icsFsts; // by ref
	ubigint refFst, refFst2, refFstNext;

	uint fstNum;

	bool hasFwderr, hasWaitLock, hasRecvShrte, hasRecvHshk, hasSend, hasSendHshk, hasSigLenCmdbuf;

	ubigint refFstInit = 0, refFstEmpty = 0;
	ubigint refFstWaitLockA = 0, refFstWaitLockB = 0, refFstWaitLockC = 0;
	ubigint refFstLock = 0;
	ubigint refFstRecvA = 0, refFstRecvB = 0, refFstRecvC = 0, refFstRecvD = 0, refFstRecvE = 0, refFstRecvF = 0, refFstRecvG = 0;
	ubigint refFstFullA = 0, refFstFullB = 0;
	ubigint refFstSendA = 0, refFstSendB = 0, refFstSendC = 0, refFstSendD = 0;
	ubigint refFstPrepCreferr = 0;

	bool maxOneOldFstNoFass, maxOneOldFstNoFass2;

	string condLcl;

	ListWdbeAMFsmstateStep fass;
	WdbeAMFsmstateStep* fas = NULL;

	vector<string> ss, ss2;
	set<string> unqss;
	string s, s2, s3;

	bool found, first;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		if (dbswdbe->tblwdbemcontroller->loadRecByRef(mdl->refWdbeMController, &ctr)) {
			dbswdbe->tblwdbemmodule->loadRstByHktHku(VecWdbeVMModuleHkTbl::UNT, mdl->hkUref, false, mdls);

			for (unsigned int i = 0; i < mdls.nodes.size(); i++) {
				mdl2 = mdls.nodes[i];

				if (mdl2->ixVBasetype == VecWdbeVMModuleBasetype::CMDBUS) {
					Cmdbussref = StrMod::cap(mdl2->sref);
					break;
				};
			};

			Wdbe::getPairsCmdbus(dbswdbe, mdls, pairsCmdbus);

			// any/no read/write conditions
			for (auto it = pairsCmdbus.begin(); it != pairsCmdbus.end(); it++) {
				if (it->first == mdl->sref) {
					if (condAnywr != "") condAnywr += " or ";
					condAnywr += "wr" + Cmdbussref + "To" + StrMod::cap(it->second);

					if (condNowr != "") condNowr += " and ";
					condNowr += "!wr" + Cmdbussref + "To" + StrMod::cap(it->second);

				} else if (it->second == mdl->sref) {
					if (condAnyrd != "") condAnyrd += " or ";
					condAnyrd += "rd" + Cmdbussref + "From" + StrMod::cap(it->first);

					if (condNord != "") condNord += " and ";
					condNord += "!rd" + Cmdbussref + "From" + StrMod::cap(it->first);
				};
			};

			if (!dbswdbe->tblwdbemprocess->loadRecBySQL("SELECT * FROM TblWdbeMProcess WHERE refWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'cmd'", &prc)) dbswdbe->tblwdbemprocess->insertNewRec(&prc, mdl->ref, 0, "cmd", "mclk", "reset", true, "", false, "command execution");
			
			if (prc->refWdbeMFsm == 0) {
				prc->refWdbeMFsm = dbswdbe->tblwdbemfsm->insertNewRec(NULL, prc->ref);
				dbswdbe->tblwdbemprocess->updateRec(prc);
			};

			// load user-defined FSM states (to be merged)
			dbswdbe->tblwdbemfsmstate->loadRstByFsm(prc->refWdbeMFsm, false, oldfsts);
			for (unsigned int i = 0; i < oldfsts.nodes.size(); i++) icsOldfsts[oldfsts.nodes[i]->sref] = i;

			// load signals
			dbswdbe->tblwdbemsignal->loadRstByRetReu(VecWdbeVMSignalRefTbl::MDL, mdl->ref, false, sigs);

			mdlNum = 1;

			if (sigs.nodes.size() > 0) {
				mdlNum = sigs.nodes[sigs.nodes.size()-1]->refNum;
				mdlNum++;
			};

			// --- command and error analysis
			dbswdbe->tblwdbemcommand->loadRstByRetReu(VecWdbeVMCommandRefTbl::CTR, ctr->ref, false, cmds);

			srefsCmdSigIvr.resize(cmds.nodes.size()); srefsCmdSigsIvas.resize(cmds.nodes.size()); refsCmdPrc.resize(cmds.nodes.size(), 0);
			srefsCmdSigRvr.resize(cmds.nodes.size()); srefsCmdSigsRvas.resize(cmds.nodes.size());
			srefsCmdSigRer.resize(cmds.nodes.size());

			refsCmdFstInv.resize(cmds.nodes.size(), 0);
			refsCmdFstPrepRet.resize(cmds.nodes.size(), 0);

			vlensCmdInv.resize(cmds.nodes.size(), false);

			for (unsigned int i = 0; i < cmds.nodes.size(); i++) {
				cmd = cmds.nodes[i];

				for (unsigned int j = 0; j < sigs.nodes.size(); j++) {
					sig = sigs.nodes[j];

					if (sig->ref == cmd->ivrRefWdbeMSignal) {
						srefsCmdSigIvr[i] = sig->sref.substr(3);

						for (unsigned int k = 0; k < sigs.nodes.size(); k++) {
							sig2 = sigs.nodes[k];
							
							if ((sig2->refWdbeCSignal == sig->refWdbeCSignal) && (sig2->sref.substr(0, 3) == "ack")) {
								if (srefsCmdSigsIvas[i] != "") {
									srefsCmdSigsIvas[i] += ";";
								} else {
									// first invoke acknowledgement signal determines governing process
									if ( ((cmd->ixVRettype == VecWdbeVMCommandRettype::DFRSNG) || (cmd->ixVRettype == VecWdbeVMCommandRettype::MULT)) && (sig2->mgeIxVTbl == VecWdbeVMSignalMgeTbl::PRC) ) {
										refsCmdPrc[i] = sig2->mgeUref;

										auto it = srefsPrcSigrootCmd.find(sig2->mgeUref);
										if (it == srefsPrcSigrootCmd.end()) srefsPrcSigrootCmd[sig2->mgeUref] = cmd->sref;
										else if (dbswdbe->loadStringBySQL("SELECT sref FROM TblWdbeMProcess WHERE ref = " + to_string(sig2->mgeUref), s)) srefsPrcSigrootCmd[sig2->mgeUref] = s;
									};
								};

								srefsCmdSigsIvas[i] += sig2->sref;
							};
						};

					} else if (sig->ref == cmd->rvrRefWdbeMSignal) {
						srefsCmdSigRvr[i] = sig->sref.substr(3);
						
						for (unsigned int k = 0; k < sigs.nodes.size(); k++) {
							sig2 = sigs.nodes[k];

							if ((sig2->refWdbeCSignal == sig->refWdbeCSignal) && (sig2->sref.substr(0, 3) == "ack")) {
								if (srefsCmdSigsRvas[i] != "") srefsCmdSigsRvas[i] += ";";
								srefsCmdSigsRvas[i] += sig2->sref;
							};
						};

					} else if (sig->ref == cmd->rerRefWdbeMSignal) {
						srefsCmdSigRer[i] = sig->sref.substr(3);
					};
				};

				dbswdbe->tblwdbeamcommandinvpar->loadRstByCmd(cmd->ref, false, ipas);
				for (unsigned int j = 0; j < ipas.nodes.size(); j++) {
					if (ipas.nodes[j]->ixWdbeVPartype == VecWdbeVPartype::VBLOB) {
						vlensCmdInv[i] = true;
						break;
					};
				};
			};

			dbswdbe->tblwdbermcommandmcontroller->loadRstByCtr(ctr->ref, false, crcs);
			mdlsrefsExtcmd.resize(crcs.nodes.size());
			srefsExtcmd.resize(crcs.nodes.size());
			rtysExtcmd.resize(crcs.nodes.size());
			for (unsigned int i = 0; i < rtysExtcmd.size();i++) rtysExtcmd[i] = VecWdbeVMCommandRettype::VOID;
			srefsExtcmdSigIvr.resize(crcs.nodes.size());
			srefsExtcmdSigRvr.resize(crcs.nodes.size());

			refsExtcmdFstPrepInv.resize(crcs.nodes.size(), 0);
			refsExtcmdFstPrepRev.resize(crcs.nodes.size(), 0);

			vlensExtcmdRet.resize(crcs.nodes.size(), false);

			for (unsigned int i = 0; i < crcs.nodes.size(); i++) {
				crc = crcs.nodes[i];

				if (dbswdbe->tblwdbemcommand->loadRecByRef(crc->refWdbeMCommand, &cmd)) {
					for (unsigned int j = 0; j < mdls.nodes.size(); j++) {
						mdl2 = mdls.nodes[j];

						if (mdl2->refWdbeMController == cmd->refUref) {
							mdlsrefsExtcmd[i] = StrMod::cap(mdl2->sref);
							srefsExtcmd[i] = StrMod::cap(cmd->sref);
							rtysExtcmd[i] = cmd->ixVRettype;

							for (unsigned int k = 0; k < sigs.nodes.size(); k++) {
								sig = sigs.nodes[k];
								
								if (sig->ref == crc->ivrRefWdbeMSignal) {
									srefsExtcmdSigIvr[i] = sig->sref.substr(3);
								} else if (sig->ref == crc->rvrRefWdbeMSignal) {
									srefsExtcmdSigRvr[i] = sig->sref.substr(3);
								};
							};
							
							break;
						};
					};

					delete cmd;
				};

				dbswdbe->tblwdbeamcommandretpar->loadRstByCmd(crc->refWdbeMCommand, false, rpas);
				for (unsigned int j = 0; j < rpas.nodes.size(); j++) {
					if (rpas.nodes[j]->ixWdbeVPartype == VecWdbeVPartype::VBLOB) {
						vlensExtcmdRet[i] = true;
						break;
					};
				};
			};

			dbswdbe->tblwdbemerror->loadRstByRetReu(VecWdbeVMErrorRefTbl::CTR, ctr->ref, false, errs);

			srefsErrSigTra.resize(errs.nodes.size());
			srefsErrSigsTrrs.resize(errs.nodes.size()); srefsPrcSigrootCmdSrefsErrSigsTrrs.resize(errs.nodes.size());

			refsFstPrepErr.resize(errs.nodes.size(), 0);

			for (unsigned int i = 0; i < errs.nodes.size(); i++) {
				err = errs.nodes[i];

				for (unsigned int j = 0; j < sigs.nodes.size(); j++) {
					sig = sigs.nodes[j];

					if (sig->ref == err->traRefWdbeMSignal) {
						srefsErrSigTra[i] = sig->sref.substr(3);

						for (unsigned int k = 0; k < sigs.nodes.size(); k++) {
							sig2 = sigs.nodes[k];
							
							if ((sig2->refWdbeCSignal == sig->refWdbeCSignal) && (sig2->sref.substr(0, 3) == "req")) {
								if (srefsErrSigsTrrs[i] != "") {
									srefsErrSigsTrrs[i] += ";";
									srefsPrcSigrootCmdSrefsErrSigsTrrs[i] += ";";
								};

								srefsErrSigsTrrs[i] += sig2->sref;

								auto it = srefsPrcSigrootCmd.find(sig2->mgeUref);
								if (it != srefsPrcSigrootCmd.end()) srefsPrcSigrootCmdSrefsErrSigsTrrs[i] += it->second;
							};
						};

						break;
					};
				};
			};

			hasFwderr = (icsOldfsts.find("prepFwderrA") != icsOldfsts.end());

			hasWaitLock = (icsOldfsts.find("lock") != icsOldfsts.end());
			if (!hasWaitLock) {
				for (unsigned int i = 0; i < cmds.nodes.size(); i++) {
					if (srefsCmdSigRer[i] != "") {
						hasWaitLock = true;
						break;
					};
				};
			};
			if (!hasWaitLock) {
				for (unsigned int i = 0; i < crcs.nodes.size(); i++) {
					if ((srefsExtcmdSigIvr[i] != "") || (srefsExtcmdSigRvr[i] != "")) {
						hasWaitLock = true;
						break;
					};
				};
			};
			if (!hasWaitLock) {
				for (unsigned int i = 0; i < errs.nodes.size(); i++) {
					if (srefsErrSigsTrrs[i] != "") {
						hasWaitLock = true;
						break;
					};
				};
			};

			hasRecvShrte = false;
			for (unsigned int i = 0; i < cmds.nodes.size(); i++) {
				cmd = cmds.nodes[i];

				if (cmd->ixVRettype != VecWdbeVMCommandRettype::VOID) {
					// immsng (obvious), dfrsng/mult for possible creferr
					hasRecvShrte = true;
					break;
				};
			};

			hasRecvHshk = false;
			for (unsigned int i = 0; i < cmds.nodes.size(); i++) {
				if ((srefsCmdSigIvr[i] != "") || (srefsCmdSigRvr[i] != "")) {
					hasRecvHshk = true;
					break;
				};
			};
			if (!hasRecvHshk) {
				for (unsigned int i = 0; i < crcs.nodes.size(); i++) {
					if ((srefsExtcmdSigIvr[i] != "") && ((rtysExtcmd[i] == VecWdbeVMCommandRettype::STATSNG) || (rtysExtcmd[i] == VecWdbeVMCommandRettype::IMMSNG))) {
						hasRecvHshk = true;
						break;
					};
				};
			};

			hasSend = hasFwderr;
			if (!hasSend) hasSend = (crcs.nodes.size() > 0);
			if (!hasSend) {
				for (unsigned int i = 0; i < cmds.nodes.size(); i++) {
					cmd = cmds.nodes[i];

					if (cmd->ixVRettype != VecWdbeVMCommandRettype::VOID) {
						hasSend = true;
						break;
					};
				};
			};

			hasSendHshk = false;
			if (hasSend) {
				hasSendHshk = hasFwderr;
				if (!hasSendHshk) {
					for (unsigned int i = 0; i < cmds.nodes.size(); i++) {
						if (srefsCmdSigRer[i] != "") {
							hasSendHshk = true;
							break;
						};
					};
				};
				if (!hasSendHshk) {
					for (unsigned int i = 0; i < errs.nodes.size(); i++) {
						if (srefsErrSigTra[i] != "") {
							hasSendHshk = true;
							break;
						};
					};
				};
				if (!hasSendHshk) {
					for (unsigned int i = 0; i < crcs.nodes.size(); i++) {
						if (((srefsExtcmdSigIvr[i] != "") && ((rtysExtcmd[i] == VecWdbeVMCommandRettype::DFRSNG) || (rtysExtcmd[i] == VecWdbeVMCommandRettype::MULT))) || (srefsExtcmdSigRvr[i] != "")) {
							hasSendHshk = true;
							break;
						};
					};
				};
			};

			// --- signals and variables
			prcNum = 1;

			// - sizeCmdbuf, cmdbuf_t and cmdbuf, lenCmdbuf, i/j/x, bytecnt
			refC = dbswdbe->tblwdbecsignal->getNewRef();

			maxlenRecv = 0;
			maxlenSend = 0;

			getMaxlenRecvSend(dbswdbe, VecWdbeVMCommandRefTbl::CTR, mdl->refWdbeMController, maxlenRecv, maxlenSend);

			if (maxlenRecv > maxlenSend) sizeCmdbuf = maxlenRecv;
			else sizeCmdbuf = maxlenSend;

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "sizeCmdbuf", true, "nat", 0, "", "", "", to_string(sizeCmdbuf), 0, "");

			dbswdbe->tblwdbeavkeylistkey->insertNewRec(NULL, VecWdbeVKeylist::KLSTWDBEKHDLTYPE, 0, VecWdbeVMaintable::TBLWDBEMPROCESS, prc->ref, true, "cmdbuf_t", "", "", 0, "array (0 to sizeCmdbuf-1) of std_logic_vector(7 downto 0)", "");

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "cmdbuf", false, "cmdbuf_t", 0, "", "", "", "", 0, "");

			// lenCmdbuf: pre-existing signal vs. variable
			hasSigLenCmdbuf = false;
			for (unsigned int i = 0; i < sigs.nodes.size(); i++) {
				sig = sigs.nodes[i];

				if ((sig->mgeIxVTbl == VecWdbeVMSignalMgeTbl::PRC) && (sig->mgeUref == prc->ref) && (sig->sref == "lenCmdbuf")) {
					sig->refWdbeCSignal = refC;
					dbswdbe->tblwdbemsignal->updateRec(sig);
					
					hasSigLenCmdbuf = true;

					break;
				};
			};
			if (!hasSigLenCmdbuf) dbswdbe->tblwdbemvariable->insertNewRec(NULL, refC, VecWdbeVMVariableRefTbl::PRC, prc->ref, prcNum++, "lenCmdbuf", false, false, "nat", 0, "0..sizeCmdbuf", "", "0", "");

			if (hasFwderr || hasRecvShrte) {
				refC = dbswdbe->tblwdbecvariable->getNewRef();

				dbswdbe->tblwdbemvariable->insertNewRec(NULL, refC, VecWdbeVMVariableRefTbl::PRC, prc->ref, prcNum++, "i", false, false, "nat", 0, "0..sizeCmdbuf", "", "0", "");
				dbswdbe->tblwdbemvariable->insertNewRec(NULL, refC, VecWdbeVMVariableRefTbl::PRC, prc->ref, prcNum++, "j", false, false, "nat", 0, "0..sizeCmdbuf", "", "0", "");
				dbswdbe->tblwdbemvariable->insertNewRec(NULL, refC, VecWdbeVMVariableRefTbl::PRC, prc->ref, prcNum++, "x", false, false, "slvdn", 8, "", "", "0", "");
			};

			if (hasSend) dbswdbe->tblwdbemvariable->insertNewRec(NULL, 0, VecWdbeVMVariableRefTbl::PRC, prc->ref, prcNum++, "bytecnt", false, false, "nat", 0, "0..sizeCmdbuf", "", "0", "");

			// - vector items
			addCtrVits(dbswdbe, ctr, cmds, mdlNum, Prjshort, Untsref);

			// - commands and errors
			for (unsigned int i = 0; i < cmds.nodes.size(); i++) {
				cmd = cmds.nodes[i];
				addCmdErrSigs(dbswdbe, mdl, mdlNum, prc, cmd, "", "", StrMod::cap(cmd->sref), NULL);
			};

			for (unsigned int i = 0; i < errs.nodes.size(); i++) {
				err = errs.nodes[i];
				addCmdErrSigs(dbswdbe, mdl, mdlNum, prc, NULL, "", "", "", err);
			};

			for (unsigned int i = 0; i < crcs.nodes.size(); i++) {
				crc = crcs.nodes[i];

				if (dbswdbe->tblwdbemcommand->loadRecByRef(crc->refWdbeMCommand, &cmd)) {
					addCmdErrSigs(dbswdbe, mdl, mdlNum, prc, cmd, Untsref, mdlsrefsExtcmd[i], srefsExtcmd[i], NULL);
					delete cmd;
				};
			};

			// - dCmdbus
			found = (crcs.nodes.size() > 0);

			if (!found) {
				for (unsigned int j = 0; j < cmds.nodes.size(); j++) {
					cmd = cmds.nodes[j];

					if (cmd->ixVRettype != VecWdbeVMCommandRettype::VOID) {
						found = true;
						break;
					};
				};
			};

			if (found) if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'd" + Cmdbussref + "'", ref))
						dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::IOPRT, 0, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "d" + Cmdbussref, false, "slvdn", 8, "", "state(sendA..C)", "", "", ref, "");

			// - rdy/req signals
			refC = 0;
			first = true;
			for (auto it = pairsCmdbus.begin(); it != pairsCmdbus.end(); it++) {
				if ((it->first == mdl->sref) || (it->second == mdl->sref)) {
					if (first) {
						refC = dbswdbe->tblwdbecsignal->getNewRef();
						first = false;
					};

					if (it->first == mdl->sref) {
						if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'req" + Cmdbussref + "To" + StrMod::cap(it->second) + "'", ref))
									dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "req" + Cmdbussref + "To" + StrMod::cap(it->second), false, "sl", 1, "", "", "1", "0", ref, "");
					} else if (it->second == mdl->sref) {
						if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'rdy" + Cmdbussref + "From" + StrMod::cap(it->first) + "'", ref))
									dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OPRT, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "rdy" + Cmdbussref + "From" + StrMod::cap(it->first), false, "sl", 1, "", "", "0", "1", ref, "");
					};
				};
			};

			// - rte/cref/tixVCommand for processes governing commands with deferred / multiple return(s)
			for (auto it = srefsPrcSigrootCmd.begin(); it != srefsPrcSigrootCmd.end(); it++) {
				if (dbswdbe->tblwdbemprocess->loadRecByRef(it->first, &prc2)) {
					refC = dbswdbe->tblwdbecsignal->getNewRef();

					dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, prc2->ref, 0, "route" + StrMod::cap(it->second), false, "slvdn", 8, "", "", "", "", 0, "");
					dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, prc2->ref, 0, "cref" + StrMod::cap(it->second), false, "slvdn", 32, "", "", "", "", 0, "");
					if (it->second == prc2->sref) dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, prc2->ref, 0, "tixVCommand" + StrMod::cap(it->second), false, "slvdn", 8, "", "", "", "", 0, "");

					delete prc2;
				};
			};

			// --- command FSM
			// general order: init, empty, waitLock/lock, recv, full, send, inv*, prepRet*/prepNewret*, prepCreferr*, prepFwderr, prepErr*, prepInv*, prepRev*
			// pre-existing states: init, empty, lock, fullA, sendC, prepFwderrA/B ; generally, all steppings are kept
			// steppings to lock are altered for empty
			// steppings to init are altered for sendC
			// lock is inserted after waitLockC w/ all steppings
			// prepFwderr* are inserted after prepCreferr* w/ all steppings
			// inv*, prepRet*, prepNewret*, prepErr*, prepInv*, prepRev* may have A-Z suffixes
			// all other pre-existing states are added at the end w/ all steppings

			// -- states / states&steppings for cmd/err/extcmd-specific states
			fsmNum = 1;

			// - stateCmdInit
			refFstInit = mergeCreateFsts(dbswdbe, prc->refWdbeMFsm, 0, "init", oldfsts, fsts, fsmNum, true, maxOneOldFstNoFass);

			// - stateCmdEmpty
			refFstEmpty = mergeCreateFsts(dbswdbe, prc->refWdbeMFsm, 0, "empty", oldfsts, fsts, fsmNum, true, maxOneOldFstNoFass);

			// - stateCmdWaitLockA..C
			if (hasWaitLock) {
				refC = dbswdbe->tblwdbecfsmstate->getNewRef();
				refFstWaitLockA = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "waitLockA", false, "");
				refFstWaitLockB = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "waitLockB", false, "");
				refFstWaitLockC = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "waitLockC", false, "");
			};

			// - stateCmdLock
			refFstLock = mergeCreateFsts(dbswdbe, prc->refWdbeMFsm, 0, "lock", oldfsts, fsts, fsmNum, false, maxOneOldFstNoFass);

			// - stateCmdRecvA..G
			refC = dbswdbe->tblwdbecfsmstate->getNewRef();
			refFstRecvA = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "recvA", false, "");
			refFstRecvB = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "recvB", false, "");
			refFstRecvC = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "recvC", false, "");
			refFstRecvD = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "recvD", false, "");
			if (hasRecvShrte || hasRecvHshk) refFstRecvE = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "recvE", false, "");
			if (hasRecvShrte) refFstRecvF = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "recvF", false, "");
			if (hasRecvShrte && hasRecvHshk) refFstRecvG = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "recvG", false, "");

			// - stateCmdFullA..B
			if (hasSend) {
				refC = dbswdbe->tblwdbecfsmstate->getNewRef();
				refFstFullA = mergeCreateFsts(dbswdbe, prc->refWdbeMFsm, refC, "fullA", oldfsts, fsts, fsmNum, true, maxOneOldFstNoFass);
				refFstFullB = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "fullB", false, "");
			};

			// - stateCmdSendA..D
			if (hasSend) {
				refC = dbswdbe->tblwdbecfsmstate->getNewRef();
				refFstSendA = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "sendA", false, "");
				refFstSendB = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "sendB", false, "");
				refFstSendC = mergeCreateFsts(dbswdbe, prc->refWdbeMFsm, refC, "sendC", oldfsts, fsts, fsmNum, true, maxOneOldFstNoFass);
				if (hasSendHshk) refFstSendD = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "sendD", false, "");
			};

			// - stateCmdInv*
			for (unsigned int i = 0; i < cmds.nodes.size(); i++) {
				cmd = cmds.nodes[i];

				if ((srefsCmdSigIvr[i] == "") && (cmd->ixVRettype != VecWdbeVMCommandRettype::STATSNG)) {
					refsCmdFstInv[i] = mergeCreateFsts(dbswdbe, prc->refWdbeMFsm, 0, "inv" + StrMod::cap(cmd->sref), oldfsts, fsts, fsmNum, true, maxOneOldFstNoFass);
					if (maxOneOldFstNoFass) dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refsCmdFstInv[i], 1, refFstInit, "", "inv" + StrMod::cap(cmd->sref), "", "", "", "", "", ""); // custom IP
				};
			};

			// - stateCmdPrepRet*/stateCmdPrepNewret*
			for (unsigned int i = 0; i < cmds.nodes.size(); i++) {
				cmd = cmds.nodes[i];

				if (cmd->ixVRettype != VecWdbeVMCommandRettype::VOID) {
					if ((cmd->ixVRettype == VecWdbeVMCommandRettype::IMMSNG) || (cmd->ixVRettype == VecWdbeVMCommandRettype::DFRSNG)) s = "prepRet" + StrMod::cap(cmd->sref);
					else s = "prepNewret" + StrMod::cap(cmd->sref);

					// insertion point is of the form impl.cmd.prep{Ret/Newret}GetFrame.xyz in case the cref is known
					s2 = s;
					if (refsCmdPrc[i] != 0) {
						auto it = srefsPrcSigrootCmd.find(refsCmdPrc[i]);
						if (it != srefsPrcSigrootCmd.end()) s2 = it->second;
					};

					refsCmdFstPrepRet[i] = mergeCreateFsts(dbswdbe, prc->refWdbeMFsm, 0, s, oldfsts, fsts, fsmNum, true, maxOneOldFstNoFass);
					if (maxOneOldFstNoFass) dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refsCmdFstPrepRet[i], 1, refFstFullA, "", s2, "", "", "", "", "", ""); // type-specific + custom IP
				};
			};

			// - stateCmdPrepCreferr*
			if (!srefsPrcSigrootCmd.empty()) {
				refC = dbswdbe->tblwdbecfsmstate->getNewRef();

				refFstPrepCreferr = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, 0, "prepCreferr", false, "");
				dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstPrepCreferr, 1, refFstFullA, "", "prepCreferr", "", "", "", "", "", ""); // type-specific IP

				for (auto it = srefsPrcSigrootCmd.begin(); it != srefsPrcSigrootCmd.end(); it++) {
					refsSrefsPrcSigrootCmdFstPrepCreferr[it->second] = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, prc->refWdbeMFsm, fsmNum++, "prepCreferr" + StrMod::cap(it->second), false, "");
					dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refsSrefsPrcSigrootCmdFstPrepCreferr[it->second], 1, refFstPrepCreferr, "", "prepCreferr" + StrMod::cap(it->second), "", "", "", "", "", ""); // type-specific IP
				};

				dbswdbe->executeQuery("UPDATE TblWdbeMFsmstate SET fsmNum = " + to_string(fsmNum++) + " WHERE ref = " + to_string(refFstPrepCreferr));
			};

			// - stateCmdPrepFwderrA..B
			mergeCreateFsts(dbswdbe, prc->refWdbeMFsm, 0, "prepFwderrA", oldfsts, fsts, fsmNum, false, maxOneOldFstNoFass);
			mergeCreateFsts(dbswdbe, prc->refWdbeMFsm, 0, "prepFwderrB", oldfsts, fsts, fsmNum, false, maxOneOldFstNoFass);

			// - stateCmdPrepErr*
			for (unsigned int i = 0; i < errs.nodes.size(); i++) {
				err = errs.nodes[i];

				refsFstPrepErr[i] = mergeCreateFsts(dbswdbe, prc->refWdbeMFsm, 0, "prepErr" + StrMod::cap(err->sref), oldfsts, fsts, fsmNum, true, maxOneOldFstNoFass);

				StrMod::srefsToVector(srefsErrSigsTrrs[i], ss);
				StrMod::srefsToVector(srefsPrcSigrootCmdSrefsErrSigsTrrs[i], ss2);

				if (ss.size() < 2) {
					if (maxOneOldFstNoFass) {
						s2 = "";

						if (ss.size() == 1) {
							refsSrefsErrSigsTrrsFstPrepErr[ss[0]] = refsFstPrepErr[i];
							s2 = "." + ss2[0];
						};

						dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refsFstPrepErr[i], 1, refFstFullA, "", "prepErr" + StrMod::cap(err->sref) + s2, "", "", "", "", "", ""); // type-specific + custom IP
					};

				} else {
					if (maxOneOldFstNoFass) fsmNum--;

					for (unsigned int j = 0; j < ss.size();j++) {
						refsSrefsErrSigsTrrsFstPrepErr[ss[j]] = mergeCreateFsts(dbswdbe, prc->refWdbeMFsm, 0, "prepErr" + StrMod::cap(err->sref) + StrMod::cap(ss2[j]), oldfsts, fsts, fsmNum, true, maxOneOldFstNoFass2);
						if (maxOneOldFstNoFass2) dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refsSrefsErrSigsTrrsFstPrepErr[ss[j]], 1, refsFstPrepErr[i], "", "prepErr" + StrMod::cap(err->sref) + StrMod::cap(ss2[j]), "", "", "", "", "", ""); // type-specific + custom IP
					};

					if (maxOneOldFstNoFass) dbswdbe->executeQuery("UPDATE TblWdbeMFsmstate SET fsmNum = " + to_string(fsmNum++) + " WHERE ref = " + to_string(refsFstPrepErr[i]));
				};

				if (maxOneOldFstNoFass) dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refsFstPrepErr[i], 1, refFstFullA, "", "prepErr" + StrMod::cap(err->sref), "", "", "", "", "", ""); // type-specific + custom IP
			};

			// - stateCmdPrepInv*
			for (unsigned int i = 0; i < crcs.nodes.size(); i++) {
				if (srefsExtcmdSigIvr[i] != "") {
					refsExtcmdFstPrepInv[i] = mergeCreateFsts(dbswdbe, prc->refWdbeMFsm, 0, "prepInv" + mdlsrefsExtcmd[i] + srefsExtcmd[i], oldfsts, fsts, fsmNum, true, maxOneOldFstNoFass);
					if (maxOneOldFstNoFass) dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refsExtcmdFstPrepInv[i], 1, refFstFullA, "", "prepInv" + mdlsrefsExtcmd[i] + srefsExtcmd[i], "", "", "", "", "", ""); // type-specific + custom IP
				};
			};

			// - stateCmdPrepRev*
			for (unsigned int i = 0; i < crcs.nodes.size(); i++) {
				if (srefsExtcmdSigRvr[i] != "") {
					refsExtcmdFstPrepRev[i] = mergeCreateFsts(dbswdbe, prc->refWdbeMFsm, 0, "prepRev" + mdlsrefsExtcmd[i] + srefsExtcmd[i], oldfsts, fsts, fsmNum, true, maxOneOldFstNoFass);
					if (maxOneOldFstNoFass) dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refsExtcmdFstPrepRev[i], 1, refFstFullA, "", "prepRev" + mdlsrefsExtcmd[i] + srefsExtcmd[i], "", "", "", "", "", ""); // type-specific IP
				};
			};

			// - remaining user-defined states
			for (unsigned int i = 0; i < oldfsts.nodes.size(); i++) {
				fst = oldfsts.nodes[i];

				if (fst) {
					fst->fsmNum = fsmNum++;
					dbswdbe->tblwdbemfsmstate->updateRec(fst);
					fsts.nodes.push_back(fst);
					oldfsts.nodes[i] = NULL;
				};
			};

			// -- steppings
			for (unsigned int i = 0; i < fsts.nodes.size(); i++) icsFsts[fsts.nodes[i]->ref] = i;

			// - stateCmdInit
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstInit, 1, refFstEmpty, "", "syncrst", "", "", "", "", "", "");

			// - stateCmdEmpty
			fstNum = 1;

			// alter/replace pre-existing steppings from empty to lock
			dbswdbe->tblwdbeamfsmstatestep->loadRstByFst(refFstEmpty, false, fass);
			ss.clear();
			for (unsigned int i = 0; i < fass.nodes.size(); i++) {
				fas = fass.nodes[i];

				if ((fas->fnxRefWdbeMFsmstate == refFstLock) && (fas->Ip1 == "unrdy")) ss.push_back(fas->Cond1); // needed up to WaitLockC
			};

			dbswdbe->executeQuery("DELETE FROM TblWdbeAMFsmstateStep WHERE fstRefWdbeMFsmstate = " + to_string(refFstEmpty));

			// stateCmdEmpty.rd
			s = condAnyrd; // ex. (rdCmdbusFromCmdinv or rdCmdbusFromLwiracq) and clkCmdbus

			if (s != "") {
				if (s.find(' ') != string::npos) s = "(" + s + ")";
				s = s + " and clk" + Cmdbussref;
				dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstEmpty, fstNum++, refFstRecvA, s, "rd", "", "", "", "", "", ""); // type-specific IP
			};

			// stateCmdEmpty.unrdy
			s = ""; // ex. reqOpToCmdLock or reqReadToCmdRet or reqReadToCmdErr or reqWriteToCmdRet or reqWriteToCmdErr

			for (unsigned int i = 0; i < ss.size();i++) {
				if (s != "") s += " or ";
				if (ss[i].find(' ') != string::npos) s += "(" + ss[i] + ")";
				else s += ss[i];
			};

			for (unsigned int i = 0; i < cmds.nodes.size(); i++) {
				if (srefsCmdSigRer[i] != "") {
					if (s != "") s += " or ";
					s += "req" + srefsCmdSigRer[i];
				};
			};
			for (unsigned int i = 0; i < crcs.nodes.size(); i++) {
				if ((srefsExtcmdSigIvr[i] != "") || (srefsExtcmdSigRvr[i] != "")) {
					if (s != "") s += " or ";
					s += "req" + srefsExtcmdSigIvr[i];
				};
			};
			for (unsigned int i = 0; i < errs.nodes.size(); i++) {
				if (srefsErrSigsTrrs[i] != "") {
					StrMod::srefsToVector(srefsErrSigsTrrs[i], ss2);
					for (unsigned int j = 0; j < ss2.size();j++) {
						if (s != "") s += " or ";
						s += ss2[j];
					};
				};
			};

			if (s != "") {
				dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstEmpty, fstNum++, refFstWaitLockA, s, "unrdy", "!clk" + Cmdbussref, "", "", "", "", ""); // type-specific IP
				dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstEmpty, fstNum++, refFstWaitLockB, s, "unrdy", "clk" + Cmdbussref, "", "", "", "", ""); // type-specific IP
			};

			if (hasWaitLock) {
				// - stateCmdWaitLockA..B
				dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstWaitLockA, 1, refFstWaitLockB, "clk" + Cmdbussref, "", "", "", "", "", "", "");
				dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstWaitLockB, 1, refFstWaitLockC, "!clk" + Cmdbussref, "", "", "", "", "", "", "");

				// - stateCmdWaitLockC
				fstNum = 1;

				for (unsigned int i = 0; i < ss.size();i++)
							dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstWaitLockC, fstNum++, refFstLock, "clk" + Cmdbussref, "", condNord, "", ss[i], "", "", "");

				for (unsigned int i = 0; i < cmds.nodes.size(); i++) if (srefsCmdSigRer[i] != "")
							dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstWaitLockC, fstNum++, refsCmdFstPrepRet[i], "clk" + Cmdbussref, "", condNord, "", "req" + srefsCmdSigRer[i], "", "", "");

				for (unsigned int i = 0; i < crcs.nodes.size(); i++) if (srefsExtcmdSigIvr[i] != "")
							dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstWaitLockC, fstNum++, refsExtcmdFstPrepInv[i], "clk" + Cmdbussref, "", condNord, "", "req" + srefsExtcmdSigIvr[i], "", "", "");

				for (unsigned int i = 0; i < crcs.nodes.size(); i++) if (srefsExtcmdSigRvr[i] != "")
							dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstWaitLockC, fstNum++, refsExtcmdFstPrepInv[i], "clk" + Cmdbussref, "", condNord, "", "req" + srefsExtcmdSigRvr[i], "", "", "");

				for (unsigned int i = 0; i < errs.nodes.size(); i++) {
					if (srefsErrSigsTrrs[i] != "") {
						StrMod::srefsToVector(srefsErrSigsTrrs[i], ss2);

						for (unsigned int j = 0; j < ss2.size(); j++)
									dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstWaitLockC, fstNum++, refsSrefsErrSigsTrrsFstPrepErr[ss2[j]], "clk" + Cmdbussref, "", condNord, "", ss2[j], "", "", "");
					};
				};
				dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstWaitLockC, fstNum++, refFstInit, "clk" + Cmdbussref, "", condNord, "", "else", "", "", "");
				dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstWaitLockC, fstNum++, refFstRecvA, "clk" + Cmdbussref, "", "else", "", "", "", "", "");
			};

			// - stateCmdLock
			// all steppings are user-defined

			// - stateCmdRecvA..C
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstRecvA, 1, refFstRecvB, "!clk" + Cmdbussref, "", "", "", "", "", "", "");

			if (hasRecvShrte) dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstRecvB, 1, refFstRecvD, "clk" + Cmdbussref, "", condNord, "initshrte", "", "", "", ""); // type-specific IP
			else dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstRecvB, 1, refFstRecvD, "clk" + Cmdbussref, "", condNord, "", "", "", "", "");
			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstRecvB, 2, refFstRecvC, "clk" + Cmdbussref, "", "else", "copy", "", "", "", ""); // type-specific IP

			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstRecvC, 1, refFstRecvB, "!clk" + Cmdbussref, "recvC", "", "", "", "", "", ""); // type-specific IP

			if (hasRecvShrte) {
				// - stateCmdRecvD/E (shift route)
				dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstRecvD, 1, refFstRecvF, "j=4", "last", "", "", "", "", "", ""); // type-specific IP
				dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstRecvD, 2, refFstRecvE, "else", "load", "", "", "", "", "", ""); // type-specific IP

				dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstRecvE, 1, refFstRecvD, "", "store", "", "", "", "", "", ""); // type-specific IP
			};

			// - stateCmdRecvD/F
			if (hasRecvShrte) {
				refFst = refFstRecvF;
				refFst2 = refFstRecvG;
			} else {
				refFst = refFstRecvD;
				refFst2 = refFstRecvE;
			};
		
			fstNum = 1;

			condLcl = "cmdbuf(ixCmdbufRoute)=x\"00\"";

			for (unsigned int i = 0; i < cmds.nodes.size(); i++) {
				cmd = cmds.nodes[i];

				s = "(cmdbuf(ixCmdbufAction)=tixDbeVActionInv and cmdbuf(ixCmdbufInvCommand)=tixVCommand" + StrMod::cap(cmd->sref);
				if (vlensCmdInv[i]) s += " and lenCmdbuf<=maxlenCmdbufInv" + StrMod::cap(cmd->sref);
				else s += " and lenCmdbuf=lenCmdbufInv" + StrMod::cap(cmd->sref);
				s += ")";

				if ((cmd->ixVRettype == VecWdbeVMCommandRettype::VOID) || (cmd->ixVRettype == VecWdbeVMCommandRettype::IMMSNG)) {
					if (srefsCmdSigIvr[i] == "") {
						s2 = "";

						if (cmd->ixVRettype == VecWdbeVMCommandRettype::VOID) refFstNext = refsCmdFstInv[i];
						else refFstNext = refsCmdFstPrepRet[i];

					} else {
						s2 = "req" + srefsCmdSigIvr[i];
						
						refFstNext = refFst2;
					};

					dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFst, fstNum++, refFstNext, s, s2, "", "", "", "", "", ""); // type-specific IP (s2 != "")

				} else if ((cmd->ixVRettype == VecWdbeVMCommandRettype::DFRSNG) || (cmd->ixVRettype == VecWdbeVMCommandRettype::MULT)) {
					auto it = srefsPrcSigrootCmd.find(refsCmdPrc[i]);
					if (it != srefsPrcSigrootCmd.end()) {
						s2 = "cref" + StrMod::cap(it->second) + "=x\"00000000\"";

						dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFst, fstNum++, refFst2, s, "", s2, "req" + srefsCmdSigIvr[i], "", "", "", ""); // type-specific IP

						dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFst, fstNum++, refsSrefsPrcSigrootCmdFstPrepCreferr[it->second], s, "", "else", "", "", "", "", "");
					};
				};
			};

			unqss.clear();

			for (unsigned int i = 0; i < cmds.nodes.size(); i++) {
				cmd = cmds.nodes[i];

				auto it = srefsPrcSigrootCmd.find(refsCmdPrc[i]);
				if ((it != srefsPrcSigrootCmd.end()) && (srefsCmdSigRvr[i] != "")) unqss.insert(it->second);
			};

			if (!unqss.empty()) {
				s = "(cmdbuf(ixCmdbufAction)=tixDbeVActionRev and lenCmdbuf=lenCmdbufRev)";

				for (auto it = unqss.begin(); it != unqss.end(); it++) {
					s2 = "(cmdbuf(ixCmdbufCref)=cref" + StrMod::cap(*it) + "(31 downto 24) and cmdbuf(ixCmdbufCref+1)=cref" + StrMod::cap(*it) + "(23 downto 16) and cmdbuf(ixCmdbufCref+2)=cref" + StrMod::cap(*it) + "(15 downto 8) and cmdbuf(ixCmdbufCref+3)=cref" + StrMod::cap(*it) + "(7 downto 0))";

					ss.clear();
					for (unsigned int i = 0; i < cmds.nodes.size(); i++) {
						cmd = cmds.nodes[i];

						auto it2 = srefsPrcSigrootCmd.find(refsCmdPrc[i]);
						if ((it2 != srefsPrcSigrootCmd.end()) && (srefsCmdSigRvr[i] != "")) if (it2->second == *it) ss.push_back("req" + srefsCmdSigRvr[i]);
					};

					StrMod::vectorToString(ss, s3);
					dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFst, fstNum++, refFst2, s, "", s2, s3, "", "", "", ""); // type-specific IP
				};

				dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFst, fstNum++, refFstInit, s, "", "else", "", "", "", "", "");
			};

			for (unsigned int i = 0; i < crcs.nodes.size(); i++) {
				crc = crcs.nodes[i];

				if ((srefsExtcmdSigIvr[i] != "") && ((rtysExtcmd[i] == VecWdbeVMCommandRettype::STATSNG) || (rtysExtcmd[i] == VecWdbeVMCommandRettype::IMMSNG))) {
					s = "(cmdbuf(ixCmdbufAction)=tixDbeVActionRet";
					s += " and cmdbuf(ixCmdbufCref)=tixV" + Untsref + mdlsrefsExtcmd[i] + "Command" + srefsExtcmd[i];
					if (vlensExtcmdRet[i]) s += " and lenCmdbuf<=maxlenCmdbufRet" + mdlsrefsExtcmd[i] + srefsExtcmd[i];
					else s += " and lenCmdbuf=lenCmdbufRet" + mdlsrefsExtcmd[i] + srefsExtcmd[i];
					s += ")";

					dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFst, fstNum++, refFst2, s, "ack" + srefsExtcmdSigIvr[i], "", "", "", "", "", ""); // type-specific IP
				};
			};

			dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFst, fstNum++, refFstInit, "else", "", "", "", "", "", "", "");

			if (hasRecvHshk) {
				// - stateCmdRecvE/G
				if (hasRecvShrte) refFst = refFstRecvG;
				else refFst = refFstRecvE;

				unqss.clear();
				s = "";

				for (unsigned int i = 0; i < cmds.nodes.size(); i++) {
					if (srefsCmdSigIvr[i] != "") if (unqss.find(srefsCmdSigIvr[i]) == unqss.end()) {
						s2 = "req" + srefsCmdSigIvr[i];

						StrMod::srefsToVector(srefsCmdSigsIvas[i], ss);
						for (unsigned int j = 0; j < ss.size();j++) s2 += " and " + ss[j];

						if (s != "") s += " or ";
						s += "(" + s2 + ")";

						unqss.insert(srefsCmdSigIvr[i]);
					};

					if (srefsCmdSigRvr[i] != "") if (unqss.find(srefsCmdSigRvr[i]) == unqss.end()) {
						s2 = "req" + srefsCmdSigRvr[i];

						StrMod::srefsToVector(srefsCmdSigsRvas[i], ss);
						for (unsigned int j = 0; j < ss.size();j++) s2 += " and " + ss[j];

						if (s != "") s += " or ";
						s += "(" + s2 + ")";

						unqss.insert(srefsCmdSigRvr[i]);
					};
				};

				for (unsigned int i = 0; i < crcs.nodes.size(); i++) {
					if ((srefsExtcmdSigIvr[i] != "") && ((rtysExtcmd[i] == VecWdbeVMCommandRettype::STATSNG) || (rtysExtcmd[i] == VecWdbeVMCommandRettype::IMMSNG))) {
						s2 = "!req" + srefsExtcmdSigIvr[i] + " and ack" + srefsExtcmdSigIvr[i];

						if (s != "") s += " or ";
						s += "(" + s2 + ")";
					};
				};

				dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFst, 1, refFstInit, s, "", "", "", "", "", "", "");
			};

			if (hasSend) {
				// - stateCmdFullA..B
				fstNum = 1;

				for (auto it = pairsCmdbus.begin(); it != pairsCmdbus.end(); it++) if (it->first == mdl->sref)
							dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstFullA, fstNum++, refFstFullB, "cmdbuf(ixCmdbufRoute)=tixV" + Prjshort + Untsref + "Controller" + StrMod::cap(it->second), StrMod::uncap(it->second), "", "", "", "", "", ""); // type-specific IP
				dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstFullA, fstNum++, refFstInit, "else", "", "", "", "", "", "", "");

				s = condAnywr;
				if (s.find(' ') != string::npos) s = "(" + s + ")";
				s += " and clk" + Cmdbussref;

				dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstFullB, fstNum++, refFstSendA, s, "first", "", "", "", "", "", ""); // type-specific IP

				// - stateCmdSendA..C
				dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstSendA, 1, refFstSendB, "!clk" + Cmdbussref, "sendA", "", "", "", "", "", ""); // type-specific IP

				dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstSendB, 1, refFstSendC, "clk" + Cmdbussref, "", "bytecnt=lenCmdbuf", "", "", "", "", "");
				dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstSendB, 2, refFstSendA, "clk" + Cmdbussref, "", "else", "out", "", "", "", ""); // type-specific IP

				if (hasSendHshk) {
					// alter/replace pre-existing steppings from sendC to init
					dbswdbe->tblwdbeamfsmstatestep->loadRstByFst(refFstSendC, false, fass);

					for (unsigned int i = 0; i < fass.nodes.size(); i++) {
						fas = fass.nodes[i];

						if ((fas->fnxRefWdbeMFsmstate == refFstInit) && (fas->Cond1 == "nowr")) {
							fas->fnxRefWdbeMFsmstate = refFstSendD;
							fas->Cond1 = condNowr;

							dbswdbe->tblwdbeamfsmstatestep->updateRec(fas);
						};
					};

					fstNum = fass.nodes.size()+1;

					for (unsigned int i = 0; i < cmds.nodes.size(); i++) {
						if (srefsCmdSigRer[i] != "") {
							s = "(req" + srefsCmdSigRer[i] + "='1'";
							if (cmd->ixVRettype == VecWdbeVMCommandRettype::MULT) s += " and cmdbuf(ixCmdbufAction)=tixDbeVActionNewret";
							else s += " and cmdbuf(ixCmdbufAction)=tixDbeVActionRet";
							s += ")";
							// TBD: cref check

							dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstSendC, fstNum++, refFstSendD, condNowr, "", s, "ack" + srefsCmdSigRer[i], "", "", "", ""); // type-specific IP
						};
					};

					for (unsigned int i = 0; i < errs.nodes.size(); i++) {
						err = errs.nodes[i];

						if (srefsErrSigTra[i] != "") {
							StrMod::srefsToVector(srefsErrSigsTrrs[i], ss);

							for (unsigned int j = 0; j < ss.size();j++) {
								s = "(" + ss[j] + "='1'";
								s += " and cmdbuf(ixCmdbufAction)=tixDbeVActionErr";
								s += " and cmdbuf(ixCmdbufErrError)=tixVError" + StrMod::cap(err->sref);
								s += ")";
								// TBD: cref check

								dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstSendC, fstNum++, refFstSendD, condNowr, "", s, "ack" + srefsErrSigTra[i], "", "", "", ""); // type-specific IP
							};
						};
					};

					for (unsigned int i = 0; i < crcs.nodes.size(); i++) {
						crc = crcs.nodes[i];

						if (srefsExtcmdSigIvr[i] != "") {
							s = "(req" + srefsExtcmdSigIvr[i] + "='1'";
							s += " and cmdbuf(ixCmdbufAction)=tixDbeVActionInv";
							s += " and cmdbuf(ixCmdbufInvCommand)=tixV" + Untsref + mdlsrefsExtcmd[i] + "Command" + srefsExtcmd[i];
							s += ")";

							if ((rtysExtcmd[i] == VecWdbeVMCommandRettype::STATSNG) || (rtysExtcmd[i] == VecWdbeVMCommandRettype::IMMSNG)) {
								dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstSendC, fstNum++, refFstRecvA, condNowr, "", s, "rdy" + Cmdbussref + "From" + mdlsrefsExtcmd[i], "rd" + Cmdbussref + "From" + mdlsrefsExtcmd[i] + " and clk" + Cmdbussref, "", "", ""); // type-specific IP
							} else {
								dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstSendC, fstNum++, refFstSendD, condNowr, "", s, "ack" + srefsExtcmdSigIvr[i], "", "", "", ""); // type-specific IP
							};
						};

						if (srefsExtcmdSigRvr[i] != "") {
							s = "(req" + srefsExtcmdSigIvr[i] + "='1'";
							s += " and cmdbuf(ixCmdbufAction)=tixDbeVActionRev";
							s += " and cmdbuf(ixCmdbufRevCommand)=tixV" + Untsref + mdlsrefsExtcmd[i] + "Command" + srefsExtcmd[i];
							s += ")";

							dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstSendC, fstNum++, refFstSendD, condNowr, "", s, "ack" + srefsExtcmdSigRvr[i], "", "", "", ""); // type-specific IP
						};
					};

					dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstSendC, fstNum++, refFstInit, condNowr, "", "else", "", "", "", "", "");

				} else dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstSendC, fstNum++, refFstInit, condNowr, "", "", "", "", "", "", "");

				if (hasSendHshk) {
					// - stateCmdSendD
					s = "";

					for (unsigned int i = 0; i < cmds.nodes.size(); i++) {
						if (srefsCmdSigRer[i] != "") {
							s2 = "!req" + srefsCmdSigRer[i] + " and ack" + srefsCmdSigRer[i];

							if (s != "") s += " or ";
							s += "(" + s2 + ")";
						};
					};

					for (unsigned int i = 0; i < errs.nodes.size(); i++) {
						if (srefsErrSigTra[i] != "") {
							s2 = "";

							StrMod::srefsToVector(srefsErrSigsTrrs[i], ss);
							for (unsigned int j = 0; j < ss.size();j++) s2 += "!" + ss[j] + " and ";
								
							s2 += "ack" + srefsErrSigTra[i];

							if (s != "") s += " or ";
							s += "(" + s2 + ")";
						};
					};

					for (unsigned int i = 0; i < crcs.nodes.size(); i++) {
						if (((srefsExtcmdSigIvr[i] != "") && ((rtysExtcmd[i] == VecWdbeVMCommandRettype::DFRSNG) || (rtysExtcmd[i] == VecWdbeVMCommandRettype::MULT))) || (srefsExtcmdSigRvr[i] != "")) {
							s2 = "!req" + srefsExtcmdSigIvr[i] + " and ack" + srefsExtcmdSigIvr[i];

							if (s != "") s += " or ";
							s += "(" + s2 + ")";
						};
					};

					dbswdbe->tblwdbeamfsmstatestep->insertNewRec(NULL, refFstSendD, 1, refFstInit, s, "", "", "", "", "", "", "");
				};
			};

			delete ctr;
		};
	
		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WdbeGenfstCtr::addCmdErrSigs(
			DbsWdbe* dbswdbe
			, WdbeMModule* mdl
			, uint& mdlNum
			, WdbeMProcess* prc
			, WdbeMCommand* cmd
			, const string& UntsrefExtcmd // ex. Bss3
			, const string& MdlsrefExtcmd // ex. Pmmu
			, const string& Cmdsref // ex. Alloc
			, WdbeMError* err
		) {
	ubigint ref, refC;

	ListWdbeAMCommandInvpar ipas;
	WdbeAMCommandInvpar* ipa = NULL;

	ListWdbeAMCommandRetpar rpas;
	WdbeAMCommandRetpar* rpa = NULL;

	ListWdbeAMErrorPar epas;
	WdbeAMErrorPar* epa = NULL;

	unsigned int ix;

	string s;

	bool first, found;

	if (cmd) {
		refC = dbswdbe->tblwdbecsignal->getNewRef();

		// tixVCommand...
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "tixV" + UntsrefExtcmd + MdlsrefExtcmd + "Command" + Cmdsref, true, "slvdn", 8, "", "", "", to_string(cmd->refNum), 0, "");

		// len/maxlenCmdbufInv...
		ref = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "lenCmdbufInv" + MdlsrefExtcmd + Cmdsref, true, "nat", 0, "", "", "", "10", 0, "");

		dbswdbe->tblwdbeamcommandinvpar->loadRstByCmd(cmd->ref, false, ipas);

		first = true;
		found = false;

		ix = 10;
		for (unsigned int k = 0; k < ipas.nodes.size(); k++) {
			ipa = ipas.nodes[k];

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ixCmdbufInv" + MdlsrefExtcmd + Cmdsref + StrMod::cap(ipa->sref), true, "nat", 0, "", "", "", to_string(ix), 0, "");
			ix += Wdbe::getParlen(ipa->ixWdbeVPartype, ipa->Length);

			first = false;
			if (ipa->ixWdbeVPartype == VecWdbeVPartype::VBLOB) {
				found = true;
				break;
			};
		};

		if (!first) {
			if (found) dbswdbe->executeQuery("UPDATE TblWdbeMSignal SET sref = 'maxlenCmdbufInv" + MdlsrefExtcmd + Cmdsref + "', Offval = '" + to_string(ix) + "' WHERE ref = " + to_string(ref));
			else dbswdbe->executeQuery("UPDATE TblWdbeMSignal SET Offval = '" + to_string(ix) + "' WHERE ref = " + to_string(ref));
		};

		if (cmd->ixVRettype != VecWdbeVMCommandRettype::VOID) {
			// len/maxlenCmdbufRet/Newret
			if (cmd->ixVRettype == VecWdbeVMCommandRettype::MULT) s = "Newret";
			else s = "Ret";

			ref = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "lenCmdbuf" + s + MdlsrefExtcmd + Cmdsref, true, "nat", 0, "", "", "", "10", 0, "");

			dbswdbe->tblwdbeamcommandretpar->loadRstByCmd(cmd->ref, false, rpas);

			first = true;
			found = false;

			ix = 9;
			for (unsigned int k = 0; k < rpas.nodes.size(); k++) {
				rpa = rpas.nodes[k];

				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ixCmdbuf" + s + MdlsrefExtcmd + Cmdsref + StrMod::cap(rpa->sref), true, "nat", 0, "", "", "", to_string(ix), 0, "");
				ix += Wdbe::getParlen(rpa->ixWdbeVPartype, rpa->Length);

				first = false;
				if (rpa->ixWdbeVPartype == VecWdbeVPartype::VBLOB) {
					found = true;
					break;
				};
			};

			if (!first) {
				if (found) dbswdbe->executeQuery("UPDATE TblWdbeMSignal SET sref = 'maxlenCmdbuf" + s + MdlsrefExtcmd + Cmdsref + "', Offval = '" + to_string(ix) + "' WHERE ref = " + to_string(ref));
				else dbswdbe->executeQuery("UPDATE TblWdbeMSignal SET Offval = '" + to_string(ix) + "' WHERE ref = " + to_string(ref));
			};
		};

	} else if (err) {
		// no support for ext so far
		refC = dbswdbe->tblwdbecsignal->getNewRef();

		// tixVError...
		dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "tixVError" + StrMod::cap(err->sref), true, "slvdn", 8, "", "", "", to_string(err->refNum), 0, "");

		// len/maxlenCmdbufErr...
		ref = dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "lenCmdbufErr" + StrMod::cap(err->sref), true, "nat", 0, "", "", "", "10", 0, "");

		dbswdbe->tblwdbeamerrorpar->loadRstByErr(err->ref, false, epas);

		first = true;
		found = false;

		ix = 10;
		for (unsigned int k = 0; k < epas.nodes.size(); k++) {
			epa = epas.nodes[k];

			dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, VecWdbeVMSignalRefTbl::MDL, mdl->ref, mdlNum++, VecWdbeVMSignalMgeTbl::PRC, prc->ref, 0, "ixCmdbufErr" + StrMod::cap(err->sref) + StrMod::cap(epa->sref), true, "nat", 0, "", "", "", to_string(ix), 0, "");
			ix += Wdbe::getParlen(epa->ixWdbeVPartype, epa->Length);

			first = false;
			if (epa->ixWdbeVPartype == VecWdbeVPartype::VBLOB) {
				found = true;
				break;
			};
		};

		if (!first) {
			if (found) dbswdbe->executeQuery("UPDATE TblWdbeMSignal SET sref = 'maxlenCmdbufErr" + StrMod::cap(err->sref) + "', Offval = '" + to_string(ix) + "' WHERE ref = " + to_string(ref));
			else dbswdbe->executeQuery("UPDATE TblWdbeMSignal SET Offval = '" + to_string(ix) + "' WHERE ref = " + to_string(ref));
		};
	};
};

ubigint WdbeGenfstCtr::mergeCreateFsts(
			DbsWdbe* dbswdbe
			, const ubigint refFsm
			, const ubigint refC
			, const string& sref
			, ListWdbeMFsmstate& oldfsts
			, ListWdbeMFsmstate& fsts
			, uint& fsmNum
			, const bool createNotSkip
			, bool& maxOneOldFstNoFass
		) {
	ubigint refFst = 0;

	WdbeMFsmstate* fst = NULL;

	uint cnt;

	maxOneOldFstNoFass = true;

	for (unsigned int i = 0; i < oldfsts.nodes.size(); i++) {
		fst = oldfsts.nodes[i];

		if (fst) {
			if (fst->sref.find(sref) == 0) {
				if (refFst == 0) refFst = fst->ref;
				else maxOneOldFstNoFass = false;

				if (refC != 0) fst->refWdbeCFsmstate = refC;
				fst->fsmNum = fsmNum++;

				dbswdbe->tblwdbemfsmstate->updateRec(fst);

				oldfsts.nodes[i] = NULL;
				fsts.nodes.push_back(fst);

			} else if (refFst != 0) break;
		};
	};

	if (createNotSkip && (refFst == 0)) {
		refFst = dbswdbe->tblwdbemfsmstate->insertNewRec(NULL, refC, refFsm, fsmNum++, sref, false, "");

	} else if (maxOneOldFstNoFass && (refFst != 0)) {
		dbswdbe->loadUintBySQL("SELECT COUNT(ref) FROM TblWdbeAMFsmstateStep WHERE fstRefWdbeMFsmstate = " + to_string(refFst), cnt);
		maxOneOldFstNoFass = (cnt == 0);
	};

	return refFst;
};
// IP cust --- IEND
