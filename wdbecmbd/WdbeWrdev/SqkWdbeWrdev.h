/**
	* \file SqkWdbeWrdev.h
	* squawk generation for operation pack WdbeWrdev (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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
	std::string getSquawkSys(DbsWdbe* dbswdbe, DpchInvWdbeWrdevSys* dpchinv);
	std::string getSquawkUnt(DbsWdbe* dbswdbe, DpchInvWdbeWrdevUnt* dpchinv);
};

#endif

