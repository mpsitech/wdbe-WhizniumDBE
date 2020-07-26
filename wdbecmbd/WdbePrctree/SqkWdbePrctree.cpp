/**
	* \file SqkWdbePrctree.cpp
	* squawk generation for operation pack WdbePrctree (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "SqkWdbePrctree.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace SqkWdbePrctree
 ******************************************************************************/

string SqkWdbePrctree::getSquawkExtract(
			DbsWdbe* dbswdbe
			, DpchInvWdbePrctreeExtract* dpchinv
		) {
	// example: "extract from file tree 'test/abcd' into extract file tree 'test/efgh'"
	// IP getSquawkExtract --- RBEGIN
	if (dpchinv->infile != "") return("extract insertion points from file '" + dpchinv->infile + "' into file '" + dpchinv->extfile + "'");
	else return("extract insertion points from file tree '" + dpchinv->infolder + "' into folder '" + dpchinv->extfolder + "'");
	// IP getSquawkExtract --- REND
};

string SqkWdbePrctree::getSquawkMerge(
			DbsWdbe* dbswdbe
			, DpchInvWdbePrctreeMerge* dpchinv
		) {
	// example: "merge extract file tree 'test/abcd' into template file tree 'test/efgh'"
	// IP getSquawkMerge --- RBEGIN
	if (dpchinv->tplfile != "") return("merge extract file '" + dpchinv->extfile + "' into template file '" + dpchinv->tplfile + "'");
	else return("merge extract file tree '" + dpchinv->extfolder + "' into template file tree '" + dpchinv->tplfolder + "'");
	// IP getSquawkMerge --- REND
};

string SqkWdbePrctree::getSquawkValidate(
			DbsWdbe* dbswdbe
			, DpchInvWdbePrctreeValidate* dpchinv
		) {
	// example: "validate file tree"
	return("validate file tree"); // IP getSquawkValidate --- RLINE
};


