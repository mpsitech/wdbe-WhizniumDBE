/**
	* \file WdbeWrfpgaMdlfine.cpp
	* Wdbe operation processor - write in-detail VHDL code (implementation)
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

#include "WdbeWrfpgaMdlfine.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeWrfpga;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeWrfpgaMdlfine
 ******************************************************************************/

DpchRetWdbe* WdbeWrfpgaMdlfine::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeWrfpgaMdlfine* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;
	string folder = dpchinv->folder;

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
		writeMdlVhd(dbswdbe, outfile, mdl);
		outfile.close();

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WdbeWrfpgaMdlfine::writeMdlVhd(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMModule* mdl
		) {
	ListWdbeMModule submdls;
	map<ubigint,string> srefsSubmdls; // by ref
	WdbeMModule* submdl = NULL;

	ListWdbeMPort prts;
	map<ubigint,string> srefsPrts; // by ref
	WdbeMPort* prt = NULL;

	ListWdbeMSignal sigs;
	WdbeMSignal* sig = NULL;
	WdbeMSignal* sig2 = NULL;
	set<ubigint> refsSigs; // used to identify signals in 'other' category
	set<string> srefsSigs;

	set<string> srefsSlprtsigs;

	ListWdbeMProcess prcs;
	WdbeMProcess* prc = NULL;
	map<ubigint,string> srefsPrcs; // by ref

	ListWdbeAVKeylistKey klsAkeys;
	WdbeAVKeylistKey* klsAkey = NULL;

	map<string,WdbeAVKeylistKey*> srefsHtys;
	set<ubigint> refsHtys;

	ListWdbeMVariable vars;
	WdbeMVariable* var = NULL;

	set<string> srefsSlvars;

	ListWdbeMFsmstate fsts;
	WdbeMFsmstate* fst = NULL;
	map<string,ubigint> refsFsts; // by sref
	map<ubigint,string> srefsFsts; // by ref

	ListWdbeAMFsmstateStep fass;
	WdbeAMFsmstateStep* fas = NULL;

	vector<WdbeMSignal*> sigreqs;
	vector<WdbeMSignal*> sigacks;
	vector<WdbeMSignal*> sigdnys;
	vector<WdbeMSignal*> sigdnes;

	ubigint refC;
	string Comment;

	uint fstCnum;

	string Prcsref;

	unsigned int major, minor;

	string altval;

	ubigint refFstSyncrst;

	bool gblrst;

	vector<string> conds, lastconds;
	vector<string> ips, lastips;

	unsigned int lvl, lastlvl, matchlvl;

	unsigned int il;

	bool fnxnewline;

	vector<string> ss;
	string s;
	size_t ptr;

	bool first, found;

	dbswdbe->tblwdbemmodule->loadRstBySup(mdl->ref, false, submdls);
	for (unsigned int i = 0; i < submdls.nodes.size(); i++) srefsSubmdls[submdls.nodes[i]->ref] = "my" + StrMod::cap(submdls.nodes[i]->sref);

	dbswdbe->tblwdbemport->loadRstByMdl(mdl->ref, false, prts);
	for (unsigned int i = 0; i < prts.nodes.size(); i++) {
		prt = prts.nodes[i];

		srefsPrts[prt->ref] = prt->sref;
		if (prt->srefWdbeKHdltype == "sl") srefsSlprtsigs.insert(prt->sref);
	};

	dbswdbe->tblwdbemsignal->loadRstByMdl(mdl->ref, false, sigs);
	for (unsigned int i = 0; i < sigs.nodes.size(); i++) {
		sig = sigs.nodes[i];

		if (sig->ixVBasetype == VecWdbeVMSignalBasetype::PSB) {
			for (auto it = srefsPrts.begin(); it != srefsPrts.end(); it++) {
				if (it->second == sig->sref) {
					sig->sref += "_psb";
					break;
				};
			};

		} else if (sig->drvRefWdbeMPort != 0) {
			auto it = srefsPrts.find(sig->drvRefWdbeMPort);
			if (it != srefsPrts.end()) if (it->second == sig->sref) sig->sref += "_sig";
		};
			
		srefsSigs.insert(sig->sref); // including suffix
		if (sig->srefWdbeKHdltype == "sl") srefsSlprtsigs.insert(sig->sref);
	};

	dbswdbe->tblwdbemprocess->loadRstByMdl(mdl->ref, false, prcs);
	for (unsigned int i = 0; i < prcs.nodes.size(); i++) {
		prc = prcs.nodes[i];

		srefsPrcs[prc->ref] = prc->sref;

		if (srefsSigs.find(prc->clkSrefWdbeMSignal + "_sig") != srefsSigs.end()) prc->clkSrefWdbeMSignal += "_sig";
		if (srefsSigs.find(prc->asrSrefWdbeMSignal + "_sig") != srefsSigs.end()) prc->asrSrefWdbeMSignal += "_sig";
	};

	// ---- signals

	// --- sigs.gblconst
	outfile << "-- IP sigs.gblconst --- IBEGIN" << endl;
	refC = 0;
	first = true;

	for (unsigned int i = 0; i < sigs.nodes.size(); i++) {
		sig = sigs.nodes[i];

		if ((sig->mgeIxVTbl == VecWdbeVMSignalMgeTbl::VOID) && sig->Const) {
			if (first) first = false;
			else if (sig->refWdbeCSignal != refC) outfile << endl;

			outfile << "\tconstant " << sig->sref << ": " << getVarStr(sig) << ";";
			if (sig->Comment != "") outfile << " -- " << sig->Comment;
			outfile << endl;

			refC = sig->refWdbeCSignal;

			refsSigs.insert(sig->ref);
		};
	};
	outfile << "-- IP sigs.gblconst --- IEND" << endl;

	for (unsigned int i = 0; i < prcs.nodes.size(); i++) {
		prc = prcs.nodes[i];
		Prcsref = StrMod::cap(prc->sref);

		if (prc->refWdbeMFsm != 0) {
			dbswdbe->tblwdbemfsmstate->loadRstByFsm(prc->refWdbeMFsm, false, fsts);

			// --- sigs.xxxx.fsm
			outfile << "-- IP sigs." << prc->sref << ".fsm --- IBEGIN" << endl;
			if (fsts.nodes.size() > 0) {
				outfile << "\ttype state" << Prcsref << "_t is (";

				for (unsigned int j = 0; j < fsts.nodes.size(); j++) {
					fst = fsts.nodes[j];

					if ((j == 0) || (fstCnum == 5) || (fst->refWdbeCFsmstate == 0)) fstCnum = 0;
					else if (fst->refWdbeCFsmstate != fsts.nodes[j-1]->refWdbeCFsmstate) fstCnum = 0;
					else fstCnum++;

					if (fstCnum == 0) outfile << endl << "\t\t";
					else outfile << " ";
					
					outfile << "state" << Prcsref << StrMod::cap(fst->sref);
					if ((j+1) != fsts.nodes.size()) outfile << ",";
				};

				outfile << endl;
				outfile << "\t);" << endl;
				outfile << "\tsignal state" << Prcsref << ": state" << Prcsref << "_t := state" << Prcsref << StrMod::cap(fsts.nodes[0]->sref) << ";" << endl;
				outfile << endl;
			};
			outfile << "-- IP sigs." << prc->sref << ".fsm --- IEND" << endl;
		};

		outfile << "-- IP sigs." << prc->sref << " --- IBEGIN" << endl;
		refC = 0;
		first = true;

		// --- sigs.xxxx (process)
		srefsHtys.clear();
		refsHtys.clear();

		dbswdbe->tblwdbeavkeylistkey->loadRstByKlsMtbUrf(VecWdbeVKeylist::KLSTWDBEKHDLTYPE, VecWdbeVMaintable::TBLWDBEMPROCESS, prc->ref, false, klsAkeys);
		for (unsigned int j = 0; j < klsAkeys.nodes.size(); j++) srefsHtys[klsAkeys.nodes[j]->sref] = klsAkeys.nodes[j];

		for (unsigned int j = 0; j < sigs.nodes.size(); j++) {
			sig = sigs.nodes[j];

			if (refsSigs.find(sig->ref) == refsSigs.end()) if ((sig->ixVBasetype != VecWdbeVMSignalBasetype::HSHK) && (sig->mgeIxVTbl == VecWdbeVMSignalMgeTbl::PRC) && (sig->mgeUref == prc->ref)) {
				if (first) first = false;
				else if (sig->refWdbeCSignal != refC) outfile << endl;

				// process-specific types before first occurrence
				auto it = srefsHtys.find(sig->srefWdbeKHdltype);
				if (it != srefsHtys.end()) {
					klsAkey = it->second;

					if (refsHtys.find(klsAkey->ref) == refsHtys.end()) {
						outfile << "\ttype " << klsAkey->sref << " is " << klsAkey->Title << ";" << endl;
						refsHtys.insert(klsAkey->ref);
					};
				};

				if (sig->Const) outfile << "\tconstant ";
				else outfile << "\tsignal ";
				outfile << sig->sref;
				if ((sig->ixVBasetype == VecWdbeVMSignalBasetype::CLK) && (sig->drvRefWdbeMPort == 0)) outfile << ", " << sig->sref << "_sig";
				
				outfile << ": " << getVarStr(sig) << ";";
				if (sig->Comment != "") outfile << " -- " << sig->Comment;
				outfile << endl;

				refC = sig->refWdbeCSignal;

				refsSigs.insert(sig->ref);
			};
		};
		outfile << endl;

		for (unsigned int j = 0; j < klsAkeys.nodes.size(); j++) {
			klsAkey = klsAkeys.nodes[j];
			if (refsHtys.find(klsAkey->ref) == refsHtys.end()) outfile << "\ttype " << klsAkey->sref << " is " << klsAkey->Title << ";" << endl;
		};

		outfile << "-- IP sigs." << prc->sref << " --- IEND" << endl;
	};

	for (unsigned int i = 0; i < submdls.nodes.size(); i++) {
		submdl = submdls.nodes[i];

		outfile << "-- IP sigs.my" << StrMod::cap(submdl->sref) << " --- IBEGIN" << endl;
		refC = 0;
		first = true;

		// --- sigs.xxxx (sub-module)
		for (unsigned int j = 0; j < sigs.nodes.size(); j++) {
			sig = sigs.nodes[j];

			if (refsSigs.find(sig->ref) == refsSigs.end()) if ((sig->ixVBasetype != VecWdbeVMSignalBasetype::HSHK) && (sig->mgeIxVTbl == VecWdbeVMSignalMgeTbl::MDL) && (sig->mgeUref == submdl->ref)) {
				if (first) first = false;
				else if (sig->refWdbeCSignal != refC) outfile << endl;

				outfile << "\tsignal ";
				outfile << sig->sref;
				if ((sig->ixVBasetype == VecWdbeVMSignalBasetype::CLK) && (sig->drvRefWdbeMPort == 0)) outfile << ", " << sig->sref << "_sig";
				
				outfile << ": " << getVarStr(sig) << ";";
				if (sig->Comment != "") outfile << " -- " << sig->Comment;
				outfile << endl;

				refC = sig->refWdbeCSignal;

				refsSigs.insert(sig->ref);
			};
		};
		outfile << endl;
		outfile << "-- IP sigs.my" << StrMod::cap(submdl->sref) << " --- IEND" << endl;
	};

	// --- sigs.hshk
	found = false;
	for (unsigned int i = 0; i < sigs.nodes.size(); i++) {
		sig = sigs.nodes[i];

		if (sig->ixVBasetype == VecWdbeVMSignalBasetype::HSHK) {
			found = true;
			break;
		};
	};

	if (found) {
		outfile << "-- IP sigs.hshk --- IBEGIN" << endl;
		for (unsigned int i = 0; i < sigs.nodes.size(); i++) {
			sig = sigs.nodes[i];

			if (sig->ixVBasetype == VecWdbeVMSignalBasetype::HSHK) if (refsSigs.find(sig->ref) == refsSigs.end()) if (sig->sref.find("req") == 0) {
				sigreqs.clear();
				sigacks.clear();
				sigdnys.clear();
				sigdnes.clear();

				sigreqs.push_back(sig);
				
				if (sig->refWdbeCSignal != 0) {
					for (unsigned int j = 0; j < sigs.nodes.size(); j++) {
						if (i != j) {
							sig2 = sigs.nodes[j];

							if ((sig2->ixVBasetype == VecWdbeVMSignalBasetype::HSHK) && (sig2->refWdbeCSignal == sig->refWdbeCSignal)) {
								if (sig2->sref.find("req") == 0) sigreqs.push_back(sig2);
								else if (sig2->sref.find("ack") == 0) sigacks.push_back(sig2);
								else if (sig2->sref.find("dny") == 0) sigdnys.push_back(sig2);
								else if (sig2->sref.find("dne") == 0) sigdnes.push_back(sig2);
							};
						};
					};
				};

				if (sigreqs.size() == 1) {
					sig = sigreqs[0];

					if (sig->mgeIxVTbl == VecWdbeVMSignalMgeTbl::MDL) outfile << "\t-- " << srefsSubmdls[sig->mgeUref];
					else if (sig->mgeIxVTbl == VecWdbeVMSignalMgeTbl::PRC) outfile << "\t-- " << srefsPrcs[sig->mgeUref];

				} else outfile << "\t-- (many)";
				
				outfile << " to ";

				sig = NULL;

				if (sigacks.size() == 1) sig = sigacks[0];
				else if (sigdnes.size() == 1) sig = sigdnes[0];

				if (sig) {
					if (sig->mgeIxVTbl == VecWdbeVMSignalMgeTbl::MDL) outfile << srefsSubmdls[sig->mgeUref];
					else if (sig->mgeIxVTbl == VecWdbeVMSignalMgeTbl::PRC) outfile << srefsPrcs[sig->mgeUref];
				} else outfile << "(many)";

				outfile << endl;

				for (unsigned int j = 0; j < sigreqs.size();j++) {
					sig = sigreqs[j];

					outfile << "\tsignal " << sig->sref << ": " << getVarStr(sig) << ";";
					if (sig->Comment != "") outfile << " -- " << sig->Comment;
					outfile << endl;

					refsSigs.insert(sig->ref);
				};
				for (unsigned int j = 0; j < sigacks.size();j++) {
					sig = sigacks[j];

					outfile << "\tsignal " << sig->sref << ": " << getVarStr(sig) << ";";
					if (sig->Comment != "") outfile << " -- " << sig->Comment;
					outfile << endl;

					refsSigs.insert(sig->ref);
				};
				for (unsigned int j = 0; j < sigdnys.size();j++) {
					sig = sigdnys[j];

					outfile << "\tsignal " << sig->sref << ": " << getVarStr(sig) << ";";
					if (sig->Comment != "") outfile << " -- " << sig->Comment;
					outfile << endl;

					refsSigs.insert(sig->ref);
				};
				for (unsigned int j = 0; j < sigdnes.size();j++) {
					sig = sigdnes[j];

					outfile << "\tsignal " << sig->sref << ": " << getVarStr(sig) << ";";
					if (sig->Comment != "") outfile << " -- " << sig->Comment;
					outfile << endl;

					refsSigs.insert(sig->ref);
				};

				outfile << endl;
			};
		};
		outfile << "-- IP sigs.hshk --- IEND" << endl;
	};

	// --- sigs.oth
	outfile << "-- IP sigs.oth --- IBEGIN" << endl;
	refC = 0;
	first = true;

	for (unsigned int i = 0; i < sigs.nodes.size(); i++) {
		sig = sigs.nodes[i];

		if (refsSigs.find(sig->ref) == refsSigs.end()) {
			if (first) first = false;
			else if (sig->refWdbeCSignal != refC) outfile << endl;

			if (sig->Const) outfile << "\tconstant ";
			else outfile << "\tsignal ";
			outfile << sig->sref << ": " << getVarStr(sig) << ";";
			if (sig->Comment != "") outfile << " -- " << sig->Comment;
			outfile << endl;

			refC = sig->refWdbeCSignal;
		};
	};
	outfile << "-- IP sigs.oth --- IEND" << endl;

	// ---- implementation

	for (unsigned int i = 0; i < prcs.nodes.size(); i++) {
		prc = prcs.nodes[i];
		Prcsref = StrMod::cap(prc->sref);

		srefsSlvars.clear();

		dbswdbe->tblwdbemvariable->loadRstByPrc(prc->ref, false, vars);
		for (unsigned int j = 0; j < vars.nodes.size(); j++) {
			var = vars.nodes[j];
			if (var->srefWdbeKHdltype == "sl") srefsSlvars.insert(var->sref);
		};

		dbswdbe->tblwdbemfsmstate->loadRstByFsm(prc->refWdbeMFsm, false, fsts);

		refsFsts.clear();
		srefsFsts.clear();
		for (unsigned int j = 0; j < fsts.nodes.size(); j++) {
			refsFsts[fsts.nodes[j]->sref] = fsts.nodes[j]->ref;
			srefsFsts[fsts.nodes[j]->ref] = fsts.nodes[j]->sref;
		};

		// --- impl.xxxx.wiring
		outfile << "-- IP impl." << prc->sref << ".wiring --- IBEGIN" << endl;
		outfile << "\t-- IP impl." << prc->sref << ".wiring --- BEGIN" << endl;
		refC = 0;
		first = true;

		for (unsigned int j = 0; j < sigs.nodes.size(); j++) {
			sig = sigs.nodes[j];

			if ((sig->mgeIxVTbl == VecWdbeVMSignalMgeTbl::PRC) && (sig->mgeUref == prc->ref)) {
				if ((sig->Comb != "") || (sig->drvRefWdbeMPort != 0)) {
					if (first) first = false;
					else if (sig->refWdbeCSignal != refC) outfile << endl;

					if (sig->ixVBasetype == VecWdbeVMSignalBasetype::IOPRT) {
						if ((sig->Comb != "") && ((sig->srefWdbeKHdltype == "sl") || (sig->srefWdbeKHdltype == "slvup") || (sig->srefWdbeKHdltype == "slvdn"))) {
							outfile << "\t" << srefsPrts[sig->drvRefWdbeMPort] << " <= " << sig->sref << " when " << expandCond(sig->Comb, Prcsref, srefsSlprtsigs, srefsSlvars, 80, 4) << " else ";
							if (sig->srefWdbeKHdltype == "sl") outfile << "'Z'";
							else outfile << valToSlv("Z", sig->Width, false, true);
							outfile << ";" << endl;

						} else {
							outfile << "\t" << srefsPrts[sig->drvRefWdbeMPort] << " <= " << sig->sref << ";" << endl;
						};

					} else {
						if (sig->Comb != "") {
							outfile << "\t" << sig->sref << " <= ";

							if (sig->Defon) outfile << getValStr(sig, false, sig->Offval);
							else outfile << getValStr(sig, false, sig->Onval);

							outfile << " when " << expandCond(sig->Comb, Prcsref, srefsSlprtsigs, srefsSlvars, 80, 4) << " else " << getValStr(sig) << ";" << endl;
						};
						
						if (sig->drvRefWdbeMPort != 0) outfile << "\t" << srefsPrts[sig->drvRefWdbeMPort] << " <= " << sig->sref << ";" << endl;
					};

					refC = sig->refWdbeCSignal;
				};
			};
		};

		// stateXxxx_dbg ...
		s = "state" + Prcsref + "_dbg";

		found = false;

		for (unsigned int j = 0; j < prts.nodes.size(); j++) {
			prt = prts.nodes[j];

			if ((prt->mdlIxVCat == VecWdbeVMPortMdlCat::DBG) && (prt->sref == s)) {
				found = true;
				break;
			};
		};

		if (found && (fsts.nodes.size() > 0) ) {
			if (!first) outfile << endl;

			major = 0;
			minor = 0;

			outfile << "\tstate" << Prcsref << "_dbg <= ";

			for (unsigned int i = 0; i < fsts.nodes.size(); i++) {
				fst = fsts.nodes[i];

				if (i != 0) {
					if ((fst->refWdbeCFsmstate == 0) || (fst->refWdbeCFsmstate != fsts.nodes[i-1]->refWdbeCFsmstate)) {
						major++;
						minor = 0;

					} else {
						minor++;

						if (minor == 16) {
							major++;
							minor = 0;
						};
					};

					if (major == 16) major = 0;
				};

				if (i != 0) outfile << "\t\t\t\telse ";
				outfile << "x\"" << Wdbe::binToHex(16*major+minor) << "\" when state" << Prcsref << "=state" << Prcsref << StrMod::cap(fst->sref) << endl;
			};

			outfile << "\t\t\t\telse (others => '1');" << endl;
		};

		outfile << "\t-- IP impl." << prc->sref << ".wiring --- END" << endl;
		outfile << "-- IP impl." << prc->sref << ".wiring --- IEND" << endl;

		// --- impl.xxxx.rising
		outfile << "-- IP impl." << prc->sref << ".rising --- IBEGIN" << endl;
		outfile << "\t-- IP impl." << prc->sref << ".rising --- BEGIN" << endl;
		if (prc->clkSrefWdbeMSignal != "") {
			outfile << "\tprocess (";
			if (prc->asrSrefWdbeMSignal != "") outfile << prc->asrSrefWdbeMSignal << ", ";
			outfile << prc->clkSrefWdbeMSignal;
			if (prc->refWdbeMFsm != 0) outfile << ", state" << Prcsref;
			outfile << ")" << endl;

			outfile << "\t\t-- IP impl." << prc->sref << ".vars --- BEGIN" << endl;
			refC = 0;
			first = true;

			for (unsigned int j = 0; j < vars.nodes.size(); j++) {
				var = vars.nodes[j];

				if (!var->Falling) {
					if (first) first = false;
					else if (var->refWdbeCVariable != refC) outfile << endl;

					if (var->Const) outfile << "\t\tconstant ";
					else outfile << "\t\tvariable ";
					outfile << var->sref << ": " << getVarStr(var) << ";";
					if (var->Comment != "") outfile << " -- " << var->Comment;
					outfile << endl;

					refC = var->refWdbeCVariable;
				};
			};
			outfile << "\t\t-- IP impl." << prc->sref << ".vars --- END" << endl;
			outfile << endl;

			outfile << "\tbegin" << endl;

			outfile << "\t\t";

			if (prc->asrSrefWdbeMSignal != "") {
				outfile << "if " << prc->asrSrefWdbeMSignal << "='1' then" << endl;

				outfile << "\t\t\t-- IP impl." << prc->sref << ".asyncrst --- BEGIN" << endl;
				if (fsts.nodes.size() > 0) outfile << "\t\t\tstate" << Prcsref << " <= state" << Prcsref << StrMod::cap(fsts.nodes[0]->sref) << ";" << endl;
				writeMdlVhd_reset(outfile, prc->ref, sigs, vars, false, 3);
				outfile << "\t\t\t-- IP impl." << prc->sref << ".asyncrst --- END" << endl;

				outfile << endl;
				outfile << endl << "\t\tels";
			};

			outfile << "if rising_edge(" << prc->clkSrefWdbeMSignal << ") then" << endl;

			if (prc->Extip) {
				outfile << "\t\t-- IP impl." << prc->sref << ".ext --- INSERT" << endl;
				outfile << endl;

				first = false;
			};

			first = true;

			refFstSyncrst = 0;

			if (prc->Syncrst != "") {
				ptr = prc->Syncrst.find("state(");
				if (ptr != string::npos) {
					s = prc->Syncrst.substr(ptr+6);

					ptr = s.find(')');
					if (ptr != string::npos) s = s.substr(0, ptr);

					auto it = refsFsts.find(s);
					if (it != refsFsts.end()) refFstSyncrst = it->second;
				};

				if (refFstSyncrst == 0) {
					outfile << "\t\t\tif " << expandCond(prc->Syncrst, Prcsref, srefsSlprtsigs, srefsSlvars, 0, 0) << " then" << endl;
					outfile << "\t\t\t\t-- IP impl." << prc->sref << ".syncrst --- BEGIN" << endl;
					writeMdlVhd_reset(outfile, prc->ref, sigs, vars, true, 4);

					if (fsts.nodes.size() > 0) {
						outfile << endl;
						outfile << "\t\t\t\tstate" << Prcsref << " <= state" << Prcsref << StrMod::cap(fsts.nodes[0]->sref) << ";" << endl;
					};
					outfile << "\t\t\t\t-- IP impl." << prc->sref << ".syncrst --- END" << endl;
					outfile << endl;

					first = false;
				};
			};

			conds.resize(4); ips.resize(4);

			for (unsigned int j = 0; j < fsts.nodes.size(); j++) {
				fst = fsts.nodes[j];

				if (first) first = false;
				else outfile << endl;

				outfile << "\t\t\t";
				if ((j != 0) || ((j == 0) && (prc->Syncrst != "") && (refFstSyncrst == 0))) outfile << "els";

				if (fst->ref == refFstSyncrst) outfile << "if " << expandCond(prc->Syncrst, Prcsref, srefsSlprtsigs, srefsSlvars, 0, 0) << " then" << endl;
				else outfile << "if state" << Prcsref << "=state" << Prcsref << StrMod::cap(fst->sref) << " then" << endl;

				// ev. TBD: add sl prts & sigs that are '1' (or '0') based on this state

				gblrst = false;

				dbswdbe->tblwdbeamfsmstatestep->loadRstByFst(fst->ref, false, fass);

				if (fst->ref == refFstSyncrst) {
					gblrst = true;

					for (unsigned int k = 0; k < fass.nodes.size(); k++) {
						fas = fass.nodes[k];

						if ((fas->Ip1 == "syncrst") || (fas->Ip2 == "syncrst") || (fas->Ip3 == "syncrst")) {
							gblrst = false;
							break;
						};
					};

					if (gblrst) {
						outfile << "\t\t\t\t-- IP impl." << prc->sref << ".syncrst --- BEGIN" << endl;
						writeMdlVhd_reset(outfile, prc->ref, sigs, vars, true, 4);

						if ((fass.nodes.size() == 0) && (fsts.nodes.size() > 1)) {
							outfile << endl;
							outfile << "\t\t\t\tstate" << Prcsref << " <= state" << Prcsref << StrMod::cap(fsts.nodes[1]->sref) << ";" << endl;
						};
						outfile << "\t\t\t\t-- IP impl." << prc->sref << ".syncrst --- END" << endl;
						outfile << endl;
					};
				};

				if (fass.nodes.size() == 0) {
					if (fst->ref != refFstSyncrst) outfile << "\t\t\t\t-- IP impl." << prc->sref << "." << fst->sref << " --- INSERT" << endl;

				} else {
					if (fst->Extip) {
						outfile << "\t\t\t\t-- IP impl." << prc->sref << "." << fst->sref << ".ext --- INSERT" << endl;
						outfile << endl;
					};

					lastconds.clear();
					lastips.clear();
					lastconds.resize(3); lastips.resize(3);

					lastlvl = 0;

					fnxnewline = false;

					for (unsigned int k = 0; k < fass.nodes.size(); k++) {
						fas = fass.nodes[k];

						conds[0] = fas->Cond1; ips[0] = fas->Ip1;
						conds[1] = fas->Cond2; ips[1] = fas->Ip2;
						conds[2] = fas->Cond3; ips[2] = fas->Ip3;
						conds[3] = fas->Cond4; ips[3] = fas->Ip4;

						lvl = 0;
						for (unsigned int l = 0; l < 4;l++) {
							if (conds[l] != "") lvl++;
							else break;
						};

						for (matchlvl = 0; matchlvl < lvl; matchlvl++) if ((lastconds[matchlvl] != conds[matchlvl]) || (lastips[matchlvl] != lastips[matchlvl])) break;

						// end if's
						if (lastlvl > 0) for (unsigned int l = lastlvl - 1; l > matchlvl; l--) outfile << string(4+l, '\t') << "end if;" << endl;

						// if's / elsif's / else's
						for (unsigned int l = matchlvl; l <= lvl; l++) {
							if (l < 4) if (conds[l] != "") {
								if ( ((lastlvl > matchlvl) && (l == matchlvl)) || fnxnewline) outfile << endl; // new line following end if or next state with IP

								outfile << string(4+l, '\t');
								if (conds[l] == "else") {
									outfile << "else" << endl;
								} else {
									if ((k > 0) && (l == matchlvl)) outfile << "elsif";
									else outfile << "if";
									outfile << " " << expandCond(conds[l], Prcsref, srefsSlprtsigs, srefsSlvars, 0, 0) << " then" << endl;
								};
							};

							if (l < 4) if (ips[l] != "") {
								if (lvl > 0) il = 4+l+1;
								else il = 4;

								if ((ips[l] == "syncrst") && !gblrst) {
									outfile << string(il, '\t') << "-- IP impl." << prc->sref << ".syncrst --- BEGIN" << endl;
									writeMdlVhd_reset(outfile, prc->ref, sigs, vars, true, il);
									outfile << string(il, '\t') << "-- IP impl." << prc->sref << ".syncrst --- END" << endl;
									outfile << endl;

								} else if (ips[l] != "syncrst") {
									outfile << string(il, '\t') << "-- IP impl." << prc->sref << "." << fst->sref;
									if (ips[l] != fst->sref) outfile << "." << ips[l];
									outfile << " --- INSERT" << endl;
									outfile << endl;
								};
							};

							fnxnewline = false;

							if (l == lvl) {
								outfile << string(4+l, '\t') << "state" << Prcsref << " <= state" << Prcsref << StrMod::cap(srefsFsts[fas->fnxRefWdbeMFsmstate]) << ";" << endl;
								if (lvl > 0) fnxnewline = (ips[lvl-1] != "");
							};
						};

						lastconds = conds;
						lastips = ips;

						lastlvl = lvl;
					};

					// remaining end if's
					for (unsigned int l = lvl; l > 0; l--) outfile << string(4+l-1, '\t') << "end if;" << endl;
				};
			};

			if (first) outfile << "\t\t\t-- IP impl." << prc->sref << " --- INSERT" << endl;
			else outfile << "\t\t\tend if;" << endl;

			outfile << "\t\tend if;" << endl;
			outfile << "\tend process;" << endl;
		};
		outfile << "\t-- IP impl." << prc->sref << ".rising --- END" << endl;
		outfile << "-- IP impl." << prc->sref << ".rising --- IEND" << endl;

		if (prc->Falling) {
			// --- impl.xxxx.falling
			outfile << "-- IP impl." << prc->sref << ".falling --- IBEGIN" << endl;
			outfile << "-- IP impl." << prc->sref << ".falling --- BEGIN" << endl;
			if (prc->clkSrefWdbeMSignal != "") {
				outfile << "\tprocess (" << prc->clkSrefWdbeMSignal << ")" << endl;

				outfile << "\t\t-- IP impl." << prc->sref << ".falling.vars --- BEGIN" << endl;
				refC = 0;
				first = true;

				for (unsigned int j = 0; j < vars.nodes.size(); j++) {
					var = vars.nodes[j];

					if (var->Falling) {
						if (first) first = false;
						else if (var->refWdbeCVariable != refC) outfile << endl;

						if (var->Const) outfile << "\t\tconstant ";
						else outfile << "\t\tvariable ";
						outfile << var->sref << ": " << getVarStr(var) << ";" << endl;

						refC = var->refWdbeCVariable;
					};
				};
				outfile << "\t\t-- IP impl." << prc->sref << ".falling.vars --- END" << endl;

				outfile << "\tbegin" << endl;

				outfile << "\t\tif falling_edge(" << prc->clkSrefWdbeMSignal << ") then" << endl;
				outfile << "\t\tend if;" << endl;

				outfile << "\tend process;" << endl;
			};
			outfile << "-- IP impl." << prc->sref << ".falling --- END" << endl;
			outfile << "-- IP impl." << prc->sref << ".falling --- IEND" << endl;
		};
	};
	
	// --- impl.oth
	outfile << "-- IP impl.oth --- IBEGIN" << endl;
	for (unsigned int i = 0; i < sigs.nodes.size(); i++) {
		sig = sigs.nodes[i];

		if ((sig->mgeIxVTbl == VecWdbeVMSignalMgeTbl::VOID) && (sig->drvRefWdbeMPort != 0)) {
			// MISSING: set remaining bits to zero
			outfile << "\t" << srefsPrts[sig->drvRefWdbeMPort] << " <= " << sig->sref << ";" << endl;
		};
	};
	outfile << "-- IP impl.oth --- IEND" << endl;
};

void WdbeWrfpgaMdlfine::writeMdlVhd_reset(
			fstream& outfile
			, const ubigint refWdbeMProcess
			, ListWdbeMSignal& sigs
			, ListWdbeMVariable& vars
			, const bool syncNotAsync
			, const unsigned int il
		) {
	WdbeMSignal* sig = NULL;
	WdbeMVariable* var = NULL;

	bool first = true;

	for (unsigned int i = 0; i < sigs.nodes.size(); i++) {
		sig = sigs.nodes[i];

		if ((sig->mgeIxVTbl == VecWdbeVMSignalMgeTbl::PRC) && (sig->mgeUref == refWdbeMProcess) && !sig->Const && (sig->Comb == "") && ((!sig->Defon && (sig->Offval != "")) || (sig->Defon && (sig->Onval != "")))) {
			first = false;

			outfile << string(il, '\t') << sig->sref << " <= ";
			if (!sig->Defon) outfile << getValStr(sig, true) << ";" << endl;
			else outfile << getValStr(sig, true, sig->Onval) << ";" << endl;
		};
	};

	if (syncNotAsync) {
		if (!first) outfile << endl;

		for (unsigned int i = 0; i < vars.nodes.size(); i++) {
			var = vars.nodes[i];

			if (!var->Const && ((!var->Defon && (var->Offval != "")) || (var->Defon && (var->Onval != ""))) ) {
				outfile << string(il, '\t') << var->sref << " := ";
				if (!var->Defon) outfile << getValStr(var, true) << ";" << endl;
				else outfile << getValStr(var, true, var->Onval) << ";" << endl;
			};
		};
	};
};

string WdbeWrfpgaMdlfine::expandCond(
			const string& Cond
			, const string& Prcsref
			, set<string>& srefsSlprtsigs
			, set<string>& srefsSlvars
			, const unsigned int maxlen
			, const unsigned int indent
		) {
	string sin = Cond;
	string sout;

	bool valid;
	bool addbraket;

	unsigned int bracnt;

	const unsigned int BRA = 1;
	const unsigned int KET = 2;
	const unsigned int CMPOP = 3;
	const unsigned int XNOT = 4;
	const unsigned int NOT = 5;
	const unsigned int AND = 6;
	const unsigned int OR = 7;
	const unsigned int STATE = 8;
	const unsigned int PRTSIGVAR = 9;
	const unsigned int SLPRTSIGVAR = 10;
	const unsigned int VAL = 11;
	const unsigned int STLIST = 12;

	vector<unsigned int> tkns;
	vector<unsigned int> ptrsTkns;

	unsigned int ptr;

	unsigned int cnt;

	vector<string> ss;
	string s;
	char c;

	bool found;

	// tokenize
	ptr = 0;

	while (ptr < sin.length()) {
		c = sin[ptr];

		if (c == '(') {
			tkns.push_back(BRA); ptrsTkns.push_back(ptr);
			ptr++;
		} else if (c == ')') {
			tkns.push_back(KET); ptrsTkns.push_back(ptr);
			ptr++;
		} else if (c == '=') {
			tkns.push_back(CMPOP); ptrsTkns.push_back(ptr);
			ptr++;
		} else if (sin.substr(ptr).find("/=") == 0) {
			tkns.push_back(CMPOP); ptrsTkns.push_back(ptr);
			ptr += 2;
		} else if (sin.substr(ptr).find("<=") == 0) {
			tkns.push_back(CMPOP); ptrsTkns.push_back(ptr);
			ptr += 2;
		} else if (sin.substr(ptr).find(">=") == 0) {
			tkns.push_back(CMPOP); ptrsTkns.push_back(ptr);
			ptr += 2;
		} else if (c == '<') {
			tkns.push_back(CMPOP); ptrsTkns.push_back(ptr);
			ptr++;
		} else if (c == '>') {
			tkns.push_back(CMPOP); ptrsTkns.push_back(ptr);
			ptr++;
		} else if (c == '!') {
			tkns.push_back(XNOT); ptrsTkns.push_back(ptr);
			ptr++;
		} else if (sin.substr(ptr).find("not ") == 0) {
			tkns.push_back(NOT); ptrsTkns.push_back(ptr);
			ptr += 4;
		} else if (sin.substr(ptr).find(" and ") == 0) {
			tkns.push_back(AND); ptrsTkns.push_back(ptr);
			ptr += 5;
		} else if (sin.substr(ptr).find(" or ") == 0) {
			tkns.push_back(OR); ptrsTkns.push_back(ptr);
			ptr += 4;
		} else if (sin.substr(ptr).find("state(") == 0) {
			tkns.push_back(STATE); ptrsTkns.push_back(ptr);
			ptr += 5; // not 6

		} else if (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')) || ((c >= '0') && (c <= '9')) || (c == '\'') || (c == '\"')) {
			// port, signal, variable, state list or value ; examples:
			// pixbuf(7 downto 3), cmdbuf(ixCmdbufInvCommand), to_integer(unsigned(colsqr)), to_integer(unsigned(d(11 downto 8))), std_logic_vector(to_unsigned(maxlenInv, 6))
			found = false;

			if (tkns.size() >= 2) {
				if ((tkns[tkns.size()-2] == PRTSIGVAR) && (tkns[tkns.size()-1] == CMPOP)) {
					tkns.push_back(VAL); ptrsTkns.push_back(ptr);
					found = true;
				} else if ((tkns[tkns.size()-2] == STATE) && (tkns[tkns.size()-1] == BRA)) {
					tkns.push_back(STLIST); ptrsTkns.push_back(ptr);
					found = true;
				};
			};

			if (!found && (tkns.size() >= 3))
				if ((tkns[tkns.size()-3] == STATE) && (tkns[tkns.size()-2] == BRA) && (tkns[tkns.size()-1] == XNOT)) {
					tkns.push_back(STLIST); ptrsTkns.push_back(ptr);
					found = true;
				};

			if (!found) {
				tkns.push_back(PRTSIGVAR); ptrsTkns.push_back(ptr);
			};

			bracnt = 0;
			while ((c == '(') || ((bracnt > 0) && (c == ')')) || (sin.substr(ptr).find(" to ") == 0) || (sin.substr(ptr).find(" downto ") == 0) || (sin.substr(ptr).find(", ") == 0) || ((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')) || ((c >= '0') && (c <= '9')) || (c == '.') || (c == ';') || (c == '_') || (c == '\'') || (c == '\"') || (c == '+') || (c == '-') || (c == '*') || (c == '/')) {

				if (c == '(') {
					bracnt++;
				} else if (c == ')') {
					bracnt--;
				} else if (sin.substr(ptr).find(" to ") == 0) {
					ptr += 3; // not 4
				} else if (sin.substr(ptr).find(" downto ") == 0) {
					ptr += 7; // not 8
				} else if (sin.substr(ptr).find(", ") == 0) {
					ptr += 1; // not 2
				};

				ptr++;
				if (ptr == sin.length()) break;
				c = sin[ptr];
			};

		} else {
			sin = sin.substr(0, ptr) + sin.substr(ptr+1);
		};
	};

	// identify known SLPRTSIGVARS
	for (unsigned int i = 0; i < tkns.size();i++) if (tkns[i] == PRTSIGVAR) {
		s = expandCond_getTknstr(sin, tkns, ptrsTkns, i);

		if (srefsSlprtsigs.find(s) != srefsSlprtsigs.end()) tkns[i] = SLPRTSIGVAR;
		else if (srefsSlvars.find(s) != srefsSlvars.end()) tkns[i] = SLPRTSIGVAR;
	};

	// validate / check requirement for external brackets

	// BRA + KET
	// PRTSIGVAR: PRTSIGVAR + CMPOP + VAL
	// STATE + BRA [+ XNOT] + STLIST + KET

	valid = true;
	addbraket = false;

	bracnt = 0;

	for (unsigned int i = 0; i < tkns.size();i++) {
		if (tkns[i] == BRA) {
			bracnt++;

		} else if (tkns[i] == KET) {
			bracnt--;
			if (bracnt < 0) valid = false;

		} else if (tkns[i] == PRTSIGVAR) {
			if ((i+2) < tkns.size()) {
				if (! ((tkns[i+1] == CMPOP) && (tkns[i+2] == VAL))) valid = false;
			} else valid = false;

		} else if (tkns[i] == STATE) {
			if ((i+3) >= tkns.size()) valid = false;
			else {
				if (tkns[i+2] == XNOT) {
					if ((i+4) >= tkns.size()) valid = false;
					else if (! ((tkns[i+1] == BRA) && (tkns[i+3] == STLIST) && (tkns[i+4] == KET))) valid = false;
				} else {
					if (! ((tkns[i+1] == BRA) && (tkns[i+2] == STLIST) && (tkns[i+3] == KET))) valid = false;
				};
			};
		};

		if ((bracnt == 0) && ((i+1) < tkns.size())) addbraket = true;

		if (!valid) break;
	};

	if (valid && (bracnt > 0)) valid = false;

	if (addbraket) {
		// require >1 of PRTSIGVAR / SLPRTSIGVAR / STLIST
		cnt = 0;
		for (unsigned int i = 0; i < tkns.size(); i++) if ((tkns[i] == PRTSIGVAR) || (tkns[i] == SLPRTSIGVAR) || (tkns[i] == STLIST)) cnt++;
		if (cnt <= 1) addbraket = false;
	};

	if (valid) {
		// compose output string
		ptr = 0;

		for (unsigned int i = 0; i < tkns.size();i++) {
			if (tkns[i] == BRA) {
				sout += "(";
			} else if (tkns[i] == KET) {
				sout += ")";

			} else if (tkns[i] == CMPOP) {
				sout += expandCond_getTknstr(sin, tkns, ptrsTkns, i);

			} else if (tkns[i] == XNOT) {
				// handled in STATE/SLPRTSIGVAR

			} else if (tkns[i] == NOT) {
				expandCond_checkBreak(sout, ptr, maxlen, indent);
				sout += "not ";

			} else if (tkns[i] == AND) {
				expandCond_checkBreak(sout, ptr, maxlen, indent);
				sout += " and ";

			} else if (tkns[i] == OR) {
				expandCond_checkBreak(sout, ptr, maxlen, indent);
				sout += " or ";

			} else if (tkns[i] == STATE) {
				if (tkns[i+2] == XNOT) srefsFstsToVector(expandCond_getTknstr(sin, tkns, ptrsTkns, i+3), ss);
				else srefsFstsToVector(expandCond_getTknstr(sin, tkns, ptrsTkns, i+2), ss);

				if (ss.size() > 1) sout += "(";

				if (tkns[i+2] == XNOT) {
					for (unsigned int j = 0; j < ss.size();j++) {
						if (j != 0) {
							expandCond_checkBreak(sout, ptr, maxlen, indent);
							sout += " and ";
						};
						sout += "state" + Prcsref + "/=state" + Prcsref + StrMod::cap(ss[j]);
					};
					i++;
				} else {
					for (unsigned int j = 0; j < ss.size();j++) {
						if (j != 0) {
							expandCond_checkBreak(sout, ptr, maxlen, indent);
							sout += " or ";
						};
						sout += "state" + Prcsref + "=state" + Prcsref + StrMod::cap(ss[j]);
					};
				};

				if (ss.size() > 1) sout += ")";

				i += 3;

			} else if (tkns[i] == PRTSIGVAR) {
				sout += expandCond_getTknstr(sin, tkns, ptrsTkns, i);

			} else if (tkns[i] == SLPRTSIGVAR) {
				sout += expandCond_getTknstr(sin, tkns, ptrsTkns, i);

				found = false;
				if ((i+1) < tkns.size()) if (tkns[i+1] == CMPOP) found = true;

				if (!found) {
					if (i > 0) if (tkns[i-1] == XNOT) found = true;

					if (found) sout += "='0'";
					else sout += "='1'";
				};

			} else if (tkns[i] == VAL) {
				sout += expandCond_getTknstr(sin, tkns, ptrsTkns, i);
			} else if (tkns[i] == STLIST) {
				// handled in STATE
			};
		};

		if (addbraket) sout = "(" + sout + ")";
 	} else sout = sin;

	if (!valid) {
		cout << "tokenizing '" << sin << "'";

		for (unsigned int i = 0; i < tkns.size(); i++) cout << " (" << tkns[i] << "," << ptrsTkns[i] << ")";
		cout << endl;
		
		if (valid) cout << " ... successfully into '" << sout << "'" << endl;
		else cout << " ... unsucessfully into '" << sout << "'" << endl;
	};

	return sout;
};

string WdbeWrfpgaMdlfine::expandCond_getTknstr(
			const string& sin
			, vector<unsigned int>& tkns
			, vector<unsigned int>& ptrsTkns
			, const unsigned int ix
		) {
	unsigned int len;

	if ((ix+1) < tkns.size()) len = ptrsTkns[ix+1] - ptrsTkns[ix];
	else len = sin.length() - ptrsTkns[ix];

	return(sin.substr(ptrsTkns[ix], len));
};

void WdbeWrfpgaMdlfine::expandCond_checkBreak(
			string& sout
			, unsigned int& ptr
			, const unsigned int maxlen
			, const unsigned int indent
		) {
	if (maxlen == 0) return;

	if (sout.length() > (ptr+maxlen)) {
		sout += "\n" + string(indent, '\t');
		ptr = sout.length();
	};
};
// IP cust --- IEND
