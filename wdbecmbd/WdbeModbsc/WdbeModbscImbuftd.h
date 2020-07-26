/**
	* \file WdbeModbscImbuftd.h
	* Wdbe operation processor - add parameters (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEMODBSCIMBUFTD_H
#define WDBEMODBSCIMBUFTD_H

#include "WdbeModbsc.h"

// IP include.cust --- INSERT

namespace WdbeModbscImbuftd {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeModbscImbuftd* dpchinv);
	// IP cust --- INSERT
};

#endif

