/**
	* \file WdbeMtpWrfpgaDpbram_v1_0.cpp
	* Wdbe operation processor -  (implementation)
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

#include "WdbeMtpWrfpgaDpbram_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpWrfpga;

/******************************************************************************
 namespace WdbeMtpWrfpgaDpbram_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpWrfpgaDpbram_v1_0::run(
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

		// xxxx/Dpbram_v1_0_size...kB.vhd
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
void WdbeMtpWrfpgaDpbram_v1_0::writeMdlVhd(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMModule* mdl
		) {
	string size;
	unsigned int N = 1;
	unsigned int amax;
	unsigned int w = 10;

	if (Wdbe::getMpa(dbswdbe, mdl->ref, "size", size)) {
		N = atoi(size.c_str()) / 2;
		amax = N*2048-1;
		w = 0;
		while (amax != 0) {
			amax >>= 1;
			w++;
		};
	};

	if (N > 1) {
		// --- impl.oth.tplspec
		outfile << "-- IP impl.oth.tplspec --- IBEGIN" << endl;

		// enA
		for (unsigned int i = 0; i < N; i++) outfile << "\tenA" << i << " <= '1' when (aA(" << (w-1) << " downto 11)=" << valToSlv(string(w, '0') + to_string(i), (w-11)) << " and enA='1') else '0';" << endl;
		outfile << endl;

		// drdA
		outfile << "\tdrdA <=";
		for (unsigned int i = 0; i < N; i++) {
			if (i != 0) outfile << "\t\telse";
			outfile << " drdA" << i << " when aA(" << (w-1) << " downto 11)=" << valToSlv(string(w, '0') + to_string(i), (w-11)) << endl;
		};
		outfile << "\t\telse (others => '0');" << endl;
		outfile << endl;

		// enB
		for (unsigned int i = 0; i < N; i++) outfile << "\tenB" << i << " <= '1' when (aB(" << (w-1) << " downto 11)=" << valToSlv(string(w, '0') + to_string(i), (w-11)) << " and enB='1') else '0';" << endl;
		outfile << endl;

		// drdB
		outfile << "\tdrdB <=";
		for (unsigned int i = 0; i < N; i++) {
			if (i != 0) outfile << "\t\telse";
			outfile << " drdB" << i << " when aB(" << (w-1) << " downto 11)=" << valToSlv(string(w, '0') + to_string(i), (w-11)) << endl;
		};
		outfile << "\t\telse (others => '0');" << endl;

		outfile << "-- IP impl.oth.tplspec --- IEND" << endl;

	} else {
		// --- sigs*
		outfile << "-- IP sigs --- REMOVE" << endl;

		// --- impl*
		outfile << "-- IP impl --- REMOVE" << endl;
	};
};
// IP cust --- IEND
