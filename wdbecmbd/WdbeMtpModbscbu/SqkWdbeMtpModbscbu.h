/**
	* \file SqkWdbeMtpModbscbu.h
	* squawk generation for operation pack WdbeMtpModbscbu (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef SQKWDBEMTPMODBSCBU_H
#define SQKWDBEMTPMODBSCBU_H

#include "WdbeMtpModbscbu_blks.h"

/**
	* SqkWdbeMtpModbscbu
	*/
namespace SqkWdbeMtpModbscbu {
	std::string getSquawk(DbsWdbe* dbswdbe, DpchInvWdbeMtpModbscbu* dpchinv);
};

#endif

