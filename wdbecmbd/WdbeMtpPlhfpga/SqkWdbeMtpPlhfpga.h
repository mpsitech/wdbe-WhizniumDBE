/**
	* \file SqkWdbeMtpPlhfpga.h
	* squawk generation for operation pack WdbeMtpPlhfpga (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef SQKWDBEMTPPLHFPGA_H
#define SQKWDBEMTPPLHFPGA_H

#include "WdbeMtpPlhfpga_blks.h"

/**
	* SqkWdbeMtpPlhfpga
	*/
namespace SqkWdbeMtpPlhfpga {
	std::string getSquawk(DbsWdbe* dbswdbe, DpchInvWdbeMtpPlhfpga* dpchinv);
};

#endif

