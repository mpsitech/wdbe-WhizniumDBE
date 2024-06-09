/**
	* \file WdbeMtpWrfpgaDpram_efnx_v1_0.cpp
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

#include "WdbeMtpWrfpgaDpram_efnx_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpWrfpga;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpWrfpgaDpram_efnx_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpWrfpgaDpram_efnx_v1_0::run(
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

		// xxxx/Dpram_size96kB_wA32wB8.vhd
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
void WdbeMtpWrfpgaDpram_efnx_v1_0::writeMdlVhd(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMModule* mdl
		) {
	ubigint ref;

	uint NRam;
	unsigned int wA, wB;

	unsigned int M, N, O, P;

	unsigned int MO, NP;

	string aA, aB;

	bool BNotA;

	string s, s2, s3;

	NRam = 1;
	wA = 8;
	wB = 8;

	dbswdbe->loadUintBySQL("SELECT COUNT(ref) FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(mdl->ref) + " AND sref LIKE 'ram_%'", NRam);
	if (Wdbe::getMpa(dbswdbe, mdl->ref, "wA", s)) wA = atoi(s.c_str());
	if (Wdbe::getMpa(dbswdbe, mdl->ref, "wB", s)) wB = atoi(s.c_str());

	N = wA / 8;
	M = NRam / N;

	P = wB / 8;
	O = NRam / P;

	aA = "aA"; if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMSignal WHERE refIxVTbl = " + to_string(VecWdbeVMSignalRefTbl::MDL) + " AND refUref = " + to_string(mdl->ref) + " AND sref = 'aA_sig'", ref)) aA += "_sig";
	aB = "aB"; if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMSignal WHERE refIxVTbl = " + to_string(VecWdbeVMSignalRefTbl::MDL) + " AND refUref = " + to_string(mdl->ref) + " AND sref = 'aB_sig'", ref)) aB += "_sig";

	// --- impl.muxA
	outfile << "-- IP impl.muxA --- IBEGIN" << endl;
	outfile << "\t\t\tenAm1 <= enA;" << endl;
	outfile << "\t\t\taAm1 <= " << aA << ";" << endl;
	outfile << "-- IP impl.muxA --- IEND" << endl;

	// --- impl.muxB
	outfile << "-- IP impl.muxB --- IBEGIN" << endl;
	outfile << "\t\t\tenBm1 <= enB;" << endl;
	outfile << "\t\t\taBm1 <= " << aB << ";" << endl;
	outfile << "-- IP impl.muxB --- IEND" << endl;

	// --- impl.oth.cust
	outfile << "-- IP impl.oth.cust --- IBEGIN" << endl;
	BNotA = false;
	do {
		if (!BNotA) {
			MO = M;
			NP = N;

			s = "A";
			s2 = "A_i";
			s3 = "j";

		} else {
			MO = O;
			NP = P;

			s = "B";
			s2 = "B_k";
			s3 = "l";

			outfile << endl;
		};

		for (unsigned int ik = 0; ik < MO; ik++) {
			outfile << "\tdrd" << s2 << ik << " <=";

			for (unsigned int jl = NP; jl > 0; jl--) {
				if (jl == NP) outfile << " ";
				else outfile << " & ";

				outfile << "drd" << s2 << ik << s3 << (jl - 1);
			};

			outfile << ";" << endl;
		};
		outfile << endl;

		outfile << "\tdrd" << s << " <= ";
		for (unsigned int ik = 0; ik < MO; ik++) {
			if (ik != 0) outfile << "\t\t\t\telse ";
			outfile << "drd" << s2 << ik << " when en" << s2 << ik << "m1='1'" << endl;
		};
		outfile << "\t\t\t\telse (others => '0');" << endl;

		BNotA = !BNotA;
	} while (BNotA);
	outfile << "-- IP impl.oth.cust --- IEND" << endl;
};
// IP cust --- IEND
