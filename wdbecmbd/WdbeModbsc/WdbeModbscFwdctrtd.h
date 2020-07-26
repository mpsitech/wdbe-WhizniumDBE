/**
	* \file WdbeModbscFwdctrtd.h
	* Wdbe operation processor - add read and write buffers and commands (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEMODBSCFWDCTRTD_H
#define WDBEMODBSCFWDCTRTD_H

#include "WdbeModbsc.h"

// IP include.cust --- INSERT

namespace WdbeModbscFwdctrtd {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeModbscFwdctrtd* dpchinv);
	// IP cust --- INSERT
};

#endif

