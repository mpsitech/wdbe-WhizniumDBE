/**
	* \file SqkWdbePlhmcu.h
	* squawk generation for operation pack WdbePlhmcu (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef SQKWDBEPLHMCU_H
#define SQKWDBEPLHMCU_H

#include "WdbePlhmcu_blks.h"

/**
	* SqkWdbePlhmcu
	*/
namespace SqkWdbePlhmcu {
	std::string getSquawkEhostif(DbsWdbe* dbswdbe, DpchInvWdbePlhmcuEhostif* dpchinv);
};

#endif

