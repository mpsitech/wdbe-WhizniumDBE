/**
	* \file WdbeWrfpga.cpp
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

#include "WdbeWrfpga.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace WdbeWrfpga
 ******************************************************************************/

// IP cust --- IBEGIN
string WdbeWrfpga::valToSlv(
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

string WdbeWrfpga::getValStr(
			WdbeMGeneric* gen
			, const bool othNotFull
		) {
	WdbeMSignal sig(0, 0, 0, 0, 0, 0, 0, 0, "", false, gen->srefWdbeKHdltype, gen->Width, gen->Minmax, "", "", gen->Defval, false, 0, "");
	return(getValStr(&sig, othNotFull));
};

string WdbeWrfpga::getValStr(
			WdbeMPort* prt
			, const bool othNotFull
		) {
	WdbeMSignal sig(0, 0, 0, 0, 0, 0, 0, 0, "", false, prt->srefWdbeKHdltype, prt->Width, prt->Minmax, "", "", prt->Defval, false, 0, "");
	return(getValStr(&sig, othNotFull));
};

string WdbeWrfpga::getValStr(
			WdbeMSignal* sig
			, const bool othNotFull
			, const string& altval
		) {
	string s;

	if (altval != "") s = altval;
	else if (sig->Defon) s = sig->Onval;
	else s = sig->Offval;

	bool val;

	if (sig->srefWdbeKHdltype == "sl") {
		if (s.length() == 1) if ((s[0] == '0') || (s[0] == '1') || (s[0] == 'Z') || (s[0] == 'z')) s = "'" + s + "'";

	} else if ((sig->srefWdbeKHdltype == "slvup") || (sig->srefWdbeKHdltype == "slvdn")) {
		val = true;

		for (unsigned int i = 0; i < s.length(); i++) {
			// signal / variable names should be copied 1:1, but numbers, including hex, should be interpreted
			if ((s[i] < '0') || (s[i] > '9')) if ((s[i] < 'A') || (s[i] > 'F')) if ((s[i] < 'a') || (s[i] > 'f')) if ((s[i] != 'Z') && (s[i] != 'z')) {
				val = false;
				break;
			};
		};

		if (val) s = valToSlv(s, sig->Width, (sig->srefWdbeKHdltype == "slvup"), othNotFull);

	} else if (sig->srefWdbeKHdltype == "str") {
		s = "\"" + s + "\"";
	};

	return s;
};

string WdbeWrfpga::getValStr(
			WdbeMVariable* var
			, const bool othNotFull
			, const string& altval
		) {
	WdbeMSignal sig(0, 0, 0, 0, 0, 0, 0, 0, "", false, var->srefWdbeKHdltype, var->Width, var->Minmax, "", var->Onval, var->Offval, var->Defon, 0, "");
	return(getValStr(&sig, othNotFull, altval));
};

string WdbeWrfpga::getVarStr(
			WdbeMGeneric* gen
		) {
	WdbeMSignal sig(0, 0, 0, 0, 0, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "", false, gen->srefWdbeKHdltype, gen->Width, gen->Minmax, "", "", gen->Defval, false, 0, "");
	return(getVarStr(&sig));
};

string WdbeWrfpga::getVarStr(
			WdbeMPort* prt
		) {
	WdbeMSignal sig(0, 0, 0, 0, 0, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "", false, prt->srefWdbeKHdltype, prt->Width, prt->Minmax, "", "", "", false, 0, "");
	return(getVarStr(&sig));
};

string WdbeWrfpga::getVarStr(
			WdbeMSignal* sig
		) {
	string s;

	size_t ptr;

	if (sig->srefWdbeKHdltype == "int") s = "integer";
	else if (sig->srefWdbeKHdltype == "nat") s = "natural";
	else if (sig->srefWdbeKHdltype == "sl") s = "std_logic";
	else if (sig->srefWdbeKHdltype == "slvup") s = "std_logic_vector(0 to " + to_string((int) (sig->Width-1)) + ")";
	else if (sig->srefWdbeKHdltype == "slvdn") s = "std_logic_vector(" + to_string((int) (sig->Width-1)) + " downto 0)";
	else if (sig->srefWdbeKHdltype == "str") s = "string";
	else s = sig->srefWdbeKHdltype;

	ptr = sig->Minmax.find("..");
	if (ptr != string::npos) s += " range " + sig->Minmax.substr(0, ptr) + " to " + sig->Minmax.substr(ptr+2);

	if ((sig->mgeIxVTbl == VecWdbeVMSignalMgeTbl::VOID) || sig->Const) if ((!sig->Defon && (sig->Offval != "")) || (sig->Defon && (sig->Onval != ""))) s += " := " + getValStr(sig, true);

	return s;
};

string WdbeWrfpga::getVarStr(
			WdbeMVariable* var
		) {
	WdbeMSignal sig(0, 0, 0, 0, 0, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "", false, var->srefWdbeKHdltype, var->Width, var->Minmax, "", var->Onval, var->Offval, var->Defon, 0, "");
	return(getVarStr(&sig));
};

void WdbeWrfpga::srefsFstsToVector(
			const string& s
			, vector<string>& ss
		) {
	size_t ptr;

	char c, c2;

	StrMod::srefsToVector(s, ss);

	for (unsigned int i = 0; i < ss.size();i++) {
		if (ss[i].length() >= 4) {
			ptr = ss[i].find("..");

			if (ptr != string::npos) if ((ptr+3) == ss[i].length()) {
				c = ss[i][ptr-1];
				c2 = ss[i][ptr+2];
				
				if ((c >= 'A') && (c <= 'Z') && (c2 >= 'A') && (c2 <= 'Z') && (c2 >= c)) {
					ss.resize(ss.size() + (c2-c));
					for (unsigned int j = ss.size(); j > (i+(c2-c)); j--) ss[j-1] = ss[j-1-(c2-c)];

					for (unsigned j = i; c <= c2; j++, c++) ss[j] = ss[i].substr(0, ptr-1) + c;
				};
			};
		};
	};
};

string WdbeWrfpga::getImbsigsref(
			DbsWdbe* dbswdbe
			, WdbeMImbuf* imb
		) {
	string sref;
	
	string s;

	sref = Wdbe::getImbshort(imb); // ex. 'ToWavegen' or 'SpecrebufFromXadcacq'

	if (dbswdbe->loadStringBySQL("SELECT sref FROM TblWdbeMModule WHERE ref = " + to_string(imb->refWdbeMModule), s)) {
		// 'BufToWavegen' or 'SpecrebufFromXadcacq'
		s = StrMod::cap(s);
		if (sref.find(s) != 0) sref = s + sref;
	};

	return sref;
};
// IP cust --- IEND
