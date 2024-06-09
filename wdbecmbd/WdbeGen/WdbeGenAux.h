/**
	* \file WdbeGenAux.h
	* Wdbe operation processor - generate auxiliary infrastructure (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 27 May 2023
  */
// IP header --- ABOVE

#ifndef WDBEGENAUX_H
#define WDBEGENAUX_H

#include "WdbeGen.h"

// IP include.cust --- INSERT

namespace WdbeGenAux {

	DpchRetWdbeGenAux* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeGenAux* dpchinv);
	// IP cust --- IBEGIN

	void genCdc(DbsWdbe* dbswdbe, WdbeMCdc* cdc, Sbecore::uint ixVDir, ListWdbeRMCdcMSignal& crss, Sbecore::uint& refNumSig);
	// IP cust --- IEND
};

#endif
