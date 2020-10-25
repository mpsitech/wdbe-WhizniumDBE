/**
	* \file SqkWdbeWrfpga.h
	* squawk generation for operation pack WdbeWrfpga (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef SQKWDBEWRFPGA_H
#define SQKWDBEWRFPGA_H

#include "WdbeWrfpga_blks.h"

/**
	* SqkWdbeWrfpga
	*/
namespace SqkWdbeWrfpga {
	std::string getSquawkBase(DbsWdbe* dbswdbe, DpchInvWdbeWrfpgaBase* dpchinv);
	std::string getSquawkCtrFwdctr(DbsWdbe* dbswdbe, DpchInvWdbeWrfpgaCtrFwdctr* dpchinv);
	std::string getSquawkDeploy(DbsWdbe* dbswdbe, DpchInvWdbeWrfpgaDeploy* dpchinv);
	std::string getSquawkEhostif(DbsWdbe* dbswdbe, DpchInvWdbeWrfpgaEhostif* dpchinv);
	std::string getSquawkHostif(DbsWdbe* dbswdbe, DpchInvWdbeWrfpgaHostif* dpchinv);
	std::string getSquawkIpclr(DbsWdbe* dbswdbe, DpchInvWdbeWrfpgaIpclr* dpchinv);
	std::string getSquawkMdlfine(DbsWdbe* dbswdbe, DpchInvWdbeWrfpgaMdlfine* dpchinv);
	std::string getSquawkMdlraw(DbsWdbe* dbswdbe, DpchInvWdbeWrfpgaMdlraw* dpchinv);
};

#endif

