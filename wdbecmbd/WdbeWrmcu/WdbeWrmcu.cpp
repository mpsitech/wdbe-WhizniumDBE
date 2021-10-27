/**
	* \file WdbeWrmcu.cpp
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

#include "WdbeWrmcu.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeWrmcu
 ******************************************************************************/

// IP cust --- IBEGIN
string WdbeWrmcu::getVarStr(
			WdbeMVariable* var
		) {
	string s;

	if (var->srefWdbeKHdltype == "bit") s = "unsigned char " + var->sref + ":1";
	else if (var->srefWdbeKHdltype == "btarr") s = "unsigned char " + var->sref + "[" + to_string(var->Width) + "]";
	else if (var->srefWdbeKHdltype == "ptr") s = "unsigned char* " + var->sref;
	else if (var->srefWdbeKHdltype == "sgn") s = "int" + to_string(var->Width) + "_t " + var->sref;
	else if (var->srefWdbeKHdltype == "usgn") s = "uint" + to_string(var->Width) + "_t " + var->sref;
	else s = var->srefWdbeKHdltype + " " + var->sref;

	return s;
};
// IP cust --- IEND
