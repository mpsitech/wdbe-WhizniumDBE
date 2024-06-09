/**
	* \file WdbeWrfpgaAux.cpp
	* Wdbe operation processor - write auxiliary VHDL code (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 30 May 2023
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeWrfpgaAux.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeWrfpga;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeWrfpgaAux
 ******************************************************************************/

DpchRetWdbe* WdbeWrfpgaAux::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeWrfpgaAux* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WdbeMModule* mdl = NULL;

	ListWdbeMCdc cdcs;
	WdbeMCdc* cdc = NULL;

	string Compsref;

	fstream outfile;

	string s;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		Compsref = StrMod::cap(Wdbe::getCompsref(dbswdbe, mdl));

		dbswdbe->tblwdbemcdc->loadRstByMdl(refWdbeMModule, false, cdcs);

		// xxxx/Xxxxx.vhd
		s = xchg->tmppath + "/" + folder + "/" + Compsref + ".vhd.ip";
		outfile.open(s.c_str(), ios::out);

		for (unsigned int i = 0; i < cdcs.nodes.size(); i++) {
			cdc = cdcs.nodes[i];
			writeCdcVhd(dbswdbe, outfile, cdc);
		};

		writeIpclrVhd(dbswdbe, outfile, mdl);

		outfile.close();

		delete mdl;
	};
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WdbeWrfpgaAux::writeCdcVhd(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMCdc* cdc
		) {
	ListWdbeRMCdcMSignal crss;
	WdbeRMCdcMSignal* crs = NULL;

	bool hasfts, hasstf;

	dbswdbe->tblwdbermcdcmsignal->loadRstByCdc(cdc->ref, false, crss);

	hasfts = false;
	hasstf = false;

	for (unsigned int j = 0; j < crss.nodes.size(); j++) {
		crs = crss.nodes[j];

		if (crs->ixVDir == VecWdbeVRMCdcMSignalDir::FTS) hasfts = true;
		else if (crs->ixVDir == VecWdbeVRMCdcMSignalDir::STF) hasstf = true;

		if (hasfts && hasstf) break;
	};

	if (hasfts) writeCdcVhd_impl(dbswdbe, outfile, cdc, VecWdbeVRMCdcMSignalDir::FTS, crss);
	if (hasstf) writeCdcVhd_impl(dbswdbe, outfile, cdc, VecWdbeVRMCdcMSignalDir::STF, crss);
};

void WdbeWrfpgaAux::writeCdcVhd_impl(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMCdc* cdc
			, const uint ixVDir
			, ListWdbeRMCdcMSignal& crss
		) {
	WdbeRMCdcMSignal* crs = NULL;

	WdbeMSignal* sig = NULL;

	string from, to;

	string stretch;

	if (ixVDir == VecWdbeVRMCdcMSignalDir::FTS) {
		from = cdc->fckSrefWdbeMSignal;
		to = cdc->sckSrefWdbeMSignal;

	} else {
		from = cdc->sckSrefWdbeMSignal;
		to = cdc->fckSrefWdbeMSignal;
	};

	if ((ixVDir == VecWdbeVRMCdcMSignalDir::FTS) || (cdc->Ratio <= 2.0)) {
		stretch = "_to_" + to;

		outfile << "-- IP impl." + from + "To" + StrMod::cap(to) + "Stretch --- IBEGIN" << endl;

		for (unsigned int j = 0; j < crss.nodes.size(); j++) {
			crs = crss.nodes[j];

			if (crs->ixVDir == ixVDir)
				if (dbswdbe->tblwdbemsignal->loadRecByRef(crs->refWdbeMSignal, &sig)) {
					if (sig->ixVBasetype == VecWdbeVMSignalBasetype::STRB) {
						outfile << "\t\t\tif " << sig->sref << "='1' then" << endl;
						outfile << "\t\t\t\t" << sig->sref << "_to_" << to << " <= '1';" << endl;
						outfile << "\t\t\t\t" << sig->sref << "_i := 0;" << endl;
						outfile << "\t\t\telsif " << sig->sref << "_i=imax then" << endl;
						outfile << "\t\t\t\t" << sig->sref << "_to_" << to << " <= '0';" << endl;
						outfile << "\t\t\telse" << endl;
						outfile << "\t\t\t\t" << sig->sref << "_i := " << sig->sref << "_i + 1;" << endl;
						outfile << "\t\t\tend if;" << endl;

					} else {
						outfile << "\t\t\tif " << sig->sref << "_i=imax then" << endl;
						outfile << "\t\t\t\tif " << sig->sref << "/=" << sig->sref << "_to_" << to << " then" << endl;
						outfile << "\t\t\t\t\t" << sig->sref << "_to_" << to << " <= " << sig->sref << ";" << endl;
						outfile << "\t\t\t\t\t" << sig->sref << "_i := 0;" << endl;
						outfile << "\t\t\t\tend if;" << endl;
						outfile << "\t\t\telse" << endl;
						outfile << "\t\t\t\t" << sig->sref << "_i := " << sig->sref << "_i + 1;" << endl;
						outfile << "\t\t\tend if;" << endl;
					};

					outfile << endl;

					delete sig;
				};
		};

		outfile << "-- IP impl." + from + "To" + StrMod::cap(to) + "Stretch --- IEND" << endl;
	};

	outfile << "-- IP impl." + from + "To" + StrMod::cap(to) + "Sample --- IBEGIN" << endl;

	for (unsigned int j = 0; j < crss.nodes.size(); j++) {
		crs = crss.nodes[j];

		if (crs->ixVDir == ixVDir)
			if (dbswdbe->tblwdbemsignal->loadRecByRef(crs->refWdbeMSignal, &sig)) {
				if (sig->ixVBasetype == VecWdbeVMSignalBasetype::STRB) {
					outfile << "\t\t\tif " << sig->sref << "_" << to << "='1' then" << endl;
					outfile << "\t\t\t\t" << sig->sref << "_" << to << " <= '0';" << endl;
					outfile << "\t\t\telsif " << sig->sref << stretch << "='1' and not " << sig->sref << "_wait then" << endl;
					outfile << "\t\t\t\t" << sig->sref << "_" << to << " <= '1';" << endl;
					outfile << "\t\t\t\t" << sig->sref << "_wait := true;" << endl;
					outfile << "\t\t\tend if;" << endl;
					outfile << "\t\t\tif " << sig->sref << stretch << "='0' and " << sig->sref << "_wait then" << endl;
					outfile << "\t\t\t\t" << sig->sref << "_wait := false;" << endl;
					outfile << "\t\t\tend if;" << endl;

				} else {
					outfile << "\t\t\tif " << sig->sref << stretch << "=" << sig->sref << "_last then" << endl;
					outfile << "\t\t\t\t" << sig->sref << "_" << to << " <= " << sig->sref << stretch << ";" << endl;
					outfile << "\t\t\tend if;" << endl;
					outfile << "\t\t\t" << sig->sref << "_last := " << sig->sref << stretch << ";" << endl;
				};

				outfile << endl;

				delete sig;
			};
	};

	outfile << "-- IP impl." + from + "To" + StrMod::cap(to) + "Sample --- IEND" << endl;
};

void WdbeWrfpgaAux::writeIpclrVhd(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMModule* mdl
		) {
	ListWdbeMProcess prcs;
	WdbeMProcess* prc = NULL;

	dbswdbe->tblwdbemprocess->loadRstBySQL("SELECT * FROM TblWdbeMProcess WHERE refWdbeMModule = " + to_string(mdl->ref) + " ORDER BY sref ASC", false, prcs);

	// -- by processes
	for (unsigned int i = 0; i < prcs.nodes.size(); i++) {
		prc = prcs.nodes[i];

		outfile << "\t-- IP sigs." << prc->sref << ".typspec --- IBEGIN" << endl;
		outfile << "\t-- IP sigs." << prc->sref << ".typspec --- IEND" << endl;

		outfile << "\t-- IP sigs." << prc->sref << ".tplspec --- IBEGIN" << endl;
		outfile << "\t-- IP sigs." << prc->sref << ".tplspec --- IEND" << endl;
	};

	// --- sigs.oth.typspec
	outfile << "\t-- IP sigs.oth.typspec --- IBEGIN" << endl;
	outfile << "\t-- IP sigs.oth.typspec --- IEND" << endl;

	// --- sigs.oth.tplspec
	outfile << "\t-- IP sigs.oth.tplspec --- IBEGIN" << endl;
	outfile << "\t-- IP sigs.oth.tplspec --- IEND" << endl;

	// --- impl.oth.typspec
	outfile << "\t-- IP impl.oth.typspec --- IBEGIN" << endl;
	outfile << "\t-- IP impl.oth.typspec --- IEND" << endl;

	// --- impl.oth.tplspec
	outfile << "\t-- IP impl.oth.tplspec --- IBEGIN" << endl;
	outfile << "\t-- IP impl.oth.tplspec --- IEND" << endl;
};
// IP cust --- IEND
