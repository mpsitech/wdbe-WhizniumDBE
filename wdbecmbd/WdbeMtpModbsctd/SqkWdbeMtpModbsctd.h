/**
	* \file SqkWdbeMtpModbsctd.h
	* squawk generation for operation pack WdbeMtpModbsctd (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef SQKWDBEMTPMODBSCTD_H
#define SQKWDBEMTPMODBSCTD_H

#include "WdbeMtpModbsctd_blks.h"

/**
	* SqkWdbeMtpModbsctd
	*/
namespace SqkWdbeMtpModbsctd {
	std::string getSquawk(DbsWdbe* dbswdbe, DpchInvWdbeMtpModbsctd* dpchinv);
};

#endif

