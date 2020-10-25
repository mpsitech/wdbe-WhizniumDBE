/**
	* \file WdbeMtpModbsctdCmdret_v1_0.cpp
	* Wdbe operation processor - adapt buffer size (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeMtpModbsctdCmdret_v1_0.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeMtpModbsctd;

/******************************************************************************
 namespace WdbeMtpModbsctdCmdret_v1_0
 ******************************************************************************/

DpchRetWdbe* WdbeMtpModbsctdCmdret_v1_0::run(
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


