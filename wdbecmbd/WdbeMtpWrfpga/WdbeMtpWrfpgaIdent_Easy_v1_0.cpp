/**
	* \file WdbeMtpWrfpgaIdent_Easy_v1_0.cpp
	* Wdbe operation processor -  (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 31 Dec 2022
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpWrfpgaIdent_Easy_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpWrfpga;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpWrfpgaIdent_Easy_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpWrfpgaIdent_Easy_v1_0::run(
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

		// xxxx/Ident.vhd
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
void WdbeMtpWrfpgaIdent_Easy_v1_0::writeMdlVhd(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMModule* mdl
		) {
	ListWdbeMGeneric gens;
	WdbeMGeneric* gen = NULL;
	map<string, unsigned int> icsGens; // by sref

	ListWdbeMPort prts;
	WdbeMPort* prt = NULL;

	dbswdbe->tblwdbemgeneric->loadRstByMdl(mdl->ref, false, gens);
	for (unsigned int i = 0; i < gens.nodes.size(); i++) icsGens[gens.nodes[i]->sref] = i;

	dbswdbe->tblwdbemport->loadRstBySQL("SELECT * FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(mdl->ref) + " AND sref LIKE 'getCfg%' ORDER BY mdlNum ASC", false, prts);

	// --- impl.cfg
	outfile << "-- IP impl.cfg --- IBEGIN" << endl;

	for (unsigned int i = 0; i < prts.nodes.size(); i++) {
		prt = prts.nodes[i];

		auto it = icsGens.find(prt->sref.substr(6));
		if (it == icsGens.end()) it = icsGens.find(StrMod::uncap(prt->sref.substr(6)));

		if (it != icsGens.end()) {
			gen = gens.nodes[it->second];

			if (gen->srefWdbeKHdltype == "nat") {
				outfile << "\t" << prt->sref << " <= std_logic_vector(to_unsigned(" << gen->sref << ", " << ((int) prt->Width) << "));" << endl;

			} else if (gen->srefWdbeKHdltype == "slvdn") {
				if (gen->Width > prt->Width) outfile << "\t" << prt->sref << " <= " << gen->sref << "(" << (prt->Width - 1) << " downto 0);" << endl;
				else if (gen->Width < prt->Width) outfile << "\t" << prt->sref << " <= std_logic_vector(resize(unsigned(" << gen->sref << "), " << prt->Width << "));" << endl;
				else outfile << "\t" << prt->sref << " <= " << gen->sref << ";" << endl;
			};
		};
	};

	outfile << "-- IP impl.cfg --- IEND" << endl;
};
// IP cust --- IEND
