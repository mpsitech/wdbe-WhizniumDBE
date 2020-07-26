/**
	* \file SqkWdbeWrmcu.h
	* squawk generation for operation pack WdbeWrmcu (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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

