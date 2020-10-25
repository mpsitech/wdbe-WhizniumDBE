/**
	* \file SqkWdbePrcfile.h
	* squawk generation for operation pack WdbePrcfile (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef SQKWDBEPRCFILE_H
#define SQKWDBEPRCFILE_H

#include "WdbePrcfile_blks.h"

/**
	* SqkWdbePrcfile
	*/
namespace SqkWdbePrcfile {
	std::string getSquawkConcat(DbsWdbe* dbswdbe, DpchInvWdbePrcfileConcat* dpchinv);
	std::string getSquawkIexconv(DbsWdbe* dbswdbe, DpchInvWdbePrcfileIexconv* dpchinv);
	std::string getSquawkPlhrpl(DbsWdbe* dbswdbe, DpchInvWdbePrcfilePlhrpl* dpchinv);
};

#endif

