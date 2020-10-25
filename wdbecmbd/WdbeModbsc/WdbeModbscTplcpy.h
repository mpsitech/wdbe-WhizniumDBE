/**
	* \file WdbeModbscTplcpy.h
	* Wdbe operation processor - copy parameters, subs, generics and ports from template (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEMODBSCTPLCPY_H
#define WDBEMODBSCTPLCPY_H

#include "WdbeModbsc.h"

// IP include.cust --- INSERT

namespace WdbeModbscTplcpy {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeModbscTplcpy* dpchinv);
	// IP cust --- INSERT
};

#endif

