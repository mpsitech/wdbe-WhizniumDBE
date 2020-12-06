/**
	* \file WdbeModbscCtrtd.h
	* Wdbe operation processor - add controller (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEMODBSCCTRTD_H
#define WDBEMODBSCCTRTD_H

#include "WdbeModbsc.h"

// IP include.cust --- INSERT

namespace WdbeModbscCtrtd {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeModbscCtrtd* dpchinv);
	// IP cust --- INSERT
};

#endif
