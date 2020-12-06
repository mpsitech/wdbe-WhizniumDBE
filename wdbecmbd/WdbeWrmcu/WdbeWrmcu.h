/**
	* \file WdbeWrmcu.h
	* Wdbe operation pack global code (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEWRMCU_H
#define WDBEWRMCU_H

#include "WdbeWrmcu_blks.h"

// IP include.cust --- INSERT

namespace WdbeWrmcu {

	// IP cust --- IBEGIN
	std::string valToSlv(const std::string& val, unsigned char w, const bool upNotDn);

	std::string getValStr(WdbeMPort* prt, const std::string& altval = "");
	std::string getValStr(WdbeMSignal* sig, const std::string& altval = "");

	std::string getVarCtype(WdbeMPort* prt);
	std::string getVarCtype(WdbeMSignal* sig);
	// IP cust --- IEND
};

#endif
