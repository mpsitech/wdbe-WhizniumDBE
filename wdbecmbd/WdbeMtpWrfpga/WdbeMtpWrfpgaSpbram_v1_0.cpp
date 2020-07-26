/**
	* \file WdbeMtpWrfpgaSpbram_v1_0.cpp
	* Wdbe operation processor -  (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpWrfpgaSpbram_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpWrfpga;

/******************************************************************************
 namespace WdbeMtpWrfpgaSpbram_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpWrfpgaSpbram_v1_0::run(
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

		// xxxx/Spbram_v1_0_size...kB.vhd
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
void WdbeMtpWrfpgaSpbram_v1_0::writeMdlVhd(
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

		// en
		for (unsigned int i = 0; i < N; i++) outfile << "\ten" << i << " <= '1' when (a(" << (w-1) << " downto 11)=" << valToSlv(string(w, '0') + to_string(i), (w-11)) << " and en='1') else '0';" << endl;
		outfile << endl;

		// drd
		outfile << "\tdrd <=";
		for (unsigned int i = 0; i < N; i++) {
			if (i != 0) outfile << "\t\telse";
			outfile << " drd" << i << " when a(" << (w-1) << " downto 11)=" << valToSlv(string(w, '0') + to_string(i), (w-11)) << endl;
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


