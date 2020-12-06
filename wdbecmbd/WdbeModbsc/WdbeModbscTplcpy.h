/**
	* \file WdbeModbscTplcpy.h
	* Wdbe operation processor - copy parameters, subs, generics and ports from template (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEMODBSCTPLCPY_H
#define WDBEMODBSCTPLCPY_H

#include "WdbeModbsc.h"

// IP include.cust --- INSERT

namespace WdbeModbscTplcpy {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeModbscTplcpy* dpchinv);
	// IP cust --- INSERT
};

#endif
