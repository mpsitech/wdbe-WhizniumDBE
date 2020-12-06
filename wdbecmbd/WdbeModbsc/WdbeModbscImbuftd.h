/**
	* \file WdbeModbscImbuftd.h
	* Wdbe operation processor - add parameters (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEMODBSCIMBUFTD_H
#define WDBEMODBSCIMBUFTD_H

#include "WdbeModbsc.h"

// IP include.cust --- INSERT

namespace WdbeModbscImbuftd {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeModbscImbuftd* dpchinv);
	// IP cust --- INSERT
};

#endif
