/**
	* \file WdbeMtpWrfpga.cpp
	* Wdbe operation pack global code (implementation)
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

#include "WdbeMtpWrfpga.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace WdbeMtpWrfpga
 ******************************************************************************/

// IP cust --- IBEGIN

// excact copy from WdbeWrfpga
string WdbeMtpWrfpga::valToSlv(
			const string& val
			, unsigned short w
			, const bool upNotDn
			, const bool othNotFull
		) {
	char c;

	string s;

	unsigned long long l;
	unsigned char u;
	unsigned long long mask;

	bool found;

	// '1', '0', 'Z': corresponding string of length w; '': zeros of length w
	c = ' ';
	if (val == "") c = '0';
	else if (val == "0") c = '0';
	else if (val == "1") c = '1';
	else if ((val == "Z") || (val == "z")) c = 'Z';

	if (c != ' ') {
		if (!othNotFull) return("\"" + string(w, c) + "\"");
		else return("(others => '" + string(1, c) + "')");
	};

	// string of length w, 0's and 1's only: assume binary
	if (val.length() == w) {
		found = true;

		for (unsigned short i = 0; i < w; i++) {
			if ((val[i] != '0') && (val[i] != '1')) {
				found = false;
				break;
			};
		};

		if (found) return("\"" + val + "\"");
	};

	// string of length w/4: assume hex
	if (4*val.length() == w) return("x\"" + StrMod::uc(val) + "\"");

	// else: assume decimal number
	l = atoll(val.c_str());

	if (!upNotDn && ((w%8) == 0)) {
		for (unsigned short i = (w/8); i != 0; i--) {
			c = l >> ((i-1)*8);
			s += Wdbe::binToHex(c);
		};

		return("x\"" + s + "\"");

	} else {
		mask = (((unsigned long long) 1) << (w-1));

		if (!upNotDn) {
			while (mask != 0) {
				if (l & mask) s += "1";
				else s += "0";
				
				mask >>= 1;
			};

		} else {
			while (mask != 0) {
				if (l & mask) s = "1" + s;
				else s = "0" + s;
				
				mask >>= 1;
			};
		};

		return("\"" + s + "\"");
	};
};
// IP cust --- IEND
