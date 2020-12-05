/**
	* \file WdbeWrmcuEhostif.cpp
	* Wdbe operation processor - write template-specific C code (implementation)
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

#include "WdbeWrmcuEhostif.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeWrmcu;

/******************************************************************************
 namespace WdbeWrmcuEhostif
 ******************************************************************************/

DpchRetWdbe* WdbeWrmcuEhostif::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeWrmcuEhostif* dpchinv
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

		// xxxx/Hostif.c
		s = xchg->tmppath + "/" + folder + "/" + Compsref + ".c.ip";
		outfile.open(s.c_str(), ios::out);
		writeMdlC(dbswdbe, outfile, Prjshort, Untsref, mdl);
		outfile.close();

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WdbeWrmcuEhostif::writeMdlC(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, const string& Prjshort
			, const string& Untsref
			, WdbeMModule* mdl
		) {
	ListWdbeMModule untmdls;
	WdbeMModule* untmdl = NULL;

	ListWdbeMCommand cmds;
	WdbeMCommand* cmd = NULL;

	ListWdbeAMCommandInvpar ipas;
	WdbeAMCommandInvpar* ipa = NULL;

	ListWdbeAMCommandRetpar rpas;
	WdbeAMCommandRetpar* rpa = NULL;

	uint cnt;

	unsigned int ix;

	unsigned int parlen;

	bool first, first2;

	dbswdbe->tblwdbemmodule->loadRstByHktHku(mdl->hkIxVTbl, mdl->hkUref, false, untmdls);

	// --- op.rxopD.cmdret
	outfile << "// IP op.rxopD.cmdret --- IBEGIN" << endl;

	// no invocation parameters, return type immsng
	first = true; // first command (any controller)
	outfile << "\t\t\t\tif (";

	for (unsigned int i = 0; i < untmdls.nodes.size(); i++) {
		untmdl = untmdls.nodes[i];

		if (untmdl->ixVBasetype == VecWdbeVMModuleBasetype::ECTR) {
			first2 = true; // first command (per controller)

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
								outfile << "\t\t\t\t\t\t\t||";
							};

							outfile << " ((opbuf[ixOpbufController] == tixVController" << StrMod::cap(untmdl->sref) << ") && (";

							first2 = false;
						} else outfile << " || ";
						
						outfile << "(opbuf[ixOpbufCommand] == tixV" << StrMod::cap(untmdl->sref) << "Command" << StrMod::cap(cmd->sref) << ")";


					};
				};
			};

			if (!first2) outfile << "))";
		};
	};

	if (first) outfile << "false";
	else outfile << " ";

	outfile << ") {" << endl;
	outfile << "\t\t\t\t\t// return type: immsng" << endl;

	if (!first) {
		first = true;

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
								outfile << "\t\t\t\t\t";
								if (first) first = false;
								else outfile << "} else ";

								outfile << "if (opbuf[ixOpbufController] == tixVController" << StrMod::cap(untmdl->sref) << ") {" << endl;

								outfile << "\t\t\t\t\t\t";

								first2 = false;
							} else outfile << "\t\t\t\t\t\telse ";
							
							outfile << "if (opbuf[ixOpbufCommand] == tixV" << StrMod::cap(untmdl->sref) << "Command" << StrMod::cap(cmd->sref) << ") shrdat" << StrMod::cap(untmdl->sref) << ".reqInv" << StrMod::cap(cmd->sref) << " = true;" << endl;
						};
					};
				};
			};
		};

		if (!first) {
			outfile << "\t\t\t\t\t};" << endl;
			outfile << endl;
		};
	};

	outfile << "\t\t\t\t\tstateOp = stateOpVoidinv;" << endl;
	outfile << endl;

	// no invocation parameters, return type statsng
	first = true;
	outfile << "\t\t\t\t} else if (";

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
								outfile << "\t\t\t\t\t\t\t||";
							};

							outfile << " ((opbuf[ixOpbufController] == tixVController" << StrMod::cap(untmdl->sref) << ") && (";

							first2 = false;
						} else outfile << " || ";
						
						outfile << "opbuf[ixOpbufCommand] == tixV" << StrMod::cap(untmdl->sref) << "Command" << StrMod::cap(cmd->sref);


					};
				};
			};

			if (!first2) outfile << "))";
		};
	};

	if (first) outfile << "false";
	else outfile << " ";

	outfile << ") {" << endl;
	outfile << endl;

	outfile << "\t\t\t\t\t// return type: statsng" << endl;
	outfile << "\t\t\t\t\tstateOp = stateOpPrepTx;" << endl;
	outfile << "\t\t\t\t};" << endl;

	outfile << "// IP op.rxopD.cmdret --- IEND" << endl;

	// --- op.rxopD.cmdinv
	outfile << "// IP op.rxopD.cmdinv --- IBEGIN" << endl;

	// return type void
	first = true;
	outfile << "\t\t\t\tif (";

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
							outfile << "\t\t\t\t\t\t\t||";
						};

						outfile << " ((opbuf[ixOpbufController] == tixVController" << StrMod::cap(untmdl->sref) << ") && (";

						first2 = false;
					} else outfile << " || ";
					
					outfile << "(opbuf[ixOpbufCommand] == tixV" << StrMod::cap(untmdl->sref) << "Command" << StrMod::cap(cmd->sref) << ")";
				};
			};

			if (!first2) outfile << "))";
		};
	};

	if (first) outfile << "false";
	else outfile << " ";

	outfile << ") {" << endl;

	outfile << "// IP op.rxopD.cmdinv --- IEND" << endl;

	// --- op.voidinv
	outfile << "// IP op.voidinv --- IBEGIN" << endl;

	// no invocation parameters, return type immsng
	first = true;

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
							outfile << "\t\t\t";
							if (first) first = false;
							else outfile << "} else ";

							outfile << "if (opbuf[ixOpbufController] == tixVController" << StrMod::cap(untmdl->sref) << ") {" << endl;

							outfile << "\t\t\t\t";

							first2 = false;

						} else outfile << "\t\t\t\t} else ";
						
						outfile << "if ((opbuf[ixOpbufCommand] == tixV" << StrMod::cap(untmdl->sref) << "Command" << StrMod::cap(cmd->sref) << ") && shrdat" << StrMod::cap(untmdl->sref) << ".ackInv" << StrMod::cap(cmd->sref) << ") {" << endl;
						outfile << "\t\t\t\t\tshrdat" << StrMod::cap(untmdl->sref) << ".reqInv" << StrMod::cap(cmd->sref) << " = false;" << endl;
						outfile << "\t\t\t\t\tstateOp = stateOpPrepTx;" << endl;
						outfile << "\t\t\t\t\tmod = true;" << endl;
					};
				};
			};

			if (!first2) outfile << "\t\t\t\t};" << endl;
		};
	};

	if (!first) {
		outfile << "\t\t\t};" << endl;
		outfile << endl;
	};

	outfile << "// IP op.voidinv --- IEND" << endl;

	// --- op.prepTx
	outfile << "// IP op.prepTx --- IBEGIN" << endl;

	// at least one return parameter(, return types statsng/immsng)
	first = true;

	for (unsigned int i = 0; i < untmdls.nodes.size(); i++) {
		untmdl = untmdls.nodes[i];

		if (untmdl->ixVBasetype == VecWdbeVMModuleBasetype::ECTR) {
			first2 = true;

			dbswdbe->tblwdbemcommand->loadRstByRetReu(VecWdbeVMCommandRefTbl::CTR, untmdl->refWdbeMController, false, cmds);

			for (unsigned int j = 0; j < cmds.nodes.size(); j++) {
				cmd = cmds.nodes[j];

				if ((cmd->ixVRettype == VecWdbeVMCommandRettype::STATSNG) || (cmd->ixVRettype == VecWdbeVMCommandRettype::IMMSNG)) {
					dbswdbe->tblwdbeamcommandretpar->loadRstByCmd(cmd->ref, false, rpas);

					if (rpas.nodes.size() > 0) {
						if (first2) {
							outfile << "\t\t\t";
							if (first) first = false;
							else outfile << "} else ";

							outfile << "if (opbuf[ixOpbufController] == tixVController" << StrMod::cap(untmdl->sref) << ") {" << endl;

							outfile << "\t\t\t\t";

							first2 = false;

						} else outfile << "\t\t\t\t} else ";
						
						outfile << "if (opbuf[ixOpbufCommand] == tixV" << StrMod::cap(untmdl->sref) << "Command" << StrMod::cap(cmd->sref) << ") {" << endl;

						ix = 0;
						for (unsigned int k = 0; k < rpas.nodes.size(); k++) {
							rpa = rpas.nodes[k];
							
							parlen = Wdbe::getParlen(rpa->ixWdbeVPartype, rpa->Length);

							if (rpa->ixWdbeVPartype == VecWdbeVPartype::VBLOB) {
								outfile << "\t\t\t\t\ttxbuf[" << ix << "] = shrdat" << StrMod::cap(untmdl->sref) << "." << cmd->sref << "Len" << StrMod::cap(rpa->sref) << ";" << endl;

								ix++;
								parlen--;
							};

							if (parlen == 1) {
								outfile << "\t\t\t\t\ttxbuf[" << ix << "] = shrdat" << StrMod::cap(untmdl->sref) << "." << cmd->sref << StrMod::cap(rpa->sref) << ";" << endl;
								ix++;

							} else {
								for (unsigned int l = 0; l < parlen;l++) {
									outfile << "\t\t\t\t\ttxbuf[" << ix << "] = ((unsigned char*) &shrdat" << StrMod::cap(untmdl->sref) << "." << cmd->sref << StrMod::cap(rpa->sref) << ")[" << (parlen-l-1) << "];" << endl;
									ix++;
								};
							};
						};
					};
				};
			};

			if (!first2) outfile << "\t\t\t\t};" << endl;
		};
	};

	if (!first) {
		outfile << "\t\t\t};" << endl;
		outfile << endl;
	};

	outfile << "// IP op.prepTx --- IEND" << endl;

	// --- op.copyRx
	outfile << "// IP op.copyRx --- IBEGIN" << endl;

	// at least one invocation parameter(, return type void)
	first = true;

	for (unsigned int i = 0; i < untmdls.nodes.size(); i++) {
		untmdl = untmdls.nodes[i];

		if (untmdl->ixVBasetype == VecWdbeVMModuleBasetype::ECTR) {
			first2 = true;

			dbswdbe->tblwdbemcommand->loadRstByRetReu(VecWdbeVMCommandRefTbl::CTR, untmdl->refWdbeMController, false, cmds);

			for (unsigned int j = 0; j < cmds.nodes.size(); j++) {
				cmd = cmds.nodes[j];

				if (cmd->ixVRettype == VecWdbeVMCommandRettype::VOID) {
					dbswdbe->tblwdbeamcommandinvpar->loadRstByCmd(cmd->ref, false, ipas);

					if (ipas.nodes.size() > 0) {
						if (first2) {
							outfile << "\t\t\t";
							if (first) first = false;
							else outfile << "} else ";

							outfile << "if (opbuf[ixOpbufController] == tixVController" << StrMod::cap(untmdl->sref) << ") {" << endl;

							outfile << "\t\t\t\t";

							first2 = false;

						} else outfile << "\t\t\t\t} else ";
						
						outfile << "if (opbuf[ixOpbufCommand] == tixV" << StrMod::cap(untmdl->sref) << "Command" << StrMod::cap(cmd->sref) << ") {" << endl;

						ix = 0;
						for (unsigned int k = 0; k < ipas.nodes.size(); k++) {
							ipa = ipas.nodes[k];
							
							parlen = Wdbe::getParlen(ipa->ixWdbeVPartype, ipa->Length);

							if (ipa->ixWdbeVPartype == VecWdbeVPartype::VBLOB) {
								outfile << "\t\t\t\t\tshrdat" << StrMod::cap(untmdl->sref) << "." << cmd->sref << "Len" << StrMod::cap(ipa->sref) << " = &(rxbuf[" << ix << "]);" << endl;

								ix++;
								parlen--;
							};

							outfile << "\t\t\t\t\tshrdat" << StrMod::cap(untmdl->sref) << "." << cmd->sref << StrMod::cap(ipa->sref) << " = &(rxbuf[" << ix << "]);" << endl;
							for (unsigned int l = 0; l < parlen;l++) ix++;
						};
						outfile << endl;

						outfile << "\t\t\t\t\tshrdat" << StrMod::cap(untmdl->sref) << ".reqInv" << StrMod::cap(cmd->sref) << " = true;" << endl;
					};
				};
			};

			if (!first2) outfile << "\t\t\t\t};" << endl;
		};
	};

	if (!first) {
		outfile << "\t\t\t};" << endl;
		outfile << endl;
	};

	outfile << "// IP op.copyRx --- IEND" << endl;

	// --- op.inv
	outfile << "// IP op.inv --- IBEGIN" << endl;

	// at least one invocation parameter, return type void
	first = true;

	for (unsigned int i = 0; i < untmdls.nodes.size(); i++) {
		untmdl = untmdls.nodes[i];

		if (untmdl->ixVBasetype == VecWdbeVMModuleBasetype::ECTR) {
			first2 = true;

			dbswdbe->tblwdbemcommand->loadRstByRetReu(VecWdbeVMCommandRefTbl::CTR, untmdl->refWdbeMController, false, cmds);

			for (unsigned int j = 0; j < cmds.nodes.size(); j++) {
				cmd = cmds.nodes[j];

				if (cmd->ixVRettype == VecWdbeVMCommandRettype::VOID) {
					dbswdbe->loadUintBySQL("SELECT COUNT(ref) FROM TblWdbeAMCommandInvpar WHERE cmdRefWdbeMCommand = " + to_string(cmd->ref), cnt);

					if (cnt > 0) {
						if (first2) {
							outfile << "\t\t\t";
							if (first) first = false;
							else outfile << "} else ";

							outfile << "if (opbuf[ixOpbufController] == tixVController" << StrMod::cap(untmdl->sref) << ") {" << endl;

							outfile << "\t\t\t\t";

							first2 = false;

						} else outfile << "\t\t\t\t} else ";
						
						outfile << "if ((opbuf[ixOpbufCommand] == tixV" << StrMod::cap(untmdl->sref) << "Command" << StrMod::cap(cmd->sref) << ") && shrdat" << StrMod::cap(untmdl->sref) << ".ackInv" << StrMod::cap(cmd->sref) << ") {" << endl;
						outfile << "\t\t\t\t\tshrdat" << StrMod::cap(untmdl->sref) << ".reqInv" << StrMod::cap(cmd->sref) << " = false;" << endl;
						outfile << "\t\t\t\t\tstateOp = stateOpTxackA;" << endl;
						outfile << "\t\t\t\t\tmod = true;" << endl;
					};
				};
			};

			if (!first2) outfile << "\t\t\t\t};" << endl;
		};
	};

	if (!first) {
		outfile << "\t\t\t};" << endl;
		outfile << endl;
	};

	outfile << "// IP op.inv --- IEND" << endl;
};
// IP cust --- IEND



