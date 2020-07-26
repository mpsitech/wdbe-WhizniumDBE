/**
	* \file WdbeModbscCtrtd.h
	* Wdbe operation processor - add controller (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEMODBSCCTRTD_H
#define WDBEMODBSCCTRTD_H

#include "WdbeModbsc.h"

// IP include.cust --- INSERT

namespace WdbeModbscCtrtd {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeModbscCtrtd* dpchinv);
	// IP cust --- INSERT
};

#endif

