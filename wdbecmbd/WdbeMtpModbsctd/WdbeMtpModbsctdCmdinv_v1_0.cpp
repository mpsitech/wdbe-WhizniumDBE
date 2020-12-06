/**
	* \file WdbeMtpModbsctdCmdinv_v1_0.cpp
	* Wdbe operation processor - adapt buffer size (implementation)
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

#include "WdbeMtpModbsctdCmdinv_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpModbsctd;

/******************************************************************************
 namespace WdbeMtpModbsctdCmdinv_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpModbsctdCmdinv_v1_0::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeMtpModbsctd* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	ubigint ref;

	string sizeBuf;

	if (Wdbe::getMpa(dbswdbe, refWdbeMModule, "sizeBuf", sizeBuf))
		if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = 'buf'", ref))
			Wdbe::setMpa(dbswdbe, ref, "size", sizeBuf);
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
