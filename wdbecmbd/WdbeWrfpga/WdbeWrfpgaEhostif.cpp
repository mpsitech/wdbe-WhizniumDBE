/**
	* \file WdbeWrfpgaEhostif.cpp
	* Wdbe operation processor - write template-specific VHDL code (implementation)
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

#include "WdbeWrfpgaEhostif.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeWrfpga;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeWrfpgaEhostif
 ******************************************************************************/

DpchRetWdbe* WdbeWrfpgaEhostif::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeWrfpgaEhostif* dpchinv
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

		// xxxx/Hostif.vhd
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
void WdbeWrfpgaEhostif::writeMdlVhd(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, const string& Prjshort
			, const string& Untsref
			, WdbeMModule* mdl
		) {
	vector<ubigint> refs;

	ListWdbeMModule untmdls;
	WdbeMModule* untmdl = NULL;

	string sref, srefrootMgmt, srefrootCor;

	vector<string> srefsImbRd, srefrootsImbRd;
	vector<string> srefsImbWr, srefrootsImbWr;

	ListWdbeMCommand cmds;
	WdbeMCommand* cmd = NULL;

	ListWdbeAMCommandInvpar ipas;
	WdbeAMCommandInvpar* ipa = NULL;

	ListWdbeAMCommandRetpar rpas;
	WdbeAMCommandRetpar* rpa = NULL;

	ListWdbeMSignal sigs;
	WdbeMSignal* sig = NULL;

	ubigint refPrcOp;

	bool w32Not8;

	uint cnt;

	unsigned int ix;

	unsigned int parlen;

	string s;

	bool first, first2;

	Wdbe::getMpa(dbswdbe, mdl->ref, "w32Not8", s); w32Not8 = (s == "true");

	dbswdbe->tblwdbemmodule->loadRstByHktHku(mdl->hkIxVTbl, mdl->hkUref, false, untmdls);

	dbswdbe->loadRefsBySQL("SELECT TblWdbeMImbuf.refWdbeMModule FROM TblWdbeMImbuf, TblWdbeMModule, TblWdbeRMModuleMModule WHERE TblWdbeMImbuf.refWdbeMModule = TblWdbeMModule.ref AND TblWdbeMModule.ref = TblWdbeRMModuleMModule.ctdRefWdbeMModule AND TblWdbeRMModuleMModule.corRefWdbeMModule = "
				+ to_string(mdl->ref) + " ORDER BY TblWdbeMImbuf.Prio ASC, TblWdbeMModule.sref ASC", false, refs);

	for (unsigned int i = 0; i < refs.size(); i++) {
		if (!Wdbe::getImbsrefs(dbswdbe, refs[i], sref, srefrootMgmt, srefrootCor)) {
			srefsImbRd.push_back(StrMod::cap(sref));
			srefrootsImbRd.push_back(srefrootCor);
		} else {
			srefsImbWr.push_back(StrMod::cap(sref));
			srefrootsImbWr.push_back(srefrootCor);
		};
	};

	dbswdbe->tblwdbemsignal->loadRstByRetReu(VecWdbeVMSignalRefTbl::MDL, mdl->ref, false, sigs);

	dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMProcess WHERE refWdbeMModule = " + to_string(mdl->ref) + " AND sref = 'op'", refPrcOp);

	// --- impl.op.wiring.voidinv
	outfile << "-- IP impl.op.wiring.voidinv --- IBEGIN" << endl;

	// no invocation parameters, return type immsng

	for (unsigned int i = 0; i < untmdls.nodes.size(); i++) {
		untmdl = untmdls.nodes[i];

		if (untmdl->ixVBasetype == VecWdbeVMModuleBasetype::ECTR) {
			dbswdbe->tblwdbemcommand->loadRstByRetReu(VecWdbeVMCommandRefTbl::CTR, untmdl->refWdbeMController, false, cmds);
 
			for (unsigned int j = 0; j < cmds.nodes.size(); j++) {
				cmd = cmds.nodes[j];

				if (cmd->ixVRettype == VecWdbeVMCommandRettype::IMMSNG) {
					dbswdbe->loadUintBySQL("SELECT COUNT(ref) FROM TblWdbeAMCommandInvpar WHERE cmdRefWdbeMCommand = " + to_string(cmd->ref), cnt);

					if (cnt == 0) {
						outfile << "\treqInv" << StrMod::cap(untmdl->sref) << StrMod::cap(cmd->sref) << " <= '1' when (stateOp=stateOpVoidinv and opbuf(ixOpbufController)=tixV" << Untsref << "Controller"
									<< StrMod::cap(untmdl->sref) << " and opbuf(ixOpbufCommand)=tixV" << StrMod::cap(untmdl->sref) << "Command" << StrMod::cap(cmd->sref) << ") else '0';" << endl;
					};
				};
			};
		};
	};
	outfile << endl;

	first = true;
	outfile << "\tackVoidinv <=";

	for (unsigned int i = 0; i < untmdls.nodes.size(); i++) {
		untmdl = untmdls.nodes[i];

		if (untmdl->ixVBasetype == VecWdbeVMModuleBasetype::ECTR) {
			dbswdbe->tblwdbemcommand->loadRstByRetReu(VecWdbeVMCommandRefTbl::CTR, untmdl->refWdbeMController, false, cmds);
 
			for (unsigned int j = 0; j < cmds.nodes.size(); j++) {
				cmd = cmds.nodes[j];

				if (cmd->ixVRettype == VecWdbeVMCommandRettype::IMMSNG) {
					dbswdbe->loadUintBySQL("SELECT COUNT(ref) FROM TblWdbeAMCommandInvpar WHERE cmdRefWdbeMCommand = " + to_string(cmd->ref), cnt);

					if (cnt == 0) {
						if (first) first = false;
						else outfile << "\t\t\t\telse";

						outfile << " ackInv" << StrMod::cap(untmdl->sref) << StrMod::cap(cmd->sref) << " when (opbuf(ixOpbufController)=tixV" << Untsref << "Controller" << StrMod::cap(untmdl->sref)
									<< " and opbuf(ixOpbufCommand)=tixV" << StrMod::cap(untmdl->sref) << "Command" << StrMod::cap(cmd->sref) << ")" << endl;
					};
				};
			};
		};
	};

	if (!first) outfile << "\t\t\t\telse";
	outfile << " '0';" << endl;

	outfile << "-- IP impl.op.wiring.voidinv --- IEND" << endl;

	// --- impl.op.wiring.inv
	outfile << "-- IP impl.op.wiring.inv --- IBEGIN" << endl;

	// at least one invocation parameter, return type void

	for (unsigned int i = 0; i < untmdls.nodes.size(); i++) {
		untmdl = untmdls.nodes[i];

		if (untmdl->ixVBasetype == VecWdbeVMModuleBasetype::ECTR) {
			dbswdbe->tblwdbemcommand->loadRstByRetReu(VecWdbeVMCommandRefTbl::CTR, untmdl->refWdbeMController, false, cmds);
 
			for (unsigned int j = 0; j < cmds.nodes.size(); j++) {
				cmd = cmds.nodes[j];

				dbswdbe->loadUintBySQL("SELECT COUNT(ref) FROM TblWdbeAMCommandRetpar WHERE cmdRefWdbeMCommand = " + to_string(cmd->ref), cnt);

				if (cnt == 0) {
					outfile << "\treqInv" << StrMod::cap(untmdl->sref) << StrMod::cap(cmd->sref) << " <= '1' when (stateOp=stateOpCopyRxB and opbuf(ixOpbufController)=tixV" << Untsref << "Controller"
								<< StrMod::cap(untmdl->sref) << " and opbuf(ixOpbufCommand)=tixV" << StrMod::cap(untmdl->sref) << "Command" << StrMod::cap(cmd->sref) << ") else '0';" << endl;
				};
			};
		};
	};
	outfile << endl;

	first = true;
	outfile << "\tackInv <=";

	for (unsigned int i = 0; i < untmdls.nodes.size(); i++) {
		untmdl = untmdls.nodes[i];

		if (untmdl->ixVBasetype == VecWdbeVMModuleBasetype::ECTR) {
			dbswdbe->tblwdbemcommand->loadRstByRetReu(VecWdbeVMCommandRefTbl::CTR, untmdl->refWdbeMController, false, cmds);
 
			for (unsigned int j = 0; j < cmds.nodes.size(); j++) {
				cmd = cmds.nodes[j];

				dbswdbe->loadUintBySQL("SELECT COUNT(ref) FROM TblWdbeAMCommandRetpar WHERE cmdRefWdbeMCommand = " + to_string(cmd->ref), cnt);

				if (cnt == 0) {
					if (first) first = false;
					else outfile << "\t\t\t\telse";

					outfile << " ackInv" << StrMod::cap(untmdl->sref) << StrMod::cap(cmd->sref) << " when (opbuf(ixOpbufController)=tixV" << Untsref << "Controller" << StrMod::cap(untmdl->sref)
								<< " and opbuf(ixOpbufCommand)=tixV" << StrMod::cap(untmdl->sref) << "Command" << StrMod::cap(cmd->sref) << ")" << endl;
				};
			};
		};
	};

	if (!first) outfile << "\t\t\t\telse";
	outfile << " '0';" << endl;

	outfile << "-- IP impl.op.wiring.inv --- IEND" << endl;

	// --- impl.op.wiring.txbuf
	outfile << "-- IP impl.op.wiring.txbuf --- IBEGIN" << endl;

	for (unsigned int i = 0; i < srefsImbRd.size(); i++)
				outfile << "\treq" << srefrootsImbRd[i] << " <= reqTxbuf when opbuf(ixOpbufBuffer)=tixW" << Untsref << "Buffer" << srefsImbRd[i] << " else '0';" << endl;
	outfile << endl;

	outfile << "\tackTxbuf <=";

	for (unsigned int i = 0; i < srefsImbRd.size(); i++) {
		if (i != 0) outfile << "\t\t\t\telse";
			
		outfile << " ack" << srefrootsImbRd[i] << " when opbuf(ixOpbufBuffer)=tixW" << Untsref << "Buffer" << srefsImbRd[i] << endl;
	};

	if (srefsImbRd.size() > 0) outfile << "\t\t\t\telse";
	outfile << " '0';" << endl;
	outfile << endl;

	for (unsigned int i = 0; i < srefsImbRd.size(); i++)
				outfile << "\tdne" << srefrootsImbRd[i] << " <= dneTxbuf when opbuf(ixOpbufBuffer)=tixW" << Untsref << "Buffer" << srefsImbRd[i] << " else '0';" << endl;
	outfile << endl;

	outfile << "\tavllenTxbuf <=";

	for (unsigned int i = 0; i < srefsImbRd.size(); i++) {
		if (i != 0) outfile << "\t\t\t\telse";
		
		outfile << " to_integer(unsigned(avllen" << srefrootsImbRd[i] << ")) when opbuf(ixOpbufBuffer)=tixW" << Untsref << "Buffer" << srefsImbRd[i] << endl;
	};

	if (srefsImbRd.size() > 0) outfile << "\t\t\t\telse";
	outfile << " 0;" << endl;
	outfile << endl;

	outfile << "\tdTxbuf <=";

	for (unsigned int i = 0; i < srefsImbRd.size(); i++) {
		if (i != 0) outfile << "\t\t\t\telse";
			
		if (!w32Not8) outfile << " d" << srefrootsImbRd[i] << " when opbuf(ixOpbufBuffer)=tixW" << Untsref << "Buffer" << srefsImbRd[i] << endl;
		else outfile << " d" << srefrootsImbRd[i] << "(7 downto 0) & d" << srefrootsImbRd[i] << "(15 downto 8) & d" << srefrootsImbRd[i] << "(23 downto 16) & d" << srefrootsImbRd[i] << "(31 downto 24) when opbuf(ixOpbufBuffer)=tixW" << Untsref << "Buffer" << srefsImbRd[i] << endl;
	};

	if (srefsImbRd.size() > 0)  outfile << "\t\t\t\telse";
	outfile << " (others => '0');" << endl;
	outfile << endl;

	for (unsigned int i = 0; i < srefsImbRd.size(); i++)
				outfile << "\tstrbD" << srefrootsImbRd[i] << " <= strbDTxbuf when opbuf(ixOpbufBuffer)=tixW" << Untsref << "Buffer" << srefsImbRd[i] << " else '0';" << endl;
	outfile << "-- IP impl.op.wiring.txbuf --- IEND" << endl;

	// --- impl.op.wiring.rxbuf
	outfile << "-- IP impl.op.wiring.rxbuf --- IBEGIN" << endl;

	for (unsigned int i = 0; i < srefsImbWr.size(); i++)
				outfile << "\treq" << srefrootsImbWr[i] << " <= reqRxbuf when opbuf(ixOpbufBuffer)=tixW" << Untsref << "Buffer" << srefsImbWr[i] << " else '0';" << endl;
	outfile << endl;

	outfile << "\tackRxbuf <=";
	for (unsigned int i = 0; i < srefsImbWr.size(); i++) {
		if (i != 0) outfile << "\t\t\t\telse";
		
		outfile << " ack" << srefrootsImbWr[i] << " when opbuf(ixOpbufBuffer)=tixW" << Untsref << "Buffer" << srefsImbWr[i] << endl;
	};

	if (srefsImbWr.size() > 0) outfile << "\t\t\t\telse";
	outfile << " '0';" << endl;
	outfile << endl;

	for (unsigned int i = 0; i < srefsImbWr.size(); i++)
				outfile << "\tdne" << srefrootsImbWr[i] << " <= dneRxbuf when opbuf(ixOpbufBuffer)=tixW" << Untsref << "Buffer" << srefsImbWr[i] << " else '0';" << endl;
	outfile << endl;

	outfile << "\tavllenRxbuf <=";
	for (unsigned int i = 0; i < srefsImbWr.size(); i++) {
		if (i != 0) outfile << "\t\t\t\telse";

		outfile << " to_integer(unsigned(avllen" << srefrootsImbWr[i] << ")) when opbuf(ixOpbufBuffer)=tixW" << Untsref << "Buffer" << srefsImbWr[i] << endl;
	};

	if (srefsImbWr.size() > 0) outfile << "\t\t\t\telse";
	outfile << " 0;" << endl;
	outfile << endl;

	for (unsigned int i = 0; i < srefsImbWr.size(); i++) {
		if (!w32Not8) outfile << "\td" << srefrootsImbWr[i] << " <= dRxbuf;" << endl;
		else outfile << "\td" << srefrootsImbWr[i] << " <= dRxbuf(7 downto 0) & dRxbuf(15 downto 8) & dRxbuf(23 downto 16) & dRxbuf(31 downto 24);" << endl;
	};
	outfile << endl;

	for (unsigned int i = 0; i < srefsImbWr.size(); i++)
				outfile << "\tstrbD" << srefrootsImbWr[i] << " <= strbDRxbuf when opbuf(ixOpbufBuffer)=tixW" << Untsref << "Buffer" << srefsImbWr[i] << " else '0';" << endl;

	outfile << "-- IP impl.op.wiring.rxbuf --- IEND" << endl;

	// --- impl.op.reset
	outfile << "-- IP impl.op.reset --- IBEGIN" << endl;
	for (unsigned int i = 0; i < sigs.nodes.size(); i++) {
		sig = sigs.nodes[i];

		if ((sig->ixVBasetype == VecWdbeVMSignalBasetype::OPRT) && (sig->mgeIxVTbl == VecWdbeVMSignalMgeTbl::PRC) && (sig->mgeUref == refPrcOp)) {
			outfile << "\t\t\t" << sig->sref << "_sig <= " << getValStr(sig, true) << ";" << endl;
		};
	};
	outfile << "-- IP impl.op.reset --- IEND" << endl;

	// --- impl.op.rxopE.cmdret
	outfile << "-- IP impl.op.rxopE.cmdret --- IBEGIN" << endl;

	// no invocation parameters, return type immsng

	first = true;

	outfile << "\t\t\t\t\tif ( ";

	for (unsigned int i = 0; i < untmdls.nodes.size(); i++) {
		untmdl = untmdls.nodes[i];

		if (untmdl->ixVBasetype == VecWdbeVMModuleBasetype::ECTR) {
			first2 = true;

			dbswdbe->tblwdbemcommand->loadRstByRetReu(VecWdbeVMCommandRefTbl::CTR, untmdl->refWdbeMController, false, cmds);

			for (unsigned int j = 0; j < cmds.nodes.size(); j++) {
				cmd = cmds.nodes[j];

				if (cmd->ixVRettype == VecWdbeVMCommandRettype::IMMSNG) {
					dbswdbe->loadUintBySQL("SELECT COUNT(ref) FROM TblWdbeAMCommandInvpar WHERE cmdRefWdbeMCommand = " + to_string(cmd->ref), cnt);

					if (cnt == 0) {
						if (first2) {
							if (first) first = false;
							else {
								outfile << endl;
								outfile << "\t\t\t\t\t\t\t\tor ";
							};

							outfile << "(opbuf(ixOpbufController)=tixV" << Untsref << "Controller" << StrMod::cap(untmdl->sref) << " and (";

							first2 = false;
						} else outfile << " or ";
						
						outfile << "opbuf(ixOpbufCommand)=tixV" << StrMod::cap(untmdl->sref) << "Command" << StrMod::cap(cmd->sref);
					};
				};
			};

			if (!first2) outfile << "))";
		};
	};

	if (first) outfile << "0=1";
	outfile << " ) then" << endl;

	outfile << endl;
	outfile << "\t\t\t\t\t\tstateOp <= stateOpVoidinv;" << endl;

	// no invocation parameters, return type statsng

	first = true;

	outfile << endl;
	outfile << "\t\t\t\t\telsif ( ";

	for (unsigned int i = 0; i < untmdls.nodes.size(); i++) {
		untmdl = untmdls.nodes[i];

		if (untmdl->ixVBasetype == VecWdbeVMModuleBasetype::ECTR) {
			first2 = true;

			dbswdbe->tblwdbemcommand->loadRstByRetReu(VecWdbeVMCommandRefTbl::CTR, untmdl->refWdbeMController, false, cmds);

			for (unsigned int j = 0; j < cmds.nodes.size(); j++) {
				cmd = cmds.nodes[j];

				if (cmd->ixVRettype == VecWdbeVMCommandRettype::STATSNG) {
					dbswdbe->loadUintBySQL("SELECT COUNT(ref) FROM TblWdbeAMCommandInvpar WHERE cmdRefWdbeMCommand = " + to_string(cmd->ref), cnt);

					if (cnt == 0) {
						if (first2) {
							if (first) first = false;
							else {
								outfile << endl;
								outfile << "\t\t\t\t\t\t\t\tor ";
							};

							outfile << "(opbuf(ixOpbufController)=tixV" << Untsref << "Controller" << StrMod::cap(untmdl->sref) << " and (";

							first2 = false;
						} else outfile << " or ";
						
						outfile << "opbuf(ixOpbufCommand)=tixV" << StrMod::cap(untmdl->sref) << "Command" << StrMod::cap(cmd->sref);
					};
				};
			};

			if (!first2) outfile << "))";
		};
	};

	if (first) outfile << "0=1";
	outfile << " ) then" << endl;

	outfile << "-- IP impl.op.rxopE.cmdret --- IEND" << endl;

	// --- impl.op.rxopE.cmdinv
	outfile << "-- IP impl.op.rxopE.cmdinv --- IBEGIN" << endl;

	// return type void

	first = true;

	outfile << "\t\t\t\t\tif ( ";

	for (unsigned int i = 0; i < untmdls.nodes.size(); i++) {
		untmdl = untmdls.nodes[i];

		if (untmdl->ixVBasetype == VecWdbeVMModuleBasetype::ECTR) {
			first2 = true;

			dbswdbe->tblwdbemcommand->loadRstByRetReu(VecWdbeVMCommandRefTbl::CTR, untmdl->refWdbeMController, false, cmds);

			for (unsigned int j = 0; j < cmds.nodes.size(); j++) {
				cmd = cmds.nodes[j];

				if (cmd->ixVRettype == VecWdbeVMCommandRettype::VOID) {
					if (first2) {
						if (first) first = false;
						else {
							outfile << endl;
							outfile << "\t\t\t\t\t\t\t\tor ";
						};

						outfile << "(opbuf(ixOpbufController)=tixV" << Untsref << "Controller" << StrMod::cap(untmdl->sref) << " and (";

						first2 = false;
					} else outfile << " or ";
					
					outfile << "opbuf(ixOpbufCommand)=tixV" << StrMod::cap(untmdl->sref) << "Command" << StrMod::cap(cmd->sref);
				};
			};

			if (!first2) outfile << "))";
		};
	};

	if (first) outfile << "0=1";
	outfile << " ) then" << endl;
	outfile << "-- IP impl.op.rxopE.cmdinv --- IEND" << endl;

	// --- impl.op.prepTxA
	outfile << "-- IP impl.op.prepTxA --- IBEGIN" << endl;
	
	first = true; // controller

	for (unsigned int i = 0; i < untmdls.nodes.size(); i++) {
		untmdl = untmdls.nodes[i];

		if (untmdl->ixVBasetype == VecWdbeVMModuleBasetype::ECTR) {
			dbswdbe->tblwdbemcommand->loadRstByRetReu(VecWdbeVMCommandRefTbl::CTR, untmdl->refWdbeMController, false, cmds);
 
 			first2 = true; // command

			for (unsigned int j = 0; j < cmds.nodes.size(); j++) {
				cmd = cmds.nodes[j];

				dbswdbe->tblwdbeamcommandretpar->loadRstByCmd(cmd->ref, false, rpas);

				if (rpas.nodes.size() > 0) {
					if (first2) {
						outfile << "\t\t\t\t";
						if (first) first = false;
						else outfile << "els";
						
						outfile << "if opbuf(ixOpbufController)=tixV" << Untsref << "Controller" << StrMod::cap(untmdl->sref) << " then" << endl;
					};

					outfile << "\t\t\t\t\t";
					if (first2) first2 = false;
					else outfile << "els";
					
					outfile << "if opbuf(ixOpbufCommand)=tixV" << StrMod::cap(untmdl->sref) << "Command" << StrMod::cap(cmd->sref) << " then" << endl;

					ix = 0;
					for (unsigned int k = 0; k < rpas.nodes.size(); k++) {
						rpa = rpas.nodes[k];
						
						parlen = Wdbe::getParlen(rpa->ixWdbeVPartype, rpa->Length);

						if (rpa->ixWdbeVPartype == VecWdbeVPartype::VBLOB) {
							outfile << "\t\t\t\t\t\ttxbuf(" << ix << ") <= " << untmdl->sref << StrMod::cap(cmd->sref) << "Len" << StrMod::cap(rpa->sref) << ";" << endl;

							ix++;
							parlen--;
						};

						if (parlen == 1) {
							outfile << "\t\t\t\t\t\ttxbuf(" << ix << ") <= " << untmdl->sref << StrMod::cap(cmd->sref) << StrMod::cap(rpa->sref) << ";" << endl;
							ix++;

						} else {
							outfile << "\t\t\t\t\t\tfor i in 0 to " << (parlen-1) << " loop" << endl;

							outfile << "\t\t\t\t\t\t\ttxbuf(";
							if (ix > 0) outfile << ix << "+";
							outfile << "i) <= " << untmdl->sref << StrMod::cap(cmd->sref) << StrMod::cap(rpa->sref) << "((" << parlen << "-i)*8-1 downto (" << (parlen-1) << "-i)*8);" << endl;

							outfile << "\t\t\t\t\t\tend loop;" << endl;

							ix += parlen;
						};
					};
				};
			};

			if (!first2) {
				outfile << "\t\t\t\t\tend if;" << endl;
				outfile << endl;
			};
		};
	};

	if (!first) {
		outfile << "\t\t\t\tend if;" << endl;
		outfile << endl;
	};

	outfile << "-- IP impl.op.prepTxA --- IEND" << endl;

	// --- impl.op.copyRxA
	outfile << "-- IP impl.op.copyRxA --- IBEGIN" << endl;
	
	first = true; // controller

	for (unsigned int i = 0; i < untmdls.nodes.size(); i++) {
		untmdl = untmdls.nodes[i];

		if (untmdl->ixVBasetype == VecWdbeVMModuleBasetype::ECTR) {
			dbswdbe->tblwdbemcommand->loadRstByRetReu(VecWdbeVMCommandRefTbl::CTR, untmdl->refWdbeMController, false, cmds);
 
 			first2 = true; // command

			for (unsigned int j = 0; j < cmds.nodes.size(); j++) {
				cmd = cmds.nodes[j];

				dbswdbe->tblwdbeamcommandinvpar->loadRstByCmd(cmd->ref, false, ipas);

				if (ipas.nodes.size() > 0) {
					if (first2) {
						outfile << "\t\t\t\t";
						if (first) first = false;
						else outfile << "els";
						
						outfile << "if opbuf(ixOpbufController)=tixV" << Untsref << "Controller" << StrMod::cap(untmdl->sref) << " then" << endl;
					};

					outfile << "\t\t\t\t\t";
					if (first2) first2 = false;
					else outfile << "els";
					
					outfile << "if opbuf(ixOpbufCommand)=tixV" << StrMod::cap(untmdl->sref) << "Command" << StrMod::cap(cmd->sref) << " then" << endl;

					ix = 0;
					for (unsigned int k = 0; k < ipas.nodes.size(); k++) {
						ipa = ipas.nodes[k];
						
						parlen = Wdbe::getParlen(ipa->ixWdbeVPartype, ipa->Length);

						if (ipa->ixWdbeVPartype == VecWdbeVPartype::VBLOB) {
							outfile << "\t\t\t\t\t\t" << untmdl->sref << StrMod::cap(cmd->sref) << "Len" << StrMod::cap(ipa->sref) << "_sig <= rxbuf(" << ix << ");" << endl;

							ix++;
							parlen--;
						};

						if (parlen == 1) {
							outfile << "\t\t\t\t\t\t" << untmdl->sref << StrMod::cap(cmd->sref) << StrMod::cap(ipa->sref) << "_sig <= rxbuf(" << ix << ");" << endl;
							ix++;

						} else {
							outfile << "\t\t\t\t\t\tfor i in 0 to " << (parlen-1) << " loop" << endl;

							outfile << "\t\t\t\t\t\t\t" << untmdl->sref << StrMod::cap(cmd->sref) << StrMod::cap(ipa->sref) << "_sig((" << parlen << "-i)*8-1 downto (" << (parlen-1) << "-i)*8) <= rxbuf(";
							if (ix > 0) outfile << ix << "+";
							outfile << "i);" << endl;

							outfile << "\t\t\t\t\t\tend loop;" << endl;

							ix += parlen;
						};
					};
				};
			};

			if (!first2) {
				outfile << "\t\t\t\t\tend if;" << endl;
				outfile << endl;
			};
		};
	};

	if (!first) {
		outfile << "\t\t\t\tend if;" << endl;
		outfile << endl;
	};

	outfile << "-- IP impl.op.copyRxA --- IEND" << endl;
};
// IP cust --- IEND
