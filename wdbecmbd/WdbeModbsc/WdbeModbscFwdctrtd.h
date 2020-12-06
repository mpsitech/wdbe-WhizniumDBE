/**
	* \file WdbeModbscFwdctrtd.h
	* Wdbe operation processor - add read and write buffers and commands (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEMODBSCFWDCTRTD_H
#define WDBEMODBSCFWDCTRTD_H

#include "WdbeModbsc.h"

// IP include.cust --- INSERT

namespace WdbeModbscFwdctrtd {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeModbscFwdctrtd* dpchinv);
	// IP cust --- INSERT
};

#endif
