/**
	* \file WdbeWrmcu.h
	* Wdbe operation pack global code (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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


