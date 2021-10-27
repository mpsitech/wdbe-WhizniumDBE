/**
	* \file WdbeGenfstPpl.cpp
	* Wdbe operation processor - add FSM's and signals (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeGenfstPpl.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeGenfst;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeGenfstPpl
 ******************************************************************************/

DpchRetWdbe* WdbeGenfstPpl::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeGenfstPpl* dpchinv
		) {
	ubigint refWdbeMPipeline = dpchinv->refWdbeMPipeline;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- INSERT

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
