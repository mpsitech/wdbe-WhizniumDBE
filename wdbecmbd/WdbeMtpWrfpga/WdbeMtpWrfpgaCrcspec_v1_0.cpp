/**
	* \file WdbeMtpWrfpgaCrcspec_v1_0.cpp
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

#include "WdbeMtpWrfpgaCrcspec_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpWrfpga;

/******************************************************************************
 namespace WdbeMtpWrfpgaCrcspec_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpWrfpgaCrcspec_v1_0::run(
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

		// xxxx/Crc..._v1_0.vhd
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
void WdbeMtpWrfpgaCrcspec_v1_0::writeMdlVhd(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMModule* mdl
		) {
	unsigned int crcpoly;

	vector<unsigned int> dincs;
	vector<unsigned int> crcolds;

	unsigned int dinc;
	unsigned int crcold;

	string s;

	unsigned int ix, ix2;

	bool first;

	// --- crccalc
	outfile << "-- IP crccalc --- IBEGIN" << endl;

	crcpoly = 0;
	if (Wdbe::getMpa(dbswdbe, mdl->ref, "poly", s)) {
		if (s.length() <= 4) {
			while (s.length() < 4) s = "0" + s;
			crcpoly = 256*((unsigned int) Wdbe::hexToBin(s.substr(0, 2))) + Wdbe::hexToBin(s.substr(2));
		};
	};

	// 16 entries corr. to crc_sig(0) to crc_sig(15)
	dincs.resize(16, 0);

	crcolds.resize(16, 0);
	ix = 1;
	for (unsigned int i = 0; i < 16; i++, ix *= 2) crcolds[i] = ix;

	// - determine composition of individual CRC bits
	ix = 128;
	for (unsigned int i = 8; i > 0; i--, ix /= 2) {
		dinc = dincs[15];
		crcold = crcolds[15];

		// shift all in the direction of MSB
		for (unsigned int j = 16; j > 1; j--) {
			dincs[j-1] = dincs[j-2];
			crcolds[j-1] = crcolds[j-2];
		};
		dincs[0] = dinc;
		crcolds[0] = crcold;

		// incorporate (former crc_sig(15)) xor d(i-1) into all crcpoly-bit=1 positions
		ix2 = 1;
		for (unsigned int j = 0; j < 16; j++, ix2 *= 2) {
			if (j == 0) dincs[j] |= ix;
			else if (crcpoly & ix2) {
				dincs[j] ^= dinc;
				crcolds[j] ^= crcold;
				
				dincs[j] |= ix;
			};
		};
	};

	// - output
	for (unsigned int i = 16; i > 0; i--) {
		outfile << "\t\t\t\tcrc_sig(" << (i-1) << ") <=";

		first = true;

		ix = 128;
		for (unsigned j = 8; j > 0; j--, ix /= 2) {
			if (dincs[i-1] & ix) {
				if (first) first = false;
				else outfile << " xor";
				
				outfile << " dinc(" << (j-1) << ")";
			};
		};

		ix = 1;
		for (unsigned j = 0; j < 16; j++, ix <<= 1) {
			if (crcolds[i-1] & ix) {
				if (first) first = false;
				else outfile << " xor";
				
				outfile << " crcold(" << j << ")";
			};
		};

		outfile << ";" << endl;
	};

	outfile << "-- IP crccalc --- IEND" << endl;
};
// IP cust --- IEND



