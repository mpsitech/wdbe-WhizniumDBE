/**
	* \file WdbeMtpWrfpgaSpram_efnx_v1_0.cpp
	* Wdbe operation processor -  (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Apr 2023
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpWrfpgaSpram_efnx_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpWrfpga;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpWrfpgaSpram_efnx_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpWrfpgaSpram_efnx_v1_0::run(
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
	// srtipped down copy from WdbeMtpWrfpgaDpram_efnx_v1_0

	WdbeMModule* mdl = NULL;

	string Compsref;

	fstream outfile;

	string s;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		Compsref = StrMod::cap(Wdbe::getCompsref(dbswdbe, mdl));

		// xxxx/Spram_size16kB_w16.vhd
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
void WdbeMtpWrfpgaSpram_efnx_v1_0::writeMdlVhd(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMModule* mdl
		) {
	// srtipped down copy from WdbeMtpWrfpgaDpram_efnx_v1_0

	ubigint ref;

	uint NRam;
	unsigned int w;

	unsigned int M, N;

	string a;

	string s;

	NRam = 1;
	w = 8;

	dbswdbe->loadUintBySQL("SELECT COUNT(ref) FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(mdl->ref) + " AND sref LIKE 'ram_%'", NRam);
	if (Wdbe::getMpa(dbswdbe, mdl->ref, "w", s)) w = atoi(s.c_str());

	N = w / 8;
	M = NRam / N;

	a = "a"; if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMSignal WHERE refIxVTbl = " + to_string(VecWdbeVMSignalRefTbl::MDL) + " AND refUref = " + to_string(mdl->ref) + " AND sref = 'a_sig'", ref)) a += "_sig";

	// --- impl.mux
	outfile << "-- IP impl.mux --- IBEGIN" << endl;
	outfile << "\t\t\tenm1 <= en;" << endl;
	outfile << "\t\t\tam1 <= " << a << ";" << endl;
	outfile << "-- IP impl.mux --- IEND" << endl;

	// --- impl.oth.cust
	outfile << "-- IP impl.oth.cust --- IBEGIN" << endl;

	for (unsigned int i = 0; i < M; i++) {
		outfile << "\tdrd_i" << i << " <=";

		for (unsigned int j = N; j > 0; j--) {
			if (j == N) outfile << " ";
			else outfile << " & ";

			outfile << "drd_i" << i << "j" << (j - 1);
		};

		outfile << ";" << endl;
	};
	outfile << endl;

	outfile << "\tdrd <= ";
	for (unsigned int i = 0; i < M; i++) {
		if (i != 0) outfile << "\t\t\t\telse ";
		outfile << "drd_i" << i << " when en_i" << i << "m1='1'" << endl;
	};
	outfile << "\t\t\t\telse (others => '0');" << endl;

	outfile << "-- IP impl.oth.cust --- IEND" << endl;
};
// IP cust --- IEND
