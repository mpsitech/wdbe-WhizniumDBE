/**
	* \file WdbeWrfpgaMdlraw.cpp
	* Wdbe operation processor - write raw VHDL code (implementation)
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

#include "WdbeWrfpgaMdlraw.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeWrfpga;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeWrfpgaMdlraw
 ******************************************************************************/

DpchRetWdbe* WdbeWrfpgaMdlraw::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeWrfpgaMdlraw* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;
	string folder = dpchinv->folder;
	string Prjshort = dpchinv->Prjshort;
	string Untsref = dpchinv->Untsref;
	string srefKToolch = dpchinv->srefKToolch;

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
		writeMdlVhd(dbswdbe, outfile, Prjshort, Untsref, srefKToolch, mdl);
		outfile.close();

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WdbeWrfpgaMdlraw::writeMdlVhd(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, const string& Prjshort
			, const string& Untsref
			, const string& srefKToolch
			, WdbeMModule* mdl
		) {
	ubigint ref;

	ListWdbeMModule submdls;
	WdbeMModule* submdl = NULL;

	ListWdbeMGeneric gens;
	WdbeMGeneric* gen = NULL;
	
	ListWdbeMPort prts;
	map<ubigint,string> srefsPrts; // by ref
	WdbeMPort* prt = NULL;

	ListWdbeMSignal sigs;
	map<string,WdbeMSignal*> srefsSigs;
	WdbeMSignal* sig = NULL;

	ListWdbeMProcess prcs;
	WdbeMProcess* prc = NULL;

	ListWdbeMPort subprts;

	set<string> srefsLibmdls;
	map<string,string> srefsLibs;

	set<string> htys;

	set<string> libs;

	vector<uint> icsMdc;
	uint ixMdc;

	set<string> compsrefs;
	string compsref;

	ubigint refC;
	string Comment;

	string sref;
	bool hasrng;
	utinyint from, to;
	string ix;

	string Defval;

	string s;

	bool first, found;

	fillIcsMdc(icsMdc);

	dbswdbe->tblwdbemmodule->loadRstBySup(mdl->ref, false, submdls);

	dbswdbe->tblwdbemgeneric->loadRstByMdl(mdl->ref, false, gens);

	dbswdbe->tblwdbemport->loadRstByMdl(mdl->ref, false, prts);
	for (unsigned int i = 0; i < prts.nodes.size(); i++) srefsPrts[prts.nodes[i]->ref] = prts.nodes[i]->sref;

	dbswdbe->tblwdbemsignal->loadRstByRetReu(VecWdbeVMSignalRefTbl::MDL, mdl->ref, false, sigs);
	for (unsigned int i = 0; i < sigs.nodes.size(); i++) {
		sig = sigs.nodes[i];

		srefsSigs[sig->sref] = sig;

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
	};

	dbswdbe->tblwdbemprocess->loadRstByMdl(mdl->ref, false, prcs);
	for (unsigned int i = 0; i < prcs.nodes.size(); i++) {
		prc = prcs.nodes[i];

		auto it = srefsSigs.find(prc->clkSrefWdbeMSignal);
		if (it != srefsSigs.end()) prc->clkSrefWdbeMSignal = it->second->sref;

		it = srefsSigs.find(prc->asrSrefWdbeMSignal);
		if (it != srefsSigs.end()) prc->asrSrefWdbeMSignal = it->second->sref;
	};

	// --- libs
	outfile << "-- IP libs --- IBEGIN" << endl;

	if ((srefKToolch == "ise") || (srefKToolch == "vivado")) {
		for (unsigned int i = 0; i < submdls.nodes.size(); i++) {
			submdl = submdls.nodes[i];

			if (submdl->ixVBasetype == VecWdbeVMModuleBasetype::MNFPRIM) {
				outfile << "library unisim;" << endl;
				outfile << "use unisim.vcomponents.all;" << endl;
				outfile << endl;
				break;
			};
		};
	};

	outfile << "use work.Dbecore.all;" << endl;
	if ((mdl->ixVBasetype == VecWdbeVMModuleBasetype::HOSTIF) || (mdl->ixVBasetype == VecWdbeVMModuleBasetype::FWDCTR)) outfile << "use work." << Prjshort << ".all;" << endl;
	outfile << "use work." << Untsref << ".all;" << endl;

	// additional libraries due to specific HDL types of module template / module, ports of sub-modules or signals
	getHdltypeLibs(dbswdbe, mdl->hkUref, srefsLibmdls, srefsLibs);

	if (mdl->tplRefWdbeMModule != 0) if (dbswdbe->tblwdbemmodule->loadSrfByRef(mdl->tplRefWdbeMModule, s)) if (srefsLibmdls.find(s) != srefsLibmdls.end()) libs.insert(StrMod::cap(s) + "_lib");
	if (srefsLibmdls.find(mdl->sref) != srefsLibmdls.end()) libs.insert(StrMod::cap(mdl->sref) + "_lib");

	for (unsigned int i = 0; i < submdls.nodes.size(); i++) {
		submdl = submdls.nodes[i];

		dbswdbe->tblwdbemport->loadRstByMdl(submdl->ref, false, subprts);
		for (unsigned int j = 0; j < subprts.nodes.size(); j++) htys.insert(subprts.nodes[j]->srefWdbeKHdltype);
	};

	for (unsigned int i = 0; i < sigs.nodes.size(); i++) htys.insert(sigs.nodes[i]->srefWdbeKHdltype);

	for (auto it = htys.begin(); it != htys.end(); it++) {
		auto it2 = srefsLibs.find(*it);
		if (it2 != srefsLibs.end()) libs.insert(it2->second);
	};

	for (auto it = libs.begin(); it != libs.end(); it++) outfile << "use work." << (*it) << ".all;" << endl;
	outfile << "-- IP libs --- IEND" << endl;

	// --- entity
	outfile << "-- IP entity --- IBEGIN" << endl;

	if (gens.nodes.size() > 0) {
		outfile << "\tgeneric (";
		
		// loop properties: group by refC, EOL semicolon except last, EOL Comment (of previous gen), works if individual gen(s) is/are skipped
		refC = 0;
		Comment = "";
		first = true;

		for (unsigned int i = 0; i < gens.nodes.size(); i++) {
			gen = gens.nodes[i];

			if (first) {
				outfile << endl;
				first = false;
			} else {
				outfile << ";";
				if (Comment != "") {
					outfile << " -- " << Comment;
					Comment = "";
				};
				outfile << endl;
				if (gen->refWdbeCGeneric != refC) outfile << endl;
			};

			outfile << "\t\t" << gen->sref << ": " << getVarStr(gen);
			refC = gen->refWdbeCGeneric;
			Comment = gen->Comment;
		};
	
		if (Comment != "") outfile << " -- " << Comment;
		outfile << endl << "\t);" << endl;
	};

	outfile << "\tport (";

	refC = 0;
	Comment = "";
	first = true;

	for (unsigned int i = 0; i < icsMdc.size();i++) {
		ixMdc = icsMdc[i];

		for (unsigned int j = 0; j < prts.nodes.size(); j++) {
			prt = prts.nodes[j];

			if (prt->mdlIxVCat == ixMdc) {
				if (first) {
					outfile << endl;
					first = false;
				} else {
					outfile << ";";
					if (Comment != "") {
						outfile << " -- " << Comment;
						Comment = "";
					};
					outfile << endl;
					if (prt->refWdbeCPort != refC) outfile << endl;
				};

				outfile << "\t\t" << prt->sref << ": " << VecWdbeVMPortDir::getSref(prt->ixVDir) << " " << getVarStr(prt);
				refC = prt->refWdbeCPort;
				Comment = prt->Comment;
			};
		};
	};

	if (Comment != "") outfile << " -- " << Comment;
	outfile << endl << "\t);" << endl;

	outfile << "-- IP entity --- IEND" << endl;

	// --- comps
	outfile << "-- IP comps --- IBEGIN" << endl;
	for (unsigned int i = 0; i < submdls.nodes.size(); i++) {
		submdl = submdls.nodes[i];

		if ( !(((srefKToolch == "ise") || (srefKToolch == "vivado")) && (submdl->ixVBasetype == VecWdbeVMModuleBasetype::MNFPRIM)) ) {
			compsref = Wdbe::getCompsref(dbswdbe, submdl);

			if (compsrefs.find(compsref) == compsrefs.end()) {
				if (submdl->tplRefWdbeMModule == 0) ref = submdl->ref;
				else ref = submdl->tplRefWdbeMModule;

				outfile << "\tcomponent " << StrMod::cap(compsref) << " is" << endl;
				
				dbswdbe->tblwdbemgeneric->loadRstByMdl(ref, false, gens);

				if (gens.nodes.size() > 0) {
					outfile << "\t\tgeneric (";
					
					refC = 0;
					first = true;

					for (unsigned int i = 0; i < gens.nodes.size(); i++) {
						gen = gens.nodes[i];

						if (first) {
							outfile << endl;
							first = false;
						} else {
							outfile << ";" << endl;
							if (gen->refWdbeCGeneric != refC) outfile << endl;
						};

						outfile << "\t\t\t" << gen->sref << ": " << getVarStr(gen);
						refC = gen->refWdbeCGeneric;
					};

					outfile << endl << "\t\t);" << endl;
				};

				dbswdbe->tblwdbemport->loadRstByMdl(submdl->ref, false, prts);

				outfile << "\t\tport (";
				
				refC = 0;
				first = true;

				for (unsigned int j = 0; j < icsMdc.size();j++) {
					ixMdc = icsMdc[j];

					for (unsigned int k = 0; k < prts.nodes.size(); k++) {
						prt = prts.nodes[k];

						if (prt->mdlIxVCat == ixMdc) {
							if (first) {
								outfile << endl;
								first = false;
							} else {
								outfile << ";" << endl;
								if (prt->refWdbeCPort != refC) outfile << endl;
							};

							outfile << "\t\t\t" << prt->sref << ": " << VecWdbeVMPortDir::getSref(prt->ixVDir) << " " << getVarStr(prt);
							refC = prt->refWdbeCPort;
						};
					};
				};

				outfile << endl << "\t\t);" << endl;

				outfile << "\tend component;" << endl;
				outfile << endl;

				compsrefs.insert(compsref);
			};
		};
	};
	outfile << "-- IP comps --- IEND" << endl;

	// --- sigs
	outfile << "-- IP sigs --- IBEGIN" << endl;

	// -- by processes
	for (unsigned int i = 0; i < prcs.nodes.size(); i++) {
		prc = prcs.nodes[i];

		outfile << "\t---- " << prc->Comment << " (" << prc->sref << ")" << endl;

		if (prc->refWdbeMFsm != 0) {
			outfile << "\t-- IP sigs." << prc->sref << ".fsm --- INSERT" << endl;
			outfile << endl;
		};

		outfile << "\t-- IP sigs." << prc->sref << ".typspec --- INSERT" << endl;
		outfile << endl;

		outfile << "\t-- IP sigs." << prc->sref << ".tplspec --- INSERT" << endl;
		outfile << endl;

		outfile << "\t-- IP sigs." << prc->sref << " --- INSERT" << endl;
		outfile << endl;

		outfile << "\t-- IP sigs." << prc->sref << ".cust --- INSERT" << endl;
		outfile << endl;
	};

	// -- by sub-modules
	for (unsigned int i = 0; i < submdls.nodes.size(); i++) {
		submdl = submdls.nodes[i];

		found = false;
		for (unsigned int j = 0; j < sigs.nodes.size(); j++) {
			sig = sigs.nodes[j];

			if ((sig->ixVBasetype != VecWdbeVMSignalBasetype::HSHK) && (sig->mgeIxVTbl == VecWdbeVMSignalMgeTbl::MDL) && (sig->mgeUref == submdl->ref)) {
				found = true;
				break;
			};
		};

		if (found) {
			outfile << "\t---- my" << StrMod::cap(submdl->sref) << endl;

			outfile << "\t-- IP sigs.my" << StrMod::cap(submdl->sref) << " --- INSERT" << endl;
			outfile << endl;
		};
	};

	// -- handshake
	for (unsigned int i = 0; i < sigs.nodes.size(); i++) {
		sig = sigs.nodes[i];

		if (sig->ixVBasetype == VecWdbeVMSignalBasetype::HSHK) {
			outfile << "\t---- handshake" << endl;
			outfile << "\t-- IP sigs.hshk --- INSERT" << endl;
			outfile << endl;
			
			break;
		};
	};
	outfile << "-- IP sigs --- IEND" << endl;

	// --- subs
	outfile << "-- IP subs --- IBEGIN" << endl;

	for (unsigned int i = 0; i < submdls.nodes.size(); i++) {
		submdl = submdls.nodes[i];

		outfile << "\tmy" << StrMod::cap(submdl->sref) << " : " << StrMod::cap(Wdbe::getCompsref(dbswdbe, submdl)) << endl;

		dbswdbe->tblwdbemgeneric->loadRstByMdl(submdl->ref, false, gens);

		if (gens.nodes.size() > 0) {
			first = true;

			for (unsigned int j = 0; j < gens.nodes.size(); j++) {
				gen = gens.nodes[j];

				if ((gen->Defval != "") || (gen->srcSrefWdbeMGeneric != "")) {
					first = false;
					break;
				};
			};

			if (!first) {
				outfile << "\t\tgeneric map (";

				refC = 0;
				Comment = "";
				first = true;

				for (unsigned int j = 0; j < gens.nodes.size(); j++) {
					gen = gens.nodes[j];

					if ((gen->Defval != "") || (gen->srcSrefWdbeMGeneric != "")) {
						if (first) {
							outfile << endl;
							first = false;
						} else {
							outfile << ",";
							if (Comment != "") {
								outfile << " -- " << Comment;
								Comment = "";
							};
							outfile << endl;
							if (gen->refWdbeCGeneric != refC) outfile << endl;
						};

						outfile << "\t\t\t" << gen->sref << " => ";

						if (gen->srcSrefWdbeMGeneric != "") outfile << gen->srcSrefWdbeMGeneric;
						else if (gen->Defval != "") outfile << getValStr(gen, true);
						
						refC = gen->refWdbeCGeneric;
						Comment = gen->Comment;
					};
				};

				if (Comment != "") outfile << " -- " << Comment;
				outfile << endl << "\t\t)" << endl;
			};
		};

		dbswdbe->tblwdbemport->loadRstByMdl(submdl->ref, false, prts);

		outfile << "\t\tport map (";

		refC = 0;
		Comment = "";
		first = true;

		for (unsigned int j = 0; j < icsMdc.size();j++) {
			ixMdc = icsMdc[j];

			for (unsigned int k = 0; k < prts.nodes.size(); k++) {
				prt = prts.nodes[k];

				if (prt->mdlIxVCat == ixMdc) {
					if (first) {
						outfile << endl;
						first = false;
					} else {
						outfile << ",";
						if (Comment != "") {
							outfile << " -- " << Comment;
							Comment = "";
						};
						outfile << endl;
						if (prt->refWdbeCPort != refC) outfile << endl;
					};

					outfile << "\t\t\t" << prt->sref << " => ";

					if (prt->cprSrefWdbeMPort != "") {
						Wdbe::getRange(prt->cprSrefWdbeMPort, sref, hasrng, from, to, ix);
						outfile << sref;
						if (hasrng) {
							outfile << "(";
							if (prt->srefWdbeKHdltype == "sl") outfile << to_string((int) from);
							else if (prt->srefWdbeKHdltype == "slvup") outfile << to_string((int) from) << " to " << to_string((int) to);
							else if (prt->srefWdbeKHdltype == "slvdn") outfile << to_string((int) to) << " downto " << to_string((int) from);
							outfile << ")";
						};

					} else if (prt->csiSrefWdbeMSignal != "") {
						Wdbe::getRange(prt->csiSrefWdbeMSignal, sref, hasrng, from, to, ix);

						auto it = srefsSigs.find(sref);
						if (it != srefsSigs.end()) {
							sig = it->second;

							outfile << sig->sref;
							if ((sig->ixVBasetype == VecWdbeVMSignalBasetype::CLK) && (sig->drvRefWdbeMPort == 0)) {
								if (submdl->sref == ("bufg" + StrMod::cap(sig->sref))) {
									if (prt->ixVDir == VecWdbeVMPortDir::OUT) outfile << "_sig";
								} else if (prt->ixVDir == VecWdbeVMPortDir::IN) outfile << "_sig";
							};
							if (hasrng) {
								outfile << "(";
								if (ix != "") {
									if (dbswdbe->loadStringBySQL("SELECT sref FROM TblWdbeMVector WHERE ref = " + to_string(sig->refWdbeMVector), s)) outfile << "ix" << s.substr(3) << StrMod::cap(ix);
								} else {
									if (prt->srefWdbeKHdltype == "sl") outfile << to_string((int) from); // connect a sl port to a slv signal element
									else if (sig->srefWdbeKHdltype == "slvup") outfile << to_string((int) from) << " to " << to_string((int) to);
									else if (sig->srefWdbeKHdltype == "slvdn") outfile << to_string((int) to) << " downto " << to_string((int) from);
								};
								outfile << ")";
							};
						};

					} else if (prt->Defval != "") {
						outfile << getValStr(prt, true);

					} else {
						outfile << "open";
					};

					refC = prt->refWdbeCPort;
					Comment = prt->Comment;
				};
			};
		};

		if (Comment != "") outfile << " -- " << Comment;
		outfile << endl << "\t\t);" << endl;
		outfile << endl;
	};

	outfile << "-- IP subs --- IEND" << endl;

	// --- impl
	outfile << "-- IP impl --- IBEGIN" << endl;

	for (unsigned int i = 0; i < prcs.nodes.size(); i++) {
		prc = prcs.nodes[i];
	
		outfile << "\t------------------------------------------------------------------------" << endl;
		outfile << "\t-- implementation: " << prc->Comment << " (" << prc->sref << ")" << endl;
		outfile << "\t------------------------------------------------------------------------" << endl;
		outfile << endl;

		outfile << "\t-- IP impl." << prc->sref << ".wiring --- INSERT" << endl;
		outfile << endl;

		outfile << "\t-- IP impl." << prc->sref << ".rising --- INSERT" << endl;
		outfile << endl;

		if (prc->Falling) {
			outfile << "\t-- IP impl." << prc->sref << ".falling --- INSERT" << endl;
			outfile << endl;
		};
	};

	outfile << "-- IP impl --- IEND" << endl;
};

void WdbeWrfpgaMdlraw::getHdltypeLibs(
			DbsWdbe* dbswdbe
			, const ubigint refUnt
			, set<string>& srefsLibmdls
			, map<string,string>& srefsLibs // by HDL type
		) {
	vector<ubigint> refs;

	ListWdbeAVKeylistKey klsAkeys;
	WdbeAVKeylistKey* klsAkey = NULL;

	string srefLib;

	// KlstWdbeKHdltype entries via module templates and modules
	dbswdbe->loadRefsBySQL("SELECT DISTINCT tplRefWdbeMModule FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND hkUref = " + to_string(refUnt)
				+ " AND tplRefWdbeMModule <> 0", false, refs);
	dbswdbe->loadRefsBySQL("SELECT ref FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND hkUref = " + to_string(refUnt), true, refs);

	srefsLibmdls.clear();
	srefsLibs.clear();

	for (unsigned int i = 0; i < refs.size();i++) {
		dbswdbe->tblwdbeavkeylistkey->loadRstByKlsMtbUrf(VecWdbeVKeylist::KLSTWDBEKHDLTYPE, VecWdbeVMaintable::TBLWDBEMMODULE, refs[i], false, klsAkeys);

		if (klsAkeys.nodes.size() > 0) {
			if (dbswdbe->tblwdbemmodule->loadSrfByRef(refs[i], srefLib)) {
				srefsLibmdls.insert(srefLib);

				srefLib = StrMod::cap(srefLib) + "_lib";

				for (unsigned int j = 0; j < klsAkeys.nodes.size(); j++) {
					klsAkey = klsAkeys.nodes[j];
					srefsLibs[klsAkey->sref] = srefLib;
				};
			};
		};
	};
};

void WdbeWrfpgaMdlraw::fillIcsMdc(
			vector<uint>& icsMdc
		) {
	icsMdc.clear();

	push_back(icsMdc, VecWdbeVMPortMdlCat::RESET);
	push_back(icsMdc, VecWdbeVMPortMdlCat::CLK);
	push_back(icsMdc, VecWdbeVMPortMdlCat::RTEWRP);
	push_back(icsMdc, VecWdbeVMPortMdlCat::RTETOP);
	push_back(icsMdc, VecWdbeVMPortMdlCat::CMDBUS);
	push_back(icsMdc, VecWdbeVMPortMdlCat::IMB);
	push_back(icsMdc, VecWdbeVMPortMdlCat::RTESUP);
	push_back(icsMdc, VecWdbeVMPortMdlCat::RTEPIN);
	push_back(icsMdc, VecWdbeVMPortMdlCat::DBG);
};
// IP cust --- IEND
