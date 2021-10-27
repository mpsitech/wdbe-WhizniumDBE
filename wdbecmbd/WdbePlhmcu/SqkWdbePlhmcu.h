/**
	* \file SqkWdbePlhmcu.h
	* squawk generation for operation pack WdbePlhmcu (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef SQKWDBEPLHMCU_H
#define SQKWDBEPLHMCU_H

#include "WdbePlhmcu_blks.h"

/**
	* SqkWdbePlhmcu
	*/
namespace SqkWdbePlhmcu {
	std::string getSquawkEctr(DbsWdbe* dbswdbe, DpchInvWdbePlhmcuEctr* dpchinv);
	std::string getSquawkEhostif(DbsWdbe* dbswdbe, DpchInvWdbePlhmcuEhostif* dpchinv);
};

#endif
