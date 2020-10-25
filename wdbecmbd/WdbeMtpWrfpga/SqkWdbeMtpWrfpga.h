/**
	* \file SqkWdbeMtpWrfpga.h
	* squawk generation for operation pack WdbeMtpWrfpga (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef SQKWDBEMTPWRFPGA_H
#define SQKWDBEMTPWRFPGA_H

#include "WdbeMtpWrfpga_blks.h"

/**
	* SqkWdbeMtpWrfpga
	*/
namespace SqkWdbeMtpWrfpga {
	std::string getSquawk(DbsWdbe* dbswdbe, DpchInvWdbeMtpWrfpga* dpchinv);
};

#endif

