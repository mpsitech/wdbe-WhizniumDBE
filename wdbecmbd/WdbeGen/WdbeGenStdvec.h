/**
	* \file WdbeGenStdvec.h
	* Wdbe operation processor - fill standard vectors (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBEGENSTDVEC_H
#define WDBEGENSTDVEC_H

#include "WdbeGen.h"

// IP include.cust --- INSERT

namespace WdbeGenStdvec {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeGenStdvec* dpchinv);
	// IP cust --- INSERT
};

#endif
