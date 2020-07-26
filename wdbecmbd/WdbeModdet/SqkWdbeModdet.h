/**
	* \file SqkWdbeModdet.h
	* squawk generation for operation pack WdbeModdet (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef SQKWDBEMODDET_H
#define SQKWDBEMODDET_H

#include "WdbeModdet_blks.h"

/**
	* SqkWdbeModdet
	*/
namespace SqkWdbeModdet {
	std::string getSquawkCmdbus(DbsWdbe* dbswdbe, DpchInvWdbeModdetCmdbus* dpchinv);
	std::string getSquawkCtrFwdctr(DbsWdbe* dbswdbe, DpchInvWdbeModdetCtrFwdctr* dpchinv);
	std::string getSquawkEctr(DbsWdbe* dbswdbe, DpchInvWdbeModdetEctr* dpchinv);
	std::string getSquawkEhostif(DbsWdbe* dbswdbe, DpchInvWdbeModdetEhostif* dpchinv);
	std::string getSquawkImbuf(DbsWdbe* dbswdbe, DpchInvWdbeModdetImbuf* dpchinv);
	std::string getSquawkUnt(DbsWdbe* dbswdbe, DpchInvWdbeModdetUnt* dpchinv);
	std::string getSquawkWiring(DbsWdbe* dbswdbe, DpchInvWdbeModdetWiring* dpchinv);
};

#endif

