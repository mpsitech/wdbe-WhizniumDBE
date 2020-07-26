/**
	* \file WdbeModbscSys.h
	* Wdbe operation processor - add standard vectors (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEMODBSCSYS_H
#define WDBEMODBSCSYS_H

#include "WdbeModbsc.h"

// IP include.cust --- INSERT

namespace WdbeModbscSys {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeModbscSys* dpchinv);
	// IP cust --- INSERT
};

#endif

