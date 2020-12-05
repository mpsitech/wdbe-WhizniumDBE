/**
	* \file SqkWdbePrcfile.cpp
	* squawk generation for operation pack WdbePrcfile (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "SqkWdbePrcfile.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace SqkWdbePrcfile
 ******************************************************************************/

string SqkWdbePrcfile::getSquawkConcat(
			DbsWdbe* dbswdbe
			, DpchInvWdbePrcfileConcat* dpchinv
		) {
	// example: "concatenate text from mutliple input files into output file 'test/abcd/test.txt'"
	return("concatenate text from mutliple input files into output file '" + dpchinv->outfile + "'"); // IP getSquawkConcat --- RLINE
};

string SqkWdbePrcfile::getSquawkPlhrpl(
			DbsWdbe* dbswdbe
			, DpchInvWdbePrcfilePlhrpl* dpchinv
		) {
	// example: "replace placeholders by text into file 'test/abcd/test.txt'"
	return("replace placeholders by text into file '" + dpchinv->outfile + "'"); // IP getSquawkPlhrpl --- RLINE
};



