/**
	* \file WdbeWrmcuDeploy.h
	* Wdbe operation processor - write MCU code deployment scripts (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEWRMCUDEPLOY_H
#define WDBEWRMCUDEPLOY_H

#include "WdbeWrmcu.h"

// IP include.cust --- INSERT

namespace WdbeWrmcuDeploy {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeWrmcuDeploy* dpchinv);
	// IP cust --- INSERT
};

#endif



