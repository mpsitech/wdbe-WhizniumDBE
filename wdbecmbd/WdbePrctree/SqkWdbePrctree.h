/**
	* \file SqkWdbePrctree.h
	* squawk generation for operation pack WdbePrctree (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

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



