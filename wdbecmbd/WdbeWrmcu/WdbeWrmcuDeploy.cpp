/**
	* \file WdbeWrmcuDeploy.cpp
	* Wdbe operation processor - write MCU code deployment scripts (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeWrmcuDeploy.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeWrmcu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeWrmcuDeploy
 ******************************************************************************/

DpchRetWdbe* WdbeWrmcuDeploy::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeWrmcuDeploy* dpchinv
		) {
	ubigint refWdbeMRelease = dpchinv->refWdbeMRelease;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- INSERT

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
