/**
	* \file VecWdbeVExpstate.cpp
	* vector VecWdbeVExpstate (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "VecWdbeVExpstate.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecWdbeVExpstate
 ******************************************************************************/

uint VecWdbeVExpstate::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "detd") return DETD;
	if (s == "maxd") return MAXD;
	if (s == "mind") return MIND;
	if (s == "regd") return REGD;

	return(0);
};

string VecWdbeVExpstate::getSref(
			const uint ix
		) {
	if (ix == DETD) return("detd");
	if (ix == MAXD) return("maxd");
	if (ix == MIND) return("mind");
	if (ix == REGD) return("regd");

	return("");
};
