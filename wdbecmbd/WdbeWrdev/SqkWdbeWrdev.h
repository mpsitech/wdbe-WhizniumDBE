/**
	* \file SqkWdbeWrdev.h
	* squawk generation for operation pack WdbeWrdev (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef SQKWDBEWRDEV_H
#define SQKWDBEWRDEV_H

#include "WdbeWrdev_blks.h"

/**
	* SqkWdbeWrdev
	*/
namespace SqkWdbeWrdev {
	std::string getSquawkBase(DbsWdbe* dbswdbe, DpchInvWdbeWrdevBase* dpchinv);
	std::string getSquawkCtr(DbsWdbe* dbswdbe, DpchInvWdbeWrdevCtr* dpchinv);
	std::string getSquawkDeploy(DbsWdbe* dbswdbe, DpchInvWdbeWrdevDeploy* dpchinv);
	std::string getSquawkUnt(DbsWdbe* dbswdbe, DpchInvWdbeWrdevUnt* dpchinv);
};

#endif
