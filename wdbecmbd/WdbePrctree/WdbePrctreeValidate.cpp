/**
	* \file WdbePrctreeValidate.cpp
	* Wdbe operation processor - validate file tree (implementation)
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

#include "WdbePrctreeValidate.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbePrctree;

/******************************************************************************
 namespace WdbePrctreeValidate
 ******************************************************************************/

DpchRetWdbe* WdbePrctreeValidate::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbe* dpchinv
		) {
	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- INSERT

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT



