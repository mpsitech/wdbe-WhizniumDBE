/**
	* \file WdbeWrmcuDeploy.cpp
	* Wdbe operation processor - write MCU code deployment scripts (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

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

