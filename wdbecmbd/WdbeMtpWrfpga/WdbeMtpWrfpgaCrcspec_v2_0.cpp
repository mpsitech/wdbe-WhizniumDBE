/**
	* \file WdbeMtpWrfpgaCrcspec_v2_0.cpp
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

#include "WdbeMtpWrfpgaCrcspec_v2_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpWrfpga;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpWrfpgaCrcspec_v2_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpWrfpgaCrcspec_v2_0::run(
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
	// modified version of WdbeMtpWrfpgaCrcspec_32_v1_0 allowing for
	// a. incorporation of all bytes within the same clock cycle
	// b. 16/32 bit polynomials

	WdbeMModule* mdl = NULL;

	string Compsref;

	fstream outfile;

	string s;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		Compsref = StrMod::cap(Wdbe::getCompsref(dbswdbe, mdl));

		// xxxx/Crc..._32.vhd
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
void WdbeMtpWrfpgaCrcspec_v2_0::writeMdlVhd(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMModule* mdl
		) {
	unsigned int wDinc0;
	vector<unsigned long long> dincs;
	unsigned long long dinc;
	unsigned long long ix; // index running along dinc bits

	unsigned int wPoly;
	unsigned int crcpoly;
	vector<unsigned int> crcolds;
	unsigned int crcold;
	unsigned int ix2; // index running along crc bits

	string indent;

	string s;

	bool first;

	// --- crccalc
	outfile << "-- IP crccalc --- IBEGIN" << endl;

	wDinc0 = 0;

	if (Wdbe::getMpa(dbswdbe, mdl->ref, "wD", s)) wDinc0 = atoi(s.c_str());

	indent = string((wDinc0 > 8) ? 6 : 4, '\t');

	// ex. for lsbD and 32 bit data
	// 0: DXXX
	// 1: DDXX
	// 2: DDDX
	// 3: DDDD

	wPoly = 0;
	crcpoly = 0;

	if (Wdbe::getMpa(dbswdbe, mdl->ref, "poly", s)) {
		if (s.length() <= 4) while (s.length() < 4) s = "0" + s;
		else if (s.length() <= 8) while (s.length() < 8) s = "0" + s;
		else s = s.substr(0, 8);

		wPoly = (s.length() == 8) ? 32 : 16;
		
		for (unsigned int i = 0; i < s.length(); i += 2) crcpoly = (crcpoly << 8) + Wdbe::hexToBin(s.substr(i, 2));
	};

	// 16/32 entries corr. to crc_sig(0) to crc_sig(15/31)
	dincs.resize(wPoly);
	crcolds.resize(wPoly);

	if (wDinc0 > 8) outfile << "\t\t\t\tcase to_integer(unsigned(lsbD)) is" << endl;

	for (unsigned int wDinc = wDinc0; wDinc > 0; wDinc -= 8)  {
		if (wDinc0 > 8) outfile << "\t\t\t\t\twhen " << (wDinc/8 - 1) << " =>" << endl;

		for (unsigned int i = 0; i < wPoly; i++) {
			dincs[i] = 0;
			crcolds[i] = 0;
		};

		ix2 = 1;
		for (unsigned int i = 0; i < wPoly; i++, ix2 <<= 1) crcolds[i] = ix2;

		// - determine composition of individual CRC bits
		ix = 1;
		ix <<= (wDinc - 1);

		for (unsigned int i = wDinc; i > 0; i--, ix >>= 1) {
			dinc = dincs[wPoly - 1];
			crcold = crcolds[wPoly - 1];

			// shift all in the direction of MSB
			for (unsigned int j = wPoly; j > 1; j--) {
				dincs[j-1] = dincs[j-2];
				crcolds[j-1] = crcolds[j-2];
			};
			dincs[0] = dinc;
			crcolds[0] = crcold;

			// incorporate (former crc_sig(wPoly-1)) xor d(i-1) into all crcpoly-bit=1 positions
			ix2 = 1;
			for (unsigned int j = 0; j < wPoly; j++, ix2 <<= 1) {
				if (j == 0) dincs[j] |= ix;
				else if (crcpoly & ix2) {
					dincs[j] ^= dinc;
					crcolds[j] ^= crcold;
					
					dincs[j] |= ix;
				};
			};
		};

		// - output
		for (unsigned int i = wPoly; i > 0; i--) {
			outfile << indent << "crc_sig(" << (i-1) << ") <=";

			first = true;

			ix = 1;
			ix <<= (wDinc - 1);

			for (unsigned j = wDinc; j > 0; j--, ix >>= 1) {
				if (dincs[i-1] & ix) {
					if (first) first = false;
					else outfile << " xor";
					
					outfile << " d(" << (j + (wDinc0 - wDinc) - 1) << ")";
				};
			};

			ix2 = 1;
			for (unsigned j = 0; j < wPoly; j++, ix2 <<= 1) {
				if (crcolds[i-1] & ix2) {
					if (first) first = false;
					else outfile << " xor";
					
					outfile << " crc_sig(" << j << ")";
				};
			};

			outfile << ";" << endl;
		};
	};

	if (wDinc0 > 8) outfile << "\t\t\t\tend case;" << endl;

	outfile << "-- IP crccalc --- IEND" << endl;
};
// IP cust --- IEND
