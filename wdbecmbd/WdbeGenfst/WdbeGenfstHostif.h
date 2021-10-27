/**
	* \file WdbeGenfstHostif.h
	* Wdbe operation processor - connect reset request (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 16 Oct 2021
  */
// IP header --- ABOVE

#ifndef WDBEGENFSTHOSTIF_H
#define WDBEGENFSTHOSTIF_H

#include "WdbeGenfst.h"

// IP include.cust --- INSERT

namespace WdbeGenfstHostif {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeGenfstHostif* dpchinv);
	// IP cust --- INSERT
};

#endif
