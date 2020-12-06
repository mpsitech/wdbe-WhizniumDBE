/**
	* \file SqkWdbePlhfpga.h
	* squawk generation for operation pack WdbePlhfpga (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

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
