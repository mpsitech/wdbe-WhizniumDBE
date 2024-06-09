/**
	* \file SqkWdbeGen.h
	* squawk generation for operation pack WdbeGen (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef SQKWDBEGEN_H
#define SQKWDBEGEN_H

#include "WdbeGen_blks.h"

/**
	* SqkWdbeGen
	*/
namespace SqkWdbeGen {
	std::string getSquawkAux(DbsWdbe* dbswdbe, DpchInvWdbeGenAux* dpchinv);
	std::string getSquawkStdvec(DbsWdbe* dbswdbe, DpchInvWdbeGenStdvec* dpchinv);
	std::string getSquawkWiring(DbsWdbe* dbswdbe, DpchInvWdbeGenWiring* dpchinv);
};

#endif
