/**
	* \file SqkWdbeModdet.h
	* squawk generation for operation pack WdbeModdet (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

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
