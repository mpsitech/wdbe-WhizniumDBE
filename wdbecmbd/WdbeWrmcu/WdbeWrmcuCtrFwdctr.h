/**
	* \file WdbeWrmcuCtrFwdctr.h
	* Wdbe operation processor - write type-specific C code (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEWRMCUCTRFWDCTR_H
#define WDBEWRMCUCTRFWDCTR_H

#include "WdbeWrmcu.h"

// IP include.cust --- INSERT

namespace WdbeWrmcuCtrFwdctr {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeWrmcuCtrFwdctr* dpchinv);
	// IP cust --- INSERT
};

#endif

