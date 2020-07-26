/**
	* \file WdbePrctreeValidate.cpp
	* Wdbe operation processor - validate file tree (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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

