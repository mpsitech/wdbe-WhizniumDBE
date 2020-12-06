/**
	* \file SqkWdbePrcfile.h
	* squawk generation for operation pack WdbePrcfile (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef SQKWDBEPRCFILE_H
#define SQKWDBEPRCFILE_H

#include "WdbePrcfile_blks.h"

/**
	* SqkWdbePrcfile
	*/
namespace SqkWdbePrcfile {
	std::string getSquawkConcat(DbsWdbe* dbswdbe, DpchInvWdbePrcfileConcat* dpchinv);
	std::string getSquawkPlhrpl(DbsWdbe* dbswdbe, DpchInvWdbePrcfilePlhrpl* dpchinv);
};

#endif
