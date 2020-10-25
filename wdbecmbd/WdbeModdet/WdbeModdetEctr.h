/**
	* \file WdbeModdetEctr.h
	* Wdbe operation processor - add vector constants and FSM debug ports (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEMODDETECTR_H
#define WDBEMODDETECTR_H

#include "WdbeModdet.h"

// IP include.cust --- INSERT

namespace WdbeModdetEctr {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeModdetEctr* dpchinv);
	// IP cust --- INSERT
};

#endif

