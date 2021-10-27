/**
	* \file WdbeMtpCplmsttd.cpp
	* Wdbe operation pack global code (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpCplmsttd.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeMtpCplmsttd
 ******************************************************************************/

// IP cust --- IBEGIN
string WdbeMtpCplmsttd::getDivstr(
			const double d
		) {
	// ex. 12.375 => 12_375, 1.50 => 1_5
	string divstr = to_string(d);

	size_t ptr, ptr2;

	ptr = divstr.find('.');

	if (ptr != string::npos) {
		for (ptr2 = divstr.size() - 1; ptr2 > ptr; ptr2--) if (divstr[ptr2] != '0') break;

		if (ptr == ptr2) divstr = divstr.substr(0, ptr);
		else divstr = divstr.substr(0, ptr) + "_" + divstr.substr(ptr + 1, ptr2 - ptr);
	};

	return divstr;
};
// IP cust --- IEND
