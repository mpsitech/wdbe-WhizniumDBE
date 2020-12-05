/**
	* \file WdbeModdetEctr.h
	* Wdbe operation processor - add vector constants and FSM debug ports (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEMODDETECTR_H
#define WDBEMODDETECTR_H

#include "WdbeModdet.h"

// IP include.cust --- INSERT

namespace WdbeModdetEctr {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeModdetEctr* dpchinv);
	// IP cust --- INSERT
};

#endif



