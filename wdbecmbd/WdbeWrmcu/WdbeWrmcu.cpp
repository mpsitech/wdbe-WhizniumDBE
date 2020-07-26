/**
	* \file WdbeWrmcu.cpp
	* Wdbe operation pack global code (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeWrmcu.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace WdbeWrmcu
 ******************************************************************************/

// IP cust --- IBEGIN
string WdbeWrmcu::valToSlv(
			const string& val
			, unsigned char w
			, const bool upNotDn
		) {
	// TBD: adapt to latest standard of Wdbe{Mtp}Wrfpga.cpp

	string s;

	unsigned long long l;
	unsigned long long mask;

	bool bin;

	unsigned char c;

	bin = (val.length() == w);
	if (bin) {
		for (unsigned char i=0;i<w;i++) {
			if ((val[i] != '0') && (val[i] != '1')) {
				bin = false;
				break;
			};
		};
	};
	
	if (bin) {
		// convert binary (0's and 1's) to number
		l = 0;

		for (unsigned char i=0;i<w;i++) {
			l <<= 1;
			if (val[i] == '1') l += 1;
		};

	} else {
		// assume input is a decimal number
		l = atoll(val.c_str());
	};

	if ((w%8) == 0) {
		// pack byte-wise data into hex
		s = "0x";

		for (unsigned char i=(w/8);i!=0;i--) {
			c = l >> ((i-1)*8);
			s += Wdbe::binToHex(c);
		};

	} else {
		s = "0b";

		mask = (((unsigned long long) 1) << (w-1));
		while (mask != 0) {
			if (l & mask) s += "1";
			else s += "0";
			
			mask >>= 1;
		};
	};

	return s;
};

string WdbeWrmcu::getValStr(
			WdbeMPort* prt
			, const string& altval
		) {
	string Comment;

	if ((prt->mdlIxVCat == VecWdbeVMPortMdlCat::CMDBUS) && (prt->ixVDir == VecWdbeVMPortDir::IN) && (prt->srefWdbeKHdltype != "sl")) Comment = "ptr";

	WdbeMSignal sig(0, 0, 0, 0, 0, 0, 0, 0, "", false, prt->srefWdbeKHdltype, prt->Width, prt->Minmax, "", "", prt->Defval, false, 0, "");

	return(getValStr(&sig));
};

string WdbeWrmcu::getValStr(
			WdbeMSignal* sig
			, const string& altval
		) {
	string s;

	if (altval != "") s = altval;
	else if (sig->Defon) s = sig->Onval;
	else s = sig->Offval;

	bool val;

	if (sig->Comment == "ptr") {
		s = "NULL";

	} else {
		if (sig->srefWdbeKHdltype == "sl") {
			if (s.length() == 1) {
				if (s[0] == '1') s = "true";
				else s = "false";
			} else s = "false";

		} else if ((sig->srefWdbeKHdltype == "slvup") || (sig->srefWdbeKHdltype == "slvdn")) {
			val = true;

			for (unsigned int i = 0; i < s.length();i++) {
				if ((s[i] < '0') || (s[i] > '9')) if ((s[i] != 'Z') && (s[i] != 'z')) {
					val = false;
					break;
				};
			};

			if (val) s = valToSlv(s, sig->Width, (sig->srefWdbeKHdltype == "slvup"));

		} else if (sig->srefWdbeKHdltype == "str") {
			s = "\"" + s + "\"";
		};
	};

	return s;
};

string WdbeWrmcu::getVarCtype(
			WdbeMPort* prt
		) {
	string Comment;

	if ((prt->mdlIxVCat == VecWdbeVMPortMdlCat::CMDBUS) && (prt->ixVDir == VecWdbeVMPortDir::IN) && (prt->srefWdbeKHdltype != "sl")) Comment = "ptr";

	WdbeMSignal sig(0, 0, 0, 0, 0, VecWdbeVMSignalMgeTbl::VOID, 0, 0, "", false, prt->srefWdbeKHdltype, prt->Width, prt->Minmax, "", "", "", false, 0, Comment);

	return(getVarCtype(&sig));
};

string WdbeWrmcu::getVarCtype(
			WdbeMSignal* sig
		) {
	string s;

	if (sig->Comment == "ptr") s = "unsigned char*";
	else {
		if (sig->srefWdbeKHdltype == "nat") s = "unsigned int";
		else if (sig->srefWdbeKHdltype == "sl") s = "bool";
		else if ((sig->srefWdbeKHdltype == "slvup") || (sig->srefWdbeKHdltype == "slvdn")) {
			if (sig->Width <= 8) s = "unsigned char";
			else if (sig->Width <= 16) s = "unsigned short";
			//else if (sig->Width <= 32) s = "unsigned int";
			else s = "unsigned long";
		} else if (sig->srefWdbeKHdltype == "str") s = "char*";
		else s = sig->srefWdbeKHdltype;
	};

	return s;
};
// IP cust --- IEND


