/**
	* \file SqkWdbeGen.cpp
	* squawk generation for operation pack WdbeGen (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#include "SqkWdbeGen.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace SqkWdbeGen
 ******************************************************************************/

string SqkWdbeGen::getSquawkStdvec(
			DbsWdbe* dbswdbe
			, DpchInvWdbeGenStdvec* dpchinv
		) {
	// example: "fill standard vectors for unit 'icacam2'"
	return(""); // IP getSquawkStdvec --- LINE
};

string SqkWdbeGen::getSquawkTest(
			DbsWdbe* dbswdbe
			, DpchInvWdbeGenTest* dpchinv
		) {
	// example: "generate test infrastructure for module 'laser (easy model controller)'"
	return(""); // IP getSquawkTest --- LINE
};

string SqkWdbeGen::getSquawkWiring(
			DbsWdbe* dbswdbe
			, DpchInvWdbeGenWiring* dpchinv
		) {
	// example: "generate wiring for module 'icm2 (top_v1_0 top module)'"
	return(""); // IP getSquawkWiring --- LINE
};
