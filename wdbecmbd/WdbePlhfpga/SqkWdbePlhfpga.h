/**
	* \file SqkWdbePlhfpga.h
	* squawk generation for operation pack WdbePlhfpga (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef SQKWDBEPLHFPGA_H
#define SQKWDBEPLHFPGA_H

#include "WdbePlhfpga_blks.h"

/**
	* SqkWdbePlhfpga
	*/
namespace SqkWdbePlhfpga {
	std::string getSquawkCmdinv(DbsWdbe* dbswdbe, DpchInvWdbePlhfpgaCmdinv* dpchinv);
	std::string getSquawkCmdret(DbsWdbe* dbswdbe, DpchInvWdbePlhfpgaCmdret* dpchinv);
	std::string getSquawkEhostif(DbsWdbe* dbswdbe, DpchInvWdbePlhfpgaEhostif* dpchinv);
	std::string getSquawkFwdctr(DbsWdbe* dbswdbe, DpchInvWdbePlhfpgaFwdctr* dpchinv);
};

#endif

