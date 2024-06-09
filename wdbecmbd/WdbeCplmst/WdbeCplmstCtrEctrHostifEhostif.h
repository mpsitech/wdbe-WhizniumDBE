/**
	* \file WdbeCplmstCtrEctrHostifEhostif.h
	* Wdbe operation processor - add controller (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 24 May 2023
  */
// IP header --- ABOVE

#ifndef WDBECPLMSTCTRECTRHOSTIFEHOSTIF_H
#define WDBECPLMSTCTRECTRHOSTIFEHOSTIF_H

#include "WdbeCplmst.h"

// IP include.cust --- INSERT

namespace WdbeCplmstCtrEctrHostifEhostif {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeCplmstCtrEctrHostifEhostif* dpchinv);
	// IP cust --- INSERT
};

#endif
