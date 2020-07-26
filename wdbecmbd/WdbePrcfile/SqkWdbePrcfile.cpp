/**
	* \file SqkWdbePrcfile.cpp
	* squawk generation for operation pack WdbePrcfile (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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

string SqkWdbePrcfile::getSquawkIexconv(
			DbsWdbe* dbswdbe
			, DpchInvWdbePrcfileIexconv* dpchinv
		) {
	// example: "convert text import input file 'test/abcd/testin.txt' into output file 'test/abcd/testout.txt'"
	return("convert text import file '" + dpchinv->infile + "' into output file '" + dpchinv->outfile + "'"); // IP getSquawkIexconv --- RLINE
};

string SqkWdbePrcfile::getSquawkPlhrpl(
			DbsWdbe* dbswdbe
			, DpchInvWdbePrcfilePlhrpl* dpchinv
		) {
	// example: "replace placeholders by text into file 'test/abcd/test.txt'"
	return("replace placeholders by text into file '" + dpchinv->outfile + "'"); // IP getSquawkPlhrpl --- RLINE
};


