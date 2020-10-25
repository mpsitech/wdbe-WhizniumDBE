/**
	* \file VecWdbeVBasereptype.cpp
	* vector VecWdbeVBasereptype (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "VecWdbeVBasereptype.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecWdbeVBasereptype
 ******************************************************************************/

uint VecWdbeVBasereptype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "prjgit") return PRJGIT;
	if (s == "custgit") return CUSTGIT;
	if (s == "uld") return ULD;

	return(0);
};

string VecWdbeVBasereptype::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == PRJGIT) return("prjgit");
	if (ix == CUSTGIT) return("custgit");
	if (ix == ULD) return("uld");

	return("");
};

