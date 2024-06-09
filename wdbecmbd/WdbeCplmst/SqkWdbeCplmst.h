/**
	* \file SqkWdbeCplmst.h
	* squawk generation for operation pack WdbeCplmst (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef SQKWDBECPLMST_H
#define SQKWDBECPLMST_H

#include "WdbeCplmst_blks.h"

/**
	* SqkWdbeCplmst
	*/
namespace SqkWdbeCplmst {
	std::string getSquawkCtrEctrHostifEhostif(DbsWdbe* dbswdbe, DpchInvWdbeCplmstCtrEctrHostifEhostif* dpchinv);
	std::string getSquawkImbuf(DbsWdbe* dbswdbe, DpchInvWdbeCplmstImbuf* dpchinv);
	std::string getSquawkTplcpy(DbsWdbe* dbswdbe, DpchInvWdbeCplmstTplcpy* dpchinv);
	std::string getSquawkUnt(DbsWdbe* dbswdbe, DpchInvWdbeCplmstUnt* dpchinv);
};

#endif
