/**
	* \file WdbeWrmcuCtrFwdctr.h
	* Wdbe operation processor - write type-specific C code (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEWRMCUCTRFWDCTR_H
#define WDBEWRMCUCTRFWDCTR_H

#include "WdbeWrmcu.h"

// IP include.cust --- INSERT

namespace WdbeWrmcuCtrFwdctr {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeWrmcuCtrFwdctr* dpchinv);
	// IP cust --- INSERT
};

#endif



