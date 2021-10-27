/**
	* \file WdbeWrmcuCtrFwdctr.cpp
	* Wdbe operation processor - write type-specific C code (implementation)
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

#include "WdbeWrmcuCtrFwdctr.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeWrmcu;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeWrmcuCtrFwdctr
 ******************************************************************************/

DpchRetWdbe* WdbeWrmcuCtrFwdctr::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeWrmcuCtrFwdctr* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;
	string folder = dpchinv->folder;
	string Prjshort = dpchinv->Prjshort;
	string Untsref = dpchinv->Untsref;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN

	// probably should become ectr

	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
