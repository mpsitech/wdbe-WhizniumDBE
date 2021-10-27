/**
	* \file WdbeWrfpgaCtrFwdctr.cpp
	* Wdbe operation processor - write type-specific VHDL code (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeWrfpgaCtrFwdctr.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeWrfpga;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeWrfpgaCtrFwdctr
 ******************************************************************************/

DpchRetWdbe* WdbeWrfpgaCtrFwdctr::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeWrfpgaCtrFwdctr* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;
	string folder = dpchinv->folder;
	string Prjshort = dpchinv->Prjshort;
	string Untsref = dpchinv->Untsref;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WdbeMModule* mdl = NULL;

	string Compsref;

	fstream outfile;

	string s;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		Compsref = StrMod::cap(Wdbe::getCompsref(dbswdbe, mdl));

		// xxxx/Xxxxx.vhd
		s = xchg->tmppath + "/" + folder + "/" + Compsref + ".vhd.ip";
		outfile.open(s.c_str(), ios::out);
		writeMdlVhd(dbswdbe, outfile, Prjshort, Untsref, mdl);
		outfile.close();

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WdbeWrfpgaCtrFwdctr::writeMdlVhd(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, const string& Prjshort
			, const string& Untsref
			, WdbeMModule* mdl
		) {
	vector<ubigint> refs;

	ListWdbeMModule mdls;
	WdbeMModule* mdl2 = NULL;

	WdbeMController* ctr = NULL;

	string Cmdbussref;
	string Cmdretsref;

	set<pair<string,string> > pairsCmdbus;

	WdbeMProcess* prc = NULL;

	ListWdbeMPort prts;
	map<ubigint,string> srefsPrts; // by ref

	ListWdbeMSignal sigs;
	WdbeMSignal* sig = NULL;

	ListWdbeMCommand cmds;
	WdbeMCommand* cmd = NULL;
	map<string,WdbeMCommand*> srefsCmds; // ex. GetFrame -> cmd

	ListWdbeMError errs;
	WdbeMError* err = NULL;
	map<string,WdbeMError*> srefsErrs; // ex. Invalid -> err

	ListWdbeRMCommandMController crcs;
	WdbeRMCommandMController* crc = NULL;

	ListWdbeMCommand extcmds;
	WdbeMCommand* extcmd = NULL;
	map<string,WdbeMCommand*> srefsExtcmds; // ex. PmmuAlloc -> extcmd
	map<ubigint,string> mdlsrefsExtcmds; // ex. extcmd->ref -> pmmu

	string mdlsref;

	string invs, revs, rets;

	ListWdbeMFsmstate fsts;
	WdbeMFsmstate* fst = NULL;

	ListWdbeAMFsmstateStep fass;
	WdbeAMFsmstateStep* fas = NULL;

	bool hasSigLenCmdbuf;

	string assLenCmdbuf;

	vector<string> ss;
	string s, s2;

	uint cnt;

	if (dbswdbe->tblwdbemcontroller->loadRecByRef(mdl->refWdbeMController, &ctr)) {
		if (dbswdbe->tblwdbemprocess->loadRecBySQL("SELECT * FROM TblWdbeMProcess WHERE refWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'cmd'", &prc)) {
			// --- command and error analysis
			dbswdbe->tblwdbemmodule->loadRstByHktHku(VecWdbeVMModuleHkTbl::UNT, mdl->hkUref, false, mdls);

			for (unsigned int i = 0; i < mdls.nodes.size(); i++) {
				mdl2 = mdls.nodes[i];

				if (mdl2->ixVBasetype == VecWdbeVMModuleBasetype::CMDBUS) Cmdbussref = StrMod::cap(mdl2->sref);
				else if (mdl2->ixVBasetype == VecWdbeVMModuleBasetype::CMDRET) Cmdretsref = StrMod::cap(mdl2->sref);

				if ((Cmdbussref != "") && (Cmdretsref != "")) break;
			};

			Wdbe::getPairsCmdbus(dbswdbe, mdls, pairsCmdbus);

			// load signals
			dbswdbe->tblwdbemport->loadRstByMdl(mdl->ref, false, prts);
			for (unsigned int i = 0; i < prts.nodes.size(); i++) srefsPrts[prts.nodes[i]->ref] = prts.nodes[i]->sref;

			dbswdbe->tblwdbemsignal->loadRstByRetReu(VecWdbeVMSignalRefTbl::MDL, mdl->ref, false, sigs);
			for (unsigned int i = 0; i < sigs.nodes.size(); i++) {
				sig = sigs.nodes[i];

				if (sig->drvRefWdbeMPort != 0) {
					auto it = srefsPrts.find(sig->drvRefWdbeMPort);
					if (it != srefsPrts.end()) if (it->second == sig->sref) sig->sref += "_sig";
				};
			};

			hasSigLenCmdbuf = false;
			for (unsigned int i = 0; i < sigs.nodes.size(); i++) {
				sig = sigs.nodes[i];

				if ((sig->mgeIxVTbl == VecWdbeVMSignalMgeTbl::PRC) && (sig->mgeUref == prc->ref) && (sig->sref == "lenCmdbuf")) {
					hasSigLenCmdbuf = true;
					break;
				};
			};

			dbswdbe->tblwdbemcommand->loadRstByRetReu(VecWdbeVMCommandRefTbl::CTR, ctr->ref, false, cmds);
			for (unsigned int i = 0; i < cmds.nodes.size(); i++) srefsCmds[StrMod::cap(cmds.nodes[i]->sref)] = cmds.nodes[i];

			dbswdbe->tblwdbemerror->loadRstByRetReu(VecWdbeVMErrorRefTbl::CTR, ctr->ref, false, errs);
			for (unsigned int i = 0; i < errs.nodes.size(); i++) srefsErrs[StrMod::cap(errs.nodes[i]->sref)] = errs.nodes[i];

			dbswdbe->tblwdbermcommandmcontroller->loadRstByCtr(ctr->ref, false, crcs);
			refs.resize(crcs.nodes.size());
			for (unsigned int i = 0; i < crcs.nodes.size(); i++) refs[i] = crcs.nodes[i]->refWdbeMCommand;
			dbswdbe->tblwdbemcommand->loadRstByRefs(refs, false, extcmds);

			for (unsigned int i = 0; i < extcmds.nodes.size(); i++) {
				extcmd = extcmds.nodes[i];

				for (unsigned int j = 0; j < mdls.nodes.size(); j++) {
					mdl2 = mdls.nodes[j];

					if (mdl2->refWdbeMController == extcmd->refUref) {
						srefsExtcmds[StrMod::cap(mdl2->sref) + StrMod::cap(extcmd->sref)] = extcmd;
						mdlsrefsExtcmds[extcmd->ref] = mdl2->sref;
						
						break;
					};
				};
			};

			// --- sigs.cmd.typspec
			outfile << "-- IP sigs.cmd.typspec --- IBEGIN" << endl;

			// -- internal command/error summary
			for (unsigned int i = 0; i < cmds.nodes.size(); i++) {
				cmd = cmds.nodes[i];

				if (invs != "") invs += ";";
				invs += cmd->sref;

				if ((cmd->ixVRettype == VecWdbeVMCommandRettype::DFRSNG) || (cmd->ixVRettype == VecWdbeVMCommandRettype::MULT)) {
					if (revs != "") revs += ";";
					revs += cmd->sref;
				};

				if (cmd->ixVRettype != VecWdbeVMCommandRettype::VOID) {
					if (rets != "") rets += ";";
					rets += cmd->sref;
				};
			};

			StrMod::srefsToVector(invs, ss);
			for (unsigned int i = 0; i < ss.size();i++) {
				if (i==0) outfile << "\t-- inv: ";
				else outfile << ", ";
				outfile << ss[i];
			};
			if (invs != "") outfile << endl;

			StrMod::srefsToVector(revs, ss);
			for (unsigned int i = 0; i < ss.size();i++) {
				if (i==0) outfile << "\t-- rev: ";
				else outfile << ", ";
				outfile << ss[i];
			};
			if (revs != "") outfile << endl;

			StrMod::srefsToVector(rets, ss);
			for (unsigned int i = 0; i < ss.size();i++) {
				if (i==0) outfile << "\t-- ret/newret: ";
				else outfile << ", ";
				outfile << ss[i];
			};
			if (rets != "") outfile << endl;

			for (unsigned int i = 0; i < errs.nodes.size(); i++) {
				err = errs.nodes[i];

				if (i==0) outfile << "\t-- err: ";
				else outfile << ", ";
				outfile << err->sref;
			};
			if (errs.nodes.size() > 0) outfile << endl;

			// -- external command summary
			invs.clear();
			revs.clear();
			rets.clear();

			for (unsigned int i = 0; i < crcs.nodes.size(); i++) {
				crc = crcs.nodes[i];
				extcmd = extcmds.nodes[i];

				auto it = mdlsrefsExtcmds.find(extcmd->ref);
				if (it != mdlsrefsExtcmds.end()) mdlsref = it->second;
				else mdlsref = "";

				if (invs != "") invs += ";";
				invs += mdlsref + "." + extcmd->sref;

				if (crc->rvrRefWdbeMSignal != 0) {
					if (revs != "") revs += ";";
					revs += mdlsref + "." + extcmd->sref;
				};

				if (extcmd->ixVRettype != VecWdbeVMCommandRettype::VOID) {
					if (rets != "") rets += ";";
					rets += mdlsref + "." + extcmd->sref;
				};
			};

			StrMod::srefsToVector(invs, ss);
			for (unsigned int i = 0; i < ss.size();i++) {
				if (i==0) outfile << "\t-- external inv: ";
				else outfile << ", ";
				outfile << ss[i];
			};
			if (invs != "") outfile << endl;

			StrMod::srefsToVector(revs, ss);
			for (unsigned int i = 0; i < ss.size();i++) {
				if (i==0) outfile << "\t-- external rev: ";
				else outfile << ", ";
				outfile << ss[i];
			};
			if (revs != "") outfile << endl;

			StrMod::srefsToVector(rets, ss);
			for (unsigned int i = 0; i < ss.size();i++) {
				if (i==0) outfile << "\t-- external ret/newret: ";
				else outfile << ", ";
				outfile << ss[i];
			};
			if (rets != "") outfile << endl;

			outfile << "-- IP sigs.cmd.typspec --- IEND" << endl;

			// --- command FSM
			if (hasSigLenCmdbuf) assLenCmdbuf = " <= ";
			else assLenCmdbuf = " := ";

			dbswdbe->tblwdbemfsmstate->loadRstByFsm(prc->refWdbeMFsm, false, fsts);

			for (unsigned int i = 0; i < fsts.nodes.size(); i++) {
				fst = fsts.nodes[i];

				dbswdbe->tblwdbeamfsmstatestep->loadRstByFst(fst->ref, false, fass);

				if (fass.nodes.size() > 0) {
					if (fst->sref == "empty") {
						// -- impl.cmd.empty.unrdy
						outfile << "-- IP impl.cmd.empty.unrdy --- IBEGIN" << endl;
						for (auto it = pairsCmdbus.begin(); it != pairsCmdbus.end(); it++) if (it->second == mdl->sref)
									outfile << "\t\t\t\t\trdy" << Cmdbussref << "From" << StrMod::cap(it->first) << "_sig <= '0';" << endl;
						outfile << "-- IP impl.cmd.empty.unrdy --- IEND" << endl;

						// -- impl.cmd.empty.rd
						outfile << "-- IP impl.cmd.empty.rd --- IBEGIN" << endl;
						for (auto it = pairsCmdbus.begin(); it != pairsCmdbus.end(); it++) if (it->second == mdl->sref)
									outfile << "\t\t\t\t\trdy" << Cmdbussref << "From" << StrMod::cap(it->first) << "_sig <= '0';" << endl;
						outfile << "-- IP impl.cmd.empty.rd --- IEND" << endl;

					} else if (fst->sref == "recvB") {
						// -- impl.cmd.recvB.initshrte
						outfile << "-- IP impl.cmd.recvB.initshrte --- IBEGIN" << endl;
						outfile << "\t\t\t\t\t\ti := ixCmdbufRoute;" << endl;
						outfile << "\t\t\t\t\t\tj := ixCmdbufRoute+1;" << endl;
						outfile << "-- IP impl.cmd.recvB.initshrte --- IEND" << endl;

						// -- impl.cmd.recvB.copy
						outfile << "-- IP impl.cmd.recvB.copy --- IBEGIN" << endl;
						outfile << "\t\t\t\t\t\tcmdbuf(lenCmdbuf) <= d" << Cmdbussref << ";" << endl;
						outfile << "-- IP impl.cmd.recvB.copy --- IEND" << endl;

					} else if (fst->sref == "recvC") {
						// -- impl.cmd.recvC
						outfile << "-- IP impl.cmd.recvC --- IBEGIN" << endl;
						outfile << "\t\t\t\t\tlenCmdbuf" << assLenCmdbuf << "lenCmdbuf + 1;" << endl;
						outfile << "-- IP impl.cmd.recvC --- IEND" << endl;

					} else if ((fst->sref == "recvD") && (fass.nodes[0]->Ip1 == "last")) {
						// -- impl.cmd.recvD.last
						outfile << "-- IP impl.cmd.recvD.last --- IBEGIN" << endl;
						outfile << "\t\t\t\t\tcmdbuf(ixCmdbufRoute+3) <= (others => '0');" << endl;
						outfile << "-- IP impl.cmd.recvD.last --- IEND" << endl;

						// -- impl.cmd.recvD.load
						outfile << "-- IP impl.cmd.recvD.load --- IBEGIN" << endl;
						outfile << "\t\t\t\t\tif (i=0 and cmdbuf(j)=x\"00\") then" << endl;
						outfile << "\t\t\t\t\t\tx := tixV" << Prjshort << Untsref << "Controller" << Cmdretsref << ";" << endl;
						outfile << "\t\t\t\t\telse" << endl;
						outfile << "\t\t\t\t\t\tx := cmdbuf(j);" << endl;
						outfile << "\t\t\t\t\tend if;" << endl;
						outfile << "-- IP impl.cmd.recvD.load --- IEND" << endl;

					} else if ((fst->sref == "recvE") && (fass.nodes[0]->Ip1 == "store")) {
						// -- impl.cmd.recvE.store
						outfile << "-- IP impl.cmd.recvE.store --- IBEGIN" << endl;
						outfile << "\t\t\t\tcmdbuf(i) <= x;" << endl;
						outfile << endl;
		
						outfile << "\t\t\t\ti := i + 1;" << endl;
						outfile << "\t\t\t\tj := j + 1;" << endl;
						outfile << "-- IP impl.cmd.recvE.store --- IEND" << endl;

					} else if ((fst->sref == "recvD") || (fst->sref == "recvF")) {
						for (unsigned int j = 0; j < fass.nodes.size(); j++) {
							fas = fass.nodes[j];

							// -- impl.cmd.recvD/F.req...
							if ((fas->Ip3.find("req") == 0) || (fas->Ip3.find("ack") == 0)) {
								outfile << "-- IP impl.cmd." << fst->sref << "." << fas->Ip3 << " --- IBEGIN" << endl;
								StrMod::stringToVector(fas->Ip3, ss, ';', true);
								for (unsigned int k = 0; k < ss.size();k++) outfile << "\t\t\t\t\t\t\t" << ss[k] << " <= '1';" << endl;
								outfile << "-- IP impl.cmd." << fst->sref << "." << fas->Ip3 << " --- IEND" << endl;

							} else if ((fas->Ip2.find("req") == 0) || (fas->Ip2.find("ack") == 0)) {
								outfile << "-- IP impl.cmd." << fst->sref << "." << fas->Ip2 << " --- IBEGIN" << endl;
								StrMod::stringToVector(fas->Ip2, ss, ';', true);
								for (unsigned int k = 0; k < ss.size();k++) outfile << "\t\t\t\t\t\t" << ss[k] << " <= '1';" << endl;
								outfile << "-- IP impl.cmd." << fst->sref << "." << fas->Ip2 << " --- IEND" << endl;

							} else if ((fas->Ip1.find("req") == 0) || (fas->Ip1.find("ack") == 0)) {
								outfile << "-- IP impl.cmd." << fst->sref << "." << fas->Ip1 << " --- IBEGIN" << endl;
								StrMod::stringToVector(fas->Ip1, ss, ';', true);
								for (unsigned int k = 0; k < ss.size();k++) outfile << "\t\t\t\t\t" << ss[k] << " <= '1';" << endl;
								outfile << "-- IP impl.cmd." << fst->sref << "." << fas->Ip1 << " --- IEND" << endl;
							};
						};

					} else if (fst->sref == "fullA") {
						for (unsigned int j = 0; j < fass.nodes.size(); j++) {
							fas = fass.nodes[j];

							// -- impl.cmd.fullA.xxx
							if (fas->Ip1 != "") {
								outfile << "-- IP impl.cmd.fullA." << fas->Ip1 << " --- IBEGIN" << endl;
								outfile << "\t\t\t\t\treq" << Cmdbussref << "To" << StrMod::cap(fas->Ip1) << "_sig <= '1';" << endl;
								outfile << "-- IP impl.cmd.fullA." << fas->Ip1 << " --- IEND" << endl;
							};
						};

					} else if (fst->sref == "fullB") {
						// -- impl.cmd.fullB.first
						outfile << "-- IP impl.cmd.fullB.first --- IBEGIN" << endl;
						outfile << "\t\t\t\t\tbytecnt := 0;" << endl;
						outfile << endl;

						outfile << "\t\t\t\t\td" << Cmdbussref << "_sig <= cmdbuf(0);" << endl;
						outfile << "-- IP impl.cmd.fullB.first --- IEND" << endl;

					} else if (fst->sref == "sendA") {
						// -- impl.cmd.sendA
						outfile << "-- IP impl.cmd.sendA --- IBEGIN" << endl;
						outfile << "\t\t\t\t\tbytecnt := bytecnt + 1;" << endl;
						outfile << "-- IP impl.cmd.sendA --- IEND" << endl;

					} else if (fst->sref == "sendB") {
						// -- impl.cmd.sendB.out
						outfile << "-- IP impl.cmd.sendB.out --- IBEGIN" << endl;
						outfile << "\t\t\t\t\t\td" << Cmdbussref << "_sig <= cmdbuf(bytecnt);" << endl;
						outfile << endl;
							
						outfile << "\t\t\t\t\t\tif bytecnt=(lenCmdbuf-1) then" << endl;
						for (auto it = pairsCmdbus.begin(); it != pairsCmdbus.end(); it++) if (it->first == mdl->sref)
									outfile << "\t\t\t\t\t\t\treq" << Cmdbussref << "To" << StrMod::cap(it->second) << "_sig <= '0';" << endl;
						outfile << "\t\t\t\t\t\tend if;" << endl;
						outfile << "-- IP impl.cmd.sendB.out --- IEND" << endl;

					} else if (fst->sref == "sendC") {
						for (unsigned int j = 0; j < fass.nodes.size(); j++) {
							fas = fass.nodes[j];

							// -- impl.cmd.sendC.ack...
							if (fas->Ip2.find("rdy") == 0) {
								outfile << "-- IP impl.cmd.sendC." << fas->Ip2 << " --- IBEGIN" << endl;
								outfile << "\t\t\t\t\t\t" << fas->Ip2 << "_sig <= '1';" << endl;
								outfile << "\t\t\t\t\t\tlenCmdbuf" << assLenCmdbuf << "0;" << endl;
								outfile << "-- IP impl.cmd.sendC." << fas->Ip2 << " --- IEND" << endl;

							} else if (fas->Ip2.find("ack") == 0) {
								outfile << "-- IP impl.cmd.sendC." << fas->Ip2 << " --- IBEGIN" << endl;
								outfile << "\t\t\t\t\t\t" << fas->Ip2 << " <= '1';" << endl;
								outfile << "-- IP impl.cmd.sendC." << fas->Ip2 << " --- IEND" << endl;
							};
						};

					} else if ((fst->sref.find("prepRet") == 0) || (fst->sref.find("prepNewret") == 0)) {
						// insertion point is of the form impl.cmd.prep{Ret/Newret}GetFrame.xyz in case the cref is known
						fas = fass.nodes[0];

						if (fst->sref.find("prepRet") == 0) s = fst->sref.substr(7);
						else s = fst->sref.substr(10);

						auto it = srefsCmds.find(s);
						if (it != srefsCmds.end()) {
							cmd = it->second;

							if (cmd->ixVRettype == VecWdbeVMCommandRettype::MULT) s2 = "Newret";
							else s2 = "Ret";

							// -- impl.cmd.prepRet/Newret...
							outfile << "-- IP impl.cmd." << fst->sref;
							if (fas->Ip1 != fst->sref) outfile << "." << fas->Ip1;
							outfile << " --- IBEGIN" << endl;

							outfile << "\t\t\t\tcmdbuf(ixCmdbufAction) <= tixDbeVAction" << s2 << ";" << endl;
							outfile << endl;

							if (fas->Ip1 != fst->sref) {
								outfile << "\t\t\t\tcmdbuf(ixCmdbufCref) <= cref" << StrMod::cap(fas->Ip1) << "(31 downto 24);" << endl;
								outfile << "\t\t\t\tcmdbuf(ixCmdbufCref+1) <= cref" << StrMod::cap(fas->Ip1) << "(23 downto 16);" << endl;
								outfile << "\t\t\t\tcmdbuf(ixCmdbufCref+2) <= cref" << StrMod::cap(fas->Ip1) << "(15 downto 8);" << endl;
								outfile << "\t\t\t\tcmdbuf(ixCmdbufCref+3) <= cref" << StrMod::cap(fas->Ip1) << "(7 downto 0);" << endl;
								outfile << endl;
							};

							dbswdbe->loadUintBySQL("SELECT COUNT(ref) FROM TblWdbeAMCommandRetpar WHERE cmdRefWdbeMCommand = " + to_string(cmd->ref), cnt);

							if (cnt > 0) {
								// -- impl.cmd.prepRet/Newret...
								outfile << "\t\t\t\t-- IP impl.cmd." << fst->sref << " --- INSERT" << endl;
								outfile << endl;
							};

							outfile << "\t\t\t\tlenCmdbuf" << assLenCmdbuf << "lenCmdbuf" << s2 << StrMod::cap(cmd->sref) << ";" << endl;

							outfile << "-- IP impl.cmd." << fst->sref;
							if (fas->Ip1 != fst->sref) outfile << "." << fas->Ip1;
							outfile << " --- IEND" << endl;
						};

					} else if ((fst->sref.find("prepCreferr") == 0)  && (fst->sref != "prepCreferr")) {
						s = fst->sref.substr(11);

						// -- impl.cmd.prepCreferr...
						outfile << "-- IP impl.cmd." << fst->sref << " --- IBEGIN" << endl;
						outfile << "\t\t\t\tcmdbuf(ixCmdbufCreferrCref) <= cref" << s << "(31 downto 24);" << endl;
						outfile << "\t\t\t\tcmdbuf(ixCmdbufCreferrCref+1) <= cref" << s << "(23 downto 16);" << endl;
						outfile << "\t\t\t\tcmdbuf(ixCmdbufCreferrCref+2) <= cref" << s << "(15 downto 8);" << endl;
						outfile << "\t\t\t\tcmdbuf(ixCmdbufCreferrCref+3) <= cref" << s << "(7 downto 0);" << endl;
						outfile << "-- IP impl.cmd." << fst->sref << " --- IEND" << endl;

					} else if (fst->sref == "prepCreferr") {
						// -- impl.cmd.prepCreferr
						outfile << "-- IP impl.cmd.prepCreferr --- IBEGIN" << endl;
						outfile << "\t\t\t\tcmdbuf(ixCmdbufAction) <= tixDbeVActionCreferr;" << endl;
						outfile << endl;
		
						outfile << "\t\t\t\tlenCmdbuf" << assLenCmdbuf << "lenCmdbufCreferr;" << endl;
						outfile << "-- IP impl.cmd.prepCreferr --- IEND" << endl;

					} else if (fst->sref.find("prepErr") == 0) {
						// possible fst's: prepErrInvalid, prepErrInvalidRead
						// possible fas's: prepErrInvalid, prepErrInvalid.read, prepErrInvalidRead
						fas = fass.nodes[0];

						s = fst->sref.substr(7);

						err = NULL;
						for (auto it = srefsErrs.begin(); it != srefsErrs.end(); it++) {
							if (s.find(StrMod::cap(it->first)) == 0) {
								err = it->second;
								break;
							};
						};

						if (err) {
							s2 = s.substr(err->sref.length());
							if (s2.find('.') == 0) s2 = s2.substr(1);
							StrMod::cap(s2);

							// -- impl.cmd.prepErr...
							outfile << "-- IP impl.cmd." << fst->sref;
							if (fas->Ip1 != fst->sref) outfile << "." << fas->Ip1;
							outfile << " --- IBEGIN" << endl;

							dbswdbe->loadUintBySQL("SELECT COUNT(ref) FROM TblWdbeAMErrorPar WHERE errRefWdbeMError = " + to_string(err->ref), cnt);

							if (s2 != "") outfile << "\t\t\t\tcmdbuf(ixCmdbufRoute) <= route" << s2 << ";" << endl;
							if ((s2 == "") || (fas->Ip1 != fst->sref)) outfile << "\t\t\t\tcmdbuf(ixCmdbufAction) <= tixDbeVActionErr;" << endl;
							if (s2 != "") {
								outfile << "\t\t\t\tcmdbuf(ixCmdbufCref) <= cref" << s2 << "(31 downto 24);" << endl;
								outfile << "\t\t\t\tcmdbuf(ixCmdbufCref+1) <= cref" << s2 << "(23 downto 16);" << endl;
								outfile << "\t\t\t\tcmdbuf(ixCmdbufCref+2) <= cref" << s2 << "(15 downto 8);" << endl;
								outfile << "\t\t\t\tcmdbuf(ixCmdbufCref+3) <= cref" << s2 << "(7 downto 0);" << endl;
							};
							if ((s2 == "") || (fas->Ip1 != fst->sref)) outfile << "\t\t\t\tcmdbuf(ixCmdbufErrError) <= tixVError" << StrMod::cap(err->sref) << ";" << endl;
							if (cnt > 0) {
								outfile << endl;
								outfile << "\t\t\t\t-- IP impl.cmd." << fst->sref << " --- INSERT" << endl;
							};
							if ((s2 == "") || (fas->Ip1 != fst->sref)) {
								outfile << endl;
								outfile << "\t\t\t\tlenCmdbuf" << assLenCmdbuf << "lenCmdbufErr" << StrMod::cap(err->sref) << ";" << endl;
							};

							outfile << "-- IP impl.cmd." << fst->sref;
							if (fas->Ip1 != fst->sref) outfile << "." << fas->Ip1;
							outfile << " --- IEND" << endl;
						};

					} else if (fst->sref.find("prepInv") == 0) {
						s = fst->sref.substr(7);

						auto it = srefsExtcmds.find(s);
						if (it != srefsExtcmds.end()) {
							extcmd = it->second;
							mdlsref = StrMod::cap(mdlsrefsExtcmds[extcmd->ref]);

							// -- impl.cmd.prepInv...
							outfile << "-- IP impl.cmd." << fst->sref << " --- IBEGIN" << endl;
							outfile << "\t\t\t\tcmdbuf(ixCmdbufRoute) <= tixV" << Prjshort << Untsref << "Controller" << mdlsref << ";" << endl;
							outfile << "\t\t\t\tcmdbuf(ixCmdbufRoute+1) <= tixV" << Prjshort << Untsref << "Controller" << mdlsref << ";" << endl;
							outfile << "\t\t\t\tcmdbuf(ixCmdbufAction) <= tixDbeVActionInv;" << endl;
							outfile << "\t\t\t\tcmdbuf(ixCmdbufCref) <= tixV" << Untsref << mdlsref << "Command" << StrMod::cap(extcmd->sref) << ";" << endl;
							outfile << "\t\t\t\tcmdbuf(ixCmdbufInvCommand) <= tixV" << Untsref << mdlsref << "Command" << StrMod::cap(extcmd->sref) << ";" << endl;
							outfile << endl;

							dbswdbe->loadUintBySQL("SELECT COUNT(ref) FROM TblWdbeAMCommandInvpar WHERE cmdRefWdbeMCommand = " + to_string(extcmd->ref), cnt);

							if (cnt > 0) {
								// -- impl.cmd.prepInv...
								outfile << "\t\t\t\t-- IP impl.cmd." << fst->sref << " --- INSERT" << endl;
								outfile << endl;
							};

							outfile << "\t\t\t\tlenCmdbuf" << assLenCmdbuf << "lenCmdbufInv" << s << ";" << endl;
							outfile << "-- IP impl.cmd." << fst->sref << " --- IEND" << endl;
						};

					} else if (fst->sref.find("prepRev") == 0) {
						s = fst->sref.substr(7);

						auto it = srefsExtcmds.find(s);
						if (it != srefsExtcmds.end()) {
							extcmd = it->second;
							mdlsref = StrMod::cap(mdlsrefsExtcmds[extcmd->ref]);

							outfile << "-- IP impl.cmd." << fst->sref << " --- IBEGIN" << endl;
							outfile << "\t\t\t\tcmdbuf(ixCmdbufRoute) <= tixV" << Prjshort << Untsref << "Controller" << mdlsref << ";" << endl;
							outfile << "\t\t\t\tcmdbuf(ixCmdbufRoute+1) <= tixV" << Prjshort << Untsref << "Controller" << mdlsref << ";" << endl;
							outfile << "\t\t\t\tcmdbuf(ixCmdbufAction) <= tixDbeVActionRev;" << endl;
							outfile << "\t\t\t\tcmdbuf(ixCmdbufCref) <= tixV" << Untsref << mdlsref << "Command" << StrMod::cap(extcmd->sref) << ";" << endl;
							outfile << "\t\t\t\tcmdbuf(ixCmdbufInvCommand) <= tixV" << Untsref << mdlsref << "Command" << StrMod::cap(extcmd->sref) << ";" << endl;
							outfile << endl;

							outfile << "\t\t\t\tlenCmdbuf" << assLenCmdbuf << "lenCmdbufRev;" << endl;
							outfile << "-- IP impl.cmd." << fst->sref << " --- IEND" << endl;
						};
					};
				};
			};

			// --- impl.cmd.falling*
			outfile << "\t-- IP impl.cmd.falling --- RBEGIN" << endl;
			outfile << "\t-- IP impl.cmd.falling --- BEGIN" << endl;

			outfile << "\tprocess (mclk)" << endl;
			outfile << "\t\t-- IP impl.cmd.falling.vars --- INSERT" << endl;
			outfile << "\tbegin" << endl;
			outfile << "\t\tif falling_edge(mclk) then" << endl;
			outfile << "\t\tend if;" << endl;
			outfile << "\tend process;" << endl;
			outfile << endl;

// !!!
			outfile << "\tprocess (clk" << Cmdbussref << ")" << endl;
			outfile << "\tbegin" << endl;
			outfile << "\t\tif falling_edge(clk" << Cmdbussref << ") then" << endl;

			for (unsigned int i = 0; i < sigs.nodes.size(); i++) {
				sig = sigs.nodes[i];

/*
				if ((sig->mgeIxVTbl == VecWdbeVMSignalMgeTbl::PRC) && (sig->mgeUref == prc->ref) && sig->Sync)
							if ((sig->sref.find("d" + Cmdbussref) == 0) || (sig->sref.find("req" + Cmdbussref) == 0) || (sig->sref.find("rdy" + Cmdbussref) == 0))
										outfile << "\t\t\t" << sig->sref << " <= " << sig->sref << "_next;" << endl;
*/
			};

			outfile << "\t\tend if;" << endl;
			outfile << "\tend process;" << endl;
			outfile << "\t-- IP impl.cmd.falling --- END" << endl;
			outfile << "\t-- IP impl.cmd.falling --- REND" << endl;


			delete prc;
		};

		delete ctr;
	};
};
// IP cust --- IEND
