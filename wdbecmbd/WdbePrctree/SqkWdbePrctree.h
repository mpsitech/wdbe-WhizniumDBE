/**
	* \file SqkWdbePrctree.h
	* squawk generation for operation pack WdbePrctree (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef SQKWDBEPRCTREE_H
#define SQKWDBEPRCTREE_H

#include "WdbePrctree_blks.h"

/**
	* SqkWdbePrctree
	*/
namespace SqkWdbePrctree {
	std::string getSquawkExtract(DbsWdbe* dbswdbe, DpchInvWdbePrctreeExtract* dpchinv);
	std::string getSquawkMerge(DbsWdbe* dbswdbe, DpchInvWdbePrctreeMerge* dpchinv);
	std::string getSquawkValidate(DbsWdbe* dbswdbe, DpchInvWdbePrctreeValidate* dpchinv);
};

#endif

