/**
	* \file WdbeMtpWrfpgaAximmcohostif_Easy_v1_0.cpp
	* Wdbe operation processor -  (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 3 Mar 2025
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpWrfpgaAximmcohostif_Easy_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpWrfpga;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpWrfpgaAximmcohostif_Easy_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpWrfpgaAximmcohostif_Easy_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpWrfpga* dpchinv
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

		// xxxx/Aximmcohostif.vhd
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
void WdbeMtpWrfpgaAximmcohostif_Easy_v1_0::writeMdlVhd(
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

	unsigned int wD;

	unsigned int ix;

	unsigned int parlen;

	vector<string> ss;
	string s;

	bool first, first2;

	dbswdbe->tblwdbemmodule->loadRstByHktHku(mdl->hkIxVTbl, mdl->hkUref, false, untmdls);

	s = "8";
	Wdbe::getMpa(dbswdbe, mdl->ref, "wD", s);
	wD = atoi(s.c_str());

	// --- impl.read.ret
	// modified version from WdbeMtpWrfpgaCohostif_Easy_v1_0.cpp, IP impl.op.inv.retbuf
	outfile << "-- IP impl.read.ret --- IBEGIN" << endl;

	first = true; // controller

	for (unsigned int i = 0; i < untmdls.nodes.size(); i++) {
		untmdl = untmdls.nodes[i];

		if ((untmdl->ixVBasetype == VecWdbeVMModuleBasetype::ECTR) || (untmdl->ixVBasetype == VecWdbeVMModuleBasetype::EDBGCTR)) {
			dbswdbe->tblwdbemcommand->loadRstBySQL("SELECT TblWdbeMCommand.* FROM TblWdbeRMCommandMController, TblWdbeMCommand WHERE TblWdbeMCommand.ref = TblWdbeRMCommandMController.refWdbeMCommand AND TblWdbeMCommand.refIxVTbl = "
						+ to_string(VecWdbeVMCommandRefTbl::CTR) + " AND TblWdbeMCommand.refUref = " + to_string(untmdl->refWdbeMController) + " AND TblWdbeRMCommandMController.refWdbeMController = " + to_string(mdl->refWdbeMController)
						+ " ORDER BY TblWdbeMCommand.refNum ASC", false, cmds);
 
 			first2 = true; // command

			for (unsigned int j = 0; j < cmds.nodes.size(); j++) {
				cmd = cmds.nodes[j];

				dbswdbe->tblwdbeamcommandretpar->loadRstByCmd(cmd->ref, false, rpas);

				if (rpas.nodes.size() > 0) {
					if (first2) {
						outfile << "\t\t\t\t\t\t";
						if (first) first = false;
						else outfile << "els";
						
						outfile << "if tixVController_lcl=tixV" << Untsref << "Controller" << StrMod::cap(untmdl->sref) << " then" << endl;
					};

					outfile << "\t\t\t\t\t\t\t";
					if (first2) first2 = false;
					else outfile << "els";
					
					outfile << "if tixVCommand_lcl=tixV" << StrMod::cap(untmdl->sref) << "Command" << StrMod::cap(cmd->sref) << " then" << endl;

					ss.clear();

					for (unsigned int k = 0; k < rpas.nodes.size(); k++) {
						rpa = rpas.nodes[k];
						
						parlen = Wdbe::getParlen(rpa->ixWdbeVPartype, rpa->Length);

						if (rpa->ixWdbeVPartype == VecWdbeVPartype::VBLOB) {
							ss.push_back(untmdl->sref + StrMod::cap(cmd->sref) + "Len" + StrMod::cap(rpa->sref));
							parlen--;
						};

						if (parlen == 1) ss.push_back(untmdl->sref + StrMod::cap(cmd->sref) + StrMod::cap(rpa->sref));
						else if ((rpa->ixWdbeVPartype == VecWdbeVPartype::BLOB) || (rpa->ixWdbeVPartype == VecWdbeVPartype::VBLOB)) for (unsigned int l = 0; l < parlen; l++) ss.push_back(untmdl->sref + StrMod::cap(cmd->sref) + StrMod::cap(rpa->sref) + "(" + to_string(l) + "*8+7 downto " +  to_string(l) + "*8)");
						else for (unsigned int l = 0; l < parlen; l++) ss.push_back(untmdl->sref + StrMod::cap(cmd->sref) + StrMod::cap(rpa->sref) + "(" + to_string(parlen-l-1) + "*8+7 downto " +  to_string(parlen-l-1) + "*8)");
					};

					while (ss.size()%(wD/8) != 0) ss.push_back("x\"00\"");

					for (unsigned int k = 0; k < ss.size(); k++) {
						if (k%(wD/8) == 0) {
							outfile << "\t\t\t\t\t\t\t\t";
							if (k != 0) outfile << "els";
							outfile << "if a=" << k/(wD/8) << " then" << endl;

							outfile << "\t\t\t\t\t\t\t\t\tAXIL_rdata_sig <=";
						} else outfile << " &";

						outfile << " " << ss[(wD/8)*(k/(wD/8)) + (wD/8)-(k%(wD/8))-1];

						if (k%(wD/8) == (wD/8-1)) outfile << ";" << endl;
					};
					outfile << "\t\t\t\t\t\t\t\tend if;" << endl;
					

				};
			};

			if (!first2) {
				outfile << "\t\t\t\t\t\t\tend if;" << endl;
				outfile << endl;
			};
		};
	};

	if (!first) {
		outfile << "\t\t\t\t\t\tend if;" << endl;
		outfile << endl;
	};

	outfile << "-- IP impl.read.ret --- IEND" << endl;

	// --- impl.write.wiring.reqInv
	// exact copy from WdbeMtpWrfpgaCohostif_Easy_v1_0.cpp

	outfile << "-- IP impl.write.wiring.reqInv --- IBEGIN" << endl;

	for (unsigned int i = 0; i < untmdls.nodes.size(); i++) {
		untmdl = untmdls.nodes[i];

		if ((untmdl->ixVBasetype == VecWdbeVMModuleBasetype::ECTR) || (untmdl->ixVBasetype == VecWdbeVMModuleBasetype::EDBGCTR)) {
			dbswdbe->tblwdbemcommand->loadRstBySQL("SELECT TblWdbeMCommand.* FROM TblWdbeRMCommandMController, TblWdbeMCommand WHERE TblWdbeMCommand.ref = TblWdbeRMCommandMController.refWdbeMCommand AND TblWdbeMCommand.refIxVTbl = "
						+ to_string(VecWdbeVMCommandRefTbl::CTR) + " AND TblWdbeMCommand.refUref = " + to_string(untmdl->refWdbeMController) + " AND TblWdbeRMCommandMController.refWdbeMController = " + to_string(mdl->refWdbeMController)
						+ " ORDER BY TblWdbeMCommand.refNum ASC", false, cmds);

			for (unsigned int j = 0; j < cmds.nodes.size(); j++) {
				cmd = cmds.nodes[j];

				if (cmd->ixVRettype != VecWdbeVMCommandRettype::STATSNG) {
					outfile << "\treqInv" << StrMod::cap(untmdl->sref) << StrMod::cap(cmd->sref) << " <= reqInv when (tixVController=tixV" << Untsref << "Controller" << StrMod::cap(untmdl->sref) << " and tixVCommand=tixV" << StrMod::cap(untmdl->sref) << "Command" << StrMod::cap(cmd->sref) << ") else '0';" << endl;

					dbswdbe->tblwdbeamcommandinvpar->loadRstByCmd(cmd->ref, false, ipas);

					ix = 0;
					for (unsigned int k = 0; k < ipas.nodes.size(); k++) {
						ipa = ipas.nodes[k];
						
						parlen = Wdbe::getParlen(ipa->ixWdbeVPartype, ipa->Length);

						if (ipa->ixWdbeVPartype == VecWdbeVPartype::VBLOB) {
							outfile << "\t" << untmdl->sref << StrMod::cap(cmd->sref) << "Len" << StrMod::cap(ipa->sref) << " <= invbuf(" << ix << ");" << endl;

							ix++;
							parlen--;
						};

						outfile << "\t" << untmdl->sref << StrMod::cap(cmd->sref) << StrMod::cap(ipa->sref) << " <=";

						for (unsigned int l = 0; l < parlen; l++) {
							if (l != 0) outfile << " &";

							if ((ipa->ixWdbeVPartype == VecWdbeVPartype::BLOB) || (ipa->ixWdbeVPartype == VecWdbeVPartype::VBLOB)) outfile << " invbuf(" << (ix+parlen-l-1) << ")";
							else outfile << " invbuf(" << (ix+l) << ")";
						};

						outfile << ";" << endl;

						ix += parlen;
					};

					outfile << endl;
				};
			};
		};
	};

	outfile << "-- IP impl.write.wiring.reqInv --- IEND" << endl;

	// --- impl.write.wiring.ackInv
	// exact copy from WdbeMtpWrfpgaCohostif_Easy_v1_0.cpp

	outfile << "-- IP impl.write.wiring.ackInv --- IBEGIN" << endl;

	first = true;

	outfile << "\tackInv <= ";

	for (unsigned int i = 0; i < untmdls.nodes.size(); i++) {
		untmdl = untmdls.nodes[i];

		if ((untmdl->ixVBasetype == VecWdbeVMModuleBasetype::ECTR) || (untmdl->ixVBasetype == VecWdbeVMModuleBasetype::EDBGCTR)) {
			dbswdbe->tblwdbemcommand->loadRstBySQL("SELECT TblWdbeMCommand.* FROM TblWdbeRMCommandMController, TblWdbeMCommand WHERE TblWdbeMCommand.ref = TblWdbeRMCommandMController.refWdbeMCommand AND TblWdbeMCommand.refIxVTbl = "
						+ to_string(VecWdbeVMCommandRefTbl::CTR) + " AND TblWdbeMCommand.refUref = " + to_string(untmdl->refWdbeMController) + " AND TblWdbeRMCommandMController.refWdbeMController = " + to_string(mdl->refWdbeMController)
						+ " ORDER BY TblWdbeMCommand.refNum ASC", false, cmds);

			for (unsigned int j = 0; j < cmds.nodes.size(); j++) {
				cmd = cmds.nodes[j];

				if (cmd->ixVRettype != VecWdbeVMCommandRettype::STATSNG) {
					if (first) first = false;
					else outfile << "\t\t\t\telse ";

					outfile << "ackInv" << StrMod::cap(untmdl->sref) << StrMod::cap(cmd->sref) << " when (tixVController=tixV" << Untsref << "Controller" << StrMod::cap(untmdl->sref) << " and tixVCommand=tixV" << StrMod::cap(untmdl->sref) << "Command" << StrMod::cap(cmd->sref) << ")" << endl;
					first = false;
				};
			};
		};
	};

	if (!first) outfile << "\t\t\t\telse ";
	outfile << "'1';" <<  endl;

	outfile << "-- IP impl.write.wiring.ackInv --- IEND" << endl;
};
// IP cust --- IEND
