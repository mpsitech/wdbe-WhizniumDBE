/**
	* \file WdbeWrmcuMdlraw.cpp
	* Wdbe operation processor - write raw C code (implementation)
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

#include "WdbeWrmcuMdlraw.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeWrmcu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeWrmcuMdlraw
 ******************************************************************************/

DpchRetWdbe* WdbeWrmcuMdlraw::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeWrmcuMdlraw* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;
	string folder = dpchinv->folder;
	string Prjshort = dpchinv->Prjshort;
	string Untsref = dpchinv->Untsref;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WdbeMModule* mdl = NULL;

	ListWdbeMProcess prcs;

	fstream outfile;

	string s;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		dbswdbe->tblwdbemprocess->loadRstByMdl(mdl->ref, false, prcs);

		// xxxx/Xxxxx.c
		s = xchg->tmppath + "/" + folder + "/" + StrMod::cap(mdl->sref) + ".c.ip";
		outfile.open(s.c_str(), ios::out);
		writeMdlC(dbswdbe, outfile, Prjshort, Untsref, mdl, prcs);
		outfile.close();

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WdbeWrmcuMdlraw::writeMdlC(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, const string& Prjshort
			, const string& Untsref
			, WdbeMModule* mdl
			, ListWdbeMProcess& prcs
		) {
	ListWdbeMCommand cmds;
	WdbeMCommand* cmd = NULL;

	ListWdbeAMCommandInvpar ipas;
	WdbeAMCommandInvpar* ipa = NULL;

	WdbeMProcess* prc = NULL;

	unsigned int ix;

	bool first;

	// probably should be part of WrmcuEctr
	// --- define.cmds
	outfile << "// IP define.cmds --- IBEGIN" << endl;
	if (mdl->refWdbeMController != 0) {
		dbswdbe->tblwdbemcommand->loadRstByRetReu(VecWdbeVMCommandRefTbl::CTR, mdl->refWdbeMController, false, cmds);

		for (unsigned int i = 0; i < cmds.nodes.size(); i++) {
			cmd = cmds.nodes[i];

			dbswdbe->tblwdbeamcommandinvpar->loadRstByCmd(cmd->ref, false, ipas);

			if (ipas.nodes.size() > 0) {
				ix = 0;

				for (unsigned int j = 0; j < ipas.nodes.size(); j++) {
					ipa = ipas.nodes[j];

					outfile << "#define IXRXBUF_" << cmd->sref << StrMod::cap(ipa->sref) << " " << ix << endl;

					ix += Wdbe::getParlen(ipa->ixWdbeVPartype, ipa->Length);
				};

				outfile << endl;
			};
		};
	};
	outfile << "// IP define.cmds --- IEND" << endl;

	// --- vars.prcs
	outfile << "// IP vars.prcs --- IBEGIN" << endl;
	for (unsigned int i = 0; i < prcs.nodes.size(); i++) {
		prc = prcs.nodes[i];

		if (prc->refWdbeMFsm != 0) {
			outfile << "// --- " << prc->Comment << " (" << prc->sref << ")" << endl;
			outfile << "// IP vars." << prc->sref << " --- INSERT" << endl;
			outfile << endl;
		};
	};
	outfile << "// IP vars.prcs --- IEND" << endl;

	// --- run.prcs
	outfile << "// IP run.prcs --- IBEGIN" << endl;
	for (unsigned int i = 0; i < prcs.nodes.size(); i++) {
		prc = prcs.nodes[i];

		if (prc->refWdbeMFsm != 0) {
			outfile << "// IP run." << prc->sref << " --- INSERT" << endl;
			outfile << endl;
		};
	};
	outfile << "// IP run.prcs --- IEND" << endl;
};
// IP cust --- IEND
