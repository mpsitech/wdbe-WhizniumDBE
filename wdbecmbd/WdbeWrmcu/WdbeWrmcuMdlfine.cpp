/**
	* \file WdbeWrmcuMdlfine.cpp
	* Wdbe operation processor - write in-detail C code (implementation)
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

#include "WdbeWrmcuMdlfine.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeWrmcu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeWrmcuMdlfine
 ******************************************************************************/

DpchRetWdbe* WdbeWrmcuMdlfine::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeWrmcuMdlfine* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WdbeMModule* mdl = NULL;

	fstream outfile;

	string s;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		// xxxx/Xxxxx.c
		s = xchg->tmppath + "/" + folder + "/" + StrMod::cap(mdl->sref) + ".c.ip";
		outfile.open(s.c_str(), ios::out);
		writeMdlC(dbswdbe, outfile, mdl);
		outfile.close();

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WdbeWrmcuMdlfine::writeMdlC(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMModule* mdl
		) {
	ListWdbeMProcess prcs;
	WdbeMProcess* prc = NULL;
	string Prcsref;

	ListWdbeMFsmstate fsts;
	WdbeMFsmstate* fst = NULL;

	uint fstCnum;

	bool found;

	dbswdbe->tblwdbemprocess->loadRstByMdl(mdl->ref, false, prcs);

	for (unsigned int i = 0; i < prcs.nodes.size(); i++) {
		prc = prcs.nodes[i];
		Prcsref = StrMod::cap(prc->sref);

		if (prc->refWdbeMFsm != 0) {
			dbswdbe->tblwdbemfsmstate->loadRstByFsm(prc->refWdbeMFsm, false, fsts);

			// --- vars.xxxx
			outfile << "// IP vars." << prc->sref << " --- IBEGIN" << endl;

			if (fsts.nodes.size() > 0) {
				outfile << "enum State" << StrMod::cap(prc->sref) << " {";

				for (unsigned int j = 0; j < fsts.nodes.size(); j++) {
					fst = fsts.nodes[j];

					if ((j == 0) || (fstCnum == 5) || (fst->refWdbeCFsmstate == 0)) fstCnum = 0;
					else if (fst->refWdbeCFsmstate != fsts.nodes[j-1]->refWdbeCFsmstate) fstCnum = 0;
					else fstCnum++;

					if (fstCnum == 0) outfile << endl << "\t";
					else outfile << " ";
					
					outfile << "state" << Prcsref << StrMod::cap(fst->sref);
					if ((j+1) != fsts.nodes.size()) outfile << ",";
				};

				outfile << endl;
				outfile << "};" << endl;
				outfile << endl;

				outfile << "static enum State" << Prcsref << " state" << Prcsref << " = state" << Prcsref << StrMod::cap(fsts.nodes[0]->sref) << ";" << endl;
				outfile << endl;
			};

			outfile << "// IP vars." << prc->sref << " --- IEND" << endl;
		};
	};

	found = false;

	for (unsigned int i = 0; i < prcs.nodes.size(); i++) {
		prc = prcs.nodes[i];
		Prcsref = StrMod::cap(prc->sref);

		if (prc->refWdbeMFsm != 0) {
			dbswdbe->tblwdbemfsmstate->loadRstByFsm(prc->refWdbeMFsm, false, fsts);

			// --- run.xxxx
			outfile << "// IP run." << prc->sref << " --- IBEGIN" << endl;
			outfile << "\t// IP run." << prc->sref << " --- BEGIN" << endl;

			outfile << "\tswitch (state" << Prcsref << ") {" << endl;

			for (unsigned int j = 0; j < fsts.nodes.size(); j++) {
				fst = fsts.nodes[j];

				outfile << "\t\tcase state" << Prcsref << StrMod::cap(fst->sref) << ":" << endl;

				if (prc->Syncrst.compare("state(" + fst->sref + ")") == 0) {
					wrSyncrst(dbswdbe, outfile, mdl);
					found = true;

				} else outfile << "\t\t\t// IP " << prc->sref << "." << fst->sref << " --- INSERT" << endl;

				outfile << "\t\t\tbreak;" << endl;
				outfile << endl;
			};

			outfile << "\t};" << endl;
			outfile << endl;

			outfile << "\t// IP run." << prc->sref << " --- END" << endl;
			outfile << "// IP run." << prc->sref << " --- IEND" << endl;
			outfile << endl;
		};
	};

	if (!found) {
		// --- syncrst
		outfile << "// IP syncrst --- IBEGIN" << endl;
		wrSyncrst(dbswdbe, outfile, mdl);
		outfile << "// IP syncrst --- IEND" << endl;
	};
};

void WdbeWrmcuMdlfine::wrSyncrst(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMModule* mdl
		) {
	ListWdbeMSignal sigs;
	WdbeMSignal* sig = NULL;

	outfile << "\t\t\t// IP syncrst --- BEGIN" << endl;

	dbswdbe->tblwdbemsignal->loadRstBySQL("SELECT * FROM TblWdbeMSignal WHERE ixVBasetype = " + to_string(VecWdbeVMSignalBasetype::HSHK) + " AND mgeIxVTbl = " + to_string(VecWdbeVMSignalMgeTbl::MDL)
				+ " AND mgeUref = " + to_string(mdl->ref) + " ORDER BY sref ASC", false, sigs);

	for (unsigned int i = 0; i < sigs.nodes.size(); i++) {
		sig = sigs.nodes[i];

		outfile << "\t\t\tflags." << sig->sref << " = 0;" << endl;
		outfile << "\t\t\tSET_EVT_" << sig->sref << "();" << endl;
	};

	outfile << "\t\t\t// IP syncrst --- END" << endl;
};
// IP cust --- IEND
