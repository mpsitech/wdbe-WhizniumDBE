/**
	* \file SqkWdbeWrterm.h
	* squawk generation for operation pack WdbeWrterm (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Sep 2023
  */
// IP header --- ABOVE

#ifndef SQKWDBEWRTERM_H
#define SQKWDBEWRTERM_H

#include "WdbeWrterm_blks.h"

/**
	* SqkWdbeWrterm
	*/
namespace SqkWdbeWrterm {
	std::string getSquawkDeploy(DbsWdbe* dbswdbe, DpchInvWdbeWrtermDeploy* dpchinv);
	std::string getSquawkMain(DbsWdbe* dbswdbe, DpchInvWdbeWrtermMain* dpchinv);
};

#endif
