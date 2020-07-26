/**
	* \file SqkWdbeMtpPlhmcu.h
	* squawk generation for operation pack WdbeMtpPlhmcu (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef SQKWDBEMTPPLHMCU_H
#define SQKWDBEMTPPLHMCU_H

#include "WdbeMtpPlhmcu_blks.h"

/**
	* SqkWdbeMtpPlhmcu
	*/
namespace SqkWdbeMtpPlhmcu {
	std::string getSquawk(DbsWdbe* dbswdbe, DpchInvWdbeMtpPlhmcu* dpchinv);
};

#endif

