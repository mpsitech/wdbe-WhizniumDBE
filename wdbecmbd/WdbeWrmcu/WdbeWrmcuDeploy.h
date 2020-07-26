/**
	* \file WdbeWrmcuDeploy.h
	* Wdbe operation processor - write MCU code deployment scripts (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEWRMCUDEPLOY_H
#define WDBEWRMCUDEPLOY_H

#include "WdbeWrmcu.h"

// IP include.cust --- INSERT

namespace WdbeWrmcuDeploy {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeWrmcuDeploy* dpchinv);
	// IP cust --- INSERT
};

#endif

