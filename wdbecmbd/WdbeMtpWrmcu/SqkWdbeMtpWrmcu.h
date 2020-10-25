/**
	* \file SqkWdbeMtpWrmcu.h
	* squawk generation for operation pack WdbeMtpWrmcu (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef SQKWDBEMTPWRMCU_H
#define SQKWDBEMTPWRMCU_H

#include "WdbeMtpWrmcu_blks.h"

/**
	* SqkWdbeMtpWrmcu
	*/
namespace SqkWdbeMtpWrmcu {
	std::string getSquawk(DbsWdbe* dbswdbe, DpchInvWdbeMtpWrmcu* dpchinv);
};

#endif

