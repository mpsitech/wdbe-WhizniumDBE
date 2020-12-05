/**
	* \file WdbeWrfpga.h
	* Wdbe operation pack global code (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEWRFPGA_H
#define WDBEWRFPGA_H

#include "WdbeWrfpga_blks.h"

// IP include.cust --- INSERT

namespace WdbeWrfpga {

	// IP cust --- IBEGIN
	std::string valToSlv(const std::string& val, unsigned short w, const bool upNotDn = false, const bool othNotFull = false);

	std::string getValStr(WdbeMGeneric* gen, const bool othNotFull = false);
	std::string getValStr(WdbeMPort* prt, const bool othNotFull = false);
	std::string getValStr(WdbeMSignal* sig, const bool othNotFull = false, const std::string& altval = "");
	std::string getValStr(WdbeMVariable* var, const bool othNotFull = false, const std::string& altval = "");

	std::string getVarStr(WdbeMGeneric* gen);
	std::string getVarStr(WdbeMPort* prt);
	std::string getVarStr(WdbeMSignal* sig);
	std::string getVarStr(WdbeMVariable* var);
	
	void srefsFstsToVector(const std::string& s, std::vector<std::string>& ss);

	std::string getImbsigsref(DbsWdbe* dbswdbe, WdbeMImbuf* imb);
	// IP cust --- IEND
};

#endif



