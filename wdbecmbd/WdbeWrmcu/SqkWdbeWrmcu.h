/**
	* \file SqkWdbeWrmcu.h
	* squawk generation for operation pack WdbeWrmcu (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef SQKWDBEWRMCU_H
#define SQKWDBEWRMCU_H

#include "WdbeWrmcu_blks.h"

/**
	* SqkWdbeWrmcu
	*/
namespace SqkWdbeWrmcu {
	std::string getSquawkBase(DbsWdbe* dbswdbe, DpchInvWdbeWrmcuBase* dpchinv);
	std::string getSquawkCtrFwdctr(DbsWdbe* dbswdbe, DpchInvWdbeWrmcuCtrFwdctr* dpchinv);
	std::string getSquawkDeploy(DbsWdbe* dbswdbe, DpchInvWdbeWrmcuDeploy* dpchinv);
	std::string getSquawkEhostif(DbsWdbe* dbswdbe, DpchInvWdbeWrmcuEhostif* dpchinv);
	std::string getSquawkMdlfine(DbsWdbe* dbswdbe, DpchInvWdbeWrmcuMdlfine* dpchinv);
	std::string getSquawkMdlraw(DbsWdbe* dbswdbe, DpchInvWdbeWrmcuMdlraw* dpchinv);
};

#endif



