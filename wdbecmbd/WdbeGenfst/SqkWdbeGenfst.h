/**
	* \file SqkWdbeGenfst.h
	* squawk generation for operation pack WdbeGenfst (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef SQKWDBEGENFST_H
#define SQKWDBEGENFST_H

#include "WdbeGenfst_blks.h"

/**
	* SqkWdbeGenfst
	*/
namespace SqkWdbeGenfst {
	std::string getSquawkCmdbus(DbsWdbe* dbswdbe, DpchInvWdbeGenfstCmdbus* dpchinv);
	std::string getSquawkCtr(DbsWdbe* dbswdbe, DpchInvWdbeGenfstCtr* dpchinv);
	std::string getSquawkEctr(DbsWdbe* dbswdbe, DpchInvWdbeGenfstEctr* dpchinv);
	std::string getSquawkEhostif(DbsWdbe* dbswdbe, DpchInvWdbeGenfstEhostif* dpchinv);
	std::string getSquawkHostif(DbsWdbe* dbswdbe, DpchInvWdbeGenfstHostif* dpchinv);
	std::string getSquawkImbuf(DbsWdbe* dbswdbe, DpchInvWdbeGenfstImbuf* dpchinv);
	std::string getSquawkPpl(DbsWdbe* dbswdbe, DpchInvWdbeGenfstPpl* dpchinv);
	std::string getSquawkTop(DbsWdbe* dbswdbe, DpchInvWdbeGenfstTop* dpchinv);
};

#endif
