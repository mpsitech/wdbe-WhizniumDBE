/**
	* \file WdbeMtpWrfpgaCrcspec_v3_0.cpp
	* Wdbe operation processor -  (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 3 Apr 2023
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpWrfpgaCrcspec_v3_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpWrfpga;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpWrfpgaCrcspec_v3_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpWrfpgaCrcspec_v3_0::run(
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

		// xxxx/Crc..._32/64/....vhd
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
void WdbeMtpWrfpgaCrcspec_v3_0::writeMdlVhd(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMModule* mdl
		) {
	typedef unsigned __int128 uint128_t;
	bool leNotBe;
	unsigned int wDinc0;
	vector<uint128_t> dincs;
	uint128_t dinc;
	uint128_t ix; // index running along dinc bits

	unsigned int wPoly;
	unsigned int crcpoly;
	vector<unsigned int> crcolds;
	unsigned int crcold;
	unsigned int ix2; // index running along crc bits

	string indent;

	string s;

	bool first;

	leNotBe = false;

	if (Wdbe::getMpa(dbswdbe, mdl->ref, "leNotBe", s)) leNotBe = (s == "true");

	wDinc0 = 0;

	if (Wdbe::getMpa(dbswdbe, mdl->ref, "wD", s)) wDinc0 = atoi(s.c_str());

	indent = string((wDinc0 > 8) ? 7 : 5, '\t');

	// ex. for AXIS_tkeep and 32 bit data
	// 0001: XXXD
	// 0011: XXDD
	// 0111: XDDD
	// 1111: DDDD

	wPoly = 0;
	crcpoly = 0;

	if (Wdbe::getMpa(dbswdbe, mdl->ref, "poly", s)) {
		if (s.length() <= 4) while (s.length() < 4) s = "0" + s;
		else if (s.length() <= 8) while (s.length() < 8) s = "0" + s;
		else s = s.substr(0, 8);

		wPoly = (s.length() == 8) ? 32 : 16;
		
		for (unsigned int i = 0; i < s.length(); i += 2) crcpoly = (crcpoly << 8) + Wdbe::hexToBin(s.substr(i, 2));
	};

	// --- initInvert.wDGtWPoly*
	if (wDinc0 > wPoly) outfile << "-- IP initInvert.wDGtWPoly --- AFFIRM" << endl;
	else outfile << "-- IP initInvert.wDGtWPoly --- REMOVE" << endl;

	// --- initInvert.wDGeqWPoly*
	if (wDinc0 >= wPoly) outfile << "-- IP initInvert.wDGeqWPoly --- AFFIRM" << endl;
	else outfile << "-- IP initInvert.wDGeqWPoly --- REMOVE" << endl;

	// --- initInvert.wDLtWPoly*
	if (wDinc0 < wPoly) outfile << "-- IP initInvert.wDLtWPoly --- AFFIRM" << endl;
	else outfile << "-- IP initInvert.wDLtWPoly --- REMOVE" << endl;

	// --- crccalc
	outfile << "-- IP crccalc --- IBEGIN" << endl;

	//cout << "working with crcpoly = " << crcpoly << endl;

	// 16/32 entries corr. to crc_sig(0) to crc_sig(15/31)
	dincs.resize(wPoly);
	crcolds.resize(wPoly);

	if (wDinc0 > 8) {
		outfile << "\t\t\t\t\tcase AXIS_tkeep is" << endl;
	};

	for (unsigned int wDinc = wDinc0; wDinc > 0; wDinc -= 8)  {
		if (wDinc0 > 8) {
			outfile << "\t\t\t\t\t\twhen \"";

			if (!leNotBe) {
				for (unsigned int j = 0; j < wDinc/8; j++) outfile << "1";
				for (unsigned int j = wDinc/8+1; j <= wDinc0/8; j++) outfile << "0";
			} else {
				for (unsigned int j = wDinc/8+1; j <= wDinc0/8; j++) outfile << "0";
				for (unsigned int j = 0; j < wDinc/8; j++) outfile << "1";
			};

			outfile << "\" =>" << endl;
		};

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
			outfile << indent << "crc_imd(" << (i-1) << ") <=";

			first = true;

			ix = 1;
			ix <<= (wDinc - 1);

			for (unsigned j = wDinc; j > 0; j--, ix >>= 1) {
				if (dincs[i-1] & ix) {
					if (first) first = false;
					else outfile << " xor";
					
					if (!leNotBe) outfile << " word(" << (j + (wDinc0 - wDinc) - 1) << ")";
					else outfile << " word(" << getLittleEndian(wDinc0, j + (wDinc0 - wDinc) - 1) << ")";
				};
			};

			ix2 = 1;
			for (unsigned j = 0; j < wPoly; j++, ix2 <<= 1) {
				if (crcolds[i-1] & ix2) {
					if (first) first = false;
					else outfile << " xor";
					
					outfile << " crc_imd(" << j << ")";
				};
			};

			outfile << ";" << endl;
		};
		outfile << indent << "validCrc_sig <= '1';" << endl;
	};

	if (wDinc0 > 8) {
		outfile << "\t\t\t\t\t\twhen others =>" << endl;
		outfile << "\t\t\t\t\t\t\tvalidCrc_sig <= '0';" << endl;
		outfile << "\t\t\t\t\tend case;" << endl;
	};

	outfile << "-- IP crccalc --- IEND" << endl;
};

unsigned int WdbeMtpWrfpgaCrcspec_v3_0::getLittleEndian(
			const unsigned int wDinc
			, const unsigned int ix
		) {
	// bits are fed into the algorithm MSBit to LSBit
	// in little-endian the byte order is LSByte to MSByte
	unsigned int ixbyte = wDinc/8 - ix/8 - 1;
	unsigned int ixbit = ix%8;

	return(8*ixbyte + ixbit);
};
// IP cust --- IEND
