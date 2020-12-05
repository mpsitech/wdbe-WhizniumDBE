/**
	* \file WdbeModbscSys.h
	* Wdbe operation processor - add standard vectors (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEMODBSCSYS_H
#define WDBEMODBSCSYS_H

#include "WdbeModbsc.h"

// IP include.cust --- INSERT

namespace WdbeModbscSys {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeModbscSys* dpchinv);
	// IP cust --- INSERT
};

#endif



